Route112_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route112_OnTransition
	.byte 0

Route112_OnTransition:
	clearflag FLAG_FORCE_MIRAGE_TOWER_VISIBLE
	setvar VAR_JAGGED_PASS_ASH_WEATHER, 0
	call Interstellar_Route112_EventScript_SyncPassScene
	end

@ Interstellar: the MAY who comes down the pass is not the player's MAY.
@ She stands at the JAGGED PASS steps only while the scene is armed
@ (badge three earned, encounter not yet fought).
Interstellar_Route112_EventScript_SyncPassScene::
	setflag FLAG_TEMP_11
	goto_if_set FLAG_INTERSTELLAR_WRONG_RIVAL_DONE, Interstellar_Route112_EventScript_SyncPassDone
	goto_if_lt VAR_INTERSTELLAR_STATE, 12, Interstellar_Route112_EventScript_SyncPassDone
	clearflag FLAG_TEMP_11
Interstellar_Route112_EventScript_SyncPassDone::
	return

Route112_EventScript_MagmaGrunts::
	lockall
	delay 40
	applymovement LOCALID_ROUTE112_GRUNT_1, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 20
	msgbox Route112_Text_LeaderGoingToAwakenThing, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROUTE112_GRUNT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	delay 40
	applymovement LOCALID_ROUTE112_GRUNT_2, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	delay 20
	msgbox Route112_Text_YeahWeNeedMeteorite, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROUTE112_GRUNT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	delay 40
	applymovement LOCALID_ROUTE112_GRUNT_1, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 20
	msgbox Route112_Text_OhThatsWhyCrewWentToFallarbor, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROUTE112_GRUNT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	delay 40
	applymovement LOCALID_ROUTE112_GRUNT_2, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	delay 20
	msgbox Route112_Text_CantLetAnyonePassUntilTheyreBack, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROUTE112_GRUNT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

Route112_EventScript_MtChimneyCableCarSign::
	msgbox Route112_Text_MtChimneyCableCarSign, MSGBOX_SIGN
	end

Route112_EventScript_MtChimneySign::
	msgbox Route112_Text_MtChimneySign, MSGBOX_SIGN
	end

Route112_EventScript_RouteSignLavaridge::
	msgbox Route112_Text_RouteSignLavaridge, MSGBOX_SIGN
	end

Route112_EventScript_Hiker::
	msgbox Route112_Text_NotEasyToGetBackToLavaridge, MSGBOX_NPC
	end

Route112_EventScript_Brice::
	trainerbattle_single TRAINER_BRICE, Route112_Text_BriceIntro, Route112_Text_BriceDefeat
	msgbox Route112_Text_BricePostBattle, MSGBOX_AUTOCLOSE
	end

Route112_EventScript_Trent::
	trainerbattle_single TRAINER_TRENT_1, Route112_Text_TrentIntro, Route112_Text_TrentDefeat, Route112_EventScript_RegisterTrent
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route112_EventScript_RematchTrent
	msgbox Route112_Text_TrentPostBattle, MSGBOX_DEFAULT
	release
	end

Route112_EventScript_RegisterTrent::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route112_Text_TrentRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_TRENT_1
	release
	end

Route112_EventScript_RematchTrent::
	trainerbattle_rematch TRAINER_TRENT_1, Route112_Text_TrentRematchIntro, Route112_Text_TrentRematchDefeat
	msgbox Route112_Text_TrentRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route112_EventScript_Larry::
	trainerbattle_single TRAINER_LARRY, Route112_Text_LarryIntro, Route112_Text_LarryDefeat
	msgbox Route112_Text_LarryPostBattle, MSGBOX_AUTOCLOSE
	end

Route112_EventScript_Carol::
	trainerbattle_single TRAINER_CAROL, Route112_Text_CarolIntro, Route112_Text_CarolDefeat
	msgbox Route112_Text_CarolPostBattle, MSGBOX_AUTOCLOSE
	end

Route112_EventScript_Bryant::
	trainerbattle_single TRAINER_BRYANT, Route112_Text_BryantIntro, Route112_Text_BryantDefeat
	msgbox Route112_Text_BryantPostBattle, MSGBOX_AUTOCLOSE
	end

Route112_EventScript_Shayla::
	trainerbattle_single TRAINER_SHAYLA, Route112_Text_ShaylaIntro, Route112_Text_ShaylaDefeat
	msgbox Route112_Text_ShaylaPostBattle, MSGBOX_AUTOCLOSE
	end

Route112_Text_LeaderGoingToAwakenThing:
	.string "Hey, man, is our leader really going\n"
	.string "to awaken that thing?$"

Route112_Text_YeahWeNeedMeteorite:
	.string "Sounds like it, yeah. But I heard\n"
	.string "we need a METEORITE to do it.$"

Route112_Text_OhThatsWhyCrewWentToFallarbor:
	.string "Oh, I get it now. That's why the rest\n"
	.string "of the crew went out to FALLARBOR.$"

Route112_Text_CantLetAnyonePassUntilTheyreBack:
	.string "You got it. And until they come back,\n"
	.string "we're not to let anyone pass, right.$"

