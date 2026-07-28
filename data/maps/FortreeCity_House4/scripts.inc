FortreeCity_House4_MapScripts::
	.byte 0

FortreeCity_House4_EventScript_Woman::
	msgbox FortreeCity_House4_Text_BringsWorldCloserTogether, MSGBOX_NPC
	end

FortreeCity_House4_EventScript_Boy::
	lockall
	goto_if_set FLAG_RECEIVED_MENTAL_HERB, FortreeCity_House4_EventScript_ReceivedMentalHerb
	goto_if_set FLAG_WINGULL_DELIVERED_MAIL, FortreeCity_House4_EventScript_WingullReturned
	goto_if_set FLAG_WINGULL_SENT_ON_ERRAND, FortreeCity_House4_EventScript_WingullOnErrand
	msgbox FortreeCity_House4_Text_GoBirdPokemon, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_WINGULL_SENT_ON_ERRAND
	clearflag FLAG_HIDE_MOSSDEEP_CITY_HOUSE_2_WINGULL
	applymovement LOCALID_FORTREE_HOUSE_WINGULL, FortreeCity_House4_Movement_WingullExit
	waitmovement 0
	removeobject LOCALID_FORTREE_HOUSE_WINGULL
	releaseall
	end

FortreeCity_House4_EventScript_WingullOnErrand::
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox FortreeCity_House4_Text_AskedWingullToRunErrand, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_House4_EventScript_WingullReturned::
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox FortreeCity_House4_Text_WelcomeWingullTakeMentalHerb, MSGBOX_DEFAULT
	giveitem ITEM_MENTAL_HERB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_MENTAL_HERB
	releaseall
	end

FortreeCity_House4_EventScript_ReceivedMentalHerb::
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox FortreeCity_House4_Text_FriendsFarAwayThanksToWingull, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_House4_Movement_WingullExit:
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_in_place_faster_down
	delay_8
	step_end

FortreeCity_House4_EventScript_Wingull::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
	msgbox FortreeCity_House4_Text_Wingull, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FortreeCity_House4_Text_BringsWorldCloserTogether:
	.string "Khi sống bên POKéMON, con người ngày\n"
	.string "càng kết thêm nhiều bạn bè.\p"
	.string "Và điều đó khiến cả thế giới xích lại\n"
	.string "gần nhau hơn. Tôi thấy thật tuyệt vời!$"

FortreeCity_House4_Text_GoBirdPokemon:
	.string "Nào! Bay đi, BIRD POKéMON!$"

FortreeCity_House4_Text_AskedWingullToRunErrand:
	.string "Hì hì, tôi nhờ WINGULL đi làm giúp một\n"
	.string "việc.$"

FortreeCity_House4_Text_WelcomeWingullTakeMentalHerb:
	.string "Tốt lắm! Mừng em trở về, WINGULL!\p"
	.string "Hả? Cái gì đây? Nó đang cầm gì vậy?\p"
	.string "Một MENTAL HERB sao? Chắc nó nhặt\n"
	.string "được ở đâu đó.\p"
	.string "Nhưng tôi không phải HLV, nên bạn\n"
	.string "cứ nhận lấy đi.$"

FortreeCity_House4_Text_FriendsFarAwayThanksToWingull:
	.string "Nhờ WINGULL, tôi có những người bạn\n"
	.string "sống ở rất xa.$"

FortreeCity_House4_Text_Wingull:
	.string "WINGULL: Pihyoh!$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global FortreeCity_House4_Text_BringsWorldCloserTogether
	.global FortreeCity_House4_Text_GoBirdPokemon
	.global FortreeCity_House4_Text_AskedWingullToRunErrand
	.global FortreeCity_House4_Text_WelcomeWingullTakeMentalHerb
	.global FortreeCity_House4_Text_FriendsFarAwayThanksToWingull
@ END GENERATED LOCALIZATION EXPORTS
