BattleFrontier_Lounge7_MapScripts::
	.byte 0

BattleFrontier_Lounge7_EventScript_LeftMoveTutor::
	lock
	faceplayer
	setvar VAR_TEMP_C, SCROLL_MULTI_BF_MOVE_TUTOR_1
	goto_if_set FLAG_MET_FRONTIER_BEAUTY_MOVE_TUTOR, BattleFrontier_Lounge7_EventScript_AlreadyMetLeftTutor
	msgbox BattleFrontier_Lounge7_Text_LeftTutorIntro, MSGBOX_DEFAULT
	setflag FLAG_MET_FRONTIER_BEAUTY_MOVE_TUTOR
	goto BattleFrontier_Lounge7_EventScript_ChooseLeftTutorMove
	end

BattleFrontier_Lounge7_EventScript_AlreadyMetLeftTutor::
	msgbox BattleFrontier_Lounge7_Text_LeftTutorWelcomeBack, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge7_EventScript_ChooseLeftTutorMove
	end

BattleFrontier_Lounge7_EventScript_ChooseLeftTutorMove::
	message BattleFrontier_Lounge7_Text_TeachWhichMove
	waitmessage
	special ShowBattlePointsWindow
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 0
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_1
	setvar VAR_0x8006, 0
	special ShowScrollableMultichoice
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_Softboiled
	case 1, BattleFrontier_Lounge7_EventScript_SeismicToss
	case 2, BattleFrontier_Lounge7_EventScript_DreamEater
	case 3, BattleFrontier_Lounge7_EventScript_MegaPunch
	case 4, BattleFrontier_Lounge7_EventScript_MegaKick
	case 5, BattleFrontier_Lounge7_EventScript_BodySlam
	case 6, BattleFrontier_Lounge7_EventScript_RockSlide
	case 7, BattleFrontier_Lounge7_EventScript_Counter
	case 8, BattleFrontier_Lounge7_EventScript_ThunderWave
	case 9, BattleFrontier_Lounge7_EventScript_SwordsDance
	case 10, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	end

BattleFrontier_Lounge7_EventScript_ChooseNewLeftTutorMove::
	message BattleFrontier_Lounge7_Text_TeachWhichMove
	waitmessage
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 0
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_1
	setvar VAR_0x8006, 1
	special ShowScrollableMultichoice
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_Softboiled
	case 1, BattleFrontier_Lounge7_EventScript_SeismicToss
	case 2, BattleFrontier_Lounge7_EventScript_DreamEater
	case 3, BattleFrontier_Lounge7_EventScript_MegaPunch
	case 4, BattleFrontier_Lounge7_EventScript_MegaKick
	case 5, BattleFrontier_Lounge7_EventScript_BodySlam
	case 6, BattleFrontier_Lounge7_EventScript_RockSlide
	case 7, BattleFrontier_Lounge7_EventScript_Counter
	case 8, BattleFrontier_Lounge7_EventScript_ThunderWave
	case 9, BattleFrontier_Lounge7_EventScript_SwordsDance
	case 10, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	end

BattleFrontier_Lounge7_EventScript_Softboiled::
	setvar VAR_0x8008, 16
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_SeismicToss::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_DreamEater::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_MegaPunch::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_MegaKick::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_BodySlam::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_RockSlide::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Counter::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_ThunderWave::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_SwordsDance::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_RightMoveTutor::
	lock
	faceplayer
	setvar VAR_TEMP_C, SCROLL_MULTI_BF_MOVE_TUTOR_2
	goto_if_set FLAG_MET_FRONTIER_SWIMMER_MOVE_TUTOR, BattleFrontier_Lounge7_EventScript_AlreadyMetRightTutor
	msgbox BattleFrontier_Lounge7_Text_RightTutorIntro, MSGBOX_DEFAULT
	setflag FLAG_MET_FRONTIER_SWIMMER_MOVE_TUTOR
	goto BattleFrontier_Lounge7_EventScript_ChooseRightTutorMove
	end

BattleFrontier_Lounge7_EventScript_AlreadyMetRightTutor::
	msgbox BattleFrontier_Lounge7_Text_RightTutorWelcomeBack, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge7_EventScript_ChooseRightTutorMove
	end

