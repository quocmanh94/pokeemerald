RustboroCity_DevonCorp_3F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_DevonCorp_3F_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, RustboroCity_DevonCorp_3F_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RustboroCity_DevonCorp_3F_OnFrame
	.byte 0

RustboroCity_DevonCorp_3F_OnTransition:
	call_if_eq VAR_DEVON_CORP_3F_STATE, 0, RustboroCity_DevonCorp_3F_EventScript_SetEmployeePos
	end

RustboroCity_DevonCorp_3F_EventScript_SetEmployeePos::
	setobjectxyperm LOCALID_DEVON_CORP_3F_EMPLOYEE, 3, 2
	setobjectmovementtype LOCALID_DEVON_CORP_3F_EMPLOYEE, MOVEMENT_TYPE_FACE_LEFT
	return

RustboroCity_DevonCorp_3F_OnWarp:
	map_script_2 VAR_DEVON_CORP_3F_STATE, 0, RustboroCity_DevonCorp_3F_EventScript_PlayerFaceEast
	.2byte 0

RustboroCity_DevonCorp_3F_EventScript_PlayerFaceEast::
	turnobject LOCALID_PLAYER, DIR_EAST
	end

RustboroCity_DevonCorp_3F_OnFrame:
	map_script_2 VAR_DEVON_CORP_3F_STATE, 0, RustboroCity_DevonCorp_3F_EventScript_MeetPresident
	.2byte 0

RustboroCity_DevonCorp_3F_EventScript_MeetPresident::
	lockall
	msgbox RustboroCity_DevonCorp_3F_Text_ThisIs3rdFloorWaitHere, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DEVON_CORP_3F_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_EmployeeWalkOffscreen
	waitmovement 0
	delay 80
	applymovement LOCALID_DEVON_CORP_3F_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_EmployeeReturnToPlayer
	waitmovement 0
	msgbox RustboroCity_DevonCorp_3F_Text_WordWithPresidentComeWithMe, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_FOLLOW_ME, FALSE
	applymovement LOCALID_DEVON_CORP_3F_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_LeadPlayerToPresident
	applymovement LOCALID_PLAYER, RustboroCity_DevonCorp_3F_Movement_PlayerFollowToPresident
	waitmovement 0
	msgbox RustboroCity_DevonCorp_3F_Text_PleaseGoAhead, MSGBOX_DEFAULT
	closemessage
	fadedefaultbgm
	applymovement LOCALID_DEVON_CORP_3F_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_EmployeeFaceDesk
	applymovement LOCALID_PLAYER, RustboroCity_DevonCorp_3F_Movement_PlayerApproachDesk
	waitmovement 0
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneIHaveFavor, MSGBOX_DEFAULT
	giveitem ITEM_LETTER
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneWantYouToHaveThis, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message RustboroCity_DevonCorp_3F_Text_ReceivedPokenav
	waitfanfare
	setflag FLAG_SYS_POKENAV_GET
	setflag FLAG_RECEIVED_POKENAV
	setflag FLAG_HIDE_RUSTBORO_CITY_POKEMON_SCHOOL_SCOTT
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneExplainPokenavRestUp, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneGoWithCautionAndCare, MSGBOX_DEFAULT
	setflag FLAG_HIDE_ROUTE_116_WANDAS_BOYFRIEND
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_WANDAS_BOYFRIEND
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_WANDA
	clearflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	clearflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	setvar VAR_BRINEY_LOCATION, 1
	clearflag FLAG_HIDE_RUSTBORO_CITY_RIVAL
	setvar VAR_DEVON_CORP_3F_STATE, 1
	setvar VAR_RUSTBORO_CITY_STATE, 6
	releaseall
	end

RustboroCity_DevonCorp_3F_Movement_Unused:
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_left
	step_end

RustboroCity_DevonCorp_3F_Movement_LeadPlayerToPresident:
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_left
	step_end

RustboroCity_DevonCorp_3F_Movement_EmployeeFaceDesk:
	delay_16
	walk_in_place_faster_down
	step_end

RustboroCity_DevonCorp_3F_Movement_EmployeeWalkOffscreen:
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

RustboroCity_DevonCorp_3F_Movement_EmployeeReturnToPlayer:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_left
	walk_left
	walk_left
	step_end

RustboroCity_DevonCorp_3F_Movement_PlayerFollowToPresident:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

RustboroCity_DevonCorp_3F_Movement_PlayerApproachDesk:
	delay_16
	delay_16
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

