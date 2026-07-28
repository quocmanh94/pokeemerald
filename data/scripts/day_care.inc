Route117_EventScript_DaycareMan::
	lock
	faceplayer
	special GetDaycareMonNicknames
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_EGG_WAITING, Route117_EventScript_DaycareEggWaiting
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route117_EventScript_CheckOnOneMon
	goto_if_eq VAR_RESULT, DAYCARE_TWO_MONS, Route117_EventScript_CheckOnTwoMons
	msgbox Route117_Text_SeeWifeIfYoudLikeMeToRaiseMon, MSGBOX_DEFAULT
	release
	end

Route117_EventScript_DaycareEggWaiting::
	msgbox Route117_Text_DoYouWantEgg, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_EventScript_DaycareAcceptEgg
	msgbox Route117_Text_IWillKeepDoYouWantIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_EventScript_DaycareAcceptEgg
	msgbox Route117_Text_IllKeepIt, MSGBOX_DEFAULT
	clearflag FLAG_PENDING_DAYCARE_EGG
	special RejectEggFromDayCare
	release
	end

Route117_EventScript_DaycareAcceptEgg::
	specialvar VAR_RESULT, CalculatePlayerPartyCount
	goto_if_ne VAR_RESULT, PARTY_SIZE, Route117_EventScript_DaycareReceiveEgg
	msgbox Route117_Text_YouHaveNoRoomForIt, MSGBOX_DEFAULT
	release
	end

Route117_EventScript_DaycareReceiveEgg::
	message Route117_Text_ReceivedEgg
	playfanfare MUS_LEVEL_UP
	waitfanfare
	waitbuttonpress
	msgbox Route117_Text_TakeGoodCareOfIt, MSGBOX_DEFAULT
	special GiveEggFromDaycare
	clearflag FLAG_PENDING_DAYCARE_EGG
	release
	end

Route117_EventScript_CheckMonReceivedMail::
	specialvar VAR_RESULT, CheckDaycareMonReceivedMail
	call_if_eq VAR_RESULT, 1, Route117_EventScript_MonReceivedMail
	return

Route117_EventScript_MonReceivedMail::
	msgbox Route117_Text_FriendlyWithOtherTrainersMon, MSGBOX_DEFAULT
	return

Route117_EventScript_CheckOnOneMon::
	special GetDaycareMonNicknames
	msgbox Route117_Text_YourMonIsDoingFine, MSGBOX_DEFAULT
	setvar VAR_0x8004, 0
	call Route117_EventScript_CheckMonReceivedMail
	release
	end

Route117_EventScript_CheckOnTwoMons::
	special GetDaycareMonNicknames
	msgbox Route117_Text_YourMonsAreDoingFine, MSGBOX_DEFAULT
	special SetDaycareCompatibilityString
	special ShowFieldMessageStringVar4
	waitmessage
	waitbuttonpress
	setvar VAR_0x8004, 0
	call Route117_EventScript_CheckMonReceivedMail
	setvar VAR_0x8004, 1
	call Route117_EventScript_CheckMonReceivedMail
	release
	end

Route117_PokemonDayCare_EventScript_DaycareWoman::
	lock
	faceplayer
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_EGG_WAITING, Route117_PokemonDayCare_EventScript_EggWaiting
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route117_PokemonDayCare_EventScript_OneMonInDaycare
	goto_if_eq VAR_RESULT, DAYCARE_TWO_MONS, Route117_PokemonDayCare_EventScript_TwoMonsInDaycare
	msgbox Route117_PokemonDayCare_Text_WouldYouLikeUsToRaiseAMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_PokemonDayCare_EventScript_GiveMonToRaise
	msgbox Route117_PokemonDayCare_Text_FineThenComeAgain, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_GiveMonToRaise::
	specialvar VAR_RESULT, CountPartyNonEggMons
	goto_if_eq VAR_RESULT, 1, Route117_PokemonDayCare_EventScript_OnlyOneMon
	specialvar VAR_RESULT, CountPartyAliveNonEggMons
	goto_if_eq VAR_RESULT, 2, Route117_PokemonDayCare_EventScript_OnlyTwoAliveMons
	msgbox Route117_PokemonDayCare_Text_WhichMonShouldWeRaise, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special ChooseSendDaycareMon
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, Route117_PokemonDayCare_EventScript_ComeAgain
	specialvar VAR_RESULT, CountPartyAliveNonEggMons_IgnoreVar0x8004Slot
	goto_if_eq VAR_RESULT, 0, Route117_PokemonDayCare_EventScript_OnlyOneAliveMon
	specialvar VAR_0x8005, GetSelectedMonNicknameAndSpecies
	waitse
	playmoncry VAR_0x8005, CRY_MODE_NORMAL
	msgbox Route117_PokemonDayCare_Text_WellRaiseYourMon, MSGBOX_DEFAULT
	waitmoncry
	special StoreSelectedPokemonInDaycare
	incrementgamestat GAME_STAT_USED_DAYCARE
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route117_PokemonDayCare_EventScript_CanRaiseOneMore
	release
	end

