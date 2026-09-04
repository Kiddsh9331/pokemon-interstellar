MtChimney_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, MtChimney_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, MtChimney_OnTransition
	.byte 0

MtChimney_OnTransition:
	@ Interstellar: no more ash on a mountain that grows gardens.
	setvar VAR_JAGGED_PASS_ASH_WEATHER, 0
	call Interstellar_MtChimney_EventScript_SyncFlannery
	end

Interstellar_MtChimney_EventScript_SyncFlannery::
	setflag FLAG_INTERSTELLAR_HIDE_CHIMNEY_FLANNERY
	setflag FLAG_INTERSTELLAR_HIDE_CHIMNEY_MAGMA_PAIR
	goto_if_lt VAR_INTERSTELLAR_STATE, 12, Interstellar_MtChimney_EventScript_SyncFlanneryDone
	goto_if_ge VAR_INTERSTELLAR_STATE, 13, Interstellar_MtChimney_EventScript_SyncFlanneryDone
	clearflag FLAG_INTERSTELLAR_HIDE_CHIMNEY_FLANNERY
	goto_if_set FLAG_INTERSTELLAR_CHIMNEY_TAG_DONE, Interstellar_MtChimney_EventScript_SyncFlanneryDone
	clearflag FLAG_INTERSTELLAR_HIDE_CHIMNEY_MAGMA_PAIR
Interstellar_MtChimney_EventScript_SyncFlanneryDone::
	return

MtChimney_OnResume:
	end

MtChimney_EventScript_Archie::
	lock
	faceplayer
	call_if_unset FLAG_EVIL_LEADER_PLEASE_STOP, MtChimney_EventScript_ArchieGoStopTeamMagma
	call_if_set FLAG_EVIL_LEADER_PLEASE_STOP, MtChimney_EventScript_ArchieBusyFighting
	closemessage
	applymovement LOCALID_MT_CHIMNEY_ARCHIE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag FLAG_EVIL_LEADER_PLEASE_STOP
	release
	end

MtChimney_EventScript_ArchieGoStopTeamMagma::
	msgbox MtChimney_Text_ArchieGoStopTeamMagma, MSGBOX_DEFAULT
	return

MtChimney_EventScript_ArchieBusyFighting::
	msgbox MtChimney_Text_ArchieIHaveMyHandsFull, MSGBOX_DEFAULT
	return

MtChimney_EventScript_Maxie::
	lockall
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
	msgbox MtChimney_Text_MeteoriteWillActivateVolcano, MSGBOX_DEFAULT
	applymovement LOCALID_MT_CHIMNEY_MAXIE, Common_Movement_FacePlayer
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_MT_CHIMNEY_MAXIE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MT_CHIMNEY_MAXIE, Common_Movement_Delay48
	waitmovement 0
	msgbox MtChimney_Text_MaxieIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_MAXIE_MT_CHIMNEY, MtChimney_Text_MaxieDefeat
	msgbox MtChimney_Text_MaxieYouHaventSeenLastOfMagma, MSGBOX_DEFAULT
	closemessage
	delay 30
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_MT_CHIMNEY_MAXIE
	removeobject LOCALID_MT_CHIMNEY_MAGMA_GRUNT_1
	removeobject LOCALID_MT_CHIMNEY_TABITHA
	removeobject LOCALID_MT_CHIMNEY_MAGMA_GRUNT_2
	setflag FLAG_HIDE_MT_CHIMNEY_TEAM_MAGMA
	fadescreenswapbuffers FADE_FROM_BLACK
	setobjectxyperm LOCALID_MT_CHIMNEY_ARCHIE, 10, 12
	addobject LOCALID_MT_CHIMNEY_ARCHIE
	call_if_eq VAR_FACING, DIR_EAST, MtChimney_EventScript_ArchieApproachPlayerEast
	call_if_eq VAR_FACING, DIR_NORTH, MtChimney_EventScript_ArchieApproachPlayerNorth
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox MtChimney_Text_ArchieThankYou, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_EAST, MtChimney_EventScript_ArchieExitEast
	call_if_eq VAR_FACING, DIR_NORTH, MtChimney_EventScript_ArchieExitNorth
	removeobject LOCALID_MT_CHIMNEY_ARCHIE
	setflag FLAG_HIDE_MT_CHIMNEY_TEAM_AQUA
	setflag FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY
	clearflag FLAG_HIDE_FALLARBOR_HOUSE_PROF_COZMO
	setflag FLAG_HIDE_METEOR_FALLS_1F_1R_COZMO
	clearflag FLAG_HIDE_MT_CHIMNEY_LAVA_COOKIE_LADY
	releaseall
	end

MtChimney_EventScript_ArchieApproachPlayerEast::
	applymovement LOCALID_MT_CHIMNEY_ARCHIE, MtChimney_Movement_ArchieApproachPlayerEast
	waitmovement 0
	return

