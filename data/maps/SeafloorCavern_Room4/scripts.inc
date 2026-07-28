SeafloorCavern_Room4_MapScripts::
	.byte 0

SeafloorCavern_Room4_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_3, SeafloorCavern_Room4_Text_Grunt3Intro, SeafloorCavern_Room4_Text_Grunt3Defeat
	msgbox SeafloorCavern_Room4_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room4_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_4, SeafloorCavern_Room4_Text_Grunt4Intro, SeafloorCavern_Room4_Text_Grunt4Defeat
	msgbox SeafloorCavern_Room4_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room4_Text_Grunt3Intro:
	.string "Ngươi là ai? Ngươi chui vào từ đâu?$"

SeafloorCavern_Room4_Text_Grunt3Defeat:
	.string "Thua mất rồi...$"

SeafloorCavern_Room4_Text_Grunt3PostBattle:
	.string "Ta không tìm thấy đường ra!\p"
	.string "Ta không sợ đâu. Đừng có hiểu lầm!$"

SeafloorCavern_Room4_Text_Grunt4Intro:
	.string "Ngươi là ai? Ngươi tưởng mình đang đi\n"
	.string "đâu vậy?$"

SeafloorCavern_Room4_Text_Grunt4Defeat:
	.string "Ta đã không thắng được!$"

SeafloorCavern_Room4_Text_Grunt4PostBattle:
	.string "Tên đồng đội của ta để quên bản đồ trên\n"
	.string "tàu ngầm rồi!\p"
	.string "Đúng là vô dụng hết chỗ nói!$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global SeafloorCavern_Room4_Text_Grunt3Intro
	.global SeafloorCavern_Room4_Text_Grunt3Defeat
	.global SeafloorCavern_Room4_Text_Grunt3PostBattle
	.global SeafloorCavern_Room4_Text_Grunt4Intro
	.global SeafloorCavern_Room4_Text_Grunt4Defeat
	.global SeafloorCavern_Room4_Text_Grunt4PostBattle
@ END GENERATED LOCALIZATION EXPORTS
