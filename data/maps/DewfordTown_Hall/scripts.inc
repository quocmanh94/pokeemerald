DewfordTown_Hall_MapScripts::
	.byte 0

DewfordTown_Hall_EventScript_Girl::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	special IsTrendyPhraseBoring
	goto_if_eq VAR_RESULT, TRUE, DewfordTown_Hall_EventScript_GirlBoredOfTrend
	msgbox DewfordTown_Hall_Text_CantImagineLifeWithoutTrend, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_GirlBoredOfTrend::
	msgbox DewfordTown_Hall_Text_GettingBoredOfTrend, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_Woman::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_TeachingMonAboutTrend, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_Man::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	special BufferDeepLinkPhrase
	msgbox DewfordTown_Hall_Text_DeepLinkBetweenXAndY, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, DewfordTown_Hall_EventScript_ConfirmTrendLink
	goto_if_eq VAR_RESULT, NO, DewfordTown_Hall_EventScript_RejectTrendLink
	end

DewfordTown_Hall_EventScript_ConfirmTrendLink::
	msgbox DewfordTown_Hall_Text_MyHunchWasRight, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_RejectTrendLink::
	msgbox DewfordTown_Hall_Text_NotEasyToKeepUp, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_ExpertM::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_TVShowAboutTrend, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DEWFORD_HALL_EXPERT_M, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	release
	end

DewfordTown_Hall_EventScript_Twin::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_IsTrendMorePopularAcrossSea, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DEWFORD_HALL_TWIN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	release
	end

DewfordTown_Hall_EventScript_LittleBoy::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_CollectTrendMerchandise, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_Bookshelf::
	lockall
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_BooksAboutTrend, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_Painting::
	lockall
	call Common_EventScript_BufferTrendyPhrase
	special GetDewfordHallPaintingNameIndex
	switch VAR_RESULT
	case 0, DewfordTown_Hall_EventScript_ScreamTitle
	case 4, DewfordTown_Hall_EventScript_ScreamTitle
	case 1, DewfordTown_Hall_EventScript_SmileTitle
	case 5, DewfordTown_Hall_EventScript_ScreamTitle
	case 2, DewfordTown_Hall_EventScript_LastTitle
	case 6, DewfordTown_Hall_EventScript_LastTitle
	case 3, DewfordTown_Hall_EventScript_BirthTitle
	case 7, DewfordTown_Hall_EventScript_LastTitle
	end

DewfordTown_Hall_EventScript_ScreamTitle::
	msgbox DewfordTown_Hall_Text_TrendsScream, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_SmileTitle::
	msgbox DewfordTown_Hall_Text_TrendsSmile, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_LastTitle::
	msgbox DewfordTown_Hall_Text_LastTrend, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_BirthTitle::
	msgbox DewfordTown_Hall_Text_BirthOfTrend, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_SchoolKidM::
	lockall
	setvar VAR_0x8008, 0
	goto DewfordTown_Hall_EventScript_DoTrendDebate
	end

DewfordTown_Hall_EventScript_PsychicM::
	lockall
	setvar VAR_0x8008, 1
	goto DewfordTown_Hall_EventScript_DoTrendDebate
	end

DewfordTown_Hall_EventScript_DoTrendDebate::
	call Common_EventScript_BufferTrendyPhrase
	special GetDewfordHallPaintingNameIndex
	switch VAR_RESULT
	case 0, DewfordTown_Hall_EventScript_TrendDebate1
	case 1, DewfordTown_Hall_EventScript_TrendDebate1
	case 2, DewfordTown_Hall_EventScript_TrendDebate2
	case 3, DewfordTown_Hall_EventScript_TrendDebate2
	case 4, DewfordTown_Hall_EventScript_TrendDebate3
	case 5, DewfordTown_Hall_EventScript_TrendDebate3
	case 6, DewfordTown_Hall_EventScript_TrendDebate4
	case 7, DewfordTown_Hall_EventScript_TrendDebate5
	end

DewfordTown_Hall_EventScript_TrendDebate1::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_SawTrendCoolestThing, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_AllegedTrendNotAuthentic, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate2::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_ComposedTrendThemeSong, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_WorkOnYourSinging, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate3::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_OrganizeTrendParty, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_BrilliantIndeed, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate4::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_TrendHasBecomePartOfLife, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_TrendWeighsHeavilyOnMind, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate5::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_IfWeTeamUpWellBeInvincible, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_WellBeTrendDuo, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_DontMovePlayer1::
	return