MtChimney_EventScript_ArchieApproachPlayerNorth::
	applymovement LOCALID_MT_CHIMNEY_ARCHIE, MtChimney_Movement_ArchieApproachPlayerNorth
	waitmovement 0
	return

MtChimney_EventScript_ArchieExitEast::
	applymovement LOCALID_MT_CHIMNEY_ARCHIE, MtChimney_Movement_ArchieExitEast
	waitmovement 0
	return

MtChimney_EventScript_ArchieExitNorth::
	applymovement LOCALID_MT_CHIMNEY_ARCHIE, MtChimney_Movement_ArchieExitNorth
	waitmovement 0
	return

MtChimney_EventScript_LavaCookieLady::
	lock
	faceplayer
	showmoneybox 0, 0
	msgbox MtChimney_Text_LavaCookiesJust200, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MtChimney_EventScript_DeclineLavaCookie
	checkmoney 200
	goto_if_eq VAR_RESULT, FALSE, MtChimney_EventScript_NotEnoughMoney
	msgbox MtChimney_Text_ThankYouDear, MSGBOX_DEFAULT
	checkitemspace ITEM_LAVA_COOKIE
	call_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_RemoveMoney
.if OW_SHOW_ITEM_DESCRIPTIONS == OW_ITEM_DESCRIPTIONS_OFF
	giveitem ITEM_LAVA_COOKIE
	goto_if_eq VAR_RESULT, FALSE, MtChimney_EventScript_BagIsFull
	hidemoneybox
	release
	end

MtChimney_EventScript_BagIsFull::
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	hidemoneybox
	release
	end
.else
	hidemoneybox
	giveitem ITEM_LAVA_COOKIE
	goto_if_eq VAR_RESULT, FALSE, MtChimney_EventScript_BagIsFull
	release
	end

MtChimney_EventScript_BagIsFull::
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	release
	end
.endif @ OW_SHOW_ITEM_DESCRIPTIONS


MtChimney_EventScript_RemoveMoney::
	removemoney 200
	updatemoneybox
	return

MtChimney_EventScript_DeclineLavaCookie::
	msgbox MtChimney_Text_OhFineThen, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

MtChimney_EventScript_NotEnoughMoney::
	msgbox MtChimney_Text_YouveNotGotTheMoney, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

MtChimney_Movement_ArchieApproachPlayerEast:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	step_end

MtChimney_Movement_ArchieExitEast:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_ArchieApproachPlayerNorth:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	step_end

MtChimney_Movement_ArchieExitNorth:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused1:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused2:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused3:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused4:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused5:
	delay_16
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused6:
	delay_16
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused7:
	delay_16
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused8:
	delay_16
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_down
	step_end

MtChimney_Movement_Unused9:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused10:
	walk_down
	step_end

MtChimney_Movement_Unused11:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused12:
	delay_16
	delay_16
	walk_in_place_faster_left
	delay_16
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused13:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_left
	delay_16
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused14:
	lock_facing_direction
	walk_fast_left
	unlock_facing_direction
	face_right
	step_end

MtChimney_Movement_Unused15:
	walk_left
	walk_in_place_faster_right
	delay_16
	step_end

MtChimney_EventScript_BusyAquaGrunt1::
	msgbox MtChimney_Text_MagmaOutnumbersUs, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyAquaGrunt2::
	msgbox MtChimney_Text_LessHabitatForWaterPokemon, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyAquaGrunt3::
	msgbox MtChimney_Text_MagmasNameSimilar, MSGBOX_SIGN
	end

MtChimney_EventScript_Tabitha::
	trainerbattle_single TRAINER_TABITHA_MT_CHIMNEY, MtChimney_Text_TabithaIntro, MtChimney_Text_TabithaDefeat
	msgbox MtChimney_Text_TabithaPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_MT_CHIMNEY_2, MtChimney_Text_Grunt2Intro, MtChimney_Text_Grunt2Defeat
	msgbox MtChimney_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_BusyMagmaGrunt1::
	msgbox MtChimney_Text_TeamAquaAlwaysMessingWithPlans, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt2::
	msgbox MtChimney_Text_MeteoritesPackAmazingPower, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt3::
	msgbox MtChimney_Text_YouBetterNotMessWithUs, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt4::
	msgbox MtChimney_Text_AquasNameSimilar, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt5::
	msgbox MtChimney_Text_DouseThemInFire, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt6::
	msgbox MtChimney_Text_KeepMakingMoreLand, MSGBOX_SIGN
	end

MtChimney_EventScript_MagmaPoochyena::
	msgbox MtChimney_Text_Bufoh, MSGBOX_SIGN
	end

MtChimney_EventScript_AquaPoochyena::
	msgbox MtChimney_Text_Bushaa, MSGBOX_SIGN
	end

