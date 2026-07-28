MagmaHideout_3F_1R_MapScripts::
	.byte 0

MagmaHideout_3F_1R_EventScript_Grunt9::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_9, MagmaHideout_3F_1R_Text_Grunt9Intro, MagmaHideout_3F_1R_Text_Grunt9Defeat
	msgbox MagmaHideout_3F_1R_Text_Grunt9PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_3F_1R_EventScript_Grunt16::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_16, MagmaHideout_3F_1R_Text_Grunt16Intro, MagmaHideout_3F_1R_Text_Grunt16Defeat
	msgbox MagmaHideout_3F_1R_Text_Grunt16PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_3F_1R_Text_Grunt9Intro:
	.string "Ta đã làm gì mà phải chịu phiên gác này\n"
	.string "chứ?\p"
	.string "Tai trái của ta nóng ran lên rồi!$"

MagmaHideout_3F_1R_Text_Grunt9Defeat:
	.string "Ta sắp kiệt sức vì nóng rồi...$"

MagmaHideout_3F_1R_Text_Grunt9PostBattle:
	.string "Ngươi có thấy kỳ lạ khi bọn ta trùm kín\n"
	.string "đầu trong ngọn núi lửa đầy dung nham\l"
	.string "này không?$"

MagmaHideout_3F_1R_Text_Grunt16Intro:
	.string "Bọn ta gia nhập để giúp thủ lĩnh thực\n"
	.string "hiện tầm nhìn vĩ đại của ông ấy.\p"
	.string "Dù ngươi thuộc TEAM AQUA hay chỉ là\n"
	.string "một đứa trẻ đi ngang qua, ta cũng chẳng\l"
	.string "quan tâm.\p"
	.string "Không ai cản đường bọn ta mà có thể\n"
	.string "yên thân!$"

MagmaHideout_3F_1R_Text_Grunt16Defeat:
	.string "Ôi không! Ngươi hoàn toàn không đáng\n"
	.string "tin!$"

MagmaHideout_3F_1R_Text_Grunt16PostBattle:
	.string "Nghe ta nói đây. TEAM MAGMA mới đúng!\p"
	.string "Đừng nghe TEAM AQUA. Đừng tin những\n"
	.string "lời dối trá của chúng!$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global MagmaHideout_3F_1R_Text_Grunt9Intro
	.global MagmaHideout_3F_1R_Text_Grunt9Defeat
	.global MagmaHideout_3F_1R_Text_Grunt9PostBattle
	.global MagmaHideout_3F_1R_Text_Grunt16Intro
	.global MagmaHideout_3F_1R_Text_Grunt16Defeat
	.global MagmaHideout_3F_1R_Text_Grunt16PostBattle
@ END GENERATED LOCALIZATION EXPORTS
