SlateportCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SlateportCity_OnFrame
	.byte 0

SlateportCity_OnTransition:
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 0
	call SlateportCity_EventScript_EnterSlateport
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_MovePeopleForSternInterview
	call_if_eq VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1, SlateportCity_EventScript_SetReadyForScottScene
	end

SlateportCity_EventScript_EnterSlateport::
	setflag FLAG_VISITED_SLATEPORT_CITY
	setvar VAR_CONTEST_HALL_STATE, 0
	setflag FLAG_HIDE_SLATEPORT_CITY_CONTEST_REPORTER
	return

SlateportCity_EventScript_MovePeopleForSternInterview::
	setobjectxyperm LOCALID_SLATEPORT_CAPT_STERN, 28, 13
	setobjectxyperm LOCALID_SLATEPORT_OLD_WOMAN, 25, 13
	setobjectxyperm LOCALID_SLATEPORT_RICH_BOY, 25, 14
	setobjectxyperm LOCALID_SLATEPORT_COOK, 27, 16
	setobjectxyperm LOCALID_SLATEPORT_GIRL, 28, 16
	setobjectxyperm LOCALID_SLATEPORT_FAT_MAN, 29, 16
	setobjectxyperm LOCALID_SLATEPORT_MAN_1, 31, 14
	setobjectmovementtype LOCALID_SLATEPORT_CAPT_STERN, MOVEMENT_TYPE_FACE_DOWN
	setobjectmovementtype LOCALID_SLATEPORT_OLD_WOMAN, MOVEMENT_TYPE_FACE_DOWN_AND_RIGHT
	setobjectmovementtype LOCALID_SLATEPORT_RICH_BOY, MOVEMENT_TYPE_FACE_UP_AND_RIGHT
	setobjectmovementtype LOCALID_SLATEPORT_COOK, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_SLATEPORT_GIRL, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_SLATEPORT_FAT_MAN, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_SLATEPORT_MAN_1, MOVEMENT_TYPE_FACE_LEFT
	return

SlateportCity_EventScript_SetReadyForScottScene::
	setflag FLAG_HIDE_MAP_NAME_POPUP
	getplayerxy VAR_0x8004, VAR_0x8005
	goto_if_eq VAR_0x8004, 30, SlateportCity_EventScript_MoveScottLeft
	setobjectxyperm LOCALID_SLATEPORT_SCOTT, 23, 27
	setobjectmovementtype LOCALID_SLATEPORT_SCOTT, MOVEMENT_TYPE_FACE_RIGHT
	return

SlateportCity_EventScript_MoveScottLeft::
	setobjectxyperm LOCALID_SLATEPORT_SCOTT, 22, 27
	setobjectmovementtype LOCALID_SLATEPORT_SCOTT, MOVEMENT_TYPE_FACE_RIGHT
	return

SlateportCity_OnFrame:
	map_script_2 VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1, SlateportCity_EventScript_ScottScene
	.2byte 0

SlateportCity_EventScript_ScottScene::
	lockall
	addobject LOCALID_SLATEPORT_SCOTT
	applymovement LOCALID_PLAYER, SlateportCity_Movement_PlayerFaceScott
	applymovement LOCALID_SLATEPORT_SCOTT, SlateportCity_Movement_ScottApproachPlayer
	waitmovement 0
	msgbox SlateportCity_Text_YouDroveTeamAquaAway, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_SCOTT, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	delay 60
	msgbox SlateportCity_Text_MaybeThisTrainer, MSGBOX_DEFAULT
	applymovement LOCALID_SLATEPORT_SCOTT, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox SlateportCity_Text_LetsRegisterEachOther, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox SlateportCity_Text_RegisteredScott, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_SCOTT_MATCH_CALL
	msgbox SlateportCity_Text_KeepEyeOnTrainersBeSeeingYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_SCOTT, SlateportCity_Movement_ScottExit
	waitmovement 0
	removeobject LOCALID_SLATEPORT_SCOTT
	setobjectxyperm LOCALID_SLATEPORT_SCOTT, 10, 12
	setobjectmovementtype LOCALID_SLATEPORT_SCOTT, MOVEMENT_TYPE_FACE_DOWN
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 2
	addvar VAR_SCOTT_STATE, 1
	releaseall
	end

SlateportCity_Movement_PlayerFaceScott:
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

SlateportCity_Movement_ScottApproachPlayer:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_Movement_ScottExit:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SlateportCity_EventScript_EnergyGuru::
	lock
	faceplayer
	message SlateportCity_Text_EnergyGuruSellWhatYouNeed
	waitmessage
	pokemart SlateportCity_Pokemart_EnergyGuru
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_Pokemart_EnergyGuru:
	.2byte ITEM_PROTEIN
	.2byte ITEM_IRON
	.2byte ITEM_CARBOS
	.2byte ITEM_ZINC
	.2byte ITEM_CALCIUM
	.2byte ITEM_HP_UP
	pokemartlistend

SlateportCity_EventScript_EffortRibbonWoman::
	lock
	faceplayer
	bufferleadmonspeciesname STR_VAR_1
	msgbox SlateportCity_Text_OhYourPokemon, MSGBOX_DEFAULT
	specialvar VAR_RESULT, LeadMonHasEffortRibbon
	call_if_eq VAR_RESULT, TRUE, SlateportCity_EventScript_MonHasEffortRibbon
	specialvar VAR_RESULT, Special_AreLeadMonEVsMaxedOut
	call_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_MonEVsNotMaxed
	msgbox SlateportCity_Text_PleaseGiveItThisEffortRibbon, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message SlateportCity_Text_ReceivedEffortRibbon
	waitfanfare
	msgbox SlateportCity_Text_PutEffortRibbonOnMon, MSGBOX_DEFAULT
	special GiveLeadMonEffortRibbon
	release
	end

SlateportCity_EventScript_MonEVsNotMaxed::
	msgbox SlateportCity_Text_GoForItLittleHarder, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_MonHasEffortRibbon::
	msgbox SlateportCity_Text_EffortRibbonLooksGoodOnIt, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Cook::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_CookSternInterview
	msgbox SlateportCity_Text_SeaweedFullOfLife, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_CookSternInterview::
	msgbox SlateportCity_Text_CaptainComeBackWithBigFish, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_OldWoman::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_OldWomanSternInterview
	msgbox SlateportCity_Text_HowTownIsBornAndGrows, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_OldWomanSternInterview::
	msgbox SlateportCity_Text_CaptSternBeingInterviewed, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Girl::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_GirlSternInterview
	goto_if_set FLAG_RECEIVED_SECRET_POWER, SlateportCity_EventScript_GirlSecretBase
	msgbox SlateportCity_Text_SlateportWonderfulPlace, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_GirlSternInterview::
	msgbox SlateportCity_Text_InterviewerSoCool, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_GirlSecretBase::
	msgbox SlateportCity_Text_BuyBricksSoDecorWontGetDirty, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_RichBoy::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_RichBoySternInterview
	msgbox SlateportCity_Text_GoingToCompeteInBattleTent, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_RichBoySternInterview::
	msgbox SlateportCity_Text_SternSaysDiscoveredSomething, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_FatMan::
	goto_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_FatManSternInterview
	msgbox SlateportCity_Text_BushedHikingFromMauville, MSGBOX_NPC
	end

