SootopolisCity_Gym_1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SootopolisCity_Gym_1F_OnFrame
	map_script MAP_SCRIPT_ON_RESUME, SootopolisCity_Gym_1F_OnResume
	map_script MAP_SCRIPT_ON_LOAD, SootopolisCity_Gym_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, SootopolisCity_Gym_1F_OnTransition
	.byte 0

SootopolisCity_Gym_1F_OnTransition:
	setvar VAR_ICE_STEP_COUNT, 1
	end

SootopolisCity_Gym_1F_OnResume:
	setstepcallback STEP_CB_SOOTOPOLIS_ICE
	end

SootopolisCity_Gym_1F_OnLoad:
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special SetSootopolisGymCrackedIceMetatiles
	end

SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles::
	goto_if_lt VAR_ICE_STEP_COUNT, 8, SootopolisCity_Gym_1F_EventScript_StopCheckingStairs  @ All stairs ice
	goto_if_lt VAR_ICE_STEP_COUNT, 28, SootopolisCity_Gym_1F_EventScript_OpenFirstStairs
	goto_if_lt VAR_ICE_STEP_COUNT, 67, SootopolisCity_Gym_1F_EventScript_OpenFirstAndSecondStairs
	setmetatile 8, 4, METATILE_SootopolisGym_Stairs, FALSE
	setmetatile 8, 5, METATILE_SootopolisGym_Stairs, FALSE
SootopolisCity_Gym_1F_EventScript_OpenFirstAndSecondStairs::
	setmetatile 8, 10, METATILE_SootopolisGym_Stairs, FALSE
	setmetatile 8, 11, METATILE_SootopolisGym_Stairs, FALSE
SootopolisCity_Gym_1F_EventScript_OpenFirstStairs::
	setmetatile 8, 15, METATILE_SootopolisGym_Stairs, FALSE
	setmetatile 8, 16, METATILE_SootopolisGym_Stairs, FALSE
SootopolisCity_Gym_1F_EventScript_StopCheckingStairs::
	return

SootopolisCity_Gym_1F_OnFrame:
	map_script_2 VAR_ICE_STEP_COUNT, 8, SootopolisCity_Gym_1F_EventScript_UnlockFirstStairs
	map_script_2 VAR_ICE_STEP_COUNT, 28, SootopolisCity_Gym_1F_EventScript_UnlockSecondStairs
	map_script_2 VAR_ICE_STEP_COUNT, 67, SootopolisCity_Gym_1F_EventScript_UnlockThirdStairs
	map_script_2 VAR_ICE_STEP_COUNT, 0, SootopolisCity_Gym_1F_EventScript_FallThroughIce
	.2byte 0

SootopolisCity_Gym_1F_EventScript_UnlockFirstStairs::
	addvar VAR_ICE_STEP_COUNT, 1
	delay 40
	playse SE_ICE_STAIRS
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special DrawWholeMapView
	end

SootopolisCity_Gym_1F_EventScript_UnlockSecondStairs::
	addvar VAR_ICE_STEP_COUNT, 1
	delay 40
	playse SE_ICE_STAIRS
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special DrawWholeMapView
	end

SootopolisCity_Gym_1F_EventScript_UnlockThirdStairs::
	addvar VAR_ICE_STEP_COUNT, 1
	delay 40
	playse SE_ICE_STAIRS
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special DrawWholeMapView
	end

SootopolisCity_Gym_1F_EventScript_FallThroughIce::
	lockall
	delay 20
	applymovement LOCALID_PLAYER, SootopolisCity_Gym_1F_Movement_FallThroughIce
	waitmovement 0
	playse SE_FALL
	delay 60
	warphole MAP_SOOTOPOLIS_CITY_GYM_B1F
	waitstate
	end

SootopolisCity_Gym_1F_Movement_FallThroughIce:
	set_invisible
	step_end

