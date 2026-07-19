Interstellar_OaksLab_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Interstellar_OaksLab_OnFrame
	.byte 0

Interstellar_OaksLab_OnFrame:
	map_script_2 VAR_INTERSTELLAR_STATE, 5, Interstellar_OaksLab_EventScript_Wake
	.2byte 0

Interstellar_OaksLab_EventScript_Wake::
	lockall
	delay 40
	msgbox Interstellar_OaksLab_Text_Wake, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_INTERSTELLAR_OAK, Interstellar_OaksLab_Movement_OakApproach
	waitmovement 0
	msgbox Interstellar_OaksLab_Text_OakEasyNow, MSGBOX_DEFAULT
	closemessage
	delay 20
	msgbox Interstellar_OaksLab_Text_OakTheSkyBroke, MSGBOX_DEFAULT
	closemessage
	msgbox Interstellar_OaksLab_Text_OakYouCrossed, MSGBOX_DEFAULT
	closemessage
	playfanfare MUS_OBTAIN_ITEM
	message Interstellar_OaksLab_Text_ReceivedFieldKit
	waitfanfare
	waitmessage
	giveitem ITEM_POKE_BALL, 5
	giveitem ITEM_POTION, 3
	giveitem ITEM_ANTIDOTE, 2
	setflag FLAG_SYS_POKEDEX_GET
	special EnableNationalPokedex
	setflag FLAG_SYS_B_DASH
	msgbox Interstellar_OaksLab_Text_OakRunningShoes, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_EXP_SHARE
	msgbox Interstellar_OaksLab_Text_OakExpShare, MSGBOX_DEFAULT
	closemessage
	setrespawn HEAL_LOCATION_PALLET_TOWN
	setvar VAR_INTERSTELLAR_STATE, 6
	releaseall
	end

Interstellar_EventScript_Oak::
	lock
	faceplayer
	goto_if_eq VAR_INTERSTELLAR_STATE, 7, Interstellar_EventScript_OakGateOpen
	goto_if_eq VAR_INTERSTELLAR_STATE, 8, Interstellar_EventScript_OakGateOpen
	msgbox Interstellar_OaksLab_Text_OakRestAMoment, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Interstellar_EventScript_OakHint
	call Interstellar_EventScript_OakHeal
	goto Interstellar_EventScript_OakHint
	end

Interstellar_EventScript_OakHeal::
	fadescreen FADE_TO_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
	fadescreen FADE_FROM_BLACK
	msgbox Interstellar_OaksLab_Text_OakThereWeAre, MSGBOX_DEFAULT
	return

Interstellar_EventScript_OakHint::
	msgbox Interstellar_OaksLab_Text_OakHint, MSGBOX_DEFAULT
	release
	end

Interstellar_EventScript_OakGateOpen::
	msgbox Interstellar_OaksLab_Text_OakGateOpen, MSGBOX_DEFAULT
	release
	end

Interstellar_EventScript_OakAide::
	msgbox Interstellar_OaksLab_Text_Aide1, MSGBOX_NPC
	end

Interstellar_EventScript_OakAide2::
	msgbox Interstellar_OaksLab_Text_Aide2, MSGBOX_NPC
	end

Interstellar_OaksLab_Movement_OakApproach:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Interstellar_OaksLab_Text_Wake:
	.string "The lab smells of machine oil\n"
	.string "and old tea.\p"
	.string "Your legs remember how to stand.\n"
	.string "Barely.$"

Interstellar_OaksLab_Text_OakEasyNow:
	.string "OAK: Sit. Breathe.\p"
	.string "I watched the sky tear open and\n"
	.string "deliver you to my doorstep,\l"
	.string "clutching that POKé BALL like\l"
	.string "the last real thing in the world.\p"
	.string "Perhaps it was.\p"
	.string "I am PROF. OAK. This is PALLET\n"
	.string "TOWN... though I suspect that\l"
	.string "name means nothing to you.\p"
	.string "You're a long way from HOENN,\n"
	.string "child. Farther than miles.$"

Interstellar_OaksLab_Text_OakTheSkyBroke:
	.string "OAK: The sky broke.\n"
	.string "Time broke with it.\p"
	.string "My KANTO is wearing three\n"
	.string "different centuries at once,\l"
	.string "and it is not alone.\p"
	.string "RIFTS, we call them.\n"
	.string "Doors torn between the eras.\p"
	.string "The largest one seethes in a cave\n"
	.string "north of CERULEAN. It holds this\l"
	.string "whole region hostage-- and\l"
	.string "something inside is holding\l"
	.string "IT open.$"

Interstellar_OaksLab_Text_OakYouCrossed:
	.string "OAK: You crossed a rift and\n"
	.string "lived. Nobody else has.\p"
	.string "That makes you, {PLAYER}, the most\n"
	.string "important trainer in the world.$"

Interstellar_OaksLab_Text_ReceivedFieldKit:
	.string "OAK handed over his old field kit\n"
	.string "and a POKéDEX!$"

Interstellar_OaksLab_Text_OakRunningShoes:
	.string "OAK: The RUNNING SHOES were my\n"
	.string "grandson's. He'd want a rival out\l"
	.string "there somewhere.\p"
	.string "Go west, then north. PEWTER CITY\n"
	.string "first-- BROCK is holding that\l"
	.string "frontier together.\p"
	.string "Earn his badge, and MISTY's in\n"
	.string "CERULEAN. Then find STEVEN STONE\l"
	.string "at the cave. He's expecting you.$"

Interstellar_OaksLab_Text_OakRestAMoment:
	.string "OAK: Rest a moment?$"

Interstellar_OaksLab_Text_OakThereWeAre:
	.string "OAK: There we are.\n"
	.string "Right as rain.$"

Interstellar_OaksLab_Text_OakHint:
	.string "OAK: The anchor sits in a cave\n"
	.string "north of CERULEAN.\p"
	.string "BROCK first. Then MISTY.\n"
	.string "Then STEVEN, at the west bank.\p"
	.string "One badge at a time, {PLAYER}.$"

Interstellar_OaksLab_Text_OakGateOpen:
	.string "OAK: The readings from CERULEAN...\n"
	.string "The gate is stable. Fixed.\p"
	.string "And its light is WARM, {PLAYER}.\n"
	.string "Hoenn-warm.\p"
	.string "Go home. Find BIRCH.\n"
	.string "Finish this.$"

Interstellar_OaksLab_Text_Aide1:
	.string "The professor hasn't slept since\n"
	.string "the readings spiked.\p"
	.string "Neither have I, but nobody writes\n"
	.string "papers about aides.$"

Interstellar_OaksLab_Text_Aide2:
	.string "The fossils in PEWTER's museum\n"
	.string "woke up last month.\p"
	.string "The curator has stopped calling\n"
	.string "them exhibits and started calling\l"
	.string "them colleagues.$"

Interstellar_OaksLab_Text_OakExpShare:
	.string "OAK: And this-- an EXP. SHARE\n"
	.string "unit from my aide's network.\p"
	.string "Use it from the KEY ITEMS pocket\n"
	.string "to switch it on or off. While it\l"
	.string "runs, your whole party learns\l"
	.string "from every battle.$"
