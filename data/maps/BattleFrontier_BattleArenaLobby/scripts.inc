BattleFrontier_BattleArenaLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleArenaLobby_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleArenaLobby_OnWarp
	.byte 0

BattleFrontier_BattleArenaLobby_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleArenaLobby_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattleArenaLobby_EventScript_TurnPlayerNorth::
	setvar VAR_TEMP_1, 1
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattleArenaLobby_OnFrame:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattleArenaLobby_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattleArenaLobby_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattleArenaLobby_EventScript_ResumeChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattleArenaLobby_EventScript_WonChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattleArenaLobby_EventScript_LostChallenge
	.2byte 0

BattleFrontier_BattleArenaLobby_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

BattleFrontier_BattleArenaLobby_EventScript_QuitWithoutSaving::
	lockall
	msgbox BattleFrontier_BattleArenaLobby_Text_DidntSaveBeforeShuttingDown, MSGBOX_DEFAULT
	closemessage
	arena_set ARENA_DATA_WIN_STREAK, 0
	arena_set ARENA_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_WonChallenge::
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleArenaLobby_EventScript_DefeatedTycoon
	msgbox BattleFrontier_BattleArenaLobby_Text_CongratsOnSevenWins, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_GiveBattlePoints

BattleFrontier_BattleArenaLobby_EventScript_DefeatedTycoon::
	msgbox BattleFrontier_BattleArenaLobby_Text_CongratsOnDefeatingTycoon, MSGBOX_DEFAULT
BattleFrontier_BattleArenaLobby_EventScript_GiveBattlePoints::
	msgbox BattleFrontier_BattleArenaLobby_Text_PleaseAcceptBattlePoints, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	message BattleFrontier_BattleArenaLobby_Text_RecordAchievement
	waitmessage
	call BattleFrontier_BattleArenaLobby_EventScript_SaveAfterChallenge
	msgbox BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge2, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_LostChallenge::
	lockall
	message BattleFrontier_BattleArenaLobby_Text_ThankYouWaitWhileSave
	waitmessage
	arena_set ARENA_DATA_WIN_STREAK_ACTIVE, FALSE
	call BattleFrontier_BattleArenaLobby_EventScript_SaveAfterChallenge
	msgbox BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge2, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_SaveAfterChallenge::
	frontier_checkairshow
	special LoadPlayerParty
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	arena_save 0
	playse SE_SAVE
	waitse
	call BattleFrontier_EventScript_GetCantRecordBattle
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleArenaLobby_EventScript_EndSaveAfterChallenge
	message BattleFrontier_BattleArenaLobby_Text_RecordLastMatch
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattleArenaLobby_EventScript_EndSaveAfterChallenge
	case 0, BattleFrontier_BattleArenaLobby_EventScript_RecordMatch
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_EndSaveAfterChallenge

BattleFrontier_BattleArenaLobby_EventScript_RecordMatch::
	call BattleFrontier_EventScript_SaveBattle
BattleFrontier_BattleArenaLobby_EventScript_EndSaveAfterChallenge::
	return

BattleFrontier_BattleArenaLobby_EventScript_ResumeChallenge::
	lockall
	message BattleFrontier_BattleArenaLobby_Text_LookingForwardToArrivalSaveGame
	waitmessage
	arena_save CHALLENGE_STATUS_SAVING
	playse SE_SAVE
	waitse
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto BattleFrontier_BattleArenaLobby_EventScript_EnterChallenge

BattleFrontier_BattleArenaLobby_EventScript_Attendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_ARENA
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	special SavePlayerParty
	msgbox BattleFrontier_BattleArenaLobby_Text_WelcomeToBattleArena, MSGBOX_DEFAULT
BattleFrontier_BattleArenaLobby_EventScript_AskTakeChallenge::
	message BattleFrontier_BattleArenaLobby_Text_WishToTakeChallenge
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleArenaLobby_EventScript_TryEnterChallenge
	case 1, BattleFrontier_BattleArenaLobby_EventScript_ExplainChallenge
	case 2, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge

BattleFrontier_BattleArenaLobby_EventScript_TryEnterChallenge::
	message BattleFrontier_BattleArenaLobby_Text_WhichLevelMode
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMons
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattleArenaLobby_Text_SelectThreeMons, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	callnative RemoveFollowingPokemon
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleArenaLobby_EventScript_LoadPartyAndCancelChallenge
	msgbox BattleFrontier_BattleArenaLobby_Text_OkayToSave, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattleArenaLobby_EventScript_LoadPartyAndCancelChallenge
	case YES, BattleFrontier_BattleArenaLobby_EventScript_SaveBeforeChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_LoadPartyAndCancelChallenge

BattleFrontier_BattleArenaLobby_EventScript_SaveBeforeChallenge::
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	arena_init
	arena_set ARENA_DATA_WIN_STREAK_ACTIVE, TRUE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleArenaLobby_EventScript_CancelChallengeSaveFailed
BattleFrontier_BattleArenaLobby_EventScript_EnterChallenge::
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	msgbox BattleFrontier_BattleArenaLobby_Text_GuideYouToArena, MSGBOX_DEFAULT
	closemessage
	frontier_get FRONTIER_DATA_LVL_MODE
	call_if_eq VAR_RESULT, FRONTIER_LVL_50, BattleFrontier_BattleArenaLobby_EventScript_WalkToDoorLv50
	call_if_eq VAR_RESULT, FRONTIER_LVL_OPEN, BattleFrontier_BattleArenaLobby_EventScript_WalkToDoorLvOpen
	warp MAP_BATTLE_FRONTIER_BATTLE_ARENA_CORRIDOR, 9, 13
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	waitstate
	end

BattleFrontier_BattleArenaLobby_EventScript_ExplainChallenge::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainChallenge, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_AskTakeChallenge

BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMons::
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMonsLv50
	case FRONTIER_LVL_OPEN, BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMonsLvOpen

BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMonsLv50::
	msgbox BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLv50, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_EndCancelChallenge

BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMonsLvOpen::
	msgbox BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLvOpen, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_EndCancelChallenge

BattleFrontier_BattleArenaLobby_EventScript_CancelChallengeSaveFailed::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge

BattleFrontier_BattleArenaLobby_EventScript_LoadPartyAndCancelChallenge::
	special LoadPlayerParty
	callnative UpdateFollowingPokemon
BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge::
	msgbox BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge, MSGBOX_DEFAULT
BattleFrontier_BattleArenaLobby_EventScript_EndCancelChallenge::
	release
	end

BattleFrontier_BattleArenaLobby_EventScript_WalkToDoorLv50::
	applymovement LOCALID_ARENA_ATTENDANT, BattleFrontier_BattleArenaLobby_Movement_AttendantWalkToLeftDoor
	applymovement LOCALID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_PlayerWalkToLeftDoor
	waitmovement 0
	opendoor 2, 2
	waitdooranim
	applymovement LOCALID_ARENA_ATTENDANT, BattleFrontier_BattleArenaLobby_Movement_AttendantEnterDoor
	applymovement LOCALID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_PlayerEnterDoor
	waitmovement 0
	closedoor 2, 2
	waitdooranim
	return

BattleFrontier_BattleArenaLobby_Movement_AttendantWalkToLeftDoor:
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

BattleFrontier_BattleArenaLobby_Movement_AttendantEnterDoor:
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleArenaLobby_Movement_PlayerWalkToLeftDoor:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_up
	step_end

BattleFrontier_BattleArenaLobby_Movement_PlayerEnterDoor:
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleArenaLobby_EventScript_WalkToDoorLvOpen::
	applymovement LOCALID_ARENA_ATTENDANT, BattleFrontier_BattleArenaLobby_Movement_AttendantWalkToRightDoor
	applymovement LOCALID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_PlayerWalkToRightDoor
	waitmovement 0
	opendoor 11, 2
	waitdooranim
	applymovement LOCALID_ARENA_ATTENDANT, BattleFrontier_BattleArenaLobby_Movement_AttendantEnterDoor
	applymovement LOCALID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_PlayerEnterDoor
	waitmovement 0
	closedoor 11, 2
	waitdooranim
	return

