BattleFrontier_ScottsHouse_MapScripts::
	.byte 0

BattleFrontier_ScottsHouse_EventScript_Scott::
	lock
	faceplayer
	goto_if_set FLAG_TEMP_4, BattleFrontier_ScottsHouse_EventScript_GivenBerry
	goto_if_set FLAG_TEMP_3, BattleFrontier_ScottsHouse_EventScript_GivenShield
	goto_if_set FLAG_TEMP_2, BattleFrontier_ScottsHouse_EventScript_GivenBattlePoints
	goto BattleFrontier_ScottsHouse_EventScript_CheckGiveItems
	end

BattleFrontier_ScottsHouse_EventScript_CheckGiveItems::
	goto_if_unset FLAG_SCOTT_GIVES_BATTLE_POINTS, BattleFrontier_ScottsHouse_EventScript_WelcomeToFrontier
	goto_if_unset FLAG_COLLECTED_ALL_SILVER_SYMBOLS, BattleFrontier_ScottsHouse_EventScript_CheckSilverSymbols
	goto_if_unset FLAG_COLLECTED_ALL_GOLD_SYMBOLS, BattleFrontier_ScottsHouse_EventScript_CheckGoldSymbols
	goto BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	end

BattleFrontier_ScottsHouse_EventScript_CheckGiveShield::
	goto_if_unset FLAG_RECEIVED_SILVER_SHIELD, BattleFrontier_ScottsHouse_EventScript_CheckGiveSilverShield
	goto_if_unset FLAG_RECEIVED_GOLD_SHIELD, BattleFrontier_ScottsHouse_EventScript_CheckGiveGoldShield
	goto BattleFrontier_ScottsHouse_EventScript_RandomComment
	end

BattleFrontier_ScottsHouse_EventScript_CheckSilverSymbols::
	goto_if_unset FLAG_SYS_TOWER_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_DOME_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_PALACE_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_ARENA_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_FACTORY_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_PIKE_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_PYRAMID_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	msgbox BattleFrontier_ScottsHouse_Text_YouveCollectedAllSilverSymbols, MSGBOX_DEFAULT
	giveitem ITEM_LANSAT_BERRY
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_ScottsHouse_EventScript_BerryPocketFull
	setflag FLAG_COLLECTED_ALL_SILVER_SYMBOLS
	setflag FLAG_TEMP_4
	release
	end

BattleFrontier_ScottsHouse_EventScript_CheckGoldSymbols::
	goto_if_unset FLAG_SYS_TOWER_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_DOME_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_PALACE_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_ARENA_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_FACTORY_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_PIKE_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_PYRAMID_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	msgbox BattleFrontier_ScottsHouse_Text_YouveCollectedAllGoldSymbols, MSGBOX_DEFAULT
	giveitem ITEM_STARF_BERRY
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_ScottsHouse_EventScript_BerryPocketFull
	setflag FLAG_COLLECTED_ALL_GOLD_SYMBOLS
	setflag FLAG_TEMP_4
	release
	end

BattleFrontier_ScottsHouse_EventScript_BerryPocketFull::
	msgbox BattleFrontier_ScottsHouse_Text_BerryPocketStuffed, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_GivenBerry::
	msgbox BattleFrontier_ScottsHouse_Text_SoGladIBroughtYouHere, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_RandomComment::
	random 3
	goto_if_eq VAR_RESULT, 1, BattleFrontier_ScottsHouse_EventScript_FrontierBrainComment
	goto_if_eq VAR_RESULT, 2, BattleFrontier_ScottsHouse_EventScript_ArtisanCaveComment
	msgbox BattleFrontier_ScottsHouse_Text_WhyIGoSeekingTrainers, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_FrontierBrainComment::
	msgbox BattleFrontier_ScottsHouse_Text_HaveYouMetFrontierBrain, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_ArtisanCaveComment::
	msgbox BattleFrontier_ScottsHouse_Text_MayFindWildMonsInFrontier, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_CheckGiveSilverShield::
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_50
	tower_get TOWER_DATA_WIN_STREAK
	goto_if_ge VAR_RESULT, 50, BattleFrontier_ScottsHouse_EventScript_GiveSilverShield
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_OPEN
	tower_get TOWER_DATA_WIN_STREAK
	goto_if_ge VAR_RESULT, 50, BattleFrontier_ScottsHouse_EventScript_GiveSilverShield
	goto BattleFrontier_ScottsHouse_EventScript_RandomComment
	end

