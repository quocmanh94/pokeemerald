Route110_TrickHouseEntrance_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_TrickHouseEntrance_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route110_TrickHouseEntrance_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route110_TrickHouseEntrance_OnWarp
	.byte 0

	@ State descriptions for VAR_TRICK_HOUSE_ENTRANCE_STATE
	@ 0: Trick Master is hiding
	@ 1: Trick Master has left at start of challenge
	@ 2: Trick Master ready to give normal reward from previous challenge (if bag was full)
	@ 3: Trick Master still making next puzzle
	@ 4: Finished final puzzle
	@ 5: Completed previous challenge
	@ 6: 'Trick Master' mechadoll ready to give Tent reward from final challenge (if bag was full)

Route110_TrickHouseEntrance_OnTransition:
	setflag FLAG_LANDMARK_TRICK_HOUSE
	goto_if_eq VAR_TRICK_HOUSE_ENTER_FROM_CORRIDOR, 1, Route110_TrickHouseEntrance_EventScript_EnterFromCorridor
	goto_if_eq VAR_TRICK_HOUSE_PRIZE_PICKUP, 1, Route110_TrickHouseEntrance_EventScript_SetReadyToGiveReward
	goto_if_eq VAR_TRICK_HOUSE_FOUND_TRICK_MASTER, 1, Route110_TrickHouseEntrance_EventScript_MoveTrickMasterToDoor
	call_if_eq VAR_TRICK_HOUSE_ENTRANCE_STATE, 5, Route110_TrickHouseEntrance_EventScript_CheckReadyForNextPuzzle
	call_if_eq VAR_TRICK_HOUSE_ENTRANCE_STATE, 3, Route110_TrickHouseEntrance_EventScript_CheckReadyForNextPuzzle
	call_if_eq VAR_TRICK_HOUSE_ENTRANCE_STATE, 0, Route110_TrickHouseEntrance_EventScript_CheckReadyForNextPuzzle
	switch VAR_TRICK_HOUSE_ENTRANCE_STATE
	case 0, Route110_TrickHouseEntrance_EventScript_ReadyBeingWatchedTrigger
	case 1, Route110_TrickHouseEntrance_EventScript_SetNotBeingWatched1
	case 3, Route110_TrickHouseEntrance_EventScript_SetNotBeingWatched2
	case 4, Route110_TrickHouseEntrance_EventScript_SetNotBeingWatched3
	end

Route110_TrickHouseEntrance_EventScript_SetReadyToGiveReward::
	setvar VAR_TRICK_HOUSE_BEING_WATCHED_STATE, 1
	goto_if_eq VAR_TRICK_HOUSE_LEVEL, 8, Route110_TrickHouseEntrance_EventScript_ReadyToGiveTentReward
	setvar VAR_TRICK_HOUSE_ENTRANCE_STATE, 2
	end

Route110_TrickHouseEntrance_EventScript_ReadyToGiveTentReward::
	setvar VAR_TRICK_HOUSE_ENTRANCE_STATE, 6
	end

Route110_TrickHouseEntrance_EventScript_EnterFromCorridor::
	setvar VAR_TRICK_HOUSE_ENTER_FROM_CORRIDOR, 0
	setvar VAR_TRICK_HOUSE_ENTRANCE_STATE, 5
	setvar VAR_TRICK_HOUSE_BEING_WATCHED_STATE, 1
	end

Route110_TrickHouseEntrance_EventScript_CheckReadyForNextPuzzle::
	setvar VAR_TRICK_HOUSE_ENTRANCE_STATE, 0
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 1, Route110_TrickHouseEntrance_EventScript_CheckReadyForPuzzle2
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 2, Route110_TrickHouseEntrance_EventScript_CheckReadyForPuzzle3
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 3, Route110_TrickHouseEntrance_EventScript_CheckReadyForPuzzle4
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 4, Route110_TrickHouseEntrance_EventScript_CheckReadyForPuzzle5
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 5, Route110_TrickHouseEntrance_EventScript_CheckReadyForPuzzle6
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 6, Route110_TrickHouseEntrance_EventScript_CheckReadyForPuzzle7
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 7, Route110_TrickHouseEntrance_EventScript_CheckReadyForPuzzle8
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 8, Route110_TrickHouseEntrance_EventScript_FinishedPuzzles
	return

Route110_TrickHouseEntrance_EventScript_CheckReadyForPuzzle2::
	call_if_unset FLAG_BADGE03_GET, Route110_TrickHouseEntrance_EventScript_NotReadyForPuzzle
	return

Route110_TrickHouseEntrance_EventScript_CheckReadyForPuzzle3::
	call_if_unset FLAG_BADGE04_GET, Route110_TrickHouseEntrance_EventScript_NotReadyForPuzzle
	return

Route110_TrickHouseEntrance_EventScript_CheckReadyForPuzzle4::
	call_if_unset FLAG_BADGE05_GET, Route110_TrickHouseEntrance_EventScript_NotReadyForPuzzle
	return

Route110_TrickHouseEntrance_EventScript_CheckReadyForPuzzle5::
	call_if_unset FLAG_BADGE06_GET, Route110_TrickHouseEntrance_EventScript_NotReadyForPuzzle
	return

Route110_TrickHouseEntrance_EventScript_CheckReadyForPuzzle6::
	call_if_unset FLAG_BADGE07_GET, Route110_TrickHouseEntrance_EventScript_NotReadyForPuzzle
	return

