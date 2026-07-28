BattleFrontier_BattleDomeLobby_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattleDomeLobby_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleDomeLobby_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleDomeLobby_OnWarp
	.byte 0

BattleFrontier_BattleDomeLobby_OnResume:
	dome_initresultstree
	end

BattleFrontier_BattleDomeLobby_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleDomeLobby_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattleDomeLobby_EventScript_TurnPlayerNorth::
	setvar VAR_TEMP_1, 1
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattleDomeLobby_OnFrame:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattleDomeLobby_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattleDomeLobby_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattleDomeLobby_EventScript_ResumeChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattleDomeLobby_EventScript_WonChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattleDomeLobby_EventScript_LostChallenge
	.2byte 0

BattleFrontier_BattleDomeLobby_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

BattleFrontier_BattleDomeLobby_EventScript_QuitWithoutSaving::
	lockall
	msgbox BattleFrontier_BattleDomeLobby_Text_DidntSaveBeforeQuitting, MSGBOX_DEFAULT
	closemessage
	dome_set DOME_DATA_WIN_STREAK, 0
	dome_set DOME_DATA_WIN_STREAK_ACTIVE, FALSE
	dome_set DOME_DATA_ATTEMPTED_CHALLENGE, TRUE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleDomeLobby_EventScript_WonChallenge::
	call BattleFrontier_EventScript_IncrementWinStreak
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleDomeLobby_EventScript_DefeatedAce
	msgbox BattleFrontier_BattleDomeLobby_Text_CongratsForWinningTourney, MSGBOX_DEFAULT
	goto BattleFrontier_BattleDomeLobby_EventScript_GiveBattlePoints

BattleFrontier_BattleDomeLobby_EventScript_DefeatedAce::
	msgbox BattleFrontier_BattleDomeLobby_Text_CongratsDefeatedTucker, MSGBOX_DEFAULT
BattleFrontier_BattleDomeLobby_EventScript_GiveBattlePoints::
	msgbox BattleFrontier_BattleDomeLobby_Text_AwardTheseBattlePoints, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	message BattleFrontier_BattleDomeLobby_Text_RecordWillBeSaved
	waitmessage
	special LoadPlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	frontier_checkairshow
	dome_set DOME_DATA_ATTEMPTED_CHALLENGE, TRUE
	dome_set DOME_DATA_HAS_WON_CHALLENGE, TRUE
	dome_set DOME_DATA_WIN_STREAK_ACTIVE, TRUE
	special LoadPlayerParty
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	goto BattleFrontier_BattleDomeLobby_EventScript_AskRecordBattle

BattleFrontier_BattleDomeLobby_EventScript_LostChallenge::
	lockall
	msgbox BattleFrontier_BattleDomeLobby_Text_ThankYouForPlaying, MSGBOX_DEFAULT
	message BattleFrontier_BattleDomeLobby_Text_RecordWillBeSaved
	waitmessage
	special LoadPlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	frontier_checkairshow
	dome_set DOME_DATA_WIN_STREAK_ACTIVE, FALSE
	dome_set DOME_DATA_ATTEMPTED_CHALLENGE, TRUE
	special LoadPlayerParty
	special HealPlayerParty
	callnative UpdateFollowingPokemon
BattleFrontier_BattleDomeLobby_EventScript_AskRecordBattle::
	dome_save 0
	playse SE_SAVE
	waitse
	call BattleFrontier_EventScript_GetCantRecordBattle
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleDomeLobby_EventScript_EndChallenge
	message BattleFrontier_BattleDomeLobby_Text_RecordLastMatch
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattleDomeLobby_EventScript_EndChallenge
	case 0, BattleFrontier_BattleDomeLobby_EventScript_RecordBattle
	case MULTI_B_PRESSED, BattleFrontier_BattleDomeLobby_EventScript_EndChallenge

BattleFrontier_BattleDomeLobby_EventScript_RecordBattle::
	call BattleFrontier_EventScript_SaveBattle
BattleFrontier_BattleDomeLobby_EventScript_EndChallenge::
	msgbox BattleFrontier_BattleDomeLobby_Text_HopeToSeeYouAgain, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleDomeLobby_EventScript_ResumeChallenge::
	lockall
	msgbox BattleFrontier_BattleDomeLobby_Text_WeveBeenWaitingForYou, MSGBOX_DEFAULT
	message BattleFrontier_BattleDomeLobby_Text_OkayToSaveBeforeChallenge2
	waitmessage
	dome_save CHALLENGE_STATUS_SAVING
	playse SE_SAVE
	waitse
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto BattleFrontier_BattleDomeLobby_EventScript_EnterChallenge

