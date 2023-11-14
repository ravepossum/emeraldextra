.if DEBUG_OVERWORLD_MENU == TRUE
Debug_MessageEnd:
	waitmessage
	waitbuttonpress
	releaseall
	end

Debug_ShowFieldMessageStringVar4::
	special ShowFieldMessageStringVar4
	goto Debug_MessageEnd

Debug_CheatStart::
	setflag FLAG_SYS_POKEMON_GET
	setflag FLAG_RESCUED_BIRCH
	setflag FLAG_HIDE_ROUTE_101_BIRCH_ZIGZAGOON_BATTLE
	setflag FLAG_ADVENTURE_STARTED
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_BIRCH
	setflag FLAG_HIDE_ROUTE_101_BIRCH_STARTERS_BAG
	setvar VAR_BIRCH_LAB_STATE, 2
	setvar VAR_ROUTE101_STATE, 3
	givemon SPECIES_TREECKO, 20, ITEM_NONE
	givemon SPECIES_TORCHIC, 20, ITEM_NONE
	givemon SPECIES_MUDKIP, 20, ITEM_NONE
	setflag FLAG_SYS_POKEDEX_GET
	special SetUnlockedPokedexFlags
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
	setvar VAR_CABLE_CLUB_TUTORIAL_STATE, 2
	setflag FLAG_SYS_NATIONAL_DEX
	special EnableNationalPokedex
	setflag FLAG_RECEIVED_RUNNING_SHOES
	setflag FLAG_SYS_B_DASH
	setvar VAR_LITTLEROOT_TOWN_STATE, 4 @ 4: Received Running Shoes
	setvar VAR_LITTLEROOT_INTRO_STATE, 7 @ 7: Told to go meet rival
	setvar VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 2 @ 2: Met Rival's Mom (and is corresponding gender)
	setvar VAR_LITTLEROOT_HOUSES_STATE_MAY, 2 @ 2: Met Rival's Mom (and is corresponding gender)
	setvar VAR_LITTLEROOT_RIVAL_STATE, 4 @ 4: Received Pokedex
	setflag FLAG_RECEIVED_BIKE
	additem ITEM_ACRO_BIKE
	setvar VAR_BRINEY_HOUSE_STATE, 1
	setvar VAR_ROUTE116_STATE, 2
	setflag FLAG_HIDE_ROUTE_116_MR_BRINEY
	clearflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	clearflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	release
	end

Debug_FlagsNotSetOverworldConfigMessage::
	message Debug_FlagsNotSetOverworldConfigMessage_Text
	goto Debug_MessageEnd

Debug_FlagsNotSetOverworldConfigMessage_Text:
	.string "Feature unavailable!\n"
	.string "Please define a usable flag in:\l"
	.string "'include/config/overworld.h'!$"

Debug_FlagsNotSetBattleConfigMessage::
	message Debug_FlagsNotSetBattleConfigMessage_Text
	goto Debug_MessageEnd

Debug_FlagsNotSetBattleConfigMessage_Text:
	.string "Feature unavailable!\n"
	.string "Please define a usable flag in:\l"
	.string "'include/config/battle.h'!$"

Debug_BoxFilledMessage::
	message Debug_BoxFilledMessage_Text
	goto Debug_MessageEnd

Debug_BoxFilledMessage_Text:
	.string "Storage boxes filled!$"

Debug_Script_1::
	giveegg SPECIES_DREEPY
	end

