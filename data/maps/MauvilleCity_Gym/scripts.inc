MauvilleCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MauvilleCity_Gym_OnLoad
	.byte 0

MauvilleCity_Gym_OnLoad:
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_DeactivatePuzzle
	switch VAR_MAUVILLE_GYM_STATE
	case 0, MauvilleCity_Gym_EventScript_UpdateBarriers
	case 1, MauvilleCity_Gym_EventScript_Switch1Pressed
	case 2, MauvilleCity_Gym_EventScript_Switch2Pressed
	case 3, MauvilleCity_Gym_EventScript_Switch3Pressed
	case 4, MauvilleCity_Gym_EventScript_Switch4Pressed
	end

MauvilleCity_Gym_EventScript_UpdateBarriers::
	goto_if_set FLAG_MAUVILLE_GYM_BARRIERS_STATE, MauvilleCity_Gym_EventScript_SetAltBarriers
	end

MauvilleCity_Gym_EventScript_SetAltBarriers::
	setmetatile 3, 11, METATILE_MauvilleGym_RedBeamV1_On, TRUE
	setmetatile 3, 12, METATILE_MauvilleGym_RedBeamV2_On, TRUE
	setmetatile 3, 13, METATILE_MauvilleGym_PoleTop_On, TRUE
	setmetatile 4, 10, METATILE_MauvilleGym_RedBeamH1_On, FALSE
	setmetatile 5, 10, METATILE_MauvilleGym_RedBeamH2_On, FALSE
	setmetatile 4, 11, METATILE_MauvilleGym_RedBeamH3_On, TRUE
	setmetatile 5, 11, METATILE_MauvilleGym_RedBeamH4_On, TRUE
	setmetatile 7, 10, METATILE_MauvilleGym_RedBeamH1_On, FALSE
	setmetatile 8, 10, METATILE_MauvilleGym_RedBeamH2_On, FALSE
	setmetatile 7, 11, METATILE_MauvilleGym_RedBeamH3_On, TRUE
	setmetatile 8, 11, METATILE_MauvilleGym_RedBeamH4_On, TRUE
	setmetatile 4, 13, METATILE_MauvilleGym_GreenBeamH1_Off, FALSE
	setmetatile 5, 13, METATILE_MauvilleGym_GreenBeamH2_Off, FALSE
	setmetatile 4, 14, METATILE_MauvilleGym_GreenBeamH3_Off, FALSE
	setmetatile 5, 14, METATILE_MauvilleGym_GreenBeamH4_Off, FALSE
	setmetatile 1, 10, METATILE_MauvilleGym_GreenBeamH1_Off, FALSE
	setmetatile 2, 10, METATILE_MauvilleGym_GreenBeamH2_Off, FALSE
	setmetatile 1, 11, METATILE_MauvilleGym_GreenBeamH3_Off, FALSE
	setmetatile 2, 11, METATILE_MauvilleGym_GreenBeamH4_Off, FALSE
	setmetatile 6, 8, METATILE_MauvilleGym_PoleBottom_On, TRUE
	setmetatile 6, 9, METATILE_MauvilleGym_FloorTile, FALSE
	setmetatile 6, 10, METATILE_MauvilleGym_PoleTop_Off, FALSE
	setmetatile 4, 6, METATILE_MauvilleGym_GreenBeamH1_Off, FALSE
	setmetatile 5, 6, METATILE_MauvilleGym_GreenBeamH2_Off, FALSE
	setmetatile 4, 7, METATILE_MauvilleGym_GreenBeamH3_Off, FALSE
	setmetatile 5, 7, METATILE_MauvilleGym_GreenBeamH4_Off, FALSE
	end

MauvilleCity_Gym_EventScript_Switch1Pressed::
	setvar VAR_0x8004, 0
	special MauvilleGymPressSwitch
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
	end

MauvilleCity_Gym_EventScript_Switch2Pressed::
	setvar VAR_0x8004, 1
	special MauvilleGymPressSwitch
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
	end

MauvilleCity_Gym_EventScript_Switch3Pressed::
	setvar VAR_0x8004, 2
	special MauvilleGymPressSwitch
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
	end

MauvilleCity_Gym_EventScript_Switch4Pressed::
	setvar VAR_0x8004, 3
	special MauvilleGymPressSwitch
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
	end

