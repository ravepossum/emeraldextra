Common_EventScript_PkmnCenterUnionNurse::
	lock
	faceplayer
	message Common_EventScript_PkmnCenterUnionNurse_Text_0
	waitmessage
	call EventScript_PkmnCenterUnionNurse_Multichoice
	release
	end


EventScript_PkmnCenterUnionNurse_Multichoice::
	dynmultichoice 0, 0, FALSE, 4, 0, DYN_MULTICHOICE_CB_NONE, EventScript_PkmnCenterUnionNurse_Multichoice_Text_0, EventScript_PkmnCenterUnionNurse_Multichoice_Text_1, EventScript_PkmnCenterUnionNurse_Multichoice_Text_2, EventScript_PkmnCenterUnionNurse_Multichoice_Text_3
	switch VAR_RESULT
	case 0, EventScript_PkmnCenterUnionNurse_Multichoice_2
	case 1, EventScript_PkmnCenterUnionNurse_Multichoice_3
	case 2, EventScript_PkmnCenterUnionNurse_Multichoice_4
	return

EventScript_PkmnCenterUnionNurse_Multichoice_2:
	call EventScript_PkmnCenterUnionNurse_MoveRelearn
	message PkmnCenterUnionNurse_AnythingElse
	waitmessage
	call EventScript_PkmnCenterUnionNurse_Multichoice
	return

EventScript_PkmnCenterUnionNurse_Multichoice_3:
	call EventScript_PkmnCenterUnionNurse_ChangeNickname
	message PkmnCenterUnionNurse_AnythingElse
	waitmessage
	call EventScript_PkmnCenterUnionNurse_Multichoice
	return

EventScript_PkmnCenterUnionNurse_Multichoice_4:
	call EventScript_PkmnCenterUnionNurse_ChangeTime
	message PkmnCenterUnionNurse_AnythingElse
	waitmessage
	call EventScript_PkmnCenterUnionNurse_Multichoice
	return


EventScript_PkmnCenterUnionNurse_MoveRelearn::
	special ChooseMonForMoveRelearner
	waitstate
	compare VAR_0x8004, PARTY_NOTHING_CHOSEN
	goto_if_eq EventScript_PkmnCenterUnionNurse_MoveRelearn_2
	special IsSelectedMonEgg
	compare VAR_RESULT, TRUE
	goto_if_eq EventScript_PkmnCenterUnionNurse_MoveRelearn_4
	compare VAR_0x8005, 0
	goto_if_eq EventScript_PkmnCenterUnionNurse_MoveRelearn_5
	special TeachMoveRelearnerMove
	waitstate
	compare VAR_0x8004, 0
	goto_if_eq EventScript_PkmnCenterUnionNurse_MoveRelearn_9
	msgbox EventScript_PkmnCenterUnionNurse_MoveRelearn_Text_2
	return

EventScript_PkmnCenterUnionNurse_MoveRelearn_2:
	return

EventScript_PkmnCenterUnionNurse_MoveRelearn_4:
	msgbox EventScript_PkmnCenterUnionNurse_MoveRelearn_Text_0
	call EventScript_PkmnCenterUnionNurse_MoveRelearn
	return

EventScript_PkmnCenterUnionNurse_MoveRelearn_5:
	msgbox EventScript_PkmnCenterUnionNurse_MoveRelearn_Text_1
	call EventScript_PkmnCenterUnionNurse_MoveRelearn
	return

EventScript_PkmnCenterUnionNurse_MoveRelearn_9:
	call EventScript_PkmnCenterUnionNurse_MoveRelearn
	return


EventScript_PkmnCenterUnionNurse_ChangeNickname::
	special ChoosePartyMon
	waitstate
	compare VAR_0x8004, PARTY_NOTHING_CHOSEN
	goto_if_eq EventScript_PkmnCenterUnionNurse_ChangeNickname_2
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_EGG
	goto_if_eq EventScript_PkmnCenterUnionNurse_ChangeNickname_4
	call Common_EventScript_NameReceivedPartyMon
	specialvar VAR_RESULT, TryPutNameRaterShowOnTheAir
	special BufferMonNickname
	compare VAR_RESULT, TRUE
	goto_if_eq EventScript_PkmnCenterUnionNurse_ChangeNickname_8
	msgbox EventScript_PkmnCenterUnionNurse_ChangeNickname_Text_2
