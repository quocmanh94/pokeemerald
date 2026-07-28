DewfordTown_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DewfordTown_Gym_OnTransition
	.byte 0

DewfordTown_Gym_OnTransition:
	call DewfordTown_Gym_EventScript_SetFlashLevel
	end

DewfordTown_Gym_EventScript_SetFlashLevel::
	goto_if_defeated TRAINER_BRAWLY_1, DewfordTown_Gym_EventScript_SetLightsOn
	call DewfordTown_Gym_EventScript_CountTrainersDefeated
	copyvar VAR_0x8001, VAR_0x8000
	goto_if_eq VAR_0x8000, 0, DewfordTown_Gym_EventScript_SetFlashLevel7
	goto_if_eq VAR_0x8000, 1, DewfordTown_Gym_EventScript_SetFlashLevel6
	goto_if_eq VAR_0x8000, 2, DewfordTown_Gym_EventScript_SetFlashLevel5
	goto_if_eq VAR_0x8000, 3, DewfordTown_Gym_EventScript_SetFlashLevel4
	goto_if_eq VAR_0x8000, 4, DewfordTown_Gym_EventScript_SetFlashLevel3
	goto_if_eq VAR_0x8000, 5, DewfordTown_Gym_EventScript_SetFlashLevel2
	goto DewfordTown_Gym_EventScript_SetFlashLevel1

DewfordTown_Gym_EventScript_SetLightsOn::
	setflashlevel 0
	return

@ Brightest
DewfordTown_Gym_EventScript_SetFlashLevel1::
	setflashlevel 1
	return

DewfordTown_Gym_EventScript_SetFlashLevel2::
	setflashlevel 2
	return

DewfordTown_Gym_EventScript_SetFlashLevel3::
	setflashlevel 3
	return

DewfordTown_Gym_EventScript_SetFlashLevel4::
	setflashlevel 4
	return

DewfordTown_Gym_EventScript_SetFlashLevel5::
	setflashlevel 5
	return

DewfordTown_Gym_EventScript_SetFlashLevel6::
	setflashlevel 6
	return

@ Darkest
DewfordTown_Gym_EventScript_SetFlashLevel7::
	setflashlevel 7
	return

DewfordTown_Gym_EventScript_BrightenRoom::
	call DewfordTown_Gym_EventScript_CountTrainersDefeated
	nop1
	goto_if_eq VAR_0x8000, VAR_0x8001, DewfordTown_Gym_EventScript_NoLightChange
	copyvar VAR_0x8001, VAR_0x8000
	goto_if_eq VAR_0x8000, 1, DewfordTown_Gym_EventScript_AnimateFlash1Trainer
	goto_if_eq VAR_0x8000, 2, DewfordTown_Gym_EventScript_AnimateFlash2Trainers
	goto_if_eq VAR_0x8000, 3, DewfordTown_Gym_EventScript_AnimateFlash3Trainers
	goto_if_eq VAR_0x8000, 4, DewfordTown_Gym_EventScript_AnimateFlash4Trainers
	goto_if_eq VAR_0x8000, 5, DewfordTown_Gym_EventScript_AnimateFlash5Trainers
	goto_if_eq VAR_0x8000, 6, DewfordTown_Gym_EventScript_AnimateFlash6Trainers

DewfordTown_Gym_EventScript_NoLightChange::
	return

@ NOTE: A little confusingly, a larger animateflash param value is a smaller flash radius
DewfordTown_Gym_EventScript_AnimateFlash1Trainer::
	playse SE_SWITCH
	animateflash 6
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash2Trainers::
	playse SE_SWITCH
	animateflash 5
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash3Trainers::
	playse SE_SWITCH
	animateflash 4
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash4Trainers::
	playse SE_SWITCH
	animateflash 3
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash5Trainers::
	playse SE_SWITCH
	animateflash 2
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash6Trainers::
	playse SE_SWITCH
	animateflash 1
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlashFullBrightness::
	playse SE_SWITCH
	animateflash 0
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_CountTrainersDefeated::
	setvar VAR_0x8000, 0
	goto_if_not_defeated TRAINER_TAKAO, DewfordTown_Gym_EventScript_CheckJocelyn
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckJocelyn::
	goto_if_not_defeated TRAINER_JOCELYN, DewfordTown_Gym_EventScript_CheckLaura
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckLaura::
	goto_if_not_defeated TRAINER_LAURA, DewfordTown_Gym_EventScript_CheckBrenden
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckBrenden::
	goto_if_not_defeated TRAINER_BRENDEN, DewfordTown_Gym_EventScript_CheckCristian
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckCristian::
	goto_if_not_defeated TRAINER_CRISTIAN, DewfordTown_Gym_EventScript_CheckLilith
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckLilith::
	goto_if_not_defeated TRAINER_LILITH, DewfordTown_Gym_EventScript_StopCountingTrainers
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_StopCountingTrainers::
	return

