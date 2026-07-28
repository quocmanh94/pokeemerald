MauvilleCity_House1_MapScripts::
	.byte 0

MauvilleCity_House1_EventScript_RockSmashDude::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_ROCK_SMASH, MauvilleCity_House1_EventScript_ReceivedRockSmash
	msgbox MauvilleCity_House1_Text_ImRockSmashDudeTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_HM_ROCK_SMASH
	setflag FLAG_RECEIVED_HM_ROCK_SMASH
	setflag FLAG_HIDE_ROUTE_111_ROCK_SMASH_TIP_GUY
	msgbox MauvilleCity_House1_Text_ExplainRockSmash, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House1_EventScript_ReceivedRockSmash::
	msgbox MauvilleCity_House1_Text_MonCanFlyOutOfSmashedRock, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House1_Text_ImRockSmashDudeTakeThis:
	.string "Woohoo!\p"
	.string "Tôi nghe mọi người gọi mình là ROCK\n"
	.string "SMASH GUY, nhưng nghe vậy hơi hạ thấp\l"
	.string "tôi.\p"
	.string "Tôi nghĩ mình đáng được tôn trọng hơn\n"
	.string "một chút, chẳng hạn gọi là ROCK SMASH\l"
	.string "DUDE.\p"
	.string "Woohoo!\p"
	.string "Dù sao thì POKéMON của bạn trông khá\n"
	.string "mạnh.\p"
	.string "Tôi thích thế! Này, nhận lấy HIDDEN\n"
	.string "MACHINE này!$"

MauvilleCity_House1_Text_ExplainRockSmash:
	.string "HM đó chứa ROCK SMASH.\p"
	.string "Nếu bạn gặp những tảng đá lớn chắn\n"
	.string "đường...\p"
	.string "Thì cứ dùng chiêu HM đó và đập chúng\n"
	.string "văng khỏi lối đi!\p"
	.string "Chính thế! Cứ đập đá sang một bên!\n"
	.string "Woohoo!$"

MauvilleCity_House1_Text_MonCanFlyOutOfSmashedRock:
	.string "À đúng rồi, khi bạn đập một tảng đá, có\n"
	.string "thể một POKéMON đang ẩn bên trong sẽ\l"
	.string "bay vọt ra.\p"
	.string "Woohoo!$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global MauvilleCity_House1_Text_ImRockSmashDudeTakeThis
	.global MauvilleCity_House1_Text_ExplainRockSmash
	.global MauvilleCity_House1_Text_MonCanFlyOutOfSmashedRock
@ END GENERATED LOCALIZATION EXPORTS
