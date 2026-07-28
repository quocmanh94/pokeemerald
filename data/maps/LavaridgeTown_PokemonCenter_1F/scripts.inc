LavaridgeTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

LavaridgeTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_LAVARIDGE_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

LavaridgeTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_LAVARIDGE_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

LavaridgeTown_PokemonCenter_1F_EventScript_Youngster::
	msgbox LavaridgeTown_PokemonCenter_1F_Text_HotSpringCanInvigorate, MSGBOX_NPC
	end

LavaridgeTown_PokemonCenter_1F_EventScript_Woman::
	msgbox LavaridgeTown_PokemonCenter_1F_Text_TrainersPokemonSpendTimeTogether, MSGBOX_NPC
	end

LavaridgeTown_PokemonCenter_1F_EventScript_Gentleman::
	msgbox LavaridgeTown_PokemonCenter_1F_Text_TrainersShouldRestToo, MSGBOX_NPC
	end

LavaridgeTown_PokemonCenter_1F_Text_TrainersPokemonSpendTimeTogether:
	.string "Tôi nghĩ POKéMON sẽ trở nên thân thiết\n"
	.string "hơn với HLV nếu họ dành thời gian\l"
	.string "bên nhau.\p"
	.string "Càng lâu càng tốt. Tôi nghĩ vậy đấy.$"

LavaridgeTown_PokemonCenter_1F_Text_HotSpringCanInvigorate:
	.string "Chỉ cần ngâm mình trong suối nước nóng\n"
	.string "mà đã thấy khỏe khoắn hẳn lên, thật kỳ\l"
	.string "diệu.\p"
	.string "Ước gì tôi cũng có thể cho POKéMON của\n"
	.string "mình xuống ngâm.$"

LavaridgeTown_PokemonCenter_1F_Text_TrainersShouldRestToo:
	.string "Hô hô hô! Này nhóc, từ đây có thể đi đến\n"
	.string "suối nước nóng đấy.\p"
	.string "Nếu POKéMON cần nghỉ ngơi thì\n"
	.string "HLV của chúng cũng vậy.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global LavaridgeTown_PokemonCenter_1F_Text_TrainersPokemonSpendTimeTogether
	.global LavaridgeTown_PokemonCenter_1F_Text_HotSpringCanInvigorate
	.global LavaridgeTown_PokemonCenter_1F_Text_TrainersShouldRestToo
@ END GENERATED LOCALIZATION EXPORTS
