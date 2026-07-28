OldaleTown_Mart_MapScripts::
	.byte 0

OldaleTown_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	goto_if_set FLAG_ADVENTURE_STARTED, OldaleTown_Mart_ExpandedItems
	pokemart OldaleTown_Mart_Pokemart_Basic
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
OldaleTown_Mart_Pokemart_Basic:
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	pokemartlistend

OldaleTown_Mart_ExpandedItems::
	pokemart OldaleTown_Mart_Pokemart_Expanded
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
OldaleTown_Mart_Pokemart_Expanded:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	pokemartlistend

OldaleTown_Mart_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_ADVENTURE_STARTED, OldaleTown_Mart_EventScript_PokeBallsInStock
	msgbox OldaleTown_Mart_Text_PokeBallsAreSoldOut, MSGBOX_DEFAULT
	release
	end

OldaleTown_Mart_EventScript_PokeBallsInStock::
	msgbox OldaleTown_Mart_Text_ImGoingToBuyPokeBalls, MSGBOX_DEFAULT
	release
	end

OldaleTown_Mart_EventScript_Boy::
	msgbox OldaleTown_Mart_Text_RestoreHPWithPotion, MSGBOX_NPC
	end

OldaleTown_Mart_Text_PokeBallsAreSoldOut:
	.string "Nhân viên nói họ đã bán hết sạch. Tôi\n"
	.string "không mua được POKé BALLS nào cả.$"

OldaleTown_Mart_Text_ImGoingToBuyPokeBalls:
	.string "Tôi sẽ mua thật nhiều POKé BALLS rồi\n"
	.string "bắt thật nhiều POKéMON!$"

OldaleTown_Mart_Text_RestoreHPWithPotion:
	.string "Nếu một POKéMON bị thương, mất hết HP\n"
	.string "rồi ngất đi, nó sẽ không thể chiến đấu.\p"
	.string "Để POKéMON của cậu không bị ngất, hãy\n"
	.string "dùng POTION phục hồi HP cho nó.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global OldaleTown_Mart_Text_PokeBallsAreSoldOut
	.global OldaleTown_Mart_Text_ImGoingToBuyPokeBalls
	.global OldaleTown_Mart_Text_RestoreHPWithPotion
@ END GENERATED LOCALIZATION EXPORTS
