BattleFrontier_Lounge3_MapScripts::
	.byte 0

	.set BET_AMOUNT_5,  5
	.set BET_AMOUNT_10, 10
	.set BET_AMOUNT_15, 15

BattleFrontier_Lounge3_EventScript_Gambler::
	lock
	faceplayer
	goto_if_set FLAG_MET_BATTLE_FRONTIER_GAMBLER, BattleFrontier_Lounge3_EventScript_AlreadyMetGambler
	call BattleFrontier_Lounge3_EventScript_CountSilverSymbols
	goto_if_le VAR_0x8004, 2, BattleFrontier_Lounge3_EventScript_NotEnoughSilverSymbols
	setflag FLAG_MET_BATTLE_FRONTIER_GAMBLER
	msgbox BattleFrontier_Lounge3_Text_YouLookToughExplainGambling, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_AskToEnterChallenge
	end

BattleFrontier_Lounge3_EventScript_AskToEnterChallenge::
	special ShowFrontierGamblerLookingMessage
	waitmessage
	waitbuttonpress
	msgbox BattleFrontier_Lounge3_Text_HowAboutEnteringEventForMe, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge3_EventScript_DeclineChallenge
	msgbox BattleFrontier_Lounge3_Text_SpotMeSomeBattlePoints, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge3_EventScript_DeclineChallenge
	message BattleFrontier_Lounge3_Text_HowMuchCanYouSpot
	waitmessage
	special ShowBattlePointsWindow
	goto BattleFrontier_Lounge3_EventScript_ChooseBetAmount
	end

BattleFrontier_Lounge3_EventScript_ChooseBetAmount::
	multichoice 20, 4, MULTI_FRONTIER_GAMBLER_BET, FALSE
	copyvar VAR_FRONTIER_GAMBLER_AMOUNT_BET, VAR_RESULT
	switch VAR_RESULT
	case FRONTIER_GAMBLER_BET_5, BattleFrontier_Lounge3_EventScript_Bet5
	case FRONTIER_GAMBLER_BET_10, BattleFrontier_Lounge3_EventScript_Bet10
	case FRONTIER_GAMBLER_BET_15, BattleFrontier_Lounge3_EventScript_Bet15
	case FRONTIER_GAMBLER_BET_CANCEL, BattleFrontier_Lounge3_EventScript_CancelBet
	case MULTI_B_PRESSED, BattleFrontier_Lounge3_EventScript_CancelBet
	end

BattleFrontier_Lounge3_EventScript_Bet5::
	setvar VAR_0x8008, BET_AMOUNT_5
	goto BattleFrontier_Lounge3_EventScript_TryPlaceBet
	end

BattleFrontier_Lounge3_EventScript_Bet10::
	setvar VAR_0x8008, BET_AMOUNT_10
	goto BattleFrontier_Lounge3_EventScript_TryPlaceBet
	end

BattleFrontier_Lounge3_EventScript_Bet15::
	setvar VAR_0x8008, BET_AMOUNT_15
	goto BattleFrontier_Lounge3_EventScript_TryPlaceBet
	end

BattleFrontier_Lounge3_EventScript_TryPlaceBet::
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
	goto_if_ge VAR_TEMP_1, VAR_0x8008, BattleFrontier_Lounge3_EventScript_PlaceBet
	msgbox BattleFrontier_Lounge3_Text_YouDontHaveEnoughPoints, MSGBOX_DEFAULT
	message BattleFrontier_Lounge3_Text_HowMuchCanYouSpot
	waitmessage
	goto BattleFrontier_Lounge3_EventScript_ChooseBetAmount
	end

BattleFrontier_Lounge3_EventScript_PlaceBet::
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	setvar VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_PLACED_BET
	special UpdateBattlePointsWindow
	playse SE_SHOP
	msgbox BattleFrontier_Lounge3_Text_ThanksOffYouGo, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FinishBet
	end

BattleFrontier_Lounge3_EventScript_FinishBet::
	special ShowFrontierGamblerGoMessage
	waitmessage
	waitbuttonpress
	special CloseBattlePointsWindow
	release
	end

BattleFrontier_Lounge3_EventScript_CountSilverSymbols::
	setvar VAR_0x8004, 0
	call_if_set FLAG_SYS_TOWER_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_DOME_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_PALACE_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_ARENA_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_FACTORY_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_PIKE_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_PYRAMID_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	return

BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount::
	addvar VAR_0x8004, 1
	return

