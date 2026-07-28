BattleFrontier_BattlePikeLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePikeLobby_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattlePikeLobby_OnWarp
	.byte 0

BattleFrontier_BattlePikeLobby_OnFrame:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattlePikeLobby_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePikeLobby_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattlePikeLobby_EventScript_WonChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattlePikeLobby_EventScript_LostChallenge
	.2byte 0

BattleFrontier_BattlePikeLobby_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattlePikeLobby_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattlePikeLobby_EventScript_TurnPlayerNorth::
	setvar VAR_TEMP_1, 1
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattlePikeLobby_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

BattleFrontier_BattlePikeLobby_EventScript_QuitWithoutSaving::
	special HealPlayerParty
	pike_resethelditems
	lockall
	msgbox BattleFrontier_BattlePikeLobby_Text_FailedToSaveBeforeQuitting, MSGBOX_DEFAULT
	closemessage
	pike_set PIKE_DATA_WIN_STREAK, 0
	pike_set PIKE_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePikeLobby_EventScript_WonChallenge::
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePikeLobby_EventScript_DefeatedQueen
	msgbox BattleFrontier_BattlePikeLobby_Text_PossessLuckInAbundance, MSGBOX_DEFAULT
	waitmessage
	goto BattleFrontier_BattlePikeLobby_EventScript_GiveBattlePoints

BattleFrontier_BattlePikeLobby_EventScript_DefeatedQueen::
	msgbox BattleFrontier_BattlePikeLobby_Text_SnatchedVictoryFromQueen, MSGBOX_DEFAULT
	waitmessage
BattleFrontier_BattlePikeLobby_EventScript_GiveBattlePoints::
	msgbox BattleFrontier_BattlePikeLobby_Text_AwardYouTheseBattlePoints, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	frontier_checkairshow
	pike_get PIKE_DATA_TOTAL_STREAKS
	addvar VAR_RESULT, 1
	pike_set PIKE_DATA_TOTAL_STREAKS, VAR_RESULT
	special LoadPlayerParty
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	pike_resethelditems
	message BattleFrontier_BattlePikeLobby_Text_ShallRecordResults
	waitmessage
	pike_save 0
	playse SE_SAVE
	waitse
	msgbox BattleFrontier_BattlePikeLobby_Text_LookForwardToSeeingYou, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePikeLobby_EventScript_LostChallenge::
	lockall
	message BattleFrontier_BattlePikeLobby_Text_ChallengeEndedRecordResults
	waitmessage
	frontier_checkairshow
	frontier_set FRONTIER_DATA_BATTLE_NUM, 0
	pike_set PIKE_DATA_WIN_STREAK_ACTIVE, FALSE
	special LoadPlayerParty
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	pike_resethelditems
	pike_save 0
	playse SE_SAVE
	waitse
	msgbox BattleFrontier_BattlePikeLobby_Text_LookForwardToSeeingYou, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePikeLobby_EventScript_Attendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_PIKE
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	special SavePlayerParty
	msgbox BattleFrontier_BattlePikeLobby_Text_WelcomeToBattlePike, MSGBOX_DEFAULT
BattleFrontier_BattlePikeLobby_EventScript_AskTakeChallenge::
	message BattleFrontier_BattlePikeLobby_Text_TakeChallenge
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePikeLobby_EventScript_TryEnterChallenge
	case 1, BattleFrontier_BattlePikeLobby_EventScript_ExplainChallenge
	case 2, BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge

BattleFrontier_BattlePikeLobby_EventScript_TryEnterChallenge::
	message BattleFrontier_BattlePikeLobby_Text_WhichChallengeMode
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMons
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattlePikeLobby_Text_PleaseChooseThreeMons, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	callnative RemoveFollowingPokemon
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePikeLobby_EventScript_LoadPartyAndCancelChallenge
	msgbox BattleFrontier_BattlePikeLobby_Text_SaveBeforeChallenge, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattlePikeLobby_EventScript_LoadPartyAndCancelChallenge
	case YES, BattleFrontier_BattlePikeLobby_EventScript_SaveBeforeChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePikeLobby_EventScript_LoadPartyAndCancelChallenge

