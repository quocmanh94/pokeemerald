BattleFrontier_BattlePalaceLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePalaceLobby_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattlePalaceLobby_OnWarp
	.byte 0

BattleFrontier_BattlePalaceLobby_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattlePalaceLobby_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattlePalaceLobby_EventScript_TurnPlayerNorth::
	setvar VAR_TEMP_1, 1
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattlePalaceLobby_OnFrame:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattlePalaceLobby_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePalaceLobby_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattlePalaceLobby_EventScript_ResumeChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattlePalaceLobby_EventScript_WonChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattlePalaceLobby_EventScript_LostChallenge
	.2byte 0

BattleFrontier_BattlePalaceLobby_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

BattleFrontier_BattlePalaceLobby_EventScript_QuitWithoutSaving::
	lockall
	msgbox BattleFrontier_BattlePalaceLobby_Text_FailedToSaveBeforeEndingChallenge, MSGBOX_DEFAULT
	closemessage
	palace_set PALACE_DATA_WIN_STREAK, 0
	palace_set PALACE_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_WonChallenge::
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePalaceLobby_EventScript_DefeatedMaven
	msgbox BattleFrontier_BattlePalaceLobby_Text_FirmTrueBondsFor7WinStreak, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_GiveBattlePoints

BattleFrontier_BattlePalaceLobby_EventScript_DefeatedMaven::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ToDefeatMavenAnd7Trainers, MSGBOX_DEFAULT
BattleFrontier_BattlePalaceLobby_EventScript_GiveBattlePoints::
	msgbox BattleFrontier_BattlePalaceLobby_Text_PresentYouWithBattlePoints, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	message BattleFrontier_BattlePalaceLobby_Text_FeatWillBeRecorded
	waitmessage
	call BattleFrontier_BattlePalaceLobby_EventScript_SaveAfterChallenge
	msgbox BattleFrontier_BattlePalaceLobby_Text_ReturnWhenFortified, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_LostChallenge::
	lockall
	message BattleFrontier_BattlePalaceLobby_Text_ResultsWillBeRecorded
	waitmessage
	palace_set PALACE_DATA_WIN_STREAK_ACTIVE, FALSE
	call BattleFrontier_BattlePalaceLobby_EventScript_SaveAfterChallenge
	msgbox BattleFrontier_BattlePalaceLobby_Text_ReturnWhenFortified, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_SaveAfterChallenge::
	frontier_checkairshow
	special LoadPlayerParty
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	palace_save 0
	playse SE_SAVE
	waitse
	call BattleFrontier_EventScript_GetCantRecordBattle
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePalaceLobby_EventScript_EndSaveAfterChallenge
	message BattleFrontier_BattlePalaceLobby_Text_LikeToRecordMatch
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattlePalaceLobby_EventScript_EndSaveAfterChallenge
	case 0, BattleFrontier_BattlePalaceLobby_EventScript_RecordMatch
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_EndSaveAfterChallenge

BattleFrontier_BattlePalaceLobby_EventScript_RecordMatch::
	call BattleFrontier_EventScript_SaveBattle
BattleFrontier_BattlePalaceLobby_EventScript_EndSaveAfterChallenge::
	return

BattleFrontier_BattlePalaceLobby_EventScript_ResumeChallenge::
	lockall
	msgbox BattleFrontier_BattlePalaceLobby_Text_WeHaveBeenWaiting, MSGBOX_DEFAULT
	message BattleFrontier_BattlePalaceLobby_Text_MustSaveBeforeChallenge
	waitmessage
	palace_save CHALLENGE_STATUS_SAVING
	playse SE_SAVE
	waitse
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto BattleFrontier_BattlePalaceLobby_EventScript_EnterChallenge

BattleFrontier_BattlePalaceLobby_EventScript_SinglesAttendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_PALACE
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	goto BattleFrontier_BattlePalaceLobby_EventScript_Attendant
	end

