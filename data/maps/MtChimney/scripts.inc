MtChimney_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, MtChimney_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, MtChimney_OnTransition
	.byte 0

MtChimney_OnTransition:
	setvar VAR_JAGGED_PASS_ASH_WEATHER, 1
	end

MtChimney_OnResume:
	setstepcallback STEP_CB_ASH
	end

MtChimney_EventScript_Archie::
	lock
	faceplayer
	call_if_unset FLAG_EVIL_LEADER_PLEASE_STOP, MtChimney_EventScript_ArchieGoStopTeamMagma
	call_if_set FLAG_EVIL_LEADER_PLEASE_STOP, MtChimney_EventScript_ArchieBusyFighting
	closemessage
	applymovement LOCALID_MT_CHIMNEY_ARCHIE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag FLAG_EVIL_LEADER_PLEASE_STOP
	release
	end

MtChimney_EventScript_ArchieGoStopTeamMagma::
	msgbox MtChimney_Text_ArchieGoStopTeamMagma, MSGBOX_DEFAULT
	return

MtChimney_EventScript_ArchieBusyFighting::
	msgbox MtChimney_Text_ArchieIHaveMyHandsFull, MSGBOX_DEFAULT
	return

MtChimney_EventScript_Maxie::
	lockall
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
	msgbox MtChimney_Text_MeteoriteWillActivateVolcano, MSGBOX_DEFAULT
	applymovement LOCALID_MT_CHIMNEY_MAXIE, Common_Movement_FacePlayer
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_MT_CHIMNEY_MAXIE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MT_CHIMNEY_MAXIE, Common_Movement_Delay48
	waitmovement 0
	msgbox MtChimney_Text_MaxieIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_MAXIE_MT_CHIMNEY, MtChimney_Text_MaxieDefeat
	msgbox MtChimney_Text_MaxieYouHaventSeenLastOfMagma, MSGBOX_DEFAULT
	closemessage
	delay 30
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_MT_CHIMNEY_MAXIE
	removeobject LOCALID_MT_CHIMNEY_MAGMA_GRUNT_1
	removeobject LOCALID_MT_CHIMNEY_TABITHA
	removeobject LOCALID_MT_CHIMNEY_MAGMA_GRUNT_2
	setflag FLAG_HIDE_MT_CHIMNEY_TEAM_MAGMA
	fadescreen FADE_FROM_BLACK
	setobjectxyperm LOCALID_MT_CHIMNEY_ARCHIE, 10, 12
	addobject LOCALID_MT_CHIMNEY_ARCHIE
	call_if_eq VAR_FACING, DIR_EAST, MtChimney_EventScript_ArchieApproachPlayerEast
	call_if_eq VAR_FACING, DIR_NORTH, MtChimney_EventScript_ArchieApproachPlayerNorth
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox MtChimney_Text_ArchieThankYou, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_EAST, MtChimney_EventScript_ArchieExitEast
	call_if_eq VAR_FACING, DIR_NORTH, MtChimney_EventScript_ArchieExitNorth
	removeobject LOCALID_MT_CHIMNEY_ARCHIE
	setflag FLAG_HIDE_MT_CHIMNEY_TEAM_AQUA
	setflag FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY
	clearflag FLAG_HIDE_FALLARBOR_HOUSE_PROF_COZMO
	setflag FLAG_HIDE_METEOR_FALLS_1F_1R_COZMO
	clearflag FLAG_HIDE_MT_CHIMNEY_LAVA_COOKIE_LADY
	releaseall
	end

MtChimney_EventScript_ArchieApproachPlayerEast::
	applymovement LOCALID_MT_CHIMNEY_ARCHIE, MtChimney_Movement_ArchieApproachPlayerEast
	waitmovement 0
	return

MtChimney_EventScript_ArchieApproachPlayerNorth::
	applymovement LOCALID_MT_CHIMNEY_ARCHIE, MtChimney_Movement_ArchieApproachPlayerNorth
	waitmovement 0
	return

MtChimney_EventScript_ArchieExitEast::
	applymovement LOCALID_MT_CHIMNEY_ARCHIE, MtChimney_Movement_ArchieExitEast
	waitmovement 0
	return

MtChimney_EventScript_ArchieExitNorth::
	applymovement LOCALID_MT_CHIMNEY_ARCHIE, MtChimney_Movement_ArchieExitNorth
	waitmovement 0
	return

