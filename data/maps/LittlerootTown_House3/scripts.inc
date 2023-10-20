LittlerootTown_House3_MapScripts::
	.byte 0


LittlerootTown_House3_EventScript_Man::
	msgbox LittlerootTown_House3_EventScript_Man_Text_0, MSGBOX_NPC
	return


LittlerootTown_House3_EventScript_Woman::
	msgbox LittlerootTown_House3_EventScript_Woman_Text_0, MSGBOX_NPC
	return


LittlerootTown_House3_EventScript_Man_Text_0:
	.string "At night time, you can find nocturnal\n"
	.string "POKéMON that don't come out during the\l"
	.string "day.$"

LittlerootTown_House3_EventScript_Woman_Text_0:
	.string "POKéMON will only grow stronger up until\n"
	.string "a certain point. You need to defeat gym\l"
	.string "leaders and earn their badges to have\l"
	.string "them become more powerful.$"
