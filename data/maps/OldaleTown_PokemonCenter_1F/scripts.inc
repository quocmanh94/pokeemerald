OldaleTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OldaleTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

OldaleTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_OLDALE_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

OldaleTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_OLDALE_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

OldaleTown_PokemonCenter_1F_EventScript_Gentleman::
	msgbox OldaleTown_PokemonCenter_1F_Text_TrainersCanUsePC, MSGBOX_NPC
	end

OldaleTown_PokemonCenter_1F_EventScript_Boy::
	msgbox OldaleTown_PokemonCenter_1F_Text_PokemonCentersAreGreat, MSGBOX_NPC
	end

OldaleTown_PokemonCenter_1F_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_SYS_POKEDEX_GET, OldaleTown_PokemonCenter_1F_EventScript_WirelessClubAvailable
	msgbox OldaleTown_PokemonCenter_1F_Text_WirelessClubNotAvailable, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_1F_EventScript_WirelessClubAvailable::
	msgbox OldaleTown_PokemonCenter_1F_Text_TradedInWirelessClub, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_1F_Text_TrainersCanUsePC:
	.string "Chiếc PC ở góc kia dành cho mọi POKéMON\n"
	.string "HLV sử dụng.\p"
	.string "Tất nhiên, cậu cũng có thể dùng nó.$"

OldaleTown_PokemonCenter_1F_Text_PokemonCentersAreGreat:
	.string "POKéMON CENTERS thật tuyệt!\p"
	.string "Cậu có thể dùng dịch vụ bao nhiêu lần\n"
	.string "tùy thích mà hoàn toàn miễn phí. Chẳng\l"
	.string "phải lo gì cả!$"

OldaleTown_PokemonCenter_1F_Text_WirelessClubNotAvailable:
	.string "POKéMON WIRELESS CLUB trên tầng hai\n"
	.string "mới được xây gần đây.\p"
	.string "Nhưng nghe nói họ vẫn đang điều chỉnh\n"
	.string "thiết bị.$"

OldaleTown_PokemonCenter_1F_Text_TradedInWirelessClub:
	.string "POKéMON WIRELESS CLUB trên tầng hai\n"
	.string "mới được xây gần đây.\p"
	.string "Tôi đã trao đổi POKéMON ngay lập tức.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global OldaleTown_PokemonCenter_1F_Text_TrainersCanUsePC
	.global OldaleTown_PokemonCenter_1F_Text_PokemonCentersAreGreat
	.global OldaleTown_PokemonCenter_1F_Text_WirelessClubNotAvailable
	.global OldaleTown_PokemonCenter_1F_Text_TradedInWirelessClub
@ END GENERATED LOCALIZATION EXPORTS
