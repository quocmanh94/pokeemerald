MauvilleCity_Mart_MapScripts::
	.byte 0

MauvilleCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart MauvilleCity_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
MauvilleCity_Mart_Pokemart:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	.2byte ITEM_GUARD_SPEC
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_X_ACCURACY
	pokemartlistend

MauvilleCity_Mart_EventScript_ExpertM::
	msgbox MauvilleCity_Mart_Text_ItemsToTemporarilyElevateStats, MSGBOX_NPC
	end

MauvilleCity_Mart_EventScript_Man::
	msgbox MauvilleCity_Mart_Text_DecisionsDetermineBattle, MSGBOX_NPC
	end

MauvilleCity_Mart_Text_ItemsToTemporarilyElevateStats:
	.string "Có những vật phẩm tạm thời tăng chỉ số\n"
	.string "của POKéMON.\p"
	.string "Những thứ tôi biết có thể dùng trong\n"
	.string "trận đấu là X ATTACK và X DEFEND...\p"
	.string "Tôi tin là còn có những vật phẩm tương\n"
	.string "tự khác.$"

MauvilleCity_Mart_Text_DecisionsDetermineBattle:
	.string "Dùng một chiêu nào đó, hay thay vào đó\n"
	.string "dùng vật phẩm...\p"
	.string "Tôi nghĩ chính quyết định của HLV\n"
	.string "sẽ định đoạt kết quả trận đấu.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global MauvilleCity_Mart_Text_ItemsToTemporarilyElevateStats
	.global MauvilleCity_Mart_Text_DecisionsDetermineBattle
@ END GENERATED LOCALIZATION EXPORTS
