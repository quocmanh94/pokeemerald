Route116_TunnelersRestHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route116_TunnelersRestHouse_OnTransition
	.byte 0

Route116_TunnelersRestHouse_OnTransition:
	setflag FLAG_LANDMARK_TUNNELERS_REST_HOUSE
	end

Route116_TunnelersRestHouse_EventScript_Tunneler1::
	msgbox Route116_TunnelersRestHouse_Text_WeHadToStopBoring, MSGBOX_NPC
	end

Route116_TunnelersRestHouse_EventScript_Tunneler2::
	msgbox Route116_TunnelersRestHouse_Text_ManDiggingHisWayToVerdanturf, MSGBOX_NPC
	end

Route116_TunnelersRestHouse_EventScript_Tunneler3::
	lock
	faceplayer
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, Route116_TunnelersRestHouse_EventScript_TunnelOpened
	msgbox Route116_TunnelersRestHouse_Text_GetToVerdanturfWithoutTunnel, MSGBOX_DEFAULT
	release
	end

Route116_TunnelersRestHouse_EventScript_TunnelOpened::
	msgbox Route116_TunnelersRestHouse_Text_TunnelHasGoneThrough, MSGBOX_DEFAULT
	release
	end

Route116_TunnelersRestHouse_Text_WeHadToStopBoring:
	.string "RUSTURF TUNNEL đằng kia...\p"
	.string "Ban đầu, chúng tôi có cả một đội thi\n"
	.string "công đông đảo dùng máy móc hiện đại\l"
	.string "nhất để khoan xuyên đá. Nhưng rồi phải\l"
	.string "dừng lại.\p"
	.string "Hóa ra công trình sẽ gây ảnh hưởng xấu\n"
	.string "đến POKéMON hoang dã trong khu vực.\p"
	.string "Thế nên chúng tôi chẳng còn việc gì\n"
	.string "ngoài ngồi đây chơi không.$"

Route116_TunnelersRestHouse_Text_ManDiggingHisWayToVerdanturf:
	.string "Có một người đàn ông đang một mình\n"
	.string "đào đường tới VERDANTURF. Ông ấy\l"
	.string "quyết tâm phải đào thông.\p"
	.string "Ông ấy nói rằng nếu cứ đào từng chút\n"
	.string "một mà không dùng máy móc thì sẽ không\l"
	.string "quấy rầy POKéMON và cũng tránh làm hại\l"
	.string "môi trường tự nhiên.\p"
	.string "Không biết ông ấy đã đào thông chưa\n"
	.string "nhỉ.$"

Route116_TunnelersRestHouse_Text_GetToVerdanturfWithoutTunnel:
	.string "Muốn đến VERDANTURF mà không đi qua\n"
	.string "TUNNEL này, bạn phải vượt biển tới\l"
	.string "DEWFORD, đi thuyền tiếp đến SLATEPORT,\l"
	.string "rồi băng qua MAUVILLE.$"

Route116_TunnelersRestHouse_Text_TunnelHasGoneThrough:
	.string "Bạn nghe tin chưa? TUNNEL đến\n"
	.string "VERDANTURF đã được đào thông rồi!\p"
	.string "Đôi khi, chỉ cần đủ lòng mong mỏi thì\n"
	.string "ước mơ thật sự sẽ thành hiện thực.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global Route116_TunnelersRestHouse_Text_WeHadToStopBoring
	.global Route116_TunnelersRestHouse_Text_ManDiggingHisWayToVerdanturf
	.global Route116_TunnelersRestHouse_Text_GetToVerdanturfWithoutTunnel
	.global Route116_TunnelersRestHouse_Text_TunnelHasGoneThrough
@ END GENERATED LOCALIZATION EXPORTS
