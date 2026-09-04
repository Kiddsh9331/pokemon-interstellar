@ ---------------------------------------------------------------------------
@ Debug start, gated on INTERSTELLAR_DEBUG_ACT2_START in config/interstellar_debug.h.
@ Nothing here runs in a shipping build.
@
@ The chamber's own objects do the work: MEWTWO (object 1) hides on
@ FLAG_INTERSTELLAR_MEWTWO_CAUGHT, and the rift scar (object 2, on the same
@ tile as the full portal) shows when FLAG_INTERSTELLAR_KANTO_GATE_LOCKED is
@ clear. Talking to it is the ordinary crossing to SLATEPORT.
@ ---------------------------------------------------------------------------

Interstellar_EventScript_DebugAct2Setup::
	@ The anchor is settled and the way out is standing open.
	setflag FLAG_INTERSTELLAR_MEWTWO_CAUGHT
	clearflag FLAG_INTERSTELLAR_KANTO_GATE_LOCKED
	setflag FLAG_INTERSTELLAR_RIFT_PORTAL_CLOSED
	@ The prologue normally hides these; the debug start skips the prologue.
	setflag FLAG_INTERSTELLAR_SLATEPORT_RIFT_SCAR_HIDDEN
	setflag FLAG_INTERSTELLAR_GARY_SCAR_HIDDEN
	setvar VAR_INTERSTELLAR_STATE, 7

	@ Everything ACT 1 would have handed over by now.
	setflag FLAG_BADGE01_GET
	setflag FLAG_BADGE02_GET
	setflag FLAG_INTERSTELLAR_TEST_KIT_ISSUED
	setflag FLAG_SYS_POKEMON_GET
	setflag FLAG_SYS_POKEDEX_GET
	setflag FLAG_RECEIVED_RUNNING_SHOES
	setflag FLAG_SYS_B_DASH

	givemon SPECIES_IVYSAUR, 30
	givemon SPECIES_CHARMELEON, 30
	givemon SPECIES_WARTORTLE, 30
	givemon SPECIES_PIKACHU, 30
	givemon SPECIES_KADABRA, 30
	givemon SPECIES_ONIX, 30

	additem ITEM_POKE_BALL, 40
	additem ITEM_SUPER_POTION, 20
	additem ITEM_REVIVE, 10
	additem ITEM_FULL_HEAL, 10
	end
