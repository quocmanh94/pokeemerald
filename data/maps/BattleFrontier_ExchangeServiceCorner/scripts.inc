BattleFrontier_ExchangeServiceCorner_MapScripts::
	.byte 0

BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize, MSGBOX_DEFAULT
	special ShowBattlePointsWindow
	return

BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ThankYouVisitWithPoints, MSGBOX_DEFAULT
	special CloseBattlePointsWindow
	release
	end

BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize::
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
	goto_if_ge VAR_TEMP_1, VAR_0x8008, BattleFrontier_ExchangeServiceCorner_EventScript_TryGivePrize
	msgbox BattleFrontier_ExchangeServiceCorner_Text_DontHaveEnoughPoints, MSGBOX_DEFAULT
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR1_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR2_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_VITAMIN_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	end

BattleFrontier_ExchangeServiceCorner_EventScript_TryGivePrize::
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR1_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_TryGiveDecor
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR2_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_TryGiveDecor
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryGiveItem
	end

BattleFrontier_ExchangeServiceCorner_EventScript_TryGiveDecor::
	checkdecorspace VAR_0x8009
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_ExchangeServiceCorner_EventScript_NoRoomForDecor
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	adddecoration VAR_0x8009
	special UpdateBattlePointsWindow
	playse SE_SHOP
	msgbox BattleFrontier_ExchangeServiceCorner_Text_WellSendItToPC, MSGBOX_DEFAULT
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR1_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2
	end

BattleFrontier_ExchangeServiceCorner_EventScript_NoRoomForDecor::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_PCIsFull, MSGBOX_DEFAULT
	special CloseBattlePointsWindow
	release
	end

BattleFrontier_ExchangeServiceCorner_EventScript_TryGiveItem::
	checkitemspace VAR_0x8009
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_ExchangeServiceCorner_EventScript_BagFull
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	additem VAR_0x8009
	special UpdateBattlePointsWindow
	playse SE_SHOP
	msgbox BattleFrontier_ExchangeServiceCorner_Text_HereIsYourPrize, MSGBOX_DEFAULT
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_VITAMIN_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	end

BattleFrontier_ExchangeServiceCorner_EventScript_BagFull::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_DontHaveSpaceToHoldIt, MSGBOX_DEFAULT
	special CloseBattlePointsWindow
	release
	end

BattleFrontier_ExchangeServiceCorner_EventScript_DecorClerk1::
	lock
	faceplayer
	setvar VAR_TEMP_2, EXCHANGE_CORNER_DECOR1_CLERK
	call BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1::
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_DECOR_VENDOR_1
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, BattleFrontier_ExchangeServiceCorner_EventScript_KissPoster
	case 1, BattleFrontier_ExchangeServiceCorner_EventScript_KissCushion
	case 2, BattleFrontier_ExchangeServiceCorner_EventScript_SmoochumDoll
	case 3, BattleFrontier_ExchangeServiceCorner_EventScript_TogepiDoll
	case 4, BattleFrontier_ExchangeServiceCorner_EventScript_MeowthDoll
	case 5, BattleFrontier_ExchangeServiceCorner_EventScript_ClefairyDoll
	case 6, BattleFrontier_ExchangeServiceCorner_EventScript_DittoDoll
	case 7, BattleFrontier_ExchangeServiceCorner_EventScript_CyndaquilDoll
	case 8, BattleFrontier_ExchangeServiceCorner_EventScript_ChikoritaDoll
	case 9, BattleFrontier_ExchangeServiceCorner_EventScript_TotodileDoll
	case 10, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	case MULTI_B_PRESSED, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	end

