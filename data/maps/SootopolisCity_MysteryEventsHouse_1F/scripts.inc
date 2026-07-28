SootopolisCity_MysteryEventsHouse_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SootopolisCity_MysteryEventsHouse_1F_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SootopolisCity_MysteryEventsHouse_1F_OnFrame
	.byte 0

SootopolisCity_MysteryEventsHouse_1F_OnTransition:
	frontier_checkvisittrainer
	call_if_eq VAR_RESULT, 0, SootopolisCity_MysteryEventsHouse_1F_EventScript_SetTrainerVisitingLayout
	call_if_ne VAR_SOOTOPOLIS_MYSTERY_EVENTS_STATE, 0, SootopolisCity_MysteryEventsHouse_1F_EventScript_MoveOldManToDoor
	end

SootopolisCity_MysteryEventsHouse_1F_EventScript_SetTrainerVisitingLayout::
	setvar VAR_TEMP_1, 1
	setobjectxyperm LOCALID_MYSTERY_EVENTS_OLD_MAN, 3, 2
	setobjectmovementtype LOCALID_MYSTERY_EVENTS_OLD_MAN, MOVEMENT_TYPE_FACE_DOWN
	setmaplayoutindex LAYOUT_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_1F_STAIRS_UNBLOCKED
	return

SootopolisCity_MysteryEventsHouse_1F_EventScript_MoveOldManToDoor::
	setobjectxyperm LOCALID_MYSTERY_EVENTS_OLD_MAN, 2, 2
	setobjectmovementtype LOCALID_MYSTERY_EVENTS_OLD_MAN, MOVEMENT_TYPE_FACE_RIGHT
	return

SootopolisCity_MysteryEventsHouse_1F_OnFrame:
	map_script_2 VAR_SOOTOPOLIS_MYSTERY_EVENTS_STATE, 1, SootopolisCity_MysteryEventsHouse_1F_EventScript_OldManCommentOnBattle
	map_script_2 VAR_SOOTOPOLIS_MYSTERY_EVENTS_STATE, 2, SootopolisCity_MysteryEventsHouse_1F_EventScript_OldManCommentOnBattle
	map_script_2 VAR_SOOTOPOLIS_MYSTERY_EVENTS_STATE, 3, SootopolisCity_MysteryEventsHouse_1F_EventScript_OldManCommentOnBattle
	.2byte 0

SootopolisCity_MysteryEventsHouse_1F_EventScript_OldManCommentOnBattle::
	lockall
	applymovement LOCALID_PLAYER, SootopolisCity_MysteryEventsHouse_1F_Movement_PlayerExitStairs
	waitmovement 0
	applymovement LOCALID_MYSTERY_EVENTS_OLD_MAN, SootopolisCity_MysteryEventsHouse_1F_Movement_OldManWalkBehindPlayer
	waitmovement 0
	copyobjectxytoperm LOCALID_MYSTERY_EVENTS_OLD_MAN
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	call_if_eq VAR_SOOTOPOLIS_MYSTERY_EVENTS_STATE, 1, SootopolisCity_MysteryEventsHouse_1F_EventScript_BattleWonComment
	call_if_eq VAR_SOOTOPOLIS_MYSTERY_EVENTS_STATE, 2, SootopolisCity_MysteryEventsHouse_1F_EventScript_BattleLostComment
	call_if_eq VAR_SOOTOPOLIS_MYSTERY_EVENTS_STATE, 3, SootopolisCity_MysteryEventsHouse_1F_EventScript_BattleTiedComment
	special LoadPlayerParty
	setvar VAR_SOOTOPOLIS_MYSTERY_EVENTS_STATE, 0
	releaseall
	end

SootopolisCity_MysteryEventsHouse_1F_EventScript_BattleWonComment::
	msgbox SootopolisCity_MysteryEventsHouse_1F_Text_ThatWasSuperlative, MSGBOX_DEFAULT
	return

SootopolisCity_MysteryEventsHouse_1F_EventScript_BattleLostComment::
	msgbox SootopolisCity_MysteryEventsHouse_1F_Text_TooBadForYou, MSGBOX_DEFAULT
	return

SootopolisCity_MysteryEventsHouse_1F_EventScript_BattleTiedComment::
	msgbox SootopolisCity_MysteryEventsHouse_1F_Text_BrilliantStandoff, MSGBOX_DEFAULT
	return

SootopolisCity_MysteryEventsHouse_1F_Movement_PlayerExitStairs:
	walk_down
	step_end

SootopolisCity_MysteryEventsHouse_1F_Movement_OldManWalkBehindPlayer:
	walk_right
	walk_in_place_faster_down
	step_end