MtChimney_EventScript_MeteoriteMachine::
	lockall
	msgbox Interstellar_MtChimney_Text_OldSurveyRig, MSGBOX_DEFAULT
	releaseall
	end

MtChimney_EventScript_MeteoriteMachineUnused::
	lockall
	goto_if_unset FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, MtChimney_EventScript_MachineOn
	goto_if_set FLAG_RECEIVED_METEORITE, MtChimney_EventScript_MachineOff
	msgbox MtChimney_Text_RemoveTheMeteorite, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MtChimney_EventScript_LeaveMeteoriteAlone
	msgbox MtChimney_Text_PlayerRemovedMeteorite, MSGBOX_DEFAULT
	giveitem ITEM_METEORITE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_METEORITE
	releaseall
	end

MtChimney_EventScript_LeaveMeteoriteAlone::
	msgbox MtChimney_Text_PlayerLeftMeteorite, MSGBOX_DEFAULT
	releaseall
	end

MtChimney_EventScript_MachineOff::
	msgbox MtChimney_Text_MachineMakesNoResponse, MSGBOX_DEFAULT
	releaseall
	end

MtChimney_EventScript_MachineOn::
	msgbox MtChimney_Text_MeteoriteFittedOnMachine, MSGBOX_DEFAULT
	releaseall
	end

MtChimney_EventScript_RouteSign::
	msgbox MtChimney_Text_RouteSign, MSGBOX_SIGN
	end

MtChimney_EventScript_Shelby::
	trainerbattle_single TRAINER_SHELBY_1, MtChimney_Text_ShelbyIntro, MtChimney_Text_ShelbyDefeat, MtChimney_EventScript_DefeatedShelby
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_RematchShelby
	msgbox MtChimney_Text_ShelbyPostBattle, MSGBOX_DEFAULT
	release
	end

MtChimney_EventScript_DefeatedShelby::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtChimney_Text_ShelbyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_SHELBY_1
	release
	end

MtChimney_EventScript_RematchShelby::
	trainerbattle_rematch TRAINER_SHELBY_1, MtChimney_Text_ShelbyRematchIntro, MtChimney_Text_ShelbyRematchDefeat
	msgbox MtChimney_Text_ShelbyPostRematch, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Melissa::
	trainerbattle_single TRAINER_MELISSA, MtChimney_Text_MelissaIntro, MtChimney_Text_MelissaDefeat
	msgbox MtChimney_Text_MelissaPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Sheila::
	trainerbattle_single TRAINER_SHEILA, MtChimney_Text_SheilaIntro, MtChimney_Text_SheilaDefeat
	msgbox MtChimney_Text_SheilaPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Shirley::
	trainerbattle_single TRAINER_SHIRLEY, MtChimney_Text_ShirleyIntro, MtChimney_Text_ShirleyDefeat
	msgbox MtChimney_Text_ShirleyPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_MT_CHIMNEY_1, MtChimney_Text_Grunt1Intro, MtChimney_Text_Grunt1Defeat
	msgbox MtChimney_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Sawyer::
	trainerbattle_single TRAINER_SAWYER_1, MtChimney_Text_SawyerIntro, MtChimney_Text_SawyerDefeat, MtChimney_EventScript_SawyerDefeated
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_SawyerRematch
	msgbox MtChimney_Text_SawyerPostBattle, MSGBOX_DEFAULT
	release
	end

MtChimney_EventScript_SawyerDefeated::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtChimney_Text_SawyerRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_SAWYER_1
	release
	end

MtChimney_EventScript_SawyerRematch::
	trainerbattle_rematch TRAINER_SAWYER_1, MtChimney_Text_SawyerRematchIntro, MtChimney_Text_SawyerRematchDefeat
	msgbox MtChimney_Text_SawyerPostRematch, MSGBOX_AUTOCLOSE
	end

MtChimney_Text_MeteoriteWillActivateVolcano:
	.string "The power contained in the METEORITE…\p"
	.string "By amplifying its power with this\n"
	.string "machine, MT. CHIMNEY's volcanic\l"
	.string "activity will instantly intensify…\p"
	.string "Its energy will grow deep inside\n"
	.string "the crater and…\l"
	.string "Fufufu…$"

MtChimney_Text_MaxieIntro:
	.string "MAXIE: Hm?\n"
	.string "Who are you?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "I'd heard ARCHIE bemoaning a child\n"
	.string "who's been meddling in TEAM AQUA's\l"
	.string "affairs.\p"
	.string "It must be you he meant.\p"
	.string "Humph! So you're thinking of\n"
	.string "interfering with us, TEAM MAGMA?\p"
	.string "Now you listen.\n"
	.string "Long ago, living things used the\l"
	.string "land to live and grow.\p"
	.string "That is why land is all important!\n"
	.string "It is the cradle of all!\p"
	.string "That is why TEAM MAGMA is dedicated\n"
	.string "to the expansion of the land mass.\p"
	.string "It is for further advancement of\n"
	.string "humankind and POKéMON!\p"
	.string "And for that, we need the power of\n"
	.string "what sleeps within this mountain…\p"
	.string "Oh! There was no need for you to\n"
	.string "learn that much.\p"
	.string "But, no matter!\n"
	.string "I'll teach you the consequences of\l"
	.string "meddling in our grand design!$"

