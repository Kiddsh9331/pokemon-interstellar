Interstellar_Prologue_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Interstellar_Prologue_OnFrame
	.byte 0

Interstellar_Prologue_OnFrame:
	map_script_2 VAR_INTERSTELLAR_STATE, 2, Interstellar_Prologue_EventScript_Begin
	.2byte 0

Interstellar_Prologue_EventScript_Begin::
	lockall
	applymovement LOCALID_PLAYER, Interstellar_Prologue_Movement_PlayerEnter
	waitmovement 0
	applymovement LOCALID_PROLOGUE_BIRCH, Interstellar_Prologue_Movement_BirchApproach
	waitmovement 0
	msgbox Interstellar_Prologue_Text_BirchBigDay, MSGBOX_DEFAULT
	closemessage
	@ He never gets the case open. The storm takes the moment off him, and the
	@ choice waits until OAK finds all twelve gathered on the other side.
	msgbox Interstellar_Prologue_Text_BirchReachesForCase, MSGBOX_DEFAULT
	closemessage
	delay 30
	playse SE_THUNDER
	waitse
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 8
	setvar VAR_0x8007, 5
	special ShakeCamera
	waitstate
	msgbox Interstellar_Prologue_Text_BirchWhatInThe, MSGBOX_DEFAULT
	closemessage
	playse SE_THUNDER
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 2
	setvar VAR_0x8006, 10
	setvar VAR_0x8007, 4
	special ShakeCamera
	waitstate
	msgbox Interstellar_Prologue_Text_BirchOutsideNow, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	setvar VAR_INTERSTELLAR_STATE, 3
	warp MAP_INTERSTELLAR_PROLOGUE_TOWN, 16, 14
	waitstate
	releaseall
	end

Interstellar_Prologue_Movement_PlayerEnter:
	walk_up
	walk_up
	step_end

Interstellar_Prologue_Movement_BirchApproach:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Interstellar_Prologue_Text_BirchBigDay:
	.string "PROF. BIRCH: {PLAYER}! There you are!\p"
	.string "I know I said today was for a quiet\n"
	.string "field study. But the sky has been\l"
	.string "wrong since dawn.\p"
	.string "Still... every journey needs a first\n"
	.string "step. Today's the day.$"

Interstellar_Prologue_Text_BirchReachesForCase:
	.string "PROF. BIRCH: Go on, then. They're\n"
	.string "in the case behind me-- pick the\l"
	.string "one that looks back at you.\p"
	.string "...Hm?\p"
	.string "That sound is not wind.\n"
	.string "Do you hear it?$"

@ Unused: BIRCH never completes the handover.
Interstellar_Prologue_Text_BirchPerfect:
	.string "PROF. BIRCH: {STR_VAR_1}, is it?\n"
	.string "A fine choice.\p"
	.string "Take good care of each other. The\n"
	.string "world feels unsteady today.\p"
	.string "...Hm? That sound is not wind.\n"
	.string "Do you hear it?$"

Interstellar_Prologue_Text_BirchWhatInThe:
	.string "PROF. BIRCH: What in the--\p"
	.string "The instruments-- every dial in\n"
	.string "the lab just pinned itself.$"

Interstellar_Prologue_Text_BirchOutsideNow:
	.string "PROF. BIRCH: Outside.\n"
	.string "NOW!$"


@ ---------- 12-starter selection (all Gen 1-4 starters, era menu first) ----------
Interstellar_EventScript_ChooseStarter::
	msgbox Interstellar_Text_OakTwelve, MSGBOX_DEFAULT
Interstellar_EventScript_EraMenu::
	message Interstellar_Prologue_Text_WhichEra
	waitmessage
	dynmultichoice 17, 0, TRUE, 4, 0, DYN_MULTICHOICE_CB_NONE, Interstellar_Text_EraKanto, Interstellar_Text_EraJohto, Interstellar_Text_EraHoenn, Interstellar_Text_EraSinnoh
	switch VAR_RESULT
	case 0, Interstellar_EventScript_MenuKanto
	case 1, Interstellar_EventScript_MenuJohto
	case 2, Interstellar_EventScript_MenuHoenn
	case 3, Interstellar_EventScript_MenuSinnoh
	goto Interstellar_EventScript_EraMenu

Interstellar_EventScript_MenuKanto::
	message Interstellar_Prologue_Text_ChoosePartner
	waitmessage
	dynmultichoice 15, 0, FALSE, 3, 0, DYN_MULTICHOICE_CB_NONE, Interstellar_Text_MonBulbasaur, Interstellar_Text_MonCharmander, Interstellar_Text_MonSquirtle
	switch VAR_RESULT
	case 0, Interstellar_EventScript_OfferBulbasaur
	case 1, Interstellar_EventScript_OfferCharmander
	case 2, Interstellar_EventScript_OfferSquirtle
	goto Interstellar_EventScript_EraMenu

