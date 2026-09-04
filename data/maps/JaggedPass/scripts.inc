JaggedPass_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, JaggedPass_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, JaggedPass_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, JaggedPass_OnLoad
	.byte 0

JaggedPass_OnResume:
	call_if_eq VAR_JAGGED_PASS_STATE, 0, JaggedPass_EventScript_CheckHasMagmaEmblem
	end

JaggedPass_EventScript_CheckHasMagmaEmblem::
	checkitem ITEM_MAGMA_EMBLEM
	goto_if_eq VAR_RESULT, TRUE, JaggedPass_EventScript_SetReadyToOpenHideout
	return

JaggedPass_EventScript_SetReadyToOpenHideout::
	setvar VAR_JAGGED_PASS_STATE, 1
	return

JaggedPass_OnTransition:
	call Interstellar_JaggedPass_EventScript_SyncMay
	call_if_eq VAR_JAGGED_PASS_ASH_WEATHER, 1, JaggedPass_EventScript_SetWeatherAsh
	end

JaggedPass_EventScript_SetWeatherAsh::
	setweather WEATHER_VOLCANIC_ASH
	doweather
	return

JaggedPass_OnLoad:
	goto_if_le VAR_JAGGED_PASS_STATE, 1, JaggedPass_EventScript_ConcealHideoutEntrance
	end

JaggedPass_EventScript_ConcealHideoutEntrance::
	setmetatile 16, 17, METATILE_Lavaridge_RockWall, TRUE
	setmetatile 16, 18, METATILE_Lavaridge_RockWall, TRUE
	end

JaggedPass_EventScript_OpenMagmaHideout::
	lockall
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	msgbox JaggedPass_Text_BoulderShakingInResponseToEmblem, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, 1   @ vertical pan
	setvar VAR_0x8005, 1   @ horizontal pan
	setvar VAR_0x8006, 16  @ num shakes
	setvar VAR_0x8007, 3   @ shake delay
	special ShakeCamera
	waitstate
	playse SE_EFFECTIVE
	setmetatile 16, 17, METATILE_Lavaridge_CaveEntrance_Top, TRUE
	setmetatile 16, 18, METATILE_Lavaridge_CaveEntrance_Bottom, FALSE
	special DrawWholeMapView
	delay 30
	setvar VAR_JAGGED_PASS_STATE, 2
	waitse
	releaseall
	end

JaggedPass_EventScript_MagmaHideoutGuard::
	lockall
	goto_if_set FLAG_BEAT_MAGMA_GRUNT_JAGGED_PASS, JaggedPass_EventScript_GuardDefeated
	waitse
	playse SE_PIN
	applymovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_FacePlayer
	waitmovement 0
	msgbox JaggedPass_Text_GruntIntro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_GRUNT_JAGGED_PASS, JaggedPass_Text_GruntDefeat
	setflag FLAG_BEAT_MAGMA_GRUNT_JAGGED_PASS
	applymovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

JaggedPass_EventScript_GuardDefeated::
	applymovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_FacePlayer
	waitmovement 0
	msgbox JaggedPass_Text_GoWhereverYouWant, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

JaggedPass_EventScript_Eric::
	trainerbattle_single TRAINER_ERIC, JaggedPass_Text_EricIntro, JaggedPass_Text_EricDefeat
	msgbox JaggedPass_Text_EricPostBattle, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Diana::
	trainerbattle_single TRAINER_DIANA_1, JaggedPass_Text_DianaIntro, JaggedPass_Text_DianaDefeat, JaggedPass_EventScript_RegisterDiana
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, JaggedPass_EventScript_DianaRematch
	msgbox JaggedPass_Text_DianaPostBattle, MSGBOX_DEFAULT
	release
	end

JaggedPass_EventScript_RegisterDiana::
	special PlayerFaceTrainerAfterBattle
	msgbox JaggedPass_Text_DianaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_DIANA_1
	release
	end