SootopolisCity_Gym_1F_EventScript_Juan::
	trainerbattle_single TRAINER_JUAN_1, SootopolisCity_Gym_1F_Text_JuanIntro, SootopolisCity_Gym_1F_Text_JuanDefeat, SootopolisCity_Gym_1F_EventScript_JuanDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, SootopolisCity_Gym_1F_EventScript_JuanRematch
	goto_if_unset FLAG_RECEIVED_TM_WATER_PULSE, SootopolisCity_Gym_1F_EventScript_GiveWaterPulse2
	goto_if_unset FLAG_BADGE06_GET, SootopolisCity_Gym_1F_EventScript_GoGetFortreeBadge
	msgbox SootopolisCity_Gym_1F_Text_JuanPostBattle, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_JuanDefeated::
	message SootopolisCity_Gym_1F_Text_ReceivedRainBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox SootopolisCity_Gym_1F_Text_ExplainRainBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_SOOTOPOLIS_GYM
	setflag FLAG_BADGE08_GET
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_RESIDENTS
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_STEVEN
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_WALLACE
	setvar VAR_SOOTOPOLIS_CITY_STATE, 6
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_MAN_1
	setvar VAR_0x8008, 8
	call Common_EventScript_SetGymTrainers
	call SootopolisCity_Gym_1F_EventScript_GiveWaterPulse
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox SootopolisCity_Gym_1F_Text_RegisteredJuan, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_JUAN_MATCH_CALL
	release
	end

SootopolisCity_Gym_1F_EventScript_GiveWaterPulse::
	giveitem ITEM_TM_WATER_PULSE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox SootopolisCity_Gym_1F_Text_ExplainWaterPulse, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_WATER_PULSE
	return

SootopolisCity_Gym_1F_EventScript_GiveWaterPulse2::
	giveitem ITEM_TM_WATER_PULSE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox SootopolisCity_Gym_1F_Text_ExplainWaterPulse, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_WATER_PULSE
	release
	end

SootopolisCity_Gym_1F_EventScript_GoGetFortreeBadge::
	msgbox SootopolisCity_Gym_1F_Text_GoGetFortreeBadge, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_JuanRematch::
	trainerbattle_rematch_double TRAINER_JUAN_1, SootopolisCity_Gym_1F_Text_JuanPreRematch, SootopolisCity_Gym_1F_Text_JuanRematchDefeat, SootopolisCity_Gym_1F_Text_JuanRematchNeedTwoMons
	msgbox SootopolisCity_Gym_1F_Text_JuanPostRematch, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_1F_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_SOOTOPOLIS_GYM, SootopolisCity_Gym_1F_EventScript_GymGuidePostVictory
	msgbox SootopolisCity_Gym_1F_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_GymGuidePostVictory::
	msgbox SootopolisCity_Gym_1F_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE08_GET, SootopolisCity_Gym_1F_EventScript_GymStatueCertified
	goto SootopolisCity_Gym_1F_EventScript_GymStatue
	end

SootopolisCity_Gym_1F_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE08_GET, SootopolisCity_Gym_1F_EventScript_GymStatueCertified
	goto SootopolisCity_Gym_1F_EventScript_GymStatue
	end

SootopolisCity_Gym_1F_EventScript_GymStatueCertified::
	msgbox SootopolisCity_Gym_1F_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_Gym_1F_EventScript_GymStatue::
	msgbox SootopolisCity_Gym_1F_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_Gym_1F_Text_GymGuideAdvice:
	.string "Chào! Mọi chuyện thế nào, {PLAYER},\n"
	.string "người đang hướng tới ngôi CHAMPION?\p"
	.string "SOOTOPOLIS GYM LEADER JUAN là bậc thầy\n"
	.string "về POKéMON hệ WATER.\p"
	.string "Và để tới được chỗ JUAN, sàn băng sẽ\n"
	.string "cản trở bước tiến của bạn...\p"
	.string "Xin lỗi nhé, nhưng tôi chỉ có thể khuyên\n"
	.string "bạn được đến thế thôi.\p"
	.string "Quãng đường còn lại, bạn phải tự mình\n"
	.string "cố gắng!$"

SootopolisCity_Gym_1F_Text_GymGuidePostVictory:
	.string "Chà! Bạn đã đánh bại cả JUAN, người\n"
	.string "được xem là mạnh nhất HOENN!\p"
	.string "Được rồi! Hãy xem TRAINER CARD của\n"
	.string "bạn.\p"
	.string "Nếu đã thu thập đủ BADGES, bạn đã sẵn\n"
	.string "sàng thách đấu POKéMON LEAGUE!$"

