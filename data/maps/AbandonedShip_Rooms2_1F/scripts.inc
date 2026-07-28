AbandonedShip_Rooms2_1F_MapScripts::
	.byte 0

AbandonedShip_Rooms2_1F_EventScript_Dan::
	trainerbattle_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_DanIntro, AbandonedShip_Rooms2_1F_Text_DanDefeat, AbandonedShip_Rooms2_1F_Text_DanNotEnoughMons, AbandonedShip_Rooms2_1F_EventScript_RegisterDan
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_Rooms2_1F_EventScript_DanRematch
	msgbox AbandonedShip_Rooms2_1F_Text_DanPostBattle, MSGBOX_DEFAULT
	release
	end

AbandonedShip_Rooms2_1F_EventScript_RegisterDan::
	msgbox AbandonedShip_Rooms2_1F_Text_KiraRegister, MSGBOX_DEFAULT  @ Kira speaks for both when registering KiraAndDan
	register_matchcall TRAINER_KIRA_AND_DAN_1
	release
	end

AbandonedShip_Rooms2_1F_EventScript_DanRematch::
	trainerbattle_rematch_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_DanRematchIntro, AbandonedShip_Rooms2_1F_Text_DanRematchDefeat, AbandonedShip_Rooms2_1F_Text_DanRematchNotEnoughMons
	msgbox AbandonedShip_Rooms2_1F_Text_DanPostRematch, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_EventScript_Kira::
	trainerbattle_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_KiraIntro, AbandonedShip_Rooms2_1F_Text_KiraDefeat, AbandonedShip_Rooms2_1F_Text_KiraNotEnoughMons, AbandonedShip_Rooms2_1F_EventScript_RegisterKira
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_Rooms2_1F_EventScript_KiraRematch
	msgbox AbandonedShip_Rooms2_1F_Text_KiraPostBattle, MSGBOX_DEFAULT
	release
	end

AbandonedShip_Rooms2_1F_EventScript_RegisterKira::
	msgbox AbandonedShip_Rooms2_1F_Text_KiraRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_KIRA_AND_DAN_1
	release
	end

AbandonedShip_Rooms2_1F_EventScript_KiraRematch::
	trainerbattle_rematch_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_KiraRematchIntro, AbandonedShip_Rooms2_1F_Text_KiraRematchDefeat, AbandonedShip_Rooms2_1F_Text_KiraRematchNotEnoughMons
	msgbox AbandonedShip_Rooms2_1F_Text_KiraPostRematch, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_EventScript_Jani::
	trainerbattle_single TRAINER_JANI, AbandonedShip_Rooms2_1F_Text_JaniIntro, AbandonedShip_Rooms2_1F_Text_JaniDefeat
	msgbox AbandonedShip_Rooms2_1F_Text_JaniPostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_EventScript_Garrison::
	trainerbattle_single TRAINER_GARRISON, AbandonedShip_Rooms2_1F_Text_GarrisonIntro, AbandonedShip_Rooms2_1F_Text_GarrisonDefeat
	msgbox AbandonedShip_Rooms2_1F_Text_GarrisonPostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_Text_DanIntro:
	.string "DAN: Trong lúc tìm kho báu, chúng tôi lại\n"
	.string "phát hiện ra một HLV!$"

AbandonedShip_Rooms2_1F_Text_DanDefeat:
	.string "DAN: Dù phối hợp với nhau, chúng tôi vẫn\n"
	.string "không thắng nổi...$"

AbandonedShip_Rooms2_1F_Text_DanPostBattle:
	.string "DAN: Chúng tôi chẳng tìm thấy kho báu\n"
	.string "nào... Không biết có ai lấy hết rồi\l"
	.string "không?$"

AbandonedShip_Rooms2_1F_Text_DanNotEnoughMons:
	.string "DAN: Bạn còn chẳng có đủ hai POKéMON.\n"
	.string "Như vậy thì đừng mong đánh bại được\l"
	.string "chúng tôi.$"

AbandonedShip_Rooms2_1F_Text_KiraIntro:
	.string "KIRA: Ồ? Chúng tôi đang tìm kho báu.\n"
	.string "Nhưng thay vào đó lại phát hiện ra một\l"
	.string "HLV!$"

AbandonedShip_Rooms2_1F_Text_KiraDefeat:
	.string "KIRA: Ôi, mạnh quá!$"

AbandonedShip_Rooms2_1F_Text_KiraPostBattle:
	.string "KIRA: Kho báu có thể ở đâu nhỉ?\p"
	.string "Tôi đã quyết định sẽ mua gì khi tìm\n"
	.string "thấy kho báu rồi!$"

AbandonedShip_Rooms2_1F_Text_KiraNotEnoughMons:
	.string "KIRA: Ồ, bạn không có hai POKéMON à? Vậy\n"
	.string "để khi khác chúng ta đấu nhé!$"

AbandonedShip_Rooms2_1F_Text_KiraRegister:
	.string "KIRA: Ôi, bạn làm tôi tức quá! Vì thế tôi\n"
	.string "sẽ đăng ký bạn!$"

