EverGrandeCity_ChampionsRoom_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_ChampionsRoom_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_ChampionsRoom_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_ChampionsRoom_OnFrame
	.byte 0

EverGrandeCity_ChampionsRoom_OnTransition:
	call Common_EventScript_SetupRivalGfxId
	end

EverGrandeCity_ChampionsRoom_OnWarp:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_ChampionsRoom_EventScript_PlayerTurnNorth
	.2byte 0

EverGrandeCity_ChampionsRoom_EventScript_PlayerTurnNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

EverGrandeCity_ChampionsRoom_OnFrame:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_ChampionsRoom_EventScript_EnterRoom
	.2byte 0

EverGrandeCity_ChampionsRoom_EventScript_EnterRoom::
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_WalkUp4
	waitmovement 0
	delay 40
	applymovement LOCALID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerApproachWallace
	waitmovement 0
	setvar VAR_TEMP_1, 1
	goto EverGrandeCity_ChampionsRoom_EventScript_Wallace
	releaseall
	end

EverGrandeCity_ChampionsRoom_Movement_PlayerApproachWallace:
	walk_up
	walk_up
	step_end

EverGrandeCity_ChampionsRoom_EventScript_Wallace::
	playbgm MUS_ENCOUNTER_CHAMPION, FALSE
	msgbox EverGrandeCity_ChampionsRoom_Text_IntroSpeech, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WALLACE, EverGrandeCity_ChampionsRoom_Text_Defeat
	goto EverGrandeCity_ChampionsRoom_EventScript_Defeated
	end

EverGrandeCity_ChampionsRoom_EventScript_Defeated::
	playse SE_DOOR
	setmetatile 6, 1, METATILE_EliteFour_OpenDoorChampion_Frame, FALSE
	setmetatile 6, 2, METATILE_EliteFour_OpenDoorChampion_Opening, FALSE
	special DrawWholeMapView
	msgbox EverGrandeCity_ChampionsRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	closemessage
	playse SE_DOOR
	checkplayergender
	call_if_eq VAR_RESULT, MALE, EverGrandeCity_ChampionsRoom_EventScript_PlayMayMusic
	call_if_eq VAR_RESULT, FEMALE, EverGrandeCity_ChampionsRoom_EventScript_PlayBrendanMusic
	addobject LOCALID_CHAMPIONS_ROOM_RIVAL
	call EverGrandeCity_ChampionsRoom_EventScript_RivalApproachPlayer
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, EverGrandeCity_ChampionsRoom_EventScript_MayAdvice
	goto_if_eq VAR_RESULT, FEMALE, EverGrandeCity_ChampionsRoom_EventScript_BrendanAdvice
	end

EverGrandeCity_ChampionsRoom_EventScript_PlayMayMusic::
	playbgm MUS_ENCOUNTER_MAY, FALSE
	return

EverGrandeCity_ChampionsRoom_EventScript_PlayBrendanMusic::
	playbgm MUS_ENCOUNTER_BRENDAN, FALSE
	return

EverGrandeCity_ChampionsRoom_EventScript_MayAdvice::
	msgbox EverGrandeCity_ChampionsRoom_Text_MayAdvice, MSGBOX_DEFAULT
	delay 40
	playse SE_PIN
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, Common_Movement_Delay48
	waitmovement 0
	call EverGrandeCity_ChampionsRoom_EventScript_RivalLookBackAndForth
	msgbox EverGrandeCity_ChampionsRoom_Text_MayItsAlreadyOver, MSGBOX_DEFAULT
	goto EverGrandeCity_ChampionsRoom_EventScript_BirchArrivesExitForHoF
	end

EverGrandeCity_ChampionsRoom_EventScript_BrendanAdvice::
	msgbox EverGrandeCity_ChampionsRoom_Text_BrendanAdvice, MSGBOX_DEFAULT
	delay 40
	playse SE_PIN
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, Common_Movement_Delay48
	waitmovement 0
	call EverGrandeCity_ChampionsRoom_EventScript_RivalLookBackAndForth
	msgbox EverGrandeCity_ChampionsRoom_Text_BrendanYouveWon, MSGBOX_DEFAULT
	goto EverGrandeCity_ChampionsRoom_EventScript_BirchArrivesExitForHoF
	end