EventScript_PkmnCenterUnionNurse_ChangeNickname_7:
	return

EventScript_PkmnCenterUnionNurse_ChangeNickname_2:
	return

EventScript_PkmnCenterUnionNurse_ChangeNickname_4:
	msgbox EventScript_PkmnCenterUnionNurse_ChangeNickname_Text_0
	call EventScript_PkmnCenterUnionNurse_ChangeNickname
	return

EventScript_PkmnCenterUnionNurse_ChangeNickname_8:
	msgbox EventScript_PkmnCenterUnionNurse_ChangeNickname_Text_1
	goto EventScript_PkmnCenterUnionNurse_ChangeNickname_7


EventScript_PkmnCenterUnionNurse_ChangeTime::
	message EventScript_PkmnCenterUnionNurse_ChangeTime_Text_0
	waitmessage
	dynmultipush EventScript_PkmnCenterUnionNurse_ChangeTime_Text_1, TIME_MORNING
	dynmultipush EventScript_PkmnCenterUnionNurse_ChangeTime_Text_2, TIME_DAY
	dynmultipush EventScript_PkmnCenterUnionNurse_ChangeTime_Text_3, TIME_EVENING
	dynmultipush EventScript_PkmnCenterUnionNurse_ChangeTime_Text_4, TIME_NIGHT
	dynmultipush EventScript_PkmnCenterUnionNurse_Multichoice_Text_3, 127
	dynmultistack 0, 0, FALSE, 4, FALSE, 0xFF, DYN_MULTICHOICE_CB_NONE
	compare VAR_RESULT, 127
	goto_if_eq EventScript_PkmnCenterUnionNurse_ChangeTime_2
	closemessage
	settimeofday VAR_RESULT
	call Common_EventScript_UnionNurseRest
	msgbox EventScript_PkmnCenterUnionNurse_ChangeTime_Text_5, MSGBOX_DEFAULT
	release
	end

EventScript_PkmnCenterUnionNurse_ChangeTime_2:
	return


Common_EventScript_PkmnCenterUnionNurse_Text_0:
	.string "Hi, I'm the Pokéhelper! How may I help\n"
	.string "you today?$"

EventScript_PkmnCenterUnionNurse_Multichoice_Text_0:
	.string "Relearn move$"

EventScript_PkmnCenterUnionNurse_Multichoice_Text_1:
	.string "Change nickname$"

EventScript_PkmnCenterUnionNurse_Multichoice_Text_2:
	.string "Rest until later$"

EventScript_PkmnCenterUnionNurse_Multichoice_Text_3:
	.string "Cancel$"

EventScript_PkmnCenterUnionNurse_MoveRelearn_Text_0:
	.string "There are no moves available to teach\n"
	.string "to an Egg.$"

EventScript_PkmnCenterUnionNurse_MoveRelearn_Text_1:
	.string "Unfortunately, there are no moves\n"
	.string "available for that Pokémon.$"

EventScript_PkmnCenterUnionNurse_MoveRelearn_Text_2:
	.string "Thank you for using the Move Relearner!$"

EventScript_PkmnCenterUnionNurse_ChangeNickname_Text_0:
	.string "You cannot nickname an Egg.$"

EventScript_PkmnCenterUnionNurse_ChangeNickname_Text_1:
	.string "From now on, this Pokémon will be known\n"
	.string "as {STR_VAR_1}.$"

EventScript_PkmnCenterUnionNurse_ChangeNickname_Text_2:
	.string "The Pokémon's name will remain\n"
	.string "unchanged.$"

EventScript_PkmnCenterUnionNurse_ChangeTime_Text_0:
	.string "You can stay at the Pokémon Center as\n"
	.string "long as you'd like.\p"
	.string "When would you like to rest until?$"

EventScript_PkmnCenterUnionNurse_ChangeTime_Text_1:
	.string "Morning$"

EventScript_PkmnCenterUnionNurse_ChangeTime_Text_2:
	.string "Day$"

EventScript_PkmnCenterUnionNurse_ChangeTime_Text_3:
	.string "Evening$"

EventScript_PkmnCenterUnionNurse_ChangeTime_Text_4:
	.string "Night$"

EventScript_PkmnCenterUnionNurse_ChangeTime_Text_5:
	.string "You and your Pokémon are well rested.$"

PkmnCenterUnionNurse_AnythingElse::
	.string "Is there anything else I can help you\n"
	.string "with today?$"
