MysteryGiftScript_StampCard::
	setvaddress MysteryGiftScript_StampCard
	setorcopyvar VAR_RESULT, GET_MAX_STAMPS
	specialvar VAR_0x8008, GetMysteryGiftCardStat
	setorcopyvar VAR_RESULT, GET_NUM_STAMPS
	specialvar VAR_0x8009, GetMysteryGiftCardStat
	subvar VAR_0x8008, VAR_0x8009
	buffernumberstring STR_VAR_1, VAR_0x8008
	lock
	faceplayer
	vmessage sText_MysteryGiftStampCard
	waitmessage
	waitbuttonpress
	release
	end

sText_MysteryGiftStampCard:
	.string "Cảm ơn bạn đã dùng hệ thống\n"
	.string "STAMP CARD.\p"
	.string "Bạn cần sưu tầm thêm\n"
	.string "{STR_VAR_1} dấu nữa để hoàn\l"
	.string "thành STAMP CARD.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global sText_MysteryGiftStampCard
@ END GENERATED LOCALIZATION EXPORTS
