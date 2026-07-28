Route111_OldLadysRestStop_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route111_OldLadysRestStop_OnTransition
	.byte 0

Route111_OldLadysRestStop_OnTransition:
	setflag FLAG_LANDMARK_OLD_LADY_REST_SHOP
	end

Route111_OldLadysRestStop_EventScript_OldLady::
	lock
	faceplayer
	msgbox Route111_OldLadysRestStop_Text_RestUpHere, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route111_OldLadysRestStop_EventScript_Rest
	goto_if_eq VAR_RESULT, NO, Route111_OldLadysRestStop_EventScript_DeclineRest
	end

Route111_OldLadysRestStop_EventScript_Rest::
	msgbox Route111_OldLadysRestStop_Text_TakeYourTimeRestUp, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox Route111_OldLadysRestStop_Text_StillTiredTakeAnotherRest, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route111_OldLadysRestStop_EventScript_Rest
	goto_if_eq VAR_RESULT, NO, Route111_OldLadysRestStop_EventScript_DeclineRest
	end

Route111_OldLadysRestStop_EventScript_DeclineRest::
	msgbox Route111_OldLadysRestStop_Text_DontNeedToBeShy, MSGBOX_DEFAULT
	release
	end

Route111_OldLadysRestStop_Text_RestUpHere:
	.string "Ôi chao. POKéMON của cháu mệt lả rồi\n"
	.string "phải không?\p"
	.string "Nếu muốn thì hãy nghỉ lại đây. Ý hay\n"
	.string "đấy! Cháu nên nghỉ đi.$"

Route111_OldLadysRestStop_Text_TakeYourTimeRestUp:
	.string "Đúng rồi. Cứ thong thả nghỉ ngơi nhé!$"

Route111_OldLadysRestStop_Text_StillTiredTakeAnotherRest:
	.string "Ôi chao. POKéMON của cháu vẫn còn mệt\n"
	.string "sao?\p"
	.string "Cháu nên nghỉ thêm một lần nữa ở đây. Ý\n"
	.string "hay đấy. Cháu cứ nghỉ đi.$"

Route111_OldLadysRestStop_Text_DontNeedToBeShy:
	.string "Vậy sao? Cháu không cần phải ngại đâu.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global Route111_OldLadysRestStop_Text_RestUpHere
	.global Route111_OldLadysRestStop_Text_TakeYourTimeRestUp
	.global Route111_OldLadysRestStop_Text_StillTiredTakeAnotherRest
	.global Route111_OldLadysRestStop_Text_DontNeedToBeShy
@ END GENERATED LOCALIZATION EXPORTS
