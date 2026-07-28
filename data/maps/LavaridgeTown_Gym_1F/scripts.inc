LavaridgeTown_Gym_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_Gym_1F_OnTransition
	.byte 0

LavaridgeTown_Gym_1F_OnTransition:
	call LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars
	call LavaridgeTown_Gym_1F_EventScript_CheckBuryTrainers
	end

@ Unclear where/if these temp vars are getting checked
LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars::
	setvar VAR_TEMP_B, 0
	setvar VAR_TEMP_C, 0
	setvar VAR_TEMP_D, 0
	setvar VAR_TEMP_E, 0
	setvar VAR_TEMP_F, 0
	goto_if_defeated TRAINER_COLE, LavaridgeTown_Gym_1F_EventScript_SetGeraldTempVar
	setvar VAR_TEMP_B, 1
LavaridgeTown_Gym_1F_EventScript_SetGeraldTempVar::
	goto_if_defeated TRAINER_GERALD, LavaridgeTown_Gym_1F_EventScript_SetAxleTempVar
	setvar VAR_TEMP_C, 1
LavaridgeTown_Gym_1F_EventScript_SetAxleTempVar::
	goto_if_defeated TRAINER_AXLE, LavaridgeTown_Gym_1F_EventScript_SetDanielleTempVar
	setvar VAR_TEMP_D, 1
LavaridgeTown_Gym_1F_EventScript_SetDanielleTempVar::
	goto_if_defeated TRAINER_DANIELLE, LavaridgeTown_Gym_1F_EventScript_EndSetTrainerTempVars
	setvar VAR_TEMP_E, 1
LavaridgeTown_Gym_1F_EventScript_EndSetTrainerTempVars::
	return

LavaridgeTown_Gym_1F_EventScript_CheckBuryTrainers::
	goto_if_defeated TRAINER_COLE, LavaridgeTown_Gym_1F_EventScript_CheckBuryGerald
	setobjectmovementtype LOCALID_COLE, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_CheckBuryGerald::
	goto_if_defeated TRAINER_GERALD, LavaridgeTown_Gym_1F_EventScript_CheckBuryAxle
	setobjectmovementtype LOCALID_GERALD, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_CheckBuryAxle::
	goto_if_defeated TRAINER_AXLE, LavaridgeTown_Gym_1F_EventScript_CheckBuryDanielle
	setobjectmovementtype LOCALID_AXLE, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_CheckBuryDanielle::
	goto_if_defeated TRAINER_DANIELLE, LavaridgeTown_Gym_1F_EventScript_EndCheckBuryTrainers
	setobjectmovementtype LOCALID_DANIELLE, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_EndCheckBuryTrainers::
	return

LavaridgeTown_Gym_1F_EventScript_Flannery::
	trainerbattle_single TRAINER_FLANNERY_1, LavaridgeTown_Gym_1F_Text_FlanneryIntro, LavaridgeTown_Gym_1F_Text_FlanneryDefeat, LavaridgeTown_Gym_1F_EventScript_FlanneryDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, LavaridgeTown_Gym_1F_EventScript_FlanneryRematch
	goto_if_unset FLAG_RECEIVED_TM_OVERHEAT, LavaridgeTown_Gym_1F_EventScript_GiveOverheat2
	msgbox LavaridgeTown_Gym_1F_Text_FlanneryPostBattle, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_FlanneryDefeated::
	message LavaridgeTown_Gym_1F_Text_ReceivedHeatBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox LavaridgeTown_Gym_1F_Text_ExplainHeatBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_WHITEOUT_TO_LAVARIDGE
	setflag FLAG_DEFEATED_LAVARIDGE_GYM
	setflag FLAG_BADGE04_GET
	addvar VAR_PETALBURG_GYM_STATE, 1
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	setvar VAR_0x8008, 4
	call Common_EventScript_SetGymTrainers
	setflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLY
	setvar VAR_LAVARIDGE_TOWN_STATE, 1
	call LavaridgeTown_Gym_1F_EventScript_GiveOverheat
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox LavaridgeTown_Gym_1F_Text_RegisteredFlannery, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_FLANNERY_MATCH_CALL
	release
	end

LavaridgeTown_Gym_1F_EventScript_GiveOverheat2::
	giveitem ITEM_TM_OVERHEAT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox LavaridgeTown_Gym_1F_Text_ExplainOverheat, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_OVERHEAT
	release
	end

LavaridgeTown_Gym_1F_EventScript_GiveOverheat::
	giveitem ITEM_TM_OVERHEAT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox LavaridgeTown_Gym_1F_Text_ExplainOverheat, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_OVERHEAT
	return

