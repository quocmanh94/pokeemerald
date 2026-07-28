BattleFrontier_BattleFactoryLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleFactoryLobby_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleFactoryLobby_OnWarp
	.byte 0

BattleFrontier_BattleFactoryLobby_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleFactoryLobby_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattleFactoryLobby_EventScript_TurnPlayerNorth::
	setvar VAR_TEMP_1, 1
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattleFactoryLobby_OnFrame:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattleFactoryLobby_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattleFactoryLobby_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattleFactoryLobby_EventScript_ResumeChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattleFactoryLobby_EventScript_WonChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattleFactoryLobby_EventScript_LostChallenge
	.2byte 0

BattleFrontier_BattleFactoryLobby_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

BattleFrontier_BattleFactoryLobby_EventScript_QuitWithoutSaving::
	lockall
	msgbox BattleFrontier_BattleFactoryLobby_Text_DidntSaveBeforeQuitting, MSGBOX_DEFAULT
	closemessage
	factory_setswapped
	factory_set FACTORY_DATA_WIN_STREAK_SWAPS, 0
	factory_set FACTORY_DATA_WIN_STREAK, 0
	factory_set FACTORY_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleFactoryLobby_EventScript_WonChallenge::
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleFactoryLobby_EventScript_DefeatedFactoryHead
	msgbox BattleFrontier_BattleFactoryLobby_Text_CongratsSevenWins, MSGBOX_DEFAULT
	waitmessage
	goto BattleFrontier_BattleFactoryLobby_EventScript_GiveBattlePoints

BattleFrontier_BattleFactoryLobby_EventScript_DefeatedFactoryHead::
	msgbox BattleFrontier_BattleFactoryLobby_Text_CongratsForDefeatingHead, MSGBOX_DEFAULT
	waitmessage
BattleFrontier_BattleFactoryLobby_EventScript_GiveBattlePoints::
	msgbox BattleFrontier_BattleFactoryLobby_Text_AwardBattlePoints, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	message BattleFrontier_BattleFactoryLobby_Text_ExchangeMonsAndSave
	waitmessage
	frontier_checkairshow
	special LoadPlayerParty
	callnative UpdateFollowingPokemon
	factory_save 0
	playse SE_SAVE
	waitse
	goto BattleFrontier_BattleFactoryLobby_EventScript_AskRecordBattle
	end

BattleFrontier_BattleFactoryLobby_EventScript_LostChallenge::
	lockall
	message BattleFrontier_BattleFactoryLobby_Text_ReturnMonsSaveResults
	waitmessage
	frontier_checkairshow
	special LoadPlayerParty
	callnative UpdateFollowingPokemon
	factory_set FACTORY_DATA_WIN_STREAK_ACTIVE, FALSE
	factory_save 0
	playse SE_SAVE
	waitse

BattleFrontier_BattleFactoryLobby_EventScript_AskRecordBattle::
	call BattleFrontier_EventScript_GetCantRecordBattle
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleFactoryLobby_EventScript_EndRecordBattle
	message BattleFrontier_BattleFactoryLobby_Text_RecordLastMatch
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_EndRecordBattle
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_RecordBattle
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_EndRecordBattle

BattleFrontier_BattleFactoryLobby_EventScript_RecordBattle::
	call BattleFrontier_EventScript_SaveBattle
BattleFrontier_BattleFactoryLobby_EventScript_EndRecordBattle::
	msgbox BattleFrontier_BattleFactoryLobby_Text_LookForwardToNextVisit, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleFactoryLobby_EventScript_ResumeChallenge::
	lockall
	message BattleFrontier_BattleFactoryLobby_Text_WaitingForYouToResume
	waitmessage
	factory_save CHALLENGE_STATUS_SAVING
	playse SE_SAVE
	waitse
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	setvar VAR_0x8006, 2
	goto BattleFrontier_BattleFactoryLobby_EventScript_EnterChallenge

BattleFrontier_BattleFactoryLobby_EventScript_SinglesAttendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_FACTORY
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	goto BattleFrontier_BattleFactoryLobby_EventScript_Attendant
	end

BattleFrontier_BattleFactoryLobby_EventScript_DoublesAttendant::
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_FACTORY
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
	goto BattleFrontier_BattleFactoryLobby_EventScript_Attendant
	end

