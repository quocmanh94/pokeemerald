LilycoveCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, LilycoveCity_OnLoad
	.byte 0

LilycoveCity_OnTransition:
	setflag FLAG_VISITED_LILYCOVE_CITY
	setvar VAR_CONTEST_HALL_STATE, 0
	setflag FLAG_HIDE_LILYCOVE_CONTEST_HALL_REPORTER
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	call Common_EventScript_SetupRivalGfxId
	end

LilycoveCity_OnLoad:
	call_if_unset FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_SetWailmerMetatiles
	end

LilycoveCity_EventScript_SetWailmerMetatiles::
	setmetatile 76, 12, METATILE_Lilycove_Wailmer0, TRUE
	setmetatile 77, 12, METATILE_Lilycove_Wailmer1, TRUE
	setmetatile 76, 13, METATILE_Lilycove_Wailmer2, TRUE
	setmetatile 77, 13, METATILE_Lilycove_Wailmer3, TRUE
	setmetatile 76, 14, METATILE_Lilycove_Wailmer0_Alt, TRUE
	setmetatile 77, 14, METATILE_Lilycove_Wailmer1_Alt, TRUE
	setmetatile 76, 15, METATILE_Lilycove_Wailmer2, TRUE
	setmetatile 77, 15, METATILE_Lilycove_Wailmer3, TRUE
	setmetatile 77, 16, METATILE_Lilycove_Wailmer0_Alt, TRUE
	setmetatile 78, 16, METATILE_Lilycove_Wailmer1_Alt, TRUE
	setmetatile 77, 17, METATILE_Lilycove_Wailmer2, TRUE
	setmetatile 78, 17, METATILE_Lilycove_Wailmer3, TRUE
	return

LilycoveCity_EventScript_BerryGentleman::
	lock
	faceplayer
	dotimebasedevents
	goto_if_set FLAG_DAILY_LILYCOVE_RECEIVED_BERRY, LilycoveCity_EventScript_ReceivedBerry
	msgbox LilycoveCity_Text_BerrySuitsYou, MSGBOX_DEFAULT
	random 10
	addvar VAR_RESULT, FIRST_BERRY_INDEX
	giveitem VAR_RESULT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_LILYCOVE_RECEIVED_BERRY
	msgbox LilycoveCity_Text_BecauseYoureTrainer, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_ReceivedBerry::
	msgbox LilycoveCity_Text_PokeblocksSuitPokemon, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Man3::
	msgbox LilycoveCity_Text_ContestHallInTown, MSGBOX_NPC
	end

LilycoveCity_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_EventScript_GirlAquaGone
	msgbox LilycoveCity_Text_StrangeCaveInCove, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_GirlAquaGone::
	msgbox LilycoveCity_Text_GoingToMoveDeleterForHMs, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_RichBoy::
	msgbox LilycoveCity_Text_ImFromKanto, MSGBOX_NPC
	end

LilycoveCity_EventScript_Sailor2::
	lock
	faceplayer
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_Sailor2AquaGone
	msgbox LilycoveCity_Text_TeamAquaBeenTrainingWailmer, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Sailor2AquaGone::
	msgbox LilycoveCity_Text_SomeonePuntedTeamAquaOut, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Woman2::
	lock
	faceplayer
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_Woman2AquaGone
	msgbox LilycoveCity_Text_SomeoneStoleMyPokemon, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Woman2AquaGone::
	msgbox LilycoveCity_Text_MissingPokemonCameBack, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Man2::
	msgbox LilycoveCity_Text_ImArtDealer, MSGBOX_NPC
	end

LilycoveCity_EventScript_ExpertM1::
	msgbox LilycoveCity_Text_SeaRemainsForeverYoung, MSGBOX_SIGN
	end

LilycoveCity_EventScript_ExpertF::
	msgbox LilycoveCity_Text_SixtyYearsAgoHusbandProposed, MSGBOX_SIGN
	end

LilycoveCity_EventScript_ExpertM2::
	lock
	faceplayer
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_EventScript_ExpertM2AquaGone
	msgbox LilycoveCity_Text_TeamAquaRenovatedCavern, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_ExpertM2AquaGone::
	msgbox LilycoveCity_Text_TeamAquaLotGoneForGood, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Sailor1::
	msgbox LilycoveCity_Text_HeardTowerCalledSkyPillar, MSGBOX_NPC
	end

LilycoveCity_EventScript_FatMan::
	msgbox LilycoveCity_Text_SawTallTowerOnRoute131, MSGBOX_NPC
	end