BattleFrontier_BattleDomeLobby_EventScript_SinglesAttendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_DOME
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	goto BattleFrontier_BattleDomeLobby_EventScript_AttendantWelcome
	end

BattleFrontier_BattleDomeLobby_EventScript_DoublesAttendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_DOME
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
	goto BattleFrontier_BattleDomeLobby_EventScript_AttendantWelcome
	end

BattleFrontier_BattleDomeLobby_EventScript_AttendantWelcome::
	special SavePlayerParty
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleDomeLobby_EventScript_WelcomeSingles
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleDomeLobby_EventScript_WelcomeDoubles
BattleFrontier_BattleDomeLobby_EventScript_AskTakeChallenge::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleDomeLobby_EventScript_TakeSinglesChallenge
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleDomeLobby_EventScript_TakeDoublesChallenge
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleDomeLobby_EventScript_TryEnterChallenge
	case 1, BattleFrontier_BattleDomeLobby_EventScript_ExplainChallenge
	case 2, BattleFrontier_BattleDomeLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleDomeLobby_EventScript_CancelChallenge

BattleFrontier_BattleDomeLobby_EventScript_TryEnterChallenge::
	message BattleFrontier_BattleDomeLobby_Text_WhichLevelMode
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattleDomeLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleDomeLobby_EventScript_CancelChallenge
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattleDomeLobby_EventScript_NotEnoughValidMons
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattleDomeLobby_Text_SelectThreeMons, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	callnative RemoveFollowingPokemon
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleDomeLobby_EventScript_LoadPartyCancelChallenge
	msgbox BattleFrontier_BattleDomeLobby_Text_OkayToSaveBeforeChallenge, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattleDomeLobby_EventScript_LoadPartyCancelChallenge
	case YES, BattleFrontier_BattleDomeLobby_EventScript_SaveBeforeChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleDomeLobby_EventScript_LoadPartyCancelChallenge

BattleFrontier_BattleDomeLobby_EventScript_SaveBeforeChallenge::
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	dome_init
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleDomeLobby_EventScript_CancelChallengeSaveFailed
	dome_inittrainers
BattleFrontier_BattleDomeLobby_EventScript_EnterChallenge::
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	dome_settrainers
	msgbox BattleFrontier_BattleDomeLobby_Text_ShowYouToBattleDome, MSGBOX_DEFAULT
	closemessage
	call BattleFrontier_BattleDomeLobby_EventScript_WalkToDoor
	special HealPlayerParty
	warp MAP_BATTLE_FRONTIER_BATTLE_DOME_CORRIDOR, 23, 6
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	waitstate
	end

BattleFrontier_BattleDomeLobby_EventScript_ExplainChallenge::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleDomeLobby_EventScript_ExplainSinglesChallenge
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleDomeLobby_EventScript_ExplainDoublesChallenge
	goto BattleFrontier_BattleDomeLobby_EventScript_AskTakeChallenge

BattleFrontier_BattleDomeLobby_EventScript_NotEnoughValidMons::
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattleDomeLobby_EventScript_NotEnoughValidMonsLv50
	case FRONTIER_LVL_OPEN, BattleFrontier_BattleDomeLobby_EventScript_NotEnoughValidMonsLvOpen

BattleFrontier_BattleDomeLobby_EventScript_NotEnoughValidMonsLv50::
	msgbox BattleFrontier_BattleDomeLobby_Text_NotEnoughValidMonsLv50, MSGBOX_DEFAULT
	goto BattleFrontier_BattleDomeLobby_EventScript_EndCancelChallenge

BattleFrontier_BattleDomeLobby_EventScript_NotEnoughValidMonsLvOpen::
	msgbox BattleFrontier_BattleDomeLobby_Text_NotEnoughValidMonsLvOpen, MSGBOX_DEFAULT
	goto BattleFrontier_BattleDomeLobby_EventScript_EndCancelChallenge

BattleFrontier_BattleDomeLobby_EventScript_CancelChallengeSaveFailed::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattleDomeLobby_EventScript_CancelChallenge

BattleFrontier_BattleDomeLobby_EventScript_LoadPartyCancelChallenge::
	special LoadPlayerParty
	callnative UpdateFollowingPokemon
