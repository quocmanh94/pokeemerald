EverGrandeCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

EverGrandeCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_EVER_GRANDE_CITY
	call_if_unset FLAG_MET_SCOTT_IN_EVERGRANDE, EverGrandeCity_PokemonCenter_1F_EventScript_TryShowScott
	end

EverGrandeCity_PokemonCenter_1F_EventScript_TryShowScott::
	goto_if_unset FLAG_BADGE06_GET, Common_EventScript_NopReturn
	clearflag FLAG_HIDE_EVER_GRANDE_POKEMON_CENTER_1F_SCOTT
	return

EverGrandeCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_EVER_GRANDE_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

EverGrandeCity_PokemonCenter_1F_EventScript_Woman::
	msgbox EverGrandeCity_PokemonCenter_1F_Text_LeagueAfterVictoryRoad, MSGBOX_NPC
	end

EverGrandeCity_PokemonCenter_1F_EventScript_ExpertM::
	msgbox EverGrandeCity_PokemonCenter_1F_Text_BelieveInYourPokemon, MSGBOX_NPC
	end

EverGrandeCity_PokemonCenter_1F_EventScript_Scott::
	lock
	faceplayer
	msgbox EverGrandeCity_PokemonCenter_1F_Text_ScottHappyForYou, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, EverGrandeCity_PokemonCenter_1F_EventScript_ScottExitNorth
	call_if_eq VAR_FACING, DIR_EAST, EverGrandeCity_PokemonCenter_1F_EventScript_ScottExit
	call_if_eq VAR_FACING, DIR_WEST, EverGrandeCity_PokemonCenter_1F_EventScript_ScottExit
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_IN_EVERGRANDE
	playse SE_EXIT
	waitse
	removeobject LOCALID_EVER_GRANDE_SCOTT
	release
	end

EverGrandeCity_PokemonCenter_1F_EventScript_ScottExitNorth::
	applymovement LOCALID_EVER_GRANDE_SCOTT, EverGrandeCity_PokemonCenter_1F_Movement_ScottExitNorth
	waitmovement 0
	return

EverGrandeCity_PokemonCenter_1F_EventScript_ScottExit::
	applymovement LOCALID_EVER_GRANDE_SCOTT, EverGrandeCity_PokemonCenter_1F_Movement_ScottExit
	waitmovement 0
	return

EverGrandeCity_PokemonCenter_1F_Movement_ScottExitNorth:
	walk_left
	walk_down
	walk_down
	walk_left
	walk_down
	walk_down
	step_end

EverGrandeCity_PokemonCenter_1F_Movement_ScottExit:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

EverGrandeCity_PokemonCenter_1F_Text_LeagueAfterVictoryRoad:
	.string "POKéMON LEAGUE chỉ cách VICTORY ROAD\n"
	.string "một quãng ngắn.\p"
	.string "Đã đi xa đến đây rồi, bạn còn lựa chọn\n"
	.string "nào ngoài tiếp tục tiến bước chứ?$"

EverGrandeCity_PokemonCenter_1F_Text_BelieveInYourPokemon:
	.string "VICTORY ROAD dài đằng đẵng và đầy gian\n"
	.string "nan...\p"
	.string "Nó giống như sống lại con đường mà mỗi\n"
	.string "người đã trải qua trong đời...\p"
	.string "Hãy tin tưởng POKéMON của bạn và cố\n"
	.string "gắng hết sức!$"

EverGrandeCity_PokemonCenter_1F_Text_ScottHappyForYou:
	.string "SCOTT: {PLAYER}{KUN}, cậu đã nỗ lực\n"
	.string "vượt mọi chông gai để đến thách đấu\l"
	.string "POKéMON LEAGUE!\p"
	.string "Tôi mừng cho cậu! Công cổ vũ của tôi\n"
	.string "thật không uổng phí!\p"
	.string "{PLAYER}{KUN}, nếu cậu trở thành\n"
	.string "POKéMON LEAGUE CHAMPION...\p"
	.string "Lúc đó tôi sẽ liên lạc với cậu.\p"
	.string "Được rồi, {PLAYER}{KUN}. Hãy tiến tới\n"
	.string "đỉnh cao!$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global EverGrandeCity_PokemonCenter_1F_Text_LeagueAfterVictoryRoad
	.global EverGrandeCity_PokemonCenter_1F_Text_BelieveInYourPokemon
	.global EverGrandeCity_PokemonCenter_1F_Text_ScottHappyForYou
@ END GENERATED LOCALIZATION EXPORTS
