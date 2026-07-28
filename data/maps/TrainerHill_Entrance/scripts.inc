TrainerHill_Entrance_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, TrainerHill_Entrance_OnResume
	map_script MAP_SCRIPT_ON_RETURN_TO_FIELD, TrainerHill_Entrance_OnReturn
	map_script MAP_SCRIPT_ON_TRANSITION, TrainerHill_Entrance_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, TrainerHill_Entrance_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TrainerHill_Entrance_OnFrame
	.byte 0

TrainerHill_Entrance_OnTransition:
	setflag FLAG_LANDMARK_TRAINER_HILL
	getplayerxy VAR_TEMP_D, VAR_RESULT
	end

@ Unused
TrainerHill_Entrance_OnWarp:
	end

TrainerHill_Entrance_OnResume:
	trainerhill_resumetimer
	setvar VAR_TEMP_0, 0
	trainerhill_getusingereader
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_EventScript_TryFaceAttendant  @ VAR_RESULT always FALSE here
	setobjectxy LOCALID_PLAYER, 9, 6
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	end

TrainerHill_Entrance_EventScript_TryFaceAttendant::
	trainerhill_getwon
	goto_if_eq VAR_RESULT, TRUE, TrainerHill_Entrance_EventScript_PlayerDontFaceAttendant
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	end

TrainerHill_Entrance_EventScript_PlayerDontFaceAttendant::
	end

TrainerHill_Entrance_OnReturn:
	addobject LOCALID_TRAINER_HILL_NURSE
	addobject LOCALID_TRAINER_HILL_ATTENDANT
	addobject LOCALID_TRAINER_HILL_MAN
	addobject LOCALID_TRAINER_HILL_GIRL
	end

TrainerHill_Entrance_OnLoad:
	call_if_eq VAR_TEMP_D, 17, TrainerHill_Entrance_EventScript_OpenCounterDoor
	end

TrainerHill_Entrance_EventScript_OpenCounterDoor::
	setmetatile 17, 10, METATILE_TrainerHill_GreenFloorTile, FALSE
	return

TrainerHill_Entrance_OnFrame:
	map_script_2 VAR_TEMP_0, 0, TrainerHill_Entrance_EventScript_ExitChallenge
	map_script_2 VAR_TEMP_D, 17, TrainerHill_Entrance_EventScript_ExitElevator
	map_script_2 VAR_TEMP_5, 1, TrainerHill_Entrance_EventScript_EntryTrigger
	map_script_2 VAR_TEMP_1, 1, TrainerHill_EventScript_WarpToEntranceCounter
	.2byte 0

TrainerHill_Entrance_EventScript_ExitElevator::
	lockall
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PlayerExitElevator
	waitmovement 0
	setmetatile 17, 10, METATILE_TrainerHill_CounterDoor, TRUE
	special DrawWholeMapView
	playse SE_CLICK
	waitse
	setvar VAR_TEMP_D, 0
	releaseall
	end

TrainerHill_Entrance_EventScript_ExitChallenge::
	setvar VAR_TEMP_0, 1
	trainerhill_getstatus
	switch VAR_RESULT
	case TRAINER_HILL_PLAYER_STATUS_LOST, TrainerHill_Entrance_EventScript_ExitChallengeLost
	case TRAINER_HILL_PLAYER_STATUS_ECARD_SCANNED, TrainerHill_Entrance_EventScript_ExitChallengeECard
	case TRAINER_HILL_PLAYER_STATUS_NORMAL, TrainerHill_Entrance_EventScript_EndExitChallenge

TrainerHill_Entrance_EventScript_ExitChallengeLost::
	lockall
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	msgbox TrainerHill_Entrance_Text_TooBadTremendousEffort, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_EventScript_PlayerExitChallenge

TrainerHill_Entrance_EventScript_ExitChallengeECard::
	lockall
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	msgbox TrainerHill_Entrance_Text_MovedReceptionHereForSwitch, MSGBOX_DEFAULT
TrainerHill_Entrance_EventScript_PlayerExitChallenge::
	closemessage
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PushPlayerBackFromCounter
	waitmovement 0
	setvar VAR_TRAINER_HILL_IS_ACTIVE, 0
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	releaseall
TrainerHill_Entrance_EventScript_EndExitChallenge::
	end