SootopolisCity_Gym_1F_Text_JuanIntro:
	.string "Để ta hỏi ngươi một điều. Ngươi có biết\n"
	.string "không? À, ta không nên úp mở như thế.\p"
	.string "Chính ta là người đã truyền dạy cho\n"
	.string "WALLACE mọi kiến thức về POKéMON.\p"
	.string "Có một thời, ta đã từ bỏ vị trí GYM\n"
	.string "LEADER.\p"
	.string "Ta giao lại GYM cho WALLACE thay mình\n"
	.string "cai quản.\p"
	.string "Tuy nhiên, một lý do không thể chối từ\n"
	.string "đã khiến ta phải trở lại.\p"
	.string "À, nhưng trò chuyện thế là đủ rồi. Chúng\n"
	.string "ta bắt đầu trận đấu nhé?\p"
	.string "Xin hãy chiêm ngưỡng nghệ thuật của\n"
	.string "chúng ta.\p"
	.string "Một ảo cảnh nước tráng lệ được tạc\n"
	.string "nên bởi POKéMON và chính ta!$"

@ NOTE: This defeat text actually causes a buffer overflow. It's about 50 bytes too long for
@ the gDisplayedStringBattle buffer that it's put into, and it stomps all over the gBattleTextBuffs
@ after, as well as the otherwise unused array after that. One wonders if that's the reason for
@ the existence of that unused array of ints.
SootopolisCity_Gym_1F_Text_JuanDefeat:
	.string "Ahahaha, xuất sắc! Được lắm, ngươi là\n"
	.string "người chiến thắng.\p"
	.string "Từ ngươi, ta cảm nhận được ánh sáng\n"
	.string "kỹ năng rực rỡ có thể vượt qua mọi thử\l"
	.string "thách.\p"
	.string "Tuy nhiên, so với ta hay thậm chí\n"
	.string "WALLACE, ngươi vẫn thiếu đôi chút\l"
	.string "thanh lịch.\p"
	.string "Có lẽ ta nên cho ngươi mượn trang phục\n"
	.string "của mình?\p"
	.string "... ... ... ... ... ... ... ... ... ... ... ...\p"
	.string "Hahaha, ta chỉ đùa thôi!\p"
	.string "Thay vì quần áo của ta, ta sẽ trao cho\n"
	.string "ngươi phần thưởng này, RAIN BADGE!$"

SootopolisCity_Gym_1F_Text_ReceivedRainBadge:
	.string "{PLAYER} đã nhận RAIN BADGE từ JUAN.$"

SootopolisCity_Gym_1F_Text_ExplainRainBadgeTakeThis:
	.string "RAIN BADGE sẽ bảo đảm mọi POKéMON của\n"
	.string "ngươi hoàn toàn tuân theo mọi mệnh\l"
	.string "lệnh.\p"
	.string "RAIN BADGE cũng cho phép sử dụng HM\n"
	.string "chiêu WATERFALL để vượt lên những\l"
	.string "vách nước đổ.\p"
	.string "Và để ngươi không bao giờ quên trận\n"
	.string "đấu giữa chúng ta, hãy nhận lấy thứ\l"
	.string "này...$"

SootopolisCity_Gym_1F_Text_ExplainWaterPulse:
	.string "TECHNICAL MACHINE ta trao cho ngươi\n"
	.string "chứa WATER PULSE.\p"
	.string "Khi sử dụng, đôi lúc nó sẽ khiến mục\n"
	.string "tiêu bối rối bằng sóng siêu âm.\p"
	.string "... ... ... ... ... ...$"

SootopolisCity_Gym_1F_Text_RegisteredJuan:
	.string "Đã đăng ký GYM LEADER JUAN vào\n"
	.string "POKéNAV.$"

SootopolisCity_Gym_1F_Text_JuanPostBattle:
	.string "Những HLV đã thu thập đủ GYM\n"
	.string "BADGES của HOENN nên tiến đến đích\l"
	.string "cuối cùng.\p"
	.string "POKéMON LEAGUE.\p"
	.string "Hãy tới vùng cực đông HOENN, đến hòn\n"
	.string "đảo EVER GRANDE.\p"
	.string "Tại đó, ngươi sẽ tìm thấy POKéMON\n"
	.string "LEAGUE.$"

