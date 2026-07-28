Route110_TrickHousePuzzle6_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_TrickHousePuzzle6_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route110_TrickHousePuzzle6_OnWarp
	.byte 0

Route110_TrickHousePuzzle6_OnTransition:
	special RotatingGate_InitPuzzle
	end

Route110_TrickHousePuzzle6_OnWarp:
	map_script_2 VAR_TEMP_0, VAR_TEMP_0, Route110_TrickHousePuzzle6_EventScript_InitPuzzle
	.2byte 0

@ NOTE: This rotating gate puzzle makes use of VAR_TEMP_0 - VAR_TEMP_5
Route110_TrickHousePuzzle6_EventScript_InitPuzzle::
	special RotatingGate_InitPuzzleAndGraphics
	end

Route110_TrickHousePuzzle6_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_6_STATE, 0, Route110_TrickHousePuzzle6_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle6_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_6_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle6_EventScript_Sophia::
	trainerbattle_single TRAINER_SOPHIA, Route110_TrickHousePuzzle6_Text_SophiaIntro, Route110_TrickHousePuzzle6_Text_SophiaDefeat
	msgbox Route110_TrickHousePuzzle6_Text_SophiaPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle6_EventScript_Benny::
	trainerbattle_single TRAINER_BENNY, Route110_TrickHousePuzzle6_Text_BennyIntro, Route110_TrickHousePuzzle6_Text_BennyDefeat
	msgbox Route110_TrickHousePuzzle6_Text_BennyPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle6_EventScript_Sebastian::
	trainerbattle_single TRAINER_SEBASTIAN, Route110_TrickHousePuzzle6_Text_SebastianIntro, Route110_TrickHousePuzzle6_Text_SebastianDefeat
	msgbox Route110_TrickHousePuzzle6_Text_SebastianPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle6_Text_WroteSecretCodeLockOpened:
	.string "{PLAYER} ghi lại mật mã trên cửa.\p"
	.string "“TRICK MASTER là cuộc đời tôi.” ... ... ...\n"
	.string "... ... ... ... ...\p"
	.string "Ổ khóa bật mở đánh tách!$"

Route110_TrickHousePuzzle6_Text_SophiaIntro:
	.string "Nghe nói có một ngôi nhà kỳ lạ là tôi\n"
	.string "phải đến xem ngay.$"

Route110_TrickHousePuzzle6_Text_SophiaDefeat:
	.string "Tôi đã phát hiện ra một HLV lợi hại!$"

Route110_TrickHousePuzzle6_Text_SophiaPostBattle:
	.string "Tôi đang rất thích thú khi khám phá nơi\n"
	.string "này.\p"
	.string "Đây là thử thách đáng để tôi quay lại\n"
	.string "nhiều lần!$"

Route110_TrickHousePuzzle6_Text_BennyIntro:
	.string "Có lẽ tôi có thể cho BIRD POKéMON của\n"
	.string "mình bay qua bức tường...$"

Route110_TrickHousePuzzle6_Text_BennyDefeat:
	.string "Gwaaah! Tôi làm hỏng hết rồi!$"

Route110_TrickHousePuzzle6_Text_BennyPostBattle:
	.string "Ehehehe... Chắc tôi thua vì đã định gian\n"
	.string "lận.$"

Route110_TrickHousePuzzle6_Text_SebastianIntro:
	.string "Mấy cánh cửa xoay này làm tôi chóng mặt\n"
	.string "quá...$"

Route110_TrickHousePuzzle6_Text_SebastianDefeat:
	.string "Mọi thứ cứ quay vòng vòng. Tôi không\n"
	.string "chịu nổi nữa...$"

Route110_TrickHousePuzzle6_Text_SebastianPostBattle:
	.string "Bạn có vẻ chẳng bị ảnh hưởng chút nào.\n"
	.string "Hay bạn chỉ đang giữ vẻ mặt tỉnh bơ?$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global Route110_TrickHousePuzzle6_Text_WroteSecretCodeLockOpened
	.global Route110_TrickHousePuzzle6_Text_SophiaIntro
	.global Route110_TrickHousePuzzle6_Text_SophiaDefeat
	.global Route110_TrickHousePuzzle6_Text_SophiaPostBattle
	.global Route110_TrickHousePuzzle6_Text_BennyIntro
	.global Route110_TrickHousePuzzle6_Text_BennyDefeat
	.global Route110_TrickHousePuzzle6_Text_BennyPostBattle
	.global Route110_TrickHousePuzzle6_Text_SebastianIntro
	.global Route110_TrickHousePuzzle6_Text_SebastianDefeat
	.global Route110_TrickHousePuzzle6_Text_SebastianPostBattle
@ END GENERATED LOCALIZATION EXPORTS