TrainerHill_Entrance_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_TRAINER_HILL_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

TrainerHill_Entrance_EventScript_Attendant::
	lock
	faceplayer
	trainerhill_inchallenge
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_EventScript_ThanksForPlaying
	msgbox TrainerHill_Entrance_Text_HopeYouGiveItYourBest, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_EventScript_AttendantEnd

TrainerHill_Entrance_EventScript_ThanksForPlaying::
	msgbox TrainerHill_Entrance_Text_ThankYouForPlaying, MSGBOX_DEFAULT
TrainerHill_Entrance_EventScript_AttendantEnd::
	release
	end

TrainerHill_Entrance_EventScript_EntryTrigger::
	lockall
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	goto_if_unset FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_Closed
	msgbox TrainerHill_Entrance_Text_WelcomeToTrainerHill, MSGBOX_DEFAULT
	trainerhill_getsaved
	call_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_EventScript_SaveGame
	trainerhill_allfloorsused
	goto_if_eq VAR_RESULT, TRUE, TrainerHill_Entrance_EventScript_AllFloorsUsed
	msgbox TrainerHill_Entrance_Text_TrainersUpToFloorX, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_EventScript_AskChallengeTrainers

TrainerHill_Entrance_EventScript_AllFloorsUsed::
	msgbox TrainerHill_Entrance_Text_TrainersInEveryRoom, MSGBOX_DEFAULT
TrainerHill_Entrance_EventScript_AskChallengeTrainers::
	message TrainerHill_Entrance_Text_LikeToChallengeTrainers
	waitmessage
	multichoice 15, 6, MULTI_YESNOINFO, FALSE
	switch VAR_RESULT
	case 0, TrainerHill_Entrance_EventScript_ChooseChallenge
	case 1, TrainerHill_Entrance_EventScript_CancelEntry
	case 2, TrainerHill_Entrance_EventScript_Info
	case MULTI_B_PRESSED, TrainerHill_Entrance_EventScript_CancelEntry
	end

TrainerHill_Entrance_EventScript_Info::
	msgbox TrainerHill_Entrance_Text_ExplainTrainerHill, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_EventScript_AskChallengeTrainers
	end

TrainerHill_Entrance_EventScript_ChooseChallenge::
	multichoice 13, 2, MULTI_TAG_MATCH_TYPE, FALSE
	switch VAR_RESULT
	case 4, TrainerHill_Entrance_EventScript_CancelEntry
	case MULTI_B_PRESSED, TrainerHill_Entrance_EventScript_CancelEntry
	trainerhill_setmode VAR_RESULT
	setvar VAR_TRAINER_HILL_IS_ACTIVE, 1
	setvar VAR_TEMP_5, 0
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	msgbox TrainerHill_Entrance_Text_TimeProgessGetSetGo, MSGBOX_DEFAULT
	trainerhill_start
	releaseall
	end

TrainerHill_Entrance_EventScript_CancelEntry::
	setvar VAR_TEMP_5, 0
	msgbox TrainerHill_Entrance_Text_PleaseVisitUsAgain, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

TrainerHill_Entrance_EventScript_SaveGame::
	msgbox TrainerHill_Entrance_Text_SaveGameBeforeEnter, MSGBOX_DEFAULT
	trainerhill_setsaved
	setvar VAR_TEMP_5, 1
	call Common_EventScript_SaveGame
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_EventScript_SaveFailed
	trainerhill_setsaved
	return

TrainerHill_Entrance_EventScript_SaveFailed::
	trainerhill_clearsaved
	goto TrainerHill_Entrance_EventScript_CancelEntry
	end

TrainerHill_Entrance_EventScript_Closed::
	msgbox TrainerHill_Entrance_Text_StillGettingReady, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

TrainerHill_Entrance_Movement_PlayerFaceAttendant:
	face_right
	step_end

TrainerHill_Entrance_Movement_PushPlayerBackFromCounter:
	walk_down
	step_end

