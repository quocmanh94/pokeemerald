@ Either ends or returns to EventScript_ContestReceptionist after submitting a contest entry
LilycoveCity_ContestLobby_EventScript_SpeakToContestReceptionist::
	lock
	faceplayer
	goto_if_ne VAR_CONTEST_PRIZE_PICKUP, 0, LilycoveCity_ContestLobby_EventScript_PickUpPrize
	call_if_set FLAG_RECEIVED_POKEBLOCK_CASE, LilycoveCity_ContestLobby_EventScript_ReceptionWelcome
	call_if_unset FLAG_RECEIVED_POKEBLOCK_CASE, LilycoveCity_ContestLobby_EventScript_GivePokeblockCase
	goto LilycoveCity_ContestLobby_EventScript_AskEnterContest
	end

LilycoveCity_ContestLobby_EventScript_ReceptionWelcome::
	msgbox LilycoveCity_ContestLobby_Text_ContestReception, MSGBOX_DEFAULT
	return

LilycoveCity_ContestLobby_EventScript_GivePokeblockCase::
	msgbox LilycoveCity_ContestLobby_Text_ReceptionDontHavePokeblockCase, MSGBOX_DEFAULT
	giveitem ITEM_POKEBLOCK_CASE
	setflag FLAG_RECEIVED_POKEBLOCK_CASE
	msgbox LilycoveCity_ContestLobby_Text_NowThatWeveClearedThatUp, MSGBOX_DEFAULT
	return

LilycoveCity_ContestLobby_EventScript_PickUpPrize::
	msgbox LilycoveCity_ContestLobby_Text_PokemonWonWeHavePrize, MSGBOX_DEFAULT
	switch VAR_CONTEST_PRIZE_PICKUP
	case 4, LilycoveCity_ContestLobby_EventScript_GiveLuxuryBallAtCounter
	end

LilycoveCity_ContestLobby_EventScript_GiveLuxuryBallAtCounter::
	giveitem ITEM_LUXURY_BALL
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_ContestLobby_EventScript_NoRoomForLuxuryBallAtCounter
	setvar VAR_CONTEST_PRIZE_PICKUP, 0
	closemessage
	release
	end

LilycoveCity_ContestLobby_EventScript_NoRoomForLuxuryBallAtCounter::
	call Common_EventScript_BagIsFull
	msgbox LilycoveCity_ContestLobby_Text_ComeBackForPrizeLater, MSGBOX_DEFAULT
	release
	end

LilycoveCity_ContestLobby_EventScript_AskEnterContest::
	message LilycoveCity_ContestLobby_Text_EnterContest1
	waitmessage
	multichoice 0, 0, MULTI_ENTERINFO, FALSE
	switch VAR_RESULT
	case 0, LilycoveCity_ContestLobby_EventScript_ChooseContestRank
	case 1, LilycoveCity_ContestLobby_EventScript_ContestInfo
	case 2, LilycoveCity_ContestLobby_EventScript_CancelEnterContest
	case MULTI_B_PRESSED, LilycoveCity_ContestLobby_EventScript_CancelEnterContest
	end

LilycoveCity_ContestLobby_EventScript_ContestInfo::
	message LilycoveCity_ContestLobby_Text_WhichTopic1
	waitmessage
	multichoice 0, 0, MULTI_CONTEST_INFO, FALSE
	switch VAR_RESULT
	case 0, LilycoveCity_ContestLobby_EventScript_ExplainContests
	case 1, LilycoveCity_ContestLobby_EventScript_ExplainContestTypes
	case 2, LilycoveCity_ContestLobby_EventScript_ExplainContestRanks
	case 3, LilycoveCity_ContestLobby_EventScript_AskEnterContest
	case MULTI_B_PRESSED, LilycoveCity_ContestLobby_EventScript_AskEnterContest
	end

LilycoveCity_ContestLobby_EventScript_ExplainContests::
	msgbox LilycoveCity_ContestLobby_Text_ExplainContests, MSGBOX_DEFAULT
	goto LilycoveCity_ContestLobby_EventScript_ContestInfo
	end

LilycoveCity_ContestLobby_EventScript_ExplainContestTypes::
	msgbox LilycoveCity_ContestLobby_Text_ExplainContestTypes, MSGBOX_DEFAULT
	goto LilycoveCity_ContestLobby_EventScript_ContestInfo
	end

LilycoveCity_ContestLobby_EventScript_ExplainContestRanks::
	msgbox LilycoveCity_ContestLobby_Text_ExplainContestRanks, MSGBOX_DEFAULT
	goto LilycoveCity_ContestLobby_EventScript_ContestInfo
	end

LilycoveCity_ContestLobby_EventScript_CancelEnterContest::
	msgbox LilycoveCity_ContestLobby_Text_ParticipateAnotherTime, MSGBOX_DEFAULT
	release
	end

LilycoveCity_ContestLobby_EventScript_ChooseContestMon::
	msgbox LilycoveCity_ContestLobby_Text_EnterWhichPokemon1, MSGBOX_DEFAULT
	choosecontestmon
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, LilycoveCity_ContestLobby_EventScript_CancelEnterContest
	special TryEnterContestMon
	goto_if_eq VAR_RESULT, CANT_ENTER_CONTEST, LilycoveCity_ContestLobby_EventScript_CantEnterLowRank
	goto_if_eq VAR_RESULT, CAN_ENTER_CONTEST_EQUAL_RANK, LilycoveCity_ContestLobby_EventScript_EnterMon
	goto_if_eq VAR_RESULT, CAN_ENTER_CONTEST_HIGH_RANK, LilycoveCity_ContestLobby_EventScript_ConfirmEntryAlreadyWon
	goto_if_eq VAR_RESULT, CANT_ENTER_CONTEST_EGG, LilycoveCity_ContestLobby_EventScript_CantEnterEgg
	goto_if_eq VAR_RESULT, CANT_ENTER_CONTEST_FAINTED, LilycoveCity_ContestLobby_EventScript_CantEnterFainted
	end

LilycoveCity_ContestLobby_EventScript_ChooseContestRank::
	message LilycoveCity_ContestLobby_Text_EnterWhichRank
	waitmessage
	multichoice 0, 0, MULTI_CONTEST_RANK, FALSE
	switch VAR_RESULT
	case 0, LilycoveCity_ContestLobby_EventScript_EnterNormalRank
	case 1, LilycoveCity_ContestLobby_EventScript_EnterSuperRank
	case 2, LilycoveCity_ContestLobby_EventScript_EnterHyperRank
	case 3, LilycoveCity_ContestLobby_EventScript_EnterMasterRank
	case 4, LilycoveCity_ContestLobby_EventScript_CancelEnterContest
	case MULTI_B_PRESSED, LilycoveCity_ContestLobby_EventScript_CancelEnterContest
	end

LilycoveCity_ContestLobby_EventScript_EnterNormalRank::
	setvar VAR_CONTEST_RANK, CONTEST_RANK_NORMAL
	goto LilycoveCity_ContestLobby_EventScript_ChooseContestType
	end

LilycoveCity_ContestLobby_EventScript_EnterSuperRank::
	setvar VAR_CONTEST_RANK, CONTEST_RANK_SUPER
	goto LilycoveCity_ContestLobby_EventScript_ChooseContestType
	end

LilycoveCity_ContestLobby_EventScript_EnterHyperRank::
	setvar VAR_CONTEST_RANK, CONTEST_RANK_HYPER
	goto LilycoveCity_ContestLobby_EventScript_ChooseContestType
	end

LilycoveCity_ContestLobby_EventScript_EnterMasterRank::
	setvar VAR_CONTEST_RANK, CONTEST_RANK_MASTER
	goto LilycoveCity_ContestLobby_EventScript_ChooseContestType
	end

@ The multichoice selection IDs are equal to the CATEGORY values
@ So rather than list the cases they just copy VAR_RESULT for a valid selection into VAR_CONTEST_CATEGORY
LilycoveCity_ContestLobby_EventScript_ChooseContestType::
	message LilycoveCity_ContestLobby_Text_EnterWhichContest1
	waitmessage
	multichoice 0, 0, MULTI_CONTEST_TYPE, FALSE
	switch VAR_RESULT
	case 5, LilycoveCity_ContestLobby_EventScript_CancelEnterContest
	case MULTI_B_PRESSED, LilycoveCity_ContestLobby_EventScript_CancelEnterContest
	copyvar VAR_CONTEST_CATEGORY, VAR_RESULT
	goto LilycoveCity_ContestLobby_EventScript_ChooseContestMon
	end

LilycoveCity_ContestLobby_EventScript_CantEnterLowRank::
	msgbox LilycoveCity_ContestLobby_Text_MonNotQualifiedForRank, MSGBOX_DEFAULT
	goto LilycoveCity_ContestLobby_EventScript_ChooseContestMon
	release
	end

@ Unused
LilycoveCity_ContestLobby_EventScript_ConfirmEntry::
	msgbox LilycoveCity_ContestLobby_Text_ConfirmContestMon, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, LilycoveCity_ContestLobby_EventScript_ChooseContestMon
	case YES, LilycoveCity_ContestLobby_EventScript_EnterMon
	end

LilycoveCity_ContestLobby_EventScript_ConfirmEntryAlreadyWon::
	msgbox LilycoveCity_ContestLobby_Text_AlreadyWonEnterAnyway, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, LilycoveCity_ContestLobby_EventScript_ChooseContestMon
	case YES, LilycoveCity_ContestLobby_EventScript_EnterMon
	end

LilycoveCity_ContestLobby_EventScript_CantEnterEgg::
	msgbox LilycoveCity_ContestLobby_Text_EggCannotTakePart, MSGBOX_DEFAULT
	goto LilycoveCity_ContestLobby_EventScript_ChooseContestMon
	release
	end

LilycoveCity_ContestLobby_EventScript_CantEnterFainted::
	msgbox LilycoveCity_ContestLobby_Text_MonInNoConditionForContest, MSGBOX_DEFAULT
	goto LilycoveCity_ContestLobby_EventScript_ChooseContestMon
	release
	end

@ The return here is back to LilycoveCity_ContestLobby_EventScript_ContestReceptionist
LilycoveCity_ContestLobby_EventScript_EnterMon::
	msgbox LilycoveCity_ContestLobby_Text_YourMonIsEntryNum4, MSGBOX_DEFAULT
	closemessage
	releaseall
	setvar VAR_CONTEST_HALL_STATE, 1
	return