LilycoveCity_EventScript_Man1::
	lockall
	msgbox LilycoveCity_Text_JustArrivedAndSawRarePokemon, MSGBOX_NPC
	applymovement LOCALID_LILYCOVE_MAN_1, Common_Movement_FaceOriginalDirection
	end

LilycoveCity_EventScript_Woman1::
	lockall
	msgbox LilycoveCity_Text_HoneymoonVowToSeeRarePokemon, MSGBOX_NPC
	applymovement LOCALID_LILYCOVE_WOMAN_1, Common_Movement_FaceOriginalDirection
	end

LilycoveCity_EventScript_CitySign::
	msgbox LilycoveCity_Text_CitySign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_ContestHallSign::
	msgbox LilycoveCity_Text_ContestHallSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_MotelSign::
	msgbox LilycoveCity_Text_MotelSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_MuseumSign::
	lockall
	specialvar VAR_0x8004, CountPlayerMuseumPaintings
	switch VAR_0x8004
	case 0, LilycoveCity_EventScript_MuseumSignNoPaintings
	msgbox LilycoveCity_Text_MuseumSignPlayersExhibit, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_MuseumSignNoPaintings::
	msgbox LilycoveCity_Text_MuseumSign, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_HarborSign::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_HarborSignFerryReady
	msgbox LilycoveCity_Text_HarborSignUnderConstruction, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_HarborSignFerryReady::
	msgbox LilycoveCity_Text_HarborSign, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_TrainerFanClubSign::
	msgbox LilycoveCity_Text_TrainerFanClubSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_DepartmentStoreSign::
	msgbox LilycoveCity_Text_DepartmentStoreSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_MoveDeletersHouseSign::
	msgbox LilycoveCity_Text_MoveDeletersHouseSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_WailmerTrainerGrunt::
	lockall
	goto_if_set FLAG_MET_WAILMER_TRAINER, LilycoveCity_EventScript_MetWailmerTrainer
	msgbox LilycoveCity_Text_WailmerLeapOutOfWater, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_Text_GetLostMessingUpTraining, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag FLAG_MET_WAILMER_TRAINER
	releaseall
	end

LilycoveCity_EventScript_MetWailmerTrainer::
	msgbox LilycoveCity_Text_WailmerLeapOutOfWater, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_AquaGrunt1::
	msgbox LilycoveCity_Text_MovedLootIntoHideoutToday, MSGBOX_NPC
	end

LilycoveCity_EventScript_AquaGrunt2::
	msgbox LilycoveCity_Text_ChanceToDoBigThings, MSGBOX_NPC
	end

LilycoveCity_EventScript_AquaGrunt3::
	msgbox LilycoveCity_Text_DontGoNearCaveInCove, MSGBOX_NPC
	end

LilycoveCity_EventScript_AquaGrunt4::
	msgbox LilycoveCity_Text_IfWorldBecomesOurs, MSGBOX_NPC
	end

LilycoveCity_EventScript_Rival::
	lock
	faceplayer
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, LilycoveCity_EventScript_May
	goto_if_eq VAR_RESULT, FEMALE, LilycoveCity_EventScript_Brendan
	end

LilycoveCity_EventScript_May::
	playbgm MUS_ENCOUNTER_MAY, TRUE
	call_if_set FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_MayAskToBattleAgain
	call_if_unset FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_MayAskToBattle
	goto_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DeclineMayBattle
	msgbox LilycoveCity_Text_MayWontBeBeaten, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, LilycoveCity_EventScript_BattleMayTreecko
	case 1, LilycoveCity_EventScript_BattleMayTorchic
	case 2, LilycoveCity_EventScript_BattleMayMudkip
	end

LilycoveCity_EventScript_MayAskToBattleAgain::
	msgbox LilycoveCity_Text_MayBattleMe, MSGBOX_YESNO
	return

LilycoveCity_EventScript_MayAskToBattle::
	msgbox LilycoveCity_Text_MayShoppingLetsBattle, MSGBOX_YESNO
	return

LilycoveCity_EventScript_DeclineMayBattle::
	setflag FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE
	msgbox LilycoveCity_Text_MayNotRaisingPokemon, MSGBOX_DEFAULT
	savebgm MUS_DUMMY
	fadedefaultbgm
	release
	end

LilycoveCity_EventScript_Brendan::
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	call_if_set FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_BrendanAskToBattleAgain
	call_if_unset FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_BrendanAskToBattle
	goto_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DeclineBrendanBattle
	msgbox LilycoveCity_Text_BrendanWontBeBeaten, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, LilycoveCity_EventScript_BattleBrendanTreecko
	case 1, LilycoveCity_EventScript_BattleBrendanTorchic
	case 2, LilycoveCity_EventScript_BattleBrendanMudkip
	end

