EverGrandeCity_PhoebesRoom_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, EverGrandeCity_PhoebesRoom_OnLoad
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_PhoebesRoom_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_PhoebesRoom_OnFrame
	.byte 0

EverGrandeCity_PhoebesRoom_OnWarp:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_PhoebesRoom_EventScript_PlayerTurnNorth
	.2byte 0

EverGrandeCity_PhoebesRoom_EventScript_PlayerTurnNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

EverGrandeCity_PhoebesRoom_OnFrame:
	map_script_2 VAR_ELITE_4_STATE, 1, EverGrandeCity_PhoebesRoom_EventScript_WalkInCloseDoor
	.2byte 0

EverGrandeCity_PhoebesRoom_EventScript_WalkInCloseDoor::
	lockall
	call PokemonLeague_EliteFour_EventScript_WalkInCloseDoor
	setvar VAR_ELITE_4_STATE, 2
	releaseall
	end

EverGrandeCity_PhoebesRoom_OnLoad:
	call_if_set FLAG_DEFEATED_ELITE_4_PHOEBE, EverGrandeCity_PhoebesRoom_EventScript_ResetAdvanceToNextRoom
	call_if_eq VAR_ELITE_4_STATE, 2, EverGrandeCity_PhoebesRoom_EventScript_CloseDoor
	end

EverGrandeCity_PhoebesRoom_EventScript_ResetAdvanceToNextRoom::
	call PokemonLeague_EliteFour_EventScript_ResetAdvanceToNextRoom
	return

EverGrandeCity_PhoebesRoom_EventScript_CloseDoor::
	call PokemonLeague_EliteFour_EventScript_CloseDoor
	return

EverGrandeCity_PhoebesRoom_EventScript_Phoebe::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_ELITE_4_PHOEBE, EverGrandeCity_PhoebesRoom_EventScript_PostBattleSpeech
	playbgm MUS_ENCOUNTER_ELITE_FOUR, FALSE
	msgbox EverGrandeCity_PhoebesRoom_Text_IntroSpeech, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_PHOEBE, EverGrandeCity_PhoebesRoom_Text_Defeat
	goto EverGrandeCity_PhoebesRoom_EventScript_Defeated
	end

EverGrandeCity_PhoebesRoom_EventScript_PostBattleSpeech::
	msgbox EverGrandeCity_PhoebesRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_PhoebesRoom_EventScript_Defeated::
	setflag FLAG_DEFEATED_ELITE_4_PHOEBE
	call PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles
	msgbox EverGrandeCity_PhoebesRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_PhoebesRoom_Text_IntroSpeech:
	.string "A ha ha ha!\p"
	.string "Tớ là PHOEBE của ELITE FOUR. Tớ đã rèn\n"
	.string "luyện trên MT. PYRE.\p"
	.string "Trong quá trình đó, tớ đã học được\n"
	.string "cách giao tiếp với POKéMON hệ GHOST.\p"
	.string "Đúng vậy, mối liên kết mà tớ xây dựng\n"
	.string "với POKéMON vô cùng bền chặt.\p"
	.string "Nào, cứ thử xem cậu có thể gây nổi chút\n"
	.string "sát thương nào cho POKéMON của tớ\l"
	.string "không!$"

EverGrandeCity_PhoebesRoom_Text_Defeat:
	.string "Ôi, chết thật. Tớ thua mất rồi.$"

EverGrandeCity_PhoebesRoom_Text_PostBattleSpeech:
	.string "Giữa cậu và POKéMON của cậu cũng có\n"
	.string "một mối liên kết rõ ràng.\p"
	.string "Tớ đã không nhận ra điều đó, nên thua\n"
	.string "cũng là lẽ tự nhiên.\p"
	.string "Ừ, tớ muốn xem mối liên kết ấy sẽ đưa\n"
	.string "cậu tiến xa đến đâu.\p"
	.string "Đi đi, hãy sang căn phòng tiếp theo.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global EverGrandeCity_PhoebesRoom_Text_IntroSpeech
	.global EverGrandeCity_PhoebesRoom_Text_Defeat
	.global EverGrandeCity_PhoebesRoom_Text_PostBattleSpeech
@ END GENERATED LOCALIZATION EXPORTS
