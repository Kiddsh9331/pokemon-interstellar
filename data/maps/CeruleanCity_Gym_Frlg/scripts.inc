CeruleanCity_Gym_Frlg_MapScripts::
	.byte 0

CeruleanCity_Gym_EventScript_Misty::
	famechecker FAMECHECKER_MISTY, FCPICKSTATE_COLORED, UpdatePickStateFromSpecialVar8005
	trainerbattle_single TRAINER_LEADER_MISTY, CeruleanCity_Gym_Text_MistyIntro, CeruleanCity_Gym_Text_MistyDefeat, CeruleanCity_Gym_EventScript_MistyDefeated, NO_MUSIC
	goto_if_unset FLAG_GOT_TM03_FROM_MISTY, CeruleanCity_Gym_EventScript_GiveTM03
	msgbox CeruleanCity_Gym_Text_ExplainTM03
	release
	end

CeruleanCity_Gym_EventScript_MistyDefeated::
	famechecker FAMECHECKER_MISTY, 1
	setflag FLAG_DEFEATED_MISTY
	setflag FLAG_BADGE02_GET
	setrespawn HEAL_LOCATION_CERULEAN_CITY
	set_gym_trainers_frlg 2
	goto CeruleanCity_Gym_EventScript_GiveTM03
	end

CeruleanCity_Gym_EventScript_GiveTM03::
	msgbox CeruleanCity_Gym_Text_ExplainCascadeBadge
	checkitemspace ITEM_TM03
	goto_if_eq VAR_RESULT, FALSE, CeruleanCity_Gym_EventScript_NoRoomForTM03
	giveitem_msg CeruleanCity_Gym_Text_ReceivedTM03FromMisty, ITEM_TM03
	setflag FLAG_GOT_TM03_FROM_MISTY
	msgbox CeruleanCity_Gym_Text_ExplainTM03
	release
	end

CeruleanCity_Gym_EventScript_NoRoomForTM03::
	msgbox CeruleanCity_Gym_Text_BetterMakeRoomForThis
	release
	end

CeruleanCity_Gym_EventScript_Diana::
	trainerbattle_single TRAINER_PICNICKER_DIANA, CeruleanCity_Gym_Text_DianaIntro, CeruleanCity_Gym_Text_DianaDefeat
	msgbox CeruleanCity_Gym_Text_DianaPostBattle, MSGBOX_AUTOCLOSE
	end

CeruleanCity_Gym_EventScript_Luis::
	trainerbattle_single TRAINER_SWIMMER_MALE_LUIS, CeruleanCity_Gym_Text_LuisIntro, CeruleanCity_Gym_Text_LuisDefeat
	famechecker FAMECHECKER_MISTY, 2
	msgbox CeruleanCity_Gym_Text_LuisPostBattle, MSGBOX_AUTOCLOSE
	end

CeruleanCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_MISTY, CeruleanCity_Gym_EventScript_GymGuyPostVictory
	msgbox CeruleanCity_Gym_Text_GymGuyAdvice
	release
	end

CeruleanCity_Gym_EventScript_GymGuyPostVictory::
	msgbox CeruleanCity_Gym_Text_WeMakePrettyGoodTeam
	release
	end

CeruleanCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE02_GET, CeruleanCity_Gym_EventScript_GymStatuePostVictory
	msgbox CeruleanCity_Gym_Text_GymStatue
	releaseall
	end

CeruleanCity_Gym_EventScript_GymStatuePostVictory::
	msgbox CeruleanCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

CeruleanCity_Gym_Text_MistyIntro::
	.string "Yes? I'm MISTY.\p"
	.string "You hear it too, right? The rain\n"
	.string "on the roof. It hasn't stopped\l"
	.string "since the night the sky broke.\p"
	.string "Every drop of it is being pulled\n"
	.string "toward the cave north of here.\l"
	.string "Toward whatever is sitting in\l"
	.string "the dark at the end of it.\p"
	.string "Half this gym is a rescue post\n"
	.string "now. My swimmers pull families\l"
	.string "off flooded porches between\l"
	.string "badge matches.\p"
	.string "I train swimmers. I read water.\n"
	.string "And the water is TERRIFIED.\p"
	.string "If you're going in there, prove\n"
	.string "the current bends around you!{PLAY_BGM}{MUS_RG_ENCOUNTER_GYM_LEADER}$"

