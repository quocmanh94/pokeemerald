LavaridgeTown_Mart_MapScripts::
	.byte 0

LavaridgeTown_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart LavaridgeTown_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LavaridgeTown_Mart_Pokemart:
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_X_SPEED
	pokemartlistend

LavaridgeTown_Mart_EventScript_ExpertM::
	msgbox LavaridgeTown_Mart_Text_XSpeedFirstStrike, MSGBOX_NPC
	end

LavaridgeTown_Mart_EventScript_OldWoman::
	msgbox LavaridgeTown_Mart_Text_LocalSpecialtyOnMtChimney, MSGBOX_NPC
	end

LavaridgeTown_Mart_Text_XSpeedFirstStrike:
	.string "Dùng X SPEED để tăng SPEED của POKéMON\n"
	.string "trong trận đấu.\p"
	.string "Nhờ vậy nó có thể ra đòn trước, một lợi\n"
	.string "thế rõ rệt!$"

LavaridgeTown_Mart_Text_LocalSpecialtyOnMtChimney:
	.string "Trên đỉnh MT. CHIMNEY có một đặc sản\n"
	.string "địa phương chỉ mua được tại đó.\p"
	.string "Đưa nó cho POKéMON, nó sẽ vui sướng\n"
	.string "lắm.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global LavaridgeTown_Mart_Text_XSpeedFirstStrike
	.global LavaridgeTown_Mart_Text_LocalSpecialtyOnMtChimney
@ END GENERATED LOCALIZATION EXPORTS
