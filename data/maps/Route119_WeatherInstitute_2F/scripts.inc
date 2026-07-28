Route119_WeatherInstitute_2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route119_WeatherInstitute_2F_OnTransition
	.byte 0

Route119_WeatherInstitute_2F_OnTransition:
	call_if_eq VAR_WEATHER_INSTITUTE_STATE, 0, Route119_WeatherInstitute_2F_EventScript_SetScientistPosAquaHere
	call_if_eq VAR_WEATHER_INSTITUTE_STATE, 1, Route119_WeatherInstitute_2F_EventScript_SetScientistPosAquaGone
	call_if_set FLAG_SYS_GAME_CLEAR, Route119_WeatherInstitute_2F_EventScript_SetScientistPosGameClear
	end

Route119_WeatherInstitute_2F_EventScript_SetScientistPosAquaHere::
	setobjectxyperm LOCALID_WEATHER_INSTITUTE_2F_SCIENTIST, 1, 6
	setobjectmovementtype LOCALID_WEATHER_INSTITUTE_2F_SCIENTIST, MOVEMENT_TYPE_FACE_RIGHT
	return

Route119_WeatherInstitute_2F_EventScript_SetScientistPosAquaGone::
	setobjectxyperm LOCALID_WEATHER_INSTITUTE_2F_SCIENTIST, 4, 6
	setobjectmovementtype LOCALID_WEATHER_INSTITUTE_2F_SCIENTIST, MOVEMENT_TYPE_FACE_RIGHT
	return

Route119_WeatherInstitute_2F_EventScript_SetScientistPosGameClear::
	setobjectxyperm LOCALID_WEATHER_INSTITUTE_2F_SCIENTIST, 2, 2
	setobjectmovementtype LOCALID_WEATHER_INSTITUTE_2F_SCIENTIST, MOVEMENT_TYPE_FACE_UP
	return

Route119_WeatherInstitute_2F_EventScript_Grunt5::
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_5, Route119_WeatherInstitute_2F_Text_Grunt5Intro, Route119_WeatherInstitute_2F_Text_Grunt5Defeat
	msgbox Route119_WeatherInstitute_2F_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_2F_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_2, Route119_WeatherInstitute_2F_Text_Grunt2Intro, Route119_WeatherInstitute_2F_Text_Grunt2Defeat
	msgbox Route119_WeatherInstitute_2F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_2F_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_3, Route119_WeatherInstitute_2F_Text_Grunt3Intro, Route119_WeatherInstitute_2F_Text_Grunt3Defeat
	msgbox Route119_WeatherInstitute_2F_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_2F_EventScript_Shelly::
	trainerbattle_single TRAINER_SHELLY_WEATHER_INSTITUTE, Route119_WeatherInstitute_2F_Text_ShellyIntro, Route119_WeatherInstitute_2F_Text_ShellyDefeat, Route119_WeatherInstitute_2F_EventScript_ShellyDefeated
	msgbox Route119_WeatherInstitute_2F_Text_ShellyPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_2F_EventScript_ShellyDefeated::
	msgbox Route119_WeatherInstitute_2F_Text_ShellyPostBattle, MSGBOX_DEFAULT
	closemessage
	addobject LOCALID_WEATHER_INSTITUTE_2F_GRUNT_3
	applymovement LOCALID_WEATHER_INSTITUTE_2F_GRUNT_3, Route119_WeatherInstitute_2F_Movement_GruntApproachShelly
	applymovement LOCALID_PLAYER, Route119_WeatherInstitute_2F_Movement_ShovePlayerOutOfWay
	waitmovement 0
	msgbox Route119_WeatherInstitute_2F_Text_TeamMagmaJustPassedBy, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_WEATHER_INSTITUTE_2F_SHELLY, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_WEATHER_INSTITUTE_2F_SHELLY, Common_Movement_Delay48
	waitmovement 0
	msgbox Route119_WeatherInstitute_2F_Text_WeHaveToHurryToMtPyre, MSGBOX_DEFAULT
	closemessage
	setvar VAR_WEATHER_INSTITUTE_STATE, 1
	clearflag FLAG_HIDE_WEATHER_INSTITUTE_2F_WORKERS
	fadedefaultbgm
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_ROUTE_119_TEAM_AQUA
	setflag FLAG_HIDE_WEATHER_INSTITUTE_2F_AQUA_GRUNT_M
	removeobject LOCALID_WEATHER_INSTITUTE_2F_GRUNT_1
	removeobject LOCALID_WEATHER_INSTITUTE_2F_GRUNT_2
	removeobject LOCALID_WEATHER_INSTITUTE_2F_SHELLY
	removeobject LOCALID_WEATHER_INSTITUTE_2F_GRUNT_4
	removeobject LOCALID_WEATHER_INSTITUTE_2F_GRUNT_3
	applymovement LOCALID_PLAYER, Route119_WeatherInstitute_2F_Movement_PlayerReturnToPosition
	waitmovement 0
	fadescreen FADE_FROM_BLACK
	applymovement LOCALID_WEATHER_INSTITUTE_2F_SCIENTIST, Route119_WeatherInstitute_2F_Movement_ScientistApproachPlayer
	waitmovement 0
	copyobjectxytoperm LOCALID_WEATHER_INSTITUTE_2F_SCIENTIST
	goto Route119_WeatherInstitute_2F_EventScript_ReceiveCastform
	end

