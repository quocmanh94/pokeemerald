SootopolisCity_House5_MapScripts::
	.byte 0

SootopolisCity_House5_EventScript_Maniac::
	msgbox SootopolisCity_House5_Text_SootopolisMtPyreConnection, MSGBOX_NPC
	end

SootopolisCity_House5_EventScript_Girl::
	msgbox SootopolisCity_House5_Text_BrotherUsedToStudySea, MSGBOX_NPC
	end

SootopolisCity_House5_Text_SootopolisMtPyreConnection:
	.string "Dường như SOOTOPOLIS và MT. PYRE có\n"
	.string "mối liên hệ nào đó.\p"
	.string "Tôi và các bạn từng nghiên cứu chuyện\n"
	.string "này tại phòng thí nghiệm nơi tôi làm\l"
	.string "việc trước đây.$"

SootopolisCity_House5_Text_BrotherUsedToStudySea:
	.string "Anh trai tôi từng nghiên cứu về biển.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global SootopolisCity_House5_Text_SootopolisMtPyreConnection
	.global SootopolisCity_House5_Text_BrotherUsedToStudySea
@ END GENERATED LOCALIZATION EXPORTS
