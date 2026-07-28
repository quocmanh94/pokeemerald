BattleFrontier_BattlePyramidFloor_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattlePyramidFloor_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePyramidFloor_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattlePyramidFloor_OnTransition
	.byte 0

BattleFrontier_BattlePyramidFloor_OnFrame:
	map_script_2 VAR_TEMP_D, 1, BattleFrontier_BattlePyramidFloor_EventScript_UpdateLight
	map_script_2 VAR_TEMP_PLAYING_PYRAMID_MUSIC, 0, BattleFrontier_BattlePyramidFloor_EventScript_PlayPyramidMusic
	map_script_2 VAR_TEMP_F, 1, BattleFrontier_BattlePyramidFloor_EventScript_ShowMapName
	.2byte 0

BattleFrontier_BattlePyramidFloor_EventScript_UpdateLight::
	lockall
	@ pyramid_updatelight, cant use macro because it straddles the loop
	setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_UPDATE_LIGHT
	setvar VAR_0x8005, 4
	setvar VAR_0x8006, PYRAMID_LIGHT_INCR_RADIUS
	setvar VAR_0x8007, SE_SAVE
	setvar VAR_RESULT, 0
BattleFrontier_BattlePyramidFloor_EventScript_UpdateLightLoop::
	special CallBattlePyramidFunction
	delay 2
	goto_if_ne VAR_RESULT, 2, BattleFrontier_BattlePyramidFloor_EventScript_UpdateLightLoop
	setvar VAR_TEMP_D, 0
	releaseall
	end

BattleFrontier_BattlePyramidFloor_EventScript_ShowMapName::
	special ShowMapNamePopup
	setvar VAR_TEMP_F, 0
	end

BattleFrontier_BattlePyramidFloor_EventScript_PlayPyramidMusic::
	playbgm MUS_B_PYRAMID, FALSE
	setvar VAR_TEMP_PLAYING_PYRAMID_MUSIC, 1
	end

BattleFrontier_BattlePyramidFloor_OnResume:
	pyramid_setfloorpal
	frontier_getstatus
	switch VAR_TEMP_CHALLENGE_STATUS
	case 0, BattleFrontier_BattlePyramidFloor_EventScript_ReadyChallenge
	case CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePyramid_EventScript_WarpToLobby
	case CHALLENGE_STATUS_PAUSED, BattleFrontier_BattlePyramidFloor_EventScript_ReadyChallenge
	frontier_get FRONTIER_DATA_BATTLE_OUTCOME
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, BattleFrontier_BattlePyramidFloor_EventScript_ResetParty
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, BattleFrontier_BattlePyramidFloor_EventScript_ResetParty
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidFloor_EventScript_ResetParty
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
	goto_if_eq VAR_RESULT, B_OUTCOME_DREW, BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
	goto_if_eq VAR_RESULT, B_OUTCOME_FORFEITED, BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
	frontier_isbattletype BATTLE_TYPE_TRAINER  @ VAR_RESULT seems to be ignored here
	setvar VAR_TEMP_D, 1
BattleFrontier_BattlePyramidFloor_EventScript_ResetParty::
	pyramid_resetparty
	end

BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST
	pyramid_set PYRAMID_DATA_TRAINER_FLAGS, 255
BattleFrontier_BattlePyramid_EventScript_WarpToLobby::
	pyramid_updatelight 0, PYRAMID_LIGHT_SET_RADIUS
	pyramid_clearhelditems
	special HealPlayerParty
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_LOBBY, 7, 13
	waitstate
	end

BattleFrontier_BattlePyramidFloor_EventScript_ReadyChallenge::
	pyramid_save CHALLENGE_STATUS_SAVING
	special SavePlayerParty
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	pyramid_settrainers
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	setvar VAR_TEMP_F, 1
	end

BattleFrontier_BattlePyramidFloor_OnTransition:
	call BattleFrontier_BattlePyramidFloor_EventScript_SetLightRadius
	setvar VAR_TEMP_F, 1
	end

BattleFrontier_BattlePyramidFloor_EventScript_SetLightRadius::
	pyramid_updatelight 32, PYRAMID_LIGHT_SET_RADIUS
	return

BattlePyramid_WarpToNextFloor::
	call BattleFrontier_EventScript_IncrementWinStreak
	frontier_get FRONTIER_DATA_BATTLE_NUM  @ Floor number
	addvar VAR_RESULT, 1
	frontier_set FRONTIER_DATA_BATTLE_NUM, VAR_RESULT
	goto_if_eq VAR_RESULT, 7, BattlePyramid_WarpToTop
	pyramid_seedfloor
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_RESULT, 0
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR, 1, 1
	waitstate
	end

BattlePyramid_WarpToTop::
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_TOP, 17, 17
	waitstate
	end

@ TRAINER_PHILLIP is used as a placeholder
BattlePyramid_TrainerBattle::
	trainerbattle TRAINER_BATTLE_PYRAMID, TRAINER_PHILLIP, LOCALID_NONE, BattleFacility_TrainerBattle_PlaceholderText, BattleFacility_TrainerBattle_PlaceholderText
	pyramid_showhint
	waitmessage
	waitbuttonpress
	closemessage
	releaseall
	end