BattleFrontier_BattlePalaceLobby_EventScript_DoublesAttendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_PALACE
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
	goto BattleFrontier_BattlePalaceLobby_EventScript_Attendant
	end

BattleFrontier_BattlePalaceLobby_EventScript_Attendant::
	palace_get PALACE_DATA_PRIZE
	goto_if_ne VAR_RESULT, ITEM_NONE, BattleFrontier_BattlePalaceLobby_EventScript_WonChallenge
	special SavePlayerParty
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattlePalaceLobby_EventScript_WelcomeForSingleBattle
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_WelcomeForDoubleBattle
BattleFrontier_BattlePalaceLobby_EventScript_AskTakeChallenge::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattlePalaceLobby_EventScript_AskTakeSingleBattleChallenge
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_AskTakeDoubleBattleChallenge
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePalaceLobby_EventScript_TryEnterChallenge
	case 1, BattleFrontier_BattlePalaceLobby_EventScript_ExplainChallenge
	case 2, BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge

BattleFrontier_BattlePalaceLobby_EventScript_TryEnterChallenge::
	message BattleFrontier_BattlePalaceLobby_Text_WhichChallenge
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMons
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattlePalaceLobby_Text_NowSelectThreeMons, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	callnative RemoveFollowingPokemon
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePalaceLobby_EventScript_LoadPartyAndCancelChallenge
	msgbox BattleFrontier_BattlePalaceLobby_Text_MustSaveBeforeChallenge2, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattlePalaceLobby_EventScript_LoadPartyAndCancelChallenge
	case YES, BattleFrontier_BattlePalaceLobby_EventScript_SaveBeforeChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_LoadPartyAndCancelChallenge

BattleFrontier_BattlePalaceLobby_EventScript_SaveBeforeChallenge::
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	palace_init
	palace_set PALACE_DATA_WIN_STREAK_ACTIVE, TRUE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePalaceLobby_EventScript_CancelChallengeSaveFailed
BattleFrontier_BattlePalaceLobby_EventScript_EnterChallenge::
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	msgbox BattleFrontier_BattlePalaceLobby_Text_FollowMe, MSGBOX_DEFAULT
	closemessage
	call BattleFrontier_BattlePalaceLobby_EventScript_WalkToDoor
	warp MAP_BATTLE_FRONTIER_BATTLE_PALACE_CORRIDOR, 8, 13
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	waitstate
	end

BattleFrontier_BattlePalaceLobby_EventScript_ExplainChallenge::
	goto_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_ExplainDoublesChallenge
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainSingleBattleChallenge, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_AskTakeChallenge

BattleFrontier_BattlePalaceLobby_EventScript_ExplainDoublesChallenge::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainDoubleBattleChallenge, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_AskTakeChallenge

BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMons::
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMonsLv50
	case FRONTIER_LVL_OPEN, BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMonsLvOpen

BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMonsLv50::
	msgbox BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsLv50, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_EndCancelChallenge

BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMonsLvOpen::
	msgbox BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsLvOpen, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_EndCancelChallenge

BattleFrontier_BattlePalaceLobby_EventScript_CancelChallengeSaveFailed::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge

BattleFrontier_BattlePalaceLobby_EventScript_LoadPartyAndCancelChallenge::
	special LoadPlayerParty
	callnative LoadPlayerParty
BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ReturnWhenFortified, MSGBOX_DEFAULT
BattleFrontier_BattlePalaceLobby_EventScript_EndCancelChallenge::
	release
	end

BattleFrontier_BattlePalaceLobby_EventScript_WelcomeForSingleBattle::
	msgbox BattleFrontier_BattlePalaceLobby_Text_WelcomeForSingleBattle, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePalaceLobby_EventScript_WelcomeForDoubleBattle::
	msgbox BattleFrontier_BattlePalaceLobby_Text_WelcomeForDoubleBattle, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePalaceLobby_EventScript_AskTakeSingleBattleChallenge::
	message BattleFrontier_BattlePalaceLobby_Text_TakeSingleBattleChallenge
	return

