RustboroCity_PokemonSchool_MapScripts::
	.byte 0

RustboroCity_PokemonSchool_EventScript_Blackboard::
	lockall
	msgbox RustboroCity_PokemonSchool_Text_BlackboardListsStatusChanges, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic::
	message RustboroCity_PokemonSchool_Text_ReadWhichTopic
	waitmessage
	multichoicegrid 8, 1, MULTI_STATUS_INFO, 3, FALSE
	switch VAR_RESULT
	case 0, RustboroCity_PokemonSchool_EventScript_Poison
	case 1, RustboroCity_PokemonSchool_EventScript_Paralysis
	case 2, RustboroCity_PokemonSchool_EventScript_Sleep
	case 3, RustboroCity_PokemonSchool_EventScript_Burn
	case 4, RustboroCity_PokemonSchool_EventScript_Freeze
	case 5, RustboroCity_PokemonSchool_EventScript_ExitTopicSelect
	case MULTI_B_PRESSED, RustboroCity_PokemonSchool_EventScript_ExitTopicSelect
	end

RustboroCity_PokemonSchool_EventScript_Poison::
	msgbox RustboroCity_PokemonSchool_Text_ExplainPoison, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Paralysis::
	msgbox RustboroCity_PokemonSchool_Text_ExplainParalysis, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Sleep::
	msgbox RustboroCity_PokemonSchool_Text_ExplainSleep, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Burn::
	msgbox RustboroCity_PokemonSchool_Text_ExplainBurn, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Freeze::
	msgbox RustboroCity_PokemonSchool_Text_ExplainFreeze, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_ExitTopicSelect::
	releaseall
	end

RustboroCity_PokemonSchool_EventScript_GameboyKid1::
	msgbox RustboroCity_PokemonSchool_Text_TradingRightNow, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_GameboyKid2::
	msgbox RustboroCity_PokemonSchool_Text_AlwaysWantedSeedot, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_RichBoy::
	msgbox RustboroCity_PokemonSchool_Text_PokemontCantUseManMadeItems, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_Lass::
	msgbox RustboroCity_PokemonSchool_Text_ConfusedPokemonAttacksItself, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_SchoolKidM::
	msgbox RustboroCity_PokemonSchool_Text_PokemonHealItselfWithBerry, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_StudentNotebook::
	msgbox RustboroCity_PokemonSchool_Text_StudentsNotes, MSGBOX_SIGN
	end

RustboroCity_PokemonSchool_EventScript_Teacher::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_QUICK_CLAW, RustboroCity_PokemonSchool_EventScript_GaveQuickClaw
	call_if_eq VAR_FACING, DIR_EAST, RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsEast
	call_if_eq VAR_FACING, DIR_WEST, RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsWest
	msgbox RustboroCity_PokemonSchool_Text_StudentsWhoDontStudyGetQuickClaw, MSGBOX_DEFAULT
	giveitem ITEM_QUICK_CLAW
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	setflag FLAG_RECEIVED_QUICK_CLAW
	release
	end

RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsEast::
	applymovement VAR_LAST_TALKED, RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsEast
	waitmovement 0
	return

RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsWest::
	applymovement VAR_LAST_TALKED, RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsWest
	waitmovement 0
	return

RustboroCity_PokemonSchool_EventScript_GaveQuickClaw::
	msgbox RustboroCity_PokemonSchool_Text_ExplainQuickClaw, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	release
	end

RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsWest:
	walk_left
	walk_down
	walk_down
	walk_right
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	walk_down
	walk_in_place_faster_left
	delay_16
	delay_16
	walk_right
	delay_16
	delay_16
	delay_8
	walk_up
	walk_left
	walk_left
	walk_up
	walk_up
	walk_right
	step_end

RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsEast:
	walk_right
	walk_right
	walk_down
	walk_down
	walk_left
	walk_left
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	walk_down
	walk_in_place_faster_left
	delay_16
	delay_16
	walk_right
	delay_16
	delay_16
	delay_8
	walk_up
	walk_right
	walk_up
	walk_up
	walk_left
	walk_left
	step_end

