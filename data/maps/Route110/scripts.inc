Route110_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Route110_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route110_OnFrame
	.byte 0

Route110_OnResume:
	special UpdateCyclingRoadState
	end

Route110_OnTransition:
	call Common_EventScript_SetupRivalGfxId
	call Common_EventScript_SetupRivalOnBikeGfxId
	call_if_eq VAR_CYCLING_CHALLENGE_STATE, 1, Route110_EventScript_SaveCyclingMusic
	end

Route110_EventScript_SaveCyclingMusic::
	savebgm MUS_CYCLING
	return

Route110_OnFrame:
	map_script_2 VAR_CYCLING_CHALLENGE_STATE, 1, Route110_EventScript_BeginCylcingRoadChallenge
	.2byte 0

Route110_EventScript_BeginCylcingRoadChallenge::
	special Special_BeginCyclingRoadChallenge
	setvar VAR_CYCLING_CHALLENGE_STATE, 2
	return

Route110_EventScript_AquaGrunt1::
	lock
	faceplayer
	msgbox Route110_Text_WeCantTalkAboutAquaActivities, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Route110_EventScript_AquaGrunt2::
	lock
	faceplayer
	msgbox Route110_Text_KickUpARuckus, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Route110_EventScript_AquaGrunt3::
	lock
	faceplayer
	msgbox Route110_Text_MyFirstJobInAqua, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Route110_EventScript_AquaGrunt4::
	lock
	faceplayer
	msgbox Route110_Text_AquaActionsBringSmiles, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Route110_EventScript_Boy1::
	msgbox Route110_Text_RideBikeAtFullSpeed, MSGBOX_NPC
	end

Route110_EventScript_CyclingGirl1::
	msgbox Route110_Text_HairStreamsBehindMe, MSGBOX_NPC
	end

Route110_EventScript_CyclingGuy1::
	msgbox Route110_Text_YouGotBikeFromRydel, MSGBOX_NPC
	end

Route110_EventScript_OldMan::
	msgbox Route110_Text_TwoRoads, MSGBOX_NPC
	end

Route110_EventScript_OldWoman::
	msgbox Route110_Text_WalkOnTheLowRoad, MSGBOX_NPC
	end

Route110_EventScript_CyclingGuy2::
	msgbox Route110_Text_BikeTechniques, MSGBOX_NPC
	end

Route110_EventScript_Boy2::
	msgbox Route110_Text_WhichShouldIChoose, MSGBOX_NPC
	end

Route110_EventScript_SlateportCitySign::
	msgbox Route110_Text_SlateportCitySign, MSGBOX_SIGN
	end

Route110_EventScript_CyclingRoadSign::
	msgbox Route110_Text_CyclingRoadSign, MSGBOX_SIGN
	end

Route110_EventScript_VandalizedSign::
	msgbox Route110_Text_AquaWasHere, MSGBOX_SIGN
	end

Route110_EventScript_Route103Sign::
	msgbox Route110_Text_Route103Sign, MSGBOX_SIGN
	end

Route110_EventScript_SeasideParkingSign::
	msgbox Route110_Text_SeasideParkingSign, MSGBOX_SIGN
	end

Route110_EventScript_MauvilleCitySign::
	msgbox Route110_Text_MauvilleCitySign, MSGBOX_SIGN
	end

Route110_EventScript_TrainerTipsPrlzSleep::
	msgbox Route110_Text_TrainerTipsPrlzSleep, MSGBOX_SIGN
	end

Route110_EventScript_TrainerTipsRegisterItems::
	msgbox Route110_Text_TrainerTipsRegisterItems, MSGBOX_SIGN
	end

Route110_EventScript_TrickHouseSign::
	msgbox Route110_Text_TrickHouseSign, MSGBOX_SIGN
	end

Route110_EventScript_CyclingRoadResultsSign::
	lockall
	specialvar VAR_RESULT, GetRecordedCyclingRoadResults
	goto_if_eq VAR_RESULT, FALSE, Route110_EventScript_NoRecordSet
	msgbox Route110_Text_BestRecord, MSGBOX_DEFAULT
	releaseall
	end

Route110_EventScript_NoRecordSet::
	msgbox Route110_Text_ThereIsNoRecord, MSGBOX_DEFAULT
	releaseall
	end

Route110_EventScript_ChallengeGuy::
	lock
	faceplayer
	specialvar VAR_RESULT, GetPlayerAvatarBike
	goto_if_eq VAR_RESULT, 1, Route110_EventScript_PlayerRidingAcroBike
	goto_if_eq VAR_CYCLING_CHALLENGE_STATE, 0, Route110_EventScript_PlayerNotRidingBike
	msgbox Route110_Text_AlwaysAimHigher, MSGBOX_DEFAULT
	release
	end

