LittlerootTown_BrendansHouse_1F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, LittlerootTown_BrendansHouse_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_BrendansHouse_1F_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_BrendansHouse_1F_OnFrame
	.byte 0

LittlerootTown_BrendansHouse_1F_OnLoad:
	call_if_lt VAR_LITTLEROOT_INTRO_STATE, 6, LittlerootTown_BrendansHouse_1F_EventScript_SetMovingBoxes
	call_if_set FLAG_RECEIVED_RUNNING_SHOES, LittlerootTown_BrendansHouse_1F_EventScript_CheckShowShoesManual
	end

LittlerootTown_BrendansHouse_1F_EventScript_SetMovingBoxes::
	setmetatile 5, 4, METATILE_BrendansMaysHouse_MovingBox_Open, TRUE
	setmetatile 5, 2, METATILE_BrendansMaysHouse_MovingBox_Closed, TRUE
	return

LittlerootTown_BrendansHouse_1F_EventScript_CheckShowShoesManual::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, LittlerootTown_BrendansHouse_1F_EventScript_ShowRunningShoesManual
	return

LittlerootTown_BrendansHouse_1F_EventScript_ShowRunningShoesManual::
	setmetatile 3, 7, METATILE_BrendansMaysHouse_BookOnTable, TRUE
	return

LittlerootTown_BrendansHouse_1F_OnTransition:
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 3, LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToDoor
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 5, LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToStairs
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 6, LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToTV
	end

LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToStairs::
	setobjectxyperm LOCALID_PLAYERS_HOUSE_1F_MOM, 8, 4
	setobjectmovementtype LOCALID_PLAYERS_HOUSE_1F_MOM, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToTV::
	setobjectxyperm LOCALID_PLAYERS_HOUSE_1F_MOM, 4, 5
	setobjectmovementtype LOCALID_PLAYERS_HOUSE_1F_MOM, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToDoor::
	setobjectxyperm LOCALID_PLAYERS_HOUSE_1F_MOM, 9, 8
	setobjectmovementtype LOCALID_PLAYERS_HOUSE_1F_MOM, MOVEMENT_TYPE_FACE_UP
	return

@ Many of the below scripts have no gender check because they assume youre in the correct house
@ The below SS Ticket script uses Mays house state by accident(?), but theyre both set identically after the intro
LittlerootTown_BrendansHouse_1F_OnFrame:
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 3, LittlerootTown_BrendansHouse_1F_EventScript_EnterHouseMovingIn
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 5, LittlerootTown_BrendansHouse_1F_EventScript_GoUpstairsToSetClock
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 6, LittlerootTown_BrendansHouse_1F_EventScript_PetalburgGymReport
	map_script_2 VAR_LITTLEROOT_HOUSES_STATE_MAY, 1, LittlerootTown_BrendansHouse_1F_EventScript_YoureNewNeighbor
	map_script_2 VAR_LITTLEROOT_HOUSES_STATE_MAY, 3, PlayersHouse_1F_EventScript_GetSSTicketAndSeeLatiTV
	.2byte 0

LittlerootTown_BrendansHouse_1F_EventScript_GoUpstairsToSetClock::
	lockall
	msgbox PlayersHouse_1F_Text_GoSetTheClock, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PushTowardStairs
	applymovement LOCALID_PLAYERS_HOUSE_1F_MOM, LittlerootTown_BrendansHouse_1F_Movement_PushTowardStairs
	waitmovement 0
	warp MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F, 7, 1
	waitstate
	releaseall
	end

LittlerootTown_BrendansHouse_1F_Movement_PushTowardStairs:
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_EnterHouseMovingIn::
	lockall
	setvar VAR_0x8004, LOCALID_PLAYERS_HOUSE_1F_MOM
	setvar VAR_0x8005, MALE
	goto PlayersHouse_1F_EventScript_EnterHouseMovingIn
	end

LittlerootTown_BrendansHouse_1F_EventScript_PetalburgGymReport::
	lockall
	setvar VAR_0x8004, MALE
	setvar VAR_0x8005, LOCALID_PLAYERS_HOUSE_1F_MOM
	goto PlayersHouse_1F_EventScript_PetalburgGymReportMale
	end

