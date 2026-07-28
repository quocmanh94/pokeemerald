RustboroCity_House1_MapScripts::
	.byte 0

RustboroCity_House1_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_RUSTBORO_NPC_TRADE_COMPLETED, RustboroCity_House1_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_SEEDOT
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox RustboroCity_House1_Text_IllTradeIfYouWant, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_House1_EventScript_DeclineTrade
	special ChoosePartyMon
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, RustboroCity_House1_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, RustboroCity_House1_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	msgbox RustboroCity_House1_Text_PleaseBeGoodToMyPokemon, MSGBOX_DEFAULT
	setflag FLAG_RUSTBORO_NPC_TRADE_COMPLETED
	release
	end

RustboroCity_House1_EventScript_DeclineTrade::
	msgbox RustboroCity_House1_Text_YouDontWantToThatsOkay, MSGBOX_DEFAULT
	release
	end

RustboroCity_House1_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox RustboroCity_House1_Text_DoesntLookLikeMonToMe, MSGBOX_DEFAULT
	release
	end

RustboroCity_House1_EventScript_TradeCompleted::
	msgbox RustboroCity_House1_Text_AnyPokemonCanBeCute, MSGBOX_DEFAULT
	release
	end

RustboroCity_House1_EventScript_Hiker::
	msgbox RustboroCity_House1_Text_AllSortsOfPlaces, MSGBOX_NPC
	end

RustboroCity_House1_Text_IllTradeIfYouWant:
	.string "Hả? POKéMON của tôi dễ thương sao?\n"
	.string "Tất nhiên, tôi biết mà.\p"
	.string "Nhưng nếu bạn thật sự muốn, tôi sẵn\n"
	.string "lòng đổi nó cho bạn.\p"
	.string "Nếu muốn, tôi sẽ đổi {STR_VAR_2}\n"
	.string "của mình lấy một {STR_VAR_1} của\l"
	.string "bạn.$"

RustboroCity_House1_Text_PleaseBeGoodToMyPokemon:
	.string "Hì hì... Hãy chăm sóc tốt POKéMON của\n"
	.string "tôi nhé.$"

RustboroCity_House1_Text_DoesntLookLikeMonToMe:
	.string "Hả? Tôi thấy nó chẳng giống\n"
	.string "{STR_VAR_1} chút nào.$"

RustboroCity_House1_Text_YouDontWantToThatsOkay:
	.string "Ồ, nếu bạn không muốn thì cũng không\n"
	.string "sao. Nhưng POKéMON của tôi dễ thương\l"
	.string "lắm đấy...$"

RustboroCity_House1_Text_AnyPokemonCanBeCute:
	.string "POKéMON nào cũng có thể trở nên dễ\n"
	.string "thương nếu được nuôi dưỡng bằng sự\l"
	.string "quan tâm và lòng yêu thương.$"

RustboroCity_House1_Text_AllSortsOfPlaces:
	.string "Ở muôn vàn nơi khác nhau có muôn vàn\n"
	.string "POKéMON và con người khác nhau.\p"
	.string "Tôi thấy điều đó thật hấp dẫn nên\n"
	.string "thường đi khắp mọi nơi.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global RustboroCity_House1_Text_IllTradeIfYouWant
	.global RustboroCity_House1_Text_PleaseBeGoodToMyPokemon
	.global RustboroCity_House1_Text_DoesntLookLikeMonToMe
	.global RustboroCity_House1_Text_YouDontWantToThatsOkay
	.global RustboroCity_House1_Text_AnyPokemonCanBeCute
	.global RustboroCity_House1_Text_AllSortsOfPlaces
@ END GENERATED LOCALIZATION EXPORTS
