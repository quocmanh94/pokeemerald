LavaridgeTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LavaridgeTown_OnFrame
	.byte 0

LavaridgeTown_OnTransition:
	setflag FLAG_VISITED_LAVARIDGE_TOWN
	call_if_set FLAG_WHITEOUT_TO_LAVARIDGE, LavaridgeTown_EventScript_ClearLavaridgeWhiteOut
	call_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, LavaridgeTown_EventScript_ShowMtChimneyTrainers
	call Common_EventScript_SetupRivalGfxId
	call Common_EventScript_SetupRivalOnBikeGfxId
	call_if_eq VAR_LAVARIDGE_TOWN_STATE, 1, LavaridgeTown_EventScript_CheckSetRivalPos
	call_if_eq VAR_LAVARIDGE_TOWN_STATE, 1, LavaridgeTown_EventScript_HideMapNamePopup
	end

LavaridgeTown_EventScript_ClearLavaridgeWhiteOut::
	clearflag FLAG_WHITEOUT_TO_LAVARIDGE
	return

LavaridgeTown_EventScript_CheckSetRivalPos::
	getplayerxy VAR_0x8004, VAR_0x8005
	goto_if_eq VAR_0x8004, 9, LavaridgeTown_EventScript_SetRivalPos
	return

LavaridgeTown_EventScript_SetRivalPos::
	setobjectxyperm LOCALID_LAVARIDGE_RIVAL, 11, 9
	setobjectxyperm LOCALID_LAVARIDGE_RIVAL_ON_BIKE, 9, 8
	setobjectmovementtype LOCALID_LAVARIDGE_RIVAL_ON_BIKE, MOVEMENT_TYPE_FACE_UP
	clearflag FLAG_HIDE_LAVARIDGE_TOWN_RIVAL
	return

LavaridgeTown_EventScript_ShowMtChimneyTrainers::
	clearflag FLAG_HIDE_MT_CHIMNEY_TRAINERS
	return

LavaridgeTown_EventScript_HideMapNamePopup::
	setflag FLAG_HIDE_MAP_NAME_POPUP
	return

LavaridgeTown_OnFrame:
	map_script_2 VAR_LAVARIDGE_TOWN_STATE, 1, LavaridgeTown_EventScript_RivalGiveGoGoggles
	.2byte 0

LavaridgeTown_EventScript_RivalGiveGoGoggles::
	lockall
	getplayerxy VAR_0x8008, VAR_0x8009
	call_if_eq VAR_0x8008, 9, LavaridgeTown_EventScript_RivalNoticePlayer
	call_if_ne VAR_0x8008, 9, LavaridgeTown_EventScript_RivalExitHerbShop
	delay 20
	checkplayergender
	call_if_eq VAR_RESULT, MALE, LavaridgeTown_EventScript_PlayMayMusic
	call_if_eq VAR_RESULT, FEMALE, LavaridgeTown_EventScript_PlayBrendanMusic
	call_if_eq VAR_0x8008, 9, LavaridgeTown_EventScript_RivalApproachPlayer1
	call_if_ne VAR_0x8008, 9, LavaridgeTown_EventScript_RivalApproachPlayer2
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, LavaridgeTown_EventScript_MayGiveGoGoggles
	goto_if_eq VAR_RESULT, FEMALE, LavaridgeTown_EventScript_BrendanGiveGoGoggles
	end

LavaridgeTown_EventScript_MayGiveGoGoggles::
	msgbox LavaridgeTown_Text_MayNiceBadgesTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_GO_GOGGLES
	setflag FLAG_RECEIVED_GO_GOGGLES
	msgbox LavaridgeTown_Text_MayExplainGoGogglesChallengeDad, MSGBOX_DEFAULT
	goto LavaridgeTown_EventScript_RivalExit
	end

LavaridgeTown_EventScript_BrendanGiveGoGoggles::
	msgbox LavaridgeTown_Text_BrendanNiceBadgesTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_GO_GOGGLES
	setflag FLAG_RECEIVED_GO_GOGGLES
	msgbox LavaridgeTown_Text_BrendanExplainGoGogglesChallengeDad, MSGBOX_DEFAULT
	goto LavaridgeTown_EventScript_RivalExit
	end

LavaridgeTown_EventScript_RivalExit::
	closemessage
	removeobject LOCALID_LAVARIDGE_RIVAL
	addobject LOCALID_LAVARIDGE_RIVAL_ON_BIKE
	delay 30
	call_if_eq VAR_0x8008, 9, LavaridgeTown_EventScript_RivalExit1
	call_if_ne VAR_0x8008, 9, LavaridgeTown_EventScript_RivalExit2
	removeobject LOCALID_LAVARIDGE_RIVAL_ON_BIKE
	setvar VAR_LAVARIDGE_TOWN_STATE, 2
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

