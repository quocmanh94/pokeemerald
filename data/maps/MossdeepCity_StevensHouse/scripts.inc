MossdeepCity_StevensHouse_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MossdeepCity_StevensHouse_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_StevensHouse_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MossdeepCity_StevensHouse_OnFrame
	.byte 0

MossdeepCity_StevensHouse_OnLoad:
	call_if_unset FLAG_SYS_GAME_CLEAR, MossdeepCity_StevensHouse_EventScript_HideStevensNote
	end

MossdeepCity_StevensHouse_EventScript_HideStevensNote::
	setmetatile 6, 4, METATILE_GenericBuilding_TableEdge, TRUE
	return

MossdeepCity_StevensHouse_OnTransition:
	call_if_eq VAR_STEVENS_HOUSE_STATE, 2, MossdeepCity_StevensHouse_EventScript_SetStevenPos
	end

MossdeepCity_StevensHouse_EventScript_SetStevenPos::
	setobjectxyperm LOCALID_STEVENS_HOUSE_STEVEN, 6, 5
	setobjectmovementtype LOCALID_STEVENS_HOUSE_STEVEN, MOVEMENT_TYPE_FACE_UP
	return

MossdeepCity_StevensHouse_OnFrame:
	map_script_2 VAR_STEVENS_HOUSE_STATE, 1, MossdeepCity_StevensHouse_EventScript_StevenGivesDive
	.2byte 0

MossdeepCity_StevensHouse_EventScript_StevenGivesDive::
	lockall
	applymovement LOCALID_STEVENS_HOUSE_STEVEN, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_STEVENS_HOUSE_STEVEN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_STEVENS_HOUSE_STEVEN, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_STEVENS_HOUSE_STEVEN, MossdeepCity_StevensHouse_Movement_StevenApproachPlayer
	waitmovement 0
	msgbox MossdeepCity_StevensHouse_Text_YouveEarnedHMDive, MSGBOX_DEFAULT
	giveitem ITEM_HM_DIVE
	setflag FLAG_RECEIVED_HM_DIVE
	setflag FLAG_OMIT_DIVE_FROM_STEVEN_LETTER
	msgbox MossdeepCity_StevensHouse_Text_ExplainDive, MSGBOX_DEFAULT
	closemessage
	delay 20
	applymovement LOCALID_STEVENS_HOUSE_STEVEN, MossdeepCity_StevensHouse_Movement_StevenReturn
	waitmovement 0
	setflag FLAG_HIDE_MOSSDEEP_CITY_SCOTT
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ENTRANCE_AQUA_GRUNT
	setvar VAR_STEVENS_HOUSE_STATE, 2
	releaseall
	end

MossdeepCity_StevensHouse_Movement_StevenApproachPlayer:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_down
	step_end

MossdeepCity_StevensHouse_Movement_StevenReturn:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

MossdeepCity_StevensHouse_EventScript_BeldumPokeball::
	lockall
	msgbox MossdeepCity_StevensHouse_Text_TakeBallContainingBeldum, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MossdeepCity_StevensHouse_EventScript_LeaveBeldum
	goto MossdeepCity_StevensHouse_EventScript_GiveBeldum
	end

MossdeepCity_StevensHouse_EventScript_LeaveBeldum::
	msgbox MossdeepCity_StevensHouse_Text_LeftPokeBallWhereItWas, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_StevensHouse_EventScript_GiveBeldum::
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_BELDUM
	givemon SPECIES_BELDUM, 5
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, MossdeepCity_StevensHouse_EventScript_SendBeldumParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, MossdeepCity_StevensHouse_EventScript_SendBeldumPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

MossdeepCity_StevensHouse_EventScript_SendBeldumParty::
	call MossdeepCity_StevensHouse_EventScript_ReceivedBeldumFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MossdeepCity_StevensHouse_EventScript_ReceivedBeldum
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto MossdeepCity_StevensHouse_EventScript_ReceivedBeldum
	end

MossdeepCity_StevensHouse_EventScript_SendBeldumPC::
	call MossdeepCity_StevensHouse_EventScript_ReceivedBeldumFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MossdeepCity_StevensHouse_EventScript_BeldumTransferredToPC
	call Common_EventScript_NameReceivedBoxMon
	goto MossdeepCity_StevensHouse_EventScript_BeldumTransferredToPC
	end

MossdeepCity_StevensHouse_EventScript_BeldumTransferredToPC::
	call Common_EventScript_TransferredToPC
	goto MossdeepCity_StevensHouse_EventScript_ReceivedBeldum
	end

MossdeepCity_StevensHouse_EventScript_ReceivedBeldumFanfare::
	bufferspeciesname STR_VAR_2, SPECIES_BELDUM
	removeobject LOCALID_STEVENS_HOUSE_BALL
	playfanfare MUS_OBTAIN_ITEM
	message MossdeepCity_StevensHouse_Text_ObtainedBeldum
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_BELDUM
	return

MossdeepCity_StevensHouse_EventScript_ReceivedBeldum::
	setflag FLAG_HIDE_MOSSDEEP_CITY_STEVENS_HOUSE_BELDUM_POKEBALL
	setflag FLAG_RECEIVED_BELDUM
	releaseall
	end