Route110_EventScript_PlayerNotRidingBike::
	msgbox Route110_Text_RatedForNumberOfCollisions, MSGBOX_DEFAULT
	release
	end

Route110_EventScript_PlayerRidingAcroBike::
	msgbox Route110_Text_AcroBikesDoNotQualify, MSGBOX_DEFAULT
	release
	end

Route110_EventScript_Edward::
	trainerbattle_single TRAINER_EDWARD, Route110_Text_EdwardIntro, Route110_Text_EdwardDefeated
	msgbox Route110_Text_EdwardPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Jaclyn::
	trainerbattle_single TRAINER_JACLYN, Route110_Text_JaclynIntro, Route110_Text_JaclynDefeated
	msgbox Route110_Text_JaclynPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Edwin::
	trainerbattle_single TRAINER_EDWIN_1, Route110_Text_EdwinIntro, Route110_Text_EdwinDefeated, Route110_EventScript_EdwinRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route110_EventScript_EdwinRematch
	msgbox Route110_Text_EdwinPostBattle, MSGBOX_DEFAULT
	release
	end

Route110_EventScript_EdwinRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route110_Text_EdwinRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_EDWIN_1
	release
	end

Route110_EventScript_EdwinRematch::
	trainerbattle_rematch TRAINER_EDWIN_1, Route110_Text_EdwinRematchIntro, Route110_Text_EdwinRematchDefeated
	msgbox Route110_Text_EdwinRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Dale::
	trainerbattle_single TRAINER_DALE, Route110_Text_DaleIntro, Route110_Text_DaleDefeated
	msgbox Route110_Text_DalePostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Jacob::
	trainerbattle_single TRAINER_JACOB, Route110_Text_JacobIntro, Route110_Text_JacobDefeated
	msgbox Route110_Text_JacobPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Anthony::
	trainerbattle_single TRAINER_ANTHONY, Route110_Text_AnthonyIntro, Route110_Text_AnthonyDefeated
	msgbox Route110_Text_AnthonyPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Benjamin::
	trainerbattle_single TRAINER_BENJAMIN_1, Route110_Text_BenjaminIntro, Route110_Text_BenjaminDefeated, Route110_EventScript_BenjaminRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route110_EventScript_BenjaminRematch
	msgbox Route110_Text_BenjaminPostBattle, MSGBOX_DEFAULT
	release
	end

Route110_EventScript_BenjaminRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route110_Text_BenjaminRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_BENJAMIN_1
	release
	end

Route110_EventScript_BenjaminRematch::
	trainerbattle_rematch TRAINER_BENJAMIN_1, Route110_Text_BenjaminRematchIntro, Route110_Text_BenjaminRematchDefeated
	msgbox Route110_Text_BenjaminRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Jasmine::
	trainerbattle_single TRAINER_JASMINE, Route110_Text_JasmineIntro, Route110_Text_JasmineDefeated
	msgbox Route110_Text_JasminePostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Abigail::
	trainerbattle_single TRAINER_ABIGAIL_1, Route110_Text_AbigailIntro, Route110_Text_AbigailDefeated, Route110_EventScript_AbigailRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route110_EventScript_AbigailRematch
	msgbox Route110_Text_AbigailPostBattle, MSGBOX_DEFAULT
	release
	end

Route110_EventScript_AbigailRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route110_Text_AbigailRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ABIGAIL_1
	release
	end

Route110_EventScript_AbigailRematch::
	trainerbattle_rematch TRAINER_ABIGAIL_1, Route110_Text_AbigailRematchIntro, Route110_Text_AbigailRematchDefeated
	msgbox Route110_Text_AbigailRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Isabel::
	trainerbattle_single TRAINER_ISABEL_1, Route110_Text_IsabelIntro, Route110_Text_IsabelDefeated, Route110_EventScript_IsabelRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route110_EventScript_IsabelRematch
	msgbox Route110_Text_IsabelPostBattle, MSGBOX_DEFAULT
	release
	end

Route110_EventScript_IsabelRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route110_Text_IsabelRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ISABEL_1
	release
	end

Route110_EventScript_IsabelRematch::
	trainerbattle_rematch TRAINER_ISABEL_1, Route110_Text_IsabelRematchIntro, Route110_Text_IsabelRematchDefeated
	msgbox Route110_Text_IsabelRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Timmy::
	trainerbattle_single TRAINER_TIMMY, Route110_Text_TimmyIntro, Route110_Text_TimmyDefeated
	msgbox Route110_Text_TimmyPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Unused::
	end

