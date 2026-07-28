SootopolisCity_House7_MapScripts::
	.byte 0

SootopolisCity_House7_EventScript_OldMan::
	msgbox SootopolisCity_House7_Text_CityFromEruptedVolcano, MSGBOX_NPC
	end

SootopolisCity_House7_EventScript_PokefanF::
	msgbox SootopolisCity_House7_Text_CaveMadeToKeepSomething, MSGBOX_NPC
	end

SootopolisCity_House7_Text_CityFromEruptedVolcano:
	.string "Một ngọn núi lửa dưới biển phun trào và\n"
	.string "trồi lên từ nơi sâu thẳm.\p"
	.string "Miệng núi lửa nhô khỏi mặt biển rồi đầy\n"
	.string "ắp nước mưa.\p"
	.string "SOOTOPOLIS CITY đã ra đời như thế.$"

SootopolisCity_House7_Text_CaveMadeToKeepSomething:
	.string "Hang động nối SOOTOPOLIS với thế giới\n"
	.string "bên ngoài...\p"
	.string "Dường như hang động ấy được tạo ra\n"
	.string "để ngăn một thứ gì đó thoát ra ngoài.\p"
	.string "Hay chỉ là tôi tưởng tượng quá nhiều?$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global SootopolisCity_House7_Text_CityFromEruptedVolcano
	.global SootopolisCity_House7_Text_CaveMadeToKeepSomething
@ END GENERATED LOCALIZATION EXPORTS
