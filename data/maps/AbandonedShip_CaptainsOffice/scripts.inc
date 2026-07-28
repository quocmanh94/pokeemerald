AbandonedShip_CaptainsOffice_MapScripts::
	.byte 0

AbandonedShip_CaptainsOffice_EventScript_CaptSternAide::
	lock
	faceplayer
	goto_if_set FLAG_EXCHANGED_SCANNER, AbandonedShip_CaptainsOffice_EventScript_ThisIsSSCactus
	checkitem ITEM_SCANNER
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_CaptainsOffice_EventScript_CanYouDeliverScanner
	goto_if_set FLAG_ITEM_ABANDONED_SHIP_HIDDEN_FLOOR_ROOM_2_SCANNER, AbandonedShip_CaptainsOffice_EventScript_ThisIsSSCactus
	msgbox AbandonedShip_CaptainsOffice_Text_NoSuccessFindingScanner, MSGBOX_DEFAULT
	release
	end

AbandonedShip_CaptainsOffice_EventScript_CanYouDeliverScanner::
	msgbox AbandonedShip_CaptainsOffice_Text_OhCanYouDeliverScanner, MSGBOX_DEFAULT
	release
	end

AbandonedShip_CaptainsOffice_EventScript_ThisIsSSCactus::
	msgbox AbandonedShip_CaptainsOffice_Text_ThisIsSSCactus, MSGBOX_DEFAULT
	release
	end

AbandonedShip_CaptainsOffice_Text_NoSuccessFindingScanner:
	.string "Tôi đang điều tra con tàu này theo yêu\n"
	.string "cầu của CAPT. STERN.\p"
	.string "Ông ấy còn nhờ tôi tìm một SCANNER,\n"
	.string "nhưng đến giờ tôi vẫn chưa có kết\l"
	.string "quả...$"

AbandonedShip_CaptainsOffice_Text_OhCanYouDeliverScanner:
	.string "Ồ! Đó là một SCANNER!\p"
	.string "Nghe này, bạn có thể mang nó đến cho\n"
	.string "CAPT. STERN được không?\p"
	.string "Tôi muốn điều tra con tàu này thêm một\n"
	.string "chút nữa.$"

AbandonedShip_CaptainsOffice_Text_ThisIsSSCactus:
	.string "Con tàu này tên là S.S. CACTUS. Có vẻ nó\n"
	.string "thuộc về một thời đại trước.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global AbandonedShip_CaptainsOffice_Text_NoSuccessFindingScanner
	.global AbandonedShip_CaptainsOffice_Text_OhCanYouDeliverScanner
	.global AbandonedShip_CaptainsOffice_Text_ThisIsSSCactus
@ END GENERATED LOCALIZATION EXPORTS
