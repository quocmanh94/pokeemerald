DewfordTown_House2_MapScripts::
	.byte 0

DewfordTown_House2_EventScript_Man::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SILK_SCARF, DewfordTown_House2_EventScript_ExplainSilkScarf
	msgbox DewfordTown_House2_Text_WantYouToHaveSilkScarf, MSGBOX_DEFAULT
	giveitem ITEM_SILK_SCARF
	goto_if_eq VAR_RESULT, FALSE, DewfordTown_House2_EventScript_NoRoomForScarf
	setflag FLAG_RECEIVED_SILK_SCARF
	release
	end

DewfordTown_House2_EventScript_NoRoomForScarf::
	msgbox DewfordTown_House2_Text_NoRoom, MSGBOX_DEFAULT
	release
	end

DewfordTown_House2_EventScript_ExplainSilkScarf::
	msgbox DewfordTown_House2_Text_ExplainSilkScarf, MSGBOX_DEFAULT
	release
	end

DewfordTown_House2_EventScript_Boy::
	msgbox DewfordTown_House2_Text_BrawlySoCool, MSGBOX_NPC
	end

DewfordTown_House2_Text_WantYouToHaveSilkScarf:
	.string "Mở to mắt mà ngắm này!\p"
	.string "Đây là SILK SCARF. Nó đang dẫn đầu xu\n"
	.string "hướng thời trang đấy!\p"
	.string "Ôi, tôi thấy mắt cậu sáng lên rồi! Cậu\n"
	.string "biết thưởng thức phong cách chói lóa\l"
	.string "của tôi!\p"
	.string "Ôi, cậu thật dễ mến! Đây, tôi muốn tặng\n"
	.string "nó cho cậu!$"

DewfordTown_House2_Text_NoRoom:
	.string "Ồ, cậu không còn chỗ trống sao?\p"
	.string "Nghe kỹ này, SCARF này là món nhất định\n"
	.string "phải có! Tôi sẵn sàng bán hết đồ của\l"
	.string "mình để sở hữu nó!$"

DewfordTown_House2_Text_ExplainSilkScarf:
	.string "SILK SCARF làm tăng sức mạnh của các\n"
	.string "chiêu hệ NORMAL.\p"
	.string "Đây là một chiếc SCARF tuyệt vời, phù\n"
	.string "hợp với gần như mọi POKéMON!$"

DewfordTown_House2_Text_BrawlySoCool:
	.string "Chà, cậu đã cất công vượt biển đến\n"
	.string "thăm DEWFORD sao?\p"
	.string "Có phải cậu đến vì đã nghe nói về\n"
	.string "BRAWLY không?\p"
	.string "Anh ấy ngầu lắm... Ai cũng thần tượng\n"
	.string "anh ấy.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global DewfordTown_House2_Text_WantYouToHaveSilkScarf
	.global DewfordTown_House2_Text_NoRoom
	.global DewfordTown_House2_Text_ExplainSilkScarf
	.global DewfordTown_House2_Text_BrawlySoCool
@ END GENERATED LOCALIZATION EXPORTS
