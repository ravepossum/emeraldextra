Route135_MapScripts::
	.byte 0


Route135_EventScript_BlackBelt::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_EXPERT_BELT, Route135_EventScript_BlackBelt_2
	msgbox Route135_EventScript_BlackBelt_Text_1, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq Route135_EventScript_BlackBelt_4
	msgbox Route135_EventScript_BlackBelt_Text_3
	giveitem ITEM_EXPERT_BELT
	compare VAR_RESULT, FALSE
	goto_if_eq Route135_EventScript_BlackBelt_7
	msgbox Route135_EventScript_BlackBelt_Text_4
	setflag FLAG_RECEIVED_EXPERT_BELT
	release
	return

Route135_EventScript_BlackBelt_2:
	msgbox Route135_EventScript_BlackBelt_Text_0
	release
	end

Route135_EventScript_BlackBelt_4:
	msgbox Route135_EventScript_BlackBelt_Text_2
	release
	end

Route135_EventScript_BlackBelt_7:
	goto Common_EventScript_ShowBagIsFull
	return


Route135_EventScript_Boy::
	msgbox Route135_EventScript_Boy_Text_0, MSGBOX_NPC
	return


Route135_EventScript_BlackBelt_Text_0:
	.string "I'm working on creating a secret\n"
	.string "handshake for us.$"

Route135_EventScript_BlackBelt_Text_1:
	.string "Hey there stranger! Would you like to be\n"
	.string "friends?$"

Route135_EventScript_BlackBelt_Text_2:
	.string "Aw, that's too bad…$"

Route135_EventScript_BlackBelt_Text_3:
	.string "Splendid! How about you take this as a\n"
	.string "token of our new friendship?$"

Route135_EventScript_BlackBelt_Text_4:
	.string "Through the power of friendship, that\n"
	.string "EXPERT BELT will boost your POKéMON's\l"
	.string "super-effective moves.$"

Route135_EventScript_Boy_Text_0:
	.string "I wish I had a BIKE…\n"
	.string "I could go visit my friends in\l"
	.string "VERDANTURF.$"