Route110_EventScript_Kaleb::
	trainerbattle_single TRAINER_KALEB, Route110_Text_KalebIntro, Route110_Text_KalebDefeated
	msgbox Route110_Text_KalebPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Joseph::
	trainerbattle_single TRAINER_JOSEPH, Route110_Text_JosephIntro, Route110_Text_JosephDefeated
	msgbox Route110_Text_JosephPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Alyssa::
	trainerbattle_single TRAINER_ALYSSA, Route110_Text_AlyssaIntro, Route110_Text_AlyssaDefeated
	msgbox Route110_Text_AlyssaPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_CyclingChallengeEnd::
	lockall
	applymovement LOCALID_CHALLENGE_BIKER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	call Route110_EventScript_CyclingChallengeResults
	releaseall
	end

Route110_EventScript_CyclingChallengeResults::
	special FinishCyclingRoadChallenge
	msgbox Route110_Text_CyclingChallengeResultSummary, MSGBOX_DEFAULT
	switch VAR_RESULT
	case 10, Route110_EventScript_ChallengeReactionBest
	case 9, Route110_EventScript_ChallengeReactionGood
	case 8, Route110_EventScript_ChallengeReactionGood
	case 7, Route110_EventScript_ChallengeReactionGood
	case 6, Route110_EventScript_ChallengeReactionOk
	case 5, Route110_EventScript_ChallengeReactionOk
	case 4, Route110_EventScript_ChallengeReactionOk
	case 3, Route110_EventScript_ChallengeReactionBad
	case 2, Route110_EventScript_ChallengeReactionBad
	case 1, Route110_EventScript_ChallengeReactionBad
	case 0, Route110_EventScript_ChallengeReactionWorst
	end

Route110_EventScript_ChallengeReactionBest::
	msgbox Route110_Text_ChallengeReactionBest, MSGBOX_DEFAULT
	goto Route110_EventScript_EndChallenge
	end

Route110_EventScript_ChallengeReactionGood::
	msgbox Route110_Text_ChallengeReactionGood, MSGBOX_DEFAULT
	goto Route110_EventScript_EndChallenge
	end

Route110_EventScript_ChallengeReactionOk::
	msgbox Route110_Text_ChallengeReactionOk, MSGBOX_DEFAULT
	goto Route110_EventScript_EndChallenge
	end

Route110_EventScript_ChallengeReactionBad::
	msgbox Route110_Text_ChallengeReactionBad, MSGBOX_DEFAULT
	goto Route110_EventScript_EndChallenge
	end

Route110_EventScript_ChallengeReactionWorst::
	msgbox Route110_Text_ChallengeReactionWorst, MSGBOX_DEFAULT
	goto Route110_EventScript_EndChallenge
	end

Route110_EventScript_EndChallenge::
	setvar VAR_CYCLING_CHALLENGE_STATE, 3
	savebgm MUS_DUMMY
	fadedefaultbgm
	return

Route110_EventScript_RivalTrigger1::
	setvar VAR_0x8008, 1
	goto Route110_EventScript_RivalScene
	end

Route110_EventScript_RivalTrigger2::
	setvar VAR_0x8008, 2
	goto Route110_EventScript_RivalScene
	end

Route110_EventScript_RivalTrigger3::
	setvar VAR_0x8008, 3
	goto Route110_EventScript_RivalScene
	end

Route110_EventScript_RivalScene::
	lockall
	checkplayergender
	call_if_eq VAR_RESULT, MALE, Route110_EventScript_PlayMayMusic
	call_if_eq VAR_RESULT, FEMALE, Route110_EventScript_PlayBrendanMusic
	applymovement LOCALID_ROUTE110_RIVAL, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	applymovement LOCALID_ROUTE110_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_ROUTE110_RIVAL, Common_Movement_Delay48
	waitmovement 0
	delay 30
	call_if_eq VAR_0x8008, 1, Route110_EventScript_RivalApproachPlayer1
	call_if_eq VAR_0x8008, 2, Route110_EventScript_RivalApproachPlayer2
	call_if_eq VAR_0x8008, 3, Route110_EventScript_RivalApproachPlayer3
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, Route110_EventScript_MayBattle
	goto_if_eq VAR_RESULT, FEMALE, Route110_EventScript_BrendanBattle
	releaseall
	end

Route110_EventScript_PlayMayMusic::
	playbgm MUS_ENCOUNTER_MAY, TRUE
	return

Route110_EventScript_PlayBrendanMusic::
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	return

Route110_EventScript_MayBattle::
	msgbox Route110_Text_MayLetsBattle, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route110_EventScript_MayBattleTreecko
	case 1, Route110_EventScript_MayBattleTorchic
	case 2, Route110_EventScript_MayBattleMudkip
	end

Route110_EventScript_MayBattleTreecko::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_110_TREECKO, Route110_Text_MayDefeated
	goto Route110_EventScript_MayDefeated
	end

