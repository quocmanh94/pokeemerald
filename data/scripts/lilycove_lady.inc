LilycoveCity_PokemonCenter_1F_EventScript_LilycoveLady::
	special Script_GetLilycoveLadyId
	switch VAR_RESULT
	case LILYCOVE_LADY_QUIZ, LilycoveCity_PokemonCenter_1F_EventScript_QuizLady
	case LILYCOVE_LADY_FAVOR, LilycoveCity_PokemonCenter_1F_EventScript_FavorLady
	case LILYCOVE_LADY_CONTEST, LilycoveCity_PokemonCenter_1F_EventScript_ContestLady
	end

LilycoveCity_PokemonCenter_1F_EventScript_FavorLady::
	lock
	faceplayer
	msgbox LilycoveCity_PokemonCenter_1F_Text_ImTheFavorLady, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetFavorLadyState
	goto_if_eq VAR_RESULT, LILYCOVE_LADY_STATE_READY, LilycoveCity_PokemonCenter_1F_EventScript_FavorLadyReady
	goto_if_eq VAR_RESULT, LILYCOVE_LADY_STATE_COMPLETED, LilycoveCity_PokemonCenter_1F_EventScript_FavorLadyCompleted
	goto_if_eq VAR_RESULT, LILYCOVE_LADY_STATE_PRIZE, LilycoveCity_PokemonCenter_1F_EventScript_FavorLadyPrize
	end

LilycoveCity_PokemonCenter_1F_EventScript_FavorLadyCompleted::
	msgbox LilycoveCity_PokemonCenter_1F_Text_ThankYouForLastTime, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_FavorLadyReady::
	special BufferFavorLadyRequest
	msgbox LilycoveCity_PokemonCenter_1F_Text_ObsessedWithThing, MSGBOX_DEFAULT
	specialvar VAR_RESULT, HasAnotherPlayerGivenFavorLadyItem
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonCenter_1F_EventScript_RequestItem
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonCenter_1F_EventScript_TellAboutPlayersItem
	end

LilycoveCity_PokemonCenter_1F_EventScript_TellAboutPlayersItem::
	special BufferFavorLadyItemName
	special BufferFavorLadyPlayerName
	specialvar VAR_RESULT, DidFavorLadyLikeItem
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonCenter_1F_EventScript_PlayerGaveBadThing
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonCenter_1F_EventScript_PlayerGaveGreatThing
	end

LilycoveCity_PokemonCenter_1F_EventScript_PlayerGaveBadThing::
	msgbox LilycoveCity_PokemonCenter_1F_Text_PlayerGaveMeBadThing, MSGBOX_DEFAULT
	goto LilycoveCity_PokemonCenter_1F_EventScript_RequestItem
	end

LilycoveCity_PokemonCenter_1F_EventScript_PlayerGaveGreatThing::
	msgbox LilycoveCity_PokemonCenter_1F_Text_PlayerGaveMeGreatThing, MSGBOX_DEFAULT
	goto LilycoveCity_PokemonCenter_1F_EventScript_RequestItem
	end

LilycoveCity_PokemonCenter_1F_EventScript_RequestItem::
	msgbox LilycoveCity_PokemonCenter_1F_Text_WillYouShareThing, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LilycoveCity_PokemonCenter_1F_EventScript_DeclineFavor
	goto_if_eq VAR_RESULT, YES, LilycoveCity_PokemonCenter_1F_EventScript_AcceptFavor
	end

LilycoveCity_PokemonCenter_1F_EventScript_DeclineFavor::
	msgbox LilycoveCity_PokemonCenter_1F_Text_IsThatSoGoodbye, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_AcceptFavor::
	msgbox LilycoveCity_PokemonCenter_1F_Text_WhatWillYouGiveMe, MSGBOX_DEFAULT
	goto LilycoveCity_PokemonCenter_1F_EventScript_ChooseFavorItem
	end

LilycoveCity_PokemonCenter_1F_EventScript_ChooseFavorItem::
	fadescreen FADE_TO_BLACK
	setvar VAR_RESULT, 0
	special Script_FavorLadyOpenBagMenu
	goto_if_eq VAR_RESULT, 0, LilycoveCity_PokemonCenter_1F_EventScript_AskQuitChooseFavorItem
	goto_if_eq VAR_RESULT, 1, LilycoveCity_PokemonCenter_1F_EventScript_GiveFavorItem
	end

LilycoveCity_PokemonCenter_1F_EventScript_AskQuitChooseFavorItem::
	msgbox LilycoveCity_PokemonCenter_1F_Text_NotWillingToShare, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LilycoveCity_PokemonCenter_1F_EventScript_DeclineFavor
	goto_if_eq VAR_RESULT, NO, LilycoveCity_PokemonCenter_1F_EventScript_ChooseFavorItem
	end

LilycoveCity_PokemonCenter_1F_EventScript_GiveFavorItem::
	specialvar VAR_RESULT, Script_DoesFavorLadyLikeItem
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonCenter_1F_EventScript_DidntLikeFavorItem
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonCenter_1F_EventScript_CheckLovedItem
	end

LilycoveCity_PokemonCenter_1F_EventScript_DidntLikeFavorItem::
	special BufferFavorLadyRequest
	msgbox LilycoveCity_PokemonCenter_1F_Text_IllTryToCherishIt, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_CheckLovedItem::
	specialvar VAR_RESULT, IsFavorLadyThresholdMet
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonCenter_1F_EventScript_LikedFavorItem
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonCenter_1F_EventScript_LovedFavorItem
	end

