AquaHideout_B2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AquaHideout_B2F_OnTransition
	.byte 0

AquaHideout_B2F_OnTransition:
	call_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, AquaHideout_B2F_EventScript_PreventMattNoticing
	end

AquaHideout_B2F_EventScript_PreventMattNoticing::
	setvar VAR_TEMP_1, 1
	return

AquaHideout_B2F_EventScript_MattNoticePlayer::
	lockall
	setvar VAR_0x8008, LOCALID_AQUA_HIDEOUT_MATT
	playse SE_PIN
	applymovement VAR_0x8008, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_0x8008, Common_Movement_FacePlayer
	waitmovement 0
	setvar VAR_TEMP_1, 1
	releaseall
	end

AquaHideout_B2F_EventScript_Matt::
	trainerbattle_single TRAINER_MATT, AquaHideout_B2F_Text_MattIntro, AquaHideout_B2F_Text_MattDefeat, AquaHideout_B2F_EventScript_SubmarineEscape
	msgbox AquaHideout_B2F_Text_MattPostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_B2F_EventScript_SubmarineEscape::
	setvar VAR_0x8008, LOCALID_AQUA_HIDEOUT_MATT
	setvar VAR_0x8009, LOCALID_AQUA_HIDEOUT_SUBMARINE
	applymovement VAR_0x8008, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	delay 20
	applymovement VAR_0x8008, Common_Movement_FacePlayer
	waitmovement 0
	msgbox AquaHideout_B2F_Text_OurBossGotThroughHisPreparations, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_0x8008, Common_Movement_WalkInPlaceFasterLeft
	applymovement VAR_0x8009, AquaHideout_B2F_Movement_SumbarineDepartLeft
	waitmovement 0
	removeobject VAR_0x8009
	delay 20
	applymovement VAR_0x8008, Common_Movement_FacePlayer
	waitmovement 0
	msgbox AquaHideout_B2F_Text_MattPostBattle, MSGBOX_DEFAULT
	setflag FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE
	setflag FLAG_HIDE_LILYCOVE_CITY_AQUA_GRUNTS
	release
	end

AquaHideout_B2F_Movement_SumbarineDepartLeft:
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

@ Unused
AquaHideout_B2F_Movement_SumbarineDepartRight:
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

AquaHideout_B2F_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_4, AquaHideout_B2F_Text_Grunt4Intro, AquaHideout_B2F_Text_Grunt4Defeat, AquaHideout_B2F_EventScript_Grunt4Defeated
	msgbox AquaHideout_B2F_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B2F_EventScript_Grunt4Defeated::
	msgbox AquaHideout_B2F_Text_Grunt4PostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_B2F_EventScript_Grunt6::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_6, AquaHideout_B2F_Text_Grunt6Intro, AquaHideout_B2F_Text_Grunt6Defeat
	msgbox AquaHideout_B2F_Text_Grunt6PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B2F_EventScript_Grunt8::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_8, AquaHideout_B2F_Text_Grunt8Intro, AquaHideout_B2F_Text_Grunt8Defeat
	msgbox AquaHideout_B2F_Text_Grunt8PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B2F_Text_MattIntro:
	.string "Hehehe...\p"
	.string "Đã tới đây rồi sao? Bọn ta đã đánh giá\n"
	.string "thấp ngươi!\p"
	.string "Nhưng đến đây là hết!\p"
	.string "Ta vượt xa đám lính ngươi đã gặp từ\n"
	.string "nãy tới giờ.\p"
	.string "Ta không câu giờ đâu. Ta sẽ nghiền nát\n"
	.string "ngươi!$"

AquaHideout_B2F_Text_MattDefeat:
	.string "Hehehe... Vậy là ta cũng thua...$"

AquaHideout_B2F_Text_OurBossGotThroughHisPreparations:
	.string "Hehehe!\p"
	.string "Lúc ta đùa giỡn với ngươi, thủ lĩnh\n"
	.string "của bọn ta đã chuẩn bị xong hết rồi!$"

AquaHideout_B2F_Text_MattPostBattle:
	.string "Hehehe!\p"
	.string "Thủ lĩnh bọn ta đã lên đường tới một\n"
	.string "hang động nào đó dưới biển rồi!\p"
	.string "Nếu muốn đuổi theo, tốt nhất ngươi nên\n"
	.string "tìm khắp vùng biển mênh mông phía\l"
	.string "ngoài LILYCOVE.\p"
	.string "Nhưng liệu ngươi có tìm thấy không?\n"
	.string "Hehehe!$"

AquaHideout_B2F_Text_Grunt4Intro:
	.string "Wahahah, ta chờ đến phát chán rồi!\n"
	.string "Ngươi cũng nợ ta một trận đấu!$"

AquaHideout_B2F_Text_Grunt4Defeat:
	.string "Chờ đến mệt mỏi... Thua đến choáng\n"
	.string "váng...$"

AquaHideout_B2F_Text_Grunt4PostBattle:
	.string "Thủ lĩnh... Thế này đã đủ chưa?$"

AquaHideout_B2F_Text_Grunt6Intro:
	.string "Các tấm dịch chuyển, niềm kiêu hãnh của\n"
	.string "HIDEOUT!\p"
	.string "Ngươi chẳng biết mình đang ở đâu,\n"
	.string "đúng không?\p"
	.string "Làm kẻ địch rối trí và kiệt sức, rồi\n"
	.string "giáng đòn kết liễu! Đó là kế hoạch của\l"
	.string "bọn ta!$"

AquaHideout_B2F_Text_Grunt6Defeat:
	.string "Ngươi bị làm sao vậy? Chẳng mệt chút\n"
	.string "nào cả!$"

AquaHideout_B2F_Text_Grunt6PostBattle:
	.string "Nhắc mới nhớ... Ta không nhớ đã để\n"
	.string "MASTER BALL ở đâu.\p"
	.string "Nếu để mất nó, thủ lĩnh sẽ\n"
	.string "mắng ta một trận...$"

AquaHideout_B2F_Text_Grunt8Intro:
	.string "Khi gia nhập TEAM AQUA, điều đầu tiên\n"
	.string "tôi phải học là các tấm dịch chuyển này\l"
	.string "nối với nhau thế nào.$"

AquaHideout_B2F_Text_Grunt8Defeat:
	.string "Tôi cứ mải nghĩ về các tấm dịch\n"
	.string "chuyển...$"

AquaHideout_B2F_Text_Grunt8PostBattle:
	.string "Tôi sẽ phải học cách chiến đấu hiệu quả\n"
	.string "hơn...$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global AquaHideout_B2F_Text_MattIntro
	.global AquaHideout_B2F_Text_MattDefeat
	.global AquaHideout_B2F_Text_OurBossGotThroughHisPreparations
	.global AquaHideout_B2F_Text_MattPostBattle
	.global AquaHideout_B2F_Text_Grunt4Intro
	.global AquaHideout_B2F_Text_Grunt4Defeat
	.global AquaHideout_B2F_Text_Grunt4PostBattle
	.global AquaHideout_B2F_Text_Grunt6Intro
	.global AquaHideout_B2F_Text_Grunt6Defeat
	.global AquaHideout_B2F_Text_Grunt6PostBattle
	.global AquaHideout_B2F_Text_Grunt8Intro
	.global AquaHideout_B2F_Text_Grunt8Defeat
	.global AquaHideout_B2F_Text_Grunt8PostBattle
@ END GENERATED LOCALIZATION EXPORTS