SootopolisCity_MysteryEventsHouse_1F_EventScript_OldMan::
	lock
	faceplayer
	frontier_checkvisittrainer
	goto_if_eq VAR_RESULT, 1, SootopolisCity_MysteryEventsHouse_1F_EventScript_InvalidVisitingTrainer
	goto_if_eq VAR_TEMP_1, 1, SootopolisCity_MysteryEventsHouse_1F_EventScript_TrainerVisiting
	msgbox SootopolisCity_MysteryEventsHouse_1F_Text_OnlyAmusementWatchingBattles, MSGBOX_DEFAULT
	release
	end

SootopolisCity_MysteryEventsHouse_1F_EventScript_InvalidVisitingTrainer::
	msgbox SootopolisCity_MysteryEventsHouse_1F_Text_OnlyAmusementWatchingBattles, MSGBOX_DEFAULT
	release
	end

SootopolisCity_MysteryEventsHouse_1F_EventScript_TrainerVisiting::
	special SavePlayerParty
	special BufferEReaderTrainerName
	msgbox SootopolisCity_MysteryEventsHouse_1F_Text_ChallengeVisitingTrainer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SootopolisCity_MysteryEventsHouse_1F_EventScript_DeclineBattle
	call SootopolisCity_MysteryEventsHouse_1F_EventScript_ChooseParty
	goto_if_eq VAR_RESULT, 0, SootopolisCity_MysteryEventsHouse_1F_EventScript_DeclineBattle
	msgbox SootopolisCity_MysteryEventsHouse_1F_Text_SaveProgressBeforeBattle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SootopolisCity_MysteryEventsHouse_1F_EventScript_DeclineBattle
	special LoadPlayerParty
	call Common_EventScript_SaveGame
	goto_if_eq VAR_RESULT, FALSE, SootopolisCity_MysteryEventsHouse_1F_EventScript_DeclineBattle
	special SavePlayerParty
	special ReducePlayerPartyToSelectedMons
	msgbox SootopolisCity_MysteryEventsHouse_1F_Text_HopeToSeeGoodMatch, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, SootopolisCity_MysteryEventsHouse_1F_EventScript_EnterBasementNorth
	call_if_eq VAR_FACING, DIR_EAST, SootopolisCity_MysteryEventsHouse_1F_EventScript_EnterBasementEast
	call_if_eq VAR_FACING, DIR_WEST, SootopolisCity_MysteryEventsHouse_1F_EventScript_EnterBasementWest
	warp MAP_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_B1F, 3, 1
	waitstate
	release
	end

SootopolisCity_MysteryEventsHouse_1F_EventScript_DeclineBattle::
	special LoadPlayerParty
	msgbox SootopolisCity_MysteryEventsHouse_1F_Text_YouWontBattle, MSGBOX_DEFAULT
	release
	end

SootopolisCity_MysteryEventsHouse_1F_EventScript_ChooseParty::
	msgbox SootopolisCity_MysteryEventsHouse_1F_Text_KeepItTo3On3, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special ChooseHalfPartyForBattle
	return

SootopolisCity_MysteryEventsHouse_1F_EventScript_EnterBasementNorth::
	applymovement VAR_LAST_TALKED, SootopolisCity_MysteryEventsHouse_1F_Movement_OldManMoveAsideLeft
	applymovement LOCALID_PLAYER, SootopolisCity_MysteryEventsHouse_1F_Movement_PlayerEnterBasementNorth
	waitmovement 0
	return

SootopolisCity_MysteryEventsHouse_1F_EventScript_EnterBasementEast::
	applymovement VAR_LAST_TALKED, SootopolisCity_MysteryEventsHouse_1F_Movement_OldManMoveAsideRight
	applymovement LOCALID_PLAYER, SootopolisCity_MysteryEventsHouse_1F_Movement_PlayerEnterBasementEast
	waitmovement 0
	return

SootopolisCity_MysteryEventsHouse_1F_EventScript_EnterBasementWest::
	applymovement VAR_LAST_TALKED, SootopolisCity_MysteryEventsHouse_1F_Movement_OldManMoveAsideLeft
	applymovement LOCALID_PLAYER, SootopolisCity_MysteryEventsHouse_1F_Movement_PlayerEnterBasementWest
	waitmovement 0
	return

SootopolisCity_MysteryEventsHouse_1F_Movement_PlayerEnterBasementNorth:
	delay_16
	walk_up
	walk_up
	step_end

SootopolisCity_MysteryEventsHouse_1F_Movement_PlayerEnterBasementEast:
	delay_16
	walk_right
	walk_up
	step_end

SootopolisCity_MysteryEventsHouse_1F_Movement_PlayerEnterBasementWest:
	delay_16
	walk_left
	walk_up
	step_end

