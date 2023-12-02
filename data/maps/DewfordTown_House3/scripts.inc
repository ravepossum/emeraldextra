DewfordTown_House3_MapScripts::
	.byte 0


DewfordTown_House3_EventScript_BlackBelt::
	lock
	faceplayer
	goto_if_unset FLAG_RECEIVED_BLACK_BELT, DewfordTown_House3_EventScript_BlackBelt_2
	msgbox DewfordTown_House3_EventScript_BlackBelt_Text_2
DewfordTown_House3_EventScript_BlackBelt_1:
	applymovement 1, DewfordTown_House3_Movement_FaceRight
	waitmovement 1
	release
	end

DewfordTown_House3_EventScript_BlackBelt_2:
	msgbox DewfordTown_House3_EventScript_BlackBelt_Text_0
	giveitem ITEM_BLACK_BELT
	compare VAR_RESULT, FALSE
	goto_if_eq DewfordTown_House3_EventScript_BlackBelt_5
	msgbox DewfordTown_House3_EventScript_BlackBelt_Text_1
	setflag FLAG_RECEIVED_BLACK_BELT
	goto DewfordTown_House3_EventScript_BlackBelt_1

DewfordTown_House3_EventScript_BlackBelt_5:
	goto Common_EventScript_ShowBagIsFull
	goto DewfordTown_House3_EventScript_BlackBelt_1


DewfordTown_House3_EventScript_Makuhita::
	lock
	faceplayer
	playmoncry SPECIES_MAKUHITA, CRY_MODE_NORMAL
	msgbox DewfordTown_House3_EventScript_Makuhita_Text_0
	applymovement 2, DewfordTown_House3_Movement_FaceLeft
	waitmovement 2
	release
	end


DewfordTown_House3_Movement_FaceRight:
	face_right
	step_end

DewfordTown_House3_Movement_FaceLeft:
	face_left
	step_end

DewfordTown_House3_EventScript_BlackBelt_Text_0:
	.string "Makuhita and I are training to join the\n"
	.string "Dewford Gym.\p"
	.string "You look like you have the fighting\n"
	.string "spirit in you too. Take this!$"

DewfordTown_House3_EventScript_BlackBelt_Text_1:
	.string "Give that to your favorite\n"
	.string "Fighting-type Pokémon to give their\l"
	.string "moves some extra kick!$"

DewfordTown_House3_EventScript_BlackBelt_Text_2:
	.string "Just like Makuhita, I'll never give up!$"

DewfordTown_House3_EventScript_Makuhita_Text_0:
	.string "Makuhita: Hi-ta!$"
