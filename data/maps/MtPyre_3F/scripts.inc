MtPyre_3F_MapScripts::
	.byte 0

MtPyre_3F_EventScript_William::
	trainerbattle_single TRAINER_WILLIAM, MtPyre_3F_Text_WilliamIntro, MtPyre_3F_Text_WilliamDefeat
	msgbox MtPyre_3F_Text_WilliamPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_3F_EventScript_Kayla::
	trainerbattle_single TRAINER_KAYLA, MtPyre_3F_Text_KaylaIntro, MtPyre_3F_Text_KaylaDefeat
	msgbox MtPyre_3F_Text_KaylaPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_3F_EventScript_Gabrielle::
	trainerbattle_single TRAINER_GABRIELLE_1, MtPyre_3F_Text_GabrielleIntro, MtPyre_3F_Text_GabrielleDefeat, MtPyre_3F_EventScript_RegisterGabrielle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtPyre_3F_EventScript_RematchGabrielle
	msgbox MtPyre_3F_Text_GabriellePostBattle, MSGBOX_DEFAULT
	release
	end

MtPyre_3F_EventScript_RegisterGabrielle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtPyre_3F_Text_GabrielleRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_GABRIELLE_1
	release
	end

MtPyre_3F_EventScript_RematchGabrielle::
	trainerbattle_rematch TRAINER_GABRIELLE_1, MtPyre_3F_Text_GabrielleRematchIntro, MtPyre_3F_Text_GabrielleRematchDefeat
	msgbox MtPyre_3F_Text_GabriellePostRematch, MSGBOX_AUTOCLOSE
	end

MtPyre_3F_Text_WilliamIntro:
	.string "Bầu không khí linh thiêng của ngọn núi\n"
	.string "đã nâng sức mạnh tâm linh của ta lên\l"
	.string "một tầm cao mới!\p"
	.string "Chỉ là một đứa trẻ như ngươi... Mà cũng\n"
	.string "mơ chiến thắng sao?$"

MtPyre_3F_Text_WilliamDefeat:
	.string "Ta chìm trong nỗi tự thương thân...$"

MtPyre_3F_Text_WilliamPostBattle:
	.string "Năng lực tâm linh của ta rõ ràng đã tăng\n"
	.string "lên gấp mấy lần, vậy mà...$"

MtPyre_3F_Text_KaylaIntro:
	.string "Ahahahaha!\p"
	.string "Đây không phải nơi dành cho trẻ con,\n"
	.string "nhất là nhóc!$"

MtPyre_3F_Text_KaylaDefeat:
	.string "Tôi thua tâm phục khẩu phục...$"

MtPyre_3F_Text_KaylaPostBattle:
	.string "Vậy nghĩa là tôi vẫn chưa luyện tập\n"
	.string "đủ...\p"
	.string "Tôi phải tiếp tục nỗ lực tiến tới đỉnh\n"
	.string "núi...\p"
	.string "Cố lên nào, tôi ơi!$"

MtPyre_3F_Text_GabrielleIntro:
	.string "Tại sao bạn lại đến đây?$"

MtPyre_3F_Text_GabrielleDefeat:
	.string "Thật tuyệt vời! Bạn là một HLV rất\n"
	.string "đặc biệt.$"

MtPyre_3F_Text_GabriellePostBattle:
	.string "Những POKéMON đã rời khỏi thế giới này.\n"
	.string "Những POKéMON đang ở bên bạn.\p"
	.string "Và những POKéMON bạn sẽ gặp trong\n"
	.string "tương lai...\p"
	.string "Tất cả đều đáng được trân trọng như\n"
	.string "nhau. Xin hãy ghi nhớ điều đó.$"

MtPyre_3F_Text_GabrielleRegister:
	.string "Tôi muốn được thấy POKéMON của bạn khi\n"
	.string "chúng trưởng thành hơn nữa...\p"
	.string "Xin hãy cho tôi xem POKéNAV của bạn.$"

MtPyre_3F_Text_GabrielleRematchIntro:
	.string "Ồ, là bạn...\p"
	.string "Bạn đến cho tôi xem những POKéMON đã\n"
	.string "trưởng thành sao?$"

MtPyre_3F_Text_GabrielleRematchDefeat:
	.string "Thật kỳ diệu! Bạn là một người đặc biệt.$"

MtPyre_3F_Text_GabriellePostRematch:
	.string "Những POKéMON đã rời khỏi thế giới này.\n"
	.string "Những POKéMON đang ở bên bạn.\p"
	.string "Và những POKéMON bạn sẽ gặp trong\n"
	.string "tương lai...\p"
	.string "Tất cả đều đáng được trân trọng như\n"
	.string "nhau. Tôi thấy bạn vẫn nhớ điều đó.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global MtPyre_3F_Text_WilliamIntro
	.global MtPyre_3F_Text_WilliamDefeat
	.global MtPyre_3F_Text_WilliamPostBattle
	.global MtPyre_3F_Text_KaylaIntro
	.global MtPyre_3F_Text_KaylaDefeat
	.global MtPyre_3F_Text_KaylaPostBattle
	.global MtPyre_3F_Text_GabrielleIntro
	.global MtPyre_3F_Text_GabrielleDefeat
	.global MtPyre_3F_Text_GabriellePostBattle
	.global MtPyre_3F_Text_GabrielleRegister
	.global MtPyre_3F_Text_GabrielleRematchIntro
	.global MtPyre_3F_Text_GabrielleRematchDefeat
	.global MtPyre_3F_Text_GabriellePostRematch
@ END GENERATED LOCALIZATION EXPORTS
