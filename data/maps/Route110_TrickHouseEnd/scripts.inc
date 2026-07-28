Route110_TrickHouseEnd_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Route110_TrickHouseEnd_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_TrickHouseEnd_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route110_TrickHouseEnd_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route110_TrickHouseEnd_OnWarp
	.byte 0

Route110_TrickHouseEnd_OnResume:
	call_if_eq VAR_TEMP_1, 1, Route110_TrickHouseEnd_EventScript_SetDoorClosedMetatile
	end

Route110_TrickHouseEnd_OnTransition:
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, 0
	special SetTrickHouseNuggetFlag
	end

Route110_TrickHouseEnd_OnWarp:
	map_script_2 VAR_TEMP_2, 0, Route110_TrickHouseEnd_EventScript_SetTrickMasterPos
	.2byte 0

Route110_TrickHouseEnd_EventScript_SetTrickMasterPos::
	addobject LOCALID_TRICK_MASTER_END
	showobjectat LOCALID_TRICK_MASTER_END, MAP_ROUTE110_TRICK_HOUSE_END
	turnobject LOCALID_TRICK_MASTER_END, DIR_EAST
	end

Route110_TrickHouseEnd_OnFrame:
	map_script_2 VAR_TEMP_1, 0, Route110_TrickHouseEnd_EventScript_CloseDoor
	.2byte 0

Route110_TrickHouseEnd_EventScript_CloseDoor::
	setvar VAR_TEMP_1, 1
	call Route110_TrickHouseEnd_EventScript_SetDoorClosedMetatile
	special DrawWholeMapView
	end

Route110_TrickHouseEnd_EventScript_SetDoorClosedMetatile::
	setmetatile 10, 1, METATILE_GenericBuilding_TrickHouse_Door_Closed, TRUE
	return

Route110_TrickHouseEnd_EventScript_TrickMaster::
	lock
	faceplayer
	msgbox Route110_TrickHouseEnd_Text_YouveMadeItToMe, MSGBOX_DEFAULT
	setvar VAR_TEMP_2, 1
	switch VAR_TRICK_HOUSE_LEVEL
	case 0, Route110_TrickHouseEnd_EventScript_CompletedPuzzle1
	case 1, Route110_TrickHouseEnd_EventScript_CompletedPuzzle2
	case 2, Route110_TrickHouseEnd_EventScript_CompletedPuzzle3
	case 3, Route110_TrickHouseEnd_EventScript_CompletedPuzzle4
	case 4, Route110_TrickHouseEnd_EventScript_CompletedPuzzle5
	case 5, Route110_TrickHouseEnd_EventScript_CompletedPuzzle6
	case 6, Route110_TrickHouseEnd_EventScript_CompletedPuzzle7
	case 7, Route110_TrickHouseEnd_EventScript_CompletedPuzzle8
	end

Route110_TrickHouseEnd_EventScript_CompletedPuzzle1::
	msgbox Route110_TrickHouseEnd_Text_AllNightToPlantTrees, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem ITEM_RARE_CANDY
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_BagFull
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
	closemessage
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
	release
	end

Route110_TrickHouseEnd_EventScript_CompletedPuzzle2::
	msgbox Route110_TrickHouseEnd_Text_AllNightToMakeMaze, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem ITEM_TIMER_BALL
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_BagFull
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
	closemessage
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
	release
	end

Route110_TrickHouseEnd_EventScript_CompletedPuzzle3::
	msgbox Route110_TrickHouseEnd_Text_AllNightToPreparePanels, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem ITEM_HARD_STONE
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_BagFull
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
	closemessage
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
	release
	end

Route110_TrickHouseEnd_EventScript_CompletedPuzzle4::
	msgbox Route110_TrickHouseEnd_Text_AllNightToShoveBoulders, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem ITEM_SMOKE_BALL
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_BagFull
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
	closemessage
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
	release
	end

