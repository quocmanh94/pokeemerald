AbandonedShip_Rooms_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, AbandonedShip_Rooms_B1F_OnResume
	.byte 0

AbandonedShip_Rooms_B1F_OnResume:
	setdivewarp MAP_ABANDONED_SHIP_UNDERWATER2, 17, 4
	end

AbandonedShip_Rooms_B1F_EventScript_FatMan::
	msgbox AbandonedShip_Rooms_B1F_Text_GettingQueasy, MSGBOX_NPC
	end

AbandonedShip_Rooms_B1F_Text_GettingQueasy:
	.string "Ựa...\p"
	.string "Chỉ cần ở trên con tàu này là tôi đã\n"
	.string "thấy buồn nôn...\p"
	.string "Nó còn chẳng di chuyển, vậy mà...$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global AbandonedShip_Rooms_B1F_Text_GettingQueasy
@ END GENERATED LOCALIZATION EXPORTS