LavaridgeTown_EventScript_PlayMayMusic::
	playbgm MUS_ENCOUNTER_MAY, TRUE
	return

LavaridgeTown_EventScript_PlayBrendanMusic::
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	return

LavaridgeTown_EventScript_RivalNoticePlayer::
	applymovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_Delay48
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalExitHerbShop::
	opendoor 12, 15
	waitdooranim
	addobject LOCALID_LAVARIDGE_RIVAL
	applymovement LOCALID_LAVARIDGE_RIVAL, LavaridgeTown_Movement_RivalExitHerbShop
	waitmovement 0
	closedoor 12, 15
	waitdooranim
	applymovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalApproachPlayer1::
	applymovement LOCALID_LAVARIDGE_RIVAL, LavaridgeTown_Movement_RivalApproachPlayer1
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalApproachPlayer2::
	applymovement LOCALID_LAVARIDGE_RIVAL, LavaridgeTown_Movement_RivalApproachPlayer2
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalExit1::
	applymovement LOCALID_PLAYER, LavaridgeTown_Movement_PlayerWatchRivalExit
	applymovement LOCALID_LAVARIDGE_RIVAL_ON_BIKE, LavaridgeTown_Movement_RivalExit1
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalExit2::
	applymovement LOCALID_LAVARIDGE_RIVAL_ON_BIKE, LavaridgeTown_Movement_RivalExit2
	waitmovement 0
	return

LavaridgeTown_Movement_RivalExit2:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

LavaridgeTown_Movement_PlayerWatchRivalExit:
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

LavaridgeTown_Movement_RivalExit1:
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

LavaridgeTown_Movement_RivalApproachPlayer2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

LavaridgeTown_Movement_RivalApproachPlayer1:
	walk_left
	walk_left
	walk_up
	step_end

LavaridgeTown_Movement_RivalExitHerbShop:
	walk_down
	step_end

LavaridgeTown_EventScript_HotSpringsTrigger::
	specialvar VAR_RESULT, GetPlayerFacingDirection
	goto_if_eq VAR_RESULT, DIR_SOUTH, LavaridgeTown_EventScript_EnteredHotSprings
	end

LavaridgeTown_EventScript_EnteredHotSprings::
	incrementgamestat GAME_STAT_ENTERED_HOT_SPRINGS
	end

LavaridgeTown_EventScript_ExpertM::
	msgbox LavaridgeTown_Text_HotSpringsNeverRunDry, MSGBOX_NPC
	end

LavaridgeTown_EventScript_OldMan::
	msgbox LavaridgeTown_Text_PokemonNippedBackside, MSGBOX_SIGN
	end

LavaridgeTown_EventScript_Twin::
	msgbox LavaridgeTown_Text_BatheInHotSpringsEveryDay, MSGBOX_NPC
	end

LavaridgeTown_EventScript_HotSpringsOldWoman1::
	msgbox LavaridgeTown_Text_IfPokemonInHotSprings, MSGBOX_NPC
	end

LavaridgeTown_EventScript_HotSpringsOldWoman2::
	msgbox LavaridgeTown_Text_HotSpringsClaims, MSGBOX_NPC
	end

LavaridgeTown_EventScript_ExpertF::
	msgbox LavaridgeTown_Text_OhYouLikeHotSprings, MSGBOX_NPC
	end

LavaridgeTown_EventScript_EggWoman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_LAVARIDGE_EGG, LavaridgeTown_EventScript_ReceivedEgg
	msgbox LavaridgeTown_Text_HaveEggWillYouTakeIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LavaridgeTown_EventScript_DeclineEgg
	getpartysize
	goto_if_eq VAR_RESULT, PARTY_SIZE, LavaridgeTown_EventScript_NoRoomForEgg
	msgbox LavaridgeTown_Text_HopeYoullWalkPlentyWithEgg, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_LAVARIDGE_EGG
	playfanfare MUS_OBTAIN_ITEM
	message LavaridgeTown_Text_ReceivedTheEgg
	waitfanfare
	giveegg SPECIES_WYNAUT
	release
	end