SootopolisCity_MysteryEventsHouse_1F_Movement_OldManMoveAsideLeft:
	walk_left
	walk_in_place_faster_right
	step_end

SootopolisCity_MysteryEventsHouse_1F_Movement_OldManMoveAsideRight:
	walk_right
	walk_in_place_faster_left
	step_end

SootopolisCity_MysteryEventsHouse_1F_Text_OnlyAmusementWatchingBattles:
	.string "Ngày trẻ, ta từng chu du khắp thế giới\n"
	.string "với tư cách HLV POKéMON.\p"
	.string "Giờ đã thành lão già khọm, thú vui duy\n"
	.string "nhất của ta là xem các HLV trẻ\l"
	.string "tuổi thi đấu.$"

SootopolisCity_MysteryEventsHouse_1F_Text_DoorAppearsToBeLocked:
	.string "Cánh cửa có vẻ đã bị khóa.$"

SootopolisCity_MysteryEventsHouse_1F_Text_ChallengeVisitingTrainer:
	.string "Một HLV tên {STR_VAR_1}\n"
	.string "đang ghé thăm nhà ta.\p"
	.string "Cháu có muốn thách đấu\n"
	.string "{STR_VAR_1} không?$"

SootopolisCity_MysteryEventsHouse_1F_Text_YouWontBattle:
	.string "Cháu không đấu sao? Tiếc quá, ta không\n"
	.string "được xem cháu thi đấu...$"

SootopolisCity_MysteryEventsHouse_1F_Text_KeepItTo3On3:
	.string "Ồ, tốt lắm, tốt lắm!\p"
	.string "Nhưng nhà ta không được chắc chắn cho\n"
	.string "lắm.\p"
	.string "Ta có thể nhờ hai cháu chỉ đấu 3 chọi 3\n"
	.string "thôi không?$"

SootopolisCity_MysteryEventsHouse_1F_Text_SaveProgressBeforeBattle:
	.string "Trước khi hai cháu thi đấu, cháu nên\n"
	.string "lưu tiến trình.$"

SootopolisCity_MysteryEventsHouse_1F_Text_HopeToSeeGoodMatch:
	.string "Ta mong sẽ được xem một trận thật hay!$"

@ Unused
SootopolisCity_MysteryEventsHouse_1F_Text_StrVar1Tie:
	.string "{STR_VAR_1}$"

SootopolisCity_MysteryEventsHouse_B1F_Text_MatchEndedUpDraw:
	.string "Trận đấu đã kết thúc với kết quả hòa.$"

SootopolisCity_MysteryEventsHouse_1F_Text_BrilliantStandoff:
	.string "Vậy là hai bên bất phân thắng bại.\p"
	.string "Một trận đấu tuyệt vời, không bên nào\n"
	.string "chịu nhường dù chỉ một bước!$"

@ Unused
SootopolisCity_MysteryEventsHouse_1F_Text_StrVar1Won:
	.string "{STR_VAR_1}$"

SootopolisCity_MysteryEventsHouse_1F_Text_ThatWasSuperlative:
	.string "Tuyệt hảo!\p"
	.string "Cứ như ta đang được nhìn lại chính\n"
	.string "mình thuở trẻ vậy!$"

@ Unused
SootopolisCity_MysteryEventsHouse_1F_Text_StrVar1Lost:
	.string "{STR_VAR_1}$"

SootopolisCity_MysteryEventsHouse_1F_Text_TooBadForYou:
	.string "À, tiếc cho cháu quá!\p"
	.string "Nhưng đó là một trận đấu hay. Mong lần\n"
	.string "sau cháu sẽ thắng.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global SootopolisCity_MysteryEventsHouse_1F_Text_OnlyAmusementWatchingBattles
	.global SootopolisCity_MysteryEventsHouse_1F_Text_DoorAppearsToBeLocked
	.global SootopolisCity_MysteryEventsHouse_1F_Text_ChallengeVisitingTrainer
	.global SootopolisCity_MysteryEventsHouse_1F_Text_YouWontBattle
	.global SootopolisCity_MysteryEventsHouse_1F_Text_KeepItTo3On3
	.global SootopolisCity_MysteryEventsHouse_1F_Text_SaveProgressBeforeBattle
	.global SootopolisCity_MysteryEventsHouse_1F_Text_HopeToSeeGoodMatch
	.global SootopolisCity_MysteryEventsHouse_B1F_Text_MatchEndedUpDraw
	.global SootopolisCity_MysteryEventsHouse_1F_Text_BrilliantStandoff
	.global SootopolisCity_MysteryEventsHouse_1F_Text_ThatWasSuperlative
	.global SootopolisCity_MysteryEventsHouse_1F_Text_TooBadForYou
@ END GENERATED LOCALIZATION EXPORTS
