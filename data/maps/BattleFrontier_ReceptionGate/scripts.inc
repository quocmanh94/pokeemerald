BattleFrontier_ReceptionGate_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_ReceptionGate_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_ReceptionGate_OnTransition
	.byte 0

BattleFrontier_ReceptionGate_OnTransition:
	setflag FLAG_LANDMARK_BATTLE_FRONTIER
	end

BattleFrontier_ReceptionGate_OnFrame:
	map_script_2 VAR_HAS_ENTERED_BATTLE_FRONTIER, 0, BattleFrontier_ReceptionGate_EventScript_FirstTimeEntering
	.2byte 0

BattleFrontier_ReceptionGate_EventScript_FirstTimeEntering::
	lockall
	setvar VAR_HAS_ENTERED_BATTLE_FRONTIER, 1
	playse SE_PIN
	applymovement LOCALID_FRONTIER_RECEPTION_GREETER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_FRONTIER_RECEPTION_GREETER, Common_Movement_Delay48
	waitmovement 0
	msgbox BattleFrontier_ReceptionGate_Text_FirstTimeHereThisWay, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, BattleFrontier_ReceptionGate_Movement_PlayerApproachCounter
	waitmovement 0
	goto BattleFrontier_ReceptionGate_EventScript_ScottScene
	end

BattleFrontier_ReceptionGate_EventScript_ScottScene::
	msgbox BattleFrontier_ReceptionGate_Text_WelcomeToBattleFrontier, MSGBOX_DEFAULT
	msgbox BattleFrontier_ReceptionGate_Text_IssueFrontierPass, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message BattleFrontier_ReceptionGate_Text_ObtainedFrontierPass
	waitfanfare
	waitmessage
	msgbox BattleFrontier_ReceptionGate_Text_PlacedTrainerCardInFrontierPass, MSGBOX_DEFAULT
	setflag FLAG_SYS_FRONTIER_PASS
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	msgbox BattleFrontier_ReceptionGate_Text_IfItIsntPlayerYouCame, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FRONTIER_RECEPTION_GREETER, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_FRONTIER_RECEPTION_GUIDE, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_FRONTIER_RECEPTION_GREETER, Common_Movement_ExclamationMark
	applymovement LOCALID_FRONTIER_RECEPTION_GUIDE, Common_Movement_ExclamationMark
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox BattleFrontier_ReceptionGate_Text_OhMrScottGoodDay, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FRONTIER_RECEPTION_GREETER, BattleFrontier_ReceptionGate_Movement_GreeterFaceScott
	applymovement LOCALID_FRONTIER_RECEPTION_GUIDE, BattleFrontier_ReceptionGate_Movement_FacilityGuideFaceScott
	applymovement LOCALID_PLAYER, BattleFrontier_ReceptionGate_Movement_PlayerFaceScott
	applymovement LOCALID_FRONTIER_RECEPTION_SCOTT, BattleFrontier_ReceptionGate_Movement_ScottEnter
	waitmovement 0
	msgbox BattleFrontier_ReceptionGate_Text_ScottGreatToSeeYouHere, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FRONTIER_RECEPTION_SCOTT, BattleFrontier_ReceptionGate_Movement_ScottExit
	waitmovement 0
	removeobject LOCALID_FRONTIER_RECEPTION_SCOTT
	releaseall
	end

BattleFrontier_ReceptionGate_Movement_PlayerApproachCounter:
	walk_up
	walk_up
	walk_left
	walk_left
	step_end

BattleFrontier_ReceptionGate_Movement_PlayerFaceScott:
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

@ Unused
BattleFrontier_ReceptionGate_Movement_WalkDown:
	walk_down
	walk_down
	step_end

BattleFrontier_ReceptionGate_Movement_ScottEnter:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	step_end

BattleFrontier_ReceptionGate_Movement_ScottExit:
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_ReceptionGate_Movement_GreeterFaceScott:
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

BattleFrontier_ReceptionGate_Movement_FacilityGuideFaceScott:
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