MtChimney_Text_MaxieDefeat:
	.string "What?!\p"
	.string "I, MAXIE, was caught off guard?!$"

MtChimney_Text_MaxieYouHaventSeenLastOfMagma:
	.string "MAXIE: But, enough.\n"
	.string "I will back off this time.\p"
	.string "But don't think that this is the last\n"
	.string "you've seen of TEAM MAGMA.\p"
	.string "Fufufu…\p"
	.string "Even without the METEORITE, if we\n"
	.string "obtain that ORB… Fufufu…$"

MtChimney_Text_TabithaIntro:
	.string "Hehehe!\p"
	.string "So you've come all the way here!\p"
	.string "But you're too late!\n"
	.string "I've already delivered the METEORITE\l"
	.string "from METEOR FALLS to the BOSS!$"

MtChimney_Text_TabithaDefeat:
	.string "Hehehe…\p"
	.string "Even though I've lost, if our leader\n"
	.string "awakens that thing…$"

MtChimney_Text_TabithaPostBattle:
	.string "BOSS, hurry!\n"
	.string "Give it the METEORITE's energy!\p"
	.string "Hehehe…$"

MtChimney_Text_Grunt2Intro:
	.string "We of TEAM MAGMA are working hard for\n"
	.string "everyone's sake.\p"
	.string "Like, if that thing's power made more\n"
	.string "land, there'd be more places to live.\p"
	.string "Everyone'd be happy!$"

MtChimney_Text_Grunt2Defeat:
	.string "Hunh?\n"
	.string "What do you mean I lost?$"

MtChimney_Text_Grunt2PostBattle:
	.string "Our BOSS says, “It will make everyone\n"
	.string "happy.”\p"
	.string "But why does everyone keep getting\n"
	.string "in our way?$"

MtChimney_Text_Grunt1Intro:
	.string "If there were more land, I'd be able\n"
	.string "to get a big house of my own!\p"
	.string "I'm going to build it on hardened lava!$"

MtChimney_Text_Grunt1Defeat:
	.string "My dream of a big house…$"

MtChimney_Text_Grunt1PostBattle:
	.string "A kid like you, you ought to be\n"
	.string "splashing about in the waves!$"

MtChimney_Text_TeamAquaAlwaysMessingWithPlans:
	.string "That annoying TEAM AQUA…\n"
	.string "They always mess with our plans!$"

MtChimney_Text_MeteoritesPackAmazingPower:
	.string "METEORITES pack amazing power!$"

MtChimney_Text_YouBetterNotMessWithUs:
	.string "You'd better not mess with us!\p"
	.string "We're trying to awaken that thing\n"
	.string "for the benefit of everyone!$"

MtChimney_Text_AquasNameSimilar:
	.string "We're TEAM MAGMA!\p"
	.string "They're TEAM AQUA!\p"
	.string "It totally annoys me that they'd\n"
	.string "use a name like ours!$"

MtChimney_Text_DouseThemInFire:
	.string "Yeah!\n"
	.string "Douse them in fire!$"

MtChimney_Text_KeepMakingMoreLand:
	.string "We're going to keep making more land!$"

MtChimney_Text_Bufoh:
	.string "Bufoh!$"

MtChimney_Text_ArchieGoStopTeamMagma:
	.string "ARCHIE: Grr, {PLAYER}!\n"
	.string "I should've guessed you'd show up!\p"
	.string "See for yourself what the fanatics\n"
	.string "of TEAM MAGMA are up to!\p"
	.string "They're trying to inject the stolen\n"
	.string "METEORITE's power into the volcano!\p"
	.string "Doing something like that will cause\n"
	.string "the volcano's eruption!$"

MtChimney_Text_ArchieIHaveMyHandsFull:
	.string "ARCHIE: Grrr…\p"
	.string "I want to stop that MAXIE,\n"
	.string "but I can't!\p"
	.string "Not when I have my hands full battling\n"
	.string "three opponents at once!$"

MtChimney_Text_ArchieThankYou:
	.string "ARCHIE: {PLAYER}!\n"
	.string "Thank you!\p"
	.string "With your help, we thwarted TEAM\n"
	.string "MAGMA's destructive plan!\p"
	.string "But… You…\n"
	.string "Whose side are you on?\p"
	.string "Ah, it doesn't matter.\p"
	.string "We will remain vigilant and keep up\n"
	.string "our pursuit of TEAM MAGMA.\p"
	.string "{PLAYER}, we shall meet again!$"