SlateportCity_EventScript_FatManSternInterview::
	msgbox SlateportCity_Text_AmIOnTV, MSGBOX_SIGN
	end

SlateportCity_EventScript_Man1::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_Man1SternInterview
	msgbox SlateportCity_Text_EveryoneCallsHimCaptStern, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Man1SternInterview::
	msgbox SlateportCity_Text_CaptainsACelebrity, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Woman1::
	lock
	faceplayer
	goto_if_set FLAG_DOCK_REJECTED_DEVON_GOODS, SlateportCity_EventScript_Woman1AquaGone
	msgbox SlateportCity_Text_WhatsLongLineOverThere, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Woman1AquaGone::
	msgbox SlateportCity_Text_VisitedMuseumOften, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_BattleTentSign::
	msgbox SlateportCity_Text_BattleTentSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_SternsShipyardSign::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_EventScript_SternsShipyardFerryComplete
	goto_if_set FLAG_BADGE07_GET, SlateportCity_EventScript_SternsShipyardNearsCompletion
	msgbox SlateportCity_Text_SternsShipyardWantedSign, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_SternsShipyardNearsCompletion::
	msgbox SlateportCity_Text_SternsShipyardNearsCompletion, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_SternsShipyardFerryComplete::
	msgbox SlateportCity_Text_SternsShipyardFerryComplete, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_PokemonFanClubSign::
	msgbox SlateportCity_Text_PokemonFanClubSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_OceanicMuseumSign::
	msgbox SlateportCity_Text_OceanicMuseumSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_CitySign::
	msgbox SlateportCity_Text_CitySign, MSGBOX_SIGN
	end

SlateportCity_EventScript_MarketSign::
	msgbox SlateportCity_Text_MarketSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_HarborSign::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_EventScript_HarborSignFerryComplete
	msgbox SlateportCity_Text_HarborFerryUnderConstruction, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_HarborSignFerryComplete::
	msgbox SlateportCity_Text_HarborSign, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_NameRatersHouseSign::
	msgbox SlateportCity_Text_NameRatersHouseSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_Maniac::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_ManiacSternInterview
	msgbox SlateportCity_Text_GetNameRaterToHelpYou, MSGBOX_DEFAULT
	release
	end

@ Unclear if the text here was meant to be different, but its not
SlateportCity_EventScript_ManiacSternInterview::
	msgbox SlateportCity_Text_GetNameRaterToHelpYou, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Woman2::
	msgbox SlateportCity_Text_CantChangeTradeMonName, MSGBOX_NPC
	end

SlateportCity_EventScript_Sailor1::
	msgbox SlateportCity_Text_SeaIsSoWet, MSGBOX_NPC
	end

SlateportCity_EventScript_Sailor2::
	msgbox SlateportCity_Text_SinkOldBoats, MSGBOX_NPC
	end

SlateportCity_EventScript_PokefanF::
	msgbox SlateportCity_Text_BuyTooMuch, MSGBOX_NPC
	end

SlateportCity_EventScript_Man2::
	msgbox SlateportCity_Text_BattleTentBuiltRecently, MSGBOX_NPC
	end

SlateportCity_EventScript_AquaGrunt1::
	lock
	faceplayer
	msgbox SlateportCity_Text_QuitPushing, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt2::
	lock
	faceplayer
	msgbox SlateportCity_Text_AquaHasPolicy, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt3::
	lock
	faceplayer
	msgbox SlateportCity_Text_BossIsBrilliant, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt4::
	lock
	faceplayer
	msgbox SlateportCity_Text_WhatsNewSchemeIWonder, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt5::
	lock
	faceplayer
	msgbox SlateportCity_Text_ShouldTakeItAll, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_5, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt6::
	lock
	faceplayer
	msgbox SlateportCity_Text_DontButtIn, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_6, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt7::
	lock
	faceplayer
	msgbox SlateportCity_Text_RemindsMeOfLongLineForGames, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_7, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt8::
	lock
	faceplayer
	msgbox SlateportCity_Text_WhyAreWeLiningUp, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_8, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt9::
	lock
	faceplayer
	playse SE_PIN
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_Delay48
	waitmovement 0
	msgbox SlateportCity_Text_WhatDoYouWant, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_FaceOriginalDirection
	waitmovement 0
	applymovement LOCALID_SLATEPORT_GRUNT_9, SlateportCity_Movement_DelayAquaGrunt
	waitmovement 0
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_Text_IllReadSignForYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_FaceOriginalDirection
	waitmovement 0
	applymovement LOCALID_SLATEPORT_GRUNT_9, SlateportCity_Movement_DelayAquaGrunt
	waitmovement 0
	msgbox SlateportCity_Text_SaysSomethingLikeSeaIsEndless, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_FacePlayer
	waitmovement 0
	applymovement LOCALID_SLATEPORT_GRUNT_9, SlateportCity_Movement_DelayAquaGrunt
	waitmovement 0
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_Movement_DelayAquaGrunt:
	delay_16
	delay_16
	step_end

SlateportCity_EventScript_AquaGrunt10::
	msgbox SlateportCity_Text_ShouldveBroughtMyGameBoy, MSGBOX_SIGN
	end

SlateportCity_EventScript_AquaGrunt11::
	lock
	faceplayer
	msgbox SlateportCity_Text_HotSpringsAfterOperation, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_11, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_DollClerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemartdecoration SlateportCity_PokemartDecor_Dolls
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_PokemartDecor_Dolls:
	.2byte DECOR_AZURILL_DOLL
	.2byte DECOR_MARILL_DOLL
	.2byte DECOR_SKITTY_DOLL
	pokemartlistend