BattleFrontier_ReceptionGate_EventScript_Greeter::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_WelcomeToBattleFrontier, MSGBOX_DEFAULT
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_EventScript_FacilityGuide::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_YourGuideToFacilities, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout::
	message BattleFrontier_ReceptionGate_Text_LearnAboutWhich2
	waitmessage
	setvar VAR_0x8004, SCROLL_MULTI_BF_RECEPTIONIST
	special ShowScrollableMultichoice
	switch VAR_RESULT
	case 0, BattleFrontier_ReceptionGate_EventScript_BattleTower
	case 1, BattleFrontier_ReceptionGate_EventScript_BattleDome
	case 2, BattleFrontier_ReceptionGate_EventScript_BattlePalace
	case 3, BattleFrontier_ReceptionGate_EventScript_BattleArena
	case 4, BattleFrontier_ReceptionGate_EventScript_BattleFactory
	case 5, BattleFrontier_ReceptionGate_EventScript_BattlePike
	case 6, BattleFrontier_ReceptionGate_EventScript_BattlePyramid
	case 7, BattleFrontier_ReceptionGate_EventScript_RankingHall
	case 8, BattleFrontier_ReceptionGate_EventScript_ExchangeCorner
	case 9, BattleFrontier_ReceptionGate_EventScript_ExitFacilityGuide
	case MULTI_B_PRESSED, BattleFrontier_ReceptionGate_EventScript_ExitFacilityGuide
	end

BattleFrontier_ReceptionGate_EventScript_BattleTower::
	msgbox BattleFrontier_ReceptionGate_Text_BattleTowerInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattleDome::
	msgbox BattleFrontier_ReceptionGate_Text_BattleDomeInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattlePalace::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePalaceInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattleArena::
	msgbox BattleFrontier_ReceptionGate_Text_BattleArenaInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattleFactory::
	msgbox BattleFrontier_ReceptionGate_Text_BattleFactoryInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattlePike::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePikeInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattlePyramid::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePyramidInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_RankingHall::
	msgbox BattleFrontier_ReceptionGate_Text_RankingHallInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ExchangeCorner::
	msgbox BattleFrontier_ReceptionGate_Text_ExchangeCornerInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ExitFacilityGuide::
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_EventScript_RulesGuide::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_YourGuideToRules, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout::
	message BattleFrontier_ReceptionGate_Text_LearnAboutWhat
	waitmessage
	multichoice 15, 0, MULTI_FRONTIER_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_ReceptionGate_EventScript_LevelMode
	case 1, BattleFrontier_ReceptionGate_EventScript_Level50
	case 2, BattleFrontier_ReceptionGate_EventScript_OpenLevel
	case 3, BattleFrontier_ReceptionGate_EventScript_MonEntry
	case 4, BattleFrontier_ReceptionGate_EventScript_HoldItems
	case 5, BattleFrontier_ReceptionGate_EventScript_ExitRulesGuide
	case MULTI_B_PRESSED, BattleFrontier_ReceptionGate_EventScript_ExitRulesGuide
	end

BattleFrontier_ReceptionGate_EventScript_LevelMode::
	msgbox BattleFrontier_ReceptionGate_Text_LevelModeInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_Level50::
	msgbox BattleFrontier_ReceptionGate_Text_Level50Info, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_OpenLevel::
	msgbox BattleFrontier_ReceptionGate_Text_OpenLevelInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_MonEntry::
	msgbox BattleFrontier_ReceptionGate_Text_MonEntryInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_HoldItems::
	msgbox BattleFrontier_ReceptionGate_Text_HoldItemsInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ExitRulesGuide::
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_EventScript_FrontierPassGuide::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_YourGuideToFrontierPass, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout::
	message BattleFrontier_ReceptionGate_Text_LearnAboutWhich1
	waitmessage
	multichoice 16, 4, MULTI_FRONTIER_PASS_INFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_ReceptionGate_EventScript_Symbols
	case 1, BattleFrontier_ReceptionGate_EventScript_RecordBattle
	case 2, BattleFrontier_ReceptionGate_EventScript_BattlePoints
	case 3, BattleFrontier_ReceptionGate_EventScript_ExitFrontierPassGuide
	case MULTI_B_PRESSED, BattleFrontier_ReceptionGate_EventScript_ExitFrontierPassGuide
	end

BattleFrontier_ReceptionGate_EventScript_Symbols::
	msgbox BattleFrontier_ReceptionGate_Text_SymbolsInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_RecordBattle::
	msgbox BattleFrontier_ReceptionGate_Text_RecordedBattleInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattlePoints::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePointsInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ExitFrontierPassGuide::
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_Text_FirstTimeHereThisWay:
	.string "Đây là lần đầu bạn đến phải không? Xin\n"
	.string "mời đi lối này!$"

BattleFrontier_ReceptionGate_Text_WelcomeToBattleFrontier:
	.string "Tuyến đầu của những trận chiến\n"
	.string "POKéMON! Chào mừng đến BATTLE\l"
	.string "FRONTIER!$"