JaggedPass_EventScript_DianaRematch::
	trainerbattle_rematch TRAINER_DIANA_1, JaggedPass_Text_DianaRematchIntro, JaggedPass_Text_DianaRematchDefeat
	msgbox JaggedPass_Text_DianaPostRematch, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Ethan::
	trainerbattle_single TRAINER_ETHAN_1, JaggedPass_Text_EthanIntro, JaggedPass_Text_EthanDefeat, JaggedPass_EventScript_RegisterEthan
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, JaggedPass_EventScript_EthanRematch
	msgbox JaggedPass_Text_EthanPostBattle, MSGBOX_DEFAULT
	release
	end

JaggedPass_EventScript_RegisterEthan::
	special PlayerFaceTrainerAfterBattle
	msgbox JaggedPass_Text_EthanRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ETHAN_1
	release
	end

JaggedPass_EventScript_EthanRematch::
	trainerbattle_rematch TRAINER_ETHAN_1, JaggedPass_Text_EthanRematchIntro, JaggedPass_Text_EthanRematchDefeat
	msgbox JaggedPass_Text_EthanPostRematch, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Julio::
	trainerbattle_single TRAINER_JULIO, JaggedPass_Text_JulioIntro, JaggedPass_Text_JulioDefeat
	msgbox JaggedPass_Text_JulioPostBattle, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Autumn::
	trainerbattle_single TRAINER_AUTUMN, JaggedPass_Text_AutumnIntro, JaggedPass_Text_AutumnDefeat
	msgbox JaggedPass_Text_AutumnPostBattle, MSGBOX_AUTOCLOSE
	end

JaggedPass_Text_EricIntro:
	.string "MT. CHIMNEY's JAGGED PASS…\p"
	.string "Now this is what I've always wanted\n"
	.string "in a mountain.\p"
	.string "This jagged bumpiness…\n"
	.string "It rocks my soul!$"

JaggedPass_Text_EricDefeat:
	.string "Losing left me bitter!$"

JaggedPass_Text_EricPostBattle:
	.string "Yes, I did lose at POKéMON…\p"
	.string "But, when it comes to the love of\n"
	.string "the mountains, I have you beat!$"

JaggedPass_Text_DianaIntro:
	.string "This place isn't your casual hike.\n"
	.string "It's not suited for a picnic.$"

JaggedPass_Text_DianaDefeat:
	.string "Ohhh, no!\n"
	.string "The ground is too bumpy…$"

JaggedPass_Text_DianaPostBattle:
	.string "Did you know?\p"
	.string "Some people cleverly ride their\n"
	.string "bicycles up this horribly bumpy pass.$"

JaggedPass_Text_DianaRegister:
	.string "Will you ever be back in this area?\n"
	.string "If you do return, I'd like a rematch.$"

JaggedPass_Text_DianaRematchIntro:
	.string "Picnics are fun wherever you go.\n"
	.string "Just like POKéMON!$"

JaggedPass_Text_DianaRematchDefeat:
	.string "I only lost because the ground is\n"
	.string "too bumpy!$"

JaggedPass_Text_DianaPostRematch:
	.string "I'll forget about losing and just\n"
	.string "enjoy this bumpy hike.$"

JaggedPass_Text_EthanIntro:
	.string "JAGGED PASS is hard to walk on.\n"
	.string "It's a good place for training.$"

JaggedPass_Text_EthanDefeat:
	.string "It was all over while we were still\n"
	.string "trying to find a good footing…$"

JaggedPass_Text_EthanPostBattle:
	.string "If I had an ACRO BIKE, I'd be able to\n"
	.string "jump ledges.$"

JaggedPass_Text_EthanRegister:
	.string "When I get more used to this bumpiness,\n"
	.string "I'll be sure to win!\p"
	.string "Can you register me in your POKéNAV?$"

JaggedPass_Text_EthanRematchIntro:
	.string "I got used to this bumpiness.\n"
	.string "I sing while I climb now.$"

JaggedPass_Text_EthanRematchDefeat:
	.string "It's still not easy to battle on this\n"
	.string "bumpy ground…$"