Route110_TrickHouseEntrance_EventScript_CheckReadyForPuzzle7::
	call_if_unset FLAG_BADGE08_GET, Route110_TrickHouseEntrance_EventScript_NotReadyForPuzzle
	return

Route110_TrickHouseEntrance_EventScript_CheckReadyForPuzzle8::
	call_if_unset FLAG_SYS_GAME_CLEAR, Route110_TrickHouseEntrance_EventScript_NotReadyForPuzzle
	return

Route110_TrickHouseEntrance_EventScript_FinishedPuzzles::
	setvar VAR_TRICK_HOUSE_ENTRANCE_STATE, 4
	return

Route110_TrickHouseEntrance_EventScript_NotReadyForPuzzle::
	setvar VAR_TRICK_HOUSE_ENTRANCE_STATE, 3
	return

Route110_TrickHouseEntrance_EventScript_MoveTrickMasterToDoor::
	setobjectxyperm LOCALID_TRICK_MASTER, 5, 2
	end

Route110_TrickHouseEntrance_EventScript_ReadyBeingWatchedTrigger::
	setvar VAR_TRICK_HOUSE_BEING_WATCHED_STATE, 0
	end

Route110_TrickHouseEntrance_EventScript_SetNotBeingWatched1::
	setvar VAR_TRICK_HOUSE_BEING_WATCHED_STATE, 1
	end

Route110_TrickHouseEntrance_EventScript_SetNotBeingWatched2::
	setvar VAR_TRICK_HOUSE_BEING_WATCHED_STATE, 1
	end

Route110_TrickHouseEntrance_EventScript_SetNotBeingWatched3::
	setvar VAR_TRICK_HOUSE_BEING_WATCHED_STATE, 1
	end

Route110_TrickHouseEntrance_OnWarp:
	map_script_2 VAR_TRICK_HOUSE_FOUND_TRICK_MASTER, 1, Route110_TrickHouseEntrance_EventScript_TrickMasterFound
	map_script_2 VAR_TRICK_HOUSE_ENTRANCE_STATE, 0, Route110_TrickHouseEntrance_EventScript_SetTrickMasterHidingSpot
	map_script_2 VAR_TRICK_HOUSE_ENTRANCE_STATE, 1, Route110_TrickHouseEntrance_EventScript_RemoveTrickMaster
	map_script_2 VAR_TRICK_HOUSE_ENTRANCE_STATE, 2, Route110_TrickHouseEntrance_EventScript_SetTrickMasterFacingDoor
	map_script_2 VAR_TRICK_HOUSE_ENTRANCE_STATE, 3, Route110_TrickHouseEntrance_EventScript_SetTrickMasterFacingDoor
	map_script_2 VAR_TRICK_HOUSE_ENTRANCE_STATE, 4, Route110_TrickHouseEntrance_EventScript_RemoveTrickMaster
	map_script_2 VAR_TRICK_HOUSE_ENTRANCE_STATE, 5, Route110_TrickHouseEntrance_EventScript_RemoveTrickMaster
	map_script_2 VAR_TRICK_HOUSE_ENTRANCE_STATE, 6, Route110_TrickHouseEntrance_EventScript_SetTrickMasterInFrontOfDoor
	.2byte 0

Route110_TrickHouseEntrance_EventScript_TrickMasterFound::
	addobject LOCALID_TRICK_MASTER
	showobjectat LOCALID_TRICK_MASTER, MAP_ROUTE110_TRICK_HOUSE_ENTRANCE
	turnobject LOCALID_TRICK_MASTER, DIR_EAST
	turnobject LOCALID_PLAYER, DIR_WEST
	end

Route110_TrickHouseEntrance_EventScript_SetTrickMasterHidingSpot::
	addobject LOCALID_TRICK_MASTER
	hideobjectat LOCALID_TRICK_MASTER, MAP_ROUTE110_TRICK_HOUSE_ENTRANCE
	switch VAR_TRICK_HOUSE_LEVEL
	case 0, Route110_TrickHouseEntrance_EventScript_SetHidingSpotPuzzle1
	case 1, Route110_TrickHouseEntrance_EventScript_SetHidingSpotPuzzle2
	case 2, Route110_TrickHouseEntrance_EventScript_SetHidingSpotPuzzle3
	case 3, Route110_TrickHouseEntrance_EventScript_SetHidingSpotPuzzle4
	case 4, Route110_TrickHouseEntrance_EventScript_SetHidingSpotPuzzle5
	case 5, Route110_TrickHouseEntrance_EventScript_SetHidingSpotPuzzle6
	case 6, Route110_TrickHouseEntrance_EventScript_SetHidingSpotPuzzle7
	case 7, Route110_TrickHouseEntrance_EventScript_SetHidingSpotPuzzle8
	end

Route110_TrickHouseEntrance_EventScript_SetHidingSpotPuzzle1::
	setobjectxy LOCALID_TRICK_MASTER, 6, 3
	end

Route110_TrickHouseEntrance_EventScript_SetHidingSpotPuzzle2::
	setobjectxy LOCALID_TRICK_MASTER, 11, 5
	end

Route110_TrickHouseEntrance_EventScript_SetHidingSpotPuzzle3::
	setobjectxy LOCALID_TRICK_MASTER, 9, 1
	end

Route110_TrickHouseEntrance_EventScript_SetHidingSpotPuzzle4::
	setobjectxy LOCALID_TRICK_MASTER, 3, 1
	end

Route110_TrickHouseEntrance_EventScript_SetHidingSpotPuzzle5::
	setobjectxy LOCALID_TRICK_MASTER, 0, 5
	end

