OmaomaTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OmaomaTown_OnTransition
	.byte 0

OmaomaTown_OnTransition::
	setflag FLAG_VISITED_OMAOMA_TOWN
	end