AbandonedShip_Rooms2_1F_Text_DanRematchIntro:
	.string "DAN: Suốt thời gian qua, chúng tôi vẫn\n"
	.string "luôn tìm kiếm kho báu.\p"
	.string "POKéMON của chúng tôi cũng đã mạnh\n"
	.string "hơn. Để chúng tôi cho bạn xem nhé?$"

AbandonedShip_Rooms2_1F_Text_DanRematchDefeat:
	.string "DAN: Bạn vẫn mạnh như mọi khi!$"

AbandonedShip_Rooms2_1F_Text_DanPostRematch:
	.string "DAN: Kho báu thì không tìm thấy, đấu\n"
	.string "POKéMON lại thua...\p"
	.string "Tôi muốn về nhà... Nhưng hễ tôi nói vậy\n"
	.string "là cô ấy lại nổi giận với tôi...$"

AbandonedShip_Rooms2_1F_Text_DanRematchNotEnoughMons:
	.string "DAN: Bạn còn chẳng có đủ hai POKéMON.\n"
	.string "Như vậy thì đừng mong đánh bại được\l"
	.string "chúng tôi.$"

AbandonedShip_Rooms2_1F_Text_KiraRematchIntro:
	.string "KIRA: Ồ? Chúng ta lại gặp nhau rồi!\p"
	.string "Giống chúng tôi, bạn vẫn chưa từ bỏ\n"
	.string "việc tìm kho báu, đúng không?\p"
	.string "Hay là ai thua thì phải bỏ cuộc tìm kiếm\n"
	.string "nhé?$"

AbandonedShip_Rooms2_1F_Text_KiraRematchDefeat:
	.string "KIRA: Ôi, chúng tôi lại thua rồi...$"

AbandonedShip_Rooms2_1F_Text_KiraPostRematch:
	.string "KIRA: Chúng tôi sẽ không rời đi cho đến\n"
	.string "khi luyện POKéMON mạnh hơn nữa và tìm\l"
	.string "thấy kho báu ở đây!$"

AbandonedShip_Rooms2_1F_Text_KiraRematchNotEnoughMons:
	.string "KIRA: Ồ, bạn không có hai POKéMON à? Vậy\n"
	.string "để khi khác chúng ta đấu nhé!$"

AbandonedShip_Rooms2_1F_Text_JaniIntro:
	.string "Tôi bơi không giỏi, nhưng đấu thì rất\n"
	.string "giỏi!$"

AbandonedShip_Rooms2_1F_Text_JaniDefeat:
	.string "Ối. Không được suôn sẻ cho lắm.$"

AbandonedShip_Rooms2_1F_Text_JaniPostBattle:
	.string "Đi chân trần quanh con tàu này thấy ghê\n"
	.string "ghê.$"

AbandonedShip_Rooms2_1F_Text_GarrisonIntro:
	.string "Sức mạnh và lòng nhân ái... Đó chính là\n"
	.string "kho báu của một HLV!$"

AbandonedShip_Rooms2_1F_Text_GarrisonDefeat:
	.string "À, ở bạn có điều gì đó thật rạng ngời.$"

AbandonedShip_Rooms2_1F_Text_GarrisonPostBattle:
	.string "Tôi đã thấy thứ gì đó lấp lánh trong\n"
	.string "một căn phòng nào đó trên tàu.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global AbandonedShip_Rooms2_1F_Text_DanIntro
	.global AbandonedShip_Rooms2_1F_Text_DanDefeat
	.global AbandonedShip_Rooms2_1F_Text_DanPostBattle
	.global AbandonedShip_Rooms2_1F_Text_DanNotEnoughMons
	.global AbandonedShip_Rooms2_1F_Text_KiraIntro
	.global AbandonedShip_Rooms2_1F_Text_KiraDefeat
	.global AbandonedShip_Rooms2_1F_Text_KiraPostBattle
	.global AbandonedShip_Rooms2_1F_Text_KiraNotEnoughMons
	.global AbandonedShip_Rooms2_1F_Text_KiraRegister
	.global AbandonedShip_Rooms2_1F_Text_DanRematchIntro
	.global AbandonedShip_Rooms2_1F_Text_DanRematchDefeat
	.global AbandonedShip_Rooms2_1F_Text_DanPostRematch
	.global AbandonedShip_Rooms2_1F_Text_DanRematchNotEnoughMons
	.global AbandonedShip_Rooms2_1F_Text_KiraRematchIntro
	.global AbandonedShip_Rooms2_1F_Text_KiraRematchDefeat
	.global AbandonedShip_Rooms2_1F_Text_KiraPostRematch
	.global AbandonedShip_Rooms2_1F_Text_KiraRematchNotEnoughMons
	.global AbandonedShip_Rooms2_1F_Text_JaniIntro
	.global AbandonedShip_Rooms2_1F_Text_JaniDefeat
	.global AbandonedShip_Rooms2_1F_Text_JaniPostBattle
	.global AbandonedShip_Rooms2_1F_Text_GarrisonIntro
	.global AbandonedShip_Rooms2_1F_Text_GarrisonDefeat
	.global AbandonedShip_Rooms2_1F_Text_GarrisonPostBattle
@ END GENERATED LOCALIZATION EXPORTS
