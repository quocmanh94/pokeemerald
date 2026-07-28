RustboroCity_House2_MapScripts::
	.byte 0

RustboroCity_House2_EventScript_PokefanF::
	msgbox RustboroCity_House2_Text_TrainerSchoolExcellent, MSGBOX_NPC
	end

RustboroCity_House2_EventScript_LittleGirl::
	msgbox RustboroCity_House2_Text_RoxanneKnowsALot, MSGBOX_NPC
	end

RustboroCity_House2_Text_TrainerSchoolExcellent:
	.string "TRAINER'S SCHOOL là một ngôi trường\n"
	.string "xuất sắc.\p"
	.string "Nếu học ở đó, bạn thậm chí có thể trở\n"
	.string "thành GYM LEADER.$"

RustboroCity_House2_Text_RoxanneKnowsALot:
	.string "GYM LEADER ROXANNE thật sự biết rất\n"
	.string "nhiều về POKéMON.\p"
	.string "Cô ấy cũng rất mạnh!$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global RustboroCity_House2_Text_TrainerSchoolExcellent
	.global RustboroCity_House2_Text_RoxanneKnowsALot
@ END GENERATED LOCALIZATION EXPORTS