BattleFrontier_BattlePalaceLobby_EventScript_AskTakeDoubleBattleChallenge::
	message BattleFrontier_BattlePalaceLobby_Text_TakeDoubleBattleChallenge
	return

BattleFrontier_BattlePalaceLobby_EventScript_WalkToDoor::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattlePalaceLobby_EventScript_TalkedToSinglesAttendant
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_TalkedToDoublesAttendant
	applymovement VAR_LAST_TALKED, BattleFrontier_BattlePalaceLobby_Movement_WalkToDoor
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePalaceLobby_Movement_WalkToDoor
	waitmovement 0
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattlePalaceLobby_EventScript_OpenSinglesHallDoor
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_OpenDoublesHallDoor
	waitdooranim
	applymovement VAR_LAST_TALKED, BattleFrontier_BattlePalaceLobby_Movement_AttendantEnterDoor
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePalaceLobby_Movement_PlayerEnterDoor
	waitmovement 0
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattlePalaceLobby_EventScript_CloseSinglesHallDoor
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_CloseDoublesHallDoor
	waitdooranim
	return

BattleFrontier_BattlePalaceLobby_EventScript_TalkedToSinglesAttendant::
	setvar VAR_LAST_TALKED, LOCALID_PALACE_ATTENDANT_SINGLES
	return

BattleFrontier_BattlePalaceLobby_EventScript_TalkedToDoublesAttendant::
	setvar VAR_LAST_TALKED, LOCALID_PALACE_ATTENDANT_DOUBLES
	return

BattleFrontier_BattlePalaceLobby_EventScript_OpenSinglesHallDoor::
	opendoor 5, 4
	return

BattleFrontier_BattlePalaceLobby_EventScript_OpenDoublesHallDoor::
	opendoor 19, 4
	return

BattleFrontier_BattlePalaceLobby_EventScript_CloseSinglesHallDoor::
	closedoor 5, 4
	return

BattleFrontier_BattlePalaceLobby_EventScript_CloseDoublesHallDoor::
	closedoor 19, 4
	return

BattleFrontier_BattlePalaceLobby_Movement_WalkToDoor:
	walk_up
	step_end

BattleFrontier_BattlePalaceLobby_Movement_AttendantEnterDoor:
	walk_up
	set_invisible
	step_end

BattleFrontier_BattlePalaceLobby_Movement_PlayerEnterDoor:
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattlePalaceLobby_EventScript_ShowSinglesResults::
	lockall
	frontier_results FRONTIER_FACILITY_PALACE, FRONTIER_MODE_SINGLES
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_ShowDoublesResults::
	lockall
	frontier_results FRONTIER_FACILITY_PALACE, FRONTIER_MODE_DOUBLES
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_BlackBelt::
	msgbox BattleFrontier_BattlePalaceLobby_Text_LadyCanTellWhatMonsThink, MSGBOX_NPC
	end

BattleFrontier_BattlePalaceLobby_EventScript_Man::
	msgbox BattleFrontier_BattlePalaceLobby_Text_NatureAndMovesKeyHere, MSGBOX_NPC
	end

BattleFrontier_BattlePalaceLobby_EventScript_Beauty::
	msgbox BattleFrontier_BattlePalaceLobby_Text_MonDocileButTransforms, MSGBOX_NPC
	end