ContestHall_EventScript_DoContest::
	special LinkContestTryShowWirelessIndicator
	setvar VAR_0x8006, 0
	lockall
	applymovement LOCALID_CONTESTANT_4, ContestHall_Movement_Player4FaceUp
	waitmovement 0
	applymovement LOCALID_CONTEST_MC, ContestHall_Movement_MCWalkDown
	waitmovement 0
	releaseall
	call ContestHall_EventScript_TryWaitForLink
	call ContestHall_EventScript_GetContestRankStringId
	call ContestHall_EventScript_GetContestCategory
	call ContestHall_EventScript_ContestGettingStarted
	call ContestHall_EventScript_ShowContestMons
	call ContestHall_EventScript_DoContestAppeals
	call ContestHall_EventScript_ContestResults
	call ContestHall_EventScript_GetWinnerObjEventId
	call ContestHall_EventScript_CongratulateWinner
	call ContestHall_EventScript_AudienceLookAround
	call ContestHall_EventScript_GiveWinnerPrize
	setvar VAR_CONTEST_HALL_STATE, 2
	return

ContestHall_EventScript_GetContestRankStringId::
	switch VAR_CONTEST_RANK
	case CONTEST_RANK_NORMAL, ContestHall_EventScript_GetNormalStringId
	case CONTEST_RANK_SUPER, ContestHall_EventScript_GetSuperStringId
	case CONTEST_RANK_HYPER, ContestHall_EventScript_GetHyperStringId
	case CONTEST_RANK_MASTER, ContestHall_EventScript_GetMasterStringId
	return

ContestHall_EventScript_GetNormalStringId::
	setvar VAR_0x8009, STDSTRING_NORMAL
	return

ContestHall_EventScript_GetSuperStringId::
	setvar VAR_0x8009, STDSTRING_SUPER
	return

ContestHall_EventScript_GetHyperStringId::
	setvar VAR_0x8009, STDSTRING_HYPER
	return

ContestHall_EventScript_GetMasterStringId::
	setvar VAR_0x8009, STDSTRING_MASTER
	return

@ This whole switch is equivalent to copyvar VAR_0x8008, VAR_CONTEST_CATEGORY
ContestHall_EventScript_GetContestCategory::
	switch VAR_CONTEST_CATEGORY
	case CONTEST_CATEGORY_COOL, ContestHall_EventScript_GetCategoryCool
	case CONTEST_CATEGORY_BEAUTY, ContestHall_EventScript_GetCategoryBeauty
	case CONTEST_CATEGORY_CUTE, ContestHall_EventScript_GetCategoryCute
	case CONTEST_CATEGORY_SMART, ContestHall_EventScript_GetCategorySmart
	case CONTEST_CATEGORY_TOUGH, ContestHall_EventScript_GetCategoryTough
	return

ContestHall_EventScript_GetCategoryCool::
	setvar VAR_0x8008, CONTEST_CATEGORY_COOL
	return

ContestHall_EventScript_GetCategoryBeauty::
	setvar VAR_0x8008, CONTEST_CATEGORY_BEAUTY
	return

ContestHall_EventScript_GetCategoryCute::
	setvar VAR_0x8008, CONTEST_CATEGORY_CUTE
	return

ContestHall_EventScript_GetCategorySmart::
	setvar VAR_0x8008, CONTEST_CATEGORY_SMART
	return

ContestHall_EventScript_GetCategoryTough::
	setvar VAR_0x8008, CONTEST_CATEGORY_TOUGH
	return

ContestHall_EventScript_ContestGettingStarted::
	buffercontestname STR_VAR_2, VAR_0x8008
	bufferstdstring STR_VAR_3, VAR_0x8009
	call ContestHall_EventScript_GettingStarted
	lockall
	applymovement LOCALID_CONTEST_MC, ContestHall_Movement_MCBackUp
	waitmovement 0
	releaseall
	return

ContestHall_EventScript_GettingStarted::
	goto_if_eq VAR_CONTEST_TYPE, CONTEST_TYPE_LINK, ContestHall_EventScript_GettingStartedLink
	lockall
	msgbox ContestHall_Text_GettingStartedParticipantsAsFollows, MSGBOX_DEFAULT
	releaseall
	return

ContestHall_EventScript_GettingStartedLink::
	specialvar VAR_RESULT, IsWirelessContest
	goto_if_eq VAR_RESULT, TRUE, ContestHall_EventScript_GettingStartedWireless
	messageautoscroll ContestHall_Text_GettingStartedParticipantsAsFollowsLink
	waitmessage
	return

ContestHall_EventScript_GettingStartedWireless::
	messageautoscroll ContestHall_Text_GettingStartedWireless
	waitmessage
	call ContestHall_EventScript_TryWaitForLink
	messageautoscroll ContestHall_Text_ParticipantsAsFollows
	waitmessage
	call ContestHall_EventScript_TryWaitForLink
	return

ContestHall_EventScript_ShowContestMons::
	call ContestHall_EventScript_ContestantWalkToCenter
	call ContestHall_EventScript_ShowContestMonPic
	call ContestHall_EventScript_AudienceHeartEmotes
	call ContestHall_EventScript_AudienceReactToContestant
	call ContestHall_EventScript_ContestantReturn
	call ContestHall_EventScript_TryWaitForLink
	call ContestHall_EventScript_TryWaitForLink
	addvar VAR_0x8006, 1
	goto_if_ne VAR_0x8006, CONTESTANT_COUNT, ContestHall_EventScript_ShowContestMons
	call ContestHall_EventScript_AudienceVote
	setvar VAR_TEMP_1, 6
	return

ContestHall_EventScript_TryWaitForLink::
	specialvar VAR_RESULT, IsWirelessContest
	goto_if_eq VAR_RESULT, TRUE, ContestHall_EventScript_WaitForLink
	return

ContestHall_EventScript_WaitForLink::
	special LinkContestWaitForConnection
	return

ContestHall_EventScript_ContestantWalkToCenter::
	goto_if_eq VAR_0x8006, 0, ContestHall_EventScript_Player1WalkToCenter
	goto_if_eq VAR_0x8006, 1, ContestHall_EventScript_Player2WalkToCenter
	goto_if_eq VAR_0x8006, 2, ContestHall_EventScript_Player3WalkToCenter
	goto_if_eq VAR_0x8006, 3, ContestHall_EventScript_Player4WalkToCenter
	return

ContestHall_EventScript_Player1WalkToCenter::
	call ContestHall_EventScript_TryWaitForLink
	lockall
	applymovement LOCALID_CONTESTANT_1, ContestHall_Movement_Player1WalkToCenter
	waitmovement 0
	releaseall
	setvar VAR_0x800B, LOCALID_CONTESTANT_1
	return

ContestHall_EventScript_Player2WalkToCenter::
	call ContestHall_EventScript_TryWaitForLink
	lockall
	applymovement LOCALID_CONTESTANT_2, ContestHall_Movement_Player2WalkToCenter
	waitmovement 0
	releaseall
	setvar VAR_0x800B, LOCALID_CONTESTANT_2
	return

ContestHall_EventScript_Player3WalkToCenter::
	call ContestHall_EventScript_TryWaitForLink
	lockall
	applymovement LOCALID_CONTESTANT_3, ContestHall_Movement_Player3WalkToCenter
	waitmovement 0
	releaseall
	setvar VAR_0x800B, LOCALID_CONTESTANT_3
	return

ContestHall_EventScript_Player4WalkToCenter::
	call ContestHall_EventScript_TryWaitForLink
	lockall
	applymovement LOCALID_CONTESTANT_4, ContestHall_Movement_Player4WalkToCenter
	waitmovement 0
	releaseall
	setvar VAR_0x800B, LOCALID_CONTESTANT_4
	return

ContestHall_EventScript_ShowContestMonPic::
	special BufferContestTrainerAndMonNames
	addvar VAR_0x8006, 1
	buffernumberstring STR_VAR_2, VAR_0x8006
	lockall
	applymovement VAR_0x800B, ContestHall_Movement_ContestantDelay32
	waitmovement 0
	releaseall
	call ContestHall_EventScript_TryWaitForLink
	call ContestHall_EventScript_CheckIfContestWithRSPlayer
	addobject LOCALID_CONTEST_POKEBALL
	playse SE_LEDGE
	lockall
	applymovement VAR_0x800B, ContestHall_Movement_ContestantDelay32
	waitmovement 0
	releaseall
	addvar VAR_0x8006, -1
	playse SE_BALL_OPEN
	special ShowContestEntryMonPic
	call ContestHall_EventScript_EntryXTrainersMon
	return

ContestHall_EventScript_EntryXTrainersMon::
	goto_if_eq VAR_CONTEST_TYPE, CONTEST_TYPE_LINK, ContestHall_EventScript_EntryXTrainersMonLink
	message ContestHall_Text_EntryXTrainersMon
	waitmessage
	return

ContestHall_EventScript_EntryXTrainersMonLink::
	messageautoscroll ContestHall_Text_EntryXTrainersMon
	waitmessage
	return

ContestHall_EventScript_AudienceVote::
	call ContestHall_EventScript_AudienceWillVote
	call ContestHall_EventScript_VotingUnderWay
	playse SE_M_ENCORE2
	waitmessage
	call ContestHall_EventScript_AudienceLookAround
	applymovement LOCALID_CONTEST_MC, ContestHall_Movement_MCFaceJudge2
	waitmovement 0
	applymovement LOCALID_CONTEST_JUDGE, ContestHall_Movement_JudgeFaceMC
	waitmovement 0
	delay 20
	applymovement LOCALID_CONTEST_MC, ContestHall_Movement_FaceContestants
	applymovement LOCALID_CONTEST_JUDGE, ContestHall_Movement_FaceContestants
	waitmovement 0
	return

ContestHall_EventScript_AudienceWillVote::
	goto_if_eq VAR_CONTEST_TYPE, CONTEST_TYPE_LINK, ContestHall_EventScript_AudienceWillVoteLink
	msgbox ContestHall_Text_SeenContestantsAudienceWillVote, MSGBOX_DEFAULT
	return

ContestHall_EventScript_AudienceWillVoteLink::
	specialvar VAR_RESULT, IsWirelessContest
	goto_if_eq VAR_RESULT, TRUE, ContestHall_EventScript_AudienceWillVoteWireless
	messageautoscroll ContestHall_Text_SeenContestantsAudienceWillVote
	waitmessage
	return

ContestHall_EventScript_AudienceWillVoteWireless::
	messageautoscroll ContestHall_Text_WeveSeenContestants
	waitmessage
	call ContestHall_EventScript_TryWaitForLink
	messageautoscroll ContestHall_Text_AudienceWillVote
	waitmessage
	call ContestHall_EventScript_TryWaitForLink
	messageautoscroll ContestHall_Text_LetVotingBegin
	waitmessage
	call ContestHall_EventScript_TryWaitForLink
	return

ContestHall_EventScript_VotingUnderWay::
	goto_if_eq VAR_CONTEST_TYPE, CONTEST_TYPE_LINK, ContestHall_EventScript_VotingUnderWayLink
	message ContestHall_Text_VotingUnderWay
	return

ContestHall_EventScript_VotingUnderWayLink::
	messageautoscroll ContestHall_Text_VotingUnderWay
	call ContestHall_EventScript_TryWaitForLink
	return