Route112_Text_NotEasyToGetBackToLavaridge:
	.string "The cable car runs again -- WATTSON\n"
	.string "put it on his grid.\p"
	.string "And someone cut a path through the\n"
	.string "ledges. The rift, or a kid with a\l"
	.string "shovel.\p"
	.string "Either way, thank you.$"

Route112_Text_MtChimneyCableCarSign:
	.string "MT. CHIMNEY CABLE CAR\n"
	.string "“A short walk {UP_ARROW} way!”$"

Route112_Text_MtChimneySign:
	.string "MT. CHIMNEY\p"
	.string "“For LAVARIDGE TOWN or the summit,\n"
	.string "please take the CABLE CAR.”$"

Route112_Text_RouteSignLavaridge:
	.string "ROUTE 112\n"
	.string "{LEFT_ARROW} LAVARIDGE TOWN$"


@ ---------------------------------------------------------------------------
@ Interstellar: the foot of MT. CHIMNEY. Below badge three the pass turns
@ the player back; at state 12 the first step toward it is met by a MAY
@ who climbed out of a different timeline entirely.
@ ---------------------------------------------------------------------------
Interstellar_Route112_EventScript_PassTrigger::
	lockall
	goto_if_ge VAR_INTERSTELLAR_STATE, 12, Interstellar_Route112_EventScript_PassOpen
	msgbox Interstellar_Route112_Text_PassSealed, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Interstellar_Route112_Movement_StepBack
	waitmovement 0
	releaseall
	end

Interstellar_Route112_EventScript_PassOpen::
	goto_if_set FLAG_INTERSTELLAR_WRONG_RIVAL_DONE, Interstellar_Route112_EventScript_PassClear
	playse SE_PIN
	applymovement LOCALID_INTERSTELLAR_WRONG_MAY, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_INTERSTELLAR_WRONG_MAY, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	getplayerxy VAR_0x8004, VAR_0x8005
	call_if_eq VAR_0x8004, 6, Interstellar_Route112_EventScript_WrongMayShiftLeft
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox Interstellar_Route112_Text_WrongMayIntro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_INTERSTELLAR_WRONGRIVAL, Interstellar_Route112_Text_WrongMayDefeat
	msgbox Interstellar_Route112_Text_WrongMayAfter, MSGBOX_DEFAULT
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_INTERSTELLAR_WRONG_MAY
	setflag FLAG_TEMP_11
	fadescreenswapbuffers FADE_FROM_BLACK
	msgbox Interstellar_Route112_Text_WrongMayGone, MSGBOX_DEFAULT
	setflag FLAG_INTERSTELLAR_WRONG_RIVAL_DONE
	setvar VAR_TEMP_2, 1
	releaseall
	end

Interstellar_Route112_EventScript_WrongMayShiftLeft::
	applymovement LOCALID_INTERSTELLAR_WRONG_MAY, Interstellar_Route112_Movement_WrongMayLeft
	waitmovement 0
	return

Interstellar_Route112_EventScript_PassClear::
	setvar VAR_TEMP_2, 1
	releaseall
	end

Interstellar_Route112_Movement_StepBack:
	walk_down
	step_end

Interstellar_Route112_Movement_WrongMayLeft:
	walk_left
	face_down
	step_end

Interstellar_Route112_Text_PassSealed:
	.string "Cold static breathes down the\n"
	.string "steps.\p"
	.string "Past the tree line, time runs\n"
	.string "loose. The rangers' rule is\l"
	.string "chalked on the rock:\p"
	.string "“No DYNAMO BADGE, no mountain.”$"

Interstellar_Route112_Text_WrongMayIntro:
	.string "MAY: {PLAYER}?\p"
	.string "No. Stop. You are not {PLAYER}.\p"
	.string "{PLAYER} is in MAHOGANY, sitting\n"
	.string "out the storm. We picked up badge\l"
	.string "five together last week.\p"
	.string "The pass does this. It wears the\n"
	.string "faces you miss.\p"
	.string "...My scanner says there are two\n"
	.string "of ME on this mountain, too.\p"
	.string "I hate this mountain.\p"
	.string "If you are wearing my best\n"
	.string "friend's face--\p"
	.string "then you get what the face earns!$"

Interstellar_Route112_Text_WrongMayDefeat:
	.string "You even win like the real one.$"

Interstellar_Route112_Text_WrongMayAfter:
	.string "MAY: That settled nothing.\p"
	.string "A copy would fight like that.\n"
	.string "{PLAYER} fights like that.\p"
	.string "Stay off my mountain, whatever\n"
	.string "you are. I have readings to chase.\p"
	.string "...If you ARE real, and there are\n"
	.string "two worlds' worth of us walking\l"
	.string "around one map--\p"
	.string "No. Not thinking about it.$"

Interstellar_Route112_Text_WrongMayGone:
	.string "She climbs into the spray without\n"
	.string "looking back.\p"
	.string "A JOHTO badge case, five badges\n"
	.string "lit, swings at her hip.$"
