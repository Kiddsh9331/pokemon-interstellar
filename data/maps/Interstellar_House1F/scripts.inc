Interstellar_House1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Interstellar_House1F_OnFrame
	.byte 0

Interstellar_House1F_OnFrame:
	map_script_2 VAR_INTERSTELLAR_STATE, 1, Interstellar_House1F_EventScript_MomScene
	.2byte 0

Interstellar_House1F_EventScript_MomScene::
	lockall
	applymovement LOCALID_INTERSTELLAR_MOM, Interstellar_House1F_Movement_MomNotice
	waitmovement 0
	msgbox Interstellar_House1F_Text_MomBigDay, MSGBOX_DEFAULT
	closemessage
	setvar VAR_INTERSTELLAR_STATE, 2
	releaseall
	end

Interstellar_EventScript_Mom::
	lock
	faceplayer
	msgbox Interstellar_House1F_Text_MomRest, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Interstellar_House1F_EventScript_MomHint
	fadescreen FADE_TO_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
	fadescreen FADE_FROM_BLACK
	msgbox Interstellar_House1F_Text_MomThereWeAre, MSGBOX_DEFAULT
Interstellar_House1F_EventScript_MomHint::
	msgbox Interstellar_House1F_Text_MomGoOn, MSGBOX_DEFAULT
	release
	end

Interstellar_House1F_Movement_MomNotice:
	emote_exclamation_mark
	delay_16
	face_up
	step_end

Interstellar_House1F_Text_MomBigDay:
	.string "MOM: Oh! Look who's finally up!\p"
	.string "PROF. BIRCH came by at dawn,\n"
	.string "{PLAYER}. Today's the day--\l"
	.string "your first POKéMON!\p"
	.string "He's waiting at the lab.\n"
	.string "Go on-- and come show me after!$"

Interstellar_House1F_Text_MomRest:
	.string "MOM: Rest a moment first?$"

Interstellar_House1F_Text_MomThereWeAre:
	.string "MOM: There.\n"
	.string "Right as rain.$"

Interstellar_House1F_Text_MomGoOn:
	.string "MOM: The lab's just across the\n"
	.string "way. Go on, sweetheart.$"
