NewMauville_Inside_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, NewMauville_Inside_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, NewMauville_Inside_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, NewMauville_Inside_OnLoad
	.byte 0

NewMauville_Inside_OnResume:
	call_if_eq VAR_TEMP_1, 1, NewMauville_Inside_EventScript_SetBarrierStateBlueButton
	call_if_eq VAR_TEMP_2, 1, NewMauville_Inside_EventScript_SetBarrierStateGreenButton
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, NewMauville_Inside_EventScript_TryRemoveVoltorb
	end

NewMauville_Inside_EventScript_TryRemoveVoltorb::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

NewMauville_Inside_OnTransition:
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, 0
	call_if_unset FLAG_DEFEATED_VOLTORB_1_NEW_MAUVILLE, NewMauville_Inside_EventScript_ShowVoltorb1
	call_if_unset FLAG_DEFEATED_VOLTORB_2_NEW_MAUVILLE, NewMauville_Inside_EventScript_ShowVoltorb2
	call_if_unset FLAG_DEFEATED_VOLTORB_3_NEW_MAUVILLE, NewMauville_Inside_EventScript_ShowVoltorb3
	call_if_set FLAG_INTERSTELLAR_NM_GENERATOR_OFF, NewMauville_Inside_EventScript_DisarmRedButton
	end

NewMauville_Inside_EventScript_DisarmRedButton::
	setvar VAR_TEMP_4, 1
	return

NewMauville_Inside_EventScript_ShowVoltorb1::
	clearflag FLAG_HIDE_NEW_MAUVILLE_VOLTORB_1
	return

NewMauville_Inside_EventScript_ShowVoltorb2::
	clearflag FLAG_HIDE_NEW_MAUVILLE_VOLTORB_2
	return

NewMauville_Inside_EventScript_ShowVoltorb3::
	clearflag FLAG_HIDE_NEW_MAUVILLE_VOLTORB_3
	return

NewMauville_Inside_OnLoad:
	call_if_set FLAG_INTERSTELLAR_NM_GENERATOR_OFF, NewMauville_Inside_EventScript_SetGeneratorOffMetatiles
	end

NewMauville_Inside_EventScript_BlueButton::
	lockall
	setvar VAR_TEMP_1, 1
	setvar VAR_TEMP_2, 0
	playse SE_PIN
	call NewMauville_Inside_EventScript_SetBarrierStateBlueButton
	special DrawWholeMapView
	releaseall
	end

NewMauville_Inside_EventScript_GreenButton::
	lockall
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, 1
	playse SE_PIN
	call NewMauville_Inside_EventScript_SetBarrierStateGreenButton
	special DrawWholeMapView
	releaseall
	end

NewMauville_Inside_EventScript_SetBarrierStateBlueButton::
	setmetatile 23, 34, METATILE_BikeShop_Barrier_Hidden_Top, TRUE
	setmetatile 23, 35, METATILE_BikeShop_Barrier_Hidden_Bottom, TRUE
	setmetatile 23, 36, METATILE_BikeShop_Floor_Shadow_Top, FALSE
	setmetatile 23, 37, METATILE_BikeShop_Wall_Edge_Top, FALSE
	setmetatile 10, 16, METATILE_BikeShop_Barrier_Hidden_Top, TRUE
	setmetatile 10, 17, METATILE_BikeShop_Barrier_Hidden_Bottom, TRUE
	setmetatile 10, 18, METATILE_BikeShop_Floor_Shadow_Top, FALSE
	setmetatile 10, 19, METATILE_BikeShop_Wall_Edge_Top, FALSE
	setmetatile 10, 0, METATILE_BikeShop_Barrier_Hidden_Top, TRUE
	setmetatile 10, 1, METATILE_BikeShop_Barrier_Hidden_Bottom, TRUE
	setmetatile 10, 2, METATILE_BikeShop_Floor_Shadow_Top, FALSE
	setmetatile 10, 3, METATILE_BikeShop_Wall_Edge_Top, FALSE
	setmetatile 37, 33, METATILE_BikeShop_Barrier_Green_Top, TRUE
	setmetatile 37, 34, METATILE_BikeShop_Barrier_Green_TopMid, TRUE
	setmetatile 37, 35, METATILE_BikeShop_Barrier_Green_BottomMid, TRUE
	setmetatile 37, 36, METATILE_BikeShop_Barrier_Green_Bottom, TRUE
	setmetatile 28, 22, METATILE_BikeShop_Barrier_Green_Top, TRUE
	setmetatile 28, 23, METATILE_BikeShop_Barrier_Green_TopMid, TRUE
	setmetatile 28, 24, METATILE_BikeShop_Barrier_Green_BottomMid, TRUE
	setmetatile 28, 25, METATILE_BikeShop_Barrier_Green_Bottom, TRUE
	setmetatile 10, 24, METATILE_BikeShop_Barrier_Green_Top, TRUE
	setmetatile 10, 25, METATILE_BikeShop_Barrier_Green_TopMid, TRUE
	setmetatile 10, 26, METATILE_BikeShop_Barrier_Green_BottomMid, TRUE
	setmetatile 10, 27, METATILE_BikeShop_Barrier_Green_Bottom, TRUE
	setmetatile 21, 2, METATILE_BikeShop_Barrier_Green_Top, TRUE
	setmetatile 21, 3, METATILE_BikeShop_Barrier_Green_TopMid, TRUE
	setmetatile 21, 4, METATILE_BikeShop_Barrier_Green_BottomMid, TRUE
	setmetatile 21, 5, METATILE_BikeShop_Barrier_Green_Bottom, TRUE
	setmetatile 6, 11, METATILE_BikeShop_Button_Pressed, FALSE
	setmetatile 13, 10, METATILE_BikeShop_Button_Pressed, FALSE
	setmetatile 16, 22, METATILE_BikeShop_Button_Pressed, FALSE
	setmetatile 4, 26, METATILE_BikeShop_Button_Pressed, FALSE
	setmetatile 30, 38, METATILE_BikeShop_Button_Pressed, FALSE
	setmetatile 2, 11, METATILE_BikeShop_Button_Green, FALSE
	setmetatile 17, 10, METATILE_BikeShop_Button_Green, FALSE
	setmetatile 25, 18, METATILE_BikeShop_Button_Green, FALSE
	setmetatile 18, 36, METATILE_BikeShop_Button_Green, FALSE
	return

