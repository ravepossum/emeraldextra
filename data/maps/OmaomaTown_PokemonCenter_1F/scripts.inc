.set LOCALID_NURSE, 1

OmaomaTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OmaomaTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

OmaomaTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_OMAOMA_TOWN
	end

OmaomaTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

OmaomaTown_PokemonCenter_1F_EventScript_UnionNurse::
	call Common_EventScript_PkmnCenterUnionNurse
	waitmessage
	waitbuttonpress
	release
	end


OmaomaTown_PokemonCenter_1F_EventScript_Boy::
	msgbox OmaomaTown_PokemonCenter_1F_EventScript_Boy_Text_0, MSGBOX_NPC
	return


OmaomaTown_PokemonCenter_1F_EventScript_Boy_Text_0:
	.string "Did you know?\p"
	.string "You can quickly swap around Pokémon by\n"
	.string "pressing the Select Button in the\l"
	.string "Party Menu?\p"
	.string "It's real nifty!$"