Route110_EventScript_MayBattleTorchic::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_110_TORCHIC, Route110_Text_MayDefeated
	goto Route110_EventScript_MayDefeated
	end

Route110_EventScript_MayBattleMudkip::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_110_MUDKIP, Route110_Text_MayDefeated
	goto Route110_EventScript_MayDefeated
	end

Route110_EventScript_MayDefeated::
	msgbox Route110_Text_MayTakeThis, MSGBOX_DEFAULT
	call Route110_EventScript_GiveItemfinder
	msgbox Route110_Text_MayExplainItemfinder, MSGBOX_DEFAULT
	goto Route110_EventScript_RivalExit
	end

Route110_EventScript_BrendanBattle::
	msgbox Route110_Text_BrendanLetsBattle, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route110_EventScript_BrendanBattleTreecko
	case 1, Route110_EventScript_BrendanBattleTorchic
	case 2, Route110_EventScript_BrendanBattleMudkip
	end

Route110_EventScript_BrendanBattleTreecko::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_110_TREECKO, Route110_Text_BrendanDefeated
	goto Route110_EventScript_BrendanDefeated
	end

Route110_EventScript_BrendanBattleTorchic::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_110_TORCHIC, Route110_Text_BrendanDefeated
	goto Route110_EventScript_BrendanDefeated
	end

Route110_EventScript_BrendanBattleMudkip::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_110_MUDKIP, Route110_Text_BrendanDefeated
	goto Route110_EventScript_BrendanDefeated
	end

Route110_EventScript_BrendanDefeated::
	msgbox Route110_Text_BrendanTakeThis, MSGBOX_DEFAULT
	call Route110_EventScript_GiveItemfinder
	msgbox Route110_Text_BrendanExplainItemfinder, MSGBOX_DEFAULT
	goto Route110_EventScript_RivalExit
	end

Route110_EventScript_GiveItemfinder::
	giveitem ITEM_ITEMFINDER
	return

Route110_EventScript_RivalExit::
	closemessage
	call_if_eq VAR_0x8008, 1, Route110_EventScript_MoveRival1
	call_if_eq VAR_0x8008, 2, Route110_EventScript_MoveRival2
	call_if_eq VAR_0x8008, 3, Route110_EventScript_MoveRival3
	setobjectmovementtype LOCALID_ROUTE110_RIVAL, MOVEMENT_TYPE_FACE_RIGHT
	setobjectmovementtype LOCALID_ROUTE110_RIVAL_ON_BIKE, MOVEMENT_TYPE_FACE_RIGHT
	removeobject LOCALID_ROUTE110_RIVAL
	addobject LOCALID_ROUTE110_RIVAL_ON_BIKE
	delay 45
	call_if_eq VAR_0x8008, 1, Route110_EventScript_RivalExit1
	call_if_eq VAR_0x8008, 2, Route110_EventScript_RivalExit2
	call_if_eq VAR_0x8008, 3, Route110_EventScript_RivalExit3
	removeobject LOCALID_ROUTE110_RIVAL_ON_BIKE
	setvar VAR_ROUTE110_STATE, 1
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

Route110_EventScript_RivalApproachPlayer1::
	applymovement LOCALID_ROUTE110_RIVAL, Route110_Movement_RivalApproachPlayer1
	waitmovement 0
	return

Route110_EventScript_RivalApproachPlayer2::
	applymovement LOCALID_ROUTE110_RIVAL, Route110_Movement_RivalApproachPlayer2
	waitmovement 0
	return

Route110_EventScript_RivalApproachPlayer3::
	applymovement LOCALID_ROUTE110_RIVAL, Route110_Movement_RivalApproachPlayer3
	waitmovement 0
	return

Route110_EventScript_RivalExit1::
	applymovement LOCALID_ROUTE110_RIVAL_ON_BIKE, Route110_Movement_RivalExit1
	waitmovement 0
	return

Route110_EventScript_RivalExit2::
	applymovement LOCALID_ROUTE110_RIVAL_ON_BIKE, Route110_Movement_RivalExit2
	waitmovement 0
	return

Route110_EventScript_RivalExit3::
	applymovement LOCALID_ROUTE110_RIVAL_ON_BIKE, Route110_Movement_RivalExit3
	waitmovement 0
	return

Route110_EventScript_MoveRival1::
	setobjectxyperm LOCALID_ROUTE110_RIVAL_ON_BIKE, 33, 55
	return

Route110_EventScript_MoveRival2::
	setobjectxyperm LOCALID_ROUTE110_RIVAL_ON_BIKE, 34, 55
	return

Route110_EventScript_MoveRival3::
	setobjectxyperm LOCALID_ROUTE110_RIVAL_ON_BIKE, 35, 55
	return