Route117_PokemonDayCare_EventScript_ComeAgain::
	msgbox Route117_PokemonDayCare_Text_ComeAgain, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_CanRaiseOneMore::
	msgbox Route117_PokemonDayCare_Text_WeCanRaiseOneMore, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_PokemonDayCare_EventScript_GiveMonToRaise
	goto Route117_PokemonDayCare_EventScript_ComeAgain
	end

Route117_PokemonDayCare_EventScript_OnlyOneMon::
	msgbox Route117_PokemonDayCare_Text_YouHaveJustOneMon, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_OnlyOneAliveMon::
	msgbox Route117_PokemonDayCare_Text_WhatWillYouBattleWith, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_OnlyTwoAliveMons::
	msgbox Route117_PokemonDayCare_Text_YoullBeLeftWithJustOne, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_EggWaiting::
	msgbox Route117_PokemonDayCare_Text_HusbandWasLookingForYou, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_YourMonHasGrownXLevels::
	msgbox Route117_PokemonDayCare_Text_YourMonHasGrownXLevels, MSGBOX_DEFAULT
	return

Route117_PokemonDayCare_EventScript_DisplayLevelsGained::
	specialvar VAR_RESULT, GetNumLevelsGainedFromDaycare
	call_if_ne VAR_RESULT, 0, Route117_PokemonDayCare_EventScript_YourMonHasGrownXLevels
	return

Route117_PokemonDayCare_EventScript_OneMonInDaycare::
	msgbox Route117_PokemonDayCare_Text_GoodToSeeYou, MSGBOX_DEFAULT
	setvar VAR_0x8004, 0
	call Route117_PokemonDayCare_EventScript_DisplayLevelsGained
	msgbox Route117_PokemonDayCare_Text_WeCanRaiseOneMore, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_PokemonDayCare_EventScript_GiveMonToRaise
	msgbox Route117_PokemonDayCare_Text_TakeYourMonBack, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_PokemonDayCare_EventScript_TryRetrieveMon
	goto Route117_PokemonDayCare_EventScript_ComeAgain
	end

Route117_PokemonDayCare_EventScript_TryRetrieveMon::
	specialvar VAR_RESULT, CalculatePlayerPartyCount
	goto_if_eq VAR_RESULT, PARTY_SIZE, Route117_PokemonDayCare_EventScript_NoRoom
	specialvar VAR_RESULT, GetDaycareState
	setvar VAR_0x8004, 0
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route117_PokemonDayCare_EventScript_CostPrompt
	special ShowDaycareLevelMenu
	copyvar VAR_0x8004, VAR_RESULT
	goto_if_eq VAR_RESULT, DAYCARE_EXITED_LEVEL_MENU, Route117_PokemonDayCare_EventScript_ComeAgain
	goto Route117_PokemonDayCare_EventScript_CostPrompt
	end

Route117_PokemonDayCare_EventScript_CostPrompt::
	special GetDaycareCostAndPrepareString
	msgbox Route117_PokemonDayCare_Text_ItWillCostX, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_PokemonDayCare_EventScript_CheckEnoughMoney
	goto Route117_PokemonDayCare_EventScript_ComeAgain
	end