BattlePyramid_FindItemBall::
	pyramid_setitem
	callstd STD_FIND_ITEM
	goto_if_eq VAR_0x8007, 0, BattlePyramid_FindItemBallEnd
	pyramid_hideitem
BattlePyramid_FindItemBallEnd::
	end

BattlePyramid_Retire::
	goto BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost

@ Also used by Trainer Hill
BattleFacility_TrainerBattle_PlaceholderText:
	.string "Đây là một tin nhắn mẫu.$"

gText_BattlePyramidConfirmRest::
	.string "Tiến trình chinh phục BATTLE PYRAMID\n"
	.string "của bạn sẽ được lưu để bạn có thể tạm\l"
	.string "thoát. Bạn đồng ý chứ?$"

gText_BattlePyramidConfirmRetire::
	.string "Bạn có chắc muốn từ bỏ hành trình\n"
	.string "chinh phục PYRAMID không?$"

BattlePyramid_Text_ExitHintUp1::
	.string "Lối ra của tầng này nằm\n"
	.string "ở hướng đó: {UP_ARROW}$"

BattlePyramid_Text_ExitHintLeft1::
	.string "Lối ra của tầng này nằm\n"
	.string "ở hướng đó: {LEFT_ARROW}$"

BattlePyramid_Text_ExitHintRight1::
	.string "Lối ra của tầng này nằm\n"
	.string "ở hướng đó: {RIGHT_ARROW}$"

BattlePyramid_Text_ExitHintDown1::
	.string "Lối ra của tầng này nằm\n"
	.string "ở hướng đó: {DOWN_ARROW}$"

BattlePyramid_Text_ExitHintUp2::
	.string "Lối ra ở tầng này nằm\n"
	.string "theo hướng {UP_ARROW}.$"

BattlePyramid_Text_ExitHintLeft2::
	.string "Lối ra ở tầng này nằm\n"
	.string "theo hướng {LEFT_ARROW}.$"

BattlePyramid_Text_ExitHintRight2::
	.string "Lối ra ở tầng này nằm\n"
	.string "theo hướng {RIGHT_ARROW}.$"

BattlePyramid_Text_ExitHintDown2::
	.string "Lối ra ở tầng này nằm\n"
	.string "theo hướng {DOWN_ARROW}.$"

BattlePyramid_Text_ExitHintUp3::
	.string "Lối ra ở phía\n"
	.string "hướng {UP_ARROW} kia.$"

BattlePyramid_Text_ExitHintLeft3::
	.string "Lối ra ở phía\n"
	.string "hướng {LEFT_ARROW} kia.$"

BattlePyramid_Text_ExitHintRight3::
	.string "Lối ra ở phía\n"
	.string "hướng {RIGHT_ARROW} kia.$"

BattlePyramid_Text_ExitHintDown3::
	.string "Lối ra ở phía\n"
	.string "hướng {DOWN_ARROW} kia.$"

BattlePyramid_Text_ExitHintUp4::
	.string "Ở tầng này, lối ra nằm đâu đó\n"
	.string "theo hướng {UP_ARROW}.$"

BattlePyramid_Text_ExitHintLeft4::
	.string "Ở tầng này, lối ra nằm đâu đó\n"
	.string "theo hướng {LEFT_ARROW}.$"

BattlePyramid_Text_ExitHintRight4::
	.string "Ở tầng này, lối ra nằm đâu đó\n"
	.string "theo hướng {RIGHT_ARROW}.$"

BattlePyramid_Text_ExitHintDown4::
	.string "Ở tầng này, lối ra nằm đâu đó\n"
	.string "theo hướng {DOWN_ARROW}.$"

BattlePyramid_Text_ExitHintUp5::
	.string "Lối ra à?\n"
	.string "Ở hướng {UP_ARROW} đó.$"

BattlePyramid_Text_ExitHintLeft5::
	.string "Lối ra à?\n"
	.string "Ở hướng {LEFT_ARROW} đó.$"

BattlePyramid_Text_ExitHintRight5::
	.string "Lối ra à?\n"
	.string "Ở hướng {RIGHT_ARROW} đó.$"

BattlePyramid_Text_ExitHintDown5::
	.string "Lối ra à?\n"
	.string "Ở hướng {DOWN_ARROW} đó.$"

BattlePyramid_Text_ExitHintUp6::
	.string "Lối ra tình cờ nằm\n"
	.string "theo hướng {UP_ARROW}.$"

BattlePyramid_Text_ExitHintLeft6::
	.string "Lối ra tình cờ nằm\n"
	.string "theo hướng {LEFT_ARROW}.$"

BattlePyramid_Text_ExitHintRight6::
	.string "Lối ra tình cờ nằm\n"
	.string "theo hướng {RIGHT_ARROW}.$"

BattlePyramid_Text_ExitHintDown6::
	.string "Lối ra tình cờ nằm\n"
	.string "theo hướng {DOWN_ARROW}.$"

BattlePyramid_Text_EightItemsRemaining1::
	.string "Bạn đang tìm vật phẩm à?\p"
	.string "Vẫn còn tám vật phẩm chưa được tìm\n"
	.string "thấy.$"

BattlePyramid_Text_SevenItemsRemaining1::
	.string "Bạn đang tìm vật phẩm à?\p"
	.string "Vẫn còn bảy vật phẩm chưa được tìm\n"
	.string "thấy.$"

