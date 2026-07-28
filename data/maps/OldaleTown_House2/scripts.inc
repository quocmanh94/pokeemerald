OldaleTown_House2_MapScripts::
	.byte 0

OldaleTown_House2_EventScript_Woman::
	msgbox OldaleTown_House2_Text_PokemonLevelUp, MSGBOX_NPC
	end

OldaleTown_House2_EventScript_Man::
	msgbox OldaleTown_House2_Text_YoullGoFurtherWithStrongPokemon, MSGBOX_NPC
	end

OldaleTown_House2_Text_PokemonLevelUp:
	.string "Khi chiến đấu, POKéMON sẽ dần lên cấp và\n"
	.string "trở nên mạnh hơn.$"

OldaleTown_House2_Text_YoullGoFurtherWithStrongPokemon:
	.string "Nếu những POKéMON đi cùng cậu trở nên\n"
	.string "mạnh hơn, cậu sẽ có thể đi xa hơn khỏi\l"
	.string "nơi này.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global OldaleTown_House2_Text_PokemonLevelUp
	.global OldaleTown_House2_Text_YoullGoFurtherWithStrongPokemon
@ END GENERATED LOCALIZATION EXPORTS
