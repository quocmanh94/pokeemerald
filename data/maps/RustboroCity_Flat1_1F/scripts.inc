RustboroCity_Flat1_1F_MapScripts::
	.byte 0

RustboroCity_Flat1_1F_EventScript_Man::
	msgbox RustboroCity_Flat1_1F_Text_EveryPokemonHasAbility, MSGBOX_NPC
	end

RustboroCity_Flat1_1F_EventScript_Woman::
	msgbox RustboroCity_Flat1_1F_Text_PokemonStrange, MSGBOX_NPC
	end

RustboroCity_Flat1_1F_Text_EveryPokemonHasAbility:
	.string "Mỗi POKéMON đều có một năng lực đặc\n"
	.string "biệt mà chúng có thể sử dụng.$"

RustboroCity_Flat1_1F_Text_PokemonStrange:
	.string "POKéMON đúng là những sinh vật kỳ lạ.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global RustboroCity_Flat1_1F_Text_EveryPokemonHasAbility
	.global RustboroCity_Flat1_1F_Text_PokemonStrange
@ END GENERATED LOCALIZATION EXPORTS
