SlateportCity_Harbor_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_Harbor_OnTransition
	.byte 0

SlateportCity_Harbor_OnTransition:
	setescapewarp MAP_SLATEPORT_CITY, 28, 13
	setvar VAR_TEMP_1, 0
	call_if_eq VAR_SLATEPORT_HARBOR_STATE, 1, SlateportCity_Harbor_EventScript_ReadyAquaEscapeScene
	call_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_Harbor_EventScript_ShowSSTidal
	end

SlateportCity_Harbor_EventScript_ShowSSTidal::
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_SS_TIDAL
	return

SlateportCity_Harbor_EventScript_ReadyAquaEscapeScene::
	savebgm MUS_ENCOUNTER_AQUA
	setobjectxyperm LOCALID_SLATEPORT_HARBOR_CAPT_STERN, 12, 13
	setobjectmovementtype LOCALID_SLATEPORT_HARBOR_CAPT_STERN, MOVEMENT_TYPE_FACE_LEFT
	setflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_PATRONS
	return

SlateportCity_Harbor_EventScript_AquaEscapeTrigger0::
	lockall
	setvar VAR_0x8008, 0
	goto SlateportCity_Harbor_EventScript_AquaEscapeScene
	end

SlateportCity_Harbor_EventScript_AquaEscapeTrigger1::
	lockall
	setvar VAR_0x8008, 1
	goto SlateportCity_Harbor_EventScript_AquaEscapeScene
	end

SlateportCity_Harbor_EventScript_AquaEscapeTrigger2::
	lockall
	setvar VAR_0x8008, 2
	goto SlateportCity_Harbor_EventScript_AquaEscapeScene
	end

SlateportCity_Harbor_EventScript_AquaEscapeTrigger3::
	lockall
	setvar VAR_0x8008, 3
	applymovement LOCALID_PLAYER, SlateportCity_Harbor_Movement_PlayerWalkUp
	waitmovement 0
	goto SlateportCity_Harbor_EventScript_AquaEscapeScene
	end

SlateportCity_Harbor_EventScript_AquaEscapeScene::
	applymovement LOCALID_SLATEPORT_HARBOR_ARCHIE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	applymovement LOCALID_SLATEPORT_HARBOR_GRUNT, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox SlateportCity_Harbor_Text_ArchieYouAgainHideoutInLilycove, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_HARBOR_GRUNT, SlateportCity_Harbor_Movement_AquaBoardSub
	applymovement LOCALID_SLATEPORT_HARBOR_ARCHIE, SlateportCity_Harbor_Movement_AquaBoardSub
	applymovement LOCALID_SLATEPORT_HARBOR_SUBMARINE, SlateportCity_Harbor_Movement_SubmarineExit
	waitmovement 0
	removeobject LOCALID_SLATEPORT_HARBOR_GRUNT
	removeobject LOCALID_SLATEPORT_HARBOR_ARCHIE
	removeobject LOCALID_SLATEPORT_HARBOR_SUBMARINE
	setvar VAR_SLATEPORT_HARBOR_STATE, 2
	setflag FLAG_MET_TEAM_AQUA_HARBOR
	setflag FLAG_HIDE_LILYCOVE_MOTEL_SCOTT
	call_if_eq VAR_0x8008, 0, SlateportCity_Harbor_EventScript_SternApproachPlayer0
	call_if_eq VAR_0x8008, 1, SlateportCity_Harbor_EventScript_SternApproachPlayer1
	call_if_eq VAR_0x8008, 2, SlateportCity_Harbor_EventScript_SternApproachPlayer
	call_if_eq VAR_0x8008, 3, SlateportCity_Harbor_EventScript_SternApproachPlayer
	msgbox SlateportCity_Harbor_Text_CaptSternWhyStealMySubmarine, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_HIDE_AQUA_HIDEOUT_1F_GRUNT_1_BLOCKING_ENTRANCE
	setflag FLAG_HIDE_AQUA_HIDEOUT_1F_GRUNT_2_BLOCKING_ENTRANCE
	copyobjectxytoperm LOCALID_SLATEPORT_HARBOR_CAPT_STERN
	setobjectmovementtype LOCALID_SLATEPORT_HARBOR_CAPT_STERN, MOVEMENT_TYPE_FACE_RIGHT
	releaseall
	end

SlateportCity_Harbor_EventScript_SternApproachPlayer0::
	applymovement LOCALID_SLATEPORT_HARBOR_CAPT_STERN, SlateportCity_Harbor_Movement_SternApproachPlayer0
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