ContestHall_EventScript_AudienceReactToContestant::
	call ContestHall_EventScript_TryWaitForLink
	applymovement LOCALID_CONTEST_MC, ContestHall_Movement_AudienceMemberLookLeft
	waitmovement 0
	playse SE_M_ENCORE2
	call ContestHall_EventScript_VObjectAudienceLookAround
	applymovement LOCALID_CONTEST_AUDIENCE_5, ContestHall_Movement_AudienceMemberLookRight
	applymovement LOCALID_CONTEST_AUDIENCE_2, ContestHall_Movement_AudienceMemberLookDown
	applymovement LOCALID_CONTEST_AUDIENCE_3, ContestHall_Movement_AudienceMemberLookRight
	waitmovement 0
	applymovement LOCALID_CONTEST_MC, ContestHall_Movement_AudienceMemberLookRight
	waitmovement 0
	applymovement LOCALID_CONTEST_AUDIENCE_6, ContestHall_Movement_AudienceMemberLookLeft
	applymovement LOCALID_CONTEST_AUDIENCE_7, ContestHall_Movement_AudienceMemberLookDown
	applymovement LOCALID_CONTEST_AUDIENCE_1, ContestHall_Movement_AudienceMemberLookUp
	applymovement LOCALID_CONTEST_AUDIENCE_4, ContestHall_Movement_AudienceMemberLookLeft
	waitmovement 0
	applymovement LOCALID_CONTEST_MC, ContestHall_Movement_MCLookAtJudge
	waitmovement 0
	applymovement LOCALID_CONTEST_MC, ContestHall_Movement_MCWalkInPlaceDown
	applymovement LOCALID_CONTEST_JUDGE, ContestHall_Movement_JudgeLookAtMC
	waitmovement 0
	releaseall
	call ContestHall_EventScript_TryWaitForLink
	return

@ For below VAR_TEMP_0 is the number of heart emotes to try to display in the audience
@ The number of hearts to try to display is based on the condition of the presented pokemon and the rank
@ For each heart to display a random audience member is chosen, and a new one chosen if they already displayed a heart
@ VAR_TEMP_1 through VAR_TEMP_8 represent each of the 8 audience members that are actual object events
@    and are set to 9 if they havent displayed a heart yet, and 1 if they have
ContestHall_EventScript_AudienceHeartEmotes::
	special GetContestMonCondition
	call_if_eq VAR_CONTEST_TYPE, CONTEST_TYPE_NPC_NORMAL, ContestHall_EventScript_GetNumberOfHeartsNormal
	call_if_eq VAR_CONTEST_TYPE, CONTEST_TYPE_NPC_SUPER, ContestHall_EventScript_GetNumberOfHeartsSuper
	call_if_eq VAR_CONTEST_TYPE, CONTEST_TYPE_NPC_HYPER, ContestHall_EventScript_GetNumberOfHeartsHyper
	call_if_eq VAR_CONTEST_TYPE, CONTEST_TYPE_NPC_MASTER, ContestHall_EventScript_GetNumberOfHeartsMaster
	call_if_eq VAR_CONTEST_TYPE, CONTEST_TYPE_LINK, ContestHall_EventScript_GetNumberOfHeartsLink
	setvar VAR_TEMP_1, 9
	setvar VAR_TEMP_2, 9
	setvar VAR_TEMP_3, 9
	setvar VAR_TEMP_4, 9
	setvar VAR_TEMP_5, 9
	setvar VAR_TEMP_6, 9
	setvar VAR_TEMP_7, 9
	setvar VAR_TEMP_8, 9
	call_if_gt VAR_TEMP_0, 0, ContestHall_EventScript_DisplayHearts
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, 0
	setvar VAR_TEMP_3, 0
	setvar VAR_TEMP_4, 0
	setvar VAR_TEMP_5, 0
	setvar VAR_TEMP_6, 0
	setvar VAR_TEMP_7, 0
	setvar VAR_TEMP_8, 0
	return

ContestHall_EventScript_DisplayHearts::
	setvar VAR_RESULT, 8
	special GenerateContestRand
	call_if_eq VAR_RESULT, 0, ContestHall_EventScript_TryDisplayHeartAudienceMember1
	call_if_eq VAR_RESULT, 1, ContestHall_EventScript_TryDisplayHeartAudienceMember2
	call_if_eq VAR_RESULT, 2, ContestHall_EventScript_TryDisplayHeartAudienceMember3
	call_if_eq VAR_RESULT, 3, ContestHall_EventScript_TryDisplayHeartAudienceMember4
	call_if_eq VAR_RESULT, 4, ContestHall_EventScript_TryDisplayHeartAudienceMember5
	call_if_eq VAR_RESULT, 5, ContestHall_EventScript_TryDisplayHeartAudienceMember6
	call_if_eq VAR_RESULT, 6, ContestHall_EventScript_TryDisplayHeartAudienceMember7
	call_if_eq VAR_RESULT, 7, ContestHall_EventScript_TryDisplayHeartAudienceMember8
	goto_if_gt VAR_TEMP_0, 0, ContestHall_EventScript_DisplayHearts  @ Still more hearts to display
	waitmovement 0
	return

ContestHall_EventScript_GetNumberOfHeartsNormal::
	goto_if_gt VAR_0x8004, 80, ContestHall_EventScript_Set8Hearts
	goto_if_gt VAR_0x8004, 70, ContestHall_EventScript_Set7Hearts
	goto_if_gt VAR_0x8004, 60, ContestHall_EventScript_Set6Hearts
	goto_if_gt VAR_0x8004, 50, ContestHall_EventScript_Set5Hearts
	goto_if_gt VAR_0x8004, 40, ContestHall_EventScript_Set4Hearts
	goto_if_gt VAR_0x8004, 30, ContestHall_EventScript_Set3Hearts
	goto_if_gt VAR_0x8004, 20, ContestHall_EventScript_Set2Hearts
	goto_if_gt VAR_0x8004, 10, ContestHall_EventScript_Set1Heart
	setvar VAR_TEMP_0, 0
	return

ContestHall_EventScript_GetNumberOfHeartsSuper::
	goto_if_gt VAR_0x8004, 230, ContestHall_EventScript_Set8Hearts
	goto_if_gt VAR_0x8004, 210, ContestHall_EventScript_Set7Hearts
	goto_if_gt VAR_0x8004, 190, ContestHall_EventScript_Set6Hearts
	goto_if_gt VAR_0x8004, 170, ContestHall_EventScript_Set5Hearts
	goto_if_gt VAR_0x8004, 150, ContestHall_EventScript_Set4Hearts
	goto_if_gt VAR_0x8004, 130, ContestHall_EventScript_Set3Hearts
	goto_if_gt VAR_0x8004, 110, ContestHall_EventScript_Set2Hearts
	goto_if_gt VAR_0x8004, 90, ContestHall_EventScript_Set1Heart
	setvar VAR_TEMP_0, 0
	return

ContestHall_EventScript_GetNumberOfHeartsHyper::
	goto_if_gt VAR_0x8004, 380, ContestHall_EventScript_Set8Hearts
	goto_if_gt VAR_0x8004, 350, ContestHall_EventScript_Set7Hearts
	goto_if_gt VAR_0x8004, 320, ContestHall_EventScript_Set6Hearts
	goto_if_gt VAR_0x8004, 290, ContestHall_EventScript_Set5Hearts
	goto_if_gt VAR_0x8004, 260, ContestHall_EventScript_Set4Hearts
	goto_if_gt VAR_0x8004, 230, ContestHall_EventScript_Set3Hearts
	goto_if_gt VAR_0x8004, 200, ContestHall_EventScript_Set2Hearts
	goto_if_gt VAR_0x8004, 170, ContestHall_EventScript_Set1Heart
	setvar VAR_TEMP_0, 0
	return

ContestHall_EventScript_GetNumberOfHeartsMaster::
	goto_if_gt VAR_0x8004, 600, ContestHall_EventScript_Set8Hearts
	goto_if_gt VAR_0x8004, 560, ContestHall_EventScript_Set7Hearts
	goto_if_gt VAR_0x8004, 520, ContestHall_EventScript_Set6Hearts
	goto_if_gt VAR_0x8004, 480, ContestHall_EventScript_Set5Hearts
	goto_if_gt VAR_0x8004, 440, ContestHall_EventScript_Set4Hearts
	goto_if_gt VAR_0x8004, 400, ContestHall_EventScript_Set3Hearts
	goto_if_gt VAR_0x8004, 360, ContestHall_EventScript_Set2Hearts
	goto_if_gt VAR_0x8004, 320, ContestHall_EventScript_Set1Heart
	setvar VAR_TEMP_0, 0
	return

ContestHall_EventScript_GetNumberOfHeartsLink::
	goto_if_gt VAR_0x8004, 600, ContestHall_EventScript_Set8Hearts
	goto_if_gt VAR_0x8004, 550, ContestHall_EventScript_Set7Hearts
	goto_if_gt VAR_0x8004, 500, ContestHall_EventScript_Set6Hearts
	goto_if_gt VAR_0x8004, 450, ContestHall_EventScript_Set5Hearts
	goto_if_gt VAR_0x8004, 400, ContestHall_EventScript_Set4Hearts
	goto_if_gt VAR_0x8004, 300, ContestHall_EventScript_Set3Hearts
	goto_if_gt VAR_0x8004, 200, ContestHall_EventScript_Set2Hearts
	goto_if_gt VAR_0x8004, 100, ContestHall_EventScript_Set1Heart
	setvar VAR_TEMP_0, 0
	return

ContestHall_EventScript_Set1Heart::
	setvar VAR_TEMP_0, 1
	return

ContestHall_EventScript_Set2Hearts::
	setvar VAR_TEMP_0, 2
	return

ContestHall_EventScript_Set3Hearts::
	setvar VAR_TEMP_0, 3
	return

ContestHall_EventScript_Set4Hearts::
	setvar VAR_TEMP_0, 4
	return

ContestHall_EventScript_Set5Hearts::
	setvar VAR_TEMP_0, 5
	return

ContestHall_EventScript_Set6Hearts::
	setvar VAR_TEMP_0, 6
	return

ContestHall_EventScript_Set7Hearts::
	setvar VAR_TEMP_0, 7
	return

ContestHall_EventScript_Set8Hearts::
	setvar VAR_TEMP_0, 8
	return

ContestHall_EventScript_TryDisplayHeartAudienceMember1::
	goto_if_eq VAR_TEMP_1, 1, ContestHall_EventScript_AudienceMember1AlreadyEmoted
	applymovement LOCALID_CONTEST_AUDIENCE_1, ContestHall_Movement_Heart
	playse SE_PIN
	delay 14
	setvar VAR_TEMP_1, 1
	addvar VAR_TEMP_0, -1
	return

