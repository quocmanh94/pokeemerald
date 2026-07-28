PetalburgCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PetalburgCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

PetalburgCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_PETALBURG_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

PetalburgCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_PETALBURG_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_FatMan::
	msgbox PetalburgCity_PokemonCenter_1F_Text_PCStorageSystem, MSGBOX_NPC
	end

PetalburgCity_PokemonCenter_1F_EventScript_Youngster::
	msgbox PetalburgCity_PokemonCenter_1F_Text_OranBerryRegainedHP, MSGBOX_NPC
	end

PetalburgCity_PokemonCenter_1F_EventScript_Woman::
	lock
	faceplayer
	msgbox PetalburgCity_PokemonCenter_1F_Text_ManyTypesOfPokemon, MSGBOX_DEFAULT
	specialvar VAR_RESULT, IsStarterInParty
	goto_if_eq VAR_RESULT, TRUE, PetalburgCity_PokemonCenter_1F_EventScript_SayStarterTypeInfo
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_SayStarterTypeInfo::
	call_if_eq VAR_STARTER_MON, 0, PetalburgCity_PokemonCenter_1F_EventScript_SayTreeckoType
	call_if_eq VAR_STARTER_MON, 1, PetalburgCity_PokemonCenter_1F_EventScript_SayTorchicType
	call_if_eq VAR_STARTER_MON, 2, PetalburgCity_PokemonCenter_1F_EventScript_SayMudkipType
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_SayTreeckoType::
	msgbox PetalburgCity_PokemonCenter_1F_Text_TreeckoIsGrassType, MSGBOX_DEFAULT
	return

PetalburgCity_PokemonCenter_1F_EventScript_SayTorchicType::
	msgbox PetalburgCity_PokemonCenter_1F_Text_TorchicIsFireType, MSGBOX_DEFAULT
	return

PetalburgCity_PokemonCenter_1F_EventScript_SayMudkipType::
	msgbox PetalburgCity_PokemonCenter_1F_Text_MudkipIsWaterType, MSGBOX_DEFAULT
	return

PetalburgCity_PokemonCenter_1F_Text_PCStorageSystem:
	.string "POKéMON Storage System dùng PC đó...\p"
	.string "Người tạo ra nó hẳn phải là một phù\n"
	.string "thủy khoa học!$"

PetalburgCity_PokemonCenter_1F_Text_OranBerryRegainedHP:
	.string "Khi POKéMON của tôi ăn ORAN BERRY, nó\n"
	.string "đã hồi lại HP!$"

PetalburgCity_PokemonCenter_1F_Text_ManyTypesOfPokemon:
	.string "Có rất nhiều hệ POKéMON.\p"
	.string "Mỗi hệ đều có điểm mạnh và điểm yếu khi\n"
	.string "đối đầu với các hệ khác.\p"
	.string "Tùy vào hệ của POKéMON, một trận đấu có\n"
	.string "thể dễ dàng hoặc khó khăn.$"

PetalburgCity_PokemonCenter_1F_Text_TreeckoIsGrassType:
	.string "Chẳng hạn, TREECKO của bạn thuộc hệ\n"
	.string "GRASS.\p"
	.string "Nó mạnh trước hệ WATER và GROUND.\p"
	.string "Nhưng lại yếu trước POKéMON hệ FIRE.$"

PetalburgCity_PokemonCenter_1F_Text_TorchicIsFireType:
	.string "Chẳng hạn, TORCHIC của bạn thuộc hệ\n"
	.string "FIRE.\p"
	.string "Nó mạnh trước hệ GRASS và BUG.\p"
	.string "Nhưng lại yếu trước POKéMON hệ WATER.$"

PetalburgCity_PokemonCenter_1F_Text_MudkipIsWaterType:
	.string "Chẳng hạn, MUDKIP của bạn thuộc hệ\n"
	.string "WATER.\p"
	.string "Nó mạnh trước hệ FIRE.\p"
	.string "Nhưng lại yếu trước POKéMON hệ GRASS\n"
	.string "và ELECTRIC.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global PetalburgCity_PokemonCenter_1F_Text_PCStorageSystem
	.global PetalburgCity_PokemonCenter_1F_Text_OranBerryRegainedHP
	.global PetalburgCity_PokemonCenter_1F_Text_ManyTypesOfPokemon
	.global PetalburgCity_PokemonCenter_1F_Text_TreeckoIsGrassType
	.global PetalburgCity_PokemonCenter_1F_Text_TorchicIsFireType
	.global PetalburgCity_PokemonCenter_1F_Text_MudkipIsWaterType
@ END GENERATED LOCALIZATION EXPORTS