Route110_TrickHouseEnd_EventScript_CompletedPuzzle5::
	msgbox Route110_TrickHouseEnd_Text_AllNightToMakeMechadolls, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem ITEM_TM_TAUNT
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_BagFull
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
	closemessage
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
	release
	end

Route110_TrickHouseEnd_EventScript_CompletedPuzzle6::
	msgbox Route110_TrickHouseEnd_Text_AllNightToInstallDoors, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem ITEM_MAGNET
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_BagFull
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
	closemessage
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
	release
	end

Route110_TrickHouseEnd_EventScript_CompletedPuzzle7::
	msgbox Route110_TrickHouseEnd_Text_AllNightSettingUpArrows, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem ITEM_PP_MAX
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_BagFull
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
	closemessage
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
	release
	end

Route110_TrickHouseEnd_EventScript_CompletedPuzzle8::
	msgbox Route110_TrickHouseEnd_Text_AllNightPolishingFloors, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_SOUTH, Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwaySouth
	call_if_eq VAR_FACING, DIR_NORTH, Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwayNorth
	call_if_eq VAR_FACING, DIR_WEST, Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwayWest
	call_if_eq VAR_FACING, DIR_EAST, Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwayEast
	delay 30
	msgbox Route110_TrickHouseEnd_Text_FountainOfIdeasRunDry, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_TRICK_MASTER_END, Common_Movement_FacePlayer
	waitmovement 0
	delay 30
	msgbox Route110_TrickHouseEnd_Text_DefeatedMePreferWhichTent, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	call Route110_TrickHouseEnd_EventScript_ChooseTent
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_NoRoomForTent
	msgbox Route110_TrickHouseEnd_Text_LeavingOnJourney, MSGBOX_DEFAULT
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
	special ResetTrickHouseNuggetFlag
	release
	end

Route110_TrickHouseEnd_EventScript_ChooseTent::
	multichoice 0, 0, MULTI_TENT, TRUE
	switch VAR_RESULT
	case 0, Route110_TrickHouseEnd_EventScript_GiveRedTent
	goto Route110_TrickHouseEnd_EventScript_GiveBlueTent

Route110_TrickHouseEnd_EventScript_GiveRedTent::
	givedecoration DECOR_RED_TENT
	return

Route110_TrickHouseEnd_EventScript_GiveBlueTent::
	givedecoration DECOR_BLUE_TENT
	return

Route110_TrickHouseEnd_EventScript_TrickMasterExit::
	applymovement LOCALID_TRICK_MASTER_END, Route110_TrickHouse_Movement_TrickMasterSpin
	waitmovement 0
	playse SE_M_EXPLOSION
	applymovement LOCALID_TRICK_MASTER_END, Route110_TrickHouse_Movement_TrickMasterJumpAway
	waitmovement 0
	removeobject LOCALID_TRICK_MASTER_END
	addvar VAR_TRICK_HOUSE_LEVEL, 1
	return

Route110_TrickHouseEnd_EventScript_BagFull::
	call Common_EventScript_BagIsFull
	msgbox Route110_TrickHouseEnd_Text_NoRoomForThis, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 1
	return

Route110_TrickHouseEnd_EventScript_NoRoomForTent::
	call Common_EventScript_NoRoomForDecor
	msgbox Route110_TrickHouseEnd_Text_NoRoomInPC, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 1
	return

Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwaySouth::
	applymovement LOCALID_TRICK_MASTER_END, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwayNorth::
	applymovement LOCALID_TRICK_MASTER_END, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwayWest::
	applymovement LOCALID_TRICK_MASTER_END, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwayEast::
	applymovement LOCALID_TRICK_MASTER_END, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

Route110_TrickHouseEnd_EventScript_TrickMasterExitTrigger::
	lockall
	turnobject LOCALID_TRICK_MASTER_END, DIR_WEST
	playse SE_PIN
	applymovement LOCALID_TRICK_MASTER_END, Common_Movement_ExclamationMark
	waitmovement 0
	delay 20
	applymovement LOCALID_TRICK_MASTER_END, Route110_TrickHouseEnd_Movement_TrickMasterSurprise
	waitmovement 0
	playse SE_M_EXPLOSION
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox Route110_TrickHouseEnd_Text_YoureIgnoringMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Route110_TrickHouseEnd_Movement_KeepPlayerInRoom
	waitmovement 0
	delay 4
	turnobject LOCALID_TRICK_MASTER_END, DIR_EAST
	releaseall
	end