NewMauville_Inside_EventScript_SetBarrierStateGreenButton::
	setmetatile 23, 34, METATILE_BikeShop_Barrier_Blue_Top, TRUE
	setmetatile 23, 35, METATILE_BikeShop_Barrier_Blue_TopMid, TRUE
	setmetatile 23, 36, METATILE_BikeShop_Barrier_Blue_BottomMid, TRUE
	setmetatile 23, 37, METATILE_BikeShop_Barrier_Blue_Bottom, TRUE
	setmetatile 10, 16, METATILE_BikeShop_Barrier_Blue_Top, TRUE
	setmetatile 10, 17, METATILE_BikeShop_Barrier_Blue_TopMid, TRUE
	setmetatile 10, 18, METATILE_BikeShop_Barrier_Blue_BottomMid, TRUE
	setmetatile 10, 19, METATILE_BikeShop_Barrier_Blue_Bottom, TRUE
	setmetatile 10, 0, METATILE_BikeShop_Barrier_Blue_Top, TRUE
	setmetatile 10, 1, METATILE_BikeShop_Barrier_Blue_TopMid, TRUE
	setmetatile 10, 2, METATILE_BikeShop_Barrier_Blue_BottomMid, TRUE
	setmetatile 10, 3, METATILE_BikeShop_Barrier_Blue_Bottom, TRUE
	setmetatile 37, 33, METATILE_BikeShop_Barrier_Hidden_Top, TRUE
	setmetatile 37, 34, METATILE_BikeShop_Barrier_Hidden_Bottom, TRUE
	setmetatile 37, 35, METATILE_BikeShop_Floor_Shadow_Top, FALSE
	setmetatile 37, 36, METATILE_BikeShop_Wall_Edge_Top, FALSE
	setmetatile 28, 22, METATILE_BikeShop_Barrier_Hidden_Top, TRUE
	setmetatile 28, 23, METATILE_BikeShop_Barrier_Hidden_Bottom, TRUE
	setmetatile 28, 24, METATILE_BikeShop_Floor_Shadow_Top, FALSE
	setmetatile 28, 25, METATILE_BikeShop_Wall_Edge_Top, FALSE
	setmetatile 10, 24, METATILE_BikeShop_Barrier_Hidden_Top, TRUE
	setmetatile 10, 25, METATILE_BikeShop_Barrier_Hidden_Bottom, TRUE
	setmetatile 10, 26, METATILE_BikeShop_Floor_Shadow_Top, FALSE
	setmetatile 10, 27, METATILE_BikeShop_Wall_Edge_Top, FALSE
	setmetatile 21, 2, METATILE_BikeShop_Barrier_Hidden_Top, TRUE
	setmetatile 21, 3, METATILE_BikeShop_Barrier_Hidden_Bottom, TRUE
	setmetatile 21, 4, METATILE_BikeShop_Floor_Shadow_Top, FALSE
	setmetatile 21, 5, METATILE_BikeShop_Wall_Edge_Top, FALSE
	setmetatile 2, 11, METATILE_BikeShop_Button_Pressed, FALSE
	setmetatile 17, 10, METATILE_BikeShop_Button_Pressed, FALSE
	setmetatile 25, 18, METATILE_BikeShop_Button_Pressed, FALSE
	setmetatile 18, 36, METATILE_BikeShop_Button_Pressed, FALSE
	setmetatile 6, 11, METATILE_BikeShop_Button_Blue, FALSE
	setmetatile 13, 10, METATILE_BikeShop_Button_Blue, FALSE
	setmetatile 16, 22, METATILE_BikeShop_Button_Blue, FALSE
	setmetatile 4, 26, METATILE_BikeShop_Button_Blue, FALSE
	setmetatile 30, 38, METATILE_BikeShop_Button_Blue, FALSE
	return

