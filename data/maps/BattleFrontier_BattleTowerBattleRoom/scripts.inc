BattleFrontier_BattleTowerBattleRoom_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleTowerBattleRoom_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleTowerBattleRoom_OnWarp
	.byte 0

BattleFrontier_BattleTowerBattleRoom_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleTowerBattleRoom_EventScript_SetUpObjects
	.2byte 0

BattleFrontier_BattleTowerBattleRoom_EventScript_SetUpObjects::
	setvar VAR_TEMP_1, 1
	applymovement LOCALID_TOWER_BATTLE_ATTENDANT_2, BattleFrontier_BattleTowerBattleRoom_Movement_SetInvisible
	end

BattleFrontier_BattleTowerBattleRoom_OnFrame:
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattleTowerBattleRoom_EventScript_EnterRoom
	.2byte 0

BattleFrontier_BattleTowerBattleRoom_EventScript_EnterRoom::
	setvar VAR_TEMP_0, 1
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerBattleRoom_Movement_PlayerEnter
	waitmovement 0
	frontier_get FRONTIER_DATA_BATTLE_NUM
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleTowerBattleRoom_EventScript_OpponentEnter
	applymovement LOCALID_TOWER_BATTLE_ATTENDANT_1, BattleFrontier_BattleTowerBattleRoom_Movement_AttendantApproachPlayer
	waitmovement 0
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerBattleRoom_Movement_PlayerFaceAttendant
	waitmovement 0
	setvar VAR_TEMP_2, 1
	frontier_set FRONTIER_DATA_RECORD_DISABLED, TRUE
	goto BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponent

BattleFrontier_BattleTowerBattleRoom_EventScript_OpponentEnter::
	tower_setopponent
	addobject LOCALID_TOWER_BATTLE_OPPONENT
	applymovement LOCALID_TOWER_BATTLE_OPPONENT, BattleFrontier_BattleTowerBattleRoom_Movement_OpponentEnter
	waitmovement 0
	tower_getopponentintro 0
	msgbox gStringVar4, MSGBOX_DEFAULT
	waitmessage
	call BattleFrontier_BattleTowerBattleRoom_EventScript_DoTowerBattle
	switch VAR_RESULT
	case B_OUTCOME_WON, BattleFrontier_BattleTowerBattleRoom_EventScript_DefeatedOpponent
BattleFrontier_BattleTower_EventScript_WarpToLobbyLost::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST
	tower_set TOWER_DATA_LVL_MODE
	setvar VAR_0x8004, FANCOUNTER_USED_BATTLE_TOWER
	special Script_TryGainNewFanFromCounter
	goto BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobby

BattleFrontier_BattleTowerBattleRoom_EventScript_DefeatedOpponent::
	call BattleFrontier_EventScript_IncrementWinStreak
	tower_setbattlewon
	switch VAR_RESULT
	case 7, BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobbyWon
	applymovement LOCALID_TOWER_BATTLE_OPPONENT, BattleFrontier_BattleTowerBattleRoom_Movement_OpponentExit
	waitmovement 0
	removeobject LOCALID_TOWER_BATTLE_OPPONENT
	frontier_getbrainstatus
	call_if_ne VAR_RESULT, FRONTIER_BRAIN_NOT_READY, BattleFrontier_BattleTowerBattleRoom_EventScript_SecondAttendantEnter
	applymovement LOCALID_TOWER_BATTLE_ATTENDANT_1, BattleFrontier_BattleTowerBattleRoom_Movement_AttendantApproachPlayer
	waitmovement 0
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerBattleRoom_Movement_PlayerFaceAttendant
	waitmovement 0
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_RestoreMonsToFullHealth, MSGBOX_DEFAULT
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponent::
	frontier_getbrainstatus
	copyvar VAR_TEMP_F, VAR_RESULT
	goto_if_ne VAR_RESULT, FRONTIER_BRAIN_NOT_READY, BattleFrontier_BattleTowerBattleRoom_EventScript_MaidenUpNext
	frontier_get FRONTIER_DATA_BATTLE_NUM
	call BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyForOpponent
	call BattleFrontier_EventScript_GetCantRecordBattle
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponentNoRecord
	multichoice 19, 4, MULTI_GO_ON_RECORD_REST_RETIRE, TRUE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleTowerBattleRoom_EventScript_ContinueChallenge
	case 1, BattleFrontier_BattleTowerBattleRoom_EventScript_AskRecordBattle
	case 2, BattleFrontier_BattleTowerBattleRoom_EventScript_AskPauseChallenge
	case 3, BattleFrontier_BattleTowerBattleRoom_EventScript_AskRetireChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponent

BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponentNoRecord::
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, TRUE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleTowerBattleRoom_EventScript_ContinueChallenge
	case 1, BattleFrontier_BattleTowerBattleRoom_EventScript_AskPauseChallenge
	case 2, BattleFrontier_BattleTowerBattleRoom_EventScript_AskRetireChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponent

BattleFrontier_BattleTowerBattleRoom_EventScript_AskRecordBattle::
	message BattleFrontier_BattleTowerBattleRoom_Text_RecordYourBattle
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponent
	case 0, BattleFrontier_BattleTowerBattleRoom_EventScript_RecordBattle
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponent

BattleFrontier_BattleTowerBattleRoom_EventScript_RecordBattle::
	call BattleFrontier_EventScript_SaveBattle
	goto BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponent

BattleFrontier_BattleTowerBattleRoom_EventScript_AskPauseChallenge::
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_SaveAndQuitGame, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponent
	case YES, BattleFrontier_BattleTowerBattleRoom_EventScript_PauseChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponent

BattleFrontier_BattleTowerBattleRoom_EventScript_AskRetireChallenge::
	message BattleFrontier_BattleTowerBattleRoom_Text_CancelYourChallenge
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponent
	case 0, BattleFrontier_BattleTowerBattleRoom_EventScript_RetireChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponent

BattleFrontier_BattleTowerBattleRoom_EventScript_ContinueChallenge::
	closemessage
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerBattleRoom_Movement_PlayerFaceBattle
	waitmovement 0
	applymovement LOCALID_TOWER_BATTLE_ATTENDANT_1, BattleFrontier_BattleTowerBattleRoom_Movement_AttendantReturnToPos
	waitmovement 0
	goto BattleFrontier_BattleTowerBattleRoom_EventScript_OpponentEnter

BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobbyWon::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_WON
	tower_set TOWER_DATA_LVL_MODE
	setvar VAR_0x8004, FANCOUNTER_USED_BATTLE_TOWER
	special Script_TryGainNewFanFromCounter
	goto BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobby

BattleFrontier_BattleTowerBattleRoom_EventScript_PauseChallenge::
	message BattleFrontier_BattleTowerBattleRoom_Text_SavingPleaseWait
	waitmessage
	tower_save CHALLENGE_STATUS_PAUSED
	playse SE_SAVE
	waitse
	fadescreen FADE_TO_BLACK
	frontier_reset
	end

BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyForOpponent::
	copyvar VAR_TEMP_F, VAR_RESULT
	switch VAR_TEMP_F
	case 1, BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyFor2ndOpponent
	case 2, BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyFor3rdOpponent
	case 3, BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyFor4thOpponent
	case 4, BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyFor5thOpponent
	case 5, BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyFor6thOpponent
	case 6, BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyFor7thOpponent

BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyFor2ndOpponent::
	message BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor2ndOpponent
	waitmessage
	return

BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyFor3rdOpponent::
	message BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor3rdOpponent
	waitmessage
	return

BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyFor4thOpponent::
	message BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor4thOpponent
	waitmessage
	return

BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyFor5thOpponent::
	message BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor5thOpponent
	waitmessage
	return

BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyFor6thOpponent::
	message BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor6thOpponent
	waitmessage
	return

BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyFor7thOpponent::
	message BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor7thOpponent
	waitmessage
	return

BattleFrontier_EventScript_IncrementWinStreak::
	frontier_incrementstreak
	return

BattleFrontier_BattleTowerBattleRoom_EventScript_SecondAttendantEnter::
	applymovement LOCALID_TOWER_BATTLE_ATTENDANT_2, BattleFrontier_BattleTowerBattleRoom_Movement_SecondAttendantEnter
	waitmovement 0
	applymovement LOCALID_TOWER_BATTLE_ATTENDANT_2, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_TOWER_BATTLE_ATTENDANT_1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_TOWER_BATTLE_ATTENDANT_1, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_TOWER_BATTLE_ATTENDANT_2, BattleFrontier_BattleTowerBattleRoom_Movement_SecondAttendantDelay
	applymovement LOCALID_TOWER_BATTLE_ATTENDANT_1, BattleFrontier_BattleTowerBattleRoom_Movement_AttendantFaceSecondAttendant
	waitmovement 0
	applymovement LOCALID_TOWER_BATTLE_ATTENDANT_2, BattleFrontier_BattleTowerBattleRoom_Movement_SecondAttendantExit
	waitmovement 0
	return

BattleFrontier_BattleTowerBattleRoom_EventScript_MaidenUpNext::
	goto_if_eq VAR_TEMP_2, 1, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForMaiden
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_SalonMaidenOnHerWay, MSGBOX_DEFAULT
	setvar VAR_TEMP_2, 1
BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForMaiden::
	message BattleFrontier_BattleTowerBattleRoom_Text_ReadyForSalonMaiden
	waitmessage
	call BattleFrontier_EventScript_GetCantRecordBattle
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForMaidenNoRecord
	multichoice 19, 4, MULTI_GO_ON_RECORD_REST_RETIRE, TRUE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleTowerBattleRoom_EventScript_BattleAnabel
	case 1, BattleFrontier_BattleTowerBattleRoom_EventScript_AskRecordBattle
	case 2, BattleFrontier_BattleTowerBattleRoom_EventScript_AskPauseChallenge
	case 3, BattleFrontier_BattleTowerBattleRoom_EventScript_AskRetireChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForMaiden

BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForMaidenNoRecord::
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, TRUE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleTowerBattleRoom_EventScript_BattleAnabel
	case 1, BattleFrontier_BattleTowerBattleRoom_EventScript_AskPauseChallenge
	case 2, BattleFrontier_BattleTowerBattleRoom_EventScript_AskRetireChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForMaiden

BattleFrontier_BattleTowerBattleRoom_EventScript_BattleAnabel::
	call BattleFrontier_EventScript_SetBrainObjectGfx
	closemessage
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerBattleRoom_Movement_PlayerFaceBattle
	waitmovement 0
	applymovement LOCALID_TOWER_BATTLE_ATTENDANT_1, BattleFrontier_BattleTowerBattleRoom_Movement_AttendantReturnToPos
	waitmovement 0
	addobject LOCALID_TOWER_BATTLE_OPPONENT
	applymovement LOCALID_TOWER_BATTLE_OPPONENT, BattleFrontier_BattleTowerBattleRoom_Movement_AnabelEnter
	waitmovement 0
	switch VAR_TEMP_F
	case FRONTIER_BRAIN_GOLD, BattleFrontier_BattleTowerBattleRoom_EventScript_AnabelGoldIntro
	case FRONTIER_BRAIN_STREAK, BattleFrontier_BattleTowerBattleRoom_EventScript_BattleAnabelSilver
	case FRONTIER_BRAIN_STREAK_LONG, BattleFrontier_BattleTowerBattleRoom_EventScript_BattleAnabelGold
	frontier_get FRONTIER_DATA_HEARD_BRAIN_SPEECH
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattleTowerBattleRoom_EventScript_BattleAnabelSilver
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_GreetingsImAnabel, MSGBOX_DEFAULT
	frontier_set FRONTIER_DATA_HEARD_BRAIN_SPEECH