Route117_PokemonDayCare_EventScript_CheckEnoughMoney::
	specialvar VAR_RESULT, IsEnoughForCostInVar0x8005
	goto_if_eq VAR_RESULT, 1, Route117_PokemonDayCare_EventScript_RetrieveMon
	msgbox Route117_PokemonDayCare_Text_NotEnoughMoney, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_RetrieveMon::
	applymovement LOCALID_DAYCARE_LADY, Route117_PokemonDayCare_Movement_RetrieveDaycareMon
	waitmovement 0
	specialvar VAR_RESULT, TakePokemonFromDaycare
	special SubtractMoneyFromVar0x8005
	playse SE_SHOP
	msgbox Route117_PokemonDayCare_Text_HeresYourMon, MSGBOX_DEFAULT
	waitse
	playmoncry VAR_RESULT, CRY_MODE_NORMAL
	msgbox Route117_PokemonDayCare_Text_TookBackMon, MSGBOX_DEFAULT
	waitmoncry
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route117_PokemonDayCare_EventScript_AskRetrieveOtherMon
	goto Route117_PokemonDayCare_EventScript_ComeAgain
	end

Route117_PokemonDayCare_EventScript_AskRetrieveOtherMon::
	msgbox Route117_PokemonDayCare_Text_TakeOtherOneBackToo, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_PokemonDayCare_EventScript_TryRetrieveMon
	goto Route117_PokemonDayCare_EventScript_ComeAgain
	end

Route117_PokemonDayCare_EventScript_NoRoom::
	msgbox Route117_PokemonDayCare_Text_YourTeamIsFull, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_Movement_RetrieveDaycareMon:
	delay_16
	delay_16
	face_left
	delay_16
	delay_16
	face_right
	delay_16
	delay_16
	face_up
	walk_slow_up
	set_invisible
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	face_down
	set_visible
	walk_slow_down
	step_end

@ Unused. Possibly a commented script, or a typo end added to the above Movement script
Route117_PokemonDayCare_EventScript_UnusedEnd::
	end

Route117_PokemonDayCare_EventScript_TwoMonsInDaycare::
	msgbox Route117_PokemonDayCare_Text_GoodToSeeYou, MSGBOX_DEFAULT
	setvar VAR_0x8004, 0
	call Route117_PokemonDayCare_EventScript_DisplayLevelsGained
	setvar VAR_0x8004, 1
	call Route117_PokemonDayCare_EventScript_DisplayLevelsGained
	msgbox Route117_PokemonDayCare_Text_TakeYourMonBack, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_PokemonDayCare_EventScript_TryRetrieveMon
	msgbox Route117_PokemonDayCare_Text_ComeAgain, MSGBOX_DEFAULT
	release
	end

@ Unused
Route117_PokemonDayCare_EventScript_UnusedRetrieveMon::
	special ShowDaycareLevelMenu
	goto_if_eq VAR_RESULT, 2, Route117_PokemonDayCare_EventScript_ComeAgain
	copyvar VAR_0x8004, VAR_RESULT
	specialvar VAR_RESULT, TakePokemonFromDaycare
	msgbox Route117_PokemonDayCare_Text_HeresYourMon, MSGBOX_DEFAULT
	msgbox Route117_PokemonDayCare_Text_ComeAgain, MSGBOX_DEFAULT
	release
	end

EventScript_EggHatch::
	lockall
	msgbox Text_EggHatchHuh, MSGBOX_DEFAULT
	special EggHatch
	releaseall
	end

Route117_Text_SeeWifeIfYoudLikeMeToRaiseMon:
	.string "Tôi là DAY-CARE MAN.\p"
	.string "Tôi giúp chăm sóc những POKéMON quý\n"
	.string "giá của các HLV.\p"
	.string "Nếu muốn tôi nuôi POKéMON của bạn, hãy\n"
	.string "nói chuyện với vợ tôi.$"

Route117_Text_DoYouWantEgg:
	.string "À, là bạn đó sao!\p"
	.string "Khi đang nuôi POKéMON của bạn, chúng\n"
	.string "tôi đã được một phen bất ngờ!\p"
	.string "POKéMON của bạn có một EGG!\p"
	.string "Chúng tôi không biết nó xuất hiện bằng\n"
	.string "cách nào, nhưng POKéMON của bạn đã có\l"
	.string "nó.\p"
	.string "Bạn muốn nhận nó, đúng không?$"

