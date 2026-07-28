BattleFrontier_BattlePikeThreePathRoom_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattlePikeRoom_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePikeThreePathRoom_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattlePikeThreePathRoom_OnWarp
	.byte 0

BattleFrontier_BattlePikeThreePathRoom_OnFrame:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattlePikeThreePathRoom_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePikeThreePathRoom_EventScript_WarpToLobby
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattlePikeThreePathRoom_EventScript_ResumeChallenge
	map_script_2 VAR_TEMP_5, 0, BattleFrontier_BattlePikeThreePathRoom_EventScript_SetHintRoom
	map_script_2 VAR_TEMP_5, 1, BattleFrontier_BattlePikeThreePathRoom_EventScript_GivePikeQueenHint
	.2byte 0

BattleFrontier_BattlePikeThreePathRoom_OnWarp:
	map_script_2 VAR_TEMP_4, 0, BattleFrontier_BattlePikeThreePathRoom_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattlePikeThreePathRoom_EventScript_TurnPlayerNorth::
	setvar VAR_TEMP_4, 1
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_WarpToLobby::
	warp MAP_BATTLE_FRONTIER_BATTLE_PIKE_LOBBY, 5, 6
	waitstate
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_ResumeChallenge::
	lockall
	message BattleFrontier_BattlePikeThreePathRoom_Text_AwaitingReturnSaveBeforeResume
	waitmessage
	pike_save CHALLENGE_STATUS_SAVING
	playse SE_SAVE
	waitse
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_PleaseEnjoyChallenge, MSGBOX_DEFAULT
	closemessage
	releaseall
	frontier_settrainers
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 99
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_Attendant::
	frontier_get FRONTIER_DATA_BATTLE_NUM  @ Room number
	switch VAR_RESULT
	case 1, BattleFrontier_BattlePikeThreePathRoom_EventScript_AttendantRoom1
	case 3, BattleFrontier_BattlePikeThreePathRoom_EventScript_AttendantRoom3
	case 5, BattleFrontier_BattlePikeThreePathRoom_EventScript_AttendantRoom5
	case 7, BattleFrontier_BattlePikeThreePathRoom_EventScript_AttendantRoom7
	case 9, BattleFrontier_BattlePikeThreePathRoom_EventScript_AttendantRoom9
	case 11, BattleFrontier_BattlePikeThreePathRoom_EventScript_AttendantRoom11
	case 13, BattleFrontier_BattlePikeThreePathRoom_EventScript_AttendantRoom13
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_AttendantRoom1::
	lock
	faceplayer
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom1, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_AskContinueChallenge
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_AttendantRoom3::
	lock
	faceplayer
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom3, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_AskContinueChallenge
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_AttendantRoom5::
	lock
	faceplayer
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom5, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_AskContinueChallenge
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_AttendantRoom7::
	lock
	faceplayer
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom7, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_AskContinueChallenge
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_AttendantRoom9::
	lock
	faceplayer
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom9, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_AskContinueChallenge
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_AttendantRoom11::
	lock
	faceplayer
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom11, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_AskContinueChallenge
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_AttendantRoom13::
	lock
	faceplayer
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom13, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_AskContinueChallenge
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_AskContinueChallenge::
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_ContinueWithChallenge, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattlePikeThreePathRoom_EventScript_AskSaveChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePikeThreePathRoom_EventScript_AskSaveChallenge
	release
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_PauseChallenge::
	frontier_saveparty
	message BattleFrontier_BattlePikeThreePathRoom_Text_SavingYourData
	waitmessage
	special LoadPlayerParty
	pike_save CHALLENGE_STATUS_PAUSED
	playse SE_SAVE
	waitse
	fadescreen FADE_TO_BLACK
	frontier_reset
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_AskSaveChallenge::
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_SaveChallengeAndQuit, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, BattleFrontier_BattlePikeThreePathRoom_EventScript_PauseChallenge
	case NO, BattleFrontier_BattlePikeThreePathRoom_EventScript_AskRetireChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePikeThreePathRoom_EventScript_AskRetireChallenge
	release
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_AskRetireChallenge::
	message BattleFrontier_BattlePikeThreePathRoom_Text_RetireFromChallenge
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePike_EventScript_Retire
	release
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_SetHintRoom::
	pike_sethintroom
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePikeThreePathRoom_EventScript_SetPikeQueenHint
	setvar VAR_TEMP_5, 255
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_SetPikeQueenHint::
	setvar VAR_TEMP_5, 1
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_GivePikeQueenHint::
	applymovement LOCALID_PIKE_HINT_GIVER, BattleFrontier_BattlePikeThreePathRoom_Movement_HintGiverApproachPlayer
	waitmovement 0
	lockall
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_TerrifyingEvent, MSGBOX_DEFAULT
	releaseall
	applymovement LOCALID_PIKE_HINT_GIVER, BattleFrontier_BattlePikeThreePathRoom_Movement_HintGiverReturnToPos
	waitmovement 0
	setvar VAR_TEMP_5, 255
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_HintGiver::
	pike_gethint
	goto_if_eq VAR_RESULT, PIKE_HINT_BRAIN, BattleFrontier_BattlePikeThreePathRoom_EventScript_GiveBrainHint
	lock
	faceplayer
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_FindingItDifficultToChoose, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, BattleFrontier_BattlePikeThreePathRoom_EventScript_AcceptHint
	case NO, BattleFrontier_BattlePikeThreePathRoom_EventScript_DeclineHint
	case MULTI_B_PRESSED, BattleFrontier_BattlePikeThreePathRoom_EventScript_DeclineHint
	release
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_DeclineHint::
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_ApologizeForImpertinence, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_AcceptHint::
	pike_gethintroomid
	switch VAR_RESULT
	case PIKE_ROOM_LEFT, BattleFrontier_BattlePikeThreePathRoom_EventScript_GiveLeftRoomHint
	case PIKE_ROOM_CENTER, BattleFrontier_BattlePikeThreePathRoom_EventScript_GiveCenterRoomHint
	case PIKE_ROOM_RIGHT, BattleFrontier_BattlePikeThreePathRoom_EventScript_GiveRightRoomHint
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_GiveLeftRoomHint::
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_SomethingAboutLeftPath, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_GiveHint