BattleFrontier_BattleArenaLobby_Movement_AttendantWalkToRightDoor:
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

BattleFrontier_BattleArenaLobby_Movement_PlayerWalkToRightDoor:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

BattleFrontier_BattleArenaLobby_EventScript_ShowResults::
	lockall
	frontier_results FRONTIER_FACILITY_ARENA
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_Youngster::
	msgbox BattleFrontier_BattleArenaLobby_Text_BadIdeaToNotAttack, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_Man::
	msgbox BattleFrontier_BattleArenaLobby_Text_LandingHitsWorked, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_Camper::
	msgbox BattleFrontier_BattleArenaLobby_Text_MatchWasDeclaredDraw, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_Woman::
	msgbox BattleFrontier_BattleArenaLobby_Text_OrderOfMonsImportant, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_RulesBoard::
	lockall
	msgbox BattleFrontier_BattleArenaLobby_Text_RulesAreListed, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard::
	message BattleFrontier_BattleArenaLobby_Text_ReadWhichHeading
	waitmessage
	multichoice 17, 2, MULTI_BATTLE_ARENA_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleArenaLobby_EventScript_BattleRules
	case 1, BattleFrontier_BattleArenaLobby_EventScript_MindRules
	case 2, BattleFrontier_BattleArenaLobby_EventScript_SkillRules
	case 3, BattleFrontier_BattleArenaLobby_EventScript_BodyRules
	case 4, BattleFrontier_BattleArenaLobby_EventScript_ExitRules
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_ExitRules
	end

BattleFrontier_BattleArenaLobby_EventScript_BattleRules::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainBattleRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleArenaLobby_EventScript_MindRules::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainMindRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleArenaLobby_EventScript_SkillRules::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainSkillRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleArenaLobby_EventScript_BodyRules::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainBodyRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleArenaLobby_EventScript_ExitRules::
	releaseall
	end

BattleFrontier_BattleArenaLobby_Text_WelcomeToBattleArena:
	.string "Nơi tinh thần chiến đấu của các\n"
	.string "HLV được thử thách!\p"
	.string "Chào mừng bạn đến với BATTLE ARENA!\p"
	.string "Tôi sẽ hướng dẫn bạn tham gia Set KO\n"
	.string "Tourney!$"

BattleFrontier_BattleArenaLobby_Text_WishToTakeChallenge:
	.string "Giờ bạn có muốn nhận thử thách BATTLE\n"
	.string "ARENA không?$"

BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge:
	.string "Chúng tôi mong được đón nhận thử\n"
	.string "thách của bạn vào dịp khác!$"

BattleFrontier_BattleArenaLobby_Text_ExplainChallenge:
	.string "Tại BATTLE ARENA, chúng tôi tổ chức Set\n"
	.string "KO Tourney.\p"
	.string "Mọi người tham gia đều phải dùng một\n"
	.string "đội gồm ba POKéMON.\p"
	.string "Ba POKéMON phải được xếp theo thứ tự\n"
	.string "ra trận.\p"
	.string "Trong trận đấu, các POKéMON sẽ lần\n"
	.string "lượt xuất hiện theo thứ tự đã định.\p"
	.string "Một khi POKéMON đã vào trận, nó phải\n"
	.string "tiếp tục chiến đấu cho đến khi có kết\l"
	.string "quả.\p"
	.string "Nếu sau ba lượt vẫn chưa phân thắng\n"
	.string "bại, trận đấu sẽ được chấm điểm.\p"
	.string "Nếu muốn tạm dừng thử thách, hãy lưu\n"
	.string "trò chơi.\p"
	.string "Nếu không lưu, bạn sẽ không thể tiếp\n"
	.string "tục thử thách.\p"
	.string "Nếu lập thành tích thắng liên tiếp bảy\n"
	.string "HLV, bạn sẽ được trao Battle\l"
	.string "Points.$"

BattleFrontier_BattleArenaLobby_Text_OkayToSave:
	.string "Trước khi đưa bạn vào BATTLE ARENA,\n"
	.string "bạn phải lưu trò chơi. Bạn đồng ý chứ?$"

