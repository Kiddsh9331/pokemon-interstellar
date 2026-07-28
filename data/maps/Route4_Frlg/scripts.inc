Route4_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Interstellar_Route4_OnTransition
	.byte 0

Route4_EventScript_Unused::
	end

Route4_EventScript_Woman::
	msgbox Route4_Text_TrippedOverGeodude, MSGBOX_NPC
	end

Route4_EventScript_MtMoonSign::
	msgbox Route4_Text_MtMoonEntrance, MSGBOX_SIGN
	end

Route4_EventScript_RouteSign::
	msgbox Route4_Text_RouteSign, MSGBOX_SIGN
	end

Route4_Text_TrippedOverGeodude::
	.string "Ouch! I tripped over a rocky\n"
	.string "POKéMON, GEODUDE!$"

Route4_Text_CrissyIntro::
	.string "I came to MT. MOON in search of\n"
	.string "mushroom POKéMON.$"

Route4_Text_CrissyDefeat::
	.string "After all I did to catch them!$"

Route4_Text_CrissyPostBattle::
	.string "There might not be any more\n"
	.string "mushrooms here.\p"
	.string "I think I got them all.$"

Route4_Text_MtMoonEntrance::
	.string "MT. MOON\n"
	.string "Tunnel Entrance$"

Route4_Text_RouteSign::
	.string "ROUTE 4\n"
	.string "MT. MOON - CERULEAN CITY$"

Text_MegaPunchTeach::
	.string "A punch of roaring ferocity!\p"
	.string "Packed with destructive power!\p"
	.string "When the chips are down,\n"
	.string "MEGA PUNCH is the ultimate attack!\l"
	.string "You agree, yes?\p"
	.string "Now!\n"
	.string "Let me teach it to your POKéMON!$"

Text_MegaPunchDeclined::
	.string "You'll be back when you understand\n"
	.string "the worth of MEGA PUNCH.$"

Text_MegaPunchWhichMon::
	.string "Fine!\n"
	.string "Which POKéMON will learn it?$"

Text_MegaPunchTaught::
	.string "Now, we are comrades in the way of\n"
	.string "punching!\p"
	.string "You should go before you're seen\n"
	.string "by the misguided fool who trains\l"
	.string "only his silly kicking over there.$"

Text_MegaKickTeach::
	.string "A kick of brutal ferocity!\p"
	.string "Packed with destructive power!\p"
	.string "When you get right down to it,\n"
	.string "MEGA KICK is the ultimate attack!\l"
	.string "Don't you agree?\p"
	.string "Okay!\n"
	.string "I'll teach it to your POKéMON!$"

Text_MegaKickDeclined::
	.string "You'll come crawling back when you\n"
	.string "realize the value of MEGA KICK.$"

Text_MegaKickWhichMon::
	.string "All right!\n"
	.string "Which POKéMON wants to learn it?$"

Text_MegaKickTaught::
	.string "Now, we are soul mates in the way\n"
	.string "of kicking!\p"
	.string "You should run before you're seen\n"
	.string "by the deluded nitwit who trains\l"
	.string "only simple punching over there.$"

Route4_Text_PeopleLikeAndRespectBrock::
	.string "Oh, wow, that's the BOULDERBADGE!\n"
	.string "You got it from BROCK, didn't you?\p"
	.string "BROCK is cool. He's not just tough.\n"
	.string "People like and respect him.\p"
	.string "I want to become a GYM LEADER\n"
	.string "like him.$"

Interstellar_Route4_OnTransition::
	goto_if_set FLAG_INTERSTELLAR_RIVAL4_DONE, Interstellar_Route4_OT_HideBoth
	@ May is the fixed Interstellar rival, independent of player gender.
	clearflag FLAG_TEMP_11
	setflag FLAG_TEMP_12
	end

Interstellar_Route4_OT_HideBoth::
	setflag FLAG_TEMP_11
	setflag FLAG_TEMP_12
	end

Interstellar_Route4_EventScript_RivalTrigger::
	lockall
	setvar VAR_TEMP_1, 1
	goto_if_set FLAG_INTERSTELLAR_RIVAL4_DONE, Interstellar_Route4_EventScript_TrigDone
	goto Interstellar_Route4_EventScript_RivalMay

Interstellar_Route4_EventScript_BrendanTreecko::
	trainerbattle_no_intro TRAINER_RIVAL_ROUTE22_LATE_BULBASAUR, Interstellar_Route4_Text_RivalDefeat
	goto Interstellar_Route4_EventScript_AfterBattleBrendan
	end

Interstellar_Route4_EventScript_BrendanTorchic::
	trainerbattle_no_intro TRAINER_RIVAL_ROUTE22_LATE_CHARMANDER, Interstellar_Route4_Text_RivalDefeat
	goto Interstellar_Route4_EventScript_AfterBattleBrendan
	end