DewfordTown_Hall_EventScript_DebateReact1::
	applymovement LOCALID_DEWFORD_HALL_PSYCHIC_M, DewfordTown_Hall_Movement_PsychicWalkInPlaceLeft
	waitmovement 0
	goto_if_eq VAR_0x8008, 0, DewfordTown_Hall_EventScript_PlayerReactWest
	goto_if_eq VAR_0x8008, 1, DewfordTown_Hall_EventScript_DontMovePlayer2
	end

DewfordTown_Hall_EventScript_PlayerReactWest::
	goto_if_eq VAR_FACING, DIR_EAST, DewfordTown_Hall_EventScript_DontMovePlayer1
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

DewfordTown_Hall_EventScript_DontMovePlayer2::
	return

DewfordTown_Hall_EventScript_DebateReact2::
	applymovement LOCALID_DEWFORD_HALL_SCHOOL_KID_M, DewfordTown_Hall_Movement_SchoolKidWalkInPlaceRight
	waitmovement 0
	goto_if_eq VAR_0x8008, 0, DewfordTown_Hall_EventScript_PlayerReactNorthSouth
	goto_if_eq VAR_0x8008, 1, DewfordTown_Hall_EventScript_PlayerReactEast
	end

DewfordTown_Hall_EventScript_PlayerReactNorthSouth::
	call_if_eq VAR_FACING, DIR_NORTH, DewfordTown_Hall_EventScript_PlayerWalkInPlaceUp
	call_if_eq VAR_FACING, DIR_SOUTH, DewfordTown_Hall_EventScript_PlayerWalkInPlaceDown
	return

DewfordTown_Hall_EventScript_PlayerWalkInPlaceUp::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

DewfordTown_Hall_EventScript_PlayerWalkInPlaceDown::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

DewfordTown_Hall_EventScript_PlayerReactEast::
	goto_if_eq VAR_FACING, DIR_WEST, DewfordTown_Hall_EventScript_DontMovePlayer1
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

DewfordTown_Hall_Movement_PsychicWalkInPlaceLeft:
	walk_in_place_left
	step_end

DewfordTown_Hall_Movement_SchoolKidWalkInPlaceRight:
	walk_in_place_right
	step_end

DewfordTown_Hall_EventScript_SludgeBombMan::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	goto_if_set FLAG_RECEIVED_TM_SLUDGE_BOMB, DewfordTown_Hall_EventScript_ReceivedSludgeBomb
	msgbox DewfordTown_Hall_Text_GiveYouSludgeBomb, MSGBOX_DEFAULT
	giveitem ITEM_TM_SLUDGE_BOMB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_SLUDGE_BOMB
	release
	end

DewfordTown_Hall_EventScript_ReceivedSludgeBomb::
	msgbox DewfordTown_Hall_Text_LoveSludgeBombButTrendInToo, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_Text_CantImagineLifeWithoutTrend:
	.string "Thứ gì đang thịnh hành ư? Tất nhiên\n"
	.string "phải là “{STR_VAR_1}” rồi!\p"
	.string "Tôi không thể tưởng tượng nổi cuộc\n"
	.string "sống thiếu “{STR_VAR_1}” sẽ ra\l"
	.string "sao!$"

DewfordTown_Hall_Text_GettingBoredOfTrend:
	.string "Thứ gì đang thịnh hành ư? Tất nhiên\n"
	.string "phải là “{STR_VAR_1}” rồi!\p"
	.string "Nhưng tôi bắt đầu thấy hơi chán nó rồi.\p"
	.string "Tôi nên tìm trào lưu lớn tiếp theo thôi.$"

DewfordTown_Hall_Text_TeachingMonAboutTrend:
	.string "Tôi đang dạy POKéMON của mình về\n"
	.string "“{STR_VAR_1}”, nhưng chẳng suôn\l"
	.string "sẻ gì cả.\p"
	.string "Có lẽ thứ này hơi quá sức với nó.$"

DewfordTown_Hall_Text_DeepLinkBetweenXAndY:
	.string "Giờ tôi đang tìm hiểu về\n"
	.string "“{STR_VAR_1}” cực kỳ thời\l"
	.string "thượng.\p"
	.string "Có thật là “{STR_VAR_1}” và\n"
	.string "“{STR_VAR_2}” có mối liên hệ sâu\l"
	.string "sắc không?$"

DewfordTown_Hall_Text_MyHunchWasRight:
	.string "Ồ! Vậy là linh cảm của tôi đã đúng!\p"
	.string "Tôi lại tiến gần thêm một bước đến đỉnh\n"
	.string "cao sành điệu rồi, tuyệt quá!$"

DewfordTown_Hall_Text_NotEasyToKeepUp:
	.string "Gì cơ?! Thật vậy sao?!\p"
	.string "Một người lớn tuổi như tôi đâu dễ bắt\n"
	.string "kịp các trào lưu!$"

