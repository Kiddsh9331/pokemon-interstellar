Route3_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Interstellar_Route3_OnTransition
	.byte 0

@ ---------------------------------------------------------------------------
@ May waits just inside ROUTE 3 to brief the player on MT. MOON. Her hide flag
@ is a TEMP flag, recomputed on every map load: a persistent flag would latch
@ "hidden" from the pre-BROCK visit and she would never appear again.
@ ---------------------------------------------------------------------------
Interstellar_Route3_OnTransition::
	setflag FLAG_TEMP_11
	goto_if_set FLAG_INTERSTELLAR_MAY_ROUTE3_DONE, Interstellar_Route3_OT_End
	goto_if_unset FLAG_DEFEATED_BROCK, Interstellar_Route3_OT_End
	clearflag FLAG_TEMP_11

Interstellar_Route3_OT_End::
	end

Interstellar_Route3_EventScript_MayTrigger::
	lockall
	goto_if_set FLAG_INTERSTELLAR_MAY_ROUTE3_DONE, Interstellar_Route3_EventScript_TrigDone
	goto_if_unset FLAG_DEFEATED_BROCK, Interstellar_Route3_EventScript_TrigDone
	setvar VAR_TEMP_1, 1
	@ The trigger is four columns wide (x 2-5) across every walkable row, so
	@ there is no line through the entrance that misses it. Close the player up
	@ to x=5 first, then walk May to (6, their row): whichever tile they tripped
	@ it on, the two of them end up face to face.
	getplayerxy VAR_0x8004, VAR_0x8005
	call_if_eq VAR_0x8004, 2, Interstellar_Route3_EventScript_PlayerStepUp3
	call_if_eq VAR_0x8004, 3, Interstellar_Route3_EventScript_PlayerStepUp2
	call_if_eq VAR_0x8004, 4, Interstellar_Route3_EventScript_PlayerStepUp1
	call_if_eq VAR_0x8005, 9, Interstellar_Route3_EventScript_MayRow9
	call_if_eq VAR_0x8005, 10, Interstellar_Route3_EventScript_MayRow10
	call_if_eq VAR_0x8005, 11, Interstellar_Route3_EventScript_MayRow11
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox Interstellar_Route3_Text_MayGuide, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_INTERSTELLAR_MAY_ROUTE3_DONE
	applymovement LOCALID_INTERSTELLAR_MAY_ROUTE3, Interstellar_Route3_Movement_MayExit
	waitmovement 0
	removeobject LOCALID_INTERSTELLAR_MAY_ROUTE3
	setflag FLAG_TEMP_11
	releaseall
	end

Interstellar_Route3_EventScript_TrigDone::
	releaseall
	end

@ Spoken to directly instead of walked into.
Interstellar_Route3_EventScript_MayGuide::
	lock
	faceplayer
	msgbox Interstellar_Route3_Text_MayGuide, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_INTERSTELLAR_MAY_ROUTE3_DONE
	applymovement LOCALID_INTERSTELLAR_MAY_ROUTE3, Interstellar_Route3_Movement_MayExit
	waitmovement 0
	removeobject LOCALID_INTERSTELLAR_MAY_ROUTE3
	setflag FLAG_TEMP_11
	release
	end

Interstellar_Route3_EventScript_PlayerStepUp1::
	applymovement LOCALID_PLAYER, Interstellar_Route3_Movement_Step1
	waitmovement 0
	return

Interstellar_Route3_EventScript_PlayerStepUp2::
	applymovement LOCALID_PLAYER, Interstellar_Route3_Movement_Step2
	waitmovement 0
	return

Interstellar_Route3_EventScript_PlayerStepUp3::
	applymovement LOCALID_PLAYER, Interstellar_Route3_Movement_Step3
	waitmovement 0
	return

Interstellar_Route3_EventScript_MayRow9::
	applymovement LOCALID_INTERSTELLAR_MAY_ROUTE3, Interstellar_Route3_Movement_MayToRow9
	waitmovement 0
	return

Interstellar_Route3_EventScript_MayRow10::
	applymovement LOCALID_INTERSTELLAR_MAY_ROUTE3, Interstellar_Route3_Movement_MayToRow10
	waitmovement 0
	return

Interstellar_Route3_EventScript_MayRow11::
	applymovement LOCALID_INTERSTELLAR_MAY_ROUTE3, Interstellar_Route3_Movement_MayToRow11
	waitmovement 0
	return

Interstellar_Route3_Movement_Step1:
	walk_right
	step_end

Interstellar_Route3_Movement_Step2:
	walk_right
	walk_right
	step_end

Interstellar_Route3_Movement_Step3:
	walk_right
	walk_right
	walk_right
	step_end