BattleFrontier_ExchangeServiceCorner_EventScript_KissPoster::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmKissPoster, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 16
	setvar VAR_0x8009, DECOR_KISS_POSTER
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_KissCushion::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmKissCushion, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 32
	setvar VAR_0x8009, DECOR_KISS_CUSHION
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_SmoochumDoll::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmSmoochumDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 32
	setvar VAR_0x8009, DECOR_SMOOCHUM_DOLL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_TogepiDoll::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmTogepiDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, DECOR_TOGEPI_DOLL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_MeowthDoll::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmMeowthDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, DECOR_MEOWTH_DOLL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ClefairyDoll::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmClefairyDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, DECOR_CLEFAIRY_DOLL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_DittoDoll::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmDittoDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, DECOR_DITTO_DOLL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_CyndaquilDoll::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmCyndaquilDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 80
	setvar VAR_0x8009, DECOR_CYNDAQUIL_DOLL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ChikoritaDoll::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmChikoritaDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 80
	setvar VAR_0x8009, DECOR_CHIKORITA_DOLL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_TotodileDoll::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmTotodileDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 80
	setvar VAR_0x8009, DECOR_TOTODILE_DOLL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_DecorClerk2::
	lock
	faceplayer
	setvar VAR_TEMP_2, EXCHANGE_CORNER_DECOR2_CLERK
	call BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2::
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_DECOR_VENDOR_2
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, BattleFrontier_ExchangeServiceCorner_EventScript_LaprasDoll
	case 1, BattleFrontier_ExchangeServiceCorner_EventScript_SnorlaxDoll
	case 2, BattleFrontier_ExchangeServiceCorner_EventScript_VenusaurDoll
	case 3, BattleFrontier_ExchangeServiceCorner_EventScript_CharizardDoll
	case 4, BattleFrontier_ExchangeServiceCorner_EventScript_BlastoiseDoll
	case 5, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	case MULTI_B_PRESSED, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	end

BattleFrontier_ExchangeServiceCorner_EventScript_LaprasDoll::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmLaprasDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2
	setvar VAR_0x8008, 128
	setvar VAR_0x8009, DECOR_LAPRAS_DOLL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_SnorlaxDoll::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmSnorlaxDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2
	setvar VAR_0x8008, 128
	setvar VAR_0x8009, DECOR_SNORLAX_DOLL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_VenusaurDoll::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmVenusaurDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2
	setvar VAR_0x8008, 256
	setvar VAR_0x8009, DECOR_VENUSAUR_DOLL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_CharizardDoll::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmCharizardDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2
	setvar VAR_0x8008, 256
	setvar VAR_0x8009, DECOR_CHARIZARD_DOLL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_BlastoiseDoll::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmBlastoiseDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2
	setvar VAR_0x8008, 256
	setvar VAR_0x8009, DECOR_BLASTOISE_DOLL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_VitaminClerk::
	lock
	faceplayer
	setvar VAR_TEMP_2, EXCHANGE_CORNER_VITAMIN_CLERK
	call BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin::
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_VITAMIN_VENDOR
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, BattleFrontier_ExchangeServiceCorner_EventScript_Protein
	case 1, BattleFrontier_ExchangeServiceCorner_EventScript_Calcium
	case 2, BattleFrontier_ExchangeServiceCorner_EventScript_Iron
	case 3, BattleFrontier_ExchangeServiceCorner_EventScript_Zinc
	case 4, BattleFrontier_ExchangeServiceCorner_EventScript_Carbos
	case 5, BattleFrontier_ExchangeServiceCorner_EventScript_HPUp
	case 6, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	case MULTI_B_PRESSED, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Protein::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmProtein, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, ITEM_PROTEIN
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Calcium::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmCalcium, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, ITEM_CALCIUM
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Iron::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmIron, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, ITEM_IRON
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Zinc::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmZinc, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, ITEM_ZINC
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Carbos::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmCarbos, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, ITEM_CARBOS
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_HPUp::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmHPUp, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, ITEM_HP_UP
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_HoldItemClerk::
	lock
	faceplayer
	setvar VAR_TEMP_2, EXCHANGE_CORNER_HOLD_ITEM_CLERK
	call BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem::
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_HOLD_ITEM_VENDOR
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, BattleFrontier_ExchangeServiceCorner_EventScript_Leftovers
	case 1, BattleFrontier_ExchangeServiceCorner_EventScript_WhiteHerb
	case 2, BattleFrontier_ExchangeServiceCorner_EventScript_QuickClaw
	case 3, BattleFrontier_ExchangeServiceCorner_EventScript_MentalHerb
	case 4, BattleFrontier_ExchangeServiceCorner_EventScript_Brightpowder
	case 5, BattleFrontier_ExchangeServiceCorner_EventScript_ChoiceBand
	case 6, BattleFrontier_ExchangeServiceCorner_EventScript_KingsRock
	case 7, BattleFrontier_ExchangeServiceCorner_EventScript_FocusBand
	case 8, BattleFrontier_ExchangeServiceCorner_EventScript_ScopeLens
	case 9, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	case MULTI_B_PRESSED, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Leftovers::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmLeftovers, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, ITEM_LEFTOVERS
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_WhiteHerb::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmWhiteHerb, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, ITEM_WHITE_HERB
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_QuickClaw::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmQuickClaw, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, ITEM_QUICK_CLAW
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_MentalHerb::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmMentalHerb, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, ITEM_MENTAL_HERB
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Brightpowder::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmBrightpowder, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 64
	setvar VAR_0x8009, ITEM_BRIGHT_POWDER
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ChoiceBand::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmChoiceBand, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 64
	setvar VAR_0x8009, ITEM_CHOICE_BAND
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_KingsRock::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmKingsRock, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 64
	setvar VAR_0x8009, ITEM_KINGS_ROCK
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_FocusBand::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmFocusBand, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 64
	setvar VAR_0x8009, ITEM_FOCUS_BAND
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ScopeLens::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmScopeLens, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 64
	setvar VAR_0x8009, ITEM_SCOPE_LENS
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Man::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_GoGetYourOwnDoll, MSGBOX_NPC
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Sailor::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ItemsWillGetMonTougher, MSGBOX_NPC
	end