DewfordTown_Hall_Text_TVShowAboutTrend:
	.string "Cả câu chuyện về “{STR_VAR_1}”\n"
	.string "này... Chẳng phải có một chương trình\l"
	.string "TV nói về nó sao?$"

DewfordTown_Hall_Text_IsTrendMorePopularAcrossSea:
	.string "Ở bên kia biển...\p"
	.string "“{STR_VAR_1}” còn nổi tiếng hơn\n"
	.string "nữa sao?$"

DewfordTown_Hall_Text_CollectTrendMerchandise:
	.string "Tôi sưu tầm hàng hóa\n"
	.string "“{STR_VAR_1}” được cấp phép\l"
	.string "chính thức.\p"
	.string "Tôi có DOLLS “{STR_VAR_1}” chính\n"
	.string "hãng...\p"
	.string "Quần áo mang thương hiệu\n"
	.string "“{STR_VAR_1}” chính hãng...\p"
	.string "Và cả sách tranh “{STR_VAR_1}”\n"
	.string "được cấp phép chính thức.\p"
	.string "Hê hê, tất cả đều là của tôi! Tôi không\n"
	.string "chia cho bạn thứ gì đâu!$"

DewfordTown_Hall_Text_BooksAboutTrend:
	.string "PHÂN BIỆT “{STR_VAR_1}” TỐT VÀ\n"
	.string "“{STR_VAR_1}” XẤU...\p"
	.string "MỐI LIÊN HỆ GIỮA “{STR_VAR_1}”\n"
	.string "VÀ POKéMON...\p"
	.string "“{STR_VAR_1}” HỮU ÍCH...\p"
	.string "Trên giá xếp kín những cuốn sách về\n"
	.string "“{STR_VAR_1}”.$"

DewfordTown_Hall_Text_TrendsScream:
	.string "Tựa sách là “TIẾNG HÉT CỦA\n"
	.string "{STR_VAR_1}”.$"

DewfordTown_Hall_Text_TrendsSmile:
	.string "Tựa sách là “NỤ CƯỜI CỦA\n"
	.string "{STR_VAR_1}”.$"

DewfordTown_Hall_Text_LastTrend:
	.string "Tựa sách là “{STR_VAR_1} CUỐI\n"
	.string "CÙNG”.$"

DewfordTown_Hall_Text_BirthOfTrend:
	.string "Tựa sách là “SỰ RA ĐỜI CỦA\n"
	.string "{STR_VAR_1}”.$"

DewfordTown_Hall_Text_SawTrendCoolestThing:
	.string "Tôi đã thấy “{STR_VAR_1}” đấy!\n"
	.string "Ngầu chứ hả?\p"
	.string "Nó phải gọi là thứ ngầu nhất hiện giờ\n"
	.string "luôn!\p"
	.string "Tuyệt vời lắm! Hàng thật chính hiệu\n"
	.string "đấy, đúng vậy!$"

DewfordTown_Hall_Text_AllegedTrendNotAuthentic:
	.string "Ồ, không, không, không.\p"
	.string "Thứ được cho là “{STR_VAR_1}”\n"
	.string "mà bạn bảo đã nhìn thấy ấy, không phải\l"
	.string "đâu.\p"
	.string "Hàng thật phải... Nói sao nhỉ? Sắc sảo\n"
	.string "hơn, nhưng cũng dịu hơn!\p"
	.string "À, chẳng quan trọng. Nó tuyệt vời đến\n"
	.string "kinh ngạc!$"

DewfordTown_Hall_Text_ComposedTrendThemeSong:
	.string "Này, nghe nhé, tôi đã sáng tác một bài\n"
	.string "hát chủ đề cho “{STR_VAR_1}”.\p"
	.string "“{STR_VAR_1}” hiện đang nổi\n"
	.string "tiếng lắm.\p"
	.string "Được rồi, nghe này! ... ...\p"
	.string "Ôi! {STR_VAR_1}!\p"
	.string "{STR_VAR_1} tuyệt vời!$"

DewfordTown_Hall_Text_WorkOnYourSinging:
	.string "... ...\p"
	.string "Theo tôi thì anh bạn nên luyện giọng\n"
	.string "cho khá hơn trước khi thử sức với\l"
	.string "“{STR_VAR_1}”.$"

DewfordTown_Hall_Text_OrganizeTrendParty:
	.string "Dù sao, như tôi vừa nói, chúng ta nên tụ\n"
	.string "họp và tổ chức một bữa tiệc\l"
	.string "“{STR_VAR_1}” trên đảo.$"