BattleFrontier_Lounge3_EventScript_NotEnoughSilverSymbols::
	msgbox BattleFrontier_Lounge3_Text_CantYouSeeWereBusyHere, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection
	end

BattleFrontier_Lounge3_EventScript_AlreadyMetGambler::
	msgbox BattleFrontier_Lounge3_Text_Oh, MSGBOX_DEFAULT
	goto_if_ge VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_PLACED_BET, BattleFrontier_Lounge3_EventScript_CheckBetResults
	goto BattleFrontier_Lounge3_EventScript_AskToEnterChallenge
	end

BattleFrontier_Lounge3_EventScript_CheckBetResults::
	goto_if_eq VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_PLACED_BET, BattleFrontier_Lounge3_EventScript_ChallengeNotAttempted
	goto_if_eq VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_WON, BattleFrontier_Lounge3_EventScript_WonChallenge
	goto BattleFrontier_Lounge3_EventScript_LostChallenge
	end

BattleFrontier_Lounge3_EventScript_WonChallenge::
	msgbox BattleFrontier_Lounge3_Text_HelloChampHeresYourPoints, MSGBOX_DEFAULT
	call_if_eq VAR_FRONTIER_GAMBLER_AMOUNT_BET, FRONTIER_GAMBLER_BET_5, BattleFrontier_Lounge3_EventScript_RewardBet5
	call_if_eq VAR_FRONTIER_GAMBLER_AMOUNT_BET, FRONTIER_GAMBLER_BET_10, BattleFrontier_Lounge3_EventScript_RewardBet10
	call_if_eq VAR_FRONTIER_GAMBLER_AMOUNT_BET, FRONTIER_GAMBLER_BET_15, BattleFrontier_Lounge3_EventScript_RewardBet15
	msgbox BattleFrontier_Lounge3_Text_ObtainedBattlePoints, MSGBOX_GETPOINTS
	special GiveFrontierBattlePoints
	msgbox BattleFrontier_Lounge3_Text_ThinkOfMeForAnotherChallenge, MSGBOX_DEFAULT
	setvar VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_WAITING
	release
	end

BattleFrontier_Lounge3_EventScript_LostChallenge::
	msgbox BattleFrontier_Lounge3_Text_NiceTryCantReturnPoints, MSGBOX_DEFAULT
	setvar VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_WAITING
	release
	end

BattleFrontier_Lounge3_EventScript_RewardBet5::
	buffernumberstring STR_VAR_1, (BET_AMOUNT_5 * 2)
	setvar VAR_0x8004, (BET_AMOUNT_5 * 2)
	return

BattleFrontier_Lounge3_EventScript_RewardBet10::
	buffernumberstring STR_VAR_1, (BET_AMOUNT_10 * 2)
	setvar VAR_0x8004, (BET_AMOUNT_10 * 2)
	return

BattleFrontier_Lounge3_EventScript_RewardBet15::
	buffernumberstring STR_VAR_1, (BET_AMOUNT_15 * 2)
	setvar VAR_0x8004, (BET_AMOUNT_15 * 2)
	return

BattleFrontier_Lounge3_EventScript_ChallengeNotAttempted::
	special ShowFrontierGamblerGoMessage
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge3_EventScript_DeclineChallenge::
	msgbox BattleFrontier_Lounge3_Text_NotInterested, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge3_EventScript_CancelBet::
	special CloseBattlePointsWindow
	goto BattleFrontier_Lounge3_EventScript_DeclineChallenge
	end

BattleFrontier_Lounge3_EventScript_Man::
	msgbox BattleFrontier_Lounge3_Text_ShouldBeTakingChallenges, MSGBOX_NPC
	end

BattleFrontier_Lounge3_EventScript_Woman::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge3_Text_BackedWrongTrainer, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection
	end

BattleFrontier_Lounge3_EventScript_PokefanF::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge3_Text_KnowWinnerWhenISeeOne, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection
	end

BattleFrontier_Lounge3_EventScript_FatMan::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge3_Text_TrainerGoodButRattled, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection
	end

BattleFrontier_Lounge3_EventScript_FaceOriginalDirection::
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

BattleFrontier_Lounge3_Text_CantYouSeeWereBusyHere::
	.string "...Bạn muốn gì?\p"
	.string "Không thấy bọn tôi đang khá bận sao?\n"
	.string "Chuyện của bạn không để sau được à?$"

