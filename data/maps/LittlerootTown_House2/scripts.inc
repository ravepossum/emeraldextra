LittlerootTown_House2_MapScripts::
	.byte 0


LittlerootTown_House2_EventScript_Woman::
	msgbox LittlerootTown_House2_EventScript_Woman_Text_0, MSGBOX_NPC
	return


LittlerootTown_House2_EventScript_Man::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_BIG_ROOT, LittlerootTown_House2_EventScript_Man_2
	msgbox LittlerootTown_House2_EventScript_Man_Text_1
	giveitem ITEM_BIG_ROOT
	compare VAR_RESULT, FALSE
	goto_if_eq LittlerootTown_House2_EventScript_Man_4
	setflag FLAG_RECEIVED_BIG_ROOT
	release
	return

LittlerootTown_House2_EventScript_Man_2:
	msgbox LittlerootTown_House2_EventScript_Man_Text_0
	release
	end

LittlerootTown_House2_EventScript_Man_4:
	goto Common_EventScript_ShowBagIsFull
	return


LittlerootTown_House2_EventScript_LittleGirl::
	msgbox LittlerootTown_House2_EventScript_LittleGirl_Text_0, MSGBOX_NPC
	return


LittlerootTown_House2_EventScript_Woman_Text_0:
	.string "Make yourself at home. It's always nice\n"
	.string "to have guests.$"

LittlerootTown_House2_EventScript_Man_Text_0:
	.string "Seeing my flowers prosper makes me\n"
	.string "smile.$"

LittlerootTown_House2_EventScript_Man_Text_1:
	.string "I maintain the garden outside.\n"
	.string "Littleroot has lush soil.\p"
	.string "Here, take this Big Root. It'll help your\n"
	.string "Grass-type Pokémon stay in tip-top\l"
	.string "shape.$"

LittlerootTown_House2_EventScript_LittleGirl_Text_0:
	.string "I need to train more so I can defeat my\n"
	.string "big brother.$"