BattleFrontier_BattlePikeLobby_EventScript_SaveBeforeChallenge::
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_1, 0
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	pike_init
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	pike_set PIKE_DATA_WIN_STREAK_ACTIVE, TRUE
	pike_savehelditems
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	pike_savehelditems
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePikeLobby_EventScript_CancelChallengeSaveFailed
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	msgbox BattleFrontier_BattlePikeLobby_Text_StepThisWay, MSGBOX_DEFAULT
	closemessage
	frontier_settrainers
	call BattleFrontier_BattlePikeLobby_EventScript_WalkToCorridor
	special HealPlayerParty
	call BattleFrontier_BattlePike_EventScript_CloseCurtain
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_PIKE_CORRIDOR, 6, 7
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	waitstate
	end

BattleFrontier_BattlePikeLobby_EventScript_ExplainChallenge::
	msgbox BattleFrontier_BattlePikeLobby_Text_ExplainBattlePike, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_AskTakeChallenge

BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMons::
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMonsLv50
	case FRONTIER_LVL_OPEN, BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMonsLvOpen

BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMonsLv50::
	msgbox BattleFrontier_BattlePikeLobby_Text_NotEnoughValidMonsLv50, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_EndCancelChallenge

BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMonsLvOpen::
	msgbox BattleFrontier_BattlePikeLobby_Text_NotEnoughValidMonsLvOpen, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_EndCancelChallenge

BattleFrontier_BattlePikeLobby_EventScript_CancelChallengeSaveFailed::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge

BattleFrontier_BattlePikeLobby_EventScript_LoadPartyAndCancelChallenge::
	special LoadPlayerParty
	callnative UpdateFollowingPokemon
BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge::
	msgbox BattleFrontier_BattlePikeLobby_Text_LookForwardToSeeingYou, MSGBOX_DEFAULT
BattleFrontier_BattlePikeLobby_EventScript_EndCancelChallenge::
	release
	end

BattleFrontier_BattlePikeLobby_EventScript_ShowResults::
	lockall
	frontier_results FRONTIER_FACILITY_PIKE
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattlePikeLobby_EventScript_WalkToCorridor::
	applymovement LOCALID_PIKE_LOBBY_ATTENDANT, BattleFrontier_BattlePikeLobby_Movement_AttendantWalkToCorridor
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePikeLobby_Movement_PlayerWalkToCorridor
	waitmovement 0
	return

BattleFrontier_BattlePikeLobby_Movement_PlayerWalkToCorridor:
	walk_up
BattleFrontier_BattlePikeLobby_Movement_AttendantWalkToCorridor:
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattlePikeLobby_EventScript_Hiker::
	msgbox BattleFrontier_BattlePikeLobby_Text_OneRoomAwayFromGoal, MSGBOX_NPC
	end

BattleFrontier_BattlePikeLobby_EventScript_Twin::
	msgbox BattleFrontier_BattlePikeLobby_Text_NeverHadToBattleTrainer, MSGBOX_NPC
	end

BattleFrontier_BattlePikeLobby_EventScript_Beauty::
	msgbox BattleFrontier_BattlePikeLobby_Text_ThinkAbilitiesUsefulHere, MSGBOX_NPC
	end

BattleFrontier_BattlePikeLobby_EventScript_RulesBoard::
	lockall
	msgbox BattleFrontier_BattlePikeLobby_Text_RulesAreListed, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePikeLobby_EventScript_ReadRulesBoard::
	message BattleFrontier_BattlePikeLobby_Text_ReadWhichHeading
	waitmessage
	multichoice 16, 4, MULTI_BATTLE_PIKE_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePikeLobby_EventScript_RulesPokenavBag
	case 1, BattleFrontier_BattlePikeLobby_EventScript_RulesHeldItems
	case 2, BattleFrontier_BattlePikeLobby_EventScript_RulesMonOrder
	case 3, BattleFrontier_BattlePikeLobby_EventScript_ExitRules
	case MULTI_B_PRESSED, BattleFrontier_BattlePikeLobby_EventScript_ExitRules
	end