CeruleanCity_Gym_Text_ExplainTM03::
	.string "TM03 teaches WATER PULSE.\p"
	.string "Use it on an aquatic POKéMON!$"

CeruleanCity_Gym_Text_ExplainCascadeBadge::
	.string "The CASCADEBADGE makes all\n"
	.string "POKéMON up to Lv. 30 obey.\p"
	.string "That includes even outsiders you\n"
	.string "got in trades.\p"
	.string "There's more. You can now use CUT\n"
	.string "anytime, even out of battle.\p"
	.string "You can CUT down small trees to\n"
	.string "open new pathways.\p"
	.string "You can also have my favorite TM.$"

CeruleanCity_Gym_Text_ReceivedTM03FromMisty::
	.string "{PLAYER} received TM03\n"
	.string "from MISTY.$"

CeruleanCity_Gym_Text_BetterMakeRoomForThis::
	.string "You better make room for this!$"

CeruleanCity_Gym_Text_MistyDefeat::
	.string "…The water went quiet around\n"
	.string "you. It trusts you.\p"
	.string "The official POKéMON LEAGUE\n"
	.string "CASCADEBADGE is yours.\p"
	.string "{FONT_NORMAL}{PLAYER} received the CASCADEBADGE\n"
	.string "from MISTY!{PAUSE_MUSIC}{PLAY_BGM}{MUS_OBTAIN_BADGE}{PAUSE 0xFE}{PAUSE 0x56}{RESUME_MUSIC}\p"
	.string "{FONT_FEMALE}STEVEN is waiting on the west\n"
	.string "bank. He's been diving the cave\l"
	.string "readings for weeks.\p"
	.string "Go end this rain, {PLAYER}.$"

CeruleanCity_Gym_Text_DianaIntro::
	.string "What? You? In the middle of a\n"
	.string "flood watch?\p"
	.string "I'm more than good enough for\n"
	.string "you-- MISTY has rescue rounds\l"
	.string "to run.$"

CeruleanCity_Gym_Text_DianaDefeat::
	.string "Overwhelmed…\n"
	.string "like the north bank levee!$"

CeruleanCity_Gym_Text_DianaPostBattle::
	.string "The rain never misses a beat, and\n"
	.string "the current always bends north--\l"
	.string "toward the cave.\p"
	.string "Nobody swims that way anymore.\p"
	.string "Beat MISTY, and maybe that\n"
	.string "finally changes.$"

CeruleanCity_Gym_Text_LuisIntro::
	.string "Splash!\p"
	.string "I'm first up! But careful--\n"
	.string "the pool's been pulling toward\l"
	.string "the north wall all week.$"

CeruleanCity_Gym_Text_LuisDefeat::
	.string "That can't be!$"

CeruleanCity_Gym_Text_LuisPostBattle::
	.string "MISTY pulled six families off\n"
	.string "their rooftops last week and\l"
	.string "STILL made time to train.\p"
	.string "She won't lose to someone like\n"
	.string "you!\p"
	.string "…Probably.$"

CeruleanCity_Gym_Text_GymGuyAdvice::
	.string "Yo!\n"
	.string "Champ in the making!\p"
	.string "Sandbags at the door, rescue\n"
	.string "boards floating in the pool…\l"
	.string "some GYM, huh?\p"
	.string "The advice still stands: MISTY\n"
	.string "is a WATER pro.\p"
	.string "GRASS-types drink her attacks.\n"
	.string "ELECTRIC-types zap the pool.\p"
	.string "One more thing. If the water\n"
	.string "flinches mid-battle…\p"
	.string "…that's not MISTY doing it.$"

CeruleanCity_Gym_Text_WeMakePrettyGoodTeam::
	.string "You beat MISTY!\n"
	.string "See, what'd I tell ya?\p"
	.string "And listen… the rain on the\n"
	.string "roof. It's softer. I'd SWEAR\l"
	.string "it's softer.\p"
	.string "You and me, kid, we make a pretty\n"
	.string "darn-good team!$"

CeruleanCity_Gym_Text_GymStatue::
	.string "CERULEAN POKéMON GYM\n"
	.string "LEADER: MISTY\p"
	.string "WINNING TRAINERS:\n"
	.string "{RIVAL}$"

CeruleanCity_Gym_Text_GymStatuePlayerWon::
	.string "CERULEAN POKéMON GYM\n"
	.string "LEADER: MISTY\p"
	.string "WINNING TRAINERS:\n"
	.string "{RIVAL}, {PLAYER}$"