BattleFrontier_BattlePalaceLobby_EventScript_Maniac::
	msgbox BattleFrontier_BattlePalaceLobby_Text_WhatNatureFavorsChippingAway, MSGBOX_NPC
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesBoard::
	lockall
	msgbox BattleFrontier_BattlePalaceLobby_Text_RulesAreListed, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard::
	message BattleFrontier_BattlePalaceLobby_Text_ReadWhichHeading
	waitmessage
	multichoice 16, 0, MULTI_BATTLE_PALACE_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePalaceLobby_EventScript_RulesBasics
	case 1, BattleFrontier_BattlePalaceLobby_EventScript_RulesNature
	case 2, BattleFrontier_BattlePalaceLobby_EventScript_RulesMoves
	case 3, BattleFrontier_BattlePalaceLobby_EventScript_RulesUnderpowered
	case 4, BattleFrontier_BattlePalaceLobby_EventScript_RulesWhenInDanger
	case 5, BattleFrontier_BattlePalaceLobby_EventScript_ExitRules
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_ExitRules
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesBasics::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesBasics, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesNature::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesNature, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesMoves::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesMoves, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesUnderpowered::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesUnderpowered, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesWhenInDanger::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesWhenInDanger, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePalaceLobby_EventScript_ExitRules::
	releaseall
	end

BattleFrontier_BattlePalaceLobby_Text_WelcomeForSingleBattle:
	.string "Nơi trái tim của các HLV được\n"
	.string "thử thách.\p"
	.string "Chào mừng bạn đến với BATTLE PALACE.\p"
	.string "Tôi tiếp nhận thử thách tại các SINGLE\n"
	.string "BATTLE HALLS.$"

BattleFrontier_BattlePalaceLobby_Text_TakeSingleBattleChallenge:
	.string "Bạn có muốn tham gia thử thách SINGLE\n"
	.string "BATTLE HALL không?$"

BattleFrontier_BattlePalaceLobby_Text_ExplainSingleBattleChallenge:
	.string "Trong BATTLE PALACE, có nhiều khán\n"
	.string "phòng dành cho SINGLE BATTLES, được\l"
	.string "gọi là SINGLE BATTLE HALLS.\p"
	.string "Các SINGLE BATTLES diễn ra theo cách\n"
	.string "thông thường, ngoại trừ một luật quan\l"
	.string "trọng bắt buộc phải tuân theo.\p"
	.string "HLV chỉ được phép đổi POKéMON ra\n"
	.string "vào.\p"
	.string "Ngoài việc đó, HLV bị cấm ra lệnh\n"
	.string "cho POKéMON.\p"
	.string "POKéMON sẽ hành động theo tính cách và\n"
	.string "tự mình chiến đấu.\p"
	.string "Bạn phải tin tưởng POKéMON của mình và\n"
	.string "dõi theo chúng.\p"
	.string "Nếu bạn đánh bại bảy HLV liên tiếp,\n"
	.string "bạn sẽ được trao\l"
	.string "Battle Points.\p"
	.string "Nếu muốn tạm dừng thử thách, bạn phải\n"
	.string "lưu trò chơi.\p"
	.string "Nếu không lưu trước khi tạm dừng, bạn\n"
	.string "sẽ bị loại.$"

BattleFrontier_BattlePalaceLobby_Text_ReturnWhenFortified:
	.string "Khi bạn đã khiến cả trái tim lẫn POKéMON\n"
	.string "của mình trở nên mạnh mẽ hơn, hãy quay\l"
	.string "lại.$"

BattleFrontier_BattlePalaceLobby_Text_WhichChallenge:
	.string "Có hai BATTLE HALLS: Level 50 và Open\n"
	.string "Level. Bạn muốn chọn thử thách nào?$"

BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsLv50:
	.string "Chà...\p"
	.string "Bạn không có đủ ba POKéMON cần thiết\n"
	.string "để tham gia thử thách.\p"
	.string "Muốn tham gia, bạn phải chọn ba loài\n"
	.string "POKéMON khác nhau.\p"
	.string "Tất cả POKéMON phải ở Level 50 trở\n"
	.string "xuống.\p"
	.string "Chúng cũng không được giữ cùng một\n"
	.string "loại vật phẩm.\p"
	.string "EGGS{STR_VAR_1} không đủ điều\n"
	.string "kiện.\p"
	.string "Hãy quay lại khi bạn đã chuẩn bị xong.$"

BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsLvOpen:
	.string "Chà...\p"
	.string "Bạn không có đủ ba POKéMON cần thiết\n"
	.string "để tham gia thử thách.\p"
	.string "Muốn tham gia, bạn phải chọn ba loài\n"
	.string "POKéMON khác nhau.\p"
	.string "Chúng cũng không được giữ cùng một\n"
	.string "loại vật phẩm.\p"
	.string "EGGS{STR_VAR_1} không đủ điều\n"
	.string "kiện.\p"
	.string "Hãy quay lại khi bạn đã chuẩn bị xong.$"

BattleFrontier_BattlePalaceLobby_Text_NowSelectThreeMons:
	.string "Tốt. Bây giờ, bạn hãy chọn ba POKéMON.$"

BattleFrontier_BattlePalaceLobby_Text_MustSaveBeforeChallenge2:
	.string "Tôi phải lưu trò chơi trước khi đưa\n"
	.string "bạn đến BATTLE HALL. Bạn đồng ý chứ?$"

BattleFrontier_BattlePalaceLobby_Text_FollowMe:
	.string "Tốt. Bây giờ, hãy đi theo tôi.$"

BattleFrontier_BattlePalaceLobby_Text_ResultsWillBeRecorded:
	.string "Tôi rất vinh dự khi được chứng kiến\n"
	.string "những chiến tích của POKéMON bên bạn.\p"
	.string "Kết quả sẽ được ghi lại. Xin bạn vui\n"
	.string "lòng chờ một lát.$"

BattleFrontier_BattlePalaceLobby_Text_FirmTrueBondsFor7WinStreak:
	.string "Để đạt được chuỗi 7 trận thắng...\p"
	.string "Mối dây gắn kết trái tim bạn với\n"
	.string "POKéMON quả thật vô cùng bền chặt và\l"
	.string "chân thành.$"

BattleFrontier_BattlePalaceLobby_Text_FeatWillBeRecorded:
	.string "Thành tích của bạn sẽ được ghi lại. Xin\n"
	.string "bạn vui lòng chờ một lát.$"

@ Unused
BattleFrontier_BattlePalaceLobby_Text_BattlePointsFor7WinStreak:
	.string "Để tưởng thưởng thành tích 7 trận\n"
	.string "thắng liên tiếp, chúng tôi xin tặng bạn\l"
	.string "Battle Point(s).$"

BattleFrontier_BattlePalaceLobby_Text_NoSpaceForPrize:
	.string "Có vẻ bạn không còn chỗ để nhận phần\n"
	.string "thưởng của chúng tôi.\p"
	.string "Hãy sắp xếp lại TÚI ĐỒ rồi quay lại.$"

BattleFrontier_BattlePalaceLobby_Text_WeHaveBeenWaiting:
	.string "Chúng tôi vẫn luôn chờ đợi bạn...$"

BattleFrontier_BattlePalaceLobby_Text_MustSaveBeforeChallenge:
	.string "Tôi phải lưu trò chơi trước khi đưa\n"
	.string "bạn đến BATTLE HALL. Bạn đồng ý chứ?$"

BattleFrontier_BattlePalaceLobby_Text_FailedToSaveBeforeEndingChallenge:
	.string "Chà...\p"
	.string "Lần trước, bạn đã kết thúc thử thách\n"
	.string "mà không lưu trò chơi.\p"
	.string "Vì vậy, kết quả thử thách của bạn đã bị\n"
	.string "hủy. Thật đáng tiếc.$"

@ Unused
BattleFrontier_BattlePalaceLobby_Text_ReceivedPrize:
	.string "{PLAYER} đã nhận phần thưởng\n"
	.string "{STR_VAR_1}.$"

