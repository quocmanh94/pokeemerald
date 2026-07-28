DewfordTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DewfordTown_OnTransition
	.byte 0

DewfordTown_OnTransition:
	setflag FLAG_VISITED_DEWFORD_TOWN
	end

DewfordTown_EventScript_Briney::
	lock
	faceplayer
	goto_if_unset FLAG_DELIVERED_STEVEN_LETTER, DewfordTown_EventScript_ReturnToPetalburgPrompt
	message DewfordTown_Text_WhereAreWeBound
	waitmessage
	multichoicedefault 21, 6, MULTI_BRINEY_ON_DEWFORD, 2, FALSE
	switch VAR_RESULT
	case 0, DewfordTown_EventScript_ChoosePetalburg
	case 1, DewfordTown_EventScript_ChooseSlateport
	case 2, DewfordTown_EventScript_CancelSailSelect
	case MULTI_B_PRESSED, DewfordTown_EventScript_CancelSailSelect
	end

DewfordTown_EventScript_ChoosePetalburg::
	msgbox DewfordTown_Text_PetalburgWereSettingSail, MSGBOX_DEFAULT
	closemessage
	goto DewfordTown_EventScript_SailToPetalburg
	release
	end

DewfordTown_EventScript_ChooseSlateport::
	msgbox DewfordTown_Text_SlateportWereSettingSail, MSGBOX_DEFAULT
	closemessage
	goto DewfordTown_EventScript_SailToSlateport
	release
	end

DewfordTown_EventScript_CancelSailSelect::
	msgbox DewfordTown_Text_JustTellMeWhenYouNeedToSetSail, MSGBOX_DEFAULT
	closemessage
	release
	end

DewfordTown_EventScript_ReturnToPetalburgPrompt::
	msgbox DewfordTown_Text_SetSailBackToPetalburg, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, DewfordTown_EventScript_SailBackToPetalburg
	msgbox DewfordTown_Text_GoDeliverIllBeWaiting, MSGBOX_DEFAULT
	release
	end

DewfordTown_EventScript_SailBackToPetalburg::
	msgbox DewfordTown_Text_PetalburgWereSettingSail2, MSGBOX_DEFAULT
	closemessage
	goto DewfordTown_EventScript_SailToPetalburg
	end

DewfordTown_EventScript_Woman::
	msgbox DewfordTown_Text_TinyIslandCommunity, MSGBOX_NPC
	end

DewfordTown_EventScript_TownSign::
	msgbox DewfordTown_Text_TownSign, MSGBOX_SIGN
	end

DewfordTown_EventScript_GymSign::
	msgbox DewfordTown_Text_GymSign, MSGBOX_SIGN
	end

DewfordTown_EventScript_HallSign::
	msgbox DewfordTown_Text_HallSign, MSGBOX_SIGN
	end

DewfordTown_EventScript_OldRodFisherman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_OLD_ROD, DewfordTown_EventScript_HowsFishing
	msgbox DewfordTown_Text_GettingItchToFish, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, DewfordTown_EventScript_GiveOldRod
	goto_if_eq VAR_RESULT, NO, DewfordTown_EventScript_NotGettingItchToFish
	end

DewfordTown_EventScript_GiveOldRod::
	msgbox DewfordTown_Text_GiveYouOneOfMyRods, MSGBOX_DEFAULT
	giveitem ITEM_OLD_ROD
	setflag FLAG_RECEIVED_OLD_ROD
	msgbox DewfordTown_Text_ThrowInFishingAdvice, MSGBOX_DEFAULT
	release
	end

DewfordTown_EventScript_NotGettingItchToFish::
	msgbox DewfordTown_Text_ThatsTooBadThen, MSGBOX_DEFAULT
	release
	end

DewfordTown_EventScript_HowsFishing::
	message DewfordTown_Text_HowsYourFishing
	waitmessage
	multichoice 20, 8, MULTI_HOWS_FISHING, TRUE
	goto_if_eq VAR_RESULT, 0, DewfordTown_EventScript_FishingExcellent
	goto_if_eq VAR_RESULT, 1, DewfordTown_EventScript_FishingNotSoGood
	end

DewfordTown_EventScript_FishingExcellent::
	msgbox DewfordTown_Text_GreatHaulInSomeBigOnes, MSGBOX_DEFAULT
	release
	end

DewfordTown_EventScript_FishingNotSoGood::
	msgbox DewfordTown_Text_FishingAdvice, MSGBOX_DEFAULT
	release
	end