BattleFrontier_BattlePikeLobby_EventScript_RulesPokenavBag::
	msgbox BattleFrontier_BattlePikeLobby_Text_ExplainPokenavBagRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePikeLobby_EventScript_RulesHeldItems::
	msgbox BattleFrontier_BattlePikeLobby_Text_ExplainHeldItemRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePikeLobby_EventScript_RulesMonOrder::
	msgbox BattleFrontier_BattlePikeLobby_Text_ExplainMonOrderRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePikeLobby_EventScript_ExitRules::
	releaseall
	end

BattleFrontier_BattlePike_EventScript_CloseCurtain::
	playse SE_PIKE_CURTAIN_CLOSE
	special CloseBattlePikeCurtain
	waitse
	return

BattleFrontier_BattlePikeLobby_Text_WelcomeToBattlePike:
	.string "Nơi vận may của các HLV được thử\n"
	.string "thách...\p"
	.string "Chào mừng bạn đến với BATTLE PIKE...\p"
	.string "Tôi sẽ hướng dẫn bạn tại BATTLE PIKE...$"

BattleFrontier_BattlePikeLobby_Text_TakeChallenge:
	.string "Bạn có muốn tham gia thử thách Battle\n"
	.string "Choice không?$"

BattleFrontier_BattlePikeLobby_Text_ExplainBattlePike:
	.string "Tại đây, chúng tôi tổ chức một sự kiện\n"
	.string "gọi là Battle Choice.\p"
	.string "Luật của Battle Choice rất đơn giản...\p"
	.string "Chọn một trong ba lối đi rồi tiến đến\n"
	.string "căn phòng đích ở cuối BATTLE PIKE. Chỉ\l"
	.string "đơn giản vậy thôi.\p"
	.string "Tuy nhiên, chuyện xảy ra trên lối đi đã\n"
	.string "chọn hoàn toàn phụ thuộc vào vận may\l"
	.string "của người thách đấu...\p"
	.string "Nếu đến được đích, bạn sẽ nhận Battle\n"
	.string "Points.\p"
	.string "Nếu muốn tạm dừng thử thách, hãy báo\n"
	.string "với nhân viên của chúng tôi trong\l"
	.string "những căn phòng lớn dọc đường.\p"
	.string "Nếu không lưu trước khi tạm dừng, bạn\n"
	.string "sẽ bị loại.$"

BattleFrontier_BattlePikeLobby_Text_LookForwardToSeeingYou:
	.string "Chúng tôi mong được gặp lại bạn vào dịp\n"
	.string "khác...$"

BattleFrontier_BattlePikeLobby_Text_WhichChallengeMode:
	.string "Bạn có thể chọn một trong hai cấp độ:\n"
	.string "Level 50 hoặc Open Level. Bạn muốn thử\l"
	.string "sức ở cấp độ nào?$"

BattleFrontier_BattlePikeLobby_Text_NotEnoughValidMonsLv50:
	.string "Xin thứ lỗi, nhưng...\p"
	.string "Bạn không có đủ ba POKéMON hợp lệ cho\n"
	.string "sự kiện Battle Choice.\p"
	.string "Muốn tham gia, bạn phải có ba POKéMON\n"
	.string "khác nhau ở Level 50 trở xuống.\p"
	.string "Chúng cũng phải giữ các loại vật phẩm\n"
	.string "khác nhau.\p"
	.string "EGGS{STR_VAR_1} không đủ điều\n"
	.string "kiện.\p"
	.string "Hãy quay lại gặp tôi khi bạn đã sẵn\n"
	.string "sàng...$"

BattleFrontier_BattlePikeLobby_Text_NotEnoughValidMonsLvOpen:
	.string "Xin thứ lỗi, nhưng...\p"
	.string "Bạn không có đủ ba POKéMON hợp lệ cho\n"
	.string "sự kiện Battle Choice.\p"
	.string "Muốn tham gia, bạn phải có ba POKéMON\n"
	.string "khác nhau.\p"
	.string "Chúng cũng phải giữ các loại vật phẩm\n"
	.string "khác nhau.\p"
	.string "EGGS{STR_VAR_1} không đủ điều\n"
	.string "kiện.\p"
	.string "Hãy quay lại gặp tôi khi bạn đã sẵn\n"
	.string "sàng...$"