MauvilleCity_Gym_EventScript_DeactivatePuzzle::
	special MauvilleGymDeactivatePuzzle
	end

MauvilleCity_Gym_EventScript_Wattson::
	trainerbattle_single TRAINER_WATTSON_1, MauvilleCity_Gym_Text_WattsonIntro, MauvilleCity_Gym_Text_WattsonDefeat, MauvilleCity_Gym_EventScript_WattsonDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_Gym_EventScript_WattsonRematch
	goto_if_unset FLAG_RECEIVED_TM_SHOCK_WAVE, MauvilleCity_Gym_EventScript_GiveShockWave2
	goto_if_eq VAR_NEW_MAUVILLE_STATE, 2, MauvilleCity_Gym_EventScript_CompletedNewMauville
	msgbox MauvilleCity_Gym_Text_WattsonPostBattle, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Gym_EventScript_WattsonDefeated::
	message MauvilleCity_Gym_Text_ReceivedDynamoBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox MauvilleCity_Gym_Text_ExplainDynamoBadgeTakeThis, MSGBOX_DEFAULT
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 3
	clearflag FLAG_HIDE_VERDANTURF_TOWN_SCOTT
	setflag FLAG_DEFEATED_MAUVILLE_GYM
	setflag FLAG_BADGE03_GET
	addvar VAR_PETALBURG_GYM_STATE, 1
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	setvar VAR_0x8008, 3
	call Common_EventScript_SetGymTrainers
	special MauvilleGymDeactivatePuzzle
	special DrawWholeMapView
	playse SE_UNLOCK
	call MauvilleCity_Gym_EventScript_GiveShockWave
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MauvilleCity_Gym_Text_RegisteredWattson, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_WATTSON_MATCH_CALL
	release
	end

MauvilleCity_Gym_EventScript_GiveShockWave2::
	giveitem ITEM_TM_SHOCK_WAVE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox MauvilleCity_Gym_Text_ExplainShockWave, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_SHOCK_WAVE
	release
	end

MauvilleCity_Gym_EventScript_GiveShockWave::
	giveitem ITEM_TM_SHOCK_WAVE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox MauvilleCity_Gym_Text_ExplainShockWave, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_SHOCK_WAVE
	return

MauvilleCity_Gym_EventScript_CompletedNewMauville::
	msgbox MauvilleCity_Gym_Text_WattsonGoForthAndEndeavor, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Gym_EventScript_WattsonRematch::
	trainerbattle_rematch_double TRAINER_WATTSON_1, MauvilleCity_Gym_Text_WattsonPreRematch, MauvilleCity_Gym_Text_WattsonRematchDefeat, MauvilleCity_Gym_Text_WattsonRematchNeedTwoMons
	msgbox MauvilleCity_Gym_Text_WattsonPostRematch, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Switch1::
	lockall
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
	goto_if_eq VAR_MAUVILLE_GYM_STATE, 1, MauvilleCity_Gym_EventScript_SwitchDoNothing
	setvar VAR_MAUVILLE_GYM_STATE, 1
	setvar VAR_0x8004, 0
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
	end

MauvilleCity_Gym_EventScript_Switch2::
	lockall
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
	goto_if_eq VAR_MAUVILLE_GYM_STATE, 2, MauvilleCity_Gym_EventScript_SwitchDoNothing
	setvar VAR_MAUVILLE_GYM_STATE, 2
	setvar VAR_0x8004, 1
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
	end

MauvilleCity_Gym_EventScript_Switch3::
	lockall
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
	goto_if_eq VAR_MAUVILLE_GYM_STATE, 3, MauvilleCity_Gym_EventScript_SwitchDoNothing
	setvar VAR_MAUVILLE_GYM_STATE, 3
	setvar VAR_0x8004, 2
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
	end

MauvilleCity_Gym_EventScript_Switch4::
	lockall
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
	goto_if_eq VAR_MAUVILLE_GYM_STATE, 4, MauvilleCity_Gym_EventScript_SwitchDoNothing
	setvar VAR_MAUVILLE_GYM_STATE, 4
	setvar VAR_0x8004, 3
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
	end