DewfordTown_EventScript_SailToPetalburg::
	call EventScript_BackupMrBrineyLocation
	setobjectsubpriority LOCALID_DEWFORD_BRINEY, MAP_DEWFORD_TOWN, 0
	setobjectsubpriority LOCALID_PLAYER, MAP_DEWFORD_TOWN, 0
	applymovement LOCALID_DEWFORD_BRINEY, DewfordTown_Movement_BrineyBoardBoat
	waitmovement 0
	removeobject LOCALID_DEWFORD_BRINEY
	applymovement LOCALID_PLAYER, DewfordTown_Movement_PlayerBoardBoat
	waitmovement 0
	hideobjectat LOCALID_PLAYER, MAP_DEWFORD_TOWN
	call Common_EventScript_PlayBrineysBoatMusic
	applymovement LOCALID_DEWFORD_BOAT, DewfordTown_Movement_SailToPetalburg
	applymovement LOCALID_PLAYER, DewfordTown_Movement_SailToPetalburg
	waitmovement 0
	showobjectat LOCALID_PLAYER, MAP_ROUTE104
	call Common_EventScript_StopBrineysBoatMusic
	applymovement LOCALID_PLAYER, DewfordTown_Movement_ExitBoatPetalburg
	waitmovement 0
	showobjectat LOCALID_PLAYER, MAP_ROUTE104
	clearflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	clearflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	clearflag FLAG_HIDE_ROUTE_104_MR_BRINEY_BOAT
	setflag FLAG_HIDE_MR_BRINEY_BOAT_DEWFORD_TOWN
	hideobjectat LOCALID_DEWFORD_BOAT, MAP_DEWFORD_TOWN
	setvar VAR_BOARD_BRINEY_BOAT_STATE, 2
	resetobjectsubpriority LOCALID_PLAYER, MAP_DEWFORD_TOWN
	warp MAP_ROUTE104_MR_BRINEYS_HOUSE, 5, 4
	copyvar VAR_BRINEY_LOCATION, VAR_0x8008
	waitstate
	release
	end

DewfordTown_EventScript_SailToSlateport::
	call EventScript_BackupMrBrineyLocation
	setobjectsubpriority LOCALID_DEWFORD_BRINEY, MAP_DEWFORD_TOWN, 0
	setobjectsubpriority LOCALID_PLAYER, MAP_DEWFORD_TOWN, 1
	applymovement LOCALID_DEWFORD_BRINEY, DewfordTown_Movement_BrineyBoardBoat
	waitmovement 0
	removeobject LOCALID_DEWFORD_BRINEY
	applymovement LOCALID_PLAYER, DewfordTown_Movement_PlayerBoardBoat
	waitmovement 0
	hideobjectat LOCALID_PLAYER, MAP_DEWFORD_TOWN
	call Common_EventScript_PlayBrineysBoatMusic
	applymovement LOCALID_DEWFORD_BOAT, DewfordTown_Movement_SailToSlateport
	applymovement LOCALID_PLAYER, DewfordTown_Movement_SailToSlateport
	waitmovement 0
	call Common_EventScript_StopBrineysBoatMusic
	showobjectat LOCALID_PLAYER, MAP_ROUTE109
	applymovement LOCALID_PLAYER, DewfordTown_Movement_ExitBoatSlateport
	waitmovement 0
	setobjectxyperm LOCALID_ROUTE109_BRINEY, 21, 26
	addobject LOCALID_ROUTE109_BRINEY
	setobjectsubpriority LOCALID_ROUTE109_BRINEY, MAP_ROUTE109, 0
	applymovement LOCALID_ROUTE109_BRINEY, DewfordTown_Movement_BrineyExitBoat
	waitmovement 0
	clearflag FLAG_HIDE_ROUTE_109_MR_BRINEY
	addobject LOCALID_ROUTE109_BOAT
	clearflag FLAG_HIDE_ROUTE_109_MR_BRINEY_BOAT
	setflag FLAG_HIDE_MR_BRINEY_BOAT_DEWFORD_TOWN
	hideobjectat LOCALID_DEWFORD_BOAT, MAP_DEWFORD_TOWN
	call_if_unset FLAG_DELIVERED_DEVON_GOODS, DewfordTown_EventScript_LandedSlateportDeliverGoods
	call_if_set FLAG_DELIVERED_DEVON_GOODS, DewfordTown_EventScript_LandedSlateport
	closemessage
	copyvar VAR_BRINEY_LOCATION, VAR_0x8008
	resetobjectsubpriority LOCALID_PLAYER, MAP_DEWFORD_TOWN
	resetobjectsubpriority LOCALID_ROUTE109_BRINEY, MAP_ROUTE109
	copyobjectxytoperm LOCALID_ROUTE109_BRINEY
	release
	end

