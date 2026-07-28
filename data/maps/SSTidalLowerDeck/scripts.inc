SSTidalLowerDeck_MapScripts::
	.byte 0

SSTidalLowerDeck_EventScript_Phillip::
	trainerbattle_single TRAINER_PHILLIP, SSTidalLowerDeck_Text_PhillipIntro, SSTidalLowerDeck_Text_PhillipDefeat
	msgbox SSTidalLowerDeck_Text_PhillipPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalLowerDeck_EventScript_Leonard::
	trainerbattle_single TRAINER_LEONARD, SSTidalLowerDeck_Text_LeonardIntro, SSTidalLowerDeck_Text_LeonardDefeat
	msgbox SSTidalLowerDeck_Text_LeonardPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalLowerDeck_Text_PhillipIntro:
	.string "Aaaa! Tôi chán ngấy, mệt bở hơi tai vì\n"
	.string "phải dọn dẹp chỗ rộng thế này rồi!\p"
	.string "Đấu nhanh một trận nào!$"

SSTidalLowerDeck_Text_PhillipDefeat:
	.string "Em trai, anh thua rồi!$"

SSTidalLowerDeck_Text_PhillipPostBattle:
	.string "Chúng tôi là CLEANUP BROTHERS!\p"
	.string "Anh lớn đổ chất tẩy rửa, còn em nhỏ lo\n"
	.string "cọ rửa!$"

SSTidalLowerDeck_Text_LeonardIntro:
	.string "Đây là đáy thân tàu. Rộng rãi lắm. Đủ\n"
	.string "chỗ cho một trận đấu POKéMON.$"

SSTidalLowerDeck_Text_LeonardDefeat:
	.string "Anh trai, em thua rồi!$"

SSTidalLowerDeck_Text_LeonardPostBattle:
	.string "Chúng tôi là CLEANUP BROTHERS!\p"
	.string "Anh lớn đổ chất tẩy rửa, còn em nhỏ lo\n"
	.string "cọ rửa!$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global SSTidalLowerDeck_Text_PhillipIntro
	.global SSTidalLowerDeck_Text_PhillipDefeat
	.global SSTidalLowerDeck_Text_PhillipPostBattle
	.global SSTidalLowerDeck_Text_LeonardIntro
	.global SSTidalLowerDeck_Text_LeonardDefeat
	.global SSTidalLowerDeck_Text_LeonardPostBattle
@ END GENERATED LOCALIZATION EXPORTS
