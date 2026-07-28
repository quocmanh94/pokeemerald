RustboroCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RustboroCity_OnFrame
	.byte 0

RustboroCity_OnTransition:
	setflag FLAG_VISITED_RUSTBORO_CITY
	call Common_EventScript_SetupRivalGfxId
	call_if_eq VAR_RUSTBORO_CITY_STATE, 6, RustboroCity_EventScript_HideMapNamePopup
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	goto_if_eq VAR_RUSTBORO_CITY_STATE, 6, RustboroCity_EventScript_PositionScientistForExit
	end

RustboroCity_EventScript_PositionScientistForExit::
	goto_if_eq VAR_TEMP_0, 11, RustboroCity_EventScript_PositionScientistLeftExit
	setobjectxyperm LOCALID_RUSTBORO_SCIENTIST, 12, 15
	end

RustboroCity_EventScript_PositionScientistLeftExit::
	setobjectxyperm LOCALID_RUSTBORO_SCIENTIST, 11, 15
	end

RustboroCity_EventScript_HideMapNamePopup::
	setflag FLAG_HIDE_MAP_NAME_POPUP
	return

RustboroCity_OnFrame:
	map_script_2 VAR_RUSTBORO_CITY_STATE, 6, RustboroCity_EventScript_ScientistAddMatchCall
	.2byte 0

RustboroCity_EventScript_ScientistAddMatchCall::
	lockall
	setvar VAR_ROUTE104_STATE, 1
	applymovement LOCALID_PLAYER, RustboroCity_Movement_PlayerWalkDown
	waitmovement 0
	playse SE_EXIT
	delay 10
	addobject LOCALID_RUSTBORO_SCIENTIST
	applymovement LOCALID_RUSTBORO_SCIENTIST, RustboroCity_Movement_ScientistApproachPlayer
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RUSTBORO_SCIENTIST, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RUSTBORO_SCIENTIST, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	applymovement LOCALID_RUSTBORO_SCIENTIST, RustboroCity_Movement_ScientistWalkInPlaceDown
	waitmovement 0
	msgbox RustboroCity_Text_DevelopedNewPokenavFeature, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_HAS_MATCH_CALL
	applymovement LOCALID_RUSTBORO_SCIENTIST, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	playse SE_CLICK
	delay 10
	playse SE_CLICK
	delay 10
	playse SE_CLICK
	delay 10
	playse SE_CLICK
	delay 20
	applymovement LOCALID_RUSTBORO_SCIENTIST, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox RustboroCity_Text_AddedMatchCallPleaseCallMrStone, MSGBOX_DEFAULT
	closemessage
	delay 20
	goto RustboroCity_EventScript_MatchCallTutorial

RustboroCity_EventScript_PleaseSelectPokenav::
	msgbox RustboroCity_Text_PleaseSelectPokenav, MSGBOX_DEFAULT
	closemessage
	delay 10
	goto RustboroCity_EventScript_MatchCallTutorial

RustboroCity_EventScript_MatchCallTutorial::
	setflag FLAG_ADDED_MATCH_CALL_TO_POKENAV
	special ScriptMenu_CreateStartMenuForPokenavTutorial
	switch VAR_RESULT
	case 0, RustboroCity_EventScript_PleaseSelectPokenav
	case 1, RustboroCity_EventScript_PleaseSelectPokenav
	case 2, RustboroCity_EventScript_PleaseSelectPokenav
	case 4, RustboroCity_EventScript_PleaseSelectPokenav
	case 5, RustboroCity_EventScript_PleaseSelectPokenav
	case 6, RustboroCity_EventScript_PleaseSelectPokenav
	case 7, RustboroCity_EventScript_PleaseSelectPokenav
	case MULTI_B_PRESSED, RustboroCity_EventScript_PleaseSelectPokenav
	special OpenPokenavForTutorial
	delay 20
	msgbox RustboroCity_Text_IdBetterGetBackToWork, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_RUSTBORO_SCIENTIST, RustboroCity_Movement_ScientistLeave
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_RUSTBORO_SCIENTIST
	setflag FLAG_HIDE_RUSTBORO_CITY_SCIENTIST
	setvar VAR_RUSTBORO_CITY_STATE, 7
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	releaseall
	end

RustboroCity_Movement_ScientistWalkInPlaceDown:
	walk_in_place_down
	step_end

RustboroCity_Movement_PlayerWalkDown:
	walk_down
	step_end

RustboroCity_Movement_ScientistApproachPlayer:
	walk_down
	delay_16
	step_end

@ Unused
RustboroCity_Movement_ScientistWalkAroundPlayer:
	delay_16
	walk_left
	walk_down
	walk_down
	walk_right
	walk_in_place_faster_up
	delay_16
	step_end

RustboroCity_Movement_ScientistLeave:
	walk_up
	step_end

RustboroCity_EventScript_FatMan::
	lock
	faceplayer
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_EventScript_FatManSawGrunt
	msgbox RustboroCity_Text_WeShortenItToDevon, MSGBOX_DEFAULT
	release
	end

RustboroCity_EventScript_FatManSawGrunt::
	msgbox RustboroCity_Text_SneakyLookingManWentAroundCorner, MSGBOX_DEFAULT
	release
	end

RustboroCity_EventScript_DevonEmployee2::
	lock
	faceplayer
	msgbox RustboroCity_Text_YoureNewAroundHere, MSGBOX_DEFAULT
	release
	end

RustboroCity_EventScript_Woman::
	msgbox RustboroCity_Text_GymLeaderIsntEasyWithFire, MSGBOX_NPC
	end