BattleFrontier_ScottsHouse_EventScript_GiveSilverShield::
	msgbox BattleFrontier_ScottsHouse_Text_Beat50TrainersInARow, MSGBOX_DEFAULT
	givedecoration DECOR_SILVER_SHIELD
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_ScottsHouse_EventScript_NoRoomForShield
	setflag FLAG_RECEIVED_SILVER_SHIELD
	setflag FLAG_TEMP_3
	goto BattleFrontier_ScottsHouse_EventScript_GivenShield
	end

BattleFrontier_ScottsHouse_EventScript_NoRoomForShield::
	msgbox BattleFrontier_ScottsHouse_Text_ComeBackForThisLater, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_GivenShield::
	msgbox BattleFrontier_ScottsHouse_Text_ExpectingToHearEvenGreaterThings, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_CheckGiveGoldShield::
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_50
	tower_get TOWER_DATA_WIN_STREAK
	goto_if_ge VAR_RESULT, 100, BattleFrontier_ScottsHouse_EventScript_GiveGoldShield
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_OPEN
	tower_get TOWER_DATA_WIN_STREAK
	goto_if_ge VAR_RESULT, 100, BattleFrontier_ScottsHouse_EventScript_GiveGoldShield
	goto BattleFrontier_ScottsHouse_EventScript_RandomComment
	end

BattleFrontier_ScottsHouse_EventScript_GiveGoldShield::
	msgbox BattleFrontier_ScottsHouse_Text_Beat100TrainersInARow, MSGBOX_DEFAULT
	givedecoration DECOR_GOLD_SHIELD
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_ScottsHouse_EventScript_NoRoomForShield
	setflag FLAG_RECEIVED_GOLD_SHIELD
	setflag FLAG_TEMP_3
	goto BattleFrontier_ScottsHouse_EventScript_GivenShield
	end

BattleFrontier_ScottsHouse_EventScript_GivenBattlePoints::
	msgbox BattleFrontier_ScottsHouse_Text_ExpectingGreatThings, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_WelcomeToFrontier::
	msgbox BattleFrontier_ScottsHouse_Text_WelcomeToBattleFrontier, MSGBOX_DEFAULT
	closemessage
	delay 30
	call_if_eq VAR_FACING, DIR_NORTH, BattleFrontier_ScottsHouse_EventScript_ScottFaceAwayNorth
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_ScottsHouse_EventScript_ScottFaceAwaySouth
	call_if_eq VAR_FACING, DIR_EAST, BattleFrontier_ScottsHouse_EventScript_ScottFaceAwayEast
	call_if_eq VAR_FACING, DIR_WEST, BattleFrontier_ScottsHouse_EventScript_ScottFaceAwayWest
	msgbox BattleFrontier_ScottsHouse_Text_HowMuchEffortItTookToMakeReal, MSGBOX_DEFAULT
	applymovement LOCALID_SCOTTS_HOUSE_SCOTT, Common_Movement_FacePlayer
	waitmovement 0
	msgbox BattleFrontier_ScottsHouse_Text_HaveThisAsMementoOfOurPathsCrossing, MSGBOX_DEFAULT
	goto_if_eq VAR_SCOTT_STATE, 13, BattleFrontier_ScottsHouse_EventScript_Give4BattlePoints
	goto_if_ge VAR_SCOTT_STATE, 9, BattleFrontier_ScottsHouse_EventScript_Give3BattlePoints
	goto_if_ge VAR_SCOTT_STATE, 6, BattleFrontier_ScottsHouse_EventScript_Give2BattlePoints
	goto BattleFrontier_ScottsHouse_EventScript_Give1BattlePoint
	end