Route119_WeatherInstitute_2F_EventScript_ReceiveCastform::
	msgbox Route119_WeatherInstitute_2F_Text_ThanksPleaseTakePokemon, MSGBOX_DEFAULT
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_CASTFORM
	givemon SPECIES_CASTFORM, 25, ITEM_MYSTIC_WATER
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, Route119_WeatherInstitute_2F_EventScript_ReceiveCastformParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, Route119_WeatherInstitute_2F_EventScript_ReceiveCastformPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

Route119_WeatherInstitute_2F_EventScript_ReceiveCastformParty::
	call Route119_WeatherInstitute_2F_EventScript_ReceivedCastformFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route119_WeatherInstitute_2F_EventScript_ExplainCastform
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto Route119_WeatherInstitute_2F_EventScript_ExplainCastform
	end

Route119_WeatherInstitute_2F_EventScript_ReceiveCastformPC::
	call Route119_WeatherInstitute_2F_EventScript_ReceivedCastformFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route119_WeatherInstitute_2F_EventScript_SendCastformToPC
	call Common_EventScript_NameReceivedBoxMon
	goto Route119_WeatherInstitute_2F_EventScript_SendCastformToPC
	end

Route119_WeatherInstitute_2F_EventScript_SendCastformToPC::
	call Common_EventScript_TransferredToPC
	goto Route119_WeatherInstitute_2F_EventScript_ExplainCastform
	end

Route119_WeatherInstitute_2F_EventScript_ReceivedCastformFanfare::
	playfanfare MUS_OBTAIN_ITEM
	message Route119_WeatherInstitute_2F_Text_PlayerReceivedCastform
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_CASTFORM
	return

Route119_WeatherInstitute_2F_EventScript_ExplainCastform::
	msgbox Route119_WeatherInstitute_2F_Text_PokemonChangesWithWeather, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_CASTFORM
	release
	end

Route119_WeatherInstitute_2F_EventScript_ScientistMentionWeather::
	goto_if_set FLAG_SYS_GAME_CLEAR, Route119_WeatherInstitute_2F_EventScript_TryStartAbnormalWeather
	msgbox Route119_WeatherInstitute_2F_Text_ChangingWeatherRidiculous, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_2F_EventScript_TryStartAbnormalWeather::
	setvar VAR_0x8004, 0
	call_if_set FLAG_DEFEATED_KYOGRE, Route119_WeatherInstitute_2F_EventScript_LegendaryDefeated
	call_if_set FLAG_DEFEATED_GROUDON, Route119_WeatherInstitute_2F_EventScript_LegendaryDefeated
	goto_if_eq VAR_0x8004, 2, Route119_WeatherInstitute_2F_EventScript_NoAbnormalWeather  @ Both defeated
	call_if_unset FLAG_TEMP_2, Route119_WeatherInstitute_2F_EventScript_CreateAbnormalWeather
	specialvar VAR_RESULT, GetAbnormalWeatherMapNameAndType
	goto_if_eq VAR_RESULT, 1, Route119_WeatherInstitute_2F_EventScript_KyogreWeather
	msgbox Route119_WeatherInstitute_2F_Text_GroudonWeather, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_2F_EventScript_KyogreWeather::
	msgbox Route119_WeatherInstitute_2F_Text_KyogreWeather, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_2F_EventScript_CreateAbnormalWeather::
	special CreateAbnormalWeatherEvent
	setflag FLAG_TEMP_2
	return

Route119_WeatherInstitute_2F_EventScript_LegendaryDefeated::
	addvar VAR_0x8004, 1
	return

Route119_WeatherInstitute_2F_EventScript_NoAbnormalWeather::
	msgbox Route119_WeatherInstitute_2F_Text_NoAbnormalWeather, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_2F_Movement_GruntApproachShelly:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

