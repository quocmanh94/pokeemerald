SlateportCity_OceanicMuseum_1F_MapScripts::
	.byte 0

SlateportCity_OceanicMuseum_1F_EventScript_EntranceAttendant::
	msgbox SlateportCity_OceanicMuseum_1F_Text_PleaseEnjoyYourself, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFeeLeft::
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFee
	end

SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFeeRight::
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFee
	end

SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFee::
	showmoneybox 0, 0
	msgbox SlateportCity_OceanicMuseum_1F_Text_WouldYouLikeToEnter, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_OceanicMuseum_1F_EventScript_CheckMoneyForFee
	closemessage
	hidemoneybox
	applymovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

SlateportCity_OceanicMuseum_1F_EventScript_CheckMoneyForFee::
	checkmoney 50
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_OceanicMuseum_1F_EventScript_NotEnoughMoney
	playse SE_SHOP
	removemoney 50
	updatemoneybox
	msgbox SlateportCity_OceanicMuseum_1F_Text_PleaseEnjoyYourself, MSGBOX_DEFAULT
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 1
	hidemoneybox
	releaseall
	end

SlateportCity_OceanicMuseum_1F_EventScript_NotEnoughMoney::
	goto_if_unset FLAG_DELIVERED_DEVON_GOODS, SlateportCity_OceanicMuseum_1F_EventScript_AllowEntranceAnyway
	msgbox SlateportCity_OceanicMuseum_1F_Text_NotEnoughMoney, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	applymovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

SlateportCity_OceanicMuseum_1F_EventScript_AllowEntranceAnyway::
	msgbox SlateportCity_OceanicMuseum_1F_Text_CatchUpWithYourGroup, MSGBOX_DEFAULT
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 1
	hidemoneybox
	releaseall
	end

SlateportCity_OceanicMuseum_1F_Movement_PushPlayerBackFromCounter:
	walk_down
	step_end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt1::
	msgbox SlateportCity_OceanicMuseum_1F_Text_AquaExistForGoodOfAll, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt2::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OurBossIsntHere, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt3::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WouldStuffHereMakeMeRich, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt4::
	msgbox SlateportCity_OceanicMuseum_1F_Text_CanLearnForNefariousDeeds, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt5::
	msgbox SlateportCity_OceanicMuseum_1F_Text_RustboroBungled, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt6::
	msgbox SlateportCity_OceanicMuseum_1F_Text_DidntHaveMoney, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_WhirlpoolExperiment::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WhirlpoolExperiment, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_WaterfallExperiment::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WaterfallExperiment, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanSoilDisplay::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanSoilDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_BeachSandDisplay::
	msgbox SlateportCity_OceanicMuseum_1F_Text_BeachSandDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanicMinifact1::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact1, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanicMinifact2::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact2, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanicMinifact3::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact3, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_FossilDisplay::
	msgbox SlateportCity_OceanicMuseum_1F_Text_FossilDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_DepthMeasuringMachine::
	msgbox SlateportCity_OceanicMuseum_1F_Text_DepthMeasuringMachine, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron1::
	msgbox SlateportCity_OceanicMuseum_1F_Text_LearnAboutSeaForBattling, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron2::
	msgbox SlateportCity_OceanicMuseum_1F_Text_SternIsRoleModel, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron3::
	msgbox SlateportCity_OceanicMuseum_1F_Text_MustBePokemonWeDontKnow, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron4::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WantSeaPokemon, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGrunt::
	lock
	faceplayer
	delay 8
	playse SE_PIN
	applymovement LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT, Common_Movement_Delay48
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_1F_Text_RememberMeTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM_THIEF
	goto_if_eq VAR_RESULT, 0, SlateportCity_OceanicMuseum_1F_EventScript_NoRoomForThief
	setflag FLAG_RECEIVED_TM_THIEF
	msgbox SlateportCity_OceanicMuseum_1F_Text_HopeINeverSeeYouAgain, MSGBOX_DEFAULT
	closemessage
	goto_if_eq VAR_FACING, DIR_NORTH, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitNorth
	goto_if_eq VAR_FACING, DIR_SOUTH, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitSouth
	goto_if_eq VAR_FACING, DIR_WEST, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitWestEast
	goto_if_eq VAR_FACING, DIR_EAST, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitWestEast
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitNorth::
	applymovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitNorth
	applymovement LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT, SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExitNorth
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitSouth::
	applymovement LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT, SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExit
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitWestEast::
	applymovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitWestEast
	applymovement LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT, SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExit
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited::
	setflag FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_FAMILIAR_AQUA_GRUNT
	playse SE_EXIT
	removeobject LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT
	release
	end