Route110_TrickHouseEnd_Movement_KeepPlayerInRoom:
	walk_down
	step_end

Route110_TrickHouseEnd_Movement_TrickMasterSurprise:
	jump_in_place_left
	step_end

Route110_TrickHouseEnd_Text_YouveMadeItToMe:
	.string "Á! Ngươi đã tới được chỗ ta sao?\n"
	.string "Hừm... Sắc bén lắm!$"

Route110_TrickHouseEnd_Text_AllNightToPlantTrees:
	.string "Ta đã mất cả đêm để trồng hết đám cây\n"
	.string "đó...\p"
	.string "Ngươi chỉ còn kém sự vĩ đại của ta một,\n"
	.string "hai, ba, bốn, năm, sáu bậc thôi!$"

Route110_TrickHouseEnd_Text_AllNightToMakeMaze:
	.string "Ta đã mất cả đêm để làm mê cung...\p"
	.string "Ngươi chỉ còn kém sự vĩ đại của ta một,\n"
	.string "hai, ba, bốn, năm bậc thôi!$"

Route110_TrickHouseEnd_Text_AllNightToPreparePanels:
	.string "Ta đã mất cả đêm để chuẩn bị những tấm\n"
	.string "vách...\p"
	.string "Ngươi chỉ còn kém sự vĩ đại của ta một,\n"
	.string "hai, ba, bốn bậc thôi!$"

Route110_TrickHouseEnd_Text_AllNightToShoveBoulders:
	.string "Ta đã mất cả đêm để đẩy những tảng đá\n"
	.string "vào chỗ...\p"
	.string "Ngươi chỉ còn kém sự vĩ đại của ta một,\n"
	.string "hai, ba bậc thôi!$"

Route110_TrickHouseEnd_Text_AllNightToMakeMechadolls:
	.string "Ta mất cả đêm để làm MECHADOLLS, rồi\n"
	.string "thêm một đêm nữa để nghĩ ra câu đố...\p"
	.string "Ngươi chỉ còn kém sự vĩ đại của ta một,\n"
	.string "hai bậc thôi!$"

Route110_TrickHouseEnd_Text_AllNightToInstallDoors:
	.string "Ta đã mất cả đêm để lắp những cánh\n"
	.string "cửa...\p"
	.string "Ngươi gần ngang hàng với ta về độ vĩ\n"
	.string "đại!$"

Route110_TrickHouseEnd_Text_AllNightSettingUpArrows:
	.string "Ta đã mất cả đêm để bố trí các mũi tên...\p"
	.string "Ngươi ngang hàng với ta về độ vĩ đại!$"

Route110_TrickHouseEnd_Text_AllNightPolishingFloors:
	.string "Ta đã mất cả đêm để đánh bóng sàn nhà...\p"
	.string "Ngươi còn vĩ đại hơn cả ta! Có lẽ vậy...$"

Route110_TrickHouseEnd_Text_FountainOfIdeasRunDry:
	.string "T-ta phải làm sao đây? Suối nguồn ý\n"
	.string "tưởng trò mẹo của ta đã cạn...\p"
	.string "Có lẽ đã đến lúc ta chu du khắp đất\n"
	.string "nước để tìm cách nghĩ ra những trò\l"
	.string "mẹo mới...$"