BattlePyramid_Text_SixItemsRemaining1::
	.string "Bạn đang tìm vật phẩm à?\p"
	.string "Vẫn còn sáu vật phẩm chưa được tìm\n"
	.string "thấy.$"

BattlePyramid_Text_FiveItemsRemaining1::
	.string "Bạn đang tìm vật phẩm à?\p"
	.string "Vẫn còn năm vật phẩm chưa được tìm\n"
	.string "thấy.$"

BattlePyramid_Text_FourItemsRemaining1::
	.string "Bạn đang tìm vật phẩm à?\p"
	.string "Vẫn còn bốn vật phẩm chưa được tìm\n"
	.string "thấy.$"

BattlePyramid_Text_ThreeItemsRemaining1::
	.string "Bạn đang tìm vật phẩm à?\p"
	.string "Vẫn còn ba vật phẩm chưa được tìm\n"
	.string "thấy.$"

BattlePyramid_Text_TwoItemsRemaining1::
	.string "Bạn đang tìm vật phẩm à?\p"
	.string "Vẫn còn hai vật phẩm chưa được tìm\n"
	.string "thấy.$"

BattlePyramid_Text_OneItemRemaining1::
	.string "Bạn đang tìm vật phẩm à?\p"
	.string "Vẫn còn một vật phẩm chưa được tìm\n"
	.string "thấy.$"

BattlePyramid_Text_ZeroItemsRemaining1::
	.string "Bạn đang tìm vật phẩm à?\p"
	.string "Không còn gì để tìm nữa!$"

BattlePyramid_Text_EightItemsRemaining2::
	.string "Vì bạn đã thắng, tôi sẽ bật mí một bí\n"
	.string "mật nhỏ!\p"
	.string "Có tám vật phẩm nằm rải rác quanh đây.$"

BattlePyramid_Text_SevenItemsRemaining2::
	.string "Vì bạn đã thắng, tôi sẽ bật mí một bí\n"
	.string "mật nhỏ!\p"
	.string "Vẫn còn bảy vật phẩm nằm rải rác quanh\n"
	.string "đây.$"

BattlePyramid_Text_SixItemsRemaining2::
	.string "Vì bạn đã thắng, tôi sẽ bật mí một bí\n"
	.string "mật nhỏ!\p"
	.string "Vẫn còn sáu vật phẩm nằm rải rác quanh\n"
	.string "đây.$"

BattlePyramid_Text_FiveItemsRemaining2::
	.string "Vì bạn đã thắng, tôi sẽ bật mí một bí\n"
	.string "mật nhỏ!\p"
	.string "Vẫn còn năm vật phẩm nằm rải rác quanh\n"
	.string "đây.$"

BattlePyramid_Text_FourItemsRemaining2::
	.string "Vì bạn đã thắng, tôi sẽ bật mí một bí\n"
	.string "mật nhỏ!\p"
	.string "Vẫn còn bốn vật phẩm nằm rải rác quanh\n"
	.string "đây.$"

BattlePyramid_Text_ThreeItemsRemaining2::
	.string "Vì bạn đã thắng, tôi sẽ bật mí một bí\n"
	.string "mật nhỏ!\p"
	.string "Vẫn còn ba vật phẩm nằm rải rác quanh\n"
	.string "đây.$"

BattlePyramid_Text_TwoItemsRemaining2::
	.string "Vì bạn đã thắng, tôi sẽ bật mí một bí\n"
	.string "mật nhỏ!\p"
	.string "Vẫn còn hai vật phẩm nằm rải rác quanh\n"
	.string "đây.$"

BattlePyramid_Text_OneItemRemaining2::
	.string "Vì bạn đã thắng, tôi sẽ bật mí một bí\n"
	.string "mật nhỏ!\p"
	.string "Chỉ có một vật phẩm nằm đâu đó quanh\n"
	.string "đây.$"

BattlePyramid_Text_ZeroItemsRemaining2::
	.string "Vì bạn đã thắng, tôi sẽ bật mí một bí\n"
	.string "mật nhỏ!\p"
	.string "Quanh đây không còn gì nữa.$"

BattlePyramid_Text_EightItemsRemaining3::
	.string "Vật phẩm dự trữ của bạn còn đủ dùng\n"
	.string "chứ?\p"
	.string "Tôi đoán tầng này vẫn còn tám vật phẩm\n"
	.string "đang chờ được tìm thấy.$"

BattlePyramid_Text_SevenItemsRemaining3::
	.string "Vật phẩm dự trữ của bạn còn đủ dùng\n"
	.string "chứ?\p"
	.string "Tôi đoán tầng này vẫn còn bảy vật phẩm\n"
	.string "đang chờ được tìm thấy.$"

BattlePyramid_Text_SixItemsRemaining3::
	.string "Vật phẩm dự trữ của bạn còn đủ dùng\n"
	.string "chứ?\p"
	.string "Tôi đoán tầng này vẫn còn sáu vật phẩm\n"
	.string "đang chờ được tìm thấy.$"

BattlePyramid_Text_FiveItemsRemaining3::
	.string "Vật phẩm dự trữ của bạn còn đủ dùng\n"
	.string "chứ?\p"
	.string "Tôi đoán tầng này vẫn còn năm vật phẩm\n"
	.string "đang chờ được tìm thấy.$"

