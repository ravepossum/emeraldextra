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