BattleFrontier_BattlePalaceLobby_Text_LadyCanTellWhatMonsThink:
	.string "Với một người rắn rỏi như tôi, POKéMON\n"
	.string "rắn rỏi là tuyệt nhất.\p"
	.string "Tấn công là cách phòng thủ tốt nhất!\n"
	.string "Tấn công không ngừng mới là đỉnh cao!\p"
	.string "Nhưng đó không phải chuyện tôi muốn\n"
	.string "nói.\p"
	.string "Thỉnh thoảng có một cô gái rất dễ\n"
	.string "thương ghé qua đây.\p"
	.string "Cô ấy bảo mình biết POKéMON đang nghĩ\n"
	.string "gì.\p"
	.string "Chuyện đó thì tôi không biết, nhưng cô\n"
	.string "ấy thật sự rất dễ thương.\p"
	.string "Hả? Sao bạn lại nhìn tôi như thế?$"

BattleFrontier_BattlePalaceLobby_Text_NatureAndMovesKeyHere:
	.string "Hừm...\p"
	.string "Có vẻ tính cách của POKéMON và những\n"
	.string "chiêu thức chúng đã học chính là chìa\l"
	.string "khóa chiến đấu ở đây.\p"
	.string "Chính xác hơn, điều quan trọng là các\n"
	.string "chiêu thức phù hợp với tính cách của\l"
	.string "POKéMON đến mức nào.\p"
	.string "Nếu POKéMON của bạn lâm nguy và không\n"
	.string "thể phát huy hết khả năng, có lẽ bạn nên\l"
	.string "xem lại mức độ phù hợp giữa chiêu thức\l"
	.string "và tính cách của nó.$"

BattleFrontier_BattlePalaceLobby_Text_MonDocileButTransforms:
	.string "POKéMON của tôi thường rất hiền lành.\p"
	.string "Nhưng khi vào BATTLE HALL, đôi lúc nó\n"
	.string "như biến thành một thứ gì đó hung ác!\p"
	.string "Nó trở nên đáng sợ vô cùng. Quả thật\n"
	.string "khiến người ta sửng sốt.$"

BattleFrontier_BattlePalaceLobby_Text_WhatNatureFavorsChippingAway:
	.string "Không biết một POKéMON thích làm suy\n"
	.string "yếu đối thủ rồi từ từ bào mòn chúng sẽ\l"
	.string "có tính cách thế nào nhỉ?\p"
	.string "Tôi sẽ rất ngạc nhiên nếu đó là tính\n"
	.string "cách LAX.\p"
	.string "Nhưng không, chắc chắn không phải vậy.$"

BattleFrontier_BattlePalaceLobby_Text_WelcomeForDoubleBattle:
	.string "Nơi trái tim của các HLV được\n"
	.string "thử thách.\p"
	.string "Chào mừng bạn đến với BATTLE PALACE.\p"
	.string "Tôi tiếp nhận người thách đấu tại\n"
	.string "DOUBLE BATTLE HALLS.$"

BattleFrontier_BattlePalaceLobby_Text_TakeDoubleBattleChallenge:
	.string "Bạn có muốn tham gia thử thách tại\n"
	.string "DOUBLE BATTLE HALL không?$"

BattleFrontier_BattlePalaceLobby_Text_ExplainDoubleBattleChallenge:
	.string "Trong BATTLE PALACE có một số đấu\n"
	.string "trường dành cho DOUBLE BATTLES, được\l"
	.string "gọi là DOUBLE BATTLE HALLS.\p"
	.string "DOUBLE BATTLES diễn ra như bình\n"
	.string "thường, ngoại trừ một quy tắc quan\l"
	.string "trọng bắt buộc phải tuân theo.\p"
	.string "HLV chỉ được phép đổi POKéMON ra\n"
	.string "vào trận.\p"
	.string "Ngoài việc đó, HLV không được ra\n"
	.string "lệnh cho POKéMON.\p"
	.string "POKéMON sẽ hành động theo tính cách và\n"
	.string "tự mình chiến đấu.\p"
	.string "Bạn phải đặt niềm tin vào POKéMON và\n"
	.string "dõi theo chúng.\p"
	.string "Nếu bạn đánh bại bảy HLV liên tiếp,\n"
	.string "bạn sẽ được trao Battle Points.\p"
	.string "Nếu muốn tạm dừng thử thách, hãy lưu\n"
	.string "trò chơi.\p"
	.string "Nếu không lưu trước khi tạm dừng, bạn\n"
	.string "sẽ bị loại.$"

