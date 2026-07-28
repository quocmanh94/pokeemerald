PacifidlogTown_House2_MapScripts::
	.byte 0

PacifidlogTown_House2_EventScript_FanClubYoungerBrother::
	lock
	faceplayer
	dotimebasedevents
	call PacifidlogTown_House2_EventScript_UpdateFanClubTMFlag
	goto_if_set FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK, PacifidlogTown_House2_EventScript_ComeBackInXDays
	call_if_set FLAG_MET_FANCLUB_YOUNGER_BROTHER, PacifidlogTown_House2_EventScript_MonAssessment
	call_if_unset FLAG_MET_FANCLUB_YOUNGER_BROTHER, PacifidlogTown_House2_EventScript_FirstMonAssessment
	setflag FLAG_MET_FANCLUB_YOUNGER_BROTHER
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_ge VAR_RESULT, FRIENDSHIP_150_TO_199, PacifidlogTown_House2_EventScript_GiveReturn
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_ge VAR_RESULT, FRIENDSHIP_50_TO_99, PacifidlogTown_House2_EventScript_PutInEffort
	goto PacifidlogTown_House2_EventScript_GiveFrustration
	end

PacifidlogTown_House2_EventScript_UpdateFanClubTMFlag::
	goto_if_unset FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK, Common_EventScript_NopReturn
	specialvar VAR_RESULT, GetDaysUntilPacifidlogTMAvailable
	call_if_eq VAR_RESULT, 0, PacifidlogTown_House2_EventScript_ClearReceivedFanClubTM
	return

PacifidlogTown_House2_EventScript_MonAssessment::
	msgbox PacifidlogTown_House2_Text_AhYourPokemon, MSGBOX_DEFAULT
	return

PacifidlogTown_House2_EventScript_FirstMonAssessment::
	msgbox PacifidlogTown_House2_Text_ChairmansYoungerBrotherOnVacation, MSGBOX_DEFAULT
	msgbox PacifidlogTown_House2_Text_AhYourPokemon, MSGBOX_DEFAULT
	return

PacifidlogTown_House2_EventScript_ClearReceivedFanClubTM::
	clearflag FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK
	return

PacifidlogTown_House2_EventScript_GiveReturn::
	msgbox PacifidlogTown_House2_Text_AdoringPokemonTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM_RETURN
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK
	special SetPacifidlogTMReceivedDay
	msgbox PacifidlogTown_House2_Text_ExplainReturnFrustration, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_PutInEffort::
	msgbox PacifidlogTown_House2_Text_PutInSomeMoreEffort, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_GiveFrustration::
	msgbox PacifidlogTown_House2_Text_ViciousPokemonTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM_FRUSTRATION
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK
	special SetPacifidlogTMReceivedDay
	msgbox PacifidlogTown_House2_Text_ExplainReturnFrustration, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_ComeBackInXDays::
	specialvar VAR_RESULT, GetDaysUntilPacifidlogTMAvailable
	buffernumberstring STR_VAR_1, VAR_RESULT
	msgbox PacifidlogTown_House2_Text_GetGoodTMInXDays, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_HappyAzurill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZURILL, CRY_MODE_NORMAL
	msgbox PacifidlogTown_House2_Text_Rurii, MSGBOX_DEFAULT
	waitmoncry
	msgbox PacifidlogTown_House2_Text_VeryFriendlyWithTrainer, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_UnhappyAzurill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZURILL, CRY_MODE_ENCOUNTER
	msgbox PacifidlogTown_House2_Text_Rururi, MSGBOX_DEFAULT
	waitmoncry
	msgbox PacifidlogTown_House2_Text_DoesntLikeTrainerVeryMuch, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_Text_ChairmansYoungerBrotherOnVacation:
	.string "Khụ khụ!\p"
	.string "Tôi là nhân vật quan trọng nhất của\n"
	.string "POKéMON FAN CLUB, em trai của CHỦ TỊCH.\p"
	.string "Tôi đang tận hưởng kỳ nghỉ cùng\n"
	.string "POKéMON tại đây, đúng vậy đấy.$"

PacifidlogTown_House2_Text_AhYourPokemon:
	.string "Ồ! POKéMON của cậu...$"

PacifidlogTown_House2_Text_AdoringPokemonTakeThis:
	.string "Rõ ràng nó rất yêu quý cậu.\p"
	.string "Một POKéMON vừa đáng yêu vừa quý mến\n"
	.string "cậu như thế xứng đáng nhận một TM thế\l"
	.string "này, phải không?$"

PacifidlogTown_House2_Text_PutInSomeMoreEffort:
	.string "Hừm... Không tệ, nhưng cũng chẳng tốt.\p"
	.string "Với tư cách HLV, cậu cần cố gắng\n"
	.string "thêm nữa.$"

PacifidlogTown_House2_Text_ViciousPokemonTakeThis:
	.string "Trông nó thật hung dữ.\p"
	.string "Một POKéMON đáng sợ như thế xứng\n"
	.string "đáng nhận một TM thế này.$"

PacifidlogTown_House2_Text_ExplainReturnFrustration:
	.string "Nếu một POKéMON rất quý mến cậu, sức\n"
	.string "mạnh của RETURN sẽ tăng lên.\p"
	.string "Nếu nó không quý cậu, sức mạnh của\n"
	.string "FRUSTRATION sẽ tăng.$"

PacifidlogTown_House2_Text_GetGoodTMInXDays:
	.string "À, phải rồi. Khoảng {STR_VAR_1}\n"
	.string "ngày nữa, tôi sẽ nhận được một hoặc\l"
	.string "hai TM tốt.\p"
	.string "Khi đó hãy đến gặp tôi. Tôi sẽ tặng cậu\n"
	.string "một TM phù hợp với POKéMON của cậu.$"

PacifidlogTown_House2_Text_Rurii:
	.string "AZURILL: Rurii.$"

PacifidlogTown_House2_Text_VeryFriendlyWithTrainer:
	.string "Có vẻ nó rất thân thiết với HLV.$"

PacifidlogTown_House2_Text_Rururi:
	.string "AZURILL: Rururi!$"

PacifidlogTown_House2_Text_DoesntLikeTrainerVeryMuch:
	.string "Có vẻ nó không quý HLV cho lắm.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global PacifidlogTown_House2_Text_ChairmansYoungerBrotherOnVacation
	.global PacifidlogTown_House2_Text_AhYourPokemon
	.global PacifidlogTown_House2_Text_AdoringPokemonTakeThis
	.global PacifidlogTown_House2_Text_PutInSomeMoreEffort
	.global PacifidlogTown_House2_Text_ViciousPokemonTakeThis
	.global PacifidlogTown_House2_Text_ExplainReturnFrustration
	.global PacifidlogTown_House2_Text_GetGoodTMInXDays
	.global PacifidlogTown_House2_Text_VeryFriendlyWithTrainer
	.global PacifidlogTown_House2_Text_DoesntLikeTrainerVeryMuch
@ END GENERATED LOCALIZATION EXPORTS
