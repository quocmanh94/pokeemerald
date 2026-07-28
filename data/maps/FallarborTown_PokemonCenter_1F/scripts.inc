FallarborTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FallarborTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

FallarborTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_FALLARBOR_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

FallarborTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_FALLARBOR_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

FallarborTown_PokemonCenter_1F_EventScript_Girl::
	msgbox FallarborTown_PokemonCenter_1F_Text_FossilManiacEdgeOfTown, MSGBOX_NPC
	end

FallarborTown_PokemonCenter_1F_EventScript_ExpertM::
	msgbox FallarborTown_PokemonCenter_1F_Text_PlantHardyTrees, MSGBOX_NPC
	end

FallarborTown_PokemonCenter_1F_EventScript_Lanette::
	lock
	faceplayer
	msgbox FallarborTown_PokemonCenter_1F_Text_LanetteGreeting, MSGBOX_DEFAULT
	closemessage
	switch VAR_FACING
	case DIR_NORTH, FallarborTown_PokemonCenter_1F_EventScript_LanetteExitNorth
	case DIR_WEST, FallarborTown_PokemonCenter_1F_EventScript_LanetteExitWest
	end

FallarborTown_PokemonCenter_1F_EventScript_LanetteExitNorth::
	applymovement LOCALID_FALLARBOR_LANETTE, FallarborTown_PokemonCenter_1F_Movement_LanetteExitNorth
	waitmovement 0
	goto FallarborTown_PokemonCenter_1F_EventScript_LanetteExited
	end

FallarborTown_PokemonCenter_1F_EventScript_LanetteExitWest::
	applymovement LOCALID_FALLARBOR_LANETTE, FallarborTown_PokemonCenter_1F_Movement_LanetteExitWest
	waitmovement 0
	goto FallarborTown_PokemonCenter_1F_EventScript_LanetteExited
	end

FallarborTown_PokemonCenter_1F_EventScript_LanetteExited::
	playse SE_SLIDING_DOOR
	removeobject LOCALID_FALLARBOR_LANETTE
	clearflag FLAG_HIDE_LANETTES_HOUSE_LANETTE
	release
	end

FallarborTown_PokemonCenter_1F_Movement_LanetteExitNorth:
	walk_right
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	delay_8
	step_end

FallarborTown_PokemonCenter_1F_Movement_LanetteExitWest:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	delay_8
	step_end

FallarborTown_PokemonCenter_1F_Text_LanetteGreeting:
	.string "Ồ, chào em. Em là...?\p"
	.string "Được rồi, tên em là {PLAYER}{KUN}. Chị\n"
	.string "nhận ra em là một HLV.\p"
	.string "Vậy nghĩa là em có dùng POKéMON\n"
	.string "Storage System do chị phát triển.\p"
	.string "Chị suy ra điều đó bằng một phép suy\n"
	.string "luận rất đơn giản.\p"
	.string "Em bắt chuyện với chị vì muốn truy cập\n"
	.string "thứ gì đó trên chiếc PC này.\p"
	.string "Ồ, chị xin lỗi. Chị là LANETTE.\p"
	.string "Thật lòng mà nói, chị rất vui được gặp\n"
	.string "em, và cũng rất vui vì em đang dùng\l"
	.string "Storage System.\p"
	.string "Nếu có thể, hãy ghé thăm chị ở nhà nhé.\n"
	.string "Nhà chị nằm trên ROUTE 114.$"

FallarborTown_PokemonCenter_1F_Text_FossilManiacEdgeOfTown:
	.string "Không biết POKéMON từ thời xa xưa\n"
	.string "trông như thế nào nhỉ?\p"
	.string "Có lẽ FOSSIL MANIAC ở rìa thị trấn sẽ\n"
	.string "biết.$"

FallarborTown_PokemonCenter_1F_Text_PlantHardyTrees:
	.string "Trên những cánh đồng ở FALLARBOR,\n"
	.string "chúng tôi trồng cây non thuộc các giống\l"
	.string "khỏe mạnh, có thể sinh trưởng ngay cả\l"
	.string "trong tro núi lửa.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global FallarborTown_PokemonCenter_1F_Text_LanetteGreeting
	.global FallarborTown_PokemonCenter_1F_Text_FossilManiacEdgeOfTown
	.global FallarborTown_PokemonCenter_1F_Text_PlantHardyTrees
@ END GENERATED LOCALIZATION EXPORTS
