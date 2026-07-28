BattleFrontier_BattleTowerMultiPartnerRoom_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattleTowerMultiPartnerRoom_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattleTowerMultiPartnerRoom_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleTowerMultiPartnerRoom_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleTowerMultiPartnerRoom_OnFrame
	.byte 0

BattleFrontier_BattleTowerMultiPartnerRoom_OnResume:
	pyramid_resetparty
	end

BattleFrontier_BattleTowerMultiPartnerRoom_OnTransition:
	goto_if_set FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ChosePartner
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_1
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_2
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_3
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_4
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_5
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_6
	setflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_ALT_1
	setflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_ALT_2
	tower_loadpartners
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ChosePartner::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_2, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_3, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_4, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_5, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_6, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_7, OBJ_EVENT_GFX_BOY_1
	setvar VAR_TEMP_1, 1
	setvar VAR_TEMP_3, 1
	setobjectxyperm LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, 10, 2
	end

BattleFrontier_BattleTowerMultiPartnerRoom_OnWarp:
	map_script_2 VAR_TEMP_3, 1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TurnPlayerNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattleTowerMultiPartnerRoom_OnFrame:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterRoom
	map_script_2 VAR_TEMP_3, 1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ExitRoom
	.2byte 0

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ExitRoom::
	lockall
	setvar VAR_TEMP_3, 0
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterElevator
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterRoom::
	lockall
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterRoom
	waitmovement 0
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantBlockExit
	waitmovement 0
	copyobjectxytoperm LOCALID_TOWER_PARTNER_ROOM_ATTENDANT
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner, MSGBOX_DEFAULT
	special HealPlayerParty
	setvar VAR_TEMP_1, 1
	releaseall
	end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterRoom:
	walk_down
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantBlockExit:
	walk_left
	walk_in_place_faster_down
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Attendant::
	lock
	faceplayer
	message BattleFrontier_BattleTowerMultiPartnerRoom_Text_QuitLookingForPartner
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_QuitChallenge
	msgbox BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner2, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_QuitChallenge::
	frontier_set FRONTIER_DATA_RECORD_DISABLED, TRUE
	goto BattleFrontier_BattleTower_EventScript_WarpToLobbyLost
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterElevator::
	msgbox BattleFrontier_BattleTowerMultiPartnerRoom_Text_ThankYouForChoosingPartner, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	opendoor 10, 1
	waitdooranim
	call BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevator
	closedoor 10, 1
	waitdooranim
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_ELEVATOR, 1, 6
	waitstate
	releaseall
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevator::
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevator
	waitmovement 0
	return

@ Unused
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevatorEast:
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevatorEast
	waitmovement 0
	return

@ Unused
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevatorWest:
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevatorWest
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevator:
	walk_up
	walk_up
	set_invisible
	step_end

@ Functionally unused
BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevatorEast:
	walk_right
	walk_up
	set_invisible
	step_end