MossdeepCity_StevensHouse_EventScript_RockDisplay::
	msgbox MossdeepCity_StevensHouse_Text_CollectionOfRareRocks, MSGBOX_SIGN
	end

MossdeepCity_StevensHouse_EventScript_Steven::
	msgbox MossdeepCity_StevensHouse_Text_UnderwateCavernBetweenMossdeepSootopolis, MSGBOX_NPC
	end

MossdeepCity_StevensHouse_EventScript_Letter::
	lockall
	msgbox MossdeepCity_StevensHouse_Text_LetterFromSteven, MSGBOX_DEFAULT
	releaseall
	end

@ Unused, leftover from RS
MossdeepCity_StevensHouse_EventScript_DiveItemBall::
	finditem ITEM_HM_DIVE
	setflag FLAG_RECEIVED_HM_DIVE
	end

MossdeepCity_StevensHouse_Text_YouveEarnedHMDive:
	.string "STEVEN: {PLAYER}{KUN}...\p"
	.string "Như em thấy đấy, ở đây không có gì\n"
	.string "nhiều, nhưng đây là nhà anh.\p"
	.string "Cảm ơn em vì tất cả những gì em đã làm.\p"
	.string "Đây là chút lòng cảm kích của anh. Đó là\n"
	.string "HIDDEN MACHINE DIVE.\p"
	.string "Không cần ngại, em xứng đáng nhận HM\n"
	.string "này.$"

MossdeepCity_StevensHouse_Text_ExplainDive:
	.string "STEVEN: Khi đang dùng SURF, em sẽ thấy\n"
	.string "những vùng nước sẫm màu.\p"
	.string "Nếu gặp vùng nước sâu như thế, hãy\n"
	.string "dùng DIVE. Em sẽ lặn xuống đáy biển.\p"
	.string "Khi muốn trở lại mặt nước, hãy dùng\n"
	.string "DIVE lần nữa.\p"
	.string "Tuy vậy, ở một số nơi em sẽ không thể\n"
	.string "nổi lên.$"

MossdeepCity_StevensHouse_Text_UnderwateCavernBetweenMossdeepSootopolis:
	.string "STEVEN: Nghe nói có một hang động dưới\n"
	.string "biển nằm giữa MOSSDEEP và SOOTOPOLIS.\p"
	.string "Em biết đấy, chính là hang mà CAPT.\n"
	.string "STERN đã tìm thấy trong chuyến đi bằng\l"
	.string "tàu ngầm.$"

MossdeepCity_StevensHouse_Text_TakeBallContainingBeldum:
	.string "{PLAYER} kiểm tra POKé BALL.\p"
	.string "Bên trong có POKéMON BELDUM.\p"
	.string "Có lấy POKé BALL không?$"

MossdeepCity_StevensHouse_Text_ObtainedBeldum:
	.string "{PLAYER} nhận được một BELDUM.$"

@ Unused
MossdeepCity_StevensHouse_Text_NoSpaceForAnotherMon:
	.string "Không còn chỗ cho thêm POKéMON.$"

MossdeepCity_StevensHouse_Text_LeftPokeBallWhereItWas:
	.string "{PLAYER} để nguyên POKé BALL tại chỗ\n"
	.string "cũ.$"

MossdeepCity_StevensHouse_Text_LetterFromSteven:
	.string "Đó là một lá thư.\p"
	.string "...\p"
	.string "Gửi {PLAYER}{KUN}...\p"
	.string "Tôi đã quyết định lên đường rèn luyện\n"
	.string "và dành thời gian nhìn lại chính mình.\p"
	.string "Tôi sẽ không về nhà trong một thời gian.\p"
	.string "Tôi có một việc muốn nhờ em.\p"
	.string "Hãy nhận lấy POKé BALL trên bàn.\p"
	.string "Bên trong là BELDUM, POKéMON tôi yêu\n"
	.string "thích nhất.\p"
	.string "Tôi trông cậy vào em.\p"
	.string "Mong một ngày nào đó chúng ta sẽ lại\n"
	.string "gặp nhau.\p"
	.string "STEVEN STONE$"

MossdeepCity_StevensHouse_Text_CollectionOfRareRocks:
	.string "Đây là bộ sưu tập những loại đá quý\n"
	.string "hiếm do STEVEN thu thập.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global MossdeepCity_StevensHouse_Text_YouveEarnedHMDive
	.global MossdeepCity_StevensHouse_Text_ExplainDive
	.global MossdeepCity_StevensHouse_Text_UnderwateCavernBetweenMossdeepSootopolis
	.global MossdeepCity_StevensHouse_Text_TakeBallContainingBeldum
	.global MossdeepCity_StevensHouse_Text_ObtainedBeldum
	.global MossdeepCity_StevensHouse_Text_NoSpaceForAnotherMon
	.global MossdeepCity_StevensHouse_Text_LeftPokeBallWhereItWas
	.global MossdeepCity_StevensHouse_Text_LetterFromSteven
	.global MossdeepCity_StevensHouse_Text_CollectionOfRareRocks
@ END GENERATED LOCALIZATION EXPORTS
