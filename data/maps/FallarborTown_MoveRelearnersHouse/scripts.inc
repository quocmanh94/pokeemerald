FallarborTown_MoveRelearnersHouse_MapScripts::
	.byte 0

FallarborTown_MoveRelearnersHouse_EventScript_MoveRelearner::
	lockall
	applymovement LOCALID_MOVE_RELEARNER, Common_Movement_FacePlayer
	waitmovement 0
	goto_if_set FLAG_TEMP_1, FallarborTown_MoveRelearnersHouse_EventScript_AskTeachMove
	msgbox FallarborTown_MoveRelearnersHouse_Text_ImTheMoveTutor, MSGBOX_DEFAULT
	setflag FLAG_TEMP_1
	goto FallarborTown_MoveRelearnersHouse_EventScript_AskTeachMove
	end

FallarborTown_MoveRelearnersHouse_EventScript_AskTeachMove::
	checkitem ITEM_HEART_SCALE
	goto_if_eq VAR_RESULT, FALSE, FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
	msgbox FallarborTown_MoveRelearnersHouse_Text_ThatsAHeartScaleWantMeToTeachMove, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
	goto FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon
	end

FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon::
	msgbox FallarborTown_MoveRelearnersHouse_Text_TutorWhichMon, MSGBOX_DEFAULT
	special ChooseMonForMoveRelearner
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, FallarborTown_MoveRelearnersHouse_EventScript_CantTeachEgg
	goto_if_eq VAR_0x8005, 0, FallarborTown_MoveRelearnersHouse_EventScript_NoMoveToTeachMon
	goto FallarborTown_MoveRelearnersHouse_EventScript_ChooseMove
	end

FallarborTown_MoveRelearnersHouse_EventScript_ChooseMove::
	msgbox FallarborTown_MoveRelearnersHouse_Text_TeachWhichMove, MSGBOX_DEFAULT
	special TeachMoveRelearnerMove
	goto_if_eq VAR_0x8004, 0, FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon
	msgbox FallarborTown_MoveRelearnersHouse_Text_HandedOverHeartScale, MSGBOX_DEFAULT
	removeitem ITEM_HEART_SCALE
	goto FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
	end

FallarborTown_MoveRelearnersHouse_EventScript_NoMoveToTeachMon::
	msgbox FallarborTown_MoveRelearnersHouse_Text_DontHaveMoveToTeachPokemon, MSGBOX_DEFAULT
	goto FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon
	end

FallarborTown_MoveRelearnersHouse_EventScript_CantTeachEgg::
	msgbox FallarborTown_MoveRelearnersHouse_Text_CantTeachEgg, MSGBOX_DEFAULT
	goto FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon
	end

FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale::
	msgbox FallarborTown_MoveRelearnersHouse_Text_ComeBackWithHeartScale, MSGBOX_DEFAULT
	releaseall
	end

FallarborTown_MoveRelearnersHouse_Text_ImTheMoveTutor:
	.string "Tôi là MOVE TUTOR.\p"
	.string "Tôi biết tất cả các chiêu mà POKéMON có\n"
	.string "thể học, không sót một chiêu nào, và tôi\l"
	.string "có thể dạy chúng cho POKéMON.\p"
	.string "Nếu muốn, tôi có thể dạy một chiêu cho\n"
	.string "POKéMON của bạn.\p"
	.string "Tôi sẽ dạy đổi lấy một HEART SCALE. Hiện\n"
	.string "tôi đang sưu tầm chúng.$"

FallarborTown_MoveRelearnersHouse_Text_ThatsAHeartScaleWantMeToTeachMove:
	.string "Ồ! Chính nó! Một HEART SCALE chính\n"
	.string "hiệu!\p"
	.string "Để tôi đoán nhé, bạn muốn tôi dạy một\n"
	.string "chiêu phải không?$"

FallarborTown_MoveRelearnersHouse_Text_TutorWhichMon:
	.string "POKéMON nào cần tôi chỉ dạy?$"

FallarborTown_MoveRelearnersHouse_Text_TeachWhichMove:
	.string "Tôi nên dạy chiêu nào?$"

FallarborTown_MoveRelearnersHouse_Text_DontHaveMoveToTeachPokemon:
	.string "Xin lỗi...\p"
	.string "Có vẻ tôi không có chiêu nào có thể dạy\n"
	.string "cho POKéMON đó.$"

FallarborTown_MoveRelearnersHouse_Text_HandedOverHeartScale:
	.string "{PLAYER} đã trao một HEART SCALE để\n"
	.string "đổi lại.$"

FallarborTown_MoveRelearnersHouse_Text_ComeBackWithHeartScale:
	.string "Nếu POKéMON của bạn cần học chiêu, hãy\n"
	.string "quay lại cùng một HEART SCALE.$"

FallarborTown_MoveRelearnersHouse_Text_CantTeachEgg:
	.string "Hả? Tôi không thể dạy cho EGG bất kỳ\n"
	.string "chiêu nào cả.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global FallarborTown_MoveRelearnersHouse_Text_ImTheMoveTutor
	.global FallarborTown_MoveRelearnersHouse_Text_ThatsAHeartScaleWantMeToTeachMove
	.global FallarborTown_MoveRelearnersHouse_Text_TutorWhichMon
	.global FallarborTown_MoveRelearnersHouse_Text_TeachWhichMove
	.global FallarborTown_MoveRelearnersHouse_Text_DontHaveMoveToTeachPokemon
	.global FallarborTown_MoveRelearnersHouse_Text_HandedOverHeartScale
	.global FallarborTown_MoveRelearnersHouse_Text_ComeBackWithHeartScale
	.global FallarborTown_MoveRelearnersHouse_Text_CantTeachEgg
@ END GENERATED LOCALIZATION EXPORTS