BattleFrontier_BattleTowerBattleRoom_EventScript_BattleAnabelSilver::
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_LetMeSeeYourTalent, MSGBOX_DEFAULT
	call BattleFrontier_BattleTowerBattleRoom_EventScript_DoTowerBattle
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, BattleFrontier_BattleTowerBattleRoom_EventScript_DefeatedAnabelSilver
	goto BattleFrontier_BattleTower_EventScript_WarpToLobbyLost

BattleFrontier_BattleTowerBattleRoom_EventScript_DefeatedAnabelSilver::
	call BattleFrontier_EventScript_IncrementWinStreak
	frontier_getsymbols
	goto_if_ne VAR_RESULT, 0, BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobbyWon
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_AnabelTalentShallBeRecognized, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_SYMBOL
	message BattleFrontier_BattleTowerBattleRoom_Text_ReceivedAbilitySymbol
	waitmessage
	waitfanfare
	frontier_givesymbol
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_UntilNextTime, MSGBOX_DEFAULT
	goto BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobbyWon

BattleFrontier_BattleTowerBattleRoom_EventScript_AnabelGoldIntro::
	frontier_get FRONTIER_DATA_HEARD_BRAIN_SPEECH
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattleTowerBattleRoom_EventScript_BattleAnabelGold
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_AnabelYouCameBack, MSGBOX_DEFAULT
	frontier_set FRONTIER_DATA_HEARD_BRAIN_SPEECH
BattleFrontier_BattleTowerBattleRoom_EventScript_BattleAnabelGold::
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_LetsBeginShallWe, MSGBOX_DEFAULT
	call BattleFrontier_BattleTowerBattleRoom_EventScript_DoTowerBattle
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, BattleFrontier_BattleTowerBattleRoom_EventScript_DefeatedAnabelGold
	goto BattleFrontier_BattleTower_EventScript_WarpToLobbyLost

BattleFrontier_BattleTowerBattleRoom_EventScript_DefeatedAnabelGold::
	call BattleFrontier_EventScript_IncrementWinStreak
	frontier_getsymbols
	goto_if_eq VAR_RESULT, 2, BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobbyWon
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_AnabelCongratsYourPassPlease, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_SYMBOL
	message BattleFrontier_BattleTowerBattleRoom_Text_AbilitySymbolTookGoldenShine
	waitmessage
	waitfanfare
	frontier_givesymbol
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_WishICouldBattleYouAgain, MSGBOX_DEFAULT
	goto BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobbyWon

BattleFrontier_BattleTowerBattleRoom_EventScript_DoTowerBattle::
	closemessage
	setvar VAR_TEMP_2, 0
	frontier_set FRONTIER_DATA_RECORD_DISABLED, FALSE
	special HealPlayerParty
	setvar VAR_0x8004, SPECIAL_BATTLE_TOWER
	setvar VAR_0x8005, 0
	special DoSpecialTrainerBattle
	copyvar VAR_0x8004, VAR_FRONTIER_BATTLE_MODE
	goto_if_eq VAR_0x8004, FRONTIER_MODE_LINK_MULTIS, BattleFrontier_BattleTowerBattleRoom_EventScript_EndTowerBattle
	frontier_restorehelditems
	special HealPlayerParty
	frontier_resetsketch
BattleFrontier_BattleTowerBattleRoom_EventScript_EndTowerBattle::
	tower_setinterviewdata
	frontier_get FRONTIER_DATA_BATTLE_OUTCOME
	return

BattleFrontier_EventScript_SetBrainObjectGfx::
	frontier_setbrainobj
	return

