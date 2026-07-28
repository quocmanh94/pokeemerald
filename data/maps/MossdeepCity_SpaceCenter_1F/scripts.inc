MossdeepCity_SpaceCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MossdeepCity_SpaceCenter_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_SpaceCenter_1F_OnTransition
	.byte 0

MossdeepCity_SpaceCenter_1F_OnTransition:
	goto_if_eq VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_1F_EventScript_MoveObjectsForTeamMagma
	end

MossdeepCity_SpaceCenter_1F_EventScript_MoveObjectsForTeamMagma::
	setobjectxyperm LOCALID_SPACE_CENTER_1F_SAILOR, 1, 9
	setobjectmovementtype LOCALID_SPACE_CENTER_1F_SAILOR, MOVEMENT_TYPE_FACE_RIGHT
	setobjectxyperm LOCALID_SPACE_CENTER_1F_WOMAN, 0, 8
	setobjectmovementtype LOCALID_SPACE_CENTER_1F_WOMAN, MOVEMENT_TYPE_FACE_RIGHT
	setobjectxyperm LOCALID_SPACE_CENTER_1F_OLD_MAN, 1, 6
	setobjectmovementtype LOCALID_SPACE_CENTER_1F_OLD_MAN, MOVEMENT_TYPE_FACE_RIGHT
	setobjectxyperm LOCALID_SPACE_CENTER_1F_SCIENTIST_1, 3, 4
	setobjectmovementtype LOCALID_SPACE_CENTER_1F_SCIENTIST_1, MOVEMENT_TYPE_FACE_RIGHT
	setobjectmovementtype LOCALID_SPACE_CENTER_1F_SCIENTIST_2, MOVEMENT_TYPE_FACE_RIGHT
	goto_if_eq VAR_MOSSDEEP_SPACE_CENTER_STAIR_GUARD_STATE, 1, MossdeepCity_SpaceCenter_1F_EventScript_MoveStairGuardLeft
	goto_if_eq VAR_MOSSDEEP_SPACE_CENTER_STAIR_GUARD_STATE, 2, MossdeepCity_SpaceCenter_1F_EventScript_MoveStairGuardDown
	goto_if_eq VAR_MOSSDEEP_SPACE_CENTER_STAIR_GUARD_STATE, 3, MossdeepCity_SpaceCenter_1F_EventScript_MoveStairGuardRight
	end

MossdeepCity_SpaceCenter_1F_EventScript_MoveStairGuardLeft::
	setobjectxyperm LOCALID_SPACE_CENTER_1F_STAIR_GRUNT, 12, 2
	end

MossdeepCity_SpaceCenter_1F_EventScript_MoveStairGuardDown::
	setobjectxyperm LOCALID_SPACE_CENTER_1F_STAIR_GRUNT, 13, 3
	end

@ Functionally unused. See comment on MossdeepCity_SpaceCenter_1F_EventScript_MoveGruntFromStairsEast
MossdeepCity_SpaceCenter_1F_EventScript_MoveStairGuardRight::
	setobjectxyperm LOCALID_SPACE_CENTER_1F_STAIR_GRUNT, 14, 2
	end

MossdeepCity_SpaceCenter_1F_OnLoad:
	goto_if_le VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_1F_EventScript_SetMagmaNote
	end

MossdeepCity_SpaceCenter_1F_EventScript_SetMagmaNote::
	setmetatile 2, 5, METATILE_Facility_DataPad, TRUE
	return

MossdeepCity_SpaceCenter_1F_EventScript_RocketLaunchCounter::
	lock
	faceplayer
	goto_if_eq VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_1F_EventScript_RocketLaunchCounterMagma
	dotimebasedevents
	specialvar VAR_RESULT, GetWeekCount
	buffernumberstring STR_VAR_1, VAR_RESULT
	call_if_eq VAR_RESULT, 0, MossdeepCity_SpaceCenter_1F_EventScript_NoLaunchesYet
	call_if_ge VAR_RESULT, 1, MossdeepCity_SpaceCenter_1F_EventScript_ShowLaunchNumber
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_NoLaunchesYet::
	msgbox MossdeepCity_SpaceCenter_1F_Text_RocketLaunchImminent, MSGBOX_DEFAULT
	return

