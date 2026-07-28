AbandonedShip_Corridors_1F_MapScripts::
	.byte 0

AbandonedShip_Corridors_1F_EventScript_Youngster::
	msgbox AbandonedShip_Corridors_1F_Text_IsntItFunHere, MSGBOX_NPC
	end

AbandonedShip_Corridors_1F_EventScript_Charlie::
	trainerbattle_single TRAINER_CHARLIE, AbandonedShip_Corridors_1F_Text_CharlieIntro, AbandonedShip_Corridors_1F_Text_CharlieDefeat
	msgbox AbandonedShip_Corridors_1F_Text_CharliePostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Corridors_1F_Text_CharlieIntro:
	.string "Có gì buồn cười khi tôi mang phao bơi\n"
	.string "lên tàu chứ?$"

AbandonedShip_Corridors_1F_Text_CharlieDefeat:
	.string "Ôi, bạn áp đảo tôi hoàn toàn rồi!$"

AbandonedShip_Corridors_1F_Text_CharliePostBattle:
	.string "Vừa bám vào phao bơi vừa ném POKé\n"
	.string "BALLS đâu có dễ!$"

AbandonedShip_Corridors_1F_Text_IsntItFunHere:
	.string "Ở đây vui quá phải không? Chỉ cần có\n"
	.string "mặt ở đây là tôi đã thấy phấn khích rồi!$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global AbandonedShip_Corridors_1F_Text_CharlieIntro
	.global AbandonedShip_Corridors_1F_Text_CharlieDefeat
	.global AbandonedShip_Corridors_1F_Text_CharliePostBattle
	.global AbandonedShip_Corridors_1F_Text_IsntItFunHere
@ END GENERATED LOCALIZATION EXPORTS