BattlePyramid_Text_FourItemsRemaining3::
	.string "Vật phẩm dự trữ của bạn còn đủ dùng\n"
	.string "chứ?\p"
	.string "Tôi đoán tầng này vẫn còn bốn vật phẩm\n"
	.string "đang chờ được tìm thấy.$"

BattlePyramid_Text_ThreeItemsRemaining3::
	.string "Vật phẩm dự trữ của bạn còn đủ dùng\n"
	.string "chứ?\p"
	.string "Tôi đoán tầng này vẫn còn ba vật phẩm\n"
	.string "đang chờ được tìm thấy.$"

BattlePyramid_Text_TwoItemsRemaining3::
	.string "Vật phẩm dự trữ của bạn còn đủ dùng\n"
	.string "chứ?\p"
	.string "Tôi đoán tầng này vẫn còn hai vật phẩm\n"
	.string "đang chờ được tìm thấy.$"

BattlePyramid_Text_OneItemRemaining3::
	.string "Vật phẩm dự trữ của bạn còn đủ dùng\n"
	.string "chứ?\p"
	.string "Tôi đoán tầng này chỉ còn một vật phẩm\n"
	.string "đang chờ được tìm thấy.$"

BattlePyramid_Text_ZeroItemsRemaining3::
	.string "Vật phẩm dự trữ của bạn còn đủ dùng\n"
	.string "chứ?\p"
	.string "Tôi đoán tầng này không còn vật phẩm\n"
	.string "nào chờ được tìm thấy nữa. Bảo trọng\l"
	.string "nhé!$"

BattlePyramid_Text_EightItemsRemaining4::
	.string "Bạn mạnh lắm, nên xứng đáng nhận một\n"
	.string "gợi ý!\p"
	.string "Có vẻ vẫn còn tám vật phẩm trên mặt\n"
	.string "đất.$"

BattlePyramid_Text_SevenItemsRemaining4::
	.string "Bạn mạnh lắm, nên xứng đáng nhận một\n"
	.string "gợi ý!\p"
	.string "Có vẻ vẫn còn bảy vật phẩm trên mặt\n"
	.string "đất.$"

BattlePyramid_Text_SixItemsRemaining4::
	.string "Bạn mạnh lắm, nên xứng đáng nhận một\n"
	.string "gợi ý!\p"
	.string "Có vẻ vẫn còn sáu vật phẩm trên mặt\n"
	.string "đất.$"

BattlePyramid_Text_FiveItemsRemaining4::
	.string "Bạn mạnh lắm, nên xứng đáng nhận một\n"
	.string "gợi ý!\p"
	.string "Có vẻ vẫn còn năm vật phẩm trên mặt\n"
	.string "đất.$"

BattlePyramid_Text_FourItemsRemaining4::
	.string "Bạn mạnh lắm, nên xứng đáng nhận một\n"
	.string "gợi ý!\p"
	.string "Có vẻ vẫn còn bốn vật phẩm trên mặt\n"
	.string "đất.$"

BattlePyramid_Text_ThreeItemsRemaining4::
	.string "Bạn mạnh lắm, nên xứng đáng nhận một\n"
	.string "gợi ý!\p"
	.string "Có vẻ vẫn còn ba vật phẩm trên mặt đất.$"

BattlePyramid_Text_TwoItemsRemaining4::
	.string "Bạn mạnh lắm, nên xứng đáng nhận một\n"
	.string "gợi ý!\p"
	.string "Có vẻ vẫn còn hai vật phẩm trên mặt đất.$"

BattlePyramid_Text_OneItemRemaining4::
	.string "Bạn mạnh lắm, nên xứng đáng nhận một\n"
	.string "gợi ý!\p"
	.string "Có vẻ chỉ còn một vật phẩm trên mặt\n"
	.string "đất.$"

BattlePyramid_Text_ZeroItemsRemaining4::
	.string "Bạn mạnh lắm, nên xứng đáng nhận một\n"
	.string "gợi ý!\p"
	.string "Có vẻ không còn vật phẩm nào trên mặt\n"
	.string "đất.$"

BattlePyramid_Text_EightItemsRemaining5::
	.string "Nghe nói ở tầng này của PYRAMID có tám\n"
	.string "vật phẩm...$"

BattlePyramid_Text_SevenItemsRemaining5::
	.string "Nghe nói ở tầng này của PYRAMID có bảy\n"
	.string "vật phẩm...$"

BattlePyramid_Text_SixItemsRemaining5::
	.string "Nghe nói ở tầng này của PYRAMID có sáu\n"
	.string "vật phẩm...$"

BattlePyramid_Text_FiveItemsRemaining5::
	.string "Nghe nói ở tầng này của PYRAMID có năm\n"
	.string "vật phẩm...$"

BattlePyramid_Text_FourItemsRemaining5::
	.string "Nghe nói ở tầng này của PYRAMID có bốn\n"
	.string "vật phẩm...$"

BattlePyramid_Text_ThreeItemsRemaining5::
	.string "Nghe nói ở tầng này của PYRAMID có ba\n"
	.string "vật phẩm...$"

BattlePyramid_Text_TwoItemsRemaining5::
	.string "Nghe nói ở tầng này của PYRAMID có hai\n"
	.string "vật phẩm...$"

BattlePyramid_Text_OneItemRemaining5::
	.string "Nghe nói ở tầng này của PYRAMID có một\n"
	.string "vật phẩm...$"

