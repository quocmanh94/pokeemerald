MagmaHideout_2F_2R_MapScripts::
	.byte 0

MagmaHideout_2F_2R_EventScript_Grunt15::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_15, MagmaHideout_2F_2R_Text_Grunt15Intro, MagmaHideout_2F_2R_Text_Grunt15Defeat
	msgbox MagmaHideout_2F_2R_Text_Grunt15PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_2R_EventScript_Grunt6::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_6, MagmaHideout_2F_2R_Text_Grunt6Intro, MagmaHideout_2F_2R_Text_Grunt6Defeat
	msgbox MagmaHideout_2F_2R_Text_Grunt6PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_2R_EventScript_Grunt7::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_7, MagmaHideout_2F_2R_Text_Grunt7Intro, MagmaHideout_2F_2R_Text_Grunt7Defeat
	msgbox MagmaHideout_2F_2R_Text_Grunt7PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_2R_EventScript_Grunt8::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_8, MagmaHideout_2F_2R_Text_Grunt8Intro, MagmaHideout_2F_2R_Text_Grunt8Defeat
	msgbox MagmaHideout_2F_2R_Text_Grunt8PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_2R_Text_Grunt15Intro:
	.string "Ta chẳng có thù oán gì với ngươi. Ta\n"
	.string "chỉ làm theo lệnh thôi!$"

MagmaHideout_2F_2R_Text_Grunt15Defeat:
	.string "Có thể ta đã thua, nhưng...$"

MagmaHideout_2F_2R_Text_Grunt15PostBattle:
	.string "Bọn ta đã đào được một thứ không thể\n"
	.string "tin nổi! Lại còn lấy được BLUE ORB!\p"
	.string "Giờ chỉ còn chờ thủ lĩnh của bọn ta...\n"
	.string "Fufufu... Fwahahaha!$"

MagmaHideout_2F_2R_Text_Grunt6Intro:
	.string "Tôi không chịu nổi nóng. Có lẽ lẽ ra tôi\n"
	.string "nên gia nhập TEAM AQUA...$"

MagmaHideout_2F_2R_Text_Grunt6Defeat:
	.string "Ừ, có lẽ tôi thật sự không hợp với TEAM\n"
	.string "MAGMA...$"

MagmaHideout_2F_2R_Text_Grunt6PostBattle:
	.string "Ở một nơi thế này, ngươi không thấy\n"
	.string "nhớ biển sao?$"

MagmaHideout_2F_2R_Text_Grunt7Intro:
	.string "Thỉnh thoảng ở đây có thể nghe thấy\n"
	.string "rung chấn.\p"
	.string "Núi lửa đang rung chuyển chăng? Hay là\n"
	.string "GROU...\p"
	.string "Úi! Không, không, đừng bận tâm!$"

MagmaHideout_2F_2R_Text_Grunt7Defeat:
	.string "Ngươi chiến đấu bốc lửa thật. Hệt như\n"
	.string "núi lửa!$"

MagmaHideout_2F_2R_Text_Grunt7PostBattle:
	.string "Lần này ngươi chỉ tình cờ thắng thôi,\n"
	.string "nhưng không quan trọng.\p"
	.string "Mục tiêu của TEAM MAGMA sắp thành hiện\n"
	.string "thực rồi!$"

MagmaHideout_2F_2R_Text_Grunt8Intro:
	.string "Một người trong bọn ta đang cuống lên\n"
	.string "vì làm mất MAGMA EMBLEM...\p"
	.string "Khoan đã! Chính ngươi đã tìm thấy nó\n"
	.string "sao?$"

MagmaHideout_2F_2R_Text_Grunt8Defeat:
	.string "Ta khó mà tin nổi chuyện này...$"

MagmaHideout_2F_2R_Text_Grunt8PostBattle:
	.string "Ta có linh cảm kế hoạch của bọn ta sẽ\n"
	.string "thất bại...$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global MagmaHideout_2F_2R_Text_Grunt15Intro
	.global MagmaHideout_2F_2R_Text_Grunt15Defeat
	.global MagmaHideout_2F_2R_Text_Grunt15PostBattle
	.global MagmaHideout_2F_2R_Text_Grunt6Intro
	.global MagmaHideout_2F_2R_Text_Grunt6Defeat
	.global MagmaHideout_2F_2R_Text_Grunt6PostBattle
	.global MagmaHideout_2F_2R_Text_Grunt7Intro
	.global MagmaHideout_2F_2R_Text_Grunt7Defeat
	.global MagmaHideout_2F_2R_Text_Grunt7PostBattle
	.global MagmaHideout_2F_2R_Text_Grunt8Intro
	.global MagmaHideout_2F_2R_Text_Grunt8Defeat
	.global MagmaHideout_2F_2R_Text_Grunt8PostBattle
@ END GENERATED LOCALIZATION EXPORTS