RustboroCity_PokemonSchool_EventScript_Scott::
	lock
	faceplayer
	goto_if_set FLAG_MET_SCOTT_AFTER_OBTAINING_STONE_BADGE, RustboroCity_PokemonSchool_EventScript_ScottWatchStudents
	goto_if_set FLAG_MET_SCOTT_RUSTBORO, RustboroCity_PokemonSchool_EventScript_ScottSpokeAlready
	goto_if_set FLAG_BADGE01_GET, RustboroCity_PokemonSchool_EventScript_ScottGreetHasBadge
	msgbox RustboroCity_PokemonSchool_Text_ScottMetAlreadyCut, MSGBOX_DEFAULT
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_RUSTBORO
	release
	end

RustboroCity_PokemonSchool_EventScript_ScottSpokeAlready::
	goto_if_set FLAG_BADGE01_GET, RustboroCity_PokemonSchool_EventScript_ScottNoticeBadge
	msgbox RustboroCity_PokemonSchool_Text_StudentTalentLevelUnknown, MSGBOX_DEFAULT
	release
	end

RustboroCity_PokemonSchool_EventScript_ScottGreetHasBadge::
	msgbox RustboroCity_PokemonSchool_Text_ScottMetAlreadyStoneBadge, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_MetScottAfterBadge
	end

RustboroCity_PokemonSchool_EventScript_ScottNoticeBadge::
	msgbox RustboroCity_PokemonSchool_Text_ScottStoneBadge, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_MetScottAfterBadge
	end

RustboroCity_PokemonSchool_EventScript_MetScottAfterBadge::
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_AFTER_OBTAINING_STONE_BADGE
	release
	end

RustboroCity_PokemonSchool_EventScript_ScottWatchStudents::
	msgbox RustboroCity_PokemonSchool_Text_StudentTalentLevelUnknown, MSGBOX_DEFAULT
	release
	end

RustboroCity_PokemonSchool_Text_BlackboardListsStatusChanges:
	.string "Trên bảng đen có liệt kê các trạng thái\n"
	.string "có thể ảnh hưởng đến POKéMON trong\l"
	.string "trận đấu.$"

RustboroCity_PokemonSchool_Text_ReadWhichTopic:
	.string "Bạn muốn đọc chủ đề nào?$"

RustboroCity_PokemonSchool_Text_ExplainPoison:
	.string "Nếu một POKéMON bị trúng độc, nó sẽ liên\n"
	.string "tục mất HP.\p"
	.string "Tác dụng của độc vẫn còn sau trận đấu.\p"
	.string "HP của POKéMON bị trúng độc sẽ giảm\n"
	.string "trong lúc di chuyển.\p"
	.string "Hãy dùng ANTIDOTE để giải độc.$"

RustboroCity_PokemonSchool_Text_ExplainParalysis:
	.string "Nếu một POKéMON bị tê liệt, SPEED của nó\n"
	.string "sẽ giảm.\p"
	.string "Trong trận đấu, đôi khi nó cũng không\n"
	.string "thể hành động.\p"
	.string "Tình trạng tê liệt vẫn còn sau trận đấu.\n"
	.string "Hãy dùng PARLYZ HEAL để chữa trị.$"

RustboroCity_PokemonSchool_Text_ExplainSleep:
	.string "Nếu một POKéMON ngủ thiếp đi, nó sẽ\n"
	.string "không thể tấn công.\p"
	.string "POKéMON có thể tự tỉnh lại, nhưng nếu\n"
	.string "trận đấu kết thúc khi nó vẫn đang ngủ,\l"
	.string "trạng thái đó sẽ tiếp tục.\p"
	.string "Hãy dùng AWAKENING để đánh thức nó.$"

RustboroCity_PokemonSchool_Text_ExplainBurn:
	.string "Bỏng làm giảm sức mạnh ATTACK và liên\n"
	.string "tục rút HP của nạn nhân.\p"
	.string "Trạng thái bỏng vẫn còn sau trận đấu.\n"
	.string "Hãy dùng BURN HEAL để chữa trị.$"

