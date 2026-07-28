BattleFrontier_OutsideWest_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_OutsideWest_OnTransition
	.byte 0

BattleFrontier_OutsideWest_OnTransition:
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, 0
	setflag FLAG_HIDE_BATTLE_TOWER_REPORTER
	end

BattleFrontier_OutsideWest_EventScript_FerryAttendant::
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_MayISeeYourTicket, MSGBOX_DEFAULT
	checkitem ITEM_SS_TICKET
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_OutsideWest_EventScript_NoSSTicket
	message BattleFrontier_OutsideWest_Text_WhereWouldYouLikeToGo
	waitmessage
	goto BattleFrontier_OutsideWest_EventScript_ChooseFerryDestination
	end

BattleFrontier_OutsideWest_EventScript_ChooseFerryDestination::
	multichoicedefault 18, 6, MULTI_SSTIDAL_BATTLE_FRONTIER, 2, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_OutsideWest_EventScript_FerryToSlateport
	case 1, BattleFrontier_OutsideWest_EventScript_FerryToLilycove
	case 2, BattleFrontier_OutsideWest_EventScript_CancelFerrySelect
	case MULTI_B_PRESSED, BattleFrontier_OutsideWest_EventScript_CancelFerrySelect
	end

BattleFrontier_OutsideWest_EventScript_NoSSTicket::
	msgbox BattleFrontier_OutsideWest_Text_MustHaveTicketToBoard, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_FerryToSlateport::
	msgbox BattleFrontier_OutsideWest_Text_SlateportItIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_OutsideWest_EventScript_ChooseNewFerryDestination
	msgbox BattleFrontier_OutsideWest_Text_PleaseBoardFerry, MSGBOX_DEFAULT
	call BattleFrontier_OutsideWest_EventScript_BoardFerry
	warp MAP_SLATEPORT_CITY_HARBOR, 8, 11
	waitstate
	release
	end

BattleFrontier_OutsideWest_EventScript_FerryToLilycove::
	msgbox BattleFrontier_OutsideWest_Text_LilycoveItIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_OutsideWest_EventScript_ChooseNewFerryDestination
	msgbox BattleFrontier_OutsideWest_Text_PleaseBoardFerry, MSGBOX_DEFAULT
	call BattleFrontier_OutsideWest_EventScript_BoardFerry
	warp MAP_LILYCOVE_CITY_HARBOR, 8, 11
	waitstate
	release
	end

BattleFrontier_OutsideWest_EventScript_ChooseNewFerryDestination::
	message BattleFrontier_OutsideWest_Text_ThenWhereWouldYouLikeToGo
	waitmessage
	goto BattleFrontier_OutsideWest_EventScript_ChooseFerryDestination
	end

BattleFrontier_OutsideWest_EventScript_BoardFerry::
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 30
	hideobjectat LOCALID_FRONTIER_FERRY_ATTENDANT, MAP_BATTLE_FRONTIER_OUTSIDE_WEST
	setvar VAR_0x8004, LOCALID_FRONTIER_SS_TIDAL
	call Common_EventScript_FerryDepartIsland
	return

BattleFrontier_OutsideWest_EventScript_CancelFerrySelect::
	msgbox BattleFrontier_OutsideWest_Text_SailWithUsAnotherTime, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_BattleDomeSign::
	msgbox BattleFrontier_OutsideWest_Text_BattleDomeSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideWest_EventScript_BattleFactorySign::
	msgbox BattleFrontier_OutsideWest_Text_BattleFactorySign, MSGBOX_SIGN
	end

BattleFrontier_OutsideWest_EventScript_BattlePikeSign::
	msgbox BattleFrontier_OutsideWest_Text_BattlePikeSign, MSGBOX_SIGN
	end

@ Unused. Of note, Battle Tower is in the East section in the final release
BattleFrontier_OutsideWest_EventScript_UnusedNPC1::
	msgbox BattleFrontier_OutsideWest_Text_ThisIsBattleTower, MSGBOX_NPC
	end

