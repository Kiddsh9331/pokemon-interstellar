Interstellar_RiftChamber_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Interstellar_RiftChamber_OnTransition
	.byte 0

Interstellar_RiftChamber_OnTransition::
	@ A full portal only exists during a crossing scene.
	setflag FLAG_INTERSTELLAR_RIFT_PORTAL_CLOSED
	@ The collapse tears are placed by the scene, never by the map. TEMP flags,
	@ so if the player ever walks back in here the room is whole again.
	setflag FLAG_TEMP_11
	setflag FLAG_TEMP_12
	setflag FLAG_TEMP_13
	setflag FLAG_TEMP_14
	end

Interstellar_EventScript_CorruptedMewtwo::
	lock
	faceplayer
	msgbox Interstellar_Text_MewtwoStirs, MSGBOX_DEFAULT
	closemessage
	waitse
	playmoncry SPECIES_MEWTWO, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	settotemboost B_POSITION_OPPONENT_LEFT, 1, 0, 0, 1
	setwildbattle SPECIES_MEWTWO, 26
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Interstellar_EventScript_MewtwoCaught
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Interstellar_EventScript_MewtwoDefeated
	msgbox Interstellar_Text_RiftStillPulses, MSGBOX_DEFAULT
	release
	end

Interstellar_EventScript_MewtwoCaught::
	setflag FLAG_INTERSTELLAR_MEWTWO_CAUGHT
	msgbox Interstellar_Text_BallGoesStill, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, SPECIES_MEWTWO
	special Interstellar_SealCaughtBoss
	playfanfare MUS_OBTAIN_ITEM
	message Interstellar_Text_VaultCustody
	waitfanfare
	waitmessage
	closemessage
	@ Cleansed and sealed. The chamber is empty from here on.
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	fadescreenswapbuffers FADE_FROM_BLACK
	goto Interstellar_EventScript_RiftCollapse
	end

Interstellar_EventScript_MewtwoDefeated::
	@ Beaten is not the same as cleansed. The rift is still knotted through it,
	@ so it stays exactly where it is until someone brings an AEON BALL back.
	msgbox Interstellar_Text_MewtwoDriven, MSGBOX_DEFAULT
	closemessage
	goto Interstellar_EventScript_RiftCollapse
	end

@ ---------------------------------------------------------------------------
@ Whatever happened to the anchor, letting go of it costs the chamber. Tears
@ open one after another, each nearer than the last, until one opens under the
@ player and takes them across.
@ ---------------------------------------------------------------------------
Interstellar_EventScript_RiftCollapse::
	playse SE_M_EARTHQUAKE
	call Interstellar_EventScript_CollapseRumble
	msgbox Interstellar_Text_ChamberComesApart, MSGBOX_DEFAULT
	closemessage

	fadescreenspeed FADE_TO_WHITE, 5
	clearflag FLAG_TEMP_11
	addobject LOCALID_INTERSTELLAR_COLLAPSE_SCAR_1
	fadescreenspeed FADE_FROM_WHITE, 5
	call Interstellar_EventScript_CollapseRumble

	fadescreenspeed FADE_TO_WHITE, 5
	clearflag FLAG_TEMP_12
	addobject LOCALID_INTERSTELLAR_COLLAPSE_SCAR_2
	fadescreenspeed FADE_FROM_WHITE, 5
	call Interstellar_EventScript_CollapseRumble

	fadescreenspeed FADE_TO_WHITE, 4
	clearflag FLAG_TEMP_13
	addobject LOCALID_INTERSTELLAR_COLLAPSE_SCAR_3
	fadescreenspeed FADE_FROM_WHITE, 4
	call Interstellar_EventScript_CollapseRumble

	fadescreenspeed FADE_TO_WHITE, 3
	clearflag FLAG_TEMP_14
	addobject LOCALID_INTERSTELLAR_COLLAPSE_SCAR_4
	fadescreenspeed FADE_FROM_WHITE, 3
	call Interstellar_EventScript_CollapseRumble

	@ ...and then a whole one opens.
	playse SE_M_TELEPORT
	fadescreenspeed FADE_TO_WHITE, 2
	clearflag FLAG_INTERSTELLAR_RIFT_PORTAL_CLOSED
	addobject LOCALID_INTERSTELLAR_KANTO_RIFT_PORTAL
	fadescreenspeed FADE_FROM_WHITE, 2
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 20
	msgbox Interstellar_Text_PulledThrough, MSGBOX_DEFAULT
	closemessage
	playse SE_M_TELEPORT
	setvar VAR_0x8004, 3
	setvar VAR_0x8005, 3
	setvar VAR_0x8006, 14
	setvar VAR_0x8007, 3
	special ShakeCamera
	waitstate
	removeobject LOCALID_INTERSTELLAR_COLLAPSE_SCAR_1
	removeobject LOCALID_INTERSTELLAR_COLLAPSE_SCAR_2
	removeobject LOCALID_INTERSTELLAR_COLLAPSE_SCAR_3
	removeobject LOCALID_INTERSTELLAR_COLLAPSE_SCAR_4
	setflag FLAG_INTERSTELLAR_KANTO_GATE_LOCKED
	setvar VAR_INTERSTELLAR_STATE, 8
	fadescreenspeed FADE_TO_WHITE, 1
	warp MAP_SLATEPORT_CITY, 20, 42
	waitstate
	releaseall
	end