DewfordTown_Hall_Text_BrilliantIndeed:
	.string "Ồ, ý tưởng tuyệt cú mèo!\p"
	.string "Nhờ vậy, chúng ta sẽ phân định dứt\n"
	.string "khoát ai giỏi “{STR_VAR_1}” nhất.\l"
	.string "Quả là xuất sắc!\p"
	.string "Từ hôm nay, cuộc sống của chúng ta sẽ\n"
	.string "xoay quanh “{STR_VAR_1}”!$"

DewfordTown_Hall_Text_TrendHasBecomePartOfLife:
	.string "Nhưng tôi đang nghĩ...\p"
	.string "Bạn có đồng ý rằng “{STR_VAR_1}”\n"
	.string "đã từ một trào lưu trở thành một phần\l"
	.string "trong cuộc sống hằng ngày của chúng ta\l"
	.string "không?$"

DewfordTown_Hall_Text_TrendWeighsHeavilyOnMind:
	.string "Xin lỗi? Nhiều đến mức nào cơ?\p"
	.string "Tuy nhiên, đúng là “{STR_VAR_1}”\n"
	.string "luôn canh cánh trong tâm trí bạn, dù\l"
	.string "thức hay ngủ.\p"
	.string "Chắc chắn rồi, anh bạn chính là\n"
	.string "PROFESSOR “{STR_VAR_1}”!$"

DewfordTown_Hall_Text_IfWeTeamUpWellBeInvincible:
	.string "Nếu cậu và tôi hợp thành một đội, chúng\n"
	.string "ta sẽ vô địch trong mọi chuyện liên quan\l"
	.string "đến “{STR_VAR_1}”!$"

DewfordTown_Hall_Text_WellBeTrendDuo:
	.string "Chính xác, bạn tôi!\p"
	.string "Chúng ta sẽ là DUO\n"
	.string "“{STR_VAR_1}”!\p"
	.string "Nghe oách lắm chứ? Ha ha ha!$"

DewfordTown_Hall_Text_GiveYouSludgeBomb:
	.string "Với tôi, SLUDGE BOMB đang ở đỉnh cao\n"
	.string "thịnh hành. Nó là số một.\p"
	.string "Hả? Cậu bảo mình không biết SLUDGE\n"
	.string "BOMB sao?\p"
	.string "Đáng thương thật đấy. Tôi sẽ cho cậu\n"
	.string "một cái.$"

DewfordTown_Hall_Text_LoveSludgeBombButTrendInToo:
	.string "Tôi rất thích SLUDGE BOMB.\p"
	.string "Nhưng POKéMON biết chiêu\n"
	.string "“{STR_VAR_1}” cũng đang thịnh\l"
	.string "hành.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global DewfordTown_Hall_Text_CantImagineLifeWithoutTrend
	.global DewfordTown_Hall_Text_GettingBoredOfTrend
	.global DewfordTown_Hall_Text_TeachingMonAboutTrend
	.global DewfordTown_Hall_Text_DeepLinkBetweenXAndY
	.global DewfordTown_Hall_Text_MyHunchWasRight
	.global DewfordTown_Hall_Text_NotEasyToKeepUp
	.global DewfordTown_Hall_Text_TVShowAboutTrend
	.global DewfordTown_Hall_Text_IsTrendMorePopularAcrossSea
	.global DewfordTown_Hall_Text_CollectTrendMerchandise
	.global DewfordTown_Hall_Text_BooksAboutTrend
	.global DewfordTown_Hall_Text_TrendsScream
	.global DewfordTown_Hall_Text_TrendsSmile
	.global DewfordTown_Hall_Text_LastTrend
	.global DewfordTown_Hall_Text_BirthOfTrend
	.global DewfordTown_Hall_Text_SawTrendCoolestThing
	.global DewfordTown_Hall_Text_AllegedTrendNotAuthentic
	.global DewfordTown_Hall_Text_ComposedTrendThemeSong
	.global DewfordTown_Hall_Text_WorkOnYourSinging
	.global DewfordTown_Hall_Text_OrganizeTrendParty
	.global DewfordTown_Hall_Text_BrilliantIndeed
	.global DewfordTown_Hall_Text_TrendHasBecomePartOfLife
	.global DewfordTown_Hall_Text_TrendWeighsHeavilyOnMind
	.global DewfordTown_Hall_Text_IfWeTeamUpWellBeInvincible
	.global DewfordTown_Hall_Text_WellBeTrendDuo
	.global DewfordTown_Hall_Text_GiveYouSludgeBomb
	.global DewfordTown_Hall_Text_LoveSludgeBombButTrendInToo
@ END GENERATED LOCALIZATION EXPORTS
