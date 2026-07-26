MtMoon_B2F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtMoon_B2F_OnTransition
	.byte 0

MtMoon_B2F_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_MT_MOON_1F
	end

MtMoon_B2F_EventScript_ShowFossils::
	clearflag FLAG_HIDE_DOME_FOSSIL
	clearflag FLAG_HIDE_HELIX_FOSSIL
	return

MtMoon_B2F_EventScript_GaryRiftTrigger::
	lockall
	goto_if_set FLAG_INTERSTELLAR_GARY_MT_MOON_DONE, MtMoon_B2F_EventScript_GaryRiftDone
	applymovement LOCALID_INTERSTELLAR_GARY_MT_MOON, MtMoon_B2F_Movement_GaryFallFromRift
	waitmovement 0
	msgbox MtMoon_B2F_Text_GaryFallFromRift, MSGBOX_DEFAULT
	closemessage
	switch VAR_STARTER_MON
	case 0, MtMoon_B2F_EventScript_GaryBattleCharmander
	case 1, MtMoon_B2F_EventScript_GaryBattleSquirtle
	case 2, MtMoon_B2F_EventScript_GaryBattleBulbasaur
	end

MtMoon_B2F_EventScript_GaryBattleCharmander::
	trainerbattle_no_intro TRAINER_RIVAL_CERULEAN_CHARMANDER, MtMoon_B2F_Text_GaryDefeat
	goto MtMoon_B2F_EventScript_GaryAfterBattle

MtMoon_B2F_EventScript_GaryBattleSquirtle::
	trainerbattle_no_intro TRAINER_RIVAL_CERULEAN_SQUIRTLE, MtMoon_B2F_Text_GaryDefeat
	goto MtMoon_B2F_EventScript_GaryAfterBattle

MtMoon_B2F_EventScript_GaryBattleBulbasaur::
	trainerbattle_no_intro TRAINER_RIVAL_CERULEAN_BULBASAUR, MtMoon_B2F_Text_GaryDefeat
	goto MtMoon_B2F_EventScript_GaryAfterBattle

MtMoon_B2F_EventScript_GaryAfterBattle::
	msgbox MtMoon_B2F_Text_GaryAfterBattle, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_INTERSTELLAR_GARY_MT_MOON_DONE
	setvar VAR_INTERSTELLAR_MT_MOON_GARY_SCENE, 1
	setvar VAR_MAP_SCENE_MT_MOON_B2F, 1
	removeobject LOCALID_INTERSTELLAR_GARY_MT_MOON
	releaseall
	end

MtMoon_B2F_EventScript_GaryRiftDone::
	setvar VAR_INTERSTELLAR_MT_MOON_GARY_SCENE, 1
	releaseall
	end

MtMoon_B2F_Movement_GaryFallFromRift:
	walk_down
	walk_down
	walk_down
	face_right
	step_end

MtMoon_B2F_Text_GaryFallFromRift:
	.string "GARY: What was that?! One second I\n"
	.string "was outside OAK's LAB, and now I'm\l"
	.string "falling through a cave ceiling!\p"
	.string "...Hold on. Why do you look so\n"
	.string "familiar? This timeline is wrong.\p"
	.string "I'm not letting a lookalike get the\n"
	.string "better of me! Let's battle!$"

MtMoon_B2F_Text_GaryDefeat:
	.string "GARY: What?! You really do know how\n"
	.string "to battle...$"

MtMoon_B2F_Text_GaryAfterBattle:
	.string "GARY: This is not my KANTO, and you\n"
	.string "are not anyone I remember.\p"
	.string "I'm finding PROFESSOR OAK. If he\n"
	.string "knows why the sky broke, he'll know\l"
	.string "how to send me home.$"

MtMoon_B2F_EventScript_Miguel::
	lock
	faceplayer
	goto_if_set FLAG_GOT_FOSSIL_FROM_MT_MOON, MtMoon_B2F_EventScript_MiguelFossilPicked
	goto_if_defeated TRAINER_SUPER_NERD_MIGUEL, MtMoon_B2F_EventScript_MiguelGoPickFossil
	call MtMoon_B2F_EventScript_BattleMiguel
	release
	end

MtMoon_B2F_EventScript_BattleMiguel::
	textcolor NPC_TEXT_COLOR_MALE
	message MtMoon_B2F_Text_MiguelIntro
	waitmessage
	playbgm MUS_RG_ENCOUNTER_GYM_LEADER, 0
	waitbuttonpress
	setvar VAR_LAST_TALKED, LOCALID_INTERSTELLAR_GARY_MT_MOON
	trainerbattle_no_intro TRAINER_SUPER_NERD_MIGUEL, MtMoon_B2F_Text_MiguelDefeat
	setvar VAR_MAP_SCENE_MT_MOON_B2F, 1
	msgbox MtMoon_B2F_Text_WellEachTakeAFossil
	return

