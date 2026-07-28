PacifidlogTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PacifidlogTown_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, PacifidlogTown_OnResume
	.byte 0

PacifidlogTown_OnTransition:
	setflag FLAG_VISITED_PACIFIDLOG_TOWN
	end

PacifidlogTown_OnResume:
	setstepcallback STEP_CB_PACIFIDLOG_BRIDGE
	end

PacifidlogTown_EventScript_NinjaBoy::
	msgbox PacifidlogTown_Text_NeatHousesOnWater, MSGBOX_NPC
	end

PacifidlogTown_EventScript_Girl::
	msgbox PacifidlogTown_Text_FastRunningCurrent, MSGBOX_NPC
	end

PacifidlogTown_EventScript_Fisherman::
	msgbox PacifidlogTown_Text_SkyPillarTooScary, MSGBOX_NPC
	end

PacifidlogTown_EventScript_TownSign::
	msgbox PacifidlogTown_Text_TownSign, MSGBOX_SIGN
	end

PacifidlogTown_Text_FastRunningCurrent:
	.string "Vùng biển giữa PACIFIDLOG và\n"
	.string "SLATEPORT có dòng thủy triều chảy rất\l"
	.string "xiết.\p"
	.string "Nếu dùng SURF, cậu có thể bị cuốn trôi\n"
	.string "đến một nơi khác.$"

PacifidlogTown_Text_NeatHousesOnWater:
	.string "Thấy chưa, tuyệt lắm phải không? Những\n"
	.string "ngôi nhà này nằm trên mặt nước!\p"
	.string "Tôi được sinh ra ở đây đấy!$"

PacifidlogTown_Text_SkyPillarTooScary:
	.string "SKY PILLAR ư?\p"
	.string "...À, chắc cậu đang nói tới tòa tháp cao\n"
	.string "thật cao ở ngoài xa hơn một chút.\p"
	.string "Nếu là tôi thì tôi sẽ không leo lên đó.\n"
	.string "Lên cao như vậy đáng sợ lắm.\p"
	.string "Sống ngang mực nước biển tại\n"
	.string "PACIFIDLOG là hợp với tôi rồi.$"

PacifidlogTown_Text_TownSign:
	.string "PACIFIDLOG TOWN\p"
	.string "“Nơi mặt trời ban mai mỉm cười trên\n"
	.string "sóng nước.”$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global PacifidlogTown_Text_FastRunningCurrent
	.global PacifidlogTown_Text_NeatHousesOnWater
	.global PacifidlogTown_Text_SkyPillarTooScary
	.global PacifidlogTown_Text_TownSign
@ END GENERATED LOCALIZATION EXPORTS
