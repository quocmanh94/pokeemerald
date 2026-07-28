MauvilleCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MauvilleCity_OnTransition
	.byte 0

MauvilleCity_OnTransition:
	setflag FLAG_VISITED_MAUVILLE_CITY
	clearflag FLAG_FORCE_MIRAGE_TOWER_VISIBLE
	clearflag FLAG_HIDE_SLATEPORT_MUSEUM_POPULATION
	setflag FLAG_SYS_TV_START
	clearflag FLAG_MAUVILLE_GYM_BARRIERS_STATE
	setvar VAR_MAUVILLE_GYM_STATE, 0
	call_if_set FLAG_GOT_TM_THUNDERBOLT_FROM_WATTSON, MauvilleCity_EventScript_MoveWattsonBackToGym
	end

MauvilleCity_EventScript_MoveWattsonBackToGym::
	clearflag FLAG_HIDE_MAUVILLE_GYM_WATTSON
	setflag FLAG_HIDE_MAUVILLE_CITY_WATTSON
	setflag FLAG_WATTSON_REMATCH_AVAILABLE
	return

MauvilleCity_EventScript_Boy::
	msgbox MauvilleCity_Text_NurseHurtMonBackToHealth, MSGBOX_NPC
	end

MauvilleCity_EventScript_Maniac::
	msgbox MauvilleCity_Text_AllSortsOfPeopleComeThrough, MSGBOX_NPC
	end

MauvilleCity_EventScript_Woman::
	msgbox MauvilleCity_Text_RydelVeryGenerous, MSGBOX_NPC
	end

MauvilleCity_EventScript_RichBoy::
	msgbox MauvilleCity_Text_PokemonCanJumpYouOnBike, MSGBOX_NPC
	end

MauvilleCity_EventScript_CitySign::
	msgbox MauvilleCity_Text_CitySign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_GymSign::
	msgbox MauvilleCity_Text_GymSign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_BikeShopSign::
	msgbox MauvilleCity_Text_BikeShopSign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_GameCornerSign::
	msgbox MauvilleCity_Text_GameCornerSign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_SchoolKidM::
	lock
	faceplayer
	goto_if_set FLAG_TV_EXPLAINED, MauvilleCity_EventScript_TVExplained
	msgbox MauvilleCity_Text_ExplainTV, MSGBOX_DEFAULT
	setflag FLAG_TV_EXPLAINED
	release
	end

MauvilleCity_EventScript_TVExplained::
	msgbox MauvilleCity_Text_BeenCheckingOutTV, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_WallysUncle::
	lock
	faceplayer
	goto_if_set FLAG_DECLINED_WALLY_BATTLE_MAUVILLE, MauvilleCity_EventScript_UncleAskPlayerToBattleWally
	msgbox MauvilleCity_Text_UncleHesTooPeppy, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MauvilleCity_EventScript_UncleAskPlayerToBattleWally::
	msgbox MauvilleCity_Text_UncleCanYouBattleWally, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MauvilleCity_EventScript_Wally::
	lockall
	goto_if_set FLAG_DECLINED_WALLY_BATTLE_MAUVILLE, MauvilleCity_EventScript_WallyRequestBattleAgain
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox MauvilleCity_Text_WallyWantToChallengeGym, MSGBOX_DEFAULT
	msgbox MauvilleCity_Text_UncleYourePushingIt, MSGBOX_DEFAULT
	msgbox MauvilleCity_Text_WallyWeCanBeatAnyone, MSGBOX_DEFAULT
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_FacePlayer
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_Delay48
	waitmovement 0
	msgbox MauvilleCity_Text_WallyWillYouBattleMe, MSGBOX_YESNO
	goto MauvilleCity_EventScript_BattleWallyPrompt
	end

MauvilleCity_EventScript_BattleWallyPrompt::
	call_if_eq VAR_RESULT, YES, MauvilleCity_EventScript_BattleWally
	goto_if_eq VAR_RESULT, NO, MauvilleCity_EventScript_DeclineWallyBattle
	closemessage
	switch VAR_FACING
	case DIR_NORTH, MauvilleCity_EventScript_WallyAndUncleExitNorth
	case DIR_EAST, MauvilleCity_EventScript_WallyAndUncleExitEast
	end