BattleFrontier_ReceptionGate_Text_IssueFrontierPass:
	.string "Với khách đến lần đầu, chúng tôi sẽ cấp\n"
	.string "FRONTIER PASS.\p"
	.string "Nó được dùng tại tất cả cơ sở trong\n"
	.string "BATTLE FRONTIER.\p"
	.string "Của bạn đây!$"

BattleFrontier_ReceptionGate_Text_ObtainedFrontierPass:
	.string "{PLAYER} nhận được FRONTIER PASS.$"

BattleFrontier_ReceptionGate_Text_PlacedTrainerCardInFrontierPass:
	.string "{PLAYER} đặt TRAINER CARD vào\n"
	.string "FRONTIER PASS.$"

BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier:
	.string "Chúc bạn tận hưởng mọi điều tuyệt vời\n"
	.string "mà BATTLE FRONTIER mang lại!$"

BattleFrontier_ReceptionGate_Text_IfItIsntPlayerYouCame:
	.string "???: Chà, chẳng phải {PLAYER}{KUN}\n"
	.string "sao! Cậu cũng đến tận đây à!$"

BattleFrontier_ReceptionGate_Text_OhMrScottGoodDay:
	.string "HƯỚNG DẪN: Ôi, ngài SCOTT!\n"
	.string "Chào ngài ạ!$"

BattleFrontier_ReceptionGate_Text_ScottGreatToSeeYouHere:
	.string "SCOTT: Thật tuyệt khi thấy cháu ở đây,\n"
	.string "thật đấy!\p"
	.string "Ta mong cháu sẽ thong thả khám phá mọi\n"
	.string "nơi.\p"
	.string "Tất nhiên, ta cũng mong cháu cảm nhận\n"
	.string "được tinh hoa thuần túy của chiến đấu.\p"
	.string "Ta cũng có chỗ ở riêng tại đây, nên nếu\n"
	.string "có thời gian cứ ghé thăm nhé.$"

BattleFrontier_ReceptionGate_Text_YourGuideToFacilities:
	.string "Tôi là người hướng dẫn bạn về các cơ\n"
	.string "sở khác nhau tại BATTLE FRONTIER.$"

BattleFrontier_ReceptionGate_Text_LearnAboutWhich2:
	.string "Bạn muốn tìm hiểu về nơi nào?$"

BattleFrontier_ReceptionGate_Text_BattleTowerInfo:
	.string "Đó là tòa tháp khổng lồ được xem là\n"
	.string "biểu tượng của BATTLE FRONTIER.\p"
	.string "Trong tháp có bốn loại BATTLE ROOMS\n"
	.string "dành cho SINGLE, DOUBLE, MULTI và LINK\l"
	.string "MULTI BATTLES.$"

BattleFrontier_ReceptionGate_Text_BattleDomeInfo:
	.string "BATTLE DOME là tòa nhà lớn có hình quả\n"
	.string "trứng khổng lồ.\p"
	.string "Các sự kiện mang tên Battle Tourneys\n"
	.string "được tổ chức tại đây.\p"
	.string "Battle Tourneys có hai nội dung: SINGLE\n"
	.string "và DOUBLE BATTLES.$"

BattleFrontier_ReceptionGate_Text_BattlePalaceInfo:
	.string "BATTLE PALACE là tòa nhà màu đỏ nằm\n"
	.string "bên phải BATTLE FRONTIER.\p"
	.string "Có hai loại BATTLE HALLS dành cho\n"
	.string "SINGLE và DOUBLE BATTLES.$"

BattleFrontier_ReceptionGate_Text_BattleArenaInfo:
	.string "BATTLE ARENA là tòa nhà giống võ đường\n"
	.string "nằm ở khu vực giữa bên phải BATTLE\l"
	.string "FRONTIER.\p"
	.string "Một sự kiện mang tên Set KO Tourney\n"
	.string "được tổ chức tại BATTLE ARENA.$"

BattleFrontier_ReceptionGate_Text_BattleFactoryInfo:
	.string "BATTLE FACTORY là tòa nhà lớn ở gần\n"
	.string "chúng ta nhất.\p"
	.string "Một sự kiện mang tên Battle Swap được\n"
	.string "tổ chức tại đó.\p"
	.string "Battle Swap có hai nội dung dành cho\n"
	.string "SINGLE và DOUBLE BATTLES.$"