BattleFrontier_ExchangeServiceCorner_EventScript_PokefanF::
	lock
	msgbox BattleFrontier_ExchangeServiceCorner_Text_GetYouAnythingYouWant, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ExchangeServiceCorner_EventScript_RichBoy::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_WishIHadAllDolls, MSGBOX_NPC
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Girl::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_MoreBattlePointsForRecord, MSGBOX_NPC
	end

BattleFrontier_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize:
	.string "Xin chào, đây là EXCHANGE SERVICE\n"
	.string "CORNER.\p"
	.string "Chúng tôi đổi số Battle Points bạn đã\n"
	.string "tích lũy lấy những phần thưởng đáng\l"
	.string "yêu.\p"
	.string "Vui lòng chọn một phần thưởng trong\n"
	.string "danh sách này.$"

@ Unused
BattleFrontier_ExchangeServiceCorner_Text_PleaseChoosePrize:
	.string "Vui lòng chọn một phần thưởng trong\n"
	.string "danh sách này.$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmKissPoster:
	.string "Bạn đã chọn KISS POSTER. Đúng không?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmKissCushion:
	.string "Bạn đã chọn KISS CUSHION. Đúng không?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmSmoochumDoll:
	.string "Bạn đã chọn SMOOCHUM DOLL. Đúng\n"
	.string "không?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmTogepiDoll:
	.string "Bạn đã chọn TOGEPI DOLL. Đúng không?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmMeowthDoll:
	.string "Bạn đã chọn MEOWTH DOLL. Đúng không?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmClefairyDoll:
	.string "Bạn đã chọn CLEFAIRY DOLL. Đúng\n"
	.string "không?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmDittoDoll:
	.string "Bạn đã chọn DITTO DOLL. Đúng không?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmCyndaquilDoll:
	.string "Bạn đã chọn CYNDAQUIL DOLL. Đúng\n"
	.string "không?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmChikoritaDoll:
	.string "Bạn đã chọn CHIKORITA DOLL. Đúng\n"
	.string "không?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmTotodileDoll:
	.string "Bạn đã chọn TOTODILE DOLL. Đúng\n"
	.string "không?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmLaprasDoll:
	.string "Bạn đã chọn LAPRAS DOLL. Đúng không?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmSnorlaxDoll:
	.string "Bạn đã chọn SNORLAX DOLL. Đúng không?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmVenusaurDoll:
	.string "Bạn đã chọn VENUSAUR DOLL. Đúng\n"
	.string "không?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmCharizardDoll:
	.string "Bạn đã chọn CHARIZARD DOLL. Đúng\n"
	.string "không?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmBlastoiseDoll:
	.string "Bạn đã chọn BLASTOISE DOLL. Đúng\n"
	.string "không?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmProtein:
	.string "Bạn đã chọn PROTEIN. Đúng không?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmCalcium:
	.string "Bạn đã chọn CALCIUM. Đúng không?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmIron:
	.string "Bạn đã chọn IRON. Đúng không?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmZinc:
	.string "Bạn đã chọn ZINC. Đúng không?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmCarbos:
	.string "Bạn đã chọn CARBOS. Đúng không?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmHPUp:
	.string "Bạn đã chọn HP UP. Đúng không?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmBrightpowder:
	.string "Bạn đã chọn BRIGHTPOWDER. Đúng không?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmWhiteHerb:
	.string "Bạn đã chọn WHITE HERB. Đúng không?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmQuickClaw:
	.string "Bạn đã chọn QUICK CLAW. Đúng không?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmMentalHerb:
	.string "Bạn đã chọn MENTAL HERB. Đúng không?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmChoiceBand:
	.string "Bạn đã chọn CHOICE BAND. Đúng không?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmKingsRock:
	.string "Bạn đã chọn KING'S ROCK. Đúng không?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmFocusBand:
	.string "Bạn đã chọn FOCUS BAND. Đúng không?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmScopeLens:
	.string "Bạn đã chọn SCOPE LENS. Đúng không?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmLeftovers:
	.string "Bạn đã chọn LEFTOVERS. Đúng chứ?$"

