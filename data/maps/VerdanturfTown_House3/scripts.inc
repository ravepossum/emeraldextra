VerdanturfTown_House3_MapScripts::
	.byte 0


VerdanturfTown_House3_EventScript_Man::
	lock
	faceplayer
	goto_if_unset FLAG_RECEIVED_TM_SWIFT, VerdanturfTown_House3_EventScript_Man_2
	msgbox VerdanturfTown_House3_EventScript_Man_Text_2
VerdanturfTown_House3_EventScript_Man_1:
	release
	end

VerdanturfTown_House3_EventScript_Man_2:
	msgbox VerdanturfTown_House3_EventScript_Man_Text_0
	giveitem ITEM_TM54
	setflag FLAG_RECEIVED_TM_SWIFT
	msgbox VerdanturfTown_House3_EventScript_Man_Text_1
	goto VerdanturfTown_House3_EventScript_Man_1


VerdanturfTown_House3_EventScript_Man_Text_0:
	.string "The best things in life are the ones you\n"
	.string "can rely on.\p"
	.string "Let me share my favorite TM with you.$"

VerdanturfTown_House3_EventScript_Man_Text_1:
	.string "Swift will always strike true and never\n"
	.string "miss the target.$"

VerdanturfTown_House3_EventScript_Man_Text_2:
	.string "Having a good routine is key.$"
