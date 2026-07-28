MauvilleCity_BikeShop_MapScripts::
	.byte 0

MauvilleCity_BikeShop_EventScript_Rydel::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_BIKE, MauvilleCity_BikeShop_EventScript_AskSwitchBikes
	goto_if_set FLAG_DECLINED_BIKE, MauvilleCity_BikeShop_EventScript_SkipGreeting
	msgbox MauvilleCity_BikeShop_Text_RydelGreeting, MSGBOX_DEFAULT
	msgbox MauvilleCity_BikeShop_Text_DidYouComeFromFarAway, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_YesFar
	goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_NotFar
	end

MauvilleCity_BikeShop_EventScript_SkipGreeting::
	msgbox MauvilleCity_BikeShop_Text_DidYouComeFromFarAway, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_YesFar
	goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_NotFar
	end

MauvilleCity_BikeShop_EventScript_ChooseBike::
	message MauvilleCity_BikeShop_Text_ExplainBikesChooseWhichOne
	waitmessage
	multichoice 21, 8, MULTI_BIKE, TRUE
	switch VAR_RESULT
	case 0, MauvilleCity_BikeShop_EventScript_GetMachBike
	case 1, MauvilleCity_BikeShop_EventScript_GetAcroBike
	end

MauvilleCity_BikeShop_EventScript_NotFar::
	setflag FLAG_DECLINED_BIKE
	msgbox MauvilleCity_BikeShop_Text_GuessYouDontNeedBike, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_YesFar::
	setflag FLAG_RECEIVED_BIKE
	goto MauvilleCity_BikeShop_EventScript_ChooseBike
	end

MauvilleCity_BikeShop_EventScript_GetMachBike::
	msgbox MauvilleCity_BikeShop_Text_ChoseMachBike, MSGBOX_DEFAULT
	giveitem ITEM_MACH_BIKE
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_GetAcroBike::
	msgbox MauvilleCity_BikeShop_Text_ChoseAcroBike, MSGBOX_DEFAULT
	giveitem ITEM_ACRO_BIKE
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes::
	msgbox MauvilleCity_BikeShop_Text_ComeBackToSwitchBikes, MSGBOX_DEFAULT
	special SwapRegisteredBike
	release
	end

MauvilleCity_BikeShop_EventScript_AskSwitchBikes::
	msgbox MauvilleCity_BikeShop_Text_WantToSwitchBikes, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_SwitchBikes
	goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_KeepBike
	end

@ If the player does not have a bike on them Rydel assumes its stored in the PC
MauvilleCity_BikeShop_EventScript_SwitchBikes::
	msgbox MauvilleCity_BikeShop_Text_IllSwitchBikes, MSGBOX_DEFAULT
	checkitem ITEM_ACRO_BIKE
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_BikeShop_EventScript_SwitchAcroForMach
	checkitem ITEM_MACH_BIKE
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_BikeShop_EventScript_SwitchMachForAcro
	msgbox MauvilleCity_BikeShop_Text_OhYourBikeIsInPC, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_KeepBike::
	msgbox MauvilleCity_BikeShop_Text_HappyYouLikeIt, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_SwitchAcroForMach::
	incrementgamestat GAME_STAT_TRADED_BIKES
	msgbox MauvilleCity_BikeShop_Text_ExchangedAcroForMach, MSGBOX_DEFAULT
	removeitem ITEM_ACRO_BIKE
	giveitem ITEM_MACH_BIKE
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_SwitchMachForAcro::
	incrementgamestat GAME_STAT_TRADED_BIKES
	msgbox MauvilleCity_BikeShop_Text_ExchangedMachForAcro, MSGBOX_DEFAULT
	removeitem ITEM_MACH_BIKE
	giveitem ITEM_ACRO_BIKE
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_Assistant::
	msgbox MauvilleCity_BikeShop_Text_HandbooksAreInBack, MSGBOX_NPC
	end

MauvilleCity_BikeShop_EventScript_MachBikeHandbook::
	message MauvilleCity_BikeShop_Text_MachHandbookWhichPage
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage::
	multichoice 0, 0, MULTI_MACH_BIKE_INFO, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_BikeShop_EventScript_HowToRide
	case 1, MauvilleCity_BikeShop_EventScript_HowToTurn
	case 2, MauvilleCity_BikeShop_EventScript_SandySlopes
	case 3, MauvilleCity_BikeShop_EventScript_ExitMachHandbook
	case MULTI_B_PRESSED, MauvilleCity_BikeShop_EventScript_ExitMachHandbook
	end

MauvilleCity_BikeShop_EventScript_HowToRide::
	message MauvilleCity_BikeShop_Text_HowToRideMachBike
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_HowToTurn::
	message MauvilleCity_BikeShop_Text_HowToTurnMachBike
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_SandySlopes::
	message MauvilleCity_BikeShop_Text_SandySlopes
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ExitMachHandbook::
	release
	end