BattleFrontier_ExchangeServiceCorner_Text_WellSendItToPC:
	.string "Cảm ơn bạn! Chúng tôi sẽ gửi nó đến PC\n"
	.string "ở nhà của bạn.$"

BattleFrontier_ExchangeServiceCorner_Text_HereIsYourPrize:
	.string "Đây là phần thưởng của bạn!$"

BattleFrontier_ExchangeServiceCorner_Text_DontHaveEnoughPoints:
	.string "Thành thật xin lỗi... Bạn không có đủ\n"
	.string "Battle Points...$"

BattleFrontier_ExchangeServiceCorner_Text_PCIsFull:
	.string "Thành thật xin lỗi... PC của bạn có vẻ đã\n"
	.string "đầy...$"

BattleFrontier_ExchangeServiceCorner_Text_DontHaveSpaceToHoldIt:
	.string "Thành thật xin lỗi... Bạn không còn chỗ\n"
	.string "để cất nó...$"

BattleFrontier_ExchangeServiceCorner_Text_ThankYouVisitWithPoints:
	.string "Xin chân thành cảm ơn.\p"
	.string "Hãy ghé lại khi bạn đã tích đủ Battle\n"
	.string "Points.$"

BattleFrontier_ExchangeServiceCorner_Text_WishIHadAllDolls:
	.string "Ôi, chúng đẹp quá! Ước gì mình có\n"
	.string "chúng! Những chiếc đệm dễ thương!\l"
	.string "DOLLS bông cỡ lớn! DOLLS bông cỡ nhỏ!\l"
	.string "Ước gì mình có hết!$"

BattleFrontier_ExchangeServiceCorner_Text_GetYouAnythingYouWant:
	.string "Cứ để mẹ lo!\p"
	.string "Chỉ cần là thứ con muốn, mẹ sẽ làm mọi\n"
	.string "cách để lấy cho con, cưng à!$"

BattleFrontier_ExchangeServiceCorner_Text_ItemsWillGetMonTougher:
	.string "Nếu lấy được những món đồ ở đây,\n"
	.string "POKéMON của tôi sẽ mạnh hơn.\p"
	.string "Chắc chắn là thế! Không phải bàn cãi!$"