Interstellar_Route4_EventScript_BrendanMudkip::
	trainerbattle_no_intro TRAINER_RIVAL_ROUTE22_LATE_SQUIRTLE, Interstellar_Route4_Text_RivalDefeat
	goto Interstellar_Route4_EventScript_AfterBattleBrendan
	end

Interstellar_Route4_EventScript_RivalMay::
	applymovement LOCALID_INTERSTELLAR_RIVAL_MAY, Interstellar_Route4_Movement_RivalNotice
	waitmovement 0
	@ May idles at (43,5); the player trips this anywhere in x41-42, rows 6-9.
	@ Walk her into their column so she ends up directly above them, facing down.
	getplayerxy VAR_0x8004, VAR_0x8005
	call_if_eq VAR_0x8005, 6, Interstellar_Route4_EventScript_MayRow6
	call_if_eq VAR_0x8005, 7, Interstellar_Route4_EventScript_MayRow7
	call_if_eq VAR_0x8005, 8, Interstellar_Route4_EventScript_MayRow8
	call_if_eq VAR_0x8005, 9, Interstellar_Route4_EventScript_MayRow9
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox Interstellar_Route4_Text_RivalAlive, MSGBOX_DEFAULT
	closemessage
	switch VAR_STARTER_MON
	case 0, Interstellar_Route4_EventScript_MayTreecko
	case 1, Interstellar_Route4_EventScript_MayTorchic
	case 2, Interstellar_Route4_EventScript_MayMudkip
	end

Interstellar_Route4_EventScript_MayTreecko::
	trainerbattle_no_intro TRAINER_RIVAL_ROUTE22_EARLY_BULBASAUR, Interstellar_Route4_Text_RivalDefeat
	goto Interstellar_Route4_EventScript_AfterBattleMay
	end

Interstellar_Route4_EventScript_MayTorchic::
	trainerbattle_no_intro TRAINER_RIVAL_ROUTE22_EARLY_CHARMANDER, Interstellar_Route4_Text_RivalDefeat
	goto Interstellar_Route4_EventScript_AfterBattleMay
	end

Interstellar_Route4_EventScript_MayMudkip::
	trainerbattle_no_intro TRAINER_RIVAL_ROUTE22_EARLY_SQUIRTLE, Interstellar_Route4_Text_RivalDefeat
	goto Interstellar_Route4_EventScript_AfterBattleMay
	end

Interstellar_Route4_EventScript_AfterBattleBrendan::
	msgbox Interstellar_Route4_Text_RivalHealsYou, MSGBOX_DEFAULT
	closemessage
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
	msgbox Interstellar_Route4_Text_RivalParting, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_INTERSTELLAR_RIVAL_BRENDAN, Interstellar_Route4_Movement_RivalExit
	waitmovement 0
	removeobject LOCALID_INTERSTELLAR_RIVAL_BRENDAN
	setflag FLAG_INTERSTELLAR_RIVAL4_DONE
	releaseall
	end

Interstellar_Route4_EventScript_AfterBattleMay::
	msgbox Interstellar_Route4_Text_RivalHealsYou, MSGBOX_DEFAULT
	closemessage
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
	msgbox Interstellar_Route4_Text_RivalParting, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_INTERSTELLAR_RIVAL_MAY, Interstellar_Route4_Movement_RivalExit
	waitmovement 0
	removeobject LOCALID_INTERSTELLAR_RIVAL_MAY
	setflag FLAG_INTERSTELLAR_RIVAL4_DONE
	releaseall
	end

Interstellar_Route4_EventScript_TrigDone::
	releaseall
	end

Interstellar_Route4_Movement_RivalNotice:
	emote_exclamation_mark
	delay_16
	step_end





Interstellar_Route4_Movement_RivalApproach:
	walk_down
	face_left
	step_end

Interstellar_Route4_Movement_RivalExit:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Interstellar_Route4_Text_RivalAlive:
	.string "MAY: You made it through MT. MOON!\p"
	.string "That cave keeps changing behind me.\n"
	.string "I marked the safe turns in my notes.\p"
	.string "Dad's scanner says the tear north\n"
	.string "of CERULEAN is getting louder.\p"
	.string "Before we chase it, show me what\n"
	.string "you and your partner can do!$"

Interstellar_Route4_Text_RivalDefeat:
	.string "Ha...!\n"
	.string "You've still got it.$"

Interstellar_Route4_Text_RivalHealsYou:
	.string "I got my team patched up back at\n"
	.string "the POKéMON CENTER. Here--$"

