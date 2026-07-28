JaggedPass_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, JaggedPass_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, JaggedPass_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, JaggedPass_OnLoad
	.byte 0

JaggedPass_OnResume:
	setstepcallback STEP_CB_ASH
	call_if_eq VAR_JAGGED_PASS_STATE, 0, JaggedPass_EventScript_CheckHasMagmaEmblem
	end

JaggedPass_EventScript_CheckHasMagmaEmblem::
	checkitem ITEM_MAGMA_EMBLEM
	goto_if_eq VAR_RESULT, TRUE, JaggedPass_EventScript_SetReadyToOpenHideout
	return

JaggedPass_EventScript_SetReadyToOpenHideout::
	setvar VAR_JAGGED_PASS_STATE, 1
	return

JaggedPass_OnTransition:
	call_if_eq VAR_JAGGED_PASS_ASH_WEATHER, 1, JaggedPass_EventScript_SetWeatherAsh
	end

JaggedPass_EventScript_SetWeatherAsh::
	setweather WEATHER_VOLCANIC_ASH
	doweather
	return

JaggedPass_OnLoad:
	goto_if_le VAR_JAGGED_PASS_STATE, 1, JaggedPass_EventScript_ConcealHideoutEntrance
	end

JaggedPass_EventScript_ConcealHideoutEntrance::
	setmetatile 16, 17, METATILE_Lavaridge_RockWall, TRUE
	setmetatile 16, 18, METATILE_Lavaridge_RockWall, TRUE
	end

JaggedPass_EventScript_OpenMagmaHideout::
	lockall
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	msgbox JaggedPass_Text_BoulderShakingInResponseToEmblem, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, 1   @ vertical pan
	setvar VAR_0x8005, 1   @ horizontal pan
	setvar VAR_0x8006, 16  @ num shakes
	setvar VAR_0x8007, 3   @ shake delay
	special ShakeCamera
	waitstate
	playse SE_EFFECTIVE
	setmetatile 16, 17, METATILE_Lavaridge_CaveEntrance_Top, TRUE
	setmetatile 16, 18, METATILE_Lavaridge_CaveEntrance_Bottom, FALSE
	special DrawWholeMapView
	delay 30
	setvar VAR_JAGGED_PASS_STATE, 2
	waitse
	releaseall
	end

JaggedPass_EventScript_MagmaHideoutGuard::
	lockall
	goto_if_set FLAG_BEAT_MAGMA_GRUNT_JAGGED_PASS, JaggedPass_EventScript_GuardDefeated
	waitse
	playse SE_PIN
	applymovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_FacePlayer
	waitmovement 0
	msgbox JaggedPass_Text_GruntIntro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_GRUNT_JAGGED_PASS, JaggedPass_Text_GruntDefeat
	setflag FLAG_BEAT_MAGMA_GRUNT_JAGGED_PASS
	applymovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

JaggedPass_EventScript_GuardDefeated::
	applymovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_FacePlayer
	waitmovement 0
	msgbox JaggedPass_Text_GoWhereverYouWant, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

JaggedPass_EventScript_Eric::
	trainerbattle_single TRAINER_ERIC, JaggedPass_Text_EricIntro, JaggedPass_Text_EricDefeat
	msgbox JaggedPass_Text_EricPostBattle, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Diana::
	trainerbattle_single TRAINER_DIANA_1, JaggedPass_Text_DianaIntro, JaggedPass_Text_DianaDefeat, JaggedPass_EventScript_RegisterDiana
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, JaggedPass_EventScript_DianaRematch
	msgbox JaggedPass_Text_DianaPostBattle, MSGBOX_DEFAULT
	release
	end

JaggedPass_EventScript_RegisterDiana::
	special PlayerFaceTrainerAfterBattle
	msgbox JaggedPass_Text_DianaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_DIANA_1
	release
	end