BattleFrontier_ExchangeServiceCorner_Text_GoGetYourOwnDoll:
	.string "Hả? Nhìn chằm chằm gì thế?\p"
	.string "Tôi không thích bạn cứ nhìn con búp bê\n"
	.string "bông của tôi như vậy.\p"
	.string "Muốn thì tự đi kiếm một con đi! Đúng\n"
	.string "không, SMOOCHUM?$"

BattleFrontier_ExchangeServiceCorner_Text_MoreBattlePointsForRecord:
	.string "Bạn biết không?\p"
	.string "Nếu kéo dài chuỗi thành tích tại bất kỳ\n"
	.string "cơ sở trận đấu nào, họ sẽ thưởng cho\l"
	.string "bạn ngày càng nhiều Battle Points.$"

BattleFrontier_ExchangeServiceCorner_Text_KissPosterDesc::
	.string "Một tấm áp phích lớn in hình SMOOCHUM.$"

BattleFrontier_ExchangeServiceCorner_Text_KissCushionDesc::
	.string "Một chiếc đệm SMOOCHUM. Đặt nó lên thảm\n"
	.string "hoặc bàn.$"

BattleFrontier_ExchangeServiceCorner_Text_SmoochumDollDesc::
	.string "Một SMOOCHUM DOLL. Đặt nó lên thảm\n"
	.string "hoặc bàn.$"

BattleFrontier_ExchangeServiceCorner_Text_TogepiDollDesc::
	.string "Một TOGEPI DOLL. Đặt nó lên thảm hoặc\n"
	.string "bàn.$"

BattleFrontier_ExchangeServiceCorner_Text_MeowthDollDesc::
	.string "Một MEOWTH DOLL. Đặt nó lên thảm hoặc\n"
	.string "bàn.$"

BattleFrontier_ExchangeServiceCorner_Text_ClefairyDollDesc::
	.string "Một CLEFAIRY DOLL. Đặt nó lên thảm\n"
	.string "hoặc bàn.$"

BattleFrontier_ExchangeServiceCorner_Text_DittoDollDesc::
	.string "Một DITTO DOLL. Đặt nó lên thảm hoặc\n"
	.string "bàn.$"

BattleFrontier_ExchangeServiceCorner_Text_CyndaquilDollDesc::
	.string "Một CYNDAQUIL DOLL. Đặt nó lên thảm\n"
	.string "hoặc bàn.$"

BattleFrontier_ExchangeServiceCorner_Text_ChikoritaDollDesc::
	.string "Một CHIKORITA DOLL. Đặt nó lên thảm\n"
	.string "hoặc bàn.$"

BattleFrontier_ExchangeServiceCorner_Text_TotodileDollDesc::
	.string "Một TOTODILE DOLL. Đặt nó lên thảm\n"
	.string "hoặc bàn.$"

BattleFrontier_ExchangeServiceCorner_Text_LargeDollDesc::
	.string "Một DOLL cỡ lớn. Đặt nó lên thảm hoặc\n"
	.string "bàn.$"

BattleFrontier_ExchangeServiceCorner_Text_ProteinDesc::
	.string "Tăng chỉ số ATTACK của một POKéMON.$"

BattleFrontier_ExchangeServiceCorner_Text_CalciumDesc::
	.string "Tăng chỉ số SP. ATK của một POKéMON.$"

BattleFrontier_ExchangeServiceCorner_Text_IronDesc::
	.string "Tăng chỉ số DEFENSE của một POKéMON.$"

BattleFrontier_ExchangeServiceCorner_Text_ZincDesc::
	.string "Tăng chỉ số SP. DEF của một POKéMON.$"

BattleFrontier_ExchangeServiceCorner_Text_CarbosDesc::
	.string "Tăng chỉ số SPEED của một POKéMON.$"

BattleFrontier_ExchangeServiceCorner_Text_HPUpDesc::
	.string "Tăng HP của một POKéMON.$"

BattleFrontier_ExchangeServiceCorner_Text_LeftoversDesc::
	.string "Vật phẩm cầm tay giúp dần hồi phục HP\n"
	.string "trong trận đấu.$"