BattleFrontier_BattleTowerBattleRoom_Movement_PlayerEnter:
	walk_up
	walk_up
	walk_up
	face_right
	step_end

BattleFrontier_BattleTowerBattleRoom_Movement_PlayerFaceAttendant:
	face_down
	step_end

BattleFrontier_BattleTowerBattleRoom_Movement_PlayerFaceBattle:
	face_right
	step_end

BattleFrontier_BattleTowerBattleRoom_Movement_OpponentEnter:
	walk_down
	walk_down
	walk_down
	walk_down
	face_left
	step_end

BattleFrontier_BattleTowerBattleRoom_Movement_OpponentExit:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_BattleTowerBattleRoom_Movement_AttendantApproachPlayer:
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

BattleFrontier_BattleTowerBattleRoom_Movement_AttendantReturnToPos:
	walk_down
	walk_left
	walk_left
	walk_left
	face_right
	step_end

BattleFrontier_BattleTowerBattleRoom_Movement_SetInvisible:
	set_invisible
	step_end

BattleFrontier_BattleTowerBattleRoom_Movement_SecondAttendantEnter:
	set_visible
	delay_16
	walk_up
	walk_left
	walk_left
	delay_8
	step_end

BattleFrontier_BattleTowerBattleRoom_Movement_SecondAttendantExit:
	walk_right
	walk_right
	walk_down
	set_invisible
	step_end

BattleFrontier_BattleTowerBattleRoom_Movement_SecondAttendantDelay:
	delay_16
	delay_16
	delay_16
	delay_16
	step_end

BattleFrontier_BattleTowerBattleRoom_Movement_AttendantFaceSecondAttendant:
	face_right
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_right
	step_end

BattleFrontier_BattleTowerBattleRoom_Movement_AnabelEnter:
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	face_left
	step_end

BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobby::
	copyvar VAR_RESULT, VAR_FRONTIER_BATTLE_MODE
	goto_if_eq VAR_RESULT, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobbyDoubles
	goto_if_eq VAR_RESULT, FRONTIER_MODE_MULTIS, BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobbyMultis
	goto_if_eq VAR_RESULT, FRONTIER_MODE_LINK_MULTIS, BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobbyLinkMultis
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_LOBBY, 6, 6
	waitstate
	end

BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobbyDoubles::
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_LOBBY, 10, 6
	waitstate
	end

BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobbyMultis::
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_LOBBY, 14, 6
	waitstate
	end

BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobbyLinkMultis::
	tower_closelink
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_LOBBY, 18, 6
	waitstate
	end

BattleFrontier_BattleTowerBattleRoom_EventScript_RetireChallenge::
	setflag FLAG_CANCEL_BATTLE_ROOM_CHALLENGE
	goto BattleFrontier_BattleTower_EventScript_WarpToLobbyLost
	end

BattleFrontier_BattleTowerBattleRoom_Text_RestoreMonsToFullHealth:
	.string "Chúng tôi sẽ hồi phục hoàn toàn sức\n"
	.string "khỏe cho POKéMON của bạn.$"

@ Unused
BattleFrontier_BattleTowerBattleRoom_Text_ReadyForOpponent:
	.string "Bạn sẽ đối đầu với đối thủ số\n"
	.string "{STR_VAR_1}. Bạn đã sẵn sàng\l"
	.string "chưa?$"

BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor2ndOpponent:
	.string "Bạn sẽ đối đầu với đối thủ số 2. Bạn đã\n"
	.string "sẵn sàng chưa?$"

BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor3rdOpponent:
	.string "Bạn sẽ đối đầu với đối thủ số 3. Bạn đã\n"
	.string "sẵn sàng chưa?$"

BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor4thOpponent:
	.string "Bạn sẽ đối đầu với đối thủ số 4. Bạn đã\n"
	.string "sẵn sàng chưa?$"

BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor5thOpponent:
	.string "Bạn sẽ đối đầu với đối thủ số 5. Bạn đã\n"
	.string "sẵn sàng chưa?$"

BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor6thOpponent:
	.string "Bạn sẽ đối đầu với đối thủ số 6. Bạn đã\n"
	.string "sẵn sàng chưa?$"

BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor7thOpponent:
	.string "Bạn sẽ đối đầu với đối thủ số 7. Bạn đã\n"
	.string "sẵn sàng chưa?$"

BattleFrontier_BattleTowerBattleRoom_Text_RecordYourBattle:
	.string "Ghi lại trận đấu của bạn vào FRONTIER\n"
	.string "PASS chứ?$"

BattleFrontier_BattleTowerLobby_Text_BattleRecordedOnPass:
	.string "Trận đấu của {PLAYER} đã được ghi\n"
	.string "vào FRONTIER PASS.$"

BattleFrontier_BattleTowerBattleRoom_Text_SaveAndQuitGame:
	.string "Bạn có muốn lưu rồi thoát trò chơi\n"
	.string "không?$"

BattleFrontier_BattleTowerBattleRoom_Text_SavingPleaseWait:
	.string "Đang lưu dữ liệu trận đấu. Vui lòng chờ.$"

BattleFrontier_BattleTowerBattleRoom_Text_CancelYourChallenge:
	.string "Bạn có muốn hủy thử thách tại BATTLE\n"
	.string "ROOM không?$"

BattleFrontier_BattleTowerBattleRoom_Text_RecordCouldntBeSaved::
	.string "Đã xảy ra lỗi. Không thể lưu thành tích\n"
	.string "của bạn.$"

BattleFrontier_BattleTowerBattleRoom_Text_SalonMaidenOnHerWay:
	.string "Xin lỗi, nhưng...\p"
	.string "Thủ lĩnh của chúng tôi, SALON MAIDEN,\n"
	.string "đang trên đường tới đây vì muốn đấu\l"
	.string "với bạn.\p"
	.string "Cô ấy sẽ đến ngay thôi.$"

BattleFrontier_BattleTowerBattleRoom_Text_ReadyForSalonMaiden:
	.string "Bạn sẽ đối đầu với SALON MAIDEN. Bạn đã\n"
	.string "chuẩn bị xong chưa?$"

BattleFrontier_BattleTowerBattleRoom_Text_GreetingsImAnabel:
	.string "Xin chào... Tôi là ANABEL.\p"
	.string "Tôi là SALON MAIDEN, người phụ trách\n"
	.string "điều hành BATTLE TOWER...\p"
	.string "Tôi đã nghe khá nhiều lời đồn về bạn...\p"
	.string "Thành thật mà nói, chẳng điều gì tôi\n"
	.string "nghe được khiến tôi thấy hứng thú...\p"
	.string "Lý do tôi đến gặp bạn... Chà, chỉ có một\n"
	.string "lý do duy nhất...$"

BattleFrontier_BattleTowerBattleRoom_Text_LetMeSeeYourTalent:
	.string "Hãy cho tôi thấy toàn bộ tài năng của\n"
	.string "bạn...$"

BattleFrontier_BattleTowerBattleRoom_Text_AnabelTalentShallBeRecognized:
	.string "ANABEL: Fu fu fu, bạn làm tốt lắm...\p"
	.string "Cho tôi xem FRONTIER PASS... Tài năng\n"
	.string "của bạn sẽ được công nhận.$"

BattleFrontier_BattleTowerBattleRoom_Text_ReceivedAbilitySymbol:
	.string "Ability Symbol đã được khắc lên\n"
	.string "FRONTIER PASS!$"

BattleFrontier_BattleTowerBattleRoom_Text_UntilNextTime:
	.string "... ... ... ... ... ...\p"
	.string "Bạn rất tự tin vào tài năng đấu POKéMON\n"
	.string "của mình, đúng không?\p"
	.string "Tôi mong bạn sẽ tiếp tục chiến đấu và\n"
	.string "tiếp tục chiến thắng.\p"
	.string "Tôi sẽ chờ bạn. Cho đến lần gặp lại...$"

