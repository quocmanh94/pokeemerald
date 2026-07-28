PetalburgCity_Mart_MapScripts::
	.byte 0

PetalburgCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	goto_if_set FLAG_PETALBURG_MART_EXPANDED_ITEMS, PetalburgCity_Mart_EventScript_ExpandedItems
	pokemart PetalburgCity_Mart_Pokemart_Basic
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
PetalburgCity_Mart_Pokemart_Basic:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_REPEL
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	.2byte ITEM_ORANGE_MAIL
	pokemartlistend

PetalburgCity_Mart_EventScript_ExpandedItems::
	pokemart PetalburgCity_Mart_Pokemart_Expanded
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
PetalburgCity_Mart_Pokemart_Expanded:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_REPEL
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	.2byte ITEM_ORANGE_MAIL
	pokemartlistend

PetalburgCity_Mart_EventScript_Woman::
	msgbox PetalburgCity_Mart_Text_WeakWillGrowStronger, MSGBOX_NPC
	end

PetalburgCity_Mart_EventScript_Boy::
	msgbox PetalburgCity_Mart_Text_RepelIsUseful, MSGBOX_NPC
	end

PetalburgCity_Mart_EventScript_Man::
	msgbox PetalburgCity_Mart_Text_TakeSomeAntidotesWithYou, MSGBOX_NPC
	end

PetalburgCity_Mart_Text_WeakWillGrowStronger:
	.string "Dù bây giờ một POKéMON còn yếu, nó rồi\n"
	.string "sẽ mạnh lên.\p"
	.string "Điều quan trọng nhất là tình yêu! Tình\n"
	.string "yêu dành cho POKéMON của bạn!$"

PetalburgCity_Mart_Text_RepelIsUseful:
	.string "Bạn có dùng REPEL không? Nó khiến\n"
	.string "POKéMON tránh xa, nên rất hữu ích khi\l"
	.string "bạn đang vội.$"

PetalburgCity_Mart_Text_TakeSomeAntidotesWithYou:
	.string "Bạn có mang theo ANTIDOTES không?\p"
	.string "Nếu đi lại cùng một POKéMON bị trúng\n"
	.string "độc, nó sẽ mất HP cho đến khi ngất xỉu.\l"
	.string "Hãy mang theo vài ANTIDOTES.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global PetalburgCity_Mart_Text_WeakWillGrowStronger
	.global PetalburgCity_Mart_Text_RepelIsUseful
	.global PetalburgCity_Mart_Text_TakeSomeAntidotesWithYou
@ END GENERATED LOCALIZATION EXPORTS