LavaridgeTown_EventScript_ReceivedEgg::
	msgbox LavaridgeTown_Text_EverySoOftenEggFoundAtDayCare, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_EventScript_NoRoomForEgg::
	msgbox LavaridgeTown_Text_NoRoomForThisEgg, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_EventScript_DeclineEgg::
	msgbox LavaridgeTown_Text_AsYouWishThen, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_EventScript_TownSign::
	msgbox LavaridgeTown_Text_TownSign, MSGBOX_SIGN
	end

LavaridgeTown_EventScript_GymSign::
	msgbox LavaridgeTown_Text_GymSign, MSGBOX_SIGN
	end

LavaridgeTown_EventScript_HerbShopSign::
	msgbox LavaridgeTown_Text_HerbShopSign, MSGBOX_SIGN
	end

LavaridgeTown_Text_MayNiceBadgesTakeThis:
	.string "MAY: {PLAYER}{KUN}! Lâu rồi không gặp!\p"
	.string "Ồ? Trong lúc tớ đi tắm suối nước nóng,\n"
	.string "cậu đã giành được LAVARIDGE GYM BADGE\l"
	.string "rồi.\p"
	.string "Hẳn cậu đã bắt được những POKéMON rất\n"
	.string "giỏi... Không, phải nói là đã nuôi dạy\l"
	.string "chúng rất tốt.\p"
	.string "Tớ nghĩ thứ này giao cho cậu cũng\n"
	.string "được.$"

LavaridgeTown_Text_MayExplainGoGogglesChallengeDad:
	.string "MAY: Có GO-GOGGLES thì cậu sẽ dễ dàng\n"
	.string "vượt qua sa mạc gần ROUTE 111.\p"
	.string "Nhưng mà, tuyệt thật đấy,\n"
	.string "{PLAYER}{KUN}... Cậu đang thách đấu\l"
	.string "các GYMS...\p"
	.string "Chắc cậu cố gắng như vậy vì không muốn\n"
	.string "thua tớ chứ gì!\p"
	.string "{PLAYER}{KUN}, tớ nghĩ mình nên đến\n"
	.string "PETALBURG GYM thách đấu ba cậu.\p"
	.string "Hẹn gặp lại!$"

LavaridgeTown_Text_BrendanNiceBadgesTakeThis:
	.string "BRENDAN: {PLAYER}, này, lâu rồi không\n"
	.string "gặp. Dạo này thế nào?\p"
	.string "Hừm... Bộ sưu tập BADGES khá ra trò đấy.\p"
	.string "Được rồi. Cậu cứ cầm lấy thứ này đi.$"

LavaridgeTown_Text_BrendanExplainGoGogglesChallengeDad:
	.string "BRENDAN: Nếu định vào sa mạc gần ROUTE\n"
	.string "111 thì nhớ mang chúng theo.\p"
	.string "Chắc ở đó có những POKéMON chỉ sống\n"
	.string "trong sa mạc. Cậu nên thử tìm xem.\p"
	.string "Còn tớ... Tớ đang cân nhắc thách đấu\n"
	.string "NORMAN, GYM LEADER của PETALBURG.\p"
	.string "Không giống cậu đâu, {PLAYER}, ba cậu\n"
	.string "trông đúng là rất mạnh.\p"
	.string "Hẹn gặp lại!$"

LavaridgeTown_Text_HaveEggWillYouTakeIt:
	.string "Tôi có một EGG ở đây.\p"
	.string "Tôi đã định ấp nó bằng cách vùi trong\n"
	.string "cát nóng cạnh suối nước nóng. Nhưng có\l"
	.string "vẻ như vậy vẫn chưa đủ...\p"
	.string "Tôi nghe nói tốt nhất là để nó ở cùng\n"
	.string "POKéMON rồi mang theo bên mình.\p"
	.string "Bạn là HLV, đúng không? Các\n"
	.string "POKéMON của bạn tràn đầy sức sống.\p"
	.string "Vậy bạn thấy sao? Bạn có nhận EGG này\n"
	.string "và giúp nó nở không?$"

LavaridgeTown_Text_HopeYoullWalkPlentyWithEgg:
	.string "Tốt lắm! Mong bạn sẽ đi thật nhiều cùng\n"
	.string "EGG này!$"

LavaridgeTown_Text_ReceivedTheEgg:
	.string "{PLAYER} đã nhận được EGG.$"

LavaridgeTown_Text_NoRoomForThisEgg:
	.string "Ồ? Bạn có quá nhiều POKéMON rồi. Không\n"
	.string "còn chỗ cho EGG này...$"

LavaridgeTown_Text_AsYouWishThen:
	.string "Vậy thì tùy bạn...\p"
	.string "Nếu đổi ý và muốn ấp EGG này, tôi vẫn sẽ\n"
	.string "ở đây.$"