MauvilleCity_EventScript_WallyAndUncleExitNorth::
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitNorth1
	applymovement LOCALID_MAUVILLE_WALLY, MauvilleCity_Movement_WallyExitNorth1
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitNorth1
	waitmovement 0
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 30
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerFaceUncleNorth
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleApproachPlayerNorth
	waitmovement 0
	msgbox MauvilleCity_Text_UncleVisitUsSometime, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitNorth2
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitNorth2
	applymovement LOCALID_MAUVILLE_WALLY, MauvilleCity_Movement_WallyExitNorth2
	waitmovement 0
	goto MauvilleCity_EventScript_DefeatedWally
	end

MauvilleCity_EventScript_WallyAndUncleExitEast::
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitEast1
	applymovement LOCALID_MAUVILLE_WALLY, MauvilleCity_Movement_WallyExitEast1
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitEast1
	waitmovement 0
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 30
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleApproachPlayerEast
	waitmovement 0
	msgbox MauvilleCity_Text_UncleVisitUsSometime, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitEast2
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitEast2
	applymovement LOCALID_MAUVILLE_WALLY, MauvilleCity_Movement_WallyExitEast2
	waitmovement 0
	goto MauvilleCity_EventScript_DefeatedWally
	end

MauvilleCity_EventScript_DefeatedWally::
	removeobject LOCALID_MAUVILLE_WALLY
	removeobject LOCALID_MAUVILLE_WALLYS_UNCLE
	clearflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLY
	clearflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLYS_UNCLE
	setflag FLAG_DEFEATED_WALLY_MAUVILLE
	setvar VAR_WALLY_CALL_STEP_COUNTER, 0
	setflag FLAG_ENABLE_FIRST_WALLY_POKENAV_CALL
	call_if_eq VAR_FACING, DIR_NORTH, MauvilleCity_EventScript_ScottApproachPlayerNorth
	call_if_eq VAR_FACING, DIR_EAST, MauvilleCity_EventScript_ScottApproachPlayerEast
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox MauvilleCity_Text_ScottYouDidntHoldBack, MSGBOX_DEFAULT
	closemessage
	addvar VAR_SCOTT_STATE, 1
	call_if_eq VAR_FACING, DIR_NORTH, MauvilleCity_EventScript_ScottExitNorth
	call_if_eq VAR_FACING, DIR_EAST, MauvilleCity_EventScript_ScottExitEast
	removeobject LOCALID_MAUVILLE_SCOTT
	releaseall
	end

MauvilleCity_EventScript_ScottApproachPlayerNorth::
	addobject LOCALID_MAUVILLE_SCOTT
	applymovement LOCALID_MAUVILLE_SCOTT, MauvilleCity_Movement_ScottApproachPlayerNorth
	waitmovement 0
	return

MauvilleCity_EventScript_ScottApproachPlayerEast::
	setobjectxyperm LOCALID_MAUVILLE_SCOTT, 12, 13
	addobject LOCALID_MAUVILLE_SCOTT
	applymovement LOCALID_MAUVILLE_SCOTT, MauvilleCity_Movement_ScottApproachPlayerEast
	waitmovement 0
	return

MauvilleCity_EventScript_ScottExitNorth::
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerWatchScottExitNorth
	applymovement LOCALID_MAUVILLE_SCOTT, MauvilleCity_Movement_ScottExitNorth
	waitmovement 0
	return

MauvilleCity_EventScript_ScottExitEast::
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerWatchScottExitEast
	applymovement LOCALID_MAUVILLE_SCOTT, MauvilleCity_Movement_ScottExitEast
	waitmovement 0
	return

MauvilleCity_EventScript_BattleWally::
	msgbox MauvilleCity_Text_WallyHereICome, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WALLY_MAUVILLE, MauvilleCity_Text_WallyDefeat
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox MauvilleCity_Text_WallyIllGoBackToVerdanturf, MSGBOX_DEFAULT
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MauvilleCity_Text_ThankYouNotEnoughToBattle, MSGBOX_DEFAULT
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox MauvilleCity_Text_UncleNoNeedToBeDown, MSGBOX_DEFAULT
	return