Interstellar_Route4_Text_RivalParting:
	.string "The scanner says the BIG anchor is\n"
	.string "north of CERULEAN.\p"
	.string "Whatever is there doesn't read like\n"
	.string "a POKéMON anymore.\p"
	.string "Be careful, {PLAYER}. I'll scout\n"
	.string "east and meet you at the next tear.$"

Interstellar_Route4_EventScript_MayRow6::
	call_if_eq VAR_0x8004, 41, Interstellar_Route4_EventScript_MayTo41_6
	call_if_eq VAR_0x8004, 42, Interstellar_Route4_EventScript_MayTo42_6
	return

Interstellar_Route4_EventScript_MayRow7::
	call_if_eq VAR_0x8004, 41, Interstellar_Route4_EventScript_MayTo41_7
	call_if_eq VAR_0x8004, 42, Interstellar_Route4_EventScript_MayTo42_7
	return

Interstellar_Route4_EventScript_MayRow8::
	call_if_eq VAR_0x8004, 41, Interstellar_Route4_EventScript_MayTo41_8
	call_if_eq VAR_0x8004, 42, Interstellar_Route4_EventScript_MayTo42_8
	return

Interstellar_Route4_EventScript_MayRow9::
	call_if_eq VAR_0x8004, 41, Interstellar_Route4_EventScript_MayTo41_9
	call_if_eq VAR_0x8004, 42, Interstellar_Route4_EventScript_MayTo42_9
	return

Interstellar_Route4_EventScript_MayTo41_6::
	applymovement LOCALID_INTERSTELLAR_RIVAL_MAY, Interstellar_Route4_Movement_MayTo41_6
	waitmovement 0
	return

Interstellar_Route4_EventScript_MayTo41_7::
	applymovement LOCALID_INTERSTELLAR_RIVAL_MAY, Interstellar_Route4_Movement_MayTo41_7
	waitmovement 0
	return

Interstellar_Route4_EventScript_MayTo41_8::
	applymovement LOCALID_INTERSTELLAR_RIVAL_MAY, Interstellar_Route4_Movement_MayTo41_8
	waitmovement 0
	return

Interstellar_Route4_EventScript_MayTo41_9::
	applymovement LOCALID_INTERSTELLAR_RIVAL_MAY, Interstellar_Route4_Movement_MayTo41_9
	waitmovement 0
	return

Interstellar_Route4_EventScript_MayTo42_6::
	applymovement LOCALID_INTERSTELLAR_RIVAL_MAY, Interstellar_Route4_Movement_MayTo42_6
	waitmovement 0
	return

Interstellar_Route4_EventScript_MayTo42_7::
	applymovement LOCALID_INTERSTELLAR_RIVAL_MAY, Interstellar_Route4_Movement_MayTo42_7
	waitmovement 0
	return

Interstellar_Route4_EventScript_MayTo42_8::
	applymovement LOCALID_INTERSTELLAR_RIVAL_MAY, Interstellar_Route4_Movement_MayTo42_8
	waitmovement 0
	return

Interstellar_Route4_EventScript_MayTo42_9::
	applymovement LOCALID_INTERSTELLAR_RIVAL_MAY, Interstellar_Route4_Movement_MayTo42_9
	waitmovement 0
	return

@ (43,5) -> (41,5), one tile above a player stood at (41,6)
Interstellar_Route4_Movement_MayTo41_6:
	walk_left
	walk_left
	walk_in_place_faster_down
	step_end

@ (43,5) -> (41,6), one tile above a player stood at (41,7)
Interstellar_Route4_Movement_MayTo41_7:
	walk_down
	walk_left
	walk_left
	walk_in_place_faster_down
	step_end

@ (43,5) -> (41,7), one tile above a player stood at (41,8)
Interstellar_Route4_Movement_MayTo41_8:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_in_place_faster_down
	step_end

@ (43,5) -> (41,8), one tile above a player stood at (41,9)
Interstellar_Route4_Movement_MayTo41_9:
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_in_place_faster_down
	step_end

@ (43,5) -> (42,5), one tile above a player stood at (42,6)
Interstellar_Route4_Movement_MayTo42_6:
	walk_left
	walk_in_place_faster_down
	step_end

@ (43,5) -> (42,6), one tile above a player stood at (42,7)
Interstellar_Route4_Movement_MayTo42_7:
	walk_down
	walk_left
	walk_in_place_faster_down
	step_end

@ (43,5) -> (42,7), one tile above a player stood at (42,8)
Interstellar_Route4_Movement_MayTo42_8:
	walk_down
	walk_down
	walk_left
	walk_in_place_faster_down
	step_end

@ (43,5) -> (42,8), one tile above a player stood at (42,9)
Interstellar_Route4_Movement_MayTo42_9:
	walk_down
	walk_down
	walk_down
	walk_left
	walk_in_place_faster_down
	step_end

