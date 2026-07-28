MysteryGiftScript_MysticTicket::
	setvaddress MysteryGiftScript_MysticTicket
	lock
	faceplayer
	vgoto_if_set FLAG_RECEIVED_MYSTIC_TICKET, MysticTicket_Obtained
	vgoto_if_set FLAG_CAUGHT_LUGIA, MysticTicket_Obtained
	vgoto_if_set FLAG_CAUGHT_HO_OH, MysticTicket_Obtained
	checkitem ITEM_MYSTIC_TICKET
	vgoto_if_eq VAR_RESULT, TRUE, MysticTicket_Obtained
	vmessage sText_MysticTicketForYou
	waitmessage
	waitbuttonpress
	checkitemspace ITEM_MYSTIC_TICKET
	vgoto_if_eq VAR_RESULT, FALSE, MysticTicket_NoBagSpace
	giveitem ITEM_MYSTIC_TICKET
	setflag FLAG_ENABLE_SHIP_NAVEL_ROCK
	setflag FLAG_RECEIVED_MYSTIC_TICKET
	vmessage sText_MysticTicketUseAtPort
	waitmessage
	waitbuttonpress
	release
	end

MysticTicket_NoBagSpace:
	vmessage sText_MysticTicketBagFull
	waitmessage
	waitbuttonpress
	release
	end

MysticTicket_Obtained:
	vmessage sText_MysticTicketThankYou
	waitmessage
	waitbuttonpress
	release
	end

sText_MysticTicketForYou:
	.string "Cảm ơn bạn đã dùng hệ thống\n"
	.string "MYSTERY GIFT.\p"
	.string "Hẳn bạn là {PLAYER}. Ở đây có một tấm\n"
	.string "vé dành cho bạn.$"

sText_MysticTicketUseAtPort:
	.string "Có vẻ tấm vé này được dùng tại cảng\n"
	.string "LILYCOVE CITY.\p"
	.string "Sao bạn không thử dùng xem nó có tác\n"
	.string "dụng gì?$"

sText_MysticTicketThankYou:
	.string "Cảm ơn bạn đã dùng hệ thống\n"
	.string "MYSTERY GIFT.$"

sText_MysticTicketBagFull:
	.string "Ồ, tôi xin lỗi, {PLAYER}. KEY ITEMS\n"
	.string "POCKET trong TÚI ĐỒ của bạn đã đầy.\p"
	.string "Hãy cất thứ gì đó vào PC rồi quay lại\n"
	.string "nhận món này.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global sText_MysticTicketForYou
	.global sText_MysticTicketUseAtPort
	.global sText_MysticTicketThankYou
	.global sText_MysticTicketBagFull
@ END GENERATED LOCALIZATION EXPORTS