BattlePyramid_Text_ZeroItemsRemaining5::
	.string "Nghe nói ở tầng này của PYRAMID không\n"
	.string "có vật phẩm nào...$"

BattlePyramid_Text_EightItemsRemaining6::
	.string "Bạn đã thu thập được vật phẩm nào\n"
	.string "chưa?\p"
	.string "Tôi tin tầng này vẫn còn tám vật phẩm.$"

BattlePyramid_Text_SevenItemsRemaining6::
	.string "Bạn đã thu thập được vật phẩm nào\n"
	.string "chưa?\p"
	.string "Tôi tin tầng này vẫn còn bảy vật phẩm.$"

BattlePyramid_Text_SixItemsRemaining6::
	.string "Bạn đã thu thập được vật phẩm nào\n"
	.string "chưa?\p"
	.string "Tôi tin tầng này vẫn còn sáu vật phẩm.$"

BattlePyramid_Text_FiveItemsRemaining6::
	.string "Bạn đã thu thập được vật phẩm nào\n"
	.string "chưa?\p"
	.string "Tôi tin tầng này vẫn còn năm vật phẩm.$"

BattlePyramid_Text_FourItemsRemaining6::
	.string "Bạn đã thu thập được vật phẩm nào\n"
	.string "chưa?\p"
	.string "Tôi tin tầng này vẫn còn bốn vật phẩm.$"

BattlePyramid_Text_ThreeItemsRemaining6::
	.string "Bạn đã thu thập được vật phẩm nào\n"
	.string "chưa?\p"
	.string "Tôi tin tầng này vẫn còn ba vật phẩm.$"

BattlePyramid_Text_TwoItemsRemaining6::
	.string "Bạn đã thu thập được vật phẩm nào\n"
	.string "chưa?\p"
	.string "Tôi tin tầng này vẫn còn hai vật phẩm.$"

BattlePyramid_Text_OneItemRemaining6::
	.string "Bạn đã thu thập được vật phẩm nào\n"
	.string "chưa?\p"
	.string "Tôi tin tầng này vẫn còn một vật phẩm.$"

BattlePyramid_Text_ZeroItemsRemaining6::
	.string "Bạn đã thu thập được vật phẩm nào\n"
	.string "chưa?\p"
	.string "Tôi tin tầng này không còn vật phẩm nào\n"
	.string "nữa.$"

BattlePyramid_Text_SevenTrainersRemaining1::
	.string "Bạn thật sự rất tuyệt!\p"
	.string "Nhưng ngoài tôi ra vẫn còn bảy\n"
	.string "HLV đáng gờm!$"

BattlePyramid_Text_SixTrainersRemaining1::
	.string "Bạn thật sự rất tuyệt!\p"
	.string "Nhưng ngoài tôi ra vẫn còn sáu\n"
	.string "HLV đáng gờm!$"

BattlePyramid_Text_FiveTrainersRemaining1::
	.string "Bạn thật sự rất tuyệt!\p"
	.string "Nhưng ngoài tôi ra vẫn còn năm\n"
	.string "HLV đáng gờm!$"

BattlePyramid_Text_FourTrainersRemaining1::
	.string "Bạn thật sự rất tuyệt!\p"
	.string "Nhưng ngoài tôi ra vẫn còn bốn\n"
	.string "HLV đáng gờm!$"

BattlePyramid_Text_ThreeTrainersRemaining1::
	.string "Bạn thật sự rất tuyệt!\p"
	.string "Nhưng ngoài tôi ra vẫn còn ba HLV\n"
	.string "đáng gờm!$"

BattlePyramid_Text_TwoTrainersRemaining1::
	.string "Bạn thật sự rất tuyệt!\p"
	.string "Nhưng ngoài tôi ra vẫn còn hai HLV\n"
	.string "đáng gờm!$"

BattlePyramid_Text_OneTrainersRemaining1::
	.string "Bạn thật sự rất tuyệt!\p"
	.string "Nhưng ngoài tôi ra vẫn còn một HLV\n"
	.string "đáng gờm!$"

BattlePyramid_Text_ZeroTrainersRemaining1::
	.string "Bạn thật sự rất tuyệt!\p"
	.string "Không còn ai có thể đánh bại bạn nữa!$"

BattlePyramid_Text_SevenTrainersRemaining2::
	.string "Bực mình quá!\p"
	.string "Nhưng vẫn còn bảy HLV! Sẽ có\n"
	.string "người cho bạn biết thế nào là khiêm\l"
	.string "tốn!$"

BattlePyramid_Text_SixTrainersRemaining2::
	.string "Bực mình quá!\p"
	.string "Nhưng vẫn còn sáu HLV! Sẽ có\n"
	.string "người cho bạn biết thế nào là khiêm\l"
	.string "tốn!$"

BattlePyramid_Text_FiveTrainersRemaining2::
	.string "Bực mình quá!\p"
	.string "Nhưng vẫn còn năm HLV! Sẽ có\n"
	.string "người cho bạn biết thế nào là khiêm\l"
	.string "tốn!$"

BattlePyramid_Text_FourTrainersRemaining2::
	.string "Bực mình quá!\p"
	.string "Nhưng vẫn còn bốn HLV! Sẽ có\n"
	.string "người cho bạn biết thế nào là khiêm\l"
	.string "tốn!$"