BattleFrontier_Lounge3_Text_YouLookToughExplainGambling::
	.string "...Hả? Trông bạn có vẻ là một HLV\n"
	.string "mạnh đấy.\p"
	.string "Hê hê... Nghe này, tôi có một đề nghị.\p"
	.string "Bọn tôi có một nhóm nhỏ ở đây, cùng\n"
	.string "chơi một trò dựa trên những gì diễn ra\l"
	.string "tại BATTLE FRONTIER.\p"
	.string "Luật rất đơn giản.\p"
	.string "Trước tiên, bọn tôi chọn một cơ sở\n"
	.string "trong BATTLE FRONTIER.\p"
	.string "Sau đó, mỗi người chọn một HLV\n"
	.string "khác nhau đang tham gia thử thách tại\l"
	.string "cơ sở đó rồi đặt cược bằng Battle\l"
	.string "Points.\p"
	.string "Người cược vào HLV có thành tích\n"
	.string "tốt nhất sẽ lấy toàn bộ Battle Points\l"
	.string "trong quỹ.\p"
	.string "Nghe đơn giản nhỉ? Vậy nên...$"

BattleFrontier_Lounge3_Text_ChallengeBattleTowerSingle::
	.string "Tôi đang tìm một HLV sắp thách đấu\n"
	.string "SINGLE BATTLE ROOMS của BATTLE TOWER.\p"
	.string "Nhưng đến giờ tôi vẫn chưa thấy\n"
	.string "HLV nào có tố chất chiến thắng.$"

BattleFrontier_Lounge3_Text_ChallengeBattleTowerDouble::
	.string "Tôi đang tìm một HLV sắp thách đấu\n"
	.string "DOUBLE BATTLE ROOMS của BATTLE TOWER.\p"
	.string "Nhưng đến giờ tôi vẫn chưa thấy\n"
	.string "HLV nào có tố chất chiến thắng.$"

BattleFrontier_Lounge3_Text_ChallengeBattleTowerMulti::
	.string "Tôi đang tìm một HLV sắp thách đấu\n"
	.string "MULTI BATTLE ROOMS của BATTLE TOWER.\p"
	.string "Nhưng đến giờ tôi vẫn chưa thấy\n"
	.string "HLV nào có tố chất chiến thắng.$"

BattleFrontier_Lounge3_Text_ChallengeBattleDomeSingle::
	.string "Tôi đang tìm một HLV sắp tham gia\n"
	.string "giải đấu SINGLE BATTLE của BATTLE\l"
	.string "DOME.\p"
	.string "Nhưng đến giờ tôi vẫn chưa thấy\n"
	.string "HLV nào có tố chất chiến thắng.$"

BattleFrontier_Lounge3_Text_ChallengeBattleDomeDouble::
	.string "Tôi đang tìm một HLV sẽ tham gia\n"
	.string "giải DOUBLE BATTLE của BATTLE DOME.\p"
	.string "Nhưng đến giờ, tôi vẫn chưa thấy\n"
	.string "HLV nào có khí chất của người\l"
	.string "chiến thắng.$"

BattleFrontier_Lounge3_Text_ChallengeBattleFactorySingle::
	.string "Tôi đang tìm một HLV sẽ tham gia\n"
	.string "Battle Swap Single Tourney của BATTLE\l"
	.string "FACTORY.\p"
	.string "Nhưng đến giờ, tôi vẫn chưa thấy\n"
	.string "HLV nào có khí chất của người\l"
	.string "chiến thắng.$"

BattleFrontier_Lounge3_Text_ChallengeBattleFactoryDouble::
	.string "Tôi đang tìm một HLV sẽ tham gia\n"
	.string "Battle Swap Double Tourney của BATTLE\l"
	.string "FACTORY.\p"
	.string "Nhưng đến giờ, tôi vẫn chưa thấy\n"
	.string "HLV nào có khí chất của người\l"
	.string "chiến thắng.$"

BattleFrontier_Lounge3_Text_ChallengeBattlePalaceSingle::
	.string "Tôi đang tìm một HLV sẽ thử sức\n"
	.string "tại SINGLE BATTLE HALLS của BATTLE\l"
	.string "PALACE.\p"
	.string "Nhưng đến giờ, tôi vẫn chưa thấy\n"
	.string "HLV nào có khí chất của người\l"
	.string "chiến thắng.$"

