LittlerootTown_Mart_MapScripts::
	.byte 0

LittlerootTown_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart LittlerootTown_Mart_Pokemart_Basic
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LittlerootTown_Mart_Pokemart_Basic:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_REPEL
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFENSE
	.2byte ITEM_ORANGE_MAIL
	.2byte ITEM_NONE
	release
	end

LittlerootTown_Mart_EventScript_BugCatcher::
	msgbox LittlerootTown_Mart_EventScript_BugCatcher_Text_0, MSGBOX_NPC
	return


LittlerootTown_Mart_EventScript_BugCatcher_Text_0:
	.string "Have you heard about Pokévials?\p"
	.string "They can hold enough medicine to heal\n"
	.string "all of your Pokémon.$"
