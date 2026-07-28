SSTidalRooms_MapScripts::
	.byte 0

SSTidalRooms_EventScript_SnatchGiver::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_SNATCH, SSTidalRooms_EventScript_ExplainSnatch
	msgbox SSTidalRooms_Text_NotSuspiciousTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM_SNATCH
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_SNATCH
	msgbox SSTidalRooms_Text_ExplainSnatch, MSGBOX_DEFAULT
	release
	end

SSTidalRooms_EventScript_ExplainSnatch::
	msgbox SSTidalRooms_Text_ExplainSnatch, MSGBOX_DEFAULT
	release
	end

SSTidalRooms_EventScript_Bed::
	lockall
	msgbox SSTidalRooms_Text_TakeRestOnBed, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	call SSTidalRooms_EventScript_ProgessCruiseAfterBed
	releaseall
	end

SSTidalRooms_EventScript_Colton::
	trainerbattle_single TRAINER_COLTON, SSTidalRooms_Text_ColtonIntro, SSTidalRooms_Text_ColtonDefeat
	msgbox SSTidalRooms_Text_ColtonPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Micah::
	trainerbattle_single TRAINER_MICAH, SSTidalRooms_Text_MicahIntro, SSTidalRooms_Text_MicahDefeat
	msgbox SSTidalRooms_Text_MicahPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Thomas::
	trainerbattle_single TRAINER_THOMAS, SSTidalRooms_Text_ThomasIntro, SSTidalRooms_Text_ThomasDefeat
	msgbox SSTidalRooms_Text_ThomasPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Jed::
	trainerbattle_double TRAINER_LEA_AND_JED, SSTidalRooms_Text_JedIntro, SSTidalRooms_Text_JedDefeat, SSTidalRooms_Text_JedNotEnoughMons
	msgbox SSTidalRooms_Text_JedPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Lea::
	trainerbattle_double TRAINER_LEA_AND_JED, SSTidalRooms_Text_LeaIntro, SSTidalRooms_Text_LeaDefeat, SSTidalRooms_Text_LeaNotEnoughMons
	msgbox SSTidalRooms_Text_LeaPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Garret::
	trainerbattle_single TRAINER_GARRET, SSTidalRooms_Text_GarretIntro, SSTidalRooms_Text_GarretDefeat
	msgbox SSTidalRooms_Text_GarretPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Naomi::
	trainerbattle_single TRAINER_NAOMI, SSTidalRooms_Text_NaomiIntro, SSTidalRooms_Text_NaomiDefeat
	msgbox SSTidalRooms_Text_NaomiPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_Text_TakeRestOnBed:
	.string "Có một chiếc giường... Nghỉ một lát\n"
	.string "thôi.$"

SSTidalRooms_Text_ColtonIntro:
	.string "Tôi thường đi tàu đến LILYCOVE CITY.\p"
	.string "Vì tôi thích tham dự các cuộc thi.$"

SSTidalRooms_Text_ColtonDefeat:
	.string "Một trận đấu thật thú vị!$"

SSTidalRooms_Text_ColtonPostBattle:
	.string "Chỉ tưởng tượng xem mình sẽ gặp\n"
	.string "những POKéMON nào trong cuộc thi tiếp\l"
	.string "theo là tôi đã phấn khích lắm rồi. Cảm\l"
	.string "giác mong chờ thật hồi hộp!$"

SSTidalRooms_Text_MicahIntro:
	.string "Bạn bè của bạn có mạnh không?$"

SSTidalRooms_Text_MicahDefeat:
	.string "Quả thật, bạn bè của bạn rất mạnh.$"

SSTidalRooms_Text_MicahPostBattle:
	.string "Bạn bè đâu nhất thiết phải là con\n"
	.string "người. Với tôi, POKéMON là những người\l"
	.string "bạn quý giá!$"

SSTidalRooms_Text_ThomasIntro:
	.string "Này cháu... Cháu đã gõ cửa chưa?$"

SSTidalRooms_Text_ThomasDefeat:
	.string "Thất bại cần được điềm tĩnh chấp nhận,\n"
	.string "không hấp tấp hay hoảng loạn.$"

SSTidalRooms_Text_ThomasPostBattle:
	.string "Không nao núng trong bất kỳ tình huống\n"
	.string "nào là quy tắc ứng xử của một\l"
	.string "GENTLEMAN.$"

SSTidalRooms_Text_JedIntro:
	.string "JED: Tôi hơi ngại khi nói điều này,\n"
	.string "nhưng... Chúng tôi sẽ cho bạn thấy sức\l"
	.string "mạnh tình yêu của mình!$"

SSTidalRooms_Text_JedDefeat:
	.string "JED: Hầy...$"

SSTidalRooms_Text_JedPostBattle:
	.string "JED: Đây là lần đầu sức mạnh tình yêu\n"
	.string "của chúng tôi không thắng nổi! Bạn hẳn\l"
	.string "là một HLV tuyệt vời!$"