MtChimney_Text_MagmaOutnumbersUs:
	.string "Darn… TEAM MAGMA outnumbers us!\n"
	.string "We can't keep up with them!$"

MtChimney_Text_LessHabitatForWaterPokemon:
	.string "If they expand the land, there'll be\n"
	.string "less habitats for WATER POKéMON!$"

MtChimney_Text_MagmasNameSimilar:
	.string "We're TEAM AQUA!\p"
	.string "They're TEAM MAGMA!\p"
	.string "It burns me up that they'd use such\n"
	.string "a confusing name!$"

MtChimney_Text_Bushaa:
	.string "Bushaa!$"

MtChimney_Text_LavaCookiesJust200:
	.string "LAVA COOKIES are MT. CHIMNEY's local\n"
	.string "specialty.\p"
	.string "Try one. It's just ¥200.$"

MtChimney_Text_ThankYouDear:
	.string "Thank you, dear!$"

MtChimney_Text_YouveNotGotTheMoney:
	.string "Oh, dear. You can't buy a thing if\n"
	.string "you've not got the money.$"

MtChimney_Text_OhFineThen:
	.string "Oh, fine then.$"

MtChimney_Text_MeteoriteFittedOnMachine:
	.string "A METEORITE is fitted on a mysterious\n"
	.string "machine…\p"
	.string "The machine seems to be storing\n"
	.string "energy in the METEORITE.$"

MtChimney_Text_RemoveTheMeteorite:
	.string "A METEORITE is fitted on a mysterious\n"
	.string "machine…\p"
	.string "Do you want to remove the METEORITE?$"

MtChimney_Text_PlayerRemovedMeteorite:
	.string "{PLAYER} removed the METEORITE from\n"
	.string "the mysterious machine.$"

MtChimney_Text_PlayerLeftMeteorite:
	.string "{PLAYER} left the METEORITE where\n"
	.string "it was.$"

MtChimney_Text_MachineMakesNoResponse:
	.string "This mysterious machine…\n"
	.string "It makes no response whatsoever.$"

MtChimney_Text_RouteSign:
	.string "{DOWN_ARROW} JAGGED PATH\n"
	.string "LAVARIDGE TOWN AHEAD$"

MtChimney_Text_ShelbyIntro:
	.string "I've been to the hot springs and\n"
	.string "refreshed my tired bones.\l"
	.string "Right now I'm feeling strong!$"

MtChimney_Text_ShelbyDefeat:
	.string "Oh, my goodness.\n"
	.string "Now, aren't you something!$"

MtChimney_Text_ShelbyPostBattle:
	.string "Well, well, I've lost. I can't call\n"
	.string "myself an EXPERT now, can I?$"

MtChimney_Text_ShelbyRegister:
	.string "Thank you, child. It was fun, as if\n"
	.string "I were battling my own grandchild.\p"
	.string "Please, come see me again for\n"
	.string "a rematch.$"

MtChimney_Text_ShelbyRematchIntro:
	.string "If you can mesh your heart with those\n"
	.string "of your POKéMON, why, you should be\l"
	.string "able to achieve great things.$"

MtChimney_Text_ShelbyRematchDefeat:
	.string "Oh, my goodness.\n"
	.string "Now, aren't you something!$"

MtChimney_Text_ShelbyPostRematch:
	.string "Perhaps your heart has become one\n"
	.string "with the hearts of your POKéMON.$"

MtChimney_Text_MelissaIntro:
	.string "I've got the fire in me, baby.\n"
	.string "I can't stand it! I have to battle!$"

MtChimney_Text_MelissaDefeat:
	.string "Ooh, that was a scorching-hot match!$"

MtChimney_Text_MelissaPostBattle:
	.string "The heat of MT. CHIMNEY warms\n"
	.string "me up, baby!$"

MtChimney_Text_SheilaIntro:
	.string "I've finally made it to MT. CHIMNEY.\n"
	.string "I want to make my POKéMON battle!$"

MtChimney_Text_SheilaDefeat:
	.string "The way you battle…\n"
	.string "It's like a MT. CHIMNEY eruption!$"

MtChimney_Text_SheilaPostBattle:
	.string "Like I said, I've finally made it to\n"
	.string "MT. CHIMNEY. It would be a shame if\l"
	.string "I only do a little sightseeing…\p"
	.string "I want to get in some battles and buy\n"
	.string "COOKIES as souvenirs.$"

MtChimney_Text_ShirleyIntro:
	.string "Since I bathed in the hot springs,\n"
	.string "I've been feeling great!\l"
	.string "I'm sure I'm going to win!$"

MtChimney_Text_ShirleyDefeat:
	.string "Yowch!\n"
	.string "I'm getting a chill out of the water.$"