Interstellar_EventScript_MenuJohto::
	message Interstellar_Prologue_Text_ChoosePartner
	waitmessage
	dynmultichoice 15, 0, FALSE, 3, 0, DYN_MULTICHOICE_CB_NONE, Interstellar_Text_MonChikorita, Interstellar_Text_MonCyndaquil, Interstellar_Text_MonTotodile
	switch VAR_RESULT
	case 0, Interstellar_EventScript_OfferChikorita
	case 1, Interstellar_EventScript_OfferCyndaquil
	case 2, Interstellar_EventScript_OfferTotodile
	goto Interstellar_EventScript_EraMenu

Interstellar_EventScript_MenuHoenn::
	message Interstellar_Prologue_Text_ChoosePartner
	waitmessage
	dynmultichoice 15, 0, FALSE, 3, 0, DYN_MULTICHOICE_CB_NONE, Interstellar_Text_MonTreecko, Interstellar_Text_MonTorchic, Interstellar_Text_MonMudkip
	switch VAR_RESULT
	case 0, Interstellar_EventScript_OfferTreecko
	case 1, Interstellar_EventScript_OfferTorchic
	case 2, Interstellar_EventScript_OfferMudkip
	goto Interstellar_EventScript_EraMenu

Interstellar_EventScript_MenuSinnoh::
	message Interstellar_Prologue_Text_ChoosePartner
	waitmessage
	dynmultichoice 15, 0, FALSE, 3, 0, DYN_MULTICHOICE_CB_NONE, Interstellar_Text_MonTurtwig, Interstellar_Text_MonChimchar, Interstellar_Text_MonPiplup
	switch VAR_RESULT
	case 0, Interstellar_EventScript_OfferTurtwig
	case 1, Interstellar_EventScript_OfferChimchar
	case 2, Interstellar_EventScript_OfferPiplup
	goto Interstellar_EventScript_EraMenu

Interstellar_EventScript_OfferBulbasaur::
	showmonpic SPECIES_BULBASAUR, 10, 3
	bufferspeciesname STR_VAR_1, SPECIES_BULBASAUR
	msgbox Interstellar_Prologue_Text_ThisOne, MSGBOX_YESNO
	hidemonpic
	goto_if_eq VAR_RESULT, NO, Interstellar_EventScript_MenuKanto
	givemon SPECIES_BULBASAUR, 5
	setvar VAR_STARTER_MON, 0
	return

Interstellar_EventScript_OfferCharmander::
	showmonpic SPECIES_CHARMANDER, 10, 3
	bufferspeciesname STR_VAR_1, SPECIES_CHARMANDER
	msgbox Interstellar_Prologue_Text_ThisOne, MSGBOX_YESNO
	hidemonpic
	goto_if_eq VAR_RESULT, NO, Interstellar_EventScript_MenuKanto
	givemon SPECIES_CHARMANDER, 5
	setvar VAR_STARTER_MON, 1
	return

Interstellar_EventScript_OfferSquirtle::
	showmonpic SPECIES_SQUIRTLE, 10, 3
	bufferspeciesname STR_VAR_1, SPECIES_SQUIRTLE
	msgbox Interstellar_Prologue_Text_ThisOne, MSGBOX_YESNO
	hidemonpic
	goto_if_eq VAR_RESULT, NO, Interstellar_EventScript_MenuKanto
	givemon SPECIES_SQUIRTLE, 5
	setvar VAR_STARTER_MON, 2
	return

Interstellar_EventScript_OfferChikorita::
	showmonpic SPECIES_CHIKORITA, 10, 3
	bufferspeciesname STR_VAR_1, SPECIES_CHIKORITA
	msgbox Interstellar_Prologue_Text_ThisOne, MSGBOX_YESNO
	hidemonpic
	goto_if_eq VAR_RESULT, NO, Interstellar_EventScript_MenuJohto
	givemon SPECIES_CHIKORITA, 5
	setvar VAR_STARTER_MON, 0
	return

Interstellar_EventScript_OfferCyndaquil::
	showmonpic SPECIES_CYNDAQUIL, 10, 3
	bufferspeciesname STR_VAR_1, SPECIES_CYNDAQUIL
	msgbox Interstellar_Prologue_Text_ThisOne, MSGBOX_YESNO
	hidemonpic
	goto_if_eq VAR_RESULT, NO, Interstellar_EventScript_MenuJohto
	givemon SPECIES_CYNDAQUIL, 5
	setvar VAR_STARTER_MON, 1
	return

Interstellar_EventScript_OfferTotodile::
	showmonpic SPECIES_TOTODILE, 10, 3
	bufferspeciesname STR_VAR_1, SPECIES_TOTODILE
	msgbox Interstellar_Prologue_Text_ThisOne, MSGBOX_YESNO
	hidemonpic
	goto_if_eq VAR_RESULT, NO, Interstellar_EventScript_MenuJohto
	givemon SPECIES_TOTODILE, 5
	setvar VAR_STARTER_MON, 2
	return