SlateportCity_OceanicMuseum_1F_EventScript_NoRoomForThief::
	msgbox SlateportCity_OceanicMuseum_1F_Text_YouHaveToTakeThis, MSGBOX_DEFAULT
	release
	end

SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitNorth:
	delay_16
	delay_8
	delay_4
	walk_in_place_faster_down
	step_end

SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitWestEast:
	delay_16
	walk_in_place_faster_down
	step_end

SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExit:
	face_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	delay_8
	step_end

SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExitNorth:
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	delay_8
	step_end

SlateportCity_OceanicMuseum_1F_Text_WouldYouLikeToEnter:
	.string "Chào mừng đến với OCEANIC MUSEUM.\p"
	.string "Vé vào cửa là ¥50. Bạn có muốn vào\n"
	.string "không?$"

SlateportCity_OceanicMuseum_1F_Text_PleaseEnjoyYourself:
	.string "Chúc bạn tham quan vui vẻ.$"

SlateportCity_OceanicMuseum_1F_Text_NotEnoughMoney:
	.string "Ồ? Tôi xin lỗi, nhưng có vẻ bạn không có\n"
	.string "đủ tiền.$"

SlateportCity_OceanicMuseum_1F_Text_CatchUpWithYourGroup:
	.string "Ồ? Bạn đi cùng nhóm đã vào trước đó\n"
	.string "sao?\p"
	.string "Chỉ có mình bạn đến muộn thôi. Mau vào\n"
	.string "đuổi kịp họ đi!$"

SlateportCity_OceanicMuseum_1F_Text_AquaExistForGoodOfAll:
	.string "TEAM AQUA chúng ta tồn tại vì lợi ích\n"
	.string "của tất cả mọi người!$"

SlateportCity_OceanicMuseum_1F_Text_OurBossIsntHere:
	.string "Chúng tôi được lệnh tập hợp ở đây nên\n"
	.string "đã đến, nhưng...\p"
	.string "Thủ lĩnh của chúng tôi lại không\n"
	.string "có mặt.$"

SlateportCity_OceanicMuseum_1F_Text_WouldStuffHereMakeMeRich:
	.string "Nếu mình cuỗm đồ ở đây thì có trở nên\n"
	.string "giàu có không nhỉ?$"

SlateportCity_OceanicMuseum_1F_Text_CanLearnForNefariousDeeds:
	.string "Những gì học được ở đây có thể dùng\n"
	.string "vào các phi vụ bất chính...$"

SlateportCity_OceanicMuseum_1F_Text_RustboroBungled:
	.string "Nếu đám tay chân của chúng ta không\n"
	.string "làm hỏng việc ở RUSTBORO thì chúng ta\l"
	.string "đã chẳng phải đến đây!$"

SlateportCity_OceanicMuseum_1F_Text_DidntHaveMoney:
	.string "Tôi không có ¥50 nên phải mất rất lâu\n"
	.string "mới qua được cô lễ tân.$"

SlateportCity_OceanicMuseum_1F_Text_LearnAboutSeaForBattling:
	.string "Tôi muốn tìm hiểu về biển cả rồi dùng\n"
	.string "kiến thức đó trong chiến đấu.$"

