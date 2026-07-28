CaveOfOrigin_B1F_MapScripts::
	.byte 0

CaveOfOrigin_B1F_EventScript_Wallace::
	lock
	faceplayer
	msgbox CaveOfOrigin_B1F_Text_WallaceStory, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CAVE_OF_ORIGIN_WALLACE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 60
	playse SE_PIN
	applymovement LOCALID_CAVE_OF_ORIGIN_WALLACE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_CAVE_OF_ORIGIN_WALLACE, Common_Movement_Delay48
	waitmovement 0
	delay 30
	applymovement LOCALID_CAVE_OF_ORIGIN_WALLACE, Common_Movement_FacePlayer
	waitmovement 0
	message CaveOfOrigin_B1F_Text_WhereIsRayquaza
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_WheresRayquaza::
	multichoice 0, 0, MULTI_WHERES_RAYQUAZA, FALSE
	switch VAR_RESULT
	case 0, CaveOfOrigin_B1F_EventScript_AtCaveOfOrigin
	case 1, CaveOfOrigin_B1F_EventScript_AtMtPyre
	case 2, CaveOfOrigin_B1F_EventScript_AtSkyPillar
	case 3, CaveOfOrigin_B1F_EventScript_DontRemember
	goto CaveOfOrigin_B1F_EventScript_DontRemember
	end

CaveOfOrigin_B1F_EventScript_AtCaveOfOrigin::
	message CaveOfOrigin_B1F_Text_ButWereInCaveOfOrigin
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_AtMtPyre::
	message CaveOfOrigin_B1F_Text_OldLadyDidntMentionThat
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_DontRemember::
	message CaveOfOrigin_B1F_Text_CantYouRememberSomehow
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_AtSkyPillar::
	msgbox CaveOfOrigin_B1F_Text_WellHeadToSkyPillar, MSGBOX_DEFAULT
	closemessage
	playse SE_EXIT
	fadescreenspeed FADE_TO_BLACK, 4
	setflag FLAG_WALLACE_GOES_TO_SKY_PILLAR
	setvar VAR_SOOTOPOLIS_CITY_STATE, 3
	removeobject LOCALID_CAVE_OF_ORIGIN_WALLACE
	clearflag FLAG_HIDE_SKY_PILLAR_WALLACE
	fadescreen FADE_FROM_BLACK
	release
	end

CaveOfOrigin_B1F_Text_WallaceStory:
	.string "À, vậy cậu là {PLAYER}{KUN}? Tôi đã\n"
	.string "nghe kể về những chiến công của cậu.\p"
	.string "Tên tôi là WALLACE.\p"
	.string "Tôi từng là GYM LEADER của SOOTOPOLIS,\n"
	.string "nhưng rồi có việc xảy ra.\p"
	.string "Vì vậy, giờ tôi đã giao việc điều hành\n"
	.string "GYM cho người thầy JUAN của mình.\p"
	.string "... ... ... ... ... ... ... ... ... ... ... ...\p"
	.string "GROUDON và KYOGRE, hai POKéMON đang\n"
	.string "tàn phá nơi đây, được xem là những\l"
	.string "POKéMON siêu cổ đại.\p"
	.string "Nhưng không chỉ có hai POKéMON siêu cổ\n"
	.string "đại.\p"
	.string "Vẫn còn một POKéMON nữa ở đâu đó.\p"
	.string "Ở một nơi nào đó có POKéMON siêu cổ đại\n"
	.string "mang tên RAYQUAZA.\p"
	.string "Tương truyền chính RAYQUAZA đã dẹp\n"
	.string "yên cuộc giao tranh giữa hai bên trong\l"
	.string "quá khứ xa xưa.\p"
	.string "Nhưng ngay cả tôi cũng không biết\n"
	.string "RAYQUAZA đang ở đâu...$"

CaveOfOrigin_B1F_Text_WhereIsRayquaza:
	.string "WALLACE: {PLAYER}{KUN}, có lẽ cậu biết\n"
	.string "RAYQUAZA hiện đang ở đâu chăng?\p"
	.string "Nếu biết, xin hãy nói cho tôi.$"

CaveOfOrigin_B1F_Text_ButWereInCaveOfOrigin:
	.string "WALLACE: CAVE OF ORIGIN ư?\p"
	.string "Nhưng đó chính là nơi này! Câu trả lời\n"
	.string "đó chưa được!\p"
	.string "Xin cậu hãy suy nghĩ xem RAYQUAZA có\n"
	.string "thể đang ở đâu vào lúc này.$"

CaveOfOrigin_B1F_Text_OldLadyDidntMentionThat:
	.string "WALLACE: MT. PYRE ư?\p"
	.string "Nhưng khi tôi gặp bà lão ở đó lúc nãy,\n"
	.string "bà ấy không hề nhắc đến chuyện này.\p"
	.string "Tôi rất khó tin rằng bà ấy lại cố giấu tôi\n"
	.string "điều gì...\p"
	.string "{PLAYER}{KUN}, cậu có thể suy nghĩ kỹ\n"
	.string "hơn giúp tôi không?$"

CaveOfOrigin_B1F_Text_CantYouRememberSomehow:
	.string "WALLACE: Hả? Cậu không nhớ sao? Hmm...\n"
	.string "Rắc rối rồi đây...\p"
	.string "Cậu không thể cố nhớ lại được sao?$"

CaveOfOrigin_B1F_Text_WellHeadToSkyPillar:
	.string "WALLACE: SKY PILLAR ư?\p"
	.string "Đúng rồi! Nhất định là SKY PILLAR!\p"
	.string "{PLAYER}{KUN}, không thể lãng phí\n"
	.string "thêm giây phút nào nữa! Chúng ta sẽ\l"
	.string "đến SKY PILLAR ngay lập tức!$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global CaveOfOrigin_B1F_Text_WallaceStory
	.global CaveOfOrigin_B1F_Text_WhereIsRayquaza
	.global CaveOfOrigin_B1F_Text_ButWereInCaveOfOrigin
	.global CaveOfOrigin_B1F_Text_OldLadyDidntMentionThat
	.global CaveOfOrigin_B1F_Text_CantYouRememberSomehow
	.global CaveOfOrigin_B1F_Text_WellHeadToSkyPillar
@ END GENERATED LOCALIZATION EXPORTS