BattleFrontier_BattlePikeLobby_Text_PleaseChooseThreeMons:
	.string "Xin hãy chọn ba POKéMON mà bạn muốn\n"
	.string "đưa vào thử thách...$"

BattleFrontier_BattlePikeLobby_Text_SaveBeforeChallenge:
	.string "Trước khi bắt đầu thử thách Battle\n"
	.string "Choice, tôi phải lưu trò chơi. Bạn đồng\l"
	.string "ý chứ?$"

BattleFrontier_BattlePikeLobby_Text_StepThisWay:
	.string "Xin mời đi lối này...$"

BattleFrontier_BattlePikeLobby_Text_ChallengeEndedRecordResults:
	.string "Thử thách của bạn đã kết thúc...\p"
	.string "Tôi sẽ ghi lại kết quả. Xin vui lòng chờ...$"

BattleFrontier_BattlePikeLobby_Text_PossessLuckInAbundance:
	.string "Bạn đã hoàn thành thử thách...\p"
	.string "Tôi phải công nhận rằng... Bạn dường\n"
	.string "như có vận may vô cùng dồi dào...$"

BattleFrontier_BattlePikeLobby_Text_ShallRecordResults:
	.string "Tôi sẽ ghi lại kết quả. Xin vui lòng chờ...$"

@ Unused
BattleFrontier_BattlePikeLobby_Text_AwardYouTheseBattlePoints2:
	.string "Để kỷ niệm việc bạn hoàn thành thử\n"
	.string "thách Battle Choice, chúng tôi xin trao\l"
	.string "bạn số Battle Point(s) này...$"

@ Unused
BattleFrontier_BattlePikeLobby_Text_ReachedBattlePointLimit:
	.string "Có vẻ bạn đã đạt giới hạn Battle\n"
	.string "Points...\p"
	.string "Hãy đổi bớt Battle Points lấy phần\n"
	.string "thưởng rồi quay lại...$"

BattleFrontier_BattlePikeLobby_Text_FailedToSaveBeforeQuitting:
	.string "Xin thứ lỗi, nhưng...\p"
	.string "Lần trước, bạn đã bỏ dở thử thách mà\n"
	.string "không lưu trò chơi.\p"
	.string "Vì vậy, toàn bộ kết quả thử thách lần\n"
	.string "đó đã bị hủy. Tôi rất tiếc...$"

BattleFrontier_BattlePikeLobby_Text_SnatchedVictoryFromQueen:
	.string "Xin chúc mừng...\p"
	.string "Bạn đã giành chiến thắng trước PIKE\n"
	.string "QUEEN và hoàn thành sự kiện...$"

BattleFrontier_BattlePikeLobby_Text_AwardYouTheseBattlePoints:
	.string "Để ghi nhận vận may phi thường của bạn,\n"
	.string "chúng tôi xin trao bạn số Battle\l"
	.string "Point(s) này...$"

BattleFrontier_BattlePikeLobby_Text_OneRoomAwayFromGoal:
	.string "Á! Tôi đã bỏ lỡ cơ hội! Chỉ còn một\n"
	.string "phòng nữa là tới đích rồi!\p"
	.string "Ở nơi này, tốt nhất bạn nên đề phòng\n"
	.string "trúng độc, đóng băng và những chuyện\l"
	.string "tương tự.$"

BattleFrontier_BattlePikeLobby_Text_NeverHadToBattleTrainer:
	.string "Tôi đã hoàn thành thử thách 10 lần,\n"
	.string "nhưng chưa từng phải đấu với một\l"
	.string "HLV nào.$"

BattleFrontier_BattlePikeLobby_Text_ThinkAbilitiesUsefulHere:
	.string "Nghe này! Nghe này!\p"
	.string "Bạn không nghĩ năng lực đặc biệt của\n"
	.string "POKéMON sẽ rất hữu ích ở đây sao?$"