@ Unused
BattleFrontier_OutsideWest_EventScript_UnusedNPC2::
	msgbox BattleFrontier_OutsideWest_Text_CantFindBattleTower, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Boy1::
	msgbox BattleFrontier_OutsideWest_Text_BestOutOfAllMyFriends, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Fisherman2::
	lock
	faceplayer
	message BattleFrontier_OutsideWest_Text_GotSeasickOnWayHere
	waitmessage
	applymovement LOCALID_FRONTIER_FISHERMAN_2, Common_Movement_FaceAwayPlayer
	waitmovement 0
	waitbuttonpress
	release
	end

BattleFrontier_OutsideWest_EventScript_Man1::
	msgbox BattleFrontier_OutsideWest_Text_OnlyToughTrainersBroughtHere, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Maniac1::
	lock
	goto BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk
	end

BattleFrontier_OutsideWest_EventScript_Maniac2::
	lock
	goto BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk
	end

BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk::
	applymovement LOCALID_FRONTIER_MANIAC_1, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox BattleFrontier_OutsideWest_Text_SureWeCanChallengeWithNoMons, MSGBOX_DEFAULT
	applymovement LOCALID_FRONTIER_MANIAC_2, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox BattleFrontier_OutsideWest_Text_BigGuySaidIllLendYouMons, MSGBOX_DEFAULT
	closemessage
	delay 25
	applymovement LOCALID_FRONTIER_MANIAC_1, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_FRONTIER_MANIAC_2, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	release
	end

BattleFrontier_OutsideWest_EventScript_Camper::
	lock
	faceplayer
	delay 20
	call_if_eq VAR_FACING, DIR_NORTH, BattleFrontier_OutsideWest_EventScript_CamperFaceFactory
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_OutsideWest_EventScript_CamperAlreadyFacingFactory
	call_if_eq VAR_FACING, DIR_WEST, BattleFrontier_OutsideWest_EventScript_CamperFaceFactory
	call_if_eq VAR_FACING, DIR_EAST, BattleFrontier_OutsideWest_EventScript_CamperFaceFactory
	msgbox BattleFrontier_OutsideWest_Text_WhosRaisingThoseRentalMons, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_CamperFaceFactory::
	applymovement LOCALID_FRONTIER_CAMPER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_CamperAlreadyFacingFactory::
	return

BattleFrontier_OutsideWest_EventScript_Girl::
	lock
	faceplayer
	message BattleFrontier_OutsideWest_Text_ScaredOfPikeBecauseSeviper
	waitmessage
	call_if_eq VAR_FACING, DIR_NORTH, BattleFrontier_OutsideWest_EventScript_GirlShudderNorth
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_OutsideWest_EventScript_GirlShudderSouth
	call_if_eq VAR_FACING, DIR_WEST, BattleFrontier_OutsideWest_EventScript_GirlShudderWest
	call_if_eq VAR_FACING, DIR_EAST, BattleFrontier_OutsideWest_EventScript_GirlShudderEast
	waitbuttonpress
	release
	end

BattleFrontier_OutsideWest_EventScript_GirlShudderNorth::
	applymovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderNorth
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_GirlShudderSouth::
	applymovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderSouth
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_GirlShudderWest::
	applymovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderWest
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_GirlShudderEast::
	applymovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderEast
	waitmovement 0
	return

BattleFrontier_OutsideWest_Movement_GirlShudderNorth:
	walk_in_place_faster_down
	walk_in_place_faster_down
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderSouth:
	walk_in_place_faster_up
	walk_in_place_faster_up
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderWest:
	walk_in_place_faster_right
	walk_in_place_faster_right
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderEast:
	walk_in_place_faster_left
	walk_in_place_faster_left
	step_end

BattleFrontier_OutsideWest_EventScript_Woman2::
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_LetsPlayRockPaperScissors, MSGBOX_DEFAULT
	random 2
	goto_if_eq VAR_RESULT, 1, BattleFrontier_OutsideWest_EventScript_WomanWonRockPaperScissors
	goto BattleFrontier_OutsideWest_EventScript_WomanLostRockPaperScissors
	end

BattleFrontier_OutsideWest_EventScript_WomanWonRockPaperScissors::
	msgbox BattleFrontier_OutsideWest_Text_WonIllTakePikeChallenge, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_WomanLostRockPaperScissors::
	msgbox BattleFrontier_OutsideWest_Text_LostIllPutOffPikeChallenge, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_Fisherman1::
	msgbox BattleFrontier_OutsideWest_Text_ChooseFishingOverBattling, MSGBOX_NPC
	end

