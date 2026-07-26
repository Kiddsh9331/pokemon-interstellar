MtMoon_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtMoon_1F_OnTransition
	.byte 0

MtMoon_1F_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_MT_MOON_1F
	end

MtMoon_1F_EventScript_ZubatSign::
	msgbox MtMoon_1F_Text_ZubatIsABloodsucker, MSGBOX_SIGN
	end

MtMoon_1F_EventScript_Marcos::
	trainerbattle_single TRAINER_HIKER_MARCOS, MtMoon_1F_Text_MarcosIntro, MtMoon_1F_Text_MarcosDefeat
	msgbox MtMoon_1F_Text_MarcosPostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_1F_EventScript_Josh::
	trainerbattle_single TRAINER_YOUNGSTER_JOSH, MtMoon_1F_Text_JoshIntro, MtMoon_1F_Text_JoshDefeat
	msgbox MtMoon_1F_Text_JoshPostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_1F_EventScript_Miriam::
	trainerbattle_single TRAINER_LASS_MIRIAM, MtMoon_1F_Text_MiriamIntro, MtMoon_1F_Text_MiriamDefeat
	msgbox MtMoon_1F_Text_MiriamPostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_1F_EventScript_Iris::
	trainerbattle_single TRAINER_LASS_IRIS, MtMoon_1F_Text_IrisIntro, MtMoon_1F_Text_IrisDefeat
	msgbox MtMoon_1F_Text_IrisPostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_1F_EventScript_Jovan::
	trainerbattle_single TRAINER_SUPER_NERD_JOVAN, MtMoon_1F_Text_JovanIntro, MtMoon_1F_Text_JovanDefeat
	msgbox MtMoon_1F_Text_JovanPostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_1F_EventScript_Kent::
	trainerbattle_single TRAINER_BUG_CATCHER_KENT, MtMoon_1F_Text_KentIntro, MtMoon_1F_Text_KentDefeat
	msgbox MtMoon_1F_Text_KentPostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_1F_EventScript_Robby::
	trainerbattle_single TRAINER_BUG_CATCHER_ROBBY, MtMoon_1F_Text_RobbyIntro, MtMoon_1F_Text_RobbyDefeat
	msgbox MtMoon_1F_Text_RobbyPostBattle, MSGBOX_AUTOCLOSE
	end

@ --- Interstellar: rift-displaced Rocket / Aqua / Magma grunts ---

MtMoon_1F_EventScript_RiftRocket1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_5, MtMoon_1F_Text_RiftRocket1Intro, MtMoon_1F_Text_RiftRocket1Defeat
	msgbox MtMoon_1F_Text_RiftRocket1PostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_1F_EventScript_RiftRocket2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_6, MtMoon_1F_Text_RiftRocket2Intro, MtMoon_1F_Text_RiftRocket2Defeat
	msgbox MtMoon_1F_Text_RiftRocket2PostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_1F_EventScript_RiftAqua1::
	trainerbattle_single TRAINER_INTERSTELLAR_AQUA_MTMOON_1, MtMoon_1F_Text_RiftAqua1Intro, MtMoon_1F_Text_RiftAqua1Defeat
	msgbox MtMoon_1F_Text_RiftAqua1PostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_1F_EventScript_RiftAqua2::
	trainerbattle_single TRAINER_INTERSTELLAR_AQUA_MTMOON_2, MtMoon_1F_Text_RiftAqua2Intro, MtMoon_1F_Text_RiftAqua2Defeat
	msgbox MtMoon_1F_Text_RiftAqua2PostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_1F_EventScript_RiftMagma1::
	trainerbattle_single TRAINER_INTERSTELLAR_MAGMA_MTMOON_1, MtMoon_1F_Text_RiftMagma1Intro, MtMoon_1F_Text_RiftMagma1Defeat
	msgbox MtMoon_1F_Text_RiftMagma1PostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_1F_EventScript_RiftMagma2::
	trainerbattle_single TRAINER_INTERSTELLAR_MAGMA_MTMOON_2, MtMoon_1F_Text_RiftMagma2Intro, MtMoon_1F_Text_RiftMagma2Defeat
	msgbox MtMoon_1F_Text_RiftMagma2PostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_1F_Text_RiftRocket1Intro::
	.string "Huh?! Last thing I remember I was\n"
	.string "in the ROCKET HIDEOUT, not some\l"
	.string "cave full of cracks!\p"
	.string "Whatever. A POKéMON's a POKéMON!$"