BattleFrontier_Lounge7_EventScript_ChooseRightTutorMove::
	message BattleFrontier_Lounge7_Text_TeachWhichMove
	waitmessage
	special ShowBattlePointsWindow
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 1
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_2
	setvar VAR_0x8006, 0
	special ShowScrollableMultichoice
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_DefenseCurl
	case 1, BattleFrontier_Lounge7_EventScript_Snore
	case 2, BattleFrontier_Lounge7_EventScript_MudSlap
	case 3, BattleFrontier_Lounge7_EventScript_Swift
	case 4, BattleFrontier_Lounge7_EventScript_IcyWind
	case 5, BattleFrontier_Lounge7_EventScript_Endure
	case 6, BattleFrontier_Lounge7_EventScript_PsychUp
	case 7, BattleFrontier_Lounge7_EventScript_IcePunch
	case 8, BattleFrontier_Lounge7_EventScript_ThunderPunch
	case 9, BattleFrontier_Lounge7_EventScript_FirePunch
	case 10, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	end

BattleFrontier_Lounge7_EventScript_ChooseNewRightTutorMove::
	message BattleFrontier_Lounge7_Text_TeachWhichMove
	waitmessage
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 1
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_2
	setvar VAR_0x8006, 1
	special ShowScrollableMultichoice
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_DefenseCurl
	case 1, BattleFrontier_Lounge7_EventScript_Snore
	case 2, BattleFrontier_Lounge7_EventScript_MudSlap
	case 3, BattleFrontier_Lounge7_EventScript_Swift
	case 4, BattleFrontier_Lounge7_EventScript_IcyWind
	case 5, BattleFrontier_Lounge7_EventScript_Endure
	case 6, BattleFrontier_Lounge7_EventScript_PsychUp
	case 7, BattleFrontier_Lounge7_EventScript_IcePunch
	case 8, BattleFrontier_Lounge7_EventScript_ThunderPunch
	case 9, BattleFrontier_Lounge7_EventScript_FirePunch
	case 10, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	end

BattleFrontier_Lounge7_EventScript_DefenseCurl::
	setvar VAR_0x8008, 16
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Snore::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_MudSlap::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Swift::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_IcyWind::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Endure::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_PsychUp::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_IcePunch::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_ThunderPunch::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_FirePunch::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect::
	special CloseBattleFrontierTutorWindow
	special CloseBattlePointsWindow
	msgbox BattleFrontier_Lounge7_Text_YouDontWantTo, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge7_EventScript_CancelChooseMon::
	msgbox BattleFrontier_Lounge7_Text_YouDontWantTo, MSGBOX_DEFAULT
	release
	end

@ VAR_0x8008 is the price
@ VAR_TEMP_C is the scroll multichoice ID
@ VAR_TEMP_FRONTIER_TUTOR_SELECTION is the move selection
@ VAR_TEMP_FRONTIER_TUTOR_ID is which move tutor was spoken to
BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection::
	copyvar VAR_0x8004, VAR_TEMP_FRONTIER_TUTOR_SELECTION
	copyvar VAR_0x8005, VAR_TEMP_FRONTIER_TUTOR_ID
	special BufferBattleFrontierTutorMoveName
	buffernumberstring STR_VAR_2, VAR_0x8008
	copyvar VAR_0x8004, VAR_TEMP_C
	msgbox BattleFrontier_Lounge7_Text_MoveWillBeXBattlePoints, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge7_EventScript_ChooseNewMove
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
	goto_if_ge VAR_TEMP_1, VAR_0x8008, BattleFrontier_Lounge7_EventScript_TeachTutorMove
	msgbox BattleFrontier_Lounge7_Text_HaventGotEnoughPoints, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge7_EventScript_ChooseNewMove
	end