Route117_Text_YourMonIsDoingFine:
	.string "À, là bạn đó sao! Rất vui được gặp bạn.\n"
	.string "{STR_VAR_1} của bạn vẫn khỏe.$"

Route117_Text_IllKeepIt:
	.string "Vậy thì tôi sẽ giữ nó lại. Cảm ơn!$"

Route117_Text_YouHaveNoRoomForIt:
	.string "Bạn không còn chỗ cho nó... Hãy quay lại\n"
	.string "khi đã dọn chỗ.$"

Route117_Text_ReceivedEgg:
	.string "{PLAYER} đã nhận EGG từ DAY-CARE\n"
	.string "MAN.$"

Route117_Text_TakeGoodCareOfIt:
	.string "Hãy chăm sóc nó thật tốt nhé.$"

Route117_Text_FriendlyWithOtherTrainersMon:
	.string "Nhân tiện, về {STR_VAR_1} của\n"
	.string "bạn, nó có vẻ rất thân với POKéMON của\l"
	.string "{STR_VAR_2}, tức\l"
	.string "{STR_VAR_3}.\p"
	.string "Tôi hình như còn thấy nó nhận được\n"
	.string "một lá MAIL.$"

@ Unused
Route117_Text_SeeWifeIfYouWantToPickUpMon:
	.string "Nếu muốn đón POKéMON của bạn về, hãy\n"
	.string "nói chuyện với vợ tôi.$"

Route117_Text_YourMonsAreDoingFine:
	.string "À, là bạn đó sao! {STR_VAR_1} và\n"
	.string "{STR_VAR_2} của bạn vẫn khỏe.$"

Route117_Text_IWillKeepDoYouWantIt:
	.string "Tôi thực sự sẽ giữ nó lại đấy. Bạn chắc\n"
	.string "là muốn nhận nó chứ?$"

Route117_PokemonDayCare_Text_WouldYouLikeUsToRaiseAMon:
	.string "Tôi là DAY-CARE LADY.\p"
	.string "Chúng tôi có thể nuôi POKéMON giúp bạn.\p"
	.string "Bạn có muốn gửi một con cho chúng tôi\n"
	.string "nuôi không?$"

Route117_PokemonDayCare_Text_WhichMonShouldWeRaise:
	.string "Bạn muốn chúng tôi nuôi POKéMON nào?$"

Route117_PokemonDayCare_Text_WellRaiseYourMon:
	.string "Được rồi, chúng tôi sẽ nuôi\n"
	.string "{STR_VAR_1} của bạn một thời\l"
	.string "gian.\p"
	.string "Sau này hãy quay lại đón nó nhé.$"

Route117_PokemonDayCare_Text_WeCanRaiseOneMore:
	.string "Chúng tôi có thể nuôi hai POKéMON của\n"
	.string "bạn. Bạn có muốn gửi thêm một con nữa\l"
	.string "không?$"

Route117_PokemonDayCare_Text_HusbandWasLookingForYou:
	.string "Chồng tôi đang tìm bạn đấy.$"

Route117_PokemonDayCare_Text_FineThenComeAgain:
	.string "Ồ, vậy cũng được. Lần sau lại đến nhé.$"

Route117_PokemonDayCare_Text_NotEnoughMoney:
	.string "Bạn không có đủ tiền...$"

Route117_PokemonDayCare_Text_TakeOtherOneBackToo:
	.string "Bạn có muốn đón cả con còn lại về\n"
	.string "không?$"

Route117_PokemonDayCare_Text_ComeAgain:
	.string "Được rồi. Lần sau lại đến nhé.$"

Route117_PokemonDayCare_Text_GoodToSeeYou:
	.string "À, là bạn đó sao! Rất vui được gặp bạn.\n"
	.string "POKéMON của bạn chắc chắn vẫn khỏe!$"

Route117_PokemonDayCare_Text_YourMonHasGrownXLevels:
	.string "Về cấp độ, {STR_VAR_1} của bạn\n"
	.string "đã tăng {STR_VAR_2} cấp.$"

