MauvilleCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MauvilleCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

MauvilleCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_MAUVILLE_CITY
	call Common_EventScript_UpdateBrineyLocation
	goto MauvilleCity_PokemonCenter_1F_EventScript_SetMauvilleOldManGfx
	end

MauvilleCity_PokemonCenter_1F_EventScript_SetMauvilleOldManGfx::
	special SetMauvilleOldManObjEventGfx
	end

MauvilleCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_MAUVILLE_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_Woman1::
	msgbox MauvilleCity_PokemonCenter_1F_Text_ManOverThereSaysWeirdThings, MSGBOX_NPC
	end

MauvilleCity_PokemonCenter_1F_EventScript_Woman2::
	msgbox MauvilleCity_PokemonCenter_1F_Text_MyDataUpdatedFromRecordCorner, MSGBOX_NPC
	end

MauvilleCity_PokemonCenter_1F_EventScript_Youngster::
	msgbox MauvilleCity_PokemonCenter_1F_Text_RecordCornerSoundsFun, MSGBOX_NPC
	end

MauvilleCity_PokemonCenter_1F_Text_ManOverThereSaysWeirdThings:
	.string "Người đàn ông đằng kia nói toàn những\n"
	.string "điều kỳ quặc!\p"
	.string "Ông ấy kỳ quặc mà buồn cười lắm. Chắc\n"
	.string "tôi chẳng quên được ông ấy đâu!$"

MauvilleCity_PokemonCenter_1F_Text_MyDataUpdatedFromRecordCorner:
	.string "Khi tôi truy cập RECORD CORNER, dữ liệu\n"
	.string "về chủ đề đang thịnh hành ở DEWFORD đã\l"
	.string "được cập nhật.\p"
	.string "Giờ phần dữ liệu đó giống hệt của bạn\n"
	.string "tôi rồi!$"

MauvilleCity_PokemonCenter_1F_Text_RecordCornerSoundsFun:
	.string "Một RECORD CORNER vừa mở ở tầng trên\n"
	.string "của POKéMON CENTER.\p"
	.string "Tôi không biết đó là gì, nhưng nghe có\n"
	.string "vẻ vui. Tôi sẽ lên xem!$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global MauvilleCity_PokemonCenter_1F_Text_ManOverThereSaysWeirdThings
	.global MauvilleCity_PokemonCenter_1F_Text_MyDataUpdatedFromRecordCorner
	.global MauvilleCity_PokemonCenter_1F_Text_RecordCornerSoundsFun
@ END GENERATED LOCALIZATION EXPORTS
