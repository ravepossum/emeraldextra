RustboroCity_Flat3_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_Flat3_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

RustboroCity_Flat3_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	compare VAR_TARA_LETTER_STATE, 3
	goto_if_eq RustboroCity_Flat3_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	clearflag FLAG_HIDE_RUSTBORO_PELIPPER
	return

RustboroCity_Flat3_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	setflag FLAG_HIDE_RUSTBORO_PELIPPER
	return


RustboroCity_Flat3_1F_EventScript_Pelipper::
	playmoncry SPECIES_PELIPPER, CRY_MODE_NORMAL
	msgbox RustboroCity_Flat3_1F_EventScript_Pelipper_Text_0, MSGBOX_NPC
	return


RustboroCity_Flat3_1F_EventScript_Kate::
	lock
	faceplayer
	switch VAR_TARA_LETTER_STATE
	case 1, RustboroCity_Flat3_1F_EventScript_Kate_3
	case 2, RustboroCity_Flat3_1F_EventScript_Kate_4
	msgbox RustboroCity_Flat3_1F_EventScript_Kate_Text_8
RustboroCity_Flat3_1F_EventScript_Kate_1:
	release
	end

RustboroCity_Flat3_1F_EventScript_Kate_3:
	msgbox RustboroCity_Flat3_1F_EventScript_Kate_Text_0
	msgbox RustboroCity_Flat3_1F_EventScript_Kate_Text_1
	playse SE_PIN
	applymovement 1, Common_Movement_ExclamationMark
	msgbox RustboroCity_Flat3_1F_EventScript_Kate_Text_2
	bufferitemname STR_VAR_1, ITEM_TARAS_LETTER
	msgbox RustboroCity_Flat3_1F_EventScript_Kate_Text_3
	removeitem ITEM_TARAS_LETTER
	msgbox RustboroCity_Flat3_1F_EventScript_Kate_Text_4
	giveitem ITEM_LUCKY_EGG
	compare VAR_RESULT, FALSE
	goto_if_eq RustboroCity_Flat3_1F_EventScript_Kate_7
	applymovement 1, Common_Movement_FaceLeft
	msgbox RustboroCity_Flat3_1F_EventScript_Kate_Text_5
	msgbox RustboroCity_Flat3_1F_EventScript_Kate_Text_6
	applymovement 2, RustboroCity_Flat3_1F_Movement_PelipperApproach
	waitmovement 2
	playmoncry SPECIES_PELIPPER, CRY_MODE_NORMAL
	applymovement 2, RustboroCity_Flat3_1F_Movement_PelipperExit
	waitmovement 2
	removeobject 2
	setvar VAR_TARA_LETTER_STATE, 3
RustboroCity_Flat3_1F_EventScript_Kate_6:
	goto RustboroCity_Flat3_1F_EventScript_Kate_1

RustboroCity_Flat3_1F_EventScript_Kate_4:
	msgbox RustboroCity_Flat3_1F_EventScript_Kate_Text_7
	giveitem ITEM_LUCKY_EGG
	compare VAR_RESULT, FALSE
	goto_if_eq RustboroCity_Flat3_1F_EventScript_Kate_11
	setvar VAR_TARA_LETTER_STATE, 3
RustboroCity_Flat3_1F_EventScript_Kate_10:
	goto RustboroCity_Flat3_1F_EventScript_Kate_1

RustboroCity_Flat3_1F_EventScript_Kate_7:
	setvar VAR_TARA_LETTER_STATE, 2
	goto Common_EventScript_ShowBagIsFull
	goto RustboroCity_Flat3_1F_EventScript_Kate_6

RustboroCity_Flat3_1F_EventScript_Kate_11:
	goto Common_EventScript_ShowBagIsFull
	goto RustboroCity_Flat3_1F_EventScript_Kate_10


RustboroCity_Flat3_1F_Movement_PelipperApproach:
	walk_down
	walk_right
	walk_right
	walk_right
	step_end

RustboroCity_Flat3_1F_Movement_PelipperExit:
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

RustboroCity_Flat3_1F_EventScript_Pelipper_Text_0:
	.string "Pelipper: Pihyoh-pah!$"

RustboroCity_Flat3_1F_EventScript_Kate_Text_0:
	.string "Kate: Hi there!$"

RustboroCity_Flat3_1F_EventScript_Kate_Text_1:
	.string "… … …$"

RustboroCity_Flat3_1F_EventScript_Kate_Text_2:
	.string "Kate: You have a letter from Tara? Wow,\n"
	.string "can I see that?$"

RustboroCity_Flat3_1F_EventScript_Kate_Text_3:
	.string "{PLAYER} handed over {STR_VAR_1}.$"

RustboroCity_Flat3_1F_EventScript_Kate_Text_4:
	.string "Kate: Thanks for bringing that all the\n"
	.string "way here!\p"
	.string "Please take this as a token of my\n"
	.string "gratitude.$"

RustboroCity_Flat3_1F_EventScript_Kate_Text_5:
	.string "… … …\p"
	.string "… … …$"

RustboroCity_Flat3_1F_EventScript_Kate_Text_6:
	.string "Kate: Pelipper, can you bring this back\n"
	.string "to Tara?$"

RustboroCity_Flat3_1F_EventScript_Kate_Text_7:
	.string "Kate: Please take this as a token of my\n"
	.string "gratitude.$"

RustboroCity_Flat3_1F_EventScript_Kate_Text_8:
	.string "Kate: I used to live in Oma'oma Town,\n"
	.string "but I moved here to work at Devon Corp.$"