RustboroCity_EventScript_Man1::
	lock
	faceplayer
	goto_if_set FLAG_BADGE01_GET, RustboroCity_EventScript_Man1HaveBadge
	msgbox RustboroCity_Text_HaveYouChallengedGym, MSGBOX_DEFAULT
	release
	end

RustboroCity_EventScript_Man1HaveBadge::
	msgbox RustboroCity_Text_HeyThatsRustborosGymBadge, MSGBOX_DEFAULT
	release
	end

RustboroCity_EventScript_Boy2::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_POKENAV, RustboroCity_EventScript_Boy2BrineyLeftTunnel
	msgbox RustboroCity_Text_MrBrineyWalksInTheTunnel, MSGBOX_DEFAULT
	release
	end

RustboroCity_EventScript_Boy2BrineyLeftTunnel::
	msgbox RustboroCity_Text_MrBrineyLovesPeeko, MSGBOX_DEFAULT
	release
	end

RustboroCity_EventScript_Twin::
	msgbox RustboroCity_Text_WowYouHavePokemon, MSGBOX_NPC
	end

RustboroCity_EventScript_NinjaBoy::
	msgbox RustboroCity_Text_CatchRarePokemonIfIGoToSchool, MSGBOX_SIGN
	end

RustboroCity_EventScript_TunnelSign::
	msgbox RustboroCity_Text_TunnelNearingCompletion, MSGBOX_SIGN
	end

RustboroCity_EventScript_DevonCorpSign::
	msgbox RustboroCity_Text_DevonCorpSign, MSGBOX_SIGN
	end

RustboroCity_EventScript_GymSign::
	msgbox RustboroCity_Text_GymSign, MSGBOX_SIGN
	end

@ Unused
RustboroCity_EventScript_DevonCorpBranchOfficeSign::
	msgbox RustboroCity_Text_DevonCorpBranchOfficeSign, MSGBOX_SIGN
	end

RustboroCity_EventScript_CitySign::
	msgbox RustboroCity_Text_CitySign, MSGBOX_SIGN
	end

RustboroCity_EventScript_TrainersSchoolSign::
	msgbox RustboroCity_Text_TrainersSchoolSign, MSGBOX_SIGN
	end

RustboroCity_EventScript_CuttersHouseSign::
	msgbox RustboroCity_Text_CuttersHouse, MSGBOX_SIGN
	end

RustboroCity_EventScript_LittleBoy::
	lock
	faceplayer
	msgbox RustboroCity_Text_PokemonCanChangeLookFromExp, MSGBOX_DEFAULT
	applymovement LOCALID_RUSTBORO_LITTLE_BOY, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_EventScript_LittleGirl::
	lock
	faceplayer
	msgbox RustboroCity_Text_PokemonChangeShape, MSGBOX_DEFAULT
	applymovement LOCALID_RUSTBORO_LITTLE_GIRL, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_EventScript_Man2::
	lock
	faceplayer
	msgbox RustboroCity_Text_TradePokemonGrowFast, MSGBOX_DEFAULT
	release
	end

RustboroCity_EventScript_StolenGoodsTrigger0::
	lockall
	setobjectxyperm LOCALID_RUSTBORO_DEVON_EMPLOYEE, 14, 21
	setobjectmovementtype LOCALID_RUSTBORO_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
	setvar VAR_0x8004, 0
	goto RustboroCity_EventScript_StolenGoodsScene
	end

RustboroCity_EventScript_StolenGoodsTrigger1::
	lockall
	setobjectxyperm LOCALID_RUSTBORO_DEVON_EMPLOYEE, 14, 21
	setobjectmovementtype LOCALID_RUSTBORO_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
	setvar VAR_0x8004, 1
	goto RustboroCity_EventScript_StolenGoodsScene
	end

RustboroCity_EventScript_StolenGoodsTrigger2::
	lockall
	setobjectxyperm LOCALID_RUSTBORO_DEVON_EMPLOYEE, 14, 21
	setobjectmovementtype LOCALID_RUSTBORO_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
	setvar VAR_0x8004, 2
	goto RustboroCity_EventScript_StolenGoodsScene
	end

RustboroCity_EventScript_StolenGoodsTrigger3::
	lockall
	setobjectxyperm LOCALID_RUSTBORO_DEVON_EMPLOYEE, 14, 21
	setobjectmovementtype LOCALID_RUSTBORO_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
	setvar VAR_0x8004, 3
	goto RustboroCity_EventScript_StolenGoodsScene
	end

RustboroCity_EventScript_StolenGoodsTrigger4::
	lockall
	setobjectxyperm LOCALID_RUSTBORO_DEVON_EMPLOYEE, 14, 21
	setobjectmovementtype LOCALID_RUSTBORO_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
	setvar VAR_0x8004, 4
	goto RustboroCity_EventScript_StolenGoodsScene
	end

RustboroCity_EventScript_StolenGoodsScene::
	msgbox RustboroCity_Text_OutOfTheWay, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	addobject LOCALID_RUSTBORO_GRUNT
	addobject LOCALID_RUSTBORO_DEVON_EMPLOYEE
	applymovement LOCALID_RUSTBORO_GRUNT, RustboroCity_Movement_GruntEscape
	waitmovement 0
	removeobject LOCALID_RUSTBORO_GRUNT
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeChaseGrunt1
	waitmovement 0
	msgbox RustboroCity_Text_WaitDontTakeMyGoods, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeChaseGrunt2
	waitmovement 0
	fadedefaultbgm
	removeobject LOCALID_RUSTBORO_DEVON_EMPLOYEE
	setobjectxyperm LOCALID_RUSTBORO_DEVON_EMPLOYEE, 30, 10
	clearflag FLAG_HIDE_RUSTBORO_CITY_DEVON_EMPLOYEE_1
	setflag FLAG_DEVON_GOODS_STOLEN
	setvar VAR_RUSTBORO_CITY_STATE, 2
	setvar VAR_RUSTURF_TUNNEL_STATE, 2
	setvar VAR_ROUTE116_STATE, 1
	clearflag FLAG_HIDE_ROUTE_116_MR_BRINEY
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_PEEKO
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_AQUA_GRUNT
	setflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	setflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	releaseall
	end

