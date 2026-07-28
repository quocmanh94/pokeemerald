BattleFrontier_RankingHall_MapScripts::
	.byte 0

BattleFrontier_RankingHall_EventScript_TowerSinglesRecords::
	lockall
	setvar VAR_0x8005, RANKING_HALL_TOWER_SINGLES
	goto BattleFrontier_RankingHall_EventScript_ShowRecords
	end

BattleFrontier_RankingHall_EventScript_TowerDoublesRecords::
	lockall
	setvar VAR_0x8005, RANKING_HALL_TOWER_DOUBLES
	goto BattleFrontier_RankingHall_EventScript_ShowRecords
	end

BattleFrontier_RankingHall_EventScript_TowerMultisRecords::
	lockall
	setvar VAR_0x8005, RANKING_HALL_TOWER_MULTIS
	goto BattleFrontier_RankingHall_EventScript_ShowRecords
	end

BattleFrontier_RankingHall_EventScript_TowerLinkRecords::
	lockall
	setvar VAR_0x8005, RANKING_HALL_TOWER_LINK
	goto BattleFrontier_RankingHall_EventScript_ShowRecords
	end

BattleFrontier_RankingHall_EventScript_ArenaRecords::
	lockall
	setvar VAR_0x8005, RANKING_HALL_ARENA
	goto BattleFrontier_RankingHall_EventScript_ShowRecords
	end

BattleFrontier_RankingHall_EventScript_PalaceRecords::
	lockall
	setvar VAR_0x8005, RANKING_HALL_PALACE
	goto BattleFrontier_RankingHall_EventScript_ShowRecords
	end

BattleFrontier_RankingHall_EventScript_FactoryRecords::
	lockall
	setvar VAR_0x8005, RANKING_HALL_FACTORY
	goto BattleFrontier_RankingHall_EventScript_ShowRecords
	end

BattleFrontier_RankingHall_EventScript_DomeRecords::
	lockall
	setvar VAR_0x8005, RANKING_HALL_DOME
	goto BattleFrontier_RankingHall_EventScript_ShowRecords
	end

BattleFrontier_RankingHall_EventScript_PikeRecords::
	lockall
	setvar VAR_0x8005, RANKING_HALL_PIKE
	goto BattleFrontier_RankingHall_EventScript_ShowRecords
	end

BattleFrontier_RankingHall_EventScript_PyramidRecords::
	lockall
	setvar VAR_0x8005, RANKING_HALL_PYRAMID
	goto BattleFrontier_RankingHall_EventScript_ShowRecords
	end

BattleFrontier_RankingHall_EventScript_ShowRecords::
	special ShowRankingHallRecordsWindow
	waitbuttonpress
	special ScrollRankingHallRecordsWindow
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_RankingHall_EventScript_Attendant::
	msgbox BattleFrontier_RankingHall_Text_ExplainRankingHall, MSGBOX_NPC
	end

BattleFrontier_RankingHall_EventScript_DomePikeFactoryRecordsSign::
	msgbox BattleFrontier_RankingHall_Text_DomePikeFactoryRecords, MSGBOX_SIGN
	end

BattleFrontier_RankingHall_EventScript_PalaceArenaPyramidRecordsSIgn::
	msgbox BattleFrontier_RankingHall_Text_PalaceArenaPyramidRecords, MSGBOX_SIGN
	end

BattleFrontier_RankingHall_EventScript_NinjaBoy::
	lock
	faceplayer
	msgbox BattleFrontier_RankingHall_Text_IsYourNameOnThisList, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, BattleFrontier_RankingHall_EventScript_NinjaBoyNameOnList
	msgbox BattleFrontier_RankingHall_Text_WorkHarderIfYouSawFriendsName, MSGBOX_DEFAULT
	release
	end

BattleFrontier_RankingHall_EventScript_NinjaBoyNameOnList::
	msgbox BattleFrontier_RankingHall_Text_WowThatsSuper, MSGBOX_DEFAULT
	release
	end

BattleFrontier_RankingHall_EventScript_Boy::
	msgbox BattleFrontier_RankingHall_Text_MyNamesNotUpThere, MSGBOX_NPC
	end

BattleFrontier_RankingHall_Text_ExplainRankingHall:
	.string "Đây là RANKING HALL.\p"
	.string "Nơi đây tôn vinh những HLV bất\n"
	.string "tử đã lập nên các kỷ lục vĩ đại trong\l"
	.string "những sự kiện của BATTLE FRONTIER.$"

BattleFrontier_RankingHall_Text_DomePikeFactoryRecords:
	.string "Kỷ lục BATTLE DOME, BATTLE PIKE và\n"
	.string "BATTLE FACTORY$"

BattleFrontier_RankingHall_Text_PalaceArenaPyramidRecords:
	.string "Kỷ lục BATTLE PALACE, BATTLE ARENA và\n"
	.string "BATTLE PYRAMID$"

BattleFrontier_RankingHall_Text_IsYourNameOnThisList:
	.string "Chào bạn, tên bạn có trong danh sách\n"
	.string "này không?$"

BattleFrontier_RankingHall_Text_WowThatsSuper:
	.string "Chà, tuyệt thật! Tôi cũng phải cố gắng\n"
	.string "hơn mới được!$"

BattleFrontier_RankingHall_Text_WorkHarderIfYouSawFriendsName:
	.string "Ồ, vậy sao?\p"
	.string "Nếu thấy tên bạn mình ở đây, chắc bạn\n"
	.string "sẽ càng muốn cố gắng hơn!$"

BattleFrontier_RankingHall_Text_MyNamesNotUpThere:
	.string "Hừm... Tên tôi không có ở đó...\p"
	.string "Cũng phải thôi, vì tôi còn chưa tham gia\n"
	.string "thử thách nào.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global BattleFrontier_RankingHall_Text_ExplainRankingHall
	.global BattleFrontier_RankingHall_Text_DomePikeFactoryRecords
	.global BattleFrontier_RankingHall_Text_PalaceArenaPyramidRecords
	.global BattleFrontier_RankingHall_Text_IsYourNameOnThisList
	.global BattleFrontier_RankingHall_Text_WowThatsSuper
	.global BattleFrontier_RankingHall_Text_WorkHarderIfYouSawFriendsName
	.global BattleFrontier_RankingHall_Text_MyNamesNotUpThere
@ END GENERATED LOCALIZATION EXPORTS