BattleFrontier_BattlePalaceLobby_Text_ToDefeatMavenAnd7Trainers:
	.string "Để đánh bại PALACE MAVEN và bảy\n"
	.string "HLV liên tiếp...$"

BattleFrontier_BattlePalaceLobby_Text_PresentYouWithBattlePoints:
	.string "Để tôn vinh mối gắn kết giữa bạn và\n"
	.string "POKéMON, chúng tôi xin trao bạn số\l"
	.string "Battle Point(s) này.$"

BattleFrontier_BattlePalaceLobby_Text_LikeToRecordMatch:
	.string "Bạn có muốn ghi lại trận đấu BATTLE\n"
	.string "PALACE gần nhất vào FRONTIER PASS\l"
	.string "không?$"

BattleFrontier_BattlePalaceLobby_Text_RulesAreListed:
	.string "Nội quy của BATTLE HALL được ghi ở\n"
	.string "đây.$"

BattleFrontier_BattlePalaceLobby_Text_ReadWhichHeading:
	.string "Bạn muốn đọc mục nào?$"

BattleFrontier_BattlePalaceLobby_Text_ExplainRulesBasics:
	.string "Tại đây, POKéMON phải tự suy nghĩ và\n"
	.string "chiến đấu.\p"
	.string "Không giống POKéMON hoang dã, POKéMON\n"
	.string "sống cùng con người sẽ hành động khác\l"
	.string "nhau tùy theo tính cách.$"

BattleFrontier_BattlePalaceLobby_Text_ExplainRulesNature:
	.string "Tùy theo tính cách, một POKéMON có thể\n"
	.string "luôn thích tấn công bất kể tình huống.\p"
	.string "POKéMON khác có thể thích tự bảo vệ\n"
	.string "khỏi mọi tổn hại.\p"
	.string "Một POKéMON khác nữa có thể thích\n"
	.string "quấy rối hoặc khiến đối thủ rối trí.\p"
	.string "Do tính cách của mình, POKéMON sẽ có\n"
	.string "những chiêu thức ưa thích mà nó sử\l"
	.string "dụng thành thạo.\p"
	.string "Nó cũng có thể không thích một số chiêu\n"
	.string "thức mà nó khó sử dụng.$"

BattleFrontier_BattlePalaceLobby_Text_ExplainRulesMoves:
	.string "Có những chiêu thức tấn công trực tiếp\n"
	.string "gây sát thương cho đối thủ.\p"
	.string "Có những chiêu thức phòng thủ dùng để\n"
	.string "chuẩn bị đối phó đòn tấn công của kẻ\l"
	.string "địch, hồi phục HP và nhiều mục đích\l"
	.string "khác.\p"
	.string "Ngoài ra còn có những chiêu thức hơi\n"
	.string "khác thường, có thể làm đối thủ suy yếu\l"
	.string "bằng các trạng thái bất lợi như trúng\l"
	.string "độc và tê liệt.\p"
	.string "POKéMON sẽ cân nhắc sử dụng chiêu\n"
	.string "thức thuộc ba nhóm này.$"

BattleFrontier_BattlePalaceLobby_Text_ExplainRulesUnderpowered:
	.string "Khi không được HLV chỉ huy,\n"
	.string "POKéMON có thể không sử dụng hiệu quả\l"
	.string "một số chiêu thức.\p"
	.string "POKéMON không giỏi sử dụng bất kỳ\n"
	.string "chiêu thức nào mà nó không thích.\p"
	.string "Nếu chỉ biết những chiêu thức không\n"
	.string "hợp với tính cách, POKéMON thường sẽ\l"
	.string "không thể phát huy hết khả năng.$"

