Interstellar_Bedroom_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Interstellar_Bedroom_OnFrame
	.byte 0

Interstellar_Bedroom_OnFrame:
	map_script_2 VAR_INTERSTELLAR_STATE, 0, Interstellar_Bedroom_EventScript_Wake
	.2byte 0

Interstellar_Bedroom_EventScript_Wake::
	lockall
	delay 30
	msgbox Interstellar_Bedroom_Text_Morning, MSGBOX_DEFAULT
	closemessage
	setvar VAR_INTERSTELLAR_STATE, 1
	releaseall
	end

Interstellar_Bedroom_Text_Morning:
	.string "HOENN -- LITTLEROOT TOWN.\n"
	.string "The morning of your first POKéMON.\p"
	.string "(You barely slept.\n"
	.string "Who could?)$"
