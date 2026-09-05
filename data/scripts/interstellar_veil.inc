@ ---------------------------------------------------------------------------
@ Interstellar: the rift veil. Every slice edge with no map on the other side
@ is torn air, not an invisible wall: a scar hangs over the gap, and stepping
@ into the torn tiles flashes white, howls the RIFT GAUGE, and steps you back.
@ Coord triggers use VAR_TEMP_D (never written) so they fire every time.
@ ---------------------------------------------------------------------------

Interstellar_EventScript_RiftVeilWest::
	lockall
	call Interstellar_EventScript_RiftVeilFlash
	applymovement LOCALID_PLAYER, Interstellar_Movement_VeilStepEast
	waitmovement 0
	releaseall
	end

Interstellar_EventScript_RiftVeilEast::
	lockall
	call Interstellar_EventScript_RiftVeilFlash
	applymovement LOCALID_PLAYER, Interstellar_Movement_VeilStepWest
	waitmovement 0
	releaseall
	end

Interstellar_EventScript_RiftVeilNorth::
	lockall
	call Interstellar_EventScript_RiftVeilFlash
	applymovement LOCALID_PLAYER, Interstellar_Movement_VeilStepSouth
	waitmovement 0
	releaseall
	end

Interstellar_EventScript_RiftVeilSouth::
	lockall
	call Interstellar_EventScript_RiftVeilFlash
	applymovement LOCALID_PLAYER, Interstellar_Movement_VeilStepNorth
	waitmovement 0
	releaseall
	end

Interstellar_EventScript_RiftVeilFlash::
	playse SE_THUNDER
	fadescreenspeed FADE_TO_WHITE, 1
	fadescreenspeed FADE_FROM_WHITE, 1
	msgbox Interstellar_Text_RiftVeil, MSGBOX_DEFAULT
	closemessage
	return

@ The scar that marks a veil. Examine text only.
Interstellar_EventScript_VeilScar::
	msgbox Interstellar_Text_VeilScar, MSGBOX_SIGN
	end

Interstellar_Text_RiftVeil:
	.string "The air ahead is torn open, edge to\n"
	.string "edge, and it hums.\p"
	.string "The RIFT GAUGE howls in your bag.\p"
	.string "Not this way. Not yet.$"

Interstellar_Text_VeilScar:
	.string "A tear, wide as the road, sealed to\n"
	.string "a scar that never stopped humming.\p"
	.string "Whatever was on the other side is\n"
	.string "in a different year now.$"

Interstellar_Movement_VeilStepEast:
	walk_right
	step_end

Interstellar_Movement_VeilStepWest:
	walk_left
	step_end

Interstellar_Movement_VeilStepSouth:
	walk_down
	step_end

Interstellar_Movement_VeilStepNorth:
	walk_up
	step_end
