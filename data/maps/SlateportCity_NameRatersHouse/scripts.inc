SlateportCity_NameRatersHouse_MapScripts::
	.byte 0

SlateportCity_NameRatersHouse_EventScript_NameRater::
	lock
	faceplayer
	msgbox SlateportCity_NameRatersHouse_Text_PleasedToRateMonNickname, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_NameRatersHouse_EventScript_ChooseMonToRate
	goto_if_eq VAR_RESULT, NO, SlateportCity_NameRatersHouse_EventScript_DeclineNameRate
	end

SlateportCity_NameRatersHouse_EventScript_ChooseMonToRate::
	msgbox SlateportCity_NameRatersHouse_Text_CritiqueWhichMonNickname, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	goto_if_ne VAR_0x8004, PARTY_NOTHING_CHOSEN, SlateportCity_NameRatersHouse_EventScript_RateMonNickname
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, SlateportCity_NameRatersHouse_EventScript_DeclineNameRate
	end

SlateportCity_NameRatersHouse_EventScript_DeclineNameRate::
	msgbox SlateportCity_NameRatersHouse_Text_DoVisitAgain, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_RateMonNickname::
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, SlateportCity_NameRatersHouse_EventScript_CantRateEgg
	special BufferMonNickname
	special IsMonOTIDNotPlayers
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_NameRatersHouse_EventScript_PlayerNotMonsOT
	specialvar VAR_RESULT, MonOTNameNotPlayer
	special BufferMonNickname
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_NameRatersHouse_EventScript_PlayerNotMonsOT
	msgbox SlateportCity_NameRatersHouse_Text_FineNameSuggestBetterOne, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_NameRatersHouse_EventScript_ChangeNickname
	goto_if_eq VAR_RESULT, NO, SlateportCity_NameRatersHouse_EventScript_DeclineNameRate
	end

SlateportCity_NameRatersHouse_EventScript_CantRateEgg::
	msgbox SlateportCity_NameRatersHouse_Text_ThatIsMerelyAnEgg, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_PlayerNotMonsOT::
	msgbox SlateportCity_NameRatersHouse_Text_MagnificentName, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_ChangeNickname::
	msgbox SlateportCity_NameRatersHouse_Text_WhatShallNewNameBe, MSGBOX_DEFAULT
	call Common_EventScript_NameReceivedPartyMon
	specialvar VAR_RESULT, TryPutNameRaterShowOnTheAir
	special BufferMonNickname
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_NameRatersHouse_EventScript_NewNameDifferent
	msgbox SlateportCity_NameRatersHouse_Text_NameNoDifferentYetSuperior, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_NewNameDifferent::
	msgbox SlateportCity_NameRatersHouse_Text_MonShallBeKnownAsName, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_Text_PleasedToRateMonNickname:
	.string "Hi, hi! I'm the Name Rater!\n"
	.string "I'm the fortune-teller of names!\p"
	.string "I shall be pleased to rate your\n"
	.string "Pokémon's nickname.$"

SlateportCity_NameRatersHouse_Text_CritiqueWhichMonNickname:
	.string "Which Pokémon's nickname should\n"
	.string "I critique?$"

SlateportCity_NameRatersHouse_Text_FineNameSuggestBetterOne:
	.string "Hmmm… {STR_VAR_1}, is it? That is\n"
	.string "quite a fine name you bestowed.\p"
	.string "But! What say you, if I were to\n"
	.string "suggest a slightly better name?$"

SlateportCity_NameRatersHouse_Text_WhatShallNewNameBe:
	.string "Ah, good. Then, what shall the new\n"
	.string "nickname be?$"

SlateportCity_NameRatersHouse_Text_MonShallBeKnownAsName:
	.string "Done! From now on, this Pokémon\n"
	.string "shall be known as {STR_VAR_1}!\p"
	.string "It is a better name than before!\n"
	.string "How fortunate for you!$"

SlateportCity_NameRatersHouse_Text_DoVisitAgain:
	.string "I see.\n"
	.string "Do come visit again.$"

SlateportCity_NameRatersHouse_Text_NameNoDifferentYetSuperior:
	.string "Done! From now on, this Pokémon\n"
	.string "shall be known as {STR_VAR_1}!\p"
	.string "It looks no different from before,\n"
	.string "and yet, this is vastly superior!\p"
	.string "How fortunate for you!$"

SlateportCity_NameRatersHouse_Text_MagnificentName:
	.string "Hmmm… {STR_VAR_1} it is!\p"
	.string "This is a magnificent nickname!\n"
	.string "It is impeccably beyond reproach!\p"
	.string "You'll do well to cherish your\n"
	.string "{STR_VAR_1} now and beyond.$"