LavaridgeTown_Gym_1F_EventScript_FlanneryRematch::
	trainerbattle_rematch_double TRAINER_FLANNERY_1, LavaridgeTown_Gym_1F_Text_FlanneryPreRematch, LavaridgeTown_Gym_1F_Text_FlanneryRematchDefeat, LavaridgeTown_Gym_1F_Text_FlanneryRematchNeedTwoMons
	msgbox LavaridgeTown_Gym_1F_Text_FlanneryPostRematch, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_Cole::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_COLE, LOCALID_COLE, LavaridgeTown_Gym_1F_Text_ColeIntro, LavaridgeTown_Gym_1F_Text_ColeDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_1F_Text_ColePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_EventScript_CheckTrainerScript::
	call LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars
	release
	special ShouldTryGetTrainerScript
	goto_if_eq VAR_RESULT, 1, EventScript_GotoTrainerScript
	end

LavaridgeTown_Gym_1F_EventScript_Axle::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_AXLE, LOCALID_AXLE, LavaridgeTown_Gym_1F_Text_AxleIntro, LavaridgeTown_Gym_1F_Text_AxleDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_1F_Text_AxlePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Keegan::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_KEEGAN, LOCALID_KEEGAN, LavaridgeTown_Gym_B1F_Text_KeeganIntro, LavaridgeTown_Gym_B1F_Text_KeeganDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_B1F_Text_KeeganPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_Danielle::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_DANIELLE, LOCALID_DANIELLE, LavaridgeTown_Gym_1F_Text_DanielleIntro, LavaridgeTown_Gym_1F_Text_DanielleDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_1F_Text_DaniellePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_Gerald::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_GERALD, LOCALID_GERALD, LavaridgeTown_Gym_1F_Text_GeraldIntro, LavaridgeTown_Gym_1F_Text_GeraldDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_1F_Text_GeraldPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Jace::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_JACE, LOCALID_JACE, LavaridgeTown_Gym_B1F_Text_JaceIntro, LavaridgeTown_Gym_B1F_Text_JaceDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_B1F_Text_JacePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Jeff::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_JEFF, LOCALID_JEFF, LavaridgeTown_Gym_B1F_Text_JeffIntro, LavaridgeTown_Gym_B1F_Text_JeffDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_B1F_Text_JeffPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Eli::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_ELI, LOCALID_ELI, LavaridgeTown_Gym_B1F_Text_EliIntro, LavaridgeTown_Gym_B1F_Text_EliDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_B1F_Text_EliPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, LavaridgeTown_Gym_1F_EventScript_GymGuidePostVictory
	msgbox LavaridgeTown_Gym_1F_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_GymGuidePostVictory::
	msgbox LavaridgeTown_Gym_1F_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE04_GET, LavaridgeTown_Gym_1F_EventScript_GymStatueCertified
	goto LavaridgeTown_Gym_1F_EventScript_GymStatue
	end

LavaridgeTown_Gym_1F_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE04_GET, LavaridgeTown_Gym_1F_EventScript_GymStatueCertified
	goto LavaridgeTown_Gym_1F_EventScript_GymStatue
	end

LavaridgeTown_Gym_1F_EventScript_GymStatueCertified::
	msgbox LavaridgeTown_Gym_1F_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

LavaridgeTown_Gym_1F_EventScript_GymStatue::
	msgbox LavaridgeTown_Gym_1F_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

LavaridgeTown_Gym_1F_Text_GymGuideAdvice:
	.string "Này, mọi chuyện thế nào rồi, CHAMPION\n"
	.string "tương lai {PLAYER}?\p"
	.string "FLANNERY, GYM LEADER của LAVARIDGE,\n"
	.string "sử dụng POKéMON hệ FIRE.\p"
	.string "Niềm đam mê POKéMON của cô ấy còn cháy\n"
	.string "dữ dội và nóng bỏng hơn cả núi lửa.\p"
	.string "Đừng đến quá gần cô ấy, không là bỏng\n"
	.string "đấy! Cứ dội nước cho nguội rồi xông\l"
	.string "lên!$"

LavaridgeTown_Gym_1F_Text_GymGuidePostVictory:
	.string "Chà! Đúng là một trận đấu nóng bỏng!$"

LavaridgeTown_Gym_1F_Text_ColeIntro:
	.string "Ái ái ái ái! Khiếp, nóng quá!$"

LavaridgeTown_Gym_1F_Text_ColeDefeat:
	.string "Mồ hôi chảy vào mắt làm tôi chẳng nhìn\n"
	.string "thấy gì...$"