@ Unused
TrainerHill_Entrance_Movement_FaceUp:
	face_up
	step_end

TrainerHill_Entrance_Movement_PlayerExitElevator:
	walk_down
	walk_down
	step_end

TrainerHill_Entrance_EventScript_Records::
	lockall
	fadescreen FADE_TO_BLACK
	special ShowTrainerHillRecords
	releaseall
	end

TrainerHill_Entrance_EventScript_Man::
	goto_if_unset FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_ManTrainerHillClosed
	msgbox TrainerHill_Entrance_Text_WhatSortOfTrainersAreAhead, MSGBOX_NPC
	end

TrainerHill_Entrance_EventScript_ManTrainerHillClosed::
	msgbox TrainerHill_Entrance_Text_CantWaitToTestTheWaters, MSGBOX_NPC
	end

TrainerHill_Entrance_EventScript_Girl::
	goto_if_unset FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_GirlTrainerHillClosed
	msgbox TrainerHill_Entrance_Text_FriendsTryingToReachTimeBoardTop, MSGBOX_NPC
	end

TrainerHill_Entrance_EventScript_GirlTrainerHillClosed::
	msgbox TrainerHill_Entrance_Text_DoYouKnowWhenTheyOpen, MSGBOX_NPC
	end

TrainerHill_Entrance_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	goto_if_set FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_ExpandedPokemart
	pokemart TrainerHill_Entrance_Pokemart_Basic
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
TrainerHill_Entrance_Pokemart_Basic:
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_SPECIAL
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_GUARD_SPEC
	.2byte ITEM_X_ACCURACY
	pokemartlistend

TrainerHill_Entrance_EventScript_ExpandedPokemart::
	pokemart TrainerHill_Entrance_Pokemart_Expanded
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
TrainerHill_Entrance_Pokemart_Expanded:
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_SPECIAL
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_GUARD_SPEC
	.2byte ITEM_X_ACCURACY
	pokemartlistend

TrainerHill_Entrance_Text_StillGettingReady:
	.string "Đây là TRAINER HILL, nơi bạn có thể\n"
	.string "tham gia các trận đấu cặp với nhiều\l"
	.string "HLV.\p"
	.string "Đáng tiếc, chúng tôi vẫn đang chuẩn bị.\n"
	.string "Xin hãy quay lại sau!$"

TrainerHill_Entrance_Text_WelcomeToTrainerHill:
	.string "Chào mừng!\p"
	.string "Đây là TRAINER HILL, nơi bạn có thể\n"
	.string "tham gia các trận đấu cặp với nhiều\l"
	.string "HLV!$"

TrainerHill_Entrance_Text_SaveGameBeforeEnter:
	.string "Đây là lần đầu bạn đến sao?\p"
	.string "Trước khi vào, xin hãy lưu trò chơi.$"

TrainerHill_Entrance_Text_TrainersUpToFloorX:
	.string "Để xem... Các HLV hiện có mặt...\p"
	.string "Đến tận tầng số {STR_VAR_1}.$"

TrainerHill_Entrance_Text_TrainersInEveryRoom:
	.string "Để xem... Các HLV hiện có mặt...\p"
	.string "Có vẻ HLV đã tập trung trong mọi\n"
	.string "căn phòng.$"

TrainerHill_Entrance_Text_LikeToChallengeTrainers:
	.string "Bạn có muốn thách đấu những HLV\n"
	.string "đang chờ không?$"

TrainerHill_Entrance_Text_TimeProgessGetSetGo:
	.string "Tôi sẽ tính thời gian của bạn. Chúc may\n"
	.string "mắn!\p"
	.string "Vào vị trí...\p"
	.string "Sẵn sàng...\p"
	.string "Bắt đầu!$"

TrainerHill_Entrance_Text_PleaseVisitUsAgain:
	.string "Mong bạn lại ghé thăm!$"

TrainerHill_Entrance_Text_TooBadTremendousEffort:
	.string "Tiếc quá.\p"
	.string "Tôi nghĩ bạn đã nỗ lực hết sức trong\n"
	.string "các trận đấu.\p"
	.string "Hãy quay lại thử lần nữa nhé!$"

