PetalburgCity_House2_MapScripts::
	.byte 0

PetalburgCity_House2_EventScript_Woman::
	msgbox PetalburgCity_House2_Text_NormanBecameGymLeader, MSGBOX_NPC
	end

PetalburgCity_House2_EventScript_SchoolKid::
	msgbox PetalburgCity_House2_Text_BattledNormanOnce, MSGBOX_NPC
	end

PetalburgCity_House2_Text_NormanBecameGymLeader:
	.string "NORMAN đã trở thành GYM LEADER mới\n"
	.string "của thị trấn chúng ta.\p"
	.string "Tôi nghĩ anh ấy đã gọi gia đình từ một\n"
	.string "nơi xa xôi đến đây.$"

PetalburgCity_House2_Text_BattledNormanOnce:
	.string "Tôi từng đấu với NORMAN một lần, nhưng\n"
	.string "chà, anh ấy mạnh quá sức.\p"
	.string "Phải nói thế nào nhỉ?\p"
	.string "Tôi chỉ có cảm giác anh ấy sống vì\n"
	.string "POKéMON.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global PetalburgCity_House2_Text_NormanBecameGymLeader
	.global PetalburgCity_House2_Text_BattledNormanOnce
@ END GENERATED LOCALIZATION EXPORTS