BattleFrontier_BattleDomeLobby_EventScript_CancelChallenge::
	msgbox BattleFrontier_BattleDomeLobby_Text_HopeToSeeYouAgain, MSGBOX_DEFAULT
BattleFrontier_BattleDomeLobby_EventScript_EndCancelChallenge::
	release
	end

BattleFrontier_BattleDomeLobby_EventScript_WalkToDoor::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleDomeLobby_EventScript_SinglesAttendantWalkToDoor
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleDomeLobby_EventScript_DoublesAttendantWalkToDoor
	applymovement LOCALID_PLAYER, BattleFrontier_BattleDomeLobby_Movement_WalkToDoor
	waitmovement 0
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleDomeLobby_EventScript_OpenSinglesDoor
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleDomeLobby_EventScript_OpenDoublesDoor
	waitdooranim
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleDomeLobby_EventScript_SinglesAttendantEnterDoor
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleDomeLobby_EventScript_DoublesAttendantEnterDoor
	applymovement LOCALID_PLAYER, BattleFrontier_BattleDomeLobby_Movement_PlayerEnterDoor
	waitmovement 0
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleDomeLobby_EventScript_CloseSinglesDoor
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleDomeLobby_EventScript_CloseDoublesDoor
	waitdooranim
	return

BattleFrontier_BattleDomeLobby_EventScript_SinglesAttendantWalkToDoor::
	applymovement LOCALID_DOME_ATTENDANT_SINGLES, BattleFrontier_BattleDomeLobby_Movement_WalkToDoor
	return

BattleFrontier_BattleDomeLobby_EventScript_DoublesAttendantWalkToDoor::
	applymovement LOCALID_DOME_ATTENDANT_DOUBLES, BattleFrontier_BattleDomeLobby_Movement_WalkToDoor
	return

BattleFrontier_BattleDomeLobby_EventScript_SinglesAttendantEnterDoor::
	applymovement LOCALID_DOME_ATTENDANT_SINGLES, BattleFrontier_BattleDomeLobby_Movement_AttendantEnterDoor
	return

BattleFrontier_BattleDomeLobby_EventScript_DoublesAttendantEnterDoor::
	applymovement LOCALID_DOME_ATTENDANT_DOUBLES, BattleFrontier_BattleDomeLobby_Movement_AttendantEnterDoor
	return

BattleFrontier_BattleDomeLobby_EventScript_WelcomeSingles::
	msgbox BattleFrontier_BattleDomeLobby_Text_WelcomeSingleBattle, MSGBOX_DEFAULT
	return

BattleFrontier_BattleDomeLobby_EventScript_WelcomeDoubles::
	msgbox BattleFrontier_BattleDomeLobby_Text_WelcomeDoubleBattle, MSGBOX_DEFAULT
	return

BattleFrontier_BattleDomeLobby_EventScript_TakeSinglesChallenge::
	message BattleFrontier_BattleDomeLobby_Text_TakeSinglesChallenge
	return

BattleFrontier_BattleDomeLobby_EventScript_TakeDoublesChallenge::
	message BattleFrontier_BattleDomeLobby_Text_TakeDoublesChallenge
	return

BattleFrontier_BattleDomeLobby_EventScript_ExplainSinglesChallenge::
	msgbox BattleFrontier_BattleDomeLobby_Text_ExplainSinglesChallenge, MSGBOX_DEFAULT
	return

BattleFrontier_BattleDomeLobby_EventScript_ExplainDoublesChallenge::
	msgbox BattleFrontier_BattleDomeLobby_Text_ExplainDoublesChallenge, MSGBOX_DEFAULT
	return

BattleFrontier_BattleDomeLobby_EventScript_OpenSinglesDoor::
	opendoor 5, 4
	return

BattleFrontier_BattleDomeLobby_EventScript_OpenDoublesDoor::
	opendoor 17, 4
	return

BattleFrontier_BattleDomeLobby_EventScript_CloseSinglesDoor::
	closedoor 5, 4
	return

BattleFrontier_BattleDomeLobby_EventScript_CloseDoublesDoor::
	closedoor 17, 4
	return