TrainerHill_Entrance_Text_HopeYouGiveItYourBest:
	.string "Mong bạn cố gắng hết sức.$"

TrainerHill_Entrance_Text_MovedReceptionHereForSwitch:
	.string "Khi các HLV đổi chỗ, việc di\n"
	.string "chuyển có thể rất hỗn loạn.\p"
	.string "Để tránh cảnh chen lấn, chúng tôi đã\n"
	.string "chuyển quầy tiếp tân đến đây.\p"
	.string "Xin lỗi vì sự bất tiện này.$"

TrainerHill_Entrance_Text_ThankYouForPlaying:
	.string "Cảm ơn bạn đã chơi!$"

TrainerHill_Entrance_Text_ExplainTrainerHill:
	.string "Tại TRAINER HILL, chúng tôi tổ chức một\n"
	.string "sự kiện mang tên Time Attack.\p"
	.string "Đây là cuộc đua đo thời gian bạn đi từ\n"
	.string "quầy này đến gặp chủ nhân của chúng\l"
	.string "tôi trên sân thượng.\p"
	.string "Các thành tích nhanh nhất sẽ được ghi\n"
	.string "lên Time Board. Hãy thử tranh tài với\l"
	.string "bạn bè.\p"
	.string "Trong các trận đấu HLV dọc đường,\n"
	.string "bạn sẽ không nhận được Exp. Points hay\l"
	.string "tiền.$"

@ Unused
TrainerHill_Entrance_Text_NeedAtLeastTwoPokemon:
	.string "Ồ, xin lỗi, nhưng hình như bạn chỉ mang\n"
	.string "theo một POKéMON.\p"
	.string "Bạn cần ít nhất hai POKéMON để tham gia\n"
	.string "sự kiện này.$"

TrainerHill_Roof_Text_YouFinallyCameBravo:
	.string "Hừm! Hừm!\p"
	.string "Cuối cùng bạn cũng tới! Đúng, bạn đã\n"
	.string "tới rồi!\p"
	.string "Khoan! Đừng nói! Tôi biết tại sao bạn\n"
	.string "lặn lội một mình đến tận đây!\p"
	.string "Bạn muốn gặp tôi, chủ nhân của TRAINER\n"
	.string "HILL, bởi vì...\p"
	.string "Bạn muốn lập đội cặp với tôi! Wa-hoo!\p"
	.string "...Ơ? Không phải sao?\p"
	.string "Dù sao, tôi đã dõi theo bạn trên đường\n"
	.string "lên đây. Chiến đấu tuyệt diệu! Quả là\l"
	.string "xuất sắc!$"

TrainerHill_Roof_Text_HaveTheMostMarvelousGift:
	.string "Với một người tuyệt vời như bạn, tôi\n"
	.string "có món quà tuyệt vời nhất!$"

TrainerHill_Roof_Text_FullUpBeBackLaterForThis:
	.string "Ôi không, bạn mang đầy đồ rồi! Lần sau\n"
	.string "hãy quay lại lấy thứ này nhé!$"

TrainerHill_Roof_Text_GotHereMarvelouslyQuickly:
	.string "Ồ, khoan đã! Chẳng lẽ bạn đã tới đây\n"
	.string "nhanh một cách tuyệt diệu sao?\p"
	.string "Xuất sắc! Bạn đâu cần vội đến thế chỉ\n"
	.string "để gặp tôi!\p"
	.string "Thật vui làm sao. Tôi sẽ cho cập nhật\n"
	.string "Time Board ở quầy tiếp tân!$"

TrainerHill_Roof_Text_YouWerentVeryQuick:
	.string "Nhưng, ôi... Bạn đến đây không nhanh\n"
	.string "lắm.$"

TrainerHill_Roof_Text_ArriveZippierNextTime:
	.string "Có lẽ lần sau bạn tới nhanh hơn sẽ làm\n"
	.string "tôi vui hơn.\p"
	.string "Khi đó, tôi sẽ rất vui lòng lập đội cặp\n"
	.string "với bạn!\p"
	.string "Hẹn gặp lại, amigo!$"