BattleFrontier_BattlePikeThreePathRoom_EventScript_GiveCenterRoomHint::
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_SomethingAboutCenterPath, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_GiveHint

BattleFrontier_BattlePikeThreePathRoom_EventScript_GiveRightRoomHint::
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_SomethingAboutRightPath, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_GiveHint

BattleFrontier_BattlePikeThreePathRoom_EventScript_GiveHint::
	pike_gethint
	switch VAR_RESULT
	case PIKE_HINT_NOSTALGIA, BattleFrontier_BattlePikeThreePathRoom_EventScript_HintNostalgia
	case PIKE_HINT_WHISPERING, BattleFrontier_BattlePikeThreePathRoom_EventScript_HintWhispering
	case PIKE_HINT_POKEMON, BattleFrontier_BattlePikeThreePathRoom_EventScript_HintPokemon
	case PIKE_HINT_PEOPLE, BattleFrontier_BattlePikeThreePathRoom_EventScript_HintPeople
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_HintNostalgia::
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_WaveOfNostaliga, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_HintWhispering::
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_HeardWhispering, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_HintPokemon::
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_AromaOfPokemon, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_HintPeople::
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_PresenceOfPeople, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_GiveBrainHint::
	lock
	faceplayer
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_DreadfulPresence, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattlePikeThreePathRoom_Movement_HintGiverApproachPlayer:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

BattleFrontier_BattlePikeThreePathRoom_Movement_HintGiverReturnToPos:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	face_down
	step_end

BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom1:
	.string "Bạn hiện đang ở căn phòng thứ 1...$"

BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom3:
	.string "Bạn hiện đang ở căn phòng thứ 3...$"

BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom5:
	.string "Bạn hiện đang ở căn phòng thứ 5...$"

BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom7:
	.string "Bạn hiện đang ở căn phòng thứ 7...$"

BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom9:
	.string "Bạn hiện đang ở căn phòng thứ 9...$"

BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom11:
	.string "Bạn hiện đang ở căn phòng thứ 11...$"

BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom13:
	.string "Bạn hiện đang ở căn phòng thứ 13...$"

BattleFrontier_BattlePikeThreePathRoom_Text_ContinueWithChallenge:
	.string "Bạn có muốn tiếp tục thử thách không?$"

BattleFrontier_BattlePikeThreePathRoom_Text_SaveChallengeAndQuit:
	.string "Bạn có muốn lưu tiến trình thử thách\n"
	.string "rồi tạm thoát trò chơi không?$"

BattleFrontier_BattlePikeThreePathRoom_Text_RetireFromChallenge:
	.string "Bạn có muốn rút lui khỏi thử thách\n"
	.string "Battle Choice không?$"

BattleFrontier_BattlePikeThreePathRoom_Text_AwaitingReturnSaveBeforeResume:
	.string "Chúng tôi vẫn đang chờ bạn quay lại...\p"
	.string "Trước khi tiếp tục thử thách Battle\n"
	.string "Choice, xin hãy để tôi lưu trò chơi...$"

BattleFrontier_BattlePikeThreePathRoom_Text_PleaseEnjoyChallenge:
	.string "Chúc bạn tận hưởng thử thách Battle\n"
	.string "Choice...$"

BattleFrontier_BattlePikeThreePathRoom_Text_SavingYourData:
	.string "Tôi đang lưu dữ liệu của bạn... Xin chờ\n"
	.string "một lát...$"

