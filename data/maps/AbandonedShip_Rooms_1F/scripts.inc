AbandonedShip_Rooms_1F_MapScripts::
	.byte 0

AbandonedShip_Rooms_1F_EventScript_Gentleman::
	msgbox AbandonedShip_Rooms_1F_Text_TakingALookAround, MSGBOX_NPC
	end

AbandonedShip_Rooms_1F_EventScript_Demetrius::
	trainerbattle_single TRAINER_DEMETRIUS, AbandonedShip_Rooms_1F_Text_DemetriusIntro, AbandonedShip_Rooms_1F_Text_DemetriusDefeat
	msgbox AbandonedShip_Rooms_1F_Text_DemetriusPostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms_1F_EventScript_Thalia::
	trainerbattle_single TRAINER_THALIA_1, AbandonedShip_Rooms_1F_Text_ThaliaIntro, AbandonedShip_Rooms_1F_Text_ThaliaDefeat, AbandonedShip_Rooms_1F_EventScript_RegisterThalia
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_Rooms_1F_EventScript_ThaliaRematch
	msgbox AbandonedShip_Rooms_1F_Text_ThaliaPostBattle, MSGBOX_DEFAULT
	release
	end

AbandonedShip_Rooms_1F_EventScript_RegisterThalia::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox AbandonedShip_Rooms_1F_Text_ThaliaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_THALIA_1
	release
	end

AbandonedShip_Rooms_1F_EventScript_ThaliaRematch::
	trainerbattle_rematch TRAINER_THALIA_1, AbandonedShip_Rooms_1F_Text_ThaliaRematchIntro, AbandonedShip_Rooms_1F_Text_ThaliaRematchDefeat
	msgbox AbandonedShip_Rooms_1F_Text_ThaliaPostRematch, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms_1F_Text_TakingALookAround:
	.string "Loại tàu này hiếm lắm nên tôi đang đi\n"
	.string "xem một vòng.\p"
	.string "Hừm... Có vẻ vẫn còn những phòng khác...$"

AbandonedShip_Rooms_1F_Text_ThaliaIntro:
	.string "Điều gì trên đời lại thôi thúc bạn tới\n"
	.string "đây vậy? Hẳn bạn tò mò lắm!$"

AbandonedShip_Rooms_1F_Text_ThaliaDefeat:
	.string "Không chỉ tò mò mà còn mạnh nữa...$"

AbandonedShip_Rooms_1F_Text_ThaliaPostBattle:
	.string "Người đàn ông ở phòng bên...\p"
	.string "Ông ta bảo chỉ đến tham quan, nhưng tôi\n"
	.string "thấy chưa chắc đâu.$"

AbandonedShip_Rooms_1F_Text_ThaliaRegister:
	.string "Bạn đúng là một HLV cừ khôi! Cho\n"
	.string "tôi đăng ký bạn để làm kỷ niệm nhé!$"

AbandonedShip_Rooms_1F_Text_ThaliaRematchIntro:
	.string "Điều gì trên đời lại thôi thúc bạn quay\n"
	.string "lại vậy? Hẳn bạn thật sự tò mò lắm!$"

AbandonedShip_Rooms_1F_Text_ThaliaRematchDefeat:
	.string "Bạn có mạnh quá không vậy?$"

AbandonedShip_Rooms_1F_Text_ThaliaPostRematch:
	.string "Tôi chắc chắn người đàn ông đó đang âm\n"
	.string "mưu gì đó! Hành động của ông ta đáng\l"
	.string "ngờ lắm!$"

AbandonedShip_Rooms_1F_Text_DemetriusIntro:
	.string "Ááá! Bị phát hiện rồi! ...Hả?$"

AbandonedShip_Rooms_1F_Text_DemetriusDefeat:
	.string "Ồ, bạn không phải mẹ tôi.$"

AbandonedShip_Rooms_1F_Text_DemetriusPostBattle:
	.string "Tôi bị mẹ mắng nên đã bỏ chạy. Đừng tiết\n"
	.string "lộ tôi đang ở đâu nhé!$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global AbandonedShip_Rooms_1F_Text_TakingALookAround
	.global AbandonedShip_Rooms_1F_Text_ThaliaIntro
	.global AbandonedShip_Rooms_1F_Text_ThaliaDefeat
	.global AbandonedShip_Rooms_1F_Text_ThaliaPostBattle
	.global AbandonedShip_Rooms_1F_Text_ThaliaRegister
	.global AbandonedShip_Rooms_1F_Text_ThaliaRematchIntro
	.global AbandonedShip_Rooms_1F_Text_ThaliaRematchDefeat
	.global AbandonedShip_Rooms_1F_Text_ThaliaPostRematch
	.global AbandonedShip_Rooms_1F_Text_DemetriusIntro
	.global AbandonedShip_Rooms_1F_Text_DemetriusDefeat
	.global AbandonedShip_Rooms_1F_Text_DemetriusPostBattle
@ END GENERATED LOCALIZATION EXPORTS