SlateportCity_Harbor_EventScript_SternApproachPlayer1::
	applymovement LOCALID_SLATEPORT_HARBOR_CAPT_STERN, SlateportCity_Harbor_Movement_SternApproachPlayer1
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

SlateportCity_Harbor_EventScript_SternApproachPlayer::
	applymovement LOCALID_SLATEPORT_HARBOR_CAPT_STERN, SlateportCity_Harbor_Movement_SternApproachPlayer
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

SlateportCity_Harbor_Movement_AquaBoardSub:
	delay_16
	delay_16
	jump_up
	set_invisible
	step_end

@ Unused, Archie instead shares above identical movement script with Grunt
SlateportCity_Harbor_Movement_ArchieBoardSub:
	delay_16
	delay_16
	jump_up
	set_invisible
	step_end

SlateportCity_Harbor_Movement_SubmarineExit:
	delay_16
	delay_16
	delay_16
	delay_16
	walk_right
	walk_right
	walk_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

SlateportCity_Harbor_Movement_SternApproachPlayer0:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

SlateportCity_Harbor_Movement_SternApproachPlayer1:
	walk_left
	walk_left
	walk_up
	walk_left
	step_end

SlateportCity_Harbor_Movement_SternApproachPlayer:
	walk_left
	walk_left
	walk_left
	step_end

SlateportCity_Harbor_Movement_PlayerWalkUp:
	walk_up
	step_end

SlateportCity_Harbor_EventScript_FerryAttendant::
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_Harbor_EventScript_AskForTicket
	msgbox SlateportCity_Harbor_Text_FerryServiceUnavailable, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_AskForTicket::
	msgbox SlateportCity_Harbor_Text_MayISeeYourTicket, MSGBOX_DEFAULT
	message SlateportCity_Harbor_Text_FlashedTicketWhereTo
	waitmessage
	goto SlateportCity_Harbor_EventScript_ChooseDestination
	end

SlateportCity_Harbor_EventScript_ChooseDestination::
	goto_if_set FLAG_MET_SCOTT_ON_SS_TIDAL, SlateportCity_Harbor_EventScript_ChooseDestinationWithBattleFrontier
	multichoicedefault 18, 8, MULTI_SSTIDAL_SLATEPORT_NO_BF, 2, FALSE
	switch VAR_RESULT
	case 0, SlateportCity_Harbor_EventScript_Lilycove
	case 1, SlateportCity_Harbor_EventScript_CancelDestinationSelect
	case MULTI_B_PRESSED, SlateportCity_Harbor_EventScript_CancelDestinationSelect
	end

SlateportCity_Harbor_EventScript_ChooseDestinationWithBattleFrontier::
	multichoicedefault 17, 6, MULTI_SSTIDAL_SLATEPORT_WITH_BF, 2, FALSE
	switch VAR_RESULT
	case 0, SlateportCity_Harbor_EventScript_Lilycove
	case 1, SlateportCity_Harbor_EventScript_BattleFrontier
	case 2, SlateportCity_Harbor_EventScript_CancelDestinationSelect
	case MULTI_B_PRESSED, SlateportCity_Harbor_EventScript_CancelDestinationSelect
	end

@ Unused. Should be impossible for player to reach Ferry without having received SS Tidal ticket
SlateportCity_Harbor_EventScript_NoTicket::
	msgbox SlateportCity_Harbor_Text_YouMustHaveTicket, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_Lilycove::
	msgbox SlateportCity_Harbor_Text_LilycoveItIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SlateportCity_Harbor_EventScript_ChooseNewDestination
	setvar VAR_SS_TIDAL_STATE, SS_TIDAL_BOARD_SLATEPORT
	call SlateportCity_Harbor_EventScript_BoardFerry
	warp MAP_SS_TIDAL_CORRIDOR, 1, 10
	waitstate
	release
	end

SlateportCity_Harbor_EventScript_BattleFrontier::
	msgbox SlateportCity_Harbor_Text_BattleFrontierItIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SlateportCity_Harbor_EventScript_ChooseNewDestination
	call SlateportCity_Harbor_EventScript_BoardFerry
	warp MAP_BATTLE_FRONTIER_OUTSIDE_WEST, 19, 67
	waitstate
	release
	end

SlateportCity_Harbor_EventScript_ChooseNewDestination::
	message SlateportCity_Harbor_Text_WhereWouldYouLikeToGo
	waitmessage
	goto SlateportCity_Harbor_EventScript_ChooseDestination
	end