Route110_Movement_RivalApproachPlayer1:
	walk_down
	walk_left
	walk_in_place_faster_down
	step_end

Route110_Movement_RivalApproachPlayer2:
	walk_down
	step_end

Route110_Movement_RivalApproachPlayer3:
	walk_down
	walk_right
	walk_in_place_faster_down
	step_end

Route110_Movement_RivalExit1:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

Route110_Movement_RivalExit2:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_down
	step_end

Route110_Movement_RivalExit3:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

Route110_EventScript_BirchScene1::
	lockall
	setvar VAR_0x8008, 1
	goto Route110_EventScript_BirchScene

Route110_EventScript_BirchScene2::
	lockall
	setvar VAR_0x8008, 2
	goto Route110_EventScript_BirchScene

Route110_EventScript_BirchScene3::
	lockall
	setvar VAR_0x8008, 3
	goto Route110_EventScript_BirchScene

Route110_EventScript_BirchScene4::
	lockall
	setvar VAR_0x8008, 4
	goto Route110_EventScript_BirchScene

Route110_EventScript_BirchScene::
	addobject LOCALID_ROUTE110_BIRCH
	applymovement LOCALID_ROUTE110_BIRCH, Route110_Movement_BirchEntrance
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_ROUTE110_BIRCH, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_ROUTE110_BIRCH, Common_Movement_Delay48
	waitmovement 0
	call_if_eq VAR_0x8008, 1, Route110_EventScript_BirchApproachPlayer1
	call_if_eq VAR_0x8008, 2, Route110_EventScript_BirchApproachPlayer2
	call_if_eq VAR_0x8008, 3, Route110_EventScript_BirchApproachPlayer3
	call_if_eq VAR_0x8008, 4, Route110_EventScript_BirchApproachPlayer4
	msgbox Route110_Text_ImagineSeeingYouHere, MSGBOX_DEFAULT
	closemessage
	delay 20
	applymovement LOCALID_ROUTE110_BIRCH, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	delay 10
	applymovement LOCALID_ROUTE110_BIRCH, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 20
	applymovement LOCALID_ROUTE110_BIRCH, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 30
	msgbox Route110_Text_HeardYouInstallMatchCall, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox Route110_Text_RegisteredBirchInPokenav, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_PROF_BIRCH_MATCH_CALL
	msgbox Route110_Text_KeepAnEyeOutForRival, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_0x8008, 1, Route110_EventScript_BirchExit1
	call_if_eq VAR_0x8008, 2, Route110_EventScript_BirchExit2
	call_if_eq VAR_0x8008, 3, Route110_EventScript_BirchExit3
	call_if_eq VAR_0x8008, 4, Route110_EventScript_BirchExit4
	removeobject LOCALID_ROUTE110_BIRCH
	setvar VAR_REGISTER_BIRCH_STATE, 2
	releaseall
	end

Route110_EventScript_BirchApproachPlayer1::
	applymovement LOCALID_ROUTE110_BIRCH, Route110_Movement_BirchApproachPlayer1
	waitmovement 0
	return

Route110_EventScript_BirchApproachPlayer2::
	applymovement LOCALID_ROUTE110_BIRCH, Route110_Movement_BirchApproachPlayer2
	waitmovement 0
	return

Route110_EventScript_BirchApproachPlayer3::
	applymovement LOCALID_ROUTE110_BIRCH, Route110_Movement_BirchApproachPlayer3
	waitmovement 0
	return

Route110_EventScript_BirchApproachPlayer4::
	applymovement LOCALID_ROUTE110_BIRCH, Route110_Movement_BirchApproachPlayer4
	waitmovement 0
	return

Route110_EventScript_BirchExit1::
	applymovement LOCALID_ROUTE110_BIRCH, Route110_Movement_BirchExit1
	waitmovement 0
	return

Route110_EventScript_BirchExit2::
	applymovement LOCALID_ROUTE110_BIRCH, Route110_Movement_BirchExit2
	waitmovement 0
	return

Route110_EventScript_BirchExit3::
	applymovement LOCALID_ROUTE110_BIRCH, Route110_Movement_BirchExit3
	waitmovement 0
	return

Route110_EventScript_BirchExit4::
	applymovement LOCALID_ROUTE110_BIRCH, Route110_Movement_BirchExit4
	waitmovement 0
	return

Route110_Movement_BirchEntrance:
	walk_down
	walk_down
	walk_down
	step_end

Route110_Movement_BirchApproachPlayer1:
	walk_down
	walk_left
	walk_left
	walk_down
	step_end

Route110_Movement_BirchApproachPlayer2:
	walk_down
	walk_left
	walk_down
	step_end

Route110_Movement_BirchApproachPlayer3:
	walk_down
	walk_down
	step_end

