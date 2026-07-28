Route119_WeatherInstitute_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route119_WeatherInstitute_1F_OnTransition
	.byte 0

Route119_WeatherInstitute_1F_OnTransition:
	call_if_eq VAR_WEATHER_INSTITUTE_STATE, 0, Route119_WeatherInstitute_1F_EventScript_SetLittleBoyPos
	end

Route119_WeatherInstitute_1F_EventScript_SetLittleBoyPos::
	setobjectxyperm LOCALID_WEATHER_INSTITUTE_LITTLE_BOY, 0, 5
	setobjectmovementtype LOCALID_WEATHER_INSTITUTE_LITTLE_BOY, MOVEMENT_TYPE_FACE_RIGHT
	return

Route119_WeatherInstitute_1F_EventScript_LittleBoy::
	lock
	faceplayer
	special GetPlayerBigGuyGirlString
	goto_if_eq VAR_WEATHER_INSTITUTE_STATE, 0, Route119_WeatherInstitute_1F_EventScript_LittleBoyTeamAquaHere
	msgbox Route119_WeatherInstitute_1F_Text_WowYoureStrong, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_LittleBoyTeamAquaHere::
	msgbox Route119_WeatherInstitute_1F_Text_EveryoneWentUpstairs, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_InstituteWorker1::
	lock
	faceplayer
	goto_if_unset FLAG_SYS_GAME_CLEAR, Route119_WeatherInstitute_1F_EventScript_StudyingRain
	setvar VAR_0x8004, 0
	call_if_set FLAG_DEFEATED_KYOGRE, Route119_WeatherInstitute_1F_EventScript_LegendaryDefeated
	call_if_set FLAG_DEFEATED_GROUDON, Route119_WeatherInstitute_1F_EventScript_LegendaryDefeated
	goto_if_eq VAR_0x8004, 2, Route119_WeatherInstitute_1F_EventScript_StudyingRain  @ Both defeated
	msgbox Route119_WeatherInstitute_1F_Text_NoticingAbnormalWeather, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_LegendaryDefeated::
	addvar VAR_0x8004, 1
	return

Route119_WeatherInstitute_1F_EventScript_StudyingRain::
	msgbox Route119_WeatherInstitute_1F_Text_ProfStudyingRain, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_InstituteWorker2::
	msgbox Route119_WeatherInstitute_1F_Text_WhatWereAquasUpTo, MSGBOX_NPC
	end

Route119_WeatherInstitute_1F_EventScript_Bed::
	lockall
	msgbox Route119_WeatherInstitute_1F_Text_TakeRestInBed, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	releaseall
	end

Route119_WeatherInstitute_1F_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_1, Route119_WeatherInstitute_1F_Text_Grunt1Intro, Route119_WeatherInstitute_1F_Text_Grunt1Defeat
	msgbox Route119_WeatherInstitute_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_1F_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_4, Route119_WeatherInstitute_1F_Text_Grunt4Intro, Route119_WeatherInstitute_1F_Text_Grunt4Defeat
	msgbox Route119_WeatherInstitute_1F_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_1F_Text_Grunt1Intro:
	.string "Thủ lĩnh quan tâm đến nghiên cứu đang\n"
	.string "được tiến hành ở đây nên đã phái bọn\l"
	.string "ta tới.\p"
	.string "Đừng có xen vào!$"

Route119_WeatherInstitute_1F_Text_Grunt1Defeat:
	.string "Khốn thật... Lại bị một đứa nhóc đánh\n"
	.string "bại...$"

Route119_WeatherInstitute_1F_Text_Grunt1PostBattle:
	.string "Thủ lĩnh của bọn ta biết mọi thứ.\p"
	.string "Nhưng ta chỉ là lính quèn. Làm sao ta\n"
	.string "biết ông ấy đang nghĩ gì chứ?$"

Route119_WeatherInstitute_1F_Text_Grunt4Intro:
	.string "Hả? Một đứa nhóc làm gì ở đây?$"

Route119_WeatherInstitute_1F_Text_Grunt4Defeat:
	.string "Hả? Ta thua rồi sao?!$"

Route119_WeatherInstitute_1F_Text_Grunt4PostBattle:
	.string "Ôi không... Ta sẽ bị mắng cho một trận vì\n"
	.string "thua một đứa nhóc mất...\p"
	.string "Hay là cứ nằm xuống giường ngủ một\n"
	.string "giấc...$"

Route119_WeatherInstitute_1F_Text_EveryoneWentUpstairs:
	.string "Trong lúc tôi ngủ, mọi người đã lên tầng\n"
	.string "trên hết rồi!$"

Route119_WeatherInstitute_1F_Text_WowYoureStrong:
	.string "Chà, bạn mạnh thật đấy!\p"
	.string "Ước gì tôi cũng có thể trở thành\n"
	.string "HLV POKéMON như bạn!$"

Route119_WeatherInstitute_1F_Text_ProfStudyingRain:
	.string "PROFESSOR rất yêu mưa. Đó là sự thật.\p"
	.string "Nhưng nếu mưa cứ kéo dài, mọi người sẽ\n"
	.string "gặp rắc rối. Đó cũng là sự thật.\p"
	.string "Vì vậy, PROFESSOR đang nghiên cứu cách\n"
	.string "tận dụng mưa sao cho có ích.$"

Route119_WeatherInstitute_1F_Text_NoticingAbnormalWeather:
	.string "Ở tầng 2 của INSTITUTE, chúng tôi\n"
	.string "nghiên cứu các kiểu thời tiết trên toàn\l"
	.string "vùng HOENN.\p"
	.string "Gần đây, chúng tôi nhận thấy có những\n"
	.string "đợt hạn hán và mưa lớn tạm thời chỉ\l"
	.string "xảy ra tại từng khu vực riêng lẻ...$"

Route119_WeatherInstitute_1F_Text_WhatWereAquasUpTo:
	.string "Xin chào! Nhờ hành động của bạn mà\n"
	.string "chúng tôi đã được cứu!\p"
	.string "Điều tôi không hiểu là bọn AQUAS rốt\n"
	.string "cuộc đang âm mưu chuyện gì.$"

Route119_WeatherInstitute_1F_Text_TakeRestInBed:
	.string "Có một chiếc giường... Nghỉ ngơi một lát\n"
	.string "thôi.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global Route119_WeatherInstitute_1F_Text_Grunt1Intro
	.global Route119_WeatherInstitute_1F_Text_Grunt1Defeat
	.global Route119_WeatherInstitute_1F_Text_Grunt1PostBattle
	.global Route119_WeatherInstitute_1F_Text_Grunt4Intro
	.global Route119_WeatherInstitute_1F_Text_Grunt4Defeat
	.global Route119_WeatherInstitute_1F_Text_Grunt4PostBattle
	.global Route119_WeatherInstitute_1F_Text_EveryoneWentUpstairs
	.global Route119_WeatherInstitute_1F_Text_WowYoureStrong
	.global Route119_WeatherInstitute_1F_Text_ProfStudyingRain
	.global Route119_WeatherInstitute_1F_Text_NoticingAbnormalWeather
	.global Route119_WeatherInstitute_1F_Text_WhatWereAquasUpTo
	.global Route119_WeatherInstitute_1F_Text_TakeRestInBed
@ END GENERATED LOCALIZATION EXPORTS