SlateportCity_EventScript_ComeBackWithSecretPower::
	msgbox gText_ComeBackWithSecretPower, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_DecorClerk::
	lock
	faceplayer
	goto_if_unset FLAG_RECEIVED_SECRET_POWER, SlateportCity_EventScript_ComeBackWithSecretPower
	message gText_HowMayIServeYou
	waitmessage
	pokemartdecoration SlateportCity_PokemartDecor
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_PokemartDecor:
	.2byte DECOR_RED_BRICK
	.2byte DECOR_BLUE_BRICK
	.2byte DECOR_YELLOW_BRICK
	.2byte DECOR_RED_BALLOON
	.2byte DECOR_BLUE_BALLOON
	.2byte DECOR_YELLOW_BALLOON
	.2byte DECOR_C_LOW_NOTE_MAT
	.2byte DECOR_D_NOTE_MAT
	.2byte DECOR_E_NOTE_MAT
	.2byte DECOR_F_NOTE_MAT
	.2byte DECOR_G_NOTE_MAT
	.2byte DECOR_A_NOTE_MAT
	.2byte DECOR_B_NOTE_MAT
	.2byte DECOR_C_HIGH_NOTE_MAT
	pokemartlistend

SlateportCity_EventScript_PowerTMClerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart SlateportCity_Pokemart_PowerTMs
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_Pokemart_PowerTMs:
	.2byte ITEM_TM_HIDDEN_POWER
	.2byte ITEM_TM_SECRET_POWER
	pokemartlistend

@ Scene with Capt Sterns interview and Team Aqua announcing plans to steal Submarine
SlateportCity_EventScript_CaptStern::
	lockall
	msgbox SlateportCity_Text_SternMoveAheadWithExploration, MSGBOX_DEFAULT
	msgbox SlateportCity_Text_GabbyWonderfulThanksForInterview, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GABBY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 10
	applymovement LOCALID_SLATEPORT_TY, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 25
	applymovement LOCALID_SLATEPORT_CAPT_STERN, SlateportCity_Movement_SternWatchGabbyAndTyExit
	applymovement LOCALID_PLAYER, SlateportCity_Movement_PlayerFaceStern
	applymovement LOCALID_SLATEPORT_GABBY, SlateportCity_Movement_GabbyExit
	applymovement LOCALID_SLATEPORT_TY, SlateportCity_Movement_TyExit
	waitmovement 0
	removeobject LOCALID_SLATEPORT_GABBY
	removeobject LOCALID_SLATEPORT_TY
	msgbox SlateportCity_Text_SternWhewFirstInterview, MSGBOX_DEFAULT
	applymovement LOCALID_SLATEPORT_CAPT_STERN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox SlateportCity_Text_OhPlayerWeMadeDiscovery, MSGBOX_DEFAULT
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	msgbox SlateportCity_Text_AquaWillAssumeControlOfSubmarine, MSGBOX_DEFAULT
	applymovement LOCALID_SLATEPORT_COOK, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_SLATEPORT_FAT_MAN, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_SLATEPORT_OLD_WOMAN, SlateportCity_Movement_OldWomanConcern
	applymovement LOCALID_SLATEPORT_RICH_BOY, Common_Movement_QuestionMark
	applymovement LOCALID_SLATEPORT_MAN_1, SlateportCity_Movement_ManConcern
	waitmovement 0
	applymovement LOCALID_SLATEPORT_CAPT_STERN, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox SlateportCity_Text_SternWhatWasAllThat, MSGBOX_DEFAULT
	playse SE_PIN
	applymovement LOCALID_SLATEPORT_CAPT_STERN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_SLATEPORT_CAPT_STERN, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_SLATEPORT_CAPT_STERN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox SlateportCity_Text_FromHarborTryingToTakeSub, MSGBOX_DEFAULT
	msgbox SlateportCity_Text_PleaseComeWithMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_CAPT_STERN, SlateportCity_Movement_SternEnterHarbor
	applymovement LOCALID_PLAYER, SlateportCity_Movement_PlayerEnterHarbor
	waitmovement 0
	removeobject LOCALID_SLATEPORT_CAPT_STERN
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_CAPTAIN_STERN
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_SUBMARINE_SHADOW
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_AQUA_GRUNT
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_ARCHIE
	setvar VAR_SLATEPORT_CITY_STATE, 2
	warp MAP_SLATEPORT_CITY_HARBOR, 11, 14
	waitstate
	releaseall
	end

SlateportCity_Movement_OldWomanConcern:
	delay_16
	delay_16
	emote_question_mark
	walk_in_place_faster_right
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

SlateportCity_Movement_ManConcern:
	emote_question_mark
	walk_in_place_faster_up
	delay_16
	walk_in_place_faster_down
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

SlateportCity_Movement_GabbyExit:
	delay_16
	walk_left
	walk_left
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SlateportCity_Movement_TyExit:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SlateportCity_Movement_Unused:
	walk_down
	walk_in_place_faster_up
	step_end

SlateportCity_Movement_SternEnterHarbor:
	walk_right
	walk_up
	walk_up
	set_invisible
	step_end

SlateportCity_Movement_SternWatchGabbyAndTyExit:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_down
	walk_left
	step_end

SlateportCity_Movement_PlayerEnterHarbor:
	walk_in_place_faster_right
	delay_16
	delay_16
	walk_right
	walk_up
	step_end

SlateportCity_Movement_PlayerFaceStern:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_down
	step_end

SlateportCity_EventScript_Ty::
	msgbox SlateportCity_Text_BigSmileForCamera, MSGBOX_SIGN
	end

SlateportCity_EventScript_Gabby::
	msgbox SlateportCity_Text_MostInvaluableExperience, MSGBOX_SIGN
	end

SlateportCity_EventScript_Man3::
	msgbox SlateportCity_Text_WonderIfLighthouseStartlesPokemon, MSGBOX_NPC
	end

SlateportCity_EventScript_BerryPowderClerk::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_POWDER_JAR, SlateportCity_EventScript_ReceivedPowderJar
	msgbox SlateportCity_Text_ExplainBerries, MSGBOX_DEFAULT
	giveitem ITEM_POWDER_JAR
	setflag FLAG_RECEIVED_POWDER_JAR
	msgbox SlateportCity_Text_ExplainBerryPowder, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_ReceivedPowderJar::
	setvar VAR_0x8004, 1
	specialvar VAR_RESULT, HasEnoughBerryPowder
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_ExplainBerryPowder
	msgbox SlateportCity_Text_BroughtMeSomeBerryPowder, MSGBOX_DEFAULT
	special DisplayBerryPowderVendorMenu
	goto SlateportCity_EventScript_ChooseBerryPowderItem
	end

