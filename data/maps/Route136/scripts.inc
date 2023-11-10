Route136_MapScripts::
	.byte 0


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


Route136_EventScript_RouteSignGraniteCave_Text_0:
	.string "Granite Cave\n{UP_ARROW} Dewford Town\p{LEFT_ARROW} Oma'oma Town$"

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
