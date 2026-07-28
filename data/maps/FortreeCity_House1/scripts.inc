FortreeCity_House1_MapScripts::
	.byte 0

FortreeCity_House1_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_FORTREE_NPC_TRADE_COMPLETED, FortreeCity_House1_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_PLUSLE
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox FortreeCity_House1_Text_YouWillTradeWontYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, FortreeCity_House1_EventScript_DeclineTrade
	special ChoosePartyMon
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, FortreeCity_House1_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, FortreeCity_House1_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox FortreeCity_House1_Text_MonYouTakeCare, MSGBOX_DEFAULT
	setflag FLAG_FORTREE_NPC_TRADE_COMPLETED
	release
	end

FortreeCity_House1_EventScript_DeclineTrade::
	msgbox FortreeCity_House1_Text_YouWontTradeMe, MSGBOX_DEFAULT
	release
	end

FortreeCity_House1_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox FortreeCity_House1_Text_ThisIsntAMon, MSGBOX_DEFAULT
	release
	end

FortreeCity_House1_EventScript_TradeCompleted::
	msgbox FortreeCity_House1_Text_GoingToMakeVolbeatStrong, MSGBOX_DEFAULT
	release
	end

FortreeCity_House1_EventScript_ExpertF::
	msgbox FortreeCity_House1_Text_TradingMemoriesWithOthers, MSGBOX_NPC
	end

FortreeCity_House1_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox FortreeCity_House1_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FortreeCity_House1_Text_YouWillTradeWontYou:
	.string "Gàoooo! Tôi cần nó! Tôi nhất định phải\n"
	.string "có một {STR_VAR_1}! Tôi sẽ làm\l"
	.string "bất cứ điều gì để có nó!\p"
	.string "...Ờ... Bạn có nghe thấy không? Tiếng hét\n"
	.string "từ tận đáy lòng tôi ấy?\p"
	.string "Nghe được rồi thì bạn sẽ đổi\n"
	.string "{STR_VAR_1} của mình lấy\l"
	.string "{STR_VAR_2} của tôi, phải không?$"

FortreeCity_House1_Text_MonYouTakeCare:
	.string "Ồ, tuyệt, đúng ý tôi rồi!\p"
	.string "Chào mừng {STR_VAR_1}!\n"
	.string "{STR_VAR_2}, hãy tự chăm sóc\l"
	.string "mình nhé!$"

FortreeCity_House1_Text_ThisIsntAMon:
	.string "Ờ, không, tôi không nghĩ vậy. Đó không\n"
	.string "phải là {STR_VAR_1}.$"

FortreeCity_House1_Text_YouWontTradeMe:
	.string "Không ư? Bạn không chịu đổi với tôi\n"
	.string "sao? Ngay cả sau khi tôi đã dốc hết lòng\l"
	.string "mình với bạn?$"

FortreeCity_House1_Text_GoingToMakeVolbeatStrong:
	.string "Từ giờ, tôi sẽ huấn luyện VOLBEAT trở\n"
	.string "nên siêu mạnh!\p"
	.string "Tôi hy vọng bạn cũng làm vậy với\n"
	.string "PLUSLE!$"

FortreeCity_House1_Text_TradingMemoriesWithOthers:
	.string "Trao đổi POKéMON với người khác...\p"
	.string "Cứ như thể bạn đang trao đổi chính\n"
	.string "những ký ức của mình với họ vậy.$"

FortreeCity_House1_Text_Zigzagoon:
	.string "ZIGZAGOON: Gumomoh?$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global FortreeCity_House1_Text_YouWillTradeWontYou
	.global FortreeCity_House1_Text_MonYouTakeCare
	.global FortreeCity_House1_Text_ThisIsntAMon
	.global FortreeCity_House1_Text_YouWontTradeMe
	.global FortreeCity_House1_Text_GoingToMakeVolbeatStrong
	.global FortreeCity_House1_Text_TradingMemoriesWithOthers
@ END GENERATED LOCALIZATION EXPORTS
