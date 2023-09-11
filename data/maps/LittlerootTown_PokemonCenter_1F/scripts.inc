.set LOCALID_NURSE, 1

LittlerootTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

LittlerootTown_PokemonCenter_1F_OnTransition:
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, LittlerootTown_PokemonCenter_1F_MaleHeal
	goto_if_eq VAR_RESULT, FEMALE, LittlerootTown_PokemonCenter_1F_FemaleHeal
	end

LittlerootTown_PokemonCenter_1F_MaleHeal:
    setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_BRENDANS_HOUSE
    end

LittlerootTown_PokemonCenter_1F_FemaleHeal:
    setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_MAYS_HOUSE
    end

LittlerootTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

LittlerootTown_PokemonCenter_1F_EventScript_Girl::
	msgbox LittlerootTown_PokemonCenter_1F_Text_SkittyContest, MSGBOX_NPC
	end

LittlerootTown_PokemonCenter_1F_EventScript_Skitty::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SKITTY, CRY_MODE_NORMAL
	msgbox LittlerootTown_PokemonCenter_1F_Text_Skitty, MSGBOX_DEFAULT
	waitmoncry
	release
	end

LittlerootTown_PokemonCenter_1F_EventScript_Youngster::
	msgbox LittlerootTown_PokemonCenter_1F_Text_Youngster, MSGBOX_NPC
	end

LittlerootTown_PokemonCenter_1F_Text_SkittyContest:
	.string "My SKITTY and I are going to enter\n"
	.string "the POKéMON CONTEST in SLATEPORT.\p"
	.string "The judges won't be able to resist\n"
	.string "its charm!$"

LittlerootTown_PokemonCenter_1F_Text_Skitty:
	.string "SKITTY: Miyaa!$"

LittlerootTown_PokemonCenter_1F_Text_Youngster:
	.string "My family loves living in LITTLEROOT.\n"
	.string "We enjoy spending time in nature.$"