Route110_TrickHouseEntrance_EventScript_SetHidingSpotPuzzle6::
	setobjectxy LOCALID_TRICK_MASTER, 11, 1
	end

Route110_TrickHouseEntrance_EventScript_SetHidingSpotPuzzle7::
	setobjectxy LOCALID_TRICK_MASTER, 8, 1
	end

Route110_TrickHouseEntrance_EventScript_SetHidingSpotPuzzle8::
	setobjectxy LOCALID_TRICK_MASTER, 4, 4
	end

Route110_TrickHouseEntrance_EventScript_RemoveTrickMaster::
	removeobject LOCALID_TRICK_MASTER
	end

Route110_TrickHouseEntrance_EventScript_SetTrickMasterFacingDoor::
	addobject LOCALID_TRICK_MASTER
	setobjectxy LOCALID_TRICK_MASTER, 5, 2
	turnobject LOCALID_TRICK_MASTER, DIR_NORTH
	end

Route110_TrickHouseEntrance_EventScript_SetTrickMasterInFrontOfDoor::
	addobject LOCALID_TRICK_MASTER
	setobjectxy LOCALID_TRICK_MASTER, 5, 2
	turnobject LOCALID_TRICK_MASTER, DIR_SOUTH
	end

Route110_TrickHouseEntrance_OnFrame:
	map_script_2 VAR_TRICK_HOUSE_FOUND_TRICK_MASTER, 1, Route110_TrickHouseEntrance_EventScript_BeginChallenge
	.2byte 0

Route110_TrickHouseEntrance_EventScript_BeginChallenge::
	lockall
	delay 20
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 0, Route110_TrickHouseEntrance_EventScript_MeetTrickMaster
	msgbox Route110_TrickHouseEntrance_Text_ComeToChallengeTrickHouse, MSGBOX_DEFAULT
	closemessage
	delay 20
	applymovement LOCALID_TRICK_MASTER, Route110_TrickHouse_Movement_TrickMasterSpin
	waitmovement 0
	playse SE_M_EXPLOSION
	applymovement LOCALID_TRICK_MASTER, Route110_TrickHouse_Movement_TrickMasterJumpAway
	waitmovement 0
	removeobject LOCALID_TRICK_MASTER
	setvar VAR_TRICK_HOUSE_ENTRANCE_STATE, 1
	setvar VAR_TRICK_HOUSE_FOUND_TRICK_MASTER, 0
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_UnusedRelease::
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_TrickMaster::
	lockall
	switch VAR_TRICK_HOUSE_ENTRANCE_STATE
	case 0, Route110_TrickHouseEntrance_EventScript_FoundTrickMaster
	case 2, Route110_TrickHouseEntrance_EventScript_GiveReward
	case 3, Route110_TrickHouseEntrance_EventScript_StillMakingPuzzle
	case 6, Route110_TrickHouseEntrance_EventScript_MechadollReward
	end

Route110_TrickHouseEntrance_EventScript_FoundTrickMaster::
	playse SE_PIN
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 0, Route110_TrickHouseEntrance_EventScript_FoundBeneathDesk
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 1, Route110_TrickHouseEntrance_EventScript_FoundBehindTree
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 2, Route110_TrickHouseEntrance_EventScript_FoundInDresser
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 3, Route110_TrickHouseEntrance_EventScript_FoundBeyondWindow
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 4, Route110_TrickHouseEntrance_EventScript_FoundInPlanter
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 5, Route110_TrickHouseEntrance_EventScript_FoundInCupboard
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 6, Route110_TrickHouseEntrance_EventScript_FoundBehindWindow
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 7, Route110_TrickHouseEntrance_EventScript_FoundBeneathCushion
	closemessage
	setvar VAR_TRICK_HOUSE_FOUND_TRICK_MASTER, 1
	warpsilent MAP_ROUTE110_TRICK_HOUSE_ENTRANCE, 6, 2
	waitstate
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_FoundBeneathDesk::
	msgbox Route110_TrickHouseEntrance_Text_ConcealedBeneathDesk, MSGBOX_DEFAULT
	return

Route110_TrickHouseEntrance_EventScript_FoundBehindTree::
	msgbox Route110_TrickHouseEntrance_Text_ConcealedBehindTree, MSGBOX_DEFAULT
	return

Route110_TrickHouseEntrance_EventScript_FoundInDresser::
	msgbox Route110_TrickHouseEntrance_Text_ConcealedInDresser, MSGBOX_DEFAULT
	return

Route110_TrickHouseEntrance_EventScript_FoundBeyondWindow::
	msgbox Route110_TrickHouseEntrance_Text_ConealedBeyondWindow, MSGBOX_DEFAULT
	return

Route110_TrickHouseEntrance_EventScript_FoundInPlanter::
	msgbox Route110_TrickHouseEntrance_Text_ConcealedInPlanter, MSGBOX_DEFAULT
	return

Route110_TrickHouseEntrance_EventScript_FoundInCupboard::
	msgbox Route110_TrickHouseEntrance_Text_ConcealedInCupboard, MSGBOX_DEFAULT
	return

Route110_TrickHouseEntrance_EventScript_FoundBehindWindow::
	msgbox Route110_TrickHouseEntrance_Text_ConcealedBehindWindow, MSGBOX_DEFAULT
	return

Route110_TrickHouseEntrance_EventScript_FoundBeneathCushion::
	msgbox Route110_TrickHouseEntrance_Text_ConcealedBeneathCushion, MSGBOX_DEFAULT
	return