LilycoveCity_PokemonCenter_1F_EventScript_LikedFavorItem::
	special BufferFavorLadyRequest
	msgbox LilycoveCity_PokemonCenter_1F_Text_IWillCherishThis, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_LovedFavorItem::
	special BufferFavorLadyRequest
	msgbox LilycoveCity_PokemonCenter_1F_Text_IWillTreasureThis, MSGBOX_DEFAULT
	goto LilycoveCity_PokemonCenter_1F_EventScript_FavorLadyPrize
	end

LilycoveCity_PokemonCenter_1F_EventScript_FavorLadyPrize::
	setvar VAR_0x8004, 0
	specialvar VAR_0x8004, FavorLadyGetPrize
	msgbox LilycoveCity_PokemonCenter_1F_Text_IllGiveYouThisInReturn, MSGBOX_DEFAULT
	giveitem VAR_0x8004
	goto_if_eq VAR_RESULT, 0, LilycoveCity_PokemonCenter_1F_EventScript_NoRoomForFavorPrize
	goto_if_eq VAR_RESULT, 1, LilycoveCity_PokemonCenter_1F_EventScript_ReceivedFavorPrize
	end

LilycoveCity_PokemonCenter_1F_EventScript_NoRoomForFavorPrize::
	msgbox LilycoveCity_PokemonCenter_1F_Text_YouDontHaveSpaceForIt, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_ReceivedFavorPrize::
	special SetFavorLadyState_Complete
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_QuizLady::
	lock
	faceplayer
	msgbox LilycoveCity_PokemonCenter_1F_Text_ImTheQuizLady, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetQuizLadyState
	goto_if_eq VAR_RESULT, LILYCOVE_LADY_STATE_READY, LilycoveCity_PokemonCenter_1F_EventScript_HasQuiz
	goto_if_eq VAR_RESULT, LILYCOVE_LADY_STATE_COMPLETED, LilycoveCity_PokemonCenter_1F_EventScript_CheckMadeQuiz
	goto_if_eq VAR_RESULT, LILYCOVE_LADY_STATE_PRIZE, LilycoveCity_PokemonCenter_1F_EventScript_ReadyGivePrize
	end

LilycoveCity_PokemonCenter_1F_EventScript_HasQuiz::
	specialvar VAR_RESULT, GetQuizAuthor
	goto_if_eq VAR_RESULT, QUIZ_AUTHOR_PLAYER, LilycoveCity_PokemonCenter_1F_EventScript_WaitingToTakeYourQuiz
	goto_if_eq VAR_RESULT, QUIZ_AUTHOR_OTHER_PLAYER, LilycoveCity_PokemonCenter_1F_EventScript_PlayerQuizReady
	goto_if_eq VAR_RESULT, QUIZ_AUTHOR_LADY, LilycoveCity_PokemonCenter_1F_EventScript_LadyQuizReady
	end

LilycoveCity_PokemonCenter_1F_EventScript_CheckMadeQuiz::
	specialvar VAR_RESULT, IsQuizLadyWaitingForChallenger
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonCenter_1F_EventScript_AskMakeQuiz
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonCenter_1F_EventScript_WaitingToTakeYourQuiz
	end

LilycoveCity_PokemonCenter_1F_EventScript_WaitingToTakeYourQuiz::
	msgbox LilycoveCity_PokemonCenter_1F_Text_WaitingToTakeYourQuiz, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_PlayerQuizReady::
	msgbox LilycoveCity_PokemonCenter_1F_Text_WaitingForChallenger, MSGBOX_DEFAULT
	goto LilycoveCity_PokemonCenter_1F_EventScript_AskTakeQuiz
	end

LilycoveCity_PokemonCenter_1F_EventScript_LadyQuizReady::
	msgbox LilycoveCity_PokemonCenter_1F_Text_WaitingForChallenger, MSGBOX_DEFAULT
	goto LilycoveCity_PokemonCenter_1F_EventScript_AskTakeQuiz
	end

LilycoveCity_PokemonCenter_1F_EventScript_AskTakeQuiz::
	setvar VAR_0x8004, 0
	msgbox LilycoveCity_PokemonCenter_1F_Text_TakeQuizChallenge, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LilycoveCity_PokemonCenter_1F_EventScript_TakeQuiz
	goto_if_eq VAR_RESULT, NO, LilycoveCity_PokemonCenter_1F_EventScript_DeclineQuiz
	end

LilycoveCity_PokemonCenter_1F_EventScript_DeclineQuiz::
	msgbox LilycoveCity_PokemonCenter_1F_Text_HowBoringBye, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_TakeQuiz::
	special ClearQuizLadyPlayerAnswer
	goto_if_eq VAR_0x8004, 0, LilycoveCity_PokemonCenter_1F_EventScript_ShowQuestion
	goto_if_eq VAR_0x8004, EASY_CHAT_TYPE_QUIZ_ANSWER, LilycoveCity_PokemonCenter_1F_EventScript_GetAnswer

LilycoveCity_PokemonCenter_1F_EventScript_CheckQuizTakingState::
	goto_if_eq VAR_RESULT, 0, LilycoveCity_PokemonCenter_1F_EventScript_AskQuitQuiz
	goto_if_eq VAR_RESULT, 1, LilycoveCity_PokemonCenter_1F_EventScript_SubmitQuizResponse
	end

LilycoveCity_PokemonCenter_1F_EventScript_ShowQuestion::
	special QuizLadyShowQuizQuestion
	goto LilycoveCity_PokemonCenter_1F_EventScript_CheckQuizTakingState
	end

LilycoveCity_PokemonCenter_1F_EventScript_GetAnswer::
	special QuizLadyGetPlayerAnswer
	goto LilycoveCity_PokemonCenter_1F_EventScript_CheckQuizTakingState
	end