MauvilleCity_Gym_EventScript_PressFloorSwitch::
	special MauvilleGymSetDefaultBarriers
	special MauvilleGymPressSwitch
	special DrawWholeMapView
	playse SE_UNLOCK
	goto_if_set FLAG_MAUVILLE_GYM_BARRIERS_STATE, MauvilleCity_Gym_EventScript_ClearBarriersAltState
	goto_if_unset FLAG_MAUVILLE_GYM_BARRIERS_STATE, MauvilleCity_Gym_EventScript_SetBarriersAltState
	releaseall
	end

MauvilleCity_Gym_EventScript_SwitchDoNothing::
	releaseall
	end

MauvilleCity_Gym_EventScript_SetBarriersAltState::
	setflag FLAG_MAUVILLE_GYM_BARRIERS_STATE
	releaseall
	end

MauvilleCity_Gym_EventScript_ClearBarriersAltState::
	clearflag FLAG_MAUVILLE_GYM_BARRIERS_STATE
	releaseall
	end

MauvilleCity_Gym_EventScript_Kirk::
	trainerbattle_single TRAINER_KIRK, MauvilleCity_Gym_Text_KirkIntro, MauvilleCity_Gym_Text_KirkDefeat
	msgbox MauvilleCity_Gym_Text_KirkPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Shawn::
	trainerbattle_single TRAINER_SHAWN, MauvilleCity_Gym_Text_ShawnIntro, MauvilleCity_Gym_Text_ShawnDefeat
	msgbox MauvilleCity_Gym_Text_ShawnPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Ben::
	trainerbattle_single TRAINER_BEN, MauvilleCity_Gym_Text_BenIntro, MauvilleCity_Gym_Text_BenDefeat
	msgbox MauvilleCity_Gym_Text_BenPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Vivian::
	trainerbattle_single TRAINER_VIVIAN, MauvilleCity_Gym_Text_VivianIntro, MauvilleCity_Gym_Text_VivianDefeat
	msgbox MauvilleCity_Gym_Text_VivianPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Angelo::
	trainerbattle_single TRAINER_ANGELO, MauvilleCity_Gym_Text_AngeloIntro, MauvilleCity_Gym_Text_AngeloDefeat
	msgbox MauvilleCity_Gym_Text_AngeloPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_GymGuidePostVictory
	msgbox MauvilleCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Gym_EventScript_GymGuidePostVictory::
	msgbox MauvilleCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE03_GET, MauvilleCity_Gym_EventScript_GymStatueCertified
	goto MauvilleCity_Gym_EventScript_GymStatue
	end

MauvilleCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE03_GET, MauvilleCity_Gym_EventScript_GymStatueCertified
	goto MauvilleCity_Gym_EventScript_GymStatue
	end

MauvilleCity_Gym_EventScript_GymStatueCertified::
	msgbox MauvilleCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

MauvilleCity_Gym_EventScript_GymStatue::
	msgbox MauvilleCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

MauvilleCity_Gym_Text_GymGuideAdvice:
	.string "Này, mọi chuyện sao rồi, {PLAYER},\n"
	.string "CHAMPION tương lai?\p"
	.string "WATTSON, LEADER của MAUVILLE GYM, sử\n"
	.string "dụng POKéMON hệ ELECTRIC.\p"
	.string "Nếu thách đấu ông ấy bằng POKéMON hệ\n"
	.string "WATER, chúng sẽ bị giật tung! Bzzt!\p"
	.string "Ông ấy còn lắp đầy những cánh cửa điều\n"
	.string "khiển bằng công tắc khắp GYM! Đúng là\l"
	.string "lập dị!\p"
	.string "Nào, cố lên!$"

MauvilleCity_Gym_Text_GymGuidePostVictory:
	.string "Chà, cậu đúng là gây sốc! Cậu đã tiếp\n"
	.string "điện để mở cánh cửa rồi!$"

MauvilleCity_Gym_Text_KirkIntro:
	.string "Linh hồn điện của ta sẽ nghiền tan giấc\n"
	.string "mơ của ngươi, whoa-yeahah!$"

MauvilleCity_Gym_Text_KirkDefeat:
	.string "Đúng là một màn điện giật cắm điện, tăng\n"
	.string "âm và quá tải hết cỡ, anh bạn!$"

MauvilleCity_Gym_Text_KirkPostBattle:
	.string "POKéMON và rock, tất cả nằm ở trái tim,\n"
	.string "whoa-yeah!$"

MauvilleCity_Gym_Text_ShawnIntro:
	.string "Tôi đã được WATTSON rèn luyện! Đừng\n"
	.string "hòng thắng tôi dễ dàng!$"

