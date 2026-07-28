RustboroCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

RustboroCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_RUSTBORO_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

RustboroCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_RUSTBORO_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

RustboroCity_PokemonCenter_1F_EventScript_Man::
	msgbox RustboroCity_PokemonCenter_1F_Text_PokemonHavePersonalities, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_EventScript_Boy::
	msgbox RustboroCity_PokemonCenter_1F_Text_MaleAndFemalePokemon, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_EventScript_Girl::
	msgbox RustboroCity_PokemonCenter_1F_Text_HMCutNextDoor, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_Text_PokemonHavePersonalities:
	.string "POKéMON của tôi có tính cách NAIVE, còn\n"
	.string "của bạn tôi có tính cách JOLLY.\p"
	.string "Thật thú vị khi POKéMON cũng có cá tính\n"
	.string "riêng!$"

RustboroCity_PokemonCenter_1F_Text_MaleAndFemalePokemon:
	.string "Cũng giống con người, POKéMON có cả\n"
	.string "giống đực lẫn giống cái.\p"
	.string "Nhưng dường như chẳng ai biết chúng\n"
	.string "khác nhau ở điểm nào.$"

RustboroCity_PokemonCenter_1F_Text_HMCutNextDoor:
	.string "Người đàn ông nhà bên đã cho tôi một\n"
	.string "HM!\p"
	.string "Tôi dùng nó để dạy POKéMON cách dùng\n"
	.string "CUT chặt những cây nhỏ.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global RustboroCity_PokemonCenter_1F_Text_PokemonHavePersonalities
	.global RustboroCity_PokemonCenter_1F_Text_MaleAndFemalePokemon
	.global RustboroCity_PokemonCenter_1F_Text_HMCutNextDoor
@ END GENERATED LOCALIZATION EXPORTS
