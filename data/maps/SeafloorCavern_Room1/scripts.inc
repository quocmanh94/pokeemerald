SeafloorCavern_Room1_MapScripts::
	.byte 0

SeafloorCavern_Room1_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_1, SeafloorCavern_Room1_Text_Grunt1Intro, SeafloorCavern_Room1_Text_Grunt1Defeat
	msgbox SeafloorCavern_Room1_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room1_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_2, SeafloorCavern_Room1_Text_Grunt2Intro, SeafloorCavern_Room1_Text_Grunt2Defeat
	msgbox SeafloorCavern_Room1_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room1_Text_Grunt1Intro:
	.string "Bọn ta không cần trẻ con lảng vảng ở\n"
	.string "đây! Mau về nhà đi!$"

SeafloorCavern_Room1_Text_Grunt1Defeat:
	.string "Ta muốn về nhà...$"

SeafloorCavern_Room1_Text_Grunt1PostBattle:
	.string "Ta muốn được thăng chức để có thể sai\n"
	.string "khiến đám lính...$"

SeafloorCavern_Room1_Text_Grunt2Intro:
	.string "Chiếc tàu ngầm đó... Bên trong bé tí. Ta\n"
	.string "đau nhức khắp người!$"

SeafloorCavern_Room1_Text_Grunt2Defeat:
	.string "Thua trận khiến ta đau quá!$"

SeafloorCavern_Room1_Text_Grunt2PostBattle:
	.string "Chiếc tàu ngầm bọn ta cuỗm được đi xóc\n"
	.string "kinh khủng. Bên trong lại còn chật ních!$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global SeafloorCavern_Room1_Text_Grunt1Intro
	.global SeafloorCavern_Room1_Text_Grunt1Defeat
	.global SeafloorCavern_Room1_Text_Grunt1PostBattle
	.global SeafloorCavern_Room1_Text_Grunt2Intro
	.global SeafloorCavern_Room1_Text_Grunt2Defeat
	.global SeafloorCavern_Room1_Text_Grunt2PostBattle
@ END GENERATED LOCALIZATION EXPORTS