ContestHall_EventScript_AudienceMember1AlreadyEmoted::
	return

ContestHall_EventScript_TryDisplayHeartAudienceMember2::
	goto_if_eq VAR_TEMP_2, 1, ContestHall_EventScript_AudienceMember2AlreadyEmoted
	applymovement LOCALID_CONTEST_AUDIENCE_2, ContestHall_Movement_Heart
	playse SE_PIN
	delay 14
	setvar VAR_TEMP_2, 1
	addvar VAR_TEMP_0, -1
	return

ContestHall_EventScript_AudienceMember2AlreadyEmoted::
	return

ContestHall_EventScript_TryDisplayHeartAudienceMember3::
	goto_if_eq VAR_TEMP_3, 1, ContestHall_EventScript_AudienceMember3AlreadyEmoted
	applymovement LOCALID_CONTEST_AUDIENCE_3, ContestHall_Movement_Heart
	playse SE_PIN
	delay 14
	setvar VAR_TEMP_3, 1
	addvar VAR_TEMP_0, -1
	return

ContestHall_EventScript_AudienceMember3AlreadyEmoted::
	return

ContestHall_EventScript_TryDisplayHeartAudienceMember4::
	goto_if_eq VAR_TEMP_4, 1, ContestHall_EventScript_Audience4MemberAlreadyEmoted
	applymovement LOCALID_CONTEST_AUDIENCE_4, ContestHall_Movement_Heart
	playse SE_PIN
	delay 14
	setvar VAR_TEMP_4, 1
	addvar VAR_TEMP_0, -1
	return

ContestHall_EventScript_Audience4MemberAlreadyEmoted::
	return

ContestHall_EventScript_TryDisplayHeartAudienceMember5::
	goto_if_eq VAR_TEMP_5, 1, ContestHall_EventScript_AudienceMember5AlreadyEmoted
	applymovement LOCALID_CONTEST_AUDIENCE_5, ContestHall_Movement_Heart
	playse SE_PIN
	delay 14
	setvar VAR_TEMP_5, 1
	addvar VAR_TEMP_0, -1
	return

ContestHall_EventScript_AudienceMember5AlreadyEmoted::
	return

ContestHall_EventScript_TryDisplayHeartAudienceMember6::
	goto_if_eq VAR_TEMP_6, 1, ContestHall_EventScript_AudienceMember6AlreadyEmoted
	applymovement LOCALID_CONTEST_AUDIENCE_6, ContestHall_Movement_Heart
	playse SE_PIN
	delay 14
	setvar VAR_TEMP_6, 1
	addvar VAR_TEMP_0, -1
	return

ContestHall_EventScript_AudienceMember6AlreadyEmoted::
	return

ContestHall_EventScript_TryDisplayHeartAudienceMember7::
	goto_if_eq VAR_TEMP_7, 1, ContestHall_EventScript_AudienceMember7AlreadyEmoted
	applymovement LOCALID_CONTEST_AUDIENCE_7, ContestHall_Movement_Heart
	playse SE_PIN
	delay 14
	setvar VAR_TEMP_7, 1
	addvar VAR_TEMP_0, -1
	return

ContestHall_EventScript_AudienceMember7AlreadyEmoted::
	return

ContestHall_EventScript_TryDisplayHeartAudienceMember8::
	goto_if_eq VAR_TEMP_8, 1, ContestHall_EventScript_AudienceMember8AlreadyEmoted
	applymovement LOCALID_CONTEST_ARTIST, ContestHall_Movement_Heart
	playse SE_PIN
	delay 14
	setvar VAR_TEMP_8, 1
	addvar VAR_TEMP_0, -1
	return

ContestHall_EventScript_AudienceMember8AlreadyEmoted::
	return

ContestHall_EventScript_ContestantReturn::
	closemessage
	release
	removeobject LOCALID_CONTEST_POKEBALL
	special HideContestEntryMonPic
	call ContestHall_EventScript_TryWaitForLink
	switch VAR_0x8006
	case 0, ContestHall_EventScript_Player1WalkBack
	case 1, ContestHall_EventScript_Player2WalkBack
	case 2, ContestHall_EventScript_Player3WalkBack
	case 3, ContestHall_EventScript_Player4WalkBack
	return

ContestHall_EventScript_Player1WalkBack::
	call ContestHall_EventScript_TryWaitForLink
	lockall
	applymovement VAR_0x800B, ContestHall_Movement_Player1WalkBack
	waitmovement 0
	releaseall
	return

ContestHall_EventScript_Player2WalkBack::
	call ContestHall_EventScript_TryWaitForLink
	lockall
	applymovement VAR_0x800B, ContestHall_Movement_Player2WalkBack
	waitmovement 0
	releaseall
	return

ContestHall_EventScript_Player3WalkBack::
	call ContestHall_EventScript_TryWaitForLink
	lockall
	applymovement VAR_0x800B, ContestHall_Movement_Player3WalkBack
	waitmovement 0
	releaseall
	return

ContestHall_EventScript_Player4WalkBack::
	call ContestHall_EventScript_TryWaitForLink
	lockall
	applymovement VAR_0x800B, ContestHall_Movement_Player4WalkBack
	waitmovement 0
	releaseall
	return

ContestHall_EventScript_DoContestAppeals::
	lockall
	applymovement LOCALID_CONTEST_MC, ContestHall_Movement_FaceContestants2
	waitmovement 0
	call ContestHall_EventScript_TryWaitForLink
	call ContestHall_EventScript_LetsAppeal
	waitmessage
	applymovement LOCALID_CONTEST_MC, ContestHall_Movement_WalkStageLeft
	applymovement LOCALID_CONTEST_JUDGE, ContestHall_Movement_WalkStageRight
	waitmovement 0
	releaseall
	call ContestHall_EventScript_TryWaitForLink
	setvar VAR_TEMP_9, 1
	special LinkContestTryHideWirelessIndicator
	startcontest
	special LinkContestTryShowWirelessIndicator
	setvar VAR_TEMP_9, 0
	lockall
	applymovement LOCALID_CONTEST_MC, ContestHall_Movement_WalkStageRight
	applymovement LOCALID_CONTEST_JUDGE, ContestHall_Movement_WalkStageLeft
	waitmovement 0
	releaseall
	return

ContestHall_EventScript_LetsAppeal::
	goto_if_eq VAR_CONTEST_TYPE, CONTEST_TYPE_LINK, ContestHall_EventScript_LetsAppealLink
	msgbox ContestHall_Text_VotingCompleteLetsAppeal, MSGBOX_DEFAULT
	return

ContestHall_EventScript_LetsAppealLink::
	specialvar VAR_RESULT, IsWirelessContest
	goto_if_eq VAR_RESULT, TRUE, ContestHall_EventScript_LetsAppealWireless
	messageautoscroll ContestHall_Text_VotingCompleteLetsAppeal
	waitmessage
	return

ContestHall_EventScript_LetsAppealWireless::
	call ContestHall_EventScript_TryWaitForLink
	messageautoscroll ContestHall_Text_VotingComplete
	waitmessage
	call ContestHall_EventScript_TryWaitForLink
	messageautoscroll ContestHall_Text_SecondStageOfJudging
	waitmessage
	call ContestHall_EventScript_TryWaitForLink
	messageautoscroll ContestHall_Text_LetsAppeal
	waitmessage
	call ContestHall_EventScript_TryWaitForLink
	return

ContestHall_EventScript_ContestResults::
	call ContestHall_EventScript_TryWaitForLink
	call ContestHall_EventScript_ThatsItForJudging
	call ContestHall_EventScript_TryWaitForLink
	call ContestHall_EventScript_ThankYouForAppeals
	call ContestHall_EventScript_TryWaitForLink
	applymovement LOCALID_CONTEST_MC, ContestHall_Movement_MCFaceJudge
	waitmovement 0
	call ContestHall_EventScript_JudgeLooksReady
	call ContestHall_EventScript_TryWaitForLink
	call ContestHall_EventScript_WeWillDeclareWinner
	call ContestHall_EventScript_TryWaitForLink
	applymovement LOCALID_CONTEST_MC, ContestHall_Movement_FaceContestants
	waitmovement 0
	closemessage
	releaseall
	special LinkContestTryHideWirelessIndicator
	setvar VAR_TEMP_9, 1
	showcontestresults
	setvar VAR_TEMP_9, 0
	playbgm MUS_CONTEST_WINNER, FALSE
	return

ContestHall_EventScript_ThatsItForJudging::
	goto_if_eq VAR_CONTEST_TYPE, CONTEST_TYPE_LINK, ContestHall_EventScript_ThatsItForJudgingLink
	msgbox ContestHall_Text_ThatsItForJudging, MSGBOX_DEFAULT
	return

ContestHall_EventScript_ThatsItForJudgingLink::
	call ContestHall_EventScript_TryWaitForLink
	messageautoscroll ContestHall_Text_ThatsItForJudging
	waitmessage
	delay 30
	return

ContestHall_EventScript_ThankYouForAppeals::
	goto_if_eq VAR_CONTEST_TYPE, CONTEST_TYPE_LINK, ContestHall_EventScript_ThankYouForAppealsLink
	msgbox ContestHall_Text_ThankYouForAppeals, MSGBOX_DEFAULT
	return

ContestHall_EventScript_ThankYouForAppealsLink::
	call ContestHall_EventScript_TryWaitForLink
	messageautoscroll ContestHall_Text_ThankYouForAppeals
	waitmessage
	delay 30
	return

ContestHall_EventScript_JudgeLooksReady::
	goto_if_eq VAR_CONTEST_TYPE, CONTEST_TYPE_LINK, ContestHall_EventScript_JudgeLooksReadyLink
	msgbox ContestHall_Text_JudgeLooksReady, MSGBOX_DEFAULT
	return

ContestHall_EventScript_JudgeLooksReadyLink::
	call ContestHall_EventScript_TryWaitForLink
	messageautoscroll ContestHall_Text_JudgeLooksReady
	waitmessage
	delay 30
	return

ContestHall_EventScript_WeWillDeclareWinner::
	goto_if_eq VAR_CONTEST_TYPE, CONTEST_TYPE_LINK, ContestHall_EventScript_WeWillDeclareWinnerLink
	msgbox ContestHall_Text_WeWillNowDeclareWinner, MSGBOX_DEFAULT
	return

ContestHall_EventScript_WeWillDeclareWinnerLink::
	call ContestHall_EventScript_TryWaitForLink
	messageautoscroll ContestHall_Text_WeWillNowDeclareWinner
	waitmessage
	delay 30
	return

ContestHall_EventScript_GetWinnerObjEventId::
	special GetContestWinnerId
	switch VAR_0x8005
	case 0, ContestHall_EventScript_GetPlayer1ObjEventId
	case 1, ContestHall_EventScript_GetPlayer2ObjEventId
	case 2, ContestHall_EventScript_GetPlayer3ObjEventId
	case 3, ContestHall_EventScript_GetPlayer4ObjEventId
	return

