BattleFrontier_OutsideEast_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_OutsideEast_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_OutsideEast_OnTransition
	.byte 0

BattleFrontier_OutsideEast_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, BattleFrontier_OutsideEast_EventScript_TryRemoveSudowoodo
	end

BattleFrontier_OutsideEast_EventScript_TryRemoveSudowoodo::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

BattleFrontier_OutsideEast_OnTransition:
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, 0
	setflag FLAG_HIDE_BATTLE_TOWER_REPORTER
	call_if_unset FLAG_DEFEATED_SUDOWOODO, BattleFrontier_OutsideEast_EventScript_ShowSudowoodo
	end

BattleFrontier_OutsideEast_EventScript_ShowSudowoodo::
	clearflag FLAG_HIDE_BATTLE_FRONTIER_SUDOWOODO
	return

BattleFrontier_OutsideEast_EventScript_BattleTowerSign::
	msgbox BattleFrontier_OutsideEast_Text_BattleTowerSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_BattlePalaceSign::
	msgbox BattleFrontier_OutsideEast_Text_BattlePalaceSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_BattleArenaSign::
	msgbox BattleFrontier_OutsideEast_Text_BattleArenaSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_BattlePyramidSign::
	msgbox BattleFrontier_OutsideEast_Text_BattlePyramidSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_NinjaBoy::
	msgbox BattleFrontier_OutsideEast_Text_BattleTowerFeelsSpecial, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Man1::
	msgbox BattleFrontier_OutsideEast_Text_ConquerLeagueAndFrontier, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Hiker::
	msgbox BattleFrontier_OutsideEast_Text_PyramidTooHarsh, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_HexManiac::
	msgbox BattleFrontier_OutsideEast_Text_ThriveInDarkness, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_BlackBelt1::
	msgbox BattleFrontier_OutsideEast_Text_PutTogetherUltimateTeam, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Cook::
	lock
	msgbox BattleFrontier_OutsideEast_Text_BelieveInYouBuddy, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox BattleFrontier_OutsideEast_Text_ZigzagoonLooksVacant, MSGBOX_DEFAULT
	waitmoncry
	release
	end

BattleFrontier_OutsideEast_EventScript_RichBoy::
	msgbox BattleFrontier_OutsideEast_Text_PeopleCallMeBusybody, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_ExpertF::
	msgbox BattleFrontier_OutsideEast_Text_OnceBeatGymLeader, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_TriathleteF::
	msgbox BattleFrontier_OutsideEast_Text_FastOnBikeAndBattles, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Twin::
	msgbox BattleFrontier_OutsideEast_Text_BetterThanDaddyAtPokemon, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Man2::
	lock
	msgbox BattleFrontier_OutsideEast_Text_GoRackUpSomeWinsForDaddy, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_TriathleteM::
	msgbox BattleFrontier_OutsideEast_Text_DidScottBringYouHere, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Sudowoodo::
	lock
	faceplayer
	waitse
	playse SE_SUDOWOODO_SHAKE
	applymovement LOCALID_FRONTIER_SUDOWOODO, BattleFrontier_OutsideEast_Movement_SudowoodoShake
	waitmovement 0
	release
	end

BattleFrontier_OutsideEast_EventScript_WaterSudowoodo::
	lock
	faceplayer
	special DoWateringBerryTreeAnim
	waitse
	playse SE_SUDOWOODO_SHAKE
	applymovement LOCALID_FRONTIER_SUDOWOODO, BattleFrontier_OutsideEast_Movement_SudowoodoShake
	waitmovement 0
	msgbox gText_Sudowoodo_Attacked, MSGBOX_DEFAULT
	closemessage
	waitse
	playmoncry SPECIES_SUDOWOODO, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setvar VAR_LAST_TALKED, LOCALID_FRONTIER_SUDOWOODO
	setwildbattle SPECIES_SUDOWOODO, 40
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo
	setflag FLAG_DEFEATED_SUDOWOODO
	release
	end

BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo::
	setflag FLAG_DEFEATED_SUDOWOODO
	goto Common_EventScript_RemoveStaticPokemon
	end