SlateportCity_EventScript_ExplainBerryPowder::
	msgbox SlateportCity_Text_ExplainBerryPowder, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_ChooseBerryPowderItem::
	message SlateportCity_Text_ExchangeWhatWithIt
	waitmessage
	setvar VAR_0x8004, SCROLL_MULTI_BERRY_POWDER_VENDOR
	special ShowScrollableMultichoice
	switch VAR_RESULT
	case 0, SlateportCity_EventScript_EnergyPowder
	case 1, SlateportCity_EventScript_EnergyRoot
	case 2, SlateportCity_EventScript_HealPowder
	case 3, SlateportCity_EventScript_RevivalHerb
	case 4, SlateportCity_EventScript_Protein
	case 5, SlateportCity_EventScript_Iron
	case 6, SlateportCity_EventScript_Carbos
	case 7, SlateportCity_EventScript_Calcium
	case 8, SlateportCity_EventScript_Zinc
	case 9, SlateportCity_EventScript_HPUp
	case 10, SlateportCity_EventScript_PPUp
	case 11, SlateportCity_EventScript_CancelPowderItemSelect
	case MULTI_B_PRESSED, SlateportCity_EventScript_CancelPowderItemSelect
	end

SlateportCity_EventScript_EnergyPowder::
	bufferitemname STR_VAR_1, ITEM_ENERGY_POWDER
	setvar VAR_0x8008, ITEM_ENERGY_POWDER
	setvar VAR_0x8009, 50
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_EnergyRoot::
	bufferitemname STR_VAR_1, ITEM_ENERGY_ROOT
	setvar VAR_0x8008, ITEM_ENERGY_ROOT
	setvar VAR_0x8009, 80
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_HealPowder::
	bufferitemname STR_VAR_1, ITEM_HEAL_POWDER
	setvar VAR_0x8008, ITEM_HEAL_POWDER
	setvar VAR_0x8009, 50
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_RevivalHerb::
	bufferitemname STR_VAR_1, ITEM_REVIVAL_HERB
	setvar VAR_0x8008, ITEM_REVIVAL_HERB
	setvar VAR_0x8009, 300
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Protein::
	bufferitemname STR_VAR_1, ITEM_PROTEIN
	setvar VAR_0x8008, ITEM_PROTEIN
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Iron::
	bufferitemname STR_VAR_1, ITEM_IRON
	setvar VAR_0x8008, ITEM_IRON
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Carbos::
	bufferitemname STR_VAR_1, ITEM_CARBOS
	setvar VAR_0x8008, ITEM_CARBOS
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Calcium::
	bufferitemname STR_VAR_1, ITEM_CALCIUM
	setvar VAR_0x8008, ITEM_CALCIUM
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Zinc::
	bufferitemname STR_VAR_1, ITEM_ZINC
	setvar VAR_0x8008, ITEM_ZINC
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_HPUp::
	bufferitemname STR_VAR_1, ITEM_HP_UP
	setvar VAR_0x8008, ITEM_HP_UP
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_PPUp::
	bufferitemname STR_VAR_1, ITEM_PP_UP
	setvar VAR_0x8008, ITEM_PP_UP
	setvar VAR_0x8009, 3000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_CancelPowderItemSelect::
	msgbox SlateportCity_Text_ComeBackToTradeBerryPowder, MSGBOX_DEFAULT
	special RemoveBerryPowderVendorMenu
	release
	end

SlateportCity_EventScript_TryBuyBerryPowderItem::
	msgbox SlateportCity_Text_ExchangeBerryPowderForItem, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SlateportCity_EventScript_ChooseBerryPowderItem
	copyvar VAR_0x8004, VAR_0x8009
	specialvar VAR_RESULT, HasEnoughBerryPowder
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_NotEnoughBerryPowder
	giveitem VAR_0x8008
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_NoRoomForBerryPowderItem
	copyvar VAR_0x8004, VAR_0x8009
	special TakeBerryPowder
	special PrintPlayerBerryPowderAmount
	msgbox SlateportCity_Text_FineBerryPowderTradeSomethingElse, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_EventScript_ChooseBerryPowderItem
	msgbox SlateportCity_Text_WhenYouGetMoreBringItToMe, MSGBOX_DEFAULT
	special RemoveBerryPowderVendorMenu
	release
	end

SlateportCity_EventScript_NoRoomForBerryPowderItem::
	msgbox gText_TheBagIsFull, MSGBOX_DEFAULT
	special RemoveBerryPowderVendorMenu
	release
	end

SlateportCity_EventScript_NotEnoughBerryPowder::
	msgbox SlateportCity_Text_DontHaveEnoughBerryPowder, MSGBOX_DEFAULT
	goto SlateportCity_EventScript_ChooseBerryPowderItem
	end

SlateportCity_EventScript_ScottBattleTentScene::
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	opendoor 10, 12
	waitdooranim
	addobject LOCALID_SLATEPORT_SCOTT
	applymovement LOCALID_PLAYER, SlateportCity_Movement_PushPlayerDown
	applymovement LOCALID_SLATEPORT_SCOTT, SlateportCity_Movement_ScottExitBattleTent
	waitmovement 0
	closedoor 10, 12
	waitdooranim
	msgbox SlateportCity_Text_TakingBattleTentChallenge, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, SlateportCity_Movement_PlayerWatchScottExit
	applymovement LOCALID_SLATEPORT_SCOTT, SlateportCity_Movement_ScottExitAfterBattleTent
	waitmovement 0
	removeobject LOCALID_SLATEPORT_SCOTT
	addvar VAR_SCOTT_STATE, 1
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 3
	releaseall
	end

SlateportCity_Movement_PushPlayerDown:
	lock_facing_direction
	walk_down
	unlock_facing_direction
	step_end

SlateportCity_Movement_PlayerWatchScottExit:
	delay_16
	walk_in_place_faster_right
	step_end

SlateportCity_Movement_ScottExitBattleTent:
	delay_8
	walk_down
	step_end

SlateportCity_Movement_ScottExitAfterBattleTent:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_EventScript_BerryCrushRankingsSign::
	lockall
	special ShowBerryCrushRankings
	releaseall
	end

SlateportCity_Text_EnergyGuruSellWhatYouNeed:
	.string "Tôi là ENERGY GURU! Tôi sẽ dốc hết sức\n"
	.string "bán cho bạn những thứ bạn cần!$"

SlateportCity_Text_OhYourPokemon:
	.string "Ồ? {STR_VAR_1} của bạn...$"

SlateportCity_Text_PleaseGiveItThisEffortRibbon:
	.string "Đã nỗ lực phi thường!\p"
	.string "Để làm phần thưởng, hãy trao cho nó\n"
	.string "EFFORT RIBBON này.$"

