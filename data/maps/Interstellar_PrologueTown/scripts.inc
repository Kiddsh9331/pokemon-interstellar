Interstellar_PrologueTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Interstellar_PrologueTown_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Interstellar_PrologueTown_OnFrame
	.byte 0

Interstellar_PrologueTown_OnTransition::
	goto_if_eq VAR_INTERSTELLAR_STATE, 3, Interstellar_PrologueTown_OT_ShowBirch
	setflag FLAG_TEMP_11
	end

Interstellar_PrologueTown_OT_ShowBirch::
	end

Interstellar_PrologueTown_OnFrame:
	map_script_2 VAR_INTERSTELLAR_STATE, 3, Interstellar_PrologueTown_EventScript_Storm
	.2byte 0

Interstellar_PrologueTown_EventScript_Storm::
	lockall
	applymovement LOCALID_PLAYER, Interstellar_PrologueTown_Movement_FaceBirch
	waitmovement 0
	setweather WEATHER_RAIN_THUNDERSTORM
	doweather
	playse SE_THUNDER
	waitse
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 2
	setvar VAR_0x8006, 12
	setvar VAR_0x8007, 4
	special ShakeCamera
	waitstate
	msgbox Interstellar_PrologueTown_Text_BirchNotAStorm, MSGBOX_DEFAULT
	closemessage
	fadescreenspeed FADE_TO_WHITE, 2
	fadescreenspeed FADE_FROM_WHITE, 2
	playse SE_THUNDER
	setvar VAR_0x8004, 3
	setvar VAR_0x8005, 3
	setvar VAR_0x8006, 16
	setvar VAR_0x8007, 3
	special ShakeCamera
	waitstate
	msgbox Interstellar_PrologueTown_Text_BirchTheSky, MSGBOX_DEFAULT
	closemessage
	fadescreenspeed FADE_TO_WHITE, 2
	fadescreenspeed FADE_FROM_WHITE, 2
	playse SE_THUNDER
	msgbox Interstellar_PrologueTown_Text_BirchGetDown, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_WHITE
	delay 30
	msgbox Interstellar_PrologueTown_Text_WorldTears, MSGBOX_DEFAULT
	closemessage
	@ Keep the screen white across the rift transfer. Pallet reveals only
	@ once Oak has reached the player.
	call Interstellar_EventScript_InitKantoState
	special HealPlayerParty
	setvar VAR_INTERSTELLAR_STATE, 4
	warp MAP_PALLET_TOWN, 9, 14
	waitstate
	releaseall
	end

@ Pre-set FRLG story state so vanilla Kanto intro events never fire.
Interstellar_EventScript_InitKantoState::
	setflag FLAG_SYS_POKEMON_GET
	setvar VAR_MAP_SCENE_PALLET_TOWN_OAK, 1
	setvar VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 2
	setvar VAR_MAP_SCENE_VIRIDIAN_CITY_MART, 1
	setvar VAR_MAP_SCENE_PEWTER_CITY, 2
	setflag FLAG_HIDE_PEWTER_CITY_RUNNING_SHOES_GUY
	setvar VAR_MAP_SCENE_CERULEAN_CITY_RIVAL, 1
	setflag FLAG_HIDE_CERULEAN_RIVAL
	setvar VAR_MAP_SCENE_CERULEAN_CITY_ROCKET, 1
	setflag FLAG_HIDE_CERULEAN_ROCKET
	setflag FLAG_HIDE_MISC_KANTO_ROCKETS
	setvar VAR_MAP_SCENE_ROUTE24, 1
	setflag FLAG_HIDE_NUGGET_BRIDGE_ROCKET
	setflag FLAG_HIDE_ROUTE_22_RIVAL
	setflag FLAG_HIDE_CERULEAN_CAVE_GUARD
	setflag FLAG_INTERSTELLAR_KANTO_GATE_LOCKED
	setflag FLAG_INTERSTELLAR_RIFT_PORTAL_CLOSED
	setflag FLAG_INTERSTELLAR_SLATEPORT_RIFT_SCAR_HIDDEN
	@ Testing convenience: the RIFT REPEL key item (repurposed Mystic Ticket)
	@ blocks all wild encounters while its flag is set. It starts toggled ON;
	@ use the item from the bag to switch it off/on. Remove for release.
	additem ITEM_MYSTIC_TICKET
	setflag FLAG_HIDE_PEWTER_CITY_RUNNING_SHOES_GUY
	setflag FLAG_INTERSTELLAR_INFINITE_REPEL
	return

Interstellar_Town_EventScript_LockedHouse::
	msgbox Interstellar_Town_Text_LockedHouse, MSGBOX_SIGN
	end

Interstellar_PrologueTown_Movement_FaceBirch:
	face_left
	step_end

Interstellar_PrologueTown_Text_BirchNotAStorm:
	.string "PROF. BIRCH: That's not thunder.\p"
	.string "The barometer is still. Every clock\n"
	.string "in town just lost the same minute.\p"
	.string "The light is wrong. {PLAYER},\n"
	.string "stay close--$"

Interstellar_PrologueTown_Text_BirchTheSky:
	.string "PROF. BIRCH: The sky--\n"
	.string "it's folding inward!\p"
	.string "OAK warned me this pattern could\n"
	.string "cross regions, but not like this--$"

Interstellar_PrologueTown_Text_BirchGetDown:
	.string "PROF. BIRCH: {PLAYER}!\n"
	.string "GET DOWN!$"

Interstellar_PrologueTown_Text_WorldTears:
	.string "The world tears.\p"
	.string "You are falling through something\n"
	.string "that is not sky, past hours that\l"
	.string "never happened and tides that\l"
	.string "never came in.\p"
	.string "And somewhere very far away--\n"
	.string "or very long ago-- a voice that\l"
	.string "is not a voice is calling\l"
	.string "your name.$"

Interstellar_Town_Text_LockedHouse:
	.string "The door is locked.\p"
	.string "...Everyone must already be\n"
	.string "at the lab.$"