@ Unused
RustboroCity_EventScript_ShadyCharacterTookOff::
	msgbox RustboroCity_Text_ShadyCharacterTookOffTowardsTunnel, MSGBOX_DEFAULT
	return

@ Unused
RustboroCity_EventScript_YouGotItThankYou::
	msgbox RustboroCity_Text_YouGotItThankYou, MSGBOX_DEFAULT
	return

@ Unknown, unused employee movements. Based on the differences in movement theyre for approaching an object (probably the player) in different positions
RustboroCity_EventScript_EmployeeApproachUp::
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachUp
	waitmovement 0
	return

@ Unused, see above
RustboroCity_EventScript_EmployeeApproachLeft::
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachLeft
	waitmovement 0
	return

@ Unused, see above
RustboroCity_EventScript_EmployeeApproachRight::
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachRight
	waitmovement 0
	return

@ Unused, see above
RustboroCity_EventScript_EmployeeApproachDown::
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachDown
	waitmovement 0
	return

@ Unused, similar movement to the above scripts
RustboroCity_EventScript_EmployeeApproachPlayerFar::
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachPlayerFar
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

@ Unused
RustboroCity_Movement_GruntEscapeExtended:
	walk_faster_right
	walk_faster_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

RustboroCity_Movement_GruntEscape:
	walk_faster_right
	walk_faster_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

RustboroCity_Movement_EmployeeChaseGrunt1:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

RustboroCity_Movement_EmployeeChaseGrunt2:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

@ Functionally unused
RustboroCity_Movement_EmployeeApproachUp:
	walk_down
	walk_right
	walk_right
	step_end

@ Functionally unused
RustboroCity_Movement_EmployeeApproachLeft:
	walk_down
	walk_down
	walk_right
	walk_right
	step_end

@ Functionally unused
RustboroCity_Movement_EmployeeApproachRight:
	walk_down
	walk_down
	walk_right
	walk_right
	step_end

@ Functionally unused
RustboroCity_Movement_EmployeeApproachDown:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	step_end

@ Functionally unused
RustboroCity_Movement_EmployeeApproachPlayerFar:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_down
	step_end

RustboroCity_EventScript_DevonEmployee1::
	lock
	faceplayer
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, RustboroCity_EventScript_ReturnGoodsSpokeToEmployee
	msgbox RustboroCity_Text_ShadyCharacterTookOffTowardsTunnel, MSGBOX_DEFAULT
	release
	end

RustboroCity_EventScript_ReturnGoodsSpokeToEmployee::
	waitse
	setvar VAR_TEMP_1, 4
	goto RustboroCity_EventScript_ReturnGoods
	end

RustboroCity_EventScript_HelpGetGoodsTrigger0::
	lockall
	setvar VAR_TEMP_1, 0
	goto RustboroCity_EventScript_EmployeeAskToGetGoods
	end

RustboroCity_EventScript_HelpGetGoodsTrigger1::
	lockall
	setvar VAR_TEMP_1, 1
	goto RustboroCity_EventScript_EmployeeAskToGetGoods
	end

RustboroCity_EventScript_HelpGetGoodsTrigger2::
	lockall
	setvar VAR_TEMP_1, 2
	goto RustboroCity_EventScript_EmployeeAskToGetGoods
	end

RustboroCity_EventScript_HelpGetGoodsTrigger3::
	lockall
	setvar VAR_TEMP_1, 3
	goto RustboroCity_EventScript_EmployeeAskToGetGoods
	end

RustboroCity_EventScript_EmployeeAskToGetGoods::
	call_if_eq VAR_TEMP_1, 0, RustboroCity_EventScript_EmployeeFacePlayerUp1
	call_if_eq VAR_TEMP_1, 1, RustboroCity_EventScript_EmployeeFacePlayerLeft1
	call_if_eq VAR_TEMP_1, 2, RustboroCity_EventScript_EmployeeFacePlayerDown1
	call_if_eq VAR_TEMP_1, 3, RustboroCity_EventScript_EmployeeApproachPlayerDown1
	setflag FLAG_INTERACTED_WITH_DEVON_EMPLOYEE_GOODS_STOLEN
	setvar VAR_RUSTBORO_CITY_STATE, 3
	copyobjectxytoperm LOCALID_RUSTBORO_DEVON_EMPLOYEE
	msgbox RustboroCity_Text_HelpMeIWasRobbed, MSGBOX_DEFAULT
	releaseall
	end

@ The below movement scripts are either partially or fully duplicated by the movement scripts when the player returns the goods
RustboroCity_EventScript_EmployeeFacePlayerUp1::
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

RustboroCity_EventScript_EmployeeFacePlayerLeft1::
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	return

RustboroCity_EventScript_EmployeeFacePlayerDown1::
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

RustboroCity_EventScript_EmployeeApproachPlayerDown1::
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachPlayerDown
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

RustboroCity_Movement_EmployeeApproachPlayerDown:
	walk_down
	step_end

RustboroCity_EventScript_ReturnGoodsTrigger0::
	lockall
	setvar VAR_TEMP_1, 0
	goto RustboroCity_EventScript_ReturnGoods
	end

RustboroCity_EventScript_ReturnGoodsTrigger1::
	lockall
	setvar VAR_TEMP_1, 1
	goto RustboroCity_EventScript_ReturnGoods
	end

