BattleFrontier_Lounge4_MapScripts::
	.byte 0

BattleFrontier_Lounge4_EventScript_Woman::
	msgbox BattleFrontier_Lounge4_Text_WonderIfInterviewsAiring, MSGBOX_NPC
	end

BattleFrontier_Lounge4_EventScript_Cook::
	msgbox BattleFrontier_Lounge4_Text_IfIOpenedRestaurantHere, MSGBOX_NPC
	end

BattleFrontier_Lounge4_EventScript_Man::
	msgbox BattleFrontier_Lounge4_Text_NeedBreatherAfterBattles, MSGBOX_NPC
	end

BattleFrontier_Lounge4_Text_WonderIfInterviewsAiring:
	.string "Không biết hôm nay họ có phát sóng cuộc\n"
	.string "phỏng vấn với những HLV mạnh\l"
	.string "không nhỉ?$"

BattleFrontier_Lounge4_Text_IfIOpenedRestaurantHere:
	.string "Nếu mở nhà hàng ở đây, chắc chắn tôi sẽ\n"
	.string "kiếm bộn tiền.$"

BattleFrontier_Lounge4_Text_NeedBreatherAfterBattles:
	.string "Phù.\p"
	.string "Sau những trận đấu căng thẳng, tôi phải\n"
	.string "nghỉ lấy hơi một chút.\p"
	.string "Nhưng ngay cả lúc này, đầu óc tôi vẫn\n"
	.string "không ngừng tính toán chiến thuật và\l"
	.string "các chuỗi phối hợp.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global BattleFrontier_Lounge4_Text_WonderIfInterviewsAiring
	.global BattleFrontier_Lounge4_Text_IfIOpenedRestaurantHere
	.global BattleFrontier_Lounge4_Text_NeedBreatherAfterBattles
@ END GENERATED LOCALIZATION EXPORTS