LittlerootTown_BrendansHouse_1F_EventScript_YoureNewNeighbor::
	lockall
	playse SE_PIN
	applymovement LOCALID_RIVALS_HOUSE_1F_MOM, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVALS_HOUSE_1F_MOM, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_RIVALS_HOUSE_1F_MOM, LittlerootTown_BrendansHouse_1F_Movement_RivalMomApproach
	waitmovement 0
	special GetRivalSonDaughterString
	msgbox RivalsHouse_1F_Text_OhYoureTheNewNeighbor, MSGBOX_DEFAULT
	setflag FLAG_MET_RIVAL_MOM
	setvar VAR_LITTLEROOT_HOUSES_STATE_MAY, 2
	releaseall
	end

LittlerootTown_BrendansHouse_1F_Movement_RivalMomApproach:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_GoSeeRoom::
	lockall
	setvar VAR_0x8004, LOCALID_PLAYERS_HOUSE_1F_MOM
	setvar VAR_0x8005, MALE
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	goto PlayersHouse_1F_EventScript_MomGoSeeRoom
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival0::
	lockall
	setvar VAR_0x8008, 0
	goto LittlerootTown_BrendansHouse_1F_EventScript_MeetRival
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival1::
	lockall
	setvar VAR_0x8008, 1
	goto LittlerootTown_BrendansHouse_1F_EventScript_MeetRival
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival2::
	lockall
	setvar VAR_0x8008, 2
	goto LittlerootTown_BrendansHouse_1F_EventScript_MeetRival
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival::
	playse SE_EXIT
	delay 10
	addobject LOCALID_RIVALS_HOUSE_1F_RIVAL
	delay 30
	playse SE_PIN
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, Common_Movement_Delay48
	waitmovement 0
	call_if_ne VAR_0x8008, 1, LittlerootTown_BrendansHouse_1F_EventScript_PlayerFaceBrendan
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	call_if_eq VAR_0x8008, 0, LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer0
	call_if_eq VAR_0x8008, 1, LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer1
	call_if_eq VAR_0x8008, 2, LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer2
	msgbox RivalsHouse_1F_Text_BrendanWhoAreYou, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_0x8008, 0, LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs0
	call_if_eq VAR_0x8008, 1, LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs1
	call_if_eq VAR_0x8008, 2, LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs2
	playse SE_EXIT
	removeobject LOCALID_RIVALS_HOUSE_1F_RIVAL
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_BRENDAN
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_POKE_BALL
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
	delay 30
	setvar VAR_LITTLEROOT_RIVAL_STATE, 3
	setvar VAR_LITTLEROOT_TOWN_STATE, 1
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

LittlerootTown_BrendansHouse_1F_EventScript_PlayerFaceBrendan::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer0::
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer0
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer1::
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer1
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer2::
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer2
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer0:
	walk_in_place_faster_left
	walk_left
	walk_in_place_faster_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer1:
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer2:
	walk_in_place_faster_right
	walk_right
	walk_in_place_faster_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs0::
	applymovement LOCALID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit0
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs0
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs1::
	applymovement LOCALID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit1
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs1
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs2::
	applymovement LOCALID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit2
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs2
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit0:
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit1:
	delay_16
	delay_8
	walk_in_place_faster_right
	delay_16
	delay_16
	walk_in_place_faster_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit2:
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs0:
	walk_in_place_faster_right
	walk_right
	walk_in_place_faster_up
	walk_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs1:
	walk_in_place_faster_right
	walk_right
	walk_in_place_faster_up
	walk_up
	walk_up
	walk_in_place_faster_left
	walk_left
	walk_in_place_faster_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs2:
	walk_in_place_faster_left
	walk_left
	walk_in_place_faster_up
	walk_up
	walk_up
	step_end

PlayersHouse_1F_Text_IsntItNiceInHere:
	.string "MẸ: Thấy chưa, {PLAYER}? Trong này\n"
	.string "cũng đẹp đúng không?$"

PlayersHouse_1F_Text_MoversPokemonGoSetClock:
	.string "POKéMON của đội chuyển nhà lo hết việc\n"
	.string "chuyển đồ vào và dọn dẹp sau đó. Tiện\l"
	.string "lợi quá!\p"
	.string "{PLAYER}, phòng của con ở trên tầng.\n"
	.string "Lên xem đi, con yêu!\p"
	.string "BA đã mua cho con một chiếc đồng hồ\n"
	.string "mới để kỷ niệm ngày chúng ta chuyển\l"
	.string "đến đây. Đừng quên chỉnh giờ nhé!$"