EverGrandeCity_ChampionsRoom_EventScript_BirchArrivesExitForHoF::
	closemessage
	addobject LOCALID_CHAMPIONS_ROOM_BIRCH
	applymovement LOCALID_CHAMPIONS_ROOM_BIRCH, EverGrandeCity_ChampionsRoom_Movement_BirchArrives
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox EverGrandeCity_ChampionsRoom_Text_BirchArriveRatePokedex, MSGBOX_DEFAULT
	call ProfBirch_EventScript_RatePokedex
	msgbox EverGrandeCity_ChampionsRoom_Text_BirchCongratulations, MSGBOX_DEFAULT
	applymovement LOCALID_CHAMPIONS_ROOM_WALLACE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 20
	applymovement LOCALID_CHAMPIONS_ROOM_WALLACE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox EverGrandeCity_ChampionsRoom_Text_WallaceComeWithMe, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_CHAMPIONS_ROOM_WALLACE, EverGrandeCity_ChampionsRoom_Movement_WallaceExitStart
	applymovement LOCALID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerExitStart
	applymovement LOCALID_CHAMPIONS_ROOM_BIRCH, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, EverGrandeCity_ChampionsRoom_Movement_RivalFollows
	waitmovement 0
	delay 20
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox EverGrandeCity_ChampionsRoom_Text_WallaceWaitOutside, MSGBOX_DEFAULT
	checkplayergender
	call_if_eq VAR_RESULT, MALE, EverGrandeCity_ChampionsRoom_EventScript_MayCongratulations
	call_if_eq VAR_RESULT, FEMALE, EverGrandeCity_ChampionsRoom_EventScript_BrendanCongratulations
	closemessage
	applymovement LOCALID_CHAMPIONS_ROOM_WALLACE, EverGrandeCity_ChampionsRoom_Movement_WallaceExit
	applymovement LOCALID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerExit
	waitmovement 0
	setflag FLAG_HIDE_PETALBURG_GYM_GREETER
	warp MAP_EVER_GRANDE_CITY_HALL_OF_FAME, 7, 16
	waitstate
	releaseall
	end

EverGrandeCity_ChampionsRoom_EventScript_MayCongratulations::
	msgbox EverGrandeCity_ChampionsRoom_Text_MayCongratulations, MSGBOX_DEFAULT
	return

EverGrandeCity_ChampionsRoom_EventScript_BrendanCongratulations::
	msgbox EverGrandeCity_ChampionsRoom_Text_BrendanCongratulations, MSGBOX_DEFAULT
	return

EverGrandeCity_ChampionsRoom_EventScript_RivalApproachPlayer::
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, EverGrandeCity_ChampionsRoom_Movement_RivalApproachPlayer
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

EverGrandeCity_ChampionsRoom_EventScript_RivalLookBackAndForth::
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, EverGrandeCity_ChampionsRoom_Movement_RivalLookBackAndForth
	waitmovement 0
	return

EverGrandeCity_ChampionsRoom_Movement_PlayerExitStart:
	walk_up
	walk_up
	step_end

EverGrandeCity_ChampionsRoom_Movement_PlayerExit:
	walk_up
	delay_16
	walk_up
	delay_8
	set_invisible
	step_end

EverGrandeCity_ChampionsRoom_Movement_RivalApproachPlayer:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_up
	walk_in_place_faster_right
	step_end

EverGrandeCity_ChampionsRoom_Movement_RivalLookBackAndForth:
	walk_in_place_faster_up
	delay_16
	walk_in_place_faster_right
	delay_16
	walk_in_place_faster_up
	delay_8
	walk_in_place_faster_right
	delay_16
	step_end

EverGrandeCity_ChampionsRoom_Movement_RivalFollows:
	walk_right
	walk_up
	step_end

EverGrandeCity_ChampionsRoom_Movement_WallaceExitStart:
	walk_up
	walk_up
	walk_in_place_faster_down
	step_end

