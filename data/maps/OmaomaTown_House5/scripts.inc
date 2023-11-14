OmaomaTown_House5_MapScripts::
	.byte 0


OmaomaTown_House5_EventScript_Maniac::
	lock
	msgbox OmaomaTown_House5_EventScript_Maniac_Text_0
	release
	end


OmaomaTown_House5_EventScript_Gentleman::
	lock
	faceplayer
	goto_if_unset FLAG_MET_OMAOMA_POKEDEX_GUY, OmaomaTown_House5_EventScript_Gentleman_2
OmaomaTown_House5_EventScript_Gentleman_1:
	goto_if_unset FLAG_RECEIVED_WISE_GLASSES, OmaomaTown_House5_EventScript_Gentleman_5
	msgbox OmaomaTown_House5_EventScript_Gentleman_Text_3
OmaomaTown_House5_EventScript_Gentleman_4:
	release
	end

OmaomaTown_House5_EventScript_Gentleman_2:
	msgbox OmaomaTown_House5_EventScript_Gentleman_Text_0
	setflag FLAG_MET_OMAOMA_POKEDEX_GUY
	goto OmaomaTown_House5_EventScript_Gentleman_1

OmaomaTown_House5_EventScript_Gentleman_5:
	setvar VAR_0x8004, 1
	specialvar VAR_RESULT, ScriptGetPokedexInfo
	copyvar VAR_0x8009, VAR_0x8006
	compare VAR_0x8009, 50
	goto_if_ge OmaomaTown_House5_EventScript_Gentleman_8
	msgbox OmaomaTown_House5_EventScript_Gentleman_Text_2
	goto OmaomaTown_House5_EventScript_Gentleman_4

OmaomaTown_House5_EventScript_Gentleman_8:
	msgbox OmaomaTown_House5_EventScript_Gentleman_Text_1
	giveitem ITEM_WISE_GLASSES
	setflag FLAG_RECEIVED_WISE_GLASSES
	goto OmaomaTown_House5_EventScript_Gentleman_4


OmaomaTown_House5_EventScript_Scientist2::
	lock
	faceplayer
	goto_if_unset FLAG_RECEIVED_PLUME_FOSSIL, OmaomaTown_House5_EventScript_Scientist2_2
	msgbox OmaomaTown_House5_EventScript_Scientist2_Text_4
OmaomaTown_House5_EventScript_Scientist2_1:
	release
	end

OmaomaTown_House5_EventScript_Scientist2_2:
	msgbox OmaomaTown_House5_EventScript_Scientist2_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq OmaomaTown_House5_EventScript_Scientist2_5
	msgbox OmaomaTown_House5_EventScript_Scientist2_Text_2
	giveitem ITEM_PLUME_FOSSIL
	msgbox OmaomaTown_House5_EventScript_Scientist2_Text_3
	setflag FLAG_RECEIVED_PLUME_FOSSIL
	goto OmaomaTown_House5_EventScript_Scientist2_1

OmaomaTown_House5_EventScript_Scientist2_5:
	msgbox OmaomaTown_House5_EventScript_Scientist2_Text_1
	goto OmaomaTown_House5_EventScript_Scientist2_1


OmaomaTown_House5_EventScript_Maniac_Text_0:
	.string "… … …\p"
	.string "… … …\p"
	.string "The man is consumed by the book he's\n"
	.string "reading.$"

OmaomaTown_House5_EventScript_Gentleman_Text_0:
	.string "Oh ho! I spy a Pokédex!\p"
	.string "I happen to be somewhat of a Pokémon\n"
	.string "connoisseur myself.$"

OmaomaTown_House5_EventScript_Gentleman_Text_1:
	.string "My, that is a marvelous looking Pokédex!\p"
	.string "I appreciate you letting me see it.\p"
	.string "Please accept this as thanks!$"

OmaomaTown_House5_EventScript_Gentleman_Text_2:
	.string "If you come back and show me you've\n"
	.string "caught 50 unique species of Pokémon,\l"
	.string "I'll give you a prize.$"

OmaomaTown_House5_EventScript_Gentleman_Text_3:
	.string "I simply cannot get enough Pokémon!\p"
	.string "I've read every book in this\n"
	.string "establishment.$"

OmaomaTown_House5_EventScript_Scientist2_Text_0:
	.string "I found a fossil in the jungle out here…\p"
	.string "but I'm too busy with my research to\n"
	.string "bring it to the Devon Corporation lab.\p"
	.string "Do you think you could bring it there\n"
	.string "for me?$"

OmaomaTown_House5_EventScript_Scientist2_Text_1:
	.string "Okay, maybe later then.$"

OmaomaTown_House5_EventScript_Scientist2_Text_2:
	.string "Splendid! Now please take this.$"

OmaomaTown_House5_EventScript_Scientist2_Text_3:
	.string "My colleague at the Devon Corporation\n"
	.string "building in Rustboro should be able to\l"
	.string "take a closer look at that.$"

OmaomaTown_House5_EventScript_Scientist2_Text_4:
	.string "I'm hoping to unearth new species of\n"
	.string "Pokémon never before seen in Hoenn.$"