JaggedPass_EventScript_DianaRematch::
	trainerbattle_rematch TRAINER_DIANA_1, JaggedPass_Text_DianaRematchIntro, JaggedPass_Text_DianaRematchDefeat
	msgbox JaggedPass_Text_DianaPostRematch, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Ethan::
	trainerbattle_single TRAINER_ETHAN_1, JaggedPass_Text_EthanIntro, JaggedPass_Text_EthanDefeat, JaggedPass_EventScript_RegisterEthan
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, JaggedPass_EventScript_EthanRematch
	msgbox JaggedPass_Text_EthanPostBattle, MSGBOX_DEFAULT
	release
	end

JaggedPass_EventScript_RegisterEthan::
	special PlayerFaceTrainerAfterBattle
	msgbox JaggedPass_Text_EthanRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ETHAN_1
	release
	end

JaggedPass_EventScript_EthanRematch::
	trainerbattle_rematch TRAINER_ETHAN_1, JaggedPass_Text_EthanRematchIntro, JaggedPass_Text_EthanRematchDefeat
	msgbox JaggedPass_Text_EthanPostRematch, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Julio::
	trainerbattle_single TRAINER_JULIO, JaggedPass_Text_JulioIntro, JaggedPass_Text_JulioDefeat
	msgbox JaggedPass_Text_JulioPostBattle, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Autumn::
	trainerbattle_single TRAINER_AUTUMN, JaggedPass_Text_AutumnIntro, JaggedPass_Text_AutumnDefeat
	msgbox JaggedPass_Text_AutumnPostBattle, MSGBOX_AUTOCLOSE
	end

JaggedPass_Text_EricIntro:
	.string "JAGGED PASS của MT. CHIMNEY...\p"
	.string "Đây chính là kiểu núi mà tôi hằng ao\n"
	.string "ước.\p"
	.string "Địa hình gập ghềnh lởm chởm này... làm\n"
	.string "tâm hồn tôi rung động!$"

JaggedPass_Text_EricDefeat:
	.string "Thua trận khiến tôi cay cú quá!$"

JaggedPass_Text_EricPostBattle:
	.string "Đúng, tôi đã thua trong trận POKéMON...\p"
	.string "Nhưng về tình yêu dành cho núi non thì\n"
	.string "tôi hơn bạn!$"

JaggedPass_Text_DianaIntro:
	.string "Nơi này không dành cho một chuyến đi\n"
	.string "bộ thong thả. Càng không thích hợp để\l"
	.string "dã ngoại.$"

JaggedPass_Text_DianaDefeat:
	.string "Ôi, không! Mặt đất gập ghềnh quá...$"

JaggedPass_Text_DianaPostBattle:
	.string "Bạn có biết không?\p"
	.string "Có những người khéo léo đến mức đạp\n"
	.string "xe lên được con đèo gập ghềnh khủng\l"
	.string "khiếp này đấy.$"

JaggedPass_Text_DianaRegister:
	.string "Bạn có quay lại khu vực này nữa không?\n"
	.string "Nếu có, tôi muốn tái đấu với bạn.$"

JaggedPass_Text_DianaRematchIntro:
	.string "Đi dã ngoại ở đâu cũng vui. POKéMON\n"
	.string "cũng vậy!$"

JaggedPass_Text_DianaRematchDefeat:
	.string "Tôi thua chỉ vì mặt đất gập ghềnh quá\n"
	.string "thôi!$"

JaggedPass_Text_DianaPostRematch:
	.string "Tôi sẽ quên trận thua và tận hưởng\n"
	.string "chuyến đi bộ gập ghềnh này.$"

JaggedPass_Text_EthanIntro:
	.string "JAGGED PASS rất khó đi. Đây là nơi\n"
	.string "thích hợp để rèn luyện.$"

JaggedPass_Text_EthanDefeat:
	.string "Trận đấu đã kết thúc khi chúng tôi còn\n"
	.string "đang lo tìm chỗ đứng vững...$"

JaggedPass_Text_EthanPostBattle:
	.string "Nếu có ACRO BIKE, tôi sẽ nhảy qua được\n"
	.string "các gờ đá.$"

JaggedPass_Text_EthanRegister:
	.string "Khi quen hơn với địa hình gập ghềnh\n"
	.string "này, nhất định tôi sẽ thắng!\p"
	.string "Bạn đăng ký tôi vào POKéNAV được\n"
	.string "không?$"