LilycoveCity_EventScript_BrendanAskToBattleAgain::
	msgbox LilycoveCity_Text_BrendanBattleMe, MSGBOX_YESNO
	return

LilycoveCity_EventScript_BrendanAskToBattle::
	msgbox LilycoveCity_Text_BrendanShoppingLetsBattle, MSGBOX_YESNO
	return

LilycoveCity_EventScript_DeclineBrendanBattle::
	setflag FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE
	msgbox LilycoveCity_Text_BrendanNoConfidence, MSGBOX_DEFAULT
	savebgm MUS_DUMMY
	fadedefaultbgm
	release
	end

LilycoveCity_EventScript_BattleMayTreecko::
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_TREECKO, LilycoveCity_Text_MayDefeat
	goto LilycoveCity_EventScript_DefeatedMay
	end

LilycoveCity_EventScript_BattleMayTorchic::
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_TORCHIC, LilycoveCity_Text_MayDefeat
	goto LilycoveCity_EventScript_DefeatedMay
	end

LilycoveCity_EventScript_BattleMayMudkip::
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_MUDKIP, LilycoveCity_Text_MayDefeat
	goto LilycoveCity_EventScript_DefeatedMay
	end

LilycoveCity_EventScript_BattleBrendanTreecko::
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_TREECKO, LilycoveCity_Text_BrendanDefeat
	goto LilycoveCity_EventScript_DefeatedBrendan
	end

LilycoveCity_EventScript_BattleBrendanTorchic::
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_TORCHIC, LilycoveCity_Text_BrendanDefeat
	goto LilycoveCity_EventScript_DefeatedBrendan
	end

LilycoveCity_EventScript_BattleBrendanMudkip::
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_MUDKIP, LilycoveCity_Text_BrendanDefeat
	goto LilycoveCity_EventScript_DefeatedBrendan
	end

LilycoveCity_EventScript_DefeatedMay::
	msgbox LilycoveCity_Text_MayGoingBackToLittleroot, MSGBOX_DEFAULT
	setvar VAR_RESULT, FALSE
	call_if_set FLAG_BADGE06_GET, LilycoveCity_EventScript_CheckFinalBadge
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_EventScript_MayCollectBadges
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_EventScript_MayPokemonLeague
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_PICHU_DOLL
	goto LilycoveCity_EventScript_RivalFlyAway
	end

LilycoveCity_EventScript_CheckFinalBadge::
	goto_if_set FLAG_BADGE08_GET, LilycoveCity_EventScript_HasFinalBadge
	return

LilycoveCity_EventScript_HasFinalBadge::
	setvar VAR_RESULT, TRUE
	return

LilycoveCity_EventScript_MayCollectBadges::
	msgbox LilycoveCity_Text_MayYouGoingToCollectBadges, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_MayPokemonLeague::
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_MayBattleFrontier
	msgbox LilycoveCity_Text_MayYouGoingToPokemonLeague, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_MayBattleFrontier::
	msgbox LilycoveCity_Text_MayYouGoingToBattleFrontier, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_DefeatedBrendan::
	msgbox LilycoveCity_Text_BrendanGoingBackToLittleroot, MSGBOX_DEFAULT
	setvar VAR_RESULT, FALSE
	call_if_set FLAG_BADGE06_GET, LilycoveCity_EventScript_CheckFinalBadge
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_EventScript_BrendanCollectBadges
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_EventScript_BrendanPokemonLeague
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_SWABLU_DOLL
	goto LilycoveCity_EventScript_RivalFlyAway
	end

LilycoveCity_EventScript_BrendanCollectBadges::
	msgbox LilycoveCity_Text_BrendanYouGoingToCollectBadges, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_BrendanPokemonLeague::
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_BrendanBattleFrontier
	msgbox LilycoveCity_Text_BrendanYouGoingToPokemonLeague, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_BrendanBattleFrontier::
	msgbox LilycoveCity_Text_BrendanYouGoingToBattleFrontier, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_RivalFlyAway::
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 50
	setfieldeffectargument 0, 1
	dofieldeffect FLDEFF_NPCFLY_OUT
	delay 15
	removeobject VAR_LAST_TALKED
	waitfieldeffect FLDEFF_NPCFLY_OUT
	savebgm MUS_DUMMY
	fadedefaultbgm
	setflag FLAG_MET_RIVAL_LILYCOVE
	release
	end

LilycoveCity_EventScript_SchoolKidM::
	lock
	faceplayer
	msgbox LilycoveCity_Text_DoYouKnowAboutBerryBlender, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, LilycoveCity_EventScript_KnowAboutBerryBlender
	call_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DontKnowAboutBerryBlender
	release
	end

