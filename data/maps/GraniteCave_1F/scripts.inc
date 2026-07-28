GraniteCave_1F_MapScripts::
	.byte 0

GraniteCave_1F_EventScript_Hiker::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_FLASH, GraniteCave_1F_EventScript_ReceivedFlash
	msgbox GraniteCave_1F_Text_GetsDarkAheadHereYouGo, MSGBOX_DEFAULT
	giveitem ITEM_HM_FLASH
	setflag FLAG_RECEIVED_HM_FLASH
	msgbox GraniteCave_1F_Text_ExplainFlash, MSGBOX_DEFAULT
	release
	end

GraniteCave_1F_EventScript_ReceivedFlash::
	msgbox GraniteCave_1F_Text_ExplainFlash, MSGBOX_DEFAULT
	release
	end

GraniteCave_1F_Text_GetsDarkAheadHereYouGo:
	.string "Này, bạn kia. Phía trước tối lắm, khám\n"
	.string "phá sẽ rất khó khăn.\p"
	.string "Người đã đi qua lúc nãy... Hình như tên\n"
	.string "là STEVEN.\p"
	.string "Cậu ấy biết dùng FLASH nên chắc sẽ ổn,\n"
	.string "nhưng...\p"
	.string "Với HIKERS chúng tôi, giúp đỡ những\n"
	.string "người mình gặp là phương châm sống.\p"
	.string "Đây, tôi sẽ trao thứ này cho bạn.$"

GraniteCave_1F_Text_ExplainFlash:
	.string "Hãy dạy chiêu thức ẩn FLASH cho một\n"
	.string "POKéMON rồi sử dụng nó.\p"
	.string "Nó có thể thắp sáng cả bóng tối đen kịt\n"
	.string "trong hang động.\p"
	.string "Nhưng để sử dụng, bạn cần GYM BADGE từ\n"
	.string "POKéMON GYM ở DEWFORD.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global GraniteCave_1F_Text_GetsDarkAheadHereYouGo
	.global GraniteCave_1F_Text_ExplainFlash
@ END GENERATED LOCALIZATION EXPORTS