Interstellar_EventScript_CollapseRumble::
	playse SE_MUD_BALL
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 2
	setvar VAR_0x8006, 8
	setvar VAR_0x8007, 3
	special ShakeCamera
	waitstate
	return

Interstellar_EventScript_KantoRiftScar::
	lock
	msgbox Interstellar_Text_KantoRiftScar, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Interstellar_EventScript_KantoRiftScarWait
	closemessage
	setflag FLAG_INTERSTELLAR_KANTO_GATE_LOCKED
	clearflag FLAG_INTERSTELLAR_RIFT_PORTAL_CLOSED
	removeobject LOCALID_INTERSTELLAR_KANTO_RIFT_SCAR
	addobject LOCALID_INTERSTELLAR_KANTO_RIFT_PORTAL
	playse SE_THUNDER
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 2
	setvar VAR_0x8006, 8
	setvar VAR_0x8007, 3
	special ShakeCamera
	waitstate
	delay 30
	fadescreenspeed FADE_TO_WHITE, 2
	setvar VAR_INTERSTELLAR_STATE, 8
	warp MAP_SLATEPORT_CITY, 20, 42
	waitstate
	release
	end

Interstellar_EventScript_KantoRiftScarWait::
	msgbox Interstellar_Text_KantoRiftScarWait, MSGBOX_DEFAULT
	release
	end

Interstellar_EventScript_RiftBlight::
	lock
	faceplayer
	msgbox Interstellar_Text_RiftBlight, MSGBOX_DEFAULT
	release
	end

Interstellar_EventScript_ForestRiftScar::
	lock
	faceplayer
	msgbox Interstellar_Text_ForestRiftScar, MSGBOX_DEFAULT
	release
	end

Interstellar_EventScript_PalletRiftScar::
	lock
	faceplayer
	msgbox Interstellar_Text_PalletRiftScar, MSGBOX_DEFAULT
	release
	end

Interstellar_EventScript_Route1RiftScar::
	lock
	faceplayer
	msgbox Interstellar_Text_Route1RiftScar, MSGBOX_DEFAULT
	release
	end

Interstellar_EventScript_MtMoonRiftScar::
	lock
	faceplayer
	msgbox Interstellar_Text_MtMoonRiftScar, MSGBOX_DEFAULT
	release
	end

Interstellar_EventScript_CeruleanRiftScar::
	lock
	faceplayer
	msgbox Interstellar_Text_CeruleanRiftScar, MSGBOX_DEFAULT
	release
	end

Interstellar_RiftChamber_EventScript_ExitTrigger::
	lockall
	msgbox Interstellar_Text_LeaveRift, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Interstellar_RiftChamber_EventScript_StepBack
	closemessage
	warp MAP_CERULEAN_CITY, 9, 14
	waitstate
	releaseall
	end

Interstellar_RiftChamber_EventScript_StepBack::
	closemessage
	applymovement LOCALID_PLAYER, Interstellar_RiftChamber_Movement_StepUp
	waitmovement 0
	releaseall
	end

Interstellar_RiftChamber_Movement_StepUp:
	walk_up
	step_end

Interstellar_Text_RiftBlight:
	.string "The ground has split into black\n"
	.string "glass and cold, unfamiliar stone.\p"
	.string "The air around it hums one note\n"
	.string "below anything you can hear.$"

