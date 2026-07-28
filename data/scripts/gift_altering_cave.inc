MysteryGiftScript_AlteringCave::
	setvaddress MysteryGiftScript_AlteringCave
	addvar VAR_ALTERING_CAVE_WILD_SET, 1
	vgoto_if_ne VAR_ALTERING_CAVE_WILD_SET, (NUM_ALTERING_CAVE_TABLES + 1), MysteryGiftScript_AlteringCave_
	setvar VAR_ALTERING_CAVE_WILD_SET, 0
MysteryGiftScript_AlteringCave_:
	lock
	faceplayer
	vmessage sText_MysteryGiftAlteringCave
	waitmessage
	waitbuttonpress
	release
	end

sText_MysteryGiftAlteringCave:
	.string "Cảm ơn bạn đã dùng hệ thống\n"
	.string "MYSTERY GIFT.\p"
	.string "Dường như đang có tin đồn về việc bắt\n"
	.string "gặp những POKéMON hiếm.\p"
	.string "Theo lời đồn, chúng xuất hiện tại\n"
	.string "ALTERING CAVE trên ROUTE 103.\p"
	.string "Có lẽ tin đồn này đáng để bạn điều tra.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global sText_MysteryGiftAlteringCave
@ END GENERATED LOCALIZATION EXPORTS
