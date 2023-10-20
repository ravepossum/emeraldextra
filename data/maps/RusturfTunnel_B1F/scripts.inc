RusturfTunnel_B1F_MapScripts::
	.byte 0


RusturfTunnel_B1F_EventScript_Delvin::
	trainerbattle_single TRAINER_DELVIN, RusturfTunnel_B1F_Text_DelvinIntro, RusturfTunnel_B1F_Text_DelvinOutro
	msgbox RusturfTunnel_B1F_Text_DelvinPostBattle, MSGBOX_AUTOCLOSE
	waitmessage
	end


RusturfTunnel_B1F_Text_DelvinIntro::
	.string "I'll defeat you with my brand new\n"
	.string "POKéMON!$"

RusturfTunnel_B1F_Text_DelvinOutro::
	.string "I guess I need to train it some more...$"

RusturfTunnel_B1F_Text_DelvinPostBattle::
	.string "I heard that you can find POKéMON in\n"
	.string "rare and unique colors. I've been\l"
	.string "searching everywhere for one.$"