DewfordTown_EventScript_LandedSlateportDeliverGoods::
	msgbox DewfordTown_Text_BrineyLandedInSlateportDeliverGoods, MSGBOX_DEFAULT
	return

DewfordTown_EventScript_LandedSlateport::
	msgbox DewfordTown_Text_BrineyLandedInSlateport, MSGBOX_DEFAULT
	return

DewfordTown_Movement_SailToPetalburg:
	walk_up
	walk_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_left
	walk_fast_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

DewfordTown_Movement_SailToSlateport:
	walk_right
	walk_fast_right
	walk_fast_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

DewfordTown_Movement_PlayerBoardBoat:
	walk_right
	walk_up
	step_end

DewfordTown_Movement_ExitBoatPetalburg:
	walk_up
	walk_up
	walk_up
	step_end

DewfordTown_Movement_ExitBoatSlateport:
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_down
	step_end

DewfordTown_Movement_BrineyBoardBoat:
	walk_up
	step_end

DewfordTown_Movement_BrineyExitBoat:
	walk_up
	walk_up
	step_end

DewfordTown_EventScript_TrendyPhraseBoy::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Text_XIsTheBiggestHappeningThingRight, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, DewfordTown_EventScript_ConfirmTrendyPhrase
	goto_if_eq VAR_RESULT, NO, DewfordTown_EventScript_RejectTrendyPhrase
	end

DewfordTown_EventScript_ConfirmTrendyPhrase::
	msgbox DewfordTown_Text_YeahDefinitionOfInRightNow, MSGBOX_DEFAULT
	release
	end

DewfordTown_EventScript_RejectTrendyPhrase::
	msgbox DewfordTown_Text_TellMeWhatsNewAndIn, MSGBOX_DEFAULT
	setvar VAR_0x8004, EASY_CHAT_TYPE_TRENDY_PHRASE
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto_if_eq VAR_RESULT, TRUE, DewfordTown_EventScript_GiveNewTrendyPhrase
	goto_if_eq VAR_RESULT, FALSE, DewfordTown_EventScript_CancelNewTrendyPhrase
	end

DewfordTown_EventScript_GiveNewTrendyPhrase::
	incrementgamestat GAME_STAT_STARTED_TRENDS
	goto_if_eq VAR_0x8004, FALSE, DewfordTown_EventScript_PhraseNotTrendyEnough
	msgbox DewfordTown_Text_OfCourseIKnowAboutThat, MSGBOX_DEFAULT
	release
	end

DewfordTown_EventScript_CancelNewTrendyPhrase::
	msgbox DewfordTown_Text_HearOfAnyTrendsComeShareWithMe, MSGBOX_DEFAULT
	release
	end

DewfordTown_EventScript_PhraseNotTrendyEnough::
	msgbox DewfordTown_Text_XHuhIThinkYIsCool, MSGBOX_DEFAULT
	release
	end

DewfordTown_Text_TinyIslandCommunity:
	.string "DEWFORD là một cộng đồng nhỏ bé trên\n"
	.string "đảo. Nếu có thứ gì trở thành trào lưu\l"
	.string "tại đây, mọi người sẽ hưởng ứng ngay\l"
	.string "lập tức.$"

DewfordTown_Text_TownSign:
	.string "DEWFORD TOWN “Một hòn đảo nhỏ giữa\n"
	.string "biển xanh.”$"

DewfordTown_Text_GymSign:
	.string "DEWFORD TOWN POKéMON GYM LEADER:\n"
	.string "BRAWLY “Một con sóng lớn trong chiến\l"
	.string "đấu!”$"

DewfordTown_Text_HallSign:
	.string "DEWFORD HALL “Nơi mọi người trao đổi\n"
	.string "thông tin!”$"

Route104_Text_LandedInDewfordDeliverLetter:
	.string "MR. BRINEY: A-hoy! Ta đã cập bến\n"
	.string "DEWFORD.\p"
	.string "Chắc cháu định đi giao LETTER cho... ai\n"
	.string "ấy nhỉ, STEVEN!$"