JaggedPass_Text_EthanPostRematch:
	.string "I should get an ACRO BIKE from RYDEL\n"
	.string "in MAUVILLE CITY…$"

JaggedPass_Text_GruntIntro:
	.string "Wah!\n"
	.string "What are you doing here?\p"
	.string "What am I doing in a place like this?\p"
	.string "What business is it of yours?$"

JaggedPass_Text_GruntDefeat:
	.string "Urrrgh…\p"
	.string "I should've ducked into our HIDEOUT\n"
	.string "right away…$"

JaggedPass_Text_GoWhereverYouWant:
	.string "Okay, oh-kay!\n"
	.string "I admit it--you're strong!\p"
	.string "Don't worry about me.\n"
	.string "Go wherever you want!$"

JaggedPass_Text_BoulderShakingInResponseToEmblem:
	.string "Oh! This boulder is shaking in response\n"
	.string "to the MAGMA EMBLEM!$"

JaggedPass_Text_JulioIntro:
	.string "Aiyeeh! It's awfully scary to shoot\n"
	.string "down the mountain in one go!$"

JaggedPass_Text_JulioDefeat:
	.string "I feel like I'm falling apart…$"

JaggedPass_Text_JulioPostBattle:
	.string "My bicycle bounced around so much,\n"
	.string "my rear end's sore…$"

JaggedPass_Text_AutumnIntro:
	.string "I climb this hill every day.\n"
	.string "I have confidence in my strength!$"

JaggedPass_Text_AutumnDefeat:
	.string "Hmm…\n"
	.string "What went wrong?$"

JaggedPass_Text_AutumnPostBattle:
	.string "What is that odd rock protrusion\n"
	.string "a little up the hill from here?$"


@ ---------------------------------------------------------------------------
@ Interstellar: the real MAY, an hour behind her own face. She waits on the
@ lower pass once the wrong one has come and gone, and moves ahead when the
@ CHIMNEY arc is done (state 13).
@ ---------------------------------------------------------------------------
Interstellar_JaggedPass_EventScript_SyncMay::
	setflag FLAG_TEMP_11
	goto_if_unset FLAG_INTERSTELLAR_WRONG_RIVAL_DONE, Interstellar_JaggedPass_EventScript_SyncMayDone
	goto_if_ge VAR_INTERSTELLAR_STATE, 13, Interstellar_JaggedPass_EventScript_SyncMayDone
	clearflag FLAG_TEMP_11
Interstellar_JaggedPass_EventScript_SyncMayDone::
	return

Interstellar_EventScript_RivalAftermath::
	lock
	faceplayer
	goto_if_set FLAG_INTERSTELLAR_RIVAL_AFTERMATH_DONE, Interstellar_JaggedPass_EventScript_MayShort
	msgbox Interstellar_JaggedPass_Text_MayRattled, MSGBOX_DEFAULT
	setflag FLAG_INTERSTELLAR_RIVAL_AFTERMATH_DONE
	release
	end

Interstellar_JaggedPass_EventScript_MayShort::
	msgbox Interstellar_JaggedPass_Text_MayCounting, MSGBOX_DEFAULT
	release
	end

Interstellar_JaggedPass_Text_MayRattled:
	.string "MAY: Hey. {PLAYER}.\p"
	.string "Tell me you saw her too.\p"
	.string "She came down the pass wearing my\n"
	.string "jacket and my scanner, and she\l"
	.string "looked at ME like I was the ghost.\p"
	.string "A JOHTO badge case, {PLAYER}.\n"
	.string "Five badges. I have never set\l"
	.string "foot in JOHTO.\p"
	.string "DAD's scanner says this mountain\n"
	.string "is carrying twice the people it\l"
	.string "holds. Whole camps that fell in\l"
	.string "from somebody else's weather.\p"
	.string "...I am fine. I am counting\n"
	.string "rifts, not faces.\p"
	.string "Go on up. If you find FLANNERY,\n"
	.string "tell her the hot springs are the\l"
	.string "least of it.\p"
	.string "And {PLAYER}? If you meet me\n"
	.string "again up there...\p"
	.string "Check the badge case before you\n"
	.string "trust her.$"