RustboroCity_EventScript_ReturnGoodsTrigger2::
	lockall
	setvar VAR_TEMP_1, 2
	goto RustboroCity_EventScript_ReturnGoods
	end

RustboroCity_EventScript_ReturnGoodsTrigger3::
	lockall
	setvar VAR_TEMP_1, 3
	goto RustboroCity_EventScript_ReturnGoods
	end

RustboroCity_EventScript_ReturnGoods::
	call_if_eq VAR_TEMP_1, 0, RustboroCity_EventScript_EmployeeFacePlayerUp2
	call_if_eq VAR_TEMP_1, 1, RustboroCity_EventScript_EmployeeFacePlayerLeft2
	call_if_eq VAR_TEMP_1, 2, RustboroCity_EventScript_EmployeeFacePlayerDown2
	call_if_eq VAR_TEMP_1, 3, RustboroCity_EventScript_EmployeeApproachPlayerDown2
	call_if_eq VAR_TEMP_1, 4, RustboroCity_EventScript_EmployeeFacePlayerRight
	msgbox RustboroCity_Text_YouGotItThankYou, MSGBOX_DEFAULT
	giveitem ITEM_GREAT_BALL
	call_if_eq VAR_RESULT, FALSE, RustboroCity_EventScript_BagFull
	msgbox RustboroCity_Text_PleaseComeWithMe, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_RETURNED_DEVON_GOODS
	setflag FLAG_HIDE_RUSTBORO_CITY_DEVON_EMPLOYEE_1
	setvar VAR_RUSTBORO_CITY_STATE, 5
	delay 30
	warp MAP_RUSTBORO_CITY_DEVON_CORP_3F, 2, 2
	waitstate
	releaseall
	end

RustboroCity_EventScript_BagFull::
	msgbox RustboroCity_Text_YoureLoadedWithItems, MSGBOX_DEFAULT
	return

RustboroCity_EventScript_EmployeeFacePlayerUp2::
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

RustboroCity_EventScript_EmployeeFacePlayerLeft2::
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	return

RustboroCity_EventScript_EmployeeFacePlayerDown2::
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

RustboroCity_EventScript_EmployeeApproachPlayerDown2::
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachPlayerDown
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

RustboroCity_EventScript_EmployeeFacePlayerRight::
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
	waitmovement 0
	return

RustboroCity_EventScript_Rival::
	lockall
	call_if_unset FLAG_MET_RIVAL_RUSTBORO, RustboroCity_EventScript_PlayRivalMusic
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_FacePlayer
	waitmovement 0
	goto RustboroCity_EventScript_RivalEncounter

RustboroCity_EventScript_PlayRivalMusic::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, RustboroCity_EventScript_PlayMayMusic
	goto_if_eq VAR_RESULT, FEMALE, RustboroCity_EventScript_PlayBrendanMusic
	return

RustboroCity_EventScript_PlayMayMusic::
	playbgm MUS_ENCOUNTER_MAY, TRUE
	return

RustboroCity_EventScript_PlayBrendanMusic::
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	return

RustboroCity_EventScript_RivalTrigger0::
	lockall
	call RustboroCity_EventScript_PlayRivalMusic
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_RUSTBORO_RIVAL, RustboroCity_Movement_RivalApproachPlayer0
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	goto RustboroCity_EventScript_RivalEncounter

RustboroCity_EventScript_RivalTrigger1::
	lockall
	call RustboroCity_EventScript_PlayRivalMusic
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_RUSTBORO_RIVAL, RustboroCity_Movement_RivalApproachPlayer1
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	goto RustboroCity_EventScript_RivalEncounter

RustboroCity_EventScript_RivalTrigger2::
	lockall
	call RustboroCity_EventScript_PlayRivalMusic
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_RUSTBORO_RIVAL, RustboroCity_Movement_RivalApproachPlayer2
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	goto RustboroCity_EventScript_RivalEncounter

RustboroCity_EventScript_RivalTrigger3::
	lockall
	call RustboroCity_EventScript_PlayRivalMusic
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_RUSTBORO_RIVAL, RustboroCity_Movement_RivalApproachPlayer3
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	goto RustboroCity_EventScript_RivalEncounter

RustboroCity_EventScript_RivalTrigger4::
	lockall
	call RustboroCity_EventScript_PlayRivalMusic
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_RUSTBORO_RIVAL, RustboroCity_Movement_RivalApproachPlayer4
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	goto RustboroCity_EventScript_RivalEncounter

RustboroCity_EventScript_RivalTrigger5::
	lockall
	call RustboroCity_EventScript_PlayRivalMusic
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_RUSTBORO_RIVAL, RustboroCity_Movement_RivalApproachPlayer5
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	goto RustboroCity_EventScript_RivalEncounter

RustboroCity_EventScript_RivalTrigger6::
	lockall
	call RustboroCity_EventScript_PlayRivalMusic
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_RUSTBORO_RIVAL, RustboroCity_Movement_RivalApproachPlayer6
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	goto RustboroCity_EventScript_RivalEncounter

RustboroCity_EventScript_RivalTrigger7::
	lockall
	call RustboroCity_EventScript_PlayRivalMusic
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_RUSTBORO_RIVAL, RustboroCity_Movement_RivalApproachPlayer7
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	goto RustboroCity_EventScript_RivalEncounter

RustboroCity_EventScript_RivalEncounter::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, RustboroCity_EventScript_MayEncounter
	goto_if_eq VAR_RESULT, FEMALE, RustboroCity_EventScript_BrendanEncounter
	end