BattleFrontier_BattleFactoryLobby_EventScript_Attendant::
	special SavePlayerParty
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForSingleBattle
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForDoubleBattle
BattleFrontier_BattleFactoryLobby_EventScript_AskTakeChallenge::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleFactoryLobby_EventScript_TakeSinglesChallenge
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryLobby_EventScript_TakeDoublesChallenge
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_TryEnterChallenge
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_ExplainChallenge
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge

BattleFrontier_BattleFactoryLobby_EventScript_TryEnterChallenge::
	message BattleFrontier_BattleFactoryLobby_Text_WhichLevelMode
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattleFactoryLobby_Text_OkayToSaveBeforeChallenge, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattleFactoryLobby_EventScript_LoadPartyAndCancelChallenge
	case YES, BattleFrontier_BattleFactoryLobby_EventScript_SaveBeforeChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_LoadPartyAndCancelChallenge

BattleFrontier_BattleFactoryLobby_EventScript_SaveBeforeChallenge::
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	factory_init
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	factory_set FACTORY_DATA_WIN_STREAK_ACTIVE, TRUE
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallengeSaveFailed
	setvar VAR_0x8006, 0
BattleFrontier_BattleFactoryLobby_EventScript_EnterChallenge::
	special SavePlayerParty
	msgbox BattleFrontier_BattleFactoryLobby_Text_StepThisWay, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleFactoryLobby_EventScript_TalkedToSinglesAttendant
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryLobby_EventScript_TalkedToDoublesAttendant
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleFactoryLobby_Movement_AttendantEnterDoor
	applymovement LOCALID_PLAYER, BattleFrontier_BattleFactoryLobby_Movement_PlayerEnterDoor
	waitmovement 0
	warp MAP_BATTLE_FRONTIER_BATTLE_FACTORY_PRE_BATTLE_ROOM, 8, 13
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	waitstate
	end

BattleFrontier_BattleFactoryLobby_EventScript_TalkedToSinglesAttendant::
	setvar VAR_LAST_TALKED, LOCALID_FACTORY_ATTENDANT_SINGLES
	return

BattleFrontier_BattleFactoryLobby_EventScript_TalkedToDoublesAttendant::
	setvar VAR_LAST_TALKED, LOCALID_FACTORY_ATTENDANT_DOUBLES
	return

BattleFrontier_BattleFactoryLobby_EventScript_ExplainChallenge::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleFactoryLobby_EventScript_ExplainSinglesChallenge
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryLobby_EventScript_ExplainDoublesChallenge
	goto BattleFrontier_BattleFactoryLobby_EventScript_AskTakeChallenge

BattleFrontier_BattleFactoryLobby_EventScript_CancelChallengeSaveFailed::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge

BattleFrontier_BattleFactoryLobby_EventScript_LoadPartyAndCancelChallenge::
	special LoadPlayerParty
	callnative UpdateFollowingPokemon
BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge::
	msgbox BattleFrontier_BattleFactoryLobby_Text_LookForwardToNextVisit, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattleFactoryLobby_Movement_AttendantEnterDoor:
	walk_up
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleFactoryLobby_Movement_PlayerEnterDoor:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForSingleBattle::
	msgbox BattleFrontier_BattleFactoryLobby_Text_WelcomeForSingleBattle, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForDoubleBattle::
	msgbox BattleFrontier_BattleFactoryLobby_Text_WelcomeForDoubleBattle, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryLobby_EventScript_TakeSinglesChallenge::
	message BattleFrontier_BattleFactoryLobby_Text_TakeSinglesChallenge
	return

BattleFrontier_BattleFactoryLobby_EventScript_TakeDoublesChallenge::
	message BattleFrontier_BattleFactoryLobby_Text_TakeDoublesChallenge
	return

BattleFrontier_BattleFactoryLobby_EventScript_ExplainSinglesChallenge::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSinglesChallenge, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryLobby_EventScript_ExplainDoublesChallenge::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainDoublesChallenge, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryLobby_EventScript_ShowSinglesResults::
	lockall
	frontier_results FRONTIER_FACILITY_FACTORY, FRONTIER_MODE_SINGLES
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleFactoryLobby_EventScript_ShowDoublesResults::
	lockall
	frontier_results FRONTIER_FACILITY_FACTORY, FRONTIER_MODE_DOUBLES
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleFactoryLobby_EventScript_Woman::
	msgbox BattleFrontier_BattleFactoryLobby_Text_NeedKnowledgeOfMonsMoves, MSGBOX_NPC
	end

