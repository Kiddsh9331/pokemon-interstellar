@ ---------------------------------------------------------------------------
@ Interstellar: scenery Pokemon (after Heart & Soul). A few wild Pokemon from
@ each area's own encounter table wander the map; talking to one gets its cry.
@ ---------------------------------------------------------------------------

Interstellar_EventScript_SceneryMon::
	lock
	faceplayer
	special Interstellar_GetTalkedMonSpecies
	playmoncry VAR_0x8004, CRY_MODE_NORMAL
	bufferspeciesname STR_VAR_1, VAR_0x8004
	msgbox Interstellar_Text_SceneryMon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Interstellar_Text_SceneryMon:
	.string "The wild {STR_VAR_1} eyes you,\n"
	.string "then goes back to what it was doing.$"