SlateportCity_Text_ReceivedEffortRibbon:
	.string "{PLAYER} nhận được EFFORT RIBBON.$"

SlateportCity_Text_PutEffortRibbonOnMon:
	.string "{PLAYER} đeo EFFORT RIBBON cho\n"
	.string "{STR_VAR_1}.$"

SlateportCity_Text_GoForItLittleHarder:
	.string "Bạn cần cố gắng thêm một chút nữa.\p"
	.string "Nếu làm được, tôi sẽ tặng POKéMON của\n"
	.string "bạn một món đồ hay.$"

SlateportCity_Text_EffortRibbonLooksGoodOnIt:
	.string "Ồ! EFFORT RIBBON trông rất hợp với\n"
	.string "{STR_VAR_1} của bạn!$"

SlateportCity_Text_WonderIfLighthouseStartlesPokemon:
	.string "Ánh sáng từ ngọn hải đăng chiếu xa\n"
	.string "hàng chục dặm.\p"
	.string "Không biết nó có làm POKéMON dưới biển\n"
	.string "giật mình không.$"

SlateportCity_Text_SeaweedFullOfLife:
	.string "Ồ, nhìn này!\p"
	.string "Rong biển quanh đây thật tươi và tràn\n"
	.string "đầy sức sống.\p"
	.string "Trông nó cứ như có thể bật dậy tấn\n"
	.string "công vậy!$"

SlateportCity_Text_HowTownIsBornAndGrows:
	.string "Nơi nào nước trong lành, sản vật dồi\n"
	.string "dào sẽ tụ về.\p"
	.string "Nơi nào con người tụ họp, chẳng bao lâu\n"
	.string "sẽ hình thành chợ.\p"
	.string "Một thị trấn ra đời và phát triển như\n"
	.string "thế đấy.$"

SlateportCity_Text_SlateportWonderfulPlace:
	.string "Mua sắm giữa hương vị của biển cả...\p"
	.string "SLATEPORT đúng là một nơi tuyệt vời!$"

SlateportCity_Text_BuyBricksSoDecorWontGetDirty:
	.string "Nếu đặt DOLLS hoặc CUSHIONS xuống sàn,\n"
	.string "chúng sẽ bị bẩn.\p"
	.string "Tôi sẽ mua vài viên BRICKS để DOLLS và\n"
	.string "CUSHIONS không bị bẩn khi bày ra.$"

SlateportCity_Text_GoingToCompeteInBattleTent:
	.string "Gừừừừ! Tôi cũng sẽ tham gia thi đấu\n"
	.string "tại BATTLE TENT!\p"
	.string "Nhưng trước hết, tôi cần bắt vài\n"
	.string "POKéMON đã!$"

SlateportCity_Text_BushedHikingFromMauville:
	.string "Phù... Tôi kiệt sức rồi...\p"
	.string "Tôi đi bộ từ MAUVILLE CITY đến đây.\n"
	.string "Nhưng trời ơi, thành phố này rộng thật.\p"
	.string "Biết vậy tôi đã đi BIKE tới đây.$"

SlateportCity_Text_EveryoneCallsHimCaptStern:
	.string "STERN, người đã xây dựng MUSEUM, đồng\n"
	.string "thời cũng là trưởng nhóm thám hiểm\l"
	.string "dưới biển.\p"
	.string "Vì vậy, mọi người đều gọi ông ấy là\n"
	.string "CAPT. STERN.$"

SlateportCity_Text_WhatsLongLineOverThere:
	.string "Đằng kia có chuyện gì vậy? Hàng người\n"
	.string "dài đó...$"

SlateportCity_Text_VisitedMuseumOften:
	.string "Khi còn nhỏ, tôi thường xuyên đến\n"
	.string "MUSEUM.\p"
	.string "Sau khi xem các hiện vật trưng bày, tôi\n"
	.string "thường mơ về những bí ẩn của biển cả.$"

SlateportCity_Text_QuitPushing:
	.string "Này! Đừng chen lấn nữa! Không thấy đây\n"
	.string "là hàng sao?$"

SlateportCity_Text_AquaHasPolicy:
	.string "TEAM AQUA có quy định tập hợp và giải\n"
	.string "tán ngay tại địa điểm thực hiện nhiệm\l"
	.string "vụ.$"

SlateportCity_Text_BossIsBrilliant:
	.string "Thủ lĩnh của bọn ta rất tài giỏi.\p"
	.string "Không biết lần này ngài ấy muốn làm gì\n"
	.string "với MUSEUM?$"

SlateportCity_Text_WhatsNewSchemeIWonder:
	.string "Không biết kế hoạch mới là gì nhỉ?\p"
	.string "Thủ lĩnh rất đáng sợ khi nổi giận, nên\n"
	.string "nhất ta đừng làm hỏng việc...$"

SlateportCity_Text_ShouldTakeItAll:
	.string "Nếu MUSEUM có thứ bọn ta cần, cứ lấy\n"
	.string "sạch là được!$"

SlateportCity_Text_DontButtIn:
	.string "Này, ngươi kia! Đừng chen ngang!$"

SlateportCity_Text_RemindsMeOfLongLineForGames:
	.string "Một hàng người dài sao?\p"
	.string "Làm ta nhớ những lần xếp hàng mua các\n"
	.string "trò chơi đình đám...$"

SlateportCity_Text_WhyAreWeLiningUp:
	.string "Sao bọn ta còn phải xếp hàng rồi trả\n"
	.string "tiền chứ? Cứ xông thẳng vào là được!$"

SlateportCity_Text_WhatDoYouWant:
	.string "Gì? Ngươi muốn gì?$"

SlateportCity_Text_IllReadSignForYou:
	.string "Ngươi muốn đọc tấm biển này sao? Để ta\n"
	.string "đọc cho!$"

SlateportCity_Text_SaysSomethingLikeSeaIsEndless:
	.string "Để xem...\p"
	.string "Ờm... Ta nghĩ nó viết đại loại là sự sống\n"
	.string "trong biển cả không bao giờ kết thúc.\p"
	.string "Ừ, ta khá chắc là nó viết như vậy.$"

SlateportCity_Text_ShouldveBroughtMyGameBoy:
	.string "Lầm bầm...\p"
	.string "Lẽ ra ta nên mang theo Game Boy\n"
	.string "Advance để khỏi chán khi xếp hàng...\p"
	.string "Lầm bầm...$"

