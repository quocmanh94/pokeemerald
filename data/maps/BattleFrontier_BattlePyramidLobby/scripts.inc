BattleFrontier_BattlePyramidLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePyramidLobby_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleDomeLobby_OnWarp
	.byte 0

@ Unused. Pyramid uses Dome's OnWarp (presumably by mistake). Their effects are identical
BattleFrontier_BattlePyramidLobby_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattlePyramidLobby_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattlePyramidLobby_EventScript_TurnPlayerNorth:
	setvar VAR_TEMP_1, 1
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattlePyramidLobby_OnFrame:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattlePyramidLobby_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePyramidLobby_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattlePyramidLobby_EventScript_ResumeChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattlePyramidLobby_EventScript_WonChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattlePyramidLobby_EventScript_LostChallenge
	.2byte 0

BattleFrontier_BattlePyramidLobby_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

BattleFrontier_BattlePyramidLobby_EventScript_QuitWithoutSaving::
	lockall
	message BattleFrontier_BattlePyramidLobby_Text_DidntSaveBeforeQuittingTakeBag
	waitmessage
	playse SE_EXP_MAX
	waitse
	closemessage
	pyramid_set PYRAMID_DATA_WIN_STREAK, 0
	pyramid_set PYRAMID_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_WonChallenge::
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePyramidLobby_EventScript_DefeatedKing
	msgbox BattleFrontier_BattlePyramidLobby_Text_YouveConqueredPyramid, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_GiveBattlePoints

BattleFrontier_BattlePyramidLobby_EventScript_DefeatedKing::
	msgbox BattleFrontier_BattlePyramidLobby_Text_YouveDefeatedPyramidKing, MSGBOX_DEFAULT
BattleFrontier_BattlePyramidLobby_EventScript_GiveBattlePoints::
	special DoBattlePyramidMonsHaveHeldItem
	call_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePyramidLobby_EventScript_StoreHeldItemsInPyramidBag
	clearflag FLAG_STORING_ITEMS_IN_PYRAMID_BAG
	frontier_checkairshow
	special LoadPlayerParty
	pyramid_clearhelditems
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	message BattleFrontier_BattlePyramidLobby_Text_UsedBattleBagWillBeKept
	waitmessage
	playse SE_EXP_MAX
	waitse
	msgbox BattleFrontier_BattlePyramidLobby_Text_GiveYouTheseBattlePoints, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	message BattleFrontier_BattlePyramidLobby_Text_RecordResultsWait
	waitmessage
	pyramid_setprize
	pyramid_save 0
	playse SE_SAVE
	waitse
	msgbox BattleFrontier_BattlePyramidLobby_Text_LookForwardToNextChallenge, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_LostChallenge::
	frontier_checkairshow
	special LoadPlayerParty
	pyramid_clearhelditems
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	lockall
	message BattleFrontier_BattlePyramidLobby_Text_DisappointingHereIsBag
	waitmessage
	playse SE_EXP_MAX
	waitse
	message BattleFrontier_BattlePyramidLobby_Text_RecordResultsWait
	waitmessage
	pyramid_set PYRAMID_DATA_WIN_STREAK_ACTIVE, FALSE
	pyramid_save 0
	playse SE_SAVE
	waitse
	msgbox BattleFrontier_BattlePyramidLobby_Text_LookForwardToNextChallenge, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_ResumeChallenge::
	goto BattleFrontier_BattlePyramidLobby_EventScript_EnterChallenge

BattleFrontier_BattlePyramidLobby_EventScript_Attendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_PYRAMID
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	special SavePlayerParty
	msgbox BattleFrontier_BattlePyramidLobby_Text_WelcomeToBattlePyramid, MSGBOX_DEFAULT
BattleFrontier_BattlePyramidLobby_EventScript_AskTakeChallenge::
	message BattleFrontier_BattlePyramidLobby_Text_EmbarkOnChallenge
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_TryEnterChallenge
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_ExplainChallenge
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge

BattleFrontier_BattlePyramidLobby_EventScript_TryEnterChallenge::
	message BattleFrontier_BattlePyramidLobby_Text_WhichLevelMode
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMons
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattlePyramidLobby_Text_SelectThreeMons, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	callnative RemoveFollowingPokemon
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidLobby_EventScript_LoadPartyAndCancelChallenge
	msgbox BattleFrontier_BattlePyramidLobby_Text_OkayToSaveBeforeChallenge, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattlePyramidLobby_EventScript_LoadPartyAndCancelChallenge
	case YES, BattleFrontier_BattlePyramidLobby_EventScript_SaveBeforeChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_LoadPartyAndCancelChallenge

BattleFrontier_BattlePyramidLobby_EventScript_SaveBeforeChallenge::
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	pyramid_init
	pyramid_set PYRAMID_DATA_WIN_STREAK_ACTIVE, TRUE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	pyramid_seedfloor
	pyramid_settrainers
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallengeSaveFailed
BattleFrontier_BattlePyramidLobby_EventScript_EnterChallenge::
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	msgbox BattleFrontier_BattlePyramidLobby_Text_ShowYouIntoPyramid, MSGBOX_DEFAULT
	closemessage
	call BattleFrontier_BattlePyramidLobby_EventScript_WalkToPanelAndReceiveBag
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_RESULT, 0
	special HealPlayerParty
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR, 1, 1
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	waitstate
	end

BattleFrontier_BattlePyramidLobby_EventScript_ExplainChallenge::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainBattlePyramid, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_AskTakeChallenge

BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMons::
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMonsLv50
	case FRONTIER_LVL_OPEN, BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMonsLvOpen

BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMonsLv50::
	msgbox BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsLv50, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_EndCancelChallenge

BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMonsLvOpen::
	msgbox BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsLvOpen, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_EndCancelChallenge

BattleFrontier_BattlePyramidLobby_EventScript_CancelChallengeSaveFailed::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge

BattleFrontier_BattlePyramidLobby_EventScript_LoadPartyAndCancelChallenge::
	special LoadPlayerParty
	callnative UpdateFollowingPokemon
BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge::
	msgbox BattleFrontier_BattlePyramidLobby_Text_AwaitFutureChallenge, MSGBOX_DEFAULT
BattleFrontier_BattlePyramidLobby_EventScript_EndCancelChallenge::
	release
	end

BattleFrontier_BattlePyramidLobby_EventScript_HintGiver::
	lockall
	applymovement LOCALID_PYRAMID_LOBBY_HINT_GIVER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox BattleFrontier_BattlePyramidLobby_Text_TellYouWhatMisfortunesAwait, MSGBOX_DEFAULT
	call BattleFrontier_BattlePyramidLobby_EventScript_GiveHint
	msgbox BattleFrontier_BattlePyramidLobby_Text_BelieveMyFortunesOrNot, MSGBOX_DEFAULT
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_GiveHint::
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattlePyramidLobby_EventScript_GiveHintLv50
	case FRONTIER_LVL_OPEN, BattleFrontier_BattlePyramidLobby_EventScript_GiveHintLvOpen
	case FRONTIER_LVL_TENT, BattleFrontier_BattlePyramidLobby_EventScript_NoHint
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_NoHint
	return

@ Shouldnt occur
BattleFrontier_BattlePyramidLobby_EventScript_NoHint::
	return

BattleFrontier_BattlePyramidLobby_EventScript_GiveHintLv50::
	msgbox BattleFrontier_BattlePyramidLobby_Text_Aah, MSGBOX_DEFAULT
	pyramid_get PYRAMID_DATA_WIN_STREAK_ACTIVE_50
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattlePyramidLobby_EventScript_GiveHintGetLv50Streak
	setvar VAR_RESULT, 0
	goto BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment
	return

BattleFrontier_BattlePyramidLobby_EventScript_GiveHintGetLv50Streak::
	pyramid_get PYRAMID_DATA_WIN_STREAK_50
	goto BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment
	return

BattleFrontier_BattlePyramidLobby_EventScript_GiveHintLvOpen::
	msgbox BattleFrontier_BattlePyramidLobby_Text_Aah, MSGBOX_DEFAULT
	pyramid_get PYRAMID_DATA_WIN_STREAK_ACTIVE_OPEN
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattlePyramidLobby_EventScript_GiveHintGetLvOpenStreak
	setvar VAR_RESULT, 0
	goto BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment
	return

BattleFrontier_BattlePyramidLobby_EventScript_GiveHintGetLvOpenStreak::
	pyramid_get PYRAMID_DATA_WIN_STREAK_OPEN
	goto BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment
	return

BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment::
	copyvar VAR_0x8004, VAR_RESULT
	special GetBattlePyramidHint
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_HintParalysis
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_HintPoison
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_HintBurn
	case 3, BattleFrontier_BattlePyramidLobby_EventScript_HintPPWaste
	case 4, BattleFrontier_BattlePyramidLobby_EventScript_HintLevitate
	case 5, BattleFrontier_BattlePyramidLobby_EventScript_HintTrapAbility
	case 6, BattleFrontier_BattlePyramidLobby_EventScript_HintIce
	case 7, BattleFrontier_BattlePyramidLobby_EventScript_HintExplosion
	case 8, BattleFrontier_BattlePyramidLobby_EventScript_HintPsychic
	case 9, BattleFrontier_BattlePyramidLobby_EventScript_HintRock
	case 10, BattleFrontier_BattlePyramidLobby_EventScript_HintFighting
	case 11, BattleFrontier_BattlePyramidLobby_EventScript_HintWeather
	case 12, BattleFrontier_BattlePyramidLobby_EventScript_HintBug
	case 13, BattleFrontier_BattlePyramidLobby_EventScript_HintDark
	case 14, BattleFrontier_BattlePyramidLobby_EventScript_HintWater
	case 15, BattleFrontier_BattlePyramidLobby_EventScript_HintGhost
	case 16, BattleFrontier_BattlePyramidLobby_EventScript_HintSteel
	case 17, BattleFrontier_BattlePyramidLobby_EventScript_HintFlyingDragon
	case 18, BattleFrontier_BattlePyramidLobby_EventScript_HintStoneEvolve
	case 19, BattleFrontier_BattlePyramidLobby_EventScript_HintNormal
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintParalysis::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintParalysis, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintPoison::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintPoison, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintBurn::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintBurn, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintPPWaste::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintPPWaste, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintLevitate::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintLevitate, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintTrapAbility::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintTrapAbility, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintIce::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintIce, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintExplosion::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintExplosion, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintPsychic::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintPsychic, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintRock::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintRock, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintFighting::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintFighting, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintWeather::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintWeather, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintBug::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintBug, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintDark::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintDark, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintWater::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintWater, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintGhost::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintGhost, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintSteel::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintSteel, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintFlyingDragon::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintFlyingDragon, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintStoneEvolve::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintStoneEvolve, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintNormal::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintNormal, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_ShowResults::
	lockall
	frontier_results FRONTIER_FACILITY_PYRAMID
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_WalkToPanelAndReceiveBag::
	applymovement LOCALID_PYRAMID_LOBBY_ATTENDANT, BattleFrontier_BattlePyramidLobby_Movement_AttendantWalkToPanel
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePyramidLobby_Movement_PlayerWalkToPanel
	waitmovement 0
	msgbox BattleFrontier_BattlePyramidLobby_Text_WeWillHoldBagForSafekeeping, MSGBOX_DEFAULT
	pyramid_get PYRAMID_DATA_WIN_STREAK
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidLobby_EventScript_ReceiveNewBattleBag
	msgbox BattleFrontier_BattlePyramidLobby_Text_PleaseTakePreviousBattleBag, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReceiveBattleBag

BattleFrontier_BattlePyramidLobby_EventScript_ReceiveNewBattleBag::
	msgbox BattleFrontier_BattlePyramidLobby_Text_PleaseTakeThisBattleBag, MSGBOX_DEFAULT
BattleFrontier_BattlePyramidLobby_EventScript_ReceiveBattleBag::
	message BattleFrontier_BattlePyramidLobby_Text_ExchangedBagForBattleBag
	waitmessage
	playse SE_EXP_MAX
	waitse
	msgbox BattleFrontier_BattlePyramidLobby_Text_StepOnFloorPanel, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PYRAMID_LOBBY_ATTENDANT, BattleFrontier_BattlePyramidLobby_Movement_AttendantMoveAside
	waitmovement 0
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePyramidLobby_Movement_PlayerStepOnPanel
	waitmovement 0
	return

BattleFrontier_BattlePyramidLobby_Movement_AttendantWalkToPanel:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_down
	step_end

BattleFrontier_BattlePyramidLobby_Movement_PlayerWalkToPanel:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_BattlePyramidLobby_Movement_AttendantMoveAside:
	walk_right
	face_left
	step_end

BattleFrontier_BattlePyramidLobby_Movement_PlayerStepOnPanel:
	walk_up
	walk_up
	step_end

BattleFrontier_BattlePyramidLobby_EventScript_StoreHeldItemsInPyramidBag::
	msgbox BattleFrontier_BattlePyramidLobby_Text_MonHoldingItemCannotTake, MSGBOX_DEFAULT
	setflag FLAG_STORING_ITEMS_IN_PYRAMID_BAG
	special TryStoreHeldItemsInPyramidBag
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidLobby_EventScript_HeldItemsStoredInPyramidBag
	message BattleFrontier_BattlePyramidLobby_Text_BagCannotHoldPickItemsToKeep
	waitmessage
	goto BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep
	end

BattleFrontier_BattlePyramidLobby_EventScript_HeldItemsStoredInPyramidBag::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HeldItemsMovedToBag, MSGBOX_DEFAULT
	return

@ When exiting Battle Pyramid with a full pyramid bag and held items the player must select to keep/toss party held items and make room for any kept items by tossing from the pyramid bag
BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep::
	multichoice 17, 6, MULTI_FRONTIER_ITEM_CHOOSE, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_PickItemsFromBag
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_PickItemsFromParty
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_ExitPickItems
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_ExitPickItems
	end

BattleFrontier_BattlePyramidLobby_EventScript_PickItemsFromBag::
	special ChooseItemsToTossFromPyramidBag
	message BattleFrontier_BattlePyramidLobby_Text_PickItemsToKeep
	waitmessage
	goto BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep
	end

BattleFrontier_BattlePyramidLobby_EventScript_PickItemsFromParty::
	special BattlePyramidChooseMonHeldItems
	message BattleFrontier_BattlePyramidLobby_Text_PickItemsToKeep
	waitmessage
	goto BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep
	end

BattleFrontier_BattlePyramidLobby_EventScript_ExitPickItems::
	special DoBattlePyramidMonsHaveHeldItem
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePyramidLobby_EventScript_PartyStillHasHeldItems
	return

BattleFrontier_BattlePyramidLobby_EventScript_PartyStillHasHeldItems::
	msgbox BattleFrontier_BattlePyramidLobby_Text_LeastOneMonHoldingItem, MSGBOX_DEFAULT
	message BattleFrontier_BattlePyramidLobby_Text_PickItemsToKeep
	waitmessage
	goto BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep
	end

BattleFrontier_BattlePyramidLobby_EventScript_Woman::
	msgbox BattleFrontier_BattlePyramidLobby_Text_TrainersNoticeRunning, MSGBOX_NPC
	end

BattleFrontier_BattlePyramidLobby_EventScript_FatMan::
	msgbox BattleFrontier_BattlePyramidLobby_Text_LostLotOfItems, MSGBOX_NPC
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesBoard::
	lockall
	msgbox BattleFrontier_BattlePyramidLobby_Text_RulesAreListed, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard::
	message BattleFrontier_BattlePyramidLobby_Text_ReadWhichHeading
	waitmessage
	multichoice 15, 2, MULTI_BATTLE_PYRAMID_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_RulesPokemon
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_RulesTrainers
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_RulesMaze
	case 3, BattleFrontier_BattlePyramidLobby_EventScript_RulesBag
	case 4, BattleFrontier_BattlePyramidLobby_EventScript_ExitRules
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_ExitRules
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesPokemon::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainMonRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesTrainers::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainTrainerRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesMaze::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainMazeRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesBag::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainBagRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePyramidLobby_EventScript_ExitRules::
	releaseall
	end

