OmaomaTown_House4_MapScripts::
	.byte 0


OmaomaTown_House4_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_OMAOMA_NPC_TRADE_COMPLETED, OmaomaTown_House4_EventScript_Trader_2
	setvar VAR_0x8008, INGAME_TRADE_MIMIKYU
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox OmaomaTown_House4_EventScript_Trader_Text_1, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq OmaomaTown_House4_EventScript_Trader_5
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	compare VAR_0x8004, PARTY_NOTHING_CHOSEN
	goto_if_eq OmaomaTown_House4_EventScript_Trader_8
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	compare VAR_RESULT, VAR_0x8009
	goto_if_ne OmaomaTown_House4_EventScript_Trader_11
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	msgbox OmaomaTown_House4_EventScript_Trader_Text_5
	setflag FLAG_OMAOMA_NPC_TRADE_COMPLETED
	release
	end

OmaomaTown_House4_EventScript_Trader_2:
	msgbox OmaomaTown_House4_EventScript_Trader_Text_0
	release
	end

OmaomaTown_House4_EventScript_Trader_5:
	msgbox OmaomaTown_House4_EventScript_Trader_Text_2
	release
	end

OmaomaTown_House4_EventScript_Trader_8:
	msgbox OmaomaTown_House4_EventScript_Trader_Text_3
	release
	end

OmaomaTown_House4_EventScript_Trader_11:
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox OmaomaTown_House4_EventScript_Trader_Text_4
	release
	end


OmaomaTown_House4_EventScript_Trader_Text_0:
	.string "Thanks again.\p"
	.string "I hope you're less creeped out by that\n"
	.string "Pikachu than I was.$"

OmaomaTown_House4_EventScript_Trader_Text_1:
	.string "I got this really weird Pikachu…\p"
	.string "It makes me uncomfortable.\p"
	.string "I'd really like an {STR_VAR_1}\n"
	.string "instead.\p"
	.string "Would you like to trade your\n"
	.string "{STR_VAR_1} for my…Pikachu…?$"

OmaomaTown_House4_EventScript_Trader_Text_2:
	.string "Aw man…$"

OmaomaTown_House4_EventScript_Trader_Text_3:
	.string "You don't really want to trade? Aw man…$"

OmaomaTown_House4_EventScript_Trader_Text_4:
	.string "Huh? That's not an {STR_VAR_1}…$"

OmaomaTown_House4_EventScript_Trader_Text_5:
	.string "Awesome! I'll finally be able to get some\n"
	.string "sleep without feeling like I'm being\l"
	.string "watched.$"