DewfordTown_Gym_EventScript_Brawly::
	trainerbattle_single TRAINER_BRAWLY_1, DewfordTown_Gym_Text_BrawlyIntro, DewfordTown_Gym_Text_BrawlyDefeat, DewfordTown_Gym_EventScript_BrawlyDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, DewfordTown_Gym_EventScript_BrawlyRematch
	goto_if_unset FLAG_RECEIVED_TM_BULK_UP, DewfordTown_Gym_EventScript_GiveBulkUp2
	msgbox DewfordTown_Gym_Text_BrawlyPostBattle, MSGBOX_DEFAULT
	release
	end

DewfordTown_Gym_EventScript_BrawlyDefeated::
	call DewfordTown_Gym_EventScript_AnimateFlashFullBrightness
	message DewfordTown_Gym_Text_ReceivedKnuckleBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox DewfordTown_Gym_Text_KnuckleBadgeInfoTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_DEWFORD_GYM
	setflag FLAG_BADGE02_GET
	addvar VAR_PETALBURG_GYM_STATE, 1
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	setvar VAR_0x8008, 2
	call Common_EventScript_SetGymTrainers
	call DewfordTown_Gym_EventScript_GiveBulkUp
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox DewfordTown_Gym_Text_RegisteredBrawly, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_BRAWLY_MATCH_CALL
	setvar VAR_ROXANNE_CALL_STEP_COUNTER, 0
	setflag FLAG_ENABLE_ROXANNE_FIRST_CALL
	release
	end

DewfordTown_Gym_EventScript_GiveBulkUp::
	giveitem ITEM_TM_BULK_UP
	goto_if_eq VAR_RESULT, 0, Common_EventScript_BagIsFull
	msgbox DewfordTown_Gym_Text_ExplainBulkUp, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_BULK_UP
	return

DewfordTown_Gym_EventScript_GiveBulkUp2:
	giveitem ITEM_TM_BULK_UP
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	msgbox DewfordTown_Gym_Text_ExplainBulkUp, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_BULK_UP
	release
	end

DewfordTown_Gym_EventScript_BrawlyRematch::
	trainerbattle_rematch_double TRAINER_BRAWLY_1, DewfordTown_Gym_Text_BrawlyPreRematch, DewfordTown_Gym_Text_BrawlyRematchDefeat, DewfordTown_Gym_Text_BrawlyRematchNeedTwoMons
	msgbox DewfordTown_Gym_Text_BrawlyPostRematch, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_Takao::
	trainerbattle_single TRAINER_TAKAO, DewfordTown_Gym_Text_TakaoIntro, DewfordTown_Gym_Text_TakaoDefeat, DewfordTown_Gym_EventScript_TakaoBrightenRoom
	msgbox DewfordTown_Gym_Text_TakaoPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_TakaoBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Jocelyn::
	trainerbattle_single TRAINER_JOCELYN, DewfordTown_Gym_Text_JocelynIntro, DewfordTown_Gym_Text_JocelynDefeat, DewfordTown_Gym_EventScript_JocelynBrightenRoom
	msgbox DewfordTown_Gym_Text_JocelynPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_JocelynBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Laura::
	trainerbattle_single TRAINER_LAURA, DewfordTown_Gym_Text_LauraIntro, DewfordTown_Gym_Text_LauraDefeat, DewfordTown_Gym_EventScript_LauraBrightenRoom
	msgbox DewfordTown_Gym_Text_LauraPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_LauraBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Brenden::
	trainerbattle_single TRAINER_BRENDEN, DewfordTown_Gym_Text_BrendenIntro, DewfordTown_Gym_Text_BrendenDefeat, DewfordTown_Gym_EventScript_BrendenBrightenRoom
	msgbox DewfordTown_Gym_Text_BrendenPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_BrendenBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Cristian::
	trainerbattle_single TRAINER_CRISTIAN, DewfordTown_Gym_Text_CristianIntro, DewfordTown_Gym_Text_CristianDefeat, DewfordTown_Gym_EventScript_CristianBrightenRoom
	msgbox DewfordTown_Gym_Text_CristianPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_CristianBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Lilith::
	trainerbattle_single TRAINER_LILITH, DewfordTown_Gym_Text_LilithIntro, DewfordTown_Gym_Text_LilithDefeat, DewfordTown_Gym_EventScript_LilithBrightenRoom
	msgbox DewfordTown_Gym_Text_LilithPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_LilithBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_DEWFORD_GYM, DewfordTown_Gym_EventScript_GymGuidePostVictory
	msgbox DewfordTown_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