BattleFrontier_Lounge7_EventScript_TeachTutorMove::
	msgbox BattleFrontier_Lounge7_Text_TeachMoveToWhichMon, MSGBOX_DEFAULT
	special GetBattleFrontierTutorMoveIndex
	fadescreen FADE_TO_BLACK
	special CloseBattlePointsWindow
	special CloseBattleFrontierTutorWindow
	special ChooseMonForMoveTutor
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_Lounge7_EventScript_CancelChooseMon
	msgbox BattleFrontier_Lounge7_Text_IllTakeBattlePoints, MSGBOX_DEFAULT
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	release
	end

BattleFrontier_Lounge7_EventScript_ChooseNewMove::
	goto_if_eq VAR_TEMP_FRONTIER_TUTOR_ID, 0, BattleFrontier_Lounge7_EventScript_ChooseNewLeftTutorMove
	goto BattleFrontier_Lounge7_EventScript_ChooseNewRightTutorMove
	end

BattleFrontier_Lounge7_EventScript_Sailor::
	msgbox BattleFrontier_Lounge7_Text_ThinkLadiesDontGetAlong, MSGBOX_NPC
	end

BattleFrontier_Lounge7_EventScript_Gentleman::
	msgbox BattleFrontier_Lounge7_Text_LadiesWereStrongAndBeautiful, MSGBOX_NPC
	end

BattleFrontier_Lounge7_Text_LeftTutorIntro:
	.string "Bwahaha!\p"
	.string "Nhìn bà bây giờ chắc cháu không thể\n"
	.string "ngờ, nhưng trước kia bà từng là một\l"
	.string "HLV cực kỳ mạnh.\p"
	.string "Bà từng nổi danh là BEAUTY mạnh nhất\n"
	.string "vùng đấy!\p"
	.string ". . . . . .\p"
	.string "Sao nào? Cháu không tin bà à.\p"
	.string "Bà không giống mụ chỉ giỏi ba hoa bên\n"
	.string "kia đâu. Bà có tài thật sự!\p"
	.string "Để bà chứng minh cho cháu xem. Bà có\n"
	.string "thể dạy POKéMON của cháu những chiêu\l"
	.string "thức vừa đặc biệt vừa dễ thương.\p"
	.string "Nhưng bà không dạy miễn phí đâu. Cháu\n"
	.string "trả một ít Battle Points cho những\l"
	.string "chiêu bà dạy nhé?$"

BattleFrontier_Lounge7_Text_LeftTutorWelcomeBack:
	.string "Bwahaha!\p"
	.string "Cháu quay lại để học những chiêu thức\n"
	.string "POKéMON vừa đặc biệt vừa dễ thương\l"
	.string "sao?$"

BattleFrontier_Lounge7_Text_TeachWhichMove:
	.string "Được, được, xem đây! Bà nên dạy chiêu\n"
	.string "nào?$"

BattleFrontier_Lounge7_Text_MoveWillBeXBattlePoints:
	.string "Chiêu {STR_VAR_1}, phải không?\n"
	.string "Chiêu đó sẽ tốn {STR_VAR_2}\l"
	.string "Battle Points, được chứ?$"

BattleFrontier_Lounge7_Text_TeachMoveToWhichMon:
	.string "Được, được, giờ hãy chọn POKéMON mà\n"
	.string "bà sẽ dạy chiêu này.$"

BattleFrontier_Lounge7_Text_HaventGotEnoughPoints:
	.string "Cái gì cơ? Cháu không có đủ Battle\n"
	.string "Points!$"

BattleFrontier_Lounge7_Text_IllTakeBattlePoints:
	.string "Giờ cháu thấy bà tài giỏi thế nào rồi\n"
	.string "chứ? Bà xin nhận Battle Points nhé!$"

BattleFrontier_Lounge7_Text_YouDontWantTo:
	.string "Gì cơ? Cháu không muốn à?\p"
	.string "Nếu muốn chứng kiến tài nghệ của bà, cứ\n"
	.string "đến gặp bà bất cứ lúc nào!$"