BattleFrontier_ScottsHouse_EventScript_Give4BattlePoints::
	buffernumberstring STR_VAR_1, 4
	setvar VAR_0x8004, 4
	goto BattleFrontier_ScottsHouse_EventScript_GiveBattlePoints
	end

BattleFrontier_ScottsHouse_EventScript_Give3BattlePoints::
	buffernumberstring STR_VAR_1, 3
	setvar VAR_0x8004, 3
	goto BattleFrontier_ScottsHouse_EventScript_GiveBattlePoints
	end

BattleFrontier_ScottsHouse_EventScript_Give2BattlePoints::
	buffernumberstring STR_VAR_1, 2
	setvar VAR_0x8004, 2
	goto BattleFrontier_ScottsHouse_EventScript_GiveBattlePoints
	end

BattleFrontier_ScottsHouse_EventScript_Give1BattlePoint::
	buffernumberstring STR_VAR_1, 1
	setvar VAR_0x8004, 1
	goto BattleFrontier_ScottsHouse_EventScript_GiveBattlePoints
	end

BattleFrontier_ScottsHouse_EventScript_GiveBattlePoints::
	special GiveFrontierBattlePoints
	msgbox BattleFrontier_ScottsHouse_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	msgbox BattleFrontier_ScottsHouse_Text_ExplainBattlePoints, MSGBOX_DEFAULT
	setflag FLAG_SCOTT_GIVES_BATTLE_POINTS
	setflag FLAG_TEMP_2
	release
	end

BattleFrontier_ScottsHouse_EventScript_ScottFaceAwayNorth::
	applymovement LOCALID_SCOTTS_HOUSE_SCOTT, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

BattleFrontier_ScottsHouse_EventScript_ScottFaceAwaySouth::
	applymovement LOCALID_SCOTTS_HOUSE_SCOTT, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

BattleFrontier_ScottsHouse_EventScript_ScottFaceAwayEast::
	applymovement LOCALID_SCOTTS_HOUSE_SCOTT, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

BattleFrontier_ScottsHouse_EventScript_ScottFaceAwayWest::
	applymovement LOCALID_SCOTTS_HOUSE_SCOTT, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

BattleFrontier_ScottsHouse_Text_WelcomeToBattleFrontier:
	.string "SCOTT: Chào cậu, hoan nghênh cậu!\n"
	.string "Heheh... Xin lỗi vì chỗ này hơi chật.\p"
	.string "Dù sao thì, {PLAYER}{KUN}, cho phép\n"
	.string "tôi chính thức chào mừng cậu đến\l"
	.string "BATTLE FRONTIER.\p"
	.string "Đây là giấc mơ của tôi đã thành hiện\n"
	.string "thực. Tôi đã mất hết năm này qua năm\l"
	.string "khác, nhưng cuối cùng cũng biến được\l"
	.string "giấc mơ ấy thành hình.$"

BattleFrontier_ScottsHouse_Text_HowMuchEffortItTookToMakeReal:
	.string "Nghĩ lại, đó quả là một hành trình dài\n"
	.string "đằng đẵng...\p"
	.string "Tôi một mình rời quê nhà để tìm kiếm\n"
	.string "những HLV mạnh mẽ.\p"
	.string "Không ai có thể tưởng tượng được tôi\n"
	.string "đã mất bao nhiêu công sức và thời gian\l"
	.string "để biến nơi này thành hiện thực.$"

BattleFrontier_ScottsHouse_Text_HaveThisAsMementoOfOurPathsCrossing:
	.string "Nhưng tất cả đã là chuyện quá khứ.\n"
	.string "Chẳng cần bận lòng về nó nữa!\p"
	.string "Tôi chỉ mong cậu có thể thỏa sức tận\n"
	.string "hưởng các trận đấu tại đây.\p"
	.string "{PLAYER}{KUN}, tôi muốn cậu nhận lấy\n"
	.string "món này làm kỷ niệm cho bao lần chúng ta\l"
	.string "gặp nhau trên hành trình.$"