MauvilleCity_Gym_Text_ShawnDefeat:
	.string "Bị rút phích, tắt điện mất rồi...$"

MauvilleCity_Gym_Text_ShawnPostBattle:
	.string "WATTSON, GYM LEADER của chúng tôi, đã\n"
	.string "sống lâu lắm rồi.\p"
	.string "Ông ấy đã chiến đấu từ trước khi ba\n"
	.string "cậu ra đời cơ, ông già gân ấy đấy.$"

MauvilleCity_Gym_Text_BenIntro:
	.string "GYM này có cả câu đố đấy! Vui không?$"

MauvilleCity_Gym_Text_BenDefeat:
	.string "Thua chẳng vui chút nào...$"

MauvilleCity_Gym_Text_BenPostBattle:
	.string "WATTSON bảo ông ấy thích giăng những\n"
	.string "cái bẫy nhỏ bằng công tắc.$"

MauvilleCity_Gym_Text_VivianIntro:
	.string "Với sức quyến rũ của tôi và các chiêu\n"
	.string "thức của POKéMON, bạn sẽ phải sốc!$"

MauvilleCity_Gym_Text_VivianDefeat:
	.string "Sức mạnh của bạn làm tôi sốc quá!$"

MauvilleCity_Gym_Text_VivianPostBattle:
	.string "Tôi nghe nói WATTSON là người sáng lập\n"
	.string "MAUVILLE.\p"
	.string "Ông ấy đã là HLV từ rất lâu trước\n"
	.string "khi chúng tôi trở thành HLV. Hẳn\l"
	.string "ông ấy biết đủ thứ!$"

MauvilleCity_Gym_Text_AngeloIntro:
	.string "Tôi mê những thứ lấp lánh!$"

MauvilleCity_Gym_Text_AngeloDefeat:
	.string "Ôi... Mắt tôi hoa lên rồi...$"

MauvilleCity_Gym_Text_AngeloPostBattle:
	.string "WATTSON của MAUVILLE GYM có cái trán\n"
	.string "bóng loáng. Nhìn mà tôi vui quá!$"

MauvilleCity_Gym_Text_WattsonIntro:
	.string "Ta đã từ bỏ kế hoạch cải tạo thành phố\n"
	.string "rồi.\p"
	.string "Vì thế, ta dành thời gian làm những cái\n"
	.string "bẫy cửa trong GYM của mình.\p"
	.string "Ồ? Cháu đến đây làm gì?\p"
	.string "Gì cơ? Cháu nói đã vượt qua mọi cánh\n"
	.string "cửa ta giăng bẫy ư?\p"
	.string "Wahahahah! Thú vị thật đấy!\p"
	.string "Vậy thì ta, WATTSON, LEADER của\n"
	.string "MAUVILLE GYM, sẽ cho cháu nếm mùi điện\l"
	.string "giật!$"

MauvilleCity_Gym_Text_WattsonDefeat:
	.string "Wahahahah! Được thôi, ta thua rồi!\p"
	.string "Cháu khiến ta phấn khích đấy! Hãy nhận\n"
	.string "BADGE này!$"

MauvilleCity_Gym_Text_ReceivedDynamoBadge:
	.string "{PLAYER} đã nhận DYNAMO BADGE từ\n"
	.string "WATTSON.$"

MauvilleCity_Gym_Text_ExplainDynamoBadgeTakeThis:
	.string "Có DYNAMO BADGE, POKéMON có thể dùng\n"
	.string "ROCK SMASH ngoài trận đấu.\p"
	.string "Nó cũng sẽ giúp POKéMON của cháu nhanh\n"
	.string "hơn một chút.\p"
	.string "Hừm... Cháu cũng nên nhận thứ này!$"

MauvilleCity_Gym_Text_ExplainShockWave:
	.string "TM34 đó chứa SHOCK WAVE.\p"
	.string "Đây là một chiêu đáng tin cậy, không\n"
	.string "bao giờ trượt! Cháu cứ tin ở nó!\p"
	.string "... ... ... ... ... ...$"

MauvilleCity_Gym_Text_RegisteredWattson:
	.string "Đã đăng ký GYM LEADER WATTSON vào\n"
	.string "POKéNAV.$"