Route110_Movement_BirchApproachPlayer4:
	walk_down
	walk_right
	walk_down
	step_end

Route110_Movement_BirchExit1:
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	step_end

Route110_Movement_BirchExit2:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Route110_Movement_BirchExit3:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Route110_Movement_BirchExit4:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Route110_Text_WeCantTalkAboutAquaActivities:
	.string "Các hoạt động của TEAM AQUA... Bọn ta\n"
	.string "chưa thể nói về chúng.$"

Route110_Text_KickUpARuckus:
	.string "Ta muốn tới SLATEPORT ngay và quậy một\n"
	.string "trận ra trò!$"

Route110_Text_MyFirstJobInAqua:
	.string "Đây là nhiệm vụ đầu tiên của tôi sau khi\n"
	.string "gia nhập TEAM AQUA. Hơi đáng sợ thật.$"

Route110_Text_AquaActionsBringSmiles:
	.string "Những việc TEAM AQUA làm phải khiến mọi\n"
	.string "người mỉm cười!$"

Route110_Text_MayLetsBattle:
	.string "MAY: Chào {PLAYER}{KUN}, lâu rồi không\n"
	.string "gặp!\p"
	.string "Trong lúc tìm kiếm những POKéMON khác,\n"
	.string "POKéMON của tớ đã mạnh lên.\p"
	.string "Vậy... Đấu một trận nhé?$"

Route110_Text_MayDefeated:
	.string "Ối! Cậu giỏi hơn tớ tưởng đấy!$"

Route110_Text_MayTakeThis:
	.string "MAY: {PLAYER}{KUN}, cậu cũng bận rộn\n"
	.string "luyện tập nhỉ?\p"
	.string "Tớ nghĩ cậu xứng đáng được thưởng!\n"
	.string "Quà của tớ đấy!$"

Route110_Text_MayExplainItemfinder:
	.string "MAY: Đó là ITEMFINDER.\p"
	.string "Thử dùng xem. Nếu có vật phẩm không\n"
	.string "nhìn thấy được, nó sẽ phát ra âm thanh.\p"
	.string "Được rồi, {PLAYER}{KUN}, hẹn gặp lại\n"
	.string "nhé!\p"
	.string "Tớ nói vậy có lẽ hơi buồn cười, nhưng\n"
	.string "tớ nghĩ lần tới cậu nên luyện tập chăm\l"
	.string "chỉ hơn nhiều.$"

Route110_Text_BrendanLetsBattle:
	.string "BRENDAN: Này, {PLAYER}. Thì ra cậu ở\n"
	.string "đây. Dạo này sao rồi?\p"
	.string "Cậu có chăm nuôi POKéMON không? Để tớ\n"
	.string "kiểm tra cho.$"

Route110_Text_BrendanDefeated:
	.string "Hừm... Cậu khá đấy.$"

Route110_Text_BrendanTakeThis:
	.string "BRENDAN: {PLAYER}, cậu đã luyện tập\n"
	.string "mà tớ không hề nhận ra...\p"
	.string "Khá lắm! Đây, cầm lấy.$"

Route110_Text_BrendanExplainItemfinder:
	.string "BRENDAN: Đó là ITEMFINDER.\p"
	.string "Hãy dùng nó để lục tìm những vật phẩm\n"
	.string "không nhìn thấy được.\p"
	.string "Nếu cảm nhận được thứ gì, nó sẽ phát\n"
	.string "ra âm thanh.\p"
	.string "Dù sao thì tớ cũng đi tìm POKéMON mới\n"
	.string "đây.$"

Route110_Text_RideBikeAtFullSpeed:
	.string "Được phóng hết tốc lực bằng BIKE trên\n"
	.string "CYCLING ROAD thì tuyệt biết mấy nhỉ?$"

Route110_Text_HairStreamsBehindMe:
	.string "Cậu thấy mái tóc đen nhánh của tôi tung\n"
	.string "bay phía sau thế nào?\p"
	.string "Tôi nuôi tóc dài chỉ vì chuyện đó đấy.$"

Route110_Text_YouGotBikeFromRydel:
	.string "Ô, này, cậu lấy chiếc BIKE đó từ RYDEL\n"
	.string "à!\p"
	.string "Ôi, nhìn là biết ngay. Trên xe của cậu\n"
	.string "ghi rõ rành rành...\p"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\n"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\p"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\n"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\p"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\n"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\p"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\n"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\p"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\n"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL... Tên\l"
	.string "ấy có ở khắp nơi.\p"
	.string "Cậu nên đạp nó đi khắp nơi, quảng cáo\n"
	.string "hiệu quả lắm đấy!$"

