BerryTreeScript::
	special ObjectEventInteractionGetBerryTreeData
	switch VAR_0x8004
	case BERRY_STAGE_SPARKLING, BerryTree_EventScript_Sparkling
	case BERRY_STAGE_NO_BERRY, BerryTree_EventScript_CheckSoil
	case BERRY_STAGE_PLANTED, BerryTree_EventScript_CheckBerryStage1
	case BERRY_STAGE_SPROUTED, BerryTree_EventScript_CheckBerryStage2
	case BERRY_STAGE_TALLER, BerryTree_EventScript_CheckBerryStage3
	case BERRY_STAGE_FLOWERING, BerryTree_EventScript_CheckBerryStage4
	case BERRY_STAGE_BERRIES, BerryTree_EventScript_CheckBerryFullyGrown
	end

BerryTree_EventScript_Sparkling::
	lockall
	message BerryTree_Text_ExclamationPoint
	waitmessage
	waitbuttonpress
	releaseall
	end

BerryTree_EventScript_CheckSoil::
	lock
	faceplayer
	specialvar VAR_RESULT, PlayerHasBerries
	goto_if_eq VAR_RESULT, TRUE, BerryTree_EventScript_ChooseBerryToPlant
	message BerryTree_Text_ItsSoftLoamySoil
	waitmessage
	waitbuttonpress
	release
	end

BerryTree_EventScript_ChooseBerryToPlant::
	fadescreen FADE_TO_BLACK
	closemessage
	special Bag_ChooseBerry
	goto_if_eq VAR_ITEM_ID, 0, BerryTree_EventScript_CancelPlanting
	removeitem VAR_ITEM_ID
	call BerryTree_EventScript_PlantBerry

BerryTree_EventScript_CancelPlanting::
	release
	end

BerryTree_EventScript_CheckBerryStage1::
	lockall
	special ObjectEventInteractionGetBerryCountString
	checkitem ITEM_WAILMER_PAIL
	goto_if_eq VAR_RESULT, FALSE, BerryTree_EventScript_ShowBerryStage1
	msgbox BerryTree_Text_BerryGrowthStage1Water, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, BerryTree_EventScript_WaterBerry
	goto_if_eq VAR_RESULT, NO, BerryTree_EventScript_DontWater
	goto BerryTree_EventScript_DontWater

BerryTree_EventScript_ShowBerryStage1::
	message BerryTree_Text_BerryGrowthStage1
	waitmessage
	waitbuttonpress
	goto BerryTree_EventScript_DontWater

BerryTree_EventScript_CheckBerryStage2::
	lockall
	special ObjectEventInteractionGetBerryName
	checkitem ITEM_WAILMER_PAIL
	goto_if_eq VAR_RESULT, FALSE, BerryTree_EventScript_ShowBerryStage2
	msgbox BerryTree_Text_BerryGrowthStage2Water, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, BerryTree_EventScript_WaterBerry
	goto_if_eq VAR_RESULT, NO, BerryTree_EventScript_DontWater
	goto BerryTree_EventScript_DontWater

BerryTree_EventScript_ShowBerryStage2::
	message BerryTree_Text_BerryGrowthStage2
	waitmessage
	waitbuttonpress
	goto BerryTree_EventScript_DontWater

BerryTree_EventScript_CheckBerryStage3::
	lockall
	special ObjectEventInteractionGetBerryName
	checkitem ITEM_WAILMER_PAIL
	goto_if_eq VAR_RESULT, FALSE, BerryTree_EventScript_ShowBerryStage3
	msgbox BerryTree_Text_BerryGrowthStage3Water, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, BerryTree_EventScript_WaterBerry
	goto_if_eq VAR_RESULT, NO, BerryTree_EventScript_DontWater
	goto BerryTree_EventScript_DontWater

BerryTree_EventScript_ShowBerryStage3::
	message BerryTree_Text_BerryGrowthStage3
	waitmessage
	waitbuttonpress
	goto BerryTree_EventScript_DontWater

BerryTree_EventScript_CheckBerryStage4::
	call BerryTree_EventScript_GetCareAdverb
	lockall
	special ObjectEventInteractionGetBerryName
	checkitem ITEM_WAILMER_PAIL
	goto_if_eq VAR_RESULT, FALSE, BerryTree_EventScript_ShowBerryStage4
	msgbox BerryTree_Text_BerryGrowthStage4Water, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, BerryTree_EventScript_WaterBerry
	goto_if_eq VAR_RESULT, NO, BerryTree_EventScript_DontWater
	goto BerryTree_EventScript_DontWater

BerryTree_EventScript_ShowBerryStage4::
	message BerryTree_Text_BerryGrowthStage4
	waitmessage
	waitbuttonpress
	goto BerryTree_EventScript_DontWater

@ VAR_0x8005 here is the number of times watered
@ Buffered by ObjectEventInteractionGetBerryTreeData
BerryTree_EventScript_GetCareAdverb::
	goto_if_eq VAR_0x8005, 0, BerryTree_EventScript_SetAdverbPoor
	goto_if_eq VAR_0x8005, 4, BerryTree_EventScript_SetAdverbGreat
	bufferstring STR_VAR_2, BerryTree_Text_CareAdverbGood
	return