@ Unused
BattleFrontier_OutsideWest_EventScript_UnusedNPC3::
	msgbox BattleFrontier_OutsideWest_Text_DomeIsHereGrandpa, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Gentleman::
	msgbox BattleFrontier_OutsideWest_Text_YoureOffToChallengeDome, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Lass::
	msgbox BattleFrontier_OutsideWest_Text_KeepBattlingUntilIGetSymbol, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_ExpertM::
	msgbox BattleFrontier_OutsideWest_Text_WontLetGentlemenBeatMe, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Man2::
	msgbox BattleFrontier_OutsideWest_Text_NothingHereNotLongAgo, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Woman1::
	msgbox BattleFrontier_OutsideWest_Text_FinallyArrivedAtFrontier, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_FatMan1::
	msgbox BattleFrontier_OutsideWest_Text_SquareFilledWithToughPeople, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_FatMan2::
	msgbox BattleFrontier_OutsideWest_Text_MetOlderGirlAtPike, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Woman3::
	lock
	msgbox BattleFrontier_OutsideWest_Text_LastTimeOurEyesMet, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_Boy2::
	lock
	msgbox BattleFrontier_OutsideWest_Text_DomeAceLookedBecauseOfMyCheering, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_OldMan::
	msgbox BattleFrontier_OutsideWest_Text_DomeAceIsMine, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Man4::
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_FansOverThereUsedToBeTrainers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FRONTIER_MAN_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

BattleFrontier_OutsideWest_EventScript_PokefanF::
	msgbox BattleFrontier_OutsideWest_Text_MonWithLongTailInFrontier, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_Text_BattleDomeSign:
	.string "Đây là BATTLE DOME! Con đường đưa bạn\n"
	.string "trở thành siêu sao bất bại!$"

BattleFrontier_OutsideWest_Text_BattleFactorySign:
	.string "Đây là BATTLE FACTORY! Hãy tìm kiếm\n"
	.string "những POKéMON mạnh nhất!$"

BattleFrontier_OutsideWest_Text_BattlePikeSign:
	.string "Đây là BATTLE PIKE! Hãy chọn một trong\n"
	.string "ba lối đi!$"

BattleFrontier_OutsideWest_Text_ThisIsBattleTower:
	.string "Đây là BATTLE TOWER.\p"
	.string "HLV đưa những POKéMON được\n"
	.string "huấn luyện tốt nhất của mình tới tranh\l"
	.string "tài theo thể thức loại trực tiếp.$"

BattleFrontier_OutsideWest_Text_MayISeeYourTicket:
	.string "Xin chào, bạn đến để đi phà phải không?\n"
	.string "Cho tôi xem TICKET được chứ?$"

BattleFrontier_OutsideWest_Text_MustHaveTicketToBoard:
	.string "{PLAYER} không có TICKET...\p"
	.string "Tôi vô cùng xin lỗi.\p"
	.string "Bạn phải có TICKET mới được lên phà.$"

BattleFrontier_OutsideWest_Text_WhereWouldYouLikeToGo:
	.string "{PLAYER} giơ TICKET ra.\p"
	.string "Hoàn hảo! Chỉ cần vậy thôi!\p"
	.string "Bạn muốn đi đâu?$"

BattleFrontier_OutsideWest_Text_SlateportItIs:
	.string "Vậy thì đến SLATEPORT CITY!$"

BattleFrontier_OutsideWest_Text_LilycoveItIs:
	.string "Vậy thì đến LILYCOVE CITY!$"

BattleFrontier_OutsideWest_Text_SailWithUsAnotherTime:
	.string "Mong lần sau bạn lại đi cùng chúng tôi!$"

BattleFrontier_OutsideWest_Text_PleaseBoardFerry:
	.string "Xin hãy lên phà và chờ khởi hành.$"

BattleFrontier_OutsideWest_Text_ThenWhereWouldYouLikeToGo:
	.string "Vậy bạn muốn đi đâu?$"