BattleFrontier_BattleArenaLobby_Text_WhichLevelMode:
	.string "BATTLE ARENA có hai cấp độ thử thách:\n"
	.string "Level 50 và Open Level. Bạn chọn cấp độ\l"
	.string "nào?$"

BattleFrontier_BattleArenaLobby_Text_SelectThreeMons:
	.string "Được rồi, giờ xin hãy chọn ba POKéMON\n"
	.string "của bạn.$"

BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLvOpen:
	.string "Thí sinh thân mến!\p"
	.string "Bạn không có đủ ba POKéMON hợp lệ để\n"
	.string "tham gia.\p"
	.string "Để đủ điều kiện, bạn phải mang theo ba\n"
	.string "loài POKéMON khác nhau.\p"
	.string "Chúng cũng không được giữ những vật\n"
	.string "phẩm cùng loại.\p"
	.string "EGGS{STR_VAR_1} không đủ điều\n"
	.string "kiện.\p"
	.string "Khi đã chuẩn bị xong, xin hãy quay lại.$"

BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLv50:
	.string "Thí sinh thân mến!\p"
	.string "Bạn không có đủ ba POKéMON hợp lệ để\n"
	.string "tham gia.\p"
	.string "Để đủ điều kiện, bạn phải mang theo ba\n"
	.string "loài POKéMON khác nhau.\p"
	.string "Cả ba POKéMON khác nhau đều phải ở\n"
	.string "Level 50 trở xuống.\p"
	.string "Chúng cũng không được giữ những vật\n"
	.string "phẩm cùng loại.\p"
	.string "EGGS{STR_VAR_1} không đủ điều\n"
	.string "kiện.\p"
	.string "Khi đã chuẩn bị xong, xin hãy quay lại.$"

BattleFrontier_BattleArenaLobby_Text_GuideYouToArena:
	.string "Giờ tôi sẽ dẫn bạn đến BATTLE ARENA.$"

BattleFrontier_BattleArenaLobby_Text_DidntSaveBeforeShuttingDown:
	.string "Thí sinh thân mến!\p"
	.string "Bạn đã không lưu trò chơi trước khi\n"
	.string "tắt máy, đúng không?\p"
	.string "Thật đáng tiếc, điều đó khiến bạn bị\n"
	.string "loại khỏi thử thách.\p"
	.string "Tất nhiên, bạn có thể bắt đầu một thử\n"
	.string "thách mới.$"

BattleFrontier_BattleArenaLobby_Text_CongratsOnSevenWins:
	.string "Chúng tôi xin chúc mừng chuỗi chiến\n"
	.string "thắng xuất sắc của bạn trước bảy\l"
	.string "HLV!$"

BattleFrontier_BattleArenaLobby_Text_RecordAchievement:
	.string "Thành tích của bạn sẽ được ghi lại. Xin\n"
	.string "chờ trong khi tôi lưu trò chơi.$"

@ Unused
BattleFrontier_BattleArenaLobby_Text_PresentYouWithPrize:
	.string "Để kỷ niệm chuỗi bảy trận thắng, chúng\n"
	.string "tôi xin trao cho bạn phần thưởng này.$"

@ Unused
BattleFrontier_BattleArenaLobby_Text_ReceivedPrize:
	.string "{PLAYER} đã nhận phần thưởng\n"
	.string "{STR_VAR_1}.$"

@ Unused
BattleFrontier_BattleArenaLobby_Text_BagFullReturnForPrize:
	.string "Ồ? TÚI ĐỒ của bạn có vẻ đã đầy.\p"
	.string "Hãy dọn chỗ rồi quay lại nhận phần\n"
	.string "thưởng.$"

BattleFrontier_BattleArenaLobby_Text_ThankYouWaitWhileSave:
	.string "Cảm ơn bạn rất nhiều vì đã tham gia!\p"
	.string "Xin chờ trong khi tôi lưu trò chơi.$"

BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge2:
	.string "Chúng tôi mong được đón nhận thử\n"
	.string "thách của bạn vào dịp khác!$"

