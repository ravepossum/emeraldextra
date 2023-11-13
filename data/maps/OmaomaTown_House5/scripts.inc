OmaomaTown_House5_MapScripts::
	.byte 0


OmaomaTown_House5_EventScript_Maniac::
	lock
	msgbox OmaomaTown_House5_EventScript_Maniac_Text_0
	release
	end


OmaomaTown_House5_EventScript_Gentleman::
	msgbox OmaomaTown_House5_EventScript_Gentleman_Text_0, MSGBOX_NPC
	return


OmaomaTown_House5_EventScript_Scientist2::
	msgbox OmaomaTown_House5_EventScript_Gentleman_Text_0, MSGBOX_NPC
	return


OmaomaTown_House5_EventScript_Maniac_Text_0:
	.string "… … …\p"
	.string "… … …\p"
	.string "The man is consumed by the book he's\n"
	.string "reading.$"

OmaomaTown_House5_EventScript_Gentleman_Text_0:
	.string "$"