BattleFrontier_Lounge7_Text_RightTutorIntro:
	.string "Hihihi!\p"
	.string "Giờ nhìn bà có lẽ khó mà nhận ra, nhưng\n"
	.string "trước kia bà từng là một HLV xuất\l"
	.string "sắc.\p"
	.string "Bà từng nổi danh là SWIMMER bất khả\n"
	.string "chiến bại nhất vùng đấy!\p"
	.string ". . . . . .\p"
	.string "Sao thế? Cháu không tin bà à.\p"
	.string "Bà không giống mụ ngốc nghếch bên kia\n"
	.string "đâu. Bà có kinh nghiệm thực sự!\p"
	.string "Bà có thể chứng minh cho cháu xem. Bà\n"
	.string "có thể dạy POKéMON của cháu những\l"
	.string "chiêu thức vừa mạnh mẽ vừa đẹp mắt.\p"
	.string "Nhưng bà không dạy miễn phí đâu. Cháu\n"
	.string "trả một ít Battle Points cho những\l"
	.string "chiêu bà dạy nhé?$"

BattleFrontier_Lounge7_Text_RightTutorWelcomeBack:
	.string "Hihihi!\p"
	.string "Cháu đến để học những chiêu thức\n"
	.string "POKéMON vừa mạnh mẽ vừa đẹp mắt sao?$"

BattleFrontier_Lounge7_Text_ThinkLadiesDontGetAlong:
	.string "Thấy hai bà ấy cứ chê bai nhau, có lẽ\n"
	.string "bạn nghĩ họ không hòa thuận.\p"
	.string "Nhưng nếu thật sự như vậy, họ đâu ở\n"
	.string "ngoài này cùng nhau, đúng không?$"

BattleFrontier_Lounge7_Text_LadiesWereStrongAndBeautiful:
	.string "Khi tôi còn là một YOUNGSTER bé tí, hai\n"
	.string "bà ấy vừa mạnh mẽ vừa xinh đẹp.\p"
	.string "Họ là thần tượng của HLV chúng\n"
	.string "tôi.\p"
	.string "Ngay cả bây giờ, tuổi tác vẫn chưa làm\n"
	.string "tài nghệ của họ mai một.\p"
	.string "Thật ra, các chiêu thức POKéMON của họ\n"
	.string "còn trở nên điêu luyện hơn.\p"
	.string "Nhưng vì lý do nào đó, tôi không khỏi\n"
	.string "nghĩ rằng...\p"
	.string "Thời gian thật tàn nhẫn.$"

BattleFrontier_Lounge7_Text_SoftboiledDesc::
	.string "Hồi phục tối đa một nửa lượng HP tối đa\n"
	.string "của người dùng.$"

BattleFrontier_Lounge7_Text_SeismicTossDesc::
	.string "Gây sát thương đúng bằng cấp độ của\n"
	.string "người dùng.$"

BattleFrontier_Lounge7_Text_DreamEaterDesc::
	.string "Hồi phục một nửa lượng sát thương gây\n"
	.string "ra cho đối thủ đang ngủ.$"

BattleFrontier_Lounge7_Text_MegaPunchDesc::
	.string "Cú đấm mạnh được tung ra với sức mạnh\n"
	.string "kinh người.$"

BattleFrontier_Lounge7_Text_MegaKickDesc::
	.string "Cú đá cực mạnh được tung ra với lực\n"
	.string "dữ dội.$"

BattleFrontier_Lounge7_Text_BodySlamDesc::
	.string "Cú đè bằng toàn thân có thể gây tê liệt.$"

BattleFrontier_Lounge7_Text_RockSlideDesc::
	.string "Ném những tảng đá lớn. Có thể khiến đối\n"
	.string "thủ chùn bước.$"

BattleFrontier_Lounge7_Text_CounterDesc::
	.string "Đáp trả mọi đòn đánh vật lý với sức\n"
	.string "mạnh gấp đôi.$"

BattleFrontier_Lounge7_Text_ThunderWaveDesc::
	.string "Luồng điện yếu làm đối thủ tê liệt.$"

BattleFrontier_Lounge7_Text_SwordsDanceDesc::
	.string "Điệu múa chiến đấu làm ATTACK tăng\n"
	.string "mạnh.$"

BattleFrontier_Lounge7_Text_DefenseCurlDesc::
	.string "Cuộn tròn để che giấu điểm yếu và tăng\n"
	.string "DEFENSE.$"