BattleFrontier_BattlePyramidLobby_Text_WelcomeToBattlePyramid:
	.string "Nơi lòng can đảm của các HLV được\n"
	.string "thử thách!\p"
	.string "Chào mừng đến với BATTLE PYRAMID!\p"
	.string "Tôi sẽ hướng dẫn bạn trong hành trình\n"
	.string "Battle Quest.$"

BattleFrontier_BattlePyramidLobby_Text_EmbarkOnChallenge:
	.string "Bạn có đủ dũng khí để bước vào thử\n"
	.string "thách Battle Quest không?$"

BattleFrontier_BattlePyramidLobby_Text_AwaitFutureChallenge:
	.string "Chúng tôi mong chờ thử thách của bạn\n"
	.string "trong tương lai!$"

BattleFrontier_BattlePyramidLobby_Text_ExplainBattlePyramid:
	.string "Battle Quest là một sự kiện thi đấu, nơi\n"
	.string "bạn phải khám phá PYRAMID và cố gắng\l"
	.string "lên đến đỉnh.\p"
	.string "PYRAMID có bảy tầng mê cung, không chỉ\n"
	.string "đầy những HLV tài giỏi mà còn có cả\l"
	.string "POKéMON hoang dã.\p"
	.string "Bạn phải tham gia cùng ba POKéMON và\n"
	.string "không con nào được mang vật phẩm.\p"
	.string "Trong lúc leo lên, bạn sẽ được cấp một\n"
	.string "TÚI CHIẾN ĐẤU để đựng vật phẩm.\p"
	.string "Nếu thất bại trong thử thách, toàn bộ\n"
	.string "vật phẩm trong TÚI CHIẾN ĐẤU sẽ mất.\p"
	.string "Nếu muốn tạm dừng thử thách, bạn phải\n"
	.string "chọn REST và lưu trò chơi.\p"
	.string "Nếu không lưu trước khi tạm dừng, bạn\n"
	.string "sẽ bị loại.$"

BattleFrontier_BattlePyramidLobby_Text_WhichLevelMode:
	.string "PYRAMID có hai thể thức, Level 50 và\n"
	.string "Open Level. Bạn sẽ chọn thể thức nào?$"

BattleFrontier_BattlePyramidLobby_Text_SelectThreeMons:
	.string "Rất tốt. Giờ xin hãy chọn ba POKéMON mà\n"
	.string "bạn muốn đồng hành cùng mình.$"

BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsLvOpen:
	.string "Có một vấn đề nhỏ, nhà thám hiểm!\p"
	.string "Có vẻ bạn chưa có đủ ba POKéMON đáp\n"
	.string "ứng điều kiện thử thách.\p"
	.string "Xin nhớ lấy hết vật phẩm khỏi POKéMON\n"
	.string "của bạn.\p"
	.string "EGGS{STR_VAR_1} không đủ điều\n"
	.string "kiện.\p"
	.string "Khi đã sẵn sàng, xin hãy nói chuyện với\n"
	.string "tôi.$"

BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsLv50:
	.string "Có một vấn đề nhỏ, nhà thám hiểm!\p"
	.string "Có vẻ bạn chưa có đủ ba POKéMON đáp\n"
	.string "ứng điều kiện thử thách.\p"
	.string "Ba POKéMON phải khác nhau và mỗi con\n"
	.string "không được vượt quá Level 50.\p"
	.string "Xin nhớ lấy hết vật phẩm khỏi POKéMON\n"
	.string "của bạn.\p"
	.string "EGGS{STR_VAR_1} không đủ điều\n"
	.string "kiện.\p"
	.string "Khi đã sẵn sàng, xin hãy nói chuyện với\n"
	.string "tôi.$"

BattleFrontier_BattlePyramidLobby_Text_OkayToSaveBeforeChallenge:
	.string "Trước khi bạn vào BATTLE PYRAMID, trò\n"
	.string "chơi phải được lưu. Bạn đồng ý chứ?$"

BattleFrontier_BattlePyramidLobby_Text_ShowYouIntoPyramid:
	.string "Rất tốt. Giờ tôi sẽ đưa bạn vào BATTLE\n"
	.string "PYRAMID.$"

BattleFrontier_BattlePyramidLobby_Text_WeWillHoldBagForSafekeeping:
	.string "Chúng tôi sẽ giữ TÚI ĐỒ của bạn an toàn\n"
	.string "trong lúc bạn thám hiểm, {PLAYER}.$"

BattleFrontier_BattlePyramidLobby_Text_PleaseTakePreviousBattleBag:
	.string "Đổi lại, hãy nhận TÚI CHIẾN ĐẤU\n"
	.string "đã dùng lần trước.$"

BattleFrontier_BattlePyramidLobby_Text_PleaseTakeThisBattleBag:
	.string "Đổi lại, hãy nhận TÚI CHIẾN ĐẤU này.$"

BattleFrontier_BattlePyramidLobby_Text_ExchangedBagForBattleBag:
	.string "{PLAYER} đã đổi TÚI ĐỒ để nhận\n"
	.string "TÚI CHIẾN ĐẤU.$"

