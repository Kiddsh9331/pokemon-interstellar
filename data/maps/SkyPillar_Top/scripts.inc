SkyPillar_Top_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, SkyPillar_Top_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, SkyPillar_Top_OnTransition
	.byte 0

@ Interstellar: the anchor of the Hoenn rift. The cracked-floor era never
@ happened here (VAR_SKY_PILLAR_STATE stays 0), so the top always loads the
@ clean layout. A KO leaves the boss object in place -- catching is the only
@ thing that removes it for good, exactly like the MEWTWO chamber.
SkyPillar_Top_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, SkyPillar_Top_EventScript_TryRemoveRayquaza
	end

SkyPillar_Top_EventScript_TryRemoveRayquaza::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

SkyPillar_Top_OnTransition:
	call_if_lt VAR_SKY_PILLAR_STATE, 2, SkyPillar_Top_EventScript_SetCleanLayout
	@ A full portal only exists during a crossing scene.
	setflag FLAG_INTERSTELLAR_SKYPILLAR_PORTAL_CLOSED
	@ The collapse tears open one by one in the scene; TEMP flags reset on every warp, so hide them here.
	setflag FLAG_TEMP_11
	setflag FLAG_TEMP_12
	setflag FLAG_TEMP_13
	setflag FLAG_TEMP_14
	end

SkyPillar_Top_EventScript_SetCleanLayout::
	setmaplayoutindex LAYOUT_SKY_PILLAR_TOP_CLEAN
	return

Interstellar_EventScript_CorruptedRayquaza::
	lock
	faceplayer
	msgbox Interstellar_SkyPillar_Text_RayquazaStirs, MSGBOX_DEFAULT
	closemessage
	waitse
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	@ Defensive totem: a catch fight should run long, not end in a wipe (+1 Atk with priority Extreme Speed was estimated to sweep Lv 40 teams)
	settotemboost B_POSITION_OPPONENT_LEFT, 0, 1, 0, 0, 1
	setwildbattle SPECIES_RAYQUAZA, 44
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Interstellar_EventScript_RayquazaCaught
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Interstellar_EventScript_RayquazaDefeated
	msgbox Interstellar_SkyPillar_Text_StormStillTurns, MSGBOX_DEFAULT
	release
	end

Interstellar_EventScript_RayquazaCaught::
	setflag FLAG_INTERSTELLAR_RAYQUAZA_CAUGHT
	msgbox Interstellar_SkyPillar_Text_BallGoesStill, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, SPECIES_RAYQUAZA
	special Interstellar_SealCaughtBoss
	playfanfare MUS_OBTAIN_ITEM
	message Interstellar_SkyPillar_Text_VaultCustody
	waitfanfare
	waitmessage
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	fadescreenswapbuffers FADE_FROM_BLACK
	goto Interstellar_EventScript_StormParts
	end

Interstellar_EventScript_RayquazaDefeated::
	@ Beaten is not the same as caught. It rises into its own storm and
	@ comes back down whenever the player does.
	msgbox Interstellar_SkyPillar_Text_RisesIntoStorm, MSGBOX_DEFAULT
	closemessage
	goto Interstellar_EventScript_StormParts
	end

