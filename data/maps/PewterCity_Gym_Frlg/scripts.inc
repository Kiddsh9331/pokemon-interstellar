PewterCity_Gym_Frlg_MapScripts::
	.byte 0

PewterCity_Gym_EventScript_Brock::
	famechecker FAMECHECKER_BROCK, FCPICKSTATE_COLORED, UpdatePickStateFromSpecialVar8005
	trainerbattle_single TRAINER_LEADER_BROCK, PewterCity_Gym_Text_BrockIntro, PewterCity_Gym_Text_BrockDefeat, PewterCity_Gym_EventScript_DefeatedBrock, NO_MUSIC
	goto_if_unset FLAG_GOT_TM39_FROM_BROCK, PewterCity_Gym_EventScript_GiveTM39
	msgbox PewterCity_Gym_Text_BrockPostBattle
	release
	end

PewterCity_Gym_EventScript_DefeatedBrock::
	famechecker FAMECHECKER_BROCK, 1
	setflag FLAG_DEFEATED_BROCK
	setflag FLAG_BADGE01_GET
	setvar VAR_MAP_SCENE_PEWTER_CITY, 1
	setflag FLAG_HIDE_PEWTER_CITY_GYM_GUIDE
	set_gym_trainers_frlg 1
	goto PewterCity_Gym_EventScript_GiveTM39
	end

PewterCity_Gym_EventScript_GiveTM39::
	msgbox PewterCity_Gym_Text_TakeThisWithYou
	checkitemspace ITEM_TM39
	goto_if_eq VAR_RESULT, FALSE, PewterCity_Gym_EventScript_NoRoomForTM39
	giveitem_msg PewterCity_Gym_Text_ReceivedTM39FromBrock, ITEM_TM39
	setflag FLAG_GOT_TM39_FROM_BROCK
	msgbox PewterCity_Gym_Text_ExplainTM39
	release
	end

PewterCity_Gym_EventScript_NoRoomForTM39::
	msgbox PewterCity_Gym_Text_DontHaveRoomForThis
	release
	end

PewterCity_Gym_EventScript_Liam::
	trainerbattle_single TRAINER_CAMPER_LIAM, PewterCity_Gym_Text_LiamIntro, PewterCity_Gym_Text_LiamDefeat
	msgbox PewterCity_Gym_Text_LiamPostBattle, MSGBOX_AUTOCLOSE
	end

PewterCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_BROCK, PewterCity_Gym_EventScript_GymGuyPostVictory
	msgbox PewterCity_Gym_Text_LetMeTakeYouToTheTop, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PewterCity_Gym_EventScript_GymGuyTakeMeToTop
	goto_if_eq VAR_RESULT, NO, PewterCity_Gym_EventScript_GymGuyDontTakeMeToTop
	end

PewterCity_Gym_EventScript_GymGuyPostVictory::
	msgbox PewterCity_Gym_Text_YoureChampMaterial
	release
	end

PewterCity_Gym_EventScript_GymGuyTakeMeToTop::
	msgbox PewterCity_Gym_Text_LetsGetHappening
	goto PewterCity_Gym_EventScript_GymGuyAdvice
	end

PewterCity_Gym_EventScript_GymGuyDontTakeMeToTop::
	msgbox PewterCity_Gym_Text_ItsFreeLetsGetHappening
	goto PewterCity_Gym_EventScript_GymGuyAdvice
	end

PewterCity_Gym_EventScript_GymGuyAdvice::
	msgbox PewterCity_Gym_Text_TryDifferentPartyOrders
	release
	end

PewterCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE01_GET, PewterCity_Gym_EventScript_GymStatuePostVictory
	msgbox PewterCity_Gym_Text_GymStatue
	releaseall
	end

PewterCity_Gym_EventScript_GymStatuePostVictory::
	msgbox PewterCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

PewterCity_Gym_Text_BrockIntro::
	.string "So you're the one who fell out\n"
	.string "of the sky.\p"
	.string "I'm BROCK. PEWTER's LEADER--\n"
	.string "and lately, its wall.\p"
	.string "Ash on the rooftops. Fossils\n"
	.string "stirring in the MUSEUM. Half my\l"
	.string "neighbors packed for a town that\l"
	.string "may not exist this year.\p"
	.string "Rock doesn't run. Rock holds\n"
	.string "the line while the sky argues\l"
	.string "with itself.\p"
	.string "OAK sent you? Then show me\n"
	.string "you're steady enough to send\l"
	.string "toward that cave.\p"
	.string "Show me you don't crack!{PLAY_BGM}{MUS_RG_ENCOUNTER_GYM_LEADER}$"