Debug_Script_2::
	givemon SPECIES_BULBASAUR, 100
	givemon SPECIES_IVYSAUR, 100
	givemon SPECIES_VENUSAUR, 100
	givemon SPECIES_CHARMANDER, 100
	givemon SPECIES_CHARMELEON, 100
	givemon SPECIES_CHARIZARD, 100
	givemon SPECIES_SQUIRTLE, 100
	givemon SPECIES_WARTORTLE, 100
	givemon SPECIES_BLASTOISE, 100
	givemon SPECIES_CATERPIE, 100
	givemon SPECIES_METAPOD, 100
	givemon SPECIES_BUTTERFREE, 100
	givemon SPECIES_WEEDLE, 100
	givemon SPECIES_KAKUNA, 100
	givemon SPECIES_BEEDRILL, 100
	givemon SPECIES_PIDGEY, 100
	givemon SPECIES_PIDGEOTTO, 100
	givemon SPECIES_PIDGEOT, 100
	givemon SPECIES_RATTATA, 100
	givemon SPECIES_RATICATE, 100
	givemon SPECIES_SPEAROW, 100
	givemon SPECIES_FEAROW, 100
	givemon SPECIES_EKANS, 100
	givemon SPECIES_ARBOK, 100
	givemon SPECIES_PIKACHU, 100
	givemon SPECIES_RAICHU, 100
	givemon SPECIES_SANDSHREW, 100
	givemon SPECIES_SANDSLASH, 100
	givemon SPECIES_NIDORAN_F, 100
	givemon SPECIES_NIDORINA, 100
	givemon SPECIES_NIDOQUEEN, 100
	givemon SPECIES_NIDORAN_M, 100
	givemon SPECIES_NIDORINO, 100
	givemon SPECIES_NIDOKING, 100
	givemon SPECIES_CLEFAIRY, 100
	givemon SPECIES_CLEFABLE, 100
	givemon SPECIES_VULPIX, 100
	givemon SPECIES_NINETALES, 100
	givemon SPECIES_JIGGLYPUFF, 100
	givemon SPECIES_WIGGLYTUFF, 100
	givemon SPECIES_ZUBAT, 100
	givemon SPECIES_GOLBAT, 100
	givemon SPECIES_ODDISH, 100
	givemon SPECIES_GLOOM, 100
	givemon SPECIES_VILEPLUME, 100
	givemon SPECIES_PARAS, 100
	givemon SPECIES_PARASECT, 100
	givemon SPECIES_VENONAT, 100
	givemon SPECIES_VENOMOTH, 100
	givemon SPECIES_DIGLETT, 100
	givemon SPECIES_DUGTRIO, 100
	givemon SPECIES_MEOWTH, 100
	givemon SPECIES_PERSIAN, 100
	givemon SPECIES_PSYDUCK, 100
	givemon SPECIES_GOLDUCK, 100
	givemon SPECIES_MANKEY, 100
	givemon SPECIES_PRIMEAPE, 100
	givemon SPECIES_GROWLITHE, 100
	givemon SPECIES_ARCANINE, 100
	givemon SPECIES_POLIWAG, 100
	givemon SPECIES_POLIWHIRL, 100
	givemon SPECIES_POLIWRATH, 100
	givemon SPECIES_ABRA, 100
	givemon SPECIES_KADABRA, 100
	givemon SPECIES_ALAKAZAM, 100
	givemon SPECIES_MACHOP, 100
	givemon SPECIES_MACHOKE, 100
	givemon SPECIES_MACHAMP, 100
	givemon SPECIES_BELLSPROUT, 100
	givemon SPECIES_WEEPINBELL, 100
	givemon SPECIES_VICTREEBEL, 100
	end

Debug_Script_3::
	end

Debug_Script_4::
	end

Debug_Script_5::
	end

Debug_Script_6::
	end

Debug_Script_7::
	end

Debug_Script_8::
	end

Debug_CheckSaveBlock::
	callnative CheckSaveBlock1Size
	msgbox Debug_SaveBlock1Size, MSGBOX_DEFAULT
	callnative CheckSaveBlock2Size
	msgbox Debug_SaveBlock2Size, MSGBOX_DEFAULT
	callnative CheckPokemonStorageSize
	msgbox Debug_PokemonStorageSize, MSGBOX_DEFAULT
	release
	end

Debug_SaveBlock1Size::
	.string "SaveBlock1 size: {STR_VAR_1}/{STR_VAR_2}.$"

Debug_SaveBlock2Size::
	.string "SaveBlock2 size: {STR_VAR_1}/{STR_VAR_2}.$"

Debug_PokemonStorageSize::
	.string "{PKMN}Storage size: {STR_VAR_1}/{STR_VAR_2}.$"

Debug_HatchAnEgg::
	lockall
	getpartysize
	goto_if_eq VAR_RESULT, 0, Debug_HatchAnEgg_NoPokemon
	special ChoosePartyMon
	waitstate
	goto_if_ge VAR_0x8004, PARTY_SIZE, Debug_HatchAnEgg_End
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_ne VAR_RESULT, SPECIES_EGG, DebugScript_HatchAnEgg_CantForceHatch
	special EggHatch
	waitstate
Debug_HatchAnEgg_End::
	releaseall
	end

Debug_HatchAnEgg_NoPokemon::
	msgbox DebugScript_HatchAnEgg_Text_EmptyParty, MSGBOX_DEFAULT
	releaseall
	end

DebugScript_HatchAnEgg_CantForceHatch::
	msgbox DebugScript_HatchAnEgg_Text_NotAnEgg, MSGBOX_DEFAULT
	releaseall
	end

DebugScript_HatchAnEgg_Text_EmptyParty::
	.string "You have no Pokémon nor Eggs.$"

DebugScript_HatchAnEgg_Text_NotAnEgg::
	.string "That's not a Pokémon Egg.$"
	
DebugScript_ZeroDaycareMons::
	msgbox DebugText_DaycareNoPokemon, MSGBOX_DEFAULT
	releaseall
	end
	
DebugScript_OneDaycareMons::
	msgbox DebugText_DaycareOnePokemon, MSGBOX_DEFAULT
	releaseall
	end
	
DebugScript_DaycareMonsNotCompatible::
	msgbox DebugText_DaycarePokemonNotCompatible, MSGBOX_DEFAULT
	releaseall
	end
	
DebugText_DaycareNoPokemon:
	.string "You have no Pokémon at Daycare.$"
	
DebugText_DaycareOnePokemon:
	.string "You have only one Pokémon at Daycare.$"
	
DebugText_DaycarePokemonNotCompatible:
	.string "Your Pokémon at Daycare can't\nhave babies together!$"

.endif