PlayersHouse_1F_Text_ArentYouInterestedInRoom:
	.string "MẸ: Sao nào, {PLAYER}?\p"
	.string "Con không muốn lên xem căn phòng riêng\n"
	.string "của mình à?$"

PlayersHouse_1F_Text_GoSetTheClock:
	.string "MẸ: {PLAYER}.\p"
	.string "Lên chỉnh đồng hồ trong phòng đi, con\n"
	.string "yêu.$"

PlayersHouse_1F_Text_OhComeQuickly:
	.string "MẸ: Ôi! {PLAYER}, {PLAYER}! Mau lên!\n"
	.string "Lại đây nhanh!$"

PlayersHouse_1F_Text_MaybeDadWillBeOn:
	.string "MẸ: Nhìn kìa! Là PETALBURG GYM! Có khi\n"
	.string "BA sẽ lên hình đấy!$"

PlayersHouse_1F_Text_ItsOverWeMissedHim:
	.string "MẸ: Ôi... Hết rồi.\p"
	.string "Hình như BA vừa lên hình, nhưng chúng\n"
	.string "ta bỏ lỡ mất. Tiếc thật.$"

PlayersHouse_1F_Text_GoIntroduceYourselfNextDoor:
	.string "À phải rồi. Một người bạn của BA sống\n"
	.string "trong thị trấn này.\p"
	.string "Ông ấy tên là PROF. BIRCH.\p"
	.string "Ông ấy sống ngay nhà bên, nên con hãy\n"
	.string "sang tự giới thiệu nhé.$"

PlayersHouse_1F_Text_SeeYouHoney:
	.string "MẸ: Gặp lại sau nhé, con yêu!$"

PlayersHouse_1F_Text_DidYouMeetProfBirch:
	.string "MẸ: Con đã sang chào PROF. BIRCH\n"
	.string "chưa?$"

PlayersHouse_1F_Text_YouShouldRestABit:
	.string "MẸ: Con thế nào rồi, {PLAYER}? Trông\n"
	.string "con hơi mệt.\p"
	.string "Mẹ nghĩ con nên nghỉ ngơi một chút.$"

PlayersHouse_1F_Text_TakeCareHoney:
	.string "MẸ: Nhớ giữ gìn nhé, con yêu!$"

PlayersHouse_1F_Text_GotDadsBadgeHeresSomethingFromMom:
	.string "MẸ: Ồ? BA trao cho con BADGE đó à?\p"
	.string "Vậy thì MẸ tặng con món này!$"

PlayersHouse_1F_Text_DontPushYourselfTooHard:
	.string "Đừng cố quá sức nhé con. Con luôn có\n"
	.string "thể về nhà.\p"
	.string "Cố lên nhé, con yêu!$"

PlayersHouse_1F_Text_IsThatAPokenav:
	.string "MẸ: Gì vậy con? POKéNAV à? Người của\n"
	.string "DEVON tặng con sao?\p"
	.string "Nào con, đăng ký MẸ vào nhé?\p"
	.string "... ... ...$"

PlayersHouse_1F_Text_RegisteredMom:
	.string "Đã đăng ký MẸ vào POKéNAV.$"

PlayersHouse_1F_Text_Vigoroth1:
	.string "Fugiiiiih!$"

PlayersHouse_1F_Text_Vigoroth2:
	.string "Huggoh, uggo uggo...$"

PlayersHouse_1F_Text_ReportFromPetalburgGym:
	.string "PHÓNG VIÊN: ...Sau đây là bản tin từ\n"
	.string "phía trước PETALBURG GYM.$"

PlayersHouse_1F_Text_TheresAMovieOnTV:
	.string "Có một bộ phim trên TV.\p"
	.string "Hai người đàn ông đang nhảy trên một\n"
	.string "bàn phím piano khổng lồ.\p"
	.string "Nên đi thôi!$"

PlayersHouse_1F_Text_RunningShoesManual:
	.string "Đây là sách hướng dẫn sử dụng RUNNING\n"
	.string "SHOES.\p"
	.string "Nhấn B Button để chạy khi đang mang\n"
	.string "RUNNING SHOES.\p"
	.string "Hãy buộc dây RUNNING SHOES rồi chạy\n"
	.string "thẳng ra đường!$"

