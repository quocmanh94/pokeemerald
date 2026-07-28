FallarborTown_CozmosHouse_MapScripts::
	.byte 0

FallarborTown_CozmosHouse_EventScript_ProfCozmo::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_RETURN, FallarborTown_CozmosHouse_EventScript_GaveMeteorite
	checkitem ITEM_METEORITE
	goto_if_eq VAR_RESULT, TRUE, FallarborTown_CozmosHouse_EventScript_PlayerHasMeteorite
	msgbox FallarborTown_CozmosHouse_Text_MeteoriteWillNeverBeMineNow, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_PlayerHasMeteorite::
	call_if_unset FLAG_TEMP_2, FallarborTown_CozmosHouse_EventScript_NoticeMeteorite
	call_if_set FLAG_TEMP_2, FallarborTown_CozmosHouse_EventScript_AskForMeteorite
	goto_if_eq VAR_RESULT, NO, FallarborTown_CozmosHouse_EventScript_DeclineGiveMeteorite
	msgbox FallarborTown_CozmosHouse_Text_PleaseUseThisTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_RETURN
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setvar VAR_0x8004, ITEM_METEORITE
	call Common_EventScript_PlayerHandedOverTheItem
	setflag FLAG_RECEIVED_TM_RETURN
	msgbox FallarborTown_CozmosHouse_Text_ReallyGoingToHelpMyResearch, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_NoticeMeteorite::
	msgbox FallarborTown_CozmosHouse_Text_MeteoriteWillNeverBeMineNow, MSGBOX_DEFAULT
	msgbox FallarborTown_CozmosHouse_Text_IsThatMeteoriteMayIHaveIt, MSGBOX_YESNO
	return

FallarborTown_CozmosHouse_EventScript_AskForMeteorite::
	msgbox FallarborTown_CozmosHouse_Text_MayIHaveMeteorite, MSGBOX_YESNO
	return

FallarborTown_CozmosHouse_EventScript_DeclineGiveMeteorite::
	setflag FLAG_TEMP_2
	msgbox FallarborTown_CozmosHouse_Text_CrushedWithDisappointment, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_GaveMeteorite::
	msgbox FallarborTown_CozmosHouse_Text_ReallyGoingToHelpMyResearch, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_CozmosWife::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_RETURN, FallarborTown_CozmosHouse_EventScript_CozmoIsHappy
	goto_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, FallarborTown_CozmosHouse_EventScript_CozmoIsSad
	msgbox FallarborTown_CozmosHouse_Text_CozmoWentToMeteorFalls, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_CozmoIsSad::
	msgbox FallarborTown_CozmosHouse_Text_FeelSorryForCozmo, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_CozmoIsHappy::
	msgbox FallarborTown_CozmosHouse_Text_CozmoIsSoHappy, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_Text_MeteoriteWillNeverBeMineNow:
	.string "PROF. COZMO: Ôi... Đáng lẽ tôi không nên\n"
	.string "để mình bị lừa rồi nói cho TEAM MAGMA\l"
	.string "biết nơi có thể tìm thấy METEORITES...\p"
	.string "Viên METEORITE từ METEOR FALLS ấy...\n"
	.string "Giờ nó sẽ chẳng bao giờ thuộc về tôi...$"

FallarborTown_CozmosHouse_Text_IsThatMeteoriteMayIHaveIt:
	.string "Ồ! Hả?\p"
	.string "Món đồ đó...\p"
	.string "Chẳng lẽ là...\p"
	.string "Đó có phải viên METEORITE mà TEAM\n"
	.string "MAGMA đã lấy từ METEOR FALLS không?\p"
	.string "Xin bạn hãy cho tôi nó được không?\p"
	.string "Tôi không xin miễn phí đâu. Bạn đổi nó\n"
	.string "lấy TM này nhé?$"

FallarborTown_CozmosHouse_Text_PleaseUseThisTM:
	.string "PROF. COZMO: TM này thể hiện lòng biết\n"
	.string "ơn của tôi. Xin hãy sử dụng nó!$"

FallarborTown_CozmosHouse_Text_ReallyGoingToHelpMyResearch:
	.string "PROF. COZMO: Ôi, tôi không thể tin nổi.\n"
	.string "Thật sự tuyệt vời quá!\p"
	.string "Nó sẽ giúp ích rất nhiều cho nghiên cứu\n"
	.string "của tôi!$"

FallarborTown_CozmosHouse_Text_CrushedWithDisappointment:
	.string "PROF. COZMO: Ôi, nhưng... Tôi thất vọng\n"
	.string "đến suy sụp mất...$"

FallarborTown_CozmosHouse_Text_MayIHaveMeteorite:
	.string "PROF. COZMO: Xin bạn hãy cho tôi viên\n"
	.string "METEORITE đó được không?\p"
	.string "Tôi không xin miễn phí đâu. Bạn đổi nó\n"
	.string "lấy TM này nhé?$"

FallarborTown_CozmosHouse_Text_CozmoWentToMeteorFalls:
	.string "PROF. COZMO đã đến METEOR FALLS trên\n"
	.string "ROUTE 114 cùng vài người của TEAM\l"
	.string "MAGMA.$"

FallarborTown_CozmosHouse_Text_FeelSorryForCozmo:
	.string "Tội nghiệp PROF. COZMO... Ông ấy buồn bã\n"
	.string "quá... Tôi thấy thương ông ấy.$"

FallarborTown_CozmosHouse_Text_CozmoIsSoHappy:
	.string "Nhìn PROF. COZMO kìa... Ông ấy vui quá!\n"
	.string "Trông thật đáng yêu.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global FallarborTown_CozmosHouse_Text_MeteoriteWillNeverBeMineNow
	.global FallarborTown_CozmosHouse_Text_IsThatMeteoriteMayIHaveIt
	.global FallarborTown_CozmosHouse_Text_PleaseUseThisTM
	.global FallarborTown_CozmosHouse_Text_ReallyGoingToHelpMyResearch
	.global FallarborTown_CozmosHouse_Text_CrushedWithDisappointment
	.global FallarborTown_CozmosHouse_Text_MayIHaveMeteorite
	.global FallarborTown_CozmosHouse_Text_CozmoWentToMeteorFalls
	.global FallarborTown_CozmosHouse_Text_FeelSorryForCozmo
	.global FallarborTown_CozmosHouse_Text_CozmoIsSoHappy
@ END GENERATED LOCALIZATION EXPORTS