LilycoveCity_EventScript_KnowAboutBerryBlender::
	msgbox LilycoveCity_Text_FasterSpinBetterPokeblocks, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_DontKnowAboutBerryBlender::
	msgbox LilycoveCity_Text_ExplainBerryBlender, MSGBOX_DEFAULT
	return

LilycoveCity_Text_MayShoppingLetsBattle:
	.string "MAY: Ồ, này? {PLAYER}{KUN}, cậu cũng\n"
	.string "đang mua sắm à?\p"
	.string "Mình đã mua cả đống DOLLS và POSTERS.\p"
	.string "Tất nhiên, mình cũng bắt được rất\n"
	.string "nhiều POKéMON và chăm sóc chúng rất tử\l"
	.string "tế.\p"
	.string "Thật ra, mình còn lo không biết cậu có\n"
	.string "chăm sóc POKéMON tử tế không đấy,\l"
	.string "{PLAYER}{KUN}.\p"
	.string "Đấu với mình đi, để cậu cho mình xem\n"
	.string "POKéMON của cậu nào, {PLAYER}{KUN}.$"

LilycoveCity_Text_MayNotRaisingPokemon:
	.string "MAY: Ồ, sao vậy? {PLAYER}{KUN}, cậu\n"
	.string "không chịu huấn luyện POKéMON à?\p"
	.string "Thế này thì chưa ra dáng một HLV\n"
	.string "lắm...$"

LilycoveCity_Text_MayBattleMe:
	.string "MAY: Nào, đấu với mình đi để mình xem\n"
	.string "POKéMON của cậu!$"

LilycoveCity_Text_MayWontBeBeaten:
	.string "MAY: Những POKéMON mình nuôi dạy sẽ\n"
	.string "không thua POKéMON của cậu đâu,\l"
	.string "{PLAYER}{KUN}!$"

LilycoveCity_Text_MayDefeat:
	.string "... ... ... ... ... ... ... ...\p"
	.string "Mình vẫn nhớ trận đấu với cậu trên\n"
	.string "ROUTE 103, {PLAYER}{KUN}.\p"
	.string "Chính trận đấu đó đã giúp cậu mạnh\n"
	.string "được như bây giờ, đúng không,\l"
	.string "{PLAYER}{KUN}?$"

LilycoveCity_Text_MayGoingBackToLittleroot:
	.string "MAY: Mình đang định sớm trở về\n"
	.string "LITTLEROOT.\p"
	.string "Mình đã bắt được kha khá POKéMON và\n"
	.string "POKéDEX cũng tiến triển tốt, nên mình\l"
	.string "sẽ về khoe với ba.$"

LilycoveCity_Text_MayYouGoingToCollectBadges:
	.string "{PLAYER}{KUN}, cậu định làm gì tiếp\n"
	.string "theo?\p"
	.string "Thu thập đủ GYM BADGES rồi thách đấu\n"
	.string "POKéMON LEAGUE à?\p"
	.string "Vậy thì trong lúc cậu thu thập BADGES,\n"
	.string "{PLAYER}{KUN}, mình sẽ tiếp tục hoàn\l"
	.string "thiện POKéDEX. Mình sẽ hoàn thành\l"
	.string "trước cậu!\p"
	.string "Hẹn gặp lại!$"

LilycoveCity_Text_MayYouGoingToPokemonLeague:
	.string "{PLAYER}{KUN}, cậu định làm gì tiếp\n"
	.string "theo?\p"
	.string "Cậu sẽ thách đấu POKéMON LEAGUE à?\p"
	.string "Hay cậu định hoàn thiện POKéDEX?\p"
	.string "Có thể mình đã thua cậu khi đấu\n"
	.string "POKéMON, nhưng mình sẽ hoàn thành\l"
	.string "POKéDEX trước cậu!\p"
	.string "Hẹn gặp lại!$"

LilycoveCity_Text_MayYouGoingToBattleFrontier:
	.string "{PLAYER}{KUN}, cậu định làm gì tiếp\n"
	.string "theo?\p"
	.string "Cậu sẽ chinh phục BATTLE FRONTIER à?\p"
	.string "Hay cậu định hoàn thiện POKéDEX?\p"
	.string "Có thể mình đã thua cậu khi đấu\n"
	.string "POKéMON, nhưng mình sẽ hoàn thành\l"
	.string "POKéDEX trước cậu!\p"
	.string "Hẹn gặp lại!$"