MauvilleCity_EventScript_DeclineWallyBattle::
	setflag FLAG_DECLINED_WALLY_BATTLE_MAUVILLE
	msgbox MauvilleCity_Text_WallyMyUncleWontKnowImStrong, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_WallyRequestBattleAgain::
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MauvilleCity_Text_WallyPleaseBattleMe, MSGBOX_YESNO
	goto MauvilleCity_EventScript_BattleWallyPrompt
	end

MauvilleCity_Movement_WallyExitNorth1:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	step_end

MauvilleCity_Movement_WallyExitEast1:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_WallyExitNorth2:
	delay_16
	delay_16
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	delay_8
	step_end

MauvilleCity_Movement_WallyExitEast2:
	delay_16
	delay_16
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	delay_8
	step_end

MauvilleCity_Movement_PlayerWatchWallyExitNorth2:
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_PlayerWatchWallyExitEast2:
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_PlayerWatchScottExitNorth:
	delay_16
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_PlayerWatchScottExitEast:
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_PlayerWatchWallyExitEast1:
	delay_16
	walk_in_place_faster_down
	step_end

MauvilleCity_Movement_PlayerWatchWallyExitNorth1:
	delay_16
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_WallysUncleExitNorth1:
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

MauvilleCity_Movement_WallysUncleExitEast1:
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_PlayerFaceUncleNorth:
	delay_16
	delay_8
	delay_4
	walk_in_place_faster_down
	step_end

MauvilleCity_Movement_WallysUncleApproachPlayerNorth:
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

MauvilleCity_Movement_WallysUncleApproachPlayerEast:
	walk_right
	walk_up
	step_end

MauvilleCity_Movement_WallysUncleExitNorth2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_WallysUncleExitEast2:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_ScottApproachPlayerNorth:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_up
	step_end

MauvilleCity_Movement_ScottApproachPlayerEast:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

MauvilleCity_Movement_ScottExitNorth:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_ScottExitEast:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_EventScript_Wattson::
	lock
	faceplayer
	goto_if_set FLAG_GOT_TM_THUNDERBOLT_FROM_WATTSON, MauvilleCity_EventScript_ReceivedThunderbolt
	goto_if_eq VAR_NEW_MAUVILLE_STATE, 2, MauvilleCity_EventScript_CompletedNewMauville
	goto_if_set FLAG_GOT_BASEMENT_KEY_FROM_WATTSON, MauvilleCity_EventScript_BegunNewMauville
	msgbox MauvilleCity_Text_WattsonNeedFavorTakeKey, MSGBOX_DEFAULT
	giveitem ITEM_BASEMENT_KEY
	setflag FLAG_GOT_BASEMENT_KEY_FROM_WATTSON
	msgbox MauvilleCity_Text_WattsonWontBeChallenge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_BegunNewMauville::
	msgbox MauvilleCity_Text_WattsonWontBeChallenge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_CompletedNewMauville::
	msgbox MauvilleCity_Text_WattsonThanksTakeTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_THUNDERBOLT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_TM_THUNDERBOLT_FROM_WATTSON
	msgbox MauvilleCity_Text_WattsonYoungTakeCharge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_ReceivedThunderbolt::
	msgbox MauvilleCity_Text_WattsonYoungTakeCharge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_RegisterWallyCall::
	lockall
	pokenavcall MauvilleCity_Text_WallyPokenavCall
	waitmessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MauvilleCity_Text_RegisteredWally, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_WALLY_MATCH_CALL
	clearflag FLAG_ENABLE_FIRST_WALLY_POKENAV_CALL
	releaseall
	end

MauvilleCity_Text_UncleHesTooPeppy:
	.string "CHÚ: Chắc nhờ POKéMON mà cậu bé này\n"
	.string "khỏe khoắn hơn... Nhưng giờ nó lại hơi\l"
	.string "quá sung sức...$"

