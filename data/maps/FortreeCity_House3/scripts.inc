FortreeCity_House3_MapScripts::
	.byte 0

FortreeCity_House3_EventScript_Maniac::
	msgbox FortreeCity_House3_Text_MetStevenHadAmazingPokemon, MSGBOX_NPC
	end

FortreeCity_House3_EventScript_SchoolKidM::
	msgbox FortreeCity_House3_Text_OhYouHavePokedex, MSGBOX_NPC
	end

FortreeCity_House3_Text_MetStevenHadAmazingPokemon:
	.string "Nhắc đến POKéDEXES làm tôi nhớ ra một\n"
	.string "chuyện.\p"
	.string "Khi đang tìm những viên đá hiếm, tôi đã\n"
	.string "gặp một HLV tên là STEVEN.\p"
	.string "Chà, cậu ấy mang theo những POKéMON\n"
	.string "thật đáng kinh ngạc.\p"
	.string "Chúng không chỉ hiếm mà còn được rèn\n"
	.string "luyện đến mức đáng sợ!\p"
	.string "Có khi cậu ấy còn mạnh hơn cả GYM\n"
	.string "LEADER của thị trấn này...$"

FortreeCity_House3_Text_OhYouHavePokedex:
	.string "Bạn đang có thứ gì thế?\p"
	.string "... ... ... ... ... ...\p"
	.string "Ồ, nó được gọi là POKéDEX sao? Tuyệt\n"
	.string "thật đấy!$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global FortreeCity_House3_Text_MetStevenHadAmazingPokemon
	.global FortreeCity_House3_Text_OhYouHavePokedex
@ END GENERATED LOCALIZATION EXPORTS