Route110_TrickHouse_Movement_TrickMasterSpin:
	face_up
	delay_4
	face_left
	delay_4
	face_down
	delay_4
	face_right
	delay_4
	step_end

Route110_TrickHouse_Movement_TrickMasterJumpAway:
	face_up
	disable_anim
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	step_end

Route110_TrickHouseEntrance_EventScript_MeetTrickMaster::
	msgbox Route110_TrickHouseEntrance_Text_TheyCallMeTrickMaster, MSGBOX_DEFAULT
	return

Route110_TrickHouseEntrance_EventScript_StillMakingPuzzle::
	msgbox Route110_TrickHouseEntrance_Text_NextTimeUseThisTrick, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_TRICK_MASTER, Common_Movement_FacePlayer
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_TRICK_MASTER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_TRICK_MASTER, Common_Movement_Delay48
	waitmovement 0
	msgbox Route110_TrickHouseEntrance_Text_InMidstOfDevisingNewChallenges, MSGBOX_DEFAULT
	applymovement LOCALID_TRICK_MASTER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_GiveReward::
	applymovement LOCALID_TRICK_MASTER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox Route110_TrickHouseEntrance_Text_YoureHereToAcceptReward, MSGBOX_DEFAULT
	goto_if_eq VAR_TRICK_HOUSE_LEVEL, 1, Route110_TrickHouseEntrance_EventScript_GivePuzzle1Reward
	goto_if_eq VAR_TRICK_HOUSE_LEVEL, 2, Route110_TrickHouseEntrance_EventScript_GivePuzzle2Reward
	goto_if_eq VAR_TRICK_HOUSE_LEVEL, 3, Route110_TrickHouseEntrance_EventScript_GivePuzzle3Reward
	goto_if_eq VAR_TRICK_HOUSE_LEVEL, 4, Route110_TrickHouseEntrance_EventScript_GivePuzzle4Reward
	goto_if_eq VAR_TRICK_HOUSE_LEVEL, 5, Route110_TrickHouseEntrance_EventScript_GivePuzzle5Reward
	goto_if_eq VAR_TRICK_HOUSE_LEVEL, 6, Route110_TrickHouseEntrance_EventScript_GivePuzzle6Reward
	goto_if_eq VAR_TRICK_HOUSE_LEVEL, 7, Route110_TrickHouseEntrance_EventScript_GivePuzzle7Reward
	end

Route110_TrickHouseEntrance_EventScript_GivePuzzle1Reward::
	giveitem ITEM_RARE_CANDY
	goto_if_eq VAR_RESULT, TRUE, Route110_TrickHouseEntrance_EventScript_GotReward
	call_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox Route110_TrickHouseEntrance_Text_DidYouNotComeToClaimReward, MSGBOX_DEFAULT
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_GivePuzzle2Reward::
	giveitem ITEM_TIMER_BALL
	goto_if_eq VAR_RESULT, TRUE, Route110_TrickHouseEntrance_EventScript_GotReward
	call_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox Route110_TrickHouseEntrance_Text_DidYouNotComeToClaimReward, MSGBOX_DEFAULT
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_GivePuzzle3Reward::
	giveitem ITEM_HARD_STONE
	goto_if_eq VAR_RESULT, TRUE, Route110_TrickHouseEntrance_EventScript_GotReward
	call_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox Route110_TrickHouseEntrance_Text_DidYouNotComeToClaimReward, MSGBOX_DEFAULT
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_GivePuzzle4Reward::
	giveitem ITEM_SMOKE_BALL
	goto_if_eq VAR_RESULT, TRUE, Route110_TrickHouseEntrance_EventScript_GotReward
	call_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox Route110_TrickHouseEntrance_Text_DidYouNotComeToClaimReward, MSGBOX_DEFAULT
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_GivePuzzle5Reward::
	giveitem ITEM_TM_TAUNT
	goto_if_eq VAR_RESULT, TRUE, Route110_TrickHouseEntrance_EventScript_GotReward
	call_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox Route110_TrickHouseEntrance_Text_DidYouNotComeToClaimReward, MSGBOX_DEFAULT
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_GivePuzzle6Reward::
	giveitem ITEM_MAGNET
	goto_if_eq VAR_RESULT, TRUE, Route110_TrickHouseEntrance_EventScript_GotReward
	call_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox Route110_TrickHouseEntrance_Text_DidYouNotComeToClaimReward, MSGBOX_DEFAULT
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_GivePuzzle7Reward::
	giveitem ITEM_PP_MAX
	goto_if_eq VAR_RESULT, TRUE, Route110_TrickHouseEntrance_EventScript_GotReward
	call_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox Route110_TrickHouseEntrance_Text_DidYouNotComeToClaimReward, MSGBOX_DEFAULT
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_GotReward::
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	setvar VAR_TRICK_HOUSE_ENTRANCE_STATE, 3
	applymovement LOCALID_TRICK_MASTER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_MechadollReward::
	applymovement LOCALID_TRICK_MASTER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox Route110_TrickHouseEntrance_Text_MechadollWhichTent, MSGBOX_DEFAULT
	call Route110_TrickHouseEntrance_EventScript_ChooseTent
	goto_if_eq VAR_RESULT, TRUE, Route110_TrickHouseEntrance_EventScript_ReceivedTent
	call_if_eq VAR_RESULT, FALSE, Common_EventScript_NoRoomForDecor
	msgbox Route110_TrickHouseEntrance_Text_PCFullAgain, MSGBOX_DEFAULT
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_ChooseTent::
	multichoice 0, 0, MULTI_TENT, TRUE
	switch VAR_RESULT
	case 0, Route110_TrickHouseEntrance_EventScript_GiveRedTent
	goto Route110_TrickHouseEntrance_EventScript_GiveBlueTent