SlateportCity_Harbor_EventScript_BoardFerry::
	msgbox SlateportCity_Harbor_Text_PleaseBoardFerry, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 30
	hideobjectat VAR_LAST_TALKED, MAP_SLATEPORT_CITY_HARBOR
	call_if_eq VAR_FACING, DIR_NORTH, SlateportCity_Harbor_EventScript_BoardFerryNorth
	call_if_eq VAR_FACING, DIR_EAST, SlateportCity_Harbor_EventScript_BoardFerryEast
	delay 30
	hideplayer
	setvar VAR_0x8004, LOCALID_SLATEPORT_HARBOR_SS_TIDAL
	call Common_EventScript_FerryDepart
	return

SlateportCity_Harbor_EventScript_CancelDestinationSelect::
	msgbox SlateportCity_Harbor_Text_SailAnotherTime, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_BoardFerryEast::
	applymovement LOCALID_PLAYER, SlateportCity_Harbor_Movement_BoardFerryEast
	waitmovement 0
	return

SlateportCity_Harbor_EventScript_BoardFerryNorth::
	applymovement LOCALID_PLAYER, SlateportCity_Harbor_Movement_BoardFerryNorth
	waitmovement 0
	return

SlateportCity_Harbor_Movement_BoardFerryEast:
	walk_right
	walk_in_place_faster_up
	step_end

SlateportCity_Harbor_Movement_BoardFerryNorth:
	walk_up
	step_end

SlateportCity_Harbor_EventScript_Sailor::
	lock
	faceplayer
	goto_if_unset FLAG_SYS_GAME_CLEAR, SlateportCity_Harbor_EventScript_SailorNoAbnormalWeather
	setvar VAR_0x8004, 0
	call_if_set FLAG_DEFEATED_KYOGRE, SlateportCity_Harbor_EventScript_CountDefeatedLegendary
	call_if_set FLAG_DEFEATED_GROUDON, SlateportCity_Harbor_EventScript_CountDefeatedLegendary
	goto_if_eq VAR_0x8004, 2, SlateportCity_Harbor_EventScript_SailorNoAbnormalWeather  @ Defeated both
	msgbox SlateportCity_Harbor_Text_AbnormalWeather, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_SailorNoAbnormalWeather::
	msgbox SlateportCity_Harbor_Text_LoveToGoDeepUnderwaterSomeday, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_CountDefeatedLegendary::
	addvar VAR_0x8004, 1
	return

SlateportCity_Harbor_EventScript_FatMan::
	msgbox SlateportCity_Harbor_Text_SubTooSmallForMe, MSGBOX_NPC
	end

SlateportCity_Harbor_EventScript_CaptStern::
	lock
	faceplayer
	goto_if_set FLAG_BADGE07_GET, SlateportCity_Harbor_EventScript_CaptSternFerryOrScannerComment
	goto_if_set FLAG_EVIL_TEAM_ESCAPED_STERN_SPOKE, SlateportCity_Harbor_EventScript_NeedDive
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, SlateportCity_Harbor_EventScript_TeamAquaLeftNeedDive
	goto_if_eq VAR_SLATEPORT_HARBOR_STATE, 2, SlateportCity_Harbor_EventScript_WhyStealSubmarine
	msgbox SlateportCity_Harbor_Text_SameThugsTriedToRobAtMuseum, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_Harbor_EventScript_WhyStealSubmarine::
	msgbox SlateportCity_Harbor_Text_CaptSternWhyStealMySubmarine, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_TeamAquaLeftNeedDive::
	setflag FLAG_EVIL_TEAM_ESCAPED_STERN_SPOKE
	msgbox SlateportCity_Harbor_Text_TeamAquaLeftNeedDive, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_NeedDive::
	msgbox SlateportCity_Harbor_Text_NeedDiveToCatchSub, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_CaptSternFerryOrScannerComment::
	goto_if_eq VAR_TEMP_1, 1, SlateportCity_Harbor_EventScript_TradedScanner
	checkitem ITEM_SCANNER
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_Harbor_EventScript_AskToTradeScanner
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_Harbor_EventScript_FerryFinished
	msgbox SlateportCity_Harbor_Text_WontBeLongBeforeWeFinishFerry, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_FerryFinished::
	msgbox SlateportCity_Harbor_Text_FinishedMakingFerry, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_AskToTradeScanner::
	message SlateportCity_Harbor_Text_WouldYouTradeScanner
	waitmessage
	goto SlateportCity_Harbor_EventScript_ChooseScannerTrade
	end