LilycoveCity_PokemonCenter_1F_EventScript_AskQuitQuiz::
	msgbox LilycoveCity_PokemonCenter_1F_Text_YoureGoingToQuit, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LilycoveCity_PokemonCenter_1F_EventScript_QuitTakingQuiz
	goto_if_eq VAR_RESULT, NO, LilycoveCity_PokemonCenter_1F_EventScript_TakeQuiz
	end

LilycoveCity_PokemonCenter_1F_EventScript_QuitTakingQuiz::
	msgbox LilycoveCity_PokemonCenter_1F_Text_TakeTheQuizAnotherTime, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_SubmitQuizResponse::
	special SetQuizLadyState_Complete
	msgbox LilycoveCity_PokemonCenter_1F_Text_WaitForAnswer, MSGBOX_DEFAULT
	specialvar VAR_RESULT, IsQuizAnswerCorrect
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonCenter_1F_EventScript_IncorrectResponse
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonCenter_1F_EventScript_CorrectResponse
	end

LilycoveCity_PokemonCenter_1F_EventScript_CorrectResponse::
	playse SE_SUCCESS
	delay 10
	playse SE_SUCCESS
	msgbox LilycoveCity_PokemonCenter_1F_Text_YouGotItRight, MSGBOX_DEFAULT
	goto LilycoveCity_PokemonCenter_1F_EventScript_ReadyGivePrize
	end

LilycoveCity_PokemonCenter_1F_EventScript_IncorrectResponse::
	special BufferQuizCorrectAnswer
	special BufferQuizPrizeName
	playse SE_FAILURE
	delay 10
	playse SE_FAILURE
	msgbox LilycoveCity_PokemonCenter_1F_Text_WrongTheCorrectAnswerIs, MSGBOX_DEFAULT
	msgbox LilycoveCity_PokemonCenter_1F_Text_IGetToKeepPrize, MSGBOX_DEFAULT
	goto LilycoveCity_PokemonCenter_1F_EventScript_AskMakeQuiz
	end

@ VAR_RESULT is essentially ignored, both jumps are identical
LilycoveCity_PokemonCenter_1F_EventScript_ReadyGivePrize::
	specialvar VAR_RESULT, BufferQuizAuthorNameAndCheckIfLady
	goto_if_eq VAR_RESULT, 1, LilycoveCity_PokemonCenter_1F_EventScript_GivePrize1
	goto_if_eq VAR_RESULT, 0, LilycoveCity_PokemonCenter_1F_EventScript_GivePrize0
	end

LilycoveCity_PokemonCenter_1F_EventScript_GivePrize1::
	msgbox LilycoveCity_PokemonCenter_1F_Text_YouGotItRightYouveWonPersonsPrize, MSGBOX_DEFAULT
	goto LilycoveCity_PokemonCenter_1F_EventScript_GivePrize
	end

LilycoveCity_PokemonCenter_1F_EventScript_GivePrize0::
	msgbox LilycoveCity_PokemonCenter_1F_Text_YouGotItRightYouveWonPersonsPrize, MSGBOX_DEFAULT
	goto LilycoveCity_PokemonCenter_1F_EventScript_GivePrize
	end

LilycoveCity_PokemonCenter_1F_EventScript_GivePrize::
	setvar VAR_0x8005, 0
	special BufferQuizPrizeItem
	special SetQuizLadyState_Complete
	giveitem VAR_0x8005
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonCenter_1F_EventScript_NoSpaceForQuizPrize
	goto LilycoveCity_PokemonCenter_1F_EventScript_AskMakeQuiz
	end

LilycoveCity_PokemonCenter_1F_EventScript_NoSpaceForQuizPrize::
	msgbox LilycoveCity_PokemonCenter_1F_Text_YourBagIsFilledUp, MSGBOX_DEFAULT
	special SetQuizLadyState_GivePrize
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_AskMakeQuiz::
	msgbox LilycoveCity_PokemonCenter_1F_Text_MakeYourOwnQuiz, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LilycoveCity_PokemonCenter_1F_EventScript_MakeQuiz
	goto_if_eq VAR_RESULT, NO, LilycoveCity_PokemonCenter_1F_EventScript_DeclineMakeQuiz
	end

LilycoveCity_PokemonCenter_1F_EventScript_DeclineMakeQuiz::
	special QuizLadyPickNewQuestion
	msgbox LilycoveCity_PokemonCenter_1F_Text_MaybeNextTime, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_MakeQuiz::
	msgbox LilycoveCity_PokemonCenter_1F_Text_PickYourPrize, MSGBOX_DEFAULT
LilycoveCity_PokemonCenter_1F_EventScript_PickPrize::
	fadescreen FADE_TO_BLACK
	setvar VAR_RESULT, 0
	special Script_QuizLadyOpenBagMenu
	goto_if_eq VAR_RESULT, 0, LilycoveCity_PokemonCenter_1F_EventScript_AskQuitChoosingPrize
	goto_if_eq VAR_RESULT, 1, LilycoveCity_PokemonCenter_1F_EventScript_WriteQuiz
	end

LilycoveCity_PokemonCenter_1F_EventScript_AskQuitChoosingPrize::
	msgbox LilycoveCity_PokemonCenter_1F_Text_QuitChoosingPrize, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LilycoveCity_PokemonCenter_1F_EventScript_DeclineMakeQuiz
	goto_if_eq VAR_RESULT, NO, LilycoveCity_PokemonCenter_1F_EventScript_PickPrize
	end

LilycoveCity_PokemonCenter_1F_EventScript_WriteQuiz::
	msgbox LilycoveCity_PokemonCenter_1F_Text_WriteYourQuiz, MSGBOX_DEFAULT
	special ClearQuizLadyQuestionAndAnswer
	special ClearQuizLadyPlayerAnswer
	setvar VAR_0x8004, EASY_CHAT_TYPE_QUIZ_QUESTION