EverGrandeCity_ChampionsRoom_Movement_WallaceExit:
	walk_up
	delay_8
	set_invisible
	step_end

EverGrandeCity_ChampionsRoom_Movement_BirchArrives:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_in_place_faster_left
	step_end

EverGrandeCity_ChampionsRoom_Text_IntroSpeech:
	.string "WALLACE: Chào mừng, {PLAYER}{KUN}.\p"
	.string "Chuyện xảy ra ở SOOTOPOLIS CITY... Cậu\n"
	.string "đã làm rất xuất sắc khi tự mình chấm\l"
	.string "dứt cuộc khủng hoảng ấy.\p"
	.string "Ấy!\p"
	.string "Nói rằng một mình cậu đã chấm dứt\n"
	.string "khủng hoảng thì không công bằng.\p"
	.string "Cậu đã vượt qua tình thế khó khăn ấy\n"
	.string "nhờ đồng lòng với POKéMON của mình.\p"
	.string "HLV chúng ta nuôi dưỡng POKéMON\n"
	.string "bằng cách cho chúng dùng vật phẩm và\l"
	.string "dạy chúng những kỹ thuật chiến đấu\l"
	.string "mới.\p"
	.string "Nhưng chính chúng ta cũng học được\n"
	.string "rất nhiều điều từ POKéMON.\p"
	.string "Và đây là nơi thành tựu của cậu được\n"
	.string "thử thách trước thành tựu của những\l"
	.string "người giống như cậu.\p"
	.string "Nào!\p"
	.string "Ai có thể cùng POKéMON của mình tạo nên\n"
	.string "vũ điệu thanh nhã nhất HOENN?\p"
	.string "Hãy cho tôi thấy ngay tại đây!$"

EverGrandeCity_ChampionsRoom_Text_Defeat:
	.string "Ta, CHAMPION, đã bại trận...\p"
	.string "Cậu đã làm rất tuyệt vời. Cậu thanh nhã\n"
	.string "đến mức khiến tôi phát bực, vậy mà vẫn\l"
	.string "huy hoàng vô cùng!\p"
	.string "Xin chúc mừng, {PLAYER}{KUN}!\p"
	.string "Cậu là một HLV POKéMON thực sự\n"
	.string "cao quý!$"

EverGrandeCity_ChampionsRoom_Text_PostBattleSpeech:
	.string "WALLACE: Những POKéMON cậu đưa vào\n"
	.string "chiến đấu...\p"
	.string "Có lúc chúng nhảy múa như làn gió xuân,\n"
	.string "có lúc lại ra đòn như sấm sét.\p"
	.string "Cậu dẫn dắt POKéMON của mình với sự\n"
	.string "thanh nhã nhẹ nhàng nhưng vô cùng\l"
	.string "vững vàng.\p"
	.string "Ngay cả tôi cũng bị choáng ngợp trước\n"
	.string "màn trình diễn điêu luyện của cậu!\p"
	.string "Giờ đây, cậu đang đứng trên đỉnh vinh\n"
	.string "quang của POKéMON LEAGUE.\p"
	.string "Tôi xin tuyên bố cậu là người mới của\n"
	.string "vùng HOENN...$"

EverGrandeCity_ChampionsRoom_Text_MayAdvice:
	.string "MAY: {PLAYER}{KUN}!\p"
	.string "Tớ có vài lời khuyên trước khi cậu\n"
	.string "thách đấu CHAMPION...$"

EverGrandeCity_ChampionsRoom_Text_MayItsAlreadyOver:
	.string "MAY: Hả? Gì, gì, gì cơ?\p"
	.string "{PLAYER}{KUN}... Chẳng lẽ... Mọi chuyện\n"
	.string "đã kết thúc rồi sao?$"

EverGrandeCity_ChampionsRoom_Text_BrendanAdvice:
	.string "BRENDAN: {PLAYER}!\p"
	.string "Cậu có muốn nghe vài lời khuyên trước\n"
	.string "khi thách đấu CHAMPION không?...$"

EverGrandeCity_ChampionsRoom_Text_BrendanYouveWon:
	.string "BRENDAN: {PLAYER}...\p"
	.string "Ý cậu là... Cậu đã đánh bại CHAMPION rồi\n"
	.string "sao?$"

