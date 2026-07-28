FortreeCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

FortreeCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_FORTREE_CITY
	end

FortreeCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_FORTREE_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

FortreeCity_PokemonCenter_1F_EventScript_Gentleman::
	msgbox FortreeCity_PokemonCenter_1F_Text_GoToSafariZone, MSGBOX_NPC
	end

FortreeCity_PokemonCenter_1F_EventScript_Man::
	msgbox FortreeCity_PokemonCenter_1F_Text_RecordCornerIsNeat, MSGBOX_NPC
	end

FortreeCity_PokemonCenter_1F_EventScript_Boy::
	msgbox FortreeCity_PokemonCenter_1F_Text_DoYouKnowAboutPokenav, MSGBOX_NPC
	end

FortreeCity_PokemonCenter_1F_Text_GoToSafariZone:
	.string "Nghe này, nhóc đang hoàn thành POKéDEX\n"
	.string "à?\p"
	.string "Hừm... Hãy đến SAFARI ZONE. Đó là lời\n"
	.string "khuyên của tôi.$"

FortreeCity_PokemonCenter_1F_Text_RecordCornerIsNeat:
	.string "Bạn đã thử làm gì ở RECORD CORNER\n"
	.string "chưa?\p"
	.string "Chỗ đó khá hay. Nó trộn và ghép các bản\n"
	.string "ghi của HLV.\p"
	.string "Tôi không rõ nó hoạt động thế nào,\n"
	.string "nhưng thú vị lắm. Thậm chí còn rất hào\l"
	.string "hứng nữa!$"

FortreeCity_PokemonCenter_1F_Text_DoYouKnowAboutPokenav:
	.string "Ồ, tuyệt thật, bạn có POKéNAV! Nó giống\n"
	.string "hệt của tôi!\p"
	.string "Bạn có biết hệ thống MATCH CALL của\n"
	.string "POKéNAV không?\p"
	.string "Mở nó ra, bạn có thể trò chuyện với các\n"
	.string "HLV đã đăng ký bất cứ lúc nào.\p"
	.string "Nó còn cho biết HLV nào muốn tái\n"
	.string "đấu với bạn.\p"
	.string "Tiện thật đấy! Mấy người bên DEVON\n"
	.string "đúng là rất giỏi!$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global FortreeCity_PokemonCenter_1F_Text_GoToSafariZone
	.global FortreeCity_PokemonCenter_1F_Text_RecordCornerIsNeat
	.global FortreeCity_PokemonCenter_1F_Text_DoYouKnowAboutPokenav
@ END GENERATED LOCALIZATION EXPORTS