MtChimney_Text_ShirleyPostBattle:
	.string "I'll have to take another dip in the\n"
	.string "hot springs. Want to join me?\p"
	.string "Just joking!$"

MtChimney_Text_SawyerIntro:
	.string "This is one fine mountain! Plenty of\n"
	.string "hot people around for company!$"

MtChimney_Text_SawyerDefeat:
	.string "Oh, you're a real firebrand, too!$"

MtChimney_Text_SawyerPostBattle:
	.string "I think I need a dip in LAVARIDGE\n"
	.string "HOT SPRING with the locals!$"

MtChimney_Text_SawyerRegister:
	.string "I like little fireballs like you.\n"
	.string "Let me register you in my POKéNAV.$"

MtChimney_Text_SawyerRematchIntro:
	.string "I'm happily surrounded by hot people\n"
	.string "around these parts. I won't lose!$"

MtChimney_Text_SawyerRematchDefeat:
	.string "Gosh, you're still the same\n"
	.string "firebrand as before!$"

MtChimney_Text_SawyerPostRematch:
	.string "Actually, it really is hot here.\n"
	.string "I'm overdressed for these parts.$"

@ ---------------------------------------------------------------------------
@ Interstellar: the crater is the setpiece of the act. FLANNERY is up here
@ between badge three and the walk back down (states 12-13), taking notes
@ on the ecosystem that ate her family volcano.
@ ---------------------------------------------------------------------------
Interstellar_MtChimney_EventScript_BowlReveal::
	lockall
	setvar VAR_TEMP_3, 1
	msgbox Interstellar_MtChimney_Text_BowlReveal, MSGBOX_DEFAULT
	releaseall
	end

Interstellar_EventScript_FlanneryChimney::
	lock
	faceplayer
	goto_if_eq VAR_TEMP_4, 1, Interstellar_MtChimney_EventScript_TagPrompt
	msgbox Interstellar_MtChimney_Text_FlanneryGardenIntro, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_4, 1
	@ The displaced MAGMA pair has been listening from the rim.
	playse SE_PIN
	applymovement 34, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 34, Interstellar_MtChimney_Movement_PairApproach
	applymovement 35, Interstellar_MtChimney_Movement_PairApproach
	waitmovement 0
	msgbox Interstellar_MtChimney_Text_MagmaAWake, MSGBOX_DEFAULT
	msgbox Interstellar_MtChimney_Text_MagmaBFell, MSGBOX_DEFAULT
	msgbox Interstellar_MtChimney_Text_FlanneryNotHis, MSGBOX_DEFAULT
Interstellar_MtChimney_EventScript_TagPrompt::
	msgbox Interstellar_MtChimney_Text_FlanneryPickThree, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Interstellar_MtChimney_EventScript_TagChooseParty
	msgbox Interstellar_MtChimney_Text_FlanneryPatient, MSGBOX_DEFAULT
	release
	end

Interstellar_MtChimney_EventScript_TagChooseParty::
	special SavePlayerParty
	fadescreen FADE_TO_BLACK
	special ChooseHalfPartyForBattle
	goto_if_ne VAR_RESULT, 0, Interstellar_MtChimney_EventScript_DoTagBattle
	special LoadPlayerParty
	goto Interstellar_MtChimney_EventScript_TagPrompt

Interstellar_MtChimney_EventScript_DoTagBattle::
	multi_2_vs_2 TRAINER_INTERSTELLAR_CHIMNEY_MAGMA_A, Interstellar_MtChimney_Text_MagmaALose, TRAINER_INTERSTELLAR_CHIMNEY_MAGMA_B, Interstellar_MtChimney_Text_MagmaBLose, PARTNER_FLANNERY
	switch VAR_RESULT
	case 1, Interstellar_MtChimney_EventScript_TagWon
	fadescreen FADE_TO_BLACK
	special SetCB2WhiteOut

Interstellar_MtChimney_EventScript_TagWon::
	special LoadPlayerParty
	setflag FLAG_INTERSTELLAR_CHIMNEY_TAG_DONE
	msgbox Interstellar_MtChimney_Text_MagmaADidntWake, MSGBOX_DEFAULT
	msgbox Interstellar_MtChimney_Text_MagmaBComeAway, MSGBOX_DEFAULT
	closemessage
	applymovement 35, Interstellar_MtChimney_Movement_PairLeave
	applymovement 34, Interstellar_MtChimney_Movement_PairLeave
	waitmovement 0
	removeobject 34
	removeobject 35
	setflag FLAG_INTERSTELLAR_HIDE_CHIMNEY_MAGMA_PAIR
	msgbox Interstellar_MtChimney_Text_FlanneryBadgePart, MSGBOX_DEFAULT
	closemessage
	setvar VAR_INTERSTELLAR_STATE, 13
	clearflag FLAG_INTERSTELLAR_FLANNERY_AWAY
	fadescreen FADE_TO_BLACK
	removeobject 31
	setflag FLAG_INTERSTELLAR_HIDE_CHIMNEY_FLANNERY
	fadescreen FADE_FROM_BLACK
	msgbox Interstellar_MtChimney_Text_FlanneryHeadsDown, MSGBOX_DEFAULT
	release
	end