EverGrandeCity_ChampionsRoom_Text_BirchArriveRatePokedex:
	.string "PROF. BIRCH: Thấy chưa? Bác đã bảo gì\n"
	.string "nào, {RIVAL}?\p"
	.string "Chẳng phải bác đã nói cháu không cần lo\n"
	.string "cho {PLAYER}{KUN} sao?\p"
	.string "... ... ... ... ... ... ... ... {PLAYER}{KUN}, cuối\n"
	.string "cùng cháu cũng làm được rồi.\p"
	.string "Khi nghe tin cháu đánh bại chính ba\n"
	.string "mình tại PETALBURG GYM, bác đã nghĩ có\l"
	.string "lẽ cháu có cơ hội...\p"
	.string "Nhưng không ngờ cháu thực sự trở\n"
	.string "thành CHAMPION!\p"
	.string "À, phải rồi!\p"
	.string "POKéDEX của cháu thế nào rồi? Đưa bác\n"
	.string "xem nào.$"

EverGrandeCity_ChampionsRoom_Text_BirchCongratulations:
	.string "PROF. BIRCH: Dù sao thì cũng xin chúc\n"
	.string "mừng!\p"
	.string "Giờ hãy tự hào bước vào căn phòng cuối\n"
	.string "cùng đi!$"

EverGrandeCity_ChampionsRoom_Text_WallaceComeWithMe:
	.string "WALLACE: {PLAYER}{KUN}...\p"
	.string "Không, để tôi gọi lại cho đúng.\p"
	.string "Tân CHAMPION!\p"
	.string "Hãy đi cùng tôi.$"

EverGrandeCity_ChampionsRoom_Text_WallaceWaitOutside:
	.string "WALLACE: Tôi xin lỗi, nhưng...\p"
	.string "Từ đây trở đi, chỉ những HLV đã\n"
	.string "trở thành CHAMPIONS mới được phép\l"
	.string "vào.\p"
	.string "Cậu sẽ phải chờ bên ngoài cùng PROF.\n"
	.string "BIRCH.$"

EverGrandeCity_ChampionsRoom_Text_MayCongratulations:
	.string "MAY: Hừm...\p"
	.string "... ... ... ... ... ... ... ... ... ... ... ... ... ... ... ...\p"
	.string "Tớ đùa thôi! Không sao đâu! Luật là vậy\n"
	.string "mà!\p"
	.string "{PLAYER}{KUN}! Thật lòng chúc mừng\n"
	.string "cậu!$"

EverGrandeCity_ChampionsRoom_Text_BrendanCongratulations:
	.string "BRENDAN: Cááái gì?! ... ... ... ... ... ... ... ...\n"
	.string "... ... ... ... ...\p"
	.string "Nếu luật là vậy thì đành chịu thôi.\p"
	.string "{PLAYER}, cậu làm tốt lắm! Chúc mừng!$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global EverGrandeCity_ChampionsRoom_Text_IntroSpeech
	.global EverGrandeCity_ChampionsRoom_Text_Defeat
	.global EverGrandeCity_ChampionsRoom_Text_PostBattleSpeech
	.global EverGrandeCity_ChampionsRoom_Text_MayAdvice
	.global EverGrandeCity_ChampionsRoom_Text_MayItsAlreadyOver
	.global EverGrandeCity_ChampionsRoom_Text_BrendanAdvice
	.global EverGrandeCity_ChampionsRoom_Text_BrendanYouveWon
	.global EverGrandeCity_ChampionsRoom_Text_BirchArriveRatePokedex
	.global EverGrandeCity_ChampionsRoom_Text_BirchCongratulations
	.global EverGrandeCity_ChampionsRoom_Text_WallaceComeWithMe
	.global EverGrandeCity_ChampionsRoom_Text_WallaceWaitOutside
	.global EverGrandeCity_ChampionsRoom_Text_MayCongratulations
	.global EverGrandeCity_ChampionsRoom_Text_BrendanCongratulations
@ END GENERATED LOCALIZATION EXPORTS
