Route110_TrickHousePuzzle7_MapScripts::
	.byte 0

Route110_TrickHousePuzzle7_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_7_STATE, 0, Route110_TrickHousePuzzle7_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle7_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_7_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

@ From here is where the new, actually used puzzle scripts begin
Route110_TrickHousePuzzle7_EventScript_YellowButton::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle TRUE
	moverotatingtileobjects 0
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

Route110_TrickHousePuzzle7_EventScript_BlueButton::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle TRUE
	moverotatingtileobjects 1
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

Route110_TrickHousePuzzle7_EventScript_GreenButton::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle TRUE
	moverotatingtileobjects 2
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

Route110_TrickHousePuzzle7_EventScript_PurpleButton::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle TRUE
	moverotatingtileobjects 3
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

@ Unused
Route110_TrickHousePuzzle7_EventScript_RedButton::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle TRUE
	moverotatingtileobjects 4
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

Route110_TrickHousePuzzle7_EventScript_Joshua::
	trainerbattle_single TRAINER_JOSHUA, Route110_TrickHousePuzzle7_Text_JoshuaIntro, Route110_TrickHousePuzzle7_Text_JoshuaDefeat
	msgbox Route110_TrickHousePuzzle7_Text_JoshuaPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle7_EventScript_Patricia::
	trainerbattle_single TRAINER_PATRICIA, Route110_TrickHousePuzzle7_Text_PatriciaIntro, Route110_TrickHousePuzzle7_Text_PatriciaDefeat
	msgbox Route110_TrickHousePuzzle7_Text_PatriciaPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle7_EventScript_Alexis::
	trainerbattle_single TRAINER_ALEXIS, Route110_TrickHousePuzzle7_Text_AlexisIntro, Route110_TrickHousePuzzle7_Text_AlexisDefeat
	msgbox Route110_TrickHousePuzzle7_Text_AlexisPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle7_EventScript_Mariela::
	trainerbattle_single TRAINER_MARIELA, Route110_TrickHousePuzzle7_Text_MarielaIntro, Route110_TrickHousePuzzle7_Text_MarielaDefeat
	msgbox Route110_TrickHousePuzzle7_Text_MarielaPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle7_EventScript_Alvaro::
	trainerbattle_single TRAINER_ALVARO, Route110_TrickHousePuzzle7_Text_AlvaroIntro, Route110_TrickHousePuzzle7_Text_AlvaroDefeat
	msgbox Route110_TrickHousePuzzle7_Text_AlvaroPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle7_EventScript_Everett::
	trainerbattle_single TRAINER_EVERETT, Route110_TrickHousePuzzle7_Text_EverettIntro, Route110_TrickHousePuzzle7_Text_EverettDefeat
	msgbox Route110_TrickHousePuzzle7_Text_EverettPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle7_Text_WroteSecretCodeLockOpened::
	.string "{PLAYER} ghi lại mật mã trên cửa.\p"
	.string "“TRICK MASTER thật đáng ôm.” ... ... ... ...\n"
	.string "... ... ... ...\p"
	.string "Ổ khóa bật mở đánh tách!$"

Route110_TrickHousePuzzle7_Text_JoshuaIntro:
	.string "TRICK MASTER lúc nào cũng biến mất như\n"
	.string "làn khói. Ông ấy làm thế nào vậy?$"

Route110_TrickHousePuzzle7_Text_JoshuaDefeat:
	.string "Aiyeeeh! Bạn mạnh quá sức rồi! Làm sao\n"
	.string "bạn làm được thế?$"

Route110_TrickHousePuzzle7_Text_JoshuaPostBattle:
	.string "Tôi cũng ước mình có thể thoắt ẩn\n"
	.string "thoắt hiện như làn khói.$"

Route110_TrickHousePuzzle7_Text_PatriciaIntro:
	.string "Cứ đi vòng quanh cùng một chỗ... sẽ\n"
	.string "rước vận rủi...$"

