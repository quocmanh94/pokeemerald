VerdanturfTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VerdanturfTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

VerdanturfTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_VERDANTURF_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

VerdanturfTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_VERDANTURF_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

VerdanturfTown_PokemonCenter_1F_EventScript_Gentleman::
	msgbox VerdanturfTown_PokemonCenter_1F_Text_FaithInYourPokemon, MSGBOX_NPC
	end

VerdanturfTown_PokemonCenter_1F_EventScript_ExpertM::
	msgbox VerdanturfTown_PokemonCenter_1F_Text_VisitForBattleTent, MSGBOX_NPC
	end

VerdanturfTown_PokemonCenter_1F_Text_FaithInYourPokemon:
	.string "Bạn không thể tự xem mình là một\n"
	.string "HLV thực thụ nếu không tin tưởng\l"
	.string "POKéMON.\p"
	.string "Chỉ những người tin vào POKéMON đang\n"
	.string "chiến đấu của mình mới có thể giành\l"
	.string "chiến thắng đến tận cùng.$"

VerdanturfTown_PokemonCenter_1F_Text_VisitForBattleTent:
	.string "Lý do người ta đến VERDANTURF...\p"
	.string "Dĩ nhiên là vì BATTLE TENT rồi.\p"
	.string "Hay bạn đến đây để gặp ai đó?$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global VerdanturfTown_PokemonCenter_1F_Text_FaithInYourPokemon
	.global VerdanturfTown_PokemonCenter_1F_Text_VisitForBattleTent
@ END GENERATED LOCALIZATION EXPORTS
