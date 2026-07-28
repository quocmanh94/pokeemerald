VictoryRoad_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VictoryRoad_1F_OnTransition
	.byte 0

VictoryRoad_1F_OnTransition:
	call_if_eq VAR_VICTORY_ROAD_1F_STATE, 1, VictoryRoad_1F_EventScript_SetEntranceWallyPos1
	call_if_eq VAR_VICTORY_ROAD_1F_STATE, 2, VictoryRoad_1F_EventScript_SetEntranceWallyPos2
	end

VictoryRoad_1F_EventScript_SetEntranceWallyPos1::
	setobjectxyperm LOCALID_VICTORY_ROAD_ENTRANCE_WALLY, 2, 24
	setobjectmovementtype LOCALID_VICTORY_ROAD_ENTRANCE_WALLY, MOVEMENT_TYPE_FACE_DOWN
	return

VictoryRoad_1F_EventScript_SetEntranceWallyPos2::
	setobjectxyperm LOCALID_VICTORY_ROAD_ENTRANCE_WALLY, 3, 24
	setobjectmovementtype LOCALID_VICTORY_ROAD_ENTRANCE_WALLY, MOVEMENT_TYPE_FACE_DOWN
	return

VictoryRoad_1F_EventScript_WallyBattleTrigger1::
	lockall
	setvar VAR_0x8008, 1
	addobject LOCALID_VICTORY_ROAD_ENTRANCE_WALLY
	applymovement LOCALID_VICTORY_ROAD_ENTRANCE_WALLY, VictoryRoad_1F_Movement_WallyApproachPlayer1
	waitmovement 0
	goto VictoryRoad_1F_EventScript_WallyEntranceBattle
	end

VictoryRoad_1F_EventScript_WallyBattleTrigger2::
	lockall
	setvar VAR_0x8008, 2
	addobject LOCALID_VICTORY_ROAD_ENTRANCE_WALLY
	applymovement LOCALID_VICTORY_ROAD_ENTRANCE_WALLY, VictoryRoad_1F_Movement_WallyApproachPlayer2
	waitmovement 0
	goto VictoryRoad_1F_EventScript_WallyEntranceBattle
	end

VictoryRoad_1F_EventScript_WallyEntranceBattle::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox VictoryRoad_1F_Text_WallyNotGoingToLoseAnymore, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WALLY_VR_1, VictoryRoad_1F_Text_WallyEntranceDefeat
	msgbox VictoryRoad_1F_Text_WallyPostEntranceBattle, MSGBOX_DEFAULT
	clearflag FLAG_HIDE_VICTORY_ROAD_ENTRANCE_WALLY
	copyobjectxytoperm LOCALID_VICTORY_ROAD_ENTRANCE_WALLY
	setflag FLAG_DEFEATED_WALLY_VICTORY_ROAD
	copyvar VAR_VICTORY_ROAD_1F_STATE, VAR_0x8008
	releaseall
	end

VictoryRoad_1F_Movement_WallyApproachPlayer1:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

VictoryRoad_1F_Movement_WallyApproachPlayer2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

@ This Wally appears near the entrance once his battle is triggered and remains there until the Hall of Fame is entered
VictoryRoad_1F_EventScript_EntranceWally::
	msgbox VictoryRoad_1F_Text_WallyPostEntranceBattle, MSGBOX_NPC
	end

