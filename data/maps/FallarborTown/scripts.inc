FallarborTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FallarborTown_OnTransition
	.byte 0

FallarborTown_OnTransition:
	setflag FLAG_VISITED_FALLARBOR_TOWN
	setvar VAR_CONTEST_HALL_STATE, 0
	end

FallarborTown_EventScript_ExpertM::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, FallarborTown_EventScript_ExpertMNormal
	msgbox FallarborTown_Text_ShadyCharactersCozmosHome, MSGBOX_DEFAULT
	release
	end

FallarborTown_EventScript_ExpertMNormal::
	msgbox FallarborTown_Text_RegionKnownForMeteors, MSGBOX_DEFAULT
	release
	end

FallarborTown_EventScript_Girl::
	msgbox FallarborTown_Text_MyPreciousAzurill, MSGBOX_NPC
	end

FallarborTown_EventScript_Gentleman::
	msgbox FallarborTown_Text_HaveYouChallengedFlannery, MSGBOX_NPC
	end

FallarborTown_EventScript_Azurill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZURILL, CRY_MODE_NORMAL
	msgbox FallarborTown_Text_Azurill, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FallarborTown_EventScript_BattleTentSign::
	msgbox FallarborTown_Text_BattleTentSign, MSGBOX_SIGN
	end

FallarborTown_EventScript_TownSign::
	msgbox FallarborTown_Text_TownSign, MSGBOX_SIGN
	end

FallarborTown_EventScript_MoveTutorSign::
	msgbox FallarborTown_Text_MoveTutorSign, MSGBOX_SIGN
	end

FallarborTown_Text_ShadyCharactersCozmosHome:
	.string "Có chuyện gì đó đang xảy ra, và tôi\n"
	.string "không thích chút nào!\p"
	.string "Tôi đã thấy những kẻ khả nghi cứ ra vào\n"
	.string "nhà của PROF. COZMO...$"

FallarborTown_Text_RegionKnownForMeteors:
	.string "Vùng này đã nổi tiếng với thiên thạch\n"
	.string "từ thời xa xưa.\p"
	.string "Người ta nói METEOR FALLS được tạo\n"
	.string "thành khi một thiên thạch rơi xuống và\l"
	.string "khoét sâu vào mặt đất từ lâu lắm rồi.$"

FallarborTown_Text_MyPreciousAzurill:
	.string "Thấy chưa! Nhìn này! Đây là AZURILL\n"
	.string "quý giá của tôi!\p"
	.string "Nó trơn mượt, mềm mại, lại còn êm ái\n"
	.string "nữa!$"

FallarborTown_Text_Azurill:
	.string "AZURILL: Rooreelooo.$"

FallarborTown_Text_HaveYouChallengedFlannery:
	.string "Bạn đã thách đấu FLANNERY, LEADER của\n"
	.string "LAVARIDGE GYM chưa?\p"
	.string "Ông của cô ấy từng rất nổi tiếng. Ông\n"
	.string "từng là một thành viên ELITE FOUR của\l"
	.string "POKéMON LEAGUE.\p"
	.string "Tôi sẽ chẳng ngạc nhiên nếu FLANNERY\n"
	.string "tự mình trở thành một HLV vĩ đại.$"

FallarborTown_Text_BattleTentSign:
	.string "BATTLE TENT, KHU FALLARBOR “Nơi những\n"
	.string "đội hình xuất sắc nhất hội tụ!”$"

FallarborTown_Text_TownSign:
	.string "FALLARBOR TOWN “Cộng đồng nông nghiệp\n"
	.string "với những khu vườn nhỏ.”$"

FallarborTown_Text_MoveTutorSign:
	.string "NHÀ CỦA MOVE TUTOR “Dạy POKéMON những\n"
	.string "chiêu mới.”$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global FallarborTown_Text_ShadyCharactersCozmosHome
	.global FallarborTown_Text_RegionKnownForMeteors
	.global FallarborTown_Text_MyPreciousAzurill
	.global FallarborTown_Text_HaveYouChallengedFlannery
	.global FallarborTown_Text_BattleTentSign
	.global FallarborTown_Text_TownSign
	.global FallarborTown_Text_MoveTutorSign
@ END GENERATED LOCALIZATION EXPORTS
