FortreeCity_DecorationShop_MapScripts::
	.byte 0

FortreeCity_DecorationShop_EventScript_PokefanM::
	msgbox FortreeCity_DecorationShop_Text_MerchandiseSentToPC, MSGBOX_NPC
	end

FortreeCity_DecorationShop_EventScript_Girl::
	msgbox FortreeCity_DecorationShop_Text_BuyingDeskForDolls, MSGBOX_NPC
	end

FortreeCity_DecorationShop_EventScript_ClerkDesks::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemartdecoration FortreeCity_DecorationShop_PokemartDecor_Desks
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
FortreeCity_DecorationShop_PokemartDecor_Desks:
	.2byte DECOR_SMALL_DESK
	.2byte DECOR_POKEMON_DESK
	.2byte DECOR_HEAVY_DESK
	.2byte DECOR_RAGGED_DESK
	.2byte DECOR_COMFORT_DESK
	.2byte DECOR_BRICK_DESK
	.2byte DECOR_CAMP_DESK
	.2byte DECOR_HARD_DESK
	pokemartlistend

FortreeCity_DecorationShop_EventScript_ClerkChairs::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemartdecoration FortreeCity_DecorationShop_PokemartDecor_Chairs
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
FortreeCity_DecorationShop_PokemartDecor_Chairs:
	.2byte DECOR_SMALL_CHAIR
	.2byte DECOR_POKEMON_CHAIR
	.2byte DECOR_HEAVY_CHAIR
	.2byte DECOR_RAGGED_CHAIR
	.2byte DECOR_COMFORT_CHAIR
	.2byte DECOR_BRICK_CHAIR
	.2byte DECOR_CAMP_CHAIR
	.2byte DECOR_HARD_CHAIR
	pokemartlistend

FortreeCity_DecorationShop_Text_MerchandiseSentToPC:
	.string "Hàng hóa mua ở đây sẽ được gửi đến PC\n"
	.string "riêng của bạn.\p"
	.string "Tuyệt thật! Ước gì họ cũng có thể gửi\n"
	.string "tôi về nhà như vậy.$"

FortreeCity_DecorationShop_Text_BuyingDeskForDolls:
	.string "Tôi sẽ mua một chiếc bàn thật đẹp rồi\n"
	.string "đặt những DOLLS dễ thương của mình\l"
	.string "lên đó.\p"
	.string "Nếu không, khi trang trí SECRET BASE,\n"
	.string "các DOLLS của tôi sẽ bị bẩn hoặc bị dằm\l"
	.string "gỗ đâm.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global FortreeCity_DecorationShop_Text_MerchandiseSentToPC
	.global FortreeCity_DecorationShop_Text_BuyingDeskForDolls
@ END GENERATED LOCALIZATION EXPORTS