LilycoveCity_PokemonCenter_1F_EventScript_WriteQuizQuestion::
	fadescreen FADE_TO_BLACK
	special QuizLadySetCustomQuestion
	goto_if_eq VAR_RESULT, 0, LilycoveCity_PokemonCenter_1F_EventScript_AskQuitWritingQuizQuestion
	goto LilycoveCity_PokemonCenter_1F_EventScript_FinishMakingQuiz
	end

LilycoveCity_PokemonCenter_1F_EventScript_AskQuitWritingQuizQuestion::
	msgbox LilycoveCity_PokemonCenter_1F_Text_QuitWritingQuizQuestion, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LilycoveCity_PokemonCenter_1F_EventScript_DeclineMakeQuiz
	goto_if_eq VAR_RESULT, NO, LilycoveCity_PokemonCenter_1F_EventScript_WriteQuizQuestion
	end

LilycoveCity_PokemonCenter_1F_EventScript_FinishMakingQuiz::
	special QuizLadyTakePrizeForCustomQuiz
	special QuizLadyRecordCustomQuizData
	special QuizLadySetWaitingForChallenger
	msgbox LilycoveCity_PokemonCenter_1F_Text_IllLookForAChallenger, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_ContestLady::
	lock
	faceplayer
	msgbox LilycoveCity_PokemonCenter_1F_Text_ImTheContestLady, MSGBOX_DEFAULT
	specialvar VAR_RESULT, HasPlayerGivenContestLadyPokeblock
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonCenter_1F_EventScript_NotGivenPokeblock
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonCenter_1F_EventScript_GivenPokeblock
	end

@ Redundant with above script, VAR_RESULT will always be FALSE here
LilycoveCity_PokemonCenter_1F_EventScript_NotGivenPokeblock::
	specialvar VAR_RESULT, ShouldContestLadyShowGoOnAir
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonCenter_1F_EventScript_AskForPokeblock
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonCenter_1F_EventScript_GivenPokeblock
	end

LilycoveCity_PokemonCenter_1F_EventScript_GivenPokeblock::
	msgbox LilycoveCity_PokemonCenter_1F_Text_ThankForPokeblock, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_AskForPokeblock::
	special Script_BufferContestLadyCategoryAndMonName
	msgbox LilycoveCity_PokemonCenter_1F_Text_MyFriendDisplaysQuality, MSGBOX_DEFAULT
	checkitem ITEM_POKEBLOCK_CASE
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonCenter_1F_EventScript_NoPokeblockCase
	msgbox LilycoveCity_PokemonCenter_1F_Text_AskingForOnePokeblock, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LilycoveCity_PokemonCenter_1F_EventScript_DeclineGivePokeblock
	goto_if_eq VAR_RESULT, YES, LilycoveCity_PokemonCenter_1F_EventScript_ChoosePokeblock
	end

LilycoveCity_PokemonCenter_1F_EventScript_DeclineGivePokeblock::
	msgbox LilycoveCity_PokemonCenter_1F_Text_WhatACheapskate, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_ChoosePokeblock::
	fadescreen FADE_TO_BLACK
	special OpenPokeblockCaseForContestLady
	goto_if_eq VAR_RESULT, 0xFFFF, LilycoveCity_PokemonCenter_1F_EventScript_AskQuitGivingPokeblock
	goto_if_ne VAR_RESULT, 0xFFFF, LilycoveCity_PokemonCenter_1F_EventScript_GivePokeblock
	end

LilycoveCity_PokemonCenter_1F_EventScript_AskQuitGivingPokeblock::
	msgbox LilycoveCity_PokemonCenter_1F_Text_ICantHaveOnePokeblock, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LilycoveCity_PokemonCenter_1F_EventScript_DeclineGivePokeblock
	goto_if_eq VAR_RESULT, NO, LilycoveCity_PokemonCenter_1F_EventScript_ChoosePokeblock
	end

LilycoveCity_PokemonCenter_1F_EventScript_GivePokeblock::
	msgbox LilycoveCity_PokemonCenter_1F_Text_IllUseYourPokeblock, MSGBOX_DEFAULT
	special SetContestLadyGivenPokeblock
	special GetContestLadyMonSpecies
	goto LilycoveCity_PokemonCenter_1F_EventScript_FeedPokeblock
	end

@ VAR_0x8004 here is the return value from GivePokeblockToContestLady
LilycoveCity_PokemonCenter_1F_EventScript_FeedPokeblock::
	applymovement LOCALID_LILYCOVE_LADY, LilycoveCity_PokemonCenter_1F_Movement_LadyFaceMon
	waitmovement 0
	delay 60
	applymovement LOCALID_LILYCOVE_LADYS_MON, LilycoveCity_PokemonCenter_1F_Movement_MonFaceLady
	waitmovement 0
	delay 60
	waitse
	playmoncry VAR_0x8005, CRY_MODE_NORMAL
	delay 120
	waitmoncry
	goto_if_eq VAR_0x8004, 1, LilycoveCity_PokemonCenter_1F_EventScript_MonEnjoyPokeblock
	goto LilycoveCity_PokemonCenter_1F_EventScript_FinishFeedPokeblock
	end

@ VAR_0x8004 here is the return value from GivePokeblockToContestLady
LilycoveCity_PokemonCenter_1F_EventScript_MonEnjoyPokeblock::
	applymovement LOCALID_LILYCOVE_LADYS_MON, LilycoveCity_PokemonCenter_1F_Movement_MonJump
	waitmovement 0
	delay 60