BattlePyramid_Text_ThreeTrainersRemaining2::
	.string "Bực mình quá!\p"
	.string "Nhưng vẫn còn ba HLV! Sẽ có\n"
	.string "người cho bạn biết thế nào là khiêm\l"
	.string "tốn!$"

BattlePyramid_Text_TwoTrainersRemaining2::
	.string "Bực mình quá!\p"
	.string "Nhưng vẫn còn hai HLV! Sẽ có\n"
	.string "người cho bạn biết thế nào là khiêm\l"
	.string "tốn!$"

BattlePyramid_Text_OneTrainersRemaining2::
	.string "Bực mình quá!\p"
	.string "Nhưng vẫn còn một HLV! Tôi chắc\n"
	.string "chắn người đó sẽ khiến bạn biết khiêm\l"
	.string "tốn!$"

BattlePyramid_Text_ZeroTrainersRemaining2::
	.string "Thật đáng buồn!\p"
	.string "Nhưng chẳng còn HLV nào có thể\n"
	.string "đấu với bạn nữa!$"

BattlePyramid_Text_SevenTrainersRemaining3::
	.string "Khá ấn tượng đấy!\p"
	.string "Nhưng tầng này vẫn còn bảy HLV.\n"
	.string "Bạn có thể đánh bại tất cả không?$"

BattlePyramid_Text_SixTrainersRemaining3::
	.string "Khá ấn tượng đấy!\p"
	.string "Nhưng tầng này vẫn còn sáu HLV.\n"
	.string "Bạn có thể đánh bại tất cả không?$"

BattlePyramid_Text_FiveTrainersRemaining3::
	.string "Khá ấn tượng đấy!\p"
	.string "Nhưng tầng này vẫn còn năm HLV.\n"
	.string "Bạn có thể đánh bại tất cả không?$"

BattlePyramid_Text_FourTrainersRemaining3::
	.string "Khá ấn tượng đấy!\p"
	.string "Nhưng tầng này vẫn còn bốn HLV.\n"
	.string "Bạn có thể đánh bại tất cả không?$"

BattlePyramid_Text_ThreeTrainersRemaining3::
	.string "Khá ấn tượng đấy!\p"
	.string "Nhưng tầng này vẫn còn ba HLV. Bạn\n"
	.string "có thể đánh bại tất cả không?$"

BattlePyramid_Text_TwoTrainersRemaining3::
	.string "Khá ấn tượng đấy!\p"
	.string "Nhưng tầng này vẫn còn hai HLV.\n"
	.string "Bạn có thể đánh bại cả hai không?$"

BattlePyramid_Text_OneTrainersRemaining3::
	.string "Khá ấn tượng đấy!\p"
	.string "Nhưng tầng này vẫn còn một HLV.\n"
	.string "Bạn có thể chiến thắng không?$"

BattlePyramid_Text_ZeroTrainersRemaining3::
	.string "Khá ấn tượng đấy!\p"
	.string "Bạn đã vượt qua tất cả HLV trên\n"
	.string "tầng này.$"

BattlePyramid_Text_SevenTrainersRemaining4::
	.string "Có lẽ bạn có thể quét sạch bảy HLV\n"
	.string "còn lại trên tầng này.$"

BattlePyramid_Text_SixTrainersRemaining4::
	.string "Có lẽ bạn có thể quét sạch sáu HLV\n"
	.string "còn lại trên tầng này.$"

BattlePyramid_Text_FiveTrainersRemaining4::
	.string "Có lẽ bạn có thể quét sạch năm HLV\n"
	.string "còn lại trên tầng này.$"

BattlePyramid_Text_FourTrainersRemaining4::
	.string "Có lẽ bạn có thể quét sạch bốn HLV\n"
	.string "còn lại trên tầng này.$"

BattlePyramid_Text_ThreeTrainersRemaining4::
	.string "Có lẽ bạn có thể quét sạch ba HLV\n"
	.string "còn lại trên tầng này.$"

BattlePyramid_Text_TwoTrainersRemaining4::
	.string "Có lẽ bạn có thể quét sạch hai HLV\n"
	.string "còn lại trên tầng này.$"

BattlePyramid_Text_OneTrainersRemaining4::
	.string "Có lẽ bạn có thể hoàn tất cuộc càn quét\n"
	.string "với HLV cuối cùng trên tầng này.$"

BattlePyramid_Text_ZeroTrainersRemaining4::
	.string "Giờ chẳng còn một ai có thể đánh bại\n"
	.string "bạn...$"

BattlePyramid_Text_SevenTrainersRemaining5::
	.string "Có lẽ bạn đủ sức đánh bại bảy HLV\n"
	.string "lão luyện còn lại.$"

BattlePyramid_Text_SixTrainersRemaining5::
	.string "Có lẽ bạn đủ sức đánh bại sáu HLV\n"
	.string "lão luyện còn lại.$"

BattlePyramid_Text_FiveTrainersRemaining5::
	.string "Có lẽ bạn đủ sức đánh bại năm HLV\n"
	.string "lão luyện còn lại.$"

BattlePyramid_Text_FourTrainersRemaining5::
	.string "Có lẽ bạn đủ sức đánh bại bốn HLV\n"
	.string "lão luyện còn lại.$"