RustboroCity_EventScript_MayEncounter::
	goto_if_set FLAG_DEFEATED_RIVAL_RUSTBORO, RustboroCity_EventScript_MayBrineyHint
	goto_if_set FLAG_MET_RIVAL_RUSTBORO, RustboroCity_EventScript_MayAskToBattle
	setflag FLAG_MET_RIVAL_RUSTBORO
	msgbox RustboroCity_Text_MayHiLetsRegister, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox RustboroCity_Text_RegisteredMay, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_RIVAL_MATCH_CALL
	setvar VAR_RUSTBORO_CITY_STATE, 8
	setvar VAR_ROUTE104_STATE, 2
	setvar VAR_0x8008, 0
	msgbox RustboroCity_Text_MayPassedBrineyWantToBattle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, RustboroCity_EventScript_BattleMay
	msgbox RustboroCity_Text_MayOhHaventRaisedPokemonEnough, MSGBOX_DEFAULT
	call RustboroCity_EventScript_RestoreBgm
	releaseall
	end

RustboroCity_EventScript_MayAskToBattle::
	setvar VAR_0x8008, 1
	msgbox RustboroCity_Text_MayWantToBattle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, RustboroCity_EventScript_BattleMay
	msgbox RustboroCity_Text_MayOhHaventRaisedPokemonEnough, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_EventScript_BattleMay::
	msgbox RustboroCity_Text_MayImNotGoingToLose, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleMayTreecko
	case 1, RustboroCity_EventScript_BattleMayTorchic
	case 2, RustboroCity_EventScript_BattleMayMudkip
	end

RustboroCity_EventScript_MayBrineyHint::
	msgbox RustboroCity_Text_MayMrBrineyHint, MSGBOX_DEFAULT
	call_if_eq VAR_0x8008, 0, RustboroCity_EventScript_RestoreBgm
	releaseall
	end

RustboroCity_EventScript_RestoreBgm::
	savebgm MUS_DUMMY
	fadedefaultbgm
	return

RustboroCity_EventScript_BattleMayTreecko::
	trainerbattle_no_intro TRAINER_MAY_RUSTBORO_TREECKO, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end

RustboroCity_EventScript_BattleMayTorchic::
	trainerbattle_no_intro TRAINER_MAY_RUSTBORO_TORCHIC, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end

RustboroCity_EventScript_BattleMayMudkip::
	trainerbattle_no_intro TRAINER_MAY_RUSTBORO_MUDKIP, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end

RustboroCity_EventScript_BrendanEncounter::
	goto_if_set FLAG_DEFEATED_RIVAL_RUSTBORO, RustboroCity_EventScript_BrendanBrineyHint
	goto_if_set FLAG_MET_RIVAL_RUSTBORO, RustboroCity_EventScript_BrendanAskToBattle
	setflag FLAG_MET_RIVAL_RUSTBORO
	msgbox RustboroCity_Text_BrendanHiLetsRegister, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox RustboroCity_Text_RegisteredBrendan, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_RIVAL_MATCH_CALL
	setvar VAR_RUSTBORO_CITY_STATE, 8
	setvar VAR_ROUTE104_STATE, 2
	msgbox RustboroCity_Text_BrendanPassedBrineyWantToBattle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, RustboroCity_EventScript_BattleBrendan
	msgbox RustboroCity_Text_BrendanNoConfidenceInPokemon, MSGBOX_DEFAULT
	call RustboroCity_EventScript_RestoreBgm
	releaseall
	end

RustboroCity_EventScript_BrendanAskToBattle::
	msgbox RustboroCity_Text_BrendanWantToBattle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, RustboroCity_EventScript_BattleBrendan
	msgbox RustboroCity_Text_BrendanNoConfidenceInPokemon, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_EventScript_BattleBrendan::
	msgbox RustboroCity_Text_BrendanIWontGoEasy, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleBrendanTreecko
	case 1, RustboroCity_EventScript_BattleBrendanTorchic
	case 2, RustboroCity_EventScript_BattleBrendanMudkip
	end

RustboroCity_EventScript_BrendanBrineyHint::
	msgbox RustboroCity_Text_BrendanMrBrineyHint, MSGBOX_DEFAULT
	call_if_eq VAR_0x8008, 0, RustboroCity_EventScript_RestoreBgm
	releaseall
	end

RustboroCity_EventScript_BattleBrendanTreecko::
	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_TREECKO, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

RustboroCity_EventScript_BattleBrendanTorchic::
	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_TORCHIC, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

RustboroCity_EventScript_BattleBrendanMudkip::
	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_MUDKIP, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

RustboroCity_Movement_RivalApproachPlayer0:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

RustboroCity_Movement_RivalApproachPlayer1:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

RustboroCity_Movement_RivalApproachPlayer2:
	walk_down
	walk_left
	walk_left
	walk_down
	step_end

RustboroCity_Movement_RivalApproachPlayer3:
	walk_down
	walk_left
	walk_down
	step_end

RustboroCity_Movement_RivalApproachPlayer4:
	walk_down
	walk_down
	step_end

RustboroCity_Movement_RivalApproachPlayer5:
	walk_down
	walk_right
	walk_down
	step_end

RustboroCity_Movement_RivalApproachPlayer6:
	walk_down
	walk_right
	walk_right
	walk_down
	step_end

RustboroCity_Movement_RivalApproachPlayer7:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	step_end

RustboroCity_EventScript_Boy1::
	msgbox RustboroCity_Text_YouCanHave2On2Battle, MSGBOX_NPC
	end

RustboroCity_Text_WeShortenItToDevon:
	.string "DEVON CORPORATION... Mọi người thường\n"
	.string "gọi tắt là DEVON.\p"
	.string "Công ty đó sản xuất đủ loại sản phẩm\n"
	.string "tiện lợi.$"

