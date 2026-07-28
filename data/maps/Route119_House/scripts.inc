Route119_House_MapScripts::
	.byte 0

Route119_House_EventScript_Woman::
	msgbox Route119_House_Text_RumorAboutCaveOfOrigin, MSGBOX_NPC
	end

Route119_House_EventScript_Wingull::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
	msgbox Route119_House_Text_Wingull, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route119_House_Text_RumorAboutCaveOfOrigin:
	.string "Tôi nghe nói có một hang động tên là\n"
	.string "CAVE OF ORIGIN.\p"
	.string "Người ta đồn rằng linh hồn của POKéMON\n"
	.string "được hồi sinh ở đó. Chuyện như vậy\l"
	.string "thật sự có thể xảy ra sao?$"

Route119_House_Text_Wingull:
	.string "WINGULL: Pi-hyô!$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global Route119_House_Text_RumorAboutCaveOfOrigin
	.global Route119_House_Text_Wingull
@ END GENERATED LOCALIZATION EXPORTS