BattleFrontier_BattlePyramidLobby_Text_StepOnFloorPanel:
	.string "Khi bước lên tấm sàn này, bạn sẽ được\n"
	.string "đưa tới một tầng cao hơn trong\l"
	.string "PYRAMID.\p"
	.string "Mong rằng hành trình của bạn sẽ diễn ra\n"
	.string "an toàn!$"

BattleFrontier_BattlePyramidLobby_Text_DidntSaveBeforeQuittingTakeBag:
	.string "Có một vấn đề nghiêm trọng, nhà thám\n"
	.string "hiểm!\p"
	.string "Lần trước, bạn đã không lưu trò chơi\n"
	.string "trước khi kết thúc thử thách.\p"
	.string "Vì vậy, rất tiếc phải nói rằng thử thách\n"
	.string "của bạn đã bị loại.\p"
	.string "Đây là TÚI ĐỒ chúng tôi đã giữ giúp\n"
	.string "bạn.\p"
	.string "{PLAYER} đã nhận lại TÚI ĐỒ.$"

BattleFrontier_BattlePyramidLobby_Text_YouveConqueredPyramid:
	.string "Thật tuyệt khi thấy bạn trở lại!\p"
	.string "Bạn đã chinh phục PYRAMID! Thật xuất\n"
	.string "sắc!$"

BattleFrontier_BattlePyramidLobby_Text_MonHoldingItemCannotTake:
	.string "À, có một vấn đề nhỏ.\p"
	.string "Ít nhất một POKéMON đang mang vật\n"
	.string "phẩm.\p"
	.string "Rất tiếc, vật phẩm lấy được trong\n"
	.string "PYRAMID không thể mang ra ngoài.$"

BattleFrontier_BattlePyramidLobby_Text_HeldItemsMovedToBag:
	.string "Mọi vật phẩm POKéMON của bạn đang mang\n"
	.string "sẽ được chuyển vào TÚI CHIẾN ĐẤU,\l"
	.string "{PLAYER}.$"

BattleFrontier_BattlePyramidLobby_Text_BagCannotHoldPickItemsToKeep:
	.string "Rất tiếc, TÚI CHIẾN ĐẤU không thể chứa\n"
	.string "hết vật phẩm của bạn.\p"
	.string "Hãy chọn vật phẩm muốn giữ lại hoặc\n"
	.string "cho POKéMON mang theo.$"

BattleFrontier_BattlePyramidLobby_Text_LeastOneMonHoldingItem:
	.string "Ít nhất một POKéMON vẫn đang mang vật\n"
	.string "phẩm.$"

BattleFrontier_BattlePyramidLobby_Text_PickItemsToKeep:
	.string "Hãy chọn vật phẩm muốn giữ lại hoặc\n"
	.string "cho POKéMON mang theo.$"

@ Unused
BattleFrontier_BattlePyramidLobby_Text_ReturnedEverythingMonsHeld:
	.string "{PLAYER} đã trả lại tất cả vật phẩm mà\n"
	.string "POKéMON đang mang.$"

BattleFrontier_BattlePyramidLobby_Text_UsedBattleBagWillBeKept:
	.string "TÚI CHIẾN ĐẤU bạn đã dùng sẽ được giữ\n"
	.string "sẵn cho thử thách tiếp theo.\p"
	.string "{PLAYER} đã giao lại TÚI CHIẾN ĐẤU để\n"
	.string "nhận lại TÚI ĐỒ.$"

BattleFrontier_BattlePyramidLobby_Text_RecordResultsWait:
	.string "Tôi phải ghi lại kết quả của bạn. Xin hãy\n"
	.string "chờ.$"

@ Unused
BattleFrontier_BattlePyramidLobby_Text_ForConqueringPyramidTakeThis:
	.string "Xin hãy nhận món này làm kỷ niệm vì đã\n"
	.string "chinh phục BATTLE PYRAMID.$"

@ Unused
BattleFrontier_BattlePyramidLobby_Text_ReceivedPrizeItem:
	.string "{PLAYER} đã nhận phần thưởng\n"
	.string "{STR_VAR_1}.$"

@ Unused
BattleFrontier_BattlePyramidLobby_Text_BagIsFull:
	.string "...À... TÚI ĐỒ của bạn hình như đã đầy.\p"
	.string "Xin hãy quay lại sau khi sắp xếp đồ\n"
	.string "trong TÚI ĐỒ.$"

BattleFrontier_BattlePyramidLobby_Text_DisappointingHereIsBag:
	.string "Thật đáng tiếc cho bạn...\p"
	.string "Đây là TÚI ĐỒ chúng tôi đã giữ giúp\n"
	.string "bạn.\p"
	.string "{PLAYER} đã nhận lại TÚI ĐỒ.$"

BattleFrontier_BattlePyramidLobby_Text_LookForwardToNextChallenge:
	.string "Chúng tôi mong chờ thử thách tiếp theo\n"
	.string "của bạn!$"

@ Unused
BattleFrontier_BattlePyramidLobby_Text_HereIsPrize:
	.string "Chúng tôi đã mong chờ bạn đến!\p"
	.string "Đây là phần thưởng vì bạn đã chinh\n"
	.string "phục PYRAMID.$"

BattleFrontier_BattlePyramidLobby_Text_TellYouWhatMisfortunesAwait:
	.string "Chào mừng...\p"
	.string "Tôi rất sẵn lòng cho bạn biết những tai\n"
	.string "họa nào đang chờ đợi trong PYRAMID...$"

BattleFrontier_BattlePyramidLobby_Text_Aah:
	.string "... ... ... ... ... ... ... ... ... ... ... ...\p"
	.string "... ... ... ... ... ... Á!$"

