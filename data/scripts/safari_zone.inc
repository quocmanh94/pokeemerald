SafariZone_EventScript_OutOfBallsMidBattle::
	setvar VAR_SAFARI_ZONE_STATE, 1
	special ExitSafariMode
	setwarp MAP_ROUTE121_SAFARI_ZONE_ENTRANCE, 2, 5
	end

SafariZone_EventScript_Exit::
	setvar VAR_SAFARI_ZONE_STATE, 1
	special ExitSafariMode
	warp MAP_ROUTE121_SAFARI_ZONE_ENTRANCE, 2, 5
	waitstate
	end

SafariZone_EventScript_RetirePrompt::
	lockall
	msgbox SafariZone_Text_WouldYouLikeToExit, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SafariZone_EventScript_Retire
	releaseall
	end

SafariZone_EventScript_Retire::
	goto SafariZone_EventScript_Exit

SafariZone_EventScript_TimesUp::
	lockall
	playse SE_DING_DONG
	message SafariZone_Text_TimesUp
	waitmessage
	waitbuttonpress
	releaseall
	goto SafariZone_EventScript_Exit

SafariZone_EventScript_OutOfBalls::
	lockall
	playse SE_DING_DONG
	message SafariZone_Text_OutOfBalls
	waitmessage
	waitbuttonpress
	releaseall
	goto SafariZone_EventScript_Exit

EventScript_PokeBlockFeeder::
	lockall
	special GetPokeblockFeederInFront
	goto_if_ne VAR_RESULT, 0xFFFF, SafariZone_EventScript_PokeblockPresent
	msgbox SafariZone_Text_PlacePokeblockOnFeeder, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SafariZone_EventScript_ChoosePokeblock
	releaseall
	end

SafariZone_EventScript_ChoosePokeblock::
	fadescreen FADE_TO_BLACK
	special OpenPokeblockCaseOnFeeder
	goto_if_ne VAR_RESULT, 0xFFFF, SafariZone_EventScript_PokeblockPlaced
#ifdef BUGFIX
	releaseall  @ Only gets called from EventScript_PokeBlockFeeder which uses lockall.
#endif
	end

SafariZone_EventScript_PokeblockPlaced::
	message SafariZone_Text_PokeblockWasPlaced
	waitmessage
	waitbuttonpress
	releaseall
	end

SafariZone_EventScript_PokeblockPresent::
	message SafariZone_Text_PokeblockStillHere
	waitmessage
	waitbuttonpress
	releaseall
	end

SafariZone_Text_WouldYouLikeToExit:
	.string "Bạn có muốn rời SAFARI ZONE\n"
	.string "ngay bây giờ không?$"

SafariZone_Text_TimesUp:
	.string "Ding-dong! Hết giờ!\n"
	.string "SAFARI Game đã kết thúc.$"

SafariZone_Text_OutOfBalls:
	.string "Bạn đã hết SAFARI BALLS.\n"
	.string "SAFARI Game đã kết thúc.$"

SafariZone_Text_PlacePokeblockOnFeeder:
	.string "Bạn có muốn đặt một {POKEBLOCK}\n"
	.string "lên {POKEBLOCK} FEEDER không?$"

SafariZone_Text_PokeblockStillHere:
	.string "{STR_VAR_1} bạn đặt trước đó\n"
	.string "vẫn còn ở đây.$"

SafariZone_Text_PokeblockWasPlaced:
	.string "Đã đặt {STR_VAR_1}\n"
	.string "lên {POKEBLOCK} FEEDER.$"

Route121_SafariZoneEntrance_Text_WelcomeToSafariZone:
	.string "Chào mừng đến SAFARI ZONE!\p"
	.string "Tại đây, bạn có thể thấy nhiều loài\n"
	.string "POKéMON hiếm gặp ở HOENN.\p"
	.string "Bạn sẽ thấy chúng sống hoang dã\n"
	.string "trong môi trường tự nhiên.\p"
	.string "Hơn nữa, chúng tôi đã mở cửa\n"
	.string "cho các HLV POKéMON.\p"
	.string "Hãy bắt và mang POKéMON về nhé!\p"
	.string "Mời vào tận hưởng SAFARI ZONE!$"