Route110_TrickHouseEntrance_EventScript_GiveRedTent::
	givedecoration DECOR_RED_TENT
	return

Route110_TrickHouseEntrance_EventScript_GiveBlueTent::
	givedecoration DECOR_BLUE_TENT
	return

Route110_TrickHouseEntrance_EventScript_ReceivedTent::
	msgbox Route110_TrickHouseEntrance_Text_ThenFarewell, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_TRICK_MASTER, Route110_TrickHousePuzzle5_Movement_MechadollShake
	waitmovement 0
	applymovement LOCALID_TRICK_MASTER, Route110_TrickHouse_Movement_TrickMasterSpin
	waitmovement 0
	playse SE_M_EXPLOSION
	applymovement LOCALID_TRICK_MASTER, Route110_TrickHouse_Movement_TrickMasterJumpAway
	waitmovement 0
	removeobject LOCALID_TRICK_MASTER
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	setvar VAR_TRICK_HOUSE_ENTRANCE_STATE, 5
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_Door::
	lockall
	switch VAR_TRICK_HOUSE_ENTRANCE_STATE
	case 0, Route110_TrickHouseEntrance_EventScript_ItsAScroll
	case 1, Route110_TrickHouseEntrance_EventScript_GoInHolePrompt
	case 4, Route110_TrickHouseEntrance_EventScript_LeftOnJourneyNote
	case 5, Route110_TrickHouseEntrance_EventScript_CheckLevelForMessage
	end

Route110_TrickHouseEntrance_EventScript_ItsAScroll::
	msgbox Route110_TrickHouseEntrance_Text_ItsAScroll, MSGBOX_DEFAULT
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_GoInHolePrompt::
	msgbox Route110_TrickHouseEntrance_Text_GoInHoleBehindScroll, MSGBOX_YESNO
	closemessage
	goto_if_eq VAR_RESULT, YES, Route110_TrickHouseEntrance_EventScript_EnterPuzzleRoom
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_EnterPuzzleRoom::
	setmetatile 5, 1, METATILE_GenericBuilding_TrickHouse_Stairs_Down, FALSE
	special DrawWholeMapView
	delay 20
	applymovement LOCALID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_PLAYER, Route110_TrickHouseEntrance_Movement_EnterRoom
	waitmovement 0
	switch VAR_TRICK_HOUSE_LEVEL
	case 0, Route110_TrickHouseEntrance_EventScript_EnterPuzzleRoom1
	case 1, Route110_TrickHouseEntrance_EventScript_EnterPuzzleRoom2
	case 2, Route110_TrickHouseEntrance_EventScript_EnterPuzzleRoom3
	case 3, Route110_TrickHouseEntrance_EventScript_EnterPuzzleRoom4
	case 4, Route110_TrickHouseEntrance_EventScript_EnterPuzzleRoom5
	case 5, Route110_TrickHouseEntrance_EventScript_EnterPuzzleRoom6
	case 6, Route110_TrickHouseEntrance_EventScript_EnterPuzzleRoom7
	case 7, Route110_TrickHouseEntrance_EventScript_EnterPuzzleRoom8
	end

Route110_TrickHouseEntrance_Movement_EnterRoom:
	set_invisible
	step_end

Route110_TrickHouseEntrance_EventScript_EnterPuzzleRoom1::
	warp MAP_ROUTE110_TRICK_HOUSE_PUZZLE1, 0, 21
	waitstate
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_EnterPuzzleRoom2::
	warp MAP_ROUTE110_TRICK_HOUSE_PUZZLE2, 0, 21
	waitstate
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_EnterPuzzleRoom3::
	warp MAP_ROUTE110_TRICK_HOUSE_PUZZLE3, 0, 21
	waitstate
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_EnterPuzzleRoom4::
	warp MAP_ROUTE110_TRICK_HOUSE_PUZZLE4, 0, 21
	waitstate
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_EnterPuzzleRoom5::
	warp MAP_ROUTE110_TRICK_HOUSE_PUZZLE5, 0, 21
	waitstate
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_EnterPuzzleRoom6::
	warp MAP_ROUTE110_TRICK_HOUSE_PUZZLE6, 0, 21
	waitstate
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_EnterPuzzleRoom7::
	warp MAP_ROUTE110_TRICK_HOUSE_PUZZLE7, 0, 21
	waitstate
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_EnterPuzzleRoom8::
	warp MAP_ROUTE110_TRICK_HOUSE_PUZZLE8, 0, 21
	waitstate
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_LeftOnJourneyNote::
	msgbox Route110_TrickHouseEntrance_Text_LeavingOnJourneyNote, MSGBOX_DEFAULT
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_CheckLevelForMessage::
	goto_if_eq VAR_TRICK_HOUSE_LEVEL, 8, Route110_TrickHouseEntrance_EventScript_LeftOnJourneyNote2
	msgbox Route110_TrickHouseEntrance_Text_ItsAScroll, MSGBOX_DEFAULT
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_LeftOnJourneyNote2::
	msgbox Route110_TrickHouseEntrance_Text_LeavingOnJourneyNote, MSGBOX_DEFAULT
	releaseall
	end