MauvilleCity_BikeShop_EventScript_AcroBikeHandbook::
	message MauvilleCity_BikeShop_Text_AcroHandbookWhichPage
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage::
	multichoice 0, 0, MULTI_ACRO_BIKE_INFO, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_BikeShop_EventScript_Wheelies
	case 1, MauvilleCity_BikeShop_EventScript_BunnyHops
	case 2, MauvilleCity_BikeShop_EventScript_Jumps
	case 3, MauvilleCity_BikeShop_EventScript_ExitAcroHandbook
	case MULTI_B_PRESSED, MauvilleCity_BikeShop_EventScript_ExitAcroHandbook
	end

MauvilleCity_BikeShop_EventScript_Wheelies::
	message MauvilleCity_BikeShop_Text_Wheelies
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_BunnyHops::
	message MauvilleCity_BikeShop_Text_BunnyHops
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_Jumps::
	message MauvilleCity_BikeShop_Text_Jumps
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ExitAcroHandbook::
	release
	end

MauvilleCity_BikeShop_Text_RydelGreeting:
	.string "Ồ, ồ, xem ai đến đây nào? Một vị khách\n"
	.string "tràn đầy năng lượng!\p"
	.string "Tôi ư? Cứ gọi tôi là RYDEL. Tôi là chủ\n"
	.string "cửa hàng xe đạp này.$"

MauvilleCity_BikeShop_Text_DidYouComeFromFarAway:
	.string "RYDEL: Đôi RUNNING SHOES của cậu... Bẩn\n"
	.string "kinh khủng.\p"
	.string "Cậu đến từ nơi xa lắm sao?$"

MauvilleCity_BikeShop_Text_GuessYouDontNeedBike:
	.string "RYDEL: Vậy à?\p"
	.string "Thế thì chắc cậu chẳng cần đến BIKES\n"
	.string "của tôi.$"

MauvilleCity_BikeShop_Text_ExplainBikesChooseWhichOne:
	.string "RYDEL: Hừm, hừm... ... ... ... ...\p"
	.string "Cậu nói mình đã đi suốt quãng đường\n"
	.string "từ LITTLEROOT tới đây sao?\p"
	.string "Trời đất! Xa khủng khiếp!\p"
	.string "Nếu có một chiếc BIKE của tôi, cậu có\n"
	.string "thể dễ dàng đi khắp nơi trong làn gió\l"
	.string "dịu dàng ve vuốt!\p"
	.string "Thế này nhé! Tôi sẽ tặng cậu một chiếc\n"
	.string "BIKE!\p"
	.string "Ồ, khoan đã!\p"
	.string "Tôi quên nói có hai loại BIKES!\p"
	.string "Đó là MACH BIKE và ACRO BIKE!\p"
	.string "MACH BIKE dành cho người muốn cảm\n"
	.string "nhận làn gió bằng cả cơ thể!\p"
	.string "Còn ACRO BIKE dành cho người thích kỹ\n"
	.string "thuật điều khiển!\p"
	.string "Tôi đúng là tốt bụng, nên cậu thích\n"
	.string "chiếc nào cũng được!\p"
	.string "Cậu sẽ chọn chiếc nào?$"

MauvilleCity_BikeShop_Text_ChoseMachBike:
	.string "{PLAYER} đã chọn MACH BIKE.$"

MauvilleCity_BikeShop_Text_ChoseAcroBike:
	.string "{PLAYER} đã chọn ACRO BIKE.$"

MauvilleCity_BikeShop_Text_ComeBackToSwitchBikes:
	.string "RYDEL: Nếu muốn đổi BIKES, cứ đến gặp\n"
	.string "tôi!$"

MauvilleCity_BikeShop_Text_WantToSwitchBikes:
	.string "RYDEL: Ồ? Cậu đang tính đổi BIKES à?$"

MauvilleCity_BikeShop_Text_IllSwitchBikes:
	.string "RYDEL: Được, không vấn đề gì! Tôi sẽ\n"
	.string "đổi BIKES cho cậu!$"

MauvilleCity_BikeShop_Text_ExchangedMachForAcro:
	.string "{PLAYER} đã đổi MACH BIKE lấy ACRO\n"
	.string "BIKE.$"

MauvilleCity_BikeShop_Text_ExchangedAcroForMach:
	.string "{PLAYER} đã đổi ACRO BIKE lấy MACH\n"
	.string "BIKE.$"

MauvilleCity_BikeShop_Text_HappyYouLikeIt:
	.string "RYDEL: Tốt, tốt! Tôi rất vui vì cậu\n"
	.string "thích nó!$"

MauvilleCity_BikeShop_Text_OhYourBikeIsInPC:
	.string "Ồ? Chiếc BIKE tôi tặng cậu đâu rồi?\p"
	.string "À, tôi hiểu rồi, cậu đã cất nó bằng PC.\p"
	.string "Vậy hãy lấy nó ra khỏi kho PC, rồi tôi sẽ\n"
	.string "vui lòng đổi cho cậu!\p"
	.string "Mong gió luôn nâng bước cậu trên hành\n"
	.string "trình!$"

