MagmaHideout_4F_MapScripts::
	.byte 0

MagmaHideout_4F_EventScript_Maxie::
	lockall
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
	msgbox MagmaHideout_4F_Text_MaxieAwakenGroudon, MSGBOX_DEFAULT
	closemessage
	delay 20
	setvar VAR_RESULT, 1
	playse SE_M_DETECT
	dofieldeffectsparkle 18, 42, 0
	waitfieldeffect FLDEFF_SPARKLE
	setvar VAR_RESULT, 1
	playfanfare MUS_AWAKEN_LEGEND
	playse SE_ORB
	special DoOrbEffect
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 150
	removeobject LOCALID_MAGMA_HIDEOUT_4F_GROUDON_SLEEPING
	addobject LOCALID_MAGMA_HIDEOUT_4F_GROUDON
	waitstate
	delay 60
	applymovement LOCALID_MAGMA_HIDEOUT_4F_GROUDON, MagmaHideout_4F_Movement_GroudonApproach
	waitmovement 0
	special FadeOutOrbEffect
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	applymovement LOCALID_MAGMA_HIDEOUT_4F_GROUDON, MagmaHideout_4F_Movement_GroudonExit
	waitmovement 0
	removeobject LOCALID_MAGMA_HIDEOUT_4F_GROUDON
	delay 4
	setvar VAR_0x8004, 2  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	delay 30
	applymovement LOCALID_MAGMA_HIDEOUT_4F_MAXIE, MagmaHideout_4F_Movement_MaxieLookAround
	waitmovement 0
	msgbox MagmaHideout_4F_Text_MaxieGroudonWhatsWrong, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 30
	applymovement LOCALID_MAGMA_HIDEOUT_4F_MAXIE, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MagmaHideout_4F_Text_MaxieOhItWasYou, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_MAXIE_MAGMA_HIDEOUT, MagmaHideout_4F_Text_MaxieDefeat
	msgbox MagmaHideout_4F_Text_MaxieImGoingAfterGroudon, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_HIDE_SLATEPORT_CITY_CAPTAIN_STERN
	clearflag FLAG_HIDE_SLATEPORT_CITY_GABBY_AND_TY
	setvar VAR_SLATEPORT_CITY_STATE, 1
	setflag FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT
	setvar VAR_SLATEPORT_HARBOR_STATE, 1
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_MAGMA_HIDEOUT_4F_MAXIE
	removeobject LOCALID_MAGMA_HIDEOUT_4F_GRUNT_1
	removeobject LOCALID_MAGMA_HIDEOUT_4F_GRUNT_2
	removeobject LOCALID_MAGMA_HIDEOUT_4F_GRUNT_3
	removeobject LOCALID_MAGMA_HIDEOUT_4F_TABITHA
	setflag FLAG_HIDE_MAGMA_HIDEOUT_GRUNTS
	fadescreen FADE_FROM_BLACK
	releaseall
	end

MagmaHideout_4F_Movement_GroudonApproach:
	delay_16
	delay_16
	walk_slow_down
	delay_16
	delay_16
	delay_16
	walk_slow_down
	delay_16
	delay_16
	delay_16
	step_end

MagmaHideout_4F_Movement_GroudonExit:
	slide_up
	slide_up
	step_end

MagmaHideout_4F_Movement_MaxieLookAround:
	face_left
	delay_16
	face_right
	delay_16
	face_left
	delay_16
	face_right
	delay_16
	face_up
	delay_16
	delay_16
	step_end

MagmaHideout_4F_EventScript_Grunt11::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_11, MagmaHideout_4F_Text_Grunt11Intro, MagmaHideout_4F_Text_Grunt11Defeat
	msgbox MagmaHideout_4F_Text_Grunt11PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_Grunt12::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_12, MagmaHideout_4F_Text_Grunt12Intro, MagmaHideout_4F_Text_Grunt12Defeat
	msgbox MagmaHideout_4F_Text_Grunt12PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_Grunt13::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_13, MagmaHideout_4F_Text_Grunt13Intro, MagmaHideout_4F_Text_Grunt13Defeat
	msgbox MagmaHideout_4F_Text_Grunt13PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_Tabitha::
	trainerbattle_single TRAINER_TABITHA_MAGMA_HIDEOUT, MagmaHideout_4F_Text_TabithaIntro, MagmaHideout_4F_Text_TabithaDefeat
	msgbox MagmaHideout_4F_Text_TabithaPostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_Text_Grunt11Intro:
	.string "Tôi cũng muốn thấy GROUDON, nhưng họ\n"
	.string "đến cái đuôi của nó cũng không cho tôi\l"
	.string "nhìn...\p"
	.string "Bực thật đấy.\p"
	.string "Ôi không! Tôi lỡ mồm nói về GROUDON rồi!$"

MagmaHideout_4F_Text_Grunt11Defeat:
	.string "Xem ra tâm không tĩnh thì không thể\n"
	.string "thắng được...$"

MagmaHideout_4F_Text_Grunt11PostBattle:
	.string "Không biết GROUDON có đuôi thật không\n"
	.string "nhỉ?$"

MagmaHideout_4F_Text_Grunt12Intro:
	.string "Fuhahaha! Sắp rồi! Rất sắp rồi! Mục tiêu\n"
	.string "vĩ đại của bọn ta sẽ thành hiện thực!$"