BattleFrontier_Lounge3_Text_ChallengeBattlePalaceDouble::
	.string "Tôi đang tìm một HLV sẽ thử sức\n"
	.string "tại DOUBLE BATTLE HALLS của BATTLE\l"
	.string "PALACE.\p"
	.string "Nhưng đến giờ, tôi vẫn chưa thấy\n"
	.string "HLV nào có khí chất của người\l"
	.string "chiến thắng.$"

BattleFrontier_Lounge3_Text_ChallengeBattleArena::
	.string "Tôi đang tìm một HLV sẽ tham gia\n"
	.string "Set KO Tourney của BATTLE ARENA.\p"
	.string "Nhưng đến giờ, tôi vẫn chưa thấy\n"
	.string "HLV nào có khí chất của người\l"
	.string "chiến thắng.$"

BattleFrontier_Lounge3_Text_ChallengeBattlePike::
	.string "Tôi đang tìm một HLV sẽ tham gia\n"
	.string "Battle Choice của BATTLE PIKE.\p"
	.string "Nhưng đến giờ, tôi vẫn chưa thấy\n"
	.string "HLV nào có khí chất của người\l"
	.string "chiến thắng.$"

BattleFrontier_Lounge3_Text_ChallengeBattlePyramid::
	.string "Tôi đang tìm một HLV sẽ tham gia\n"
	.string "Battle Quest của BATTLE PYRAMID.\p"
	.string "Nhưng đến giờ, tôi vẫn chưa thấy\n"
	.string "HLV nào có khí chất của người\l"
	.string "chiến thắng.$"

BattleFrontier_Lounge3_Text_HowAboutEnteringEventForMe::
	.string "Tôi cũng sẽ bảo đảm cậu được hưởng\n"
	.string "lợi. Thế nào? Cậu tham gia sự kiện đó\l"
	.string "giúp tôi nhé?$"

BattleFrontier_Lounge3_Text_SpotMeSomeBattlePoints::
	.string "Được rồi, hoàn hảo! Vậy thì, cậu cho tôi\n"
	.string "vay một ít Battle Points được không?\p"
	.string "Tin tôi đi, sau đó tôi sẽ hậu tạ cậu.$"

BattleFrontier_Lounge3_Text_HowMuchCanYouSpot::
	.string "Tuyệt, tuyệt lắm! Vậy cậu có thể cho tôi\n"
	.string "vay bao nhiêu?$"

BattleFrontier_Lounge3_Text_YouDontHaveEnoughPoints::
	.string "Ôi, không, không, không! Cậu không có đủ\n"
	.string "Battle Points!\p"
	.string "Đừng làm trò khỉ rồi phí thời gian của\n"
	.string "mọi người chứ!$"

BattleFrontier_Lounge3_Text_ThanksOffYouGo::
	.string "Hê hê! Cảm ơn nhiều! Giờ thì lên đường\n"
	.string "đi!$"

BattleFrontier_Lounge3_Text_GetToBattleTowerSingle::
	.string "Đến SINGLE BATTLE ROOMS của BATTLE\n"
	.string "TOWER ngay!\p"
	.string "Trận này nhất định phải thắng! Đừng bỏ\n"
	.string "lỡ cơ hội! Tương lai của cả hai ta phụ\l"
	.string "thuộc vào cậu!$"

BattleFrontier_Lounge3_Text_GetToBattleTowerDouble::
	.string "Đến DOUBLE BATTLE ROOMS của BATTLE\n"
	.string "TOWER ngay!\p"
	.string "Trận này nhất định phải thắng! Đừng bỏ\n"
	.string "lỡ cơ hội! Tương lai của cả hai ta phụ\l"
	.string "thuộc vào cậu!$"

BattleFrontier_Lounge3_Text_GetToBattleTowerMulti::
	.string "Đến MULTI BATTLE ROOMS của BATTLE\n"
	.string "TOWER ngay!\p"
	.string "Trận này nhất định phải thắng! Đừng bỏ\n"
	.string "lỡ cơ hội! Tương lai của cả hai ta phụ\l"
	.string "thuộc vào cậu!$"

BattleFrontier_Lounge3_Text_GetToBattleDomeSingle::
	.string "Đến giải SINGLE BATTLE của BATTLE DOME\n"
	.string "ngay!\p"
	.string "Trận này nhất định phải thắng! Đừng bỏ\n"
	.string "lỡ cơ hội! Tương lai của cả hai ta phụ\l"
	.string "thuộc vào cậu!$"