BattleFrontier_ExchangeServiceCorner_Text_WhiteHerbDesc::
	.string "Vật phẩm cầm tay giúp khôi phục mọi chỉ\n"
	.string "số đã bị giảm.$"

BattleFrontier_ExchangeServiceCorner_Text_QuickClawDesc::
	.string "Vật phẩm cầm tay đôi khi cho phép ra\n"
	.string "đòn trước.$"

BattleFrontier_ExchangeServiceCorner_Text_MentalHerbDesc::
	.string "Vật phẩm cầm tay giúp POKéMON thoát\n"
	.string "khỏi trạng thái mê đắm.$"

BattleFrontier_ExchangeServiceCorner_Text_BrightpowderDesc::
	.string "Vật phẩm cầm tay phát ra ánh chói làm\n"
	.string "giảm độ chính xác.$"

BattleFrontier_ExchangeServiceCorner_Text_ChoiceBandDesc::
	.string "Tăng sức mạnh của một chiêu thức,\n"
	.string "nhưng chỉ cho phép dùng chiêu đó.$"

BattleFrontier_ExchangeServiceCorner_Text_KingsRockDesc::
	.string "Vật phẩm cầm tay có thể khiến đối thủ\n"
	.string "nao núng khi trúng đòn.$"

BattleFrontier_ExchangeServiceCorner_Text_FocusBandDesc::
	.string "Vật phẩm cầm tay đôi khi giúp tránh bị\n"
	.string "hạ gục.$"

