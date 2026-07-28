Route104_MrBrineysHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route104_MrBrineysHouse_OnTransition
	.byte 0

Route104_MrBrineysHouse_OnTransition:
	setflag FLAG_LANDMARK_MR_BRINEY_HOUSE
	call_if_eq VAR_BRINEY_HOUSE_STATE, 1, Route104_MrBrineysHouse_EventScript_SetBrineyPeekoPos
	call_if_set FLAG_RECEIVED_POKENAV, Route104_MrBrineysHouse_EventScript_HideRustboroRival
	end

Route104_MrBrineysHouse_EventScript_HideRustboroRival::
	setflag FLAG_HIDE_RUSTBORO_CITY_RIVAL
	return

Route104_MrBrineysHouse_EventScript_SetBrineyPeekoPos::
	setobjectxyperm LOCALID_BRINEYS_HOUSE_BRINEY, 9, 3
	setobjectmovementtype LOCALID_BRINEYS_HOUSE_BRINEY, MOVEMENT_TYPE_WALK_SEQUENCE_DOWN_LEFT_UP_RIGHT
	setobjectxyperm LOCALID_BRINEYS_HOUSE_PEEKO, 9, 6
	setobjectmovementtype LOCALID_BRINEYS_HOUSE_PEEKO, MOVEMENT_TYPE_WALK_SEQUENCE_LEFT_UP_RIGHT_DOWN
	return

Route104_MrBrineysHouse_EventScript_Briney::
	lock
	faceplayer
	call_if_unset FLAG_MR_BRINEY_SAILING_INTRO, Route104_MrBrineysHouse_EventScript_SailingIntro
	goto_if_unset FLAG_DELIVERED_STEVEN_LETTER, Route104_MrBrineysHouse_EventScript_SailBothDeliveries
	goto_if_unset FLAG_DELIVERED_DEVON_GOODS, Route104_MrBrineysHouse_EventScript_SailDeliverPackage
	goto Route104_MrBrineysHouse_EventScript_WhereAreWeBound
	end

Route104_MrBrineysHouse_EventScript_SailingIntro::
	setflag FLAG_MR_BRINEY_SAILING_INTRO
	msgbox Route104_MrBrineysHouse_Text_WaitUpPeeko, MSGBOX_DEFAULT
	msgbox Route104_MrBrineysHouse_Text_ItsYouLetsSailToDewford, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route104_MrBrineysHouse_EventScript_DeclineDeliverySailing
	goto Route104_MrBrineysHouse_EventScript_SailToDewford
	end

Route104_MrBrineysHouse_EventScript_WhereAreWeBound::
	message Route104_MrBrineysHouse_Text_WhereAreWeBound
	waitmessage
	multichoicedefault 20, 8, MULTI_BRINEY_OFF_DEWFORD, 1, FALSE
	switch VAR_RESULT
	case 0, Route104_MrBrineysHouse_EventScript_SailToDewford
	case 1, Route104_MrBrineysHouse_EventScript_DeclineSailing
	case MULTI_B_PRESSED, Route104_MrBrineysHouse_EventScript_DeclineSailing
	end

Route104_MrBrineysHouse_EventScript_SailBothDeliveries::
	msgbox Route104_MrBrineysHouse_Text_NeedToMakeDeliveriesSailToDewford, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route104_MrBrineysHouse_EventScript_DeclineDeliverySailing
	goto Route104_MrBrineysHouse_EventScript_SailToDewford
	end

Route104_MrBrineysHouse_EventScript_SailDeliverPackage::
	msgbox Route104_MrBrineysHouse_Text_NeedToDeliverPackageSailToDewford, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route104_MrBrineysHouse_EventScript_DeclineDeliverySailing
	goto Route104_MrBrineysHouse_EventScript_SailToDewford
	end

Route104_MrBrineysHouse_EventScript_DeclineDeliverySailing::
	msgbox Route104_MrBrineysHouse_Text_DeclineDeliverySail, MSGBOX_DEFAULT
	release
	end

Route104_MrBrineysHouse_EventScript_DeclineSailing::
	msgbox Route104_MrBrineysHouse_Text_TellMeWheneverYouWantToSail, MSGBOX_DEFAULT
	release
	end

Route104_MrBrineysHouse_EventScript_SailToDewford::
	msgbox Route104_MrBrineysHouse_Text_SetSailForDewford, MSGBOX_DEFAULT
	call EventScript_BackupMrBrineyLocation
	setvar VAR_BOARD_BRINEY_BOAT_STATE, 1
	clearflag FLAG_HIDE_ROUTE_104_MR_BRINEY
	setflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	setflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	setvar VAR_RUSTBORO_CITY_STATE, 8
	setvar VAR_ROUTE104_STATE, 2
	setflag FLAG_HIDE_RUSTBORO_CITY_RIVAL
	setflag FLAG_HIDE_ROUTE_104_RIVAL
	warp MAP_ROUTE104, 13, 51
	waitstate
	releaseall
	end

