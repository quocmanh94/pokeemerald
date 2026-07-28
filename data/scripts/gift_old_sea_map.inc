MysteryGiftScript_OldSeaMap::
	setvaddress MysteryGiftScript_OldSeaMap
	lock
	faceplayer
	vgoto_if_set FLAG_RECEIVED_OLD_SEA_MAP, OldSeaMap_Obtained
	vgoto_if_set FLAG_CAUGHT_MEW, OldSeaMap_Obtained
	checkitem ITEM_OLD_SEA_MAP
	vgoto_if_eq VAR_RESULT, TRUE, OldSeaMap_Obtained
	vmessage sText_MysteryGiftOldSeaMapForYou
	waitmessage
	waitbuttonpress
	checkitemspace ITEM_OLD_SEA_MAP
	vgoto_if_eq VAR_RESULT, FALSE, OldSeaMap_NoBagSpace
	giveitem ITEM_OLD_SEA_MAP
	setflag FLAG_ENABLE_SHIP_FARAWAY_ISLAND
	setflag FLAG_RECEIVED_OLD_SEA_MAP
	vmessage sText_MysteryGiftOldSeaMapUseAtPort
	waitmessage
	waitbuttonpress
	release
	end

OldSeaMap_NoBagSpace:
	vmessage sText_MysteryGiftOldSeaMapBagFull
	waitmessage
	waitbuttonpress
	release
	end

OldSeaMap_Obtained:
	vmessage sText_MysteryGiftOldSeaMapThankYou
	waitmessage
	waitbuttonpress
	release
	end

sText_MysteryGiftOldSeaMapForYou:
	.string "Cảm ơn bạn đã dùng hệ thống\n"
	.string "MYSTERY GIFT.\p"
	.string "Để tôi xác nhận, bạn là {PLAYER}, đúng\n"
	.string "không?\p"
	.string "Chúng tôi đã nhận được OLD SEA MAP đề\n"
	.string "tên người nhận là bạn.$"

sText_MysteryGiftOldSeaMapUseAtPort:
	.string "Có vẻ món này được dùng tại cảng\n"
	.string "LILYCOVE CITY.\p"
	.string "Sao bạn không thử dùng xem nó có tác\n"
	.string "dụng gì?$"

sText_MysteryGiftOldSeaMapThankYou:
	.string "Cảm ơn bạn đã dùng hệ thống\n"
	.string "MYSTERY GIFT.$"

sText_MysteryGiftOldSeaMapBagFull:
	.string "Ồ, tôi xin lỗi, {PLAYER}. KEY ITEMS\n"
	.string "POCKET trong TÚI ĐỒ của bạn đã đầy.\p"
	.string "Hãy cất thứ gì đó vào PC rồi quay lại\n"
	.string "nhận món này.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global sText_MysteryGiftOldSeaMapForYou
	.global sText_MysteryGiftOldSeaMapUseAtPort
	.global sText_MysteryGiftOldSeaMapThankYou
	.global sText_MysteryGiftOldSeaMapBagFull
@ END GENERATED LOCALIZATION EXPORTS