MtMoon_1F_Text_RiftRocket1Defeat::
	.string "Ngh! This isn't my mission\n"
	.string "briefing at all!$"

MtMoon_1F_Text_RiftRocket1PostBattle::
	.string "One second I was somewhere else\n"
	.string "entirely. I don't like this cave.$"

MtMoon_1F_Text_RiftRocket2Intro::
	.string "A TEAM ROCKET grunt, pulled clean\n"
	.string "out of some other job, by the\l"
	.string "look of it.\p"
	.string "Well, I'm still on the clock!$"

MtMoon_1F_Text_RiftRocket2Defeat::
	.string "Tch. Knocked out by a kid, in a\n"
	.string "cave I don't even recognize.$"

MtMoon_1F_Text_RiftRocket2PostBattle::
	.string "These black scars keep spitting\n"
	.string "people out. Boss is gonna hear\l"
	.string "about this.$"

MtMoon_1F_Text_RiftAqua1Intro::
	.string "TEAM AQUA?! In a mountain?\n"
	.string "This isn't even the right region!\p"
	.string "Doesn't matter. Let's go!$"

MtMoon_1F_Text_RiftAqua1Defeat::
	.string "Ugh! Nothing about this cave\n"
	.string "makes sense!$"

MtMoon_1F_Text_RiftAqua1PostBattle::
	.string "One of those black scars spat me\n"
	.string "out here. I want to go home.$"

MtMoon_1F_Text_RiftAqua2Intro::
	.string "There's no ocean for a hundred\n"
	.string "miles, and yet, here I am.\p"
	.string "Fine! I'll battle anyway!$"

MtMoon_1F_Text_RiftAqua2Defeat::
	.string "This mountain beat me before my\n"
	.string "POKéMON even had a chance!$"

MtMoon_1F_Text_RiftAqua2PostBattle::
	.string "I keep hearing something ancient\n"
	.string "moving deeper in the cave.$"

MtMoon_1F_Text_RiftMagma1Intro::
	.string "TEAM MAGMA doesn't answer to\n"
	.string "whatever dragged me here!\p"
	.string "But I'll still battle you!$"

MtMoon_1F_Text_RiftMagma1Defeat::
	.string "Impossible! I lost to a trainer\n"
	.string "from who knows where!$"

MtMoon_1F_Text_RiftMagma1PostBattle::
	.string "I fell through a scar looking for\n"
	.string "warm rock. Found cold stone and\l"
	.string "a battle instead.$"

MtMoon_1F_Text_RiftMagma2Intro::
	.string "A cave full of MOON STONES and\n"
	.string "cracked air. Never seen anything\l"
	.string "like it.\p"
	.string "Let's battle!$"

MtMoon_1F_Text_RiftMagma2Defeat::
	.string "Gah! Even my POKéMON seem thrown\n"
	.string "off by this place!$"

MtMoon_1F_Text_RiftMagma2PostBattle::
	.string "Team Rocket, Team Aqua, now us.\n"
	.string "Whatever tore these scars open\l"
	.string "doesn't care whose turf it is.$"

MtMoon_1F_Text_MarcosIntro::
	.string "Stop! The walls are shifting.\n"
	.string "I heard a second heartbeat in the\l"
	.string "stone and came to check it.$"

MtMoon_1F_Text_MarcosIntro_Vanilla::
	.string "WHOA!\n"
	.string "You shocked me!\l"
	.string "…Oh, you're just a kid!$"

MtMoon_1F_Text_MarcosDefeat::
	.string "Wow!\n"
	.string "Shocked again!$"

