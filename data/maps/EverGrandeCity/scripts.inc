EverGrandeCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_OnTransition
	.byte 0

EverGrandeCity_OnTransition:
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	end

EverGrandeCity_EventScript_VictoryRoadSign::
	msgbox EverGrandeCity_Text_EnteringVictoryRoad, MSGBOX_SIGN
	end

EverGrandeCity_EventScript_CitySign::
	msgbox EverGrandeCity_Text_CitySign, MSGBOX_SIGN
	end

EverGrandeCity_EventScript_PokemonLeagueSign::
	msgbox EverGrandeCity_Text_EnteringPokemonLeague, MSGBOX_SIGN
	end

EverGrandeCity_EventScript_SetVisitedEverGrande::
	setflag FLAG_VISITED_EVER_GRANDE_CITY
	setvar VAR_TEMP_1, 1
	end

EverGrandeCity_Text_EnteringVictoryRoad:
	.string "ĐANG VÀO VICTORY ROAD$"

EverGrandeCity_Text_EnteringPokemonLeague:
	.string "ĐANG VÀO CỔNG TRUNG TÂM POKéMON\n"
	.string "LEAGUE$"

EverGrandeCity_Text_CitySign:
	.string "EVER GRANDE CITY\p"
	.string "“Thiên đường của hoa, biển cả và\n"
	.string "POKéMON.”$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global EverGrandeCity_Text_EnteringVictoryRoad
	.global EverGrandeCity_Text_EnteringPokemonLeague
	.global EverGrandeCity_Text_CitySign
@ END GENERATED LOCALIZATION EXPORTS