SootopolisCity_Gym_1F_Text_GoGetFortreeBadge:
	.string "Ở HOENN vẫn còn một BADGE ngươi chưa\n"
	.string "giành được.\p"
	.string "Nếu muốn thách đấu POKéMON LEAGUE,\n"
	.string "ngươi phải lấy BADGE cuối cùng từ GYM\l"
	.string "ở FORTREE.$"

SootopolisCity_Gym_1F_Text_GymStatue:
	.string "SOOTOPOLIS CITY POKéMON GYM$"

SootopolisCity_Gym_1F_Text_GymStatueCertified:
	.string "SOOTOPOLIS CITY POKéMON GYM\p"
	.string "JUAN'S CERTIFIED TRAINERS: {PLAYER}$"

SootopolisCity_Gym_1F_Text_JuanPreRematch:
	.string "JUAN: À, GYM này vừa trở lại vẻ thanh\n"
	.string "bình vốn có...\p"
	.string "Nhưng cơn cuồng phong trẻ tuổi của\n"
	.string "chúng ta đã quay lại để thử thách mọi\l"
	.string "người lần nữa!\p"
	.string "Được thôi, bạn của ta, tất nhiên rồi!\p"
	.string "Ta rất vui lòng khiêu vũ cùng ngươi bao\n"
	.string "nhiêu lần tùy thích!$"

SootopolisCity_Gym_1F_Text_JuanRematchDefeat:
	.string "Ahahaha, ngươi đã thắng! Ngươi lại\n"
	.string "đánh bại ta rồi!$"

SootopolisCity_Gym_1F_Text_JuanPostRematch:
	.string "JUAN: Nếu ta bảo ngươi trở thành học\n"
	.string "trò của mình, chắc chắn ngươi sẽ từ\l"
	.string "chối.\p"
	.string "Ta muốn tặng chiếc áo khoác của mình\n"
	.string "cho ngươi.\p"
	.string "Nhưng một lần nữa, ngươi cũng sẽ từ\n"
	.string "chối. Ta đoán là vậy.\p"
	.string "Và điều đó, bạn của ta, chính là dấu\n"
	.string "hiệu rõ ràng của khí chất cao quý!$"

SootopolisCity_Gym_1F_Text_JuanRematchNeedTwoMons:
	.string "JUAN: À, GYM này vừa trở lại vẻ thanh\n"
	.string "bình vốn có...\p"
	.string "Nhưng cơn cuồng phong trẻ tuổi của\n"
	.string "chúng ta đã quay lại để thử thách mọi\l"
	.string "người lần nữa!\p"
	.string "Được thôi, bạn của ta, tất nhiên rồi! Ta\n"
	.string "rất vui lòng khiêu vũ cùng ngươi...\p"
	.string "À, không, không, không. Ngươi chỉ mang\n"
	.string "theo một POKéMON.\p"
	.string "Xin hãy quay lại cùng hai POKéMON, hoặc\n"
	.string "nhiều hơn.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global SootopolisCity_Gym_1F_Text_GymGuideAdvice
	.global SootopolisCity_Gym_1F_Text_GymGuidePostVictory
	.global SootopolisCity_Gym_1F_Text_JuanIntro
	.global SootopolisCity_Gym_1F_Text_JuanDefeat
	.global SootopolisCity_Gym_1F_Text_ReceivedRainBadge
	.global SootopolisCity_Gym_1F_Text_ExplainRainBadgeTakeThis
	.global SootopolisCity_Gym_1F_Text_ExplainWaterPulse
	.global SootopolisCity_Gym_1F_Text_RegisteredJuan
	.global SootopolisCity_Gym_1F_Text_JuanPostBattle
	.global SootopolisCity_Gym_1F_Text_GoGetFortreeBadge
	.global SootopolisCity_Gym_1F_Text_GymStatueCertified
	.global SootopolisCity_Gym_1F_Text_JuanPreRematch
	.global SootopolisCity_Gym_1F_Text_JuanRematchDefeat
	.global SootopolisCity_Gym_1F_Text_JuanPostRematch
	.global SootopolisCity_Gym_1F_Text_JuanRematchNeedTwoMons
@ END GENERATED LOCALIZATION EXPORTS