SlateportCity_Text_HotSpringsAfterOperation:
	.string "Khi nhiệm vụ này kết thúc, ta sẽ đưa\n"
	.string "các ngươi đi nghỉ ở suối nước nóng!\p"
	.string "Thủ lĩnh đã nói vậy đấy. Ta mong quá!$"

SlateportCity_Text_SeaIsSoWet:
	.string "Biển thật mênh mông...\p"
	.string "Có khi nào biển được tạo nên từ nước\n"
	.string "mắt của POKéMON không?$"

SlateportCity_Text_SinkOldBoats:
	.string "Bạn có biết người ta làm gì với những\n"
	.string "con tàu cũ kỹ đến mức không thể ra\l"
	.string "khơi không?\p"
	.string "Họ đánh chìm chúng xuống biển để biến\n"
	.string "chúng thành nơi sinh sống cho POKéMON.$"

SlateportCity_Text_BuyTooMuch:
	.string "Mỗi lần đến đây, tôi đều mải mê mua sắm\n"
	.string "rồi mua quá nhiều.$"

SlateportCity_Text_GetNameRaterToHelpYou:
	.string "Nếu muốn đổi biệt danh của POKéMON, bạn\n"
	.string "sẽ phải nhờ NAME RATER giúp đỡ.$"

SlateportCity_Text_CantChangeTradeMonName:
	.string "Bạn không thể đổi biệt danh của\n"
	.string "POKéMON nhận được qua trao đổi.\p"
	.string "Tình yêu mà HLV ban đầu dành cho\n"
	.string "POKéMON ấy nằm trong chính biệt danh\l"
	.string "đó.$"

SlateportCity_Text_BattleTentBuiltRecently:
	.string "Gần đây, một BATTLE TENT đã được xây\n"
	.string "dựng tại SLATEPORT.\p"
	.string "GYMS rất vui, nhưng BATTLE TENT cũng\n"
	.string "thú vị theo cách riêng.\p"
	.string "Bạn nên đi tìm những POKéMON mạnh để\n"
	.string "tham gia BATTLE TENT!$"

SlateportCity_Text_CaptSternBeingInterviewed:
	.string "Tôi cứ hy vọng đó là một ngôi sao nổi\n"
	.string "tiếng để còn xin chữ ký.\p"
	.string "Nhưng người đang được phỏng vấn là ai\n"
	.string "vậy? Chẳng phải CAPT. STERN sao?$"

SlateportCity_Text_InterviewerSoCool:
	.string "Chị phóng viên đó vừa xinh đẹp vừa\n"
	.string "ngầu quá.\p"
	.string "Khi lớn lên, tôi sẽ trở thành một nhà\n"
	.string "báo quốc tế!$"

SlateportCity_Text_SternSaysDiscoveredSomething:
	.string "CAPT. STERN nói họ đã phát hiện thứ gì\n"
	.string "đó dưới đáy biển.\p"
	.string "Không biết đó là gì nhỉ? Có thể là thứ\n"
	.string "gì đây?$"

SlateportCity_Text_CaptainComeBackWithBigFish:
	.string "Ở đây có chuyện gì vậy?\p"
	.string "Vị CAPTAIN đáng kính đã mang về một\n"
	.string "con cá lớn từ đáy đại dương sao?$"

SlateportCity_Text_AmIOnTV:
	.string "Này! Bạn đang xem chứ? Tôi có lên TV\n"
	.string "không?$"

SlateportCity_Text_CaptainsACelebrity:
	.string "Một cuộc phỏng vấn trên TV! Ngay tại\n"
	.string "đây! CAPTAIN đúng là người nổi tiếng!$"

SlateportCity_Text_BigSmileForCamera:
	.string "TY: Được rồi, CAPT. STERN, hãy cười\n"
	.string "thật tươi trước máy quay!$"

SlateportCity_Text_MostInvaluableExperience:
	.string "GABBY: Tôi hiểu rồi. Ông đã có một trải\n"
	.string "nghiệm vô cùng quý giá...$"

SlateportCity_Text_SternMoveAheadWithExploration:
	.string "CAPT. STERN: Đúng vậy. Chúng tôi dự\n"
	.string "định tiếp tục công cuộc thám hiểm.$"

SlateportCity_Text_GabbyWonderfulThanksForInterview:
	.string "GABBY: Thật tuyệt vời, CAPT. STERN! Cảm\n"
	.string "ơn ông đã dành thời gian trong lịch\l"
	.string "trình bận rộn để trò chuyện với chúng\l"
	.string "tôi.\p"
	.string "Hy vọng chúng tôi có thể phỏng vấn ông\n"
	.string "lần nữa khi có thêm tin tức về những\l"
	.string "khám phá mới!$"

SlateportCity_Text_SternWhewFirstInterview:
	.string "CAPT. STERN: Phù...\p"
	.string "Đây là lần đầu tiên tôi được quay hình\n"
	.string "cho TV. Căng thẳng thật đấy.$"

SlateportCity_Text_OhPlayerWeMadeDiscovery:
	.string "Ồ! {PLAYER}{KUN}! Trông cháu khỏe lắm!\p"
	.string "Trong chuyến thám hiểm đáy biển vừa\n"
	.string "rồi, chúng tôi đã có một phát hiện rất\l"
	.string "lớn.\p"
	.string "Chúng tôi tìm thấy một hang động dưới\n"
	.string "nước ở ROUTE 128.\p"
	.string "Chúng tôi cho rằng đó là nơi sinh sống\n"
	.string "của một POKéMON được cho là đã tuyệt\l"
	.string "chủng từ lâu.$"

SlateportCity_Text_AquaWillAssumeControlOfSubmarine:
	.string "Fufufu... Hẳn ông là CAPT. STERN.\p"
	.string "TEAM AQUA bọn ta sẽ tiếp quản tàu ngầm\n"
	.string "của ông!\p"
	.string "Phản đối cũng vô ích! Bọn ta yêu cầu\n"
	.string "ông hợp tác hoàn toàn!\p"
	.string "Fufufu... Cứ nhìn cho kỹ và xem TEAM\n"
	.string "AQUA đã lên kế hoạch gì!$"

SlateportCity_Text_SternWhatWasAllThat:
	.string "CAPT. STERN: Chuyện vừa rồi là sao?\p"
	.string "Nghe như có ai đó đang dùng loa phóng\n"
	.string "thanh...\p"
	.string "Âm thanh phát ra từ đâu vậy?$"

SlateportCity_Text_FromHarborTryingToTakeSub:
	.string "Từ HARBOR!\p"
	.string "Chiếc tàu ngầm! Chúng đang định cướp\n"
	.string "nó!$"

