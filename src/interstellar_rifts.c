// Pokémon Interstellar — runtime rift randomisation.
//
// Every boot the game rolls one seed. Each map derives its own stream from
// that seed, so a map's rifts stay put for the whole play session but the
// world is laid out differently the next time you launch the ROM.
//
// Positions come from src/data/interstellar_rift_spots.h, generated offline.
// Every spot in a map's list is walkable and clear of NPCs/warps, and the
// list was validated with ALL of its spots occupied at once: nothing on the
// map became unreachable. Any subset chosen here blocks fewer tiles, so a
// random layout can never wall off a route.
#include "global.h"
#include "event_data.h"
#include "overworld.h"
#include "random.h"
#include "main.h"
#include "constants/event_objects.h"
#include "constants/maps.h"
#include "constants/weather.h"
#include "constants/rgb.h"
#include "palette.h"
#include "sound.h"
#include "constants/songs.h"
#include "gpu_regs.h"

struct RiftSpot
{
    u8 x;
    u8 y;
};

struct RiftSpotList
{
    u8 mapGroup;
    u8 mapNum;
    u8 count;
    // The first anchorCount spots sit beside an NPC the rift dropped here, so
    // they stay put every boot -- only the tiles after them get shuffled.
    u8 anchorCount;
    const struct RiftSpot *spots;
};

#include "data/interstellar_rift_spots.h"

#define MAX_RIFT_SPOTS 16

static u32 sRiftSeed; // zero at boot, rolled on first overworld load

// ---------------------------------------------------------------------------
// Dry lightning: the Act 1 storm never breaks into rain, it just keeps
// flashing. Runs on any overcast (WEATHER_SHADE) map.
// ---------------------------------------------------------------------------
static u16 sLightningTimer;
static u8 sLightningPhase;
static u16 sLightningSavedBldCnt;

// The flash uses the GPU brightness blend, NOT the palette buffers: writing
// palettes here overwrote the weather shading and day/night tint every frame
// and washed the whole map out.
//
// BLDY on its own is not enough. The overworld runs with WIN0 and WIN1 on and
// neither WININ nor WINOUT requesting the colour special effect, so the blend
// is masked off across the whole screen and the storm was invisible no matter
// how bright the flash was set. FadeScreenHardware() hits the same wall and
// solves it the same way: switch the colour-effect bits on for the duration,
// then hand them back along with the overworld's own BLDCNT, which is what
// draws grass and reflections.
static void SetLightningBlendWindows(bool32 enable)
{
    if (enable)
    {
        SetGpuRegBits(REG_OFFSET_WININ, WININ_WIN0_CLR | WININ_WIN1_CLR);
        SetGpuRegBits(REG_OFFSET_WINOUT, WINOUT_WIN01_CLR);
    }
    else
    {
        ClearGpuRegBits(REG_OFFSET_WININ, WININ_WIN0_CLR | WININ_WIN1_CLR);
        ClearGpuRegBits(REG_OFFSET_WINOUT, WINOUT_WIN01_CLR);
    }
}

void Interstellar_UpdateStormLightning(void)
{
    // Overcast outdoors only -- a few vanilla interiors are WEATHER_SHADE too,
    // and lightning flashing inside a mansion would be nonsense. ROUTE 1 is the
    // exception: it carries the rain as well, so it is named rather than picked
    // up by weather, which would drag the whole slow-rain tier in with it.
    if (gPaletteFade.active || !MapHasNaturalLight(gMapHeader.mapType))
        return;
    if (gMapHeader.weather != WEATHER_SHADE
     && !(gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(MAP_ROUTE1)
       && gSaveBlock1Ptr->location.mapNum == MAP_NUM(MAP_ROUTE1)))
        return;

    if (sLightningPhase != 0)
    {
        u32 bldy;

        sLightningPhase--;
        // A stab, the strike proper, then a fade back down -- about two thirds
        // of a second, which is long enough to read as lightning rather than a
        // dropped frame.
        switch (sLightningPhase)
        {
        case 22: bldy = 11; break;
        case 21: bldy = 6;  break;
        case 20: bldy = 3;  break;
        case 15: bldy = 14; break;
        case 14: bldy = 12; break;
        case 13: bldy = 8;  break;
        case 12: bldy = 6;  break;
        case 11: bldy = 4;  break;
        case 10: bldy = 2;  break;
        case 9:  bldy = 1;  break;
        default: bldy = 0;  break;
        }

        if (bldy != 0)
        {
            SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_ALL | BLDCNT_EFFECT_LIGHTEN);
            SetGpuReg(REG_OFFSET_BLDY, bldy);
        }
        else
        {
            SetGpuReg(REG_OFFSET_BLDY, 0);
            if (sLightningPhase == 0) // hand the registers back
            {
                SetGpuReg(REG_OFFSET_BLDCNT, sLightningSavedBldCnt);
                SetLightningBlendWindows(FALSE);
            }
        }
        return;
    }

    // Roughly every 8-16 seconds. This is the far edge of the storm, not the
    // middle of it -- the middle is waiting in CERULEAN.
    if (++sLightningTimer >= 480 + (Random() % 480))
    {
        sLightningTimer = 0;
        sLightningPhase = 24;
        sLightningSavedBldCnt = GetGpuReg(REG_OFFSET_BLDCNT);
        SetLightningBlendWindows(TRUE);
        PlaySE(SE_THUNDER);
    }
}

