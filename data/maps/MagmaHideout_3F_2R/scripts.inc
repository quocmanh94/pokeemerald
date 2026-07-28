MagmaHideout_3F_2R_MapScripts::
	.byte 0

MagmaHideout_3F_2R_EventScript_Grunt10::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_10, MagmaHideout_3F_2R_Text_Grunt10Intro, MagmaHideout_3F_2R_Text_Grunt10Defeat
	msgbox MagmaHideout_3F_2R_Text_Grunt10PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_3F_2R_Text_Grunt10Intro:
	.string "Tôi hiểu mọi điều thủ lĩnh nói. Nhưng mà\n"
	.string "này...\p"
	.string "Những chuyện như đào một POKéMON siêu\n"
	.string "cổ đại lên rồi cướp METEORITE của\l"
	.string "người khác...\p"
	.string "Tôi nghĩ bọn tôi đang đi hơi quá xa. Cậu\n"
	.string "thấy sao?$"

MagmaHideout_3F_2R_Text_Grunt10Defeat:
	.string "Ừ, tôi nghĩ bằng cách nào đó bọn tôi\n"
	.string "đang làm điều sai trái.$"

MagmaHideout_3F_2R_Text_Grunt10PostBattle:
	.string "Cậu biết không, thua cậu khiến đầu óc\n"
	.string "tôi sáng ra.\p"
	.string "Lần tới gặp thủ lĩnh, tôi sẽ hỏi ông ấy\n"
	.string "về những việc bọn tôi đang làm.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global MagmaHideout_3F_2R_Text_Grunt10Intro
	.global MagmaHideout_3F_2R_Text_Grunt10Defeat
	.global MagmaHideout_3F_2R_Text_Grunt10PostBattle
@ END GENERATED LOCALIZATION EXPORTS