LilycoveCity_Text_BrendanShoppingLetsBattle:
	.string "BRENDAN: Ồ, này, {PLAYER} đấy à.\p"
	.string "Tớ đang đi làm việc vặt cho ba. Không,\n"
	.string "tớ không mua DOLLS đâu.\p"
	.string "Dù sao cũng lâu rồi chúng ta chưa gặp.\p"
	.string "Muốn đấu một trận xem ai huấn luyện\n"
	.string "POKéMON tốt hơn không?$"

LilycoveCity_Text_BrendanNoConfidence:
	.string "BRENDAN: Ồ, sao thế? Không tự tin à?$"

LilycoveCity_Text_BrendanBattleMe:
	.string "BRENDAN: Muốn đấu một trận xem ai huấn\n"
	.string "luyện POKéMON tốt hơn không?$"

LilycoveCity_Text_BrendanWontBeBeaten:
	.string "BRENDAN: Chà, nhưng cậu biết tớ đời\n"
	.string "nào chịu thua {PLAYER} mà.$"

LilycoveCity_Text_BrendanDefeat:
	.string "Hừm... Cậu đã dày công huấn luyện đấy.\p"
	.string "Cay thật, tớ đã bắt đầu làm HLV\n"
	.string "trước cậu cơ mà...$"

LilycoveCity_Text_BrendanGoingBackToLittleroot:
	.string "BRENDAN: Tớ... tớ định về nhà ở\n"
	.string "LITTLEROOT.\p"
	.string "Cậu biết tớ đang giúp ba hoàn thiện\n"
	.string "POKéDEX mà. Mọi việc cũng tiến triển khá\l"
	.string "tốt, nên tớ phải về cho ba xem.$"

LilycoveCity_Text_BrendanYouGoingToCollectBadges:
	.string "{PLAYER}, cậu định làm gì tiếp theo?\p"
	.string "Thu thập đủ GYM BADGES rồi thách đấu\n"
	.string "POKéMON LEAGUE à?\p"
	.string "Có lẽ tớ cũng sẽ làm vậy...\p"
	.string "Dù sao thì cũng cố lên nhé!$"

LilycoveCity_Text_BrendanYouGoingToPokemonLeague:
	.string "{PLAYER}, cậu định làm gì tiếp theo?\p"
	.string "Mạnh đến mức đó rồi, cậu sẽ thách đấu\n"
	.string "POKéMON LEAGUE à?\p"
	.string "Hừ, chỉ cần huấn luyện POKéMON thêm\n"
	.string "một chút, tớ sẽ mạnh hơn cậu thôi,\l"
	.string "{PLAYER}.\p"
	.string "Dù sao thì cũng cố lên nhé!$"

LilycoveCity_Text_BrendanYouGoingToBattleFrontier:
	.string "{PLAYER}, cậu định làm gì tiếp theo?\p"
	.string "Cậu sẽ chinh phục BATTLE FRONTIER à?\p"
	.string "Hay cậu định hoàn thiện POKéDEX?\p"
	.string "Mạnh đến mức đó rồi thì cậu nên thử\n"
	.string "sức ở BATTLE FRONTIER.\p"
	.string "Hừ, chỉ cần huấn luyện POKéMON thêm\n"
	.string "một chút, tớ sẽ mạnh hơn cậu thôi,\l"
	.string "{PLAYER}.\p"
	.string "Có lẽ tớ cũng nên đến BATTLE FRONTIER.\p"
	.string "Dù sao thì cũng cố lên nhé!$"

LilycoveCity_Text_MovedLootIntoHideoutToday:
	.string "Fufufu...\p"
	.string "Hôm nay bọn ta lại chuyển thêm chiến lợi\n"
	.string "phẩm vào HIDEOUT bí mật...\p"
	.string "Ngươi... ngươi là ai?! Ta chỉ đang tự\n"
	.string "nói chuyện một mình thôi!$"

LilycoveCity_Text_ChanceToDoBigThings:
	.string "Ta chỉ là lính quèn, đâu biết thủ lĩnh\n"
	.string "đang nghĩ gì...\p"
	.string "Nhưng đã gia nhập TEAM AQUA thì chắc\n"
	.string "chắn ta sẽ có cơ hội làm nên chuyện\l"
	.string "lớn!\p"
	.string "Ngươi... ngươi là ai?! Ta chỉ đang tự\n"
	.string "nói chuyện một mình thôi!$"

LilycoveCity_Text_DontGoNearCaveInCove:
	.string "Này, nhóc kia!\p"
	.string "Đừng đến gần hang động trong vịnh!\p"
	.string "Tại sao à? Không cần lý do! Ta là người\n"
	.string "lớn, cứ nghe lời ta đi!$"