DewfordTown_Text_SetSailBackToPetalburg:
	.string "MR. BRINEY: Cháu đã giao LETTER chưa?\p"
	.string "Hay cháu định đi thuyền trở về\n"
	.string "PETALBURG?$"

DewfordTown_Text_PetalburgWereSettingSail2:
	.string "MR. BRINEY: Vậy thì đến PETALBURG!\p"
	.string "Nhổ neo! PEEKO, ra khơi thôi, cục cưng\n"
	.string "của ta!$"

DewfordTown_Text_GoDeliverIllBeWaiting:
	.string "MR. BRINEY: Vậy cháu cứ đi giao LETTER\n"
	.string "đi. Ta sẽ chờ ở đây.$"

DewfordTown_Text_BrineyLandedInDewford:
	.string "MR. BRINEY: A-hoy! Ta đã cập bến\n"
	.string "DEWFORD!\p"
	.string "Khi nào muốn ra khơi lần nữa, cháu chỉ\n"
	.string "cần nói với ta!$"

DewfordTown_Text_WhereAreWeBound:
	.string "MR. BRINEY: A-hoy! Vì cháu, ta sẵn sàng\n"
	.string "ra khơi bất cứ lúc nào!\p"
	.string "Nào, bạn nhỏ, chúng ta đi đâu đây?$"

DewfordTown_Text_PetalburgWereSettingSail:
	.string "MR. BRINEY: Đến PETALBURG phải không?\p"
	.string "Nhổ neo! PEEKO, ra khơi thôi, cục cưng\n"
	.string "của ta!$"

DewfordTown_Text_SlateportWereSettingSail:
	.string "MR. BRINEY: Đến SLATEPORT phải không?\p"
	.string "Nhổ neo! PEEKO, ra khơi thôi, cục cưng\n"
	.string "của ta!$"

DewfordTown_Text_JustTellMeWhenYouNeedToSetSail:
	.string "MR. BRINEY: Khi nào cần ra khơi lần nữa,\n"
	.string "cháu chỉ việc nói với ta!$"

DewfordTown_Text_GettingItchToFish:
	.string "Đây là một địa điểm câu cá nổi tiếng.\n"
	.string "Cậu đã thấy nôn nao muốn câu chưa?$"

DewfordTown_Text_GiveYouOneOfMyRods:
	.string "Nghe là tôi khoái rồi đấy!\p"
	.string "Tôi sẽ tặng cậu một trong những RODS\n"
	.string "câu cá của mình.$"

DewfordTown_Text_ThrowInFishingAdvice:
	.string "Và để khuyến mãi thêm, tôi còn tặng cậu\n"
	.string "một chút lời khuyên về câu cá!\p"
	.string "Trước tiên, hãy quay mặt về phía mặt\n"
	.string "nước rồi dùng ROD.\p"
	.string "Hãy tập trung... Nếu cá cắn câu, hãy giật\n"
	.string "ROD.\p"
	.string "Đôi khi cậu có thể câu được ngay,\n"
	.string "nhưng với những con lớn hơn, cậu phải\l"
	.string "canh đúng nhịp để giật ROD và kéo chúng\l"
	.string "lên.$"

DewfordTown_Text_ThatsTooBadThen:
	.string "Ồ, vậy sao? Thế thì tiếc thật.$"

DewfordTown_Text_HowsYourFishing:
	.string "Này! Câu cá thế nào rồi?$"

DewfordTown_Text_GreatHaulInSomeBigOnes:
	.string "Thật sao! Tuyệt lắm! Hãy câu vài con\n"
	.string "thật lớn nhé!$"

DewfordTown_Text_FishingAdvice:
	.string "Này, đừng nản lòng chứ! Tôi sẽ cho cậu\n"
	.string "một chút lời khuyên về câu cá.\p"
	.string "Trước tiên, hãy quay mặt về phía mặt\n"
	.string "nước rồi dùng ROD.\p"
	.string "Hãy tập trung... Nếu cá cắn câu, hãy giật\n"
	.string "ROD.\p"
	.string "Đôi khi cậu có thể câu được ngay,\n"
	.string "nhưng với những con lớn hơn, cậu phải\l"
	.string "canh đúng nhịp để giật ROD và kéo chúng\l"
	.string "lên.$"