ContestHall_EventScript_GetPlayer1ObjEventId::
	setvar VAR_TEMP_3, LOCALID_CONTESTANT_1
	return

ContestHall_EventScript_GetPlayer2ObjEventId::
	setvar VAR_TEMP_3, LOCALID_CONTESTANT_2
	return

ContestHall_EventScript_GetPlayer3ObjEventId::
	setvar VAR_TEMP_3, LOCALID_CONTESTANT_3
	return

ContestHall_EventScript_GetPlayer4ObjEventId::
	setvar VAR_TEMP_3, LOCALID_CONTESTANT_4
	return

ContestHall_EventScript_CongratulateWinner::
	special BufferContestWinnerTrainerName
	special BufferContestWinnerMonName
	addvar VAR_0x8005, 1
	buffernumberstring STR_VAR_2, VAR_0x8005
	addvar VAR_0x8005, -1
	call ContestHall_EventScript_CongratsWinner
	applymovement VAR_TEMP_3, ContestHall_Movement_WinningPlayerWalkUp
	waitmovement 0
	playse SE_M_ENCORE2
	setvar VAR_TEMP_1, 0
	return

ContestHall_EventScript_CongratsWinner::
	goto_if_eq VAR_CONTEST_TYPE, CONTEST_TYPE_LINK, ContestHall_EventScript_CongratsWinnerLink
	msgbox ContestHall_Text_CongratsTrainerXandMon, MSGBOX_DEFAULT
	return

ContestHall_EventScript_CongratsWinnerLink::
	messageautoscroll ContestHall_Text_CongratsTrainerXandMon
	waitmessage
	return

ContestHall_EventScript_AudienceLookAround::
	addvar VAR_TEMP_1, 1
	lockall
	call_if_gt VAR_CONTEST_TYPE, CONTEST_TYPE_NPC_NORMAL, ContestHall_EventScript_VObjectAudienceLookAround
	applymovement LOCALID_CONTEST_AUDIENCE_5, ContestHall_Movement_AudienceMemberLookRight
	applymovement LOCALID_CONTEST_AUDIENCE_2, ContestHall_Movement_AudienceMemberLookDown
	applymovement LOCALID_CONTEST_AUDIENCE_3, ContestHall_Movement_AudienceMemberLookRight
	delay 30
	applymovement LOCALID_CONTEST_AUDIENCE_6, ContestHall_Movement_AudienceMemberLookLeft
	applymovement LOCALID_CONTEST_AUDIENCE_7, ContestHall_Movement_AudienceMemberLookDown
	applymovement LOCALID_CONTEST_AUDIENCE_1, ContestHall_Movement_AudienceMemberLookUp
	applymovement LOCALID_CONTEST_AUDIENCE_4, ContestHall_Movement_AudienceMemberLookLeft
	goto_if_ne VAR_TEMP_1, 4, ContestHall_EventScript_AudienceLookAround
	delay 30
	return

ContestHall_EventScript_VObjectAudienceLookAround::
	turnvobject 0, DIR_SOUTH
	turnvobject 2, DIR_SOUTH
	turnvobject 4, DIR_EAST
	turnvobject 6, DIR_SOUTH
	turnvobject 8, DIR_SOUTH
	turnvobject 10, DIR_SOUTH
	turnvobject 12, DIR_SOUTH
	turnvobject 14, DIR_SOUTH
	turnvobject 16, DIR_SOUTH
	turnvobject 18, DIR_SOUTH
	turnvobject 20, DIR_EAST
	turnvobject 22, DIR_EAST
	turnvobject 25, DIR_EAST
	turnvobject 27, DIR_WEST
	turnvobject 28, DIR_EAST
	delay 10
	turnvobject 0, DIR_EAST
	turnvobject 2, DIR_EAST
	turnvobject 4, DIR_EAST
	turnvobject 6, DIR_EAST
	turnvobject 8, DIR_EAST
	turnvobject 10, DIR_WEST
	turnvobject 12, DIR_WEST
	turnvobject 14, DIR_WEST
	turnvobject 16, DIR_WEST
	turnvobject 18, DIR_WEST
	turnvobject 20, DIR_SOUTH
	turnvobject 22, DIR_SOUTH
	turnvobject 25, DIR_NORTH
	turnvobject 27, DIR_NORTH
	turnvobject 28, DIR_NORTH
	delay 10
	turnvobject 1, DIR_NORTH
	turnvobject 3, DIR_NORTH
	turnvobject 5, DIR_NORTH
	turnvobject 7, DIR_NORTH
	turnvobject 9, DIR_EAST
	turnvobject 11, DIR_NORTH
	turnvobject 15, DIR_NORTH
	turnvobject 13, DIR_NORTH
	turnvobject 17, DIR_NORTH
	turnvobject 19, DIR_NORTH
	turnvobject 21, DIR_WEST
	turnvobject 23, DIR_WEST
	turnvobject 24, DIR_WEST
	turnvobject 26, DIR_EAST
	turnvobject 29, DIR_WEST
	turnvobject 30, DIR_WEST
	delay 10
	turnvobject 1, DIR_EAST
	turnvobject 3, DIR_EAST
	turnvobject 5, DIR_EAST
	turnvobject 7, DIR_EAST
	turnvobject 9, DIR_EAST
	turnvobject 11, DIR_WEST
	turnvobject 15, DIR_WEST
	turnvobject 13, DIR_WEST
	turnvobject 17, DIR_WEST
	turnvobject 19, DIR_WEST
	turnvobject 21, DIR_SOUTH
	turnvobject 23, DIR_SOUTH
	turnvobject 24, DIR_SOUTH
	turnvobject 26, DIR_NORTH
	turnvobject 29, DIR_NORTH
	turnvobject 30, DIR_NORTH
	delay 10
	return

ContestHall_EventScript_GiveWinnerPrize::
	goto_if_eq VAR_CONTEST_TYPE, CONTEST_TYPE_LINK, ContestHall_EventScript_EndLinkContest
	call ContestHall_EventScript_CheckShouldSkipPrize
	goto_if_set FLAG_TEMP_2, ContestHall_EventScript_SkipPrize
	lockall
	msgbox ContestHall_Text_AcceptYourPrize, MSGBOX_DEFAULT
	releaseall
	call ContestHall_EventScript_WinnerApproachForPrize
	call ContestHall_EventScript_GivePrizeIfWinner
	playse SE_M_ENCORE2
	setvar VAR_TEMP_1, 0
	call ContestHall_EventScript_AudienceLookAround
	delay 30
	special ShouldReadyContestArtist
	goto_if_eq VAR_0x8004, TRUE, ContestHall_EventScript_SetReadyForContestArtist
	return

ContestHall_EventScript_SkipPrize::
	lockall
	msgbox ContestHall_Text_CongratsPleaseCompeteAgain, MSGBOX_DEFAULT
	releaseall
	delay 90
	special ShouldReadyContestArtist
	goto_if_eq VAR_0x8004, TRUE, ContestHall_EventScript_SetReadyForContestArtist
	return

ContestHall_EventScript_CheckShouldSkipPrize::
	specialvar VAR_RESULT, HasMonWonThisContestBefore
	goto_if_eq VAR_RESULT, TRUE, ContestHall_EventScript_CheckPlayerWon
	return

ContestHall_EventScript_CheckPlayerWon::
	special GetContestWinnerId
	goto_if_eq VAR_0x8005, 3, ContestHall_EventScript_CheckRankIsMaster
	return

ContestHall_EventScript_CheckRankIsMaster::
	goto_if_eq VAR_CONTEST_RANK, CONTEST_RANK_MASTER, ContestHall_EventScript_DontSkipPrize
	setflag FLAG_TEMP_2
	return

ContestHall_EventScript_DontSkipPrize::
	return

ContestHall_EventScript_SetReadyForContestArtist::
	setvar VAR_LILYCOVE_CONTEST_LOBBY_STATE, 1
	return

ContestHall_EventScript_EndLinkContest::
	delay 60
	special GetContestPlayerId
	special GetContestWinnerId
	special ShouldReadyContestArtist
	goto_if_eq VAR_0x8004, TRUE, ContestHall_EventScript_SetReadyForLinkContestArtist
	closemessage
	return

ContestHall_EventScript_SetReadyForLinkContestArtist::
	setvar VAR_LILYCOVE_CONTEST_LOBBY_STATE, 2
	return

@ Unused
ContestHall_EventScript_Ret::
	return

ContestHall_EventScript_WinnerApproachForPrize::
	switch VAR_0x8005
	case 0, ContestHall_EventScript_Player1ApproachForPrize
	case 1, ContestHall_EventScript_Player2ApproachForPrize
	case 2, ContestHall_EventScript_Player3ApproachForPrize
	case 3, ContestHall_EventScript_Player4ApproachForPrize
	return

ContestHall_EventScript_Player1ApproachForPrize::
	lockall
	applymovement VAR_TEMP_3, ContestHall_Movement_Player1ApproachForPrize
	waitmovement 0
	releaseall
	return

ContestHall_EventScript_Player2ApproachForPrize::
	lockall
	applymovement VAR_TEMP_3, ContestHall_Movement_Player2ApproachForPrize
	waitmovement 0
	releaseall
	return

ContestHall_EventScript_Player3ApproachForPrize::
	lockall
	applymovement VAR_TEMP_3, ContestHall_Movement_Player3ApproachForPrize
	waitmovement 0
	releaseall
	return

ContestHall_EventScript_Player4ApproachForPrize::
	lockall
	applymovement VAR_TEMP_3, ContestHall_Movement_Player4ApproachForPrize
	waitmovement 0
	releaseall
	return

@ In NPC Contests, the player is always entry 4 (id number 3)
ContestHall_EventScript_GivePrizeIfWinner::
	special GetContestWinnerId
	goto_if_eq VAR_0x8005, 3, ContestHall_EventScript_GiveContestPrizes
	lockall
	msgbox ContestHall_Text_CongratsPleaseCompeteAgain, MSGBOX_DEFAULT
	releaseall
	return

ContestHall_EventScript_GiveContestPrizes::
	specialvar VAR_RESULT, HasMonWonThisContestBefore
	goto_if_eq VAR_RESULT, FALSE, ContestHall_EventScript_ReceiveContestRibbon
	goto_if_eq VAR_CONTEST_RANK, CONTEST_RANK_MASTER, ContestHall_EventScript_GiveLuxuryBall
	lockall
	msgbox ContestHall_Text_CongratsPleaseCompeteAgain, MSGBOX_DEFAULT
	releaseall
	return