MauvilleCity_Text_WallyWantToChallengeGym:
	.string "WALLY: Ôi, CHÚ, cho cháu thử đi mà!\p"
	.string "Cháu muốn thách đấu GYM này để xem\n"
	.string "mình đã tiến bộ đến đâu.\p"
	.string "Đi mà? Cho cháu thử nhé?$"

MauvilleCity_Text_UncleYourePushingIt:
	.string "CHÚ: Khoan đã, WALLY.\p"
	.string "Từ khi bắt đầu sống cùng POKéMON, cháu\n"
	.string "đã mạnh lên rất nhiều.\p"
	.string "Nhưng đột nhiên thách đấu một GYM,\n"
	.string "cháu không thấy mình hơi quá sức sao?$"

MauvilleCity_Text_WallyWeCanBeatAnyone:
	.string "WALLY: Cháu không hề quá sức.\p"
	.string "Nếu cháu và RALTS hợp sức, bọn cháu có\n"
	.string "thể đánh bại bất kỳ ai!$"

MauvilleCity_Text_WallyWillYouBattleMe:
	.string "WALLY: Ồ! Chào {PLAYER}!\p"
	.string "Từ lần gặp trước, mình đã mạnh lên rất\n"
	.string "nhiều.\p"
	.string "{PLAYER}, mình muốn cậu và CHÚ hiểu\n"
	.string "điều đó.\p"
	.string "{PLAYER}, làm ơn đấu với mình một\n"
	.string "trận nhé?$"

MauvilleCity_Text_WallyMyUncleWontKnowImStrong:
	.string "WALLY: Ồ... Nếu cậu không đấu với mình,\n"
	.string "{PLAYER}, CHÚ sẽ không biết mình đã\l"
	.string "trở nên mạnh đến mức nào.$"

MauvilleCity_Text_UncleCanYouBattleWally:
	.string "CHÚ: {PLAYER}{KUN}, phải không? Vì\n"
	.string "WALLY, chú có thể nhờ cháu đấu với nó\l"
	.string "đúng một lần được không?\p"
	.string "Với tình trạng hiện giờ, chú nghĩ nó sẽ\n"
	.string "chẳng chịu nghe ai khuyên đâu.$"

MauvilleCity_Text_WallyPleaseBattleMe:
	.string "WALLY: {PLAYER}, làm ơn! Hãy đấu với\n"
	.string "mình đi.$"

MauvilleCity_Text_WallyHereICome:
	.string "WALLY: {PLAYER}, cảm ơn cậu.\p"
	.string "Được rồi... Mình tới đây!$"

MauvilleCity_Text_WallyDefeat:
	.string "WALLY: ... ... ... ... ... ... ...\p"
	.string "... ... ... ... ... ... ... ...\p"
	.string "Mình thua rồi...$"

MauvilleCity_Text_WallyIllGoBackToVerdanturf:
	.string "WALLY: CHÚ... Cháu sẽ trở về\n"
	.string "VERDANTURF...$"

MauvilleCity_Text_ThankYouNotEnoughToBattle:
	.string "{PLAYER}, cảm ơn cậu. Làm HLV\n"
	.string "thật khó, phải không?\p"
	.string "Chỉ có POKéMON rồi cho chúng chiến đấu\n"
	.string "thôi thì chưa đủ. Một HLV thực thụ\l"
	.string "không chỉ có vậy.$"

MauvilleCity_Text_UncleNoNeedToBeDown:
	.string "CHÚ: WALLY, cháu không cần phải thất\n"
	.string "vọng về bản thân như thế.\p"
	.string "Có gì ngăn cháu ngày càng mạnh hơn\n"
	.string "đâu?\p"
	.string "Nào, về nhà thôi. Mọi người đang chờ\n"
	.string "cháu.$"

MauvilleCity_Text_UncleVisitUsSometime:
	.string "CHÚ: {PLAYER}{KUN}, giờ chú mới\n"
	.string "nhận ra cháu hẳn là HLV đã trông\l"
	.string "chừng WALLY khi nó bắt POKéMON.\p"
	.string "Khi nào ghé thăm nhà chú ở VERDANTURF\n"
	.string "nhé? Chú chắc WALLY sẽ vui lắm.$"