RustboroCity_DevonCorp_3F_EventScript_MrStone::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_EXP_SHARE, RustboroCity_DevonCorp_3F_EventScript_MrStoneAfterFavor
	goto_if_set FLAG_DELIVERED_STEVEN_LETTER, RustboroCity_DevonCorp_3F_EventScript_GiveExpShare
	msgbox RustboroCity_DevonCorp_3F_Text_CountingOnYou, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_DevonCorp_3F_EventScript_GiveExpShare::
	msgbox RustboroCity_DevonCorp_3F_Text_ThankYouForDeliveringLetter, MSGBOX_DEFAULT
	giveitem ITEM_EXP_SHARE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_EXP_SHARE
	msgbox RustboroCity_DevonCorp_3F_Text_ExplainExpShare, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_DevonCorp_3F_EventScript_MrStoneAfterFavor::
	msgbox RustboroCity_DevonCorp_3F_Text_NotFamiliarWithTrends, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_DevonCorp_3F_EventScript_Employee::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_REPEAT_BALL, RustboroCity_DevonCorp_3F_EventScript_EmployeeBalls
	msgbox RustboroCity_DevonCorp_3F_Text_VisitCaptSternShipyard, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_3F_EventScript_EmployeeBalls::
	msgbox RustboroCity_DevonCorp_3F_Text_RepeatAndTimerHugelyPopular, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_3F_EventScript_RareRocksDisplay::
	msgbox RustboroCity_DevonCorp_3F_Text_RareRocksDisplay, MSGBOX_SIGN
	end

RustboroCity_DevonCorp_3F_Text_MrStoneIHaveFavor:
	.string "Tôi là MR. STONE, PRESIDENT của DEVON\n"
	.string "CORPORATION.\p"
	.string "Tôi vừa nghe tin về cháu!\p"
	.string "Cháu đã cứu nhân viên của chúng tôi\n"
	.string "không chỉ một mà đến hai lần!\p"
	.string "Tôi có một việc muốn nhờ một người\n"
	.string "tuyệt vời như cháu.\p"
	.string "Tôi được biết cháu đang giao một kiện\n"
	.string "hàng đến SHIPYARD ở SLATEPORT.\p"
	.string "Trên đường đi, cháu có thể ghé qua\n"
	.string "DEWFORD TOWN không?\p"
	.string "Tôi mong cháu chuyển một LETTER cho\n"
	.string "STEVEN ở DEWFORD.$"

RustboroCity_DevonCorp_3F_Text_MrStoneWantYouToHaveThis:
	.string "MR. STONE: Cháu nên biết rằng tôi là một\n"
	.string "PRESIDENT tài giỏi.\p"
	.string "Vì thế, tôi không đời nào keo kiệt đến\n"
	.string "mức nhờ vả mà không đáp lại.\p"
	.string "Cho nên tôi muốn cháu nhận lấy thứ này!$"

RustboroCity_DevonCorp_3F_Text_ReceivedPokenav:
	.string "{PLAYER} đã nhận được một POKéNAV.$"

RustboroCity_DevonCorp_3F_Text_MrStoneExplainPokenavRestUp:
	.string "MR. STONE: Thiết bị đó...\p"
	.string "Nó là POKéMON NAVIGATOR, gọi tắt là\n"
	.string "POKéNAV.\p"
	.string "Đây là công cụ không thể thiếu với mọi\n"
	.string "HLV đang phiêu lưu.\p"
	.string "Nó có bản đồ vùng HOENN.\p"
	.string "Cháu có thể dễ dàng kiểm tra vị trí của\n"
	.string "DEWFORD và SLATEPORT!\p"
	.string "Nhân tiện, tôi nghe nói những kẻ tội\n"
	.string "phạm nham hiểm, hình như là MAGMA và\l"
	.string "AQUA, đang gây rắc rối khắp nơi.\p"
	.string "Tôi nghĩ tốt nhất cháu nên nghỉ ngơi\n"
	.string "trước khi tiếp tục lên đường.$"

RustboroCity_DevonCorp_3F_Text_MrStoneGoWithCautionAndCare:
	.string "MR. STONE: Vậy nhé, {PLAYER}{KUN}, hãy\n"
	.string "luôn thận trọng và cẩn thận!$"

RustboroCity_DevonCorp_3F_Text_CountingOnYou:
	.string "MR. STONE: Tôi trông cậy vào cháu!$"

RustboroCity_DevonCorp_3F_Text_ThankYouForDeliveringLetter:
	.string "MR. STONE: Cháu đã giao LETTER của tôi\n"
	.string "rồi sao? Cảm ơn cháu rất nhiều!\p"
	.string "Đây là cách tôi cảm ơn cháu. Nó hẳn sẽ\n"
	.string "giúp ích cho một HLV như cháu.$"

