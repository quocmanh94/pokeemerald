FortreeCity_Mart_MapScripts::
	.byte 0

FortreeCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart FortreeCity_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
FortreeCity_Mart_Pokemart:
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_REVIVE
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_WOOD_MAIL
	pokemartlistend

FortreeCity_Mart_EventScript_Woman::
	msgbox FortreeCity_Mart_Text_SuperRepelBetter, MSGBOX_NPC
	end

FortreeCity_Mart_EventScript_Girl::
	msgbox FortreeCity_Mart_Text_StockUpOnItems, MSGBOX_NPC
	end

FortreeCity_Mart_EventScript_Boy::
	msgbox FortreeCity_Mart_Text_RareCandyMakesMonGrow, MSGBOX_NPC
	end

FortreeCity_Mart_Text_SuperRepelBetter:
	.string "SUPER REPEL có tác dụng lâu và hoàn\n"
	.string "thành tốt nhiệm vụ.\p"
	.string "Nó tốt hơn hẳn REPEL thông thường.$"

FortreeCity_Mart_Text_StockUpOnItems:
	.string "Tôi luôn dự trữ nhiều vật phẩm hơn mức\n"
	.string "mình nghĩ sẽ cần.\p"
	.string "Không ai biết chuyện gì có thể xảy ra.\n"
	.string "Cẩn tắc vô áy náy!$"

FortreeCity_Mart_Text_RareCandyMakesMonGrow:
	.string "RARE CANDY giúp POKéMON lập tức tăng\n"
	.string "một cấp.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global FortreeCity_Mart_Text_SuperRepelBetter
	.global FortreeCity_Mart_Text_StockUpOnItems
	.global FortreeCity_Mart_Text_RareCandyMakesMonGrow
@ END GENERATED LOCALIZATION EXPORTS