MtChimney_EventScript_LavaCookieLady::
	lock
	faceplayer
	showmoneybox 0, 0
	msgbox MtChimney_Text_LavaCookiesJust200, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MtChimney_EventScript_DeclineLavaCookie
	checkmoney 200
	goto_if_eq VAR_RESULT, FALSE, MtChimney_EventScript_NotEnoughMoney
	msgbox MtChimney_Text_ThankYouDear, MSGBOX_DEFAULT
	checkitemspace ITEM_LAVA_COOKIE
	call_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_RemoveMoney
	giveitem ITEM_LAVA_COOKIE
	goto_if_eq VAR_RESULT, FALSE, MtChimney_EventScript_BagIsFull
	hidemoneybox
	release
	end

MtChimney_EventScript_BagIsFull::
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

MtChimney_EventScript_RemoveMoney::
	removemoney 200
	updatemoneybox
	return

MtChimney_EventScript_DeclineLavaCookie::
	msgbox MtChimney_Text_OhFineThen, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

MtChimney_EventScript_NotEnoughMoney::
	msgbox MtChimney_Text_YouveNotGotTheMoney, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

MtChimney_Movement_ArchieApproachPlayerEast:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	step_end

MtChimney_Movement_ArchieExitEast:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_ArchieApproachPlayerNorth:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	step_end

MtChimney_Movement_ArchieExitNorth:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused1:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused2:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused3:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused4:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused5:
	delay_16
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused6:
	delay_16
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused7:
	delay_16
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused8:
	delay_16
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_down
	step_end

MtChimney_Movement_Unused9:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused10:
	walk_down
	step_end

MtChimney_Movement_Unused11:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused12:
	delay_16
	delay_16
	walk_in_place_faster_left
	delay_16
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused13:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_left
	delay_16
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused14:
	lock_facing_direction
	walk_fast_left
	unlock_facing_direction
	face_right
	step_end

MtChimney_Movement_Unused15:
	walk_left
	walk_in_place_faster_right
	delay_16
	step_end

MtChimney_EventScript_BusyAquaGrunt1::
	msgbox MtChimney_Text_MagmaOutnumbersUs, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyAquaGrunt2::
	msgbox MtChimney_Text_LessHabitatForWaterPokemon, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyAquaGrunt3::
	msgbox MtChimney_Text_MagmasNameSimilar, MSGBOX_SIGN
	end

MtChimney_EventScript_Tabitha::
	trainerbattle_single TRAINER_TABITHA_MT_CHIMNEY, MtChimney_Text_TabithaIntro, MtChimney_Text_TabithaDefeat
	msgbox MtChimney_Text_TabithaPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_MT_CHIMNEY_2, MtChimney_Text_Grunt2Intro, MtChimney_Text_Grunt2Defeat
	msgbox MtChimney_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_BusyMagmaGrunt1::
	msgbox MtChimney_Text_TeamAquaAlwaysMessingWithPlans, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt2::
	msgbox MtChimney_Text_MeteoritesPackAmazingPower, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt3::
	msgbox MtChimney_Text_YouBetterNotMessWithUs, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt4::
	msgbox MtChimney_Text_AquasNameSimilar, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt5::
	msgbox MtChimney_Text_DouseThemInFire, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt6::
	msgbox MtChimney_Text_KeepMakingMoreLand, MSGBOX_SIGN
	end

MtChimney_EventScript_MagmaPoochyena::
	msgbox MtChimney_Text_Bufoh, MSGBOX_SIGN
	end

MtChimney_EventScript_AquaPoochyena::
	msgbox MtChimney_Text_Bushaa, MSGBOX_SIGN
	end

MtChimney_EventScript_MeteoriteMachine::
	lockall
	goto_if_unset FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, MtChimney_EventScript_MachineOn
	goto_if_set FLAG_RECEIVED_METEORITE, MtChimney_EventScript_MachineOff
	msgbox MtChimney_Text_RemoveTheMeteorite, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MtChimney_EventScript_LeaveMeteoriteAlone
	msgbox MtChimney_Text_PlayerRemovedMeteorite, MSGBOX_DEFAULT
	giveitem ITEM_METEORITE
	setflag FLAG_RECEIVED_METEORITE
	releaseall
	end