SlateportCity_Harbor_EventScript_ChooseScannerTrade::
	multichoice 0, 0, MULTI_STERN_DEEPSEA, FALSE
	switch VAR_RESULT
	case 0, SlateportCity_Harbor_EventScript_DeepSeaTooth
	case 1, SlateportCity_Harbor_EventScript_DeepSeaScale
	case 2, SlateportCity_Harbor_EventScript_DeclineTrade
	case MULTI_B_PRESSED, SlateportCity_Harbor_EventScript_DeclineTrade
	end

SlateportCity_Harbor_EventScript_DeepSeaTooth::
	msgbox SlateportCity_Harbor_Text_TradeForDeepSeaTooth, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SlateportCity_Harbor_EventScript_ChooseDifferentTrade
	giveitem ITEM_DEEP_SEA_TOOTH
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	removeitem ITEM_SCANNER
	msgbox SlateportCity_Harbor_Text_HandedScannerToStern, MSGBOX_DEFAULT
	setflag FLAG_EXCHANGED_SCANNER
	goto SlateportCity_Harbor_EventScript_TradedScanner
	end

SlateportCity_Harbor_EventScript_DeepSeaScale::
	msgbox SlateportCity_Harbor_Text_TradeForDeepSeaScale, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SlateportCity_Harbor_EventScript_ChooseDifferentTrade
	giveitem ITEM_DEEP_SEA_SCALE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	removeitem ITEM_SCANNER
	msgbox SlateportCity_Harbor_Text_HandedScannerToStern, MSGBOX_DEFAULT
	setflag FLAG_EXCHANGED_SCANNER
	goto SlateportCity_Harbor_EventScript_TradedScanner
	end

SlateportCity_Harbor_EventScript_DeclineTrade::
	msgbox SlateportCity_Harbor_Text_IfYouWantToTradeLetMeKnow, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_ChooseDifferentTrade::
	message SlateportCity_Harbor_Text_WhichOneDoYouWant
	waitmessage
	goto SlateportCity_Harbor_EventScript_ChooseScannerTrade
	end

SlateportCity_Harbor_EventScript_TradedScanner::
	setvar VAR_TEMP_1, 1
	msgbox SlateportCity_Harbor_Text_ThisWillHelpResearch, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_Text_FerryServiceUnavailable:
	.string "Xin lỗi, bạn nói gì cơ? Bạn đang tìm tàu\n"
	.string "sao?\p"
	.string "Rất tiếc, hiện tại dịch vụ phà chưa hoạt\n"
	.string "động...$"

SlateportCity_Harbor_Text_MayISeeYourTicket:
	.string "Xin chào, bạn đến để đi phà phải không?\n"
	.string "Tôi có thể xem TICKET của bạn chứ?$"

SlateportCity_Harbor_Text_YouMustHaveTicket:
	.string "{PLAYER} không có TICKET...\p"
	.string "Tôi vô cùng xin lỗi.\p"
	.string "Bạn phải có TICKET mới được lên phà.$"

SlateportCity_Harbor_Text_FlashedTicketWhereTo:
	.string "{PLAYER} đưa TICKET ra.\p"
	.string "Tuyệt! Bạn chỉ cần thứ này là đủ!\p"
	.string "Vậy bạn muốn đi đâu?$"

SlateportCity_Harbor_Text_SailAnotherTime:
	.string "Mong bạn sẽ đi cùng chúng tôi vào dịp\n"
	.string "khác!$"

SlateportCity_Harbor_Text_LilycoveItIs:
	.string "Vậy thì đến LILYCOVE CITY!$"

SlateportCity_Harbor_Text_BattleFrontierItIs:
	.string "Vậy thì đến BATTLE FRONTIER!$"

SlateportCity_Harbor_Text_PleaseBoardFerry:
	.string "Xin hãy lên phà và chờ tàu khởi hành.$"

SlateportCity_Harbor_Text_WhereWouldYouLikeToGo:
	.string "Vậy bạn muốn đi đâu?$"

SlateportCity_Harbor_Text_LoveToGoDeepUnderwaterSomeday:
	.string "Một chuyến đi xuống tận đáy biển...\n"
	.string "Không biết sẽ như thế nào nhỉ?\p"
	.string "Một ngày nào đó, tôi rất muốn được lặn\n"
	.string "sâu dưới nước như vậy.$"