MtMoon_1F_Text_MarcosPostBattle::
	.string "If the cave goes quiet, don't trust\n"
	.string "the next turn. It may not be there\l"
	.string "when you come back.$"

MtMoon_1F_Text_MarcosPostBattle_Vanilla::
	.string "Kids like you shouldn't be\n"
	.string "wandering around here in the dark.$"

MtMoon_1F_Text_JoshIntro::
	.string "Did you see the blue light deeper\n"
	.string "in the cave, too?$"

MtMoon_1F_Text_JoshIntro_Vanilla::
	.string "Did you come to explore the cave,\n"
	.string "too?$"

MtMoon_1F_Text_JoshDefeat::
	.string "Losing stinks!\n"
	.string "It's so uncool.$"

MtMoon_1F_Text_JoshPostBattle::
	.string "I came to prove the rift was fake.\n"
	.string "Now I wish it had stayed a rumor.$"

MtMoon_1F_Text_JoshPostBattle_Vanilla::
	.string "I came all the way down here to\n"
	.string "show off to girls.$"

MtMoon_1F_Text_MiriamIntro::
	.string "The tunnel was not this long when\n"
	.string "I entered. I counted the steps.$"

MtMoon_1F_Text_MiriamIntro_Vanilla::
	.string "Wow! It's way bigger in here than\n"
	.string "I thought!$"

MtMoon_1F_Text_MiriamDefeat::
	.string "Oh!\n"
	.string "I lost it!$"

MtMoon_1F_Text_MiriamPostBattle::
	.string "How do you get out of here?\n"
	.string "It's so big, I may get lost.$"

MtMoon_1F_Text_JovanIntro::
	.string "Don't touch the black crystals!\n"
	.string "They move when no one is looking.$"

MtMoon_1F_Text_JovanIntro_Vanilla::
	.string "What!\n"
	.string "Don't sneak up on me!$"

MtMoon_1F_Text_JovanDefeat::
	.string "My POKéMON won't do!$"

MtMoon_1F_Text_JovanPostBattle::
	.string "I have to find stronger POKéMON.\n"
	.string "Where might they be?$"

MtMoon_1F_Text_IrisIntro::
	.string "What?\n"
	.string "I'm waiting for my friends to find\l"
	.string "me here.$"

MtMoon_1F_Text_IrisDefeat::
	.string "I lost?$"

MtMoon_1F_Text_IrisPostBattle::
	.string "I came for fossils. Then the fossils\n"
	.string "started humming back at me.$"

MtMoon_1F_Text_IrisPostBattle_Vanilla::
	.string "I came because I heard there are\n"
	.string "some very rare fossils here.$"

MtMoon_1F_Text_KentIntro::
	.string "Suspicious men are in the cave.\n"
	.string "They said the rift was worth money.$"

MtMoon_1F_Text_KentIntro_Vanilla::
	.string "Suspicious men are in the cave.\n"
	.string "What about you?$"

MtMoon_1F_Text_KentDefeat::
	.string "You got me!$"

MtMoon_1F_Text_KentPostBattle::
	.string "I saw them!\n"
	.string "I'm sure they're from TEAM ROCKET!$"

MtMoon_1F_Text_RobbyIntro::
	.string "CERULEAN is through here... if the\n"
	.string "cave lets us keep the same exits.$"

MtMoon_1F_Text_RobbyIntro_Vanilla::
	.string "You need to go through this cave\n"
	.string "to get to CERULEAN CITY.$"

MtMoon_1F_Text_RobbyDefeat::
	.string "I lost.$"

MtMoon_1F_Text_RobbyPostBattle::
	.string "ZUBAT is tough!\n"
	.string "But if you can catch one, you'll\l"
	.string "be able to count on it.$"

MtMoon_1F_Text_ZubatIsABloodsucker::
	.string "Beware!\n"
	.string "ZUBAT is a bloodsucker!$"

MtMoon_1F_Text_BrockHelpsExcavateFossils::
	.string "Hi, I'm excavating for fossils here\n"
	.string "under MT. MOON.\p"
	.string "Sometimes, BROCK of PEWTER GYM\n"
	.string "lends me a hand.$"