Route119_WeatherInstitute_2F_Movement_ShovePlayerOutOfWay:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	ride_water_current_up
	walk_in_place_faster_down
	step_end

Route119_WeatherInstitute_2F_Movement_PlayerReturnToPosition:
	slide_down
	walk_in_place_faster_left
	step_end

Route119_WeatherInstitute_2F_Movement_ScientistApproachPlayer:
	walk_right
	walk_right
	walk_right
	step_end

Route119_WeatherInstitute_2F_EventScript_WeatherScientist::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_CASTFORM, Route119_WeatherInstitute_2F_EventScript_ScientistMentionWeather
	goto Route119_WeatherInstitute_2F_EventScript_ReceiveCastform
	end

Route119_WeatherInstitute_2F_Text_Grunt2Intro:
	.string "INSTITUTE đã tạo ra một loài POKéMON\n"
	.string "có liên quan đến thời tiết. Bọn ta đến\l"
	.string "đây để bắt chúng!$"

Route119_WeatherInstitute_2F_Text_Grunt2Defeat:
	.string "Kế hoạch của bọn ta lại bị một đứa nhóc\n"
	.string "phá hỏng sao?$"

Route119_WeatherInstitute_2F_Text_Grunt2PostBattle:
	.string "Nếu POKéMON được tạo ra ở đây có thể\n"
	.string "tự do điều khiển thời tiết thì TEAM\l"
	.string "AQUA bọn ta nhất định phải có nó!$"

Route119_WeatherInstitute_2F_Text_Grunt3Intro:
	.string "Bọn ta là TEAM AQUA! Nơi nào phát hiện\n"
	.string "thứ quý hiếm, nơi đó bọn ta xuất hiện!$"

Route119_WeatherInstitute_2F_Text_Grunt3Defeat:
	.string "Ngươi hạ được ta rồi!$"

Route119_WeatherInstitute_2F_Text_Grunt3PostBattle:
	.string "Ngươi chẳng biết TEAM AQUA bọn ta đang\n"
	.string "hướng tới điều gì đâu! Đừng cản\l"
	.string "đường bọn ta!$"

Route119_WeatherInstitute_2F_Text_Grunt5Intro:
	.string "Đừng nói là nhóc cũng đang tìm POKéMON\n"
	.string "thời tiết đó nhé?\p"
	.string "Không được đâu! Bọn ta đến đây lấy nó\n"
	.string "trước rồi!$"

Route119_WeatherInstitute_2F_Text_Grunt5Defeat:
	.string "Ôi, nhìn POKéMON của ta xem kìa?$"

Route119_WeatherInstitute_2F_Text_Grunt5PostBattle:
	.string "Hừ, thì sao chứ? Thứ bọn ta muốn...\p"
	.string "Thứ bọn ta thật sự muốn không có ở\n"
	.string "đây... Hihihihi...$"

Route119_WeatherInstitute_2F_Text_ShellyIntro:
	.string "Ahahaha!\p"
	.string "Nhóc định xen vào chuyện của TEAM AQUA\n"
	.string "sao?\p"
	.string "Hoặc là nhóc hoàn toàn không biết sợ,\n"
	.string "hoặc quá ngây thơ, hoặc cả hai!\p"
	.string "Nhóc đáng yêu đến phát ghét! Ta sẽ hạ\n"
	.string "nhóc ngay!$"

Route119_WeatherInstitute_2F_Text_ShellyDefeat:
	.string "Ahahaha! Nhóc mạnh đến phát ghét!$"

Route119_WeatherInstitute_2F_Text_ShellyPostBattle:
	.string "TEAM MAGMA phá phách lung tung đã đủ\n"
	.string "phiền rồi, giờ lại thêm nhóc nữa!\p"
	.string "Mà sao nhóc cứ thích chõ mũi vào\n"
	.string "chuyện của bọn ta thế?$"

Route119_WeatherInstitute_2F_Text_TeamMagmaJustPassedBy:
	.string "Có chuyện rồi!\p"
	.string "Một nhóm TEAM MAGMA vừa đi ngang qua\n"
	.string "WEATHER INSTITUTE.\p"
	.string "Có vẻ chúng đang tiến về MT. PYRE!$"

Route119_WeatherInstitute_2F_Text_WeHaveToHurryToMtPyre:
	.string "Cái gì?!\p"
	.string "Không thể lãng phí thêm thời gian ở\n"
	.string "đây! Chúng ta cũng phải mau đến MT.\l"
	.string "PYRE!\p"
	.string "Ahahaha! TEAM MAGMA, cứ chờ đấy!$"

