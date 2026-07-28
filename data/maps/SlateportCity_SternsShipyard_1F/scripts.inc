SlateportCity_SternsShipyard_1F_MapScripts::
	.byte 0

SlateportCity_SternsShipyard_1F_EventScript_Dock::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_SternsShipyard_1F_EventScript_FerryReady
	goto_if_set FLAG_BADGE07_GET, SlateportCity_SternsShipyard_1F_EventScript_BrineyJoined
	goto_if_set FLAG_DELIVERED_DEVON_GOODS, SlateportCity_SternsShipyard_1F_EventScript_NeedVeteran
	goto_if_set FLAG_DOCK_REJECTED_DEVON_GOODS, SlateportCity_SternsShipyard_1F_EventScript_GoFindStern
	msgbox SlateportCity_SternsShipyard_1F_Text_CantMakeHeadsOrTails, MSGBOX_DEFAULT
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_MeetDockDeliverToStern, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DOCK, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag FLAG_DOCK_REJECTED_DEVON_GOODS
	setflag FLAG_HIDE_SLATEPORT_CITY_TEAM_AQUA
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_FerryReady::
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_FerryIsReady, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_BrineyJoined::
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_BrineyJoinedUs, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_GoFindStern::
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_CouldYouFindStern, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DOCK, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_NeedVeteran::
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_CouldUseAdviceFromVeteran, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_Scientist1::
	msgbox SlateportCity_SternsShipyard_1F_Text_SeaIsLikeLivingThing, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_1F_EventScript_Scientist2::
	msgbox SlateportCity_SternsShipyard_1F_Text_GetSeasickEasily, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_1F_EventScript_Briney::
	msgbox SlateportCity_SternsShipyard_1F_Text_DecidedToHelpDock, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_1F_Text_CantMakeHeadsOrTails:
	.string "Ờm... Nếu cái này đặt ở đây, còn cái kia\n"
	.string "đặt bên đó...\p"
	.string "Vậy thứ này đặt ở đâu? Còn cái đồ lỉnh\n"
	.string "kỉnh kia thì sao?\p"
	.string "Aaargh! Tôi chẳng hiểu đầu cua tai nheo\n"
	.string "gì cả!$"

SlateportCity_SternsShipyard_1F_Text_MeetDockDeliverToStern:
	.string "Hửm? Chào, tôi là DOCK.\p"
	.string "CAPT. STERN đã giao cho tôi thiết kế một\n"
	.string "chiếc phà.\p"
	.string "Ô! Thứ đằng kia... Có phải DEVON GOODS\n"
	.string "không?\p"
	.string "Nhưng, hừm... Không ổn rồi...\p"
	.string "CAPT. STERN đã đi đâu đó. Ông ấy nói\n"
	.string "mình có việc cần làm.\p"
	.string "Cháu có thể tìm CAPT. STERN và giao món\n"
	.string "đồ đó cho ông ấy được không?$"

SlateportCity_SternsShipyard_1F_Text_CouldYouFindStern:
	.string "DOCK: CAPT. STERN đã đi đâu rồi nhỉ?\p"
	.string "Cháu có thể tìm CAPT. STERN và giao\n"
	.string "kiện hàng đó cho ông ấy được không?$"

SlateportCity_SternsShipyard_1F_Text_CouldUseAdviceFromVeteran:
	.string "DOCK: Đóng tàu là một nghệ thuật.\p"
	.string "Có rất nhiều thứ không thể chỉ dựa vào\n"
	.string "tính toán mà hiểu được.\p"
	.string "Tôi thật sự cần lời khuyên từ một thủy\n"
	.string "thủ kỳ cựu am hiểu biển cả...$"

SlateportCity_SternsShipyard_1F_Text_BrineyJoinedUs:
	.string "DOCK: Chào! MR. BRINEY đã tham gia\n"
	.string "giúp đỡ chúng tôi.\p"
	.string "Nhờ người thủy thủ kỳ cựu ấy, chiếc\n"
	.string "phà đang dần thành hình.$"

SlateportCity_SternsShipyard_1F_Text_FerryIsReady:
	.string "DOCK: Cuối cùng chiếc phà cũng hoàn\n"
	.string "thành!\p"
	.string "S.S. TIDAL mới thật sự là một kỳ quan\n"
	.string "công nghệ!\p"
	.string "Nhưng tôi có cảm giác chúng ta vẫn có\n"
	.string "thể tạo ra thứ còn tuyệt vời hơn.\p"
	.string "Cậu biết đấy, bước tiến của công nghệ\n"
	.string "không bao giờ dừng lại.$"

SlateportCity_SternsShipyard_1F_Text_DecidedToHelpDock:
	.string "MR. BRINEY: A, {PLAYER}{KUN}! Lâu lắm\n"
	.string "rồi mới gặp cháu!\p"
	.string "Ừ, từ khi gặp cháu, lão sói biển này cảm\n"
	.string "thấy sung sức hẳn!\p"
	.string "Vì thế, ta đã quyết định giúp DOCK đóng\n"
	.string "một chiếc phà.\p"
	.string "Ừ, dù sao phà cũng có thể chở được rất\n"
	.string "nhiều người.\p"
	.string "Nhưng cháu biết không, DOCK thật sự là\n"
	.string "một người đặc biệt.\p"
	.string "Với tài công nghệ của cậu ấy và kinh\n"
	.string "nghiệm của ta, chúng ta nhất định có\l"
	.string "thể đóng nên một con tàu tuyệt vời, ừ!$"

SlateportCity_SternsShipyard_1F_Text_SeaIsLikeLivingThing:
	.string "Mùa, thời tiết, vị trí của mặt trăng\n"
	.string "trên bầu trời...\p"
	.string "Những điều kiện này và nhiều yếu tố\n"
	.string "khác khiến biển thay đổi sắc thái.\p"
	.string "Đúng vậy! Biển cả giống như một sinh\n"
	.string "vật sống!$"

SlateportCity_SternsShipyard_1F_Text_GetSeasickEasily:
	.string "Tôi rất dễ bị say sóng. Vì vậy, thay vào\n"
	.string "đó tôi được phụ giúp ở đây.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global SlateportCity_SternsShipyard_1F_Text_CantMakeHeadsOrTails
	.global SlateportCity_SternsShipyard_1F_Text_MeetDockDeliverToStern
	.global SlateportCity_SternsShipyard_1F_Text_CouldYouFindStern
	.global SlateportCity_SternsShipyard_1F_Text_CouldUseAdviceFromVeteran
	.global SlateportCity_SternsShipyard_1F_Text_BrineyJoinedUs
	.global SlateportCity_SternsShipyard_1F_Text_FerryIsReady
	.global SlateportCity_SternsShipyard_1F_Text_DecidedToHelpDock
	.global SlateportCity_SternsShipyard_1F_Text_SeaIsLikeLivingThing
	.global SlateportCity_SternsShipyard_1F_Text_GetSeasickEasily
@ END GENERATED LOCALIZATION EXPORTS