Interstellar_MtChimney_EventScript_MagmaPairA::
	msgbox Interstellar_MtChimney_Text_MagmaPairAIdle, MSGBOX_NPC
	end

Interstellar_MtChimney_EventScript_MagmaPairB::
	msgbox Interstellar_MtChimney_Text_MagmaPairBIdle, MSGBOX_NPC
	end

Interstellar_MtChimney_EventScript_PairScar::
	msgbox Interstellar_MtChimney_Text_PairScar, MSGBOX_SIGN
	end

Interstellar_MtChimney_EventScript_AquaGrunt::
	trainerbattle_single TRAINER_INTERSTELLAR_CHIMNEY_AQUA, Interstellar_MtChimney_Text_AquaIntro, Interstellar_MtChimney_Text_AquaDefeat
	msgbox Interstellar_MtChimney_Text_AquaPost, MSGBOX_AUTOCLOSE
	end

Interstellar_MtChimney_EventScript_RocketGrunt::
	trainerbattle_single TRAINER_INTERSTELLAR_CHIMNEY_ROCKET, Interstellar_MtChimney_Text_RocketIntro, Interstellar_MtChimney_Text_RocketDefeat
	msgbox Interstellar_MtChimney_Text_RocketPost, MSGBOX_AUTOCLOSE
	end

Interstellar_MtChimney_Movement_PairApproach:
	walk_left
	step_end

Interstellar_MtChimney_Movement_PairLeave:
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Interstellar_MtChimney_EventScript_Todd::
	trainerbattle_single TRAINER_INTERSTELLAR_CHIMNEY_TODD, Interstellar_MtChimney_Text_ToddIntro, Interstellar_MtChimney_Text_ToddDefeat
	msgbox Interstellar_MtChimney_Text_ToddPost, MSGBOX_AUTOCLOSE
	end

Interstellar_MtChimney_EventScript_Mimi::
	trainerbattle_single TRAINER_INTERSTELLAR_CHIMNEY_MIMI, Interstellar_MtChimney_Text_MimiIntro, Interstellar_MtChimney_Text_MimiDefeat
	msgbox Interstellar_MtChimney_Text_MimiPost, MSGBOX_AUTOCLOSE
	end

Interstellar_MtChimney_Text_BowlReveal:
	.string "Spray drifts over the rim.\p"
	.string "Where the mountain's fire was, a\n"
	.string "garden hangs from the crater walls,\l"
	.string "drinking a waterfall.\p"
	.string "And under the water, faint as a\n"
	.string "pulse: warmth.\p"
	.string "Not gone. Waiting.$"

Interstellar_MtChimney_Text_FlanneryGardenIntro:
	.string "FLANNERY: Don't say it.\p"
	.string "Everyone says it. “It's beautiful,\n"
	.string "FLANNERY.” And it is.\p"
	.string "My family kept this volcano for\n"
	.string "four generations. The springs.\l"
	.string "The ash. Heat in the floorboards.\p"
	.string "One morning the mountain forgot\n"
	.string "all of it.\p"
	.string "Now there's a waterfall where my\n"
	.string "grandfather's fire was, and it\l"
	.string "doesn't even have the decency\l"
	.string "to be ugly.\p"
	.string "…A MASQUERAIN landed on my arm\n"
	.string "yesterday. At this altitude.\p"
	.string "I took notes for three hours.$"

Interstellar_MtChimney_Text_MagmaAWake:
	.string "GRUNT: Step away from the rim,\n"
	.string "GYM LEADER.\p"
	.string "The mountain isn't dead. It's\n"
	.string "ASLEEP. TEAM MAGMA remembers\l"
	.string "the fire, even if the sky forgot.\p"
	.string "We wake it, and everything goes\n"
	.string "back the way it was.$"

Interstellar_MtChimney_Text_MagmaBFell:
	.string "GRUNT: We fell through a hole in\n"
	.string "the sky.\p"
	.string "First thing he did when he stopped\n"
	.string "shaking was check if the volcano\l"
	.string "still worked.\p"
	.string "I don't know what I'm checking\n"
	.string "for anymore.$"

Interstellar_MtChimney_Text_FlanneryNotHis:
	.string "FLANNERY: You heard him. He wants\n"
	.string "his fire back.\p"
	.string "Funny thing. So do I.\p"
	.string "And it's still not his to take.$"

Interstellar_MtChimney_Text_FlanneryPickThree:
	.string "FLANNERY: Two of us, two of them.\n"
	.string "I bring three, you bring three.\p"
	.string "Ready?$"