MossdeepCity_SpaceCenter_1F_EventScript_ShowLaunchNumber::
	msgbox MossdeepCity_SpaceCenter_1F_Text_SuccessfulLaunchNumber, MSGBOX_DEFAULT
	return

MossdeepCity_SpaceCenter_1F_EventScript_RocketLaunchCounterMagma::
	dotimebasedevents
	specialvar VAR_RESULT, GetWeekCount
	buffernumberstring STR_VAR_1, VAR_RESULT
	call_if_eq VAR_RESULT, 0, MossdeepCity_SpaceCenter_1F_EventScript_NoLaunchesYetMagma
	call_if_ge VAR_RESULT, 1, MossdeepCity_SpaceCenter_1F_EventScript_ShowLaunchNumberMagma
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_NoLaunchesYetMagma::
	msgbox MossdeepCity_SpaceCenter_1F_Text_HaywireButRocketLaunchImminent, MSGBOX_DEFAULT
	return

MossdeepCity_SpaceCenter_1F_EventScript_ShowLaunchNumberMagma::
	msgbox MossdeepCity_SpaceCenter_1F_Text_HaywireButSuccessfulLaunchNumber, MSGBOX_DEFAULT
	return

MossdeepCity_SpaceCenter_1F_EventScript_Scientist::
	lock
	faceplayer
	goto_if_eq VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_1F_EventScript_ScientistMagma
	msgbox MossdeepCity_SpaceCenter_1F_Text_RocketLaunchDemandsPerfection, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_ScientistMagma::
	msgbox MossdeepCity_SpaceCenter_1F_Text_MagmaHaveSightsOnSpaceCenter, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_SunStoneMan::
	lock
	faceplayer
	goto_if_eq VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_1F_EventScript_SunStoneManMagma
	goto_if_set FLAG_RECEIVED_SUN_STONE_MOSSDEEP, MossdeepCity_SpaceCenter_1F_EventScript_GaveSunStone
	msgbox MossdeepCity_SpaceCenter_1F_Text_FoundThisYouCanHaveIt, MSGBOX_DEFAULT
	giveitem ITEM_SUN_STONE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_SUN_STONE_MOSSDEEP
	msgbox MossdeepCity_SpaceCenter_1F_Text_HoennFamousForMeteorShowers, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_GaveSunStone::
	msgbox MossdeepCity_SpaceCenter_1F_Text_HoennFamousForMeteorShowers, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_SunStoneManMagma::
	goto_if_set FLAG_RECEIVED_SUN_STONE_MOSSDEEP, MossdeepCity_SpaceCenter_1F_EventScript_GaveSunStoneMagma
	msgbox MossdeepCity_SpaceCenter_1F_Text_MagmaCantStealFuelTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_SUN_STONE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_SUN_STONE_MOSSDEEP
	msgbox MossdeepCity_SpaceCenter_1F_Text_CantStrollOnBeachWithMagma, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_GaveSunStoneMagma::
	msgbox MossdeepCity_SpaceCenter_1F_Text_CantStrollOnBeachWithMagma, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, MossdeepCity_SpaceCenter_1F_EventScript_WomanNormal
	goto_if_eq VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_1F_EventScript_WomanMagma
	goto_if_lt VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_1F_EventScript_WomanNormal
	goto MossdeepCity_SpaceCenter_1F_EventScript_WomanMagma
	end

MossdeepCity_SpaceCenter_1F_EventScript_WomanNormal::
	msgbox MossdeepCity_SpaceCenter_1F_Text_DidPokemonComeFromSpace, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_WomanMagma::
	msgbox MossdeepCity_SpaceCenter_1F_Text_AquaShouldBeatMagma, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_OldMan::
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, MossdeepCity_SpaceCenter_1F_EventScript_OldManNormal
	goto_if_eq VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_1F_EventScript_OldManMagma
	goto_if_lt VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_1F_EventScript_OldManNormal
	goto MossdeepCity_SpaceCenter_1F_EventScript_OldManMagma
	end