@ Interstellar: the switch answers to the story, not the BASEMENT KEY quest.
@ Before the badge WATTSON stops you; after it, stamping the switch is his
@ reward for the whole region.
NewMauville_Inside_EventScript_RedButton::
	lockall
	goto_if_unset FLAG_BADGE03_GET, NewMauville_Inside_EventScript_RedButtonNotYet
	msgbox NewMauville_Inside_Text_SteppedOnSwitchGeneratorStopped, MSGBOX_DEFAULT
	call NewMauville_Inside_EventScript_SetGeneratorOffMetatiles
	setflag FLAG_INTERSTELLAR_NM_GENERATOR_OFF
	setvar VAR_TEMP_4, 1
	goto_if_unset FLAG_INTERSTELLAR_HIDE_NEWMAUVILLE_WATTSON, NewMauville_Inside_EventScript_WattsonSwitchPraise
	releaseall
	end

NewMauville_Inside_EventScript_WattsonSwitchPraise::
	msgbox Interstellar_NewMauville_Text_WattsonSwitchDone, MSGBOX_DEFAULT
	releaseall
	end

NewMauville_Inside_EventScript_RedButtonNotYet::
	msgbox Interstellar_NewMauville_Text_WattsonNotThatSwitch, MSGBOX_DEFAULT
	setvar VAR_TEMP_4, 1
	releaseall
	end

NewMauville_Inside_EventScript_SetGeneratorOffMetatiles::
	setmetatile 33, 6, METATILE_BikeShop_Button_Pressed, FALSE
	setmetatile 32, 2, METATILE_BikeShop_Generator_Off_Tile0, TRUE
	setmetatile 33, 2, METATILE_BikeShop_Generator_Off_Tile1, TRUE
	setmetatile 34, 2, METATILE_BikeShop_Generator_Off_Tile2, TRUE
	setmetatile 35, 2, METATILE_BikeShop_Generator_Off_Tile3, TRUE
	setmetatile 32, 3, METATILE_BikeShop_Generator_Off_Tile4, TRUE
	setmetatile 33, 3, METATILE_BikeShop_Generator_Off_Tile5, TRUE
	setmetatile 34, 3, METATILE_BikeShop_Generator_Off_Tile6, TRUE
	setmetatile 35, 3, METATILE_BikeShop_Generator_Off_Tile7, TRUE
	special DrawWholeMapView
	return

NewMauville_Inside_EventScript_Generator::
	lockall
	goto_if_set FLAG_INTERSTELLAR_NM_GENERATOR_OFF, NewMauville_Inside_EventScript_GeneratorOff
	msgbox Interstellar_NewMauville_Text_GeneratorHowls, MSGBOX_DEFAULT
	releaseall
	end

NewMauville_Inside_EventScript_GeneratorOff::
	msgbox NewMauville_Inside_Text_GeneratorQuietedDown, MSGBOX_DEFAULT
	releaseall
	end

NewMauville_Inside_EventScript_Voltorb1::
	lock
	faceplayer
	setwildbattle SPECIES_VOLTORB, 25
	waitse
	playmoncry SPECIES_VOLTORB, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, NewMauville_Inside_EventScript_DefeatedVoltorb1
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, NewMauville_Inside_EventScript_DefeatedVoltorb1
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, NewMauville_Inside_EventScript_DefeatedVoltorb1
	setflag FLAG_DEFEATED_VOLTORB_1_NEW_MAUVILLE
	release
	end

NewMauville_Inside_EventScript_DefeatedVoltorb1::
	setflag FLAG_DEFEATED_VOLTORB_1_NEW_MAUVILLE
	goto Common_EventScript_RemoveStaticPokemon
	end