MtChimney_EventScript_LeaveMeteoriteAlone::
	msgbox MtChimney_Text_PlayerLeftMeteorite, MSGBOX_DEFAULT
	releaseall
	end

MtChimney_EventScript_MachineOff::
	msgbox MtChimney_Text_MachineMakesNoResponse, MSGBOX_DEFAULT
	releaseall
	end

MtChimney_EventScript_MachineOn::
	msgbox MtChimney_Text_MeteoriteFittedOnMachine, MSGBOX_DEFAULT
	releaseall
	end

MtChimney_EventScript_RouteSign::
	msgbox MtChimney_Text_RouteSign, MSGBOX_SIGN
	end

MtChimney_EventScript_Shelby::
	trainerbattle_single TRAINER_SHELBY_1, MtChimney_Text_ShelbyIntro, MtChimney_Text_ShelbyDefeat, MtChimney_EventScript_DefeatedShelby
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_RematchShelby
	msgbox MtChimney_Text_ShelbyPostBattle, MSGBOX_DEFAULT
	release
	end

MtChimney_EventScript_DefeatedShelby::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtChimney_Text_ShelbyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_SHELBY_1
	release
	end

MtChimney_EventScript_RematchShelby::
	trainerbattle_rematch TRAINER_SHELBY_1, MtChimney_Text_ShelbyRematchIntro, MtChimney_Text_ShelbyRematchDefeat
	msgbox MtChimney_Text_ShelbyPostRematch, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Melissa::
	trainerbattle_single TRAINER_MELISSA, MtChimney_Text_MelissaIntro, MtChimney_Text_MelissaDefeat
	msgbox MtChimney_Text_MelissaPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Sheila::
	trainerbattle_single TRAINER_SHEILA, MtChimney_Text_SheilaIntro, MtChimney_Text_SheilaDefeat
	msgbox MtChimney_Text_SheilaPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Shirley::
	trainerbattle_single TRAINER_SHIRLEY, MtChimney_Text_ShirleyIntro, MtChimney_Text_ShirleyDefeat
	msgbox MtChimney_Text_ShirleyPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_MT_CHIMNEY_1, MtChimney_Text_Grunt1Intro, MtChimney_Text_Grunt1Defeat
	msgbox MtChimney_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Sawyer::
	trainerbattle_single TRAINER_SAWYER_1, MtChimney_Text_SawyerIntro, MtChimney_Text_SawyerDefeat, MtChimney_EventScript_SawyerDefeated
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_SawyerRematch
	msgbox MtChimney_Text_SawyerPostBattle, MSGBOX_DEFAULT
	release
	end

MtChimney_EventScript_SawyerDefeated::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtChimney_Text_SawyerRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_SAWYER_1
	release
	end

MtChimney_EventScript_SawyerRematch::
	trainerbattle_rematch TRAINER_SAWYER_1, MtChimney_Text_SawyerRematchIntro, MtChimney_Text_SawyerRematchDefeat
	msgbox MtChimney_Text_SawyerPostRematch, MSGBOX_AUTOCLOSE
	end

MtChimney_Text_MeteoriteWillActivateVolcano:
	.string "Sức mạnh ẩn chứa trong METEORITE...\p"
	.string "Nếu dùng cỗ máy này khuếch đại sức\n"
	.string "mạnh đó, hoạt động núi lửa của MT.\l"
	.string "CHIMNEY sẽ lập tức trở nên dữ dội...\p"
	.string "Năng lượng của nó sẽ dâng lên từ sâu\n"
	.string "trong miệng núi lửa và... Hư hư hư...$"

MtChimney_Text_MaxieIntro:
	.string "MAXIE: Hửm? Ngươi là ai?\p"
	.string "...\p"
	.string "Ta từng nghe ARCHIE than phiền về một\n"
	.string "đứa trẻ cứ xen vào chuyện của TEAM\l"
	.string "AQUA.\p"
	.string "Hẳn hắn nói về ngươi.\p"
	.string "Hừ! Vậy ngươi định cản trở TEAM MAGMA\n"
	.string "bọn ta sao?\p"
	.string "Nghe cho rõ đây. Từ xa xưa, sinh vật đã\n"
	.string "sống và sinh trưởng trên đất liền.\p"
	.string "Chính vì thế, đất liền là thứ quan\n"
	.string "trọng nhất! Đó là chiếc nôi của tất cả!\p"
	.string "Vì vậy, TEAM MAGMA quyết tâm mở rộng\n"
	.string "đất liền.\p"
	.string "Đó là để loài người và POKéMON tiến xa\n"
	.string "hơn nữa!\p"
	.string "Và để làm được thế, bọn ta cần sức\n"
	.string "mạnh của thứ đang ngủ sâu trong ngọn\l"
	.string "núi này...\p"
	.string "Ồ! Ngươi đâu cần biết nhiều đến vậy.\p"
	.string "Nhưng không sao! Ta sẽ cho ngươi biết\n"
	.string "hậu quả của việc xen vào đại kế của bọn\l"
	.string "ta!$"

