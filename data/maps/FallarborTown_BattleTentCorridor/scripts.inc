FallarborTown_BattleTentCorridor_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FallarborTown_BattleTentCorridor_OnFrame
	.byte 0

FallarborTown_BattleTentCorridor_OnFrame:
	map_script_2 VAR_TEMP_0, 0, FallarborTown_BattleTentCorridor_EventScript_EnterCorridor
	.2byte 0

FallarborTown_BattleTentCorridor_EventScript_EnterCorridor::
	lockall
	setvar VAR_TEMP_0, 1
	applymovement LOCALID_FALLARBOR_TENT_CORRIDOR_ATTENDANT, FallarborTown_BattleTentCorridor_Movement_WalkToDoor
	applymovement LOCALID_PLAYER, FallarborTown_BattleTentCorridor_Movement_WalkToDoor
	waitmovement 0
	opendoor 2, 1
	waitdooranim
	applymovement LOCALID_FALLARBOR_TENT_CORRIDOR_ATTENDANT, FallarborTown_BattleTentCorridor_Movement_AttendantEnterDoor
	applymovement LOCALID_PLAYER, FallarborTown_BattleTentCorridor_Movement_PlayerEnterDoor
	waitmovement 0
	closedoor 2, 1
	waitdooranim
	setvar VAR_0x8006, 0
	warp MAP_FALLARBOR_TOWN_BATTLE_TENT_BATTLE_ROOM, 4, 4
	waitstate
	releaseall
	end

FallarborTown_BattleTentCorridor_Movement_WalkToDoor:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

FallarborTown_BattleTentCorridor_Movement_PlayerEnterDoor:
	walk_up
FallarborTown_BattleTentCorridor_Movement_AttendantEnterDoor:
	walk_up
	set_invisible
	step_end

@ Leftover text from when this was a Contest Hall in R/S
@ Unused
FallarborTown_ContestHall_Text_DoAllRightInPreliminary:
	.string "Chúng tôi làm khá tốt ở vòng sơ khảo,\n"
	.string "nhưng chẳng bao giờ thắng được phần\l"
	.string "biểu diễn...\p"
	.string "Có lẽ tôi cần chú ý xem các thí sinh\n"
	.string "khác đang làm gì...$"

@ Unused
FallarborTown_ContestHall_Text_MonAllTheseRibbons:
	.string "Nhìn này! POKéMON của tôi đã giành\n"
	.string "được tất cả số RIBBONS này!\p"
	.string "POKéMON của bạn đã giành được RIBBONS\n"
	.string "nào chưa? Bạn có thể kiểm tra trên\l"
	.string "POKéNAV.$"

@ Unused
FallarborTown_ContestHall_Text_CantWinEverywhere:
	.string "Tôi không thể đánh bại GYM LEADERS...\p"
	.string "Tôi cũng chẳng thắng nổi các cuộc thi\n"
	.string "nào...\p"
	.string "Tôi đã đi khắp nơi, nhưng tất cả đều vô\n"
	.string "ích...$"

@ Unused
FallarborTown_ContestHall_Text_SuperRankStage:
	.string "SÂN KHẤU SUPER RANK CỦA POKéMON\n"
	.string "CONTESTS!$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global FallarborTown_ContestHall_Text_DoAllRightInPreliminary
	.global FallarborTown_ContestHall_Text_MonAllTheseRibbons
	.global FallarborTown_ContestHall_Text_CantWinEverywhere
	.global FallarborTown_ContestHall_Text_SuperRankStage
@ END GENERATED LOCALIZATION EXPORTS