static u32 RiftRand(u32 *state)
{
    *state = (*state * 1103515245u) + 12345u;
    return (*state >> 16) & 0x7FFF;
}

static bool32 IsRandomisableRift(const struct ObjectEventTemplate *t)
{
    // Story rifts (arrival portals, the Cerulean gate) are placed by hand and
    // always carry a visibility flag; leave those exactly where they are.
    if (t->flagId != 0)
        return FALSE;

    return t->graphicsId == OBJ_EVENT_GFX_INTERSTELLAR_RIFT_SCAR
        || t->graphicsId == OBJ_EVENT_GFX_INTERSTELLAR_RIFT_SCAR_MED
        || t->graphicsId == OBJ_EVENT_GFX_INTERSTELLAR_RIFT_BLIGHT;
}

void Interstellar_RandomiseRifts(void)
{
    const struct RiftSpotList *list = NULL;
    u8 order[MAX_RIFT_SPOTS];
    u32 i, count, anchors, stream, next;

    if (gMapHeader.events == NULL)
        return;

    for (i = 0; i < ARRAY_COUNT(sRiftSpotLists); i++)
    {
        if (sRiftSpotLists[i].mapGroup == gSaveBlock1Ptr->location.mapGroup
         && sRiftSpotLists[i].mapNum == gSaveBlock1Ptr->location.mapNum)
        {
            list = &sRiftSpotLists[i];
            break;
        }
    }

    if (list == NULL)
        return;

    if (sRiftSeed == 0)
    {
        // Entropy: RNG state plus how many frames the player spent getting
        // here (title screen dwell time differs every launch).
        sRiftSeed = (Random32() ^ (gMain.vblankCounter1 * 2654435761u)) | 1;
    }

    // One stream per map, so re-entering a map during a session is stable.
    stream = sRiftSeed ^ (list->mapGroup * 2654435761u) ^ (list->mapNum * 2246822519u);

    count = list->count;
    if (count > MAX_RIFT_SPOTS)
        count = MAX_RIFT_SPOTS;
    anchors = list->anchorCount;
    if (anchors > count)
        anchors = count;

    for (i = 0; i < count; i++)
        order[i] = i;

    // Shuffle only the free tail; the anchors keep their order and their spot.
    for (i = count - 1; i > anchors; i--)
    {
        u32 j = anchors + RiftRand(&stream) % (i + 1 - anchors);
        u8 tmp = order[i];
        order[i] = order[j];
        order[j] = tmp;
    }

    next = 0;
    for (i = 0; i < gMapHeader.events->objectEventCount && i < OBJECT_EVENT_TEMPLATES_COUNT; i++)
    {
        struct ObjectEventTemplate *t = &gSaveBlock1Ptr->objectEventTemplates[i];

        if (!IsRandomisableRift(t))
            continue;
        if (next >= count)
            break;

        t->x = list->spots[order[next]].x;
        t->y = list->spots[order[next]].y;

        // An anchor was only cleared for a mid-size tear -- it sits close to an
        // NPC, where a 64px scar would be sliced by the scenery around them.
        if (next < anchors)
        {
            t->graphicsId = OBJ_EVENT_GFX_INTERSTELLAR_RIFT_SCAR_MED;
            next++;
            continue;
        }
        next++;

        // ...and vary how badly the world is torn at that spot.
        switch (RiftRand(&stream) % 10)
        {
        case 0:
        case 1:
        case 2:
            t->graphicsId = OBJ_EVENT_GFX_INTERSTELLAR_RIFT_SCAR;
            break;
        case 3:
        case 4:
        case 5:
        case 6:
            t->graphicsId = OBJ_EVENT_GFX_INTERSTELLAR_RIFT_SCAR_MED;
            break;
        default:
            t->graphicsId = OBJ_EVENT_GFX_INTERSTELLAR_RIFT_BLIGHT;
            break;
        }
    }
}