BattlePyramid_Text_ThreeTrainersRemaining5::
	.string "Có lẽ bạn đủ sức đánh bại ba HLV\n"
	.string "lão luyện còn lại.$"

BattlePyramid_Text_TwoTrainersRemaining5::
	.string "Có lẽ bạn đủ sức đánh bại hai HLV\n"
	.string "lão luyện còn lại.$"

BattlePyramid_Text_OneTrainersRemaining5::
	.string "Có lẽ bạn đủ sức đánh bại HLV lão\n"
	.string "luyện cuối cùng.$"

BattlePyramid_Text_ZeroTrainersRemaining5::
	.string "Kỹ năng của bạn thật không chê vào đâu\n"
	.string "được.\p"
	.string "Không còn HLV nào ở đây có cơ hội\n"
	.string "đánh bại bạn.$"

BattlePyramid_Text_SevenTrainersRemaining6::
	.string "Bạn có thể tiếp tục chiến thắng trước\n"
	.string "bảy HLV còn lại không?$"

BattlePyramid_Text_SixTrainersRemaining6::
	.string "Bạn có thể tiếp tục chiến thắng trước\n"
	.string "sáu HLV còn lại không?$"

BattlePyramid_Text_FiveTrainersRemaining6::
	.string "Bạn có thể tiếp tục chiến thắng trước\n"
	.string "năm HLV còn lại không?$"

BattlePyramid_Text_FourTrainersRemaining6::
	.string "Bạn có thể tiếp tục chiến thắng trước\n"
	.string "bốn HLV còn lại không?$"

BattlePyramid_Text_ThreeTrainersRemaining6::
	.string "Bạn có thể tiếp tục chiến thắng trước\n"
	.string "ba HLV còn lại không?$"

BattlePyramid_Text_TwoTrainersRemaining6::
	.string "Bạn có thể tiếp tục chiến thắng trước\n"
	.string "hai HLV còn lại không?$"

BattlePyramid_Text_OneTrainersRemaining6::
	.string "Bạn có thể tiếp tục chiến thắng trước\n"
	.string "HLV cuối cùng không?$"

