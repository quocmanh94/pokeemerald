PacifidlogTown_House1_MapScripts::
	.byte 0

PacifidlogTown_House1_EventScript_Man::
	msgbox PacifidlogTown_House1_Text_RegiStory, MSGBOX_NPC
	end

PacifidlogTown_House1_EventScript_Woman::
	msgbox PacifidlogTown_House1_Text_SixDotsOpenThreeDoors, MSGBOX_NPC
	end

PacifidlogTown_House1_Text_RegiStory:
	.string "Ở vùng HOENN có ba POKéMON đại diện\n"
	.string "cho sức mạnh của đá, băng và thép.\p"
	.string "Tương truyền mỗi con đều ẩn mình sâu\n"
	.string "trong các hang động.\p"
	.string "Đó là câu chuyện tôi được nghe khi còn\n"
	.string "bé.$"

PacifidlogTown_House1_Text_SixDotsOpenThreeDoors:
	.string "“Sáu dấu chấm mở ba cánh cửa.”\p"
	.string "Ông tôi thường nói vậy, nhưng tôi\n"
	.string "không hiểu ông muốn nói gì.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global PacifidlogTown_House1_Text_RegiStory
	.global PacifidlogTown_House1_Text_SixDotsOpenThreeDoors
@ END GENERATED LOCALIZATION EXPORTS