MauvilleCity_Gym_Text_WattsonPostBattle:
	.string "Thấy một HLV trẻ đầy triển vọng\n"
	.string "như cháu, ta tràn trề lạc quan!$"

MauvilleCity_Gym_Text_WattsonGoForthAndEndeavor:
	.string "Wahahahah! Tiến lên và nỗ lực hết mình\n"
	.string "đi, người trẻ!$"

MauvilleCity_Gym_Text_GymStatue:
	.string "MAUVILLE CITY POKéMON GYM$"

MauvilleCity_Gym_Text_GymStatueCertified:
	.string "MAUVILLE CITY POKéMON GYM\p"
	.string "WATTSON'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"

MauvilleCity_Gym_Text_WattsonPreRematch:
	.string "WATTSON: A ha! Cuối cùng cháu cũng đến!\n"
	.string "Ta biết cháu muốn gì. Cháu muốn đấu với\l"
	.string "POKéMON của ta!\p"
	.string "Wahahahaha!\p"
	.string "Ta sẽ khiến tia lửa bắn ra từ người\n"
	.string "cháu! Đừng bảo là ta chưa cảnh báo\l"
	.string "nhé!$"

MauvilleCity_Gym_Text_WattsonRematchDefeat:
	.string "Ối... Pin của chúng ta cạn rồi...$"

MauvilleCity_Gym_Text_WattsonPostRematch:
	.string "WATTSON: Chúng ta lại phải sạc pin thôi.\p"
	.string "Khi đã sạc đầy, chúng ta sẽ vui lòng\n"
	.string "chấp nhận lời thách đấu của cháu.\p"
	.string "Vậy nên lúc nào đó hãy quay lại nhé?$"

MauvilleCity_Gym_Text_WattsonRematchNeedTwoMons:
	.string "WATTSON: A ha! Cuối cùng cháu cũng đến!\n"
	.string "Ta biết cháu muốn gì. Cháu muốn đấu với\l"
	.string "POKéMON của ta!\p"
	.string "Wahahahaha!\p"
	.string "Ối! Khoan đã! Cháu chỉ mang theo một\n"
	.string "POKéMON!\p"
	.string "Hãy quay lại gặp ta khi có ít nhất hai\n"
	.string "POKéMON, được chứ?$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global MauvilleCity_Gym_Text_GymGuideAdvice
	.global MauvilleCity_Gym_Text_GymGuidePostVictory
	.global MauvilleCity_Gym_Text_KirkIntro
	.global MauvilleCity_Gym_Text_KirkDefeat
	.global MauvilleCity_Gym_Text_KirkPostBattle
	.global MauvilleCity_Gym_Text_ShawnIntro
	.global MauvilleCity_Gym_Text_ShawnDefeat
	.global MauvilleCity_Gym_Text_ShawnPostBattle
	.global MauvilleCity_Gym_Text_BenIntro
	.global MauvilleCity_Gym_Text_BenDefeat
	.global MauvilleCity_Gym_Text_BenPostBattle
	.global MauvilleCity_Gym_Text_VivianIntro
	.global MauvilleCity_Gym_Text_VivianDefeat
	.global MauvilleCity_Gym_Text_VivianPostBattle
	.global MauvilleCity_Gym_Text_AngeloIntro
	.global MauvilleCity_Gym_Text_AngeloDefeat
	.global MauvilleCity_Gym_Text_AngeloPostBattle
	.global MauvilleCity_Gym_Text_WattsonIntro
	.global MauvilleCity_Gym_Text_WattsonDefeat
	.global MauvilleCity_Gym_Text_ReceivedDynamoBadge
	.global MauvilleCity_Gym_Text_ExplainDynamoBadgeTakeThis
	.global MauvilleCity_Gym_Text_ExplainShockWave
	.global MauvilleCity_Gym_Text_RegisteredWattson
	.global MauvilleCity_Gym_Text_WattsonPostBattle
	.global MauvilleCity_Gym_Text_WattsonGoForthAndEndeavor
	.global MauvilleCity_Gym_Text_WattsonPreRematch
	.global MauvilleCity_Gym_Text_WattsonRematchDefeat
	.global MauvilleCity_Gym_Text_WattsonPostRematch
	.global MauvilleCity_Gym_Text_WattsonRematchNeedTwoMons
@ END GENERATED LOCALIZATION EXPORTS