SlateportCity_NameRatersHouse_Text_ThatIsMerelyAnEgg:
	.string "Now, now.\n"
	.string "That is merely an Egg!$"

SlateportCity_NameRatersHouse_EventScript_AbilityMaster::
	lock
	faceplayer
	msgbox SlateportCity_NameRatersHouse_EventScript_AbilityMaster_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq SlateportCity_NameRatersHouse_EventScript_AbilityMaster_2
SlateportCity_NameRatersHouse_EventScript_AbilityMaster_1:
	msgbox SlateportCity_NameRatersHouse_EventScript_AbilityMaster_Text_1
	special ChoosePartyMon
	waitstate
	compare VAR_0x8004, PARTY_NOTHING_CHOSEN
	goto_if_eq SlateportCity_NameRatersHouse_EventScript_AbilityMaster_5
SlateportCity_NameRatersHouse_EventScript_AbilityMaster_4:
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_EGG
	goto_if_eq SlateportCity_NameRatersHouse_EventScript_AbilityMaster_8
	special BufferMonNickname
	special BufferMonAbilities
	compare VAR_RESULT, FALSE
	goto_if_eq SlateportCity_NameRatersHouse_EventScript_AbilityMaster_11
	msgbox SlateportCity_NameRatersHouse_EventScript_AbilityMaster_Text_4
	compare VAR_0x8006, ABILITY_NONE
	goto_if_ne SlateportCity_NameRatersHouse_EventScript_AbilityMaster_14
SlateportCity_NameRatersHouse_EventScript_AbilityMaster_13:
	compare VAR_0x8007, ABILITY_NONE
	goto_if_ne SlateportCity_NameRatersHouse_EventScript_AbilityMaster_17
SlateportCity_NameRatersHouse_EventScript_AbilityMaster_16:
	compare VAR_0x8008, ABILITY_NONE
	goto_if_ne SlateportCity_NameRatersHouse_EventScript_AbilityMaster_20
SlateportCity_NameRatersHouse_EventScript_AbilityMaster_19:
	dynmultipush SlateportCity_NameRatersHouse_EventScript_AbilityMaster_Text_6, ABILITY_NONE
	dynmultistack 0, 0, TRUE, 4, FALSE, 0xFF, DYN_MULTICHOICE_CB_NONE
	compare VAR_RESULT, ABILITY_NONE
	goto_if_eq SlateportCity_NameRatersHouse_EventScript_AbilityMaster_23
SlateportCity_NameRatersHouse_EventScript_AbilityMaster_22:
	switch VAR_RESULT
	case VAR_0x8006, SlateportCity_NameRatersHouse_EventScript_AbilityMaster_27
	case VAR_0x8007, SlateportCity_NameRatersHouse_EventScript_AbilityMaster_28
	case VAR_0x8008, SlateportCity_NameRatersHouse_EventScript_AbilityMaster_29
SlateportCity_NameRatersHouse_EventScript_AbilityMaster_25:
	bufferabilityname STR_VAR_2, VAR_RESULT
	msgbox SlateportCity_NameRatersHouse_EventScript_AbilityMaster_Text_7, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq SlateportCity_NameRatersHouse_EventScript_AbilityMaster_31
SlateportCity_NameRatersHouse_EventScript_AbilityMaster_30:
	msgbox SlateportCity_NameRatersHouse_EventScript_AbilityMaster_Text_8
	special ChangeMonAbility
	fadescreen FADE_TO_BLACK
	delay 10
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	closemessage
	fadescreen FADE_FROM_BLACK
	msgbox SlateportCity_NameRatersHouse_EventScript_AbilityMaster_Text_9
	release
	end

SlateportCity_NameRatersHouse_EventScript_AbilityMaster_2:
	goto SlateportCity_NameRatersHouse_EventScript_AbilityMasterNo
	goto SlateportCity_NameRatersHouse_EventScript_AbilityMaster_1

SlateportCity_NameRatersHouse_EventScript_AbilityMaster_5:
	goto SlateportCity_NameRatersHouse_EventScript_AbilityMasterNo
	goto SlateportCity_NameRatersHouse_EventScript_AbilityMaster_4

SlateportCity_NameRatersHouse_EventScript_AbilityMaster_8:
	msgbox SlateportCity_NameRatersHouse_EventScript_AbilityMaster_Text_2
	release
	end