Route119_WeatherInstitute_2F_Text_ThanksPleaseTakePokemon:
	.string "Cảm ơn! Nhờ có bạn mà chúng tôi được\n"
	.string "an toàn!\p"
	.string "Cách cảm ơn này có thể hơi kỳ lạ, nhưng\n"
	.string "hãy nhận lấy POKéMON này.$"

@ Unused
Route119_WeatherInstitute_2F_Text_NoRoomForPokemon:
	.string "Hmm? Có vẻ bạn không còn chỗ cho\n"
	.string "POKéMON này.$"

Route119_WeatherInstitute_2F_Text_PlayerReceivedCastform:
	.string "{PLAYER} đã nhận CASTFORM!$"

Route119_WeatherInstitute_2F_Text_PokemonChangesWithWeather:
	.string "POKéMON đó thay đổi hình dạng tùy theo\n"
	.string "điều kiện thời tiết.\p"
	.string "Trong INSTITUTE còn rất nhiều, bạn cứ\n"
	.string "nhận lấy con này đi.$"

Route119_WeatherInstitute_2F_Text_ChangingWeatherRidiculous:
	.string "Tôi đã nghiên cứu mưa suốt nhiều năm,\n"
	.string "nhưng cho rằng con người có thể tùy ý\l"
	.string "thay đổi thời tiết thì thật nực cười.$"

Route119_WeatherInstitute_2F_Text_GroudonWeather:
	.string "Tôi theo dõi các kiểu thời tiết trên\n"
	.string "toàn vùng HOENN.\p"
	.string "Hiện tại, một đợt hạn hán đã được ghi\n"
	.string "nhận tại {STR_VAR_1}.\p"
	.string "Chẳng lẽ ở đâu đó gần\n"
	.string "{STR_VAR_1}...$"

Route119_WeatherInstitute_2F_Text_KyogreWeather:
	.string "Tôi theo dõi các kiểu thời tiết trên\n"
	.string "toàn vùng HOENN.\p"
	.string "Hiện tại, mưa lớn đã được ghi nhận tại\n"
	.string "{STR_VAR_1}.\p"
	.string "Chẳng lẽ ở đâu đó gần\n"
	.string "{STR_VAR_1}...$"

Route119_WeatherInstitute_2F_Text_NoAbnormalWeather:
	.string "Không còn báo cáo nào về tình trạng\n"
	.string "thời tiết bất thường nữa.\p"
	.string "Thật ra, những cơn mưa thỉnh thoảng\n"
	.string "kéo đến cũng là một điều may mắn.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global Route119_WeatherInstitute_2F_Text_Grunt2Intro
	.global Route119_WeatherInstitute_2F_Text_Grunt2Defeat
	.global Route119_WeatherInstitute_2F_Text_Grunt2PostBattle
	.global Route119_WeatherInstitute_2F_Text_Grunt3Intro
	.global Route119_WeatherInstitute_2F_Text_Grunt3Defeat
	.global Route119_WeatherInstitute_2F_Text_Grunt3PostBattle
	.global Route119_WeatherInstitute_2F_Text_Grunt5Intro
	.global Route119_WeatherInstitute_2F_Text_Grunt5Defeat
	.global Route119_WeatherInstitute_2F_Text_Grunt5PostBattle
	.global Route119_WeatherInstitute_2F_Text_ShellyIntro
	.global Route119_WeatherInstitute_2F_Text_ShellyDefeat
	.global Route119_WeatherInstitute_2F_Text_ShellyPostBattle
	.global Route119_WeatherInstitute_2F_Text_TeamMagmaJustPassedBy
	.global Route119_WeatherInstitute_2F_Text_WeHaveToHurryToMtPyre
	.global Route119_WeatherInstitute_2F_Text_ThanksPleaseTakePokemon
	.global Route119_WeatherInstitute_2F_Text_NoRoomForPokemon
	.global Route119_WeatherInstitute_2F_Text_PlayerReceivedCastform
	.global Route119_WeatherInstitute_2F_Text_PokemonChangesWithWeather
	.global Route119_WeatherInstitute_2F_Text_ChangingWeatherRidiculous
	.global Route119_WeatherInstitute_2F_Text_GroudonWeather
	.global Route119_WeatherInstitute_2F_Text_KyogreWeather
	.global Route119_WeatherInstitute_2F_Text_NoAbnormalWeather
@ END GENERATED LOCALIZATION EXPORTS