BattlePyramid_Text_ZeroTrainersRemaining6::
	.string "Giờ chẳng còn HLV nào có thể đối\n"
	.string "đầu với bạn...$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global BattleFacility_TrainerBattle_PlaceholderText
	.global gText_BattlePyramidConfirmRest
	.global gText_BattlePyramidConfirmRetire
	.global BattlePyramid_Text_ExitHintUp1
	.global BattlePyramid_Text_ExitHintLeft1
	.global BattlePyramid_Text_ExitHintRight1
	.global BattlePyramid_Text_ExitHintDown1
	.global BattlePyramid_Text_ExitHintUp2
	.global BattlePyramid_Text_ExitHintLeft2
	.global BattlePyramid_Text_ExitHintRight2
	.global BattlePyramid_Text_ExitHintDown2
	.global BattlePyramid_Text_ExitHintUp3
	.global BattlePyramid_Text_ExitHintLeft3
	.global BattlePyramid_Text_ExitHintRight3
	.global BattlePyramid_Text_ExitHintDown3
	.global BattlePyramid_Text_ExitHintUp4
	.global BattlePyramid_Text_ExitHintLeft4
	.global BattlePyramid_Text_ExitHintRight4
	.global BattlePyramid_Text_ExitHintDown4
	.global BattlePyramid_Text_ExitHintUp5
	.global BattlePyramid_Text_ExitHintLeft5
	.global BattlePyramid_Text_ExitHintRight5
	.global BattlePyramid_Text_ExitHintDown5
	.global BattlePyramid_Text_ExitHintUp6
	.global BattlePyramid_Text_ExitHintLeft6
	.global BattlePyramid_Text_ExitHintRight6
	.global BattlePyramid_Text_ExitHintDown6
	.global BattlePyramid_Text_EightItemsRemaining1
	.global BattlePyramid_Text_SevenItemsRemaining1
	.global BattlePyramid_Text_SixItemsRemaining1
	.global BattlePyramid_Text_FiveItemsRemaining1
	.global BattlePyramid_Text_FourItemsRemaining1
	.global BattlePyramid_Text_ThreeItemsRemaining1
	.global BattlePyramid_Text_TwoItemsRemaining1
	.global BattlePyramid_Text_OneItemRemaining1
	.global BattlePyramid_Text_ZeroItemsRemaining1
	.global BattlePyramid_Text_EightItemsRemaining2
	.global BattlePyramid_Text_SevenItemsRemaining2
	.global BattlePyramid_Text_SixItemsRemaining2
	.global BattlePyramid_Text_FiveItemsRemaining2
	.global BattlePyramid_Text_FourItemsRemaining2
	.global BattlePyramid_Text_ThreeItemsRemaining2
	.global BattlePyramid_Text_TwoItemsRemaining2
	.global BattlePyramid_Text_OneItemRemaining2
	.global BattlePyramid_Text_ZeroItemsRemaining2
	.global BattlePyramid_Text_EightItemsRemaining3
	.global BattlePyramid_Text_SevenItemsRemaining3
	.global BattlePyramid_Text_SixItemsRemaining3
	.global BattlePyramid_Text_FiveItemsRemaining3
	.global BattlePyramid_Text_FourItemsRemaining3
	.global BattlePyramid_Text_ThreeItemsRemaining3
	.global BattlePyramid_Text_TwoItemsRemaining3
	.global BattlePyramid_Text_OneItemRemaining3
	.global BattlePyramid_Text_ZeroItemsRemaining3
	.global BattlePyramid_Text_EightItemsRemaining4
	.global BattlePyramid_Text_SevenItemsRemaining4
	.global BattlePyramid_Text_SixItemsRemaining4
	.global BattlePyramid_Text_FiveItemsRemaining4
	.global BattlePyramid_Text_FourItemsRemaining4
	.global BattlePyramid_Text_ThreeItemsRemaining4
	.global BattlePyramid_Text_TwoItemsRemaining4
	.global BattlePyramid_Text_OneItemRemaining4
	.global BattlePyramid_Text_ZeroItemsRemaining4
	.global BattlePyramid_Text_EightItemsRemaining5
	.global BattlePyramid_Text_SevenItemsRemaining5
	.global BattlePyramid_Text_SixItemsRemaining5
	.global BattlePyramid_Text_FiveItemsRemaining5
	.global BattlePyramid_Text_FourItemsRemaining5
	.global BattlePyramid_Text_ThreeItemsRemaining5
	.global BattlePyramid_Text_TwoItemsRemaining5
	.global BattlePyramid_Text_OneItemRemaining5
	.global BattlePyramid_Text_ZeroItemsRemaining5
	.global BattlePyramid_Text_EightItemsRemaining6
	.global BattlePyramid_Text_SevenItemsRemaining6
	.global BattlePyramid_Text_SixItemsRemaining6
	.global BattlePyramid_Text_FiveItemsRemaining6
	.global BattlePyramid_Text_FourItemsRemaining6
	.global BattlePyramid_Text_ThreeItemsRemaining6
	.global BattlePyramid_Text_TwoItemsRemaining6
	.global BattlePyramid_Text_OneItemRemaining6
	.global BattlePyramid_Text_ZeroItemsRemaining6
	.global BattlePyramid_Text_SevenTrainersRemaining1
	.global BattlePyramid_Text_SixTrainersRemaining1
	.global BattlePyramid_Text_FiveTrainersRemaining1
	.global BattlePyramid_Text_FourTrainersRemaining1
	.global BattlePyramid_Text_ThreeTrainersRemaining1
	.global BattlePyramid_Text_TwoTrainersRemaining1
	.global BattlePyramid_Text_OneTrainersRemaining1
	.global BattlePyramid_Text_ZeroTrainersRemaining1
	.global BattlePyramid_Text_SevenTrainersRemaining2
	.global BattlePyramid_Text_SixTrainersRemaining2
	.global BattlePyramid_Text_FiveTrainersRemaining2
	.global BattlePyramid_Text_FourTrainersRemaining2
	.global BattlePyramid_Text_ThreeTrainersRemaining2
	.global BattlePyramid_Text_TwoTrainersRemaining2
	.global BattlePyramid_Text_OneTrainersRemaining2
	.global BattlePyramid_Text_ZeroTrainersRemaining2
	.global BattlePyramid_Text_SevenTrainersRemaining3
	.global BattlePyramid_Text_SixTrainersRemaining3
	.global BattlePyramid_Text_FiveTrainersRemaining3
	.global BattlePyramid_Text_FourTrainersRemaining3
	.global BattlePyramid_Text_ThreeTrainersRemaining3
	.global BattlePyramid_Text_TwoTrainersRemaining3
	.global BattlePyramid_Text_OneTrainersRemaining3
	.global BattlePyramid_Text_ZeroTrainersRemaining3
	.global BattlePyramid_Text_SevenTrainersRemaining4
	.global BattlePyramid_Text_SixTrainersRemaining4
	.global BattlePyramid_Text_FiveTrainersRemaining4
	.global BattlePyramid_Text_FourTrainersRemaining4
	.global BattlePyramid_Text_ThreeTrainersRemaining4
	.global BattlePyramid_Text_TwoTrainersRemaining4
	.global BattlePyramid_Text_OneTrainersRemaining4
	.global BattlePyramid_Text_ZeroTrainersRemaining4
	.global BattlePyramid_Text_SevenTrainersRemaining5
	.global BattlePyramid_Text_SixTrainersRemaining5
	.global BattlePyramid_Text_FiveTrainersRemaining5
	.global BattlePyramid_Text_FourTrainersRemaining5
	.global BattlePyramid_Text_ThreeTrainersRemaining5
	.global BattlePyramid_Text_TwoTrainersRemaining5
	.global BattlePyramid_Text_OneTrainersRemaining5
	.global BattlePyramid_Text_ZeroTrainersRemaining5
	.global BattlePyramid_Text_SevenTrainersRemaining6
	.global BattlePyramid_Text_SixTrainersRemaining6
	.global BattlePyramid_Text_FiveTrainersRemaining6
	.global BattlePyramid_Text_FourTrainersRemaining6
	.global BattlePyramid_Text_ThreeTrainersRemaining6
	.global BattlePyramid_Text_TwoTrainersRemaining6
	.global BattlePyramid_Text_OneTrainersRemaining6
	.global BattlePyramid_Text_ZeroTrainersRemaining6
@ END GENERATED LOCALIZATION EXPORTS