BattleFrontier_OutsideEast_Movement_SudowoodoShake:
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	delay_8
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	step_end

BattleFrontier_OutsideEast_EventScript_Maniac1::
	msgbox BattleFrontier_OutsideEast_Text_HeardPrettyGirlAtBattleArena, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Girl::
	msgbox BattleFrontier_OutsideEast_Text_SometimesImportantOldManInThere, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_PsychicM::
	msgbox BattleFrontier_OutsideEast_Text_LegendOfBattlePyramid, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Man3::
	msgbox BattleFrontier_OutsideEast_Text_GotWipedOut, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Woman1::
	msgbox BattleFrontier_OutsideEast_Text_ToughTrainerInBattleTower, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Woman2::
	msgbox BattleFrontier_OutsideEast_Text_EnoughBattlePointsForDoll, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_BlackBelt2::
	msgbox BattleFrontier_OutsideEast_Text_LikeToHaveNameRecordedHere, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Maniac2::
	lock
	msgbox BattleFrontier_OutsideEast_Text_CanDoAnythingWithYou, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_Woman3::
	lock
	msgbox BattleFrontier_OutsideEast_Text_PowerOfOurLoveWillOvercome, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_RankingHallSign::
	msgbox BattleFrontier_OutsideEast_Text_RankingHallSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_ExchangeCornerSign::
	msgbox BattleFrontier_OutsideEast_Text_ExchangeCornerSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_Gentleman::
	msgbox BattleFrontier_OutsideEast_Text_FrontierNotExclusivelyForToughTrainers, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_OldWoman::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_SUDOWOODO, BattleFrontier_OutsideEast_EventScript_OldWomanSudowoodoGone
	msgbox BattleFrontier_OutsideEast_Text_OddTreeHereSeemsToWiggle, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_OldWomanSudowoodoGone::
	msgbox BattleFrontier_OutsideEast_Text_OnceAnOddTreePastHere, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_Camper::
	msgbox BattleFrontier_OutsideEast_Text_StickyMonWithLongTail, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_Text_BattleTowerSign:
	.string "Đây là BATTLE TOWER! Hãy trở thành\n"
	.string "HLV mạnh nhất và kéo dài chuỗi\l"
	.string "chiến thắng!$"

BattleFrontier_OutsideEast_Text_BattlePalaceSign:
	.string "Đây là BATTLE PALACE! Hãy dõi theo\n"
	.string "những trận đấu POKéMON!$"

BattleFrontier_OutsideEast_Text_BattleArenaSign:
	.string "Đây là BATTLE ARENA! Nơi quy tụ những\n"
	.string "đội mạnh nhất!$"

BattleFrontier_OutsideEast_Text_BattlePyramidSign:
	.string "Đây là BATTLE PYRAMID! Tiến bước trong\n"
	.string "Battle Quest!$"

BattleFrontier_OutsideEast_Text_RankingHallSign:
	.string "BATTLE FRONTIER RANKING HALL Hướng\n"
	.string "tới những kỷ lục mới!$"

BattleFrontier_OutsideEast_Text_ExchangeCornerSign:
	.string "BATTLE POINT EXCHANGE SERVICE CORNER\n"
	.string "Hãy đổi Battle Points của bạn!$"

BattleFrontier_OutsideEast_Text_BattleTowerFeelsSpecial:
	.string "Chà! To thật!\p"
	.string "BATTLE TOWER có cảm giác rất đặc biệt.\n"
	.string "Nó khác hẳn những nơi còn lại.$"

BattleFrontier_OutsideEast_Text_ConquerLeagueAndFrontier:
	.string "Tham vọng lớn nhất của tôi là chinh\n"
	.string "phục cả BATTLE FRONTIER lẫn POKéMON\l"
	.string "LEAGUE.\p"
	.string "Và nếu ước mơ đó thành sự thật...\p"
	.string "Tôi... tôi sẽ hỏi MIMI nhà bên xem cô ấy\n"
	.string "có chịu làm bạn với tôi không!$"

