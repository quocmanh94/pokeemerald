FortreeCity_House5_MapScripts::
	.byte 0

FortreeCity_House5_EventScript_PokefanF::
	msgbox FortreeCity_House5_Text_TreeHousesAreGreat, MSGBOX_NPC
	end

FortreeCity_House5_EventScript_Man::
	msgbox FortreeCity_House5_Text_AdaptedToNature, MSGBOX_NPC
	end

FortreeCity_House5_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox FortreeCity_House5_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FortreeCity_House5_Text_TreeHousesAreGreat:
	.string "Những ngôi nhà trên cây ở FORTREE thật\n"
	.string "tuyệt!\p"
	.string "Tôi nghĩ đây là thị trấn số một để sống\n"
	.string "cùng POKéMON.$"

FortreeCity_House5_Text_AdaptedToNature:
	.string "POKéMON và con người đã thích nghi với\n"
	.string "thiên nhiên để sinh tồn.\p"
	.string "Không cần phải uốn thiên nhiên theo\n"
	.string "cách sống mà chúng ta mong muốn.$"

FortreeCity_House5_Text_Zigzagoon:
	.string "ZIGZAGOON: Bufuu!$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global FortreeCity_House5_Text_TreeHousesAreGreat
	.global FortreeCity_House5_Text_AdaptedToNature
@ END GENERATED LOCALIZATION EXPORTS
