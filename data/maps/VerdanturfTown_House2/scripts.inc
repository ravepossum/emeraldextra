VerdanturfTown_House2_MapScripts::
	.byte 0


VerdanturfTown_House2_EventScript_BlackBelt::
	lock
	faceplayer
	goto_if_unset FLAG_RECEIVED_PROTECTIVE_PADS, VerdanturfTown_House2_EventScript_BlackBelt_2
	msgbox VerdanturfTown_House2_EventScript_BlackBelt_Text_2
VerdanturfTown_House2_EventScript_BlackBelt_1:
	release
	end

VerdanturfTown_House2_EventScript_BlackBelt_2:
	msgbox VerdanturfTown_House2_EventScript_BlackBelt_Text_0
	giveitem ITEM_PROTECTIVE_PADS
	setflag FLAG_RECEIVED_PROTECTIVE_PADS
	msgbox VerdanturfTown_House2_EventScript_BlackBelt_Text_1
	goto VerdanturfTown_House2_EventScript_BlackBelt_1


VerdanturfTown_House2_EventScript_Beauty::
	msgbox VerdanturfTown_House2_EventScript_Beauty_Text_0, MSGBOX_NPC
	return


VerdanturfTown_House2_EventScript_BlackBelt_Text_0:
	.string "I'm trying to be more conscious of my\n"
	.string "health while training. You should too.\l"
	.string "Take these!$"

VerdanturfTown_House2_EventScript_BlackBelt_Text_1:
	.string "Those will protect your Pokémon from\n"
	.string "contact moves in battle.$"

VerdanturfTown_House2_EventScript_BlackBelt_Text_2:
	.string "The air out here gets me invigorated\n"
	.string "for my training routine!$"

VerdanturfTown_House2_EventScript_Beauty_Text_0:
	.string "I love how easy it is to get to Mauville\n"
	.string "from here.\p"
	.string "Sometimes I even like to visit the Game\n"
	.string "Corner…$"