@ This Wally appears and remains at the exit after the Hall of Fame is entered
VictoryRoad_1F_EventScript_ExitWally::
	trainerbattle_single TRAINER_WALLY_VR_2, VictoryRoad_1F_Text_WallyIntro, VictoryRoad_1F_Text_WallyDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, VictoryRoad_1F_EventScript_RematchWally
	msgbox VictoryRoad_1F_Text_WallyPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_RematchWally::
	trainerbattle_rematch TRAINER_WALLY_VR_2, VictoryRoad_1F_Text_WallyIntro, VictoryRoad_1F_Text_WallyDefeat
	msgbox VictoryRoad_1F_Text_WallyPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Edgar::
	trainerbattle_single TRAINER_EDGAR, VictoryRoad_1F_Text_EdgarIntro, VictoryRoad_1F_Text_EdgarDefeat
	msgbox VictoryRoad_1F_Text_EdgarPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Albert::
	trainerbattle_single TRAINER_ALBERT, VictoryRoad_1F_Text_AlbertIntro, VictoryRoad_1F_Text_AlbertDefeat
	msgbox VictoryRoad_1F_Text_AlbertPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Hope::
	trainerbattle_single TRAINER_HOPE, VictoryRoad_1F_Text_HopeIntro, VictoryRoad_1F_Text_HopeDefeat
	msgbox VictoryRoad_1F_Text_HopePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Quincy::
	trainerbattle_single TRAINER_QUINCY, VictoryRoad_1F_Text_QuincyIntro, VictoryRoad_1F_Text_QuincyDefeat
	msgbox VictoryRoad_1F_Text_QuincyPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Katelynn::
	trainerbattle_single TRAINER_KATELYNN, VictoryRoad_1F_Text_KatelynnIntro, VictoryRoad_1F_Text_KatelynnDefeat
	msgbox VictoryRoad_1F_Text_KatelynnPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_Text_WallyNotGoingToLoseAnymore:
	.string "WALLY: Chào, {PLAYER}!\p"
	.string "Chắc cậu bất ngờ khi gặp tớ ở đây!\p"
	.string "Tớ đã đi được đến tận đây, tất cả đều\n"
	.string "nhờ có cậu!\p"
	.string "{PLAYER}, lần thua cậu khi ấy đã giúp\n"
	.string "tớ mạnh mẽ hơn!\p"
	.string "Nhưng tớ sẽ không thua nữa!\p"
	.string "Tớ sẽ chiến thắng! Vì những POKéMON đã\n"
	.string "cho tớ lòng can đảm và sức mạnh!\p"
	.string "Được rồi... Tớ đến đây!$"

VictoryRoad_1F_Text_WallyEntranceDefeat:
	.string "Chà! {PLAYER}, quả nhiên cậu rất mạnh!$"

VictoryRoad_1F_Text_WallyPostEntranceBattle:
	.string "WALLY: Hôm nay tớ chưa thể thắng cậu,\n"
	.string "{PLAYER}, nhưng một ngày nào đó tớ\l"
	.string "sẽ đuổi kịp cậu!$"

VictoryRoad_1F_Text_WallyIntro:
	.string "WALLY: Chào, {PLAYER}!\p"
	.string "Tớ đã mạnh hơn kể từ lần trước! Tớ\n"
	.string "muốn cho cậu thấy điều đó, {PLAYER}!\p"
	.string "Được rồi... Tớ đến đây!$"

VictoryRoad_1F_Text_WallyDefeat:
	.string "Chà! {PLAYER}, quả nhiên cậu rất mạnh!$"

VictoryRoad_1F_Text_WallyPostBattle:
	.string "WALLY: Lần này tớ vẫn không thể thắng\n"
	.string "cậu... Nhưng một ngày nào đó,\l"
	.string "{PLAYER}, tớ sẽ đuổi kịp cậu...\p"
	.string "Và thách đấu POKéMON LEAGUE!$"

VictoryRoad_1F_Text_EdgarIntro:
	.string "Tôi đã đến được đây vài lần rồi, nhưng\n"
	.string "chặng cuối dài quá...$"

VictoryRoad_1F_Text_EdgarDefeat:
	.string "Giấc mơ của tôi lại kết thúc tại đây...$"

VictoryRoad_1F_Text_EdgarPostBattle:
	.string "Bạn đã đi được đến tận đây rồi. Hãy giữ\n"
	.string "vững khí thế và trở thành CHAMPION!\l"
	.string "Nếu có ai làm được, người đó chính là\l"
	.string "bạn!$"