Interstellar_Text_MewtwoStirs:
	.string "Something in the dark uncoils.\p"
	.string "Violet light crawls the walls\n"
	.string "like frost. A pressure like a\l"
	.string "held breath fills the chamber.\p"
	.string "The creature turns.\n"
	.string "Its eyes are two rifts, opening.$"

Interstellar_Text_BallGoesStill:
	.string "The ball snaps shut-- and the\n"
	.string "violet light pours OUT of it,\l"
	.string "thinning, dissolving.\p"
	.string "Inside, something sleeps deeper\n"
	.string "than sleep.$"

Interstellar_Text_VaultCustody:
	.string "The cleansed anchor is beyond\n"
	.string "exhaustion. Its power will not\l"
	.string "wake until every rift is sealed.\p"
	.string "Its AEON BALL was entrusted\n"
	.string "to the RIFT VAULT.$"

@ Unused: the anchor is only freed by catching it, never by winning.
Interstellar_Text_MewtwoCleansed:
	.string "The corrupted aura shatters\n"
	.string "like old glass.\p"
	.string "For a moment, the creature simply\n"
	.string "breathes.\p"
	.string "Then it inclines its head--\n"
	.string "almost a bow-- and recedes into\l"
	.string "the deeper dark to heal.\p"
	.string "It is free.\n"
	.string "Perhaps, someday, it will let\l"
	.string "you prove yourself again.$"

Interstellar_Text_MewtwoDriven:
	.string "The corrupted aura gutters--\n"
	.string "then draws itself back in.\p"
	.string "The creature sinks down where it\n"
	.string "stands. It does not leave.\p"
	.string "It cannot. The rift is knotted\n"
	.string "through it, and beating a thing\l"
	.string "is not the same as freeing it.\p"
	.string "Only the ball can do that.$"

Interstellar_Text_ChamberComesApart:
	.string "The floor answers with a sound\n"
	.string "like a held breath letting go.\p"
	.string "Something that was holding this\n"
	.string "room together has stopped.$"

Interstellar_Text_PulledThrough:
	.string "The last tear opens wide enough\n"
	.string "to walk through-- and does not\l"
	.string "wait to be walked through.\p"
	.string "{PLAYER} is pulled off their feet.$"

Interstellar_Text_RiftStillPulses:
	.string "The rift pulses on, unbroken.\n"
	.string "The anchor waits.$"

Interstellar_Text_RiftCrystallizes:
	.string "The rift convulses--\p"
	.string "then folds in on itself, leaving\n"
	.string "only a small, star-shaped scar\l"
	.string "in the stone.\p"
	.string "It is quiet now. Not closed--\n"
	.string "only waiting.$"

Interstellar_Text_KantoRiftScar:
	.string "The scar trembles. For a moment,\n"
	.string "warm sunlight leaks through its\l"
	.string "black center.\p"
	.string "Pull it open and cross to HOENN?$"

Interstellar_Text_KantoRiftScarWait:
	.string "The scar rests in the stone.\n"
	.string "It will not open by itself.$"

Interstellar_Text_ForestRiftScar:
	.string "The fog bends toward a black\n"
	.string "scar between the trees.\p"
	.string "It is no gate--only the husk\n"
	.string "of a wound that never quite\l"
	.string "closed.\p"
	.string "The forest is growing around it.$"

Interstellar_Text_PalletRiftScar:
	.string "The wound you fell through has\n"
	.string "left a second shadow by the sea.\p"
	.string "It gives off no heat. Only a low,\n"
	.string "unbroken pressure behind the eyes.$"

Interstellar_Text_Route1RiftScar:
	.string "Grass leans away from the dark\n"
	.string "oval as if a storm is coming.\p"
	.string "For a moment, something moves on\n"
	.string "the other side of the black glass.$"

Interstellar_Text_MtMoonRiftScar:
	.string "A dark fold trembles in the\n"
	.string "cave air.\p"
	.string "Moonstone dust orbits it in\n"
	.string "tiny, impossible circles.\p"
	.string "Something ancient is stirring\n"
	.string "beneath MT. MOON.$"

Interstellar_Text_CeruleanRiftScar:
	.string "Rain vanishes into the black\n"
	.string "spiral before it can touch it.\p"
	.string "CERULEAN's water has been pulled\n"
	.string "out of its old paths by rift\l"
	.string "pressure.$"

Interstellar_Text_LeaveRift:
	.string "The way back to CERULEAN shimmers\n"
	.string "at the cave mouth.\p"
	.string "Leave the rift chamber?$"
