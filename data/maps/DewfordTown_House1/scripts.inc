DewfordTown_House1_MapScripts::
	.byte 0

DewfordTown_House1_EventScript_Man::
	msgbox DewfordTown_House1_Text_LotToBeSaidForLivingOnIsland, MSGBOX_NPC
	end

DewfordTown_House1_EventScript_Woman::
	msgbox DewfordTown_House1_Text_LifeGoesSlowlyOnIsland, MSGBOX_NPC
	end

DewfordTown_House1_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox DewfordTown_House1_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

DewfordTown_House1_Text_LotToBeSaidForLivingOnIsland:
	.string "Cuộc sống hòa thuận bên gia đình và\n"
	.string "POKéMON trên một hòn đảo nhỏ thế này\l"
	.string "có rất nhiều điều đáng quý.$"

DewfordTown_House1_Text_LifeGoesSlowlyOnIsland:
	.string "Tôi rời cảng lớn SLATEPORT CITY khi kết\n"
	.string "hôn và theo chồng đến đây.\p"
	.string "Cuộc sống trôi qua chậm rãi trên hòn\n"
	.string "đảo nhỏ này. Nhưng được bao quanh bởi\l"
	.string "biển xanh tuyệt đẹp cũng là một niềm\l"
	.string "hạnh phúc.$"

DewfordTown_House1_Text_Zigzagoon:
	.string "ZIGZAGOON: Guguuh!$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global DewfordTown_House1_Text_LotToBeSaidForLivingOnIsland
	.global DewfordTown_House1_Text_LifeGoesSlowlyOnIsland
@ END GENERATED LOCALIZATION EXPORTS
