@ ---------------------------------------------------------------------------
@ The Hoenn opening, played on the real LITTLEROOT maps.
@
@ Each beat hangs off VAR_INTERSTELLAR_STATE:
@   0  wake in the bedroom              1  MOM downstairs
@   2  BIRCH's lab, storm interrupts    3  outside, the rift takes the player
@ The vanilla Hoenn scripts on these maps are untouched; their own state vars
@ are pre-set past their scenes at new game so they never fire.
@ ---------------------------------------------------------------------------

Interstellar_Hoenn_Bedroom_OnFrame:
	map_script_2 VAR_INTERSTELLAR_STATE, 0, Interstellar_Hoenn_EventScript_Wake
	.2byte 0

Interstellar_Hoenn_EventScript_Wake::
	lockall
	delay 30
	msgbox Interstellar_Bedroom_Text_Morning, MSGBOX_DEFAULT
	closemessage
	setvar VAR_INTERSTELLAR_STATE, 1
	releaseall
	end

@ Downstairs the storm is already the morning news. MOM stands at her default
@ (2,6) -- VAR_LITTLEROOT_INTRO_STATE is set past every vanilla scene, so
@ nothing repositions her -- and the player comes down the stairs at (8,2).
@ The player crosses to the TV and MOM comes over to watch it with them.
Interstellar_Hoenn_EventScript_MomScene::
	lockall
	applymovement LOCALID_PLAYER, Interstellar_Hoenn_Movement_PlayerToTV
	waitmovement 0
	applymovement LOCALID_PLAYERS_HOUSE_1F_MOM, Interstellar_Hoenn_Movement_MomToTV
	waitmovement 0
	msgbox Interstellar_Hoenn_Text_MomWeather, MSGBOX_DEFAULT
	closemessage
	msgbox Interstellar_Hoenn_Text_TVWeather, MSGBOX_DEFAULT
	closemessage
	msgbox Interstellar_Hoenn_Text_TVSightings, MSGBOX_DEFAULT
	closemessage
	msgbox Interstellar_Hoenn_Text_TVSky, MSGBOX_DEFAULT
	closemessage
	msgbox Interstellar_Hoenn_Text_MomGoToBirch, MSGBOX_DEFAULT
	closemessage
	setvar VAR_INTERSTELLAR_STATE, 2
	releaseall
	end

@ Down the stairs puts the player on (8,3), not the (8,2) warp tile, so this
@ lands on (5,5): beside the TV unit, facing it.
Interstellar_Hoenn_Movement_PlayerToTV:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	step_end

@ (2,6) -> (4,5), stopping one tile short of the player and already facing
@ them. Row 5 is the only clear lane across the room -- row 6 is the kitchen
@ counter -- and stopping short matters twice over: walking any further would
@ take her through the player's own tile, and standing on the tile below him
@ would draw her over him from the waist down, since overworld sprites are two
@ tiles tall and sort by y.
Interstellar_Hoenn_Movement_MomToTV:
	walk_up
	walk_right
	walk_right
	step_end

Interstellar_Hoenn_Text_MomWeather:
	.string "MOM: There you are.\p"
	.string "Did the thunder keep you up?\n"
	.string "It's been like that since dawn.\p"
	.string "No rain. Not a drop. Just the sky\n"
	.string "arguing with itself.$"

Interstellar_Hoenn_Text_TVWeather:
	.string "TV: ...still no front, no drop in\n"
	.string "pressure, nothing to explain it.\p"
	.string "LITTLEROOT, OLDALE, half of\n"
	.string "ROUTE 103. All the same sky.$"

Interstellar_Hoenn_Text_TVSightings:
	.string "TV: And trainers on the coast are\n"
	.string "reporting POKéMON nobody can put\l"
	.string "a name to.\p"
	.string "Not HOENN species. Not in any\n"
	.string "guidebook we have here.$"

Interstellar_Hoenn_Text_TVSky:
	.string "TV: Viewers have been sending us\n"
	.string "this one all morning.\p"
	.string "A seam of light, low over the\n"
	.string "trees. It doesn't drift with the\l"
	.string "clouds. It doesn't move at all.$"

Interstellar_Hoenn_Text_MomGoToBirch:
	.string "MOM: PROF. BIRCH has been at the\n"
	.string "lab since it started.\p"
	.string "Go on. He'll want you where he\n"
	.string "can see you.$"

@ The lab door in LITTLEROOT targets warp 0, so the player always arrives at
@ (6,12). BIRCH stands at (6,4) and column 6 is clear the whole way down -- the
@ three starter balls sit on (6,8) but are hidden, so he walks straight through
@ them. The player takes two steps in and BIRCH comes to meet them.
Interstellar_Hoenn_EventScript_LabScene::
	lockall
	applymovement LOCALID_PLAYER, Interstellar_Hoenn_Movement_IntoLab
	waitmovement 0
	delay 20
	applymovement LOCALID_BIRCHS_LAB_BIRCH, Interstellar_Hoenn_Movement_BirchApproach
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
	warp MAP_LITTLEROOT_TOWN, 7, 17
	waitstate
	releaseall
	end

@ (6,12) -> (6,10), facing up.
Interstellar_Hoenn_Movement_IntoLab:
	walk_up
	walk_up
	step_end

@ (6,4) -> (6,9), which leaves him facing down at the player.
Interstellar_Hoenn_Movement_BirchApproach:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

@ Outside, with the sky coming apart over LITTLEROOT. The town's own weather is
@ the slow rain that has been falling since the player left the house; the storm
@ beat escalates it to thunder, the way the old prologue town did.
Interstellar_Hoenn_EventScript_Storm::
	lockall
	setweather WEATHER_RAIN_THUNDERSTORM
	doweather
	@ BIRCH followed the player out of the lab, but the town's copy of him is
	@ hidden at new game, so his lines were playing to an empty street. Bring him
	@ back and stand him in the lab doorway at (7,16), directly above the tile the
	@ player warps onto. Object 8 on this map; it has no LOCALID constant.
	setobjectxyperm 8, 7, 16
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCH
	addobject 8
	turnobject 8, DIR_SOUTH
	delay 20
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 2
	setvar VAR_0x8006, 10
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