@ ---------------------------------------------------------------------------
@ Either way the anchor is cleansed and the storm lets go of the tower.
@ ---------------------------------------------------------------------------
Interstellar_EventScript_StormParts::
	playse SE_THUNDER
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 2
	setvar VAR_0x8006, 10
	setvar VAR_0x8007, 3
	special ShakeCamera
	waitstate
	msgbox Interstellar_SkyPillar_Text_StormOpens, MSGBOX_DEFAULT
	closemessage
	@ Letting go of the anchor costs the summit, exactly as it cost the chamber
	@ under CERULEAN: tears open one after another, each nearer, until the last
	@ one opens at your back and takes you.
	playse SE_M_EARTHQUAKE
	call Interstellar_SkyPillar_EventScript_Rumble
	msgbox Interstellar_SkyPillar_Text_SummitComesApart, MSGBOX_DEFAULT
	closemessage

	fadescreenswapbuffers FADE_TO_WHITE
	setobjectxy LOCALID_PLAYER, 14, 7
	turnobject LOCALID_PLAYER, DIR_NORTH
	clearflag FLAG_TEMP_11
	addobject 5
	fadescreenswapbuffers FADE_FROM_WHITE
	call Interstellar_SkyPillar_EventScript_Rumble

	fadescreenswapbuffers FADE_TO_WHITE
	clearflag FLAG_TEMP_12
	addobject 6
	fadescreenswapbuffers FADE_FROM_WHITE
	call Interstellar_SkyPillar_EventScript_Rumble

	fadescreenswapbuffers FADE_TO_WHITE
	clearflag FLAG_TEMP_13
	addobject 7
	fadescreenswapbuffers FADE_FROM_WHITE
	call Interstellar_SkyPillar_EventScript_Rumble

	fadescreenswapbuffers FADE_TO_WHITE
	clearflag FLAG_TEMP_14
	addobject 8
	fadescreenswapbuffers FADE_FROM_WHITE
	call Interstellar_SkyPillar_EventScript_Rumble

	@ ...and then a whole one opens, directly behind you.
	playse SE_M_TELEPORT
	fadescreenswapbuffers FADE_TO_WHITE
	clearflag FLAG_INTERSTELLAR_SKYPILLAR_PORTAL_CLOSED
	addobject LOCALID_INTERSTELLAR_SP_GATE
	fadescreenswapbuffers FADE_FROM_WHITE
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 20
	msgbox Interstellar_SkyPillar_Text_PulledThrough, MSGBOX_DEFAULT
	closemessage
	playse SE_M_TELEPORT
	setvar VAR_0x8004, 3
	setvar VAR_0x8005, 3
	setvar VAR_0x8006, 14
	setvar VAR_0x8007, 3
	special ShakeCamera
	waitstate
	removeobject 5
	removeobject 6
	removeobject 7
	removeobject 8
	clearflag FLAG_INTERSTELLAR_SKYPILLAR_SCAR_HIDDEN
	setflag FLAG_INTERSTELLAR_SKYPILLAR_PORTAL_CLOSED
	setvar VAR_INTERSTELLAR_STATE, 15
	fadescreenspeed FADE_TO_WHITE, 1
	msgbox Interstellar_SkyPillar_Text_FarSideWontHold, MSGBOX_DEFAULT
	closemessage
	warp MAP_SLATEPORT_CITY, 19, 42
	waitstate
	releaseall
	end

Interstellar_EventScript_StevenSkyPillar::
	lock
	faceplayer
	msgbox Interstellar_SkyPillar_Text_StevenFerryOffer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Interstellar_EventScript_StevenStays
	msgbox Interstellar_SkyPillar_Text_StevenSkarmory, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	playse SE_M_WING_ATTACK
	waitse
	warp MAP_SLATEPORT_CITY, 19, 42
	waitstate
	release
	end

Interstellar_EventScript_StevenStays::
	msgbox Interstellar_SkyPillar_Text_StevenStays, MSGBOX_DEFAULT
	release
	end

Interstellar_EventScript_SkyPillarScar::
	lock
	msgbox Interstellar_SkyPillar_Text_ScarWestward, MSGBOX_DEFAULT
	release
	end

Interstellar_SkyPillar_Text_RayquazaStirs:
	.string "It is coiled around the summit\n"
	.string "like a scar around a wound.\p"
	.string "The storm turns overhead in a\n"
	.string "slow, patient spiral. It has\l"
	.string "been holding the sky shut for\l"
	.string "a long time.\p"
	.string "It fought the falling star alone,\n"
	.string "and the wound it could not close\l"
	.string "closed around it instead.\p"
	.string "The guardian of the sky opens\n"
	.string "one eye.$"

Interstellar_SkyPillar_Text_StormStillTurns:
	.string "The storm still turns.\p"
	.string "The anchor waits. It has nowhere\n"
	.string "else to be.$"

Interstellar_SkyPillar_Text_BallGoesStill:
	.string "The ball rocks once… twice…\p"
	.string "…and goes still.\p"
	.string "Through its shell, a last curl of\n"
	.string "violet bleeds out and scatters\l"
	.string "on the wind.$"

Interstellar_SkyPillar_Text_VaultCustody:
	.string "The dormant ball was entrusted\n"
	.string "to the RIFT VAULT.\p"
	.string "Inside, faint and slow, its glow\n"
	.string "pulses once.\p"
	.string "Some promises outrank sleep.$"

