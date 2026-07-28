FortreeCity_House2_MapScripts::
	.byte 0

FortreeCity_House2_EventScript_HiddenPowerGiver::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_HIDDEN_POWER, FortreeCity_House2_EventScript_ExplainHiddenPower
	call_if_unset FLAG_MET_HIDDEN_POWER_GIVER, FortreeCity_House2_EventScript_Greeting
	msgbox FortreeCity_House2_Text_CoinInWhichHand, MSGBOX_DEFAULT
	multichoice 21, 8, MULTI_RIGHTLEFT, TRUE
	switch VAR_RESULT
	case 1, FortreeCity_House2_EventScript_WrongGuess
	msgbox FortreeCity_House2_Text_CorrectTryAgainWhichHand, MSGBOX_DEFAULT
	multichoice 21, 8, MULTI_RIGHTLEFT, TRUE
	switch VAR_RESULT
	case 1, FortreeCity_House2_EventScript_WrongGuess
	msgbox FortreeCity_House2_Text_CorrectTryAgainWhichHand2, MSGBOX_DEFAULT
	multichoice 21, 8, MULTI_RIGHTLEFT, TRUE
	switch VAR_RESULT
	case 0, FortreeCity_House2_EventScript_WrongGuess
	msgbox FortreeCity_House2_Text_YourHiddenPowerHasAwoken, MSGBOX_DEFAULT
	giveitem ITEM_TM_HIDDEN_POWER
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_HIDDEN_POWER
	msgbox FortreeCity_House2_Text_ExplainHiddenPower, MSGBOX_DEFAULT
	release
	end

FortreeCity_House2_EventScript_Greeting::
	msgbox FortreeCity_House2_Text_HiddenPowersArousedByNature, MSGBOX_DEFAULT
	setflag FLAG_MET_HIDDEN_POWER_GIVER
	return

FortreeCity_House2_EventScript_ExplainHiddenPower::
	msgbox FortreeCity_House2_Text_ExplainHiddenPower, MSGBOX_DEFAULT
	release
	end

FortreeCity_House2_EventScript_WrongGuess::
	msgbox FortreeCity_House2_Text_YouGuessedWrong, MSGBOX_DEFAULT
	release
	end

FortreeCity_House2_Text_HiddenPowersArousedByNature:
	.string "Con người... POKéMON...\p"
	.string "Sống trong môi trường tự nhiên sẽ đánh\n"
	.string "thức sức mạnh tiềm ẩn trong họ...$"

FortreeCity_House2_Text_CoinInWhichHand:
	.string "Để bà lão này xem sức mạnh tiềm ẩn của\n"
	.string "cháu đã thức tỉnh chưa...\p"
	.string "Bà đang cầm một đồng xu trong tay.\p"
	.string "Nào, hãy nói xem bà giấu nó trong tay\n"
	.string "phải hay tay trái?$"

FortreeCity_House2_Text_CorrectTryAgainWhichHand:
	.string "Ồ! Đúng rồi!\p"
	.string "Chúng ta thử lại nhé.\p"
	.string "Bà đã giấu đồng xu trong tay nào? Tay\n"
	.string "phải hay tay trái?$"

FortreeCity_House2_Text_CorrectTryAgainWhichHand2:
	.string "Ồ! Đúng rồi!\p"
	.string "Chúng ta thử lại nhé.\p"
	.string "Bà đã giấu đồng xu trong tay nào? Tay\n"
	.string "phải hay tay trái?$"

FortreeCity_House2_Text_YourHiddenPowerHasAwoken:
	.string "Ồ! Tuyệt lắm! Sức mạnh tiềm ẩn của cháu\n"
	.string "đã thức tỉnh!\p"
	.string "Nào, hãy nhận lấy thứ này và đánh thức\n"
	.string "sức mạnh tiềm ẩn của POKéMON.$"

FortreeCity_House2_Text_ExplainHiddenPower:
	.string "HIDDEN POWER là một chiêu thức thay\n"
	.string "đổi tùy theo từng POKéMON.$"

FortreeCity_House2_Text_YouGuessedWrong:
	.string "Không, tiếc quá. Cháu đoán sai rồi.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global FortreeCity_House2_Text_HiddenPowersArousedByNature
	.global FortreeCity_House2_Text_CoinInWhichHand
	.global FortreeCity_House2_Text_CorrectTryAgainWhichHand
	.global FortreeCity_House2_Text_CorrectTryAgainWhichHand2
	.global FortreeCity_House2_Text_YourHiddenPowerHasAwoken
	.global FortreeCity_House2_Text_ExplainHiddenPower
	.global FortreeCity_House2_Text_YouGuessedWrong
@ END GENERATED LOCALIZATION EXPORTS
