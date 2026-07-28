MossdeepCity_GameCorner_1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MossdeepCity_GameCorner_1F_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, MossdeepCity_GameCorner_1F_OnWarp
	map_script MAP_SCRIPT_ON_LOAD, CableClub_OnLoad
	.byte 0

MossdeepCity_GameCorner_1F_OnWarp:
	map_script_2 VAR_CABLE_CLUB_STATE, USING_MINIGAME, CableClub_EventScript_CheckTurnAttendant
	.2byte 0

MossdeepCity_GameCorner_1F_OnFrame:
	map_script_2 VAR_CABLE_CLUB_STATE, USING_MINIGAME, CableClub_EventScript_ExitMinigameRoom
	.2byte 0

@ Script is redundant, the label in the goto also does lock and faceplayer
MossdeepCity_GameCorner_1F_EventScript_InfoMan::
	lock
	faceplayer
	goto MossdeepCity_GameCorner_1F_EventScript_InfoMan2
	release
	end

@ Script is redundant, the label in the goto also does lock and faceplayer
MossdeepCity_GameCorner_1F_EventScript_OldMan::
	lock
	faceplayer
	goto MossdeepCity_GameCorner_1F_EventScript_OldMan2
	release
	end


@ Everything below is leftover from RS
@ The house that was here in RS was moved to Sootopolis and replaced by the Game Corner
@ The text below is unused and duplicated in its replacement in Sootopolis City
@ And the BG Door event was moved inaccessibly into a wall

RS_MysteryEventsHouse_EventScript_Door::
	msgbox RS_MysteryEventsHouse_Text_DoorIsLocked, MSGBOX_SIGN
	end

RS_MysteryEventsHouse_Text_OldManGreeting:
	.string "Khi còn trẻ, ông từng chu du khắp thế\n"
	.string "giới với tư cách một HLV POKéMON.\p"
	.string "Giờ đã thành một lão già, thú vui duy\n"
	.string "nhất của ông là xem các HLV trẻ\l"
	.string "tuổi thi đấu.$"

RS_MysteryEventsHouse_Text_DoorIsLocked:
	.string "Cánh cửa có vẻ đã bị khóa.$"

RS_MysteryEventsHouse_Text_ChallengeVisitingTrainer:
	.string "Một HLV tên {STR_VAR_1}\n"
	.string "đang ghé thăm nhà ông.\p"
	.string "Cháu có muốn thách đấu\n"
	.string "{STR_VAR_1} không?$"

RS_MysteryEventsHouse_Text_YouWontBattle:
	.string "Cháu không đấu sao? Ông thất vọng vì\n"
	.string "không được xem cháu thi đấu...$"

RS_MysteryEventsHouse_Text_KeepItToA3On3:
	.string "Ồ, tốt lắm, tốt lắm!\p"
	.string "Nhưng nhà ông không được kiên cố cho\n"
	.string "lắm.\p"
	.string "Hai cháu có thể chỉ đấu trận 3 đấu 3\n"
	.string "thôi được không?$"

RS_MysteryEventsHouse_Text_SaveYourProgress:
	.string "Trước khi hai cháu thi đấu, cháu nên\n"
	.string "lưu tiến trình lại.$"

RS_MysteryEventsHouse_Text_HopeToSeeAGoodMatch:
	.string "Ông mong được xem một trận đấu thật\n"
	.string "hay!$"

RS_MysteryEventsHouse_Text_BattleTie:
	.string "Vậy là hai bên bất phân thắng bại.\p"
	.string "Một trận đấu xuất sắc, không bên nào\n"
	.string "chịu nhường dù chỉ một bước!$"

RS_MysteryEventsHouse_Text_BattleWon:
	.string "Thật tuyệt vời!\p"
	.string "Cứ như ông đang được nhìn lại chính\n"
	.string "mình thời trẻ vậy!$"

RS_MysteryEventsHouse_Text_BattleLost:
	.string "A, tiếc cho cháu quá!\p"
	.string "Nhưng đó là một trận đấu hay. Ông hy\n"
	.string "vọng lần tới cháu sẽ thắng.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global RS_MysteryEventsHouse_Text_OldManGreeting
	.global RS_MysteryEventsHouse_Text_DoorIsLocked
	.global RS_MysteryEventsHouse_Text_ChallengeVisitingTrainer
	.global RS_MysteryEventsHouse_Text_YouWontBattle
	.global RS_MysteryEventsHouse_Text_KeepItToA3On3
	.global RS_MysteryEventsHouse_Text_SaveYourProgress
	.global RS_MysteryEventsHouse_Text_HopeToSeeAGoodMatch
	.global RS_MysteryEventsHouse_Text_BattleTie
	.global RS_MysteryEventsHouse_Text_BattleWon
	.global RS_MysteryEventsHouse_Text_BattleLost
@ END GENERATED LOCALIZATION EXPORTS