LilycoveCity_PokemonCenter_1F_EventScript_FinishFeedPokeblock::
	applymovement LOCALID_LILYCOVE_LADY, LilycoveCity_PokemonCenter_1F_Movement_LadyFacePlayer
	waitmovement 0
	delay 60
	goto_if_eq VAR_0x8004, 0, LilycoveCity_PokemonCenter_1F_EventScript_MonDislikedPokeblock
	goto_if_eq VAR_0x8004, 1, LilycoveCity_PokemonCenter_1F_EventScript_MonLikedPokeblock
	end

LilycoveCity_PokemonCenter_1F_EventScript_MonDislikedPokeblock::
	msgbox LilycoveCity_PokemonCenter_1F_Text_NoChangeThanks, MSGBOX_DEFAULT
	goto LilycoveCity_PokemonCenter_1F_EventScript_CheckAirContestLadyShow
	end

LilycoveCity_PokemonCenter_1F_EventScript_MonLikedPokeblock::
	special Script_BufferContestLadyCategoryAndMonName
	msgbox LilycoveCity_PokemonCenter_1F_Text_ReallyImprovedThanks, MSGBOX_DEFAULT
	goto LilycoveCity_PokemonCenter_1F_EventScript_CheckAirContestLadyShow
	end

LilycoveCity_PokemonCenter_1F_EventScript_CheckAirContestLadyShow::
	specialvar VAR_RESULT, ShouldContestLadyShowGoOnAir
	goto_if_eq VAR_RESULT, 1, LilycoveCity_PokemonCenter_1F_EventScript_AirContestLadyShow
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_AirContestLadyShow::
	msgbox LilycoveCity_PokemonCenter_1F_Text_ReadyToEnterContests, MSGBOX_DEFAULT
	special PutLilycoveContestLadyShowOnTheAir
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_NoPokeblockCase::
	msgbox LilycoveCity_PokemonCenter_1F_Text_DontHaveAPokeblockCase, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_Movement_LadyFaceMon:
	face_right
	delay_8
	step_end

LilycoveCity_PokemonCenter_1F_Movement_MonFaceLady:
	face_left
	delay_8
	step_end

@ Unused
LilycoveCity_PokemonCenter_1F_Movement_MonFaceDown:
	face_down
	step_end

LilycoveCity_PokemonCenter_1F_Movement_LadyFacePlayer:
	face_player
	step_end

LilycoveCity_PokemonCenter_1F_Movement_MonJump:
	disable_jump_landing_ground_effect
	jump_in_place_left
	disable_jump_landing_ground_effect
	jump_in_place_left
	step_end

LilycoveCity_PokemonCenter_1F_EventScript_ContestLadyMon::
	specialvar VAR_RESULT, GetContestLadyCategory
	special Script_BufferContestLadyCategoryAndMonName
	special GetContestLadyMonSpecies
	goto_if_eq VAR_RESULT, CONTEST_CATEGORY_COOL, LilycoveCity_PokemonCenter_1F_EventScript_Zigzagoon
	goto_if_eq VAR_RESULT, CONTEST_CATEGORY_BEAUTY, LilycoveCity_PokemonCenter_1F_EventScript_Skitty
	goto_if_eq VAR_RESULT, CONTEST_CATEGORY_CUTE, LilycoveCity_PokemonCenter_1F_EventScript_Poochyena
	goto_if_eq VAR_RESULT, CONTEST_CATEGORY_SMART, LilycoveCity_PokemonCenter_1F_EventScript_Kecleon
	goto_if_eq VAR_RESULT, CONTEST_CATEGORY_TOUGH, LilycoveCity_PokemonCenter_1F_EventScript_Pikachu
	end

LilycoveCity_PokemonCenter_1F_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry VAR_0x8005, CRY_MODE_NORMAL
	msgbox LilycoveCity_PokemonCenter_1F_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_Skitty::
	lock
	faceplayer
	waitse
	playmoncry VAR_0x8005, CRY_MODE_NORMAL
	msgbox LilycoveCity_PokemonCenter_1F_Text_Skitty, MSGBOX_DEFAULT
	waitmoncry
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_Poochyena::
	lock
	faceplayer
	waitse
	playmoncry VAR_0x8005, CRY_MODE_NORMAL
	msgbox LilycoveCity_PokemonCenter_1F_Text_Poochyena, MSGBOX_DEFAULT
	waitmoncry
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_Kecleon::
	lock
	faceplayer
	waitse
	playmoncry VAR_0x8005, CRY_MODE_NORMAL
	msgbox LilycoveCity_PokemonCenter_1F_Text_Kecleon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_Pikachu::
	lock
	faceplayer
	waitse
	playmoncry VAR_0x8005, CRY_MODE_NORMAL
	msgbox LilycoveCity_PokemonCenter_1F_Text_Pikachu, MSGBOX_DEFAULT
	waitmoncry
	release
	end

LilycoveCity_PokemonCenter_1F_Text_ImTheFavorLady:
	.string "Tôi là FAVOR LADY...$"

LilycoveCity_PokemonCenter_1F_Text_ObsessedWithThing:
	.string "Dạo gần đây, tôi bị ám ảnh bởi những\n"
	.string "thứ {STR_VAR_1}...$"

LilycoveCity_PokemonCenter_1F_Text_ThankYouForLastTime:
	.string "Ồ... Cảm ơn bạn về lần trước...$"

LilycoveCity_PokemonCenter_1F_Text_PlayerGaveMeBadThing:
	.string "Lần trước, hình như là\n"
	.string "{STR_VAR_3}...\p"
	.string "{STR_VAR_3} đưa tôi một\n"
	.string "{STR_VAR_2}, bảo rằng nó\l"
	.string "{STR_VAR_1}.\p"
	.string "Nhưng nó chẳng {STR_VAR_1} chút\n"
	.string "nào. Hoàn toàn không.$"