VictoryRoad_1F_Text_AlbertIntro:
	.string "Tôi không đi xa đến tận đây để rồi thất\n"
	.string "bại. Chuyện đó tuyệt đối không thể xảy\l"
	.string "ra!$"

VictoryRoad_1F_Text_AlbertDefeat:
	.string "Không thể nào... Tôi đã thua sao?$"

VictoryRoad_1F_Text_AlbertPostBattle:
	.string "Tôi đã thua tại đây...\p"
	.string "Nghĩa là tôi không đủ tư cách trở\n"
	.string "thành CHAMPION...$"

VictoryRoad_1F_Text_HopeIntro:
	.string "Con đường khắc nghiệt tưởng chừng vô\n"
	.string "tận này quả xứng với chữ VICTORY\l"
	.string "trong tên gọi.$"

VictoryRoad_1F_Text_HopeDefeat:
	.string "Phong cách chiến đấu của bạn thật\n"
	.string "tuyệt vời...$"

VictoryRoad_1F_Text_HopePostBattle:
	.string "Bạn có vẻ sở hữu tiềm năng để trở\n"
	.string "thành CHAMPION.$"

VictoryRoad_1F_Text_QuincyIntro:
	.string "VICTORY ROAD là gì ư? Nếu thắng, tôi sẽ\n"
	.string "cho bạn biết!$"

VictoryRoad_1F_Text_QuincyDefeat:
	.string "Được lắm! Làm tốt lắm!$"

VictoryRoad_1F_Text_QuincyPostBattle:
	.string "Vượt qua nơi này an toàn chính là thử\n"
	.string "thách cuối cùng dành cho mọi HLV\l"
	.string "muốn trở thành POKéMON CHAMPION.\p"
	.string "Vì thế nơi này được gọi là VICTORY\n"
	.string "ROAD.$"

VictoryRoad_1F_Text_KatelynnIntro:
	.string "Tôi chẳng có gì để nói với người đã đi\n"
	.string "được đến tận đây. Lên đi!$"

VictoryRoad_1F_Text_KatelynnDefeat:
	.string "Thật nhục nhã...$"

VictoryRoad_1F_Text_KatelynnPostBattle:
	.string "Hừ, cứ việc đi tiếp đi. Tôi chẳng quan\n"
	.string "tâm.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global VictoryRoad_1F_Text_WallyNotGoingToLoseAnymore
	.global VictoryRoad_1F_Text_WallyEntranceDefeat
	.global VictoryRoad_1F_Text_WallyPostEntranceBattle
	.global VictoryRoad_1F_Text_WallyIntro
	.global VictoryRoad_1F_Text_WallyDefeat
	.global VictoryRoad_1F_Text_WallyPostBattle
	.global VictoryRoad_1F_Text_EdgarIntro
	.global VictoryRoad_1F_Text_EdgarDefeat
	.global VictoryRoad_1F_Text_EdgarPostBattle
	.global VictoryRoad_1F_Text_AlbertIntro
	.global VictoryRoad_1F_Text_AlbertDefeat
	.global VictoryRoad_1F_Text_AlbertPostBattle
	.global VictoryRoad_1F_Text_HopeIntro
	.global VictoryRoad_1F_Text_HopeDefeat
	.global VictoryRoad_1F_Text_HopePostBattle
	.global VictoryRoad_1F_Text_QuincyIntro
	.global VictoryRoad_1F_Text_QuincyDefeat
	.global VictoryRoad_1F_Text_QuincyPostBattle
	.global VictoryRoad_1F_Text_KatelynnIntro
	.global VictoryRoad_1F_Text_KatelynnDefeat
	.global VictoryRoad_1F_Text_KatelynnPostBattle
@ END GENERATED LOCALIZATION EXPORTS