MtChimney_Text_MaxieDefeat:
	.string "Cái gì?!\p"
	.string "Ta, MAXIE, lại mất cảnh giác sao?!$"

MtChimney_Text_MaxieYouHaventSeenLastOfMagma:
	.string "MAXIE: Nhưng đủ rồi. Lần này ta sẽ rút\n"
	.string "lui.\p"
	.string "Nhưng đừng tưởng đây là lần cuối\n"
	.string "ngươi thấy TEAM MAGMA.\p"
	.string "Hư hư hư...\p"
	.string "Dù không có METEORITE, chỉ cần bọn ta\n"
	.string "có được ORB đó... Hư hư hư...$"

MtChimney_Text_TabithaIntro:
	.string "Hê hê hê!\p"
	.string "Vậy là ngươi đã tới tận đây!\p"
	.string "Nhưng quá muộn rồi! Ta đã giao\n"
	.string "METEORITE từ METEOR FALLS\l"
	.string "cho thủ lĩnh rồi!$"

MtChimney_Text_TabithaDefeat:
	.string "Hê hê hê...\p"
	.string "Dù ta đã thua, chỉ cần thủ lĩnh đánh\n"
	.string "thức thứ đó...$"

MtChimney_Text_TabithaPostBattle:
	.string "Thủ lĩnh, mau lên! Truyền năng lượng\n"
	.string "của METEORITE cho nó!\p"
	.string "Hê hê hê...$"

MtChimney_Text_Grunt2Intro:
	.string "TEAM MAGMA bọn ta đang nỗ lực vì lợi\n"
	.string "ích của tất cả mọi người.\p"
	.string "Chẳng hạn, nếu sức mạnh của thứ đó tạo\n"
	.string "thêm đất liền, sẽ có thêm nhiều nơi để\l"
	.string "sinh sống.\p"
	.string "Mọi người đều sẽ hạnh phúc!$"

MtChimney_Text_Grunt2Defeat:
	.string "Hả? Ngươi nói ta thua là sao?$"

MtChimney_Text_Grunt2PostBattle:
	.string "Thủ lĩnh bọn ta nói: Việc đó sẽ khiến\n"
	.string "mọi người hạnh phúc.\p"
	.string "Nhưng sao ai cũng cứ cản đường bọn\n"
	.string "ta?$"

MtChimney_Text_Grunt1Intro:
	.string "Nếu có thêm đất liền, ta sẽ có thể xây\n"
	.string "một căn nhà thật lớn cho riêng mình!\p"
	.string "Ta sẽ xây nó trên dung nham đã đông\n"
	.string "cứng!$"

MtChimney_Text_Grunt1Defeat:
	.string "Giấc mơ về căn nhà lớn của ta...$"

MtChimney_Text_Grunt1PostBattle:
	.string "Một đứa trẻ như ngươi thì nên ra\n"
	.string "nghịch sóng đi!$"

MtChimney_Text_TeamAquaAlwaysMessingWithPlans:
	.string "TEAM AQUA phiền phức đó... Chúng lúc\n"
	.string "nào cũng phá hỏng kế hoạch của bọn ta!$"

MtChimney_Text_MeteoritesPackAmazingPower:
	.string "METEORITES chứa đựng sức mạnh đáng\n"
	.string "kinh ngạc!$"

MtChimney_Text_YouBetterNotMessWithUs:
	.string "Tốt nhất đừng cản đường bọn ta!\p"
	.string "Bọn ta đang cố đánh thức thứ đó vì lợi\n"
	.string "ích của tất cả mọi người!$"