SlateportCity_Text_PleaseComeWithMe:
	.string "{PLAYER}{KUN}! Xin hãy đi cùng tôi!$"

SlateportCity_Text_BattleTentSign:
	.string "BATTLE TENT SLATEPORT SITE “Hãy tìm\n"
	.string "ra! POKéMON tuyệt đỉnh!”$"

SlateportCity_Text_SternsShipyardWantedSign:
	.string "STERN'S SHIPYARD\p"
	.string "“Tuyển: Một thủy thủ có thể vượt qua\n"
	.string "mọi dòng hải lưu.”$"

SlateportCity_Text_SternsShipyardNearsCompletion:
	.string "STERN'S SHIPYARD\p"
	.string "“Phà S.S. TIDAL sắp được hoàn thành để\n"
	.string "phục vụ các cảng SLATEPORT và\l"
	.string "LILYCOVE.”$"

SlateportCity_Text_SternsShipyardFerryComplete:
	.string "STERN'S SHIPYARD\p"
	.string "“Việc lên phà S.S. TIDAL tuyến\n"
	.string "SLATEPORT-LILYCOVE được thực hiện\l"
	.string "tại HARBOR.”$"

SlateportCity_Text_PokemonFanClubSign:
	.string "POKéMON FAN CLUB “Kêu gọi tất cả người\n"
	.string "hâm mộ POKéMON!”$"

SlateportCity_Text_OceanicMuseumSign:
	.string "“Biển cả vô tận nuôi dưỡng mọi sự\n"
	.string "sống.”\p"
	.string "OCEANIC MUSEUM$"

SlateportCity_Text_CitySign:
	.string "SLATEPORT CITY\p"
	.string "“Bến cảng nơi con người và POKéMON\n"
	.string "gặp gỡ nhau.”$"

SlateportCity_Text_MarketSign:
	.string "SLATEPORT MARKET “Những món hàng độc\n"
	.string "đáo không nơi nào khác có!”$"

SlateportCity_Text_HarborFerryUnderConstruction:
	.string "SLATEPORT HARBOR\p"
	.string "“Phà S.S. TIDAL đang được đóng tại\n"
	.string "SHIPYARD.\p"
	.string "“Dịch vụ dự kiến sẽ sớm đi vào hoạt\n"
	.string "động.”$"

SlateportCity_Text_HarborSign:
	.string "SLATEPORT HARBOR\p"
	.string "“Hãy tận hưởng chuyến du ngoạn thú vị\n"
	.string "trên phà S.S. TIDAL.”$"

SlateportCity_Text_NameRatersHouseSign:
	.string "NAME RATER'S HOUSE “Chuyên đánh giá\n"
	.string "biệt danh POKéMON.”$"

SlateportCity_Text_ExplainBerries:
	.string "Khi POKéMON hoang dã bị thương, chúng\n"
	.string "sẽ nhai BERRIES để tự hồi phục.\p"
	.string "Cháu có biết không?\p"
	.string "Có người nhìn thấy vậy và nảy ra ý\n"
	.string "tưởng chế thuốc từ BERRIES.\p"
	.string "Cháu có biết không?\p"
	.string "Muốn biến BERRIES thành thuốc thì phải\n"
	.string "nghiền chúng thành bột.\p"
	.string "Cháu có biết không?\p"
	.string "Có vẻ cháu rất quan tâm đến BERRIES!\p"
	.string "Ta có thứ này rất hợp với người như\n"
	.string "cháu.$"

SlateportCity_Text_ExplainBerryPowder:
	.string "Gần đây ta đã cho lắp máy nghiền\n"
	.string "BERRIES tại các POKéMON CENTERS.\p"
	.string "Máy BERRY CRUSH nằm ở DIRECT CORNER\n"
	.string "trên tầng.\p"
	.string "Cháu có biết không?\p"
	.string "Cháu có thể dùng những chiếc máy đó\n"
	.string "làm BERRY POWDER cho ta không?\p"
	.string "Nếu cháu mang thật nhiều BERRY POWDER\n"
	.string "đến, ta có thể chế đủ loại thuốc cho\l"
	.string "cháu.$"

SlateportCity_Text_BroughtMeSomeBerryPowder:
	.string "Cháu có mang BERRY POWDER đến cho ta\n"
	.string "không?$"

SlateportCity_Text_ExchangeWhatWithIt:
	.string "Cháu muốn đổi lấy thứ gì?$"

SlateportCity_Text_ExchangeBerryPowderForItem:
	.string "Được rồi, cháu muốn đổi BERRY POWDER\n"
	.string "lấy một {STR_VAR_1} phải không?$"

SlateportCity_Text_DontHaveEnoughBerryPowder:
	.string "Ôi chao. Cháu không có đủ BERRY POWDER.$"

SlateportCity_Text_FineBerryPowderTradeSomethingElse:
	.string "BERRY POWDER này có chất lượng rất\n"
	.string "tốt. Nó sẽ tạo ra loại thuốc tuyệt hảo.\p"
	.string "Cháu có muốn đổi thêm BERRY POWDER lấy\n"
	.string "thứ khác không?$"

SlateportCity_Text_WhenYouGetMoreBringItToMe:
	.string "Được rồi! Khi có thêm BERRY POWDER,\n"
	.string "nhớ mang đến cho ta nhé!$"

SlateportCity_Text_ComeBackToTradeBerryPowder:
	.string "Hãy quay lại nếu cháu muốn đổi BERRY\n"
	.string "POWDER lấy thuốc.\p"
	.string "Ta luôn mở quầy trao đổi ở đây.\p"
	.string "Cháu có biết không?$"

SlateportCity_Text_YouDroveTeamAquaAway:
	.string "SCOTT: Hả? Tôi chắc chắn đã từng gặp\n"
	.string "cậu ở đâu đó rồi.\p"
	.string "Tôi đã giới thiệu bản thân chưa nhỉ?\n"
	.string "Nếu chưa thì tôi tên là SCOTT.\p"
	.string "Tôi vừa thấy TEAM AQUA tháo chạy khỏi\n"
	.string "đây như bị ong chích.\p"
	.string "Để tôi đoán nhé, chính cậu đã đuổi\n"
	.string "chúng đi phải không?$"

SlateportCity_Text_MaybeThisTrainer:
	.string "SCOTT: Hừm... Có lẽ, chỉ là có lẽ thôi,\n"
	.string "HLV này...$"

SlateportCity_Text_LetsRegisterEachOther:
	.string "SCOTT: Được rồi! Tôi nghĩ cậu sẽ trở\n"
	.string "thành một người bạn tốt.\p"
	.string "Vậy hãy đăng ký nhau vào POKéNAVS của\n"
	.string "chúng ta nhé.\p"
	.string "... ... ... ... ... ...$"