Interstellar_EventScript_OfferTreecko::
	showmonpic SPECIES_TREECKO, 10, 3
	bufferspeciesname STR_VAR_1, SPECIES_TREECKO
	msgbox Interstellar_Prologue_Text_ThisOne, MSGBOX_YESNO
	hidemonpic
	goto_if_eq VAR_RESULT, NO, Interstellar_EventScript_MenuHoenn
	givemon SPECIES_TREECKO, 5
	setvar VAR_STARTER_MON, 0
	return

Interstellar_EventScript_OfferTorchic::
	showmonpic SPECIES_TORCHIC, 10, 3
	bufferspeciesname STR_VAR_1, SPECIES_TORCHIC
	msgbox Interstellar_Prologue_Text_ThisOne, MSGBOX_YESNO
	hidemonpic
	goto_if_eq VAR_RESULT, NO, Interstellar_EventScript_MenuHoenn
	givemon SPECIES_TORCHIC, 5
	setvar VAR_STARTER_MON, 1
	return

Interstellar_EventScript_OfferMudkip::
	showmonpic SPECIES_MUDKIP, 10, 3
	bufferspeciesname STR_VAR_1, SPECIES_MUDKIP
	msgbox Interstellar_Prologue_Text_ThisOne, MSGBOX_YESNO
	hidemonpic
	goto_if_eq VAR_RESULT, NO, Interstellar_EventScript_MenuHoenn
	givemon SPECIES_MUDKIP, 5
	setvar VAR_STARTER_MON, 2
	return

Interstellar_EventScript_OfferTurtwig::
	showmonpic SPECIES_TURTWIG, 10, 3
	bufferspeciesname STR_VAR_1, SPECIES_TURTWIG
	msgbox Interstellar_Prologue_Text_ThisOne, MSGBOX_YESNO
	hidemonpic
	goto_if_eq VAR_RESULT, NO, Interstellar_EventScript_MenuSinnoh
	givemon SPECIES_TURTWIG, 5
	setvar VAR_STARTER_MON, 0
	return

Interstellar_EventScript_OfferChimchar::
	showmonpic SPECIES_CHIMCHAR, 10, 3
	bufferspeciesname STR_VAR_1, SPECIES_CHIMCHAR
	msgbox Interstellar_Prologue_Text_ThisOne, MSGBOX_YESNO
	hidemonpic
	goto_if_eq VAR_RESULT, NO, Interstellar_EventScript_MenuSinnoh
	givemon SPECIES_CHIMCHAR, 5
	setvar VAR_STARTER_MON, 1
	return

Interstellar_EventScript_OfferPiplup::
	showmonpic SPECIES_PIPLUP, 10, 3
	bufferspeciesname STR_VAR_1, SPECIES_PIPLUP
	msgbox Interstellar_Prologue_Text_ThisOne, MSGBOX_YESNO
	hidemonpic
	goto_if_eq VAR_RESULT, NO, Interstellar_EventScript_MenuSinnoh
	givemon SPECIES_PIPLUP, 5
	setvar VAR_STARTER_MON, 2
	return

@ The choice happens in OAK's lab now, and nobody sent these -- he found them
@ waiting. The old BIRCH wording went with the lab it used to be set in.
Interstellar_Text_OakTwelve:
	.string "PROF. OAK: Twelve of them.\p"
	.string "Every starter I know, and several\n"
	.string "I have only read about-- JOHTO,\l"
	.string "HOENN, SINNOH.\p"
	.string "They were waiting in here when I\n"
	.string "opened up this morning.\p"
	.string "Any era. Any partner.\n"
	.string "The choice is yours.$"

Interstellar_Prologue_Text_WhichEra:
	.string "Which region's partner\n"
	.string "calls to you?$"

Interstellar_Prologue_Text_ChoosePartner:
	.string "Choose your partner!$"

Interstellar_Prologue_Text_ThisOne:
	.string "{STR_VAR_1}, is that the one?$"

Interstellar_Text_EraKanto:
	.string "KANTO$"

Interstellar_Text_EraJohto:
	.string "JOHTO$"

Interstellar_Text_EraHoenn:
	.string "HOENN$"

Interstellar_Text_EraSinnoh:
	.string "SINNOH$"

Interstellar_Text_MonBulbasaur:
	.string "BULBASAUR$"

Interstellar_Text_MonCharmander:
	.string "CHARMANDER$"

Interstellar_Text_MonSquirtle:
	.string "SQUIRTLE$"

Interstellar_Text_MonChikorita:
	.string "CHIKORITA$"

Interstellar_Text_MonCyndaquil:
	.string "CYNDAQUIL$"

Interstellar_Text_MonTotodile:
	.string "TOTODILE$"

Interstellar_Text_MonTreecko:
	.string "TREECKO$"

Interstellar_Text_MonTorchic:
	.string "TORCHIC$"

Interstellar_Text_MonMudkip:
	.string "MUDKIP$"

Interstellar_Text_MonTurtwig:
	.string "TURTWIG$"

Interstellar_Text_MonChimchar:
	.string "CHIMCHAR$"

Interstellar_Text_MonPiplup:
	.string "PIPLUP$"
