LilycoveCity_CoveLilyMotel_1F_MapScripts::
	.byte 0

LilycoveCity_CoveLilyMotel_1F_EventScript_MotelOwner::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_CoveLilyMotel_1F_EventScript_GameClear
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_CoveLilyMotel_1F_EventScript_AquaHideoutBusted
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_GuestsDoubledByMascot, MSGBOX_DEFAULT
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_NoGuestsWithTeamAqua, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

LilycoveCity_CoveLilyMotel_1F_EventScript_AquaHideoutBusted::
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_MonFoundLostItem, MSGBOX_DEFAULT
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_HeardAquaHideoutBusted, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

LilycoveCity_CoveLilyMotel_1F_EventScript_GameClear::
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_HouseSittingMonCaughtBurglar, MSGBOX_DEFAULT
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_BetterGetWorkingOnGuestsDinner, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

LilycoveCity_CoveLilyMotel_1F_EventScript_BlockingTV::
	lockall
	playse SE_PIN
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_CantSeeTheTV, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, LilycoveCity_CoveLilyMotel_1F_Movement_PlayerPushFromTV
	applymovement LOCALID_MOTEL_OWNER, LilycoveCity_CoveLilyMotel_1F_Movement_OwnerPushPlayer
	waitmovement 0
	applymovement LOCALID_MOTEL_OWNER, LilycoveCity_CoveLilyMotel_1F_Movement_OwnerReturn
	waitmovement 0
	release
	end

LilycoveCity_CoveLilyMotel_1F_Movement_PlayerPushFromTV:
	face_right
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

LilycoveCity_CoveLilyMotel_1F_Movement_OwnerPushPlayer:
	walk_up
	step_end

LilycoveCity_CoveLilyMotel_1F_Movement_OwnerReturn:
	face_down
	walk_down
	face_up
	step_end

LilycoveCity_CoveLilyMotel_1F_Text_GuestsDoubledByMascot:
	.string "Ừm, họ đã tăng gấp đôi lượng khách nhờ\n"
	.string "dùng POKéMON làm điểm thu hút sao?\p"
	.string "Ừm, có lẽ mình cũng nên chọn một\n"
	.string "POKéMON dễ thương làm linh vật cho nhà\l"
	.string "trọ.\p"
	.string "Không biết như vậy có thu hút thêm\n"
	.string "khách đến nghỉ không nhỉ?$"

LilycoveCity_CoveLilyMotel_1F_Text_NoGuestsWithTeamAqua:
	.string "Ôi, xin lỗi, xin lỗi! Tôi mải xem TV quá!\p"
	.string "Từ khi TEAM AQUA đến thành phố, khách\n"
	.string "du lịch chẳng còn bén mảng tới đây.$"

LilycoveCity_CoveLilyMotel_1F_Text_CantSeeTheTV:
	.string "Này, cúi xuống đi! Tôi không thấy TV!$"

LilycoveCity_CoveLilyMotel_1F_Text_MonFoundLostItem:
	.string "Tuyệt thật! Bạn nói một POKéMON đã tìm\n"
	.string "thấy đồ thất lạc của người khác sao?\p"
	.string "Đúng là đáng nể. Nếu chúng tôi có một\n"
	.string "POKéMON thông minh như vậy...\p"
	.string "Chúng tôi có thể tìm lại bất cứ thứ gì\n"
	.string "khách để thất lạc...$"

LilycoveCity_CoveLilyMotel_1F_Text_HeardAquaHideoutBusted:
	.string "Ôi, xin lỗi, xin lỗi! Tôi mải xem TV quá!\p"
	.string "Tôi nghe nói có người đã triệt phá TEAM\n"
	.string "AQUA HIDEOUT.\p"
	.string "Nhờ vậy, chúng tôi vừa nhận được đơn\n"
	.string "đặt phòng của một đoàn khách lớn.\p"
	.string "Họ là một công ty tên là... Ờ... GAME gì\n"
	.string "đó...$"

LilycoveCity_CoveLilyMotel_1F_Text_HouseSittingMonCaughtBurglar:
	.string "Tuyệt thật! Một POKéMON trông nhà đã\n"
	.string "bắt được kẻ trộm sao?\p"
	.string "Đúng là đáng nể. Nếu chúng tôi có một\n"
	.string "POKéMON mạnh mẽ làm bảo vệ...\p"
	.string "Chúng tôi có thể đảm bảo an toàn hơn\n"
	.string "cho khách nghỉ.$"

LilycoveCity_CoveLilyMotel_1F_Text_BetterGetWorkingOnGuestsDinner:
	.string "Ôi, xin lỗi, xin lỗi! Tôi mải xem TV quá.\p"
	.string "À, đúng rồi. Một đoàn khách lớn vừa đến\n"
	.string "cách đây không lâu.\p"
	.string "Họ đăng ký dưới tên GAME FREAK, chắc\n"
	.string "họ là công ty làm game.\p"
	.string "Chết rồi, tôi phải mau chuẩn bị bữa tối\n"
	.string "cho họ!$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global LilycoveCity_CoveLilyMotel_1F_Text_GuestsDoubledByMascot
	.global LilycoveCity_CoveLilyMotel_1F_Text_NoGuestsWithTeamAqua
	.global LilycoveCity_CoveLilyMotel_1F_Text_CantSeeTheTV
	.global LilycoveCity_CoveLilyMotel_1F_Text_MonFoundLostItem
	.global LilycoveCity_CoveLilyMotel_1F_Text_HeardAquaHideoutBusted
	.global LilycoveCity_CoveLilyMotel_1F_Text_HouseSittingMonCaughtBurglar
	.global LilycoveCity_CoveLilyMotel_1F_Text_BetterGetWorkingOnGuestsDinner
@ END GENERATED LOCALIZATION EXPORTS
