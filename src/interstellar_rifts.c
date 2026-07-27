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

// The flash uses the GPU brightness blend, NOT the palette buffers: writing
// palettes here overwrote the weather shading and day/night tint every frame
// and washed the whole map out.
void Interstellar_UpdateStormLightning(void)
{
    // Overcast outdoors only -- a few vanilla interiors are WEATHER_SHADE too,
    // and lightning flashing inside a mansion would be nonsense.
    if (gMapHeader.weather != WEATHER_SHADE || gPaletteFade.active
     || !MapHasNaturalLight(gMapHeader.mapType))
        return;

    if (sLightningPhase != 0)
    {
        u32 bldy;

        sLightningPhase--;
        // double strike, then back to normal
        switch (sLightningPhase)
        {
        case 10:
        case 6:
            bldy = 10;
            break;
        case 9:
        case 5:
            bldy = 5;
            break;
        case 8:
        case 4:
            bldy = 2;
            break;
        default:
            bldy = 0;
            break;
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
                SetGpuReg(REG_OFFSET_BLDCNT, 0);
        }
        return;
    }

    // Roughly every 15-30 seconds. This is the far edge of the storm, not the
    // middle of it -- the middle is waiting in CERULEAN.
    if (++sLightningTimer >= 900 + (Random() % 900))
    {
        sLightningTimer = 0;
        sLightningPhase = 12;
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
