LilycoveCity_MoveDeletersHouse_MapScripts::
	.byte 0

LilycoveCity_MoveDeletersHouse_EventScript_MoveDeleter::
	lockall
	applymovement LOCALID_MOVE_DELETER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_MoveDeletersHouse_Text_ICanMakeMonForgetMove, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, LilycoveCity_MoveDeletersHouse_EventScript_ChooseMonAndMoveToForget
	case NO, LilycoveCity_MoveDeletersHouse_EventScript_ComeAgain
	releaseall
	end

LilycoveCity_MoveDeletersHouse_EventScript_ChooseMonAndMoveToForget::
	msgbox LilycoveCity_MoveDeletersHouse_Text_WhichMonShouldForget, MSGBOX_DEFAULT
	special ChoosePartyMon
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, LilycoveCity_MoveDeletersHouse_EventScript_ComeAgain
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_MoveDeletersHouse_EventScript_EggCantForgetMoves
	special GetNumMovesSelectedMonHas
	goto_if_eq VAR_RESULT, 1, LilycoveCity_MoveDeletersHouse_EventScript_MonOnlyKnowsOneMove
	msgbox LilycoveCity_MoveDeletersHouse_Text_WhichMoveShouldBeForgotten, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special MoveDeleterChooseMoveToForget
	fadescreen FADE_FROM_BLACK
	goto_if_eq VAR_0x8005, MAX_MON_MOVES, LilycoveCity_MoveDeletersHouse_EventScript_ChooseMonAndMoveToForget
	special BufferMoveDeleterNicknameAndMove
	msgbox LilycoveCity_MoveDeletersHouse_Text_MonsMoveShouldBeForgotten, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, LilycoveCity_MoveDeletersHouse_EventScript_TryForgetMove
	case NO, LilycoveCity_MoveDeletersHouse_EventScript_ComeAgain
	releaseall
	end

LilycoveCity_MoveDeletersHouse_EventScript_TryForgetMove::
	special IsLastMonThatKnowsSurf
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_MoveDeletersHouse_EventScript_LastMonWithSurf
	special MoveDeleterForgetMove
	playfanfare MUS_MOVE_DELETED
	waitfanfare
	msgbox LilycoveCity_MoveDeletersHouse_Text_MonHasForgottenMove, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_MoveDeletersHouse_EventScript_MonOnlyKnowsOneMove::
	special BufferMoveDeleterNicknameAndMove
	msgbox LilycoveCity_MoveDeletersHouse_Text_MonOnlyKnowsOneMove, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_MoveDeletersHouse_EventScript_EggCantForgetMoves::
	msgbox LilycoveCity_MoveDeletersHouse_Text_EggCantForgetMoves, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_MoveDeletersHouse_EventScript_ComeAgain::
	msgbox LilycoveCity_MoveDeletersHouse_Text_ComeAgain, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_MoveDeletersHouse_EventScript_LastMonWithSurf::
	special BufferMoveDeleterNicknameAndMove
	msgbox LilycoveCity_MoveDeletersHouse_Text_CantForgetSurf, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_MoveDeletersHouse_Text_ICanMakeMonForgetMove:
	.string "Ờ... À phải, tôi là MOVE DELETER.\p"
	.string "Tôi có thể khiến POKéMON quên chiêu\n"
	.string "thức.\p"
	.string "Bạn có muốn tôi làm vậy không?$"

LilycoveCity_MoveDeletersHouse_Text_WhichMonShouldForget:
	.string "POKéMON nào sẽ quên một chiêu?$"

LilycoveCity_MoveDeletersHouse_Text_WhichMoveShouldBeForgotten:
	.string "Bạn muốn nó quên chiêu nào?$"

LilycoveCity_MoveDeletersHouse_Text_MonOnlyKnowsOneMove:
	.string "{STR_VAR_1} chỉ biết một chiêu\n"
	.string "nên không thể quên chiêu đó...$"

LilycoveCity_MoveDeletersHouse_Text_MonsMoveShouldBeForgotten:
	.string "Hừm! Chiêu {STR_VAR_2} của\n"
	.string "{STR_VAR_1} à? Bạn muốn nó quên\l"
	.string "chiêu đó sao?$"

LilycoveCity_MoveDeletersHouse_Text_MonHasForgottenMove:
	.string "Hoàn hảo!\p"
	.string "{STR_VAR_1} đã quên sạch\n"
	.string "{STR_VAR_2}.$"

LilycoveCity_MoveDeletersHouse_Text_ComeAgain:
	.string "Hãy quay lại nếu có chiêu nào cần được\n"
	.string "quên.$"

LilycoveCity_MoveDeletersHouse_Text_EggCantForgetMoves:
	.string "Gì cơ? EGG thì vốn không thể biết chiêu\n"
	.string "nào cả.$"

LilycoveCity_MoveDeletersHouse_Text_CantForgetSurf:
	.string "Hừm!\p"
	.string "{STR_VAR_1} của bạn có vẻ không\n"
	.string "muốn quên SURF.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global LilycoveCity_MoveDeletersHouse_Text_ICanMakeMonForgetMove
	.global LilycoveCity_MoveDeletersHouse_Text_WhichMonShouldForget
	.global LilycoveCity_MoveDeletersHouse_Text_WhichMoveShouldBeForgotten
	.global LilycoveCity_MoveDeletersHouse_Text_MonOnlyKnowsOneMove
	.global LilycoveCity_MoveDeletersHouse_Text_MonsMoveShouldBeForgotten
	.global LilycoveCity_MoveDeletersHouse_Text_MonHasForgottenMove
	.global LilycoveCity_MoveDeletersHouse_Text_ComeAgain
	.global LilycoveCity_MoveDeletersHouse_Text_EggCantForgetMoves
	.global LilycoveCity_MoveDeletersHouse_Text_CantForgetSurf
@ END GENERATED LOCALIZATION EXPORTS
