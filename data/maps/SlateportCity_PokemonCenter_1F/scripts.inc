SlateportCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

SlateportCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_SLATEPORT_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

SlateportCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_SLATEPORT_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

SlateportCity_PokemonCenter_1F_EventScript_Sailor::
	msgbox SlateportCity_PokemonCenter_1F_Text_RaiseDifferentTypesOfPokemon, MSGBOX_NPC
	end

SlateportCity_PokemonCenter_1F_EventScript_Woman::
	msgbox SlateportCity_PokemonCenter_1F_Text_TradedMonWithFriend, MSGBOX_NPC
	end

SlateportCity_PokemonCenter_1F_Text_RaiseDifferentTypesOfPokemon:
	.string "Muốn nghe một lời khuyên khi chiến đấu\n"
	.string "không?\p"
	.string "Theo tôi, nên nuôi nhiều loại POKéMON\n"
	.string "khác nhau một cách cân bằng.\p"
	.string "Chỉ làm cho một POKéMON thật mạnh thì\n"
	.string "không ổn đâu.\p"
	.string "Nếu gặp bất lợi về hệ, nó có thể chẳng\n"
	.string "có cơ hội chiến thắng.$"

SlateportCity_PokemonCenter_1F_Text_TradedMonWithFriend:
	.string "Tôi trao đổi POKéMON với bạn bè.\p"
	.string "Nếu POKéMON nhận được còn đang giữ\n"
	.string "một vật phẩm, tôi sẽ vui gấp đôi!$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global SlateportCity_PokemonCenter_1F_Text_RaiseDifferentTypesOfPokemon
	.global SlateportCity_PokemonCenter_1F_Text_TradedMonWithFriend
@ END GENERATED LOCALIZATION EXPORTS