PlayersHouse_1F_Text_TicketFromBrineyCameForYou:
	.string "BA: Hửm?\p"
	.string "Này, {PLAYER} đây mà!\p"
	.string "Lâu rồi ba chưa gặp con, nhưng trông\n"
	.string "con... có vẻ mạnh hơn.\p"
	.string "Ba có cảm giác như vậy. Nhưng ông già\n"
	.string "này vẫn chưa chịu thua đâu!\p"
	.string "À phải, ba có thứ này cho con. Một\n"
	.string "người tên MR. BRINEY gửi nó đến cho\l"
	.string "con.$"

PlayersHouse_1F_Text_PortsInSlateportLilycove:
	.string "BA: Hừm, một TICKET đi phà à?\p"
	.string "Nếu ba nhớ không lầm, SLATEPORT và\n"
	.string "LILYCOVE đều có bến phà.$"

PlayersHouse_1F_Text_BetterGetBackToGym:
	.string "Ba nên quay lại PETALBURG GYM.\p"
	.string "MẸ, cảm ơn em đã trông nom nhà cửa lúc\n"
	.string "anh vắng nhà.$"

PlayersHouse_1F_Text_DadShouldStayLonger:
	.string "MẸ: BA của con thật là...\p"
	.string "Lâu lắm mới về nhà, vậy mà ông ấy chỉ\n"
	.string "nói chuyện POKéMON.\p"
	.string "Ông ấy nên nghỉ ngơi và ở lại thêm một\n"
	.string "chút.$"

PlayersHouse_1F_Text_IsThatABreakingStory:
	.string "MẸ: Đó có phải tin nóng không?$"

PlayersHouse_1F_Text_LatiEmergencyNewsFlash:
	.string "Bản tin khẩn cấp!\p"
	.string "Tại nhiều nơi ở HOENN, đã có báo cáo về\n"
	.string "một POKéMON màu BZZT... đang bay.\p"
	.string "Danh tính của POKéMON này hiện vẫn\n"
	.string "chưa rõ.\p"
	.string "Sau đây, xin mời quý vị tiếp tục theo\n"
	.string "dõi bộ phim đang phát.$"

PlayersHouse_1F_Text_WhatColorDidTheySay:
	.string "MẸ: {PLAYER}, con có nghe thấy\n"
	.string "không?\p"
	.string "Phát thanh viên nói POKéMON đó có màu\n"
	.string "gì?$"

PlayersHouse_1F_Text_StillUnknownPokemon:
	.string "MẸ: Thật đáng ngạc nhiên! Vẫn còn\n"
	.string "những POKéMON chưa được biết đến.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global PlayersHouse_1F_Text_IsntItNiceInHere
	.global PlayersHouse_1F_Text_MoversPokemonGoSetClock
	.global PlayersHouse_1F_Text_ArentYouInterestedInRoom
	.global PlayersHouse_1F_Text_GoSetTheClock
	.global PlayersHouse_1F_Text_OhComeQuickly
	.global PlayersHouse_1F_Text_MaybeDadWillBeOn
	.global PlayersHouse_1F_Text_ItsOverWeMissedHim
	.global PlayersHouse_1F_Text_GoIntroduceYourselfNextDoor
	.global PlayersHouse_1F_Text_SeeYouHoney
	.global PlayersHouse_1F_Text_DidYouMeetProfBirch
	.global PlayersHouse_1F_Text_YouShouldRestABit
	.global PlayersHouse_1F_Text_TakeCareHoney
	.global PlayersHouse_1F_Text_GotDadsBadgeHeresSomethingFromMom
	.global PlayersHouse_1F_Text_DontPushYourselfTooHard
	.global PlayersHouse_1F_Text_IsThatAPokenav
	.global PlayersHouse_1F_Text_RegisteredMom
	.global PlayersHouse_1F_Text_Vigoroth2
	.global PlayersHouse_1F_Text_ReportFromPetalburgGym
	.global PlayersHouse_1F_Text_TheresAMovieOnTV
	.global PlayersHouse_1F_Text_RunningShoesManual
	.global PlayersHouse_1F_Text_TicketFromBrineyCameForYou
	.global PlayersHouse_1F_Text_PortsInSlateportLilycove
	.global PlayersHouse_1F_Text_BetterGetBackToGym
	.global PlayersHouse_1F_Text_DadShouldStayLonger
	.global PlayersHouse_1F_Text_IsThatABreakingStory
	.global PlayersHouse_1F_Text_LatiEmergencyNewsFlash
	.global PlayersHouse_1F_Text_WhatColorDidTheySay
	.global PlayersHouse_1F_Text_StillUnknownPokemon
@ END GENERATED LOCALIZATION EXPORTS
