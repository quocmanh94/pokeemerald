SlateportCity_NameRatersHouse_MapScripts::
	.byte 0

SlateportCity_NameRatersHouse_EventScript_NameRater::
	lock
	faceplayer
	msgbox SlateportCity_NameRatersHouse_Text_PleasedToRateMonNickname, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_NameRatersHouse_EventScript_ChooseMonToRate
	goto_if_eq VAR_RESULT, NO, SlateportCity_NameRatersHouse_EventScript_DeclineNameRate
	end

SlateportCity_NameRatersHouse_EventScript_ChooseMonToRate::
	msgbox SlateportCity_NameRatersHouse_Text_CritiqueWhichMonNickname, MSGBOX_DEFAULT
	special ChoosePartyMon
	goto_if_ne VAR_0x8004, PARTY_NOTHING_CHOSEN, SlateportCity_NameRatersHouse_EventScript_RateMonNickname
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, SlateportCity_NameRatersHouse_EventScript_DeclineNameRate
	end

SlateportCity_NameRatersHouse_EventScript_DeclineNameRate::
	msgbox SlateportCity_NameRatersHouse_Text_DoVisitAgain, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_RateMonNickname::
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, SlateportCity_NameRatersHouse_EventScript_CantRateEgg
	special BufferMonNickname
	msgbox SlateportCity_NameRatersHouse_Text_FineNameSuggestBetterOne, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_NameRatersHouse_EventScript_ChangeNickname
	goto_if_eq VAR_RESULT, NO, SlateportCity_NameRatersHouse_EventScript_DeclineNameRate
	end

SlateportCity_NameRatersHouse_EventScript_CantRateEgg::
	msgbox SlateportCity_NameRatersHouse_Text_ThatIsMerelyAnEgg, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_PlayerNotMonsOT::
	msgbox SlateportCity_NameRatersHouse_Text_MagnificentName, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_ChangeNickname::
	msgbox SlateportCity_NameRatersHouse_Text_WhatShallNewNameBe, MSGBOX_DEFAULT
	call Common_EventScript_NameReceivedPartyMon
	specialvar VAR_RESULT, TryPutNameRaterShowOnTheAir
	special BufferMonNickname
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_NameRatersHouse_EventScript_NewNameDifferent
	msgbox SlateportCity_NameRatersHouse_Text_NameNoDifferentYetSuperior, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_NewNameDifferent::
	msgbox SlateportCity_NameRatersHouse_Text_MonShallBeKnownAsName, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_Text_PleasedToRateMonNickname:
	.string "Chào, chào! Ta là NAME RATER! Ta là thầy\n"
	.string "bói của những cái tên!\p"
	.string "Ta rất hân hạnh được đánh giá biệt\n"
	.string "danh POKéMON của cháu.$"

SlateportCity_NameRatersHouse_Text_CritiqueWhichMonNickname:
	.string "Ta nên đánh giá biệt danh của POKéMON\n"
	.string "nào đây?$"

SlateportCity_NameRatersHouse_Text_FineNameSuggestBetterOne:
	.string "Hừm... {STR_VAR_1}, phải không?\n"
	.string "Cháu đã đặt một cái tên khá hay đấy.\p"
	.string "Nhưng! Cháu nghĩ sao nếu ta đề xuất\n"
	.string "một cái tên hay hơn một chút?$"

SlateportCity_NameRatersHouse_Text_WhatShallNewNameBe:
	.string "À, tốt lắm. Vậy biệt danh mới sẽ là gì?$"

SlateportCity_NameRatersHouse_Text_MonShallBeKnownAsName:
	.string "Xong! Từ giờ POKéMON này sẽ được gọi\n"
	.string "là {STR_VAR_1}!\p"
	.string "Cái tên này hay hơn trước! Cháu thật\n"
	.string "may mắn!$"

SlateportCity_NameRatersHouse_Text_DoVisitAgain:
	.string "Ta hiểu rồi. Nhớ ghé thăm lần nữa nhé.$"

SlateportCity_NameRatersHouse_Text_NameNoDifferentYetSuperior:
	.string "Xong! Từ giờ POKéMON này sẽ được gọi\n"
	.string "là {STR_VAR_1}!\p"
	.string "Trông chẳng khác gì trước, vậy mà hay\n"
	.string "hơn hẳn!\p"
	.string "Cháu thật may mắn!$"

SlateportCity_NameRatersHouse_Text_MagnificentName:
	.string "Hừm... Chính là {STR_VAR_1}!\p"
	.string "Đây là một biệt danh tuyệt mỹ! Hoàn hảo\n"
	.string "đến mức không thể chê vào đâu được!\p"
	.string "Hãy luôn trân trọng {STR_VAR_1},\n"
	.string "từ giờ và mãi về sau.$"

SlateportCity_NameRatersHouse_Text_ThatIsMerelyAnEgg:
	.string "Nào, nào. Đó chỉ là một EGG thôi!$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global SlateportCity_NameRatersHouse_Text_PleasedToRateMonNickname
	.global SlateportCity_NameRatersHouse_Text_CritiqueWhichMonNickname
	.global SlateportCity_NameRatersHouse_Text_FineNameSuggestBetterOne
	.global SlateportCity_NameRatersHouse_Text_WhatShallNewNameBe
	.global SlateportCity_NameRatersHouse_Text_MonShallBeKnownAsName
	.global SlateportCity_NameRatersHouse_Text_DoVisitAgain
	.global SlateportCity_NameRatersHouse_Text_NameNoDifferentYetSuperior
	.global SlateportCity_NameRatersHouse_Text_MagnificentName
	.global SlateportCity_NameRatersHouse_Text_ThatIsMerelyAnEgg
@ END GENERATED LOCALIZATION EXPORTS