Interstellar_MtChimney_Text_FlanneryPatient:
	.string "FLANNERY: Fix your team first.\n"
	.string "They'll wait.\p"
	.string "Anger that old is patient.$"

Interstellar_MtChimney_Text_MagmaALose:
	.string "The mountain didn't listen…$"

Interstellar_MtChimney_Text_MagmaBLose:
	.string "Told you. It isn't asleep.$"

Interstellar_MtChimney_Text_MagmaADidntWake:
	.string "GRUNT: …It didn't want to wake.$"

Interstellar_MtChimney_Text_MagmaBComeAway:
	.string "GRUNT: It's not asleep, and it's\n"
	.string "not dead. It's DIFFERENT.\p"
	.string "Come away from the edge now.\n"
	.string "We'll figure out dinner.$"

Interstellar_MtChimney_Text_FlanneryBadgePart:
	.string "FLANNERY: So. You're climbing with\n"
	.string "a fresh DYNAMO BADGE, which makes\l"
	.string "you mine next.\p"
	.string "Good. I'm the LAVARIDGE leader.\n"
	.string "I guard what's left of the fire.\p"
	.string "Finish looking. I mean it -- look\n"
	.string "properly. Then come down.\p"
	.string "I'll be at the gym, deciding\n"
	.string "whether fire still means anything\l"
	.string "on this mountain.\p"
	.string "You're going to help me decide.$"

Interstellar_MtChimney_Text_MagmaPairAIdle:
	.string "GRUNT: The lake is a mistake.\n"
	.string "The garden is a mistake.\p"
	.string "MAGMA can fix a mountain.\n"
	.string "We just need it to wake up.$"

Interstellar_MtChimney_Text_MagmaPairBIdle:
	.string "GRUNT: Don't mind him.\p"
	.string "It's easier to argue with a\n"
	.string "volcano than to be lost.$"

Interstellar_MtChimney_Text_PairScar:
	.string "The tear the two of them fell\n"
	.string "through, sealed to a scar.\p"
	.string "It's still warm. Ash-warm.$"

Interstellar_MtChimney_Text_AquaIntro:
	.string "More sea! That was the entire\n"
	.string "plan!\p"
	.string "So here's a sea on top of a\n"
	.string "volcano, and I hate it.$"

Interstellar_MtChimney_Text_AquaDefeat:
	.string "It's cold up here.\n"
	.string "The sea shouldn't be cold.$"

Interstellar_MtChimney_Text_AquaPost:
	.string "We wanted more water. Not…\n"
	.string "instead.\p"
	.string "Don't tell anyone I cried about\n"
	.string "a lake with a MAGMA kid.$"

Interstellar_MtChimney_Text_RocketIntro:
	.string "Three years we waited to rebuild\n"
	.string "TEAM ROCKET.\p"
	.string "I climbed all this way for radio\n"
	.string "signal. There's no tower.\p"
	.string "There's no GOLDENROD.$"

Interstellar_MtChimney_Text_RocketDefeat:
	.string "The radio only plays weather now.$"

Interstellar_MtChimney_Text_RocketPost:
	.string "Someone else's summer, on every\n"
	.string "channel.\p"
	.string "It's not a bad show, honestly.$"

Interstellar_MtChimney_Text_FlanneryHeadsDown:
	.string "FLANNERY heads down the pass,\n"
	.string "stopping twice to write\l"
	.string "something.$"

Interstellar_MtChimney_Text_ToddIntro:
	.string "I pitched my tent in a forest.\n"
	.string "I woke up on a volcano!\p"
	.string "That is NOT what the brochure\n"
	.string "said!$"

Interstellar_MtChimney_Text_ToddDefeat:
	.string "The tent stays.\n"
	.string "I have nowhere else to be.$"

Interstellar_MtChimney_Text_ToddPost:
	.string "The HERACROSS like the vines.\p"
	.string "So... home, I guess.$"

Interstellar_MtChimney_Text_MimiIntro:
	.string "The flowers bloom at the wrong\n"
	.string "altitude and nobody TELLS them!\p"
	.string "Isn't it wonderful?$"

Interstellar_MtChimney_Text_MimiDefeat:
	.string "Petals everywhere!$"

Interstellar_MtChimney_Text_MimiPost:
	.string "GRANDMA says the mountain is\n"
	.string "dreaming.\p"
	.string "I hope it doesn't wake up\n"
	.string "embarrassed.$"

Interstellar_MtChimney_Text_OldSurveyRig:
	.string "An old survey rig, bolted to the\n"
	.string "rock. The dials are dark.\p"
	.string "Someone has scratched a note into\n"
	.string "the casing:\p"
	.string "“It measured the fire. It has\n"
	.string "nothing to say about the water.”$"