LilycoveCity_PokemonCenter_1F_Text_PlayerGaveMeGreatThing:
	.string "Trước đây, {STR_VAR_3} đã tặng\n"
	.string "tôi một món rất {STR_VAR_1}, đó\l"
	.string "là {STR_VAR_2}.\p"
	.string "Giờ tôi quý nó lắm.$"

LilycoveCity_PokemonCenter_1F_Text_WillYouShareThing:
	.string "Nghe này, nếu bạn có thứ gì\n"
	.string "{STR_VAR_1}, bạn chia sẻ với tôi\l"
	.string "nhé?$"

LilycoveCity_PokemonCenter_1F_Text_WhatWillYouGiveMe:
	.string "...Thật sao? Bạn sẽ cho tôi gì vậy?$"

LilycoveCity_PokemonCenter_1F_Text_IsThatSoGoodbye:
	.string "Vậy sao? Thế thì tạm biệt...$"

LilycoveCity_PokemonCenter_1F_Text_NotWillingToShare:
	.string "Ồ... Bạn không muốn chia sẻ sao?$"

LilycoveCity_PokemonCenter_1F_Text_IllTryToCherishIt:
	.string "Ồ? {STR_VAR_2} đó\n"
	.string "{STR_VAR_1} sao?\p"
	.string "...Ồ, vậy à?\p"
	.string "Dù sao tôi cũng phải cảm ơn bạn. Tôi sẽ\n"
	.string "cố trân trọng nó...$"

LilycoveCity_PokemonCenter_1F_Text_IWillCherishThis:
	.string "Ồ...\p"
	.string "Thật là {STR_VAR_1}, món\n"
	.string "{STR_VAR_2} này...\p"
	.string "Tuyệt quá phải không? Cứ như mơ vậy...\p"
	.string "Cảm ơn bạn... Tôi sẽ trân trọng nó...$"

LilycoveCity_PokemonCenter_1F_Text_IWillTreasureThis:
	.string "...Ồ, ồ, ồ...\p"
	.string "Tuyệt vời quá! Nó thật sự\n"
	.string "{STR_VAR_1}!\p"
	.string "Tôi chưa từng biết một\n"
	.string "{STR_VAR_2} lại có thể\l"
	.string "{STR_VAR_1} đến thế!\p"
	.string "Cảm ơn bạn!\p"
	.string "Tôi sẽ nâng niu nó suốt đời!$"

LilycoveCity_PokemonCenter_1F_Text_IllGiveYouThisInReturn:
	.string "Để đáp lại món quà tuyệt vời của bạn,\n"
	.string "tôi sẽ tặng bạn vật phẩm tuyệt diệu\l"
	.string "này.\p"
	.string "Hy vọng bạn sẽ trân trọng nó...$"

LilycoveCity_PokemonCenter_1F_Text_YouDontHaveSpaceForIt:
	.string "Ồ, bạn không thể nhận nó khi không còn\n"
	.string "chỗ trống.\p"
	.string "Hãy sắp xếp lại TÚI ĐỒ rồi quay lại gặp\n"
	.string "tôi...$"

LilycoveCity_PokemonCenter_1F_Text_ImTheQuizLady:
	.string "Tôi là QUIZ LADY! Tôi mê đố vui lắm!$"

LilycoveCity_PokemonCenter_1F_Text_WaitingToTakeYourQuiz:
	.string "Ồ?\p"
	.string "Tôi đang chờ một người thử sức với\n"
	.string "câu đố bạn đã tạo.\p"
	.string "Chúng ta nói chuyện vào dịp khác nhé?$"

LilycoveCity_PokemonCenter_1F_Text_WaitingForChallenger:
	.string "Tôi đang chờ ai đó đến thử sức với câu\n"
	.string "đố do {STR_VAR_1} này nghĩ ra!$"

LilycoveCity_PokemonCenter_1F_Text_TakeQuizChallenge:
	.string "Nếu trả lời đúng, bạn có thể giành được\n"
	.string "phần thưởng tuyệt vời!\p"
	.string "Bạn có muốn thử sức với câu đố không?$"

LilycoveCity_PokemonCenter_1F_Text_WaitForAnswer:
	.string "... ... ... ... ... ... ... ... ... ... ... ...$"

LilycoveCity_PokemonCenter_1F_Text_HowBoringBye:
	.string "Ôi, chán quá! Tạm biệt nhé!$"

LilycoveCity_PokemonCenter_1F_Text_YoureGoingToQuit:
	.string "Ôi! Bạn định bỏ cuộc sao?$"

LilycoveCity_PokemonCenter_1F_Text_TakeTheQuizAnotherTime:
	.string "Lần sau hãy đến thử sức với câu đố\n"
	.string "nhé!$"

LilycoveCity_PokemonCenter_1F_Text_YouGotItRight:
	.string "Bạn tuyệt thật! Bạn đã trả lời đúng!\n"
	.string "Đầu óc bạn nhạy bén ghê!$"

LilycoveCity_PokemonCenter_1F_Text_YouGotItRightYouveWonPersonsPrize:
	.string "Xin chúc mừng! Bạn đã trả lời đúng câu\n"
	.string "đố!\p"
	.string "Bạn đã giành được phần thưởng do\n"
	.string "{STR_VAR_1} cung cấp!$"

@ Unused
LilycoveCity_PokemonCenter_1F_Text_XReceivedOneY:
	.string "{STR_VAR_1} đã nhận được một\n"
	.string "{STR_VAR_2}!$"