MauvilleCity_BikeShop_Text_HandbooksAreInBack:
	.string "Tôi vừa làm việc ở đây vừa học hỏi về\n"
	.string "BIKES.\p"
	.string "Nếu cần lời khuyên về cách đi BIKE,\n"
	.string "phía sau có vài cuốn sổ hướng dẫn.$"

MauvilleCity_BikeShop_Text_MachHandbookWhichPage:
	.string "Đây là sổ hướng dẫn về MACH BIKE.\p"
	.string "Cậu muốn đọc trang nào?$"

MauvilleCity_BikeShop_Text_HowToRideMachBike:
	.string "BIKE di chuyển theo hướng cậu nhấn\n"
	.string "trên + Control Pad.\p"
	.string "Khi đã bắt đầu lăn bánh, nó sẽ tăng tốc.\p"
	.string "Muốn dừng lại, hãy thả + Control Pad.\n"
	.string "BIKE sẽ giảm tốc rồi dừng hẳn.\p"
	.string "Cậu muốn đọc trang khác không?$"

MauvilleCity_BikeShop_Text_HowToTurnMachBike:
	.string "MACH BIKE rất nhanh, nhưng không thể\n"
	.string "dừng lại ngay.\p"
	.string "Vì vậy, vào cua sẽ hơi khó.\p"
	.string "Hãy thả + Control Pad một chút trước\n"
	.string "khi tới góc cua để giảm tốc.\p"
	.string "Cậu muốn đọc trang khác không?$"

MauvilleCity_BikeShop_Text_SandySlopes:
	.string "Khắp vùng HOENN có những dốc cát nhỏ.\p"
	.string "Lớp cát tơi xốp khiến ta không thể leo\n"
	.string "lên theo cách thông thường.\p"
	.string "Nhưng nếu có MACH BIKE, cậu có thể\n"
	.string "phóng vút lên dốc cát.\p"
	.string "Cậu muốn đọc trang khác không?$"

MauvilleCity_BikeShop_Text_AcroHandbookWhichPage:
	.string "Đây là sổ hướng dẫn về ACRO BIKE.\p"
	.string "Cậu muốn đọc trang nào?$"

MauvilleCity_BikeShop_Text_Wheelies:
	.string "Khi đang đi, nhấn B Button để nhấc bánh\n"
	.string "trước lên.\p"
	.string "Cậu có thể dùng + Control Pad để chạy\n"
	.string "quanh khi bánh trước vẫn nhấc lên.\p"
	.string "Kỹ thuật này gọi là bốc đầu.\p"
	.string "Cậu muốn đọc trang khác không?$"

MauvilleCity_BikeShop_Text_BunnyHops:
	.string "Giữ B Button, BIKE của cậu có thể nhảy\n"
	.string "tại chỗ.\p"
	.string "Kỹ thuật này gọi là nhảy thỏ.\p"
	.string "Cậu cũng có thể vừa chạy vừa nhảy.\p"
	.string "Cậu muốn đọc trang khác không?$"

MauvilleCity_BikeShop_Text_Jumps:
	.string "Nhấn đồng thời B Button và + Control\n"
	.string "Pad để nhảy.\p"
	.string "Nhấn + Control Pad sang bên để nhảy\n"
	.string "ngang.\p"
	.string "Nhấn về phía sau để BIKE đổi hướng\n"
	.string "trong lúc nhảy.\p"
	.string "Cậu muốn đọc trang khác không?$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global MauvilleCity_BikeShop_Text_RydelGreeting
	.global MauvilleCity_BikeShop_Text_DidYouComeFromFarAway
	.global MauvilleCity_BikeShop_Text_GuessYouDontNeedBike
	.global MauvilleCity_BikeShop_Text_ExplainBikesChooseWhichOne
	.global MauvilleCity_BikeShop_Text_ChoseMachBike
	.global MauvilleCity_BikeShop_Text_ChoseAcroBike
	.global MauvilleCity_BikeShop_Text_ComeBackToSwitchBikes
	.global MauvilleCity_BikeShop_Text_WantToSwitchBikes
	.global MauvilleCity_BikeShop_Text_IllSwitchBikes
	.global MauvilleCity_BikeShop_Text_ExchangedMachForAcro
	.global MauvilleCity_BikeShop_Text_ExchangedAcroForMach
	.global MauvilleCity_BikeShop_Text_HappyYouLikeIt
	.global MauvilleCity_BikeShop_Text_OhYourBikeIsInPC
	.global MauvilleCity_BikeShop_Text_HandbooksAreInBack
	.global MauvilleCity_BikeShop_Text_MachHandbookWhichPage
	.global MauvilleCity_BikeShop_Text_HowToRideMachBike
	.global MauvilleCity_BikeShop_Text_HowToTurnMachBike
	.global MauvilleCity_BikeShop_Text_SandySlopes
	.global MauvilleCity_BikeShop_Text_AcroHandbookWhichPage
	.global MauvilleCity_BikeShop_Text_Wheelies
	.global MauvilleCity_BikeShop_Text_BunnyHops
	.global MauvilleCity_BikeShop_Text_Jumps
@ END GENERATED LOCALIZATION EXPORTS