BattleFrontier_OutsideEast_Text_PyramidTooHarsh:
	.string "BATTLE PYRAMID khắc nghiệt quá! Tôi\n"
	.string "không thể nào lên đến đỉnh!\p"
	.string "Hết cách rồi, hay là mình leo bên ngoài...$"

BattleFrontier_OutsideEast_Text_ThriveInDarkness:
	.string "Ta sinh ra để sống trong bóng tối...\n"
	.string "Phải... Còn nơi nào xứng với ta? Không\l"
	.string "đâu khác ngoài BATTLE PYRAMID...\p"
	.string "Ngươi nghĩ sao về việc lang thang\n"
	.string "trong bóng tối, giữa nỗi tuyệt vọng\l"
	.string "cùng cực?$"

BattleFrontier_OutsideEast_Text_PutTogetherUltimateTeam:
	.string "Tôi thức trắng suốt một tuần, nhưng\n"
	.string "cuối cùng cũng lập được đội hình tối\l"
	.string "thượng!\p"
	.string "Nói thật, tôi không thể tưởng tượng\n"
	.string "mình sẽ thua. Chúng tôi sẽ càn quét\l"
	.string "BATTLE ARENA!$"

BattleFrontier_OutsideEast_Text_DidScottBringYouHere:
	.string "SCOTT cũng đưa bạn tới đây à? Ông ta\n"
	.string "đúng là sao vậy nhỉ?\p"
	.string "Nghe nói ông ta thật sự có tài nhận ra\n"
	.string "những HLV xuất sắc, nhưng...\p"
	.string "Tôi chưa từng tận mắt thấy ông ta\n"
	.string "chiến đấu bao giờ.$"

BattleFrontier_OutsideEast_Text_BelieveInYouBuddy:
	.string "ZIGG! Tôi tin cậu, bạn nhỏ!\p"
	.string "Nếu cậu thắng, tôi sẽ làm cho ZIGG bé\n"
	.string "bỏng bất cứ món ngon khoái khẩu nào\l"
	.string "cậu thích!$"

BattleFrontier_OutsideEast_Text_ZigzagoonLooksVacant:
	.string "ZIGZAGOON trông đờ đẫn...$"

BattleFrontier_OutsideEast_Text_PeopleCallMeBusybody:
	.string "Mọi người bảo tôi hay lo chuyện bao\n"
	.string "đồng, nhưng tôi không nhịn được.\p"
	.string "Mũ bạn đội lệch rồi! Ôi không, có rác\n"
	.string "dưới đất! Ối, sắp đến giờ ăn tối rồi!\p"
	.string "Không biết tôi có chịu nổi việc chỉ\n"
	.string "đứng nhìn ở BATTLE PALACE không nữa...$"

BattleFrontier_OutsideEast_Text_OnceBeatGymLeader:
	.string "Giờ trông tôi có thể chẳng ấn tượng\n"
	.string "lắm, nhưng trước đây tôi từng đánh bại\l"
	.string "một GYM LEADER.\p"
	.string "Biết đâu tôi nên thử một lần nữa để tìm\n"
	.string "lại vinh quang.$"

BattleFrontier_OutsideEast_Text_FastOnBikeAndBattles:
	.string "Tôi chạy BIKE rất nhanh, và chiến đấu\n"
	.string "cũng nhanh y như vậy.\p"
	.string "Tôi thắng trận chỉ trong chớp mắt!$"

BattleFrontier_OutsideEast_Text_BetterThanDaddyAtPokemon:
	.string "Tớ giỏi POKéMON hơn ba tớ.$"

BattleFrontier_OutsideEast_Text_GoRackUpSomeWinsForDaddy:
	.string "Cố lên, cục cưng của ba! Thắng thật\n"
	.string "nhiều trận cho ba nhé!\p"
	.string "Con giống hệt mẹ, nên chắc chắn sẽ áp\n"
	.string "đảo tất cả!$"

