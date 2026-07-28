MossdeepCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

MossdeepCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_MOSSDEEP_CITY
	end

MossdeepCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_MOSSDEEP_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

MossdeepCity_PokemonCenter_1F_EventScript_Woman::
	msgbox MossdeepCity_PokemonCenter_1F_Text_GymLeaderDuoFormidable, MSGBOX_NPC
	end

MossdeepCity_PokemonCenter_1F_EventScript_Girl::
	msgbox MossdeepCity_PokemonCenter_1F_Text_AbilitiesMightChangeMoves, MSGBOX_NPC
	end

MossdeepCity_PokemonCenter_1F_Text_GymLeaderDuoFormidable:
	.string "Hai GYM LEADERS của thị trấn này là một\n"
	.string "cặp cực kỳ đáng gờm.\p"
	.string "Các đòn phối hợp của họ phải nói là\n"
	.string "tuyệt vời, đỉnh thật sự!$"

MossdeepCity_PokemonCenter_1F_Text_AbilitiesMightChangeMoves:
	.string "Tùy vào năng lực đặc biệt của POKéMON,\n"
	.string "một số chiêu thức có thể thay đổi hoặc\l"
	.string "hoàn toàn không có tác dụng.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global MossdeepCity_PokemonCenter_1F_Text_GymLeaderDuoFormidable
	.global MossdeepCity_PokemonCenter_1F_Text_AbilitiesMightChangeMoves
@ END GENERATED LOCALIZATION EXPORTS
