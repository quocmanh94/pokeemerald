PacifidlogTown_House3_MapScripts::
	.byte 0

PacifidlogTown_House3_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_PACIFIDLOG_NPC_TRADE_COMPLETED, PacifidlogTown_House3_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_HORSEA
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox PacifidlogTown_House3_Text_WillingToTradeIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, PacifidlogTown_House3_EventScript_DeclineTrade
	special ChoosePartyMon
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, PacifidlogTown_House3_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, PacifidlogTown_House3_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox PacifidlogTown_House3_Text_ItsSubtlyDifferentThankYou, MSGBOX_DEFAULT
	setflag FLAG_PACIFIDLOG_NPC_TRADE_COMPLETED
	release
	end

PacifidlogTown_House3_EventScript_DeclineTrade::
	msgbox PacifidlogTown_House3_Text_NotDesperateOrAnything, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House3_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox PacifidlogTown_House3_Text_WontAcceptAnyLessThanRealMon, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House3_EventScript_TradeCompleted::
	msgbox PacifidlogTown_House3_Text_ReallyWantedToGetBagon, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House3_EventScript_Girl::
	msgbox PacifidlogTown_House3_Text_IsThatAPokedex, MSGBOX_NPC
	end

PacifidlogTown_House3_Text_WillingToTradeIt:
	.string "Nhìn {STR_VAR_2} này xem!\p"
	.string "Đây là {STR_VAR_2} tôi bắt được\n"
	.string "hôm qua để mừng sinh nhật!\p"
	.string "Ồ, nhìn là biết cậu muốn có nó rồi! Dù\n"
	.string "sao nó cũng vô giá mà!\p"
	.string "Thế này nhé. Có lẽ tôi sẽ đồng ý đổi nó\n"
	.string "lấy một {STR_VAR_1}.$"

PacifidlogTown_House3_Text_ItsSubtlyDifferentThankYou:
	.string "Ồ, vậy đây là một {STR_VAR_1}\n"
	.string "sao?\p"
	.string "Nó khá giống một {STR_VAR_2},\n"
	.string "nhưng vẫn có chút khác biệt tinh tế.\p"
	.string "Cảm ơn cậu!$"

PacifidlogTown_House3_Text_WontAcceptAnyLessThanRealMon:
	.string "Không, không, không! Tôi chỉ chấp nhận\n"
	.string "một {STR_VAR_1} thứ thiệt!$"

PacifidlogTown_House3_Text_NotDesperateOrAnything:
	.string "Ồ, vậy cậu không định thực hiện vụ trao\n"
	.string "đổi này à?\p"
	.string "Không sao. Tôi cũng đâu có khao khát\n"
	.string "trao đổi đến thế.$"

PacifidlogTown_House3_Text_ReallyWantedToGetBagon:
	.string "Tôi biết mình có thể tự đi tìm một con,\n"
	.string "nhưng...\p"
	.string "Nhưng tôi thật sự muốn có một BAGON do\n"
	.string "HLV khác bắt được...$"

PacifidlogTown_House3_Text_IsThatAPokedex:
	.string "Đó là POKéDEX sao?\p"
	.string "Cậu đã được gặp nhiều POKéMON khác\n"
	.string "nhau rồi à?\p"
	.string "Ước gì tôi được như cậu.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global PacifidlogTown_House3_Text_WillingToTradeIt
	.global PacifidlogTown_House3_Text_ItsSubtlyDifferentThankYou
	.global PacifidlogTown_House3_Text_WontAcceptAnyLessThanRealMon
	.global PacifidlogTown_House3_Text_NotDesperateOrAnything
	.global PacifidlogTown_House3_Text_ReallyWantedToGetBagon
	.global PacifidlogTown_House3_Text_IsThatAPokedex
@ END GENERATED LOCALIZATION EXPORTS
