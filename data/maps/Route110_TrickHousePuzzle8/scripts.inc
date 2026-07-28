Route110_TrickHousePuzzle8_MapScripts::
	.byte 0

Route110_TrickHousePuzzle8_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_8_STATE, 0, Route110_TrickHousePuzzle8_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle8_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_8_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle8_EventScript_Vincent::
	trainerbattle_single TRAINER_VINCENT, Route110_TrickHousePuzzle8_Text_VincentIntro, Route110_TrickHousePuzzle8_Text_VincentDefeat
	msgbox Route110_TrickHousePuzzle8_Text_VincentPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle8_EventScript_Keira::
	trainerbattle_single TRAINER_KEIRA, Route110_TrickHousePuzzle8_Text_KeiraIntro, Route110_TrickHousePuzzle8_Text_KeiraDefeat
	msgbox Route110_TrickHousePuzzle8_Text_KeiraPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle8_EventScript_Leroy::
	trainerbattle_single TRAINER_LEROY, Route110_TrickHousePuzzle8_Text_LeroyIntro, Route110_TrickHousePuzzle8_Text_LeroyDefeat
	msgbox Route110_TrickHousePuzzle8_Text_LeroyPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle8_Text_WroteSecretCodeLockOpened::
	.string "{PLAYER} ghi lại mật mã trên cửa.\p"
	.string "“Tôi yêu TRICK MASTER.” ... ... ... ... ... ... ...\n"
	.string "...\p"
	.string "Ổ khóa bật mở đánh tách!$"

Route110_TrickHousePuzzle8_Text_VincentIntro:
	.string "Không có nhiều HLV đi được xa\n"
	.string "đến thế này.$"

Route110_TrickHousePuzzle8_Text_VincentDefeat:
	.string "Vậy hẳn là bạn cũng rất mạnh...$"

Route110_TrickHousePuzzle8_Text_VincentPostBattle:
	.string "Bạn đã đánh bại POKéMON LEAGUE\n"
	.string "CHAMPION sao? Thế thì ghê quá!$"

Route110_TrickHousePuzzle8_Text_KeiraIntro:
	.string "Hãy xem được chiến đấu với tôi là may\n"
	.string "mắn đi!$"

Route110_TrickHousePuzzle8_Text_KeiraDefeat:
	.string "Không thể nào! Tôi không thể thua\n"
	.string "được!$"

Route110_TrickHousePuzzle8_Text_KeiraPostBattle:
	.string "Bạn thắng được tôi đúng là kỳ tích. Cứ\n"
	.string "việc đem chuyện đó ra khoe.$"

Route110_TrickHousePuzzle8_Text_LeroyIntro:
	.string "Bạn cũng đã vất vả vượt qua thử thách\n"
	.string "TRICK HOUSE nhỉ.$"

Route110_TrickHousePuzzle8_Text_LeroyDefeat:
	.string "Ra là vậy... Bạn có một phong cách thật\n"
	.string "phi thường.$"

Route110_TrickHousePuzzle8_Text_LeroyPostBattle:
	.string "Gặp được người như bạn chắc hẳn sẽ\n"
	.string "khiến TRICK MASTER hài lòng.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global Route110_TrickHousePuzzle8_Text_WroteSecretCodeLockOpened
	.global Route110_TrickHousePuzzle8_Text_VincentIntro
	.global Route110_TrickHousePuzzle8_Text_VincentDefeat
	.global Route110_TrickHousePuzzle8_Text_VincentPostBattle
	.global Route110_TrickHousePuzzle8_Text_KeiraIntro
	.global Route110_TrickHousePuzzle8_Text_KeiraDefeat
	.global Route110_TrickHousePuzzle8_Text_KeiraPostBattle
	.global Route110_TrickHousePuzzle8_Text_LeroyIntro
	.global Route110_TrickHousePuzzle8_Text_LeroyDefeat
	.global Route110_TrickHousePuzzle8_Text_LeroyPostBattle
@ END GENERATED LOCALIZATION EXPORTS