BattleFrontier_OutsideWest_Text_BestOutOfAllMyFriends:
	.string "Trong nhóm bạn, tôi là người giỏi nhất.\n"
	.string "Nhưng ở đây... tôi chẳng làm được gì\l"
	.string "cả!$"

BattleFrontier_OutsideWest_Text_CantFindBattleTower:
	.string "Tôi muốn đến BATTLE TOWER, nhưng dù có\n"
	.string "bản đồ BATTLE FRONTIER, tôi vẫn không\l"
	.string "tìm ra.\p"
	.string "Nơi này rộng quá!$"

BattleFrontier_OutsideWest_Text_GotSeasickOnWayHere:
	.string "Tôi định vừa tới nơi là tham gia thử\n"
	.string "thách ngay.\p"
	.string "Nhưng dọc đường tôi bị say sóng... Ựa...$"

BattleFrontier_OutsideWest_Text_OnlyToughTrainersBroughtHere:
	.string "Không phải ai cũng có thể đến đây đâu,\n"
	.string "biết không?\p"
	.string "Chỉ những HLV được công nhận là\n"
	.string "mạnh mới được đưa tới đây.\p"
	.string "Vì thế nhiều HLV thậm chí còn\n"
	.string "không biết đến BATTLE FRONTIER.$"

BattleFrontier_OutsideWest_Text_SureWeCanChallengeWithNoMons:
	.string "Này, anh...\p"
	.string "Anh có chắc là không có POKéMON thì\n"
	.string "chúng ta vẫn tham gia thử thách được\l"
	.string "không?$"

BattleFrontier_OutsideWest_Text_BigGuySaidIllLendYouMons:
	.string "Ừm... chắc là không sao đâu.\p"
	.string "Anh nghĩ vậy...\p"
	.string "Nhưng em nhớ gã to xác đáng sợ đó\n"
	.string "chứ? Hắn nói: 'Tôi sẽ cho các cậu mượn\l"
	.string "POKéMON!'$"

BattleFrontier_OutsideWest_Text_WhosRaisingThoseRentalMons:
	.string "Đó là BATTLE FACTORY. Bạn có thể thuê\n"
	.string "những POKéMON mạnh ở đó.\p"
	.string "Nhưng tôi cứ thắc mắc. Ai đã nuôi những\n"
	.string "POKéMON cho thuê ấy nhỉ?$"

BattleFrontier_OutsideWest_Text_ScaredOfPikeBecauseSeviper:
	.string "Tôi sợ vào BATTLE PIKE vì SEVIPER...\p"
	.string "N-nhưng tôi đã lặn lội đến tận đây, nên\n"
	.string "sẽ cố chinh phục mọi thứ! ...R-run quá...$"

BattleFrontier_OutsideWest_Text_LetsPlayRockPaperScissors:
	.string "Chơi oẳn tù tì nhé! Một, hai, ba!\p"
	.string "... ... ... ... ... ...$"

BattleFrontier_OutsideWest_Text_WonIllTakePikeChallenge:
	.string "Hay quá! Tôi thắng rồi! Tôi sẽ thử sức ở\n"
	.string "BATTLE PIKE!$"

BattleFrontier_OutsideWest_Text_LostIllPutOffPikeChallenge:
	.string "Ôi không... Tôi thua rồi.\p"
	.string "Hôm nay chắc tôi không may mắn lắm. Thử\n"
	.string "thách BATTLE PIKE để mai vậy.$"

BattleFrontier_OutsideWest_Text_ChooseFishingOverBattling:
	.string "Có lẽ tôi là người duy nhất ở đây,\n"
	.string "chẳng hiểu vì sao, lại thích câu cá hơn\l"
	.string "chiến đấu.\p"
	.string "Hả? Ở đây không câu được gì à? Thất\n"
	.string "vọng thật...$"

BattleFrontier_OutsideWest_Text_KeepBattlingUntilIGetSymbol:
	.string "Hôm nay, dù có chuyện gì, tôi cũng sẽ\n"
	.string "tiếp tục chiến đấu cho đến khi giành\l"
	.string "được một Symbol.$"

