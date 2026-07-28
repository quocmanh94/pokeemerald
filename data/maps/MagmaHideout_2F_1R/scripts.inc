MagmaHideout_2F_1R_MapScripts::
	.byte 0

MagmaHideout_2F_1R_EventScript_Grunt14::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_14, MagmaHideout_2F_1R_Text_Grunt14Intro, MagmaHideout_2F_1R_Text_Grunt14Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt14PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_3, MagmaHideout_2F_1R_Text_Grunt3Intro, MagmaHideout_2F_1R_Text_Grunt3Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_4, MagmaHideout_2F_1R_Text_Grunt4Intro, MagmaHideout_2F_1R_Text_Grunt4Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_EventScript_Grunt5::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_5, MagmaHideout_2F_1R_Text_Grunt5Intro, MagmaHideout_2F_1R_Text_Grunt5Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_Text_Grunt14Intro:
	.string "Gì, gì, gì cơ?\p"
	.string "Chỉ thành viên TEAM MAGMA mới được\n"
	.string "phép vào đây!\p"
	.string "Nhưng ngươi không mặc đồng phục TEAM\n"
	.string "MAGMA...\p"
	.string "Đáng ngờ quá! Đấu với ta!$"

MagmaHideout_2F_1R_Text_Grunt14Defeat:
	.string "Aiyiyi... Niềm kiêu hãnh của một thành\n"
	.string "viên TEAM MAGMA...$"

MagmaHideout_2F_1R_Text_Grunt14PostBattle:
	.string "Nếu hay bị lạnh run, ngươi nên gia nhập\n"
	.string "TEAM MAGMA.$"

MagmaHideout_2F_1R_Text_Grunt3Intro:
	.string "Đứng lại đó!\p"
	.string "Ngươi thật sự nghĩ ta sẽ ngậm miệng và\n"
	.string "để ngươi ung dung đi qua sao?$"

MagmaHideout_2F_1R_Text_Grunt3Defeat:
	.string "Ồ, ghê thật! Ta xin thua!$"

MagmaHideout_2F_1R_Text_Grunt3PostBattle:
	.string "Có lẽ cứ để ngươi đi mà không thách\n"
	.string "đấu còn hơn...$"

MagmaHideout_2F_1R_Text_Grunt4Intro:
	.string "A ha! Có kẻ xâm nhập!$"

MagmaHideout_2F_1R_Text_Grunt4Defeat:
	.string "Graaa!$"

MagmaHideout_2F_1R_Text_Grunt4PostBattle:
	.string "Ta thua rồi.\p"
	.string "Ta thật sự vẫn phải chạy vòng vòng thế\n"
	.string "này sao?$"

MagmaHideout_2F_1R_Text_Grunt5Intro:
	.string "Ối, ối! Có kẻ xâm nhập!$"

MagmaHideout_2F_1R_Text_Grunt5Defeat:
	.string "Lầm bầm...$"

MagmaHideout_2F_1R_Text_Grunt5PostBattle:
	.string "Thật ra, tôi đâu có giỏi chiến đấu...$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global MagmaHideout_2F_1R_Text_Grunt14Intro
	.global MagmaHideout_2F_1R_Text_Grunt14Defeat
	.global MagmaHideout_2F_1R_Text_Grunt14PostBattle
	.global MagmaHideout_2F_1R_Text_Grunt3Intro
	.global MagmaHideout_2F_1R_Text_Grunt3Defeat
	.global MagmaHideout_2F_1R_Text_Grunt3PostBattle
	.global MagmaHideout_2F_1R_Text_Grunt4Intro
	.global MagmaHideout_2F_1R_Text_Grunt4Defeat
	.global MagmaHideout_2F_1R_Text_Grunt4PostBattle
	.global MagmaHideout_2F_1R_Text_Grunt5Intro
	.global MagmaHideout_2F_1R_Text_Grunt5Defeat
	.global MagmaHideout_2F_1R_Text_Grunt5PostBattle
@ END GENERATED LOCALIZATION EXPORTS