SSTidalRooms_Text_JedNotEnoughMons:
	.string "JED: Bạn chỉ có một POKéMON thôi sao?\n"
	.string "Như thế chẳng cô đơn quá à?$"

SSTidalRooms_Text_LeaIntro:
	.string "LEA: Tôi thấy hơi ngượng, nhưng...\n"
	.string "Chúng tôi sẽ cho bạn thấy sức mạnh\l"
	.string "tình yêu của mình!$"

SSTidalRooms_Text_LeaDefeat:
	.string "LEA: Ôi, chán quá!$"

SSTidalRooms_Text_LeaPostBattle:
	.string "LEA: Không thể tin được! Sức mạnh tình\n"
	.string "yêu của chúng tôi đã thất bại... Bạn hẳn\l"
	.string "là một HLV tuyệt vời!$"

SSTidalRooms_Text_LeaNotEnoughMons:
	.string "LEA: Tôi muốn đấu lắm... Nhưng bạn còn\n"
	.string "không có nổi hai POKéMON...$"

SSTidalRooms_Text_GarretIntro:
	.string "À, bạn đến đúng lúc lắm.\p"
	.string "Tôi đang chán. Bạn có thể mua vui cho\n"
	.string "tôi.$"

SSTidalRooms_Text_GarretDefeat:
	.string "...Thế là được.$"

SSTidalRooms_Text_GarretPostBattle:
	.string "Có lẽ ta nên bảo Cha mua cho ta một\n"
	.string "chiếc du thuyền. Một chiếc du thuyền\l"
	.string "cho ta và POKéMON!$"

SSTidalRooms_Text_NaomiIntro:
	.string "Ôi, bạn đúng là một HLV đáng yêu.\n"
	.string "Bạn muốn dùng trà chứ? Hay bạn thích\l"
	.string "đấu hơn?$"

SSTidalRooms_Text_NaomiDefeat:
	.string "Tôi hiểu rồi. Bạn thuộc kiểu năng động.$"

SSTidalRooms_Text_NaomiPostBattle:
	.string "Một chuyến vòng quanh thế giới trên\n"
	.string "tàu biển sang trọng quả có nét quyến rũ\l"
	.string "riêng...\p"
	.string "Nhưng tôi phải thừa nhận, đi phà tham\n"
	.string "quan HOENN cũng có cái thú của nó.$"

SSTidalRooms_Text_NotSuspiciousTakeThis:
	.string "Ờ... Chào! Tôi... tôi không hề có biểu hiện\n"
	.string "đáng ngờ đâu! Ờ... Cái này cho bạn! Miễn\l"
	.string "phí!\p"
	.string "Thật... thật đấy, tôi không SNATCH nó từ\n"
	.string "ai đâu! Tôi không bao giờ làm thế! Nó\l"
	.string "sạch sẽ! Bạn cứ dùng đi!$"

SSTidalRooms_Text_ExplainSnatch:
	.string "SNATCH đánh cắp hiệu ứng có lợi của\n"
	.string "một số chiêu thức trước khi đối thủ\l"
	.string "hoặc đồng minh kịp sử dụng chúng.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global SSTidalRooms_Text_TakeRestOnBed
	.global SSTidalRooms_Text_ColtonIntro
	.global SSTidalRooms_Text_ColtonDefeat
	.global SSTidalRooms_Text_ColtonPostBattle
	.global SSTidalRooms_Text_MicahIntro
	.global SSTidalRooms_Text_MicahDefeat
	.global SSTidalRooms_Text_MicahPostBattle
	.global SSTidalRooms_Text_ThomasIntro
	.global SSTidalRooms_Text_ThomasDefeat
	.global SSTidalRooms_Text_ThomasPostBattle
	.global SSTidalRooms_Text_JedIntro
	.global SSTidalRooms_Text_JedDefeat
	.global SSTidalRooms_Text_JedPostBattle
	.global SSTidalRooms_Text_JedNotEnoughMons
	.global SSTidalRooms_Text_LeaIntro
	.global SSTidalRooms_Text_LeaDefeat
	.global SSTidalRooms_Text_LeaPostBattle
	.global SSTidalRooms_Text_LeaNotEnoughMons
	.global SSTidalRooms_Text_GarretIntro
	.global SSTidalRooms_Text_GarretDefeat
	.global SSTidalRooms_Text_GarretPostBattle
	.global SSTidalRooms_Text_NaomiIntro
	.global SSTidalRooms_Text_NaomiDefeat
	.global SSTidalRooms_Text_NaomiPostBattle
	.global SSTidalRooms_Text_NotSuspiciousTakeThis
	.global SSTidalRooms_Text_ExplainSnatch
@ END GENERATED LOCALIZATION EXPORTS