SlateportCity_OceanicMuseum_1F_Text_SternIsRoleModel:
	.string "Mỗi khi nhìn thấy biển, tôi lại nôn nao\n"
	.string "và mềm nhũn cả người!\p"
	.string "Với tôi, CAPT. STERN là hình mẫu số một!$"

SlateportCity_OceanicMuseum_1F_Text_MustBePokemonWeDontKnow:
	.string "Biển cả rộng lớn vô tận và sâu không\n"
	.string "thấy đáy...\p"
	.string "Chắc chắn vẫn còn nhiều POKéMON mà\n"
	.string "chúng ta chưa biết đến.$"

SlateportCity_OceanicMuseum_1F_Text_WantSeaPokemon:
	.string "Tôi muốn có một POKéMON sống dưới biển.\p"
	.string "Ôm nó chắc sẽ mát lạnh và dễ chịu lắm.$"

SlateportCity_OceanicMuseum_1F_Text_RememberMeTakeThis:
	.string "Áaaa! Cậu làm gì ở đây vậy?\p"
	.string "Tôi sao? Tôi là thành viên TEAM AQUA\n"
	.string "từng bị cậu cho một trận, nhớ không? Ở\l"
	.string "RUSTURF TUNNEL ấy?\p"
	.string "Đây, cầm lấy! Cậu phải tha thứ cho tôi\n"
	.string "đấy!$"

SlateportCity_OceanicMuseum_1F_Text_HopeINeverSeeYouAgain:
	.string "TM đó hợp với ngươi hơn là với ta.\p"
	.string "Mong rằng ta không bao giờ phải gặp lại\n"
	.string "ngươi! Wahahaha!$"

SlateportCity_OceanicMuseum_1F_Text_YouHaveToTakeThis:
	.string "Thôi nào! Cậu phải nhận cái này rồi thả\n"
	.string "tôi đi chứ!$"

SlateportCity_OceanicMuseum_1F_Text_WhirlpoolExperiment:
	.string "Một chất lỏng màu xanh đang xoáy tròn\n"
	.string "bên trong bình thủy tinh.\p"
	.string "Đây là thí nghiệm dùng gió để tạo ra\n"
	.string "WHIRLPOOL nhân tạo.$"

SlateportCity_OceanicMuseum_1F_Text_WaterfallExperiment:
	.string "Một quả bóng đỏ đang nhấp nhô bên\n"
	.string "trong bình thủy tinh.\p"
	.string "Đây là thí nghiệm mô phỏng WATERFALL\n"
	.string "bằng lực nổi của quả bóng.$"

SlateportCity_OceanicMuseum_1F_Text_OceanSoilDisplay:
	.string "Đây là mẫu đất lấy từ đáy đại dương.\p"
	.string "Qua nhiều năm, xác các sinh vật lắng\n"
	.string "xuống đáy biển, hình thành những tầng\l"
	.string "trầm tích.\p"
	.string "Phân tích những tầng này sẽ hé lộ quá\n"
	.string "khứ xa xưa.$"

SlateportCity_OceanicMuseum_1F_Text_BeachSandDisplay:
	.string "Đây là mẫu cát lấy từ bãi biển.\p"
	.string "Đá từ trên núi bị sông cuốn xuống, va\n"
	.string "đập rồi bị bào mòn.\p"
	.string "Chúng vỡ thành những hạt nhỏ và cuối\n"
	.string "cùng trở thành cát trên bãi biển.$"

SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact1:
	.string "OCEANIC MINIFACT 1 Vì sao nước biển\n"
	.string "có màu xanh?\p"
	.string "Ánh sáng được tạo thành từ nhiều màu\n"
	.string "sắc.\p"
	.string "Khi ánh sáng đi qua nước, hầu hết các\n"
	.string "màu đều bị hấp thụ.\p"
	.string "Tuy nhiên, ánh sáng xanh vẫn giữ được\n"
	.string "màu sắc, khiến biển trông có màu xanh.$"

SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact2:
	.string "OCEANIC MINIFACT 2 Vì sao biển lại mặn?\p"
	.string "Nước biển chứa muối hòa tan dưới dạng\n"
	.string "các ion natri và clo.\p"
	.string "Những ion này tách ra từ đá rồi được\n"
	.string "nước mưa đưa ra biển.\p"
	.string "Nồng độ muối hòa tan khiến nước biển\n"
	.string "có vị mặn.$"

SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact3:
	.string "OCEANIC MINIFACT 3 Biển và đất liền,\n"
	.string "bên nào lớn hơn?\p"
	.string "Biển bao phủ khoảng 70% hành tinh, phần\n"
	.string "còn lại là đất liền.\p"
	.string "Vì vậy, biển rộng hơn đất liền trên hai\n"
	.string "lần.$"

SlateportCity_OceanicMuseum_1F_Text_FossilDisplay:
	.string "Đây là một hóa thạch có những đường\n"
	.string "gợn sóng.\p"
	.string "Đất dưới đáy đại dương bị thủy triều\n"
	.string "bào mòn.\p"
	.string "Dòng nước biển tạo ra những đường gờ\n"
	.string "và rãnh nhỏ trên mặt đất.\p"
	.string "Nếu lớp đất này hóa thạch, nó được gọi\n"
	.string "là dấu gợn sóng.$"

SlateportCity_OceanicMuseum_1F_Text_DepthMeasuringMachine:
	.string "Một cỗ máy kỳ lạ đang xoay dưới mái vòm\n"
	.string "thủy tinh.\p"
	.string "Có lẽ nó dùng để đo độ sâu của thứ gì\n"
	.string "đó...$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global SlateportCity_OceanicMuseum_1F_Text_WouldYouLikeToEnter
	.global SlateportCity_OceanicMuseum_1F_Text_PleaseEnjoyYourself
	.global SlateportCity_OceanicMuseum_1F_Text_NotEnoughMoney
	.global SlateportCity_OceanicMuseum_1F_Text_CatchUpWithYourGroup
	.global SlateportCity_OceanicMuseum_1F_Text_AquaExistForGoodOfAll
	.global SlateportCity_OceanicMuseum_1F_Text_OurBossIsntHere
	.global SlateportCity_OceanicMuseum_1F_Text_WouldStuffHereMakeMeRich
	.global SlateportCity_OceanicMuseum_1F_Text_CanLearnForNefariousDeeds
	.global SlateportCity_OceanicMuseum_1F_Text_RustboroBungled
	.global SlateportCity_OceanicMuseum_1F_Text_DidntHaveMoney
	.global SlateportCity_OceanicMuseum_1F_Text_LearnAboutSeaForBattling
	.global SlateportCity_OceanicMuseum_1F_Text_SternIsRoleModel
	.global SlateportCity_OceanicMuseum_1F_Text_MustBePokemonWeDontKnow
	.global SlateportCity_OceanicMuseum_1F_Text_WantSeaPokemon
	.global SlateportCity_OceanicMuseum_1F_Text_RememberMeTakeThis
	.global SlateportCity_OceanicMuseum_1F_Text_HopeINeverSeeYouAgain
	.global SlateportCity_OceanicMuseum_1F_Text_YouHaveToTakeThis
	.global SlateportCity_OceanicMuseum_1F_Text_WhirlpoolExperiment
	.global SlateportCity_OceanicMuseum_1F_Text_WaterfallExperiment
	.global SlateportCity_OceanicMuseum_1F_Text_OceanSoilDisplay
	.global SlateportCity_OceanicMuseum_1F_Text_BeachSandDisplay
	.global SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact1
	.global SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact2
	.global SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact3
	.global SlateportCity_OceanicMuseum_1F_Text_FossilDisplay
	.global SlateportCity_OceanicMuseum_1F_Text_DepthMeasuringMachine
@ END GENERATED LOCALIZATION EXPORTS