MossdeepCity_SpaceCenter_1F_EventScript_OldManNormal::
	msgbox MossdeepCity_SpaceCenter_1F_Text_RocketsBoggleMyMind, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_OldManMagma::
	msgbox MossdeepCity_SpaceCenter_1F_Text_MagmaWantsToSpoilMyDream, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_Steven::
	lock
	faceplayer
	msgbox MossdeepCity_SpaceCenter_1F_Text_StevenMagmaCantBeAllowedToTakeFuel, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_MagmaNote::
	lockall
	msgbox MossdeepCity_SpaceCenter_1F_Text_MagmaIntentToStealNotice, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_SpaceCenter_1F_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_SPACE_CENTER_3, MossdeepCity_SpaceCenter_1F_Text_Grunt3Intro, MossdeepCity_SpaceCenter_1F_Text_Grunt3Defeat
	msgbox MossdeepCity_SpaceCenter_1F_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_SpaceCenter_1F_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_SPACE_CENTER_1, MossdeepCity_SpaceCenter_1F_Text_Grunt1Intro, MossdeepCity_SpaceCenter_1F_Text_Grunt1Defeat
	msgbox MossdeepCity_SpaceCenter_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_SpaceCenter_1F_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_SPACE_CENTER_4, MossdeepCity_SpaceCenter_1F_Text_Grunt4Intro, MossdeepCity_SpaceCenter_1F_Text_Grunt4Defeat
	msgbox MossdeepCity_SpaceCenter_1F_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_SpaceCenter_1F_EventScript_Grunt2::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_GRUNT_SPACE_CENTER_1F, MossdeepCity_SpaceCenter_1F_EventScript_Grunt2Defeated
	msgbox MossdeepCity_SpaceCenter_1F_Text_Grunt2Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_SPACE_CENTER_2, MossdeepCity_SpaceCenter_1F_Text_Grunt2Defeat
	setflag FLAG_DEFEATED_GRUNT_SPACE_CENTER_1F
	copyobjectxytoperm LOCALID_SPACE_CENTER_1F_STAIR_GRUNT
	switch VAR_FACING
	case DIR_WEST, MossdeepCity_SpaceCenter_1F_EventScript_MoveGruntFromStairsWest
#ifdef BUGFIX
	case DIR_EAST, MossdeepCity_SpaceCenter_1F_EventScript_MoveGruntFromStairsEast
#else
	case DIR_WEST, MossdeepCity_SpaceCenter_1F_EventScript_MoveGruntFromStairsEast
#endif
	applymovement LOCALID_SPACE_CENTER_1F_STAIR_GRUNT, MossdeepCity_SpaceCenter_1F_Movement_MoveGruntFromStairs
	waitmovement 0
	setvar VAR_MOSSDEEP_SPACE_CENTER_STAIR_GUARD_STATE, 2
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_Grunt2Defeated::
	msgbox MossdeepCity_SpaceCenter_1F_Text_Grunt2PostBattle, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_MoveGruntFromStairsWest::
	applymovement LOCALID_SPACE_CENTER_1F_STAIR_GRUNT, MossdeepCity_SpaceCenter_1F_Movement_MoveGruntFromStairsWest
	waitmovement 0
	setvar VAR_MOSSDEEP_SPACE_CENTER_STAIR_GUARD_STATE, 1
	release
	end

@ Functionally unused by mistake. The movement is handled anyway after the switch (see above)
@ This also means VAR_MOSSDEEP_SPACE_CENTER_STAIR_GUARD_STATE can never be 3
MossdeepCity_SpaceCenter_1F_EventScript_MoveGruntFromStairsEast::
	applymovement LOCALID_SPACE_CENTER_1F_STAIR_GRUNT, MossdeepCity_SpaceCenter_1F_Movement_MoveGruntFromStairsEast
	waitmovement 0
	setvar VAR_MOSSDEEP_SPACE_CENTER_STAIR_GUARD_STATE, 3
	release
	end