LilycoveCity_Text_IfWorldBecomesOurs:
	.string "Nếu cả thế giới rộng lớn này thuộc về\n"
	.string "TEAM AQUA, nơi đây cũng sẽ trở nên\l"
	.string "hạnh phúc hơn đối với POKéMON.$"

LilycoveCity_Text_WailmerLeapOutOfWater:
	.string "Nào! WAILMER! Nhảy khỏi mặt nước ngay!$"

LilycoveCity_Text_GetLostMessingUpTraining:
	.string "Hả? Muốn gì?\p"
	.string "Ngươi đang phá buổi huấn luyện của bọn\n"
	.string "ta đấy, biến đi được không?$"

LilycoveCity_Text_ContestHallInTown:
	.string "Ngay trong thành phố này có một\n"
	.string "POKéMON CONTEST HALL.\p"
	.string "Nghĩa là những POKéMON được chăm sóc\n"
	.string "tốt sẽ kéo đến từ khắp mọi miền.\p"
	.string "Chỉ nghĩ thôi là tim tôi đã rộn lên vì\n"
	.string "phấn khích!$"

LilycoveCity_Text_StrangeCaveInCove:
	.string "Bạn đã thấy hang động kỳ lạ trong vịnh\n"
	.string "ở rìa thành phố chưa?$"

LilycoveCity_Text_GoingToMoveDeleterForHMs:
	.string "Tôi sẽ dạy POKéMON vài chiêu mới để\n"
	.string "tham gia cuộc thi.\p"
	.string "Vì vậy, tôi sẽ đến gặp MOVE DELETER để\n"
	.string "khiến nó quên các chiêu HM.$"

LilycoveCity_Text_ImFromKanto:
	.string "Tôi đến từ KANTO.\p"
	.string "Vùng HOENN thật tươi đẹp với bao sông\n"
	.string "nước và thiên nhiên xanh tốt.\p"
	.string "Hả? Khoan đã...\p"
	.string "Liệu có POKéMON quý hiếm nào chỉ sống ở\n"
	.string "vùng này không?$"

LilycoveCity_Text_TeamAquaBeenTrainingWailmer:
	.string "TEAM AQUA đang huấn luyện WAILMER\n"
	.string "trong vịnh.\p"
	.string "Chúng chắn hết đường nên SAILORS\n"
	.string "chúng tôi không thể đưa tàu ra khơi!$"

LilycoveCity_Text_SomeonePuntedTeamAquaOut:
	.string "A-hôi, bạn biết chưa?\p"
	.string "Có người đã tống TEAM AQUA ra khỏi\n"
	.string "đường giúp chúng tôi!\p"
	.string "Nhờ vậy, WAILMER đã rời khỏi vịnh và\n"
	.string "tàu thuyền lại có thể ra khơi.$"

LilycoveCity_Text_SomeoneStoleMyPokemon:
	.string "Tôi đang thư thái chợp mắt trong quán\n"
	.string "trọ ven biển, nghe tiếng sóng vỗ...\p"
	.string "Thế mà có kẻ đã bắt trộm POKéMON của\n"
	.string "tôi!\p"
	.string "Kẻ bắt cóc là ai? TEAM AQUA à? Có phải\n"
	.string "TEAM AQUA không?$"

LilycoveCity_Text_MissingPokemonCameBack:
	.string "POKéMON mất tích của tôi... Nó đã trở về\n"
	.string "lúc nào mà tôi chẳng hề hay biết!$"

LilycoveCity_Text_ImArtDealer:
	.string "Tôi là một ART DEALER.\p"
	.string "Tôi mua bán các tác phẩm mỹ thuật, đặc\n"
	.string "biệt là tranh vẽ.\p"
	.string "Tôi nghe nói MUSEUM ở đây đang trưng\n"
	.string "bày những tác phẩm tuyệt mỹ...$"

LilycoveCity_Text_SeaRemainsForeverYoung:
	.string "Dẫu chúng ta có già nua và nhăn nheo,\n"
	.string "biển cả vẫn mãi trẻ trung, rực rỡ sức\l"
	.string "sống...\p"
	.string "Fwohoho fwohohohoho...$"

LilycoveCity_Text_SixtyYearsAgoHusbandProposed:
	.string "Sáu mươi năm trước, chồng tôi đã cầu\n"
	.string "hôn tôi ngay tại đây. Biển vẫn đẹp như\l"
	.string "thuở nào.\p"
	.string "Mufufufu mufufufufufu...$"

