PacifidlogTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PacifidlogTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

PacifidlogTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_PACIFIDLOG_TOWN
	end

PacifidlogTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_PACIFIDLOG_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

PacifidlogTown_PokemonCenter_1F_EventScript_Girl::
	msgbox PacifidlogTown_PokemonCenter_1F_Text_WhatColorTrainerCard, MSGBOX_NPC
	end

PacifidlogTown_PokemonCenter_1F_EventScript_Woman::
	msgbox PacifidlogTown_PokemonCenter_1F_Text_OnColonyOfCorsola, MSGBOX_NPC
	end

PacifidlogTown_PokemonCenter_1F_EventScript_OldMan::
	msgbox PacifidlogTown_PokemonCenter_1F_Text_AncestorsLivedOnBoats, MSGBOX_NPC
	end

PacifidlogTown_PokemonCenter_1F_Text_WhatColorTrainerCard:
	.string "TRAINER CARD của cậu màu gì? Của tôi\n"
	.string "màu đồng!$"

PacifidlogTown_PokemonCenter_1F_Text_OnColonyOfCorsola:
	.string "PACIFIDLOG TOWN nổi trên một quần thể\n"
	.string "CORSOLA.\p"
	.string "Nếu tôi nói vậy, cậu có tin không?$"

PacifidlogTown_PokemonCenter_1F_Text_AncestorsLivedOnBoats:
	.string "Tương truyền tổ tiên của người dân\n"
	.string "PACIFIDLOG được sinh ra trên thuyền,\l"
	.string "sống rồi qua đời ngay trên thuyền.\p"
	.string "Theo tôi biết, họ sống như vậy vì đang\n"
	.string "tìm kiếm một thứ gì đó.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global PacifidlogTown_PokemonCenter_1F_Text_WhatColorTrainerCard
	.global PacifidlogTown_PokemonCenter_1F_Text_OnColonyOfCorsola
	.global PacifidlogTown_PokemonCenter_1F_Text_AncestorsLivedOnBoats
@ END GENERATED LOCALIZATION EXPORTS
