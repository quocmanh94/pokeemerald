LilycoveCity_DepartmentStore_4F_MapScripts::
	.byte 0

LilycoveCity_DepartmentStore_4F_EventScript_Gentleman::
	msgbox LilycoveCity_DepartmentStore_4F_Text_AttackOrDefenseTM, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_4F_EventScript_Woman::
	msgbox LilycoveCity_DepartmentStore_4F_Text_FiftyDifferentTMs, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_4F_EventScript_Youngster::
	msgbox LilycoveCity_DepartmentStore_4F_Text_PokemonOnlyHaveFourMoves, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_4F_EventScript_ClerkLeft::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart LilycoveCity_DepartmentStore_4F_Pokemart_AttackTMs
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LilycoveCity_DepartmentStore_4F_Pokemart_AttackTMs:
	.2byte ITEM_TM_FIRE_BLAST
	.2byte ITEM_TM_THUNDER
	.2byte ITEM_TM_BLIZZARD
	.2byte ITEM_TM_HYPER_BEAM
	pokemartlistend

LilycoveCity_DepartmentStore_4F_EventScript_ClerkRight::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart LilycoveCity_DepartmentStore_4F_Pokemart_DefenseTMs
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LilycoveCity_DepartmentStore_4F_Pokemart_DefenseTMs:
	.2byte ITEM_TM_PROTECT
	.2byte ITEM_TM_SAFEGUARD
	.2byte ITEM_TM_REFLECT
	.2byte ITEM_TM_LIGHT_SCREEN
	pokemartlistend

LilycoveCity_DepartmentStore_4F_Text_AttackOrDefenseTM:
	.string "Hmm...\p"
	.string "Một chiêu tấn công... Hay một chiêu\n"
	.string "phòng thủ...\p"
	.string "Quyết định nên dạy chiêu TM nào cho\n"
	.string "POKéMON chẳng dễ chút nào...$"

LilycoveCity_DepartmentStore_4F_Text_FiftyDifferentTMs:
	.string "Có rất nhiều loại chiêu TM khác nhau.\p"
	.string "Một cuốn danh mục tôi từng đọc nói rằng\n"
	.string "có năm mươi loại.$"

LilycoveCity_DepartmentStore_4F_Text_PokemonOnlyHaveFourMoves:
	.string "Tôi muốn kiếm đủ mọi TM, nhưng mỗi\n"
	.string "POKéMON chỉ học được bốn chiêu.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global LilycoveCity_DepartmentStore_4F_Text_AttackOrDefenseTM
	.global LilycoveCity_DepartmentStore_4F_Text_FiftyDifferentTMs
	.global LilycoveCity_DepartmentStore_4F_Text_PokemonOnlyHaveFourMoves
@ END GENERATED LOCALIZATION EXPORTS
