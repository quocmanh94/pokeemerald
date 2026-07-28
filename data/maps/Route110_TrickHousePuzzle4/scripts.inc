Route110_TrickHousePuzzle4_MapScripts::
	.byte 0

Route110_TrickHousePuzzle4_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_4_STATE, 0, Route110_TrickHousePuzzle4_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle4_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_4_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle4_EventScript_Cora::
	trainerbattle_single TRAINER_CORA, Route110_TrickHousePuzzle4_Text_CoraIntro, Route110_TrickHousePuzzle4_Text_CoraDefeat
	msgbox Route110_TrickHousePuzzle4_Text_CoraPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle4_EventScript_Yuji::
	trainerbattle_single TRAINER_YUJI, Route110_TrickHousePuzzle4_Text_YujiIntro, Route110_TrickHousePuzzle4_Text_YujiDefeat
	msgbox Route110_TrickHousePuzzle4_Text_YujiPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle4_EventScript_Paula::
	trainerbattle_single TRAINER_PAULA, Route110_TrickHousePuzzle4_Text_PaulaIntro, Route110_TrickHousePuzzle4_Text_PaulaDefeat
	msgbox Route110_TrickHousePuzzle4_Text_PaulaPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle4_Text_WroteSecretCodeLockOpened:
	.string "{PLAYER} ghi lại mật mã trên cửa.\p"
	.string "“TRICK MASTER thật ngầu.” ... ... ... ... ...\n"
	.string "... ... ...\p"
	.string "Ổ khóa bật mở đánh tách!$"

Route110_TrickHousePuzzle4_Text_CoraIntro:
	.string "Nghĩ cách giải phiền phức quá. Tôi chỉ\n"
	.string "muốn chiến đấu thôi!$"

Route110_TrickHousePuzzle4_Text_CoraDefeat:
	.string "Dù thua, tôi vẫn thích chiến đấu nhất!$"

Route110_TrickHousePuzzle4_Text_CoraPostBattle:
	.string "Bạn cũng thấy vậy chứ? Hễ nơi nào có\n"
	.string "HLV là bạn sẽ đi đến đó.$"

Route110_TrickHousePuzzle4_Text_YujiIntro:
	.string "Hê! Mấy tảng đá thế này, tôi chỉ cần một\n"
	.string "ngón tay là gạt đi được!$"

Route110_TrickHousePuzzle4_Text_YujiDefeat:
	.string "Tôi đẩy được đá, nhưng lại không giải\n"
	.string "nổi câu đố...$"

Route110_TrickHousePuzzle4_Text_YujiPostBattle:
	.string "Chỉ có cơ bắp thôi chưa đủ... Còn phải\n"
	.string "biết động não. Phải có đầu óc nữa!$"

Route110_TrickHousePuzzle4_Text_PaulaIntro:
	.string "TRICK HOUSE ngày càng hóc búa hơn,\n"
	.string "đúng không?$"

Route110_TrickHousePuzzle4_Text_PaulaDefeat:
	.string "Ááá!$"

Route110_TrickHousePuzzle4_Text_PaulaPostBattle:
	.string "Đã có ai đi đến cuối chưa?$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global Route110_TrickHousePuzzle4_Text_WroteSecretCodeLockOpened
	.global Route110_TrickHousePuzzle4_Text_CoraIntro
	.global Route110_TrickHousePuzzle4_Text_CoraDefeat
	.global Route110_TrickHousePuzzle4_Text_CoraPostBattle
	.global Route110_TrickHousePuzzle4_Text_YujiIntro
	.global Route110_TrickHousePuzzle4_Text_YujiDefeat
	.global Route110_TrickHousePuzzle4_Text_YujiPostBattle
	.global Route110_TrickHousePuzzle4_Text_PaulaIntro
	.global Route110_TrickHousePuzzle4_Text_PaulaDefeat
	.global Route110_TrickHousePuzzle4_Text_PaulaPostBattle
@ END GENERATED LOCALIZATION EXPORTS
