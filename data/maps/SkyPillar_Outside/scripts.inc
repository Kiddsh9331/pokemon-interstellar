SkyPillar_Outside_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SkyPillar_Outside_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, SkyPillar_Outside_OnLoad
	.byte 0

@ Interstellar: the SOOTOPOLIS crisis never reaches this world. The tower
@ door answers to the story (four badges, state 14), and MAY holds the
@ doorway until the scanner has said the anchor's name out loud.
SkyPillar_Outside_OnTransition:
	call Interstellar_SkyPillar_EventScript_SyncMay
	end

Interstellar_SkyPillar_EventScript_SyncMay::
	setflag FLAG_TEMP_11
	setflag FLAG_TEMP_12
	goto_if_lt VAR_INTERSTELLAR_STATE, 14, Interstellar_SkyPillar_EventScript_SyncMayDone
	goto_if_ge VAR_INTERSTELLAR_STATE, 15, Interstellar_SkyPillar_EventScript_SyncMayDone
	goto_if_set FLAG_INTERSTELLAR_RIVAL_SKYPILLAR_DONE, Interstellar_SkyPillar_EventScript_SyncMayShore
	clearflag FLAG_TEMP_11
	goto Interstellar_SkyPillar_EventScript_SyncMayDone

Interstellar_SkyPillar_EventScript_SyncMayShore::
	clearflag FLAG_TEMP_12
Interstellar_SkyPillar_EventScript_SyncMayDone::
	return

SkyPillar_Outside_OnLoad:
	call_if_ge VAR_INTERSTELLAR_STATE, 14, SkyPillar_Outside_EventScript_OpenDoor
	end

SkyPillar_Outside_EventScript_OpenDoor::
	setmetatile 14, 4, METATILE_Pacifidlog_SkyPillar_DoorOpen_Top, FALSE
	setmetatile 14, 5, METATILE_Pacifidlog_SkyPillar_DoorOpen_Bottom, FALSE
	return

Interstellar_EventScript_MaySkyPillar::
	lock
	faceplayer
	msgbox Interstellar_SkyPillarOut_Text_MayIntro, MSGBOX_DEFAULT
	closemessage
	switch VAR_STARTER_MON
	case 0, Interstellar_SkyPillarOut_EventScript_MayBlaziken
	case 1, Interstellar_SkyPillarOut_EventScript_MaySwampert
	case 2, Interstellar_SkyPillarOut_EventScript_MaySceptile
	end

Interstellar_SkyPillarOut_EventScript_MayBlaziken::
	trainerbattle_no_intro TRAINER_INTERSTELLAR_RIVAL_SP_BLAZIKEN, Interstellar_SkyPillarOut_Text_MayDefeat
	goto Interstellar_EventScript_MayAfterBattle
	end

Interstellar_SkyPillarOut_EventScript_MaySwampert::
	trainerbattle_no_intro TRAINER_INTERSTELLAR_RIVAL_SP_SWAMPERT, Interstellar_SkyPillarOut_Text_MayDefeat
	goto Interstellar_EventScript_MayAfterBattle
	end

Interstellar_SkyPillarOut_EventScript_MaySceptile::
	trainerbattle_no_intro TRAINER_INTERSTELLAR_RIVAL_SP_SCEPTILE, Interstellar_SkyPillarOut_Text_MayDefeat
	goto Interstellar_EventScript_MayAfterBattle
	end

Interstellar_EventScript_MayAfterBattle::
	msgbox Interstellar_SkyPillarOut_Text_MayScanner, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_INTERSTELLAR_SP_MAY_DOOR, Common_Movement_ExclamationMark
	waitmovement 0
	delay 30
	msgbox Interstellar_SkyPillarOut_Text_MayItsRayquaza, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_INTERSTELLAR_RIVAL_SKYPILLAR_DONE
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_INTERSTELLAR_SP_MAY_DOOR
	setflag FLAG_TEMP_11
	clearflag FLAG_TEMP_12
	addobject LOCALID_INTERSTELLAR_SP_MAY_SHORE
	fadescreenswapbuffers FADE_FROM_BLACK
	msgbox Interstellar_SkyPillarOut_Text_MayStepsAside, MSGBOX_DEFAULT
	release
	end