BattleFrontier_OutsideWest_Text_YoureOffToChallengeDome:
	.string "Ồ? Bạn sắp đến thử thách BATTLE DOME\n"
	.string "à?\p"
	.string "Chúc bạn thật nhiều may mắn. Mong cả\n"
	.string "hai chúng ta cùng chiến thắng và gặp lại\l"
	.string "nhau trong các thử thách.$"

BattleFrontier_OutsideWest_Text_DomeIsHereGrandpa:
	.string "Ông ơi, bên này! BATTLE DOME ở đây! Cố\n"
	.string "lên ông!$"

BattleFrontier_OutsideWest_Text_WontLetGentlemenBeatMe:
	.string "À, vậy đây là BATTLE DOME sao? Ta sẽ\n"
	.string "không để GENTLEMEN đánh bại mình!\p"
	.string "Nhưng lối vào ở đâu nhỉ?$"

BattleFrontier_OutsideWest_Text_NothingHereNotLongAgo:
	.string "Cách đây chưa lâu, nơi này chẳng có gì\n"
	.string "cả.\p"
	.string "Nhưng giờ nhìn xem! Thật đáng kinh\n"
	.string "ngạc! Tôi sẽ đưa mẹ đến đây xem.$"

BattleFrontier_OutsideWest_Text_FinallyArrivedAtFrontier:
	.string "Cuối cùng tôi cũng đến BATTLE\n"
	.string "FRONTIER!\p"
	.string "Với ngoại hình và năng lực của mình,\n"
	.string "chắc chắn tôi sẽ thu hút mọi ánh nhìn!$"

BattleFrontier_OutsideWest_Text_SquareFilledWithToughPeople:
	.string "Nhai, nhai...\p"
	.string "Có vẻ quảng trường này toàn người\n"
	.string "mạnh.\p"
	.string "Nhai, nhai...$"

BattleFrontier_OutsideWest_Text_MetOlderGirlAtPike:
	.string "Rôm rốp, nhồm nhoàm...\p"
	.string "Một thời gian trước, tôi gặp một chị\n"
	.string "lớn tuổi hơn ở BATTLE PIKE.\p"
	.string "Ánh mắt chị ta dữ dằn đến đáng sợ.\p"
	.string "Rôm rốp, nhồm nhoàm...\p"
	.string "Chị ta nổi giận đùng đùng: 'Có thôi ăn đi\n"
	.string "không!' Rồi cho tôi một trận.\p"
	.string "Quả là một trải nghiệm đáng sợ đến\n"
	.string "dựng tóc gáy.\p"
	.string "Rôm rốp, nhồm nhoàm...$"

BattleFrontier_OutsideWest_Text_LastTimeOurEyesMet:
	.string "Hả? Nghe cậu nói kìa! Chuyện đó có là\n"
	.string "gì!\p"
	.string "Lần trước tôi cổ vũ anh ấy, mắt chúng\n"
	.string "tôi chạm nhau, tia lửa bắn tung tóe đấy!$"

BattleFrontier_OutsideWest_Text_DomeAceLookedBecauseOfMyCheering:
	.string "Cááááái gì?! Hừ!\p"
	.string "Chuyện đó chỉ xảy ra vì tôi tình cờ\n"
	.string "ngồi cạnh cậu thôi!\p"
	.string "DOME ACE nhìn về phía chúng ta chỉ vì\n"
	.string "tôi cổ vũ quá lớn!$"

BattleFrontier_OutsideWest_Text_DomeAceIsMine:
	.string "Ôi, im đi! Bớt ồn ào lại!\p"
	.string "Đám người hâm mộ lúc nắng lúc mưa các\n"
	.string "cậu cứ đi cổ vũ GYM LEADER nào đó đi!\p"
	.string "DOME ACE là của tôi! Là thần tượng duy\n"
	.string "nhất của tôi!$"

BattleFrontier_OutsideWest_Text_FansOverThereUsedToBeTrainers:
	.string "Những người đang cãi nhau đằng kia...\p"
	.string "Khó tin thật, nhưng trước đây họ từng\n"
	.string "là HLV, lại còn rất giỏi.\p"
	.string "Họ từng mạnh khủng khiếp và cũng rất\n"
	.string "nổi tiếng.\p"
	.string "Nhưng rồi họ bị một HLV nọ nghiền\n"
	.string "nát tại một giải đấu.\p"
	.string "Thua tâm phục khẩu phục đến mức họ mê\n"
	.string "mẩn HLV đó.\p"
	.string "Giờ họ chỉ còn là người hâm mộ của\n"
	.string "HLV ấy. Ngày nào họ cũng đến\l"
	.string "BATTLE DOME cổ vũ thần tượng.$"