BattleFrontier_BattleFactoryLobby_EventScript_Camper::
	msgbox BattleFrontier_BattleFactoryLobby_Text_SwappedForWeakMon, MSGBOX_NPC
	end

BattleFrontier_BattleFactoryLobby_EventScript_Picnicker::
	lock
	msgbox BattleFrontier_BattleFactoryLobby_Text_NeedToCheckOpponentsMons, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattleFactoryLobby_EventScript_FatMan::
	msgbox BattleFrontier_BattleFactoryLobby_Text_CantFigureOutStaffHints, MSGBOX_NPC
	end

BattleFrontier_BattleFactoryLobby_EventScript_RulesBoard::
	lockall
	msgbox BattleFrontier_BattleFactoryLobby_Text_RulesAreListed, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard::
	message BattleFrontier_BattleFactoryLobby_Text_ReadWhichHeading
	waitmessage
	multichoice 17, 0, MULTI_BATTLE_FACTORY_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_RulesBasics
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapPartner
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNumber
	case 3, BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNotes
	case 4, BattleFrontier_BattleFactoryLobby_EventScript_RulesOpenLv
	case 5, BattleFrontier_BattleFactoryLobby_EventScript_ExitRules
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_ExitRules
	end

BattleFrontier_BattleFactoryLobby_EventScript_RulesBasics::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainBasicRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapPartner::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSwapPartnerRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNumber::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNumberRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNotes::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNotesRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleFactoryLobby_EventScript_RulesOpenLv::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainOpenLvRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleFactoryLobby_EventScript_ExitRules::
	releaseall
	end

BattleFrontier_BattleFactoryLobby_Text_WelcomeForSingleBattle:
	.string "Nơi trí tuệ của các HLV được thử\n"
	.string "thách!\p"
	.string "Chào mừng đến với BATTLE FACTORY!\p"
	.string "Tôi sẽ hướng dẫn bạn tham gia Battle\n"
	.string "Swap Single Tournament.$"

BattleFrontier_BattleFactoryLobby_Text_TakeSinglesChallenge:
	.string "Bạn có muốn tham gia thử thách Battle\n"
	.string "Swap Single không?$"

BattleFrontier_BattleFactoryLobby_Text_ExplainSinglesChallenge:
	.string "Battle Swap Single Tournament là cuộc\n"
	.string "thi SINGLE BATTLE chỉ dùng POKéMON\l"
	.string "thuê.\p"
	.string "Trước tiên, bạn sẽ được cho mượn ba\n"
	.string "POKéMON dành riêng cho sự kiện này.\p"
	.string "Bạn phải dùng các POKéMON thuê được\n"
	.string "cấp để đấu một trận SINGLE BATTLE.\p"
	.string "Nếu thắng, bạn được phép đổi một trong\n"
	.string "các POKéMON thuê của mình.\p"
	.string "Cứ lặp lại chu trình đấu rồi đổi, nếu\n"
	.string "thắng liên tiếp bảy trận, bạn sẽ nhận\l"
	.string "được Battle Points.\p"
	.string "Nếu muốn tạm dừng thử thách, vui lòng\n"
	.string "lưu trò chơi.\p"
	.string "Nếu không lưu, bạn sẽ bị loại khỏi thử\n"
	.string "thách.$"

BattleFrontier_BattleFactoryLobby_Text_LookForwardToNextVisit:
	.string "Chúng tôi mong chờ lần ghé thăm tiếp\n"
	.string "theo của bạn.$"

BattleFrontier_BattleFactoryLobby_Text_WhichLevelMode:
	.string "Bạn muốn thử thách cấp độ nào? Level\n"
	.string "50 hay Open Level?$"

BattleFrontier_BattleFactoryLobby_Text_OkayToSaveBeforeChallenge:
	.string "Trước khi bạn bắt đầu thử thách, tôi\n"
	.string "cần lưu trò chơi. Bạn đồng ý chứ?$"

@ Unused
BattleFrontier_BattleFactoryLobby_Text_WillHoldMonsForSafekeeping:
	.string "Được rồi, tôi sẽ giữ POKéMON của bạn an\n"
	.string "toàn trong thời gian bạn thi đấu.$"

BattleFrontier_BattleFactoryLobby_Text_StepThisWay:
	.string "Xin mời đi lối này.$"