LavaridgeTown_Text_EverySoOftenEggFoundAtDayCare:
	.string "Thỉnh thoảng người ta lại tìm thấy một\n"
	.string "EGG tại POKéMON DAY CARE.\p"
	.string "Ít nhất lời đồn là như vậy.$"

LavaridgeTown_Text_HotSpringsNeverRunDry:
	.string "Chúng tôi lấy bao nhiêu nước nóng tùy\n"
	.string "thích mà suối nước nóng vẫn không bao\l"
	.string "giờ cạn.\p"
	.string "Kỳ diệu phải không?\p"
	.string "Những suối nước nóng này xuất hiện\n"
	.string "gần núi lửa đang hoạt động. Các mạch\l"
	.string "nước ngầm được magma làm nóng rồi\l"
	.string "trào lên thành suối nước nóng.$"

LavaridgeTown_Text_PokemonNippedBackside:
	.string "Được vùi trong cát nóng thế này... Ha...\p"
	.string "Ấm áp, dễ chịu như trên thiên đường...\p"
	.string "Hả? Ááá! Đau!\p"
	.string "Một POKéMON vừa cắn vào mông tôi!$"

LavaridgeTown_Text_OhYouLikeHotSprings:
	.string "Ồ, bạn thích suối nước nóng à?\p"
	.string "Còn trẻ như bạn mà thích thứ này thì\n"
	.string "thật bất ngờ.$"

LavaridgeTown_Text_BatheInHotSpringsEveryDay:
	.string "Ngày nào tôi cũng tắm suối nước nóng.\p"
	.string "Tôi muốn trở thành một GYM LEADER vừa\n"
	.string "xinh đẹp vừa mạnh mẽ như FLANNERY.$"

LavaridgeTown_Text_IfPokemonInHotSprings:
	.string "Nếu mọi người cho POKéMON vào suối\n"
	.string "nước nóng thì có khi sẽ xảy ra những\l"
	.string "chuyện rất kỳ quặc.\p"
	.string "Nó có thể biến thành bồn tắm điện, bồn\n"
	.string "sủi bọt, hay thậm chí là bồn dung nham...$"

LavaridgeTown_Text_HotSpringsClaims:
	.string "Người ta quảng cáo rằng những suối\n"
	.string "nước nóng này giúp xoa dịu căng thẳng\l"
	.string "thần kinh, giảm đau cơ, giải quyết\l"
	.string "chuyện tình cảm và thu hút tiền tài...$"

LavaridgeTown_Text_TownSign:
	.string "LAVARIDGE TOWN\p"
	.string "“POKéMON CENTER HOT SPRINGS Nơi thư\n"
	.string "giãn tuyệt vời!”$"

LavaridgeTown_Text_GymSign:
	.string "LAVARIDGE TOWN POKéMON GYM LEADER:\n"
	.string "FLANNERY “Ngọn lửa đam mê luôn rực\l"
	.string "cháy!”$"

LavaridgeTown_Text_HerbShopSign:
	.string "POKéMON HERB SHOP “Vị càng đắng, chữa\n"
	.string "càng hay!”$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global LavaridgeTown_Text_MayNiceBadgesTakeThis
	.global LavaridgeTown_Text_MayExplainGoGogglesChallengeDad
	.global LavaridgeTown_Text_BrendanNiceBadgesTakeThis
	.global LavaridgeTown_Text_BrendanExplainGoGogglesChallengeDad
	.global LavaridgeTown_Text_HaveEggWillYouTakeIt
	.global LavaridgeTown_Text_HopeYoullWalkPlentyWithEgg
	.global LavaridgeTown_Text_ReceivedTheEgg
	.global LavaridgeTown_Text_NoRoomForThisEgg
	.global LavaridgeTown_Text_AsYouWishThen
	.global LavaridgeTown_Text_EverySoOftenEggFoundAtDayCare
	.global LavaridgeTown_Text_HotSpringsNeverRunDry
	.global LavaridgeTown_Text_PokemonNippedBackside
	.global LavaridgeTown_Text_OhYouLikeHotSprings
	.global LavaridgeTown_Text_BatheInHotSpringsEveryDay
	.global LavaridgeTown_Text_IfPokemonInHotSprings
	.global LavaridgeTown_Text_HotSpringsClaims
	.global LavaridgeTown_Text_TownSign
	.global LavaridgeTown_Text_GymSign
	.global LavaridgeTown_Text_HerbShopSign
@ END GENERATED LOCALIZATION EXPORTS
