Route110_SeasideCyclingRoadSouthEntrance_MapScripts::
	.byte 0

Route110_SeasideCyclingRoadSouthEntrance_EventScript_Clerk::
	lock
	faceplayer
	msgbox Route110_SeasideCyclingRoadSouthEntrance_Text_GoAllOutOnCyclingRoad, MSGBOX_DEFAULT
	release
	end

Route110_SeasideCyclingRoadSouthEntrance_EventScript_BikeCheck::
	lockall
	specialvar VAR_RESULT, GetPlayerAvatarBike
	goto_if_eq VAR_RESULT, 0, Route110_SeasideCyclingRoadSouthEntrance_EventScript_NoBike
	setflag FLAG_SYS_CYCLING_ROAD
	setvar VAR_TEMP_1, 1
	releaseall
	end

Route110_SeasideCyclingRoadSouthEntrance_EventScript_NoBike::
	msgbox Route110_SeasideCyclingRoadSouthEntrance_Text_TooDangerousToWalk, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Route110_SeasideCyclingRoadSouthEntrance_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

Route110_SeasideCyclingRoadSouthEntrance_Movement_PushPlayerBackFromCounter:
	walk_left
	step_end

Route110_SeasideCyclingRoadSouthEntrance_EventScript_ClearCyclingRoad::
	lockall
	clearflag FLAG_SYS_CYCLING_ROAD
	setvar VAR_TEMP_1, 0
	releaseall
	end

Route110_SeasideCyclingRoadSouthEntrance_Text_GoAllOutOnCyclingRoad:
	.string "Trên CYCLING ROAD, cậu có thể dốc hết\n"
	.string "sức và đạp nhanh tùy thích.\p"
	.string "Chạy nhanh như vậy rất đã, nhưng cố\n"
	.string "đừng đâm vào ai nhé!$"

Route110_SeasideCyclingRoadSouthEntrance_Text_TooDangerousToWalk:
	.string "Xin lỗi, cậu không thể đi bộ trên\n"
	.string "CYCLING ROAD. Nguy hiểm lắm.\p"
	.string "Hãy quay lại khi có BIKE.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global Route110_SeasideCyclingRoadSouthEntrance_Text_GoAllOutOnCyclingRoad
	.global Route110_SeasideCyclingRoadSouthEntrance_Text_TooDangerousToWalk
@ END GENERATED LOCALIZATION EXPORTS