Route110_TrickHousePuzzle7_Text_PatriciaDefeat:
	.string "Bị đánh bại rồi! Đây là điềm xấu...$"

Route110_TrickHousePuzzle7_Text_PatriciaPostBattle:
	.string "Tôi đã đi vòng quanh cùng một chỗ hơn\n"
	.string "mười lần... Đúng là vận rủi...$"

Route110_TrickHousePuzzle7_Text_AlexisIntro:
	.string "Ai thắng sẽ được qua đây trước. Tôi có\n"
	.string "linh cảm như vậy.$"

Route110_TrickHousePuzzle7_Text_AlexisDefeat:
	.string "Ồ! Vậy thì bạn cứ đi trước đi!$"

Route110_TrickHousePuzzle7_Text_AlexisPostBattle:
	.string "Tôi có cảm giác bạn sẽ giải được hết mọi\n"
	.string "câu đố trong TRICK HOUSE.$"

Route110_TrickHousePuzzle7_Text_MarielaIntro:
	.string "Nufufufu, cuối cùng cũng đến rồi! Bắt\n"
	.string "đầu ngay nào!$"

Route110_TrickHousePuzzle7_Text_MarielaDefeat:
	.string "Bạn thắng mà thản nhiên quá!$"

Route110_TrickHousePuzzle7_Text_MarielaPostBattle:
	.string "Hừ! Tôi không bực đâu! Không hề!$"

Route110_TrickHousePuzzle7_Text_AlvaroIntro:
	.string "Tôi đã chăm chú dõi theo bạn đến đây!$"

Route110_TrickHousePuzzle7_Text_AlvaroDefeat:
	.string "Kết quả này thì tôi không lường trước\n"
	.string "được...$"

Route110_TrickHousePuzzle7_Text_AlvaroPostBattle:
	.string "Dù sao thì cả hai ta đã chọn một nơi kỳ\n"
	.string "quặc để làm quen.\p"
	.string "Người kỳ quặc gặp người kỳ quặc, cùng\n"
	.string "cố gắng nhé!$"

Route110_TrickHousePuzzle7_Text_EverettIntro:
	.string "Ở đây chật chội quá...$"

Route110_TrickHousePuzzle7_Text_EverettDefeat:
	.string "Ồ, đúng vậy, bạn quả là mạnh.$"

Route110_TrickHousePuzzle7_Text_EverettPostBattle:
	.string "Tôi đã định thắng bạn rồi đổi chỗ với\n"
	.string "bạn, nhưng...$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global Route110_TrickHousePuzzle7_Text_WroteSecretCodeLockOpened
	.global Route110_TrickHousePuzzle7_Text_JoshuaIntro
	.global Route110_TrickHousePuzzle7_Text_JoshuaDefeat
	.global Route110_TrickHousePuzzle7_Text_JoshuaPostBattle
	.global Route110_TrickHousePuzzle7_Text_PatriciaIntro
	.global Route110_TrickHousePuzzle7_Text_PatriciaDefeat
	.global Route110_TrickHousePuzzle7_Text_PatriciaPostBattle
	.global Route110_TrickHousePuzzle7_Text_AlexisIntro
	.global Route110_TrickHousePuzzle7_Text_AlexisDefeat
	.global Route110_TrickHousePuzzle7_Text_AlexisPostBattle
	.global Route110_TrickHousePuzzle7_Text_MarielaIntro
	.global Route110_TrickHousePuzzle7_Text_MarielaDefeat
	.global Route110_TrickHousePuzzle7_Text_MarielaPostBattle
	.global Route110_TrickHousePuzzle7_Text_AlvaroIntro
	.global Route110_TrickHousePuzzle7_Text_AlvaroDefeat
	.global Route110_TrickHousePuzzle7_Text_AlvaroPostBattle
	.global Route110_TrickHousePuzzle7_Text_EverettIntro
	.global Route110_TrickHousePuzzle7_Text_EverettDefeat
	.global Route110_TrickHousePuzzle7_Text_EverettPostBattle
@ END GENERATED LOCALIZATION EXPORTS
