Route136_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route136_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

Route136_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	goto_if_unset FLAG_DEFEATED_PHOEBE_ROUTE_136, Route136_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	return

Route136_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	special GetTimeOfDaySpecial
	switch VAR_RESULT
	case TIME_NIGHT, Route136_MapScripts_MAP_SCRIPT_ON_TRANSITION_4
	setflag FLAG_HIDE_PHOEBE_ROUTE_136
	return

Route136_MapScripts_MAP_SCRIPT_ON_TRANSITION_4:
	clearflag FLAG_HIDE_PHOEBE_ROUTE_136
	return


Route136_EventScript_RouteSignGraniteCave::
	msgbox Route136_EventScript_RouteSignGraniteCave_Text_0, MSGBOX_SIGN
	return


Route136_EventScript_Connor::
	trainerbattle_single TRAINER_CONNOR, Route136_Text_ConnorIntro, Route136_Text_ConnorDefeat
	msgbox Route136_Text_ConnorPostBattle, MSGBOX_AUTOCLOSE
	end


Route136_EventScript_Renee::
	trainerbattle_single TRAINER_RENEE, Route136_Text_ReneeIntro, Route136_Text_ReneeDefeat
	msgbox Route136_Text_ReneePostBattle, MSGBOX_AUTOCLOSE
	end


Route136_EventScript_Eduardo::
	trainerbattle_single TRAINER_EDUARDO, Route136_Text_EduardoIntro, Route136_Text_EduardoDefeat
	msgbox Route136_Text_EduardoPostBattle, MSGBOX_AUTOCLOSE
	end


Route136_EventScript_Phoebe::
	lock
	faceplayer
	playbgm MUS_ENCOUNTER_SUSPICIOUS, FALSE
	msgbox Route136_EventScript_Phoebe_Text_0
	trainerbattle_no_intro TRAINER_PHOEBE_ROUTE_136, Route136_Text_PhoebeDefeat
	msgbox Route136_EventScript_Phoebe_Text_1
	applymovement 4, Route136_Movement_Phoebe_Float
	playse SE_M_NIGHTMARE
	waitmovement 4
	applymovement 4, Route136_Movement_Phoebe_Fly
	playse SE_LAVARIDGE_FALL_WARP
	waitse
	removeobject 4
	setflag FLAG_DEFEATED_PHOEBE_ROUTE_136
	setflag FLAG_HIDE_PHOEBE_ROUTE_136
	release
	end


Route136_Movement_Phoebe_Float:
	levitate
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	step_end

Route136_Movement_Phoebe_Fly:
	fly_up
	step_end

Route136_EventScript_RouteSignGraniteCave_Text_0:
	.string "Granite Cave\n{UP_ARROW} Dewford Town\p{LEFT_ARROW} Oma'oma Town$"

Route136_EventScript_Phoebe_Text_0:
	.string "Hehehehehe…\p"
	.string "… … …\p"
	.string "You found me.\p"
	.string "… … …\p"
	.string "You seem different.\p"
	.string "Let me see how strong you are.$"

Route136_EventScript_Phoebe_Text_1:
	.string "{PLAYER}, is it?\p"
	.string "My name is Phoebe. I'm a member of\n"
	.string "Hoenn's Elite Four.\p"
	.string "You battled fiercely. I'll be keeping an\n"
	.string "eye on this one…$"

Route136_Text_ConnorIntro::
	.string "I'm all fired up and ready! Time to\n"
	.string "battle!$"

Route136_Text_ConnorDefeat::
	.string "Quenched like it was a cinch…$"

Route136_Text_ConnorPostBattle::
	.string "I'm on my way to Oma'oma town--Are you\n"
	.string "heading there too?$"

Route136_Text_ReneeIntro::
	.string "Let me see if you have what it takes to\n"
	.string "survive the wilds of Dewford Island.$"

Route136_Text_ReneeDefeat::
	.string "I think you'll have no problem out here…$"

Route136_Text_ReneePostBattle::
	.string "Enjoy the island! There's plenty of\n"
	.string "unique Pokémon to find here.$"

Route136_Text_EduardoIntro::
	.string "I'm on a mission. Let's make this quick.$"

Route136_Text_EduardoDefeat::
	.string "I guess I got what I wanted!$"

Route136_Text_EduardoPostBattle::
	.string "I'm hot on the trail of a secret cave\n"
	.string "here. I just need to keep exploring.$"

Route136_Text_PhoebeDefeat::
	.string "… … … magnificent!$"