RustboroCity_Text_SneakyLookingManWentAroundCorner:
	.string "Hửm? Một người đàn ông trông lén lút\n"
	.string "à?\p"
	.string "Nghĩ lại thì đúng là có một gã khả nghi\n"
	.string "vừa rẽ qua góc đường.$"

RustboroCity_Text_HaveYouChallengedGym:
	.string "Bạn đã thử thách POKéMON GYM chưa?\p"
	.string "Khi cầm GYM BADGE sáng bóng trong tay,\n"
	.string "có lẽ HLV mới bắt đầu hiểu mình\l"
	.string "cần phải làm gì.$"

RustboroCity_Text_HeyThatsRustborosGymBadge:
	.string "Này, đó là GYM BADGE của RUSTBORO!\p"
	.string "Trong tất cả POKéMON GYM BADGES, tôi\n"
	.string "thấy huy hiệu của RUSTBORO là ngầu\l"
	.string "nhất.$"

RustboroCity_Text_YoureNewAroundHere:
	.string "Ồ? Bạn là ai vậy? Trông bạn lạ mặt ở\n"
	.string "vùng này.\p"
	.string "Bạn vừa chuyển vào POKéMON TRAINER'S\n"
	.string "SCHOOL sao?$"

RustboroCity_Text_GymLeaderIsntEasyWithFire:
	.string "Tôi đã thách đấu GYM LEADER, nhưng...\p"
	.string "Sẽ không dễ thắng bằng POKéMON hệ FIRE\n"
	.string "của tôi...\p"
	.string "POKéMON hệ FIRE gặp bất lợi trước\n"
	.string "POKéMON hệ ROCK...$"

RustboroCity_Text_MrBrineyWalksInTheTunnel:
	.string "Ông lão thủy thủ MR. BRINEY sống trong\n"
	.string "một căn nhà nhỏ bên bờ biển.\p"
	.string "Thỉnh thoảng ông ấy lại đi dạo trong\n"
	.string "đường hầm.$"

RustboroCity_Text_MrBrineyLovesPeeko:
	.string "Ông lão thủy thủ MR. BRINEY sống trong\n"
	.string "một căn nhà nhỏ bên bờ biển.\p"
	.string "Ông ấy nói sẽ đến SLATEPORT mua đồ cho\n"
	.string "thú cưng PEEKO.\p"
	.string "Lão sói biển ấy chắc hẳn yêu PEEKO lắm.$"

RustboroCity_Text_WowYouHavePokemon:
	.string "Chà, bạn cũng có POKéMON đi cùng.\p"
	.string "Khi lớn lên, mình cũng sẽ cùng POKéMON\n"
	.string "đi khắp nơi.$"

RustboroCity_Text_CatchRarePokemonIfIGoToSchool:
	.string "POKéMON TRAINER'S SCHOOL!\p"
	.string "Nếu học ở đây, mình có thể dễ dàng bắt\n"
	.string "được POKéMON hiếm không nhỉ?$"

RustboroCity_Text_PokemonCanChangeLookFromExp:
	.string "Khi một POKéMON tích lũy kinh nghiệm\n"
	.string "qua chiến đấu, đôi khi ngoại hình của nó\l"
	.string "sẽ thay đổi.$"

RustboroCity_Text_PokemonChangeShape:
	.string "Một POKéMON thay đổi hình dạng ư? Nếu\n"
	.string "thấy vậy, mình sẽ sốc lắm!$"

RustboroCity_Text_TradePokemonGrowFast:
	.string "POKéMON bạn nhận được qua trao đổi\n"
	.string "với người khác sẽ trưởng thành nhanh.\p"
	.string "Nhưng nếu bạn chưa có một số GYM\n"
	.string "BADGES nhất định, nó có thể không nghe\l"
	.string "lời...$"

RustboroCity_Text_OutOfTheWay:
	.string "Tránh ra! Tránh đường!$"

RustboroCity_Text_WaitDontTakeMyGoods:
	.string "Khoan đã! Làm ơơơn!\p"
	.string "Đừng lấy GOODS của tôi!$"

RustboroCity_Text_HelpMeIWasRobbed:
	.string "Ồ, là bạn!\p"
	.string "Bạn chính là HLV tuyệt vời đã giúp\n"
	.string "tôi trong PETALBURG WOODS!\p"
	.string "Cứu tôi với! TEAM AQUA đã cướp đồ của\n"
	.string "tôi! Tôi phải lấy lại DEVON GOODS!\p"
	.string "Nếu không... tôi sẽ gặp rắc rối lớn mất.$"

RustboroCity_Text_ShadyCharacterTookOffTowardsTunnel:
	.string "Tôi nghĩ gã khả nghi đó đã chạy về phía\n"
	.string "đường hầm đằng kia.$"

RustboroCity_Text_YouGotItThankYou:
	.string "Ồ! Chuyện thế nào rồi? Còn DEVON GOODS?\p"
	.string "Bạn làm được rồi! Bạn đã lấy lại chúng!\p"
	.string "Bạn đúng là một HLV tuyệt vời!\p"
	.string "Phải rồi! Để cảm ơn, tôi sẽ tặng bạn\n"
	.string "thêm một GREAT BALL!$"

RustboroCity_Text_YoureLoadedWithItems:
	.string "Bạn mang quá nhiều đồ rồi. Tôi không thể\n"
	.string "đưa GREAT BALL này cho bạn.$"

RustboroCity_Text_PleaseComeWithMe:
	.string "Xin thứ lỗi! Phiền bạn đi cùng tôi!$"