BattleFrontier_BattleFactoryLobby_Text_ReturnMonsSaveResults:
	.string "Cảm ơn bạn đã tham gia!\p"
	.string "Tôi sẽ trả lại POKéMON của bạn để đổi\n"
	.string "lấy các POKéMON thuê của chúng tôi.\p"
	.string "Tôi cũng phải lưu kết quả sự kiện. Vui\n"
	.string "lòng chờ.$"

@ Unused
BattleFrontier_BattleFactoryLobby_Text_ReturnMons:
	.string "Tôi sẽ trả lại POKéMON của bạn để đổi\n"
	.string "lấy các POKéMON thuê của chúng tôi.$"

BattleFrontier_BattleFactoryLobby_Text_CongratsSevenWins:
	.string "Xin chúc mừng! Bạn đã thắng liên tiếp\n"
	.string "bảy trận Battle Swap!$"

@ Unused
BattleFrontier_BattleFactoryLobby_Text_AwardBattlePointsForStreak:
	.string "Để ghi nhận chuỗi 7 trận thắng của bạn,\n"
	.string "chúng tôi trao cho bạn số Battle\l"
	.string "Point(s) này.$"

@ Unused
BattleFrontier_BattleFactoryLobby_Text_MaxBattlePoints:
	.string "Ôi, ôi, ôi!\p"
	.string "Battle Points của bạn đã đạt mức tối\n"
	.string "đa.\p"
	.string "Vui lòng quay lại sau khi đã dùng bớt\n"
	.string "Battle Points.$"

BattleFrontier_BattleFactoryLobby_Text_WaitingForYouToResume:
	.string "Chúng tôi vẫn đang chờ bạn!\p"
	.string "Trước khi tiếp tục thử thách, tôi phải\n"
	.string "lưu trò chơi.$"

BattleFrontier_BattleFactoryLobby_Text_DidntSaveBeforeQuitting:
	.string "Rất tiếc phải nói điều này, nhưng lần\n"
	.string "trước bạn đã không lưu trước khi\l"
	.string "thoát trò chơi.\p"
	.string "Vì vậy, bạn đã bị loại khỏi thử thách.$"

@ Unused
BattleFrontier_BattleFactoryLobby_Text_WellReturnMons:
	.string "Chúng tôi sẽ trả lại POKéMON riêng của\n"
	.string "bạn.$"

@ Unused
BattleFrontier_BattleFactoryLobby_Text_ReceivedPrizeItem:
	.string "{PLAYER} nhận được phần thưởng\n"
	.string "{STR_VAR_1}.$"

BattleFrontier_BattleFactoryLobby_Text_WelcomeForDoubleBattle:
	.string "Nơi trí tuệ của các HLV được thử\n"
	.string "thách!\p"
	.string "Chào mừng đến với BATTLE FACTORY!\p"
	.string "Tôi sẽ hướng dẫn bạn tham gia Battle\n"
	.string "Swap Double Tournament.$"

BattleFrontier_BattleFactoryLobby_Text_TakeDoublesChallenge:
	.string "Bạn có muốn tham gia thử thách Battle\n"
	.string "Swap Double không?$"

BattleFrontier_BattleFactoryLobby_Text_ExplainDoublesChallenge:
	.string "Battle Swap Double Tournament là cuộc\n"
	.string "thi DOUBLE BATTLE chỉ dùng POKéMON\l"
	.string "thuê.\p"
	.string "Trước tiên, bạn sẽ được cho mượn ba\n"
	.string "POKéMON dành riêng cho sự kiện này.\p"
	.string "Bạn phải dùng các POKéMON thuê được\n"
	.string "cấp để đấu một trận DOUBLE BATTLE.\p"
	.string "Nếu thắng, bạn được phép đổi một trong\n"
	.string "các POKéMON thuê của mình.\p"
	.string "Cứ lặp lại chu trình đấu rồi đổi, nếu\n"
	.string "thắng liên tiếp bảy trận, bạn sẽ nhận\l"
	.string "được Battle Points.\p"
	.string "Nếu muốn tạm dừng thử thách, vui lòng\n"
	.string "lưu trò chơi.\p"
	.string "Nếu không lưu trước khi tạm dừng, bạn\n"
	.string "sẽ bị loại.$"