MossdeepCity_SpaceCenter_1F_Movement_MoveGruntFromStairsWest:
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

@ Functionally unused. See above
MossdeepCity_SpaceCenter_1F_Movement_MoveGruntFromStairsEast:
	lock_facing_direction
	walk_right
	unlock_facing_direction
	step_end

@ This was meant to only handle the player facing North, but by mistake(?) it also handles the player facing East
MossdeepCity_SpaceCenter_1F_Movement_MoveGruntFromStairs:
	face_left
	lock_facing_direction
	walk_right
	unlock_facing_direction
	step_end

MossdeepCity_SpaceCenter_1F_Text_RocketLaunchImminent:
	.string "Tên lửa sắp được phóng rồi!$"

MossdeepCity_SpaceCenter_1F_Text_SuccessfulLaunchNumber:
	.string "Tên lửa đã được phóng an toàn! Đây là\n"
	.string "lần phóng thành công thứ\l"
	.string "{STR_VAR_1}!$"

MossdeepCity_SpaceCenter_1F_Text_HaywireButRocketLaunchImminent:
	.string "Tôi biết lúc này mọi chuyện đang hơi\n"
	.string "rối, nhưng...\p"
	.string "Tên lửa sắp được phóng rồi!$"

MossdeepCity_SpaceCenter_1F_Text_HaywireButSuccessfulLaunchNumber:
	.string "Tôi biết lúc này mọi chuyện đang hơi\n"
	.string "rối, nhưng...\p"
	.string "Tên lửa đã được phóng an toàn! Đây là\n"
	.string "lần phóng thành công thứ\l"
	.string "{STR_VAR_1}!$"

MossdeepCity_SpaceCenter_1F_Text_RocketLaunchDemandsPerfection:
	.string "Một vụ phóng tên lửa đòi hỏi sự hoàn\n"
	.string "hảo. Sai số dù chỉ 1% cũng không được\l"
	.string "phép.\p"
	.string "Dù 99% đều ổn, toàn bộ vẫn vô nghĩa nếu\n"
	.string "1% còn lại có vấn đề.\p"
	.string "Dẫu vậy, chúng tôi chưa bao giờ ngừng\n"
	.string "cố gắng. Vì sao ư? Vì đó là một giấc mơ\l"
	.string "không bao giờ kết thúc.$"

MossdeepCity_SpaceCenter_1F_Text_MagmaHaveSightsOnSpaceCenter:
	.string "Bọn côn đồ MAGMA đang nhắm vào SPACE\n"
	.string "CENTER của chúng tôi.\p"
	.string "Nhưng chúng tôi không thể để một\n"
	.string "chuyện nhỏ nhặt như vậy cản trở vụ\l"
	.string "phóng tên lửa!$"

MossdeepCity_SpaceCenter_1F_Text_FoundThisYouCanHaveIt:
	.string "Tôi đang đi dạo trên bãi biển thì nhặt\n"
	.string "được thứ này.\p"
	.string "Tôi không cần dùng đến, nên bạn cứ lấy\n"
	.string "đi.$"

MossdeepCity_SpaceCenter_1F_Text_HoennFamousForMeteorShowers:
	.string "Vùng HOENN từ lâu đã nổi tiếng với\n"
	.string "những trận mưa sao băng.$"

MossdeepCity_SpaceCenter_1F_Text_MagmaCantStealFuelTakeThis:
	.string "Không thể để TEAM MAGMA cướp nhiên\n"
	.string "liệu tên lửa.\p"
	.string "À, nhân tiện, bạn có thể lấy viên đá tôi\n"
	.string "nhặt được trên bãi biển.$"

MossdeepCity_SpaceCenter_1F_Text_CantStrollOnBeachWithMagma:
	.string "TEAM MAGMA đang lảng vảng thế này thì\n"
	.string "chắc đi dạo trên bãi biển cũng chẳng an\l"
	.string "toàn.$"