BattleFrontier_BattleDomeLobby_Movement_WalkToDoor:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_BattleDomeLobby_Movement_AttendantEnterDoor:
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleDomeLobby_Movement_PlayerEnterDoor:
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleDomeLobby_EventScript_ShowSinglesResults::
	lockall
	frontier_results FRONTIER_FACILITY_DOME, FRONTIER_MODE_SINGLES
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleDomeLobby_EventScript_ShowDoublesResults::
	lockall
	frontier_results FRONTIER_FACILITY_DOME, FRONTIER_MODE_DOUBLES
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleDomeLobby_EventScript_ShowPrevTourneyTree::
	dome_get DOME_DATA_PREV_TOURNEY_TYPE
	call_if_eq VAR_RESULT, 0, BattleFrontier_BattleDomeLobby_EventScript_PrevTourneyResultsSinglesLv50
	call_if_eq VAR_RESULT, 1, BattleFrontier_BattleDomeLobby_EventScript_PrevTourneyResultsDoublesLv50
	call_if_eq VAR_RESULT, 2, BattleFrontier_BattleDomeLobby_EventScript_PrevTourneyResultsSinglesLvOpen
	call_if_eq VAR_RESULT, 3, BattleFrontier_BattleDomeLobby_EventScript_PrevTourneyResultsDoublesLvOpen
	fadescreen FADE_TO_BLACK
	dome_showprevtourneytree
	waitstate
	end

BattleFrontier_BattleDomeLobby_EventScript_PrevTourneyResultsSinglesLv50::
	msgbox BattleFrontier_BattleDomeLobby_Text_PrevTourneyResultsSinglesLv50, MSGBOX_SIGN
	return

BattleFrontier_BattleDomeLobby_EventScript_PrevTourneyResultsDoublesLv50::
	msgbox BattleFrontier_BattleDomeLobby_Text_PrevTourneyResultsDoublesLv50, MSGBOX_SIGN
	return

BattleFrontier_BattleDomeLobby_EventScript_PrevTourneyResultsSinglesLvOpen::
	msgbox BattleFrontier_BattleDomeLobby_Text_PrevTourneyResultsSinglesLvOpen, MSGBOX_SIGN
	return

BattleFrontier_BattleDomeLobby_EventScript_PrevTourneyResultsDoublesLvOpen::
	msgbox BattleFrontier_BattleDomeLobby_Text_PrevTourneyResultsDoublesLvOpen, MSGBOX_SIGN
	return

BattleFrontier_BattleDomeLobby_EventScript_Maniac::
	dome_getwinnersname
	msgbox BattleFrontier_BattleDomeLobby_Text_LastWinnerWasTough, MSGBOX_NPC
	end

BattleFrontier_BattleDomeLobby_EventScript_Lass::
	msgbox BattleFrontier_BattleDomeLobby_Text_WinnersGainReputation, MSGBOX_NPC
	end

BattleFrontier_BattleDomeLobby_EventScript_FatMan::
	msgbox BattleFrontier_BattleDomeLobby_Text_TrashedInFirstRound, MSGBOX_NPC
	end

BattleFrontier_BattleDomeLobby_EventScript_Man::
	msgbox BattleFrontier_BattleDomeLobby_Text_NeedToCheckOpponentCarefully, MSGBOX_NPC
	end

@ A few OutsideWest event scripts are inserted here instead, two of which are unused
BattleFrontier_OutsideWest_EventScript_Man3::
	msgbox BattleFrontier_OutsideWest_Text_LongDreamedAboutBattleFrontier, MSGBOX_NPC
	end

@ Unused
BattleFrontier_OutsideWest_EventScript_BattleDomeSign2::
	msgbox BattleFrontier_OutsideWest_Text_BattleDomeSign2, MSGBOX_NPC
	end

@ Unused
BattleFrontier_OutsideWest_EventScript_UnderConstructionSign::
	msgbox BattleFrontier_OutsideWest_Text_QuestionMarkUnderConstruction, MSGBOX_NPC
	end

BattleFrontier_BattleDomeLobby_EventScript_RulesBoard::
	lockall
	msgbox BattleFrontier_BattleDomeLobby_Text_RulesAreListed, MSGBOX_DEFAULT
	goto BattleFrontier_BattleDomeLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleDomeLobby_EventScript_ReadRulesBoard::
	message BattleFrontier_BattleDomeLobby_Text_ReadWhichHeading
	waitmessage
	multichoice 17, 4, MULTI_BATTLE_DOME_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleDomeLobby_EventScript_RulesMatchup
	case 1, BattleFrontier_BattleDomeLobby_EventScript_RulesTourneyTree
	case 2, BattleFrontier_BattleDomeLobby_EventScript_RulesDoubleKO
	case 3, BattleFrontier_BattleDomeLobby_EventScript_ExitRules
	case MULTI_B_PRESSED, BattleFrontier_BattleDomeLobby_EventScript_ExitRules
	end

