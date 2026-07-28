AbandonedShip_Corridors_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, AbandonedShip_Corridors_B1F_OnResume
	map_script MAP_SCRIPT_ON_LOAD, AbandonedShip_Corridors_B1F_OnLoad
	.byte 0

AbandonedShip_Corridors_B1F_OnResume:
	setdivewarp MAP_ABANDONED_SHIP_UNDERWATER1, 5, 4
	end

AbandonedShip_Corridors_B1F_OnLoad:
	call_if_unset FLAG_USED_STORAGE_KEY, AbandonedShip_Corridors_B1F_EventScript_LockStorageRoom
	call_if_set FLAG_USED_STORAGE_KEY, AbandonedShip_Corridors_B1F_EventScript_UnlockStorageRoom
	end

AbandonedShip_Corridors_B1F_EventScript_LockStorageRoom::
	setmetatile 11, 4, METATILE_InsideShip_IntactDoor_Bottom_Locked, TRUE
	return

AbandonedShip_Corridors_B1F_EventScript_UnlockStorageRoom::
	setmetatile 11, 4, METATILE_InsideShip_IntactDoor_Bottom_Unlocked, TRUE
	return

AbandonedShip_Corridors_B1F_EventScript_TuberM::
	msgbox AbandonedShip_Corridors_B1F_Text_YayItsAShip, MSGBOX_NPC
	end

AbandonedShip_Corridors_B1F_EventScript_StorageRoomDoor::
	lockall
	goto_if_set FLAG_USED_STORAGE_KEY, AbandonedShip_Corridors_B1F_EventScript_DoorIsUnlocked
	checkitem ITEM_STORAGE_KEY
	goto_if_eq VAR_RESULT, FALSE, AbandonedShip_Corridors_B1F_EventScript_DoorIsLocked
	msgbox AbandonedShip_Corridors_B1F_Text_InsertedStorageKey, MSGBOX_DEFAULT
	playse SE_PIN
	removeitem ITEM_STORAGE_KEY
	setflag FLAG_USED_STORAGE_KEY
	call AbandonedShip_Corridors_B1F_EventScript_UnlockStorageRoom
	special DrawWholeMapView
	releaseall
	end

AbandonedShip_Corridors_B1F_EventScript_DoorIsLocked::
	msgbox AbandonedShip_Corridors_B1F_Text_DoorIsLocked, MSGBOX_DEFAULT
	releaseall
	end

AbandonedShip_Corridors_B1F_EventScript_DoorIsUnlocked::
	msgbox AbandonedShip_Text_TheDoorIsOpen, MSGBOX_DEFAULT
	releaseall
	end

AbandonedShip_Corridors_B1F_EventScript_Duncan::
	trainerbattle_single TRAINER_DUNCAN, AbandonedShip_Corridors_B1F_Text_DuncanIntro, AbandonedShip_Corridors_B1F_Text_DuncanDefeat
	msgbox AbandonedShip_Corridors_B1F_Text_DuncanPostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Corridors_B1F_Text_DuncanIntro:
	.string "Mỗi khi ra khơi, SAILORS chúng tôi luôn\n"
	.string "mang theo POKéMON. Đấu nhanh một trận\l"
	.string "nhé?$"

AbandonedShip_Corridors_B1F_Text_DuncanDefeat:
	.string "Ối, tôi chìm nghỉm rồi!$"

AbandonedShip_Corridors_B1F_Text_DuncanPostBattle:
	.string "Phần đáy tàu đã chìm xuống vực sâu.\p"
	.string "Nếu có POKéMON biết cách đi dưới nước,\n"
	.string "có lẽ chúng ta sẽ tiến xa hơn...$"

AbandonedShip_Corridors_B1F_Text_YayItsAShip:
	.string "Hoan hô! Một con tàu!$"

AbandonedShip_Corridors_B1F_Text_DoorIsLocked:
	.string "Cửa đã khóa.\p"
	.string "Trên cửa có sơn chữ STORAGE.$"

AbandonedShip_Corridors_B1F_Text_InsertedStorageKey:
	.string "{PLAYER} tra STORAGE KEY vào rồi\n"
	.string "xoay.\p"
	.string "KEY bị kẹt cứng trong ổ, nhưng cửa đã\n"
	.string "mở.$"

AbandonedShip_Text_TheDoorIsOpen:
	.string "Cửa đang mở.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global AbandonedShip_Corridors_B1F_Text_DuncanIntro
	.global AbandonedShip_Corridors_B1F_Text_DuncanDefeat
	.global AbandonedShip_Corridors_B1F_Text_DuncanPostBattle
	.global AbandonedShip_Corridors_B1F_Text_YayItsAShip
	.global AbandonedShip_Corridors_B1F_Text_DoorIsLocked
	.global AbandonedShip_Corridors_B1F_Text_InsertedStorageKey
	.global AbandonedShip_Text_TheDoorIsOpen
@ END GENERATED LOCALIZATION EXPORTS
