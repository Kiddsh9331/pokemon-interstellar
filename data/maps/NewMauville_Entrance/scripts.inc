NewMauville_Entrance_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, NewMauville_Entrance_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, NewMauville_Entrance_OnTransition
	.byte 0

@ Interstellar: the BASEMENT KEY does not exist in this story. WATTSON tells
@ the door to expect the player (VAR_INTERSTELLAR_STATE 10); the opening
@ itself is remembered in FLAG_INTERSTELLAR_NM_DOOR_OPENED so the metatiles
@ and the approach trigger stay consistent on every later visit.
NewMauville_Entrance_OnLoad:
	call_if_unset FLAG_INTERSTELLAR_NM_DOOR_OPENED, NewMauville_Entrance_EventScript_CloseDoor
	end

NewMauville_Entrance_EventScript_CloseDoor::
	setmetatile 3, 0, METATILE_Facility_NewMauvilleDoor_Closed_Tile0, TRUE
	setmetatile 4, 0, METATILE_Facility_NewMauvilleDoor_Closed_Tile1, TRUE
	setmetatile 5, 0, METATILE_Facility_NewMauvilleDoor_Closed_Tile2, TRUE
	setmetatile 3, 1, METATILE_Facility_NewMauvilleDoor_Closed_Tile3, TRUE
	setmetatile 4, 1, METATILE_Facility_NewMauvilleDoor_Closed_Tile4, TRUE
	setmetatile 5, 1, METATILE_Facility_NewMauvilleDoor_Closed_Tile5, TRUE
	return

NewMauville_Entrance_OnTransition:
	setflag FLAG_LANDMARK_NEW_MAUVILLE
	call_if_set FLAG_INTERSTELLAR_NM_DOOR_OPENED, NewMauville_Entrance_EventScript_DisarmDoorTrigger
	end

NewMauville_Entrance_EventScript_DisarmDoorTrigger::
	setvar VAR_TEMP_1, 1
	return

NewMauville_Entrance_EventScript_Door::
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	goto_if_ge VAR_INTERSTELLAR_STATE, 10, NewMauville_Entrance_EventScript_OpenDoor
	msgbox NewMauville_Entrance_Text_DoorSealed, MSGBOX_DEFAULT
	setvar VAR_TEMP_1, 1
	releaseall
	end

NewMauville_Entrance_EventScript_OpenDoor::
	msgbox NewMauville_Entrance_Text_DoorExpectsYou, MSGBOX_DEFAULT
	setmetatile 3, 0, METATILE_Facility_NewMauvilleDoor_Open_Tile0, FALSE
	setmetatile 4, 0, METATILE_Facility_NewMauvilleDoor_Open_Tile1, FALSE
	setmetatile 5, 0, METATILE_Facility_NewMauvilleDoor_Open_Tile2, FALSE
	setmetatile 3, 1, METATILE_Facility_NewMauvilleDoor_Open_Tile3, TRUE
	setmetatile 4, 1, METATILE_Facility_NewMauvilleDoor_Open_Tile4, FALSE
	setmetatile 5, 1, METATILE_Facility_NewMauvilleDoor_Open_Tile5, TRUE
	special DrawWholeMapView
	playse SE_BANG
	setflag FLAG_INTERSTELLAR_NM_DOOR_OPENED
	setvar VAR_TEMP_1, 1
	releaseall
	end

NewMauville_Entrance_Text_DoorSealed:
	.string "The door is sealed.\p"
	.string "From deep below: a hum, like a\n"
	.string "hive of angry MAGNEMITE.$"

NewMauville_Entrance_Text_DoorExpectsYou:
	.string "The lock blinks twice, as if\n"
	.string "someone told it to expect you.\p"
	.string "The door slides open.$"