SlateportCity_Harbor_Text_AbnormalWeather:
	.string "Muốn tàu đi lại an toàn, chúng ta phải\n"
	.string "nắm rõ tình hình thời tiết!\p"
	.string "Nhắc đến thời tiết, tôi có nghe một\n"
	.string "người ở WEATHER INSTITUTE kể chuyện\l"
	.string "này.\p"
	.string "Anh ta nói thời tiết bất thường đang\n"
	.string "được ghi nhận ở khắp mọi nơi!\p"
	.string "Bạn nên đến WEATHER INSTITUTE và hỏi\n"
	.string "thăm xem sao!$"

SlateportCity_Harbor_Text_SubTooSmallForMe:
	.string "Tôi muốn cùng CAPT. STERN tham gia\n"
	.string "chuyến thám hiểm đáy biển.\p"
	.string "Nhưng chiếc tàu ngầm quá nhỏ đối với\n"
	.string "tôi.\p"
	.string "Nếu tôi cố chen vào thì sẽ chẳng còn\n"
	.string "chỗ cho CAPTAIN...$"

SlateportCity_Harbor_Text_SameThugsTriedToRobAtMuseum:
	.string "CAPT. STERN: Bọn côn đồ đó...\p"
	.string "Chính là đám đã tìm cách cướp DEVON\n"
	.string "GOODS tại MUSEUM.$"

SlateportCity_Harbor_Text_ArchieYouAgainHideoutInLilycove:
	.string "ARCHIE: Ồ? Lại là ngươi sao...\p"
	.string "Ta phải công nhận ngươi rất dai dẳng\n"
	.string "khi lần theo chúng ta đến tận đây.\p"
	.string "Nhưng giờ thì... Không ai có thể ngăn\n"
	.string "cản chúng ta! Không một ai!\p"
	.string "Hay là ngươi định đuổi theo chúng ta về\n"
	.string "tận HIDEOUT ở LILYCOVE CITY?\p"
	.string "Fwahahahaha...$"

SlateportCity_Harbor_Text_CaptSternWhyStealMySubmarine:
	.string "CAPT. STERN: Tại sao...\p"
	.string "Tại sao TEAM AQUA lại đánh cắp\n"
	.string "SUBMARINE EXPLORER 1 của tôi?\p"
	.string "Chẳng lẽ chúng đang nhắm đến POKéMON\n"
	.string "say ngủ dưới đáy biển...\p"
	.string "Nhưng dù có đuổi theo, tôi cũng không\n"
	.string "thể chống lại chúng...$"

SlateportCity_Harbor_Text_TeamAquaLeftNeedDive:
	.string "CAPT. STERN: Ôi, {PLAYER}{KUN}...\p"
	.string "Vậy sao... TEAM AQUA đã rời đi trước khi\n"
	.string "cậu kịp ngăn chúng...\p"
	.string "Không, đừng tự trách mình. Chuyện này\n"
	.string "không phải lỗi của cậu.\p"
	.string "Đuổi theo một chiếc tàu ngầm... Hầu hết\n"
	.string "mọi người đều không thể làm được.\p"
	.string "Cậu sẽ cần một POKéMON biết DIVE...\p"
	.string "Có lẽ nếu cậu đến MOSSDEEP CITY...\p"
	.string "Nơi đó có nhiều thợ lặn sinh sống, nên\n"
	.string "có thể ai đó sẽ dạy cậu...$"

SlateportCity_Harbor_Text_NeedDiveToCatchSub:
	.string "CAPT. STERN: Đuổi theo một chiếc tàu\n"
	.string "ngầm... Đó là chuyện không thể.\p"
	.string "Cậu sẽ cần một POKéMON biết DIVE...\p"
	.string "Có lẽ nếu cậu đến MOSSDEEP CITY...\p"
	.string "Nơi đó có nhiều thợ lặn sinh sống, nên\n"
	.string "có thể ai đó sẽ dạy cậu...$"

SlateportCity_Harbor_Text_WontBeLongBeforeWeFinishFerry:
	.string "CAPT. STERN: À, đúng rồi. MR. BRINEY đã\n"
	.string "đến SHIPYARD của chúng tôi.\p"
	.string "Chẳng bao lâu nữa chúng tôi sẽ đóng\n"
	.string "xong chiếc phà!$"

SlateportCity_Harbor_Text_FinishedMakingFerry:
	.string "CAPT. STERN: {PLAYER}{KUN}!\p"
	.string "Cuối cùng chúng tôi cũng đóng xong phà\n"
	.string "S.S. TIDAL!\p"
	.string "Chúng tôi không thể hoàn thành nó nếu\n"
	.string "thiếu người bạn MR. BRINEY của cậu.\p"
	.string "Hãy thử đi một chuyến du ngoạn ngắn\n"
	.string "trên phà nhé!$"