MtChimney_Text_AquasNameSimilar:
	.string "Bọn ta là TEAM MAGMA!\p"
	.string "Chúng là TEAM AQUA!\p"
	.string "Việc chúng dùng một cái tên giống bọn\n"
	.string "ta khiến ta bực mình hết sức!$"

MtChimney_Text_DouseThemInFire:
	.string "Đúng! Cho chúng tắm trong lửa đi!$"

MtChimney_Text_KeepMakingMoreLand:
	.string "Bọn ta sẽ tiếp tục mở rộng đất liền!$"

MtChimney_Text_Bufoh:
	.string "Hự!$"

MtChimney_Text_ArchieGoStopTeamMagma:
	.string "ARCHIE: Gừ, {PLAYER}! Ta biết ngay\n"
	.string "nhóc sẽ xuất hiện mà!\p"
	.string "Tự nhìn xem lũ cuồng tín TEAM MAGMA\n"
	.string "đang làm gì đi!\p"
	.string "Chúng đang cố truyền sức mạnh của\n"
	.string "METEORITE bị đánh cắp vào núi lửa!\p"
	.string "Làm vậy sẽ khiến núi lửa phun trào!$"

MtChimney_Text_ArchieIHaveMyHandsFull:
	.string "ARCHIE: Gừừ...\p"
	.string "Ta muốn ngăn tên MAXIE đó, nhưng không\n"
	.string "thể!\p"
	.string "Ta đang phải một mình đối đầu với ba kẻ\n"
	.string "cùng lúc!$"

MtChimney_Text_ArchieThankYou:
	.string "ARCHIE: {PLAYER}! Cảm ơn nhóc!\p"
	.string "Nhờ nhóc giúp sức, chúng ta đã phá tan\n"
	.string "kế hoạch hủy diệt của TEAM MAGMA!\p"
	.string "Nhưng... Nhóc... Nhóc đứng về phe nào?\p"
	.string "À, không quan trọng.\p"
	.string "Bọn ta sẽ luôn cảnh giác và tiếp tục\n"
	.string "truy đuổi TEAM MAGMA.\p"
	.string "{PLAYER}, chúng ta sẽ còn gặp lại!$"

MtChimney_Text_MagmaOutnumbersUs:
	.string "Khỉ thật... TEAM MAGMA đông hơn chúng\n"
	.string "ta! Chúng ta không cầm cự nổi!$"

MtChimney_Text_LessHabitatForWaterPokemon:
	.string "Nếu chúng mở rộng đất liền, môi trường\n"
	.string "sống của WATER POKéMON sẽ bị thu hẹp!$"

MtChimney_Text_MagmasNameSimilar:
	.string "Bọn ta là TEAM AQUA!\p"
	.string "Chúng là TEAM MAGMA!\p"
	.string "Việc chúng dùng một cái tên dễ gây nhầm\n"
	.string "lẫn như thế khiến ta tức muốn bốc hỏa!$"

MtChimney_Text_Bushaa:
	.string "Bùm!$"

MtChimney_Text_LavaCookiesJust200:
	.string "LAVA COOKIES là đặc sản địa phương\n"
	.string "của MT. CHIMNEY.\p"
	.string "Dùng thử đi. Chỉ ¥200 thôi.$"

MtChimney_Text_ThankYouDear:
	.string "Cảm ơn cháu nhé!$"

MtChimney_Text_YouveNotGotTheMoney:
	.string "Ôi, cháu à. Không có tiền thì chẳng mua\n"
	.string "được gì đâu.$"

MtChimney_Text_OhFineThen:
	.string "Ồ, vậy thôi.$"

MtChimney_Text_MeteoriteFittedOnMachine:
	.string "Một METEORITE được gắn vào một cỗ máy\n"
	.string "bí ẩn...\p"
	.string "Có vẻ cỗ máy đang tích trữ năng lượng\n"
	.string "trong METEORITE.$"

MtChimney_Text_RemoveTheMeteorite:
	.string "Một METEORITE được gắn vào một cỗ máy\n"
	.string "bí ẩn...\p"
	.string "Bạn có muốn tháo METEORITE ra không?$"

MtChimney_Text_PlayerRemovedMeteorite:
	.string "{PLAYER} đã tháo METEORITE khỏi cỗ\n"
	.string "máy bí ẩn.$"