RustboroCity_PokemonSchool_Text_ExplainFreeze:
	.string "Nếu một POKéMON bị đóng băng, nó sẽ\n"
	.string "hoàn toàn không thể hành động.\p"
	.string "Trạng thái đóng băng vẫn còn sau trận\n"
	.string "đấu. Hãy dùng ICE HEAL để làm tan băng.$"

RustboroCity_PokemonSchool_Text_StudentsWhoDontStudyGetQuickClaw:
	.string "Học sinh không chịu học sẽ được nếm\n"
	.string "mùi QUICK CLAW của tôi.\p"
	.string "Bạn có phải học sinh giỏi hay không sẽ\n"
	.string "thể hiện qua cách bạn sử dụng món đồ\l"
	.string "này.$"

RustboroCity_PokemonSchool_Text_ExplainQuickClaw:
	.string "POKéMON giữ QUICK CLAW đôi khi sẽ tăng\n"
	.string "tốc và ra đòn trước đối thủ.\p"
	.string "Còn có nhiều món đồ khác dành cho\n"
	.string "POKéMON cầm giữ.\p"
	.string "Chỉ riêng chúng thôi cũng đã cho bạn\n"
	.string "rất nhiều chủ đề để học rồi!$"

RustboroCity_PokemonSchool_Text_TradingRightNow:
	.string "Tớ đang trao đổi POKéMON với bạn mình.$"

RustboroCity_PokemonSchool_Text_AlwaysWantedSeedot:
	.string "Tớ luôn muốn có một SEEDOT, và cuối\n"
	.string "cùng cũng sắp nhận được rồi!$"

RustboroCity_PokemonSchool_Text_PokemontCantUseManMadeItems:
	.string "POKéMON có thể giữ đồ, nhưng chúng\n"
	.string "không biết phải làm gì với những món do\l"
	.string "con người chế tạo như POTION và\l"
	.string "ANTIDOTE.$"

RustboroCity_PokemonSchool_Text_ConfusedPokemonAttacksItself:
	.string "Bạn biết một số chiêu của POKéMON có\n"
	.string "thể khiến POKéMON rơi vào trạng thái\l"
	.string "hoang mang chứ?\p"
	.string "POKéMON đang hoang mang đôi khi sẽ vô\n"
	.string "tình tự tấn công chính mình.\p"
	.string "Nhưng khi rời khỏi trận đấu, nó sẽ trở\n"
	.string "lại bình thường.$"

RustboroCity_PokemonSchool_Text_PokemonHealItselfWithBerry:
	.string "POKéMON giữ BERRY sẽ tự hồi phục...\p"
	.string "Có rất nhiều loại đồ mà POKéMON có thể\n"
	.string "cầm giữ...\p"
	.string "Trời ạ, ghi chép lại thật vất vả...$"

RustboroCity_PokemonSchool_Text_StudentsNotes:
	.string "Đây là vở ghi chép của học sinh này...\p"
	.string "Phải dùng POKé BALLS để bắt POKéMON.\p"
	.string "Một HLV có thể mang theo tối đa\n"
	.string "sáu POKéMON.\p"
	.string "HLV là người bắt, nuôi dưỡng và\n"
	.string "cùng POKéMON chiến đấu.\p"
	.string "Nhiệm vụ của HLV là đánh bại những\n"
	.string "HLV mạnh đang chờ người thách\l"
	.string "đấu tại các POKéMON GYMS.$"

RustboroCity_PokemonSchool_Text_ScottMetAlreadyCut:
	.string "Xin chào? Chúng ta từng gặp nhau rồi\n"
	.string "phải không? Hình như là ở PETALBURG\l"
	.string "CITY.\p"
	.string "Để tôi tự giới thiệu. Tôi tên SCOTT.\p"
	.string "Tôi đã đi khắp nơi để tìm kiếm những\n"
	.string "HLV xuất sắc.\p"
	.string "Nói chính xác hơn, tôi đang tìm các\n"
	.string "chuyên gia chiến đấu POKéMON.\p"
	.string "Vậy điều gì đưa bạn đến SCHOOL này?\n"
	.string "Bạn cũng là HLV sao?\p"
	.string "Việc đầu tiên bạn nên làm là cho một\n"
	.string "POKéMON học chiêu CUT.\p"
	.string "Nếu tôi nhớ không nhầm, có người trong\n"
	.string "thành phố này sở hữu CUT.$"