MtMoon_B2F_EventScript_MiguelFossilPicked::
	msgbox MtMoon_B2F_Text_LabOnCinnabarRegeneratesFossils
	release
	end

MtMoon_B2F_EventScript_MiguelGoPickFossil::
	msgbox MtMoon_B2F_Text_WellEachTakeAFossil
	release
	end

MtMoon_B2F_EventScript_DomeFossil::
	lock
	faceplayer
	msgbox MtMoon_B2F_Text_YouWantDomeFossil, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MtMoon_B2F_EventScript_DontTakeFossil
	removeobject LOCALID_INTERSTELLAR_MT_MOON_RIFT
	giveitem_msg MtMoon_B2F_Text_ObtainedDomeFossil, ITEM_DOME_FOSSIL, 1, MUS_RG_OBTAIN_KEY_ITEM
	closemessage
	delay 10
	applymovement LOCALID_INTERSTELLAR_GARY_MT_MOON, MtMoon_B2F_Movement_MiguelToHelixFossil
	waitmovement 0
	copyobjectxytoperm LOCALID_INTERSTELLAR_GARY_MT_MOON
	textcolor NPC_TEXT_COLOR_MALE
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	message MtMoon_B2F_Text_ThenThisFossilIsMine
	waitmessage
	waitfanfare
	removeobject LOCALID_INTERSTELLAR_MT_MOON_BLIGHT
	setflag FLAG_GOT_DOME_FOSSIL
	setflag FLAG_GOT_FOSSIL_FROM_MT_MOON
	release
	end

MtMoon_B2F_Movement_MiguelToHelixFossil::
	walk_right
	walk_up
	walk_up
	walk_up
	step_end

MtMoon_B2F_EventScript_HelixFossil::
	lock
	faceplayer
	msgbox MtMoon_B2F_Text_YouWantHelixFossil, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MtMoon_B2F_EventScript_DontTakeFossil
	removeobject LOCALID_INTERSTELLAR_MT_MOON_BLIGHT
	giveitem_msg MtMoon_B2F_Text_ObtainedHelixFossil, ITEM_HELIX_FOSSIL, 1, MUS_RG_OBTAIN_KEY_ITEM
	closemessage
	delay 10
	applymovement LOCALID_INTERSTELLAR_GARY_MT_MOON, MtMoon_B2F_Movement_MiguelToDomeFossil
	waitmovement 0
	copyobjectxytoperm LOCALID_INTERSTELLAR_GARY_MT_MOON
	textcolor NPC_TEXT_COLOR_MALE
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	message MtMoon_B2F_Text_ThenThisFossilIsMine
	waitmessage
	waitfanfare
	removeobject LOCALID_INTERSTELLAR_MT_MOON_RIFT
	setflag FLAG_GOT_HELIX_FOSSIL
	setflag FLAG_GOT_FOSSIL_FROM_MT_MOON
	release
	end

MtMoon_B2F_EventScript_DontTakeFossil::
	release
	end

MtMoon_B2F_Movement_MiguelToDomeFossil::
	walk_up
	walk_up
	walk_up
	step_end

MtMoon_B2F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT, MtMoon_B2F_Text_Grunt1Intro, MtMoon_B2F_Text_Grunt1Defeat
	msgbox MtMoon_B2F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_B2F_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_2, MtMoon_B2F_Text_Grunt2Intro, MtMoon_B2F_Text_Grunt2Defeat
	msgbox MtMoon_B2F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_B2F_EventScript_Grunt3::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_3, MtMoon_B2F_Text_Grunt3Intro, MtMoon_B2F_Text_Grunt3Defeat
	msgbox MtMoon_B2F_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_B2F_EventScript_Grunt4::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_4, MtMoon_B2F_Text_Grunt4Intro, MtMoon_B2F_Text_Grunt4Defeat
	msgbox MtMoon_B2F_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_B2F_Text_MiguelIntro::
	.string "Hey, stop!\p"
	.string "I found these fossils!\n"
	.string "They're both mine!$"

MtMoon_B2F_Text_MiguelDefeat::
	.string "Okay!\n"
	.string "I'll share!$"

