SootopolisCity_LotadAndSeedotHouse_MapScripts::
	.byte 0

SootopolisCity_LotadAndSeedotHouse_EventScript_SeedotBrother::
	special GetSeedotSizeRecordInfo
	lock
	faceplayer
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_PleaseShowMeBigSeedot, MSGBOX_DEFAULT
	special ChoosePartyMon
	copyvar VAR_RESULT, VAR_0x8004
	goto_if_eq VAR_RESULT, PARTY_NOTHING_CHOSEN, SootopolisCity_LotadAndSeedotHouse_EventScript_CancelShowSeedot
	special CompareSeedotSize
	goto_if_eq VAR_RESULT, COMPARE_SIZE_INCORRECT_SPECIES, SootopolisCity_LotadAndSeedotHouse_EventScript_NotSeedot
	goto_if_eq VAR_RESULT, COMPARE_SIZE_SMALLER, SootopolisCity_LotadAndSeedotHouse_EventScript_SmallSeedot
	goto_if_eq VAR_RESULT, COMPARE_SIZE_LARGER, SootopolisCity_LotadAndSeedotHouse_EventScript_BigSeedot
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_CancelShowSeedot::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_DontHaveBigSeedot, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_NotSeedot::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_ThatsNotSeedot, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_SmallSeedot::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_SeenBiggerSeedot, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_BigSeedot::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_GoshMightBeBiggerThanLotad, MSGBOX_DEFAULT
	giveitem ITEM_ELIXIR
	goto_if_eq VAR_RESULT, FALSE, SootopolisCity_LotadAndSeedotHouse_EventScript_NoRoomForElixir1
	closemessage
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_NoRoomForElixir1::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_BagCrammedFull1, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_LotadBrother::
	special GetLotadSizeRecordInfo
	lock
	faceplayer
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_PleaseShowMeBigLotad, MSGBOX_DEFAULT
	special ChoosePartyMon
	copyvar VAR_RESULT, VAR_0x8004
	goto_if_eq VAR_RESULT, PARTY_NOTHING_CHOSEN, SootopolisCity_LotadAndSeedotHouse_EventScript_CancelShowLotad
	special CompareLotadSize
	goto_if_eq VAR_RESULT, COMPARE_SIZE_INCORRECT_SPECIES, SootopolisCity_LotadAndSeedotHouse_EventScript_NotLotad
	goto_if_eq VAR_RESULT, COMPARE_SIZE_SMALLER, SootopolisCity_LotadAndSeedotHouse_EventScript_SmallLotad
	goto_if_eq VAR_RESULT, COMPARE_SIZE_LARGER, SootopolisCity_LotadAndSeedotHouse_EventScript_BigLotad
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_CancelShowLotad::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_DontHaveBigLotad, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_NotLotad::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_ThatsNotLotad, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_SmallLotad::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_SeenBiggerLotad, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_BigLotad::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_WowMightBeBiggerThanSeedot, MSGBOX_DEFAULT
	giveitem ITEM_ELIXIR
	goto_if_eq VAR_RESULT, FALSE, SootopolisCity_LotadAndSeedotHouse_EventScript_NoRoomForElixir2
	closemessage
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_NoRoomForElixir2::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_BagCrammedFull2, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_SeedotSizeRecord::
	special GetSeedotSizeRecordInfo
	lockall
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_BiggestSeedotInHistory, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_LotadSizeRecord::
	special GetLotadSizeRecordInfo
	lockall
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_BiggestLotadInHistory, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_LotadAndSeedotHouse_Text_PleaseShowMeBigSeedot:
	.string "Bạn có biết POKéMON SEEDOT không? Ở\n"
	.string "SOOTOPOLIS gần như chẳng bao giờ thấy\l"
	.string "nó.\p"
	.string "Dù sao thì tôi rất thích SEEDOT lớn.\n"
	.string "Càng lớn càng tốt.\p"
	.string "Nhưng em trai tôi lại bảo LOTAD lớn hơn.\p"
	.string "Thật vô lý. SEEDOT nhất định phải lớn\n"
	.string "hơn chứ!\p"
	.string "Hả? Bạn có mang theo SEEDOT sao?\n"
	.string "L-l-làm ơn, cho tôi xem với!$"

SootopolisCity_LotadAndSeedotHouse_Text_GoshMightBeBiggerThanLotad:
	.string "{STR_VAR_2} inch! Trời ơi, con\n"
	.string "này lớn thật!\p"
	.string "Có khi nó còn vượt qua LOTAD khổng lồ\n"
	.string "mà em trai tôi từng thấy!\p"
	.string "Cảm ơn bạn đã cho tôi xem. Đây là quà\n"
	.string "cảm ơn!$"

@ Unused
SootopolisCity_LotadAndSeedotHouse_Text_ReceivedPotion1:
	.string "{PLAYER} đã nhận một POTION.$"

SootopolisCity_LotadAndSeedotHouse_Text_BagCrammedFull1:
	.string "Hả? TÚI ĐỒ của bạn đầy cứng rồi.$"

SootopolisCity_LotadAndSeedotHouse_Text_SeenBiggerSeedot:
	.string "{STR_VAR_2} inch sao?\p"
	.string "Hmm... Tôi từng thấy một SEEDOT lớn hơn\n"
	.string "con này.$"

