MtMoon_B1F_Frlg_MapScripts::
	.byte 0

@ --- Interstellar: rift-displaced Rocket / Aqua / Magma grunts ---

MtMoon_B1F_EventScript_RiftRocket1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_7, MtMoon_B1F_Text_RiftRocket1Intro, MtMoon_B1F_Text_RiftRocket1Defeat
	msgbox MtMoon_B1F_Text_RiftRocket1PostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_B1F_EventScript_RiftRocket2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_8, MtMoon_B1F_Text_RiftRocket2Intro, MtMoon_B1F_Text_RiftRocket2Defeat
	msgbox MtMoon_B1F_Text_RiftRocket2PostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_B1F_EventScript_RiftRocket3::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_9, MtMoon_B1F_Text_RiftRocket3Intro, MtMoon_B1F_Text_RiftRocket3Defeat
	msgbox MtMoon_B1F_Text_RiftRocket3PostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_B1F_EventScript_RiftAqua1::
	trainerbattle_single TRAINER_INTERSTELLAR_AQUA_MTMOON_3, MtMoon_B1F_Text_RiftAqua1Intro, MtMoon_B1F_Text_RiftAqua1Defeat
	msgbox MtMoon_B1F_Text_RiftAqua1PostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_B1F_EventScript_RiftAqua2::
	trainerbattle_single TRAINER_INTERSTELLAR_AQUA_MTMOON_4, MtMoon_B1F_Text_RiftAqua2Intro, MtMoon_B1F_Text_RiftAqua2Defeat
	msgbox MtMoon_B1F_Text_RiftAqua2PostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_B1F_EventScript_RiftMagma1::
	trainerbattle_single TRAINER_INTERSTELLAR_MAGMA_MTMOON_3, MtMoon_B1F_Text_RiftMagma1Intro, MtMoon_B1F_Text_RiftMagma1Defeat
	msgbox MtMoon_B1F_Text_RiftMagma1PostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_B1F_EventScript_RiftMagma2::
	trainerbattle_single TRAINER_INTERSTELLAR_MAGMA_MTMOON_4, MtMoon_B1F_Text_RiftMagma2Intro, MtMoon_B1F_Text_RiftMagma2Defeat
	msgbox MtMoon_B1F_Text_RiftMagma2PostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_B1F_Text_RiftRocket1Intro::
	.string "Ngh… one second I was in a\n"
	.string "warehouse, now I'm in a cave?\p"
	.string "Whatever! Hand over your\n"
	.string "POKéMON!$"

MtMoon_B1F_Text_RiftRocket1Defeat::
	.string "This whole cave is wrong, and now\n"
	.string "I've lost too!$"

MtMoon_B1F_Text_RiftRocket1PostBattle::
	.string "I don't even recognize this part\n"
	.string "of MT. MOON. Or is it MT. MOON?$"

MtMoon_B1F_Text_RiftRocket2Intro::
	.string "Great, dragged into a cave by a\n"
	.string "crack in the air. Typical.\p"
	.string "Fine, let's get this over with!$"

MtMoon_B1F_Text_RiftRocket2Defeat::
	.string "Just my luck. Pulled through a\n"
	.string "rift AND beaten.$"

MtMoon_B1F_Text_RiftRocket2PostBattle::
	.string "There are TINY MUSHROOMS growing\n"
	.string "everywhere down here. Creepy.$"

MtMoon_B1F_Text_RiftRocket3Intro::
	.string "I was chasing a MEOWTH. Now I'm\n"
	.string "chasing you instead!$"

MtMoon_B1F_Text_RiftRocket3Defeat::
	.string "Lost the MEOWTH, lost the battle.\n"
	.string "Rough day.$"

MtMoon_B1F_Text_RiftRocket3PostBattle::
	.string "Whatever tore that scar open, it's\n"
	.string "still humming behind me.$"

MtMoon_B1F_Text_RiftAqua1Intro::
	.string "TEAM AQUA doesn't do caves. But\n"
	.string "here I am, so let's battle!$"

MtMoon_B1F_Text_RiftAqua1Defeat::
	.string "This isn't even close to the sea.\n"
	.string "None of this makes sense!$"

MtMoon_B1F_Text_RiftAqua1PostBattle::
	.string "The scar I fell through is still\n"
	.string "open. I can feel the pull from\l"
	.string "here.$"

MtMoon_B1F_Text_RiftAqua2Intro::
	.string "One minute I'm on a boat, the next\n"
	.string "I'm underground. Let's battle and\l"
	.string "sort out the details later!$"

MtMoon_B1F_Text_RiftAqua2Defeat::
	.string "Beaten, lost, and nowhere near\n"
	.string "water. Not my day.$"

MtMoon_B1F_Text_RiftAqua2PostBattle::
	.string "These BIG MUSHROOMS smell like the\n"
	.string "tide. That can't be right.$"

MtMoon_B1F_Text_RiftMagma1Intro::
	.string "TEAM MAGMA answers to the boss,\n"
	.string "not to whatever scar dropped me\l"
	.string "here. Let's battle!$"

MtMoon_B1F_Text_RiftMagma1Defeat::
	.string "This cave is colder than anything\n"
	.string "MAGMA'S ever operated in!$"

MtMoon_B1F_Text_RiftMagma1PostBattle::
	.string "I felt the ground crack open\n"
	.string "behind me, then I was just… here.$"

MtMoon_B1F_Text_RiftMagma2Intro::
	.string "Never seen so many MOON STONES\n"
	.string "in one place. Let's battle before\l"
	.string "I figure out how I got here.$"

MtMoon_B1F_Text_RiftMagma2Defeat::
	.string "Lost again. This whole cave is\n"
	.string "against me today.$"

MtMoon_B1F_Text_RiftMagma2PostBattle::
	.string "Rocket, Aqua, and now us MAGMA\n"
	.string "folks, all pulled into one cave.\l"
	.string "Something's very wrong here.$"

MtMoon_B1F_EventScript_RiftGalactic1::
	trainerbattle_single TRAINER_INTERSTELLAR_GALACTIC_MTMOON_1, MtMoon_B1F_Text_RiftGalactic1Intro, MtMoon_B1F_Text_RiftGalactic1Defeat
	msgbox MtMoon_B1F_Text_RiftGalactic1PostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_B1F_EventScript_RiftGalactic2::
	trainerbattle_single TRAINER_INTERSTELLAR_GALACTIC_MTMOON_2, MtMoon_B1F_Text_RiftGalactic2Intro, MtMoon_B1F_Text_RiftGalactic2Defeat
	msgbox MtMoon_B1F_Text_RiftGalactic2PostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_B1F_Text_RiftGalactic1Intro::
	.string "TEAM GALACTIC was promised a new\n"
	.string "universe. This cave isn't it.\l"
	.string "Battle!$"

MtMoon_B1F_Text_RiftGalactic1Defeat::
	.string "Not even my STUNKY knows where\n"
	.string "we are.$"

MtMoon_B1F_Text_RiftGalactic1PostBattle::
	.string "That scar hums like the lab\n"
	.string "generators back home.\l"
	.string "It worries me.$"

MtMoon_B1F_Text_RiftGalactic2Intro::
	.string "I was guarding a lab in VEILSTONE.\n"
	.string "Then the wall folded.\l"
	.string "You'll do as a test subject!$"

MtMoon_B1F_Text_RiftGalactic2Defeat::
	.string "Beaten in a cave I can't even\n"
	.string "find on a map…$"

MtMoon_B1F_Text_RiftGalactic2PostBattle::
	.string "Space isn't supposed to fold on\n"
	.string "its own. That's OUR job.$"