Interstellar_JaggedPass_Text_MayCounting:
	.string "MAY: Counting rifts.\n"
	.string "Not faces.$"

Interstellar_JaggedPass_EventScript_Bern::
	trainerbattle_single TRAINER_INTERSTELLAR_JP_BERN, Interstellar_JaggedPass_Text_BernIntro, Interstellar_JaggedPass_Text_BernDefeat
	msgbox Interstellar_JaggedPass_Text_BernPost, MSGBOX_AUTOCLOSE
	end

Interstellar_JaggedPass_EventScript_Susie::
	trainerbattle_single TRAINER_INTERSTELLAR_JP_SUSIE, Interstellar_JaggedPass_Text_SusieIntro, Interstellar_JaggedPass_Text_SusieDefeat
	msgbox Interstellar_JaggedPass_Text_SusiePost, MSGBOX_AUTOCLOSE
	end

Interstellar_JaggedPass_Text_BernIntro:
	.string "This mountain is SUPPOSED to be\n"
	.string "on fire!\p"
	.string "I have climbed it for forty\n"
	.string "years! I would know!$"

Interstellar_JaggedPass_Text_BernDefeat:
	.string "Hmph. The jungle fights back.$"

Interstellar_JaggedPass_Text_BernPost:
	.string "Fine. FINE.\p"
	.string "The moss is... soft.\p"
	.string "I am not saying it twice.$"

Interstellar_JaggedPass_Text_SusieIntro:
	.string "The tour bus dropped us off and\n"
	.string "the whole trail was ash!\p"
	.string "That was... what year is it?\n"
	.string "Where did all this GREEN come from?$"

Interstellar_JaggedPass_Text_SusieDefeat:
	.string "Even my sandwiches are confused.$"

Interstellar_JaggedPass_Text_SusiePost:
	.string "If you meet a tour guide up\n"
	.string "there, tell him the picnic is\l"
	.string "still ON.$"

Interstellar_JaggedPass_EventScript_RocketGrunt::
	trainerbattle_single TRAINER_INTERSTELLAR_JAGGED_ROCKET, Interstellar_JaggedPass_Text_RocketIntro, Interstellar_JaggedPass_Text_RocketDefeat
	msgbox Interstellar_JaggedPass_Text_RocketPost, MSGBOX_AUTOCLOSE
	end

Interstellar_JaggedPass_EventScript_GalacticGrunt::
	trainerbattle_single TRAINER_INTERSTELLAR_JAGGED_GALACTIC, Interstellar_JaggedPass_Text_GalacticIntro, Interstellar_JaggedPass_Text_GalacticDefeat
	msgbox Interstellar_JaggedPass_Text_GalacticPost, MSGBOX_AUTOCLOSE
	end

Interstellar_JaggedPass_Text_RocketIntro:
	.string "The boss said dig under MT. MOON.\p"
	.string "One wrong tunnel, and the rock\n"
	.string "let go of me.$"

Interstellar_JaggedPass_Text_RocketDefeat:
	.string "The sky here is the wrong kind\n"
	.string "of dark.$"

Interstellar_JaggedPass_Text_RocketPost:
	.string "No ROCKET post reports back from…\n"
	.string "whenever this is.\p"
	.string "Maybe that means I'm off shift.$"

Interstellar_JaggedPass_Text_GalacticIntro:
	.string "We were promised a new world.\p"
	.string "Cleaner. Quieter. Empty of all\n"
	.string "this… mess.$"

Interstellar_JaggedPass_Text_GalacticDefeat:
	.string "…This broken one looks just like\n"
	.string "the blueprints.$"

Interstellar_JaggedPass_Text_GalacticPost:
	.string "I keep waiting to feel glad.\p"
	.string "I'm going to sit by the waterfall\n"
	.string "for a while instead.$"
