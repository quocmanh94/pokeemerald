MossdeepCity_House3_MapScripts::
	.byte 0

MossdeepCity_House3_EventScript_SuperRodFisherman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SUPER_ROD, MossdeepCity_House3_EventScript_ReceivedSuperRod
	msgbox MossdeepCity_House3_Text_YouWantSuperRod, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MossdeepCity_House3_EventScript_DeclineSuperRod
	msgbox MossdeepCity_House3_Text_SuperRodIsSuper, MSGBOX_DEFAULT
	giveitem ITEM_SUPER_ROD
	setflag FLAG_RECEIVED_SUPER_ROD
	msgbox MossdeepCity_House3_Text_TryDroppingRodInWater, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House3_EventScript_ReceivedSuperRod::
	msgbox MossdeepCity_House3_Text_GoAfterSeafloorPokemon, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House3_EventScript_DeclineSuperRod::
	msgbox MossdeepCity_House3_Text_DontYouLikeToFish, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House3_Text_YouWantSuperRod:
	.string "Này, HLV! SUPER ROD đúng là siêu\n"
	.string "hạng!\p"
	.string "Nói sao thì nói, bảo bối này câu được\n"
	.string "cả POKéMON dưới đáy biển đấy!\p"
	.string "Thế nào? Muốn có nó lắm, đúng không?$"

MossdeepCity_House3_Text_SuperRodIsSuper:
	.string "Đúng vậy, đúng vậy! Dù sao thì SUPER\n"
	.string "ROD quả thật là siêu hạng!$"

MossdeepCity_House3_Text_TryDroppingRodInWater:
	.string "Hễ thấy chỗ nào có nước, cứ thả ROD\n"
	.string "xuống thử xem con gì cắn câu!$"

MossdeepCity_House3_Text_DontYouLikeToFish:
	.string "Hả? Cậu không thích câu cá à?$"

MossdeepCity_House3_Text_GoAfterSeafloorPokemon:
	.string "Hãy dùng SUPER ROD để săn POKéMON\n"
	.string "dưới đáy biển.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global MossdeepCity_House3_Text_YouWantSuperRod
	.global MossdeepCity_House3_Text_SuperRodIsSuper
	.global MossdeepCity_House3_Text_TryDroppingRodInWater
	.global MossdeepCity_House3_Text_DontYouLikeToFish
	.global MossdeepCity_House3_Text_GoAfterSeafloorPokemon
@ END GENERATED LOCALIZATION EXPORTS