Interstellar_EventScript_MayShore::
	lock
	faceplayer
	msgbox Interstellar_SkyPillarOut_Text_MayShore, MSGBOX_DEFAULT
	release
	end

Interstellar_EventScript_LaunchReturn::
	lock
	faceplayer
	msgbox Interstellar_SkyPillarOut_Text_SailorReturn, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Interstellar_EventScript_LaunchWaits
	msgbox Interstellar_SkyPillarOut_Text_SailorCastOff, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	playse SE_SHIP
	waitse
	warp MAP_SLATEPORT_CITY_HARBOR, 8, 11
	waitstate
	release
	end

Interstellar_EventScript_LaunchWaits::
	msgbox Interstellar_SkyPillarOut_Text_SailorWaits, MSGBOX_DEFAULT
	release
	end

SkyPillar_Outside_EventScript_Wallace::
	end

SkyPillar_Outside_EventScript_ClosedDoor::
	msgbox SkyPillar_Outside_Text_DoorIsClosed, MSGBOX_SIGN
	end

SkyPillar_Outside_Text_DoorIsClosed:
	.string "The door is sealed against the\n"
	.string "storm.$"

Interstellar_SkyPillarOut_Text_MayIntro:
	.string "MAY: I checked the badge case.\n"
	.string "It's really you.\p"
	.string "Good. Because I have been standing\n"
	.string "under this thing for an hour, my\l"
	.string "hair is ruined, and these are the\l"
	.string "worst readings I have ever logged.\p"
	.string "The anchor is up there, {PLAYER}.\n"
	.string "Top of the tower. Holding the\l"
	.string "whole storm shut.\p"
	.string "Before you climb-- show me\n"
	.string "you're ready.\p"
	.string "Not for the badge count.\n"
	.string "For me.$"

Interstellar_SkyPillarOut_Text_MayDefeat:
	.string "…Okay.\n"
	.string "Okay. You're ready.$"

Interstellar_SkyPillarOut_Text_MayScanner:
	.string "MAY: I knew you were ready. I\n"
	.string "just needed to feel it.\p"
	.string "Hang on. The scanner finally has\n"
	.string "a clean lock on the anchor.\p"
	.string "Big. Serpentine. Old-- the signal\n"
	.string "is layered like tree rings.\p"
	.string "Wait.\p"
	.string "That profile is in DAD's field\n"
	.string "guide. That's…$"

Interstellar_SkyPillarOut_Text_MayItsRayquaza:
	.string "MAY: …RAYQUAZA.\p"
	.string "The guardian didn't abandon the\n"
	.string "world, {PLAYER}.\p"
	.string "The world's wound took it.\p"
	.string "It fought the sky-breaker alone,\n"
	.string "and the rift closed around it\l"
	.string "like a trap.\p"
	.string "…Go. Cleanse it. Ball or battle,\n"
	.string "either way it goes free.\p"
	.string "I'll hold the door.$"

Interstellar_SkyPillarOut_Text_MayStepsAside:
	.string "MAY walks down to the waterline\n"
	.string "without another word, watching\l"
	.string "the storm turn.$"

Interstellar_SkyPillarOut_Text_MayShore:
	.string "MAY: All this time I was racing\n"
	.string "you to the anchors.\p"
	.string "I didn't think about what it\n"
	.string "would feel like when we found\l"
	.string "one that used to be the good guy.\p"
	.string "Go on. It has waited long enough.$"

Interstellar_SkyPillarOut_Text_SailorReturn:
	.string "RANGER: Some weather, eh?\n"
	.string "Launch is ready when you are.\p"
	.string "Back to SLATEPORT?$"

Interstellar_SkyPillarOut_Text_SailorCastOff:
	.string "RANGER: Casting off!$"

Interstellar_SkyPillarOut_Text_SailorWaits:
	.string "RANGER: No hurry.\p"
	.string "I'll keep her steady.$"