RustboroCity_PokemonSchool_Text_StudentTalentLevelUnknown:
	.string "SCOTT: Hừm...\p"
	.string "Chưa thể biết trình độ tài năng của học\n"
	.string "sinh ở đây đến đâu. Nhưng họ có tiềm\l"
	.string "năng.$"

RustboroCity_PokemonSchool_Text_ScottStoneBadge:
	.string "SCOTT: Ồ, cái gì thế?\p"
	.string "Đó là STONE BADGE phải không? Tôi phải\n"
	.string "nói là khá ấn tượng đấy.\p"
	.string "Nhưng bạn biết không, tôi rất muốn tận\n"
	.string "mắt xem bạn chiến đấu.\p"
	.string "Chỉ nhìn một LEAGUE BADGE thì khó biết\n"
	.string "bạn là HLV như thế nào.$"

RustboroCity_PokemonSchool_Text_ScottMetAlreadyStoneBadge:
	.string "Xin chào? Chúng ta từng gặp nhau rồi\n"
	.string "phải không? Hình như là ở PETALBURG\l"
	.string "CITY.\p"
	.string "Để tôi tự giới thiệu. Tôi tên SCOTT.\p"
	.string "Tôi đã đi khắp nơi để tìm kiếm những\n"
	.string "HLV xuất sắc.\p"
	.string "Nói chính xác hơn, tôi đang tìm các\n"
	.string "chuyên gia chiến đấu POKéMON.\p"
	.string "Ồ, cái gì thế? Đó là STONE BADGE phải\n"
	.string "không?\p"
	.string "Với một HLV mới vào nghề như bạn,\n"
	.string "tôi phải nói là khá ấn tượng đấy.\p"
	.string "Nhưng bạn biết không, tôi rất muốn tận\n"
	.string "mắt xem bạn chiến đấu.\p"
	.string "Chỉ nhìn một LEAGUE BADGE thì khó biết\n"
	.string "bạn là HLV như thế nào.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global RustboroCity_PokemonSchool_Text_BlackboardListsStatusChanges
	.global RustboroCity_PokemonSchool_Text_ReadWhichTopic
	.global RustboroCity_PokemonSchool_Text_ExplainPoison
	.global RustboroCity_PokemonSchool_Text_ExplainParalysis
	.global RustboroCity_PokemonSchool_Text_ExplainSleep
	.global RustboroCity_PokemonSchool_Text_ExplainBurn
	.global RustboroCity_PokemonSchool_Text_ExplainFreeze
	.global RustboroCity_PokemonSchool_Text_StudentsWhoDontStudyGetQuickClaw
	.global RustboroCity_PokemonSchool_Text_ExplainQuickClaw
	.global RustboroCity_PokemonSchool_Text_TradingRightNow
	.global RustboroCity_PokemonSchool_Text_AlwaysWantedSeedot
	.global RustboroCity_PokemonSchool_Text_PokemontCantUseManMadeItems
	.global RustboroCity_PokemonSchool_Text_ConfusedPokemonAttacksItself
	.global RustboroCity_PokemonSchool_Text_PokemonHealItselfWithBerry
	.global RustboroCity_PokemonSchool_Text_StudentsNotes
	.global RustboroCity_PokemonSchool_Text_ScottMetAlreadyCut
	.global RustboroCity_PokemonSchool_Text_StudentTalentLevelUnknown
	.global RustboroCity_PokemonSchool_Text_ScottStoneBadge
	.global RustboroCity_PokemonSchool_Text_ScottMetAlreadyStoneBadge
@ END GENERATED LOCALIZATION EXPORTS