BattleFrontier_BattleFactoryLobby_Text_CongratsForDefeatingHead:
	.string "Chúc mừng bạn đã đánh bại FACTORY\n"
	.string "HEAD và giành chiến thắng bảy trận liên\l"
	.string "tiếp!$"

BattleFrontier_BattleFactoryLobby_Text_AwardBattlePoints:
	.string "Để ghi nhận vốn kiến thức phong phú và\n"
	.string "trí tuệ sắc bén của bạn, chúng tôi xin\l"
	.string "trao tặng bạn số Battle Point(s) này.$"

BattleFrontier_BattleFactoryLobby_Text_ExchangeMonsAndSave:
	.string "Để tôi đổi POKéMON của bạn lấy POKéMON\n"
	.string "cho thuê của chúng tôi.\p"
	.string "Tôi cần lưu dữ liệu trận đấu, xin vui\n"
	.string "lòng chờ.$"

BattleFrontier_BattleFactoryLobby_Text_RecordLastMatch:
	.string "Bạn có muốn ghi lại trận BATTLE FACTORY\n"
	.string "gần nhất vào FRONTIER PASS không?$"

BattleFrontier_BattleFactoryLobby_Text_NeedKnowledgeOfMonsMoves:
	.string "Chào! Bạn kia!\p"
	.string "Bạn đang nghĩ các thử thách ở đây rất\n"
	.string "dễ vì không cần tự nuôi dưỡng một đội\l"
	.string "POKéMON sao?\p"
	.string "Tôi sẽ không vội tin rằng có thể thắng\n"
	.string "dễ dàng như thế đâu.\p"
	.string "Nếu không hiểu thật rõ về POKéMON và\n"
	.string "các chiêu thức của chúng, bạn sẽ khó mà\l"
	.string "tiếp tục chiến thắng.$"

BattleFrontier_BattleFactoryLobby_Text_SwappedForWeakMon:
	.string "Tôi đã đổi lấy một POKéMON yếu... Tôi cứ\n"
	.string "tưởng loại đó sẽ hữu ích...\p"
	.string "Bọn họ đánh chúng tôi tơi tả...$"

BattleFrontier_BattleFactoryLobby_Text_NeedToCheckOpponentsMons:
	.string "Mọi chuyện chẳng hề suôn sẻ với tôi.\p"
	.string "Trong trận đấu, bạn cần quan sát\n"
	.string "POKéMON của đối thủ để xem chúng có\l"
	.string "thực sự mạnh không.$"

BattleFrontier_BattleFactoryLobby_Text_CantFigureOutStaffHints:
	.string "Bạn biết nhân viên ở đây thường gợi ý\n"
	.string "đôi chút về đối thủ tiếp theo chứ?\p"
	.string "Thế mà tôi đã là một người đàn ông\n"
	.string "trưởng thành rồi, vẫn chẳng hiểu nổi\l"
	.string "những gợi ý ấy.$"

@ Unused
BattleFrontier_BattleFactoryLobby_Text_RentalMonsAreVaried:
	.string "Này nhé, tôi rất mạnh nhưng lại mau\n"
	.string "chán, nên cứ đổi POKéMON rồi chiến đấu\l"
	.string "hết lần này đến lần khác.\p"
	.string "Dù sao thì, sau khi tham gia Battle Swap\n"
	.string "liên tục, tôi nhận ra các POKéMON cho\l"
	.string "thuê cũng thay đổi.$"

BattleFrontier_BattleFactoryLobby_Text_RulesAreListed:
	.string "Các luật của Battle Swap được ghi ở\n"
	.string "đây.$"

BattleFrontier_BattleFactoryLobby_Text_ReadWhichHeading:
	.string "Bạn muốn đọc mục nào?$"

BattleFrontier_BattleFactoryLobby_Text_ExplainBasicRules:
	.string "Trong một sự kiện Battle Swap, bạn chỉ\n"
	.string "được dùng ba POKéMON.\p"
	.string "Dù là thuê hay đổi, đội của bạn không\n"
	.string "được có từ hai POKéMON cùng loài trở\l"
	.string "lên.$"

BattleFrontier_BattleFactoryLobby_Text_ExplainSwapPartnerRules:
	.string "Bạn chỉ có thể đổi POKéMON với HLV\n"
	.string "mà mình vừa đánh bại.\p"
	.string "Bạn chỉ có thể đổi lấy những POKéMON\n"
	.string "mà HLV bại trận đã sử dụng.$"

BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNumberRules:
	.string "Sau mỗi trận thắng, bạn có thể đổi lấy\n"
	.string "một POKéMON của đối thủ vừa bị mình\l"
	.string "đánh bại.\p"
	.string "Bạn sẽ không thể đổi POKéMON với\n"
	.string "HLV thứ bảy trong sự kiện.$"

BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNotesRules:
	.string "Có hai điểm quan trọng cần lưu ý khi đổi\n"
	.string "POKéMON.\p"
	.string "Thứ nhất, khi đổi, bạn không thể kiểm\n"
	.string "tra chỉ số của POKéMON mình sắp nhận.\p"
	.string "Thứ hai, các POKéMON trong đội được\n"
	.string "xếp theo thứ tự bạn đã thuê chúng.\p"
	.string "Thứ tự này không thay đổi ngay cả khi\n"
	.string "bạn đổi POKéMON.$"

BattleFrontier_BattleFactoryLobby_Text_ExplainOpenLvRules:
	.string "Ở Open Level, POKéMON cho thuê và\n"
	.string "POKéMON của các HLV đối thủ đều\l"
	.string "ở Level 100.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global BattleFrontier_BattleFactoryLobby_Text_WelcomeForSingleBattle
	.global BattleFrontier_BattleFactoryLobby_Text_TakeSinglesChallenge
	.global BattleFrontier_BattleFactoryLobby_Text_ExplainSinglesChallenge
	.global BattleFrontier_BattleFactoryLobby_Text_LookForwardToNextVisit
	.global BattleFrontier_BattleFactoryLobby_Text_WhichLevelMode
	.global BattleFrontier_BattleFactoryLobby_Text_OkayToSaveBeforeChallenge
	.global BattleFrontier_BattleFactoryLobby_Text_WillHoldMonsForSafekeeping
	.global BattleFrontier_BattleFactoryLobby_Text_StepThisWay
	.global BattleFrontier_BattleFactoryLobby_Text_ReturnMonsSaveResults
	.global BattleFrontier_BattleFactoryLobby_Text_ReturnMons
	.global BattleFrontier_BattleFactoryLobby_Text_CongratsSevenWins
	.global BattleFrontier_BattleFactoryLobby_Text_AwardBattlePointsForStreak
	.global BattleFrontier_BattleFactoryLobby_Text_MaxBattlePoints
	.global BattleFrontier_BattleFactoryLobby_Text_WaitingForYouToResume
	.global BattleFrontier_BattleFactoryLobby_Text_DidntSaveBeforeQuitting
	.global BattleFrontier_BattleFactoryLobby_Text_WellReturnMons
	.global BattleFrontier_BattleFactoryLobby_Text_ReceivedPrizeItem
	.global BattleFrontier_BattleFactoryLobby_Text_WelcomeForDoubleBattle
	.global BattleFrontier_BattleFactoryLobby_Text_TakeDoublesChallenge
	.global BattleFrontier_BattleFactoryLobby_Text_ExplainDoublesChallenge
	.global BattleFrontier_BattleFactoryLobby_Text_CongratsForDefeatingHead
	.global BattleFrontier_BattleFactoryLobby_Text_AwardBattlePoints
	.global BattleFrontier_BattleFactoryLobby_Text_ExchangeMonsAndSave
	.global BattleFrontier_BattleFactoryLobby_Text_RecordLastMatch
	.global BattleFrontier_BattleFactoryLobby_Text_NeedKnowledgeOfMonsMoves
	.global BattleFrontier_BattleFactoryLobby_Text_SwappedForWeakMon
	.global BattleFrontier_BattleFactoryLobby_Text_NeedToCheckOpponentsMons
	.global BattleFrontier_BattleFactoryLobby_Text_CantFigureOutStaffHints
	.global BattleFrontier_BattleFactoryLobby_Text_RentalMonsAreVaried
	.global BattleFrontier_BattleFactoryLobby_Text_RulesAreListed
	.global BattleFrontier_BattleFactoryLobby_Text_ReadWhichHeading
	.global BattleFrontier_BattleFactoryLobby_Text_ExplainBasicRules
	.global BattleFrontier_BattleFactoryLobby_Text_ExplainSwapPartnerRules
	.global BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNumberRules
	.global BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNotesRules
	.global BattleFrontier_BattleFactoryLobby_Text_ExplainOpenLvRules
@ END GENERATED LOCALIZATION EXPORTS