MossdeepCity_SpaceCenter_1F_Text_DidPokemonComeFromSpace:
	.string "Có người cho rằng POKéMON đến từ vũ\n"
	.string "trụ. Liệu có thật không?$"

MossdeepCity_SpaceCenter_1F_Text_AquaShouldBeatMagma:
	.string "TEAM AQUA nên xử lý TEAM MAGMA đi!\p"
	.string "Nhưng nếu làm thế, TEAM AQUA sẽ càng\n"
	.string "thêm táo tợn, phải không?$"

MossdeepCity_SpaceCenter_1F_Text_RocketsBoggleMyMind:
	.string "Một khối kim loại khổng lồ xé toạc bầu\n"
	.string "trời rồi bay vào vũ trụ...\p"
	.string "Thật không thể tưởng tượng nổi!$"

MossdeepCity_SpaceCenter_1F_Text_MagmaWantsToSpoilMyDream:
	.string "Một khối kim loại khổng lồ xé toạc bầu\n"
	.string "trời rồi bay vào vũ trụ...\p"
	.string "Nhưng TEAM MAGMA lại muốn phá hỏng\n"
	.string "giấc mơ ấy của tôi!\p"
	.string "Tôi không chấp nhận đâu!$"

MossdeepCity_SpaceCenter_1F_Text_StevenMagmaCantBeAllowedToTakeFuel:
	.string "STEVEN: {PLAYER}{KUN}, em đã đọc bản\n"
	.string "tuyên bố kia chưa?\p"
	.string "TEAM MAGMA đang nhắm tới nhiên liệu tên\n"
	.string "lửa trên hòn đảo này.\p"
	.string "Anh không biết chúng cần nó để làm gì,\n"
	.string "nhưng không thể để chúng lấy đi.\p"
	.string "Anh sẽ theo dõi tình hình thêm một lúc\n"
	.string "nữa.\p"
	.string "Trong lúc đó, sao em không đi xem quanh\n"
	.string "thị trấn?$"

MossdeepCity_SpaceCenter_1F_Text_Grunt3Intro:
	.string "Đúng như đã báo trước, bọn ta đến lấy\n"
	.string "nhiên liệu tên lửa đây!$"

MossdeepCity_SpaceCenter_1F_Text_Grunt3Defeat:
	.string "Cạn nhiên liệu rồi...$"

MossdeepCity_SpaceCenter_1F_Text_Grunt3PostBattle:
	.string "Đừng tưởng chỉ vì đánh bại được ta\n"
	.string "mà ngươi đang thắng như chẻ tre!$"

MossdeepCity_SpaceCenter_1F_Text_Grunt1Intro:
	.string "Bọn ta đã cảnh báo đàng hoàng! Bọn ta\n"
	.string "chẳng hề chơi lén lút!$"

MossdeepCity_SpaceCenter_1F_Text_Grunt1Defeat:
	.string "Gừ... Biết thế bọn ta đã giở trò đánh\n"
	.string "lén...$"

MossdeepCity_SpaceCenter_1F_Text_Grunt1PostBattle:
	.string "Rồi, ta hiểu rồi! Lần sau bọn ta sẽ đến\n"
	.string "mà không báo trước.$"

MossdeepCity_SpaceCenter_1F_Text_Grunt4Intro:
	.string "Thứ bọn ta nhắm tới chính là nhiên liệu\n"
	.string "tên lửa đang được SPACE CENTER cất\l"
	.string "giữ.\p"
	.string "Bọn ta sẽ lấy sạch không chừa một giọt!$"

MossdeepCity_SpaceCenter_1F_Text_Grunt4Defeat:
	.string "Làm ơn, có thể cho ta chút nhiên liệu\n"
	.string "không? Chỉ một cốc còm cũng được!$"

MossdeepCity_SpaceCenter_1F_Text_Grunt4PostBattle:
	.string "Bọn ta định làm gì với nhiên liệu tên\n"
	.string "lửa ư?\p"
	.string "Sao ta biết được? Đi mà hỏi thủ lĩnh ở\n"
	.string "tầng trên!$"

