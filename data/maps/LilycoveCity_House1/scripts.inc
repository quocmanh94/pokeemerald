LilycoveCity_House1_MapScripts::
	.byte 0

LilycoveCity_House1_EventScript_ExpertM::
	msgbox LilycoveCity_House1_Text_PokemonPartnersNotTools, MSGBOX_NPC
	end

LilycoveCity_House1_EventScript_Kecleon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_KECLEON, CRY_MODE_NORMAL
	msgbox LilycoveCity_House1_Text_Kecleon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

LilycoveCity_House1_Text_PokemonPartnersNotTools:
	.string "POKéMON là bạn đồng hành của con\n"
	.string "người. Chúng không phải công cụ của\l"
	.string "chúng ta.\p"
	.string "Đáng tiếc là vẫn có những người không\n"
	.string "hiểu điều đó...$"

LilycoveCity_House1_Text_Kecleon:
	.string "KECLEON: Ruroro?$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global LilycoveCity_House1_Text_PokemonPartnersNotTools
@ END GENERATED LOCALIZATION EXPORTS
