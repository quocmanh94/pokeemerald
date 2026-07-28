FallarborTown_Mart_MapScripts::
	.byte 0

FallarborTown_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart FallarborTown_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
FallarborTown_Mart_Pokemart:
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_X_SPECIAL
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_GUARD_SPEC
	pokemartlistend

FallarborTown_Mart_EventScript_Woman::
	msgbox FallarborTown_Mart_Text_DecidingSkittyEvolve, MSGBOX_NPC
	end

FallarborTown_Mart_EventScript_PokefanM::
	msgbox FallarborTown_Mart_Text_SellNuggetIFound, MSGBOX_NPC
	end

FallarborTown_Mart_EventScript_Skitty::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SKITTY, CRY_MODE_NORMAL
	msgbox FallarborTown_Mart_Text_Skitty, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FallarborTown_Mart_Text_DecidingSkittyEvolve:
	.string "Tôi đang rất khó quyết định có nên cho\n"
	.string "SKITTY tiến hóa hay không.\p"
	.string "Chỉ cần dùng MOON STONE này thôi,\n"
	.string "nhưng thật khó quyết định...\p"
	.string "Nếu cho nó tiến hóa, nó sẽ mạnh hơn rất\n"
	.string "nhiều.\p"
	.string "Nhưng ngoại hình của nó cũng sẽ khác\n"
	.string "hẳn.$"

FallarborTown_Mart_Text_Skitty:
	.string "SKITTY: Meo?$"

FallarborTown_Mart_Text_SellNuggetIFound:
	.string "NUGGET tôi tìm thấy ở đây... Chắc tôi\n"
	.string "đành bán nó thôi, vì nó chẳng còn công\l"
	.string "dụng nào khác.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global FallarborTown_Mart_Text_DecidingSkittyEvolve
	.global FallarborTown_Mart_Text_Skitty
	.global FallarborTown_Mart_Text_SellNuggetIFound
@ END GENERATED LOCALIZATION EXPORTS