Route110_TrickHousePuzzle_EventScript_Door::
	lockall
	switch VAR_TRICK_HOUSE_LEVEL
	case 0, Route110_TrickHousePuzzle1_EventScript_Door
	case 1, Route110_TrickHousePuzzle2_EventScript_Door
	case 2, Route110_TrickHousePuzzle3_EventScript_Door
	case 3, Route110_TrickHousePuzzle4_EventScript_Door
	case 4, Route110_TrickHousePuzzle5_EventScript_Door
	case 5, Route110_TrickHousePuzzle6_EventScript_Door
	case 6, Route110_TrickHousePuzzle7_EventScript_Door
	case 7, Route110_TrickHousePuzzle8_EventScript_Door
	end

Route110_TrickHousePuzzle1_EventScript_Door::
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_1_STATE, 0, Route110_TrickHousePuzzle_EventScript_DoorLocked
	msgbox Route110_TrickHousePuzzle1_Text_WroteSecretCodeLockOpened, MSGBOX_DEFAULT
	playse SE_PIN
	setvar VAR_TRICK_HOUSE_PUZZLE_1_STATE, 2
	setmetatile 13, 1, METATILE_TrickHousePuzzle_Stairs_Down, FALSE
	special DrawWholeMapView
	releaseall
	end

Route110_TrickHousePuzzle2_EventScript_Door::
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_2_STATE, 0, Route110_TrickHousePuzzle_EventScript_DoorLocked
	msgbox Route110_TrickHousePuzzle2_Text_WroteSecretCodeLockOpened, MSGBOX_DEFAULT
	playse SE_PIN
	setvar VAR_TRICK_HOUSE_PUZZLE_2_STATE, 2
	setmetatile 13, 1, METATILE_TrickHousePuzzle_Stairs_Down, FALSE
	special DrawWholeMapView
	releaseall
	end

Route110_TrickHousePuzzle3_EventScript_Door::
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_3_STATE, 0, Route110_TrickHousePuzzle_EventScript_DoorLocked
	msgbox Route110_TrickHousePuzzle3_Text_WroteSecretCodeLockOpened, MSGBOX_DEFAULT
	playse SE_PIN
	setvar VAR_TRICK_HOUSE_PUZZLE_3_STATE, 2
	setmetatile 13, 1, METATILE_TrickHousePuzzle_Stairs_Down, FALSE
	special DrawWholeMapView
	releaseall
	end

Route110_TrickHousePuzzle4_EventScript_Door::
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_4_STATE, 0, Route110_TrickHousePuzzle_EventScript_DoorLocked
	msgbox Route110_TrickHousePuzzle4_Text_WroteSecretCodeLockOpened, MSGBOX_DEFAULT
	playse SE_PIN
	setvar VAR_TRICK_HOUSE_PUZZLE_4_STATE, 2
	setmetatile 13, 1, METATILE_TrickHousePuzzle_Stairs_Down, FALSE
	special DrawWholeMapView
	releaseall
	end

Route110_TrickHousePuzzle5_EventScript_Door::
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_5_STATE, 0, Route110_TrickHousePuzzle_EventScript_DoorLocked
	msgbox Route110_TrickHousePuzzle5_Text_WroteSecretCodeLockOpened, MSGBOX_DEFAULT
	playse SE_PIN
	setvar VAR_TRICK_HOUSE_PUZZLE_5_STATE, 2
	setmetatile 13, 1, METATILE_TrickHousePuzzle_Stairs_Down, FALSE
	special DrawWholeMapView
	releaseall
	end

Route110_TrickHousePuzzle6_EventScript_Door::
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_6_STATE, 0, Route110_TrickHousePuzzle_EventScript_DoorLocked
	msgbox Route110_TrickHousePuzzle6_Text_WroteSecretCodeLockOpened, MSGBOX_DEFAULT
	playse SE_PIN
	setvar VAR_TRICK_HOUSE_PUZZLE_6_STATE, 2
	setmetatile 13, 1, METATILE_TrickHousePuzzle_Stairs_Down, FALSE
	special DrawWholeMapView
	releaseall
	end

Route110_TrickHousePuzzle7_EventScript_Door::
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_7_STATE, 0, Route110_TrickHousePuzzle_EventScript_DoorLocked
	msgbox Route110_TrickHousePuzzle7_Text_WroteSecretCodeLockOpened, MSGBOX_DEFAULT
	playse SE_PIN
	setvar VAR_TRICK_HOUSE_PUZZLE_7_STATE, 2
	setmetatile 13, 1, METATILE_TrickHousePuzzle_Stairs_Down, FALSE
	special DrawWholeMapView
	releaseall
	end

Route110_TrickHousePuzzle8_EventScript_Door::
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_8_STATE, 0, Route110_TrickHousePuzzle_EventScript_DoorLocked
	msgbox Route110_TrickHousePuzzle8_Text_WroteSecretCodeLockOpened, MSGBOX_DEFAULT
	playse SE_PIN
	setvar VAR_TRICK_HOUSE_PUZZLE_8_STATE, 2
	setmetatile 13, 1, METATILE_TrickHousePuzzle_Stairs_Down, FALSE
	special DrawWholeMapView
	releaseall
	end

Route110_TrickHousePuzzle_EventScript_DoorLocked::
	msgbox Route110_TrickHouseEntrance_Text_DoorLockedWriteSecretCodeHere, MSGBOX_DEFAULT
	releaseall
	end

Route110_TrickHousePuzzle_EventScript_ReadScrollAgain::
	msgbox Route110_TrickHousePuzzle_Text_SecretCodeWrittenOnIt, MSGBOX_DEFAULT
	releaseall
	end