BattleFrontier_BattlePyramidLobby_Text_HintParalysis:
	.string "Tôi thấy một trận mưa tia lửa...\p"
	.string "...Và trong đó, tôi thấy POKéMON của bạn\n"
	.string "đang chật vật vì tê liệt...$"

BattleFrontier_BattlePyramidLobby_Text_HintPoison:
	.string "Tôi thấy độc tố...\p"
	.string "...Và tôi thấy POKéMON của bạn đang chịu\n"
	.string "tác động của độc...$"

BattleFrontier_BattlePyramidLobby_Text_HintBurn:
	.string "Tôi thấy những ngọn lửa đỏ rực...\p"
	.string "...Và tôi thấy POKéMON của bạn đang chịu\n"
	.string "đau đớn vì bỏng...$"

BattleFrontier_BattlePyramidLobby_Text_HintPPWaste:
	.string "Tôi cảm nhận áp lực khủng khiếp từ một\n"
	.string "nỗi oán giận không được hồi đáp...\p"
	.string "Đó là một lời nguyền...\p"
	.string "...Và tôi thấy POKéMON của bạn cạn sạch\n"
	.string "Power Points, chẳng còn cách nào khác\l"
	.string "ngoài dùng STRUGGLE...$"

BattleFrontier_BattlePyramidLobby_Text_HintLevitate:
	.string "Tôi thấy những POKéMON lơ lửng kiêu\n"
	.string "hãnh trên không...\p"
	.string "...Và tôi thấy POKéMON của bạn bất lực\n"
	.string "vì các chiêu hệ GROUND không có tác\l"
	.string "dụng...$"

BattleFrontier_BattlePyramidLobby_Text_HintTrapAbility:
	.string "Tôi cảm nhận một luồng năng lượng dữ\n"
	.string "dội dâng lên từ lòng đất...\p"
	.string "...Và tôi thấy POKéMON của bạn không thể\n"
	.string "thoát khỏi gọng kìm của sức mạnh ấy...$"

BattleFrontier_BattlePyramidLobby_Text_HintIce:
	.string "Tôi thấy POKéMON hệ ICE...\p"
	.string "...Và tôi thấy POKéMON của bạn đang\n"
	.string "chật vật chống lại sự đóng băng do\l"
	.string "băng gây ra...$"

BattleFrontier_BattlePyramidLobby_Text_HintExplosion:
	.string "Tôi thấy hàng loạt chiêu thức gây nguy\n"
	.string "hiểm cho chính người sử dụng...\p"
	.string "...Và tôi thấy POKéMON của bạn gục ngã\n"
	.string "trước chúng...$"

BattleFrontier_BattlePyramidLobby_Text_HintPsychic:
	.string "Tôi thấy POKéMON hệ PSYCHIC...\p"
	.string "...Và tôi thấy POKéMON của bạn bị các\n"
	.string "chiêu PSYCHIC hành hạ...$"

BattleFrontier_BattlePyramidLobby_Text_HintRock:
	.string "Tôi thấy POKéMON hệ ROCK...\p"
	.string "...Và tôi thấy POKéMON của bạn chịu đau\n"
	.string "đớn vì các chiêu ROCK...$"

BattleFrontier_BattlePyramidLobby_Text_HintFighting:
	.string "Tôi thấy POKéMON hệ FIGHTING...\p"
	.string "...Và tôi thấy POKéMON của bạn bị các\n"
	.string "chiêu FIGHTING đánh tơi tả...$"

BattleFrontier_BattlePyramidLobby_Text_HintWeather:
	.string "RAIN DANCE... SUNNY DAY... SANDSTORM...\n"
	.string "HAIL...\p"
	.string "Tôi thấy những POKéMON trở nên mạnh\n"
	.string "hơn nhờ thời tiết...\p"
	.string "...Và tôi thấy POKéMON của bạn bối rối\n"
	.string "trước nhiều loại chiêu thức khác\l"
	.string "nhau...$"

BattleFrontier_BattlePyramidLobby_Text_HintBug:
	.string "Tôi thấy POKéMON hệ BUG...\p"
	.string "...Và tôi thấy POKéMON của bạn chịu đau\n"
	.string "đớn vì nhiều kiểu tấn công khác nhau...$"

BattleFrontier_BattlePyramidLobby_Text_HintDark:
	.string "Tôi thấy POKéMON hệ DARK...\p"
	.string "...Và tôi thấy POKéMON của bạn chịu đau\n"
	.string "đớn vì các chiêu hệ DARK...$"

BattleFrontier_BattlePyramidLobby_Text_HintWater:
	.string "Tôi thấy POKéMON hệ WATER...\p"
	.string "...Và tôi thấy POKéMON của bạn chịu đau\n"
	.string "đớn vì các chiêu hệ WATER...$"

BattleFrontier_BattlePyramidLobby_Text_HintGhost:
	.string "Tôi thấy POKéMON hệ GHOST...\p"
	.string "...Và tôi thấy POKéMON của bạn chịu đau\n"
	.string "đớn vì các chiêu hệ GHOST...$"

BattleFrontier_BattlePyramidLobby_Text_HintSteel:
	.string "Tôi thấy POKéMON hệ STEEL...\p"
	.string "...Và tôi thấy POKéMON của bạn chịu đau\n"
	.string "đớn vì những chiêu thức mạnh khủng\l"
	.string "khiếp...$"