ContestHall_EventScript_NoRoomForLuxuryBall::
	lockall
	call Common_EventScript_BagIsFull
	msgbox ContestHall_Text_PickUpPrizeAtCounterLater, MSGBOX_DEFAULT
	releaseall
	setvar VAR_CONTEST_PRIZE_PICKUP, 4
	return

ContestHall_EventScript_GiveLuxuryBall::
	giveitem ITEM_LUXURY_BALL
	goto_if_eq VAR_RESULT, FALSE, ContestHall_EventScript_NoRoomForLuxuryBall
	lockall
	msgbox ContestHall_Text_CongratsPleaseCompeteAgain, MSGBOX_DEFAULT
	releaseall
	return

ContestHall_EventScript_ReceiveContestRibbon::
	special GiveMonContestRibbon
	incrementgamestat GAME_STAT_RECEIVED_RIBBONS
	setflag FLAG_SYS_RIBBON_GET
	lockall
	msgbox ContestHall_Text_ConferRibbonAsPrize, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	msgbox ContestHall_Text_ReceivedRibbon, MSGBOX_DEFAULT
	waitfanfare
	special BufferContestWinnerMonName
	msgbox ContestHall_Text_PutRibbonOnMon, MSGBOX_DEFAULT
	releaseall
	return

ContestHall_Movement_MCWalkDown:
	walk_down
	step_end

ContestHall_Movement_MCBackUp:
	lock_facing_direction
	walk_up
	unlock_facing_direction
	step_end

ContestHall_Movement_MCFaceJudge:
	walk_in_place_faster_right
	step_end

ContestHall_Movement_Heart:
	emote_heart
	step_end

ContestHall_Movement_FaceContestants:
	walk_in_place_faster_down
	step_end

ContestHall_Movement_WalkStageLeft:
	walk_left
	walk_left
	walk_in_place_faster_down
	step_end

ContestHall_Movement_WalkStageRight:
	walk_right
	walk_right
	walk_in_place_faster_down
	step_end

ContestHall_Movement_WinningPlayerWalkUp:
	walk_up
	walk_in_place_faster_down
	step_end

ContestHall_Movement_ContestantDelay32:
	delay_16
	delay_16
	step_end

ContestHall_Movement_MCFaceJudge2:
	walk_in_place_faster_right
	step_end

ContestHall_Movement_JudgeFaceMC:
	walk_in_place_faster_left
	step_end

ContestHall_Movement_FaceContestants2:
	walk_in_place_faster_down
	step_end

ContestHall_Movement_Player3ApproachForPrize:
	walk_left
	walk_left
	walk_up
	step_end

ContestHall_Movement_Player4ApproachForPrize:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

ContestHall_Movement_AudienceMemberLookLeft:
	face_left
	delay_16
	face_original_direction
	step_end

ContestHall_Movement_AudienceMemberLookUp:
	face_up
	delay_16
	face_original_direction
	step_end

ContestHall_Movement_AudienceMemberLookRight:
	face_right
	delay_16
	face_original_direction
	step_end

ContestHall_Movement_AudienceMemberLookDown:
	face_down
	delay_16
	face_original_direction
	step_end

ContestHall_Movement_Player4FaceUp:
	face_up
	step_end

ContestHall_Movement_MCLookAtJudge:
	face_up
	delay_16
	walk_in_place_faster_right
	step_end

ContestHall_Movement_JudgeLookAtMC:
	walk_in_place_faster_left
	delay_16
	delay_16
	walk_in_place_faster_down
	step_end

ContestHall_Movement_MCWalkInPlaceDown:
	delay_16
	delay_16
	walk_in_place_faster_down
	step_end

ContestHall_Movement_Player1WalkToCenter:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

ContestHall_Movement_Player1WalkBack:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_in_place_faster_up
	step_end

ContestHall_Movement_Player2WalkToCenter:
	walk_up
	walk_right
	walk_in_place_faster_up
	step_end

ContestHall_Movement_Player2WalkBack:
	walk_fast_left
	walk_fast_down
	walk_in_place_faster_up
	step_end

ContestHall_Movement_Player3WalkToCenter:
	walk_up
	walk_left
	walk_in_place_faster_up
	step_end

ContestHall_Movement_Player3WalkBack:
	walk_fast_right
	walk_fast_down
	walk_in_place_faster_up
	step_end

ContestHall_Movement_Player4WalkToCenter:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_up
	step_end

ContestHall_Movement_Player4WalkBack:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_in_place_faster_up
	step_end

ContestHall_Movement_Player1ApproachForPrize:
	walk_right
	walk_right
	walk_up
	step_end

ContestHall_Movement_Player2ApproachForPrize:
	walk_up
	step_end

@ IsContestWithRSPlayer has no side effect, so this is nop
ContestHall_EventScript_CheckIfContestWithRSPlayer::
	specialvar VAR_RESULT, IsContestWithRSPlayer
	goto_if_eq VAR_RESULT, TRUE, ContestHall_EventScript_RetRSPlayer
	return

ContestHall_EventScript_RetRSPlayer::
	return

LilycoveCity_ContestLobby_EventScript_DelayIfContestWithRSPlayer::
	specialvar VAR_RESULT, IsContestWithRSPlayer
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_ContestLobby_EventScript_DelayForRSPlayer
	return

LilycoveCity_ContestLobby_EventScript_DelayForRSPlayer::
	delay 9
	return

LilycoveCity_ContestLobby_Text_ReceptionDontHavePokeblockCase:
	.string "Xin chào!\p"
	.string "Đây là quầy tiếp tân của POKéMON\n"
	.string "CONTESTS.\p"
	.string "Ồ? Có vẻ bạn vẫn chưa có {POKEBLOCK}\n"
	.string "CASE.\p"
	.string "Nếu vậy, chúng tôi cần trao cho bạn thứ\n"
	.string "này!$"

LilycoveCity_ContestLobby_Text_NowThatWeveClearedThatUp:
	.string "Được rồi, vậy là chuyện đó đã xong...\p"
	.string "Xin chào!\p"
	.string "Đây là quầy tiếp tân của POKéMON\n"
	.string "CONTESTS.$"

LilycoveCity_ContestLobby_Text_ContestReception:
	.string "Xin chào!\p"
	.string "Đây là quầy tiếp tân của POKéMON\n"
	.string "CONTESTS.$"

@ Unused
LilycoveCity_ContestLobby_Text_CounterOnlyFor4PlayerContests:
	.string "Xin chào!\p"
	.string "Quầy tiếp tân này chỉ dành cho POKéMON\n"
	.string "CONTESTS 4 người chơi.$"

LilycoveCity_ContestLobby_Text_EnterContest1:
	.string "Bạn có muốn cho POKéMON của mình tham\n"
	.string "gia các cuộc thi của chúng tôi không?$"

LilycoveCity_ContestLobby_Text_WhichTopic1:
	.string "Bạn muốn tìm hiểu chủ đề nào?$"

LilycoveCity_ContestLobby_Text_ExplainContests:
	.string "Một POKéMON CONTEST gồm bốn HLV,\n"
	.string "mỗi người đưa một POKéMON vào tranh\l"
	.string "tài để được chấm điểm.\p"
	.string "Một cuộc thi có hai phần chấm điểm, phần\n"
	.string "đầu tiên và phần thứ hai.\p"
	.string "Phần chấm điểm đầu tiên là cuộc bình\n"
	.string "chọn độ yêu thích của khán giả.\p"
	.string "Trong phần chấm điểm thứ hai, các\n"
	.string "POKéMON dùng chiêu thức để biểu diễn.\p"
	.string "Hãy tính toán các màn biểu diễn cẩn\n"
	.string "thận để thu hút GIÁM KHẢO chú ý\l"
	.string "nhiều nhất và khiến khán giả phấn\l"
	.string "khích. Cố gắng hết sức để nổi bật.\p"
	.string "Điểm của hai phần sẽ được cộng lại khi\n"
	.string "kết thúc.\p"
	.string "POKéMON giành được số điểm cao nhất\n"
	.string "sẽ được tuyên bố là người chiến thắng.$"

LilycoveCity_ContestLobby_Text_ExplainContestTypes:
	.string "Có năm loại cuộc thi.\p"
	.string "Năm hạng mục là COOL, BEAUTY, CUTE,\n"
	.string "SMART và TOUGH.\p"
	.string "Hãy chọn cuộc thi phù hợp với POKéMON\n"
	.string "mà bạn định đăng ký.$"

LilycoveCity_ContestLobby_Text_ExplainContestRanks:
	.string "POKéMON CONTESTS có bốn hạng.\p"
	.string "Bốn hạng đó là NORMAL, SUPER, HYPER và\n"
	.string "MASTER.\p"
	.string "Ở hạng NORMAL, POKéMON nào cũng có thể\n"
	.string "tham gia.\p"
	.string "POKéMON thắng một cuộc thi hạng NORMAL\n"
	.string "có thể lên hạng SUPER ở cùng hạng mục.\p"
	.string "Tương tự, POKéMON thắng hạng SUPER có\n"
	.string "thể lên hạng HYPER, còn POKéMON thắng\l"
	.string "hạng HYPER có thể tiến lên hạng MASTER\l"
	.string "ở cùng hạng mục.\p"
	.string "POKéMON đã thắng hạng MASTER có thể\n"
	.string "tiếp tục thi đấu ở hạng MASTER bao\l"
	.string "nhiêu lần tùy ý HLV của nó.$"

LilycoveCity_ContestLobby_Text_EnterWhichRank:
	.string "Bạn muốn tham gia hạng nào?$"

LilycoveCity_ContestLobby_Text_EnterWhichContest1:
	.string "Bạn muốn tham gia cuộc thi nào?$"

LilycoveCity_ContestLobby_Text_EnterWhichPokemon1:
	.string "Bạn muốn đăng ký POKéMON nào?$"

LilycoveCity_ContestLobby_Text_MonNotQualifiedForRank:
	.string "Tôi rất xin lỗi, nhưng POKéMON của bạn\n"
	.string "vẫn chưa đủ điều kiện thi đấu ở hạng\l"
	.string "này...$"

LilycoveCity_ContestLobby_Text_EggCannotTakePart:
	.string "Tôi xin lỗi, nhưng EGG không thể tham\n"
	.string "gia POKéMON CONTEST.$"

LilycoveCity_ContestLobby_Text_MonInNoConditionForContest:
	.string "Có vẻ tình trạng hiện tại của POKéMON\n"
	.string "không cho phép nó tham gia cuộc thi...$"

LilycoveCity_ContestLobby_Text_AlreadyWonEnterAnyway:
	.string "Ồ, nhưng RIBBON đó...\p"
	.string "POKéMON của bạn đã từng thắng cuộc thi\n"
	.string "này rồi, phải không?\p"
	.string "Bạn vẫn muốn cho nó tham gia cuộc thi\n"
	.string "này chứ?$"

LilycoveCity_ContestLobby_Text_ConfirmContestMon:
	.string "Đó có phải POKéMON bạn muốn đưa vào\n"
	.string "cuộc thi không?$"

