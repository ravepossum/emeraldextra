OmaomaTown_House3_MapScripts::
	.byte 0


OmaomaTown_House3_EventScript_PokefanM::
	msgbox OmaomaTown_House3_EventScript_PokefanM_Text_0, MSGBOX_NPC
	return


OmaomaTown_House3_EventScript_PokefanF::
	lock
	faceplayer
	dotimebasedevents
	goto_if_unset FLAG_RECEIVED_DAILY_WATER, OmaomaTown_House3_EventScript_PokefanF_2
OmaomaTown_House3_EventScript_PokefanF_1:
	msgbox OmaomaTown_House3_EventScript_PokefanF_Text_2
	release
	end

OmaomaTown_House3_EventScript_PokefanF_2:
	msgbox OmaomaTown_House3_EventScript_PokefanF_Text_0
	compare VAR_FACING, DIR_WEST
	goto_if_eq OmaomaTown_House3_EventScript_PokefanF_5
	applymovement 2, OmaomaTown_House3_Movement_MomTowardFridge_FacingUpDown
	waitmovement 2
	delay 20
	applymovement 2, OmaomaTown_House3_Movement_MomTowardPlayer_FacingUpDown
	waitmovement 2
OmaomaTown_House3_EventScript_PokefanF_4:
	faceplayer
	msgbox OmaomaTown_House3_EventScript_PokefanF_Text_1
	giveitem ITEM_FRESH_WATER
	compare VAR_RESULT, FALSE
	goto_if_eq OmaomaTown_House3_EventScript_PokefanF_9
OmaomaTown_House3_EventScript_PokefanF_8:
	setflag FLAG_RECEIVED_DAILY_WATER
	goto OmaomaTown_House3_EventScript_PokefanF_1

OmaomaTown_House3_EventScript_PokefanF_5:
	applymovement 2, OmaomaTown_House3_Movement_MomTowardFridge_FacingRight
	waitmovement 2
	delay 20
	applymovement 2, OmaomaTown_House3_Movement_MomTowardPlayer_FacingRight
	waitmovement 2
	goto OmaomaTown_House3_EventScript_PokefanF_4

OmaomaTown_House3_EventScript_PokefanF_9:
	goto Common_EventScript_ShowBagIsFull
	goto OmaomaTown_House3_EventScript_PokefanF_8


OmaomaTown_House3_Movement_MomTowardFridge_FacingRight:
	walk_slow_up
	walk_slow_right
	walk_slow_right
	walk_slow_up
	step_end

OmaomaTown_House3_Movement_MomTowardPlayer_FacingRight:
	walk_in_place_slow_up
	walk_slow_down
	walk_slow_left
	walk_slow_left
	walk_slow_down
	step_end

OmaomaTown_House3_Movement_MomTowardFridge_FacingUpDown:
	walk_slow_right
	walk_slow_right
	walk_slow_up
	walk_slow_up
	step_end

OmaomaTown_House3_Movement_MomTowardPlayer_FacingUpDown:
	walk_in_place_slow_up
	walk_slow_down
	walk_slow_down
	walk_slow_left
	walk_slow_left
	step_end

OmaomaTown_House3_EventScript_PokefanM_Text_0:
	.string "Our son just left for the mainland to\n"
	.string "begin his Pokémon Trainer journey.\p"
	.string "I do hope he calls every now and then.$"

OmaomaTown_House3_EventScript_PokefanF_Text_0:
	.string "Oh my--your youthful vigor!\p"
	.string "You remind me of my son.$"

OmaomaTown_House3_EventScript_PokefanF_Text_1:
	.string "Please, take this.$"

OmaomaTown_House3_EventScript_PokefanF_Text_2:
	.string "Remember to stay hydrated out there.\p"
	.string "Come back any time you're parched.$"