BattleFrontier_BattlePyramidLobby_Text_HintFlyingDragon:
	.string "Tôi thấy những POKéMON biết bay...\p"
	.string "...Và tôi thấy POKéMON của bạn chịu đau\n"
	.string "đớn vì những chiêu thức mạnh khủng\l"
	.string "khiếp...$"

BattleFrontier_BattlePyramidLobby_Text_HintStoneEvolve:
	.string "Tôi thấy những POKéMON đã tiến hóa nhờ\n"
	.string "sức mạnh của đá...\p"
	.string "Tôi còn cảm nhận được lửa, nước và\n"
	.string "điện...\p"
	.string "...Và tôi thấy POKéMON của bạn chịu đau\n"
	.string "đớn vì ba nguồn sức mạnh ấy...$"

BattleFrontier_BattlePyramidLobby_Text_HintNormal:
	.string "Tôi thấy POKéMON hệ NORMAL...\p"
	.string "...Và tôi thấy POKéMON của bạn chịu đau\n"
	.string "đớn vì những chiêu thức mạnh khủng\l"
	.string "khiếp...$"

BattleFrontier_BattlePyramidLobby_Text_BelieveMyFortunesOrNot:
	.string "Tin hay không tin lời tiên đoán của tôi\n"
	.string "là tùy bạn...\p"
	.string "Tương lai có thể thay đổi bất cứ lúc\n"
	.string "nào... Chúc bạn lên đường bình an...$"

BattleFrontier_BattlePyramidLobby_Text_TrainersNoticeRunning:
	.string "Bạn có biết không?\p"
	.string "Nếu chạy nhanh, bạn có thể bị HLV\n"
	.string "phát hiện và đuổi theo để giao đấu.\p"
	.string "Vì vậy, nếu muốn tránh HLV, đừng\n"
	.string "để họ nhìn thấy bạn, hãy thận trọng lén\l"
	.string "đi qua thật nhẹ nhàng và im lặng.$"

BattleFrontier_BattlePyramidLobby_Text_LostLotOfItems:
	.string "Aaaaaaaa!\p"
	.string "Tôi từng có cả đống vật phẩm, nhưng khi\n"
	.string "thua thì mất sạch rồi!\p"
	.string "Aaaaaaaa!$"

BattleFrontier_BattlePyramidLobby_Text_YouveDefeatedPyramidKing:
	.string "Chào mừng trở lại! Bạn đã làm được\n"
	.string "điều không tưởng!\p"
	.string "Bạn đã đánh bại PYRAMID KING và chinh\n"
	.string "phục BATTLE PYRAMID!$"

BattleFrontier_BattlePyramidLobby_Text_GiveYouTheseBattlePoints:
	.string "Nhà thám hiểm trẻ tuổi! Để tuyên dương\n"
	.string "lòng can đảm của bạn, chúng tôi xin trao\l"
	.string "số Battle Point(s) này!$"

BattleFrontier_BattlePyramidLobby_Text_RulesAreListed:
	.string "Nội quy Battle Quest được ghi ở đây.$"

BattleFrontier_BattlePyramidLobby_Text_ReadWhichHeading:
	.string "Bạn muốn đọc mục nào?$"

BattleFrontier_BattlePyramidLobby_Text_ExplainMonRules:
	.string "Mỗi khi PYRAMID được chinh phục, các\n"
	.string "POKéMON hoang dã xuất hiện bên trong\l"
	.string "sẽ được thay bằng những loài khác.\p"
	.string "Hãy khám phá, quan sát và tìm hiểu xem\n"
	.string "bạn có thể gặp những loài POKéMON\l"
	.string "hoang dã nào.$"

BattleFrontier_BattlePyramidLobby_Text_ExplainTrainerRules:
	.string "Các HLV đang mai phục bạn bên\n"
	.string "trong PYRAMID.\p"
	.string "Mỗi tầng có tối đa tám HLV.\p"
	.string "Khi đánh bại một HLV, bạn sẽ nhận\n"
	.string "được một gợi ý hữu ích cho hành trình.$"

BattleFrontier_BattlePyramidLobby_Text_ExplainMazeRules:
	.string "Các mê cung trong PYRAMID sẽ tự sắp\n"
	.string "xếp lại mỗi khi bạn tiến vào.\p"
	.string "Mê cung rất tối. Bạn phải thận trọng\n"
	.string "tiến bước.\p"
	.string "Ánh sáng sẽ rực hơn mỗi khi bạn đánh\n"
	.string "bại một POKéMON hoang dã hoặc một\l"
	.string "HLV.$"

