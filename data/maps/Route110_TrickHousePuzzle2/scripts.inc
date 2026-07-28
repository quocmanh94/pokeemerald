Route110_TrickHousePuzzle2_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Route110_TrickHousePuzzle2_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_TrickHousePuzzle2_OnTransition
	.byte 0

Route110_TrickHousePuzzle2_OnResume:
	call_if_eq VAR_TEMP_1, 1, Route110_TrickHousePuzzle2_EventScript_PressButton1
	call_if_eq VAR_TEMP_2, 1, Route110_TrickHousePuzzle2_EventScript_PressButton2
	call_if_eq VAR_TEMP_3, 1, Route110_TrickHousePuzzle2_EventScript_PressButton3
	call_if_eq VAR_TEMP_4, 1, Route110_TrickHousePuzzle2_EventScript_PressButton4
	end

Route110_TrickHousePuzzle2_OnTransition:
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, 0
	setvar VAR_TEMP_3, 0
	setvar VAR_TEMP_4, 0
	end

Route110_TrickHousePuzzle2_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_2_STATE, 0, Route110_TrickHousePuzzle2_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle2_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_2_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle2_EventScript_Button1::
	lockall
	setvar VAR_TEMP_1, 1
	playse SE_PIN
	call Route110_TrickHousePuzzle2_EventScript_PressButton1
	special DrawWholeMapView
	releaseall
	end

Route110_TrickHousePuzzle2_EventScript_Button2::
	lockall
	setvar VAR_TEMP_2, 1
	playse SE_PIN
	call Route110_TrickHousePuzzle2_EventScript_PressButton2
	special DrawWholeMapView
	releaseall
	end

Route110_TrickHousePuzzle2_EventScript_Button3::
	lockall
	setvar VAR_TEMP_3, 1
	playse SE_PIN
	call Route110_TrickHousePuzzle2_EventScript_PressButton3
	special DrawWholeMapView
	releaseall
	end

Route110_TrickHousePuzzle2_EventScript_Button4::
	lockall
	setvar VAR_TEMP_4, 1
	playse SE_PIN
	call Route110_TrickHousePuzzle2_EventScript_PressButton4
	special DrawWholeMapView
	releaseall
	end

Route110_TrickHousePuzzle2_EventScript_PressButton1::
	setmetatile 11, 12, METATILE_TrickHousePuzzle_Button_Pressed, FALSE
	setmetatile 1, 13, METATILE_TrickHousePuzzle_Door_Shuttered, FALSE
	return

Route110_TrickHousePuzzle2_EventScript_PressButton2::
	setmetatile 0, 4, METATILE_TrickHousePuzzle_Button_Pressed, FALSE
	setmetatile 5, 6, METATILE_TrickHousePuzzle_Door_Shuttered, FALSE
	return

Route110_TrickHousePuzzle2_EventScript_PressButton3::
	setmetatile 14, 5, METATILE_TrickHousePuzzle_Button_Pressed, FALSE
	setmetatile 7, 15, METATILE_TrickHousePuzzle_Door_Shuttered, FALSE
	return

Route110_TrickHousePuzzle2_EventScript_PressButton4::
	setmetatile 7, 11, METATILE_TrickHousePuzzle_Button_Pressed, FALSE
	setmetatile 14, 12, METATILE_TrickHousePuzzle_Door_Shuttered, FALSE
	return

Route110_TrickHousePuzzle2_EventScript_Ted::
	trainerbattle_single TRAINER_TED, Route110_TrickHousePuzzle2_Text_TedIntro, Route110_TrickHousePuzzle2_Text_TedDefeat
	msgbox Route110_TrickHousePuzzle2_Text_TedPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle2_EventScript_Paul::
	trainerbattle_single TRAINER_PAUL, Route110_TrickHousePuzzle2_Text_PaulIntro, Route110_TrickHousePuzzle2_Text_PaulDefeat
	msgbox Route110_TrickHousePuzzle2_Text_PaulPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle2_EventScript_Georgia::
	trainerbattle_single TRAINER_GEORGIA, Route110_TrickHousePuzzle2_Text_GeorgiaIntro, Route110_TrickHousePuzzle2_Text_GeorgiaDefeat
	msgbox Route110_TrickHousePuzzle2_Text_GeorgiaPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle2_Text_WroteSecretCodeLockOpened:
	.string "{PLAYER} ghi lại mật mã trên cửa.\p"
	.string "“TRICK MASTER thật thông minh.” ... ... ...\n"
	.string "... ... ... ... ...\p"
	.string "Ổ khóa bật mở đánh tách!$"

Route110_TrickHousePuzzle2_Text_TedIntro:
	.string "Công tắc nào sẽ lấp cái hố nào nhỉ?$"

Route110_TrickHousePuzzle2_Text_TedDefeat:
	.string "Đấu xong tôi lại càng rối hơn!$"

Route110_TrickHousePuzzle2_Text_TedPostBattle:
	.string "Bạn bấm hết các nút giúp tôi được\n"
	.string "không?$"

Route110_TrickHousePuzzle2_Text_PaulIntro:
	.string "Ồ! Đây là lần thứ hai bạn thử sức tại\n"
	.string "TRICK HOUSE!$"

Route110_TrickHousePuzzle2_Text_PaulDefeat:
	.string "Bạn còn giỏi chiến đấu nữa sao?$"

Route110_TrickHousePuzzle2_Text_PaulPostBattle:
	.string "TRICK MASTER đã tự tay bố trí tất cả\n"
	.string "trò đánh đố trong ngôi nhà này.$"

Route110_TrickHousePuzzle2_Text_GeorgiaIntro:
	.string "Một ngày nào đó tôi muốn mở GYM của\n"
	.string "riêng mình. Vì thế, tôi đang học cách bố\l"
	.string "trí cạm bẫy.$"

Route110_TrickHousePuzzle2_Text_GeorgiaDefeat:
	.string "Tôi chưa học chiến đấu đủ kỹ!$"

Route110_TrickHousePuzzle2_Text_GeorgiaPostBattle:
	.string "Bạn mạnh thật đấy! Có khi còn đủ sức\n"
	.string "trở thành GYM LEADER!$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global Route110_TrickHousePuzzle2_Text_WroteSecretCodeLockOpened
	.global Route110_TrickHousePuzzle2_Text_TedIntro
	.global Route110_TrickHousePuzzle2_Text_TedDefeat
	.global Route110_TrickHousePuzzle2_Text_TedPostBattle
	.global Route110_TrickHousePuzzle2_Text_PaulIntro
	.global Route110_TrickHousePuzzle2_Text_PaulDefeat
	.global Route110_TrickHousePuzzle2_Text_PaulPostBattle
	.global Route110_TrickHousePuzzle2_Text_GeorgiaIntro
	.global Route110_TrickHousePuzzle2_Text_GeorgiaDefeat
	.global Route110_TrickHousePuzzle2_Text_GeorgiaPostBattle
@ END GENERATED LOCALIZATION EXPORTS