LilycoveCity_PokemonCenter_1F_Text_YourBagIsFilledUp:
	.string "Ồ? TÚI ĐỒ của bạn đã đầy!\p"
	.string "Hãy quay lại gặp tôi khi có chỗ trống.$"

LilycoveCity_PokemonCenter_1F_Text_WrongTheCorrectAnswerIs:
	.string "Hmm... Sai rồi! Đáp án đúng là\n"
	.string "{STR_VAR_3}!$"

LilycoveCity_PokemonCenter_1F_Text_IGetToKeepPrize:
	.string "Tiếc quá!\p"
	.string "Giờ phần thưởng {STR_VAR_1} của\n"
	.string "câu đố sẽ thuộc về tôi!$"

LilycoveCity_PokemonCenter_1F_Text_MakeYourOwnQuiz:
	.string "Nghe này, nghe này! Bạn có muốn tự tạo\n"
	.string "một câu đố không?$"

LilycoveCity_PokemonCenter_1F_Text_MaybeNextTime:
	.string "Ồ, ra vậy... Thôi thì để lần sau nhé!$"

LilycoveCity_PokemonCenter_1F_Text_PickYourPrize:
	.string "Được rồi, việc đầu tiên bạn phải làm là\n"
	.string "chọn phần thưởng cho người trả lời\l"
	.string "đúng câu đố của bạn.\p"
	.string "Nhưng hãy cẩn thận, nếu người thử sức\n"
	.string "không trả lời đúng, phần thưởng sẽ\l"
	.string "thuộc về tôi!$"

LilycoveCity_PokemonCenter_1F_Text_QuitChoosingPrize:
	.string "Nếu không chọn phần thưởng, bạn không\n"
	.string "thể tạo câu đố.\p"
	.string "Bạn định ngừng tạo câu đố sao?$"

LilycoveCity_PokemonCenter_1F_Text_WriteYourQuiz:
	.string "Ồ, tuyệt quá! Đó là một phần thưởng\n"
	.string "tuyệt vời!\p"
	.string "Tiếp theo, bạn cần viết câu hỏi và đáp\n"
	.string "án cho câu đố.$"

LilycoveCity_PokemonCenter_1F_Text_QuitWritingQuizQuestion:
	.string "Bạn định ngừng viết câu hỏi cho câu đố\n"
	.string "sao?$"

@ Unused
LilycoveCity_PokemonCenter_1F_Text_QuitWritingQuizAnswer:
	.string "Bạn định ngừng chọn đáp án cho câu đố\n"
	.string "sao?$"

LilycoveCity_PokemonCenter_1F_Text_IllLookForAChallenger:
	.string "Cảm ơn bạn! Bạn đã tạo được một câu đố\n"
	.string "hay đấy.\p"
	.string "Tôi sẽ đi tìm người đến thử sức với\n"
	.string "câu đố của bạn ngay.$"

LilycoveCity_PokemonCenter_1F_Text_ImTheContestLady:
	.string "Tôi là CONTEST LADY! Tôi mê thi đấu\n"
	.string "lắm!$"

LilycoveCity_PokemonCenter_1F_Text_ThankForPokeblock:
	.string "Cảm ơn bạn về {POKEBLOCK} lần trước\n"
	.string "nhé!$"

LilycoveCity_PokemonCenter_1F_Text_MyFriendDisplaysQuality:
	.string "Đây là bạn tôi, {STR_VAR_1}! Nó\n"
	.string "chính là hiện thân của\l"
	.string "{STR_VAR_2}!\p"
	.string "Nhưng tôi nghĩ nó còn có thể thể hiện\n"
	.string "nhiều {STR_VAR_2} hơn nữa!$"

LilycoveCity_PokemonCenter_1F_Text_DontHaveAPokeblockCase:
	.string "Vì vậy, tôi cần bạn giúp!\p"
	.string "Làm ơn cho tôi một {POKEBLOCK} nhé?\n"
	.string "Tôi chỉ xin đúng một cái thôi!\p"
	.string "...Ồ, nhưng... Bạn không có {POKEBLOCK}\n"
	.string "CASE sao? Vậy thì không được rồi. Để\l"
	.string "lần sau nhé!$"

LilycoveCity_PokemonCenter_1F_Text_AskingForOnePokeblock:
	.string "Vì vậy, tôi cần bạn giúp!\p"
	.string "Làm ơn cho tôi một {POKEBLOCK} nhé?\n"
	.string "Tôi chỉ xin đúng một cái thôi!$"

LilycoveCity_PokemonCenter_1F_Text_ICantHaveOnePokeblock:
	.string "Ơ kìa! Tôi không được một {POKEBLOCK}\n"
	.string "sao?!$"

LilycoveCity_PokemonCenter_1F_Text_WhatACheapskate:
	.string "Trời ạ! Đúng là keo kiệt!$"

LilycoveCity_PokemonCenter_1F_Text_IllUseYourPokeblock:
	.string "Hay quá! Cảm ơn bạn!\p"
	.string "Tôi sẽ cho POKéMON của mình ăn\n"
	.string "{POKEBLOCK} của bạn ngay.$"

LilycoveCity_PokemonCenter_1F_Text_NoChangeThanks:
	.string "...Có vẻ chẳng có gì thay đổi cả...\p"
	.string "Hmm...\p"
	.string "Thôi cũng được! Cảm ơn bạn rất nhiều!$"

LilycoveCity_PokemonCenter_1F_Text_ReallyImprovedThanks:
	.string "Ồ, hay quá! Nó vui hẳn lên!\p"
	.string "Tôi nghĩ {STR_VAR_1} cũng đã cải\n"
	.string "thiện đáng kể phẩm chất\l"
	.string "{STR_VAR_2}.\p"
	.string "Cảm ơn bạn nhiều lắm!$"