MtChimney_Text_PlayerLeftMeteorite:
	.string "{PLAYER} để nguyên METEORITE tại\n"
	.string "chỗ.$"

MtChimney_Text_MachineMakesNoResponse:
	.string "Cỗ máy bí ẩn này... Hoàn toàn không có\n"
	.string "phản ứng.$"

MtChimney_Text_RouteSign:
	.string "{DOWN_ARROW} JAGGED PATH\n"
	.string "LAVARIDGE TOWN AHEAD$"

MtChimney_Text_ShelbyIntro:
	.string "Bà vừa ngâm suối nóng, xua tan hết mỏi\n"
	.string "mệt. Giờ bà thấy khỏe khoắn lắm!$"

MtChimney_Text_ShelbyDefeat:
	.string "Ôi trời. Cháu giỏi thật đấy!$"

MtChimney_Text_ShelbyPostBattle:
	.string "Chà chà, bà thua rồi. Giờ bà đâu thể tự\n"
	.string "nhận mình là EXPERT nữa, phải không?$"

MtChimney_Text_ShelbyRegister:
	.string "Cảm ơn cháu. Trận đấu vui như thể bà\n"
	.string "đang đấu với chính cháu mình vậy.\p"
	.string "Lần sau hãy lại đến tái đấu với bà nhé.$"

MtChimney_Text_ShelbyRematchIntro:
	.string "Nếu cháu có thể hòa nhịp trái tim mình\n"
	.string "với trái tim của POKéMON, cháu sẽ làm\l"
	.string "nên những điều lớn lao.$"

MtChimney_Text_ShelbyRematchDefeat:
	.string "Ôi trời. Cháu giỏi thật đấy!$"

MtChimney_Text_ShelbyPostRematch:
	.string "Có lẽ trái tim cháu đã hòa làm một với\n"
	.string "trái tim của POKéMON rồi.$"

MtChimney_Text_MelissaIntro:
	.string "Ngọn lửa trong tôi đang bùng cháy đây,\n"
	.string "cưng à. Tôi không chịu nổi nữa! Phải đấu\l"
	.string "thôi!$"

MtChimney_Text_MelissaDefeat:
	.string "Ôi, đúng là một trận đấu nóng bỏng!$"

MtChimney_Text_MelissaPostBattle:
	.string "Hơi nóng của MT. CHIMNEY làm tôi ấm hẳn\n"
	.string "lên, cưng à!$"

MtChimney_Text_SheilaIntro:
	.string "Cuối cùng tôi cũng đến được MT.\n"
	.string "CHIMNEY. Tôi muốn cho POKéMON của mình\l"
	.string "chiến đấu!$"

MtChimney_Text_SheilaDefeat:
	.string "Cách bạn chiến đấu... Cứ như MT.\n"
	.string "CHIMNEY phun trào vậy!$"

MtChimney_Text_SheilaPostBattle:
	.string "Như tôi đã nói, cuối cùng tôi cũng đến\n"
	.string "được MT. CHIMNEY. Nếu chỉ ngắm cảnh\l"
	.string "một chút rồi về thì phí quá...\p"
	.string "Tôi muốn đấu vài trận và mua COOKIES\n"
	.string "làm quà lưu niệm.$"

MtChimney_Text_ShirleyIntro:
	.string "Từ lúc ngâm suối nóng, tôi thấy khỏe\n"
	.string "khoắn vô cùng! Tôi chắc chắn mình sẽ\l"
	.string "thắng!$"

MtChimney_Text_ShirleyDefeat:
	.string "Ái da! Vừa ra khỏi nước mà tôi đã lạnh\n"
	.string "run rồi.$"

MtChimney_Text_ShirleyPostBattle:
	.string "Tôi phải xuống suối nóng ngâm thêm lần\n"
	.string "nữa. Muốn đi cùng không?\p"
	.string "Đùa thôi!$"

MtChimney_Text_SawyerIntro:
	.string "Quả là một ngọn núi tuyệt vời! Xung\n"
	.string "quanh lại có bao người nóng bỏng bầu\l"
	.string "bạn!$"

MtChimney_Text_SawyerDefeat:
	.string "Ồ, bạn cũng đúng là một ngọn lửa dữ dội\n"
	.string "đấy!$"

MtChimney_Text_SawyerPostBattle:
	.string "Có lẽ tôi cần ngâm mình trong LAVARIDGE\n"
	.string "HOT SPRING cùng dân địa phương!$"

