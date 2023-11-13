.set LOCALID_BRAWLY, 10
.set LOCALID_PELIPPER, 11

OmaomaTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OmaomaTown_OnTransition
	.byte 0

OmaomaTown_OnTransition::
	setflag FLAG_VISITED_OMAOMA_TOWN
	compare VAR_TARA_LETTER_STATE, 3
	goto_if_eq OmaomaTown_OnTransition_2
	setflag FLAG_HIDE_OMAOMA_PELIPPER
OmaomaTown_OnTransition_1:
	end

OmaomaTown_OnTransition_2:
	clearflag FLAG_HIDE_OMAOMA_PELIPPER
	goto OmaomaTown_OnTransition_1


OmaomaTown_EventScript_TownSign::
	msgbox OmaomaTown_EventScript_TownSign_Text_0, MSGBOX_SIGN
	end


OmaomaTown_EventScript_ExpertF::
	msgbox OmaomaTown_EventScript_ExpertF_Text_0, MSGBOX_NPC
	return


OmaomaTown_EventScript_Girl::
	msgbox OmaomaTown_EventScript_Girl_Text_0, MSGBOX_NPC
	return


OmaomaTown_EventScript_BugCatcher::
	msgbox OmaomaTown_EventScript_BugCatcher_Text_0, MSGBOX_NPC
	return


OmaomaTown_EventScript_Fisherman::
	msgbox OmaomaTown_EventScript_Fisherman_Text_0, MSGBOX_NPC
	return


OmaomaTown_EventScript_Tara::
	lock
	faceplayer
	switch VAR_TARA_LETTER_STATE
	case 0, OmaomaTown_EventScript_Tara_3
	case 1, OmaomaTown_EventScript_Tara_4
	case 2, OmaomaTown_EventScript_Tara_5
	case 3, OmaomaTown_EventScript_Tara_6
	msgbox OmaomaTown_EventScript_Tara_Text_7
OmaomaTown_EventScript_Tara_1:
	release
	end

OmaomaTown_EventScript_Tara_3:
	msgbox OmaomaTown_EventScript_Tara_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq OmaomaTown_EventScript_Tara_9
	msgbox OmaomaTown_EventScript_Tara_Text_2
	giveitem ITEM_TARAS_LETTER
	setvar VAR_TARA_LETTER_STATE, 1
OmaomaTown_EventScript_Tara_8:
	goto OmaomaTown_EventScript_Tara_1

OmaomaTown_EventScript_Tara_4:
	msgbox OmaomaTown_EventScript_Tara_Text_3
	goto OmaomaTown_EventScript_Tara_1

OmaomaTown_EventScript_Tara_5:
	msgbox OmaomaTown_EventScript_Tara_Text_3
	goto OmaomaTown_EventScript_Tara_1

OmaomaTown_EventScript_Tara_6:
	msgbox OmaomaTown_EventScript_Tara_Text_4
	msgbox OmaomaTown_EventScript_Tara_Text_5
	giveitem ITEM_ULTRA_BALL
	msgbox OmaomaTown_EventScript_Tara_Text_6
	setvar VAR_TARA_LETTER_STATE, 4
	goto OmaomaTown_EventScript_Tara_1

OmaomaTown_EventScript_Tara_9:
	msgbox OmaomaTown_EventScript_Tara_Text_1
	goto OmaomaTown_EventScript_Tara_8


OmaomaTown_EventScript_Pelipper::
	playmoncry SPECIES_PELIPPER, CRY_MODE_NORMAL
	msgbox OmaomaTown_EventScript_Pelipper_Text_0, MSGBOX_NPC
	return


OmaomaTown_EventScript_Brawly::
	lock
	faceplayer
	msgbox OmaomaTown_EventScript_Brawly_Text_0
	msgbox OmaomaTown_EventScript_Brawly_Text_1
	playse SE_PIN
	applymovement LOCALID_BRAWLY, Common_Movement_ExclamationMark
	waitmovement LOCALID_BRAWLY
	msgbox OmaomaTown_EventScript_Brawly_Text_2
	compare VAR_FACING, DIR_WEST
	goto_if_eq OmaomaTown_EventScript_Brawly_2
	applymovement LOCALID_BRAWLY, OmaomaTown_Movement_Brawly_Facing_Up_Down_Left