Route121_SafariZoneEntrance_Text_WelcomeFirstTime:
	.string "Chào mừng đến SAFARI ZONE!\n"
	.string "Đây là lần đầu bạn đến sao?$"

Route121_SafariZoneEntrance_Text_ComeInAndEnjoy:
	.string "Mời vào tận hưởng SAFARI ZONE!$"

Route121_SafariZoneEntrance_Text_FirstTimeInfo:
	.string "Khi vào SAFARI ZONE, bạn sẽ nhận\n"
	.string "30 SAFARI BALLS để bắt POKéMON.\p"
	.string "SAFARI Game kết thúc khi bạn hết\n"
	.string "SAFARI BALLS hoặc đã đi 500 bước.\p"
	.string "Mời vào tận hưởng SAFARI ZONE!$"

Route121_SafariZoneEntrance_Text_WouldYouLikeToPlay:
	.string "Chào mừng đến SAFARI ZONE!\p"
	.string "Chỉ ¥500, bắt được bao nhiêu tùy sức!\n"
	.string "Bạn muốn chơi SAFARI Game không?$"

Route121_SafariZoneEntrance_Text_PlayAnotherTime:
	.string "Được rồi.\n"
	.string "Hẹn bạn lần sau!$"

Route121_SafariZoneEntrance_Text_NotEnoughMoney:
	.string "Bạn không có đủ tiền.\n"
	.string "Xin lỗi nhé.$"

Route121_SafariZoneEntrance_Text_ThatWillBe500Please:
	.string "Xin trả ¥500.$"

Route121_SafariZoneEntrance_Text_HereAreYourSafariBalls:
	.string "Đây là SAFARI BALLS của bạn.$"

Route121_SafariZoneEntrance_Text_Received30SafariBalls:
	.string "{PLAYER} đã nhận 30 SAFARI BALLS.$"

Route121_SafariZoneEntrance_Text_PleaseEnjoyYourself:
	.string "Chúng tôi sẽ báo khi trò chơi\n"
	.string "kết thúc.\p"
	.string "Đến lúc đó, hãy tận hưởng nhé!\n"
	.string "Lên đường khám phá hoang dã nào!$"

Route121_SafariZoneEntrance_Text_PCIsFull:
	.string "Xin lỗi!\n"
	.string "PC BOX của bạn đã đầy.$"

Route121_SafariZoneEntrance_Text_YouNeedPokeblockCase:
	.string "Xin lỗi!\n"
	.string "Có vẻ bạn không có {POKEBLOCK} CASE.\p"
	.string "SAFARI Game sẽ hiệu quả hơn nhiều\n"
	.string "nếu bạn dùng {POKEBLOCK}.\p"
	.string "Hãy quay lại cùng {POKEBLOCK} CASE.\p"
	.string "Bạn có thể nhận {POKEBLOCK} CASE tại\n"
	.string "LILYCOVE CONTEST HALL.$"

SafariZone_South_Text_StillHaveTimeExit:
	.string "Bạn vẫn còn thời gian. Bạn có muốn\n"
	.string "rời SAFARI ZONE ngay không?$"

SafariZone_South_Text_EnjoyTheRestOfYourAdventure:
	.string "Hãy tận hưởng phần còn lại của\n"
	.string "chuyến phiêu lưu hoang dã!$"

SafariZone_South_Text_ExitEarlyThankYouForPlaying:
	.string "Được rồi.\p"
	.string "Tôi sẽ thu lại số SAFARI BALLS\n"
	.string "còn dư của bạn.\p"
	.string "Cảm ơn bạn đã tham gia.\n"
	.string "Hẹn gặp lại!$"

SafariZone_South_Text_GoodLuck:
	.string "Chúc may mắn!\p"
	.string "Nếu cần gì, cứ nói với tôi nhé!$"

