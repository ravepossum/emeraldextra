OmaomaTown_House1_MapScripts::
	.byte 0


OmaomaTown_House1_EventScript_Maniac::
	lock
	faceplayer
	goto_if_set FLAG_BOUGHT_SOUVENIR, OmaomaTown_House1_EventScript_Maniac_2
	msgbox OmaomaTown_House1_EventScript_Maniac_Text_1, MSGBOX_YESNO
OmaomaTown_House1_EventScript_Maniac_1:
	compare VAR_RESULT, YES
	goto_if_eq OmaomaTown_House1_EventScript_Maniac_6
	msgbox OmaomaTown_House1_EventScript_Maniac_Text_4
OmaomaTown_House1_EventScript_Maniac_5:
	release
	end

OmaomaTown_House1_EventScript_Maniac_2:
	msgbox OmaomaTown_House1_EventScript_Maniac_Text_0, MSGBOX_YESNO
	goto OmaomaTown_House1_EventScript_Maniac_1

OmaomaTown_House1_EventScript_Maniac_6:
	checkmoney 3000
	compare VAR_RESULT, FALSE
	goto_if_eq OmaomaTown_House1_EventScript_Maniac_9
	giveitem ITEM_STRANGE_SOUVENIR
	compare VAR_RESULT, FALSE
	goto_if_eq OmaomaTown_House1_EventScript_Maniac_12
	removemoney 3000
	setflag FLAG_BOUGHT_SOUVENIR
	msgbox OmaomaTown_House1_EventScript_Maniac_Text_3
	goto OmaomaTown_House1_EventScript_Maniac_5

OmaomaTown_House1_EventScript_Maniac_9:
	msgbox OmaomaTown_House1_EventScript_Maniac_Text_2
	goto OmaomaTown_House1_EventScript_Maniac_5

OmaomaTown_House1_EventScript_Maniac_12:
	goto Common_EventScript_ShowBagIsFull
	goto OmaomaTown_House1_EventScript_Maniac_5


OmaomaTown_House1_EventScript_Maniac_Text_0:
	.string "I got another great deal for you!\p"
	.string "I found another Alolan souvenir, and\n"
	.string "just for you, it's only ¥3,000!\p"
	.string "What do you say?$"

OmaomaTown_House1_EventScript_Maniac_Text_1:
	.string "Hey, kid, you wanna buy a rare souvenir?\p"
	.string "It's from the land of Alola--far far\n"
	.string "away from here!\p"
	.string "And today only, I'll give it to you for\n"
	.string "the low, low, price of ¥3,000!\p"
	.string "What do you say?$"

OmaomaTown_House1_EventScript_Maniac_Text_2:
	.string "You trying to mess with me or something,\n"
	.string "kid?\p"
	.string "Come back when you're a little richer.$"

OmaomaTown_House1_EventScript_Maniac_Text_3:
	.string "Pleasure doing business with ya, kid.$"

OmaomaTown_House1_EventScript_Maniac_Text_4:
	.string "That's a shame.\p"
	.string "Come back when you're ready to make a\n"
	.string "great investment.$"