OmaomaTown_EventScript_Brawly_1:
	waitmovement LOCALID_BRAWLY
	removeobject LOCALID_BRAWLY
	setflag FLAG_FOUND_BRAWLY_OMAOMA
	release
	end

OmaomaTown_EventScript_Brawly_2:
	applymovement LOCALID_BRAWLY, OmaomaTown_Movement_Brawly_Facing_Right
	goto OmaomaTown_EventScript_Brawly_1


OmaomaTown_Movement_Brawly_Facing_Up_Down_Left:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

OmaomaTown_Movement_Brawly_Facing_Right:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

OmaomaTown_EventScript_TownSign_Text_0:
	.string "Oma'oma Town\n“A town that is one with the tide.”$"

OmaomaTown_EventScript_ExpertF_Text_0:
	.string "Our ancestors all came from the Alola\n"
	.string "region.\p"
	.string "We've carved out a space of our own\n"
	.string "here in Oma'oma.$"

OmaomaTown_EventScript_Girl_Text_0:
	.string "Alola! Welcome to Oma'oma!$"

OmaomaTown_EventScript_BugCatcher_Text_0:
	.string "Pokémon helped us build elevated homes\n"
	.string "to handle the rising tide.\p"
	.string "Our bond is what allowed us to survive\n"
	.string "here.$"

OmaomaTown_EventScript_Fisherman_Text_0:
	.string "As much as I love to fish, I make sure to\n"
	.string "only catch as much as we need.\p"
	.string "It's important that we keep the\n"
	.string "ecosystem in balance.$"

OmaomaTown_EventScript_Tara_Text_0:
	.string "Tara: Do you make it out to Rustboro\n"
	.string "City much?\p"
	.string "Do you think you could bring this letter\n"
	.string "to my friend Kate there?$"

OmaomaTown_EventScript_Tara_Text_1:
	.string "Tara: I get it…\p"
	.string "Rustboro feels so far away sometimes.$"

OmaomaTown_EventScript_Tara_Text_2:
	.string "Tara: Yay! That's great!\p"
	.string "She's going to be so happy to hear from\n"
	.string "me.$"

OmaomaTown_EventScript_Tara_Text_3:
	.string "Tara: I can't wait to hear back from\n"
	.string "Kate.$"

OmaomaTown_EventScript_Tara_Text_4:
	.string "Tara: Yipee! Kate's Pelipper brought\n"
	.string "back her response!\p"
	.string "She's going to stop by Oma'oma soon.\p"
	.string "I can't thank you enough for putting us\n"
	.string "back in touch.$"

OmaomaTown_EventScript_Tara_Text_5:
	.string "I bet a trainer like you could use this.$"

OmaomaTown_EventScript_Tara_Text_6:
	.string "Tara: Come back and visit again\n"
	.string "sometime!$"

OmaomaTown_EventScript_Tara_Text_7:
	.string "Tara: It's nice to have friends all\n"
	.string "across Hoenn.$"

OmaomaTown_EventScript_Pelipper_Text_0:
	.string "Pelipper: Pihyoh-pah!$"

OmaomaTown_EventScript_Brawly_Text_0:
	.string "Oh, hey there!\p"
	.string "{PLAYER}, is it?\p"
	.string "I'm Brawly! Dewford's Gym Leader!$"

OmaomaTown_EventScript_Brawly_Text_1:
	.string "… … …$"

OmaomaTown_EventScript_Brawly_Text_2:
	.string "Huh? The other Trainers were looking\n"
	.string "for me?\p"
	.string "I was just hitting the waves before\n"
	.string "opening up the Gym.\p"
	.string "I'll head right over!$"