NewMauville_Inside_EventScript_Voltorb2::
	lock
	faceplayer
	setwildbattle SPECIES_VOLTORB, 25
	waitse
	playmoncry SPECIES_VOLTORB, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, NewMauville_Inside_EventScript_DefeatedVoltorb2
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, NewMauville_Inside_EventScript_DefeatedVoltorb2
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, NewMauville_Inside_EventScript_DefeatedVoltorb2
	setflag FLAG_DEFEATED_VOLTORB_2_NEW_MAUVILLE
	release
	end

NewMauville_Inside_EventScript_DefeatedVoltorb2::
	setflag FLAG_DEFEATED_VOLTORB_2_NEW_MAUVILLE
	goto Common_EventScript_RemoveStaticPokemon
	end

NewMauville_Inside_EventScript_Voltorb3::
	lock
	faceplayer
	setwildbattle SPECIES_VOLTORB, 25
	waitse
	playmoncry SPECIES_VOLTORB, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, NewMauville_Inside_EventScript_DefeatedVoltorb3
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, NewMauville_Inside_EventScript_DefeatedVoltorb3
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, NewMauville_Inside_EventScript_DefeatedVoltorb3
	setflag FLAG_DEFEATED_VOLTORB_3_NEW_MAUVILLE
	release
	end

NewMauville_Inside_EventScript_DefeatedVoltorb3::
	setflag FLAG_DEFEATED_VOLTORB_3_NEW_MAUVILLE
	goto Common_EventScript_RemoveStaticPokemon
	end

NewMauville_Inside_Text_GeneratorRadiatingHeat:
	.string "The generator is radiating heat that\n"
	.string "can be felt even at a distance.\p"
	.string "It looks like it should be turned off\n"
	.string "as soon as possible.$"

NewMauville_Inside_Text_GeneratorQuietedDown:
	.string "The generator quieted down.$"

NewMauville_Inside_Text_SteppedOnSwitchGeneratorStopped:
	.string "{PLAYER} stepped on the switch.\p"
	.string "Click…\p"
	.string "… … … … … … … …\n"
	.string "… … … … … … … …\p"
	.string "The generator appears to have\n"
	.string "stopped…$"

@ ---------------------------------------------------------------------------
@ Interstellar: the DYNAMO BADGE battle happens down here, in the humming
@ dark, with the surging generator for a crowd. WATTSON appears at state 10
@ (sent from his gym) and goes home once the badge changes hands.
@ ---------------------------------------------------------------------------
Interstellar_EventScript_WattsonNewMauville::
	lock
	faceplayer
	goto_if_set FLAG_BADGE03_GET, Interstellar_NewMauville_EventScript_WattsonPostBadge
	msgbox Interstellar_NewMauville_Text_WattsonScene, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_LEADER_WATTSON, Interstellar_NewMauville_Text_WattsonDefeat
	message MauvilleCity_Gym_Text_ReceivedDynamoBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox Interstellar_NewMauville_Text_WattsonBadge, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_MAUVILLE_GYM
	setflag FLAG_BADGE03_GET
	setvar VAR_0x8008, 3
	call Common_EventScript_SetGymTrainers
	call MauvilleCity_Gym_EventScript_GiveShockWave
	msgbox Interstellar_NewMauville_Text_WattsonAfter, MSGBOX_DEFAULT
	setvar VAR_INTERSTELLAR_STATE, 12
	setflag FLAG_INTERSTELLAR_HIDE_NEWMAUVILLE_WATTSON
	clearflag FLAG_HIDE_MAUVILLE_GYM_WATTSON
	release
	end

Interstellar_NewMauville_EventScript_WattsonPostBadge::
	goto_if_set FLAG_INTERSTELLAR_NM_GENERATOR_OFF, Interstellar_NewMauville_EventScript_WattsonQuietNow
	msgbox Interstellar_NewMauville_Text_WattsonTheSwitch, MSGBOX_DEFAULT
	release
	end

Interstellar_NewMauville_EventScript_WattsonQuietNow::
	msgbox Interstellar_NewMauville_Text_WattsonListening, MSGBOX_DEFAULT
	release
	end

Interstellar_NewMauville_Text_WattsonScene:
	.string "WATTSON: Hear it, kid? Forty years\n"
	.string "I have kept this old girl running,\l"
	.string "and she never sang THAT note.\p"
	.string "Rift static, pouring in faster\n"
	.string "than I can bleed it off.\p"
	.string "Every light left in MAUVILLE\n"
	.string "hangs on this room.\p"
	.string "So! Your gym battle.\p"
	.string "No floor puzzle. No spectators.\n"
	.string "Just two trainers and a machine\l"
	.string "that wants to be a thunderstorm.\p"
	.string "The DYNAMO BADGE, winner keeps it!\p"
	.string "WAHAHAHA! Show me you can stand\n"
	.string "in the noise!$"