LilycoveCity_ContestLobby_Text_YourMonIsEntryNum4:
	.string "Được rồi, POKéMON của bạn sẽ được\n"
	.string "đăng ký vào cuộc thi này.\p"
	.string "POKéMON của bạn là thí sinh số 4.\n"
	.string "cuộc thi sẽ sớm bắt đầu.$"

LilycoveCity_ContestLobby_Text_ComeThroughHere:
	.string "Xin mời đi qua lối này. Chúc bạn may mắn!$"

LilycoveCity_ContestLobby_Text_PokemonWonWeHavePrize:
	.string "Xin chúc mừng! POKéMON của bạn là quán\n"
	.string "quân cuộc thi!\p"
	.string "Phần thưởng của bạn ở ngay đây. Xin\n"
	.string "mời đi lối này!$"

LilycoveCity_ContestLobby_Text_ComeBackForPrizeLater:
	.string "Vui lòng quay lại nhận phần thưởng sau.$"

ContestHall_Text_GettingStartedParticipantsAsFollows:
	.string "MC: Xin chào! Chúng ta sắp bắt đầu hạng\n"
	.string "{STR_VAR_3} của POKéMON\l"
	.string "{STR_VAR_2}!\p"
	.string "Các HLV tham gia cùng POKéMON của\n"
	.string "họ gồm có:$"

ContestHall_Text_GettingStartedParticipantsAsFollowsLink:
	.string "MC: Xin chào! Chúng ta sắp bắt đầu\n"
	.string "POKéMON {STR_VAR_2} liên kết\l"
	.string "dành cho 4 người chơi!\p"
	.string "Các HLV tham gia cùng POKéMON của\n"
	.string "họ gồm có:$"

ContestHall_Text_EntryXTrainersMon:
	.string "MC: Thí sinh số {STR_VAR_2}!\n"
	.string "POKéMON của {STR_VAR_1},\l"
	.string "{STR_VAR_3}!$"

ContestHall_Text_SeenContestantsAudienceWillVote:
	.string "MC: Chúng ta vừa gặp bốn POKéMON dự\n"
	.string "thi.\p"
	.string "Giờ là phần chấm điểm đầu tiên!\p"
	.string "Khán giả sẽ bình chọn POKéMON dự thi mà\n"
	.string "họ yêu thích nhất.\p"
	.string "Không để mọi người chờ thêm nữa, cuộc\n"
	.string "bình chọn xin bắt đầu!$"

ContestHall_Text_VotingUnderWay:
	.string "Đang bình chọn...$"

ContestHall_Text_VotingCompleteLetsAppeal:
	.string "Cuộc bình chọn đã kết thúc!\p"
	.string "Trong lúc kiểm phiếu, hãy chuyển sang\n"
	.string "phần chấm điểm thứ hai!\p"
	.string "Phần chấm điểm thứ hai chính là thời\n"
	.string "gian biểu diễn được mong đợi nhất!\p"
	.string "Mong các thí sinh làm chúng ta kinh\n"
	.string "ngạc bằng những màn biểu diễn xuất sắc\l"
	.string "với các chiêu thức mãn nhãn!\p"
	.string "Hãy thể hiện nhiệt huyết nào! Bắt đầu\n"
	.string "biểu diễn!$"

ContestHall_Text_ThatsItForJudging:
	.string "MC: Phần chấm điểm đến đây là kết thúc!$"

ContestHall_Text_ThankYouForAppeals:
	.string "Cảm ơn tất cả vì những màn biểu diễn vô\n"
	.string "cùng xuất sắc!\p"
	.string "Toàn bộ phần chấm điểm xin kết thúc tại\n"
	.string "đây! Cảm ơn những nỗ lực tuyệt vời của\l"
	.string "các bạn!$"

ContestHall_Text_JudgeLooksReady:
	.string "Giờ chỉ còn màn công bố người chiến\n"
	.string "thắng đầy nghẹt thở.\p"
	.string "Có vẻ GIÁM KHẢO đã sẵn sàng\n"
	.string "công bố kết quả!$"

ContestHall_Text_WeWillNowDeclareWinner:
	.string "GIÁM KHẢO: Bây giờ, chúng tôi sẽ\n"
	.string "người chiến thắng!$"

ContestHall_Text_CongratsTrainerXandMon:
	.string "MC: Thí sinh số {STR_VAR_2}!\p"
	.string "{STR_VAR_3} và\n"
	.string "{STR_VAR_1}, xin chúc mừng!$"

ContestHall_Text_CongratsPleaseCompeteAgain:
	.string "MC: Xin chúc mừng! Hãy tiếp tục tham gia\n"
	.string "nhé!$"

ContestHall_Text_AcceptYourPrize:
	.string "MC: Đây ạ! Xin hãy nhận phần thưởng!$"

ContestHall_Text_ConferRibbonAsPrize:
	.string "Chúng tôi xin trao RIBBON này làm phần\n"
	.string "thưởng cho bạn!$"

ContestHall_Text_ReceivedRibbon:
	.string "{PLAYER} đã nhận được một RIBBON.$"

ContestHall_Text_PutRibbonOnMon:
	.string "{PLAYER} đã đeo RIBBON cho\n"
	.string "{STR_VAR_1}.$"

ContestHall_Text_PickUpPrizeAtCounterLater:
	.string "Vui lòng đến quầy tiếp tân nhận phần\n"
	.string "thưởng sau. Hãy tiếp tục tham gia nhé!$"

@ Unused
ContestHall_Text_OnlyRegister4Players:
	.string "Tôi chỉ tiếp nhận đăng ký cho bốn\n"
	.string "người chơi trong POKéMON CONTESTS.\p"
	.string "Nếu ba người chơi khác kết nối, cả bốn\n"
	.string "người có thể tham gia cùng một\l"
	.string "cuộc thi.\p"
	.string "Bạn có muốn tham gia không?$"

LilycoveCity_ContestLobby_Text_ProgressWillBeSaved:
	.string "Trước khi tham gia cuộc thi, tiến trình\n"
	.string "của bạn sẽ được lưu.$"

LilycoveCity_ContestLobby_Text_ParticipateAnotherTime:
	.string "Hy vọng bạn sẽ tham gia vào dịp khác.$"

@ Unused
LilycoveCity_ContestLobby_Text_EnterContest2:
	.string "Bạn có muốn tham gia cuộc thi không?$"

@ Unused
LilycoveCity_ContestLobby_Text_Explain4PlayerContest:
	.string "Khi cả bốn người chơi đã sẵn sàng, vui\n"
	.string "lòng kết nối bằng Game Link cable rồi\l"
	.string "đăng ký với tôi.\p"
	.string "Hãy chọn cùng một cuộc thi với những\n"
	.string "người thi cùng bạn.\p"
	.string "cuộc thi sẽ bắt đầu ngay khi tất cả\n"
	.string "người chơi đăng ký xong.\p"
	.string "Sau đó, các quy tắc cuộc thi thông\n"
	.string "thường sẽ được áp dụng.$"

@ Unused
LilycoveCity_ContestLobby_Text_EnterWhichContest2:
	.string "Bạn muốn tham gia cuộc thi nào?$"

@ Unused
LilycoveCity_ContestLobby_Text_EnterWhichPokemon2:
	.string "Bạn muốn đăng ký POKéMON nào?$"

LilycoveCity_ContestLobby_Text_Transmitting:
	.string "Đang truyền dữ liệu...$"

LilycoveCity_ContestLobby_Text_TransmissionError:
	.string "Lỗi truyền dữ liệu...$"

LilycoveCity_ContestLobby_Text_PlayersChoseDifferentContest:
	.string "Có thể bạn đã chọn cuộc thi khác với\n"
	.string "một người chơi khác.$"

LilycoveCity_ContestLobby_Text_PlayersMadeDifferentChoice:
	.string "Có thể lựa chọn của bạn khác với một\n"
	.string "người chơi khác.$"

LilycoveCity_ContestLobby_Text_PleaseWaitBButtonCancel:
	.string "Vui lòng chờ. ... ... Nút B: Hủy$"

@ Unused
LilycoveCity_ContestLobby_Text_ParticipateAnotherTime2:
	.string "Hy vọng bạn sẽ tham gia vào dịp khác.$"

@ Unused
LilycoveCity_ContestLobby_Text_TransmissionErrorTryAgain:
	.string "Lỗi truyền dữ liệu. Vui lòng thử lại.$"

LilycoveCity_ContestLobby_Text_YourMonIsEntryNumX:
	.string "POKéMON của bạn sẽ được đăng ký vào\n"
	.string "cuộc thi.\p"
	.string "POKéMON của bạn là thí sinh số\n"
	.string "{STR_VAR_2}.$"

LilycoveCity_ContestLobby_Text_ContestBeginShortly:
	.string "cuộc thi sẽ sớm bắt đầu.$"

LilycoveCity_ContestLobby_Text_LinkContestReception:
	.string "Chào mừng! Đây là quầy tiếp tân liên\n"
	.string "kết của POKéMON CONTEST.\p"
	.string "Bạn có thể dự thi cùng một\n"
	.string "hoặc nhiều người bạn.$"

LilycoveCity_ContestLobby_Text_WhichTopic2:
	.string "Bạn muốn tìm hiểu chủ đề nào?$"

LilycoveCity_ContestLobby_Text_EnterContest3:
	.string "Bạn có muốn tham gia cuộc thi không?$"

LilycoveCity_ContestLobby_Text_EnterWhichContest3:
	.string "Bạn muốn tham gia cuộc thi nào?$"

LilycoveCity_ContestLobby_Text_MonInNoCondition2:
	.string "Có vẻ tình trạng hiện tại của POKéMON\n"
	.string "không cho phép nó tham gia cuộc thi...$"

LilycoveCity_ContestLobby_Text_EggCannotTakePart2:
	.string "Tôi xin lỗi, nhưng EGG không thể tham\n"
	.string "gia POKéMON CONTEST.$"

LilycoveCity_ContestLobby_Text_EnterWhichPokemon3:
	.string "Bạn muốn đăng ký POKéMON nào?$"

LilycoveCity_ContestLobby_Text_PleaseDecideLinkLeader:
	.string "Vui lòng quyết định ai trong số các bạn\n"
	.string "sẽ làm GROUP LEADER.\p"
	.string "Những người chơi khác sau đó phải\n"
	.string "chọn JOIN GROUP.$"

LilycoveCity_ContestLobby_Text_PlayerAt4PCounterUseGMode:
	.string "Có ít nhất một người chơi đã đăng ký\n"
	.string "qua quầy tiếp tân dành cho 4 người\l"
	.string "chơi.\p"
	.string "Cần có bốn người chơi kết nối bằng GBA\n"
	.string "Game Link cable.\p"
	.string "Khi cả bốn người đã sẵn sàng, hãy chọn\n"
	.string "G-MODE (GLOBAL MODE), rồi đăng ký tham\l"
	.string "gia lại.$"