BattleFrontier_BattlePyramidLobby_Text_ExplainBagRules:
	.string "Trong PYRAMID, TÚI CHIẾN ĐẤU sẽ\n"
	.string "thay cho TÚI ĐỒ của bạn.\p"
	.string "Có hai TÚI CHIẾN ĐẤU riêng biệt, một\n"
	.string "cho hành trình Level 50 và một dành cho\l"
	.string "Open Level.\p"
	.string "Mỗi chiếc có thể chứa 10 loại vật phẩm,\n"
	.string "mỗi loại tối đa 99 món.\p"
	.string "Nếu bạn thất bại, toàn bộ vật phẩm\n"
	.string "trong TÚI CHIẾN ĐẤU sẽ biến mất.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global BattleFrontier_BattlePyramidLobby_Text_WelcomeToBattlePyramid
	.global BattleFrontier_BattlePyramidLobby_Text_EmbarkOnChallenge
	.global BattleFrontier_BattlePyramidLobby_Text_AwaitFutureChallenge
	.global BattleFrontier_BattlePyramidLobby_Text_ExplainBattlePyramid
	.global BattleFrontier_BattlePyramidLobby_Text_WhichLevelMode
	.global BattleFrontier_BattlePyramidLobby_Text_SelectThreeMons
	.global BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsLvOpen
	.global BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsLv50
	.global BattleFrontier_BattlePyramidLobby_Text_OkayToSaveBeforeChallenge
	.global BattleFrontier_BattlePyramidLobby_Text_ShowYouIntoPyramid
	.global BattleFrontier_BattlePyramidLobby_Text_WeWillHoldBagForSafekeeping
	.global BattleFrontier_BattlePyramidLobby_Text_PleaseTakePreviousBattleBag
	.global BattleFrontier_BattlePyramidLobby_Text_PleaseTakeThisBattleBag
	.global BattleFrontier_BattlePyramidLobby_Text_ExchangedBagForBattleBag
	.global BattleFrontier_BattlePyramidLobby_Text_StepOnFloorPanel
	.global BattleFrontier_BattlePyramidLobby_Text_DidntSaveBeforeQuittingTakeBag
	.global BattleFrontier_BattlePyramidLobby_Text_YouveConqueredPyramid
	.global BattleFrontier_BattlePyramidLobby_Text_MonHoldingItemCannotTake
	.global BattleFrontier_BattlePyramidLobby_Text_HeldItemsMovedToBag
	.global BattleFrontier_BattlePyramidLobby_Text_BagCannotHoldPickItemsToKeep
	.global BattleFrontier_BattlePyramidLobby_Text_LeastOneMonHoldingItem
	.global BattleFrontier_BattlePyramidLobby_Text_PickItemsToKeep
	.global BattleFrontier_BattlePyramidLobby_Text_ReturnedEverythingMonsHeld
	.global BattleFrontier_BattlePyramidLobby_Text_UsedBattleBagWillBeKept
	.global BattleFrontier_BattlePyramidLobby_Text_RecordResultsWait
	.global BattleFrontier_BattlePyramidLobby_Text_ForConqueringPyramidTakeThis
	.global BattleFrontier_BattlePyramidLobby_Text_ReceivedPrizeItem
	.global BattleFrontier_BattlePyramidLobby_Text_BagIsFull
	.global BattleFrontier_BattlePyramidLobby_Text_DisappointingHereIsBag
	.global BattleFrontier_BattlePyramidLobby_Text_LookForwardToNextChallenge
	.global BattleFrontier_BattlePyramidLobby_Text_HereIsPrize
	.global BattleFrontier_BattlePyramidLobby_Text_TellYouWhatMisfortunesAwait
	.global BattleFrontier_BattlePyramidLobby_Text_Aah
	.global BattleFrontier_BattlePyramidLobby_Text_HintParalysis
	.global BattleFrontier_BattlePyramidLobby_Text_HintPoison
	.global BattleFrontier_BattlePyramidLobby_Text_HintBurn
	.global BattleFrontier_BattlePyramidLobby_Text_HintPPWaste
	.global BattleFrontier_BattlePyramidLobby_Text_HintLevitate
	.global BattleFrontier_BattlePyramidLobby_Text_HintTrapAbility
	.global BattleFrontier_BattlePyramidLobby_Text_HintIce
	.global BattleFrontier_BattlePyramidLobby_Text_HintExplosion
	.global BattleFrontier_BattlePyramidLobby_Text_HintPsychic
	.global BattleFrontier_BattlePyramidLobby_Text_HintRock
	.global BattleFrontier_BattlePyramidLobby_Text_HintFighting
	.global BattleFrontier_BattlePyramidLobby_Text_HintWeather
	.global BattleFrontier_BattlePyramidLobby_Text_HintBug
	.global BattleFrontier_BattlePyramidLobby_Text_HintDark
	.global BattleFrontier_BattlePyramidLobby_Text_HintWater
	.global BattleFrontier_BattlePyramidLobby_Text_HintGhost
	.global BattleFrontier_BattlePyramidLobby_Text_HintSteel
	.global BattleFrontier_BattlePyramidLobby_Text_HintFlyingDragon
	.global BattleFrontier_BattlePyramidLobby_Text_HintStoneEvolve
	.global BattleFrontier_BattlePyramidLobby_Text_HintNormal
	.global BattleFrontier_BattlePyramidLobby_Text_BelieveMyFortunesOrNot
	.global BattleFrontier_BattlePyramidLobby_Text_TrainersNoticeRunning
	.global BattleFrontier_BattlePyramidLobby_Text_LostLotOfItems
	.global BattleFrontier_BattlePyramidLobby_Text_YouveDefeatedPyramidKing
	.global BattleFrontier_BattlePyramidLobby_Text_GiveYouTheseBattlePoints
	.global BattleFrontier_BattlePyramidLobby_Text_RulesAreListed
	.global BattleFrontier_BattlePyramidLobby_Text_ReadWhichHeading
	.global BattleFrontier_BattlePyramidLobby_Text_ExplainMonRules
	.global BattleFrontier_BattlePyramidLobby_Text_ExplainTrainerRules
	.global BattleFrontier_BattlePyramidLobby_Text_ExplainMazeRules
	.global BattleFrontier_BattlePyramidLobby_Text_ExplainBagRules
@ END GENERATED LOCALIZATION EXPORTS
