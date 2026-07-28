MagmaHideout_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MagmaHideout_1F_OnTransition
	.byte 0

MagmaHideout_1F_OnTransition:
	setvar VAR_JAGGED_PASS_ASH_WEATHER, 0
	end

MagmaHideout_1F_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_1, MagmaHideout_1F_Text_Grunt1Intro, MagmaHideout_1F_Text_Grunt1Defeat
	msgbox MagmaHideout_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_1F_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_2, MagmaHideout_1F_Text_Grunt2Intro, MagmaHideout_1F_Text_Grunt2Defeat
	msgbox MagmaHideout_1F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_1F_Text_Grunt1Intro:
	.string "Mỗi khi TEAM MAGMA điểm danh, nhiệm vụ\n"
	.string "canh gác quan trọng được giao theo\l"
	.string "thứ tự bọn ta xếp hàng.\p"
	.string "Vì thế ta mới bị mắc kẹt ở góc này. Lúc\n"
	.string "nào ta cũng đến điểm danh muộn!$"

MagmaHideout_1F_Text_Grunt1Defeat:
	.string "Ta cũng luôn đến các buổi huấn luyện\n"
	.string "muộn!\p"
	.string "Không muốn thừa nhận đâu, nhưng ta\n"
	.string "yếu xìu...$"

MagmaHideout_1F_Text_Grunt1PostBattle:
	.string "Được rồi, từ giờ ta sẽ cố gắng hơn một\n"
	.string "chút...$"

MagmaHideout_1F_Text_Grunt2Intro:
	.string "Thủ lĩnh bảo bọn ta đào sâu vào MT.\n"
	.string "CHIMNEY, thế là bọn ta đào mãi, đào mãi.\p"
	.string "Trong lúc đào, bọn ta tình cờ phát hiện\n"
	.string "một thứ khiến ai nấy kinh ngạc!\p"
	.string "Bọn ta tìm thấy gì ư?\p"
	.string "Fuhahaha! Đánh thắng ta rồi ta sẽ nói!$"

MagmaHideout_1F_Text_Grunt2Defeat:
	.string "Aaargh! Bị hạ rồi!$"

MagmaHideout_1F_Text_Grunt2PostBattle:
	.string "Ta đổi ý, không nói đâu. Đến nơi rồi\n"
	.string "ngươi sẽ tự biết!\p"
	.string "Bất ngờ nên để dành đến cuối mới hay,\n"
	.string "đúng không?$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global MagmaHideout_1F_Text_Grunt1Intro
	.global MagmaHideout_1F_Text_Grunt1Defeat
	.global MagmaHideout_1F_Text_Grunt1PostBattle
	.global MagmaHideout_1F_Text_Grunt2Intro
	.global MagmaHideout_1F_Text_Grunt2Defeat
	.global MagmaHideout_1F_Text_Grunt2PostBattle
@ END GENERATED LOCALIZATION EXPORTS