Route110_TrickHouseEnd_Text_DefeatedMePreferWhichTent:
	.string "Ta không muốn thừa nhận thất bại,\n"
	.string "nhưng ngươi đã thắng ta!\p"
	.string "Dù vậy, hẳn ngươi đã bị sức hút của ta\n"
	.string "mê hoặc nên mới đến thăm ta hết lần này\l"
	.string "đến lần khác. Đúng, nhất định là vậy!\p"
	.string "Nhưng chuyện đó chẳng liên quan gì đến\n"
	.string "việc ta thua!\p"
	.string "Để ghi nhận tình bạn giữa ngươi, kẻ\n"
	.string "đầy quyết tâm, và thiên tài là ta, ta yêu\l"
	.string "cầu ngươi nhận lấy kỷ vật này!\p"
	.string "Thực ra có hai món: RED TENT và BLUE\n"
	.string "TENT. Ngươi thích món nào?$"

Route110_TrickHouseEnd_Text_NoRoomInPC:
	.string "Gì cơ? PC của ngươi không còn chỗ? Ta\n"
	.string "phải hiểu chuyện này thế nào đây?\p"
	.string "Ta muốn nói thế lắm, nhưng ta quá tử tế\n"
	.string "và chu đáo, nên hãy quay lại sau!$"

Route110_TrickHouseEnd_Text_LeavingOnJourney:
	.string "... ... ... ... ... ...\p"
	.string "Ta sẽ lên đường khám phá. Một hành\n"
	.string "trình tìm kiếm những trò mẹo mới.\p"
	.string "Ta mong một ngày nào đó ngươi lại ghé\n"
	.string "thăm và mua vui cho ta.\p"
	.string "Giờ thì, vĩnh biệt!$"

Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward:
	.string "Được! Ngươi xứng đáng nhận phần\n"
	.string "thưởng này!$"

Route110_TrickHouseEnd_Text_NoRoomForThis:
	.string "Gì cơ? Ngươi không còn chỗ cho thứ\n"
	.string "này sao? Ngươi mang theo toàn thứ gì\l"
	.string "vậy?\p"
	.string "Nhưng thôi, vì ngươi đã tới được chỗ\n"
	.string "ta, ta sẽ giữ phần thưởng đến khi\l"
	.string "ngươi quay lại.$"

Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou:
	.string "Gạt nụ cười tự mãn đó khỏi mặt ngươi\n"
	.string "đi! Còn quá sớm để nghĩ rằng ngươi đã\l"
	.string "thắng!\p"
	.string "Ta sẽ nghĩ ra những trò mẹo mới để làm\n"
	.string "khó ngươi. Chỉ khi vượt qua hết, ngươi\l"
	.string "mới được chế giễu ta.\p"
	.string "Hãy quay lại đón xem màn tiếp theo đầy\n"
	.string "gay cấn!$"

Route110_TrickHouseEnd_Text_YoureIgnoringMe:
	.string "Này, này! Giờ ngươi phớt lờ ta sao?\n"
	.string "Chuyện đó làm ta đau lòng lắm đấy!$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global Route110_TrickHouseEnd_Text_YouveMadeItToMe
	.global Route110_TrickHouseEnd_Text_AllNightToPlantTrees
	.global Route110_TrickHouseEnd_Text_AllNightToMakeMaze
	.global Route110_TrickHouseEnd_Text_AllNightToPreparePanels
	.global Route110_TrickHouseEnd_Text_AllNightToShoveBoulders
	.global Route110_TrickHouseEnd_Text_AllNightToMakeMechadolls
	.global Route110_TrickHouseEnd_Text_AllNightToInstallDoors
	.global Route110_TrickHouseEnd_Text_AllNightSettingUpArrows
	.global Route110_TrickHouseEnd_Text_AllNightPolishingFloors
	.global Route110_TrickHouseEnd_Text_FountainOfIdeasRunDry
	.global Route110_TrickHouseEnd_Text_DefeatedMePreferWhichTent
	.global Route110_TrickHouseEnd_Text_NoRoomInPC
	.global Route110_TrickHouseEnd_Text_LeavingOnJourney
	.global Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward
	.global Route110_TrickHouseEnd_Text_NoRoomForThis
	.global Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou
	.global Route110_TrickHouseEnd_Text_YoureIgnoringMe
@ END GENERATED LOCALIZATION EXPORTS