BattleFrontier_Lounge3_Text_GetToBattleDomeDouble::
	.string "Đến giải DOUBLE BATTLE của BATTLE DOME\n"
	.string "ngay!\p"
	.string "Trận này nhất định phải thắng! Đừng bỏ\n"
	.string "lỡ cơ hội! Tương lai của cả hai ta phụ\l"
	.string "thuộc vào cậu!$"

BattleFrontier_Lounge3_Text_GetToBattleFactorySingle::
	.string "Đến Battle Swap Single Tourney của\n"
	.string "BATTLE FACTORY ngay!\p"
	.string "Trận này nhất định phải thắng! Đừng bỏ\n"
	.string "lỡ cơ hội! Tương lai của cả hai ta phụ\l"
	.string "thuộc vào cậu!$"

BattleFrontier_Lounge3_Text_GetToBattleFactoryDouble::
	.string "Đến Battle Swap Double Tourney của\n"
	.string "BATTLE FACTORY ngay!\p"
	.string "Trận này nhất định phải thắng! Đừng bỏ\n"
	.string "lỡ cơ hội! Tương lai của cả hai ta phụ\l"
	.string "thuộc vào cậu!$"

BattleFrontier_Lounge3_Text_GetToBattlePalaceSingle::
	.string "Đến SINGLE BATTLE HALLS của BATTLE\n"
	.string "PALACE ngay!\p"
	.string "Trận này nhất định phải thắng! Đừng bỏ\n"
	.string "lỡ cơ hội! Tương lai của cả hai ta phụ\l"
	.string "thuộc vào cậu!$"

BattleFrontier_Lounge3_Text_GetToBattlePalaceDouble::
	.string "Đến DOUBLE BATTLE HALLS của BATTLE\n"
	.string "PALACE ngay!\p"
	.string "Trận này nhất định phải thắng! Đừng bỏ\n"
	.string "lỡ cơ hội! Tương lai của cả hai ta phụ\l"
	.string "thuộc vào cậu!$"

BattleFrontier_Lounge3_Text_GetToBattleArena::
	.string "Đến Set KO Tourney của BATTLE ARENA\n"
	.string "ngay!\p"
	.string "Trận này nhất định phải thắng! Đừng bỏ\n"
	.string "lỡ cơ hội! Tương lai của cả hai ta phụ\l"
	.string "thuộc vào cậu!$"

BattleFrontier_Lounge3_Text_GetToBattlePike::
	.string "Đến Battle Choice của BATTLE PIKE\n"
	.string "ngay!\p"
	.string "Trận này nhất định phải thắng! Đừng bỏ\n"
	.string "lỡ cơ hội! Tương lai của cả hai ta phụ\l"
	.string "thuộc vào cậu!$"

BattleFrontier_Lounge3_Text_GetToBattlePyramid::
	.string "Đến Battle Quest của BATTLE PYRAMID\n"
	.string "ngay!\p"
	.string "Trận này nhất định phải thắng! Đừng bỏ\n"
	.string "lỡ cơ hội! Tương lai của cả hai ta phụ\l"
	.string "thuộc vào cậu!$"

BattleFrontier_Lounge3_Text_NiceTryCantReturnPoints::
	.string "Ồ, là cậu à. Cậu đã cố gắng rồi.\p"
	.string "Tôi rất tiếc phải nói rằng tôi không thể\n"
	.string "trả lại Battle Points cho cậu.\p"
	.string "Xem như đây là động lực để lần sau\n"
	.string "chúng ta cố gắng hơn nữa nhé!$"

BattleFrontier_Lounge3_Text_HelloChampHeresYourPoints::
	.string "Ồ, tuyệt quá! Chào nhà vô địch!\p"
	.string "Tôi biết cậu làm được mà! Tôi biết cậu\n"
	.string "sẽ thắng! Cả hai ta đều thắng lớn!\p"
	.string "Tôi sẽ trả lại Battle Points cho cậu, và\n"
	.string "tất nhiên còn tặng thêm một ít nữa!$"

BattleFrontier_Lounge3_Text_ObtainedBattlePoints::
	.string "{PLAYER} nhận được\n"
	.string "{STR_VAR_1} Battle Points.$"

BattleFrontier_Lounge3_Text_ThinkOfMeForAnotherChallenge::
	.string "Nếu muốn thử sức lần nữa, nhớ nghĩ đến\n"
	.string "tôi nhé!$"

BattleFrontier_Lounge3_Text_NotInterested::
	.string "Không hứng thú sao?! Cậu đừng sợ mạo\n"
	.string "hiểm như thế chứ!$"

