#ifndef GUARD_CONFIG_INTERSTELLAR_DEBUG_H
#define GUARD_CONFIG_INTERSTELLAR_DEBUG_H

// TRUE: a new game starts in the rift chamber under CERULEAN with MEWTWO
// already dealt with, a party, both KANTO badges and the ACT 1 bag. Walk down
// to the rift scar, answer YES, and the crossing takes you to SLATEPORT.
// Everything before that point -- LITTLEROOT, PALLET, the KANTO gyms -- is
// skipped. Must be FALSE in a shipping build.
#define INTERSTELLAR_DEBUG_ACT2_START   FALSE

// TRUE: nothing in your party ever refuses an order, whatever its level or where it
// came from. B_OBEDIENCE_MECHANICS is GEN_LATEST, which applies the badge level cap to
// your OWN Pokemon by met level and not just to traded ones, so a demo that hands out a
// catch-up party far above the badges it also hands out would disobey constantly.
// A demo convenience only: set FALSE for a full release, where the badges are earned.
#define INTERSTELLAR_DEMO_ALWAYS_OBEY   TRUE

#endif // GUARD_CONFIG_INTERSTELLAR_DEBUG_H