PewterCity_Gym_Text_BrockDefeat::
	.string "…Steady hands. Steadier than\n"
	.string "mine.\p"
	.string "As proof, the official POKéMON\n"
	.string "LEAGUE BOULDERBADGE.\p"
	.string "{FONT_NORMAL}{PLAYER} received the BOULDERBADGE\n"
	.string "from BROCK!{PAUSE_MUSIC}{PLAY_BGM}{MUS_OBTAIN_BADGE}{PAUSE 0xFE}{PAUSE 0x56}{RESUME_MUSIC}\p"
	.string "{FONT_MALE}The rift took our future once.\n"
	.string "You're going to take it back.\p"
	.string "MISTY holds CERULEAN, under the\n"
	.string "rain that never stops. She's\l"
	.string "closer to the anchor than anyone.\p"
	.string "Tell her PEWTER still stands.$"

PewterCity_Gym_Text_TakeThisWithYou::
	.string "Wait!\n"
	.string "Take this with you.$"

PewterCity_Gym_Text_ReceivedTM39FromBrock::
	.string "{PLAYER} received TM39\n"
	.string "from BROCK.$"

PewterCity_Gym_Text_ExplainTM39::
	.string "A TM, Technical Machine, contains a\n"
	.string "technique for POKéMON.\p"
	.string "Using a TM teaches the move it\n"
	.string "contains to a POKéMON.\p"
	.string "A TM is good for only one use.\p"
	.string "So, when you use one, pick the\n"
	.string "POKéMON carefully.\p"
	.string "Anyways…\n"
	.string "TM39 contains ROCK TOMB.\p"
	.string "It hurls boulders at the foe and\n"
	.string "lowers its SPEED.$"

PewterCity_Gym_Text_BrockPostBattle::
	.string "The rifts leave black seams in the\n"
	.string "roads and worse things in caves.\p"
	.string "Take ROUTE 3 carefully. If the air\n"
	.string "goes silent, get to solid ground.\p"
	.string "Find MISTY in CERULEAN. Tell her\n"
	.string "PEWTER is still standing.$"

PewterCity_Gym_Text_DontHaveRoomForThis::
	.string "You don't have room for this.$"

PewterCity_Gym_Text_LiamIntro::
	.string "Stop right there, kid!\p"
	.string "You're ten thousand YEARS from\n"
	.string "facing BROCK!\p"
	.string "…Give or take. Time's been\n"
	.string "slippery around here lately.$"

PewterCity_Gym_Text_LiamDefeat::
	.string "Darn!\p"
	.string "Maybe it was only a thousand.$"

PewterCity_Gym_Text_LiamPostBattle::
	.string "BROCK hasn't slept since the ash\n"
	.string "started falling.\p"
	.string "He stands at that podium like\n"
	.string "the mountain is holding HIM up.\p"
	.string "…Or maybe it's the other way\n"
	.string "around.$"

PewterCity_Gym_Text_LetMeTakeYouToTheTop::
	.string "Hiya!\n"
	.string "Still dreaming big? Even NOW?\p"
	.string "…Good. Somebody should.\p"
	.string "The sky cracked open, the fossils\n"
	.string "woke up, and BROCK still takes\l"
	.string "every challenger who walks in.\p"
	.string "Know why? Because a broken world\n"
	.string "needs a champ MORE, not less.\p"
	.string "I'm no TRAINER, but I can talk\n"
	.string "you to the top!$"

PewterCity_Gym_Text_LetsGetHappening::
	.string "All right!\n"
	.string "Let's get happening!$"

PewterCity_Gym_Text_TryDifferentPartyOrders::
	.string "The first POKéMON out in a match is\n"
	.string "at the left of the POKéMON LIST.\p"
	.string "By changing the order of POKéMON,\n"
	.string "you may gain an advantage.\p"
	.string "Try different orders to suit your\n"
	.string "opponent's party.$"

PewterCity_Gym_Text_ItsFreeLetsGetHappening::
	.string "It's a free service!\n"
	.string "Let's get happening!$"

PewterCity_Gym_Text_YoureChampMaterial::
	.string "Just as I thought!\n"
	.string "You're POKéMON champ material!$"

PewterCity_Gym_Text_GymStatue::
	.string "PEWTER POKéMON GYM\n"
	.string "LEADER: BROCK\p"
	.string "WINNING TRAINERS:\n"
	.string "{RIVAL}$"

PewterCity_Gym_Text_GymStatuePlayerWon::
	.string "PEWTER POKéMON GYM\n"
	.string "LEADER: BROCK\p"
	.string "WINNING TRAINERS:\n"
	.string "{RIVAL}, {PLAYER}$"
