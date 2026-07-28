BattleFrontier_Lounge6_MapScripts::
	.byte 0

BattleFrontier_Lounge6_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_BATTLE_FRONTIER_TRADE_DONE, BattleFrontier_Lounge6_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_MEOWTH
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox BattleFrontier_Lounge6_Text_WouldYouLikeToTrade, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge6_EventScript_DeclineTrade
	special ChoosePartyMon
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_Lounge6_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, BattleFrontier_Lounge6_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	msgbox BattleFrontier_Lounge6_Text_PromiseIllBeGoodToIt, MSGBOX_DEFAULT
	setflag FLAG_BATTLE_FRONTIER_TRADE_DONE
	release
	end

BattleFrontier_Lounge6_EventScript_DeclineTrade::
	msgbox BattleFrontier_Lounge6_Text_WellThatsFineToo, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox BattleFrontier_Lounge6_Text_DontTradeForAnythingButMon, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_EventScript_TradeCompleted::
	msgbox BattleFrontier_Lounge6_Text_SkittySoMuchCuterThanImagined, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_Text_WouldYouLikeToTrade:
	.string "POKéMON của tôi là một\n"
	.string "{STR_VAR_2}. Bạn biết loài đó\l"
	.string "chứ? Nó khá dễ thương và rất ngoan.\p"
	.string "Tôi rất tự hào khi đem bé này ra trao\n"
	.string "đổi!\p"
	.string "Bạn có muốn đổi một {STR_VAR_1}\n"
	.string "lấy {STR_VAR_2} của tôi không?$"

BattleFrontier_Lounge6_Text_PromiseIllBeGoodToIt:
	.string "Ôi, đáng yêu quá! Cảm ơn bạn! Tôi hứa sẽ\n"
	.string "đối xử thật tốt với nó!\p"
	.string "À! Tôi cũng mong bạn sẽ đối xử tốt với\n"
	.string "{STR_VAR_2} của tôi!$"

BattleFrontier_Lounge6_Text_DontTradeForAnythingButMon:
	.string "Ôi, tôi xin lỗi! Tôi chỉ định trao đổi để\n"
	.string "lấy một {STR_VAR_1} thôi.$"

BattleFrontier_Lounge6_Text_WellThatsFineToo:
	.string "Ồ, bạn không muốn sao? Không sao cả.\n"
	.string "Hãy ghé thăm chúng tôi lần nữa nhé.$"

BattleFrontier_Lounge6_Text_SkittySoMuchCuterThanImagined:
	.string "Hí hí! SKITTY dễ thương hơn tôi tưởng\n"
	.string "rất nhiều. Tôi vui quá!$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global BattleFrontier_Lounge6_Text_WouldYouLikeToTrade
	.global BattleFrontier_Lounge6_Text_PromiseIllBeGoodToIt
	.global BattleFrontier_Lounge6_Text_DontTradeForAnythingButMon
	.global BattleFrontier_Lounge6_Text_WellThatsFineToo
	.global BattleFrontier_Lounge6_Text_SkittySoMuchCuterThanImagined
@ END GENERATED LOCALIZATION EXPORTS