RustboroCity_Text_MayHiLetsRegister:
	.string "MAY: Ồ, chào {PLAYER}{KUN}!\p"
	.string "Cậu đã được cài tính năng MATCH CALL\n"
	.string "vào POKéNAV rồi!\p"
	.string "Hãy đăng ký nhau để chúng ta có thể\n"
	.string "liên lạc bất cứ lúc nào nhé!\p"
	.string "... ... ... ... ... ...$"

RustboroCity_Text_RegisteredMay:
	.string "Đã đăng ký MAY vào POKéNAV.$"

RustboroCity_Text_MayPassedBrineyWantToBattle:
	.string "MAY: À, tớ vừa đi ngang qua MR. BRINEY\n"
	.string "trong PETALBURG WOODS.\p"
	.string "Chắc ông ấy đang về căn nhà nhỏ bên bờ\n"
	.string "biển.\p"
	.string "POKéDEX của cậu tiến triển thế nào rồi,\n"
	.string "{PLAYER}{KUN}? Của tớ khá ổn đấy!\p"
	.string "Vậy... đấu một trận ngắn nhé?$"

RustboroCity_Text_MayOhHaventRaisedPokemonEnough:
	.string "MAY: Ồ, có chuyện gì vậy?\p"
	.string "Cậu chưa bắt hay rèn luyện POKéMON\n"
	.string "được bao nhiêu à?\p"
	.string "Như thế không ổn với một HLV đâu!$"

RustboroCity_Text_MayWantToBattle:
	.string "MAY: Cậu thấy sao? Đấu một trận ngắn\n"
	.string "ngay tại đây nhé?$"

RustboroCity_Text_MayImNotGoingToLose:
	.string "MAY: Cậu chỉ vừa trở thành HLV\n"
	.string "thôi, {PLAYER}{KUN}. Tớ sẽ không thua\l"
	.string "đâu!$"

RustboroCity_Text_MayDefeat:
	.string "Ôi! Cậu giỏi hơn tớ tưởng đấy!$"

RustboroCity_Text_MayMrBrineyHint:
	.string "MAY: À, còn MR. BRINEY mà tớ vừa đi\n"
	.string "ngang qua...\p"
	.string "{PLAYER}{KUN}, cậu mới chuyển đến nên\n"
	.string "có thể chưa biết, nhưng MR. BRINEY\l"
	.string "từng là một thủy thủ được mọi người\l"
	.string "kính trọng.$"

RustboroCity_Text_BrendanHiLetsRegister:
	.string "BRENDAN: Ồ, chào {PLAYER}!\p"
	.string "Cậu đã được cài tính năng MATCH CALL\n"
	.string "vào POKéNAV rồi! Hay đấy!\p"
	.string "Hãy đăng ký nhau để chúng ta có thể\n"
	.string "liên lạc bất cứ lúc nào!\p"
	.string "... ... ... ... ... ...$"

RustboroCity_Text_RegisteredBrendan:
	.string "Đã đăng ký BRENDAN vào POKéNAV.$"

RustboroCity_Text_BrendanPassedBrineyWantToBattle:
	.string "BRENDAN: À, {PLAYER}, tớ vừa đi ngang\n"
	.string "qua MR. BRINEY trong PETALBURG WOODS.\p"
	.string "Chắc ông ấy đang về căn nhà nhỏ bên bờ\n"
	.string "biển.\p"
	.string "{PLAYER}, POKéDEX của cậu thế nào\n"
	.string "rồi? Điền được trang nào chưa?\p"
	.string "Của tớ chất lắm.\p"
	.string "Muốn đấu một trận để xem cậu đã tiến bộ\n"
	.string "đến đâu không?$"

RustboroCity_Text_BrendanNoConfidenceInPokemon:
	.string "BRENDAN: Sao vậy? Cậu không tự tin vào\n"
	.string "POKéMON của mình à?$"

RustboroCity_Text_BrendanWantToBattle:
	.string "BRENDAN: Sao nào? Muốn đấu với tớ một\n"
	.string "trận không?$"

RustboroCity_Text_BrendanIWontGoEasy:
	.string "BRENDAN: Tớ biết cậu chỉ vừa trở thành\n"
	.string "HLV, nhưng tớ sẽ không nương tay\l"
	.string "đâu!$"

RustboroCity_Text_BrendanDefeat:
	.string "Hừm... Cậu khá giỏi đấy.$"

RustboroCity_Text_BrendanMrBrineyHint:
	.string "BRENDAN: À, cậu biết MR. BRINEY chứ?\n"
	.string "Người tớ vừa đi ngang qua ấy?\p"
	.string "Cậu mới chuyển đến nên chắc chưa biết\n"
	.string "đâu, {PLAYER}, nhưng MR. BRINEY từng\l"
	.string "là một thủy thủ cừ khôi.$"

RustboroCity_Text_TunnelNearingCompletion:
	.string "“Đường hầm tiết kiệm thời gian sắp\n"
	.string "hoàn thành!”\p"
	.string "...Trên biển ghi như vậy, nhưng còn có\n"
	.string "một dấu “X” lớn được sơn màu đỏ chói\l"
	.string "đè lên...$"

RustboroCity_Text_DevonCorpSign:
	.string "DEVON CORPORATION\p"
	.string "“Đáp ứng mọi nhu cầu cuộc sống, chúng\n"
	.string "tôi làm ra tất cả.”$"

RustboroCity_Text_GymSign:
	.string "RUSTBORO CITY POKéMON GYM LEADER:\n"
	.string "ROXANNE\p"
	.string "“Học sinh ưu tú yêu ROCK!”$"

RustboroCity_Text_DevonCorpBranchOfficeSign:
	.string "DEVON CORP. BRANCH OFFICE\p"
	.string "“Chỉ nhân viên DEVON và người được ủy\n"
	.string "quyền mới được vào.”$"

