Route114_FossilManiacsTunnel_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_FossilManiacsTunnel_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, Route114_FossilManiacsTunnel_OnLoad
	.byte 0

Route114_FossilManiacsTunnel_OnTransition:
	call_if_set FLAG_SYS_GAME_CLEAR, Route114_FossilManiacsTunnel_EventScript_MoveFossilManiac
	end

Route114_FossilManiacsTunnel_EventScript_MoveFossilManiac::
	setobjectxyperm LOCALID_FOSSIL_MANIAC, 6, 5
	setobjectmovementtype LOCALID_FOSSIL_MANIAC, MOVEMENT_TYPE_FACE_DOWN
	return

Route114_FossilManiacsTunnel_OnLoad:
	call_if_unset FLAG_SYS_GAME_CLEAR, Route114_FossilManiacsTunnel_EventScript_CloseDesertUnderpass
	end

Route114_FossilManiacsTunnel_EventScript_CloseDesertUnderpass::
	setmetatile 6, 1, METATILE_Fallarbor_RedRockWall, TRUE
	setmetatile 6, 2, METATILE_Fallarbor_RedRockWall, TRUE
	return

Route114_FossilManiacsTunnel_EventScript_ManiacMentionCaveIn::
	lockall
	applymovement LOCALID_FOSSIL_MANIAC, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox Route114_FossilManiacsTunnel_Text_NotSafeThatWay, MSGBOX_DEFAULT
	setvar VAR_FOSSIL_MANIAC_STATE, 2
	releaseall
	end

Route114_FossilManiacsTunnel_EventScript_FossilManiac::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_REVIVED_FOSSIL_MON, Route114_FossilManiacsTunnel_EventScript_PlayerRevivedFossil
	checkitem ITEM_ROOT_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, Route114_FossilManiacsTunnel_EventScript_PlayerHasFossil
	checkitem ITEM_CLAW_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, Route114_FossilManiacsTunnel_EventScript_PlayerHasFossil
	msgbox Route114_FossilManiacsTunnel_Text_LookInDesertForFossils, MSGBOX_DEFAULT
	release
	end

Route114_FossilManiacsTunnel_EventScript_PlayerHasFossil::
	msgbox Route114_FossilManiacsTunnel_Text_DevonCorpRevivingFossils, MSGBOX_DEFAULT
	release
	end

Route114_FossilManiacsTunnel_EventScript_PlayerRevivedFossil::
	msgbox Route114_FossilManiacsTunnel_Text_FossilsAreWonderful, MSGBOX_DEFAULT
	release
	end

Route114_FossilManiacsTunnel_Text_LookInDesertForFossils:
	.string "Tôi là FOSSIL MANIAC... Tôi là người tốt\n"
	.string "và rất yêu FOSSILS...\p"
	.string "Bạn muốn một FOSSIL sao?\p"
	.string "Nhưng tất cả FOSSILS quanh vùng này\n"
	.string "đều thuộc về tôi... Không có phần cho\l"
	.string "bạn...\p"
	.string "Nếu không thể chịu nổi cảnh thiếu\n"
	.string "FOSSIL, hãy tìm ở một sa mạc có những\l"
	.string "tảng đá và cát có thể che giấu\l"
	.string "FOSSILS...$"

Route114_FossilManiacsTunnel_Text_DevonCorpRevivingFossils:
	.string "Bạn tìm được một FOSSIL rồi phải\n"
	.string "không? Tuyệt quá... Thật mê hoặc...\p"
	.string "Bạn định làm gì với FOSSIL đó?\p"
	.string "Theo tôi nghe được, DEVON đang nghiên\n"
	.string "cứu cách hồi sinh POKéMON từ FOSSILS...\p"
	.string "Tôi yêu FOSSILS của mình nên sẽ không\n"
	.string "bao giờ làm chuyện như thế...$"

Route114_FossilManiacsTunnel_Text_FossilsAreWonderful:
	.string "FOSSILS thật... Tuyệt vời... Thật mê\n"
	.string "hoặc...$"

Route114_FossilManiacsTunnel_Text_NotSafeThatWay:
	.string "Ồ... Phía đó không an toàn đâu...\p"
	.string "Tôi đang đào thì... Cả bức tường đột\n"
	.string "nhiên sụp xuống...\p"
	.string "Tôi nghĩ giờ bên dưới có một hang động\n"
	.string "khổng lồ...\p"
	.string "Nhưng tôi mặc kệ nó vì không nghĩ ở đó\n"
	.string "có FOSSILS...$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global Route114_FossilManiacsTunnel_Text_LookInDesertForFossils
	.global Route114_FossilManiacsTunnel_Text_DevonCorpRevivingFossils
	.global Route114_FossilManiacsTunnel_Text_FossilsAreWonderful
	.global Route114_FossilManiacsTunnel_Text_NotSafeThatWay
@ END GENERATED LOCALIZATION EXPORTS