LavaridgeTown_Gym_1F_Text_ColePostBattle:
	.string "Vùi mình trong cát nóng giúp máu lưu\n"
	.string "thông tốt hơn.\p"
	.string "Cách này rất hiệu quả để chữa đau\n"
	.string "khớp.$"

LavaridgeTown_Gym_1F_Text_AxleIntro:
	.string "Tôi đang cố giải tỏa căng thẳng. Đừng\n"
	.string "đến đây làm tôi căng thẳng thêm!$"

LavaridgeTown_Gym_1F_Text_AxleDefeat:
	.string "Mong FLANNERY sẽ thiêu cậu ra trò!$"

LavaridgeTown_Gym_1F_Text_AxlePostBattle:
	.string "Hààà... Phù...\p"
	.string "Vùi mình trong cát nóng quá lâu sẽ\n"
	.string "khiến người ta kiệt sức...$"

LavaridgeTown_Gym_B1F_Text_KeeganIntro:
	.string "Chắc giờ bạn đã bắt đầu mệt rồi. Bạn\n"
	.string "muốn nghỉ ngơi trong cát nóng, phải\l"
	.string "không?\p"
	.string "Nhưng bạn nên biết rằng giữ vững ý chí\n"
	.string "là một năng lực quan trọng đối với mọi\l"
	.string "HLV.$"

LavaridgeTown_Gym_B1F_Text_KeeganDefeat:
	.string "Đùa với lửa thì có ngày bị bỏng...$"

LavaridgeTown_Gym_B1F_Text_KeeganPostBattle:
	.string "Thực lực của bạn là thật... Nhưng\n"
	.string "LEADER FLANNERY của chúng tôi rất\l"
	.string "mạnh.\p"
	.string "Nếu không cẩn thận, bạn sẽ bị bỏng nặng\n"
	.string "đấy.$"

LavaridgeTown_Gym_1F_Text_GeraldIntro:
	.string "POKéMON của bạn có chịu nổi sức nóng\n"
	.string "392 độ không?$"

LavaridgeTown_Gym_1F_Text_GeraldDefeat:
	.string "Lửa vẫn chưa cháy đủ nóng...$"

LavaridgeTown_Gym_1F_Text_GeraldPostBattle:
	.string "Nhiệt độ của magma là 392 độ.\p"
	.string "POKéMON của bạn đã đánh bại tôi, vậy\n"
	.string "nên chúng chắc chắn sống khỏe trong\l"
	.string "magma.$"

LavaridgeTown_Gym_1F_Text_DanielleIntro:
	.string "Ừm... Được thôi, tôi sẽ đấu với bạn.$"

LavaridgeTown_Gym_1F_Text_DanielleDefeat:
	.string "Ôi, nhưng bạn mạnh quá.$"

LavaridgeTown_Gym_1F_Text_DaniellePostBattle:
	.string "Tôi sẽ trở thành một HLV vừa xinh\n"
	.string "đẹp vừa mạnh mẽ như FLANNERY.$"

LavaridgeTown_Gym_B1F_Text_JaceIntro:
	.string "Nhanh lên nào! Đánh đi trước khi nhiệt\n"
	.string "huyết của tôi nguội mất!$"

LavaridgeTown_Gym_B1F_Text_JaceDefeat:
	.string "Nơi này nóng đến vậy mà trái tim tôi lại\n"
	.string "bị băng giá siết chặt...$"

LavaridgeTown_Gym_B1F_Text_JacePostBattle:
	.string "Với tinh thần chiến đấu đang rực cháy\n"
	.string "trong bạn, có lẽ bạn đủ sức đối đầu với\l"
	.string "LEADER của chúng tôi.$"

LavaridgeTown_Gym_B1F_Text_JeffIntro:
	.string "Thấy ngọn lửa bùng cháy dữ dội chưa?\n"
	.string "Chúng đang phấn khích chờ tôi chiến\l"
	.string "thắng đấy!$"

LavaridgeTown_Gym_B1F_Text_JeffDefeat:
	.string "Có gì đó không ổn rồi.$"

LavaridgeTown_Gym_B1F_Text_JeffPostBattle:
	.string "Thì sao chứ? Tôi hỏi thì sao nào? Tôi\n"
	.string "có thể đi chân trần trên than hồng!\p"
	.string "...Đừng hòng bắt chước đấy!$"

LavaridgeTown_Gym_B1F_Text_EliIntro:
	.string "Tôi yêu núi non, nhưng đặc biệt yêu núi\n"
	.string "lửa.$"

