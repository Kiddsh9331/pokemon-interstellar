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

Interstellar_Hoenn_EventScript_MomScene::
	lockall
	msgbox Interstellar_House1F_Text_MomBigDay, MSGBOX_DEFAULT
	closemessage
	setvar VAR_INTERSTELLAR_STATE, 2
	releaseall
	end

@ BIRCH stands at (6,4); the player comes in at (6,12) or (7,12).
Interstellar_Hoenn_EventScript_LabScene::
	lockall
	applymovement LOCALID_PLAYER, Interstellar_Hoenn_Movement_IntoLab
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

Interstellar_Hoenn_Movement_IntoLab:
	walk_up
	walk_up
	walk_up
	step_end

@ Outside, with the sky coming apart over LITTLEROOT.
Interstellar_Hoenn_EventScript_Storm::
	lockall
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