BattleFrontier_OutsideWest_Text_MonWithLongTailInFrontier:
	.string "Tôi nghe đồn có người nhìn thấy một\n"
	.string "POKéMON với cái đuôi dài khác thường ở\l"
	.string "đâu đó trong BATTLE FRONTIER.\p"
	.string "Hẳn nó phải đáng yêu lắm. Tôi chắc\n"
	.string "chắn...\p"
	.string "Thôi, thử thách để sau. Tôi nhất định\n"
	.string "phải tìm cho ra sinh vật đáng yêu ấy!$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global BattleFrontier_OutsideWest_Text_BattleDomeSign
	.global BattleFrontier_OutsideWest_Text_BattleFactorySign
	.global BattleFrontier_OutsideWest_Text_BattlePikeSign
	.global BattleFrontier_OutsideWest_Text_ThisIsBattleTower
	.global BattleFrontier_OutsideWest_Text_MayISeeYourTicket
	.global BattleFrontier_OutsideWest_Text_MustHaveTicketToBoard
	.global BattleFrontier_OutsideWest_Text_WhereWouldYouLikeToGo
	.global BattleFrontier_OutsideWest_Text_SlateportItIs
	.global BattleFrontier_OutsideWest_Text_LilycoveItIs
	.global BattleFrontier_OutsideWest_Text_SailWithUsAnotherTime
	.global BattleFrontier_OutsideWest_Text_PleaseBoardFerry
	.global BattleFrontier_OutsideWest_Text_ThenWhereWouldYouLikeToGo
	.global BattleFrontier_OutsideWest_Text_BestOutOfAllMyFriends
	.global BattleFrontier_OutsideWest_Text_CantFindBattleTower
	.global BattleFrontier_OutsideWest_Text_GotSeasickOnWayHere
	.global BattleFrontier_OutsideWest_Text_OnlyToughTrainersBroughtHere
	.global BattleFrontier_OutsideWest_Text_SureWeCanChallengeWithNoMons
	.global BattleFrontier_OutsideWest_Text_BigGuySaidIllLendYouMons
	.global BattleFrontier_OutsideWest_Text_WhosRaisingThoseRentalMons
	.global BattleFrontier_OutsideWest_Text_ScaredOfPikeBecauseSeviper
	.global BattleFrontier_OutsideWest_Text_LetsPlayRockPaperScissors
	.global BattleFrontier_OutsideWest_Text_WonIllTakePikeChallenge
	.global BattleFrontier_OutsideWest_Text_LostIllPutOffPikeChallenge
	.global BattleFrontier_OutsideWest_Text_ChooseFishingOverBattling
	.global BattleFrontier_OutsideWest_Text_KeepBattlingUntilIGetSymbol
	.global BattleFrontier_OutsideWest_Text_YoureOffToChallengeDome
	.global BattleFrontier_OutsideWest_Text_DomeIsHereGrandpa
	.global BattleFrontier_OutsideWest_Text_WontLetGentlemenBeatMe
	.global BattleFrontier_OutsideWest_Text_NothingHereNotLongAgo
	.global BattleFrontier_OutsideWest_Text_FinallyArrivedAtFrontier
	.global BattleFrontier_OutsideWest_Text_SquareFilledWithToughPeople
	.global BattleFrontier_OutsideWest_Text_MetOlderGirlAtPike
	.global BattleFrontier_OutsideWest_Text_LastTimeOurEyesMet
	.global BattleFrontier_OutsideWest_Text_DomeAceLookedBecauseOfMyCheering
	.global BattleFrontier_OutsideWest_Text_DomeAceIsMine
	.global BattleFrontier_OutsideWest_Text_FansOverThereUsedToBeTrainers
	.global BattleFrontier_OutsideWest_Text_MonWithLongTailInFrontier
@ END GENERATED LOCALIZATION EXPORTS