Route104_MrBrineysHouse_EventScript_Peeko::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
	msgbox Route104_MrBrineysHouse_Text_Peeko, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route104_MrBrineysHouse_Text_WaitUpPeeko:
	.string "MR. BRINEY: Khoan nào, cô bé! Chờ ta\n"
	.string "với, PEEKO!$"

Route104_MrBrineysHouse_Text_ItsYouLetsSailToDewford:
	.string "Hửm? Cháu là {PLAYER}{KUN}! Cháu đã\n"
	.string "cứu PEEKO yêu quý của ta! Ta nợ cháu\l"
	.string "nhiều lắm!\p"
	.string "Gì cơ? Cháu muốn ra khơi cùng ta à?\p"
	.string "Hừm hừm...\p"
	.string "Cháu có một LETTER cần gửi đến DEWFORD\n"
	.string "và một kiện hàng cần chuyển đến\l"
	.string "SLATEPORT, đúng không?\p"
	.string "Cuộc sống của cháu bận rộn thật đấy!\p"
	.string "Nhưng tất nhiên, chuyện cháu nhờ hoàn\n"
	.string "toàn không thành vấn đề.\p"
	.string "Cháu tìm đúng người rồi! Chúng ta sẽ ra\n"
	.string "khơi đến DEWFORD.$"

Route104_MrBrineysHouse_Text_SetSailForDewford:
	.string "MR. BRINEY: Vậy thì đến DEWFORD!\p"
	.string "Nhổ neo! PEEKO, chúng ta ra khơi thôi,\n"
	.string "cục cưng!$"

Route104_MrBrineysHouse_Text_DeclineDeliverySail:
	.string "MR. BRINEY: Vậy sao? Chuyện giao hàng\n"
	.string "của cháu có thể đợi à?\p"
	.string "Khi nào muốn ra khơi thì cứ bảo ta nhé!$"

Route104_MrBrineysHouse_Text_NeedToMakeDeliveriesSailToDewford:
	.string "MR. BRINEY: A-hô! Ta biết chính xác\n"
	.string "cháu muốn nói gì!\p"
	.string "Cháu cần chuyển một LETTER đến\n"
	.string "DEWFORD và một kiện hàng đến\l"
	.string "SLATEPORT.\p"
	.string "Việc cháu cần ta làm chẳng có gì khó. Ta\n"
	.string "chính là người phù hợp!\p"
	.string "Trước tiên, chúng ta sẽ ra khơi đến\n"
	.string "DEWFORD.$"

Route104_MrBrineysHouse_Text_NeedToDeliverPackageSailToDewford:
	.string "MR. BRINEY: A-hô! Ta biết chính xác\n"
	.string "cháu muốn nói gì!\p"
	.string "Cháu cần chuyển một kiện hàng cho CAPT.\n"
	.string "STERN tại SLATEPORT.\p"
	.string "Việc cháu cần ta làm chẳng có gì khó. Ta\n"
	.string "chính là người phù hợp!\p"
	.string "Trước tiên, chúng ta sẽ ra khơi đến\n"
	.string "DEWFORD.$"

Route104_MrBrineysHouse_Text_WhereAreWeBound:
	.string "MR. BRINEY: A-hô! Vì cháu, ta có thể ra\n"
	.string "khơi bất cứ lúc nào!\p"
	.string "Nào, người bạn của ta, chúng ta sẽ đi\n"
	.string "đâu?$"

Route104_MrBrineysHouse_Text_TellMeWheneverYouWantToSail:
	.string "MR. BRINEY: Vậy sao? PEEKO nợ cháu cả\n"
	.string "mạng sống.\p"
	.string "Khi nào muốn ra khơi thì cứ bảo ta nhé!$"

Route104_MrBrineysHouse_Text_Peeko:
	.string "PEEKO: Pii piihyoro!$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global Route104_MrBrineysHouse_Text_WaitUpPeeko
	.global Route104_MrBrineysHouse_Text_ItsYouLetsSailToDewford
	.global Route104_MrBrineysHouse_Text_SetSailForDewford
	.global Route104_MrBrineysHouse_Text_DeclineDeliverySail
	.global Route104_MrBrineysHouse_Text_NeedToMakeDeliveriesSailToDewford
	.global Route104_MrBrineysHouse_Text_NeedToDeliverPackageSailToDewford
	.global Route104_MrBrineysHouse_Text_WhereAreWeBound
	.global Route104_MrBrineysHouse_Text_TellMeWheneverYouWantToSail
@ END GENERATED LOCALIZATION EXPORTS
