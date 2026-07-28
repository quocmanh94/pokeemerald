DewfordTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DewfordTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

DewfordTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_DEWFORD_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

DewfordTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_DEWFORD_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

DewfordTown_PokemonCenter_1F_EventScript_PokefanF::
	msgbox DewfordTown_PokemonCenter_1F_Text_StoneCavern, MSGBOX_NPC
	end

DewfordTown_PokemonCenter_1F_EventScript_Man::
	msgbox DewfordTown_PokemonCenter_1F_Text_FaintedMonCanUseHM, MSGBOX_NPC
	end

DewfordTown_PokemonCenter_1F_Text_StoneCavern:
	.string "Có một hang đá ở rìa thị trấn.\p"
	.string "Tôi nghe nói có thể tìm thấy những viên\n"
	.string "đá quý hiếm ở đó.$"

DewfordTown_PokemonCenter_1F_Text_FaintedMonCanUseHM:
	.string "Ngay cả khi POKéMON bị ngất và không\n"
	.string "thể chiến đấu, nó vẫn có thể dùng chiêu\l"
	.string "học từ HIDDEN MACHINE (HM).$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global DewfordTown_PokemonCenter_1F_Text_StoneCavern
	.global DewfordTown_PokemonCenter_1F_Text_FaintedMonCanUseHM
@ END GENERATED LOCALIZATION EXPORTS