BerryTree_EventScript_SetAdverbGreat::
	bufferstring STR_VAR_2, BerryTree_Text_CareAdverbGreat
	return

BerryTree_EventScript_SetAdverbPoor::
	bufferstring STR_VAR_2, BerryTree_Text_CareAdverbPoor
	return

@ VAR_0x8006 here is the number of berries
BerryTree_EventScript_CheckBerryFullyGrown::
	buffernumberstring STR_VAR_2, VAR_0x8006
	lock
	faceplayer
	goto BerryTree_EventScript_PickBerry

BerryTree_EventScript_PickBerry::
	special ObjectEventInteractionPickBerryTree
	goto_if_eq VAR_0x8004, 0, BerryTree_EventScript_BerryPocketFull
	special IncrementDailyPickedBerries
	special ObjectEventInteractionRemoveBerryTree
	message BerryTree_Text_PickedTheBerry
	playfanfare MUS_OBTAIN_BERRY
	waitmessage
	waitfanfare
	release
	end

BerryTree_EventScript_BerryPocketFull::
	message BerryTree_Text_BerryPocketFull
	waitmessage
	waitbuttonpress
	release
	end

BerryTree_EventScript_ItemUsePlantBerry::
	lockall
	special ObjectEventInteractionGetBerryTreeData
	call BerryTree_EventScript_PlantBerry
	releaseall
	end

BerryTree_EventScript_DontWater::
	releaseall
	end

BerryTree_EventScript_ItemUseWailmerPail::
	special ObjectEventInteractionGetBerryTreeData
	lockall
BerryTree_EventScript_WaterBerry::
	special ObjectEventInteractionWaterBerryTree
	special DoWateringBerryTreeAnim
	releaseall
	end

BerryTree_EventScript_PlantBerry::
	special ObjectEventInteractionPlantBerryTree
	incrementgamestat GAME_STAT_PLANTED_BERRIES
	special IncrementDailyPlantedBerries
	return

BerryTree_Text_ItsSoftLoamySoil:
	.string "Đất ở đây mềm và tơi xốp.$"

BerryTree_Text_BerryGrowthStage1:
	.string "Đã trồng một {STR_VAR_1} ở đây.$"

BerryTree_Text_BerryGrowthStage1Water:
	.string "Đã trồng một {STR_VAR_1} ở đây.\n"
	.string "Tưới bằng WAILMER PAIL chứ?$"

BerryTree_Text_BerryGrowthStage2:
	.string "{STR_VAR_1} đã nảy mầm.$"

BerryTree_Text_BerryGrowthStage2Water:
	.string "{STR_VAR_1} đã nảy mầm.\n"
	.string "Tưới bằng WAILMER PAIL chứ?$"

BerryTree_Text_BerryGrowthStage3:
	.string "Cây {STR_VAR_1} đang lớn dần.$"

BerryTree_Text_BerryGrowthStage3Water:
	.string "Cây {STR_VAR_1} đang lớn dần.\n"
	.string "Tưới bằng WAILMER PAIL chứ?$"

BerryTree_Text_BerryGrowthStage4:
	.string "Hoa {STR_VAR_1} đang nở\n"
	.string "{STR_VAR_2}.$"

BerryTree_Text_BerryGrowthStage4Water:
	.string "Hoa {STR_VAR_1} đang nở {STR_VAR_2}.\n"
	.string "Bạn muốn tưới cây chứ?$"

BerryTree_Text_CareAdverbGreat:
	.string "rất đẹp$"

BerryTree_Text_CareAdverbPoor:
	.string "dễ thương$"

BerryTree_Text_CareAdverbGood:
	.string "xinh xắn$"

BerryTree_Text_PickedTheBerry:
	.string "{PLAYER} hái {STR_VAR_2} {STR_VAR_1}.$"

BerryTree_Text_BerryPocketFull:
	.string "BERRIES POCKET trong TÚI ĐỒ đã đầy.\p"
	.string "Không thể lấy {STR_VAR_1}.$"

BerryTree_Text_ExclamationPoint:
	.string "!$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global BerryTree_Text_ItsSoftLoamySoil
	.global BerryTree_Text_BerryGrowthStage1
	.global BerryTree_Text_BerryGrowthStage1Water
	.global BerryTree_Text_BerryGrowthStage2
	.global BerryTree_Text_BerryGrowthStage2Water
	.global BerryTree_Text_BerryGrowthStage3
	.global BerryTree_Text_BerryGrowthStage3Water
	.global BerryTree_Text_BerryGrowthStage4
	.global BerryTree_Text_BerryGrowthStage4Water
	.global BerryTree_Text_CareAdverbGreat
	.global BerryTree_Text_CareAdverbPoor
	.global BerryTree_Text_CareAdverbGood
	.global BerryTree_Text_PickedTheBerry
	.global BerryTree_Text_BerryPocketFull
@ END GENERATED LOCALIZATION EXPORTS