BattleFrontier_BattleDomeLobby_EventScript_RulesMatchup::
	msgbox BattleFrontier_BattleDomeLobby_Text_ExplainMatchupRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleDomeLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleDomeLobby_EventScript_RulesTourneyTree::
	msgbox BattleFrontier_BattleDomeLobby_Text_ExplainTourneyTree, MSGBOX_DEFAULT
	goto BattleFrontier_BattleDomeLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleDomeLobby_EventScript_RulesDoubleKO::
	msgbox BattleFrontier_BattleDomeLobby_Text_ExplainDoubleKORules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleDomeLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleDomeLobby_EventScript_ExitRules::
	releaseall
	end

BattleFrontier_BattleDomeLobby_Text_WelcomeSingleBattle:
	.string "Nơi chiến thuật của các HLV được\n"
	.string "thử thách!\p"
	.string "Chào mừng đến với BATTLE DOME!\p"
	.string "Tôi sẽ hướng dẫn bạn tham gia giải đấu\n"
	.string "SINGLE BATTLE.$"

BattleFrontier_BattleDomeLobby_Text_TakeSinglesChallenge:
	.string "Bạn có muốn thử sức ở giải đấu SINGLE\n"
	.string "BATTLE không?$"

BattleFrontier_BattleDomeLobby_Text_HopeToSeeYouAgain:
	.string "Chúng tôi mong sẽ lại được gặp bạn.$"

BattleFrontier_BattleDomeLobby_Text_ExplainSinglesChallenge:
	.string "Giải đấu SINGLE BATTLE đúng như tên\n"
	.string "gọi, là giải đấu gồm các trận SINGLE\l"
	.string "BATTLES.\p"
	.string "Tất cả HLV tham gia đều phải đăng\n"
	.string "ký ba POKéMON.\p"
	.string "Trong mỗi trận, một trong ba POKéMON\n"
	.string "phải được giữ làm dự bị.\p"
	.string "Hai POKéMON còn lại có thể lần lượt ra\n"
	.string "đấu.\p"
	.string "Sau khi xem xét bộ ba của đối thủ, hãy\n"
	.string "chọn hai POKéMON ra trận.\p"
	.string "Bạn sẽ vô địch nếu đánh bại bốn\n"
	.string "HLV.\p"
	.string "Người vô địch giải đấu sẽ nhận được\n"
	.string "Battle Points.\p"
	.string "Nếu muốn tạm dừng giải đấu, vui lòng lưu\n"
	.string "trò chơi.\p"
	.string "Nếu không lưu trước khi tạm dừng, bạn\n"
	.string "sẽ bị loại.$"

BattleFrontier_BattleDomeLobby_Text_OkayToSaveBeforeChallenge:
	.string "Trước khi đưa bạn vào BATTLE DOME, tôi\n"
	.string "phải lưu dữ liệu. Bạn đồng ý chứ?$"

BattleFrontier_BattleDomeLobby_Text_WhichLevelMode:
	.string "Giải đấu có hai cấp độ thử thách: Level\n"
	.string "50 và Open Level. Bạn chọn cấp nào?$"

BattleFrontier_BattleDomeLobby_Text_SelectThreeMons:
	.string "Bây giờ, vui lòng chọn ba POKéMON mà\n"
	.string "bạn muốn đăng ký.$"

BattleFrontier_BattleDomeLobby_Text_NotEnoughValidMonsLvOpen:
	.string "Xin lỗi!\p"
	.string "Bạn không có đủ ba POKéMON hợp lệ.\p"
	.string "Ngoài ra, các POKéMON phải cầm những\n"
	.string "loại vật phẩm khác nhau.\p"
	.string "EGGS{STR_VAR_1} không đủ điều\n"
	.string "kiện.\p"
	.string "Hãy quay lại gặp tôi khi bạn đã sẵn\n"
	.string "sàng.$"

BattleFrontier_BattleDomeLobby_Text_NotEnoughValidMonsLv50:
	.string "Xin lỗi!\p"
	.string "Bạn không có đủ ba POKéMON hợp lệ.\p"
	.string "Bạn phải có ba POKéMON khác nhau ở\n"
	.string "Level 50 trở xuống để tham gia.\p"
	.string "Chúng cũng phải cầm những loại vật\n"
	.string "phẩm khác nhau.\p"
	.string "EGGS{STR_VAR_1} không đủ điều\n"
	.string "kiện.\p"
	.string "Hãy quay lại gặp tôi khi bạn đã sẵn\n"
	.string "sàng.$"