SlateportCity_Harbor_Text_WouldYouTradeScanner:
	.string "CAPT. STERN: Ồ? {PLAYER}{KUN}, món đồ\n"
	.string "cậu đang có...\p"
	.string "Đó là SCANNER! Nó chắc chắn sẽ giúp ích\n"
	.string "rất nhiều cho các chuyến thám hiểm của\l"
	.string "chúng tôi.\p"
	.string "{PLAYER}{KUN}, cậu có muốn đổi\n"
	.string "SCANNER lấy thứ gì đó không?\p"
	.string "Chẳng hạn như DEEPSEATOOTH hoặc\n"
	.string "DEEPSEASCALE mà tôi đang có?$"

SlateportCity_Harbor_Text_IfYouWantToTradeLetMeKnow:
	.string "CAPT. STERN: Cậu chắc chứ? Nó đâu có\n"
	.string "ích gì cho cậu, {PLAYER}{KUN}...\p"
	.string "Thôi được rồi. Nếu muốn đổi SCANNER\n"
	.string "thì hãy cho tôi biết.$"

SlateportCity_Harbor_Text_TradeForDeepSeaTooth:
	.string "CAPT. STERN: Vậy cậu sẽ đổi nó lấy\n"
	.string "DEEPSEATOOTH của tôi phải không?$"

SlateportCity_Harbor_Text_TradeForDeepSeaScale:
	.string "CAPT. STERN: Vậy cậu sẽ đổi nó lấy\n"
	.string "DEEPSEASCALE của tôi phải không?$"

SlateportCity_Harbor_Text_WhichOneDoYouWant:
	.string "CAPT. STERN: Cậu muốn món nào?$"

SlateportCity_Harbor_Text_HandedScannerToStern:
	.string "{PLAYER} trao SCANNER cho CAPT.\n"
	.string "STERN.$"

SlateportCity_Harbor_Text_ThisWillHelpResearch:
	.string "CAPT. STERN: Cảm ơn, {PLAYER}{KUN}!\n"
	.string "Thứ này sẽ giúp ích rất nhiều cho công\l"
	.string "việc nghiên cứu của chúng tôi!$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global SlateportCity_Harbor_Text_FerryServiceUnavailable
	.global SlateportCity_Harbor_Text_MayISeeYourTicket
	.global SlateportCity_Harbor_Text_YouMustHaveTicket
	.global SlateportCity_Harbor_Text_FlashedTicketWhereTo
	.global SlateportCity_Harbor_Text_SailAnotherTime
	.global SlateportCity_Harbor_Text_LilycoveItIs
	.global SlateportCity_Harbor_Text_BattleFrontierItIs
	.global SlateportCity_Harbor_Text_PleaseBoardFerry
	.global SlateportCity_Harbor_Text_WhereWouldYouLikeToGo
	.global SlateportCity_Harbor_Text_LoveToGoDeepUnderwaterSomeday
	.global SlateportCity_Harbor_Text_AbnormalWeather
	.global SlateportCity_Harbor_Text_SubTooSmallForMe
	.global SlateportCity_Harbor_Text_SameThugsTriedToRobAtMuseum
	.global SlateportCity_Harbor_Text_ArchieYouAgainHideoutInLilycove
	.global SlateportCity_Harbor_Text_CaptSternWhyStealMySubmarine
	.global SlateportCity_Harbor_Text_TeamAquaLeftNeedDive
	.global SlateportCity_Harbor_Text_NeedDiveToCatchSub
	.global SlateportCity_Harbor_Text_WontBeLongBeforeWeFinishFerry
	.global SlateportCity_Harbor_Text_FinishedMakingFerry
	.global SlateportCity_Harbor_Text_WouldYouTradeScanner
	.global SlateportCity_Harbor_Text_IfYouWantToTradeLetMeKnow
	.global SlateportCity_Harbor_Text_TradeForDeepSeaTooth
	.global SlateportCity_Harbor_Text_TradeForDeepSeaScale
	.global SlateportCity_Harbor_Text_WhichOneDoYouWant
	.global SlateportCity_Harbor_Text_HandedScannerToStern
	.global SlateportCity_Harbor_Text_ThisWillHelpResearch
@ END GENERATED LOCALIZATION EXPORTS