LilycoveCity_Text_TeamAquaRenovatedCavern:
	.string "Hừm, bạn biết hang động kỳ lạ trong\n"
	.string "vịnh này chứ?\p"
	.string "Vốn dĩ nó được hình thành tự nhiên,\n"
	.string "nhưng đám TEAM AQUA kéo đến rồi sửa\l"
	.string "sang lại.\p"
	.string "Chúng tự xưng là TEAM AQUA yêu thiên\n"
	.string "nhiên!\p"
	.string "Nhưng lời nói và việc làm của chúng\n"
	.string "chẳng ăn nhập gì cả!$"

LilycoveCity_Text_TeamAquaLotGoneForGood:
	.string "Hang động trong vịnh ấy...\p"
	.string "Ban đầu tôi không nhận ra, nhưng giờ\n"
	.string "bên trong đã hoàn toàn trống rỗng.\p"
	.string "Đám TEAM AQUA đó chắc đã bỏ đi hẳn rồi.$"

LilycoveCity_Text_CitySign:
	.string "LILYCOVE CITY\p"
	.string "Nơi đất liền kết thúc và biển cả bắt\n"
	.string "đầu.$"

LilycoveCity_Text_ContestHallSign:
	.string "POKéMON CONTEST HALL Nơi tụ hội của\n"
	.string "các HLV!$"

LilycoveCity_Text_MotelSign:
	.string "COVE LILY MOTEL\p"
	.string "Hãy nhớ đến COVE LILY của LILYCOVE.$"

LilycoveCity_Text_MuseumSign:
	.string "LILYCOVE MUSEUM\p"
	.string "Đang trưng bày POKéMON Masterpiece\n"
	.string "Collection!$"

LilycoveCity_Text_MuseumSignPlayersExhibit:
	.string "LILYCOVE MUSEUM\p"
	.string "Đang trưng bày Bộ sưu tập POKéMON của\n"
	.string "{PLAYER}!$"

LilycoveCity_Text_HarborSignUnderConstruction:
	.string "LILYCOVE CITY HARBOR\p"
	.string "Phà S.S. TIDAL đang được đóng tại\n"
	.string "SLATEPORT CITY.\p"
	.string "Dịch vụ dự kiến sẽ sớm bắt đầu.$"

LilycoveCity_Text_HarborSign:
	.string "LILYCOVE CITY HARBOR\p"
	.string "Hãy tận hưởng chuyến hải trình thú vị\n"
	.string "trên phà S.S. TIDAL.$"

LilycoveCity_Text_TrainerFanClubSign:
	.string "POKéMON TRAINER FAN CLUB\p"
	.string "Tên của các HLV được viết nguệch\n"
	.string "ngoạc khắp tấm biển...$"

LilycoveCity_Text_DepartmentStoreSign:
	.string "LILYCOVE DEPARTMENT STORE\p"
	.string "Ngập tràn hàng hóa tuyệt vời và niềm\n"
	.string "vui mua sắm!\p"
	.string "Nơi lý tưởng để tìm món đồ bạn cần!$"

LilycoveCity_Text_MoveDeletersHouseSign:
	.string "MOVE DELETER'S HOUSE\p"
	.string "Xóa những chiêu POKéMON không còn cần\n"
	.string "thiết.$"

LilycoveCity_Text_DoYouKnowAboutBerryBlender:
	.string "Bạn có biết cỗ máy BERRY BLENDER\n"
	.string "không?$"

LilycoveCity_Text_FasterSpinBetterPokeblocks:
	.string "Mọi người phải phối hợp để làm nó quay\n"
	.string "nhanh hơn.\p"
	.string "Tôi nghe nói quay càng nhanh thì càng\n"
	.string "tạo ra được {POKEBLOCK}S ngon hơn.$"

LilycoveCity_Text_ExplainBerryBlender:
	.string "Nó được dùng để làm một loại kẹo gọi là\n"
	.string "{POKEBLOCK}.\p"
	.string "Nếu cho POKéMON ăn một {POKEBLOCK}\n"
	.string "ngon, trạng thái của nó sẽ cải thiện\l"
	.string "đáng kể.$"

LilycoveCity_Text_HeardTowerCalledSkyPillar:
	.string "Tôi nghe nói có một tòa tháp nằm đâu đó\n"
	.string "ngoài những tuyến đường biển.\p"
	.string "Hình như nó được gọi là SKY PILLAR.$"

LilycoveCity_Text_SawTallTowerOnRoute131:
	.string "Tôi đã thấy một tòa tháp cao ở đâu đó\n"
	.string "gần ROUTE 131.\p"
	.string "Chẳng lẽ đó chính là...?$"