LilycoveCity_PokemonCenter_1F_Text_ReadyToEnterContests:
	.string "Hmm...\p"
	.string "Tôi nghĩ chúng tôi đã sẵn sàng tham gia\n"
	.string "vài cuộc thi.\p"
	.string "Nếu tình cờ thấy chúng tôi thi đấu ở\n"
	.string "đâu đó, hy vọng bạn sẽ cổ vũ cho chúng\l"
	.string "tôi.$"

LilycoveCity_PokemonCenter_1F_Text_Zigzagoon:
	.string "{STR_VAR_1}: Guguuh!$"

LilycoveCity_PokemonCenter_1F_Text_Kecleon:
	.string "{STR_VAR_1}: Igigigiiih!$"

LilycoveCity_PokemonCenter_1F_Text_Poochyena:
	.string "{STR_VAR_1}: Baaarun...$"

LilycoveCity_PokemonCenter_1F_Text_Pikachu:
	.string "{STR_VAR_1}: Pikka!$"

LilycoveCity_PokemonCenter_1F_Text_Skitty:
	.string "{STR_VAR_1}: Umyaaaan!$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global LilycoveCity_PokemonCenter_1F_Text_ImTheFavorLady
	.global LilycoveCity_PokemonCenter_1F_Text_ObsessedWithThing
	.global LilycoveCity_PokemonCenter_1F_Text_ThankYouForLastTime
	.global LilycoveCity_PokemonCenter_1F_Text_PlayerGaveMeBadThing
	.global LilycoveCity_PokemonCenter_1F_Text_PlayerGaveMeGreatThing
	.global LilycoveCity_PokemonCenter_1F_Text_WillYouShareThing
	.global LilycoveCity_PokemonCenter_1F_Text_WhatWillYouGiveMe
	.global LilycoveCity_PokemonCenter_1F_Text_IsThatSoGoodbye
	.global LilycoveCity_PokemonCenter_1F_Text_NotWillingToShare
	.global LilycoveCity_PokemonCenter_1F_Text_IllTryToCherishIt
	.global LilycoveCity_PokemonCenter_1F_Text_IWillCherishThis
	.global LilycoveCity_PokemonCenter_1F_Text_IWillTreasureThis
	.global LilycoveCity_PokemonCenter_1F_Text_IllGiveYouThisInReturn
	.global LilycoveCity_PokemonCenter_1F_Text_YouDontHaveSpaceForIt
	.global LilycoveCity_PokemonCenter_1F_Text_ImTheQuizLady
	.global LilycoveCity_PokemonCenter_1F_Text_WaitingToTakeYourQuiz
	.global LilycoveCity_PokemonCenter_1F_Text_WaitingForChallenger
	.global LilycoveCity_PokemonCenter_1F_Text_TakeQuizChallenge
	.global LilycoveCity_PokemonCenter_1F_Text_WaitForAnswer
	.global LilycoveCity_PokemonCenter_1F_Text_HowBoringBye
	.global LilycoveCity_PokemonCenter_1F_Text_YoureGoingToQuit
	.global LilycoveCity_PokemonCenter_1F_Text_TakeTheQuizAnotherTime
	.global LilycoveCity_PokemonCenter_1F_Text_YouGotItRight
	.global LilycoveCity_PokemonCenter_1F_Text_YouGotItRightYouveWonPersonsPrize
	.global LilycoveCity_PokemonCenter_1F_Text_XReceivedOneY
	.global LilycoveCity_PokemonCenter_1F_Text_YourBagIsFilledUp
	.global LilycoveCity_PokemonCenter_1F_Text_WrongTheCorrectAnswerIs
	.global LilycoveCity_PokemonCenter_1F_Text_IGetToKeepPrize
	.global LilycoveCity_PokemonCenter_1F_Text_MakeYourOwnQuiz
	.global LilycoveCity_PokemonCenter_1F_Text_MaybeNextTime
	.global LilycoveCity_PokemonCenter_1F_Text_PickYourPrize
	.global LilycoveCity_PokemonCenter_1F_Text_QuitChoosingPrize
	.global LilycoveCity_PokemonCenter_1F_Text_WriteYourQuiz
	.global LilycoveCity_PokemonCenter_1F_Text_QuitWritingQuizQuestion
	.global LilycoveCity_PokemonCenter_1F_Text_QuitWritingQuizAnswer
	.global LilycoveCity_PokemonCenter_1F_Text_IllLookForAChallenger
	.global LilycoveCity_PokemonCenter_1F_Text_ImTheContestLady
	.global LilycoveCity_PokemonCenter_1F_Text_ThankForPokeblock
	.global LilycoveCity_PokemonCenter_1F_Text_MyFriendDisplaysQuality
	.global LilycoveCity_PokemonCenter_1F_Text_DontHaveAPokeblockCase
	.global LilycoveCity_PokemonCenter_1F_Text_AskingForOnePokeblock
	.global LilycoveCity_PokemonCenter_1F_Text_ICantHaveOnePokeblock
	.global LilycoveCity_PokemonCenter_1F_Text_WhatACheapskate
	.global LilycoveCity_PokemonCenter_1F_Text_IllUseYourPokeblock
	.global LilycoveCity_PokemonCenter_1F_Text_NoChangeThanks
	.global LilycoveCity_PokemonCenter_1F_Text_ReallyImprovedThanks
	.global LilycoveCity_PokemonCenter_1F_Text_ReadyToEnterContests
	.global LilycoveCity_PokemonCenter_1F_Text_Poochyena
@ END GENERATED LOCALIZATION EXPORTS