BattleFrontier_ScottsHouse_Text_ObtainedXBattlePoints:
	.string "{PLAYER} đã nhận được\n"
	.string "{STR_VAR_1} Battle Point(s).$"

BattleFrontier_ScottsHouse_Text_ExplainBattlePoints:
	.string "SCOTT: Cậu có thể kiểm tra Battle\n"
	.string "Points trên FRONTIER PASS.\p"
	.string "Càng thành công tại BATTLE FRONTIER,\n"
	.string "cậu càng tích lũy được nhiều Battle\l"
	.string "Points.\p"
	.string "Hãy dùng Battle Points theo cách cậu\n"
	.string "muốn, chẳng hạn như đổi chúng lấy vật\l"
	.string "phẩm.$"

BattleFrontier_ScottsHouse_Text_ExpectingGreatThings:
	.string "Tôi rất kỳ vọng vào cậu!$"

BattleFrontier_ScottsHouse_Text_WhyIGoSeekingTrainers:
	.string "SCOTT: Mỗi HLV đều là một con\n"
	.string "người riêng biệt. Ai cũng có cuộc sống\l"
	.string "của riêng mình.\p"
	.string "Nhưng khi bước vào trận đấu, họ là ai\n"
	.string "không còn quan trọng.\p"
	.string "Tất cả đều như nhau!\p"
	.string "Tôi yêu sự thuần khiết của trận đấu,\n"
	.string "nơi mọi người đều bình đẳng.\p"
	.string "Vì thế, tôi đi khắp nơi tìm kiếm những\n"
	.string "HLV nghiêm túc với việc thi đấu và\l"
	.string "mời họ đến đây.$"

BattleFrontier_ScottsHouse_Text_HaveYouMetFrontierBrain:
	.string "SCOTT: Cậu đã gặp ai trong số FRONTIER\n"
	.string "BRAINS chưa?\p"
	.string "Hay tuyệt hơn nữa, cậu đã giành được\n"
	.string "biểu tượng nào từ họ chưa?\p"
	.string "Tôi đã đích thân chọn FRONTIER BRAINS\n"
	.string "từ những HLV mạnh nhất khắp nơi.\p"
	.string "Nhưng tôi tin rằng ngay cả họ cũng sẽ\n"
	.string "sửng sốt khi chứng kiến sức mạnh của\l"
	.string "cậu!$"

BattleFrontier_ScottsHouse_Text_MayFindWildMonsInFrontier:
	.string "SCOTT: Cậu đâu chỉ luyện tập để chiến\n"
	.string "đấu, đúng không?\p"
	.string "Hình như tôi còn nhớ cậu đang hoàn\n"
	.string "thiện một POKéDEX nữa.\p"
	.string "Này, đoán xem?\p"
	.string "Có thể cậu sẽ bắt gặp POKéMON hoang dã\n"
	.string "ở đâu đó trong BATTLE FRONTIER...\l"
	.string "Fufufu!$"

BattleFrontier_ScottsHouse_Text_YouveCollectedAllSilverSymbols:
	.string "SCOTT: Cậu có đang tận hưởng BATTLE\n"
	.string "FRONTIER không?\p"
	.string "...Khoan đã... Ồ!\p"
	.string "FRONTIER PASS của cậu! Cậu đã thu thập\n"
	.string "đủ bộ biểu tượng bạc rồi!\p"
	.string "Thật hơn cả ấn tượng! Cậu quả nhiên\n"
	.string "rất mạnh, đúng như tôi nghĩ!\p"
	.string "Bình thường tôi sẽ không làm thế này,\n"
	.string "nhưng đây là một dịp đặc biệt!\p"
	.string "Tôi muốn cậu nhận lấy món này. Tôi tin\n"
	.string "cậu sẽ sử dụng nó thật hữu ích.$"