LavaridgeTown_Gym_B1F_Text_EliDefeat:
	.string "Có vẻ tôi đã thua mà chưa lúc nào nắm\n"
	.string "được thế chủ động.$"

LavaridgeTown_Gym_B1F_Text_EliPostBattle:
	.string "Tôi ở lại đây vì đã trở thành người hâm\n"
	.string "mộ sức mạnh của FLANNERY.\p"
	.string "Hê hê hê.$"

LavaridgeTown_Gym_1F_Text_FlanneryIntro:
	.string "Chào mừng... Không, khoan đã.\p"
	.string "HLV bé nhỏ kia, thật đáng khen khi\n"
	.string "ngươi đã đến được đây!\p"
	.string "Ta được giao trọng trách... Không,\n"
	.string "khoan đã.\p"
	.string "Ta là FLANNERY, GYM LEADER của nơi này!\p"
	.string "Ờm... Chớ coi thường ta dù ta mới chỉ\n"
	.string "làm LEADER chưa lâu!\p"
	.string "Với kỹ năng thừa hưởng từ ông mình,\n"
	.string "ta sẽ, ờm... cho ngươi thấy những chiêu\l"
	.string "thức nóng bỏng mà chúng ta đã tôi\l"
	.string "luyện trên mảnh đất này!$"

LavaridgeTown_Gym_1F_Text_FlanneryDefeat:
	.string "Ôi... Có lẽ tôi đã cố gắng quá sức...\p"
	.string "Tôi... Tôi chỉ mới trở thành GYM LEADER\n"
	.string "gần đây.\p"
	.string "Tôi đã quá cố gắng để trở thành một\n"
	.string "người không phải mình.\p"
	.string "Tôi phải làm mọi thứ theo cách tự nhiên\n"
	.string "của mình. Nếu không, POKéMON của tôi sẽ\l"
	.string "bối rối.\p"
	.string "Cảm ơn bạn đã giúp tôi hiểu ra. Vì điều\n"
	.string "đó, bạn xứng đáng nhận thứ này.$"

LavaridgeTown_Gym_1F_Text_ReceivedHeatBadge:
	.string "{PLAYER} đã nhận được HEAT BADGE từ\n"
	.string "FLANNERY.$"

LavaridgeTown_Gym_1F_Text_ExplainHeatBadgeTakeThis:
	.string "Khi có HEAT BADGE, mọi POKéMON từ Level\n"
	.string "50 trở xuống, kể cả những POKéMON bạn\l"
	.string "nhận được qua trao đổi, sẽ hoàn toàn\l"
	.string "nghe lời bạn.\p"
	.string "Nó cũng cho phép POKéMON sử dụng chiêu\n"
	.string "HM STRENGTH ngoài trận đấu.\p"
	.string "Đây là món quà thay cho lời cảm ơn của\n"
	.string "tôi. Đừng ngại, cứ nhận lấy!$"

LavaridgeTown_Gym_1F_Text_ExplainOverheat:
	.string "TM50 đó chứa OVERHEAT.\p"
	.string "Chiêu này gây sát thương cực lớn cho\n"
	.string "đối thủ.\p"
	.string "Nhưng nó cũng làm SP. ATK của POKéMON\n"
	.string "sử dụng giảm mạnh. Có lẽ nó không thích\l"
	.string "hợp với những trận đấu kéo dài.$"

LavaridgeTown_Gym_1F_Text_RegisteredFlannery:
	.string "Đã đăng ký GYM LEADER FLANNERY vào\n"
	.string "POKéNAV.$"

LavaridgeTown_Gym_1F_Text_FlanneryPostBattle:
	.string "Sức mạnh của bạn khiến tôi nhớ đến một\n"
	.string "người...\p"
	.string "A! Tôi biết rồi! Cách bạn chiến đấu giống\n"
	.string "NORMAN, GYM LEADER của PETALBURG.$"

LavaridgeTown_Gym_1F_Text_GymStatue:
	.string "LAVARIDGE TOWN POKéMON GYM$"

LavaridgeTown_Gym_1F_Text_GymStatueCertified:
	.string "LAVARIDGE TOWN POKéMON GYM\p"
	.string "FLANNERY'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"

LavaridgeTown_Gym_1F_Text_FlanneryPreRematch:
	.string "FLANNERY: Thua một trận không thể\n"
	.string "khiến tôi nhụt chí.\p"
	.string "Tôi yêu POKéMON. Tôi yêu chiến đấu. Và...\n"
	.string "Tôi yêu GYM này!\p"
	.string "Hãy trao đổi những chiêu thức siêu\n"
	.string "nóng bỏng trong một trận đấu nữa nào!$"

