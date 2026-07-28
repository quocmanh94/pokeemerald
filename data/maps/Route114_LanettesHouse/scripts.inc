Route114_LanettesHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_LanettesHouse_OnTransition
	.byte 0

Route114_LanettesHouse_OnTransition:
	setflag FLAG_LANDMARK_LANETTES_HOUSE
	end

Route114_LanettesHouse_EventScript_Lanette::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_DOLL_LANETTE, Route114_LanettesHouse_EventScript_OfferAdvice
	setflag FLAG_SYS_PC_LANETTE
	msgbox Route114_LanettesHouse_Text_EverythingClutteredKeepThis, MSGBOX_DEFAULT
	givedecoration DECOR_LOTAD_DOLL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowNoRoomForDecor
	setflag FLAG_RECEIVED_DOLL_LANETTE
	release
	end

Route114_LanettesHouse_EventScript_OfferAdvice::
	msgbox Route114_LanettesHouse_Text_OrganizeYourBoxes, MSGBOX_DEFAULT
	release
	end

Route114_LanettesHouse_EventScript_Notebook::
	lockall
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route114_LanettesHouse_EventScript_NotebookPage2
	msgbox Route114_LanettesHouse_Text_ClosedTheNotebook, MSGBOX_DEFAULT
	releaseall
	end

Route114_LanettesHouse_EventScript_NotebookPage2::
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage2, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, Route114_LanettesHouse_EventScript_NotebookPage3
	releaseall
	end

Route114_LanettesHouse_EventScript_NotebookPage3::
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage3, MSGBOX_DEFAULT
	return

Route114_LanettesHouse_EventScript_PC::
	msgbox Route114_LanettesHouse_Text_EmailFromBill, MSGBOX_SIGN
	end

Route114_LanettesHouse_Text_EverythingClutteredKeepThis:
	.string "LANETTE: Ôi! {PLAYER}{KUN}!\p"
	.string "Xin lỗi vì mọi thứ bừa bộn quá... Mỗi khi\n"
	.string "mải mê nghiên cứu, căn phòng lại thành\l"
	.string "ra thế này...\p"
	.string "Xấu hổ quá... Xin hãy giữ bí mật chuyện\n"
	.string "này, đổi lại tôi sẽ tặng bạn thứ này.$"

Route114_LanettesHouse_Text_OrganizeYourBoxes:
	.string "Tôi có thể cho bạn một lời khuyên về\n"
	.string "POKéMON Storage System của mình\l"
	.string "không?\p"
	.string "Bạn nên sắp xếp BOXES để dễ nhận biết\n"
	.string "mỗi BOX đang chứa POKéMON nào.$"

Route114_LanettesHouse_Text_ResearchNotesPage1:
	.string "Đây là ghi chép nghiên cứu của LANETTE.\n"
	.string "Trong đó có thông tin về BOXES.\p"
	.string "Thiết kế BOXES để mỗi hộp chứa được 30\n"
	.string "POKéMON.\p"
	.string "Mỗi HLV có thể lưu trữ 420 POKéMON\n"
	.string "trên hệ thống PC.\p"
	.string "Đọc tiếp không?$"

Route114_LanettesHouse_Text_ResearchNotesPage2:
	.string "Nên bổ sung hệ thống đánh dấu để dễ\n"
	.string "sắp xếp POKéMON hơn.\p"
	.string "Có thể thay đổi tên và hình nền của mỗi\n"
	.string "BOX để làm hài lòng POKéMON được lưu\l"
	.string "trữ.\p"
	.string "Đọc tiếp không?$"

Route114_LanettesHouse_Text_ResearchNotesPage3:
	.string "Khi lưu trữ một POKéMON, nó sẽ được\n"
	.string "gửi đến BOX được xem gần nhất.\p"
	.string "Nếu BOX đó đầy, POKéMON vừa nhận sẽ\n"
	.string "được lưu vào BOX tiếp theo.\p"
	.string "Nói cách khác, khi xem một BOX, BOX đó\n"
	.string "sẽ tự động được chọn làm nơi tiếp nhận\l"
	.string "POKéMON.$"

Route114_LanettesHouse_Text_ClosedTheNotebook:
	.string "{PLAYER} đóng cuốn sổ lại.$"

Route114_LanettesHouse_Text_EmailFromBill:
	.string "Có một e-mail của ai đó trên PC.\p"
	.string "“... ... ... ... ... ... ...\p"
	.string "“Storage System của bạn tiện lợi hơn\n"
	.string "hệ thống của tôi.\p"
	.string "“Nó còn có nhiều tính năng thân thiện\n"
	.string "với người dùng, vừa thú vị vừa hữu\l"
	.string "ích.\p"
	.string "“Tôi rất tự hào vì đã góp một phần vào\n"
	.string "quá trình phát triển hệ thống đó.\p"
	.string "“Hy vọng bạn sẽ tiếp tục nghiên cứu\n"
	.string "Storage Systems.\p"
	.string "“Từ BILL ... ... ... ... ... ... ... ...”$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global Route114_LanettesHouse_Text_EverythingClutteredKeepThis
	.global Route114_LanettesHouse_Text_OrganizeYourBoxes
	.global Route114_LanettesHouse_Text_ResearchNotesPage1
	.global Route114_LanettesHouse_Text_ResearchNotesPage2
	.global Route114_LanettesHouse_Text_ResearchNotesPage3
	.global Route114_LanettesHouse_Text_ClosedTheNotebook
	.global Route114_LanettesHouse_Text_EmailFromBill
@ END GENERATED LOCALIZATION EXPORTS
