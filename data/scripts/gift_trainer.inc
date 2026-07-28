MysteryGiftScript_VisitingTrainer::
	setvaddress MysteryGiftScript_VisitingTrainer
	special ValidateEReaderTrainer
	vgoto_if_eq VAR_RESULT, 0, MysteryGiftScript_VisitingTrainerArrived
	lock
	faceplayer
	vmessage sText_MysteryGiftVisitingTrainerInstructions
	waitmessage
	waitbuttonpress
	release
	end

MysteryGiftScript_VisitingTrainerArrived:
	lock
	faceplayer
	vmessage sText_MysteryGiftVisitingTrainerArrived
	waitmessage
	waitbuttonpress
	release
	end

sText_MysteryGiftVisitingTrainerInstructions:
	.string "Cảm ơn bạn đã dùng hệ thống\n"
	.string "MYSTERY GIFT.\p"
	.string "Khi giữ WONDER CARD này, bạn có thể\n"
	.string "tham gia một cuộc khảo sát tại POKéMON\l"
	.string "MART.\p"
	.string "Hãy dùng các cuộc khảo sát này để mời\n"
	.string "HLV đến SOOTOPOLIS CITY.\p"
	.string "...Để tôi cho bạn biết mật khẩu bí mật\n"
	.string "của một cuộc khảo sát:\p"
	.string "GIVE ME AWESOME TRAINER\p"
	.string "Hãy điền câu đó vào khảo sát rồi gửi\n"
	.string "đến WIRELESS COMMUNICATION SYSTEM.$"

sText_MysteryGiftVisitingTrainerArrived:
	.string "Cảm ơn bạn đã dùng hệ thống\n"
	.string "MYSTERY GIFT.\p"
	.string "Một HLV đã đến SOOTOPOLIS CITY để\n"
	.string "tìm bạn.\p"
	.string "Hy vọng bạn sẽ tận hưởng trận đấu với\n"
	.string "vị HLV ghé thăm này.\p"
	.string "Bạn có thể mời những HLV khác\n"
	.string "bằng cách nhập các mật khẩu khác.\p"
	.string "Hãy thử tìm thêm những mật khẩu có thể\n"
	.string "dùng được.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global sText_MysteryGiftVisitingTrainerInstructions
	.global sText_MysteryGiftVisitingTrainerArrived
@ END GENERATED LOCALIZATION EXPORTS