Route117_PokemonDayCare_Text_YourTeamIsFull:
	.string "Đội POKéMON của bạn đã đầy. Hãy dọn chỗ\n"
	.string "rồi quay lại gặp tôi.$"

@ Unused
Route117_PokemonDayCare_Text_TakeBackWhichMon:
	.string "Bạn muốn đón POKéMON nào về?$"

Route117_PokemonDayCare_Text_ItWillCostX:
	.string "Nếu muốn đón {STR_VAR_1} về, bạn\n"
	.string "sẽ phải trả ¥{STR_VAR_2}.$"

Route117_PokemonDayCare_Text_HeresYourMon:
	.string "Tuyệt! POKéMON của bạn đây.$"

Route117_PokemonDayCare_Text_TookBackMon:
	.string "{PLAYER} đã đón {STR_VAR_1} về\n"
	.string "từ DAY-CARE LADY.$"

Route117_PokemonDayCare_Text_YouHaveJustOneMon:
	.string "Ồ? Nhưng bạn chỉ có một POKéMON thôi.\p"
	.string "Hãy quay lại vào dịp khác nhé.$"

Route117_PokemonDayCare_Text_TakeYourMonBack:
	.string "Bạn có muốn đón POKéMON của mình về\n"
	.string "không?$"

Route117_PokemonDayCare_Text_WhatWillYouBattleWith:
	.string "Nếu để POKéMON đó lại với tôi, bạn sẽ\n"
	.string "lấy gì để chiến đấu?\p"
	.string "Hãy quay lại vào dịp khác nhé.$"

Text_EggHatchHuh:
	.string "Hả?$"

Route117_PokemonDayCare_Text_YoullBeLeftWithJustOne:
	.string "Hả? Khoan đã nào.\p"
	.string "Nếu để POKéMON đó lại với tôi, bạn sẽ\n"
	.string "chỉ còn một con.\p"
	.string "Tôi nghĩ bạn nên bắt thêm vài con nữa\n"
	.string "thì hơn.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global Route117_Text_SeeWifeIfYoudLikeMeToRaiseMon
	.global Route117_Text_DoYouWantEgg
	.global Route117_Text_YourMonIsDoingFine
	.global Route117_Text_IllKeepIt
	.global Route117_Text_YouHaveNoRoomForIt
	.global Route117_Text_ReceivedEgg
	.global Route117_Text_TakeGoodCareOfIt
	.global Route117_Text_FriendlyWithOtherTrainersMon
	.global Route117_Text_SeeWifeIfYouWantToPickUpMon
	.global Route117_Text_YourMonsAreDoingFine
	.global Route117_Text_IWillKeepDoYouWantIt
	.global Route117_PokemonDayCare_Text_WouldYouLikeUsToRaiseAMon
	.global Route117_PokemonDayCare_Text_WhichMonShouldWeRaise
	.global Route117_PokemonDayCare_Text_WellRaiseYourMon
	.global Route117_PokemonDayCare_Text_WeCanRaiseOneMore
	.global Route117_PokemonDayCare_Text_HusbandWasLookingForYou
	.global Route117_PokemonDayCare_Text_FineThenComeAgain
	.global Route117_PokemonDayCare_Text_NotEnoughMoney
	.global Route117_PokemonDayCare_Text_TakeOtherOneBackToo
	.global Route117_PokemonDayCare_Text_ComeAgain
	.global Route117_PokemonDayCare_Text_GoodToSeeYou
	.global Route117_PokemonDayCare_Text_YourMonHasGrownXLevels
	.global Route117_PokemonDayCare_Text_YourTeamIsFull
	.global Route117_PokemonDayCare_Text_TakeBackWhichMon
	.global Route117_PokemonDayCare_Text_ItWillCostX
	.global Route117_PokemonDayCare_Text_HeresYourMon
	.global Route117_PokemonDayCare_Text_TookBackMon
	.global Route117_PokemonDayCare_Text_YouHaveJustOneMon
	.global Route117_PokemonDayCare_Text_TakeYourMonBack
	.global Route117_PokemonDayCare_Text_WhatWillYouBattleWith
	.global Text_EggHatchHuh
	.global Route117_PokemonDayCare_Text_YoullBeLeftWithJustOne
@ END GENERATED LOCALIZATION EXPORTS