BattleFrontier_ReceptionGate_Text_BattlePikeInfo:
	.string "BATTLE PIKE là tòa nhà có hình một\n"
	.string "POKéMON nằm ở khu vực giữa bên trái\l"
	.string "BATTLE FRONTIER.\p"
	.string "Một sự kiện mang tên Battle Choice\n"
	.string "được tổ chức tại đó.$"

BattleFrontier_ReceptionGate_Text_BattlePyramidInfo:
	.string "BATTLE PYRAMID là kim tự tháp khổng lồ.\p"
	.string "Một sự kiện mang tên Battle Quest\n"
	.string "được tổ chức tại đó.$"

BattleFrontier_ReceptionGate_Text_RankingHallInfo:
	.string "RANKING HALL nằm gần BATTLE TOWER.\p"
	.string "Tại đó, bạn có thể xem những kỷ lục\n"
	.string "tuyệt vời nhất do các HLV từng\l"
	.string "đương đầu với vô số thử thách tại\l"
	.string "BATTLE FRONTIER để lại.$"

BattleFrontier_ReceptionGate_Text_ExchangeCornerInfo:
	.string "EXCHANGE SERVICE CORNER nằm gần\n"
	.string "BATTLE TOWER.\p"
	.string "Tại đó, bạn có thể đổi Battle Points\n"
	.string "kiếm được ở BATTLE FRONTIER lấy\l"
	.string "những phần thưởng tuyệt vời.$"

BattleFrontier_ReceptionGate_Text_YourGuideToRules:
	.string "Tôi sẽ hướng dẫn bạn những quy tắc cơ\n"
	.string "bản áp dụng chung cho mọi thử thách tại\l"
	.string "các cơ sở của BATTLE FRONTIER.$"

BattleFrontier_ReceptionGate_Text_LearnAboutWhat:
	.string "Bạn muốn tìm hiểu về điều gì?$"

BattleFrontier_ReceptionGate_Text_LevelModeInfo:
	.string "Mọi thử thách tại các cơ sở của BATTLE\n"
	.string "FRONTIER đều có hai nội dung: Level 50\l"
	.string "và Open Level.$"

BattleFrontier_ReceptionGate_Text_Level50Info:
	.string "Nội dung Level 50 dành cho các POKéMON\n"
	.string "có Level không quá 50.\p"
	.string "Tuy nhiên, xin lưu ý rằng không HLV\n"
	.string "nào bạn đối đầu sử dụng POKéMON dưới\l"
	.string "Level 50.\p"
	.string "Đây là nội dung nhập môn cho các trận\n"
	.string "đấu tại BATTLE FRONTIER.\p"
	.string "Trước tiên, chúng tôi hy vọng bạn sẽ\n"
	.string "thử sức với nội dung này.$"

BattleFrontier_ReceptionGate_Text_OpenLevelInfo:
	.string "Nội dung Open Level không giới hạn\n"
	.string "Level của các POKéMON tham gia thử\l"
	.string "thách.\p"
	.string "Level của đối thủ sẽ được điều chỉnh\n"
	.string "cho phù hợp với Level của POKéMON bên\l"
	.string "bạn.\p"
	.string "Tuy nhiên, không HLV nào bạn đối\n"
	.string "đầu sử dụng POKéMON dưới Level 60.$"

BattleFrontier_ReceptionGate_Text_MonEntryInfo:
	.string "Hầu như mọi loài POKéMON đều có thể\n"
	.string "tham gia thử thách tại tất cả các cơ\l"
	.string "sở.\p"
	.string "Tuy nhiên, EGGS và một số loài POKéMON\n"
	.string "nhất định không được phép tham gia.\p"
	.string "Số lượng POKéMON cần thiết cho mỗi thử\n"
	.string "thách tùy thuộc vào từng cơ sở.\p"
	.string "Tuy nhiên, mọi cơ sở đều không cho phép\n"
	.string "sử dụng từ hai POKéMON cùng loài trở\l"
	.string "lên.$"

BattleFrontier_ReceptionGate_Text_HoldItemsInfo:
	.string "Khi tham gia thử thách tại một cơ sở\n"
	.string "của BATTLE FRONTIER, các POKéMON\l"
	.string "không được giữ cùng một loại vật phẩm.\p"
	.string "Xin hãy bảo đảm rằng mọi POKéMON tham\n"
	.string "gia thử thách đều giữ những vật phẩm\l"
	.string "khác nhau.$"

BattleFrontier_ReceptionGate_Text_YourGuideToFrontierPass:
	.string "Tôi sẽ hướng dẫn bạn về FRONTIER PASS.$"

