OldaleTown_House3_MapScripts::
	.byte 0


OldaleTown_House3_EventScript_Scientist::
	msgbox OldaleTown_House3_EventScript_Scientist_Text_0, MSGBOX_NPC
	return


OldaleTown_House3_EventScript_Scientist2::
	msgbox OldaleTown_House3_EventScript_Scientist2_Text_0, MSGBOX_NPC
	return


OldaleTown_House3_EventScript_Scientist_Text_0:
	.string "Thanks to new technology, you can now\n"
	.string "see your Pokémon's Effort Values (EVs)\l"
	.string "by pressing the L Button while viewing\l"
	.string "their stats.\p"
	.string "You can also view their Individual\n"
	.string "Values (IVs) by pressing the R Button\l"
	.string "while viewing their stats.$"

OldaleTown_House3_EventScript_Scientist2_Text_0:
	.string "When you search for Pokémon using the\n"
	.string "DexNav, you'll be able to see additional\l"
	.string "information about them.\p"
	.string "This can include their level, their\n"
	.string "ability, their held item, and even\l"
	.string "certain moves they know.$"