Route110_Text_TwoRoads:
	.string "Hai con đường, một trên, một dưới...\p"
	.string "Một đường cho người, một đường cho\n"
	.string "POKéMON. Có lẽ như vậy là đúng đắn và\l"
	.string "công bằng.$"

Route110_Text_WalkOnTheLowRoad:
	.string "Tôi không có BIKE, nên sẽ thong thả đi\n"
	.string "bộ trên con đường phía dưới.$"

Route110_Text_BikeTechniques:
	.string "Học các kỹ thuật sẽ khiến việc đi BIKE\n"
	.string "thú vị hơn nữa.\p"
	.string "Có những nơi chỉ có thể đến được bằng\n"
	.string "kỹ thuật đi BIKE.$"

Route110_Text_WhichShouldIChoose:
	.string "Mình nên chọn đường nào đây?\p"
	.string "Đi thẳng tới MAUVILLE qua CYCLING\n"
	.string "ROAD, hay đi đường dưới để tìm\l"
	.string "POKéMON?$"

Route110_Text_CyclingChallengeResultSummary:
	.string "Số lần va chạm: ... ... {STR_VAR_1}!\p"
	.string "Tổng thời gian: ... ... {STR_VAR_2}!$"

Route110_Text_ChallengeReactionBest:
	.string "Hoan hô! Màn thể hiện tuyệt vời!\p"
	.string "Tình yêu đạp xe của cậu xuất phát từ\n"
	.string "sâu thẳm con tim. Cậu đã làm cả tâm hồn\l"
	.string "tôi rung động!$"

Route110_Text_ChallengeReactionGood:
	.string "Kỹ thuật của cậu thật đáng nể.\p"
	.string "Tôi khuyên cậu tăng tốc thêm một chút\n"
	.string "mà vẫn tránh va chạm.$"

Route110_Text_ChallengeReactionOk:
	.string "Tôi cho rằng cậu vẫn đang trong quá\n"
	.string "trình rèn luyện.\p"
	.string "Dù vậy, mong cậu đừng quên niềm vui\n"
	.string "thuần túy của việc đạp xe.$"

Route110_Text_ChallengeReactionBad:
	.string "Trời đất... Kỹ năng đạp xe của cậu gần\n"
	.string "như đáng sợ.\p"
	.string "Chắc chắn cậu cần luyện tập thêm nhiều.$"

Route110_Text_ChallengeReactionWorst:
	.string "...Tôi kinh hãi thật...\p"
	.string "Có lẽ cậu không hợp với cái nghiệp đạp\n"
	.string "xe đầy bất hạnh này.\p"
	.string "Cậu nên nghiêm túc nghĩ đến chuyện trả\n"
	.string "chiếc BIKE đó cho RYDEL.$"

Route110_Text_RatedForNumberOfCollisions:
	.string "Đây là CYCLING ROAD.\p"
	.string "Nếu chạy MACH BIKE từ MAUVILLE đến\n"
	.string "SLATEPORT, cậu sẽ được chấm theo số\l"
	.string "lần va chạm và tổng thời gian.$"

Route110_Text_AlwaysAimHigher:
	.string "Bất kể kết quả thế nào, tôi vẫn mong\n"
	.string "được thấy cậu thử sức thêm. Hãy luôn\l"
	.string "vươn cao hơn!$"

Route110_Text_AcroBikesDoNotQualify:
	.string "Trên CYCLING ROAD này, người chạy MACH\n"
	.string "BIKES được chấm theo số lần va chạm và\l"
	.string "tổng thời gian.\p"
	.string "ACRO BIKES không đủ điều kiện xếp hạng.\n"
	.string "Chúng dễ rẽ nên như vậy không công\l"
	.string "bằng.$"

Route110_Text_SlateportCitySign:
	.string "ROUTE 110\n"
	.string "{DOWN_ARROW} SLATEPORT CITY$"

Route110_Text_CyclingRoadSign:
	.string "SEASIDE CYCLING ROAD$"

Route110_Text_AquaWasHere:
	.string "“TEAM AQUA đã ở đây!”\p"
	.string "Ai đó đã sơn dòng ấy lên tấm biển này,\n"
	.string "rồi một người khác sơn đè lên.\p"
	.string "Giờ trên đó ghi: “TEAM MAGMA là nhất!”$"

Route110_Text_Route103Sign:
	.string "ROUTE 110\n"
	.string "{LEFT_ARROW} ROUTE 103$"

Route110_Text_SeasideParkingSign:
	.string "SEASIDE PARKING$"

Route110_Text_MauvilleCitySign:
	.string "ROUTE 110\n"
	.string "{UP_ARROW} MAUVILLE CITY$"

Route110_Text_TrainerTipsPrlzSleep:
	.string "TRAINER TIPS\p"
	.string "Có thể khiến đối thủ bất lực bằng cách\n"
	.string "làm nó tê liệt hoặc ngủ.\p"
	.string "Đây là một kỹ thuật quan trọng trong\n"
	.string "chiến đấu POKéMON.$"