BattleFrontier_BattleArenaLobby_Text_LookingForwardToArrivalSaveGame:
	.string "Chúng tôi đã rất mong chờ bạn đến.\p"
	.string "Trước khi đưa bạn vào BATTLE ARENA,\n"
	.string "tôi phải lưu trò chơi. Xin chờ một chút.$"

BattleFrontier_BattleArenaLobby_Text_RecordLastMatch:
	.string "Tôi có nên ghi lại trận đấu BATTLE ARENA\n"
	.string "vừa rồi vào FRONTIER PASS không?$"

BattleFrontier_BattleArenaLobby_Text_BadIdeaToNotAttack:
	.string "Tôi thua do phán quyết của trọng tài...\p"
	.string "Có lẽ chỉ dùng các chiêu phòng thủ mà\n"
	.string "không tấn công không phải ý hay...$"

BattleFrontier_BattleArenaLobby_Text_LandingHitsWorked:
	.string "Tôi đã thắng ở phần chấm điểm!\p"
	.string "Liên tục đánh trúng POKéMON của đối\n"
	.string "thủ quả nhiên có hiệu quả!$"

BattleFrontier_BattleArenaLobby_Text_MatchWasDeclaredDraw:
	.string "Trận đấu của chúng tôi được xử hòa.\p"
	.string "Khi hết thời gian, POKéMON của tôi và\n"
	.string "của đối thủ còn lượng HP gần như ngang\l"
	.string "nhau.$"

BattleFrontier_BattleArenaLobby_Text_OrderOfMonsImportant:
	.string "Tại BATTLE ARENA, thứ tự POKéMON cực\n"
	.string "kỳ quan trọng.\p"
	.string "Ví dụ, nếu POKéMON đầu tiên của bạn bất\n"
	.string "lợi trước một số hệ, hãy chọn POKéMON\l"
	.string "thứ hai có các chiêu cực kỳ hiệu quả\l"
	.string "với POKéMON đầu tiên.\p"
	.string "Tôi nghĩ đó là cách hay để tạo nên một\n"
	.string "đội hình hiệu quả.$"

BattleFrontier_BattleArenaLobby_Text_RulesAreListed:
	.string "Luật của Set KO Tourney được ghi ở\n"
	.string "đây.$"

BattleFrontier_BattleArenaLobby_Text_ReadWhichHeading:
	.string "Bạn muốn đọc mục nào?$"

BattleFrontier_BattleArenaLobby_Text_ExplainBattleRules:
	.string "Set KO Tourney có những luật đặc biệt,\n"
	.string "khác với các trận đấu thông thường.\p"
	.string "Trước hết, mỗi trận chỉ kéo dài ba\n"
	.string "lượt.\p"
	.string "Nếu sau ba lượt vẫn chưa có kết quả,\n"
	.string "trận đấu sẽ được chấm điểm.\p"
	.string "Trọng tài sẽ chọn bên thắng dựa trên\n"
	.string "cách các POKéMON chiến đấu.\p"
	.string "Ngoài ra, POKéMON không thể đổi ra cho\n"
	.string "đến khi phần đấu của nó có kết quả.$"

BattleFrontier_BattleArenaLobby_Text_ExplainMindRules:
	.string "Yếu tố chấm điểm đầu tiên là Mind. Yếu\n"
	.string "tố này đánh giá mức độ chủ động tấn\l"
	.string "công của hai bên.\p"
	.string "Điểm số dựa trên tần suất các HLV\n"
	.string "ra lệnh dùng chiêu tấn công.$"

BattleFrontier_BattleArenaLobby_Text_ExplainSkillRules:
	.string "Yếu tố chấm điểm thứ hai là Skill. Yếu tố\n"
	.string "này đánh giá mức độ hiệu quả khi sử\l"
	.string "dụng các chiêu của POKéMON.\p"
	.string "Nếu một chiêu phát huy tác dụng, điểm\n"
	.string "Skill sẽ tăng.\p"
	.string "Nếu một chiêu thất bại, điểm Skill sẽ\n"
	.string "giảm.\p"
	.string "Với chiêu tấn công, điểm Skill sẽ tăng\n"
	.string "nếu chiêu cực kỳ hiệu quả và giảm nếu\l"
	.string "chiêu không hiệu quả lắm.\p"
	.string "Điểm Skill sẽ không tăng với những\n"
	.string "chiêu như PROTECT và DETECT.\p"
	.string "Nếu đối thủ dùng PROTECT hoặc DETECT\n"
	.string "khiến chiêu của POKéMON bên bạn không\l"
	.string "trúng, điểm Skill của nó sẽ không giảm.$"