DewfordTown_Gym_EventScript_GymGuidePostVictory::
	msgbox DewfordTown_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

DewfordTown_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE02_GET, DewfordTown_Gym_EventScript_GymStatueCertified
	goto DewfordTown_Gym_EventScript_GymStatue
	end

DewfordTown_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE02_GET, DewfordTown_Gym_EventScript_GymStatueCertified
	goto DewfordTown_Gym_EventScript_GymStatue
	end

DewfordTown_Gym_EventScript_GymStatueCertified::
	msgbox DewfordTown_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Gym_EventScript_GymStatue::
	msgbox DewfordTown_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Gym_Text_GymGuideAdvice:
	.string "Này, dạo này sao rồi, {PLAYER}, nhà\n"
	.string "CHAMPION tương lai?\p"
	.string "GYM LEADER BRAWLY của DEWFORD chỉ huy\n"
	.string "các POKéMON hệ FIGHTING.\p"
	.string "Dùng POKéMON hệ NORMAL đối đầu anh ấy\n"
	.string "chẳng khác nào tự chuốc rắc rối.\p"
	.string "POKéMON hệ FIGHTING sẽ đánh POKéMON\n"
	.string "hệ NORMAL tơi tả, nên hãy cẩn thận!\p"
	.string "Tệ hơn nữa, GYM tối như đáy đại dương.\p"
	.string "Nhưng nơi này sẽ sáng dần lên sau khi\n"
	.string "cậu đánh bại các HLV chắn đường.\p"
	.string "Được rồi, tiến lên nào!$"

DewfordTown_Gym_Text_GymGuidePostVictory:
	.string "Chà! Trong này sáng quá rồi!\p"
	.string "Tương lai của cậu cũng sáng lạn như\n"
	.string "vậy!$"

DewfordTown_Gym_Text_TakaoIntro:
	.string "Sức mạnh là lẽ phải! Tới đi!$"

DewfordTown_Gym_Text_TakaoDefeat:
	.string "Chưa đủ sức mạnh...$"

DewfordTown_Gym_Text_TakaoPostBattle:
	.string "Kỹ năng của cậu đã vượt qua sức mạnh\n"
	.string "của tôi! Kỹ thuật thật đáng khen!$"

DewfordTown_Gym_Text_JocelynIntro:
	.string "Không cần BRAWLY phải ra tay!\p"
	.string "Tôi sẽ nghiền nát cậu!$"

DewfordTown_Gym_Text_JocelynDefeat:
	.string "Nhưng... Tại sao? Sao tôi có thể thua dễ\n"
	.string "dàng đến thế?$"

DewfordTown_Gym_Text_JocelynPostBattle:
	.string "Tôi sẽ không để thất bại này trở nên vô\n"
	.string "ích. Tôi sẽ lấy nó làm động lực luyện\l"
	.string "tập!\p"
	.string "Một ngày nào đó tôi sẽ trở thành GYM\n"
	.string "LEADER...\p"
	.string "Không, tôi sẽ trở thành POKéMON LEAGUE\n"
	.string "CHAMPION!$"

DewfordTown_Gym_Text_LauraIntro:
	.string "Đừng có coi thường tôi! Có khóc thì\n"
	.string "cũng đừng trách tôi!$"