MagmaHideout_4F_Text_Grunt12Defeat:
	.string "Grrr... Ta đã đi xa đến thế, vậy mà giờ\n"
	.string "lại thế này sao?$"

MagmaHideout_4F_Text_Grunt12PostBattle:
	.string "Ngài MAXIE! Có kẻ xâm nhập đang tiến về\n"
	.string "phía ngài!$"

MagmaHideout_4F_Text_Grunt13Intro:
	.string "Ngươi vẫn chưa xong đâu! Đừng hòng dễ\n"
	.string "dàng vượt qua ta!$"

MagmaHideout_4F_Text_Grunt13Defeat:
	.string "Ta dễ bị đánh gục đến vậy sao?$"

MagmaHideout_4F_Text_Grunt13PostBattle:
	.string "N-nào, đấu thêm một trận nữa đi...$"

MagmaHideout_4F_Text_TabithaIntro:
	.string "Hehehe! Ngươi đã đến tận đây, vậy ta\n"
	.string "sẽ nói cho ngươi biết!\p"
	.string "Đúng thế! Phía trước, GROUDON đang\n"
	.string "ngủ!\p"
	.string "MAXIE vừa đến chỗ GROUDON cách đây ít\n"
	.string "giây!\p"
	.string "Nó sắp thức tỉnh rồi! Hehe! Hehehe!$"

MagmaHideout_4F_Text_TabithaDefeat:
	.string "Lại bị hạ nữa rồi... Hehe...$"

MagmaHideout_4F_Text_TabithaPostBattle:
	.string "...Và trong lúc ngươi lãng phí thời gian\n"
	.string "với ta, MAXIE hẳn đã đánh thức\l"
	.string "GROUDON...$"

MagmaHideout_4F_Text_MaxieAwakenGroudon:
	.string "MAXIE: GROUDON...\p"
	.string "Không gì có thể đánh thức ngươi khỏi\n"
	.string "giấc ngủ giữa dung nham...\p"
	.string "BLUE ORB này chính là thứ ngươi tìm\n"
	.string "kiếm. Đúng không?\p"
	.string "Ta đã mang BLUE ORB đến cho ngươi. Hãy\n"
	.string "để ánh sáng của nó đánh thức ngươi!\p"
	.string "Và cho ta thấy... Cho ta thấy toàn bộ\n"
	.string "sức mạnh của ngươi!$"

MagmaHideout_4F_Text_MaxieGroudonWhatsWrong:
	.string "MAXIE: GROUDON! Có chuyện gì vậy?\p"
	.string "BLUE ORB chẳng phải là chìa khóa sao?\p"
	.string "GROUDON! Ngươi đã đi đâu rồi...$"

MagmaHideout_4F_Text_MaxieOhItWasYou:
	.string "MAXIE: Ồ, hóa ra là ngươi sao?\p"
	.string "Ta đã thấy ngươi tự tiện lảng vảng hết\n"
	.string "chỗ này đến chỗ khác...\p"
	.string "Giờ ta hiểu rồi! Hẳn ngươi đã giở trò\n"
	.string "hèn hạ!$"

MagmaHideout_4F_Text_MaxieDefeat:
	.string "Điều gì khiến ngươi điều khiển POKéMON\n"
	.string "thành thạo đến vậy?$"

MagmaHideout_4F_Text_MaxieImGoingAfterGroudon:
	.string "MAXIE: GROUDON bỏ chạy hẳn phải có lý\n"
	.string "do nào đó...\p"
	.string "Đó là điều ngươi muốn nói, đúng không?\p"
	.string "... ... ... ... ... ... ... ... ... ... ... ...\p"
	.string "Hừm... Ngươi tưởng ta không biết sao?\p"
	.string "GROUDON đã đi rồi, ngọn núi lửa chết\n"
	.string "tiệt này cũng không còn cần thiết nữa.\p"
	.string "Ta sẽ đuổi theo GROUDON, chúng ta chia\n"
	.string "tay tại đây!$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global MagmaHideout_4F_Text_Grunt11Intro
	.global MagmaHideout_4F_Text_Grunt11Defeat
	.global MagmaHideout_4F_Text_Grunt11PostBattle
	.global MagmaHideout_4F_Text_Grunt12Intro
	.global MagmaHideout_4F_Text_Grunt12Defeat
	.global MagmaHideout_4F_Text_Grunt12PostBattle
	.global MagmaHideout_4F_Text_Grunt13Intro
	.global MagmaHideout_4F_Text_Grunt13Defeat
	.global MagmaHideout_4F_Text_Grunt13PostBattle
	.global MagmaHideout_4F_Text_TabithaIntro
	.global MagmaHideout_4F_Text_TabithaDefeat
	.global MagmaHideout_4F_Text_TabithaPostBattle
	.global MagmaHideout_4F_Text_MaxieAwakenGroudon
	.global MagmaHideout_4F_Text_MaxieGroudonWhatsWrong
	.global MagmaHideout_4F_Text_MaxieOhItWasYou
	.global MagmaHideout_4F_Text_MaxieDefeat
	.global MagmaHideout_4F_Text_MaxieImGoingAfterGroudon
@ END GENERATED LOCALIZATION EXPORTS
