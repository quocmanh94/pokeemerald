MtPyre_6F_MapScripts::
	.byte 0

MtPyre_6F_EventScript_Valerie::
	trainerbattle_single TRAINER_VALERIE_1, MtPyre_6F_Text_ValerieIntro, MtPyre_6F_Text_ValerieDefeat, MtPyre_6F_EventScript_RegisterValerie
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtPyre_6F_EventScript_RematchValerie
	msgbox MtPyre_6F_Text_ValeriePostBattle, MSGBOX_DEFAULT
	release
	end

MtPyre_6F_EventScript_RegisterValerie::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtPyre_6F_Text_ValerieRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_VALERIE_1
	release
	end

MtPyre_6F_EventScript_RematchValerie::
	trainerbattle_rematch TRAINER_VALERIE_1, MtPyre_6F_Text_ValerieRematchIntro, MtPyre_6F_Text_ValerieRematchDefeat
	msgbox MtPyre_6F_Text_ValeriePostRematch, MSGBOX_AUTOCLOSE
	end

MtPyre_6F_EventScript_Cedric::
	trainerbattle_single TRAINER_CEDRIC, MtPyre_6F_Text_CedricIntro, MtPyre_6F_Text_CedricDefeat
	msgbox MtPyre_6F_Text_CedricPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_6F_Text_ValerieIntro:
	.string "Khi ở đây... Một sức mạnh kỳ lạ chảy vào\n"
	.string "cơ thể tôi...$"

MtPyre_6F_Text_ValerieDefeat:
	.string "Sức mạnh đang dần rút đi...$"

MtPyre_6F_Text_ValeriePostBattle:
	.string "Có lẽ sức mạnh ấy đến từ linh hồn của\n"
	.string "những POKéMON đang chập chờn yên\l"
	.string "nghỉ tại đây...$"

MtPyre_6F_Text_ValerieRegister:
	.string "Fufufu... Tôi đã thua trận, nhưng... tôi\n"
	.string "có chút năng lực này...\p"
	.string "Không cần chạm tay vào POKéNAV của\n"
	.string "bạn... Hiyah!$"

MtPyre_6F_Text_ValerieRematchIntro:
	.string "Sau lưng bạn... Là thứ gì vậy...$"

MtPyre_6F_Text_ValerieRematchDefeat:
	.string "Có thứ gì đó vừa tan biến...$"

MtPyre_6F_Text_ValeriePostRematch:
	.string "Những POKéMON an nghỉ tại đây... Đôi\n"
	.string "khi, chúng vui đùa...$"

MtPyre_6F_Text_CedricIntro:
	.string "Bạn mất phương hướng rồi sao? Đừng\n"
	.string "sợ, vì đã có tôi đây!$"

MtPyre_6F_Text_CedricDefeat:
	.string "Chẳng phải bạn bị lạc sao?$"

MtPyre_6F_Text_CedricPostBattle:
	.string "Tôi cứ nghĩ một HLV bị lạc sẽ hoảng\n"
	.string "loạn và dễ đánh bại.\p"
	.string "Thật hèn hạ, tôi sẽ không làm thế nữa...$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global MtPyre_6F_Text_ValerieIntro
	.global MtPyre_6F_Text_ValerieDefeat
	.global MtPyre_6F_Text_ValeriePostBattle
	.global MtPyre_6F_Text_ValerieRegister
	.global MtPyre_6F_Text_ValerieRematchIntro
	.global MtPyre_6F_Text_ValerieRematchDefeat
	.global MtPyre_6F_Text_ValeriePostRematch
	.global MtPyre_6F_Text_CedricIntro
	.global MtPyre_6F_Text_CedricDefeat
	.global MtPyre_6F_Text_CedricPostBattle
@ END GENERATED LOCALIZATION EXPORTS
