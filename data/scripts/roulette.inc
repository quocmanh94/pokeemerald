Roulette_EventScript_Table1::
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 0
	getpokenewsactive POKENEWS_GAME_CORNER
	goto_if_eq VAR_RESULT, FALSE, Roulette_EventScript_Play
	addvar VAR_0x8004, ROULETTE_SPECIAL_RATE
	goto Roulette_EventScript_Play
	end

Roulette_EventScript_Table2::
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 1
	getpokenewsactive POKENEWS_GAME_CORNER
	goto_if_eq VAR_RESULT, FALSE, Roulette_EventScript_Play
	addvar VAR_0x8004, ROULETTE_SPECIAL_RATE
	goto Roulette_EventScript_Play
	end

Roulette_EventScript_Play::
	special PlayRoulette
	end

Roulette_Text_PlayMinimumWagerIsX::
	.string "Mức cược tối thiểu tại bàn này\n"
	.string "là {STR_VAR_1}. Bạn muốn chơi không?$"

Roulette_Text_NotEnoughCoins::
	.string "Bạn không có đủ COINS.$"

Roulette_Text_SpecialRateTable::
	.string "Bàn này đang có tỷ lệ đặc biệt!$"

Roulette_Text_ControlsInstruction::
	.string "Dùng + Control Pad để đặt cược,\n"
	.string "sau đó nhấn A Button.$"

Roulette_Text_ItsAHit::
	.string "Trúng rồi!$"

Roulette_Text_Jackpot::
	.string "Trúng độc đắc!$"

Roulette_Text_NothingDoing::
	.string "Không trúng gì cả!$"

Roulette_Text_YouveWonXCoins::
	.string "Bạn đã thắng {STR_VAR_1} COINS!$"

Roulette_Text_NoCoinsLeft::
	.string "Không còn COINS…$"

Roulette_Text_KeepPlaying::
	.string "Tiếp tục chơi không?$"

Roulette_Text_BoardWillBeCleared::
	.string "Bàn ROULETTE sẽ được xóa sạch.$"

@ Unused
Roulette_Text_YouDontHaveACoinCase::
	.string "Bạn không có COIN CASE.$"

Roulette_Text_CoinCaseIsFull::
	.string "COIN CASE của bạn đã đầy!\n"
	.string "Có thể đổi Coins lấy phần thưởng.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global Roulette_Text_PlayMinimumWagerIsX
	.global Roulette_Text_NotEnoughCoins
	.global Roulette_Text_SpecialRateTable
	.global Roulette_Text_ControlsInstruction
	.global Roulette_Text_ItsAHit
	.global Roulette_Text_Jackpot
	.global Roulette_Text_NothingDoing
	.global Roulette_Text_YouveWonXCoins
	.global Roulette_Text_NoCoinsLeft
	.global Roulette_Text_KeepPlaying
	.global Roulette_Text_BoardWillBeCleared
	.global Roulette_Text_YouDontHaveACoinCase
	.global Roulette_Text_CoinCaseIsFull
@ END GENERATED LOCALIZATION EXPORTS
