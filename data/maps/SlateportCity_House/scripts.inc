SlateportCity_House_MapScripts::
	.byte 0

SlateportCity_House_EventScript_PokefanM::
	msgbox SlateportCity_House_Text_NatureToDoWithStatGains, MSGBOX_NPC
	end

SlateportCity_House_EventScript_Girl::
	msgbox SlateportCity_House_Text_MustBeGoingToBattleTent, MSGBOX_NPC
	end

SlateportCity_House_Text_NatureToDoWithStatGains:
	.string "POKéMON của tôi có tính cách HASTY.\p"
	.string "Chỉ số SPEED của nó cao hơn những\n"
	.string "POKéMON khác của tôi.\p"
	.string "Có lẽ tính cách có liên quan đến mức\n"
	.string "tăng chỉ số của POKéMON.$"

SlateportCity_House_Text_MustBeGoingToBattleTent:
	.string "Bạn là một HLV, phải không?\p"
	.string "Đã đến SLATEPORT CITY thì chắc hẳn\n"
	.string "bạn đang định tới BATTLE TENT.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global SlateportCity_House_Text_NatureToDoWithStatGains
	.global SlateportCity_House_Text_MustBeGoingToBattleTent
@ END GENERATED LOCALIZATION EXPORTS
