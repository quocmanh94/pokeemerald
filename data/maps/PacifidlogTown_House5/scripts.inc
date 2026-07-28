PacifidlogTown_House5_MapScripts::
	.byte 0

PacifidlogTown_House5_EventScript_MirageIslandWatcher::
	lock
	faceplayer
	specialvar VAR_RESULT, IsMirageIslandPresent
	goto_if_eq VAR_RESULT, TRUE, PacifidlogTown_House5_EventScript_MirageIslandPresent
	msgbox PacifidlogTown_House5_Text_CantSeeMirageIslandToday, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House5_EventScript_MirageIslandPresent::
	msgbox PacifidlogTown_House5_Text_CanSeeMirageIslandToday, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House5_EventScript_Gentleman::
	msgbox PacifidlogTown_House5_Text_MirageIslandAppearDependingOnWeather, MSGBOX_NPC
	end

PacifidlogTown_House5_Text_CantSeeMirageIslandToday:
	.string "Hôm nay tôi không thấy MIRAGE ISLAND...$"

PacifidlogTown_House5_Text_CanSeeMirageIslandToday:
	.string "Ồ! Trời ơi! Hôm nay tôi nhìn thấy\n"
	.string "MIRAGE ISLAND!$"

PacifidlogTown_House5_Text_MirageIslandAppearDependingOnWeather:
	.string "MIRAGE ISLAND...\p"
	.string "Chắc hòn đảo lúc hiện lúc ẩn tùy theo\n"
	.string "điều kiện thời tiết tạo ra ảo ảnh.\p"
	.string "Hay nó thật sự đang xuất hiện rồi biến\n"
	.string "mất?$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global PacifidlogTown_House5_Text_CantSeeMirageIslandToday
	.global PacifidlogTown_House5_Text_CanSeeMirageIslandToday
	.global PacifidlogTown_House5_Text_MirageIslandAppearDependingOnWeather
@ END GENERATED LOCALIZATION EXPORTS
