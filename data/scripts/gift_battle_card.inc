MysteryGiftScript_BattleCard::
	setvaddress MysteryGiftScript_BattleCard
	vgoto_if_set FLAG_MYSTERY_GIFT_DONE, MysteryGiftScript_BattleCardInfo
	setorcopyvar VAR_RESULT, GET_CARD_BATTLES_WON
	specialvar VAR_0x8008, GetMysteryGiftCardStat
	vgoto_if_ne VAR_0x8008, REQUIRED_CARD_BATTLES, MysteryGiftScript_BattleCardInfo
	lock
	faceplayer
	vmessage sText_MysteryGiftBattleCountCard_WonPrize
	waitmessage
	waitbuttonpress
	giveitem ITEM_POTION
	release
	setflag FLAG_MYSTERY_GIFT_DONE
	end

MysteryGiftScript_BattleCardInfo:
	lock
	faceplayer
	vmessage sText_MysteryGiftBattleCountCard
	waitmessage
	waitbuttonpress
	release
	end

sText_MysteryGiftBattleCountCard:
	.string "Cảm ơn bạn đã dùng hệ thống\n"
	.string "MYSTERY GIFT.\p"
	.string "BATTLE COUNT CARD sẽ ghi lại thành tích\n"
	.string "chiến đấu của bạn với những HLV\l"
	.string "có cùng CARD.\p"
	.string "Hãy tìm và chiến đấu với những\n"
	.string "HLV có cùng CARD với bạn.\p"
	.string "Bạn có thể xem bảng xếp hạng tổng thể\n"
	.string "bằng cách đọc NEWS.\p"
	.string "Nhất định hãy thử nhé!$"

sText_MysteryGiftBattleCountCard_WonPrize:
	.string "Cảm ơn bạn đã dùng hệ thống\n"
	.string "MYSTERY GIFT.\p"
	.string "Xin chúc mừng!\p"
	.string "Bạn đã giành được phần thưởng vì\n"
	.string "thắng ba trận!\p"
	.string "Hy vọng điều này sẽ thôi thúc bạn chiến\n"
	.string "đấu nhiều hơn nữa.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global sText_MysteryGiftBattleCountCard
	.global sText_MysteryGiftBattleCountCard_WonPrize
@ END GENERATED LOCALIZATION EXPORTS