BattleFrontier_ExchangeServiceCorner_Text_ScopeLensDesc::
	.string "Vật phẩm cầm tay làm tăng tỷ lệ ra đòn\n"
	.string "chí mạng.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global BattleFrontier_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize
	.global BattleFrontier_ExchangeServiceCorner_Text_PleaseChoosePrize
	.global BattleFrontier_ExchangeServiceCorner_Text_ConfirmKissPoster
	.global BattleFrontier_ExchangeServiceCorner_Text_ConfirmKissCushion
	.global BattleFrontier_ExchangeServiceCorner_Text_ConfirmSmoochumDoll
	.global BattleFrontier_ExchangeServiceCorner_Text_ConfirmTogepiDoll
	.global BattleFrontier_ExchangeServiceCorner_Text_ConfirmMeowthDoll
	.global BattleFrontier_ExchangeServiceCorner_Text_ConfirmClefairyDoll
	.global BattleFrontier_ExchangeServiceCorner_Text_ConfirmDittoDoll
	.global BattleFrontier_ExchangeServiceCorner_Text_ConfirmCyndaquilDoll
	.global BattleFrontier_ExchangeServiceCorner_Text_ConfirmChikoritaDoll
	.global BattleFrontier_ExchangeServiceCorner_Text_ConfirmTotodileDoll
	.global BattleFrontier_ExchangeServiceCorner_Text_ConfirmLaprasDoll
	.global BattleFrontier_ExchangeServiceCorner_Text_ConfirmSnorlaxDoll
	.global BattleFrontier_ExchangeServiceCorner_Text_ConfirmVenusaurDoll
	.global BattleFrontier_ExchangeServiceCorner_Text_ConfirmCharizardDoll
	.global BattleFrontier_ExchangeServiceCorner_Text_ConfirmBlastoiseDoll
	.global BattleFrontier_ExchangeServiceCorner_Text_ConfirmProtein
	.global BattleFrontier_ExchangeServiceCorner_Text_ConfirmCalcium
	.global BattleFrontier_ExchangeServiceCorner_Text_ConfirmIron
	.global BattleFrontier_ExchangeServiceCorner_Text_ConfirmZinc
	.global BattleFrontier_ExchangeServiceCorner_Text_ConfirmCarbos
	.global BattleFrontier_ExchangeServiceCorner_Text_ConfirmHPUp
	.global BattleFrontier_ExchangeServiceCorner_Text_ConfirmBrightpowder
	.global BattleFrontier_ExchangeServiceCorner_Text_ConfirmWhiteHerb
	.global BattleFrontier_ExchangeServiceCorner_Text_ConfirmQuickClaw
	.global BattleFrontier_ExchangeServiceCorner_Text_ConfirmMentalHerb
	.global BattleFrontier_ExchangeServiceCorner_Text_ConfirmChoiceBand
	.global BattleFrontier_ExchangeServiceCorner_Text_ConfirmKingsRock
	.global BattleFrontier_ExchangeServiceCorner_Text_ConfirmFocusBand
	.global BattleFrontier_ExchangeServiceCorner_Text_ConfirmScopeLens
	.global BattleFrontier_ExchangeServiceCorner_Text_ConfirmLeftovers
	.global BattleFrontier_ExchangeServiceCorner_Text_WellSendItToPC
	.global BattleFrontier_ExchangeServiceCorner_Text_HereIsYourPrize
	.global BattleFrontier_ExchangeServiceCorner_Text_DontHaveEnoughPoints
	.global BattleFrontier_ExchangeServiceCorner_Text_PCIsFull
	.global BattleFrontier_ExchangeServiceCorner_Text_DontHaveSpaceToHoldIt
	.global BattleFrontier_ExchangeServiceCorner_Text_ThankYouVisitWithPoints
	.global BattleFrontier_ExchangeServiceCorner_Text_WishIHadAllDolls
	.global BattleFrontier_ExchangeServiceCorner_Text_GetYouAnythingYouWant
	.global BattleFrontier_ExchangeServiceCorner_Text_ItemsWillGetMonTougher
	.global BattleFrontier_ExchangeServiceCorner_Text_GoGetYourOwnDoll
	.global BattleFrontier_ExchangeServiceCorner_Text_MoreBattlePointsForRecord
	.global BattleFrontier_ExchangeServiceCorner_Text_KissPosterDesc
	.global BattleFrontier_ExchangeServiceCorner_Text_KissCushionDesc
	.global BattleFrontier_ExchangeServiceCorner_Text_SmoochumDollDesc
	.global BattleFrontier_ExchangeServiceCorner_Text_TogepiDollDesc
	.global BattleFrontier_ExchangeServiceCorner_Text_MeowthDollDesc
	.global BattleFrontier_ExchangeServiceCorner_Text_ClefairyDollDesc
	.global BattleFrontier_ExchangeServiceCorner_Text_DittoDollDesc
	.global BattleFrontier_ExchangeServiceCorner_Text_CyndaquilDollDesc
	.global BattleFrontier_ExchangeServiceCorner_Text_ChikoritaDollDesc
	.global BattleFrontier_ExchangeServiceCorner_Text_TotodileDollDesc
	.global BattleFrontier_ExchangeServiceCorner_Text_LargeDollDesc
	.global BattleFrontier_ExchangeServiceCorner_Text_ProteinDesc
	.global BattleFrontier_ExchangeServiceCorner_Text_CalciumDesc
	.global BattleFrontier_ExchangeServiceCorner_Text_IronDesc
	.global BattleFrontier_ExchangeServiceCorner_Text_ZincDesc
	.global BattleFrontier_ExchangeServiceCorner_Text_CarbosDesc
	.global BattleFrontier_ExchangeServiceCorner_Text_HPUpDesc
	.global BattleFrontier_ExchangeServiceCorner_Text_LeftoversDesc
	.global BattleFrontier_ExchangeServiceCorner_Text_WhiteHerbDesc
	.global BattleFrontier_ExchangeServiceCorner_Text_QuickClawDesc
	.global BattleFrontier_ExchangeServiceCorner_Text_MentalHerbDesc
	.global BattleFrontier_ExchangeServiceCorner_Text_BrightpowderDesc
	.global BattleFrontier_ExchangeServiceCorner_Text_ChoiceBandDesc
	.global BattleFrontier_ExchangeServiceCorner_Text_KingsRockDesc
	.global BattleFrontier_ExchangeServiceCorner_Text_FocusBandDesc
	.global BattleFrontier_ExchangeServiceCorner_Text_ScopeLensDesc
@ END GENERATED LOCALIZATION EXPORTS