Route110_TrickHousePuzzle_EventScript_FoundScroll::
	playfanfare MUS_OBTAIN_ITEM
	message Route110_TrickHousePuzzle_Text_FoundAScroll
	waitfanfare
	msgbox Route110_TrickHousePuzzle_Text_MemorizedSecretCode, MSGBOX_DEFAULT
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_TrickMasterHiding::
	lockall
	msgbox Route110_TrickHouseEntrance_Text_YoureBeingWatched, MSGBOX_DEFAULT
	releaseall
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 0, Route110_TrickHouseEntrance_EventScript_DoHidingSpotSparkle1
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 1, Route110_TrickHouseEntrance_EventScript_DoHidingSpotSparkle2
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 2, Route110_TrickHouseEntrance_EventScript_DoHidingSpotSparkle3
	setvar VAR_TRICK_HOUSE_BEING_WATCHED_STATE, 1
	end

Route110_TrickHouseEntrance_EventScript_DoHidingSpotSparkle1::
	setvar VAR_0x8004, 6  @ x
	setvar VAR_0x8005, 3  @ y
	call Route110_TrickHouseEntrance_EventScript_DoHidingSpotSparkle
	return

Route110_TrickHouseEntrance_EventScript_DoHidingSpotSparkle2::
	setvar VAR_0x8004, 11  @ x
	setvar VAR_0x8005, 5   @ y
	call Route110_TrickHouseEntrance_EventScript_DoHidingSpotSparkle
	return

Route110_TrickHouseEntrance_EventScript_DoHidingSpotSparkle3::
	setvar VAR_0x8004, 9  @ x
	setvar VAR_0x8005, 2  @ y
	call Route110_TrickHouseEntrance_EventScript_DoHidingSpotSparkle
	return

Route110_TrickHouseEntrance_EventScript_DoHidingSpotSparkle::
	setvar VAR_0x8006, 0
	dofieldeffectsparkle VAR_0x8004, VAR_0x8005, VAR_0x8006
	waitfieldeffect FLDEFF_SPARKLE
	delay 10
	return

Route110_TrickHouseEntrance_Text_YoureBeingWatched:
	.string "Có người đang theo dõi...$"

Route110_TrickHouseEntrance_Text_ConcealedBeneathDesk:
	.string "Hả? Gừừ...\p"
	.string "Sao ngươi biết ta ẩn dưới chiếc bàn\n"
	.string "này? Sắc bén lắm!$"

Route110_TrickHouseEntrance_Text_ConcealedBehindTree:
	.string "Hả? Gừừ...\p"
	.string "Sao ngươi biết ta ẩn sau cái cây này?\n"
	.string "Sắc bén lắm!$"

Route110_TrickHouseEntrance_Text_ConcealedInDresser:
	.string "Hả? Gừừ...\p"
	.string "Sao ngươi biết ta ẩn trong chiếc tủ\n"
	.string "ngăn kéo này? Sắc bén lắm!$"

Route110_TrickHouseEntrance_Text_ConealedBeyondWindow:
	.string "Hả? Gừừ...\p"
	.string "Sao ngươi biết ta ẩn phía bên kia cửa\n"
	.string "sổ này? Sắc bén lắm!$"

Route110_TrickHouseEntrance_Text_ConcealedInPlanter:
	.string "Hả? Gừừ...\p"
	.string "Sao ngươi biết ta ẩn trong bồn cây\n"
	.string "này? Sắc bén lắm!$"

Route110_TrickHouseEntrance_Text_ConcealedInCupboard:
	.string "Hả? Gừừ...\p"
	.string "Sao ngươi biết ta ẩn trong chiếc tủ\n"
	.string "này? Sắc bén lắm!$"

Route110_TrickHouseEntrance_Text_ConcealedBehindWindow:
	.string "Hả? Gừừ...\p"
	.string "Sao ngươi biết ta ẩn sau cửa sổ này?\n"
	.string "Sắc bén lắm!$"

Route110_TrickHouseEntrance_Text_ConcealedBeneathCushion:
	.string "Hả? Gừừ...\p"
	.string "Sao ngươi biết ta ẩn dưới chiếc đệm\n"
	.string "này? Sắc bén lắm!$"

Route110_TrickHouseEntrance_Text_TheyCallMeTrickMaster:
	.string "Hãy chiêm ngưỡng!\p"
	.string "Bởi ta là người đàn ông bí ẩn nhất còn\n"
	.string "sống trên toàn HOENN! Người ta gọi ta\l"
	.string "là...\p"
	.string "TRICK MASTER! Wahahaha! Rất hân hạnh\n"
	.string "được gặp ngươi!$"

Route110_TrickHouseEntrance_Text_ComeToChallengeTrickHouse:
	.string "Ngươi, ngươi đến để thách thức TRICK\n"
	.string "HOUSE của ta, đúng không?\p"
	.string "Vì thế ngươi mới ở đây, đúng không?\n"
	.string "Đúng vậy!\p"
	.string "Ta chấp nhận lời thách đấu!\p"
	.string "Hãy đi qua cuộn giấy đằng kia và bắt\n"
	.string "đầu thử thách!\p"
	.string "Ta sẽ đợi ở phía sau!$"

Route110_TrickHouseEntrance_Text_ItsAScroll:
	.string "Đó là một cuộn giấy.$"