BattleFrontier_BattlePike_Text_PathBlockedNoTurningBack:
	.string "Lối đi đã bị chặn! Và cũng không thể\n"
	.string "quay lại...$"

BattleFrontier_BattlePikeThreePathRoom_Text_FindingItDifficultToChoose:
	.string "Xin thứ lỗi, nhưng...\p"
	.string "Có phải bạn đang khó chọn lối đi không?$"

BattleFrontier_BattlePikeThreePathRoom_Text_ApologizeForImpertinence:
	.string "Tôi hiểu rồi... Xin lỗi vì đã mạo muội...$"

BattleFrontier_BattlePikeThreePathRoom_Text_SomethingAboutRightPath:
	.string "À, để tôi xem... Lối bên phải có điều gì\n"
	.string "đó...$"

BattleFrontier_BattlePikeThreePathRoom_Text_SomethingAboutCenterPath:
	.string "À, để tôi xem... Lối ở giữa có điều gì\n"
	.string "đó...$"

BattleFrontier_BattlePikeThreePathRoom_Text_SomethingAboutLeftPath:
	.string "À, để tôi xem... Lối bên trái có điều gì\n"
	.string "đó...$"

BattleFrontier_BattlePikeThreePathRoom_Text_AromaOfPokemon:
	.string "Hình như quanh lối đó phảng phất mùi\n"
	.string "đặc trưng của POKéMON...$"

BattleFrontier_BattlePikeThreePathRoom_Text_PresenceOfPeople:
	.string "Có phải... Một HLV? Tôi cảm nhận\n"
	.string "được có người...$"

BattleFrontier_BattlePikeThreePathRoom_Text_HeardWhispering:
	.string "Hình như tôi vừa nghe thấy gì đó... Có\n"
	.string "lẽ là tiếng thì thầm...$"

BattleFrontier_BattlePikeThreePathRoom_Text_WaveOfNostaliga:
	.string "Vì lý do kỳ lạ nào đó, tôi cảm thấy một\n"
	.string "làn hoài niệm tỏa ra từ lối ấy...$"

BattleFrontier_BattlePikeThreePathRoom_Text_TerrifyingEvent:
	.string "Tôi rất tiếc phải nói rằng...\p"
	.string "Một chuyện kinh hoàng, đúng vậy, một\n"
	.string "chuyện vô cùng khủng khiếp sắp giáng\l"
	.string "xuống bạn...\p"
	.string "Tôi khuyên bạn phải hết sức cẩn thận và\n"
	.string "chuẩn bị cho tình huống tồi tệ nhất...$"

BattleFrontier_BattlePikeThreePathRoom_Text_DreadfulPresence:
	.string "Tôi cảm nhận được một luồng khí đáng\n"
	.string "sợ từ mọi lối đi...$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom1
	.global BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom3
	.global BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom5
	.global BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom7
	.global BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom9
	.global BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom11
	.global BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom13
	.global BattleFrontier_BattlePikeThreePathRoom_Text_ContinueWithChallenge
	.global BattleFrontier_BattlePikeThreePathRoom_Text_SaveChallengeAndQuit
	.global BattleFrontier_BattlePikeThreePathRoom_Text_RetireFromChallenge
	.global BattleFrontier_BattlePikeThreePathRoom_Text_AwaitingReturnSaveBeforeResume
	.global BattleFrontier_BattlePikeThreePathRoom_Text_PleaseEnjoyChallenge
	.global BattleFrontier_BattlePikeThreePathRoom_Text_SavingYourData
	.global BattleFrontier_BattlePike_Text_PathBlockedNoTurningBack
	.global BattleFrontier_BattlePikeThreePathRoom_Text_FindingItDifficultToChoose
	.global BattleFrontier_BattlePikeThreePathRoom_Text_ApologizeForImpertinence
	.global BattleFrontier_BattlePikeThreePathRoom_Text_SomethingAboutRightPath
	.global BattleFrontier_BattlePikeThreePathRoom_Text_SomethingAboutCenterPath
	.global BattleFrontier_BattlePikeThreePathRoom_Text_SomethingAboutLeftPath
	.global BattleFrontier_BattlePikeThreePathRoom_Text_AromaOfPokemon
	.global BattleFrontier_BattlePikeThreePathRoom_Text_PresenceOfPeople
	.global BattleFrontier_BattlePikeThreePathRoom_Text_HeardWhispering
	.global BattleFrontier_BattlePikeThreePathRoom_Text_WaveOfNostaliga
	.global BattleFrontier_BattlePikeThreePathRoom_Text_TerrifyingEvent
	.global BattleFrontier_BattlePikeThreePathRoom_Text_DreadfulPresence
@ END GENERATED LOCALIZATION EXPORTS