BattleFrontier_ReceptionGate_Text_LearnAboutWhich1:
	.string "Bạn muốn tìm hiểu về mục nào?$"

BattleFrontier_ReceptionGate_Text_SymbolsInfo:
	.string "BATTLE FRONTIER có bảy cơ sở.\p"
	.string "Những HLV được công nhận về\n"
	.string "năng lực có thể nhận được biểu tượng\l"
	.string "từ mỗi cơ sở.\p"
	.string "Để giành biểu tượng, HLV có thể\n"
	.string "phải đánh bại nhiều HLV liên tiếp\l"
	.string "và chiến thắng các sự kiện nhiều lần.\p"
	.string "Giành được biểu tượng chắc chắn\n"
	.string "không hề dễ dàng. Chúc bạn may mắn!$"

BattleFrontier_ReceptionGate_Text_RecordedBattleInfo:
	.string "Bạn có thể lưu lại một trận đấu trên\n"
	.string "FRONTIER PASS.\p"
	.string "Bạn có thể lưu một trận đấu với một\n"
	.string "hoặc nhiều người bạn.\p"
	.string "Bạn cũng có thể lưu một trận đấu diễn\n"
	.string "ra tại BATTLE FRONTIER, ngoại trừ các\l"
	.string "trận ở BATTLE PIKE hoặc BATTLE\l"
	.string "PYRAMID.\p"
	.string "Khi trận đấu kết thúc, bạn có thể chọn\n"
	.string "lưu lại trận đó.$"

BattleFrontier_ReceptionGate_Text_BattlePointsInfo:
	.string "Battle Points là phần thưởng dành cho\n"
	.string "các HLV có màn thể hiện xuất sắc\l"
	.string "tại BATTLE FRONTIER.\p"
	.string "Bạn có thể đổi Battle Points lấy phần\n"
	.string "thưởng tại EXCHANGE SERVICE CORNER.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global BattleFrontier_ReceptionGate_Text_FirstTimeHereThisWay
	.global BattleFrontier_ReceptionGate_Text_WelcomeToBattleFrontier
	.global BattleFrontier_ReceptionGate_Text_IssueFrontierPass
	.global BattleFrontier_ReceptionGate_Text_ObtainedFrontierPass
	.global BattleFrontier_ReceptionGate_Text_PlacedTrainerCardInFrontierPass
	.global BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier
	.global BattleFrontier_ReceptionGate_Text_IfItIsntPlayerYouCame
	.global BattleFrontier_ReceptionGate_Text_OhMrScottGoodDay
	.global BattleFrontier_ReceptionGate_Text_ScottGreatToSeeYouHere
	.global BattleFrontier_ReceptionGate_Text_YourGuideToFacilities
	.global BattleFrontier_ReceptionGate_Text_LearnAboutWhich2
	.global BattleFrontier_ReceptionGate_Text_BattleTowerInfo
	.global BattleFrontier_ReceptionGate_Text_BattleDomeInfo
	.global BattleFrontier_ReceptionGate_Text_BattlePalaceInfo
	.global BattleFrontier_ReceptionGate_Text_BattleArenaInfo
	.global BattleFrontier_ReceptionGate_Text_BattleFactoryInfo
	.global BattleFrontier_ReceptionGate_Text_BattlePikeInfo
	.global BattleFrontier_ReceptionGate_Text_BattlePyramidInfo
	.global BattleFrontier_ReceptionGate_Text_RankingHallInfo
	.global BattleFrontier_ReceptionGate_Text_ExchangeCornerInfo
	.global BattleFrontier_ReceptionGate_Text_YourGuideToRules
	.global BattleFrontier_ReceptionGate_Text_LearnAboutWhat
	.global BattleFrontier_ReceptionGate_Text_LevelModeInfo
	.global BattleFrontier_ReceptionGate_Text_Level50Info
	.global BattleFrontier_ReceptionGate_Text_OpenLevelInfo
	.global BattleFrontier_ReceptionGate_Text_MonEntryInfo
	.global BattleFrontier_ReceptionGate_Text_HoldItemsInfo
	.global BattleFrontier_ReceptionGate_Text_YourGuideToFrontierPass
	.global BattleFrontier_ReceptionGate_Text_LearnAboutWhich1
	.global BattleFrontier_ReceptionGate_Text_SymbolsInfo
	.global BattleFrontier_ReceptionGate_Text_RecordedBattleInfo
	.global BattleFrontier_ReceptionGate_Text_BattlePointsInfo
@ END GENERATED LOCALIZATION EXPORTS