Route110_TrickHouseEntrance_Text_GoInHoleBehindScroll:
	.string "Có một cái lỗ lớn phía sau cuộn giấy!\p"
	.string "Muốn chui vào không?$"

Route110_TrickHouseEntrance_Text_LeavingOnJourneyNote:
	.string "Có một mảnh giấy được gắn vào cuộn\n"
	.string "giấy...\p"
	.string "“Ta lên đường đây. Đừng tìm ta. TRICK\n"
	.string "MASTER”$"

Route110_TrickHouseEntrance_Text_NextTimeUseThisTrick:
	.string "Lần tới, ta sẽ dùng trò này, kế kia và cả\n"
	.string "những mánh nọ...\p"
	.string "Mufufufu... Ta phải tự công nhận rằng\n"
	.string "nó khó một cách xuất sắc, ngay cả với\l"
	.string "ta!$"

Route110_TrickHouseEntrance_Text_InMidstOfDevisingNewChallenges:
	.string "Hả? Gì?! Ồ, là ngươi!\p"
	.string "Ta đang bận nghĩ ra những thử thách\n"
	.string "mưu mẹo mới!\p"
	.string "Cho ta thêm chút thời gian suy nghĩ\n"
	.string "đâu có quá đáng, phải không? Ngươi\l"
	.string "không nỡ từ chối chứ? Lát nữa hãy\l"
	.string "quay lại!$"

Route110_TrickHouseEntrance_Text_YoureHereToAcceptReward:
	.string "À, là ngươi! Ngươi đến nhận phần\n"
	.string "thưởng lần trước, đúng không? Phải,\l"
	.string "đúng là ta!\p"
	.string "Đây! Ta sẽ đưa cho ngươi ngay!$"

Route110_TrickHouseEntrance_Text_DidYouNotComeToClaimReward:
	.string "Hả? Ngươi không đến nhận phần thưởng\n"
	.string "sao?$"

Route110_TrickHouseEntrance_Text_MechadollWhichTent:
	.string "TA LÀ MECHADOLL 5! NẾU NGƯƠI KHÔNG\n"
	.string "NHẬN PHẦN THƯỞNG, NGƯƠI KHÔNG THỂ ĐI\l"
	.string "THEO TRICK MASTER.\p"
	.string "NGƯƠI THÍCH RED TENT HAY BLUE TENT?$"

Route110_TrickHouseEntrance_Text_ThenFarewell:
	.string "VẬY THÌ TẠM BIỆT.$"

Route110_TrickHouseEntrance_Text_PCFullAgain:
	.string "TRẠNG THÁI PC CỦA NGƯƠI: LẠI ĐẦY.\n"
	.string "NGƯƠI, THẬT XẤU TÍNH.$"

Route110_TrickHousePuzzle_Text_FoundAScroll:
	.string "{PLAYER} tìm thấy một cuộn giấy.$"

Route110_TrickHousePuzzle_Text_MemorizedSecretCode:
	.string "{PLAYER} ghi nhớ mật mã viết trên\n"
	.string "cuộn giấy.$"

Route110_TrickHousePuzzle_Text_SecretCodeWrittenOnIt:
	.string "Trên đó có viết một mật mã.$"

Route110_TrickHouseEntrance_Text_DoorLockedWriteSecretCodeHere:
	.string "Cửa bị khóa.\p"
	.string "...Nhìn kỹ hơn, trên đó viết: “Hãy viết\n"
	.string "mật mã vào đây.”$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global Route110_TrickHouseEntrance_Text_YoureBeingWatched
	.global Route110_TrickHouseEntrance_Text_ConcealedBeneathDesk
	.global Route110_TrickHouseEntrance_Text_ConcealedBehindTree
	.global Route110_TrickHouseEntrance_Text_ConcealedInDresser
	.global Route110_TrickHouseEntrance_Text_ConealedBeyondWindow
	.global Route110_TrickHouseEntrance_Text_ConcealedInPlanter
	.global Route110_TrickHouseEntrance_Text_ConcealedInCupboard
	.global Route110_TrickHouseEntrance_Text_ConcealedBehindWindow
	.global Route110_TrickHouseEntrance_Text_ConcealedBeneathCushion
	.global Route110_TrickHouseEntrance_Text_TheyCallMeTrickMaster
	.global Route110_TrickHouseEntrance_Text_ComeToChallengeTrickHouse
	.global Route110_TrickHouseEntrance_Text_ItsAScroll
	.global Route110_TrickHouseEntrance_Text_GoInHoleBehindScroll
	.global Route110_TrickHouseEntrance_Text_LeavingOnJourneyNote
	.global Route110_TrickHouseEntrance_Text_NextTimeUseThisTrick
	.global Route110_TrickHouseEntrance_Text_InMidstOfDevisingNewChallenges
	.global Route110_TrickHouseEntrance_Text_YoureHereToAcceptReward
	.global Route110_TrickHouseEntrance_Text_DidYouNotComeToClaimReward
	.global Route110_TrickHouseEntrance_Text_MechadollWhichTent
	.global Route110_TrickHouseEntrance_Text_ThenFarewell
	.global Route110_TrickHouseEntrance_Text_PCFullAgain
	.global Route110_TrickHousePuzzle_Text_FoundAScroll
	.global Route110_TrickHousePuzzle_Text_MemorizedSecretCode
	.global Route110_TrickHousePuzzle_Text_SecretCodeWrittenOnIt
	.global Route110_TrickHouseEntrance_Text_DoorLockedWriteSecretCodeHere
@ END GENERATED LOCALIZATION EXPORTS
