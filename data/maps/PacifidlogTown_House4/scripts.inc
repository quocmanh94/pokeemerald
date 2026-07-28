PacifidlogTown_House4_MapScripts::
	.byte 0

PacifidlogTown_House4_EventScript_LittleGirl::
	msgbox PacifidlogTown_House4_Text_SkyPokemon, MSGBOX_NPC
	end

PacifidlogTown_House4_EventScript_Woman::
	msgbox PacifidlogTown_House4_Text_PeopleSawHighFlyingPokemon, MSGBOX_NPC
	end

PacifidlogTown_House4_EventScript_Boy::
	lock
	faceplayer
	msgbox PacifidlogTown_House4_Text_WhereDidYouComeFrom, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PacifidlogTown_House4_EventScript_Yes
	goto_if_eq VAR_RESULT, NO, PacifidlogTown_House4_EventScript_No
	end

PacifidlogTown_House4_EventScript_Yes::
	msgbox PacifidlogTown_House4_Text_YesTown, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House4_EventScript_No::
	msgbox PacifidlogTown_House4_Text_YouHaveToComeFromSomewhere, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House4_Text_PeopleSawHighFlyingPokemon:
	.string "Mọi người nói rằng họ đã thấy một\n"
	.string "POKéMON bay rất cao trên bầu trời\l"
	.string "HOENN.\p"
	.string "Nó cứ bay mãi như vậy sao? Nó không\n"
	.string "cần nghỉ ở đâu đó à?$"

PacifidlogTown_House4_Text_SkyPokemon:
	.string "POKéMON của bầu trời! POKéMON của bầu\n"
	.string "trời!$"

PacifidlogTown_House4_Text_WhereDidYouComeFrom:
	.string "Cậu đến từ đâu?$"

PacifidlogTown_House4_Text_YesTown:
	.string "Hả? YES TOWN ư?\p"
	.string "Tôi chưa từng nghe nói đến nơi nào như\n"
	.string "thế.$"

PacifidlogTown_House4_Text_YouHaveToComeFromSomewhere:
	.string "Không ư? Vô lý quá. Cậu phải đến từ nơi\n"
	.string "nào đó chứ.\p"
	.string "Ồ! Khoan đã! Cậu không định nói rằng\n"
	.string "mình được sinh ra dưới đáy biển đấy\l"
	.string "chứ?$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global PacifidlogTown_House4_Text_PeopleSawHighFlyingPokemon
	.global PacifidlogTown_House4_Text_SkyPokemon
	.global PacifidlogTown_House4_Text_WhereDidYouComeFrom
	.global PacifidlogTown_House4_Text_YesTown
	.global PacifidlogTown_House4_Text_YouHaveToComeFromSomewhere
@ END GENERATED LOCALIZATION EXPORTS