DewfordTown_Text_XIsTheBiggestHappeningThingRight:
	.string "Tôi mê những gì sành điệu, đang nổi và\n"
	.string "hợp mốt. Tôi lúc nào cũng theo dõi\l"
	.string "chúng.\p"
	.string "Này, cậu đã nghe về\n"
	.string "“{STR_VAR_1}” mới nổi chưa?\p"
	.string "Đúng rồi! Tất nhiên là cậu biết!\p"
	.string "Ý tôi là, trời ạ, “{STR_VAR_1}”...\n"
	.string "Nó đang cực kỳ thời thượng!\p"
	.string "Ở chỗ cậu sống, “{STR_VAR_1}”\n"
	.string "cũng là trào lưu đình đám nhất, đúng\l"
	.string "không?$"

DewfordTown_Text_TellMeWhatsNewAndIn:
	.string "Hả? Nó không phải thứ sành điệu đang\n"
	.string "thịnh hành sao?\p"
	.string "Vậy thì cậu phải cho tôi biết thứ gì\n"
	.string "đang mới và hợp mốt chứ?$"

DewfordTown_Text_OfCourseIKnowAboutThat:
	.string "Hả? “{STR_VAR_2}” ư?\p"
	.string "... ...\p"
	.string "...Ờ... Đúng! Chính nó! Tôi biết mà! Biết\n"
	.string "từ đầu rồi!\p"
	.string "Tất nhiên tôi biết chuyện đó!\n"
	.string "“{STR_VAR_2}”, đúng chứ?\p"
	.string "Ừ, chính là nó, nó đang nổi!\n"
	.string "“{STR_VAR_2}” ngầu nhất còn gì?\p"
	.string "Đó là thứ thời thượng nhất trong mọi\n"
	.string "thứ thời thượng. Cậu nghĩ tôi lại\l"
	.string "không biết sao?\p"
	.string "“{STR_VAR_1}”... Xưa như chuyện\n"
	.string "năm phút trước rồi.\p"
	.string "Giờ “{STR_VAR_2}” mới là thứ\n"
	.string "quan trọng và bắt kịp thời đại!$"

DewfordTown_Text_XHuhIThinkYIsCool:
	.string "Hmm... “{STR_VAR_2}” à?\p"
	.string "Nhưng riêng tôi thấy\n"
	.string "“{STR_VAR_1}” mới thật sự chất.$"

DewfordTown_Text_HearOfAnyTrendsComeShareWithMe:
	.string "Nếu nghe được trào lưu mới nào đang\n"
	.string "nổi, hãy đến chia sẻ với tôi nhé?$"

DewfordTown_Text_YeahDefinitionOfInRightNow:
	.string "Đúng, hoàn toàn chính xác!\p"
	.string "“{STR_VAR_1}” chính là định\n"
	.string "nghĩa của “hợp mốt” lúc này.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global DewfordTown_Text_TinyIslandCommunity
	.global DewfordTown_Text_TownSign
	.global DewfordTown_Text_GymSign
	.global DewfordTown_Text_HallSign
	.global Route104_Text_LandedInDewfordDeliverLetter
	.global DewfordTown_Text_SetSailBackToPetalburg
	.global DewfordTown_Text_PetalburgWereSettingSail2
	.global DewfordTown_Text_GoDeliverIllBeWaiting
	.global DewfordTown_Text_BrineyLandedInDewford
	.global DewfordTown_Text_WhereAreWeBound
	.global DewfordTown_Text_PetalburgWereSettingSail
	.global DewfordTown_Text_SlateportWereSettingSail
	.global DewfordTown_Text_JustTellMeWhenYouNeedToSetSail
	.global DewfordTown_Text_GettingItchToFish
	.global DewfordTown_Text_GiveYouOneOfMyRods
	.global DewfordTown_Text_ThrowInFishingAdvice
	.global DewfordTown_Text_ThatsTooBadThen
	.global DewfordTown_Text_HowsYourFishing
	.global DewfordTown_Text_GreatHaulInSomeBigOnes
	.global DewfordTown_Text_FishingAdvice
	.global DewfordTown_Text_XIsTheBiggestHappeningThingRight
	.global DewfordTown_Text_TellMeWhatsNewAndIn
	.global DewfordTown_Text_OfCourseIKnowAboutThat
	.global DewfordTown_Text_XHuhIThinkYIsCool
	.global DewfordTown_Text_HearOfAnyTrendsComeShareWithMe
	.global DewfordTown_Text_YeahDefinitionOfInRightNow
@ END GENERATED LOCALIZATION EXPORTS