LavaridgeTown_Gym_1F_Text_FlanneryRematchDefeat:
	.string "Phù! Sắp phun trào rồi!$"

LavaridgeTown_Gym_1F_Text_FlanneryPostRematch:
	.string "FLANNERY: Tôi đã thua, nhưng hoàn toàn\n"
	.string "mãn nguyện.\p"
	.string "Hiếm khi tôi được tận hưởng một trận\n"
	.string "đấu nóng bỏng đến vậy.\p"
	.string "Lần sau chúng ta lại đấu một trận như\n"
	.string "thế nhé!$"

LavaridgeTown_Gym_1F_Text_FlanneryRematchNeedTwoMons:
	.string "FLANNERY: Thua một trận không thể\n"
	.string "khiến tôi nhụt chí.\p"
	.string "Tôi yêu POKéMON. Tôi yêu chiến đấu. Và...\n"
	.string "Tôi yêu GYM này!\p"
	.string "Hãy trao đổi những chiêu thức siêu\n"
	.string "nóng bỏng trong một trận đấu nữa nào!\p"
	.string "Ơ, khoan đã. Bạn chỉ có một POKéMON có\n"
	.string "thể chiến đấu thôi sao?\p"
	.string "Tôi rất tiếc phải nói thế này, nhưng lần\n"
	.string "tới gặp tôi, hãy mang theo ít nhất hai\l"
	.string "POKéMON.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global LavaridgeTown_Gym_1F_Text_GymGuideAdvice
	.global LavaridgeTown_Gym_1F_Text_GymGuidePostVictory
	.global LavaridgeTown_Gym_1F_Text_ColeIntro
	.global LavaridgeTown_Gym_1F_Text_ColeDefeat
	.global LavaridgeTown_Gym_1F_Text_ColePostBattle
	.global LavaridgeTown_Gym_1F_Text_AxleIntro
	.global LavaridgeTown_Gym_1F_Text_AxleDefeat
	.global LavaridgeTown_Gym_1F_Text_AxlePostBattle
	.global LavaridgeTown_Gym_B1F_Text_KeeganIntro
	.global LavaridgeTown_Gym_B1F_Text_KeeganDefeat
	.global LavaridgeTown_Gym_B1F_Text_KeeganPostBattle
	.global LavaridgeTown_Gym_1F_Text_GeraldIntro
	.global LavaridgeTown_Gym_1F_Text_GeraldDefeat
	.global LavaridgeTown_Gym_1F_Text_GeraldPostBattle
	.global LavaridgeTown_Gym_1F_Text_DanielleIntro
	.global LavaridgeTown_Gym_1F_Text_DanielleDefeat
	.global LavaridgeTown_Gym_1F_Text_DaniellePostBattle
	.global LavaridgeTown_Gym_B1F_Text_JaceIntro
	.global LavaridgeTown_Gym_B1F_Text_JaceDefeat
	.global LavaridgeTown_Gym_B1F_Text_JacePostBattle
	.global LavaridgeTown_Gym_B1F_Text_JeffIntro
	.global LavaridgeTown_Gym_B1F_Text_JeffDefeat
	.global LavaridgeTown_Gym_B1F_Text_JeffPostBattle
	.global LavaridgeTown_Gym_B1F_Text_EliIntro
	.global LavaridgeTown_Gym_B1F_Text_EliDefeat
	.global LavaridgeTown_Gym_B1F_Text_EliPostBattle
	.global LavaridgeTown_Gym_1F_Text_FlanneryIntro
	.global LavaridgeTown_Gym_1F_Text_FlanneryDefeat
	.global LavaridgeTown_Gym_1F_Text_ReceivedHeatBadge
	.global LavaridgeTown_Gym_1F_Text_ExplainHeatBadgeTakeThis
	.global LavaridgeTown_Gym_1F_Text_ExplainOverheat
	.global LavaridgeTown_Gym_1F_Text_RegisteredFlannery
	.global LavaridgeTown_Gym_1F_Text_FlanneryPostBattle
	.global LavaridgeTown_Gym_1F_Text_FlanneryPreRematch
	.global LavaridgeTown_Gym_1F_Text_FlanneryRematchDefeat
	.global LavaridgeTown_Gym_1F_Text_FlanneryPostRematch
	.global LavaridgeTown_Gym_1F_Text_FlanneryRematchNeedTwoMons
@ END GENERATED LOCALIZATION EXPORTS