BattleFrontier_BattleDomeLobby_Text_ShowYouToBattleDome:
	.string "Bây giờ tôi sẽ đưa bạn vào BATTLE DOME.$"

BattleFrontier_BattleDomeLobby_Text_DidntSaveBeforeQuitting:
	.string "Xin lỗi!\p"
	.string "Lần trước, bạn đã không lưu trước khi\n"
	.string "bỏ dở thử thách.\p"
	.string "Vì vậy, thành tích thử thách khi đó của\n"
	.string "bạn đã bị hủy. Rất tiếc!$"

BattleFrontier_BattleDomeLobby_Text_CongratsForWinningTourney:
	.string "Chúc mừng bạn đã giành chiến thắng\n"
	.string "trong Battle Tournament!$"

@ Unused
BattleFrontier_BattleDomeLobby_Text_HereIsYourPrize:
	.string "Đây là phần thưởng cho chiến thắng của\n"
	.string "bạn tại Battle Tournament.$"

@ Used by Verdanturf Tent
BattleFrontier_BattleDomeLobby_Text_ReceivedPrize:
	.string "{PLAYER} nhận được phần thưởng\n"
	.string "{STR_VAR_1}.$"

@ Unused
BattleFrontier_BattleDomeLobby_Text_BagFullMakeRoom:
	.string "Ồ, có vẻ TÚI ĐỒ của bạn đã đầy.\p"
	.string "Hãy dọn chỗ rồi quay lại gặp tôi.$"

BattleFrontier_BattleDomeLobby_Text_ThankYouForPlaying:
	.string "Cảm ơn bạn đã tham gia!$"

BattleFrontier_BattleDomeLobby_Text_RecordWillBeSaved:
	.string "Thành tích của bạn sẽ được lưu. Vui\n"
	.string "lòng chờ.$"

BattleFrontier_BattleDomeLobby_Text_WeveBeenWaitingForYou:
	.string "Chúng tôi vẫn đang chờ bạn!$"

BattleFrontier_BattleDomeLobby_Text_OkayToSaveBeforeChallenge2:
	.string "Trước khi đưa bạn vào BATTLE DOME, tôi\n"
	.string "phải lưu dữ liệu. Bạn đồng ý chứ?$"

BattleFrontier_BattleDomeLobby_Text_WelcomeDoubleBattle:
	.string "Nơi chiến thuật của các HLV được\n"
	.string "thử thách!\p"
	.string "Chào mừng đến với BATTLE DOME!\p"
	.string "Tôi sẽ hướng dẫn bạn tham gia giải đấu\n"
	.string "DOUBLE BATTLE.$"

BattleFrontier_BattleDomeLobby_Text_TakeDoublesChallenge:
	.string "Bạn có muốn thử sức ở giải đấu DOUBLE\n"
	.string "BATTLE không?$"

BattleFrontier_BattleDomeLobby_Text_ExplainDoublesChallenge:
	.string "Giải đấu DOUBLE BATTLE đúng như tên\n"
	.string "gọi, là giải đấu gồm các trận DOUBLE\l"
	.string "BATTLES.\p"
	.string "Tất cả HLV tham gia đều phải đăng\n"
	.string "ký ba POKéMON.\p"
	.string "Trong mỗi trận, một trong ba POKéMON\n"
	.string "phải được giữ làm dự bị.\p"
	.string "Hai POKéMON còn lại phải tham gia một\n"
	.string "trận DOUBLE BATTLE.\p"
	.string "Sau khi xem xét bộ ba của đối thủ, hãy\n"
	.string "chọn hai POKéMON ra trận.\p"
	.string "Bạn sẽ vô địch nếu đánh bại bốn\n"
	.string "HLV.\p"
	.string "Người vô địch giải đấu sẽ nhận được\n"
	.string "Battle Points.\p"
	.string "Nếu muốn tạm dừng giải đấu, vui lòng lưu\n"
	.string "trò chơi.\p"
	.string "Nếu không lưu trước khi tạm dừng, bạn\n"
	.string "sẽ bị loại.$"

BattleFrontier_BattleDomeLobby_Text_PrevTourneyResultsSinglesLv50:
	.string "Đây là kết quả của giải đấu SINGLE\n"
	.string "BATTLE Level 50 gần nhất.$"

BattleFrontier_BattleDomeLobby_Text_PrevTourneyResultsDoublesLv50:
	.string "Đây là kết quả của giải đấu DOUBLE\n"
	.string "BATTLE Level 50 gần nhất.$"

