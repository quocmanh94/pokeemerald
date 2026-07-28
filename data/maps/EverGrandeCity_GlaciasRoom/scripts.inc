EverGrandeCity_GlaciasRoom_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_GlaciasRoom_OnFrame
	map_script MAP_SCRIPT_ON_LOAD, EverGrandeCity_GlaciasRoom_OnLoad
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_GlaciasRoom_OnWarp
	.byte 0

EverGrandeCity_GlaciasRoom_OnWarp:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_GlaciasRoom_EventScript_PlayerTurnNorth
	.2byte 0

EverGrandeCity_GlaciasRoom_EventScript_PlayerTurnNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

EverGrandeCity_GlaciasRoom_OnFrame:
	map_script_2 VAR_ELITE_4_STATE, 2, EverGrandeCity_GlaciasRoom_EventScript_WalkInCloseDoor
	.2byte 0

EverGrandeCity_GlaciasRoom_EventScript_WalkInCloseDoor::
	lockall
	call PokemonLeague_EliteFour_EventScript_WalkInCloseDoor
	setvar VAR_ELITE_4_STATE, 3
	releaseall
	end

EverGrandeCity_GlaciasRoom_OnLoad:
	call_if_set FLAG_DEFEATED_ELITE_4_GLACIA, EverGrandeCity_GlaciasRoom_EventScript_ResetAdvanceToNextRoom
	call_if_eq VAR_ELITE_4_STATE, 3, EverGrandeCity_GlaciasRoom_EventScript_CloseDoor
	end

EverGrandeCity_GlaciasRoom_EventScript_ResetAdvanceToNextRoom::
	call PokemonLeague_EliteFour_EventScript_ResetAdvanceToNextRoom
	return

EverGrandeCity_GlaciasRoom_EventScript_CloseDoor::
	call PokemonLeague_EliteFour_EventScript_CloseDoor
	return

EverGrandeCity_GlaciasRoom_EventScript_Glacia::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_ELITE_4_GLACIA, EverGrandeCity_GlaciasRoom_EventScript_PostBattleSpeech
	playbgm MUS_ENCOUNTER_ELITE_FOUR, FALSE
	msgbox EverGrandeCity_GlaciasRoom_Text_IntroSpeech, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GLACIA, EverGrandeCity_GlaciasRoom_Text_Defeat
	goto EverGrandeCity_GlaciasRoom_EventScript_Defeated
	end

EverGrandeCity_GlaciasRoom_EventScript_PostBattleSpeech::
	msgbox EverGrandeCity_GlaciasRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_GlaciasRoom_EventScript_Defeated::
	setflag FLAG_DEFEATED_ELITE_4_GLACIA
	call PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles
	msgbox EverGrandeCity_GlaciasRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_GlaciasRoom_Text_IntroSpeech:
	.string "Chào mừng, ta là GLACIA của ELITE FOUR.\p"
	.string "Ta đã vượt đường xa đến HOENN để rèn\n"
	.string "luyện kỹ năng băng giá của mình.\p"
	.string "Nhưng những gì ta chứng kiến chỉ là\n"
	.string "lời thách đấu từ các HLV yếu đuối\l"
	.string "cùng POKéMON của họ.\p"
	.string "Còn ngươi thì sao?\p"
	.string "Ta sẽ vô cùng mãn nguyện nếu có thể dốc\n"
	.string "toàn lực đấu với ngươi!$"

EverGrandeCity_GlaciasRoom_Text_Defeat:
	.string "Ngươi và POKéMON của ngươi... Tinh\n"
	.string "thần của các ngươi cháy bỏng biết bao!\p"
	.string "Sức nóng thiêu đốt tất cả đã áp đảo ta.\p"
	.string "Chẳng trách kỹ năng băng giá của ta\n"
	.string "không thể làm tổn thương ngươi.$"

EverGrandeCity_GlaciasRoom_Text_PostBattleSpeech:
	.string "Hãy tiến vào căn phòng tiếp theo.\p"
	.string "Tại đó, ngươi sẽ được chứng kiến bộ\n"
	.string "mặt thực sự đáng sợ của POKéMON\l"
	.string "LEAGUE.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global EverGrandeCity_GlaciasRoom_Text_IntroSpeech
	.global EverGrandeCity_GlaciasRoom_Text_Defeat
	.global EverGrandeCity_GlaciasRoom_Text_PostBattleSpeech
@ END GENERATED LOCALIZATION EXPORTS