MtMoon_B2F_Text_WellEachTakeAFossil::
	.string "We'll each take a fossil!\n"
	.string "No being greedy!$"

MtMoon_B2F_Text_ThenThisFossilIsMine::
	.string "All right.\n"
	.string "Then this fossil is mine!$"

MtMoon_B2F_Text_LabOnCinnabarRegeneratesFossils::
	.string "Far away, on CINNABAR ISLAND,\n"
	.string "there's a POKéMON LAB.\p"
	.string "They do research on regenerating\n"
	.string "fossils.$"

MtMoon_B2F_Text_Grunt1Intro::
	.string "We, TEAM ROCKET, shall find the\n"
	.string "fossils!\p"
	.string "Reviving POKéMON from them will\n"
	.string "earn us huge riches!$"

MtMoon_B2F_Text_Grunt1Defeat::
	.string "Urgh!\n"
	.string "Now I'm mad!$"

MtMoon_B2F_Text_Grunt1PostBattle::
	.string "You made me mad!\n"
	.string "TEAM ROCKET will blacklist you!$"

MtMoon_B2F_Text_Grunt2Intro::
	.string "We, TEAM ROCKET, are POKéMON\n"
	.string "gangsters!\l"
	.string "We strike fear with our strength!$"

MtMoon_B2F_Text_Grunt2Defeat::
	.string "I blew it!$"

MtMoon_B2F_Text_Grunt2PostBattle::
	.string "Darn it all!\n"
	.string "My associates won't stand for this!$"

MtMoon_B2F_Text_Grunt3Intro::
	.string "We're pulling a big job here!\n"
	.string "Get lost, kid!$"

MtMoon_B2F_Text_Grunt3Defeat::
	.string "So, you are good…$"

MtMoon_B2F_Text_Grunt3PostBattle::
	.string "If you find a fossil, give it to me\n"
	.string "and scram!$"

MtMoon_B2F_Text_Grunt4Intro::
	.string "Little kids shouldn't be messing\n"
	.string "around with grown-ups!\p"
	.string "It could be bad news!$"

MtMoon_B2F_Text_Grunt4Defeat::
	.string "I'm steamed!$"

MtMoon_B2F_Text_Grunt4PostBattle::
	.string "POKéMON lived here long before\n"
	.string "people came.$"

MtMoon_B2F_Text_YouWantDomeFossil::
	.string "Do you want the DOME FOSSIL?$"

MtMoon_B2F_Text_YouWantHelixFossil::
	.string "Do you want the HELIX FOSSIL?$"

MtMoon_B2F_Text_ObtainedHelixFossil::
	.string "Obtained the HELIX FOSSIL!$"

MtMoon_B2F_Text_ObtainedDomeFossil::
	.string "Obtained the DOME FOSSIL!$"

MtMoon_B2F_EventScript_RiftGalactic1::
	trainerbattle_single TRAINER_INTERSTELLAR_GALACTIC_MTMOON_3, MtMoon_B2F_Text_RiftGalactic1Intro, MtMoon_B2F_Text_RiftGalactic1Defeat
	msgbox MtMoon_B2F_Text_RiftGalactic1PostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_B2F_EventScript_RiftGalactic2::
	trainerbattle_single TRAINER_INTERSTELLAR_GALACTIC_MTMOON_4, MtMoon_B2F_Text_RiftGalactic2Intro, MtMoon_B2F_Text_RiftGalactic2Defeat
	msgbox MtMoon_B2F_Text_RiftGalactic2PostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_B2F_Text_RiftGalactic1Intro::
	.string "My BRONZOR's compass just spins\n"
	.string "in circles here. Fine.\l"
	.string "Battle first, questions later!$"

MtMoon_B2F_Text_RiftGalactic1Defeat::
	.string "Even BRONZOR is lost.\n"
	.string "That never happens.$"

MtMoon_B2F_Text_RiftGalactic1PostBattle::
	.string "The boss says time and space can\n"
	.string "be rebuilt. Whatever tore this\l"
	.string "cave open beat him to it.$"

MtMoon_B2F_Text_RiftGalactic2Intro::
	.string "MOON STONES? So this is a moon\n"
	.string "mountain… but the wrong one.\l"
	.string "The wrong world. Battle!$"

MtMoon_B2F_Text_RiftGalactic2Defeat::
	.string "Fine! It's not even our moon.$"

MtMoon_B2F_Text_RiftGalactic2PostBattle::
	.string "If that scar leads back to SINNOH,\n"
	.string "TEAM GALACTIC will be the ones\l"
	.string "to open it.$"