BattleFrontier_ScottsHouse_Text_YouveCollectedAllGoldSymbols:
	.string "SCOTT: Tôi hy vọng cậu đang tận hưởng\n"
	.string "mọi thứ tại BATTLE FRONTIER.\p"
	.string "...Khoan đã... Ôi, mắt tôi không thể tin\n"
	.string "nổi!\p"
	.string "FRONTIER PASS của cậu! Cậu đã thu thập\n"
	.string "đủ bộ biểu tượng vàng rồi!\p"
	.string "Thật hơn cả phi thường! Cậu quả nhiên\n"
	.string "tuyệt vời, đúng như tôi nghĩ!\p"
	.string "... ... ... ... ... ...\p"
	.string "{PLAYER}, cậu nhất định phải nhận món\n"
	.string "này!\p"
	.string "Tôi tin cậu sẽ hiểu được giá trị món quà\n"
	.string "của tôi!$"

BattleFrontier_ScottsHouse_Text_SoGladIBroughtYouHere:
	.string "Phải nói rằng tôi rất có tài nhận ra một\n"
	.string "HLV giỏi ngay khi gặp họ.\p"
	.string "Tôi thật mừng vì đã sáng suốt đưa cậu\n"
	.string "đến đây!$"

BattleFrontier_ScottsHouse_Text_BerryPocketStuffed:
	.string "BERRY POCKET của bạn có vẻ đã đầy ắp.$"

BattleFrontier_ScottsHouse_Text_Beat50TrainersInARow:
	.string "SCOTT: Ồ, tôi nghe chuyện về cậu rồi!\n"
	.string "Cậu đã thống trị BATTLE TOWER! Cậu\l"
	.string "đánh bại hơn 50 HLV liên tiếp sao?\p"
	.string "Tuyệt vời! Tôi muốn cậu nhận lấy món\n"
	.string "này!$"

BattleFrontier_ScottsHouse_Text_Beat100TrainersInARow:
	.string "SCOTT: Trời ơi! Tôi nghe chuyện về cậu\n"
	.string "rồi! Cậu đã áp đảo hoàn toàn BATTLE\l"
	.string "TOWER! Cậu đánh bại hơn 100 HLV\l"
	.string "liên tiếp sao?\p"
	.string "Quá sức ngoạn mục! Cậu nhất định phải\n"
	.string "nhận món này!$"

BattleFrontier_ScottsHouse_Text_ExpectingToHearEvenGreaterThings:
	.string "Từ giờ tôi sẽ mong được nghe những\n"
	.string "thành tích còn vĩ đại hơn nữa của cậu!$"

BattleFrontier_ScottsHouse_Text_ComeBackForThisLater:
	.string "Ôi, nếu đồ đạc của cậu nhiều quá thì hãy\n"
	.string "quay lại nhận món này sau nhé.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global BattleFrontier_ScottsHouse_Text_WelcomeToBattleFrontier
	.global BattleFrontier_ScottsHouse_Text_HowMuchEffortItTookToMakeReal
	.global BattleFrontier_ScottsHouse_Text_HaveThisAsMementoOfOurPathsCrossing
	.global BattleFrontier_ScottsHouse_Text_ObtainedXBattlePoints
	.global BattleFrontier_ScottsHouse_Text_ExplainBattlePoints
	.global BattleFrontier_ScottsHouse_Text_ExpectingGreatThings
	.global BattleFrontier_ScottsHouse_Text_WhyIGoSeekingTrainers
	.global BattleFrontier_ScottsHouse_Text_HaveYouMetFrontierBrain
	.global BattleFrontier_ScottsHouse_Text_MayFindWildMonsInFrontier
	.global BattleFrontier_ScottsHouse_Text_YouveCollectedAllSilverSymbols
	.global BattleFrontier_ScottsHouse_Text_YouveCollectedAllGoldSymbols
	.global BattleFrontier_ScottsHouse_Text_SoGladIBroughtYouHere
	.global BattleFrontier_ScottsHouse_Text_BerryPocketStuffed
	.global BattleFrontier_ScottsHouse_Text_Beat50TrainersInARow
	.global BattleFrontier_ScottsHouse_Text_Beat100TrainersInARow
	.global BattleFrontier_ScottsHouse_Text_ExpectingToHearEvenGreaterThings
	.global BattleFrontier_ScottsHouse_Text_ComeBackForThisLater
@ END GENERATED LOCALIZATION EXPORTS
