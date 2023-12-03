DewfordTown_House4_MapScripts::
	.byte 0


DewfordTown_House4_EventScript_Man::
	msgbox DewfordTown_House4_EventScript_Man_Text_0, MSGBOX_NPC
	return


DewfordTown_House4_EventScript_Hiker::
	msgbox DewfordTown_House4_EventScript_Hiker_Text_0, MSGBOX_NPC
	return


DewfordTown_House4_EventScript_Man_Text_0:
	.string "Being isolated from the rest of Hoenn\n"
	.string "may seem tough, but it brings us closer\l"
	.string "together.\p"
	.string "We all look out for each other here.$"

DewfordTown_House4_EventScript_Hiker_Text_0:
	.string "I heard there's a resort where people\n"
	.string "do nothing but battle with Pokémon all\l"
	.string "day long.\p"
	.string "That sounds amazing!$"