BattleFrontier_Lounge7_Text_SnoreDesc::
	.string "Đòn tấn công bằng tiếng ngáy lớn, chỉ\n"
	.string "dùng được khi đang ngủ.$"

BattleFrontier_Lounge7_Text_MudSlapDesc::
	.string "Hất bùn vào mặt đối thủ để giảm độ\n"
	.string "chính xác.$"

BattleFrontier_Lounge7_Text_SwiftDesc::
	.string "Bắn ra những tia sáng hình ngôi sao\n"
	.string "không bao giờ trượt.$"

BattleFrontier_Lounge7_Text_IcyWindDesc::
	.string "Đòn tấn công lạnh buốt làm giảm SPEED\n"
	.string "của đối thủ.$"

BattleFrontier_Lounge7_Text_EndureDesc::
	.string "Chịu đựng mọi đòn tấn công trong 1\n"
	.string "lượt và còn lại 1 HP.$"

BattleFrontier_Lounge7_Text_PsychUpDesc::
	.string "Sao chép các hiệu ứng của đối thủ sang\n"
	.string "người dùng.$"

BattleFrontier_Lounge7_Text_IcePunchDesc::
	.string "Một cú đấm băng giá có thể đóng băng\n"
	.string "đối thủ.$"

BattleFrontier_Lounge7_Text_ThunderPunchDesc::
	.string "Một cú đấm tích điện có thể làm đối thủ\n"
	.string "tê liệt.$"

BattleFrontier_Lounge7_Text_FirePunchDesc::
	.string "Một cú đấm rực lửa có thể thiêu bỏng\n"
	.string "đối thủ.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global BattleFrontier_Lounge7_Text_LeftTutorIntro
	.global BattleFrontier_Lounge7_Text_LeftTutorWelcomeBack
	.global BattleFrontier_Lounge7_Text_TeachWhichMove
	.global BattleFrontier_Lounge7_Text_MoveWillBeXBattlePoints
	.global BattleFrontier_Lounge7_Text_TeachMoveToWhichMon
	.global BattleFrontier_Lounge7_Text_HaventGotEnoughPoints
	.global BattleFrontier_Lounge7_Text_IllTakeBattlePoints
	.global BattleFrontier_Lounge7_Text_YouDontWantTo
	.global BattleFrontier_Lounge7_Text_RightTutorIntro
	.global BattleFrontier_Lounge7_Text_RightTutorWelcomeBack
	.global BattleFrontier_Lounge7_Text_ThinkLadiesDontGetAlong
	.global BattleFrontier_Lounge7_Text_LadiesWereStrongAndBeautiful
	.global BattleFrontier_Lounge7_Text_SoftboiledDesc
	.global BattleFrontier_Lounge7_Text_SeismicTossDesc
	.global BattleFrontier_Lounge7_Text_DreamEaterDesc
	.global BattleFrontier_Lounge7_Text_MegaPunchDesc
	.global BattleFrontier_Lounge7_Text_MegaKickDesc
	.global BattleFrontier_Lounge7_Text_BodySlamDesc
	.global BattleFrontier_Lounge7_Text_RockSlideDesc
	.global BattleFrontier_Lounge7_Text_CounterDesc
	.global BattleFrontier_Lounge7_Text_ThunderWaveDesc
	.global BattleFrontier_Lounge7_Text_SwordsDanceDesc
	.global BattleFrontier_Lounge7_Text_DefenseCurlDesc
	.global BattleFrontier_Lounge7_Text_SnoreDesc
	.global BattleFrontier_Lounge7_Text_MudSlapDesc
	.global BattleFrontier_Lounge7_Text_SwiftDesc
	.global BattleFrontier_Lounge7_Text_IcyWindDesc
	.global BattleFrontier_Lounge7_Text_EndureDesc
	.global BattleFrontier_Lounge7_Text_PsychUpDesc
	.global BattleFrontier_Lounge7_Text_IcePunchDesc
	.global BattleFrontier_Lounge7_Text_ThunderPunchDesc
	.global BattleFrontier_Lounge7_Text_FirePunchDesc
@ END GENERATED LOCALIZATION EXPORTS