BattleFrontier_BattleDomeLobby_Text_PrevTourneyResultsSinglesLvOpen:
	.string "Đây là kết quả của giải đấu SINGLE\n"
	.string "BATTLE Open Level gần nhất.$"

BattleFrontier_BattleDomeLobby_Text_PrevTourneyResultsDoublesLvOpen:
	.string "Đây là kết quả của giải đấu DOUBLE\n"
	.string "BATTLE Open Level gần nhất.$"

BattleFrontier_BattleDomeLobby_Text_LastWinnerWasTough:
	.string "Bạn xem chưa? Battle Tournament vừa\n"
	.string "rồi ấy?\p"
	.string "Người chiến thắng, {STR_VAR_1},\n"
	.string "mạnh kinh khủng.\p"
	.string "Bạn nên xem kết quả trên màn hình bên\n"
	.string "cạnh PC.$"

BattleFrontier_OutsideWest_Text_LongDreamedAboutBattleFrontier:
	.string "BATTLE FRONTIER. Từ lâu tôi đã mơ về\n"
	.string "một nơi như thế.$"

@ Functionally unused
BattleFrontier_OutsideWest_Text_BattleDomeSign2:
	.string "BATTLE DOME: Trở Thành Siêu Sao Bất\n"
	.string "Bại!$"

@ Functionally unused
BattleFrontier_OutsideWest_Text_QuestionMarkUnderConstruction:
	.string "??????: Đang Thi Công!$"

BattleFrontier_BattleDomeLobby_Text_WinnersGainReputation:
	.string "Khi một HLV liên tiếp vô địch tại\n"
	.string "BATTLE DOME, họ sẽ nổi danh như một\l"
	.string "ngôi sao.\p"
	.string "Danh tiếng ấy thu hút những HLV\n"
	.string "mạnh đến BATTLE DOME.\p"
	.string "Một siêu sao đích thực là HLV có\n"
	.string "thể liên tục giành chức vô địch.$"

BattleFrontier_BattleDomeLobby_Text_TrashedInFirstRound:
	.string "Ngay vòng đầu tiên, tôi đã gặp một\n"
	.string "trong những ứng viên sáng giá nhất\l"
	.string "giải.\p"
	.string "Tất nhiên là tôi bị đánh tơi tả rồi.$"

BattleFrontier_BattleDomeLobby_Text_NeedToCheckOpponentCarefully:
	.string "Tôi đã có thể thắng nếu để POKéMON này\n"
	.string "làm dự bị.\p"
	.string "Bạn phải xem xét kỹ POKéMON của đối thủ\n"
	.string "trước khi chọn POKéMON ra trận.$"

BattleFrontier_BattleDomeLobby_Text_CongratsDefeatedTucker:
	.string "Xin chúc mừng!\p"
	.string "Bạn đã đánh bại DOME ACE và vô địch\n"
	.string "Battle Tournament!$"

BattleFrontier_BattleDomeLobby_Text_AwardTheseBattlePoints:
	.string "Để ghi nhận chiến thuật đẹp mắt của\n"
	.string "bạn, chúng tôi trao cho bạn số Battle\l"
	.string "Point(s) này!$"

BattleFrontier_BattleDomeLobby_Text_RecordLastMatch:
	.string "Bạn có muốn ghi lại trận BATTLE DOME\n"
	.string "vừa rồi vào FRONTIER PASS không?$"

BattleFrontier_BattleDomeLobby_Text_RulesAreListed:
	.string "Nội quy Battle Tournament được ghi ở\n"
	.string "đây.$"

BattleFrontier_BattleDomeLobby_Text_ReadWhichHeading:
	.string "Bạn muốn đọc mục nào?$"

BattleFrontier_BattleDomeLobby_Text_ExplainMatchupRules:
	.string "Các cặp đấu trong giải được xếp dựa\n"
	.string "trên sức mạnh của POKéMON mà các\l"
	.string "HLV sở hữu.\p"
	.string "Cách xếp này tránh để những HLV\n"
	.string "mạnh phải gặp nhau ngay từ đầu.$"

BattleFrontier_BattleDomeLobby_Text_ExplainTourneyTree:
	.string "Sơ đồ giải đấu, hay chúng tôi gọi là\n"
	.string "Tree, có thể xem bằng cách hỏi bất kỳ\l"
	.string "hướng dẫn viên nào trong Waiting Room.\p"
	.string "Tournament Tree cung cấp nhiều loại dữ\n"
	.string "liệu.\p"
	.string "Dữ liệu hiển thị gồm kết quả giải đấu\n"
	.string "trước, POKéMON của các HLV và\l"
	.string "phong cách chiến đấu của HLV.$"