BattleFrontier_Lounge3_Text_Oh::
	.string "Ồ.$"

BattleFrontier_Lounge3_Text_BackedWrongTrainer::
	.string "Tôi lại đặt cược nhầm HLV rồi!\p"
	.string "Có lẽ tôi nên chiến đấu bình thường\n"
	.string "như mọi người.$"

BattleFrontier_Lounge3_Text_TrainerGoodButRattled::
	.string "HLV đó.\p"
	.string "Cậu ta giỏi, nhưng quá dễ mất bình tĩnh\n"
	.string "để có thể trụ lại BATTLE DOME.$"

BattleFrontier_Lounge3_Text_KnowWinnerWhenISeeOne::
	.string "Hí hí! Nhìn là tôi biết ngay ai sẽ chiến\n"
	.string "thắng!$"

BattleFrontier_Lounge3_Text_ShouldBeTakingChallenges::
	.string "Các HLV đó đang làm gì vậy? Lẽ ra\n"
	.string "họ phải đi thử sức chứ.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global BattleFrontier_Lounge3_Text_CantYouSeeWereBusyHere
	.global BattleFrontier_Lounge3_Text_YouLookToughExplainGambling
	.global BattleFrontier_Lounge3_Text_ChallengeBattleTowerSingle
	.global BattleFrontier_Lounge3_Text_ChallengeBattleTowerDouble
	.global BattleFrontier_Lounge3_Text_ChallengeBattleTowerMulti
	.global BattleFrontier_Lounge3_Text_ChallengeBattleDomeSingle
	.global BattleFrontier_Lounge3_Text_ChallengeBattleDomeDouble
	.global BattleFrontier_Lounge3_Text_ChallengeBattleFactorySingle
	.global BattleFrontier_Lounge3_Text_ChallengeBattleFactoryDouble
	.global BattleFrontier_Lounge3_Text_ChallengeBattlePalaceSingle
	.global BattleFrontier_Lounge3_Text_ChallengeBattlePalaceDouble
	.global BattleFrontier_Lounge3_Text_ChallengeBattleArena
	.global BattleFrontier_Lounge3_Text_ChallengeBattlePike
	.global BattleFrontier_Lounge3_Text_ChallengeBattlePyramid
	.global BattleFrontier_Lounge3_Text_HowAboutEnteringEventForMe
	.global BattleFrontier_Lounge3_Text_SpotMeSomeBattlePoints
	.global BattleFrontier_Lounge3_Text_HowMuchCanYouSpot
	.global BattleFrontier_Lounge3_Text_YouDontHaveEnoughPoints
	.global BattleFrontier_Lounge3_Text_ThanksOffYouGo
	.global BattleFrontier_Lounge3_Text_GetToBattleTowerSingle
	.global BattleFrontier_Lounge3_Text_GetToBattleTowerDouble
	.global BattleFrontier_Lounge3_Text_GetToBattleTowerMulti
	.global BattleFrontier_Lounge3_Text_GetToBattleDomeSingle
	.global BattleFrontier_Lounge3_Text_GetToBattleDomeDouble
	.global BattleFrontier_Lounge3_Text_GetToBattleFactorySingle
	.global BattleFrontier_Lounge3_Text_GetToBattleFactoryDouble
	.global BattleFrontier_Lounge3_Text_GetToBattlePalaceSingle
	.global BattleFrontier_Lounge3_Text_GetToBattlePalaceDouble
	.global BattleFrontier_Lounge3_Text_GetToBattleArena
	.global BattleFrontier_Lounge3_Text_GetToBattlePike
	.global BattleFrontier_Lounge3_Text_GetToBattlePyramid
	.global BattleFrontier_Lounge3_Text_NiceTryCantReturnPoints
	.global BattleFrontier_Lounge3_Text_HelloChampHeresYourPoints
	.global BattleFrontier_Lounge3_Text_ObtainedBattlePoints
	.global BattleFrontier_Lounge3_Text_ThinkOfMeForAnotherChallenge
	.global BattleFrontier_Lounge3_Text_NotInterested
	.global BattleFrontier_Lounge3_Text_Oh
	.global BattleFrontier_Lounge3_Text_BackedWrongTrainer
	.global BattleFrontier_Lounge3_Text_TrainerGoodButRattled
	.global BattleFrontier_Lounge3_Text_KnowWinnerWhenISeeOne
	.global BattleFrontier_Lounge3_Text_ShouldBeTakingChallenges
@ END GENERATED LOCALIZATION EXPORTS