SlateportCity_NameRatersHouse_EventScript_AbilityMaster_11:
	msgbox SlateportCity_NameRatersHouse_EventScript_AbilityMaster_Text_3
	release
	end

SlateportCity_NameRatersHouse_EventScript_AbilityMaster_14:
	bufferabilityname STR_VAR_2, VAR_0x8006
	dynmultipush SlateportCity_NameRatersHouse_EventScript_AbilityMaster_Text_5, VAR_0x8006
	goto SlateportCity_NameRatersHouse_EventScript_AbilityMaster_13

SlateportCity_NameRatersHouse_EventScript_AbilityMaster_17:
	bufferabilityname STR_VAR_2, VAR_0x8007
	dynmultipush SlateportCity_NameRatersHouse_EventScript_AbilityMaster_Text_5, VAR_0x8007
	goto SlateportCity_NameRatersHouse_EventScript_AbilityMaster_16

SlateportCity_NameRatersHouse_EventScript_AbilityMaster_20:
	bufferabilityname STR_VAR_2, VAR_0x8008
	dynmultipush SlateportCity_NameRatersHouse_EventScript_AbilityMaster_Text_5, VAR_0x8008
	goto SlateportCity_NameRatersHouse_EventScript_AbilityMaster_19

SlateportCity_NameRatersHouse_EventScript_AbilityMaster_23:
	goto SlateportCity_NameRatersHouse_EventScript_AbilityMasterNo
	goto SlateportCity_NameRatersHouse_EventScript_AbilityMaster_22

SlateportCity_NameRatersHouse_EventScript_AbilityMaster_27:
	setvar VAR_0x8009, 0
	goto SlateportCity_NameRatersHouse_EventScript_AbilityMaster_25

SlateportCity_NameRatersHouse_EventScript_AbilityMaster_28:
	setvar VAR_0x8009, 1
	goto SlateportCity_NameRatersHouse_EventScript_AbilityMaster_25

SlateportCity_NameRatersHouse_EventScript_AbilityMaster_29:
	setvar VAR_0x8009, 2
	goto SlateportCity_NameRatersHouse_EventScript_AbilityMaster_25

SlateportCity_NameRatersHouse_EventScript_AbilityMaster_31:
	goto SlateportCity_NameRatersHouse_EventScript_AbilityMasterNo
	goto SlateportCity_NameRatersHouse_EventScript_AbilityMaster_30


SlateportCity_NameRatersHouse_EventScript_AbilityMasterNo::
	msgbox SlateportCity_NameRatersHouse_EventScript_AbilityMasterNo_Text_0
	release
	end


SlateportCity_NameRatersHouse_EventScript_AbilityMaster_Text_0:
	.string "Hello, child. I am known as the Ability\n"
	.string "Master.\p"
	.string "I can train with one of your Pokémon to\n"
	.string "grant them an entirely new Ability.\p"
	.string "Would you like one of your Pokémon to\n"
	.string "change their Ability?$"

SlateportCity_NameRatersHouse_EventScript_AbilityMaster_Text_1:
	.string "Which Pokémon should I train?$"

SlateportCity_NameRatersHouse_EventScript_AbilityMaster_Text_2:
	.string "How foolish! An Egg cannot train!$"

SlateportCity_NameRatersHouse_EventScript_AbilityMaster_Text_3:
	.string "{STR_VAR_1} cannot learn any other\n"
	.string "abilities.$"

SlateportCity_NameRatersHouse_EventScript_AbilityMaster_Text_4:
	.string "Which Ability should {STR_VAR_1}\n"
	.string "learn?$"

SlateportCity_NameRatersHouse_EventScript_AbilityMaster_Text_5:
	.string "{STR_VAR_2}$"

SlateportCity_NameRatersHouse_EventScript_AbilityMaster_Text_6:
	.string "Cancel$"

SlateportCity_NameRatersHouse_EventScript_AbilityMaster_Text_7:
	.string "So {STR_VAR_1} should learn the\n"
	.string "{STR_VAR_2} Ability?$"

SlateportCity_NameRatersHouse_EventScript_AbilityMaster_Text_8:
	.string "Excellent. We shall begin at once!$"

SlateportCity_NameRatersHouse_EventScript_AbilityMaster_Text_9:
	.string "{STR_VAR_1}'s training is complete.\p"
	.string "Come back if you need to train another\n"
	.string "Pokémon.$"

SlateportCity_NameRatersHouse_EventScript_AbilityMasterNo_Text_0:
	.string "I see. Come back when one of your\n"
	.string "Pokémon needs to learn a new Ability.$"