SafariZone_South_Text_Boy:
	.string "Bạn biết không?\p"
	.string "Nếu đặt {POKEBLOCK} vào chiếc hộp vuông,\n"
	.string "POKéMON sẽ tụ tập quanh đó.$"

SafariZone_South_Text_Man:
	.string "Tôi muốn đi sâu hơn, nhưng lại\n"
	.string "quên mang theo BIKE.\p"
	.string "Tôi có cảm giác POKéMON hiếm\n"
	.string "sống ở những khu vực xa hơn.$"

SafariZone_Southwest_Text_Woman:
	.string "Đôi khi tôi ném {POKEBLOCK} cho POKéMON,\n"
	.string "nhưng chúng lại phớt lờ.\p"
	.string "POKéMON cũng kén món mình ăn sao?$"

SafariZone_Northwest_Text_Man:
	.string "Hộc… Hộc…\n"
	.string "Tôi…đã đến được đây…nhưng…\p"
	.string "Kiệt sức rồi… Tôi không còn\n"
	.string "sức để bắt POKéMON nữa…$"

SafariZone_North_Text_Fisherman:
	.string "Tôi đang tìm WATER POKéMON\n"
	.string "không xuất hiện ở HOENN.\p"
	.string "Bạn biết hồ nước ở đâu không?$"

SafariZone_North_Text_Man:
	.string "Tôi sẽ bắt thật nhiều POKéMON hiếm\n"
	.string "ở đây rồi trao đổi với bạn bè!$"

SafariZone_South_Text_Youngster:
	.string "Tôi đặt {POKEBLOCK} lên {POKEBLOCK} FEEDER,\n"
	.string "nhưng nó biến mất rồi.\p"
	.string "Chắc POKéMON đã ăn khi tôi không để ý.$"

Route121_SafariZoneEntrance_Text_TrainerTip:
	.string "SAFARI ZONE TRAINER TIP!\p"
	.string "Ném {POKEBLOCK} cho POKéMON hoang dã\n"
	.string "để chúng ít bỏ chạy hơn.$"

SafariZone_Southwest_Text_RestHouseSign:
	.string "“Cho đôi chân mệt mỏi nghỉ ngơi.”\n"
	.string "REST HOUSE$"

SafariZone_RestHouse_Text_Youngster:
	.string "Tôi không có {POKEBLOCK}, nhưng vẫn bắt\n"
	.string "được khá nhiều POKéMON.\p"
	.string "Bạn sẽ dễ bắt hơn nếu tiến lại gần\n"
	.string "trước khi ném SAFARI BALL.$"

SafariZone_RestHouse_Text_PsychicM:
	.string "Dùng {POKEBLOCK} sẽ khiến POKéMON hoang dã\n"
	.string "không vội bỏ chạy.\p"
	.string "Nhưng không cần dùng với POKéMON\n"
	.string "vốn ít khi bỏ chạy.$"

SafariZone_RestHouse_Text_FatMan:
	.string "Đặt {POKEBLOCK} lên FEEDER sẽ thu hút\n"
	.string "POKéMON đến đó.\p"
	.string "Có lẽ những POKéMON cùng Nature\n"
	.string "sẽ bị hấp dẫn bởi một loại {POKEBLOCK}.$"

SafariZone_South_Text_AreaOffLimits1:
	.string "Khu vực này vẫn đang được xây dựng.\n"
	.string "Xin lỗi, không được vào!$"

SafariZone_Southeast_Text_ExpansionIsFinished:
	.string "Dự án mở rộng SAFARI ZONE\n"
	.string "đã hoàn thành.\p"
	.string "Hy vọng bạn thích khu vực mới.$"

SafariZone_South_Text_AreaOffLimits2:
	.string "Khu vực này vẫn đang được xây dựng.\n"
	.string "Xin lỗi, không được vào!$"

SafariZone_Southeast_Text_LittleGirl:
	.string "Wow! Tuyệt quá! Mình chưa từng thấy\n"
	.string "những POKéMON này!$"

