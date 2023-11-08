OmaomaTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OmaomaTown_OnTransition
	.byte 0

OmaomaTown_OnTransition::
	setflag FLAG_VISITED_OMAOMA_TOWN
	end


OmaomaTown_EventScript_TownSign::
	msgbox OmaomaTown_EventScript_TownSign_Text_0, MSGBOX_SIGN
	end


OmaomaTown_EventScript_TownSign_Text_0:
	.string "Oma'oma Town\n“A town that is one with the tide.”$"
