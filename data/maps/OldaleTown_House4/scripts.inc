OldaleTown_House4_MapScripts::
	.byte 0


OldaleTown_House4_EventScript_Snorlax::
	lock
	msgbox OldaleTown_House4_EventScript_Snorlax_Text_0
	goto_if_set FLAG_RECEIVED_LAX_INCENSE, OldaleTown_House4_EventScript_Snorlax_2
	msgbox OldaleTown_House4_EventScript_Snorlax_Text_1
	giveitem ITEM_LAX_INCENSE
	compare VAR_RESULT, FALSE
	goto_if_eq OldaleTown_House4_EventScript_Snorlax_4
	setflag FLAG_RECEIVED_LAX_INCENSE
	release
	return

OldaleTown_House4_EventScript_Snorlax_2:
	release
	end

OldaleTown_House4_EventScript_Snorlax_4:
	goto Common_EventScript_ShowBagIsFull
	return


OldaleTown_House4_EventScript_Snorlax_Text_0:
	.string "Snorlax: … … … Zzz … … …\p"
	.string "… … … laaax … … …\p"
	.string "… … … Zzz … … …$"

OldaleTown_House4_EventScript_Snorlax_Text_1:
	.string "Huh? The creature dropped something.$"