BattleFrontier_BattleArenaLobby_Text_ExplainBodyRules:
	.string "Yếu tố chấm điểm thứ ba là Body. Yếu tố\n"
	.string "này dựa trên lượng HP còn lại khi trận\l"
	.string "đấu kết thúc.\p"
	.string "Điểm số xét cả lượng HP mà POKéMON có\n"
	.string "lúc bắt đầu trận đấu và lượng còn lại\l"
	.string "khi kết thúc.$"

BattleFrontier_BattleArenaLobby_Text_CongratsOnDefeatingTycoon:
	.string "Đánh bại ARENA TYCOON và quét sạch bảy\n"
	.string "HLV!\p"
	.string "Xin chúc mừng màn thử thách vô cùng\n"
	.string "xuất sắc của bạn!$"

BattleFrontier_BattleArenaLobby_Text_PleaseAcceptBattlePoints:
	.string "Thí sinh thân mến, để ghi nhận tinh thần\n"
	.string "bền bỉ của bạn, xin hãy nhận số Battle\l"
	.string "Point(s) này.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global BattleFrontier_BattleArenaLobby_Text_WelcomeToBattleArena
	.global BattleFrontier_BattleArenaLobby_Text_WishToTakeChallenge
	.global BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge
	.global BattleFrontier_BattleArenaLobby_Text_ExplainChallenge
	.global BattleFrontier_BattleArenaLobby_Text_OkayToSave
	.global BattleFrontier_BattleArenaLobby_Text_WhichLevelMode
	.global BattleFrontier_BattleArenaLobby_Text_SelectThreeMons
	.global BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLvOpen
	.global BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLv50
	.global BattleFrontier_BattleArenaLobby_Text_GuideYouToArena
	.global BattleFrontier_BattleArenaLobby_Text_DidntSaveBeforeShuttingDown
	.global BattleFrontier_BattleArenaLobby_Text_CongratsOnSevenWins
	.global BattleFrontier_BattleArenaLobby_Text_RecordAchievement
	.global BattleFrontier_BattleArenaLobby_Text_PresentYouWithPrize
	.global BattleFrontier_BattleArenaLobby_Text_ReceivedPrize
	.global BattleFrontier_BattleArenaLobby_Text_BagFullReturnForPrize
	.global BattleFrontier_BattleArenaLobby_Text_ThankYouWaitWhileSave
	.global BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge2
	.global BattleFrontier_BattleArenaLobby_Text_LookingForwardToArrivalSaveGame
	.global BattleFrontier_BattleArenaLobby_Text_RecordLastMatch
	.global BattleFrontier_BattleArenaLobby_Text_BadIdeaToNotAttack
	.global BattleFrontier_BattleArenaLobby_Text_LandingHitsWorked
	.global BattleFrontier_BattleArenaLobby_Text_MatchWasDeclaredDraw
	.global BattleFrontier_BattleArenaLobby_Text_OrderOfMonsImportant
	.global BattleFrontier_BattleArenaLobby_Text_RulesAreListed
	.global BattleFrontier_BattleArenaLobby_Text_ReadWhichHeading
	.global BattleFrontier_BattleArenaLobby_Text_ExplainBattleRules
	.global BattleFrontier_BattleArenaLobby_Text_ExplainMindRules
	.global BattleFrontier_BattleArenaLobby_Text_ExplainSkillRules
	.global BattleFrontier_BattleArenaLobby_Text_ExplainBodyRules
	.global BattleFrontier_BattleArenaLobby_Text_CongratsOnDefeatingTycoon
	.global BattleFrontier_BattleArenaLobby_Text_PleaseAcceptBattlePoints
@ END GENERATED LOCALIZATION EXPORTS