@ Functionally unused
BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevatorWest:
	walk_left
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator:
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner1::
	lock
	faceplayer
	setvar VAR_TEMP_2, 0
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner::
	goto_if_set FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner
	tower_dopartnermsg PARTNER_MSGID_INTRO
	waitmessage
	waitbuttonpress
	tower_dopartnermsg PARTNER_MSGID_MON1
	waitmessage
	waitbuttonpress
	tower_dopartnermsg PARTNER_MSGID_MON2_ASK
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner
	tower_dopartnermsg PARTNER_MSGID_ACCEPT
	waitmessage
	waitbuttonpress
	closemessage
	call_if_ne VAR_FACING, DIR_SOUTH, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExit
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExitSouth
	removeobject VAR_LAST_TALKED
	setflag FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_TOWER_MULTI_PARTNER_ROOM, 10, 3
	waitstate
	release
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner::
	tower_dopartnermsg PARTNER_MSGID_REJECT
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExit::
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExit
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExitSouth::
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExitSouth
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExit:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExitSouth:
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner2::
	lock
	faceplayer
	setvar VAR_TEMP_2, 1
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner3::
	lock
	faceplayer
	setvar VAR_TEMP_2, 2
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner4::
	lock
	faceplayer
	setvar VAR_TEMP_2, 3
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner5::
	lock
	faceplayer
	setvar VAR_TEMP_2, 4
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner6::
	lock
	faceplayer
	setvar VAR_TEMP_2, 5
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner7::
	lock
	faceplayer
	setvar VAR_TEMP_2, 6
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner8::
	lock
	faceplayer
	setvar VAR_TEMP_2, 7
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner:
	.string "Vui lòng tìm một đồng đội trong số\n"
	.string "HLV đang tập trung tại đây.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_QuitLookingForPartner:
	.string "{PLAYER}, bạn vẫn chưa tìm được\n"
	.string "đồng đội.\p"
	.string "Bạn có muốn ngừng tìm và quay lại quầy\n"
	.string "tiếp tân không?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner2:
	.string "Vậy xin hãy tìm một đồng đội trong số\n"
	.string "HLV đang tập trung tại đây.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ThankYouForChoosingPartner::
	.string "Cảm ơn bạn đã chọn được đồng đội.\p"
	.string "Bây giờ tôi sẽ đưa bạn đến MULTI\n"
	.string "BATTLE ROOM.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Intro::
	.string "Tôi là học trò của {STR_VAR_1}, số\n"
	.string "{STR_VAR_2}. Cứ gọi tôi là\l"
	.string "{STR_VAR_3}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Mon1::
	.string "Theo lời khuyên của {STR_VAR_1},\n"
	.string "tôi đã mang theo một {STR_VAR_3}\l"
	.string "có {STR_VAR_2} và$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Mon2Ask::
	.string "một {STR_VAR_2} có\n"
	.string "{STR_VAR_1}.\p"
	.string "Xin hãy lập đội đôi cùng tôi.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Accept::
	.string "Cảm ơn! Tôi sẽ đi đăng ký ngay.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Reject::
	.string "Tôi thực sự rất muốn lập đội với bạn,\n"
	.string "{PLAYER}...$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Intro::
	.string "Tôi là học trò của {STR_VAR_1}, số\n"
	.string "{STR_VAR_2}. Tên tôi là\l"
	.string "{STR_VAR_3}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Mon1::
	.string "Tôi đã nghe lời khuyên từ\n"
	.string "{STR_VAR_1} và chọn một\l"
	.string "{STR_VAR_3} có\l"
	.string "{STR_VAR_2}, cùng với$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Mon2Ask::
	.string "một {STR_VAR_2} có\n"
	.string "{STR_VAR_1}.\p"
	.string "Xin hãy lập đội đôi với tôi!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Accept::
	.string "Cảm ơn bạn rất nhiều! Tôi sẽ đăng ký\n"
	.string "xong ngay thôi!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Reject::
	.string "{PLAYER}, tôi đã hy vọng có thể làm\n"
	.string "đồng đội của bạn...$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Intro::
	.string "Ừm, tôi tên là {STR_VAR_3}, và tôi\n"
	.string "là học trò của {STR_VAR_1}, số\l"
	.string "{STR_VAR_2}.\p"
	.string "Sụt sịt...\p"
	.string "Xin lỗi! Không khí căng thẳng này làm\n"
	.string "tôi phát khóc...$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Mon1::
	.string "{STR_VAR_3} đã khuyên tôi, nên\n"
	.string "tôi có một {STR_VAR_2} biết\l"
	.string "{STR_VAR_1} và$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Mon2Ask::
	.string "một {STR_VAR_2} biết\n"
	.string "{STR_VAR_1}.\p"
	.string "Sụt sịt... Xin bạn, hãy lập đội với tôi!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Accept::
	.string "Ôi, thật sao? Bạn đồng ý ư? Tuyệt quá!\n"
	.string "Hết sảy! A hú!\p"
	.string "Ôi... Xin lỗi... Tôi vui quá nên khóc mất\n"
	.string "rồi...\p"
	.string "Tôi sẽ đi đăng ký ngay. Xin đừng đi đâu\n"
	.string "nhé!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Reject::
	.string "Ôi, n-nhưng... Hức... Oaaaaa!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Intro::
	.string "Chào bạn! Tôi là {STR_VAR_3}! Tôi\n"
	.string "là học trò của {STR_VAR_1}, số\l"
	.string "{STR_VAR_2}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Mon1::
	.string "{STR_VAR_3} đã gợi ý đội hình\n"
	.string "này cho tôi. Một {STR_VAR_2} có\l"
	.string "{STR_VAR_1} và$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Mon2Ask::
	.string "một {STR_VAR_2} có\n"
	.string "{STR_VAR_1}, đó là đội của tôi!\l"
	.string "Tuyệt chứ?\p"
	.string "Nào! Hãy lập đội đôi với tôi!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Accept::
	.string "Hoan hô! Tuyệt lắm! Được rồi, tôi đi\n"
	.string "đăng ký nhé?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Reject::
	.string "Ơ, sao vậy? Tôi muốn lập đội với bạn mà,\n"
	.string "{PLAYER}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Intro::
	.string "Tôi là {STR_VAR_3}, học trò số\n"
	.string "{STR_VAR_2} của\l"
	.string "{STR_VAR_1} nổi tiếng!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Mon1::
	.string "Tôi đã xin {STR_VAR_3} lời\n"
	.string "khuyên. Với {STR_VAR_1}, tôi chọn\l"
	.string "một {STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Mon2Ask::
	.string "và một {STR_VAR_2} có\n"
	.string "{STR_VAR_1}, đó là cặp của tôi.\p"
	.string "Xin hãy lập đội đôi cùng tôi nhé?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Accept::
	.string "Cảm ơn! Tôi sẽ đi đăng ký ngay!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Reject::
	.string "{PLAYER}, tôi đã mong được lập đội\n"
	.string "đôi cùng bạn...$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Intro::
	.string "Ừm... Tôi thực sự rất vui vì bạn đã dành\n"
	.string "thời gian nói chuyện với tôi.\p"
	.string "Tôi là {STR_VAR_3}. Tôi là học trò\n"
	.string "của {STR_VAR_1}, số\l"
	.string "{STR_VAR_2}...$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Mon1::
	.string "{STR_VAR_3} đã cho tôi lời\n"
	.string "khuyên. Tôi rất biết ơn.\p"
	.string "Đội của tôi gồm một {STR_VAR_2}\n"
	.string "có {STR_VAR_1} và$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Mon2Ask::
	.string "một {STR_VAR_2} có\n"
	.string "{STR_VAR_1}. Tôi biết mình đang\l"
	.string "đòi hỏi nhiều...\p"
	.string "Tôi không nghĩ bạn sẽ đồng ý, nhưng tôi\n"
	.string "có thể làm đồng đội của bạn không?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Accept::
	.string "Thật sao? Tôi không thể tin được!\n"
	.string "Không thể tin là bạn cho tôi đi cùng!\l"
	.string "Tôi... Tôi sẽ không làm bạn thất vọng!\p"
	.string "Ừm... Nếu thực sự được, tôi sẽ đi đăng\n"
	.string "ký ngay lập tức!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Reject::
	.string "Ôi... Tôi đã nghĩ mình không đủ giỏi...$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Intro::
	.string "Xin chào, tôi là {STR_VAR_3}. Tôi\n"
	.string "là học trò của {STR_VAR_1}, số\l"
	.string "{STR_VAR_2}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Mon1::
	.string "{STR_VAR_3} bảo tôi rằng dùng\n"
	.string "{STR_VAR_1} cho một\l"
	.string "{STR_VAR_2} sẽ tạo nên đội hình\l"
	.string "rất ổn$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Mon2Ask::
	.string "và một {STR_VAR_2} biết sử dụng\n"
	.string "{STR_VAR_1}.\p"
	.string "Không tệ chứ? Muốn tôi lập đội với bạn\n"
	.string "không?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Accept::
	.string "Được, rất vui được đi cùng bạn! Mong\n"
	.string "là bạn đừng làm hỏng chuyện của tôi!\l"
	.string "Tôi sẽ đi đăng ký ngay.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Reject::
	.string "Hả? Sao bạn lại từ chối tôi? Bạn chẳng\n"
	.string "biết nhìn người gì cả!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Intro::
	.string "Tôi là {STR_VAR_3}, một\n"
	.string "TRIATHLETE. Ngày nào tôi cũng bận rộn\l"
	.string "với chạy bộ, luyện tập và rap.\p"
	.string "Tôi cũng tình cờ là học trò của\n"
	.string "{STR_VAR_1}, số\l"
	.string "{STR_VAR_2}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Mon1::
	.string "Đây là đề xuất của {STR_VAR_3}:\n"
	.string "dùng {STR_VAR_1} cho một\l"
	.string "{STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Mon2Ask::
	.string "và dùng {STR_VAR_1} cho một\n"
	.string "{STR_VAR_2}.\p"
	.string "Dù bận rộn, tôi vẫn bỏ rất nhiều công\n"
	.string "sức nuôi dạy chúng.\p"
	.string "Hãy lập đội đôi và thử sức cùng nhau!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Accept::
	.string "Cảm ơn, phải thế chứ! Chờ tôi đi đăng\n"
	.string "ký nhé?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Reject::
	.string "Tôi đã bớt thời gian khỏi lịch trình bận\n"
	.string "rộn để tới đây đấy! Đừng quá đáng chứ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Intro::
	.string "Chào! Dạo này thế nào?\p"
	.string "Tôi là {STR_VAR_3}, học trò của\n"
	.string "{STR_VAR_1}, số\l"
	.string "{STR_VAR_2}. Rất vui được gặp\l"
	.string "bạn!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Mon1::
	.string "Nghe này, nghe này! Bạn phải nghe về\n"
	.string "những POKéMON mà {STR_VAR_3} đã\l"
	.string "đề xuất. Một {STR_VAR_2} có\l"
	.string "{STR_VAR_1} và$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Mon2Ask::
	.string "một {STR_VAR_2} có\n"
	.string "{STR_VAR_1}. Tất nhiên tôi đã\l"
	.string "nuôi dạy chúng cực kỳ xuất sắc!\p"
	.string "Vậy muốn lập đội không? Tôi chắc chắn\n"
	.string "chúng ta sẽ phối hợp rất ăn ý!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Accept::
	.string "Hoan hô, chắc sẽ vui lắm đây! Tôi đi\n"
	.string "đăng ký nhé!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Reject::
	.string "Ôi, bạn thật xấu tính! Tôi được đích\n"
	.string "thân giới thiệu đấy nhé.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Intro::
	.string "Xin phép được tự giới thiệu. Tôi là\n"
	.string "{STR_VAR_3}.\p"
	.string "Tôi là học trò của {STR_VAR_1}, số\n"
	.string "{STR_VAR_2}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Mon1::
	.string "Tôi đã tìm đến lời khuyên sáng suốt của\n"
	.string "{STR_VAR_3} và huấn luyện đội\l"
	.string "của mình gồm một {STR_VAR_2} có\l"
	.string "{STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Mon2Ask::
	.string "và một {STR_VAR_2} có\n"
	.string "{STR_VAR_1}.\p"
	.string "Xin hãy đồng ý lập đội đôi với tôi!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Accept::
	.string "Ôi... Tôi rất vui! Tôi hứa sẽ cố gắng hết\n"
	.string "sức!\p"
	.string "Tất nhiên tôi sẽ đi đăng ký cho chúng\n"
	.string "ta! Xin hãy chờ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Reject::
	.string "Tôi đã hy vọng được đi cùng bạn,\n"
	.string "{PLAYER}...$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Intro::
	.string "Á! Bạn đã bắt chuyện với tôi! Tôi... Tôi\n"
	.string "vui quá!\p"
	.string "Tôi là {STR_VAR_3}! Tôi là học trò\n"
	.string "của {STR_VAR_1}, số\l"
	.string "{STR_VAR_2}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Mon1::
	.string "Theo lời khuyên của {STR_VAR_3},\n"
	.string "với {STR_VAR_1}, tôi đã huấn\l"
	.string "luyện một {STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Mon2Ask::
	.string "và huấn luyện cách dùng\n"
	.string "{STR_VAR_1} cho một\l"
	.string "{STR_VAR_2}.\p"
	.string "Xin bạn hãy biến điều ước của tôi thành\n"
	.string "sự thật! Tôi muốn làm đồng đội của bạn!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Accept::
	.string "Á! Tôi... Tôi lâng lâng quá! Cảm ơn bạn\n"
	.string "rất nhiều! Tôi sẽ đi đăng ký cho chúng\l"
	.string "ta ngay!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Reject::
	.string "Oaaaa! Bạn không thấy thương tôi chút\n"
	.string "nào sao? Nhưng như thế lại khiến bạn\l"
	.string "ngầu hơn...$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Intro::
	.string "Yeehaw! Tôi là học trò của\n"
	.string "{STR_VAR_1}, số\l"
	.string "{STR_VAR_2}!\p"
	.string "Tên tôi là {STR_VAR_3}, xin chào,\n"
	.string "xin chào!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Mon1::
	.string "Sư phụ {STR_VAR_3} của tôi đề\n"
	.string "xuất: bậc thầy về {STR_VAR_1},\l"
	.string "một {STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Mon2Ask::
	.string "và một bậc thầy về {STR_VAR_1},\n"
	.string "một {STR_VAR_2}.\p"
	.string "Hay chứ? Bạn sẽ làm đồng đội của tôi,\n"
	.string "phải không?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Accept::
	.string "Được, tuyệt lắm! Tôi sẽ đăng ký thật\n"
	.string "nhanh!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Reject::
	.string "Gwaaah! Bạn tính toán ghê đấy,\n"
	.string "{PLAYER}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Intro::
	.string "Này! Có chuyện lớn rồi! Hôm nay là ngày\n"
	.string "cuối cùng của BATTLE TOWER!\p"
	.string ".......... Tôi chỉ đùa thôi!\p"
	.string "Mọi người gọi tôi là {STR_VAR_3},\n"
	.string "tôi cũng tự gọi mình thế! Tôi là học trò\l"
	.string "thứ 1.000 của {STR_VAR_1}! Thật\l"
	.string "ra là số {STR_VAR_2}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Mon1::
	.string "{STR_VAR_3} đã cho tôi vài lời\n"
	.string "khuyên. {STR_VAR_2} có\l"
	.string "{STR_VAR_1} và$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Mon2Ask::
	.string "{STR_VAR_2} có\n"
	.string "{STR_VAR_1}. Tôi có mười con mỗi\l"
	.string "loại! Thật ra chỉ một con mỗi loại thôi!\p"
	.string "Thế nào? Muốn thử đấu đôi phối hợp\n"
	.string "cùng tôi không?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Accept::
	.string "Yippee! Để cảm ơn, tôi sẽ tặng bạn một\n"
	.string "POKéMON!\p"
	.string "Đùa thôi! Nhưng tôi thực sự sẽ đi đăng\n"
	.string "ký, được chứ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Reject::
	.string "Ôi, lạnh lùng quá! Tôi sẽ phá tan BATTLE\n"
	.string "TOWER vì chuyện này!\p"
	.string "Tất nhiên là không rồi!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Intro::
	.string "Yo, tôi lắc lư theo nhạc, điều khiển\n"
	.string "POKéMON cực khác!\p"
	.string "Tôi là {STR_VAR_3}, SAILOR mê rap.\n"
	.string "Đừng nhầm tôi với kẻ chỉ biết kêu ca!\p"
	.string "Tôi là học trò của {STR_VAR_1}, số\n"
	.string "{STR_VAR_2}. Đừng vội xem\l"
	.string "thường tôi!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Mon1::
	.string "Nghe lời khuyên của {STR_VAR_3},\n"
	.string "tôi làm theo, lập nên đội hình đáng tự\l"
	.string "hào! Với {STR_VAR_1}, tôi chọn\l"
	.string "một {STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Mon2Ask::
	.string "và với {STR_VAR_1}, tôi chọn một\n"
	.string "{STR_VAR_2}!\p"
	.string "Hãy kỷ niệm cuộc gặp này bằng một\n"
	.string "chiến thắng đấu đôi huy hoàng!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Accept::
	.string "Này, này, gu của bạn thật hợp ý tôi!\n"
	.string "Đăng ký để tôi lo thôi!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Reject::
	.string "Ôi, này, {PLAYER}, lạnh lùng quá đấy!\n"
	.string "Cho tôi mạnh dạn nói vậy nhé!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Intro::
	.string "Yippee-yahoo! Ối, đừng chạy! Tôi chỉ\n"
	.string "đang đùa vui thôi!\p"
	.string "Xin chào! Tôi là {STR_VAR_3}! Tôi\n"
	.string "là học trò của {STR_VAR_1}, số\l"
	.string "{STR_VAR_2}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Mon1::
	.string "{STR_VAR_3} đã bảo tôi nên làm\n"
	.string "gì. Vì vậy, tôi chọn một\l"
	.string "{STR_VAR_2} dùng\l"
	.string "{STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Mon2Ask::
	.string "và một {STR_VAR_2} dùng\n"
	.string "{STR_VAR_1}.\p"
	.string "Cậu thấy sao? Đồng ý đi, cho tôi vui\n"
	.string "nào!\p"
	.string "Xin cậu đấy! Hãy cho tôi tham gia, đừng\n"
	.string "để tôi buồn thiu!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Accept::
	.string "Yê-hê! May mắn đứng về phía tôi! Vui\n"
	.string "quá đi mất!\p"
	.string "Trước khi ra trận, tôi sẽ đi đăng ký\n"
	.string "ngay!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Reject::
	.string "Cậu từ chối tôi sao? {PLAYER}, cậu làm\n"
	.string "tôi buồn thiu rồi!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Intro::
	.string "Khụ!\p"
	.string "Ồ, xin lỗi, tôi bị cảm. Nhưng POKéMON của\n"
	.string "tôi vẫn khỏe.\p"
	.string "Tôi là {STR_VAR_3}, học trò số\n"
	.string "{STR_VAR_2} của\l"
	.string "{STR_VAR_1}. Khụ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Mon1::
	.string "Tôi ghi nhớ lời khuyên của\n"
	.string "{STR_VAR_3} và lập đội gồm một\l"
	.string "{STR_VAR_2} có\l"
	.string "{STR_VAR_1}, cùng$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Mon2Ask::
	.string "một {STR_VAR_2} có\n"
	.string "{STR_VAR_1}.\p"
	.string "Ngày nào tôi cũng huấn luyện chúng, dù\n"
	.string "mưa hay gió.\p"
	.string "Chắc vì vậy mà tôi bị cảm.\p"
	.string "Tôi là thế đấy. Cậu muốn làm đồng đội\n"
	.string "đấu đôi với tôi không?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Accept::
	.string "Cảm ơn, tôi trân trọng lắm! Khụ, khụ!\n"
	.string "Chờ tôi đi đăng ký nhé.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Reject::
	.string "Ồ, không sao? {PLAYER}, tôi nghĩ\n"
	.string "chúng ta sẽ là một cặp ăn ý đấy.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Intro::
	.string "Ồ, xin chào! Hồi hộp quá.\p"
	.string "Tôi là {STR_VAR_3}. Tôi là học trò\n"
	.string "số {STR_VAR_2} của\l"
	.string "{STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Mon1::
	.string "{STR_VAR_3} bảo đội hình này sẽ\n"
	.string "ổn: một {STR_VAR_2} có\l"
	.string "{STR_VAR_1}, cùng$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Mon2Ask::
	.string "một {STR_VAR_2} có\n"
	.string "{STR_VAR_1}.\p"
	.string "Tôi hơi ngại, nhưng cậu cho tôi tham gia\n"
	.string "cùng nhé?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Accept::
	.string "Ôi, cảm ơn cậu! Tôi hơi xấu hổ, nhưng sẽ\n"
	.string "cố hết sức!\p"
	.string "Tôi đi đăng ký đây.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Reject::
	.string "Ôi, xin đừng từ chối! Tôi đã ngại lắm\n"
	.string "rồi...$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Intro::
	.string "Tôi là {STR_VAR_3}, lời này không\n"
	.string "sai. Tôi là học trò số {STR_VAR_2}\l"
	.string "của {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Mon1::
	.string "{STR_VAR_3} đã đề xuất đội hình\n"
	.string "cho tôi.\p"
	.string "Lời khuyên nghe rất chân thành, nên tôi\n"
	.string "quyết định mang theo một\l"
	.string "{STR_VAR_2} dùng\l"
	.string "{STR_VAR_1}, cùng$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Mon2Ask::
	.string "một {STR_VAR_2} dùng\n"
	.string "{STR_VAR_1}.\p"
	.string "Nếu có thể, tôi mong cậu nhận tôi làm\n"
	.string "đồng đội đấu đôi.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Accept::
	.string "Cậu thật sự chấp nhận tôi sao? Nếu\n"
	.string "không thì thật tệ quá.\p"
	.string "Nhưng cậu đã đồng ý, vậy là ổn. Tôi sẽ\n"
	.string "đi đăng ký cho cả hai chúng ta.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Reject::
	.string "Hửm? Sao cậu lại từ chối? Cậu đang đùa\n"
	.string "tôi đấy à?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassIntro::
	.string "Tớ là {STR_VAR_1}, một LASS!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassMon1::
	.string "Tớ có một {STR_VAR_2} dùng\n"
	.string "{STR_VAR_1}, cùng một$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassMon2Ask::
	.string "{STR_VAR_2} dùng\n"
	.string "{STR_VAR_1}. Tớ mang theo hai\l"
	.string "bạn ấy.\p"
	.string "Cậu làm đồng đội của tớ nhé?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassAccept::
	.string "Cảm ơn cậu! Tớ đi đăng ký đây!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassReject::
	.string "Cậu không muốn làm đồng đội của tớ\n"
	.string "sao? Sau này cậu sẽ tiếc đấy!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterIntro::
	.string "Xin chào!\p"
	.string "Tớ là YOUNGSTER {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterMon1::
	.string "Muốn biết tớ có gì không? Một\n"
	.string "{STR_VAR_2} có\l"
	.string "{STR_VAR_1}, cùng$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterMon2Ask::
	.string "một {STR_VAR_2} có\n"
	.string "{STR_VAR_1}!\p"
	.string "Cậu sẽ làm đồng đội đấu đôi của tớ,\n"
	.string "đúng không?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterAccept::
	.string "Tuyệt! Tớ đi đăng ký nhé?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterReject::
	.string "Ôi! Nếu cậu lập đội với POKéMON của tớ,\n"
	.string "chúng ta sẽ bất khả chiến bại!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerIntro::
	.string "Yahoo! Tôi là HIKER {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerMon1::
	.string "Biết tôi mang theo gì không? Một\n"
	.string "{STR_VAR_2} dùng\l"
	.string "{STR_VAR_1}, cùng$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerMon2Ask::
	.string "một {STR_VAR_2} dùng\n"
	.string "{STR_VAR_1}!\p"
	.string "Nghe ổn chứ? Muốn lập đội đấu đôi\n"
	.string "không?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerAccept::
	.string "Yahoo! Vậy tôi đi đăng ký đây.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerReject::
	.string "Tôi đã rất muốn chiến đấu khi có cậu bên\n"
	.string "cạnh.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyIntro::
	.string "Xin chào! Tôi là {STR_VAR_1}, một\n"
	.string "BEAUTY!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyMon1::
	.string "Cậu biết tôi đã nuôi những gì không?\n"
	.string "Một {STR_VAR_2} có\l"
	.string "{STR_VAR_1}, cùng$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyMon2Ask::
	.string "một {STR_VAR_2} có\n"
	.string "{STR_VAR_1}!\p"
	.string "Cậu thấy sao? Muốn cùng tôi lập đội đấu\n"
	.string "đôi không?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyAccept::
	.string "Tuyệt vời! Tôi sẽ đi đăng ký ngay!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyReject::
	.string "Thật đáng thất vọng!\p"
	.string "Hai chúng ta mà kết hợp thì đã là tuyệt\n"
	.string "nhất rồi!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanIntro::
	.string "Này!\p"
	.string "Biết tôi là ai không? Tôi là FISHERMAN\n"
	.string "{STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanMon1::
	.string "Đội tôi mang theo gồm một\n"
	.string "{STR_VAR_2} dùng\l"
	.string "{STR_VAR_1}, cùng$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanMon2Ask::
	.string "một {STR_VAR_2} dùng\n"
	.string "{STR_VAR_1}.\p"
	.string "Sao nào? Cậu sẽ chiến đấu bên cạnh tôi\n"
	.string "chứ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanAccept::
	.string "Tốt, tốt lắm! Cứ để tôi lo!\p"
	.string "Tôi đi đăng ký cho cả hai ngay đây.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanReject::
	.string "Chúng ta hợp nhau hoàn hảo thế mà...$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyIntro::
	.string "Rất hân hạnh được làm quen. Tôi là\n"
	.string "{STR_VAR_1}, một LADY.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyMon1::
	.string "Đi cùng tôi là một đội gồm một\n"
	.string "{STR_VAR_2} có\l"
	.string "{STR_VAR_1}, cùng$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyMon2Ask::
	.string "một {STR_VAR_2} có\n"
	.string "{STR_VAR_1}.\p"
	.string "Mong tôi được cậu chấp thuận, vì tôi\n"
	.string "muốn cậu làm đồng đội của mình.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyAccept::
	.string "Tôi chân thành cảm ơn. Tôi sẽ lo việc\n"
	.string "đăng ký.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyReject::
	.string "Tôi chắc cậu sẽ hối tiếc vì không chọn\n"
	.string "tôi làm đồng đội.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFIntro::
	.string "Tôi là TRIATHLETE {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFMon1::
	.string "Tôi có... Một {STR_VAR_2} có\n"
	.string "{STR_VAR_1}, cùng$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFMon2Ask::
	.string "một {STR_VAR_2} có\n"
	.string "{STR_VAR_1}! Đó là cặp của tôi!\p"
	.string "Làm ơn nhé? Cậu sẽ lập đội đấu đôi với\n"
	.string "tôi chứ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFAccept::
	.string "Ôi, cảm ơn! Tôi sẽ ra quầy đăng ký.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFReject::
	.string "Hai chúng ta mà kết hợp thì chắc chắn\n"
	.string "sẽ rất mạnh!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherIntro::
	.string "Chào nhé! Tớ là BUG CATCHER\n"
	.string "{STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherMon1::
	.string "Xem tớ có gì này! Một\n"
	.string "{STR_VAR_2} có\l"
	.string "{STR_VAR_1}, cùng$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherMon2Ask::
	.string "một {STR_VAR_2} có\n"
	.string "{STR_VAR_1}!\p"
	.string "Này, nghe tớ nói! Cậu có muốn lập đội\n"
	.string "đấu đôi không?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherAccept::
	.string "Bắt được cậu rồi!\p"
	.string "Tớ sẽ ra quầy làm thủ tục đăng ký.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherReject::
	.string "Ôi, POKéMON của tớ tuyệt lắm đấy. Hy\n"
	.string "vọng cậu không hối hận!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMIntro::
	.string "Xin chào! Tớ là SCHOOL KID\n"
	.string "{STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMMon1::
	.string "Tớ đã nuôi một {STR_VAR_2} dùng\n"
	.string "{STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMMon2Ask::
	.string "và một {STR_VAR_2} dùng\n"
	.string "{STR_VAR_1}.\p"
	.string "Cũng không tệ, đúng không? Cậu có muốn\n"
	.string "lập đội đấu đôi không?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMAccept::
	.string "Cảm ơn cậu rất nhiều! Tớ sẽ đi đăng ký.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMReject::
	.string "Tiếc quá...\p"
	.string "Tớ đã hy vọng có thể làm đồng đội và\n"
	.string "học hỏi từ cậu...$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyIntro::
	.string "Này! Để tôi cho cậu biết tôi là ai! Tôi là\n"
	.string "RICH BOY {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyMon1::
	.string "Đoán xem tôi có gì! Một\n"
	.string "{STR_VAR_2} có\l"
	.string "{STR_VAR_1}, cùng$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyMon2Ask::
	.string "một {STR_VAR_2} có\n"
	.string "{STR_VAR_1}!\p"
	.string "Tôi sẵn lòng cho cậu cơ hội được lập\n"
	.string "đội đấu đôi với tôi.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyAccept::
	.string "Lựa chọn sáng suốt!\p"
	.string "Tôi sẽ nhanh chóng hoàn tất thủ tục\n"
	.string "đăng ký!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyReject::
	.string "Cậu lại từ chối chính tôi sao? Cậu chắc\n"
	.string "chắn sẽ hối hận vì quyết định đó!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltIntro::
	.string "Hây da! Tôi là BLACK BELT\n"
	.string "{STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltMon1::
	.string "Đồng hành cùng tôi là một\n"
	.string "{STR_VAR_2} dùng\l"
	.string "{STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltMon2Ask::
	.string "và một {STR_VAR_2} dùng\n"
	.string "{STR_VAR_1}.\p"
	.string "Xin hãy cho tôi được toại nguyện! Hãy\n"
	.string "cho phép tôi làm đồng đội đấu đôi của\l"
	.string "cậu!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltAccept::
	.string "Hây da! Tôi sẽ đi đăng ký ngay lập tức!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltReject::
	.string "Tôi hiểu rồi... Hy vọng lần sau gặp lại,\n"
	.string "tôi sẽ có cơ hội...$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFIntro::
	.string "Xin chào! Tớ là {STR_VAR_1}, một\n"
	.string "TUBER!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFMon1::
	.string "Tớ sẽ cho cậu biết tớ có gì. Một\n"
	.string "{STR_VAR_2} có\l"
	.string "{STR_VAR_1}, cùng$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFMon2Ask::
	.string "một {STR_VAR_2} có\n"
	.string "{STR_VAR_1}! Cho tớ vào đội đấu\l"
	.string "đôi của cậu nhé?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFAccept::
	.string "Cảm ơn cậu! Tớ đi đăng ký cho chúng ta\n"
	.string "ngay đây!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFReject::
	.string "Nếu làm đồng đội, chúng ta đã có thể\n"
	.string "mạnh lắm!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacIntro::
	.string "Xin chào... Tôi là HEX MANIAC\n"
	.string "{STR_VAR_1}...$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacMon1::
	.string "Tôi mang theo một {STR_VAR_2}\n"
	.string "dùng {STR_VAR_1}, cùng với một$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacMon2Ask::
	.string "{STR_VAR_2} dùng\n"
	.string "{STR_VAR_1}...\p"
	.string "Tôi khẩn cầu cậu... Hãy lập đội đấu đôi\n"
	.string "cùng tôi...$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacAccept::
	.string "Cảm ơn cậu... Tôi sẽ đi đăng ký cho\n"
	.string "chúng ta...$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacReject::
	.string "Tôi đã mong mỏi được đi cùng cậu biết\n"
	.string "bao...$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMIntro::
	.string "Xin chào! Tôi là {STR_VAR_1}, một\n"
	.string "POKéMON BREEDER!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMMon1::
	.string "Tôi đang nuôi hai bạn rất khá! Một\n"
	.string "{STR_VAR_2} có\l"
	.string "{STR_VAR_1}, cùng$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMMon2Ask::
	.string "một {STR_VAR_2} có\n"
	.string "{STR_VAR_1}!\p"
	.string "Sao nào? Muốn lập đội đấu đôi với tôi\n"
	.string "không?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMAccept::
	.string "Cảm ơn cậu nhiều!\p"
	.string "Tôi sẽ lo thủ tục đăng ký, cậu cứ đợi\n"
	.string "ngay đây nhé!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMReject::
	.string "Tôi đã rất mong được làm đồng đội của\n"
	.string "cậu...$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFIntro::
	.string "Ồ, xin chào! Tôi là TRIATHLETE\n"
	.string "{STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFMon1::
	.string "Muốn biết tôi chạy cùng những ai\n"
	.string "không? Một {STR_VAR_2} có\l"
	.string "{STR_VAR_1}, cùng$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFMon2Ask::
	.string "một {STR_VAR_2} có\n"
	.string "{STR_VAR_1}!\p"
	.string "Sao nào? Muốn lập đội đấu đôi với tôi\n"
	.string "không?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFAccept::
	.string "Tốt lắm!\p"
	.string "Tôi sẽ nhanh chóng hoàn tất đăng ký!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFReject::
	.string "Cậu và tôi đã có thể đứng đầu. Tiếc\n"
	.string "thật...$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMIntro::
	.string "Chào nhé! Tôi tên {STR_VAR_1}!\n"
	.string "Tôi là TRIATHLETE!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMMon1::
	.string "Tôi chạy cùng đội hình bền bỉ của mình:\n"
	.string "một {STR_VAR_2} có\l"
	.string "{STR_VAR_1}, cùng$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMMon2Ask::
	.string "một {STR_VAR_2} có\n"
	.string "{STR_VAR_1}!\p"
	.string "Khá ổn, nhỉ? Chúng ta nên lập đội đấu\n"
	.string "đôi cùng nhau!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMAccept::
	.string "Được rồi! Tôi sẽ đi đăng ký trong nháy\n"
	.string "mắt!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMReject::
	.string "Tôi thật sự muốn chiến đấu với tư cách\n"
	.string "đồng đội đấu đôi của cậu...$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlIntro::
	.string "Tớ là BATTLE GIRL {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlMon1::
	.string "Tớ đã dày công rèn luyện chiêu\n"
	.string "{STR_VAR_1} cho một\l"
	.string "{STR_VAR_2} và$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlMon2Ask::
	.string "chiêu {STR_VAR_1} cho một\n"
	.string "{STR_VAR_2} nữa!\p"
	.string "Cậu thấy bộ đôi đó thế nào? Hay cậu bắt\n"
	.string "cặp với tớ nhé?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlAccept::
	.string "Ôi, cảm ơn nhé!\p"
	.string "Tớ sẽ đi đăng ký ngay bây giờ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlReject::
	.string "Tớ đã nghĩ hai chúng ta có thể trở\n"
	.string "thành đội đánh đôi vô địch...$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMIntro::
	.string "Tôi là TRIATHLETE {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMMon1::
	.string "Tôi đã đồng hành cùng một\n"
	.string "{STR_VAR_2} biết dùng\l"
	.string "{STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMMon2Ask::
	.string "và một {STR_VAR_2} có\n"
	.string "{STR_VAR_1}!\p"
	.string "Chúng ta có thể lập đội đánh đôi. Tuyệt\n"
	.string "quá còn gì?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMAccept::
	.string "Cảm ơn cậu!\p"
	.string "Tôi sẽ đi đăng ký cho cả hai ngay bây\n"
	.string "giờ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMReject::
	.string "Ôi, tiếc thật. Chúng ta đã có thể trở\n"
	.string "thành đội đánh đôi mạnh nhất đấy!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMIntro::
	.string "Tớ á? Tớ là TUBER {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMMon1::
	.string "Tớ mang theo gì à? Một\n"
	.string "{STR_VAR_2} có\l"
	.string "{STR_VAR_1} và$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMMon2Ask::
	.string "một {STR_VAR_2} có\n"
	.string "{STR_VAR_1}!\p"
	.string "Này? Cậu sẽ bắt cặp với tớ, đúng\n"
	.string "không?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMAccept::
	.string "Được rồi!\p"
	.string "Tớ sẽ đi đăng ký! Cùng nhau thi đấu\n"
	.string "thật xuất sắc nhé!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMReject::
	.string "POKéMON của tớ mạnh lắm đấy... Tiếc là\n"
	.string "cậu không muốn bắt cặp với tớ.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristIntro::
	.string "Yeah-hê! Cứ gọi tôi là GUITARIST\n"
	.string "{STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristMon1::
	.string "Xem ban nhạc của tôi này! Một\n"
	.string "{STR_VAR_2} có\l"
	.string "{STR_VAR_1} và$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristMon2Ask::
	.string "một {STR_VAR_2} có\n"
	.string "{STR_VAR_1}!\p"
	.string "Yeah-hê! Chất lắm, đúng không? Chúng\n"
	.string "ta phải lập đội đánh đôi để song tấu\l"
	.string "thôi!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristAccept::
	.string "Yeah-hê! Quá chuẩn! Tôi sẽ đi lo vụ đăng\n"
	.string "ký ngay!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristReject::
	.string "POKéMON của tôi chất rock cực đỉnh!\n"
	.string "Rồi cậu sẽ tiếc cho xem!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanIntro::
	.string "Rất hân hạnh được gặp cậu. Tôi là\n"
	.string "{STR_VAR_1}, một GENTLEMAN.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanMon1::
	.string "Đi cùng tôi là một người bạn đáng tin\n"
	.string "biết dùng {STR_VAR_1}, đó là\l"
	.string "{STR_VAR_2}, và$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanMon2Ask::
	.string "một người bạn dùng {STR_VAR_1},\n"
	.string "đó là {STR_VAR_2}.\p"
	.string "Liệu tôi có thể mời cậu cùng lập một đội\n"
	.string "đánh đôi không?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanAccept::
	.string "À, cảm ơn vì cậu đã tin tưởng. Tôi sẽ\n"
	.string "hoàn tất việc đăng ký.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanReject::
	.string "Quả là đáng tiếc...\p"
	.string "Tôi sẽ mong chờ cơ hội tiếp theo...$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMIntro::
	.string "Xin chào, tôi là {STR_VAR_1}, một\n"
	.string "POKéFAN.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMMon1::
	.string "Hiện tôi mang theo một\n"
	.string "{STR_VAR_2} biết chiêu\l"
	.string "{STR_VAR_1} và$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMMon2Ask::
	.string "một {STR_VAR_2} có\n"
	.string "{STR_VAR_1}.\p"
	.string "Cậu thấy chúng thế nào? Sao không làm\n"
	.string "đồng đội đánh đôi của tôi?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMAccept::
	.string "Cảm ơn cậu! Tôi sẽ lo việc đăng ký!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMReject::
	.string "POKéMON của tôi đều thuộc hàng ưu tú...\n"
	.string "Tiếc là cậu không nhận ra điều đó.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMIntro::
	.string "Hừm! Ta là {STR_VAR_1}, một\n"
	.string "EXPERT chính hiệu!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMMon1::
	.string "Những POKéMON ta đã rèn luyện gồm một\n"
	.string "{STR_VAR_2} có\l"
	.string "{STR_VAR_1} và$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMMon2Ask::
	.string "một {STR_VAR_2} có\n"
	.string "{STR_VAR_1}!\p"
	.string "Cậu thấy sao nếu lập đội đánh đôi với\n"
	.string "ta?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMAccept::
	.string "Hừm! Ta sẽ đăng ký cho cả hai ngay!\n"
	.string "Chúng ta cùng cố hết sức!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMReject::
	.string "Ta chỉ mong lựa chọn của cậu quả thực\n"
	.string "là đúng...$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFIntro::
	.string "Xin chào, xin chào. Tôi là\n"
	.string "{STR_VAR_1}, một EXPERT.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFMon1::
	.string "Tôi đã nuôi dạy POKéMON rất kỹ lưỡng.\n"
	.string "Một {STR_VAR_2} có\l"
	.string "{STR_VAR_1} và$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFMon2Ask::
	.string "một {STR_VAR_2} có\n"
	.string "{STR_VAR_1}. Đó là đội của tôi.\p"
	.string "Cậu có muốn bắt cặp với tôi không?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFAccept::
	.string "Tốt, tốt. Tôi sẽ lo việc đăng ký ngay.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFReject::
	.string "Có lẽ lần tới gặp nhau, chúng ta có thể\n"
	.string "lập đội.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerIntro::
	.string "Tôi là DRAGON TAMER {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerMon1::
	.string "Đội mà tôi đã rèn luyện gồm một\n"
	.string "{STR_VAR_2} có\l"
	.string "{STR_VAR_1} và$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerMon2Ask::
	.string "một {STR_VAR_2} có\n"
	.string "{STR_VAR_1}!\p"
	.string "Thế nào? Muốn làm đồng đội của tôi\n"
	.string "không?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerAccept::
	.string "Được, tôi sẽ cố hết sức! Tôi đi đăng ký\n"
	.string "ngay nhé?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerReject::
	.string "Cậu khó mà tìm được đồng đội nào mạnh\n"
	.string "hơn tôi đấy!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperIntro::
	.string "Tôi là BIRD KEEPER {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperMon1::
	.string "Tôi có những POKéMON nào à? Một\n"
	.string "{STR_VAR_2} có\l"
	.string "{STR_VAR_1} và$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperMon2Ask::
	.string "một {STR_VAR_2} có\n"
	.string "{STR_VAR_1}.\p"
	.string "Cậu không nghĩ chúng ta sẽ thành một\n"
	.string "đội đánh đôi khá ổn sao?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperAccept::
	.string "Tuyệt, cảm ơn cậu! Tôi sẽ lo việc đăng\n"
	.string "ký!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperReject::
	.string "POKéMON của tôi và tôi đều rất mạnh.\n"
	.string "Thất vọng thật.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyIntro::
	.string "Tớ là NINJA BOY {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyMon1::
	.string "Đội POKéMON của tớ gồm một\n"
	.string "{STR_VAR_2} có\l"
	.string "{STR_VAR_1} và$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyMon2Ask::
	.string "một {STR_VAR_2} có\n"
	.string "{STR_VAR_1}!\p"
	.string "Cùng tớ lập đội đánh đôi nhé!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyAccept::
	.string "Hoan hô! Để tớ đi đăng ký!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyReject::
	.string "Cậu sẽ hối hận vì không có những\n"
	.string "POKéMON mạnh mẽ của tớ bên cạnh!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyIntro::
	.string "Xin chào! Tôi là PARASOL LADY\n"
	.string "{STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyMon1::
	.string "Đang tháp tùng tôi là một\n"
	.string "{STR_VAR_2} biết dùng\l"
	.string "{STR_VAR_1} và$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyMon2Ask::
	.string "một {STR_VAR_2} biết dùng\n"
	.string "{STR_VAR_1}.\p"
	.string "Chúng tuyệt lắm, phải không? Cậu muốn\n"
	.string "cùng chúng tôi lập đội đánh đôi chứ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyAccept::
	.string "Cảm ơn cậu nhiều!\p"
	.string "Tôi sẽ đến quầy đăng ký. Chúng ta đừng\n"
	.string "làm nhau thất vọng nhé!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyReject::
	.string "POKéMON của tôi mạnh khủng khiếp đấy.\n"
	.string "Thất vọng quá...$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacIntro::
	.string "Xin chào. Tôi là {STR_VAR_1}, một\n"
	.string "BUG MANIAC!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacMon1::
	.string "Đúng vậy, tôi đã tìm thấy những\n"
	.string "POKéMON của mình. Một\l"
	.string "{STR_VAR_2} có\l"
	.string "{STR_VAR_1} và$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacMon2Ask::
	.string "một {STR_VAR_2} có\n"
	.string "{STR_VAR_1}. Đó là những gì tôi\l"
	.string "tìm được.\p"
	.string "Cậu có hứng thú lập đội đánh đôi\n"
	.string "không?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacAccept::
	.string "Được! Tôi hiểu rồi!\p"
	.string "Tôi sẽ đăng ký nhanh thôi!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacReject::
	.string "Với những POKéMON tôi tìm được, chúng\n"
	.string "ta đã chẳng thể thua...$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorIntro::
	.string "Chào thủy thủ! Tôi là SAILOR\n"
	.string "{STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorMon1::
	.string "Để tôi khoe niềm tự hào của mình! Một\n"
	.string "{STR_VAR_2} có\l"
	.string "{STR_VAR_1} và$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorMon2Ask::
	.string "một {STR_VAR_2} có\n"
	.string "{STR_VAR_1}!\p"
	.string "Tất nhiên cậu sẽ không từ chối tôi rồi.\n"
	.string "Chúng ta sẽ lập đội, đúng chứ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorAccept::
	.string "Đúng như tôi mong đợi! Tôi sẽ đi đăng\n"
	.string "ký ngay.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorReject::
	.string "Chúng ta đã có thể quét sạch mọi đối\n"
	.string "thủ! Tiếc thật!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorIntro::
	.string "Chào, tôi là {STR_VAR_1}. Tôi là\n"
	.string "một COLLECTOR.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorMon1::
	.string "Những viên ngọc trong bộ sưu tập của\n"
	.string "tôi là một {STR_VAR_2} có\l"
	.string "{STR_VAR_1} và$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorMon2Ask::
	.string "một {STR_VAR_2} có\n"
	.string "{STR_VAR_1}!\p"
	.string "Tuyệt chứ? Chúng ta nên lập đội cùng\n"
	.string "nhau.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorAccept::
	.string "Ồ, tuyệt!\p"
	.string "Đừng phí thời gian nữa. Tôi sẽ đi đăng\n"
	.string "ký cho cả hai.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorReject::
	.string "Chà, buồn thật đấy. Cậu không biết trân\n"
	.string "trọng POKéMON của tôi.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMIntro::
	.string "Chào nhé, tôi là {STR_VAR_1}. Tôi\n"
	.string "là một POKéMON RANGER.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMMon1::
	.string "Đồng hành cùng tôi là một người bạn\n"
	.string "biết dùng {STR_VAR_1}, đó là\l"
	.string "{STR_VAR_2}, và$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMMon2Ask::
	.string "một {STR_VAR_2} có\n"
	.string "{STR_VAR_1}!\p"
	.string "Cậu không nghĩ chúng ta sẽ thành một\n"
	.string "đội đánh đôi đầy ấn tượng sao?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMAccept::
	.string "Tuyệt quá! Tôi sẽ lo việc đăng ký ngay.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMReject::
	.string "Lần tới hãy chọn POKéMON của tôi nhé?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFIntro::
	.string "Tên tôi là {STR_VAR_1}. Tôi là một\n"
	.string "POKéMON RANGER!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFMon1::
	.string "Để tôi giới thiệu đội của mình. Tôi có\n"
	.string "một {STR_VAR_2} có\l"
	.string "{STR_VAR_1} và$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFMon2Ask::
	.string "một {STR_VAR_2} có\n"
	.string "{STR_VAR_1}!\p"
	.string "Cậu có muốn cùng nhóm nhỏ của tôi lập\n"
	.string "đội đánh đôi không?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFAccept::
	.string "Chúng ta sẽ phát huy hết sức mạnh! Tôi\n"
	.string "sẽ đăng ký thật nhanh!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFReject::
	.string "Hy vọng lần tới cậu sẽ chọn POKéMON của\n"
	.string "tôi.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyIntro::
	.string "Rất hân hạnh được gặp cậu. Tôi là\n"
	.string "{STR_VAR_1}. Tôi tự nhận mình là\l"
	.string "một AROMA LADY.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyMon1::
	.string "Tôi đi cùng một {STR_VAR_2} biết\n"
	.string "dùng {STR_VAR_1} và$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyMon2Ask::
	.string "một {STR_VAR_2} biết dùng\n"
	.string "{STR_VAR_1}.\p"
	.string "Mong rằng chúng hợp ý cậu. Cậu có muốn\n"
	.string "làm đồng đội của tôi không?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyAccept::
	.string "Tôi rất vinh dự khi cậu đồng ý. Tôi sẽ đi\n"
	.string "đăng ký ngay lập tức.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyReject::
	.string "Thật tuyệt nếu lần tới gặp nhau, chúng\n"
	.string "ta có thể lập đội đánh đôi.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacIntro::
	.string "Muốn biết tôi là ai sao? Tôi là\n"
	.string "{STR_VAR_1}, RUIN MANIAC!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacMon1::
	.string "Những POKéMON tôi mang theo gồm một\n"
	.string "{STR_VAR_2} có\l"
	.string "{STR_VAR_1} và$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacMon2Ask::
	.string "một {STR_VAR_2} có\n"
	.string "{STR_VAR_1}!\p"
	.string "Thú vị chứ? Cậu và tôi bắt cặp nhé?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacAccept::
	.string "Một quyết định sáng suốt! Tôi sẽ đi làm\n"
	.string "thủ tục đăng ký.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacReject::
	.string "Hừm... Tôi nghĩ POKéMON của mình mạnh\n"
	.string "lắm mà...$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMIntro::
	.string "Tôi là COOLTRAINER {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMMon1::
	.string "Những POKéMON tôi đang có gồm một\n"
	.string "{STR_VAR_2} có\l"
	.string "{STR_VAR_1} và$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMMon2Ask::
	.string "một {STR_VAR_2} có\n"
	.string "{STR_VAR_1}. Ngầu chứ?\p"
	.string "Cậu không nghĩ chúng ta lập đội đánh\n"
	.string "đôi sẽ cực ngầu sao?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMAccept::
	.string "Ngầu đấy! Tôi sẽ đi đăng ký trong chớp\n"
	.string "mắt!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMReject::
	.string "Tôi đã nghĩ chúng ta sẽ trở thành đội\n"
	.string "tuyệt vời nhất từ trước đến nay.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFIntro::
	.string "Tôi là COOLTRAINER {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFMon1::
	.string "Đội hình tôi đã dày công huấn luyện gồm\n"
	.string "một {STR_VAR_2} có\l"
	.string "{STR_VAR_1} và$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFMon2Ask::
	.string "một {STR_VAR_2} có\n"
	.string "{STR_VAR_1}.\p"
	.string "Nghe ổn chứ? Chúng ta lập đội đôi nhé?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFAccept::
	.string "Tuyệt hảo! Tôi phải đi đăng ký ngay.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFReject::
	.string "Tôi đã nghĩ chúng ta sẽ thành một đội\n"
	.string "cực mạnh cơ.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacIntro::
	.string "Chào nhé! Tôi là {STR_VAR_1},\n"
	.string "POKéMANIAC!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacMon1::
	.string "Một người như tôi có gì ư? Một\n"
	.string "{STR_VAR_2} có\l"
	.string "{STR_VAR_1} và$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacMon2Ask::
	.string "một {STR_VAR_2} có\n"
	.string "{STR_VAR_1}, chứ còn gì nữa!\p"
	.string "Triển thôi! Ta sẽ tung hoành với tư\n"
	.string "cách đội đôi!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacAccept::
	.string "Quyết định hay lắm! Tôi sẽ đăng ký cho\n"
	.string "cả hai chúng ta!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacReject::
	.string "POKéMON của tôi dữ dằn lắm! Có hối hận\n"
	.string "thì cũng đừng trách tôi!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerIntro::
	.string "Chào nhé! Tôi là KINDLER\n"
	.string "{STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerMon1::
	.string "Biết công sức huấn luyện của tôi đã cho\n"
	.string "ra lò gì không? Một {STR_VAR_2}\l"
	.string "có {STR_VAR_1} và$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerMon2Ask::
	.string "một {STR_VAR_2} có\n"
	.string "{STR_VAR_1}!\p"
	.string "Sao nào? Muốn lập đội đôi chứ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerAccept::
	.string "Được rồi! Tôi sẽ đi đăng ký.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerReject::
	.string "Hứa là lần sau gặp nhau, bạn sẽ lập đội\n"
	.string "với tôi nhé.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperIntro::
	.string "Tôi là {STR_VAR_1}, một CAMPER!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperMon1::
	.string "Trong đội tôi nuôi, {STR_VAR_1} là\n"
	.string "chiêu của một {STR_VAR_2}, còn$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperMon2Ask::
	.string "{STR_VAR_1} là chiêu của một\n"
	.string "{STR_VAR_2} khác.\p"
	.string "Bạn nghĩ lập đội cùng nhau sẽ vui\n"
	.string "không? Tôi cá là có!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperAccept::
	.string "Hay quá! Tôi đi đăng ký đây!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperReject::
	.string "Lần sau nhé? Tôi muốn vào đội của bạn.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerIntro::
	.string "Xin chào! Tôi là {STR_VAR_1}, một\n"
	.string "PICNICKER!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerMon1::
	.string "Các POKéMON tôi mang theo gồm một\n"
	.string "{STR_VAR_2} có\l"
	.string "{STR_VAR_1} và$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerMon2Ask::
	.string "một {STR_VAR_2} có\n"
	.string "{STR_VAR_1}.\p"
	.string "Bạn có muốn cùng tôi lập đội đôi không?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerAccept::
	.string "Ôi, cảm ơn bạn! Tôi sẽ đi đăng ký ngay.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerReject::
	.string "Mong là lần khác tôi có thể tham gia\n"
	.string "cùng bạn.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMIntro::
	.string "Tôi là PSYCHIC {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMMon1::
	.string "Cặp POKéMON tôi đã nuôi gồm một\n"
	.string "{STR_VAR_2} có\l"
	.string "{STR_VAR_1} và$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMMon2Ask::
	.string "một {STR_VAR_2} có\n"
	.string "{STR_VAR_1}.\p"
	.string "Bạn có muốn lập đội đôi với tôi không?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMAccept::
	.string "Được chứ! Tôi sẽ lo việc đăng ký!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMReject::
	.string "Nếu gặp lại, lúc đó tôi muốn lập đội cùng\n"
	.string "bạn.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFIntro::
	.string "Tôi là {STR_VAR_1}. Tôi là một\n"
	.string "PSYCHIC.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFMon1::
	.string "Một {STR_VAR_2} có\n"
	.string "{STR_VAR_1} và$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFMon2Ask::
	.string "một {STR_VAR_2} có\n"
	.string "{STR_VAR_1}. Chúng là các môn đồ\l"
	.string "của tôi.\p"
	.string "Ý tưởng lập đội đôi không khiến bạn\n"
	.string "thấy hứng thú sao?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFAccept::
	.string "Cảm ơn. Tôi sẽ đi lo việc đăng ký.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFReject::
	.string "Tôi hy vọng chúng ta sẽ còn dịp kết\n"
	.string "thành đồng minh.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFIntro::
	.string "Tôi là SCHOOL KID {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFMon1::
	.string "{STR_VAR_1} là chiêu của một\n"
	.string "{STR_VAR_2},$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFMon2Ask::
	.string "còn {STR_VAR_1} là chiêu của một\n"
	.string "{STR_VAR_2} khác. Đó là cặp\l"
	.string "POKéMON của tôi.\p"
	.string "Cho tôi làm cộng sự trong đội đôi của\n"
	.string "bạn nhé?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFAccept::
	.string "Ôi, cảm ơn bạn! Tôi sẽ đăng ký tại quầy\n"
	.string "ngay!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFReject::
	.string "Làm ơn nhé? Lần sau cho tôi tham gia\n"
	.string "cùng được không?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFIntro::
	.string "Chào nhé! Tôi tên {STR_VAR_1}!\n"
	.string "Tôi là POKéMON BREEDER!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFMon1::
	.string "Trong số POKéMON tôi nuôi,\n"
	.string "{STR_VAR_1} là chiêu của một\l"
	.string "{STR_VAR_2}, còn$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFMon2Ask::
	.string "{STR_VAR_1} là chiêu của một\n"
	.string "{STR_VAR_2} khác.\p"
	.string "Nghe thú vị chứ? Vậy chúng ta lập đội\n"
	.string "đôi nhé?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFAccept::
	.string "Được thôi! Cứ để tôi lo việc đăng ký!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFReject::
	.string "Lần sau nhất định phải lập đội với tôi\n"
	.string "đấy, được chứ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFIntro::
	.string "Tôi là {STR_VAR_1}, và tôi tự hào\n"
	.string "mình là một POKéFAN.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFMon1::
	.string "Các POKéMON cưng tôi nuôi gồm một\n"
	.string "{STR_VAR_2} có\l"
	.string "{STR_VAR_1} và$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFMon2Ask::
	.string "một {STR_VAR_2} có\n"
	.string "{STR_VAR_1}.\p"
	.string "Chúng đáng yêu quá phải không? Chúng\n"
	.string "ta nên lập đội!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFAccept::
	.string "Cảm ơn nhé, cưng! Tôi đi đăng ký đây!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFReject::
	.string "Các POKéMON cưng của tôi là tuyệt nhất,\n"
	.string "cho bạn biết đấy. Thật bực mình!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFIntro::
	.string "Xin chào, tôi là SWIMMER\n"
	.string "{STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFMon1::
	.string "{STR_VAR_1} là chiêu của một\n"
	.string "{STR_VAR_2},$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFMon2Ask::
	.string "còn {STR_VAR_1} là chiêu của một\n"
	.string "{STR_VAR_2} khác mà tôi đã huấn\l"
	.string "luyện.\p"
	.string "Bạn và tôi, hãy lập đội đôi nhé.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFAccept::
	.string "Tuyệt đấy! Tôi sẽ đăng ký cho cả hai\n"
	.string "chúng ta.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFReject::
	.string "Nếu gặp lại, bạn nợ tôi một lần lập đội\n"
	.string "đôi đấy!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMIntro::
	.string "Có gì vui không? Tôi là\n"
	.string "{STR_VAR_1}, một TRIATHLETE.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMMon1::
	.string "Tôi có một cặp POKéMON khá ổn. Một\n"
	.string "{STR_VAR_2} có\l"
	.string "{STR_VAR_1} và$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMMon2Ask::
	.string "một {STR_VAR_2} có\n"
	.string "{STR_VAR_1}!\p"
	.string "Chúng ta lập đội đôi chắc sẽ hay lắm,\n"
	.string "bạn thấy sao?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMAccept::
	.string "Quá chuẩn! Chờ tôi đăng ký nhé?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMReject::
	.string "Lần sau bạn phải cho tôi tham gia đấy,\n"
	.string "được chứ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFIntro::
	.string "Tôi là TRIATHLETE {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFMon1::
	.string "Một {STR_VAR_2} có\n"
	.string "{STR_VAR_1} và$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFMon2Ask::
	.string "một {STR_VAR_2} khác biết dùng\n"
	.string "{STR_VAR_1}. Đó là cặp POKéMON\l"
	.string "của tôi.\p"
	.string "Bạn thấy sao? Tôi nghĩ chúng ta sẽ\n"
	.string "thành một đội ăn ý.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFAccept::
	.string "Tôi thích câu trả lời đó! Tôi sẽ đăng ký\n"
	.string "thật nhanh!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFReject::
	.string "Bạn sẽ cho tôi thêm một cơ hội lập đội\n"
	.string "cùng chứ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMIntro::
	.string "Xin chào! Chào bạn! Tôi là\n"
	.string "{STR_VAR_1}, một SWIMMER!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMMon1::
	.string "Xem những gì tôi đã nuôi này! Một\n"
	.string "{STR_VAR_2} có\l"
	.string "{STR_VAR_1} và$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMMon2Ask::
	.string "một {STR_VAR_2} có\n"
	.string "{STR_VAR_1}!\p"
	.string "Tuyệt chứ? Lập đội cùng nhau cũng sẽ\n"
	.string "tuyệt lắm!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMAccept::
	.string "Đa tạ nhé! Tôi sẽ xử lý xong vụ đăng ký\n"
	.string "này!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMReject::
	.string "Nếu gặp lại, bạn phải lập đội với tôi\n"
	.string "đấy. Bạn sẽ làm vậy, đúng không?$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_QuitLookingForPartner
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner2
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_ThankYouForChoosingPartner
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Intro
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Mon1
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Mon2Ask
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Accept
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Reject
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Intro
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Mon1
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Mon2Ask
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Accept
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Reject
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Intro
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Mon1
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Mon2Ask
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Accept
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Reject
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Intro
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Mon1
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Mon2Ask
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Accept
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Reject
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Intro
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Mon1
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Mon2Ask
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Accept
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Reject
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Intro
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Mon1
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Mon2Ask
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Accept
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Reject
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Intro
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Mon1
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Mon2Ask
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Accept
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Reject
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Intro
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Mon1
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Mon2Ask
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Accept
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Reject
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Intro
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Mon1
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Mon2Ask
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Accept
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Reject
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Intro
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Mon1
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Mon2Ask
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Accept
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Reject
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Intro
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Mon1
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Mon2Ask
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Accept
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Reject
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Intro
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Mon1
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Mon2Ask
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Accept
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Reject
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Intro
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Mon1
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Mon2Ask
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Accept
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Reject
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Intro
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Mon1
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Mon2Ask
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Accept
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Reject
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Intro
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Mon1
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Mon2Ask
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Accept
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Reject
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Intro
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Mon1
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Mon2Ask
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Accept
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Reject
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Intro
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Mon1
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Mon2Ask
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Accept
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Reject
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Intro
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Mon1
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Mon2Ask
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Accept
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Reject
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassIntro
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassMon1
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassMon2Ask
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassAccept
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassReject
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterIntro
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterMon1
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterMon2Ask
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterAccept
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterReject
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerIntro
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerMon1
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerMon2Ask
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerAccept
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerReject
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyIntro
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyMon1
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyMon2Ask
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyAccept
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyReject
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanIntro
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanMon1
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanMon2Ask
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanAccept
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanReject
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyIntro
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyMon1
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyMon2Ask
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyAccept
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyReject
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFIntro
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFMon1
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFMon2Ask
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFAccept
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFReject
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherIntro
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherMon1
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherMon2Ask
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherAccept
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherReject
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMIntro
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMMon1
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMMon2Ask
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMAccept
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMReject
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyIntro
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyMon1
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyMon2Ask
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyAccept
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyReject
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltIntro
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltMon1
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltMon2Ask
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltAccept
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltReject
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFIntro
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFMon1
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFMon2Ask
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFAccept
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFReject
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacIntro
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacMon1
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacMon2Ask
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacAccept
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacReject
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMIntro
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMMon1
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMMon2Ask
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMAccept
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMReject
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFIntro
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFMon1
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFMon2Ask
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFAccept
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFReject
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMIntro
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMMon1
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMMon2Ask
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMAccept
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMReject
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlIntro
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlMon1
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlMon2Ask
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlAccept
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlReject
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMIntro
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMMon1
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMMon2Ask
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMAccept
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMReject
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMIntro
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMMon1
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMMon2Ask
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMAccept
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMReject
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristIntro
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristMon1
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristMon2Ask
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristAccept
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristReject
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanIntro
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanMon1
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanMon2Ask
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanAccept
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanReject
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMIntro
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMMon1
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMMon2Ask
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMAccept
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMReject
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMIntro
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMMon1
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMMon2Ask
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMAccept
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMReject
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFIntro
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFMon1
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFMon2Ask
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFAccept
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFReject
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerIntro
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerMon1
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerMon2Ask
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerAccept
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerReject
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperIntro
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperMon1
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperMon2Ask
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperAccept
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperReject
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyIntro
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyMon1
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyMon2Ask
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyAccept
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyReject
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyIntro
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyMon1
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyMon2Ask
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyAccept
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyReject
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacIntro
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacMon1
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacMon2Ask
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacAccept
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacReject
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorIntro
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorMon1
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorMon2Ask
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorAccept
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorReject
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorIntro
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorMon1
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorMon2Ask
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorAccept
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorReject
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMIntro
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMMon1
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMMon2Ask
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMAccept
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMReject
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFIntro
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFMon1
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFMon2Ask
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFAccept
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFReject
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyIntro
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyMon1
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyMon2Ask
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyAccept
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyReject
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacIntro
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacMon1
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacMon2Ask
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacAccept
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacReject
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMIntro
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMMon1
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMMon2Ask
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMAccept
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMReject
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFIntro
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFMon1
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFMon2Ask
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFAccept
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFReject
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacIntro
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacMon1
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacMon2Ask
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacAccept
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacReject
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerIntro
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerMon1
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerMon2Ask
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerAccept
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerReject
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperIntro
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperMon1
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperMon2Ask
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperAccept
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperReject
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerIntro
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerMon1
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerMon2Ask
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerAccept
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerReject
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMIntro
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMMon1
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMMon2Ask
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMAccept
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMReject
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFIntro
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFMon1
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFMon2Ask
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFAccept
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFReject
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFIntro
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFMon1
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFMon2Ask
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFAccept
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFReject
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFIntro
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFMon1
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFMon2Ask
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFAccept
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFReject
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFIntro
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFMon1
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFMon2Ask
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFAccept
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFReject
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFIntro
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFMon1
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFMon2Ask
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFAccept
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFReject
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMIntro
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMMon1
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMMon2Ask
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMAccept
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMReject
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFIntro
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFMon1
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFMon2Ask
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFAccept
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFReject
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMIntro
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMMon1
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMMon2Ask
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMAccept
	.global BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMReject
@ END GENERATED LOCALIZATION EXPORTS
