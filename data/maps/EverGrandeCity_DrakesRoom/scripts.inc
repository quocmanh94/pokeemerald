EverGrandeCity_DrakesRoom_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_DrakesRoom_OnFrame
	map_script MAP_SCRIPT_ON_LOAD, EverGrandeCity_DrakesRoom_OnLoad
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_SidneysRoom_OnWarp
	.byte 0

@ Unused, Drake uses Sidneys identical OnWarp for some reason
EverGrandeCity_DrakesRoom_OnWarp:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_DrakesRoom_EventScript_PlayerTurnNorth
	.2byte 0

EverGrandeCity_DrakesRoom_EventScript_PlayerTurnNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

EverGrandeCity_DrakesRoom_OnFrame:
	map_script_2 VAR_ELITE_4_STATE, 3, EverGrandeCity_DrakesRoom_EventScript_WalkInCloseDoor
	.2byte 0

EverGrandeCity_DrakesRoom_EventScript_WalkInCloseDoor::
	lockall
	call PokemonLeague_EliteFour_EventScript_WalkInCloseDoor
	setvar VAR_ELITE_4_STATE, 4
	releaseall
	end

EverGrandeCity_DrakesRoom_OnLoad:
	call_if_set FLAG_DEFEATED_ELITE_4_DRAKE, EverGrandeCity_DrakesRoom_EventScript_ResetAdvanceToNextRoom
	call_if_eq VAR_ELITE_4_STATE, 4, EverGrandeCity_DrakesRoom_EventScript_CloseDoor
	end

EverGrandeCity_DrakesRoom_EventScript_ResetAdvanceToNextRoom::
	call PokemonLeague_EliteFour_EventScript_ResetAdvanceToNextRoom
	return

EverGrandeCity_DrakesRoom_EventScript_CloseDoor::
	call PokemonLeague_EliteFour_EventScript_CloseDoor
	return

EverGrandeCity_DrakesRoom_EventScript_Drake::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_ELITE_4_DRAKE, EverGrandeCity_DrakesRoom_EventScript_PostBattleSpeech
	playbgm MUS_ENCOUNTER_ELITE_FOUR, FALSE
	msgbox EverGrandeCity_DrakesRoom_Text_IntroSpeech, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_DRAKE, EverGrandeCity_DrakesRoom_Text_Defeat
	goto EverGrandeCity_DrakesRoom_EventScript_Defeated
	end

EverGrandeCity_DrakesRoom_EventScript_PostBattleSpeech::
	msgbox EverGrandeCity_DrakesRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_DrakesRoom_EventScript_Defeated::
	setvar VAR_0x8004, FANCOUNTER_DEFEATED_DRAKE
	special Script_TryGainNewFanFromCounter
	setflag FLAG_DEFEATED_ELITE_4_DRAKE
	call PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles
	msgbox EverGrandeCity_DrakesRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_DrakesRoom_Text_IntroSpeech:
	.string "Ta là thành viên cuối cùng của POKéMON\n"
	.string "LEAGUE ELITE FOUR, DRAKE, bậc thầy\l"
	.string "DRAGON!\p"
	.string "Trong trạng thái tự nhiên, POKéMON là\n"
	.string "những sinh vật hoang dã. Chúng được\l"
	.string "tự do.\p"
	.string "Đôi khi chúng cản trở ta. Đôi khi chúng\n"
	.string "giúp đỡ ta.\p"
	.string "Ngươi có biết cần điều gì để con người\n"
	.string "và POKéMON có thể chiến đấu như những\l"
	.string "người bạn đồng hành không?\p"
	.string "Ngươi có biết thứ gì là cần thiết\n"
	.string "không?\p"
	.string "Nếu không biết, ngươi sẽ không bao giờ\n"
	.string "thắng được ta!$"

EverGrandeCity_DrakesRoom_Text_Defeat:
	.string "Phải nói là xuất sắc.$"

EverGrandeCity_DrakesRoom_Text_PostBattleSpeech:
	.string "Ngươi hoàn toàn xứng đáng được công\n"
	.string "nhận vì đã tiến xa đến vậy với tư cách\l"
	.string "HLV của POKéMON.\p"
	.string "Có vẻ ngươi biết điều gì là cần thiết.\p"
	.string "Đúng vậy, một HLV cần có tấm lòng\n"
	.string "chính trực.\p"
	.string "POKéMON cảm nhận trái tim lương thiện\n"
	.string "của HLV và học cách phân biệt\l"
	.string "đúng sai.\p"
	.string "Chúng cảm nhận trái tim lương thiện của\n"
	.string "HLV và trở nên mạnh mẽ.\p"
	.string "Đi đi! Tiến lên! CHAMPION đang đợi!$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global EverGrandeCity_DrakesRoom_Text_IntroSpeech
	.global EverGrandeCity_DrakesRoom_Text_Defeat
	.global EverGrandeCity_DrakesRoom_Text_PostBattleSpeech
@ END GENERATED LOCALIZATION EXPORTS