RustboroCity_DevonCorp_3F_Text_ExplainExpShare:
	.string "MR. STONE: POKéMON mang EXP. SHARE sẽ\n"
	.string "nhận được một phần EXP Points từ trận\l"
	.string "đấu.\p"
	.string "Nó vẫn nhận được EXP Points ngay cả\n"
	.string "khi không trực tiếp chiến đấu.\p"
	.string "Theo tôi, EXP. SHARE rất hữu ích khi rèn\n"
	.string "luyện POKéMON yếu.$"

RustboroCity_DevonCorp_3F_Text_NotFamiliarWithTrends:
	.string "MR. STONE: Từ thời trẻ, tôi đã vùi mình\n"
	.string "vào công việc.\p"
	.string "Vì vậy, tôi không hiểu rõ các trào lưu\n"
	.string "và những thứ tương tự.\p"
	.string "Nhưng có phải giới trẻ đều muốn trở\n"
	.string "thành HLV trong POKéMON LEAGUE\l"
	.string "không?$"

RustboroCity_DevonCorp_3F_Text_ThisIs3rdFloorWaitHere:
	.string "Đây là tầng ba của DEVON CORPORATION.\p"
	.string "PRESIDENT's OFFICE nằm trên tầng này.\p"
	.string "Dù sao, tôi thật sự không biết phải cảm\n"
	.string "ơn bạn thế nào vì những việc bạn đã\l"
	.string "làm.\p"
	.string "Ờ... Nhân tiện, kiện hàng bạn lấy lại cho\n"
	.string "chúng tôi...\p"
	.string "Tôi có thể nhờ bạn giao nó đến\n"
	.string "SHIPYARD ở SLATEPORT không?\p"
	.string "Sẽ rất tệ nếu bọn cướp lại tìm cách lấy\n"
	.string "nó.\p"
	.string "Ờ... Hehehe, vậy, ờ, tôi có thể trông cậy\n"
	.string "vào bạn chứ?\p"
	.string "Ồ, phải rồi. Bạn có thể chờ ở đây một lát\n"
	.string "không?$"

RustboroCity_DevonCorp_3F_Text_WordWithPresidentComeWithMe:
	.string "Ngài PRESIDENT của chúng tôi muốn nói\n"
	.string "chuyện với bạn.\p"
	.string "Xin hãy đi cùng tôi.$"

RustboroCity_DevonCorp_3F_Text_PleaseGoAhead:
	.string "Xin mời đi tiếp.$"

RustboroCity_DevonCorp_3F_Text_VisitCaptSternShipyard:
	.string "Nếu đến SHIPYARD ở SLATEPORT, bạn nên\n"
	.string "ghé gặp CAPT. STERN.$"

RustboroCity_DevonCorp_3F_Text_RepeatAndTimerHugelyPopular:
	.string "Hai sản phẩm mới của DEVON là REPEAT\n"
	.string "BALL và TIMER BALL đã trở nên cực kỳ\l"
	.string "phổ biến với các HLV.$"

RustboroCity_DevonCorp_3F_Text_RareRocksDisplay:
	.string "Đây là bộ sưu tập đá quý hiếm do\n"
	.string "PRESIDENT sưu tầm.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global RustboroCity_DevonCorp_3F_Text_MrStoneIHaveFavor
	.global RustboroCity_DevonCorp_3F_Text_MrStoneWantYouToHaveThis
	.global RustboroCity_DevonCorp_3F_Text_ReceivedPokenav
	.global RustboroCity_DevonCorp_3F_Text_MrStoneExplainPokenavRestUp
	.global RustboroCity_DevonCorp_3F_Text_MrStoneGoWithCautionAndCare
	.global RustboroCity_DevonCorp_3F_Text_CountingOnYou
	.global RustboroCity_DevonCorp_3F_Text_ThankYouForDeliveringLetter
	.global RustboroCity_DevonCorp_3F_Text_ExplainExpShare
	.global RustboroCity_DevonCorp_3F_Text_NotFamiliarWithTrends
	.global RustboroCity_DevonCorp_3F_Text_ThisIs3rdFloorWaitHere
	.global RustboroCity_DevonCorp_3F_Text_WordWithPresidentComeWithMe
	.global RustboroCity_DevonCorp_3F_Text_PleaseGoAhead
	.global RustboroCity_DevonCorp_3F_Text_VisitCaptSternShipyard
	.global RustboroCity_DevonCorp_3F_Text_RepeatAndTimerHugelyPopular
	.global RustboroCity_DevonCorp_3F_Text_RareRocksDisplay
@ END GENERATED LOCALIZATION EXPORTS
