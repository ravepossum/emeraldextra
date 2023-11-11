.set LOCALID_BRAWLY, 10

OmaomaTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OmaomaTown_OnTransition
	.byte 0

OmaomaTown_OnTransition::
	setflag FLAG_VISITED_OMAOMA_TOWN
	end


OmaomaTown_EventScript_TownSign::
	msgbox OmaomaTown_EventScript_TownSign_Text_0, MSGBOX_SIGN
	end


OmaomaTown_EventScript_Brawly::
	lock
	faceplayer
	msgbox OmaomaTown_EventScript_Brawly_Text_0
	msgbox OmaomaTown_EventScript_Brawly_Text_1
	playse SE_PIN
	applymovement LOCALID_BRAWLY, Common_Movement_ExclamationMark
	waitmovement LOCALID_BRAWLY
	msgbox OmaomaTown_EventScript_Brawly_Text_2
	compare VAR_FACING, DIR_WEST
	goto_if_eq OmaomaTown_EventScript_Brawly_2
	applymovement LOCALID_BRAWLY, OmaomaTown_Movement_Brawly_Facing_Up_Down_Left
OmaomaTown_EventScript_Brawly_1:
	waitmovement LOCALID_BRAWLY
	removeobject LOCALID_BRAWLY
	setflag FLAG_FOUND_BRAWLY_OMAOMA
	release
	end

OmaomaTown_EventScript_Brawly_2:
	applymovement LOCALID_BRAWLY, OmaomaTown_Movement_Brawly_Facing_Right
	goto OmaomaTown_EventScript_Brawly_1


OmaomaTown_Movement_Brawly_Facing_Up_Down_Left:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

OmaomaTown_Movement_Brawly_Facing_Right:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

OmaomaTown_EventScript_TownSign_Text_0:
	.string "Oma'oma Town\n“A town that is one with the tide.”$"

OmaomaTown_EventScript_Brawly_Text_0:
	.string "Oh, hey there!\p"
	.string "{PLAYER}, is it?\p"
	.string "I'm Brawly! Dewford's Gym Leader!$"

OmaomaTown_EventScript_Brawly_Text_1:
	.string "… … …$"

OmaomaTown_EventScript_Brawly_Text_2:
	.string "Huh? The other Trainers were looking\n"
	.string "for me?\p"
	.string "I was just hitting the waves before\n"
	.string "opening up the Gym.\p"
	.string "I'll head right over!$"
