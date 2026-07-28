SlateportCity_Mart_MapScripts::
	.byte 0

SlateportCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart SlateportCity_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_Mart_Pokemart:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_REPEL
	.2byte ITEM_HARBOR_MAIL
	pokemartlistend

SlateportCity_Mart_EventScript_BlackBelt::
	msgbox SlateportCity_Mart_Text_SomeItemsOnlyAtMart, MSGBOX_NPC
	end

SlateportCity_Mart_EventScript_Man::
	msgbox SlateportCity_Mart_Text_GreatBallIsBetter, MSGBOX_NPC
	end

SlateportCity_Mart_Text_SomeItemsOnlyAtMart:
	.string "MARKET đúng là có vài món hàng thú vị.\p"
	.string "Nhưng có một số món đồ chỉ mua được\n"
	.string "tại POKéMON MART.$"

SlateportCity_Mart_Text_GreatBallIsBetter:
	.string "GREAT BALL bắt POKéMON hiệu quả hơn\n"
	.string "POKé BALL.\p"
	.string "Với thứ này, mình sẽ bắt được POKéMON\n"
	.string "khó tìm đó...$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global SlateportCity_Mart_Text_SomeItemsOnlyAtMart
	.global SlateportCity_Mart_Text_GreatBallIsBetter
@ END GENERATED LOCALIZATION EXPORTS
