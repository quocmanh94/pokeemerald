BattleFrontier_Mart_MapScripts::
	.byte 0

BattleFrontier_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart BattleFrontier_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_Mart_Pokemart:
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_PROTEIN
	.2byte ITEM_CALCIUM
	.2byte ITEM_IRON
	.2byte ITEM_ZINC
	.2byte ITEM_CARBOS
	.2byte ITEM_HP_UP
	pokemartlistend

BattleFrontier_Mart_EventScript_OldMan::
	msgbox BattleFrontier_Mart_Text_ChaperonGrandson, MSGBOX_NPC
	end

BattleFrontier_Mart_EventScript_OldWoman::
	lock
	applymovement LOCALID_FRONTIER_MART_OLD_WOMAN, Common_Movement_FaceDown
	waitmovement 0
	msgbox BattleFrontier_Mart_Text_ProteinMakeNiceGift, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Mart_EventScript_Boy::
	msgbox BattleFrontier_Mart_Text_FacilitiesDontAllowItems, MSGBOX_NPC
	end

BattleFrontier_Mart_Text_ChaperonGrandson:
	.string "Chúng tôi đến đây để trông chừng cháu\n"
	.string "trai.\p"
	.string "Nhưng đã đến tận đây rồi, chúng tôi\n"
	.string "nghĩ nên mua ít quà lưu niệm.$"

BattleFrontier_Mart_Text_ProteinMakeNiceGift:
	.string "Mình ơi, mình thấy món này thế nào?\n"
	.string "Chẳng phải sẽ là một món quà hay sao?\p"
	.string "Nó là... PRO...TE...IN à? Nghe ngon lắm,\n"
	.string "phải không?$"

BattleFrontier_Mart_Text_FacilitiesDontAllowItems:
	.string "Nhiều cơ sở ở BATTLE FRONTIER không\n"
	.string "cho phép dùng vật phẩm trong trận đấu.\p"
	.string "Luật đó khiến mọi thứ vốn đã khó lại\n"
	.string "càng khó hơn!$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global BattleFrontier_Mart_Text_ChaperonGrandson
	.global BattleFrontier_Mart_Text_ProteinMakeNiceGift
	.global BattleFrontier_Mart_Text_FacilitiesDontAllowItems
@ END GENERATED LOCALIZATION EXPORTS
