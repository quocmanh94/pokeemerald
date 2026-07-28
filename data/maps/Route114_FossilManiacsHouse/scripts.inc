Route114_FossilManiacsHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_FossilManiacsHouse_OnTransition
	.byte 0

Route114_FossilManiacsHouse_OnTransition:
	setflag FLAG_LANDMARK_FOSSIL_MANIACS_HOUSE
	end

Route114_FossilManiacsHouse_EventScript_FossilManiacsBrother::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_DIG, Route114_FossilManiacsHouse_EventScript_ReceivedDig
	msgbox Route114_FossilManiacsHouse_Text_HaveThisToDigLikeMyBrother, MSGBOX_DEFAULT
	giveitem ITEM_TM_DIG
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_DIG
	release
	end

Route114_FossilManiacsHouse_EventScript_ReceivedDig::
	msgbox Route114_FossilManiacsHouse_Text_DigReturnsYouToEntrance, MSGBOX_DEFAULT
	release
	end

Route114_FossilManiacsHouse_EventScript_RockDisplay::
	msgbox Route114_FossilManiacsHouse_Text_RocksFillDisplayCase, MSGBOX_SIGN
	end

Route114_FossilManiacsHouse_EventScript_Bookshelf::
	msgbox Route114_FossilManiacsHouse_Text_CrammedWithBooks, MSGBOX_SIGN
	end

Route114_FossilManiacsHouse_Text_HaveThisToDigLikeMyBrother:
	.string "Anh trai tôi là FOSSIL MANIAC... Anh ấy\n"
	.string "là người tốt và rất yêu FOSSILS...\p"
	.string "Anh ấy cũng thích đào hang... Anh ấy tự\n"
	.string "đào đường hầm này một mình...\p"
	.string "Bạn có thể lấy thứ này để dùng DIG đào\n"
	.string "hang giống anh trai tôi...$"

Route114_FossilManiacsHouse_Text_DigReturnsYouToEntrance:
	.string "Nếu cho POKéMON dùng DIG trong hang\n"
	.string "động, bạn sẽ được đưa trở lại cửa\l"
	.string "hang...$"

Route114_FossilManiacsHouse_Text_RocksFillDisplayCase:
	.string "Tủ trưng bày chứa đầy những hòn đá có\n"
	.string "hình thù kỳ lạ...$"

Route114_FossilManiacsHouse_Text_CrammedWithBooks:
	.string "CẤU TẠO CỦA CÁC TẦNG ĐÁ... MƯA ĐỊNH\n"
	.string "HÌNH MẶT ĐẤT THẾ NÀO... ĐÁ, ĐẤT VÀ\l"
	.string "SỎI...\p"
	.string "Sách được nhét kín bên trong.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global Route114_FossilManiacsHouse_Text_HaveThisToDigLikeMyBrother
	.global Route114_FossilManiacsHouse_Text_DigReturnsYouToEntrance
	.global Route114_FossilManiacsHouse_Text_RocksFillDisplayCase
	.global Route114_FossilManiacsHouse_Text_CrammedWithBooks
@ END GENERATED LOCALIZATION EXPORTS