@ Unused
BattleFrontier_BattlePikeLobby_Text_TrainersWhicheverPathIChoose:
	.string "Nơi kỳ quặc này là sao vậy? Tôi chẳng\n"
	.string "hiểu nổi!\p"
	.string "Tôi đã thử sức bao nhiêu lần rồi, nhưng\n"
	.string "chọn đường nào cũng chỉ toàn gặp\l"
	.string "HLV.$"

BattleFrontier_BattlePikeLobby_Text_RulesAreListed:
	.string "Luật của Battle Choice được ghi ở đây.$"

BattleFrontier_BattlePikeLobby_Text_ReadWhichHeading:
	.string "Bạn muốn đọc mục nào?$"

BattleFrontier_BattlePikeLobby_Text_ExplainPokenavBagRules:
	.string "Không được sử dụng TÚI ĐỒ và POKéNAV\n"
	.string "trong thử thách Battle Choice.$"

BattleFrontier_BattlePikeLobby_Text_ExplainHeldItemRules:
	.string "Trong thử thách Battle Choice, mọi\n"
	.string "BERRY hoặc HERB mà POKéMON giữ chỉ có\l"
	.string "hiệu lực một lần.$"

BattleFrontier_BattlePikeLobby_Text_ExplainMonOrderRules:
	.string "Trong thử thách Battle Choice, không\n"
	.string "thể thay đổi thứ tự POKéMON.\p"
	.string "Bạn phải sắp xếp thứ tự trước khi bắt\n"
	.string "đầu thử thách.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global BattleFrontier_BattlePikeLobby_Text_WelcomeToBattlePike
	.global BattleFrontier_BattlePikeLobby_Text_TakeChallenge
	.global BattleFrontier_BattlePikeLobby_Text_ExplainBattlePike
	.global BattleFrontier_BattlePikeLobby_Text_LookForwardToSeeingYou
	.global BattleFrontier_BattlePikeLobby_Text_WhichChallengeMode
	.global BattleFrontier_BattlePikeLobby_Text_NotEnoughValidMonsLv50
	.global BattleFrontier_BattlePikeLobby_Text_NotEnoughValidMonsLvOpen
	.global BattleFrontier_BattlePikeLobby_Text_PleaseChooseThreeMons
	.global BattleFrontier_BattlePikeLobby_Text_SaveBeforeChallenge
	.global BattleFrontier_BattlePikeLobby_Text_StepThisWay
	.global BattleFrontier_BattlePikeLobby_Text_ChallengeEndedRecordResults
	.global BattleFrontier_BattlePikeLobby_Text_PossessLuckInAbundance
	.global BattleFrontier_BattlePikeLobby_Text_ShallRecordResults
	.global BattleFrontier_BattlePikeLobby_Text_AwardYouTheseBattlePoints2
	.global BattleFrontier_BattlePikeLobby_Text_ReachedBattlePointLimit
	.global BattleFrontier_BattlePikeLobby_Text_FailedToSaveBeforeQuitting
	.global BattleFrontier_BattlePikeLobby_Text_SnatchedVictoryFromQueen
	.global BattleFrontier_BattlePikeLobby_Text_AwardYouTheseBattlePoints
	.global BattleFrontier_BattlePikeLobby_Text_OneRoomAwayFromGoal
	.global BattleFrontier_BattlePikeLobby_Text_NeverHadToBattleTrainer
	.global BattleFrontier_BattlePikeLobby_Text_ThinkAbilitiesUsefulHere
	.global BattleFrontier_BattlePikeLobby_Text_TrainersWhicheverPathIChoose
	.global BattleFrontier_BattlePikeLobby_Text_RulesAreListed
	.global BattleFrontier_BattlePikeLobby_Text_ReadWhichHeading
	.global BattleFrontier_BattlePikeLobby_Text_ExplainPokenavBagRules
	.global BattleFrontier_BattlePikeLobby_Text_ExplainHeldItemRules
	.global BattleFrontier_BattlePikeLobby_Text_ExplainMonOrderRules
@ END GENERATED LOCALIZATION EXPORTS