RustboroCity_Text_CitySign:
	.string "RUSTBORO CITY\p"
	.string "“Thành phố nghiên cứu sự kết hợp giữa\n"
	.string "thiên nhiên và khoa học.”$"

RustboroCity_Text_TrainersSchoolSign:
	.string "POKéMON TRAINER'S SCHOOL\p"
	.string "“Chúng tôi sẽ dạy bạn mọi điều về\n"
	.string "POKéMON!”$"

RustboroCity_Text_CuttersHouse:
	.string "CUTTER'S HOUSE$"

RustboroCity_Text_DevelopedNewPokenavFeature:
	.string "Tôi đã phát triển một tính năng bổ sung\n"
	.string "cho POKéNAV...\p"
	.string "Và kết quả thật tuyệt!\p"
	.string "{PLAYER}, cho tôi xem chiếc POKéNAV\n"
	.string "được không? Chiếc mà PRESIDENT đã\l"
	.string "tặng bạn ấy?$"

RustboroCity_Text_AddedMatchCallPleaseCallMrStone:
	.string "Xong rồi, {PLAYER}!\p"
	.string "Tôi đã thêm một tính năng mới tên là\n"
	.string "MATCH CALL vào POKéNAV của bạn.\p"
	.string "Với tính năng MATCH CALL, bạn có thể\n"
	.string "trò chuyện với những người đã được\l"
	.string "đăng ký trong POKéNAV.\p"
	.string "{PLAYER}, PRESIDENT STONE của chúng\n"
	.string "tôi hẳn đã được đăng ký trong POKéNAV\l"
	.string "của bạn.\p"
	.string "Hãy thử xem. Phiền bạn gọi cho\n"
	.string "PRESIDENT của chúng tôi.$"

RustboroCity_Text_PleaseSelectPokenav:
	.string "Vui lòng chọn POKéNAV.$"

RustboroCity_Text_IdBetterGetBackToWork:
	.string "Được rồi, tôi nên quay lại làm việc. Hãy\n"
	.string "bảo trọng nhé, {PLAYER}!$"

RustboroCity_Text_YouCanHave2On2Battle:
	.string "Bạn có biết điều này không?\p"
	.string "Bạn có thể đấu trận 2 đấu 2 ngay cả khi\n"
	.string "không đi cùng một HLV khác.\p"
	.string "Nếu bạn chạm mắt với hai HLV khi\n"
	.string "có ít nhất hai POKéMON, cả hai người đó\l"
	.string "sẽ thách đấu bạn.\p"
	.string "Một mình đánh bại hai HLV, chẳng\n"
	.string "phải rất ngầu sao?$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global RustboroCity_Text_WeShortenItToDevon
	.global RustboroCity_Text_SneakyLookingManWentAroundCorner
	.global RustboroCity_Text_HaveYouChallengedGym
	.global RustboroCity_Text_HeyThatsRustborosGymBadge
	.global RustboroCity_Text_YoureNewAroundHere
	.global RustboroCity_Text_GymLeaderIsntEasyWithFire
	.global RustboroCity_Text_MrBrineyWalksInTheTunnel
	.global RustboroCity_Text_MrBrineyLovesPeeko
	.global RustboroCity_Text_WowYouHavePokemon
	.global RustboroCity_Text_CatchRarePokemonIfIGoToSchool
	.global RustboroCity_Text_PokemonCanChangeLookFromExp
	.global RustboroCity_Text_PokemonChangeShape
	.global RustboroCity_Text_TradePokemonGrowFast
	.global RustboroCity_Text_OutOfTheWay
	.global RustboroCity_Text_WaitDontTakeMyGoods
	.global RustboroCity_Text_HelpMeIWasRobbed
	.global RustboroCity_Text_ShadyCharacterTookOffTowardsTunnel
	.global RustboroCity_Text_YouGotItThankYou
	.global RustboroCity_Text_YoureLoadedWithItems
	.global RustboroCity_Text_PleaseComeWithMe
	.global RustboroCity_Text_MayHiLetsRegister
	.global RustboroCity_Text_RegisteredMay
	.global RustboroCity_Text_MayPassedBrineyWantToBattle
	.global RustboroCity_Text_MayOhHaventRaisedPokemonEnough
	.global RustboroCity_Text_MayWantToBattle
	.global RustboroCity_Text_MayImNotGoingToLose
	.global RustboroCity_Text_MayDefeat
	.global RustboroCity_Text_MayMrBrineyHint
	.global RustboroCity_Text_BrendanHiLetsRegister
	.global RustboroCity_Text_RegisteredBrendan
	.global RustboroCity_Text_BrendanPassedBrineyWantToBattle
	.global RustboroCity_Text_BrendanNoConfidenceInPokemon
	.global RustboroCity_Text_BrendanWantToBattle
	.global RustboroCity_Text_BrendanIWontGoEasy
	.global RustboroCity_Text_BrendanDefeat
	.global RustboroCity_Text_BrendanMrBrineyHint
	.global RustboroCity_Text_TunnelNearingCompletion
	.global RustboroCity_Text_DevonCorpSign
	.global RustboroCity_Text_GymSign
	.global RustboroCity_Text_DevonCorpBranchOfficeSign
	.global RustboroCity_Text_CitySign
	.global RustboroCity_Text_TrainersSchoolSign
	.global RustboroCity_Text_DevelopedNewPokenavFeature
	.global RustboroCity_Text_AddedMatchCallPleaseCallMrStone
	.global RustboroCity_Text_PleaseSelectPokenav
	.global RustboroCity_Text_IdBetterGetBackToWork
	.global RustboroCity_Text_YouCanHave2On2Battle
@ END GENERATED LOCALIZATION EXPORTS