BattleFrontier_BattlePalaceLobby_Text_ExplainRulesWhenInDanger:
	.string "Tùy theo tính cách, POKéMON có thể bắt\n"
	.string "đầu sử dụng những chiêu thức không\l"
	.string "hợp với mình khi lâm nguy.\p"
	.string "Nếu POKéMON bỗng hành động kỳ lạ trong\n"
	.string "tình thế nguy cấp, hãy quan sát nó thật\l"
	.string "kỹ.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global BattleFrontier_BattlePalaceLobby_Text_WelcomeForSingleBattle
	.global BattleFrontier_BattlePalaceLobby_Text_TakeSingleBattleChallenge
	.global BattleFrontier_BattlePalaceLobby_Text_ExplainSingleBattleChallenge
	.global BattleFrontier_BattlePalaceLobby_Text_ReturnWhenFortified
	.global BattleFrontier_BattlePalaceLobby_Text_WhichChallenge
	.global BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsLv50
	.global BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsLvOpen
	.global BattleFrontier_BattlePalaceLobby_Text_NowSelectThreeMons
	.global BattleFrontier_BattlePalaceLobby_Text_MustSaveBeforeChallenge2
	.global BattleFrontier_BattlePalaceLobby_Text_FollowMe
	.global BattleFrontier_BattlePalaceLobby_Text_ResultsWillBeRecorded
	.global BattleFrontier_BattlePalaceLobby_Text_FirmTrueBondsFor7WinStreak
	.global BattleFrontier_BattlePalaceLobby_Text_FeatWillBeRecorded
	.global BattleFrontier_BattlePalaceLobby_Text_BattlePointsFor7WinStreak
	.global BattleFrontier_BattlePalaceLobby_Text_NoSpaceForPrize
	.global BattleFrontier_BattlePalaceLobby_Text_WeHaveBeenWaiting
	.global BattleFrontier_BattlePalaceLobby_Text_MustSaveBeforeChallenge
	.global BattleFrontier_BattlePalaceLobby_Text_FailedToSaveBeforeEndingChallenge
	.global BattleFrontier_BattlePalaceLobby_Text_ReceivedPrize
	.global BattleFrontier_BattlePalaceLobby_Text_LadyCanTellWhatMonsThink
	.global BattleFrontier_BattlePalaceLobby_Text_NatureAndMovesKeyHere
	.global BattleFrontier_BattlePalaceLobby_Text_MonDocileButTransforms
	.global BattleFrontier_BattlePalaceLobby_Text_WhatNatureFavorsChippingAway
	.global BattleFrontier_BattlePalaceLobby_Text_WelcomeForDoubleBattle
	.global BattleFrontier_BattlePalaceLobby_Text_TakeDoubleBattleChallenge
	.global BattleFrontier_BattlePalaceLobby_Text_ExplainDoubleBattleChallenge
	.global BattleFrontier_BattlePalaceLobby_Text_ToDefeatMavenAnd7Trainers
	.global BattleFrontier_BattlePalaceLobby_Text_PresentYouWithBattlePoints
	.global BattleFrontier_BattlePalaceLobby_Text_LikeToRecordMatch
	.global BattleFrontier_BattlePalaceLobby_Text_RulesAreListed
	.global BattleFrontier_BattlePalaceLobby_Text_ReadWhichHeading
	.global BattleFrontier_BattlePalaceLobby_Text_ExplainRulesBasics
	.global BattleFrontier_BattlePalaceLobby_Text_ExplainRulesNature
	.global BattleFrontier_BattlePalaceLobby_Text_ExplainRulesMoves
	.global BattleFrontier_BattlePalaceLobby_Text_ExplainRulesUnderpowered
	.global BattleFrontier_BattlePalaceLobby_Text_ExplainRulesWhenInDanger
@ END GENERATED LOCALIZATION EXPORTS