Interstellar_SkyPillar_Text_RisesIntoStorm:
	.string "The corruption tears away like\n"
	.string "old bandages.\p"
	.string "RAYQUAZA circles the pillar\n"
	.string "once. It looks at you-- long,\l"
	.string "unhurried, remembering.\p"
	.string "Then it rises, up, into the\n"
	.string "heart of its own storm.$"

Interstellar_SkyPillar_Text_StormOpens:
	.string "The spiral overhead slows…\n"
	.string "hesitates…\p"
	.string "…and opens.\p"
	.string "For the first time since the sky\n"
	.string "broke, the sun touches the top\l"
	.string "of the SKY PILLAR.$"

Interstellar_SkyPillar_Text_StevenItRemembered:
	.string "STEVEN: I watched it from the\n"
	.string "stormline. The moment it let go.\p"
	.string "It circled once. Looked down.\n"
	.string "Then it went up, not away.\p"
	.string "…It remembered something.\p"
	.string "Or someone.$"

Interstellar_SkyPillar_Text_GateCrystallizes:
	.string "Light races along the summit\n"
	.string "stones and knots itself into\l"
	.string "a standing scar.\p"
	.string "The rift here is stable now.\n"
	.string "A door, not a wound.$"

Interstellar_SkyPillar_Text_StevenWestward:
	.string "STEVEN: The readings through the\n"
	.string "gate run westward in time.\p"
	.string "Old wood. Incense. A tower that\n"
	.string "burned somewhere else, and here\l"
	.string "never did.\p"
	.string "JOHTO, or I am no geologist.\p"
	.string "Rest first. You have earned a\n"
	.string "region's worth of it.\p"
	.string "When you need the sky, my\n"
	.string "SKARMORY knows the way down.$"

Interstellar_SkyPillar_Text_StevenFerryOffer:
	.string "STEVEN: SKARMORY can have you in\n"
	.string "SLATEPORT before the spray dries.\p"
	.string "Shall we?$"

Interstellar_SkyPillar_Text_StevenSkarmory:
	.string "STEVEN: Hold on tight.$"

Interstellar_SkyPillar_Text_StevenStays:
	.string "STEVEN: Take your time.\p"
	.string "Not many people get to stand in\n"
	.string "this much quiet.$"

Interstellar_SkyPillar_Text_ScarWestward:
	.string "The scar hums, westward in time.\p"
	.string "Old wood. Incense. Bells.\n"
	.string "JOHTO waits on the far side.\p"
	.string "…This is where ACT 2 ends.\p"
	.string "Your save file carries forward\n"
	.string "into ACT 3.\p"
	.string "Thank you for playing\n"
	.string "POKéMON INTERSTELLAR!$"

Interstellar_SkyPillar_Text_SummitComesApart:
	.string "The summit stones split.\p"
	.string "Light comes up through the cracks,\n"
	.string "and every crack is a door.$"

Interstellar_SkyPillar_Text_PulledThrough:
	.string "The wind turns around.\p"
	.string "It goes the wrong way-- into the\n"
	.string "tear at your back-- and takes you\l"
	.string "with it.$"

Interstellar_SkyPillar_Text_FarSideWontHold:
	.string "Westward in time. Old wood.\n"
	.string "Incense. Bells.\p"
	.string "JOHTO, for one breath-- and then\n"
	.string "the far side will not hold, and\l"
	.string "the tear throws you back onto\l"
	.string "salt air.\p"
	.string "SLATEPORT.\p"
	.string "…This is where ACT 2 ends.\p"
	.string "Your save file carries forward\n"
	.string "into ACT 3.\p"
	.string "Thank you for playing\n"
	.string "POKéMON INTERSTELLAR!$"

@ Local copies: the chamber versions live in the FRLG-only script block, this map is built for both targets.
Interstellar_SkyPillar_EventScript_Rumble::
	playse SE_MUD_BALL
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 2
	setvar VAR_0x8006, 8
	setvar VAR_0x8007, 3
	special ShakeCamera
	waitstate
	return

Interstellar_SkyPillar_EventScript_Blight::
	msgbox Interstellar_SkyPillar_Text_Blight, MSGBOX_SIGN
	end

Interstellar_SkyPillar_Text_Blight:
	.string "A tear the size of a hand.\n"
	.string "It hums. The stones around it\l"
	.string "are warm.$"
