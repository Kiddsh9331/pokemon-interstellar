Route1_Frlg_MapScripts::
	.byte 0

Route1_EventScript_MartClerk::
	lock
	faceplayer
	goto_if_set FLAG_GOT_POTION_ON_ROUTE_1, Route1_EventScript_AlreadyGotPotion
	msgbox Route1_Text_WorkAtPokeMartTakeSample
	textcolor NPC_TEXT_COLOR_NEUTRAL
	checkitemspace ITEM_POTION
	goto_if_eq VAR_RESULT, FALSE, EventScript_BagIsFull
	bufferitemname STR_VAR_2, ITEM_POTION
	playfanfare MUS_LEVEL_UP
	message gText_ObtainedTheItem
	waitmessage
	waitfanfare
	additem ITEM_POTION
	msgbox Route1_Text_PutPotionAway
	call EventScript_RestorePrevTextColor
	setflag FLAG_GOT_POTION_ON_ROUTE_1
	release
	end

Route1_EventScript_AlreadyGotPotion::
	msgbox Route1_Text_ComeSeeUsIfYouNeedPokeBalls
	release
	end

Route1_EventScript_Boy::
	msgbox Route1_Text_CanJumpFromLedges, MSGBOX_NPC
	end

@ --- Interstellar: on-the-loose Pokémon and uneasy NPC (rift chaos flavor, no battle) ---

Interstellar_EventScript_Route1LooseMon::
	lock
	faceplayer
	msgbox Interstellar_Text_Route1LooseMon, MSGBOX_DEFAULT
	release
	end

Interstellar_EventScript_Route1UneasyKid::
	msgbox Interstellar_Text_Route1UneasyKid, MSGBOX_NPC
	end

Interstellar_Text_Route1LooseMon::
	.string "A GIRAFARIG steps out of the tall\n"
	.string "grass, blinks at you, and just…\l"
	.string "stands there.\p"
	.string "It shouldn't be anywhere near\n"
	.string "KANTO. It doesn't seem to know\l"
	.string "that.\p"
	.string "It watches you a moment longer,\n"
	.string "then wanders back into the grass.$"

Interstellar_Text_Route1UneasyKid::
	.string "Did you see that GIRAFARIG?\p"
	.string "My dad says POKéMON like that\n"
	.string "don't live anywhere near here.\p"
	.string "Ever since the sky did that\n"
	.string "weird folding thing, stuff's been\l"
	.string "showing up that shouldn't.$"

Route1_EventScript_RouteSign::
	msgbox Route1_Text_RouteSign, MSGBOX_SIGN
	end

Route1_Text_WorkAtPokeMartTakeSample::
	.string "Hi! The MART is still open, even\n"
	.string "with the roads flickering out.\p"
	.string "VIRIDIAN needs supplies and people\n"
	.string "need to keep moving. Take this.$"

Route1_Text_ComeSeeUsIfYouNeedPokeBalls::
	.string "If the wild POKéMON look wrong,\n"
	.string "don't assume they are hostile.\p"
	.string "Come to the MART if you need more\n"
	.string "AEON BALLS or a safe place to ask.$"

Route1_Text_PutPotionAway::
	.string "{PLAYER} put the POTION away in\n"
	.string "the BAG's ITEMS POCKET.$"

Route1_Text_CanJumpFromLedges::
	.string "The ledges still go down. The sky\n"
	.string "doesn't always agree anymore.\p"
	.string "If the air begins to hum, get off\n"
	.string "the road and find solid ground.$"

Route1_Text_RouteSign::
	.string "ROUTE 1\n"
	.string "PALLET TOWN - VIRIDIAN CITY$"
