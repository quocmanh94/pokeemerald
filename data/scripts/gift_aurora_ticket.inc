MysteryGiftScript_AuroraTicket::
	setvaddress MysteryGiftScript_AuroraTicket
	lock
	faceplayer
	vgoto_if_set FLAG_RECEIVED_AURORA_TICKET, AuroraTicket_Obtained
	vgoto_if_set FLAG_BATTLED_DEOXYS, AuroraTicket_Obtained
	checkitem ITEM_AURORA_TICKET
	vgoto_if_eq VAR_RESULT, TRUE, AuroraTicket_Obtained
	vmessage sText_AuroraTicketForYou
	waitmessage
	waitbuttonpress
	checkitemspace ITEM_AURORA_TICKET
	vgoto_if_eq VAR_RESULT, FALSE, AuroraTicket_NoBagSpace
	giveitem ITEM_AURORA_TICKET
	setflag FLAG_ENABLE_SHIP_BIRTH_ISLAND
	setflag FLAG_RECEIVED_AURORA_TICKET
	vmessage sText_AuroraTicketUseAtPort
	waitmessage
	waitbuttonpress
	release
	end

AuroraTicket_NoBagSpace:
	vmessage sText_AuroraTicketBagFull
	waitmessage
	waitbuttonpress
	release
	end

AuroraTicket_Obtained:
	vmessage sText_AuroraTicketThankYou
	waitmessage
	waitbuttonpress
	release
	end

sText_AuroraTicketForYou:
	.string "Cảm ơn bạn đã dùng hệ thống\n"
	.string "MYSTERY GIFT.\p"
	.string "Hẳn bạn là {PLAYER}. Ở đây có một tấm\n"
	.string "vé dành cho bạn.$"

sText_AuroraTicketUseAtPort:
	.string "Có vẻ tấm vé này được dùng tại cảng\n"
	.string "LILYCOVE CITY.\p"
	.string "Sao bạn không thử dùng xem nó có tác\n"
	.string "dụng gì?$"

sText_AuroraTicketThankYou:
	.string "Cảm ơn bạn đã dùng hệ thống\n"
	.string "MYSTERY GIFT.$"

sText_AuroraTicketBagFull:
	.string "Ồ, tôi xin lỗi, {PLAYER}. KEY ITEMS\n"
	.string "POCKET trong TÚI ĐỒ của bạn đã đầy.\p"
	.string "Hãy cất thứ gì đó vào PC rồi quay lại\n"
	.string "nhận món này.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global sText_AuroraTicketForYou
	.global sText_AuroraTicketUseAtPort
	.global sText_AuroraTicketThankYou
	.global sText_AuroraTicketBagFull
@ END GENERATED LOCALIZATION EXPORTS