@ (7,10) -> (6,9), ending face-left: right in front of a player stood at (5,9).
Interstellar_Route3_Movement_MayToRow9:
	walk_up
	walk_left
	step_end

@ (7,10) -> (6,10)
Interstellar_Route3_Movement_MayToRow10:
	walk_left
	step_end

@ (7,10) -> (6,11)
Interstellar_Route3_Movement_MayToRow11:
	walk_down
	walk_left
	step_end

@ Two tiles east is open ground on all three rows (x9-11 is cliff at row 11).
Interstellar_Route3_Movement_MayExit:
	walk_right
	walk_right
	step_end

Interstellar_Route3_Text_MayGuide::
	.string "MAY: BROCK told me you held your\n"
	.string "ground. Good--we need that.\p"
	.string "ROUTE 3 is the only open way east,\n"
	.string "and it leads straight to MT. MOON.\p"
	.string "My dad's scanner caught the same\n"
	.string "signal in there that brought us here.\p"
	.string "I'll scout ahead. If the cave starts\n"
	.string "to change, follow the blue light.$"

Route3_EventScript_Youngster::
	msgbox Route3_Text_TunnelFromCeruleanTiring, MSGBOX_NPC
	end

Route3_EventScript_RouteSign::
	msgbox Route3_Text_RouteSign, MSGBOX_SIGN
	end

Route3_Text_TunnelFromCeruleanTiring::
	.string "I came from CERULEAN, but the road\n"
	.string "changed behind me twice.\p"
	.string "MT. MOON is worse. Every echo in\n"
	.string "there sounds like a different year.$"

Route3_Text_ColtonIntro::
	.string "Hey! You're the trainer everyone\n"
	.string "says looks like somebody else!$"

Route3_Text_ColtonDefeat::
	.string "You beat me again!$"

Route3_Text_ColtonPostBattle::
	.string "The rift keeps dropping POKéMON from\n"
	.string "places my guidebook never listed.$"

Route3_Text_BenIntro::
	.string "Hi! I was hiding from the sky when\n"
	.string "I saw the tear over MT. MOON.\p"
	.string "Battling helps me stop listening to\n"
	.string "it. Let's go!$"

Route3_Text_BenDefeat::
	.string "I don't believe it!$"

Route3_Text_BenPostBattle::
	.string "Are you using a POKéMON CENTER's\n"
	.string "PC for storing your POKéMON?\p"
	.string "Each BOX can hold up to\n"
	.string "30 POKéMON.$"

Route3_Text_JaniceIntro::
	.string "Excuse me!\n"
	.string "You looked at me, didn't you?$"

Route3_Text_JaniceDefeat::
	.string "You're mean!$"

Route3_Text_JanicePostBattle::
	.string "You shouldn't be staring if you\n"
	.string "don't want to battle!$"

Route3_Text_GregIntro::
	.string "Are you a TRAINER?\n"
	.string "Let's get with it right away!$"

Route3_Text_GregDefeat::
	.string "If I had new POKéMON, I would've\n"
	.string "won!$"

Route3_Text_GregPostBattle::
	.string "If a POKéMON BOX on the PC gets\n"
	.string "full, just switch to another BOX.$"

Route3_Text_SallyIntro::
	.string "That look you gave me…\n"
	.string "It's so intriguing!$"

Route3_Text_SallyDefeat::
	.string "Be nice!$"

Route3_Text_SallyPostBattle::
	.string "You can avoid battles by not\n"
	.string "letting TRAINERS see you.$"

Route3_Text_CalvinIntro::
	.string "Hey! You're not wearing shorts!\n"
	.string "What's wrong with you?$"

Route3_Text_CalvinDefeat::
	.string "Lost!\n"
	.string "Lost! Lost!$"

Route3_Text_CalvinPostBattle::
	.string "I always wear shorts, even in\n"
	.string "winter. That's my policy.$"

Route3_Text_JamesIntro::
	.string "I'll battle you with the POKéMON\n"
	.string "I just caught.$"

Route3_Text_JamesDefeat::
	.string "Done like dinner!$"

Route3_Text_JamesPostBattle::
	.string "Trained POKéMON are stronger than\n"
	.string "the wild ones.$"

Route3_Text_RobinIntro::
	.string "Eek!\n"
	.string "Did you touch me?$"

Route3_Text_RobinDefeat::
	.string "That's it?$"

Route3_Text_RobinPostBattle::
	.string "ROUTE 4 is at the foot of\n"
	.string "MT. MOON.$"

Route3_Text_RouteSign::
	.string "ROUTE 3\n"
	.string "MT. MOON AHEAD -- RIFT WARNING$"