Interstellar_NewMauville_Text_WattsonDefeat:
	.string "WAHAHAHA!\n"
	.string "Louder than the generator!$"

Interstellar_NewMauville_Text_WattsonBadge:
	.string "WATTSON: The DYNAMO BADGE, kid.\p"
	.string "Earned in the dark, where volts\n"
	.string "mean something.$"

Interstellar_NewMauville_Text_WattsonAfter:
	.string "WATTSON: Now. The red switch,\n"
	.string "behind me. Stamp it good.\p"
	.string "She has earned her rest, and the\n"
	.string "grid can carry us from here.\p"
	.string "Then get up the mountain. The rift\n"
	.string "took FLANNERY's volcano and left\l"
	.string "her a garden.\p"
	.string "She will pretend she is not glad\n"
	.string "of a challenger. She is.\p"
	.string "And those two in the odd uniforms?\n"
	.string "The sky has been dropping people\l"
	.string "all over the region.\p"
	.string "If they are down here, they are\n"
	.string "on the mountain too.\p"
	.string "FLANNERY should hear it from you.\p"
	.string "LAVARIDGE. West, up ROUTE 112.\n"
	.string "The cable car is dead -- take the\l"
	.string "pass on foot.\p"
	.string "Me? One more night down here.\n"
	.string "Somebody has to sing to her.$"

Interstellar_NewMauville_Text_WattsonTheSwitch:
	.string "WATTSON: The switch, kid!\n"
	.string "The big red one! Stamp it!$"

Interstellar_NewMauville_Text_WattsonListening:
	.string "WATTSON: Listen to that.\p"
	.string "Rain on the rock, and an old\n"
	.string "machine cooling down.\p"
	.string "Best sound in HOENN.\p"
	.string "LAVARIDGE, kid. Up the pass.$"

Interstellar_NewMauville_Text_WattsonSwitchDone:
	.string "WATTSON: HA! Good stamp!\p"
	.string "Forty years of service. Sleep\n"
	.string "well, old girl.$"

Interstellar_NewMauville_Text_WattsonNotThatSwitch:
	.string "WATTSON: NOT that switch! Not yet!\p"
	.string "Kill the flow mid-surge and the\n"
	.string "backwash eats MAUVILLE whole.\p"
	.string "Me first, kid!$"

Interstellar_NewMauville_Text_GeneratorHowls:
	.string "The generator howls and swallows.\p"
	.string "The dials read a number that has\n"
	.string "no name on this side of the sky.$"

Interstellar_NewMauville_EventScript_GalacticA::
	trainerbattle_single TRAINER_INTERSTELLAR_NM_GALACTIC_A, Interstellar_NewMauville_Text_GalacticAIntro, Interstellar_NewMauville_Text_GalacticADefeat
	msgbox Interstellar_NewMauville_Text_GalacticAPost, MSGBOX_AUTOCLOSE
	end

Interstellar_NewMauville_EventScript_GalacticB::
	trainerbattle_single TRAINER_INTERSTELLAR_NM_GALACTIC_B, Interstellar_NewMauville_Text_GalacticBIntro, Interstellar_NewMauville_Text_GalacticBDefeat
	msgbox Interstellar_NewMauville_Text_GalacticBPost, MSGBOX_AUTOCLOSE
	end

Interstellar_NewMauville_Text_GalacticAIntro:
	.string "This machine drinks the sky.\p"
	.string "The boss promised us a new world\n"
	.string "with power like this in it.\p"
	.string "Nobody said it would HUM.$"

Interstellar_NewMauville_Text_GalacticADefeat:
	.string "It hums in my teeth now.$"

Interstellar_NewMauville_Text_GalacticAPost:
	.string "We fell in from… later.\n"
	.string "A lot later.\p"
	.string "I keep waiting for orders. The\n"
	.string "radio only gets weather.$"

Interstellar_NewMauville_Text_GalacticBIntro:
	.string "Don't touch the dials! He has been\n"
	.string "reading them like scripture since\l"
	.string "we landed.\p"
	.string "If you want past us, prove the new\n"
	.string "world has room for you.$"

Interstellar_NewMauville_Text_GalacticBDefeat:
	.string "…Fine. It has room.$"

Interstellar_NewMauville_Text_GalacticBPost:
	.string "There were others when we fell.\p"
	.string "They went for the mountain. Said\n"
	.string "it looked like home was burning.\p"
	.string "It is not burning. I checked.$"