Route110_Text_TrainerTipsRegisterItems:
	.string "TRAINER TIPS\p"
	.string "Có thể sắp xếp lại các vật phẩm trong\n"
	.string "TÚI ĐỒ bằng cách nhấn SELECT.$"

Route110_Text_TrickHouseSign:
	.string "“Đi ba bước {RIGHT_ARROW}, rồi hai bước {UP_ARROW}\n"
	.string "để đến TRICK HOUSE kỳ thú.”$"

Route110_Text_BestRecord:
	.string "KỶ LỤC TỐT NHẤT TÍNH ĐẾN NAY...\p"
	.string "Số lần va chạm: {STR_VAR_1}\p"
	.string "Thời gian: {STR_VAR_2}$"

Route110_Text_ThereIsNoRecord:
	.string "KỶ LỤC TỐT NHẤT TÍNH ĐẾN NAY...\p"
	.string "Có vẻ chưa ai thử sức. Chưa có kỷ lục...$"

Route110_Text_ImagineSeeingYouHere:
	.string "PROF. BIRCH: Ồ, {PLAYER}{KUN}! Không\n"
	.string "ngờ lại gặp cháu ở đây!\p"
	.string "Thế {RIVAL} đang ở đâu nhỉ?$"

Route110_Text_HeardYouInstallMatchCall:
	.string "Ồ, ra vậy! Hai đứa đang đi riêng. Thế\n"
	.string "cũng được.\p"
	.string "À phải, bác nghe nói POKéNAV của cháu\n"
	.string "đã được cài hệ thống MATCH CALL.\p"
	.string "Vậy thì bác cũng nên đăng ký cháu vào\n"
	.string "POKéNAV của bác.\p"
	.string "Như thế, dù ở xa nhau, bác vẫn có thể\n"
	.string "đánh giá POKéDEX của cháu bất cứ lúc\l"
	.string "nào.\p"
	.string "... ... ... ... ... ...$"

Route110_Text_RegisteredBirchInPokenav:
	.string "Đã đăng ký PROF. BIRCH vào POKéNAV.$"

Route110_Text_KeepAnEyeOutForRival:
	.string "PROF. BIRCH: {PLAYER}{KUN}...\p"
	.string "Cháu hãy để mắt giúp bác đến\n"
	.string "{RIVAL} nhé. ... ... ... ... ... ...\p"
	.string "Thôi, bác phải đi đây. Hẹn gặp lại,\n"
	.string "{PLAYER}{KUN}!$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global Route110_Text_WeCantTalkAboutAquaActivities
	.global Route110_Text_KickUpARuckus
	.global Route110_Text_MyFirstJobInAqua
	.global Route110_Text_AquaActionsBringSmiles
	.global Route110_Text_MayLetsBattle
	.global Route110_Text_MayDefeated
	.global Route110_Text_MayTakeThis
	.global Route110_Text_MayExplainItemfinder
	.global Route110_Text_BrendanLetsBattle
	.global Route110_Text_BrendanDefeated
	.global Route110_Text_BrendanTakeThis
	.global Route110_Text_BrendanExplainItemfinder
	.global Route110_Text_RideBikeAtFullSpeed
	.global Route110_Text_HairStreamsBehindMe
	.global Route110_Text_YouGotBikeFromRydel
	.global Route110_Text_TwoRoads
	.global Route110_Text_WalkOnTheLowRoad
	.global Route110_Text_BikeTechniques
	.global Route110_Text_WhichShouldIChoose
	.global Route110_Text_CyclingChallengeResultSummary
	.global Route110_Text_ChallengeReactionBest
	.global Route110_Text_ChallengeReactionGood
	.global Route110_Text_ChallengeReactionOk
	.global Route110_Text_ChallengeReactionBad
	.global Route110_Text_ChallengeReactionWorst
	.global Route110_Text_RatedForNumberOfCollisions
	.global Route110_Text_AlwaysAimHigher
	.global Route110_Text_AcroBikesDoNotQualify
	.global Route110_Text_AquaWasHere
	.global Route110_Text_TrainerTipsPrlzSleep
	.global Route110_Text_TrainerTipsRegisterItems
	.global Route110_Text_TrickHouseSign
	.global Route110_Text_BestRecord
	.global Route110_Text_ThereIsNoRecord
	.global Route110_Text_ImagineSeeingYouHere
	.global Route110_Text_HeardYouInstallMatchCall
	.global Route110_Text_RegisteredBirchInPokenav
	.global Route110_Text_KeepAnEyeOutForRival
@ END GENERATED LOCALIZATION EXPORTS