BattleFrontier_OutsideEast_Text_HeardPrettyGirlAtBattleArena:
	.string "Đến được đây chẳng dễ dàng gì, nhưng\n"
	.string "tôi nghe nói ở BATTLE ARENA có một cô\l"
	.string "nàng xinh đẹp mê hồn.\p"
	.string "Thay vì cô ấy, bạn biết tôi tìm thấy gì\n"
	.string "không?\p"
	.string "Cả một đám đông nhung nhúc võ sĩ đổ mồ\n"
	.string "hôi, bốc mùi và cục mịch!$"

BattleFrontier_OutsideEast_Text_SometimesImportantOldManInThere:
	.string "Thỉnh thoảng tôi thấy một ông lão trông\n"
	.string "rất quyền thế đi vào đó.\p"
	.string "Ông ấy có những POKéMON cực kỳ lợi hại.\n"
	.string "Dù vậy, ông ấy có vẻ rất tốt bụng.$"

BattleFrontier_OutsideEast_Text_LegendOfBattlePyramid:
	.string "Bạn có biết không? Truyền thuyết về\n"
	.string "BATTLE PYRAMID ấy?\p"
	.string "Khi một HLV đầy tự tin vươn tới\n"
	.string "đỉnh vàng, một bậc đại trượng phu sẽ\l"
	.string "xuất hiện.\p"
	.string "Chưa từng nghe truyền thuyết đó à?\n"
	.string "Tất nhiên rồi! Tôi vừa bịa ra mà!\p"
	.string "Nó có ý nghĩa gì ư? Chuyện đó thì, bạn\n"
	.string "tôi ơi, tôi không thể nói!$"

BattleFrontier_OutsideEast_Text_GotWipedOut:
	.string "Trời đất! Tôi chưa từng thua lần nào!\p"
	.string "Vậy mà lần này tôi bị đánh bại tan tác,\n"
	.string "chẳng còn chút thể diện nào!\p"
	.string "Rồi họ còn bảo tôi không có tài nữa\n"
	.string "chứ?! Trời ơi!$"

BattleFrontier_OutsideEast_Text_ToughTrainerInBattleTower:
	.string "Anh chàng này đụng phải một HLV\n"
	.string "đáng sợ vô cùng khi đang chinh phục\l"
	.string "BATTLE TOWER.\p"
	.string "Giờ nhìn anh ta xem...\p"
	.string "Nếu bạn định đến BATTLE TOWER, nhất\n"
	.string "định phải cẩn thận.$"

BattleFrontier_OutsideEast_Text_EnoughBattlePointsForDoll:
	.string "Tuyệt! Cuối cùng tôi cũng có đủ Battle\n"
	.string "Points!\p"
	.string "Chắc tôi sẽ đổi lấy thêm một con DOLL\n"
	.string "nhồi bông khổng lồ nữa!$"

BattleFrontier_OutsideEast_Text_LikeToHaveNameRecordedHere:
	.string "À, phải rồi! Vậy đây là RANKING HALL!\p"
	.string "Tôi muốn đi vào lịch sử như một siêu vô\n"
	.string "địch và để tên mình được lưu lại đây\l"
	.string "cho hậu thế.$"

BattleFrontier_OutsideEast_Text_CanDoAnythingWithYou:
	.string "Có bạn bên cạnh, tôi làm được mọi thứ.$"

BattleFrontier_OutsideEast_Text_PowerOfOurLoveWillOvercome:
	.string "Ôi, cưng ơi, cưng tuyệt vời quá!\p"
	.string "Ôi, không thể chờ thêm nữa rồi!\p"
	.string "Chúng ta đến MULTI BATTLE ROOM ngay\n"
	.string "bây giờ đi!\p"
	.string "Nếu chúng ta sát cánh trong BATTLE\n"
	.string "SALON, sức mạnh tình yêu của chúng ta\l"
	.string "sẽ vượt qua mọi đối thủ.\p"
	.string "Trước chúng ta, cưng à, tất cả sẽ đổ\n"
	.string "rạp như domino!$"

BattleFrontier_OutsideEast_Text_FrontierNotExclusivelyForToughTrainers:
	.string "BATTLE FRONTIER không chỉ dành riêng\n"
	.string "cho những HLV mạnh.\p"
	.string "Có vẻ nhiều người sở hữu năng lực đặc\n"
	.string "biệt cũng được mời tới.\p"
	.string "SCOTT...\p"
	.string "Có lẽ ông ta xây nơi này để phục vụ một\n"
	.string "mục tiêu lớn hơn...$"