LilycoveCity_ContestLobby_Text_ExplainLinkContest:
	.string "Đây là cuộc thi dành cho hai đến bốn\n"
	.string "người chơi kết nối bằng Wireless\l"
	.string "Adapter hoặc GBA Game Link cable.\p"
	.string "Trước tiên, người tham gia sẽ được\n"
	.string "yêu cầu chọn chế độ muốn tham gia.\p"
	.string "Có hai chế độ khác nhau.\p"
	.string "E-MODE (EMERALD MODE) dành cho hai đến\n"
	.string "bốn người chơi, mỗi người có một\l"
	.string "POKéMON Emerald Game Pak.\p"
	.string "G-MODE (GLOBAL MODE) chỉ dành cho bốn\n"
	.string "người chơi, mỗi người có một POKéMON\l"
	.string "Emerald, Ruby hoặc Sapphire Game Pak.\p"
	.string "Những người chơi nên bàn bạc chọn chế\n"
	.string "độ, rồi cùng chọn chế độ đó.\p"
	.string "Khi tất cả người chơi đã chọn cùng một\n"
	.string "cuộc thi trong cùng một chế độ, việc\l"
	.string "đăng ký tham gia sẽ hoàn tất.\p"
	.string "Sau đó, cuộc thi sẽ bắt đầu như bình\n"
	.string "thường.$"

LilycoveCity_ContestLobby_Text_ExplainEMode:
	.string "Trong E-MODE (EMERALD MODE), có thể tổ\n"
	.string "chức LINK cuộc thi cho hai đến bốn\l"
	.string "người chơi. Mỗi người chơi phải có một\l"
	.string "POKéMON Emerald Game Pak.\p"
	.string "Những người chơi phải kết nối với nhau\n"
	.string "bằng Wireless Adapters hoặc GBA Game\l"
	.string "Link cables.\p"
	.string "Nếu có ít hơn bốn người chơi, HLV\n"
	.string "trong sảnh sẽ tham gia để đủ đội hình\l"
	.string "cuộc thi 4 người.\p"
	.string "Xin lưu ý rằng E-MODE không dùng được\n"
	.string "trong POKéMON Ruby hoặc Sapphire.$"

LilycoveCity_ContestLobby_Text_ExplainGMode:
	.string "G-MODE (GLOBAL MODE) chỉ dành cho bốn\n"
	.string "người chơi kết nối bằng GBA Game Link\l"
	.string "cables.\p"
	.string "Mỗi người chơi phải có một POKéMON\n"
	.string "Emerald, Ruby hoặc Sapphire Game Pak.\p"
	.string "cuộc thi bắt đầu sau khi tất cả người\n"
	.string "chơi chọn G-MODE (POKéMON Emerald)\l"
	.string "hoặc đăng ký qua quầy tiếp tân dành\l"
	.string "cho 4 người chơi (POKéMON Ruby hoặc\l"
	.string "Sapphire).$"

LilycoveCity_ContestLobby_Text_NoWirelessAdapterInGMode:
	.string "Tôi rất xin lỗi.\p"
	.string "G-MODE không hoạt động với Wireless\n"
	.string "Adapters.\p"
	.string "Vui lòng chọn E-MODE hoặc thử lại bằng\n"
	.string "GBA Game Link cable.$"

LilycoveCity_ContestLobby_Text_WhichContestMode:
	.string "Bạn muốn tham gia cuộc thi MODE nào?$"

ContestHall_Text_GettingStartedWireless:
	.string "MC: Xin chào! Chúng ta sắp bắt đầu\n"
	.string "POKéMON {STR_VAR_2} liên kết\l"
	.string "dành cho 4 người chơi!$"

ContestHall_Text_ParticipantsAsFollows:
	.string "Các HLV tham gia cùng POKéMON của\n"
	.string "họ gồm có:$"

ContestHall_Text_WeveSeenContestants:
	.string "MC: Chúng ta vừa gặp bốn POKéMON dự\n"
	.string "thi.\p"
	.string "Giờ là phần chấm điểm đầu tiên!$"

ContestHall_Text_AudienceWillVote:
	.string "Khán giả sẽ bình chọn POKéMON dự thi mà\n"
	.string "họ yêu thích nhất.$"

ContestHall_Text_LetVotingBegin:
	.string "Không để mọi người chờ thêm nữa, cuộc\n"
	.string "bình chọn xin bắt đầu!$"

ContestHall_Text_VotingComplete:
	.string "Cuộc bình chọn đã kết thúc!\p"
	.string "Trong lúc kiểm phiếu, hãy chuyển sang\n"
	.string "phần chấm điểm thứ hai!$"

ContestHall_Text_SecondStageOfJudging:
	.string "Phần chấm điểm thứ hai chính là thời\n"
	.string "gian biểu diễn được mong đợi nhất!\p"
	.string "Mong các thí sinh làm chúng ta kinh\n"
	.string "ngạc bằng những màn biểu diễn xuất sắc\l"
	.string "với các chiêu thức mãn nhãn!$"

ContestHall_Text_LetsAppeal:
	.string "Nào, cho tôi thấy chút nhiệt huyết đi!\n"
	.string "Cùng phô diễn nào!$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global LilycoveCity_ContestLobby_Text_ReceptionDontHavePokeblockCase
	.global LilycoveCity_ContestLobby_Text_NowThatWeveClearedThatUp
	.global LilycoveCity_ContestLobby_Text_ContestReception
	.global LilycoveCity_ContestLobby_Text_CounterOnlyFor4PlayerContests
	.global LilycoveCity_ContestLobby_Text_EnterContest1
	.global LilycoveCity_ContestLobby_Text_WhichTopic1
	.global LilycoveCity_ContestLobby_Text_ExplainContests
	.global LilycoveCity_ContestLobby_Text_ExplainContestTypes
	.global LilycoveCity_ContestLobby_Text_ExplainContestRanks
	.global LilycoveCity_ContestLobby_Text_EnterWhichRank
	.global LilycoveCity_ContestLobby_Text_EnterWhichContest1
	.global LilycoveCity_ContestLobby_Text_EnterWhichPokemon1
	.global LilycoveCity_ContestLobby_Text_MonNotQualifiedForRank
	.global LilycoveCity_ContestLobby_Text_EggCannotTakePart
	.global LilycoveCity_ContestLobby_Text_MonInNoConditionForContest
	.global LilycoveCity_ContestLobby_Text_AlreadyWonEnterAnyway
	.global LilycoveCity_ContestLobby_Text_ConfirmContestMon
	.global LilycoveCity_ContestLobby_Text_YourMonIsEntryNum4
	.global LilycoveCity_ContestLobby_Text_ComeThroughHere
	.global LilycoveCity_ContestLobby_Text_PokemonWonWeHavePrize
	.global LilycoveCity_ContestLobby_Text_ComeBackForPrizeLater
	.global ContestHall_Text_GettingStartedParticipantsAsFollows
	.global ContestHall_Text_GettingStartedParticipantsAsFollowsLink
	.global ContestHall_Text_EntryXTrainersMon
	.global ContestHall_Text_SeenContestantsAudienceWillVote
	.global ContestHall_Text_VotingUnderWay
	.global ContestHall_Text_VotingCompleteLetsAppeal
	.global ContestHall_Text_ThatsItForJudging
	.global ContestHall_Text_ThankYouForAppeals
	.global ContestHall_Text_JudgeLooksReady
	.global ContestHall_Text_WeWillNowDeclareWinner
	.global ContestHall_Text_CongratsTrainerXandMon
	.global ContestHall_Text_CongratsPleaseCompeteAgain
	.global ContestHall_Text_AcceptYourPrize
	.global ContestHall_Text_ConferRibbonAsPrize
	.global ContestHall_Text_ReceivedRibbon
	.global ContestHall_Text_PutRibbonOnMon
	.global ContestHall_Text_PickUpPrizeAtCounterLater
	.global ContestHall_Text_OnlyRegister4Players
	.global LilycoveCity_ContestLobby_Text_ProgressWillBeSaved
	.global LilycoveCity_ContestLobby_Text_ParticipateAnotherTime
	.global LilycoveCity_ContestLobby_Text_EnterContest2
	.global LilycoveCity_ContestLobby_Text_Explain4PlayerContest
	.global LilycoveCity_ContestLobby_Text_EnterWhichContest2
	.global LilycoveCity_ContestLobby_Text_EnterWhichPokemon2
	.global LilycoveCity_ContestLobby_Text_Transmitting
	.global LilycoveCity_ContestLobby_Text_TransmissionError
	.global LilycoveCity_ContestLobby_Text_PlayersChoseDifferentContest
	.global LilycoveCity_ContestLobby_Text_PlayersMadeDifferentChoice
	.global LilycoveCity_ContestLobby_Text_PleaseWaitBButtonCancel
	.global LilycoveCity_ContestLobby_Text_ParticipateAnotherTime2
	.global LilycoveCity_ContestLobby_Text_TransmissionErrorTryAgain
	.global LilycoveCity_ContestLobby_Text_YourMonIsEntryNumX
	.global LilycoveCity_ContestLobby_Text_ContestBeginShortly
	.global LilycoveCity_ContestLobby_Text_LinkContestReception
	.global LilycoveCity_ContestLobby_Text_WhichTopic2
	.global LilycoveCity_ContestLobby_Text_EnterContest3
	.global LilycoveCity_ContestLobby_Text_EnterWhichContest3
	.global LilycoveCity_ContestLobby_Text_MonInNoCondition2
	.global LilycoveCity_ContestLobby_Text_EggCannotTakePart2
	.global LilycoveCity_ContestLobby_Text_EnterWhichPokemon3
	.global LilycoveCity_ContestLobby_Text_PleaseDecideLinkLeader
	.global LilycoveCity_ContestLobby_Text_PlayerAt4PCounterUseGMode
	.global LilycoveCity_ContestLobby_Text_ExplainLinkContest
	.global LilycoveCity_ContestLobby_Text_ExplainEMode
	.global LilycoveCity_ContestLobby_Text_ExplainGMode
	.global LilycoveCity_ContestLobby_Text_NoWirelessAdapterInGMode
	.global LilycoveCity_ContestLobby_Text_WhichContestMode
	.global ContestHall_Text_GettingStartedWireless
	.global ContestHall_Text_ParticipantsAsFollows
	.global ContestHall_Text_WeveSeenContestants
	.global ContestHall_Text_AudienceWillVote
	.global ContestHall_Text_LetVotingBegin
	.global ContestHall_Text_VotingComplete
	.global ContestHall_Text_SecondStageOfJudging
	.global ContestHall_Text_LetsAppeal
@ END GENERATED LOCALIZATION EXPORTS
