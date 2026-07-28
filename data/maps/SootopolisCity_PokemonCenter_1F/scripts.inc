SootopolisCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SootopolisCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

SootopolisCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_SOOTOPOLIS_CITY
	end

SootopolisCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_SOOTOPOLIS_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

SootopolisCity_PokemonCenter_1F_EventScript_Gentleman::
	lock
	faceplayer
	goto_if_ge VAR_SKY_PILLAR_STATE, 2, SootopolisCity_PokemonCenter_1F_EventScript_GentlemanNoLegendaries
	goto_if_unset FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, SootopolisCity_PokemonCenter_1F_EventScript_GentlemanNoLegendaries
	msgbox SootopolisCity_PokemonCenter_1F_Text_EveryoneTakenRefuge, MSGBOX_DEFAULT
	release
	end

SootopolisCity_PokemonCenter_1F_EventScript_GentlemanNoLegendaries::
	msgbox SootopolisCity_PokemonCenter_1F_Text_WallaceToughestInHoenn, MSGBOX_DEFAULT
	release
	end

SootopolisCity_PokemonCenter_1F_EventScript_Woman::
	lock
	faceplayer
	goto_if_ge VAR_SKY_PILLAR_STATE, 2, SootopolisCity_PokemonCenter_1F_EventScript_WomanNoLegendaries
	goto_if_unset FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, SootopolisCity_PokemonCenter_1F_EventScript_WomanNoLegendaries
	msgbox SootopolisCity_PokemonCenter_1F_Text_ArentPokemonOurFriends, MSGBOX_DEFAULT
	release
	end

SootopolisCity_PokemonCenter_1F_EventScript_WomanNoLegendaries::
	msgbox SootopolisCity_PokemonCenter_1F_Text_AlwaysBeFriendsWithPokemon, MSGBOX_DEFAULT
	release
	end

SootopolisCity_PokemonCenter_1F_Text_WallaceToughestInHoenn:
	.string "Nghe đồn WALLACE là HLV mạnh nhất\n"
	.string "toàn vùng HOENN.\p"
	.string "GYM của thành phố này do HLV từng\n"
	.string "dạy WALLACE dẫn dắt.\p"
	.string "Nhưng ELITE FOUR... Người ta nói họ còn\n"
	.string "mạnh hơn cả sư phụ của WALLACE.\p"
	.string "Rốt cuộc họ mạnh đến mức nào nhỉ?$"

SootopolisCity_PokemonCenter_1F_Text_EveryoneTakenRefuge:
	.string "Mọi người trong thành phố đều đã đi\n"
	.string "lánh nạn và không chịu ra khỏi nhà.\p"
	.string "Ngay cả tôi cũng chẳng muốn mạo hiểm ra\n"
	.string "ngoài.$"

SootopolisCity_PokemonCenter_1F_Text_AlwaysBeFriendsWithPokemon:
	.string "Dù khi nào, ở đâu hay xảy ra chuyện gì,\n"
	.string "tôi vẫn sẽ luôn là bạn của POKéMON.\p"
	.string "Vì ở bên POKéMON vui lắm!$"

SootopolisCity_PokemonCenter_1F_Text_ArentPokemonOurFriends:
	.string "POKéMON chẳng phải là bạn của chúng ta\n"
	.string "sao?\p"
	.string "Sao chúng lại trở nên hung hăng thế\n"
	.string "này?$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global SootopolisCity_PokemonCenter_1F_Text_WallaceToughestInHoenn
	.global SootopolisCity_PokemonCenter_1F_Text_EveryoneTakenRefuge
	.global SootopolisCity_PokemonCenter_1F_Text_AlwaysBeFriendsWithPokemon
	.global SootopolisCity_PokemonCenter_1F_Text_ArentPokemonOurFriends
@ END GENERATED LOCALIZATION EXPORTS
