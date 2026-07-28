MossdeepCity_Mart_MapScripts::
	.byte 0

MossdeepCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart MossdeepCity_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
MossdeepCity_Mart_Pokemart:
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_NET_BALL
	.2byte ITEM_DIVE_BALL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	pokemartlistend

MossdeepCity_Mart_EventScript_Woman::
	msgbox MossdeepCity_Mart_Text_ReviveIsFantastic, MSGBOX_NPC
	end

MossdeepCity_Mart_EventScript_Boy::
	msgbox MossdeepCity_Mart_Text_MaxRepelLastsLongest, MSGBOX_NPC
	end

MossdeepCity_Mart_EventScript_Sailor::
	msgbox MossdeepCity_Mart_Text_NetAndDiveBallsRare, MSGBOX_NPC
	end

MossdeepCity_Mart_Text_ReviveIsFantastic:
	.string "REVIVE tuyệt thật!\p"
	.string "Dùng nó cho một POKéMON bị ngất,\n"
	.string "POKéMON đó sẽ tỉnh lại.\p"
	.string "Nhưng hãy cẩn thận, REVIVE không hồi\n"
	.string "lại PP đã tiêu hao của các chiêu thức.$"

MossdeepCity_Mart_Text_MaxRepelLastsLongest:
	.string "MAX REPEL khiến mọi POKéMON yếu tránh\n"
	.string "xa.\p"
	.string "Trong tất cả các loại thuốc xịt REPEL,\n"
	.string "nó có tác dụng lâu nhất.$"

MossdeepCity_Mart_Text_NetAndDiveBallsRare:
	.string "NET BALL và DIVE BALL là những POKé\n"
	.string "BALL hiếm chỉ được sản xuất tại\l"
	.string "MOSSDEEP.\p"
	.string "NET BALL hiệu quả khi dùng với\n"
	.string "BUG-type và WATER-type POKéMON.\p"
	.string "DIVE BALL phát huy hiệu quả cao nhất\n"
	.string "với POKéMON dưới đáy biển.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global MossdeepCity_Mart_Text_ReviveIsFantastic
	.global MossdeepCity_Mart_Text_MaxRepelLastsLongest
	.global MossdeepCity_Mart_Text_NetAndDiveBallsRare
@ END GENERATED LOCALIZATION EXPORTS
