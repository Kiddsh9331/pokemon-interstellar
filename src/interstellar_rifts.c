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
    const struct RiftSpot *spots;
};

#include "data/interstellar_rift_spots.h"

#define MAX_RIFT_SPOTS 16

static u32 sRiftSeed; // zero at boot, rolled on first overworld load

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
    u32 i, count, stream, next;

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

    for (i = 0; i < count; i++)
        order[i] = i;

    for (i = count - 1; i > 0; i--)
    {
        u32 j = RiftRand(&stream) % (i + 1);
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