SootopolisCity_LotadAndSeedotHouse_Text_ThatsNotSeedot:
	.string "Ồ, con này cũng thật ấn tượng... Nhưng\n"
	.string "nó đâu phải SEEDOT!$"

SootopolisCity_LotadAndSeedotHouse_Text_DontHaveBigSeedot:
	.string "Bạn không có SEEDOT lớn sao? Tiếc\n"
	.string "thật...\p"
	.string "Nếu tìm được một SEEDOT lớn, xin hãy\n"
	.string "mang tới cho tôi xem.$"

SootopolisCity_LotadAndSeedotHouse_Text_BiggestSeedotInHistory:
	.string "SEEDOT lớn nhất lịch sử! Con khổng lồ\n"
	.string "dài {STR_VAR_3} inch của\l"
	.string "{STR_VAR_2}!\p"
	.string "Một SEEDOT lớn hơn LOTAD, đúng như\n"
	.string "mong ước!$"

SootopolisCity_LotadAndSeedotHouse_Text_PleaseShowMeBigLotad:
	.string "Bạn có biết POKéMON LOTAD không? Ở\n"
	.string "SOOTOPOLIS hiếm khi thấy nó.\p"
	.string "Tôi thích, phải nói là cực kỳ thích\n"
	.string "những LOTAD lớn!\p"
	.string "Anh trai tôi bảo SEEDOT lớn hơn.\p"
	.string "Nhưng anh ấy sai rồi! Ai cũng biết LOTAD\n"
	.string "lớn hơn rất nhiều.\p"
	.string "Hả? Bạn có LOTAD sao? L-l-làm ơn cho\n"
	.string "tôi xem với!$"

SootopolisCity_LotadAndSeedotHouse_Text_WowMightBeBiggerThanSeedot:
	.string "{STR_VAR_2} inch! Chà, lớn thật\n"
	.string "đấy!\p"
	.string "Có khi nó còn lớn hơn SEEDOT khổng lồ\n"
	.string "mà anh trai tôi từng thấy.\p"
	.string "Cảm ơn bạn đã cho tôi xem! Đây là quà\n"
	.string "cảm ơn!$"

@ Unused
SootopolisCity_LotadAndSeedotHouse_Text_ReceivedPotion2:
	.string "{PLAYER} đã nhận một POTION.$"

SootopolisCity_LotadAndSeedotHouse_Text_BagCrammedFull2:
	.string "Hả? TÚI ĐỒ của bạn đầy ắp rồi.$"

SootopolisCity_LotadAndSeedotHouse_Text_SeenBiggerLotad:
	.string "{STR_VAR_2} inch à?\p"
	.string "Ừm... Tôi từng thấy một LOTAD còn lớn\n"
	.string "hơn con này.$"

SootopolisCity_LotadAndSeedotHouse_Text_ThatsNotLotad:
	.string "Ồ, cũng ra trò đấy! Nhưng đây đâu phải\n"
	.string "LOTAD!$"

SootopolisCity_LotadAndSeedotHouse_Text_DontHaveBigLotad:
	.string "Bạn không có LOTAD lớn à? Thất vọng\n"
	.string "thật...\p"
	.string "Nếu bắt được một LOTAD lớn, nhớ mang\n"
	.string "đến cho tôi xem nhé!$"

SootopolisCity_LotadAndSeedotHouse_Text_BiggestLotadInHistory:
	.string "LOTAD lớn nhất lịch sử! Gã khổng lồ dài\n"
	.string "{STR_VAR_3} inch của\l"
	.string "{STR_VAR_2}!\p"
	.string "Một LOTAD lớn hơn cả SEEDOT mà tôi\n"
	.string "hằng mong ước!$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global SootopolisCity_LotadAndSeedotHouse_Text_PleaseShowMeBigSeedot
	.global SootopolisCity_LotadAndSeedotHouse_Text_GoshMightBeBiggerThanLotad
	.global SootopolisCity_LotadAndSeedotHouse_Text_ReceivedPotion1
	.global SootopolisCity_LotadAndSeedotHouse_Text_BagCrammedFull1
	.global SootopolisCity_LotadAndSeedotHouse_Text_SeenBiggerSeedot
	.global SootopolisCity_LotadAndSeedotHouse_Text_ThatsNotSeedot
	.global SootopolisCity_LotadAndSeedotHouse_Text_DontHaveBigSeedot
	.global SootopolisCity_LotadAndSeedotHouse_Text_BiggestSeedotInHistory
	.global SootopolisCity_LotadAndSeedotHouse_Text_PleaseShowMeBigLotad
	.global SootopolisCity_LotadAndSeedotHouse_Text_WowMightBeBiggerThanSeedot
	.global SootopolisCity_LotadAndSeedotHouse_Text_ReceivedPotion2
	.global SootopolisCity_LotadAndSeedotHouse_Text_BagCrammedFull2
	.global SootopolisCity_LotadAndSeedotHouse_Text_SeenBiggerLotad
	.global SootopolisCity_LotadAndSeedotHouse_Text_ThatsNotLotad
	.global SootopolisCity_LotadAndSeedotHouse_Text_DontHaveBigLotad
	.global SootopolisCity_LotadAndSeedotHouse_Text_BiggestLotadInHistory
@ END GENERATED LOCALIZATION EXPORTS