MauvilleCity_Text_WallyPokenavCall:
	.string "... ... ... ... ... ... ... ... ... ... ... Bíp!\p"
	.string "WALLY: Ồ, chào {PLAYER}!\p"
	.string "Mình chỉ muốn báo rằng CHÚ đã mua\n"
	.string "cho mình một chiếc POKéNAV!\p"
	.string "Giờ mình có thể liên lạc với cậu bất cứ\n"
	.string "lúc nào, {PLAYER}!\p"
	.string "... ... ... ... ... ... ... ... ... ... ... Tách!$"

MauvilleCity_Text_RegisteredWally:
	.string "Đã đăng ký WALLY vào POKéNAV.$"

MauvilleCity_Text_ScottYouDidntHoldBack:
	.string "SCOTT: Hehe... Ta đã xem trận đấu đó!\p"
	.string "Cháu là bạn của cậu bé WALLY ấy, phải\n"
	.string "không?\p"
	.string "Nhưng cháu không hề nương tay và đã\n"
	.string "đánh bại cậu ấy thật ngoạn mục.\p"
	.string "Đúng vậy! Một trận đấu POKéMON thực\n"
	.string "thụ phải như thế!\p"
	.string "Ta rất ngưỡng mộ những HLV như\n"
	.string "vậy!\p"
	.string "... ... ... ... ... ... Ta sẽ cổ vũ cho cháu!$"

MauvilleCity_Text_WattsonNeedFavorTakeKey:
	.string "WATTSON: Ô, {PLAYER}{KUN}! Trông cháu\n"
	.string "đầy sức sống đấy! Tốt lắm, wahahahaha!\p"
	.string "Được! Ta quyết định rồi! Ta cần cháu\n"
	.string "giúp một việc, {PLAYER}{KUN}!\p"
	.string "Bên dưới MAUVILLE CITY có một khu vực\n"
	.string "gọi là NEW MAUVILLE.\p"
	.string "{PLAYER}{KUN}, ta muốn cháu đến đó và\n"
	.string "tắt GENERATOR.\p"
	.string "GENERATOR gần đây hoạt động hơi mất\n"
	.string "kiểm soát. Nó đang trở nên nguy hiểm.\p"
	.string "Đây, KEY để vào NEW MAUVILLE.$"

MauvilleCity_Text_WattsonWontBeChallenge:
	.string "WATTSON: Đừng lo. Việc đó chẳng thể làm\n"
	.string "khó cháu đâu.\p"
	.string "Lối vào NEW MAUVILLE chỉ cách ROUTE\n"
	.string "110 một đoạn SURF ngắn.\p"
	.string "Quyết vậy nhé, ta tin tưởng ở cháu!\n"
	.string "Wahahahaha!$"

MauvilleCity_Text_WattsonThanksTakeTM:
	.string "WATTSON: Wahahahaha!\p"
	.string "Ta biết mà, {PLAYER}{KUN}! Ta biết nhờ\n"
	.string "cháu là lựa chọn đúng đắn!\p"
	.string "Đây là lời cảm ơn của ta: một TM chứa\n"
	.string "THUNDERBOLT!\p"
	.string "Cầm lấy đi, cháu xứng đáng nhận nó!$"

MauvilleCity_Text_WattsonYoungTakeCharge:
	.string "WATTSON: Wahahahaha!\p"
	.string "Không gì khiến ta vui hơn khi thấy\n"
	.string "người trẻ đứng ra gánh vác trách\l"
	.string "nhiệm!$"

MauvilleCity_Text_NurseHurtMonBackToHealth:
	.string "Cậu biết đấy, đấu POKéMON các kiểu thì\n"
	.string "rất ngầu...\p"
	.string "Nhưng nếu POKéMON bị thương, cậu phải\n"
	.string "chăm sóc cho nó khỏe lại.$"

MauvilleCity_Text_AllSortsOfPeopleComeThrough:
	.string "Đường phố ở thị trấn này chạy theo cả\n"
	.string "hướng bắc nam lẫn đông tây.\p"
	.string "Nhờ vậy, đủ mọi kiểu người đều đi qua\n"
	.string "đây.$"