SlateportCity_Text_RegisteredScott:
	.string "Đã đăng ký người tên SCOTT này vào\n"
	.string "POKéNAV.$"

SlateportCity_Text_KeepEyeOnTrainersBeSeeingYou:
	.string "SCOTT: Tôi rất muốn đi cùng cậu, nhưng\n"
	.string "tôi cũng muốn để mắt đến tài năng của\l"
	.string "những người khác.\p"
	.string "Vì vậy, tôi sẽ tiếp tục lang thang qua\n"
	.string "vài thị trấn khác.\p"
	.string "Hẹn gặp lại, {PLAYER}{KUN}!$"

SlateportCity_Text_TakingBattleTentChallenge:
	.string "SCOTT: Ồ, chào! Chẳng phải\n"
	.string "{PLAYER}{KUN} đây sao!\p"
	.string "{PLAYER}{KUN}, để tôi đoán nhé, cậu\n"
	.string "định tham gia thử thách BATTLE TENT\l"
	.string "phải không?\p"
	.string "Phải! Ý hay đấy! Thật sự là một ý tưởng\n"
	.string "tuyệt vời!\p"
	.string "Dù sao thì một HLV mạnh mẽ là\n"
	.string "người phù hợp nhất với BATTLE TENT!\p"
	.string "Hãy cố gắng hết sức nhé!$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global SlateportCity_Text_EnergyGuruSellWhatYouNeed
	.global SlateportCity_Text_OhYourPokemon
	.global SlateportCity_Text_PleaseGiveItThisEffortRibbon
	.global SlateportCity_Text_ReceivedEffortRibbon
	.global SlateportCity_Text_PutEffortRibbonOnMon
	.global SlateportCity_Text_GoForItLittleHarder
	.global SlateportCity_Text_EffortRibbonLooksGoodOnIt
	.global SlateportCity_Text_WonderIfLighthouseStartlesPokemon
	.global SlateportCity_Text_SeaweedFullOfLife
	.global SlateportCity_Text_HowTownIsBornAndGrows
	.global SlateportCity_Text_SlateportWonderfulPlace
	.global SlateportCity_Text_BuyBricksSoDecorWontGetDirty
	.global SlateportCity_Text_GoingToCompeteInBattleTent
	.global SlateportCity_Text_BushedHikingFromMauville
	.global SlateportCity_Text_EveryoneCallsHimCaptStern
	.global SlateportCity_Text_WhatsLongLineOverThere
	.global SlateportCity_Text_VisitedMuseumOften
	.global SlateportCity_Text_QuitPushing
	.global SlateportCity_Text_AquaHasPolicy
	.global SlateportCity_Text_BossIsBrilliant
	.global SlateportCity_Text_WhatsNewSchemeIWonder
	.global SlateportCity_Text_ShouldTakeItAll
	.global SlateportCity_Text_DontButtIn
	.global SlateportCity_Text_RemindsMeOfLongLineForGames
	.global SlateportCity_Text_WhyAreWeLiningUp
	.global SlateportCity_Text_WhatDoYouWant
	.global SlateportCity_Text_IllReadSignForYou
	.global SlateportCity_Text_SaysSomethingLikeSeaIsEndless
	.global SlateportCity_Text_ShouldveBroughtMyGameBoy
	.global SlateportCity_Text_HotSpringsAfterOperation
	.global SlateportCity_Text_SeaIsSoWet
	.global SlateportCity_Text_SinkOldBoats
	.global SlateportCity_Text_BuyTooMuch
	.global SlateportCity_Text_GetNameRaterToHelpYou
	.global SlateportCity_Text_CantChangeTradeMonName
	.global SlateportCity_Text_BattleTentBuiltRecently
	.global SlateportCity_Text_CaptSternBeingInterviewed
	.global SlateportCity_Text_InterviewerSoCool
	.global SlateportCity_Text_SternSaysDiscoveredSomething
	.global SlateportCity_Text_CaptainComeBackWithBigFish
	.global SlateportCity_Text_AmIOnTV
	.global SlateportCity_Text_CaptainsACelebrity
	.global SlateportCity_Text_BigSmileForCamera
	.global SlateportCity_Text_MostInvaluableExperience
	.global SlateportCity_Text_SternMoveAheadWithExploration
	.global SlateportCity_Text_GabbyWonderfulThanksForInterview
	.global SlateportCity_Text_SternWhewFirstInterview
	.global SlateportCity_Text_OhPlayerWeMadeDiscovery
	.global SlateportCity_Text_AquaWillAssumeControlOfSubmarine
	.global SlateportCity_Text_SternWhatWasAllThat
	.global SlateportCity_Text_FromHarborTryingToTakeSub
	.global SlateportCity_Text_PleaseComeWithMe
	.global SlateportCity_Text_BattleTentSign
	.global SlateportCity_Text_SternsShipyardWantedSign
	.global SlateportCity_Text_SternsShipyardNearsCompletion
	.global SlateportCity_Text_SternsShipyardFerryComplete
	.global SlateportCity_Text_PokemonFanClubSign
	.global SlateportCity_Text_OceanicMuseumSign
	.global SlateportCity_Text_CitySign
	.global SlateportCity_Text_MarketSign
	.global SlateportCity_Text_HarborFerryUnderConstruction
	.global SlateportCity_Text_HarborSign
	.global SlateportCity_Text_NameRatersHouseSign
	.global SlateportCity_Text_ExplainBerries
	.global SlateportCity_Text_ExplainBerryPowder
	.global SlateportCity_Text_BroughtMeSomeBerryPowder
	.global SlateportCity_Text_ExchangeWhatWithIt
	.global SlateportCity_Text_ExchangeBerryPowderForItem
	.global SlateportCity_Text_DontHaveEnoughBerryPowder
	.global SlateportCity_Text_FineBerryPowderTradeSomethingElse
	.global SlateportCity_Text_WhenYouGetMoreBringItToMe
	.global SlateportCity_Text_ComeBackToTradeBerryPowder
	.global SlateportCity_Text_YouDroveTeamAquaAway
	.global SlateportCity_Text_MaybeThisTrainer
	.global SlateportCity_Text_LetsRegisterEachOther
	.global SlateportCity_Text_RegisteredScott
	.global SlateportCity_Text_KeepEyeOnTrainersBeSeeingYou
	.global SlateportCity_Text_TakingBattleTentChallenge
@ END GENERATED LOCALIZATION EXPORTS
