GraniteCave_StevensRoom_MapScripts::
	.byte 0

GraniteCave_StevensRoom_EventScript_Steven::
	lock
	faceplayer
	msgbox GraniteCave_StevensRoom_Text_ImStevenLetterForMe, MSGBOX_DEFAULT
	setvar VAR_0x8004, ITEM_LETTER
	call Common_EventScript_PlayerHandedOverTheItem
	setflag FLAG_DELIVERED_STEVEN_LETTER
	msgbox GraniteCave_StevensRoom_Text_ThankYouTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM_STEEL_WING
	call_if_eq VAR_RESULT, FALSE, GraniteCave_StevensRoom_EventScript_BagFull
	msgbox GraniteCave_StevensRoom_Text_CouldBecomeChampionLetsRegister, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox GraniteCave_StevensRoom_Text_RegisteredSteven, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_REGISTERED_STEVEN_POKENAV
	msgbox GraniteCave_StevensRoom_Text_IveGotToHurryAlong, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, GraniteCave_StevensRoom_EventScript_StevenExitNorth
	call_if_eq VAR_FACING, DIR_SOUTH, GraniteCave_StevensRoom_EventScript_StevenExitSouth
	call_if_eq VAR_FACING, DIR_WEST, GraniteCave_StevensRoom_EventScript_StevenExitWestEast
	call_if_eq VAR_FACING, DIR_EAST, GraniteCave_StevensRoom_EventScript_StevenExitWestEast
	playse SE_EXIT
	removeobject LOCALID_GRANITE_CAVE_STEVEN
	release
	end

GraniteCave_StevensRoom_EventScript_StevenExitNorth::
	applywaitmovement LOCALID_GRANITE_CAVE_STEVEN, GraniteCave_StevensRoom_Movement_StevenExit
	return

GraniteCave_StevensRoom_EventScript_StevenExitWestEast::
	applymovement LOCALID_PLAYER, GraniteCave_StevensRoom_Movement_PlayerTurnTowardExit
	applymovement LOCALID_GRANITE_CAVE_STEVEN, GraniteCave_StevensRoom_Movement_StevenExit
	waitmovement 0
	return

GraniteCave_StevensRoom_EventScript_StevenExitSouth::
	applymovement LOCALID_PLAYER, GraniteCave_StevensRoom_Movement_PlayerTurnTowardExit
	applymovement LOCALID_GRANITE_CAVE_STEVEN, GraniteCave_StevensRoom_Movement_StevenExitSouth
	waitmovement 0
	return

GraniteCave_StevensRoom_EventScript_BagFull::
	msgbox GraniteCave_StevensRoom_Text_OhBagIsFull, MSGBOX_DEFAULT
	return

GraniteCave_StevensRoom_Movement_StevenExit:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	delay_8
	step_end

GraniteCave_StevensRoom_Movement_PlayerTurnTowardExit:
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_up
	step_end

GraniteCave_StevensRoom_Movement_StevenExitSouth:
	walk_left
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	delay_8
	step_end

GraniteCave_StevensRoom_Text_ImStevenLetterForMe:
	.string "Tên anh là STEVEN.\p"
	.string "Anh quan tâm đến những viên đá hiếm,\n"
	.string "nên đi khắp nơi.\p"
	.string "Ồ? LETTER này là gửi cho anh sao?$"

GraniteCave_StevensRoom_Text_ThankYouTakeThis:
	.string "STEVEN: Được rồi, cảm ơn em.\p"
	.string "Em đã vất vả đến tận đây để giao nó.\n"
	.string "Anh phải cảm ơn em mới được.\p"
	.string "Để xem… Anh sẽ tặng em TM này.\p"
	.string "Nó chứa chiêu anh yêu thích, STEEL\n"
	.string "WING.$"

GraniteCave_StevensRoom_Text_CouldBecomeChampionLetsRegister:
	.string "STEVEN: POKéMON của em có vẻ rất tài\n"
	.string "giỏi.\p"
	.string "Nếu tiếp tục rèn luyện, một ngày nào đó\n"
	.string "em thậm chí có thể trở thành CHAMPION\l"
	.string "của POKéMON LEAGUE. Anh tin là vậy.\p"
	.string "Phải rồi, vì chúng ta đã quen nhau, hãy\n"
	.string "đăng ký nhau vào POKéNAVS nhé.\p"
	.string "… … … … … …$"

GraniteCave_StevensRoom_Text_RegisteredSteven:
	.string "Đã đăng ký STEVEN vào POKéNAV.$"

GraniteCave_StevensRoom_Text_IveGotToHurryAlong:
	.string "Giờ anh phải đi gấp rồi.$"

GraniteCave_StevensRoom_Text_OhBagIsFull:
	.string "Ồ, TÚI ĐỒ của em đầy rồi… Tiếc quá.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global GraniteCave_StevensRoom_Text_ImStevenLetterForMe
	.global GraniteCave_StevensRoom_Text_ThankYouTakeThis
	.global GraniteCave_StevensRoom_Text_CouldBecomeChampionLetsRegister
	.global GraniteCave_StevensRoom_Text_RegisteredSteven
	.global GraniteCave_StevensRoom_Text_IveGotToHurryAlong
	.global GraniteCave_StevensRoom_Text_OhBagIsFull
@ END GENERATED LOCALIZATION EXPORTS