DewfordTown_Gym_Text_LauraDefeat:
	.string "Oaaaaaaa! Tôi thua rồi!$"

DewfordTown_Gym_Text_LauraPostBattle:
	.string "Tôi chiến đấu trong bóng tối để khiến\n"
	.string "trái tim mình mạnh mẽ hơn.\p"
	.string "Nhưng vì ở đây tối quá nên tôi chẳng\n"
	.string "bao giờ nhìn thấy mặt BRAWLY...$"

DewfordTown_Gym_Text_LilithIntro:
	.string "Ufufu... Cậu đang loạng choạng trong\n"
	.string "bóng tối à?$"

DewfordTown_Gym_Text_LilithDefeat:
	.string "Ôi, cậu... Tôi chẳng muốn biết cậu là ai\n"
	.string "nữa!$"

DewfordTown_Gym_Text_LilithPostBattle:
	.string "Cậu đáng bị lạc đường rồi quay lại tận\n"
	.string "lối vào!$"

DewfordTown_Gym_Text_BrendenIntro:
	.string "Ta sẽ cho cậu thấy khí phách của một\n"
	.string "thủy thủ!$"

DewfordTown_Gym_Text_BrendenDefeat:
	.string "Sao lại thế này? Ta đâu có dễ dàng thua\n"
	.string "như vậy!$"

DewfordTown_Gym_Text_BrendenPostBattle:
	.string "Ồ, phải rồi! Cậu xứng đáng được diện\n"
	.string "kiến GYM LEADER của chúng tôi.$"

DewfordTown_Gym_Text_CristianIntro:
	.string "Muốn đi tiếp thì cậu phải vượt qua tôi!$"

DewfordTown_Gym_Text_CristianDefeat:
	.string "Grrrrr! Bị áp đảo hoàn toàn!$"

DewfordTown_Gym_Text_CristianPostBattle:
	.string "Cậu thắng! Tiến tới giành BADGE đi!$"

DewfordTown_Gym_Text_BrawlyIntro:
	.string "Tôi là BRAWLY! GYM LEADER của DEWFORD!\p"
	.string "Tôi đã được những con sóng dữ nơi đây\n"
	.string "nhào luyện và trở nên cứng cỏi trong\l"
	.string "hang động tối đen!\p"
	.string "Vậy cậu muốn thách đấu tôi sao? Để tôi\n"
	.string "xem cậu có bản lĩnh đến đâu!$"

DewfordTown_Gym_Text_BrawlyDefeat:
	.string "Ghê thật! Cậu đã tạo ra con sóng lớn\n"
	.string "hơn tôi tưởng nhiều!\p"
	.string "Cậu cuốn phăng tôi luôn!\p"
	.string "Được rồi, tôi chịu thua. Hãy nhận GYM\n"
	.string "BADGE này!$"

DewfordTown_Gym_Text_ReceivedKnuckleBadge:
	.string "{PLAYER} đã nhận KNUCKLE BADGE từ\n"
	.string "BRAWLY.$"

DewfordTown_Gym_Text_KnuckleBadgeInfoTakeThis:
	.string "KNUCKLE BADGE sẽ khiến mọi POKéMON từ\n"
	.string "Level 30 trở xuống, kể cả những\l"
	.string "POKéMON nhận qua trao đổi, tuyệt đối\l"
	.string "nghe lời.\p"
	.string "Ngoài ra, cậu sẽ có thể dùng chiêu HM\n"
	.string "FLASH bên ngoài trận đấu.\p"
	.string "Nếu thích, hãy dùng cả TECHNICAL\n"
	.string "MACHINE này nữa.$"

DewfordTown_Gym_Text_ExplainBulkUp:
	.string "TM08 đó chứa BULK UP.\p"
	.string "Chiêu này tăng cả chỉ số ATTACK lẫn\n"
	.string "DEFENSE.\p"
	.string "... ... ... ... ... ...$"

DewfordTown_Gym_Text_RegisteredBrawly:
	.string "Đã đăng ký GYM LEADER BRAWLY vào\n"
	.string "POKéNAV.$"