MauvilleCity_Text_RydelVeryGenerous:
	.string "Cậu đã đến RYDEL'S CYCLES chưa?\p"
	.string "Chủ tiệm RYDEL là một người rất hào\n"
	.string "phóng.$"

MauvilleCity_Text_PokemonCanJumpYouOnBike:
	.string "Ngay cả khi đang đi BIKE, cậu vẫn có thể\n"
	.string "bị POKéMON hoang dã bất ngờ tấn công.$"

MauvilleCity_Text_CitySign:
	.string "MAUVILLE CITY Thành phố vui chơi sáng\n"
	.string "sủa và lấp lánh!$"

MauvilleCity_Text_GymSign:
	.string "MAUVILLE CITY POKéMON GYM LEADER:\n"
	.string "WATTSON Người đàn ông vui vẻ, tràn đầy\l"
	.string "điện lực!$"

MauvilleCity_Text_BikeShopSign:
	.string "Lướt trên sỏi đá, lay động tâm hồn!\n"
	.string "RYDEL'S CYCLES$"

MauvilleCity_Text_GameCornerSign:
	.string "Nơi vui chơi dành cho tất cả mọi người!\n"
	.string "MAUVILLE GAME CORNER$"

MauvilleCity_Text_ExplainTV:
	.string "Chào, cậu có hay xem TV không?\p"
	.string "Gần đây họ thêm vào rất nhiều chương\n"
	.string "trình mới cực hay.\p"
	.string "TV tuyệt lắm. Có lần bạn tôi bỗng dưng\n"
	.string "xuất hiện trên TV.\p"
	.string "Đôi khi họ còn đưa cả cậu lên TV mà\n"
	.string "chẳng báo trước.\p"
	.string "Tôi cũng mong một ngày nào đó được lên\n"
	.string "TV.\p"
	.string "Vì vậy, tôi nghĩ hễ có dịp là cậu nên xem\n"
	.string "TV.$"

MauvilleCity_Text_BeenCheckingOutTV:
	.string "Chào, dạo này cậu có xem TV không?$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global MauvilleCity_Text_UncleHesTooPeppy
	.global MauvilleCity_Text_WallyWantToChallengeGym
	.global MauvilleCity_Text_UncleYourePushingIt
	.global MauvilleCity_Text_WallyWeCanBeatAnyone
	.global MauvilleCity_Text_WallyWillYouBattleMe
	.global MauvilleCity_Text_WallyMyUncleWontKnowImStrong
	.global MauvilleCity_Text_UncleCanYouBattleWally
	.global MauvilleCity_Text_WallyPleaseBattleMe
	.global MauvilleCity_Text_WallyHereICome
	.global MauvilleCity_Text_WallyDefeat
	.global MauvilleCity_Text_WallyIllGoBackToVerdanturf
	.global MauvilleCity_Text_ThankYouNotEnoughToBattle
	.global MauvilleCity_Text_UncleNoNeedToBeDown
	.global MauvilleCity_Text_UncleVisitUsSometime
	.global MauvilleCity_Text_WallyPokenavCall
	.global MauvilleCity_Text_RegisteredWally
	.global MauvilleCity_Text_ScottYouDidntHoldBack
	.global MauvilleCity_Text_WattsonNeedFavorTakeKey
	.global MauvilleCity_Text_WattsonWontBeChallenge
	.global MauvilleCity_Text_WattsonThanksTakeTM
	.global MauvilleCity_Text_WattsonYoungTakeCharge
	.global MauvilleCity_Text_NurseHurtMonBackToHealth
	.global MauvilleCity_Text_AllSortsOfPeopleComeThrough
	.global MauvilleCity_Text_RydelVeryGenerous
	.global MauvilleCity_Text_PokemonCanJumpYouOnBike
	.global MauvilleCity_Text_CitySign
	.global MauvilleCity_Text_GymSign
	.global MauvilleCity_Text_BikeShopSign
	.global MauvilleCity_Text_GameCornerSign
	.global MauvilleCity_Text_ExplainTV
	.global MauvilleCity_Text_BeenCheckingOutTV
@ END GENERATED LOCALIZATION EXPORTS