SafariZone_Southeast_Text_FatMan:
	.string "POKéMON ở khu vực này đều\n"
	.string "rất lạ với tôi.\p"
	.string "Lại còn được phép bắt chúng nữa!\n"
	.string "Tuyệt thật!$"

SafariZone_Southeast_Text_RichBoy:
	.string "POKéMON quanh đây có vẻ đến từ\n"
	.string "một nơi khác ngoài HOENN.$"

SafariZone_Northeast_Text_Boy:
	.string "Tôi chỉ còn vài SAFARI BALLS.\p"
	.string "Khó quyết định nên bắt gì quá.$"

SafariZone_Northeast_Text_Woman:
	.string "Tôi nghe nói có thể thấy PIKACHU ở đây.\n"
	.string "Không biết chúng ở đâu nhỉ?$"

SafariZone_Northeast_Text_Girl:
	.string "Ôi, chán quá!\n"
	.string "Tôi chẳng bắt được gì cả!\p"
	.string "Nếu không bắt được gì thì phí\n"
	.string "mất tiền vào cửa!$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global SafariZone_Text_WouldYouLikeToExit
	.global SafariZone_Text_TimesUp
	.global SafariZone_Text_OutOfBalls
	.global SafariZone_Text_PlacePokeblockOnFeeder
	.global SafariZone_Text_PokeblockStillHere
	.global SafariZone_Text_PokeblockWasPlaced
	.global Route121_SafariZoneEntrance_Text_WelcomeToSafariZone
	.global Route121_SafariZoneEntrance_Text_WelcomeFirstTime
	.global Route121_SafariZoneEntrance_Text_ComeInAndEnjoy
	.global Route121_SafariZoneEntrance_Text_FirstTimeInfo
	.global Route121_SafariZoneEntrance_Text_WouldYouLikeToPlay
	.global Route121_SafariZoneEntrance_Text_PlayAnotherTime
	.global Route121_SafariZoneEntrance_Text_NotEnoughMoney
	.global Route121_SafariZoneEntrance_Text_ThatWillBe500Please
	.global Route121_SafariZoneEntrance_Text_HereAreYourSafariBalls
	.global Route121_SafariZoneEntrance_Text_Received30SafariBalls
	.global Route121_SafariZoneEntrance_Text_PleaseEnjoyYourself
	.global Route121_SafariZoneEntrance_Text_PCIsFull
	.global Route121_SafariZoneEntrance_Text_YouNeedPokeblockCase
	.global SafariZone_South_Text_StillHaveTimeExit
	.global SafariZone_South_Text_EnjoyTheRestOfYourAdventure
	.global SafariZone_South_Text_ExitEarlyThankYouForPlaying
	.global SafariZone_South_Text_GoodLuck
	.global SafariZone_South_Text_Boy
	.global SafariZone_South_Text_Man
	.global SafariZone_Southwest_Text_Woman
	.global SafariZone_Northwest_Text_Man
	.global SafariZone_North_Text_Fisherman
	.global SafariZone_North_Text_Man
	.global SafariZone_South_Text_Youngster
	.global Route121_SafariZoneEntrance_Text_TrainerTip
	.global SafariZone_Southwest_Text_RestHouseSign
	.global SafariZone_RestHouse_Text_Youngster
	.global SafariZone_RestHouse_Text_PsychicM
	.global SafariZone_RestHouse_Text_FatMan
	.global SafariZone_South_Text_AreaOffLimits1
	.global SafariZone_Southeast_Text_ExpansionIsFinished
	.global SafariZone_South_Text_AreaOffLimits2
	.global SafariZone_Southeast_Text_LittleGirl
	.global SafariZone_Southeast_Text_FatMan
	.global SafariZone_Southeast_Text_RichBoy
	.global SafariZone_Northeast_Text_Boy
	.global SafariZone_Northeast_Text_Woman
	.global SafariZone_Northeast_Text_Girl
@ END GENERATED LOCALIZATION EXPORTS