BattleFrontier_OutsideEast_Text_OddTreeHereSeemsToWiggle:
	.string "Xin lỗi, người trẻ tuổi. Mắt cậu có tinh\n"
	.string "không?\p"
	.string "Qua đây có một cái cây kỳ lạ, mà đôi mắt\n"
	.string "mỏi mệt của ta cứ thấy nó ngọ nguậy.$"

BattleFrontier_OutsideEast_Text_OnceAnOddTreePastHere:
	.string "Xin lỗi, người trẻ tuổi. Trí nhớ cậu có\n"
	.string "tốt không?\p"
	.string "Ta cứ có cảm giác trước đây qua chỗ\n"
	.string "này từng có một cái cây kỳ lạ.$"

BattleFrontier_OutsideEast_Text_StickyMonWithLongTail:
	.string "Tôi... tôi thấy nó rồi!\p"
	.string "Phía trước có một POKéMON trông dính\n"
	.string "dính với cái đuôi dài!\p"
	.string "Nó nấp dưới một tảng đá và cứ nhìn\n"
	.string "chằm chằm vào tôi!$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global BattleFrontier_OutsideEast_Text_BattleTowerSign
	.global BattleFrontier_OutsideEast_Text_BattlePalaceSign
	.global BattleFrontier_OutsideEast_Text_BattleArenaSign
	.global BattleFrontier_OutsideEast_Text_BattlePyramidSign
	.global BattleFrontier_OutsideEast_Text_RankingHallSign
	.global BattleFrontier_OutsideEast_Text_ExchangeCornerSign
	.global BattleFrontier_OutsideEast_Text_BattleTowerFeelsSpecial
	.global BattleFrontier_OutsideEast_Text_ConquerLeagueAndFrontier
	.global BattleFrontier_OutsideEast_Text_PyramidTooHarsh
	.global BattleFrontier_OutsideEast_Text_ThriveInDarkness
	.global BattleFrontier_OutsideEast_Text_PutTogetherUltimateTeam
	.global BattleFrontier_OutsideEast_Text_DidScottBringYouHere
	.global BattleFrontier_OutsideEast_Text_BelieveInYouBuddy
	.global BattleFrontier_OutsideEast_Text_ZigzagoonLooksVacant
	.global BattleFrontier_OutsideEast_Text_PeopleCallMeBusybody
	.global BattleFrontier_OutsideEast_Text_OnceBeatGymLeader
	.global BattleFrontier_OutsideEast_Text_FastOnBikeAndBattles
	.global BattleFrontier_OutsideEast_Text_BetterThanDaddyAtPokemon
	.global BattleFrontier_OutsideEast_Text_GoRackUpSomeWinsForDaddy
	.global BattleFrontier_OutsideEast_Text_HeardPrettyGirlAtBattleArena
	.global BattleFrontier_OutsideEast_Text_SometimesImportantOldManInThere
	.global BattleFrontier_OutsideEast_Text_LegendOfBattlePyramid
	.global BattleFrontier_OutsideEast_Text_GotWipedOut
	.global BattleFrontier_OutsideEast_Text_ToughTrainerInBattleTower
	.global BattleFrontier_OutsideEast_Text_EnoughBattlePointsForDoll
	.global BattleFrontier_OutsideEast_Text_LikeToHaveNameRecordedHere
	.global BattleFrontier_OutsideEast_Text_CanDoAnythingWithYou
	.global BattleFrontier_OutsideEast_Text_PowerOfOurLoveWillOvercome
	.global BattleFrontier_OutsideEast_Text_FrontierNotExclusivelyForToughTrainers
	.global BattleFrontier_OutsideEast_Text_OddTreeHereSeemsToWiggle
	.global BattleFrontier_OutsideEast_Text_OnceAnOddTreePastHere
	.global BattleFrontier_OutsideEast_Text_StickyMonWithLongTail
@ END GENERATED LOCALIZATION EXPORTS