MtChimney_Text_SawyerRegister:
	.string "Tôi thích những quả cầu lửa bé nhỏ như\n"
	.string "bạn. Cho tôi đăng ký bạn vào POKéNAV\l"
	.string "nhé.$"

MtChimney_Text_SawyerRematchIntro:
	.string "Ở vùng này, quanh tôi toàn những người\n"
	.string "nóng bỏng nên vui lắm. Tôi sẽ không thua\l"
	.string "đâu!$"

MtChimney_Text_SawyerRematchDefeat:
	.string "Trời, bạn vẫn nồng nhiệt như lần trước!$"

MtChimney_Text_SawyerPostRematch:
	.string "Thật ra ở đây nóng thật. Tôi mặc nhiều\n"
	.string "quá so với vùng này.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global MtChimney_Text_MeteoriteWillActivateVolcano
	.global MtChimney_Text_MaxieIntro
	.global MtChimney_Text_MaxieDefeat
	.global MtChimney_Text_MaxieYouHaventSeenLastOfMagma
	.global MtChimney_Text_TabithaIntro
	.global MtChimney_Text_TabithaDefeat
	.global MtChimney_Text_TabithaPostBattle
	.global MtChimney_Text_Grunt2Intro
	.global MtChimney_Text_Grunt2Defeat
	.global MtChimney_Text_Grunt2PostBattle
	.global MtChimney_Text_Grunt1Intro
	.global MtChimney_Text_Grunt1Defeat
	.global MtChimney_Text_Grunt1PostBattle
	.global MtChimney_Text_TeamAquaAlwaysMessingWithPlans
	.global MtChimney_Text_MeteoritesPackAmazingPower
	.global MtChimney_Text_YouBetterNotMessWithUs
	.global MtChimney_Text_AquasNameSimilar
	.global MtChimney_Text_DouseThemInFire
	.global MtChimney_Text_KeepMakingMoreLand
	.global MtChimney_Text_Bufoh
	.global MtChimney_Text_ArchieGoStopTeamMagma
	.global MtChimney_Text_ArchieIHaveMyHandsFull
	.global MtChimney_Text_ArchieThankYou
	.global MtChimney_Text_MagmaOutnumbersUs
	.global MtChimney_Text_LessHabitatForWaterPokemon
	.global MtChimney_Text_MagmasNameSimilar
	.global MtChimney_Text_Bushaa
	.global MtChimney_Text_LavaCookiesJust200
	.global MtChimney_Text_ThankYouDear
	.global MtChimney_Text_YouveNotGotTheMoney
	.global MtChimney_Text_OhFineThen
	.global MtChimney_Text_MeteoriteFittedOnMachine
	.global MtChimney_Text_RemoveTheMeteorite
	.global MtChimney_Text_PlayerRemovedMeteorite
	.global MtChimney_Text_PlayerLeftMeteorite
	.global MtChimney_Text_MachineMakesNoResponse
	.global MtChimney_Text_ShelbyIntro
	.global MtChimney_Text_ShelbyDefeat
	.global MtChimney_Text_ShelbyPostBattle
	.global MtChimney_Text_ShelbyRegister
	.global MtChimney_Text_ShelbyRematchIntro
	.global MtChimney_Text_ShelbyRematchDefeat
	.global MtChimney_Text_ShelbyPostRematch
	.global MtChimney_Text_MelissaIntro
	.global MtChimney_Text_MelissaDefeat
	.global MtChimney_Text_MelissaPostBattle
	.global MtChimney_Text_SheilaIntro
	.global MtChimney_Text_SheilaDefeat
	.global MtChimney_Text_SheilaPostBattle
	.global MtChimney_Text_ShirleyIntro
	.global MtChimney_Text_ShirleyDefeat
	.global MtChimney_Text_ShirleyPostBattle
	.global MtChimney_Text_SawyerIntro
	.global MtChimney_Text_SawyerDefeat
	.global MtChimney_Text_SawyerPostBattle
	.global MtChimney_Text_SawyerRegister
	.global MtChimney_Text_SawyerRematchIntro
	.global MtChimney_Text_SawyerRematchDefeat
	.global MtChimney_Text_SawyerPostRematch
@ END GENERATED LOCALIZATION EXPORTS