LilycoveCity_Text_JustArrivedAndSawRarePokemon:
	.string "Chúng tôi vừa đến đây hưởng tuần\n"
	.string "trăng mật.\p"
	.string "Tình cờ, chúng tôi thấy một POKéMON hệ\n"
	.string "DRAGON bay tít trên trời cao.\p"
	.string "Những POKéMON tuyệt vời như thế cũng\n"
	.string "sống ở vùng HOENN sao?$"

LilycoveCity_Text_HoneymoonVowToSeeRarePokemon:
	.string "Trong tuần trăng mật, chúng tôi đã hứa\n"
	.string "sẽ ngắm nhìn càng nhiều POKéMON quý\l"
	.string "hiếm càng tốt.\p"
	.string "Vì vậy, vừa đặt chân đến đây mà đã\n"
	.string "thấy một POKéMON quý hiếm khiến chúng\l"
	.string "tôi vui sướng vô cùng.\p"
	.string "Ý tôi là, chúng tôi thực sự rất hạnh\n"
	.string "phúc!$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global LilycoveCity_Text_MayShoppingLetsBattle
	.global LilycoveCity_Text_MayNotRaisingPokemon
	.global LilycoveCity_Text_MayBattleMe
	.global LilycoveCity_Text_MayWontBeBeaten
	.global LilycoveCity_Text_MayDefeat
	.global LilycoveCity_Text_MayGoingBackToLittleroot
	.global LilycoveCity_Text_MayYouGoingToCollectBadges
	.global LilycoveCity_Text_MayYouGoingToPokemonLeague
	.global LilycoveCity_Text_MayYouGoingToBattleFrontier
	.global LilycoveCity_Text_BrendanShoppingLetsBattle
	.global LilycoveCity_Text_BrendanNoConfidence
	.global LilycoveCity_Text_BrendanBattleMe
	.global LilycoveCity_Text_BrendanWontBeBeaten
	.global LilycoveCity_Text_BrendanDefeat
	.global LilycoveCity_Text_BrendanGoingBackToLittleroot
	.global LilycoveCity_Text_BrendanYouGoingToCollectBadges
	.global LilycoveCity_Text_BrendanYouGoingToPokemonLeague
	.global LilycoveCity_Text_BrendanYouGoingToBattleFrontier
	.global LilycoveCity_Text_MovedLootIntoHideoutToday
	.global LilycoveCity_Text_ChanceToDoBigThings
	.global LilycoveCity_Text_DontGoNearCaveInCove
	.global LilycoveCity_Text_IfWorldBecomesOurs
	.global LilycoveCity_Text_WailmerLeapOutOfWater
	.global LilycoveCity_Text_GetLostMessingUpTraining
	.global LilycoveCity_Text_ContestHallInTown
	.global LilycoveCity_Text_StrangeCaveInCove
	.global LilycoveCity_Text_GoingToMoveDeleterForHMs
	.global LilycoveCity_Text_ImFromKanto
	.global LilycoveCity_Text_TeamAquaBeenTrainingWailmer
	.global LilycoveCity_Text_SomeonePuntedTeamAquaOut
	.global LilycoveCity_Text_SomeoneStoleMyPokemon
	.global LilycoveCity_Text_MissingPokemonCameBack
	.global LilycoveCity_Text_ImArtDealer
	.global LilycoveCity_Text_SeaRemainsForeverYoung
	.global LilycoveCity_Text_SixtyYearsAgoHusbandProposed
	.global LilycoveCity_Text_TeamAquaRenovatedCavern
	.global LilycoveCity_Text_TeamAquaLotGoneForGood
	.global LilycoveCity_Text_CitySign
	.global LilycoveCity_Text_ContestHallSign
	.global LilycoveCity_Text_MotelSign
	.global LilycoveCity_Text_MuseumSign
	.global LilycoveCity_Text_MuseumSignPlayersExhibit
	.global LilycoveCity_Text_HarborSignUnderConstruction
	.global LilycoveCity_Text_HarborSign
	.global LilycoveCity_Text_TrainerFanClubSign
	.global LilycoveCity_Text_DepartmentStoreSign
	.global LilycoveCity_Text_MoveDeletersHouseSign
	.global LilycoveCity_Text_DoYouKnowAboutBerryBlender
	.global LilycoveCity_Text_FasterSpinBetterPokeblocks
	.global LilycoveCity_Text_ExplainBerryBlender
	.global LilycoveCity_Text_HeardTowerCalledSkyPillar
	.global LilycoveCity_Text_SawTallTowerOnRoute131
	.global LilycoveCity_Text_JustArrivedAndSawRarePokemon
	.global LilycoveCity_Text_HoneymoonVowToSeeRarePokemon
@ END GENERATED LOCALIZATION EXPORTS