@ Unused
TrainerHill_Roof_Text_BuiltTrainerHillToFindPartner:
	.string "Tôi xây TRAINER HILL chỉ vì một lý do\n"
	.string "duy nhất!\p"
	.string "Để tìm người đồng đội phù hợp nhất mà\n"
	.string "tôi có thể lập đội cặp cùng!$"

TrainerHill_Entrance_Text_ChallengeTime:
	.string "{STR_VAR_1} phút\n"
	.string "{STR_VAR_2}.{STR_VAR_3}\l"
	.string "giây.$"

TrainerHill_Entrance_Text_WhatSortOfTrainersAreAhead:
	.string "Ai biết phía trước có những tổ hợp\n"
	.string "HLV và POKéMON nào?\p"
	.string "Tôi chỉ biết rằng bất kỳ ai cản đường,\n"
	.string "tôi sẽ hất văng hết!$"

TrainerHill_Entrance_Text_CantWaitToTestTheWaters:
	.string "Tôi nghe nói các HLV mạnh từ khắp\n"
	.string "nơi đều đến TRAINER HILL này.\p"
	.string "Tôi nóng lòng muốn thử sức!\p"
	.string "Bất kỳ ai cản đường, tôi sẽ hất văng\n"
	.string "hết!$"

TrainerHill_Entrance_Text_FriendsTryingToReachTimeBoardTop:
	.string "Bạn thấy Time Board đằng kia chứ?\p"
	.string "Tôi và bạn bè đang thi xem ai có thể lên\n"
	.string "tới đỉnh trong thời gian ngắn nhất.$"

TrainerHill_Entrance_Text_DoYouKnowWhenTheyOpen:
	.string "Bạn có biết khi nào nơi này mở cửa\n"
	.string "không?\p"
	.string "Tôi đang chờ để trở thành người thách\n"
	.string "đấu đầu tiên ở đây!$"

TrainerHill_Elevator_Text_ReturnToReception:
	.string "Bạn có muốn quay lại quầy tiếp tân\n"
	.string "không?$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global TrainerHill_Entrance_Text_StillGettingReady
	.global TrainerHill_Entrance_Text_WelcomeToTrainerHill
	.global TrainerHill_Entrance_Text_SaveGameBeforeEnter
	.global TrainerHill_Entrance_Text_TrainersUpToFloorX
	.global TrainerHill_Entrance_Text_TrainersInEveryRoom
	.global TrainerHill_Entrance_Text_LikeToChallengeTrainers
	.global TrainerHill_Entrance_Text_TimeProgessGetSetGo
	.global TrainerHill_Entrance_Text_PleaseVisitUsAgain
	.global TrainerHill_Entrance_Text_TooBadTremendousEffort
	.global TrainerHill_Entrance_Text_HopeYouGiveItYourBest
	.global TrainerHill_Entrance_Text_MovedReceptionHereForSwitch
	.global TrainerHill_Entrance_Text_ThankYouForPlaying
	.global TrainerHill_Entrance_Text_ExplainTrainerHill
	.global TrainerHill_Entrance_Text_NeedAtLeastTwoPokemon
	.global TrainerHill_Roof_Text_YouFinallyCameBravo
	.global TrainerHill_Roof_Text_HaveTheMostMarvelousGift
	.global TrainerHill_Roof_Text_FullUpBeBackLaterForThis
	.global TrainerHill_Roof_Text_GotHereMarvelouslyQuickly
	.global TrainerHill_Roof_Text_YouWerentVeryQuick
	.global TrainerHill_Roof_Text_ArriveZippierNextTime
	.global TrainerHill_Roof_Text_BuiltTrainerHillToFindPartner
	.global TrainerHill_Entrance_Text_ChallengeTime
	.global TrainerHill_Entrance_Text_WhatSortOfTrainersAreAhead
	.global TrainerHill_Entrance_Text_CantWaitToTestTheWaters
	.global TrainerHill_Entrance_Text_FriendsTryingToReachTimeBoardTop
	.global TrainerHill_Entrance_Text_DoYouKnowWhenTheyOpen
	.global TrainerHill_Elevator_Text_ReturnToReception
@ END GENERATED LOCALIZATION EXPORTS