DewfordTown_Gym_Text_BrawlyPostBattle:
	.string "Tôi có thể thấy một ngày nào đó tài\n"
	.string "năng của cậu sẽ hóa thành con sóng\l"
	.string "khổng lồ, tạo nên cơn bão kinh ngạc\l"
	.string "giữa các HLV!$"

DewfordTown_Gym_Text_GymStatue:
	.string "DEWFORD TOWN POKéMON GYM$"

DewfordTown_Gym_Text_GymStatueCertified:
	.string "DEWFORD TOWN POKéMON GYM\p"
	.string "HLV ĐƯỢC BRAWLY CÔNG NHẬN:\n"
	.string "{PLAYER}$"

DewfordTown_Gym_Text_BrawlyPreRematch:
	.string "BRAWLY: Sóng có thể rút xa, nhưng rồi\n"
	.string "luôn trở lại bờ.\p"
	.string "Một tài năng cuồn cuộn như sóng lớn\n"
	.string "của cậu... Tôi biết cậu sẽ trở lại mà!\p"
	.string "Cho tôi xem cậu đã tiến xa đến mức nào!$"

DewfordTown_Gym_Text_BrawlyRematchDefeat:
	.string "Chà! Lại bị nhấn chìm rồi!$"

DewfordTown_Gym_Text_BrawlyPostRematch:
	.string "BRAWLY: Chiến đấu thật bao la và sâu\n"
	.string "thẳm. Không thể nào nhìn thấy đáy. Hệt\l"
	.string "như biển cả HOENN vậy!$"

DewfordTown_Gym_Text_BrawlyRematchNeedTwoMons:
	.string "BRAWLY: Sóng có thể rút xa, nhưng rồi\n"
	.string "luôn trở lại bờ.\p"
	.string "Một tài năng cuồn cuộn như sóng lớn\n"
	.string "của cậu... Tôi biết cậu sẽ trở lại mà!\p"
	.string "Ồ? Cậu chỉ có một POKéMON có thể chiến\n"
	.string "đấu thôi à.\p"
	.string "Xin lỗi, nhưng hãy quay lại khi cậu có ít\n"
	.string "nhất hai POKéMON nhé.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global DewfordTown_Gym_Text_GymGuideAdvice
	.global DewfordTown_Gym_Text_GymGuidePostVictory
	.global DewfordTown_Gym_Text_TakaoIntro
	.global DewfordTown_Gym_Text_TakaoDefeat
	.global DewfordTown_Gym_Text_TakaoPostBattle
	.global DewfordTown_Gym_Text_JocelynIntro
	.global DewfordTown_Gym_Text_JocelynDefeat
	.global DewfordTown_Gym_Text_JocelynPostBattle
	.global DewfordTown_Gym_Text_LauraIntro
	.global DewfordTown_Gym_Text_LauraDefeat
	.global DewfordTown_Gym_Text_LauraPostBattle
	.global DewfordTown_Gym_Text_LilithIntro
	.global DewfordTown_Gym_Text_LilithDefeat
	.global DewfordTown_Gym_Text_LilithPostBattle
	.global DewfordTown_Gym_Text_BrendenIntro
	.global DewfordTown_Gym_Text_BrendenDefeat
	.global DewfordTown_Gym_Text_BrendenPostBattle
	.global DewfordTown_Gym_Text_CristianIntro
	.global DewfordTown_Gym_Text_CristianDefeat
	.global DewfordTown_Gym_Text_CristianPostBattle
	.global DewfordTown_Gym_Text_BrawlyIntro
	.global DewfordTown_Gym_Text_BrawlyDefeat
	.global DewfordTown_Gym_Text_ReceivedKnuckleBadge
	.global DewfordTown_Gym_Text_KnuckleBadgeInfoTakeThis
	.global DewfordTown_Gym_Text_ExplainBulkUp
	.global DewfordTown_Gym_Text_RegisteredBrawly
	.global DewfordTown_Gym_Text_BrawlyPostBattle
	.global DewfordTown_Gym_Text_GymStatueCertified
	.global DewfordTown_Gym_Text_BrawlyPreRematch
	.global DewfordTown_Gym_Text_BrawlyRematchDefeat
	.global DewfordTown_Gym_Text_BrawlyPostRematch
	.global DewfordTown_Gym_Text_BrawlyRematchNeedTwoMons
@ END GENERATED LOCALIZATION EXPORTS