BattleFrontier_BattleDomeLobby_Text_ExplainDoubleKORules:
	.string "Nếu các POKéMON đang đấu cùng ngất\n"
	.string "một lúc, tức double KO, trong một trận\l"
	.string "đấu giải, REFEREES sẽ xem lại trận đấu\l"
	.string "và tuyên bố người thắng.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global BattleFrontier_BattleDomeLobby_Text_WelcomeSingleBattle
	.global BattleFrontier_BattleDomeLobby_Text_TakeSinglesChallenge
	.global BattleFrontier_BattleDomeLobby_Text_HopeToSeeYouAgain
	.global BattleFrontier_BattleDomeLobby_Text_ExplainSinglesChallenge
	.global BattleFrontier_BattleDomeLobby_Text_OkayToSaveBeforeChallenge
	.global BattleFrontier_BattleDomeLobby_Text_WhichLevelMode
	.global BattleFrontier_BattleDomeLobby_Text_SelectThreeMons
	.global BattleFrontier_BattleDomeLobby_Text_NotEnoughValidMonsLvOpen
	.global BattleFrontier_BattleDomeLobby_Text_NotEnoughValidMonsLv50
	.global BattleFrontier_BattleDomeLobby_Text_ShowYouToBattleDome
	.global BattleFrontier_BattleDomeLobby_Text_DidntSaveBeforeQuitting
	.global BattleFrontier_BattleDomeLobby_Text_CongratsForWinningTourney
	.global BattleFrontier_BattleDomeLobby_Text_HereIsYourPrize
	.global BattleFrontier_BattleDomeLobby_Text_ReceivedPrize
	.global BattleFrontier_BattleDomeLobby_Text_BagFullMakeRoom
	.global BattleFrontier_BattleDomeLobby_Text_ThankYouForPlaying
	.global BattleFrontier_BattleDomeLobby_Text_RecordWillBeSaved
	.global BattleFrontier_BattleDomeLobby_Text_WeveBeenWaitingForYou
	.global BattleFrontier_BattleDomeLobby_Text_OkayToSaveBeforeChallenge2
	.global BattleFrontier_BattleDomeLobby_Text_WelcomeDoubleBattle
	.global BattleFrontier_BattleDomeLobby_Text_TakeDoublesChallenge
	.global BattleFrontier_BattleDomeLobby_Text_ExplainDoublesChallenge
	.global BattleFrontier_BattleDomeLobby_Text_PrevTourneyResultsSinglesLv50
	.global BattleFrontier_BattleDomeLobby_Text_PrevTourneyResultsDoublesLv50
	.global BattleFrontier_BattleDomeLobby_Text_PrevTourneyResultsSinglesLvOpen
	.global BattleFrontier_BattleDomeLobby_Text_PrevTourneyResultsDoublesLvOpen
	.global BattleFrontier_BattleDomeLobby_Text_LastWinnerWasTough
	.global BattleFrontier_OutsideWest_Text_LongDreamedAboutBattleFrontier
	.global BattleFrontier_OutsideWest_Text_BattleDomeSign2
	.global BattleFrontier_OutsideWest_Text_QuestionMarkUnderConstruction
	.global BattleFrontier_BattleDomeLobby_Text_WinnersGainReputation
	.global BattleFrontier_BattleDomeLobby_Text_TrashedInFirstRound
	.global BattleFrontier_BattleDomeLobby_Text_NeedToCheckOpponentCarefully
	.global BattleFrontier_BattleDomeLobby_Text_CongratsDefeatedTucker
	.global BattleFrontier_BattleDomeLobby_Text_AwardTheseBattlePoints
	.global BattleFrontier_BattleDomeLobby_Text_RecordLastMatch
	.global BattleFrontier_BattleDomeLobby_Text_RulesAreListed
	.global BattleFrontier_BattleDomeLobby_Text_ReadWhichHeading
	.global BattleFrontier_BattleDomeLobby_Text_ExplainMatchupRules
	.global BattleFrontier_BattleDomeLobby_Text_ExplainTourneyTree
	.global BattleFrontier_BattleDomeLobby_Text_ExplainDoubleKORules
@ END GENERATED LOCALIZATION EXPORTS