JaggedPass_Text_EthanRematchIntro:
	.string "Tôi đã quen với địa hình gập ghềnh này\n"
	.string "rồi. Giờ leo núi tôi còn vừa đi vừa hát\l"
	.string "nữa.$"

JaggedPass_Text_EthanRematchDefeat:
	.string "Chiến đấu trên mặt đất gập ghềnh này\n"
	.string "vẫn chẳng dễ chút nào...$"

JaggedPass_Text_EthanPostRematch:
	.string "Mình nên đến gặp RYDEL ở MAUVILLE\n"
	.string "CITY để lấy một chiếc ACRO BIKE...$"

JaggedPass_Text_GruntIntro:
	.string "Á! Ngươi làm gì ở đây?\p"
	.string "Ta làm gì tại một nơi thế này ư?\p"
	.string "Liên quan gì đến ngươi?$"

JaggedPass_Text_GruntDefeat:
	.string "Ưưư...\p"
	.string "Lẽ ra ta phải chui ngay vào HIDEOUT...$"

JaggedPass_Text_GoWhereverYouWant:
	.string "Được rồi, được rồi! Ta thừa nhận\n"
	.string "ngươi rất mạnh!\p"
	.string "Đừng bận tâm đến ta. Muốn đi đâu thì\n"
	.string "đi!$"

JaggedPass_Text_BoulderShakingInResponseToEmblem:
	.string "Ồ! Tảng đá này đang rung lên vì phản\n"
	.string "ứng với MAGMA EMBLEM!$"

JaggedPass_Text_JulioIntro:
	.string "Ái chà! Lao một mạch xuống núi đáng sợ\n"
	.string "quá!$"

JaggedPass_Text_JulioDefeat:
	.string "Tôi có cảm giác cả người sắp rã ra rồi...$"

JaggedPass_Text_JulioPostBattle:
	.string "Xe đạp của tôi nảy dữ quá, làm ê cả\n"
	.string "mông...$"

JaggedPass_Text_AutumnIntro:
	.string "Ngày nào tôi cũng leo ngọn đồi này. Tôi\n"
	.string "rất tự tin vào sức mạnh của mình!$"

JaggedPass_Text_AutumnDefeat:
	.string "Hừm... Có chuyện gì không ổn nhỉ?$"

JaggedPass_Text_AutumnPostBattle:
	.string "Mỏm đá kỳ lạ nhô lên ở phía trên đồi kia\n"
	.string "là gì vậy?$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global JaggedPass_Text_EricIntro
	.global JaggedPass_Text_EricDefeat
	.global JaggedPass_Text_EricPostBattle
	.global JaggedPass_Text_DianaIntro
	.global JaggedPass_Text_DianaDefeat
	.global JaggedPass_Text_DianaPostBattle
	.global JaggedPass_Text_DianaRegister
	.global JaggedPass_Text_DianaRematchIntro
	.global JaggedPass_Text_DianaRematchDefeat
	.global JaggedPass_Text_DianaPostRematch
	.global JaggedPass_Text_EthanIntro
	.global JaggedPass_Text_EthanDefeat
	.global JaggedPass_Text_EthanPostBattle
	.global JaggedPass_Text_EthanRegister
	.global JaggedPass_Text_EthanRematchIntro
	.global JaggedPass_Text_EthanRematchDefeat
	.global JaggedPass_Text_EthanPostRematch
	.global JaggedPass_Text_GruntIntro
	.global JaggedPass_Text_GruntDefeat
	.global JaggedPass_Text_GoWhereverYouWant
	.global JaggedPass_Text_BoulderShakingInResponseToEmblem
	.global JaggedPass_Text_JulioIntro
	.global JaggedPass_Text_JulioDefeat
	.global JaggedPass_Text_JulioPostBattle
	.global JaggedPass_Text_AutumnIntro
	.global JaggedPass_Text_AutumnDefeat
	.global JaggedPass_Text_AutumnPostBattle
@ END GENERATED LOCALIZATION EXPORTS