BattleFrontier_BattleTowerBattleRoom_Text_AnabelYouCameBack:
	.string "ANABEL: Bạn thật sự đã quay lại gặp\n"
	.string "tôi...\p"
	.string "... ... ... ... ... ...\p"
	.string "Bạn đã thắng liên tiếp để đến gặp tôi...\n"
	.string "Tôi không cần phải nương tay với bạn\l"
	.string "nữa...\p"
	.string "Đã quá lâu rồi...\p"
	.string "Quá lâu kể từ lần cuối tôi có thể chiến\n"
	.string "đấu mà không phải nghĩ ngợi điều gì...$"

BattleFrontier_BattleTowerBattleRoom_Text_LetsBeginShallWe:
	.string "Chúng ta bắt đầu nhé?$"

BattleFrontier_BattleTowerBattleRoom_Text_AnabelCongratsYourPassPlease:
	.string "ANABEL: Fu fu, chúc mừng bạn... Cho tôi\n"
	.string "xem FRONTIER PASS...$"

BattleFrontier_BattleTowerBattleRoom_Text_AbilitySymbolTookGoldenShine:
	.string "Ability Symbol đã tỏa ánh vàng rực rỡ!$"

BattleFrontier_BattleTowerBattleRoom_Text_WishICouldBattleYouAgain:
	.string "Thật vui...\p"
	.string "Tôi chưa từng có một trận đấu POKéMON\n"
	.string "nào thú vị đến thế...\p"
	.string "Tôi ước mình có thể đấu với bạn lần\n"
	.string "nữa...$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global BattleFrontier_BattleTowerBattleRoom_Text_RestoreMonsToFullHealth
	.global BattleFrontier_BattleTowerBattleRoom_Text_ReadyForOpponent
	.global BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor2ndOpponent
	.global BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor3rdOpponent
	.global BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor4thOpponent
	.global BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor5thOpponent
	.global BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor6thOpponent
	.global BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor7thOpponent
	.global BattleFrontier_BattleTowerBattleRoom_Text_RecordYourBattle
	.global BattleFrontier_BattleTowerLobby_Text_BattleRecordedOnPass
	.global BattleFrontier_BattleTowerBattleRoom_Text_SaveAndQuitGame
	.global BattleFrontier_BattleTowerBattleRoom_Text_SavingPleaseWait
	.global BattleFrontier_BattleTowerBattleRoom_Text_CancelYourChallenge
	.global BattleFrontier_BattleTowerBattleRoom_Text_RecordCouldntBeSaved
	.global BattleFrontier_BattleTowerBattleRoom_Text_SalonMaidenOnHerWay
	.global BattleFrontier_BattleTowerBattleRoom_Text_ReadyForSalonMaiden
	.global BattleFrontier_BattleTowerBattleRoom_Text_GreetingsImAnabel
	.global BattleFrontier_BattleTowerBattleRoom_Text_LetMeSeeYourTalent
	.global BattleFrontier_BattleTowerBattleRoom_Text_AnabelTalentShallBeRecognized
	.global BattleFrontier_BattleTowerBattleRoom_Text_ReceivedAbilitySymbol
	.global BattleFrontier_BattleTowerBattleRoom_Text_UntilNextTime
	.global BattleFrontier_BattleTowerBattleRoom_Text_AnabelYouCameBack
	.global BattleFrontier_BattleTowerBattleRoom_Text_LetsBeginShallWe
	.global BattleFrontier_BattleTowerBattleRoom_Text_AnabelCongratsYourPassPlease
	.global BattleFrontier_BattleTowerBattleRoom_Text_AbilitySymbolTookGoldenShine
	.global BattleFrontier_BattleTowerBattleRoom_Text_WishICouldBattleYouAgain
@ END GENERATED LOCALIZATION EXPORTS