MossdeepCity_SpaceCenter_1F_Text_Grunt2Intro:
	.string "Thủ lĩnh đã bảo không một ai, tuyệt đối\n"
	.string "không một ai, được vượt qua ta!$"

MossdeepCity_SpaceCenter_1F_Text_Grunt2Defeat:
	.string "Á! Á! Ááá!$"

MossdeepCity_SpaceCenter_1F_Text_Grunt2PostBattle:
	.string "Xin hãy nói với thủ lĩnh rằng ta chưa\n"
	.string "từng rời bỏ vị trí, rằng ta đã trụ lại\l"
	.string "đến tận phút cuối...$"

MossdeepCity_SpaceCenter_1F_Text_MagmaIntentToStealNotice:
	.string "Đây là... thông báo ý định trộm cắp sao?\p"
	.string "Gửi các nhân viên của SPACE CENTER: Các\n"
	.string "vị khỏe không? Chúng tôi vẫn khỏe.\p"
	.string "Chúng tôi sẽ sớm ghé thăm để lấy nhiên\n"
	.string "liệu tên lửa của các vị.\p"
	.string "Xin đừng cố ngăn cản. Dù thế nào chúng\n"
	.string "tôi cũng sẽ lấy nhiên liệu.\p"
	.string "Hãy để đất liền mở rộng! TEAM MAGMA$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global MossdeepCity_SpaceCenter_1F_Text_RocketLaunchImminent
	.global MossdeepCity_SpaceCenter_1F_Text_SuccessfulLaunchNumber
	.global MossdeepCity_SpaceCenter_1F_Text_HaywireButRocketLaunchImminent
	.global MossdeepCity_SpaceCenter_1F_Text_HaywireButSuccessfulLaunchNumber
	.global MossdeepCity_SpaceCenter_1F_Text_RocketLaunchDemandsPerfection
	.global MossdeepCity_SpaceCenter_1F_Text_MagmaHaveSightsOnSpaceCenter
	.global MossdeepCity_SpaceCenter_1F_Text_FoundThisYouCanHaveIt
	.global MossdeepCity_SpaceCenter_1F_Text_HoennFamousForMeteorShowers
	.global MossdeepCity_SpaceCenter_1F_Text_MagmaCantStealFuelTakeThis
	.global MossdeepCity_SpaceCenter_1F_Text_CantStrollOnBeachWithMagma
	.global MossdeepCity_SpaceCenter_1F_Text_DidPokemonComeFromSpace
	.global MossdeepCity_SpaceCenter_1F_Text_AquaShouldBeatMagma
	.global MossdeepCity_SpaceCenter_1F_Text_RocketsBoggleMyMind
	.global MossdeepCity_SpaceCenter_1F_Text_MagmaWantsToSpoilMyDream
	.global MossdeepCity_SpaceCenter_1F_Text_StevenMagmaCantBeAllowedToTakeFuel
	.global MossdeepCity_SpaceCenter_1F_Text_Grunt3Intro
	.global MossdeepCity_SpaceCenter_1F_Text_Grunt3Defeat
	.global MossdeepCity_SpaceCenter_1F_Text_Grunt3PostBattle
	.global MossdeepCity_SpaceCenter_1F_Text_Grunt1Intro
	.global MossdeepCity_SpaceCenter_1F_Text_Grunt1Defeat
	.global MossdeepCity_SpaceCenter_1F_Text_Grunt1PostBattle
	.global MossdeepCity_SpaceCenter_1F_Text_Grunt4Intro
	.global MossdeepCity_SpaceCenter_1F_Text_Grunt4Defeat
	.global MossdeepCity_SpaceCenter_1F_Text_Grunt4PostBattle
	.global MossdeepCity_SpaceCenter_1F_Text_Grunt2Intro
	.global MossdeepCity_SpaceCenter_1F_Text_Grunt2Defeat
	.global MossdeepCity_SpaceCenter_1F_Text_Grunt2PostBattle
	.global MossdeepCity_SpaceCenter_1F_Text_MagmaIntentToStealNotice
@ END GENERATED LOCALIZATION EXPORTS
