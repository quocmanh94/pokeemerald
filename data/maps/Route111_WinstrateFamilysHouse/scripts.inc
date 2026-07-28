Route111_WinstrateFamilysHouse_MapScripts::
	.byte 0

Route111_WinstrateFamilysHouse_EventScript_Victor::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_WINSTRATE_HOUSE_VICTOR
	msgbox Route111_WinstrateFamilysHouse_Text_MySonIsStrongerThanYou, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_Victoria::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_WINSTRATE_HOUSE_VICTORIA
	goto_if_set FLAG_RECEIVED_MACHO_BRACE, Route111_WinstrateFamilysHouse_EventScript_ReceivedMachoBrace
	msgbox Route111_WinstrateFamilysHouse_Text_LikeYouToHaveMachoBrace, MSGBOX_DEFAULT
	giveitem ITEM_MACHO_BRACE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_MACHO_BRACE
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_ReceivedMachoBrace::
	msgbox Route111_WinstrateFamilysHouse_Text_PassionateAboutBattles, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_Vivi::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_WINSTRATE_HOUSE_VIVI
	msgbox Route111_WinstrateFamilysHouse_Text_StrongerFamilyMembers, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_Vicky::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_WINSTRATE_HOUSE_VICKY
	goto_if_set FLAG_TEMP_4, Route111_WinstrateFamilysHouse_EventScript_AlreadySpokenTo
	msgbox Route111_WinstrateFamilysHouse_Text_GrandsonStrong, MSGBOX_DEFAULT
	setflag FLAG_TEMP_4
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_AlreadySpokenTo::
	msgbox Route111_WinstrateFamilysHouse_Text_GrandsonStrongShort, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection::
	closemessage
	applymovement VAR_0x8008, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Route111_WinstrateFamilysHouse_Text_MySonIsStrongerThanYou:
	.string "Bạn là HLV đầu tiên tôi gặp có thể\n"
	.string "điều khiển POKéMON tài tình đến vậy.\p"
	.string "Nhưng tôi phải nói rằng con trai tôi còn\n"
	.string "mạnh hơn bạn.\p"
	.string "Nó thậm chí đã tham gia thử thách\n"
	.string "POKéMON LEAGUE đấy.$"

Route111_WinstrateFamilysHouse_Text_LikeYouToHaveMachoBrace:
	.string "Chúng tôi dùng MACHO BRACE này để rèn\n"
	.string "luyện POKéMON hiệu quả hơn.\p"
	.string "Bạn đã đánh bại tất cả chúng tôi nên\n"
	.string "không biết còn cần nó không, nhưng gia\l"
	.string "đình tôi muốn tặng bạn chiếc MACHO\l"
	.string "BRACE này.$"

Route111_WinstrateFamilysHouse_Text_PassionateAboutBattles:
	.string "Nhắc đến đấu POKéMON là cả gia đình\n"
	.string "chúng tôi thường nhiệt tình lắm.$"

Route111_WinstrateFamilysHouse_Text_StrongerFamilyMembers:
	.string "Mẹ mạnh hơn Ba.\p"
	.string "Mình mạnh hơn Mẹ.\p"
	.string "Còn Bà lại mạnh hơn mình!\p"
	.string "Nhưng anh trai mình còn mạnh hơn cả Bà.$"

Route111_WinstrateFamilysHouse_Text_GrandsonStrong:
	.string "Không thể phủ nhận rằng ngươi rất\n"
	.string "mạnh.\p"
	.string "Nhưng nếu đấu với cháu trai ta, ngươi\n"
	.string "sẽ phải khóc vì bất lực.\p"
	.string "Nó mạnh hơn bất kỳ HLV nào mà gia\n"
	.string "đình ta biết.\p"
	.string "Có lẽ giờ nó đang thách đấu CHAMPION\n"
	.string "của POKéMON LEAGUE.\p"
	.string "Với tài năng của cháu ta, biết đâu nó đã\n"
	.string "trở thành CHAMPION rồi!$"

Route111_WinstrateFamilysHouse_Text_GrandsonStrongShort:
	.string "Có lẽ giờ cháu trai ta đang thách đấu\n"
	.string "CHAMPION của POKéMON LEAGUE.\p"
	.string "Với tài năng của cháu ta, biết đâu nó đã\n"
	.string "trở thành CHAMPION rồi!$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global Route111_WinstrateFamilysHouse_Text_MySonIsStrongerThanYou
	.global Route111_WinstrateFamilysHouse_Text_LikeYouToHaveMachoBrace
	.global Route111_WinstrateFamilysHouse_Text_PassionateAboutBattles
	.global Route111_WinstrateFamilysHouse_Text_StrongerFamilyMembers
	.global Route111_WinstrateFamilysHouse_Text_GrandsonStrong
	.global Route111_WinstrateFamilysHouse_Text_GrandsonStrongShort
@ END GENERATED LOCALIZATION EXPORTS
