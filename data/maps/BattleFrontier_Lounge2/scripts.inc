BattleFrontier_Lounge2_MapScripts::
	.byte 0

@ This NPC gives hints about a random facility or battle mode.
@ For battle modes he gives generic advice
@ For facilities, depending on how far the player has progressed he will say either
@    The name of the Frontier Brain there
@    The type and description of the 3 pokemon they use in their silver battle
@    The type and description of the 3 pokemon they use in their gold battle
BattleFrontier_Lounge2_EventScript_FrontierManiac::
	lock
	faceplayer
	goto_if_set FLAG_MET_BATTLE_FRONTIER_MANIAC, BattleFrontier_Lounge2_EventScript_AlreadyMetManiac
	setflag FLAG_MET_BATTLE_FRONTIER_MANIAC
	msgbox BattleFrontier_Lounge2_Text_FrontierManiacIntro, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge2_EventScript_GiveAdvice
	end

BattleFrontier_Lounge2_EventScript_AlreadyMetManiac::
	msgbox BattleFrontier_Lounge2_Text_SwingByForTheLatestWord, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge2_EventScript_GiveAdvice
	end

BattleFrontier_Lounge2_EventScript_GiveAdvice::
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_SINGLES, BattleFrontier_Lounge2_EventScript_BufferSingle
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_DOUBLES, BattleFrontier_Lounge2_EventScript_BufferDouble
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_MULTIS, BattleFrontier_Lounge2_EventScript_BufferMulti
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_LINK, BattleFrontier_Lounge2_EventScript_BufferMultiLink
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_DOME, BattleFrontier_Lounge2_EventScript_BufferBattleDome
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_FACTORY, BattleFrontier_Lounge2_EventScript_BufferBattleFactory
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_PALACE, BattleFrontier_Lounge2_EventScript_BufferBattlePalace
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_ARENA, BattleFrontier_Lounge2_EventScript_BufferBattleArena
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_PIKE, BattleFrontier_Lounge2_EventScript_BufferBattlePike
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_PYRAMID, BattleFrontier_Lounge2_EventScript_BufferBattlePyramid
@ <= FRONTIER_MANIAC_TOWER_LINK is any Battle Tower mode
	call_if_le VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_LINK, BattleFrontier_Lounge2_EventScript_BattleTowerNews
@ >= FRONTIER_MANIAC_DOME is any facility other than Battle Tower
	call_if_ge VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_DOME, BattleFrontier_Lounge2_EventScript_FacilityNews
	special ShowFrontierManiacMessage
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge2_EventScript_BattleTowerNews::
	msgbox BattleFrontier_Lounge2_Text_BattleTowerIsHottest, MSGBOX_DEFAULT
	return

BattleFrontier_Lounge2_EventScript_FacilityNews::
	msgbox BattleFrontier_Lounge2_Text_FacilityIsHottest, MSGBOX_DEFAULT
	return

BattleFrontier_Lounge2_EventScript_BufferSingle::
	bufferstdstring STR_VAR_1, STDSTRING_SINGLE
	return

BattleFrontier_Lounge2_EventScript_BufferDouble::
	bufferstdstring STR_VAR_1, STDSTRING_DOUBLE
	return

BattleFrontier_Lounge2_EventScript_BufferMulti::
	bufferstdstring STR_VAR_1, STDSTRING_MULTI
	return

BattleFrontier_Lounge2_EventScript_BufferMultiLink::
	bufferstdstring STR_VAR_1, STDSTRING_MULTI_LINK
	return

BattleFrontier_Lounge2_EventScript_BufferBattleDome::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_DOME
	return

BattleFrontier_Lounge2_EventScript_BufferBattleFactory::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_FACTORY
	return

BattleFrontier_Lounge2_EventScript_BufferBattlePalace::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_PALACE
	return

BattleFrontier_Lounge2_EventScript_BufferBattleArena::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_ARENA
	return

BattleFrontier_Lounge2_EventScript_BufferBattlePike::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_PIKE
	return

BattleFrontier_Lounge2_EventScript_BufferBattlePyramid::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_PYRAMID
	return

BattleFrontier_Lounge2_EventScript_Maniac1::
	lock
	msgbox BattleFrontier_Lounge2_Text_NewsGatheringPower, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_Maniac2::
	lock
	msgbox BattleFrontier_Lounge2_Text_AmazingPowersOfObservation, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_Maniac3::
	lock
	msgbox BattleFrontier_Lounge2_Text_AmazingPowerOfPersuasion, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_TriathleteF::
	msgbox BattleFrontier_Lounge2_Text_ThisPlaceIsScaringMe, MSGBOX_NPC
	end

BattleFrontier_Lounge2_Text_FrontierManiacIntro::
	.string "Chào nhé! Về tin tức BATTLE FRONTIER\n"
	.string "thì tôi là số 1.\p"
	.string "Cứ xem tôi là FRONTIER MANIAC.\p"
	.string "Chỉ hỏi lại cho chắc, bạn là một HLV,\n"
	.string "đúng không?\p"
	.string "Tôi rất sẵn lòng chia sẻ những tin nóng\n"
	.string "nhất mình thu thập được về BATTLE\l"
	.string "FRONTIER.$"

BattleFrontier_Lounge2_Text_SwingByForTheLatestWord::
	.string "Chào nhé! Bạn ghé qua để tra hỏi tôi về\n"
	.string "tin mới nhất à? Ôi, được thôi!$"

@ Unused
BattleFrontier_Lounge2_Text_MyInformationsBeenUsefulRight::
	.string "Thế nào? Thế nào? Thế nào?\p"
	.string "Thông tin của tôi hẳn đã giúp ích rất\n"
	.string "nhiều cho bạn, đúng không?$"

BattleFrontier_Lounge2_Text_FacilityIsHottest::
	.string "Để xem nào...\p"
	.string "Có vẻ {STR_VAR_1} đang là nơi\n"
	.string "được chú ý nhất.$"

BattleFrontier_Lounge2_Text_BattleTowerIsHottest::
	.string "Để xem nào...\p"
	.string "Có vẻ BATTLE TOWER {STR_VAR_1}\n"
	.string "đang được chú ý nhất.$"

BattleFrontier_Lounge2_Text_SalonMaidenIsThere::
	.string "Có điều này chắc bạn chưa biết!\p"
	.string "Một trong những HLV hàng đầu mà\n"
	.string "SCOTT gọi là FRONTIER BRAINS đang ở\l"
	.string "đó.\p"
	.string "Một HLV bí ẩn mang danh SALON\n"
	.string "MAIDEN đang quản lý nơi ấy.$"

BattleFrontier_Lounge2_Text_SalonMaidenSilverMons::
	.string "Bạn đã đấu với SALON MAIDEN chưa?\p"
	.string "Khi thăm dò thực lực đối thủ, nghe nói\n"
	.string "cô ấy dùng những POKéMON này:\p"
	.string "Một PSI POKéMON hệ PSYCHIC, một\n"
	.string "VOLCANO POKéMON hệ FIRE và một\l"
	.string "SLEEPING POKéMON hệ NORMAL.$"

BattleFrontier_Lounge2_Text_SalonMaidenGoldMons::
	.string "Bạn đã đấu với SALON MAIDEN khi cô ấy\n"
	.string "nghiêm túc chưa?\p"
	.string "Khi chiến đấu hết sức, nghe nói cô ấy\n"
	.string "dùng những POKéMON này:\p"
	.string "Một EON POKéMON hệ DRAGON & PSYCHIC,\n"
	.string "một THUNDER POKéMON hệ ELECTRIC và\l"
	.string "một SLEEPING POKéMON hệ NORMAL.$"

BattleFrontier_Lounge2_Text_DomeAceIsThere::
	.string "Có điều này chắc bạn chưa biết!\p"
	.string "Một trong những HLV hàng đầu mà\n"
	.string "SCOTT gọi là FRONTIER BRAINS đang ở\l"
	.string "đó.\p"
	.string "Một HLV hào hoa mang danh DOME ACE\n"
	.string "đang quản lý nơi ấy.$"

BattleFrontier_Lounge2_Text_DomeAceSilverMons::
	.string "Bạn đã đấu với DOME ACE chưa?\p"
	.string "Khi chưa coi đối thủ là mối đe dọa, anh\n"
	.string "ấy dùng ba POKéMON này:\p"
	.string "Một DRAGON POKéMON hệ DRAGON & FLYING,\n"
	.string "một MUD FISH POKéMON hệ WATER & GROUND\l"
	.string "và một FLAME POKéMON hệ FIRE & FLYING.$"

BattleFrontier_Lounge2_Text_DomeAceGoldMons::
	.string "Bạn đã đấu với DOME ACE khi anh ấy\n"
	.string "nghiêm túc chưa?\p"
	.string "Khi phô diễn chiến thuật, anh ấy dùng ba\n"
	.string "POKéMON này:\p"
	.string "Một EON POKéMON hệ DRAGON & FLYING,\n"
	.string "một MUD FISH POKéMON hệ WATER & GROUND\l"
	.string "và một IRON LEG POKéMON hệ STEEL &\l"
	.string "PSYCHIC.$"

BattleFrontier_Lounge2_Text_FactoryHeadIsThere::
	.string "Có điều này chắc bạn chưa biết!\p"
	.string "Một trong những HLV hàng đầu mà\n"
	.string "SCOTT gọi là FRONTIER BRAINS đang ở\l"
	.string "đó.\p"
	.string "Một HLV quái dị mang danh FACTORY\n"
	.string "HEAD đang quản lý nơi ấy.$"

BattleFrontier_Lounge2_Text_FactoryHeadSilverMons::
	.string "Bạn đã đấu với FACTORY HEAD chưa?\p"
	.string "Để tôi nghĩ xem... Khi ra trận, anh ấy chỉ\n"
	.string "nhận ba POKéMON thuê.\p"
	.string "Anh ấy chiến đấu trong điều kiện gần\n"
	.string "như giống hệt bạn.$"

BattleFrontier_Lounge2_Text_FactoryHeadGoldMons::
	.string "Bạn đã đấu với FACTORY HEAD khi anh ấy\n"
	.string "nghiêm túc chưa?\p"
	.string "Ngay cả khi nghiêm túc ra trận, anh ấy\n"
	.string "vẫn nhận ba POKéMON thuê.\p"
	.string "Anh ấy chiến đấu trong điều kiện hầu\n"
	.string "như giống hệt bạn.$"

BattleFrontier_Lounge2_Text_PikeQueenIsThere::
	.string "Có điều này chắc bạn chưa biết!\p"
	.string "Một trong những HLV hàng đầu mà\n"
	.string "SCOTT gọi là FRONTIER BRAINS đang ở\l"
	.string "đó.\p"
	.string "Một HLV đáng sợ mang danh PIKE\n"
	.string "QUEEN đang quản lý nơi ấy.$"

BattleFrontier_Lounge2_Text_PikeQueenSilverMons::
	.string "Bạn từng đấu với PIKE QUEEN chưa?\p"
	.string "Khi tâm trạng tốt, nghe nói cô ấy dùng\n"
	.string "ba POKéMON này:\p"
	.string "Một FANG SNAKE POKéMON hệ POISON, một\n"
	.string "MOLD POKéMON hệ BUG & ROCK và một\l"
	.string "TENDER POKéMON hệ WATER.$"

BattleFrontier_Lounge2_Text_PikeQueenGoldMons::
	.string "Bạn đã đấu với PIKE QUEEN khi cô ấy\n"
	.string "nghiêm túc chưa?\p"
	.string "Khi thực sự nổi giận, nghe nói cô ấy\n"
	.string "dùng ba POKéMON này:\p"
	.string "Một FANG SNAKE POKéMON hệ POISON, một\n"
	.string "IRON SNAKE POKéMON hệ STEEL & GROUND\l"
	.string "và một ATROCIOUS POKéMON hệ WATER &\l"
	.string "FLYING.$"

BattleFrontier_Lounge2_Text_ArenaTycoonIsThere::
	.string "Có điều này chắc bạn chưa biết!\p"
	.string "Một trong những HLV hàng đầu mà\n"
	.string "SCOTT gọi là FRONTIER BRAINS đang ở\l"
	.string "đó.\p"
	.string "Một HLV đáng yêu mang danh ARENA\n"
	.string "TYCOON đang quản lý nơi ấy.$"

BattleFrontier_Lounge2_Text_ArenaTycoonSilverMons::
	.string "Bạn từng đấu với ARENA TYCOON chưa?\p"
	.string "Khi đánh giá năng lực đối thủ, nghe nói\n"
	.string "cô ấy dùng những POKéMON này:\p"
	.string "Một SINGLE HORN POKéMON hệ BUG &\n"
	.string "FIGHTING, một MOONLIGHT POKéMON hệ\l"
	.string "DARK và một SHED POKéMON hệ BUG &\l"
	.string "GHOST.$"

BattleFrontier_Lounge2_Text_ArenaTycoonGoldMons::
	.string "Bạn đã đấu với ARENA TYCOON khi cô ấy\n"
	.string "nghiêm túc chưa?\p"
	.string "Khi quyết chiến, nghe nói cô ấy dùng\n"
	.string "những POKéMON này:\p"
	.string "Một MOONLIGHT POKéMON hệ DARK, một\n"
	.string "SHADOW POKéMON hệ GHOST & POISON và\l"
	.string "một MUSHROOM POKéMON hệ GRASS &\l"
	.string "FIGHTING.$"

BattleFrontier_Lounge2_Text_PalaceMavenIsThere::
	.string "Có điều này chắc bạn chưa biết!\p"
	.string "Một trong những HLV hàng đầu mà\n"
	.string "SCOTT gọi là FRONTIER BRAINS đang ở\l"
	.string "đó.\p"
	.string "Một HLV nham hiểm mang danh PALACE\n"
	.string "MAVEN đang quản lý nơi ấy.$"

BattleFrontier_Lounge2_Text_PalaceMavenSilverMons::
	.string "Bạn từng đấu với PALACE MAVEN chưa?\p"
	.string "Khi thử thách tinh thần đối thủ, nghe\n"
	.string "nói ông ấy dùng những POKéMON này:\p"
	.string "Một BAT POKéMON hệ POISON & FLYING,\n"
	.string "một LAZY POKéMON hệ NORMAL và một\l"
	.string "TRANSPORT POKéMON hệ WATER & ICE.$"

BattleFrontier_Lounge2_Text_PalaceMavenGoldMons::
	.string "Bạn đã đấu với PALACE MAVEN khi ông ấy\n"
	.string "nghiêm túc chưa?\p"
	.string "Khi dốc toàn bộ sức mạnh vào trận đấu,\n"
	.string "nghe nói ông ấy dùng những POKéMON\l"
	.string "này:\p"
	.string "Một LEGENDARY POKéMON hệ FIRE, một\n"
	.string "LAZY POKéMON hệ NORMAL và một AURORA\l"
	.string "POKéMON hệ WATER.$"

BattleFrontier_Lounge2_Text_PyramidKingIsThere::
	.string "Có điều này chắc bạn chưa biết!\p"
	.string "Một trong những HLV hàng đầu mà\n"
	.string "SCOTT gọi là FRONTIER BRAINS đang ở\l"
	.string "đó.\p"
	.string "Một HLV bừng bừng khí thế mang\n"
	.string "danh PYRAMID KING đang quản lý nơi ấy.$"

BattleFrontier_Lounge2_Text_PyramidKingSilverMons::
	.string "Bạn từng đấu với PYRAMID KING chưa?\p"
	.string "Khi kiểm tra sức mạnh đối thủ, nghe nói\n"
	.string "ông ấy dùng những POKéMON này:\p"
	.string "Một ROCK PEAK POKéMON hệ ROCK, một\n"
	.string "ICEBERG POKéMON hệ ICE và một IRON\l"
	.string "POKéMON hệ STEEL.$"

BattleFrontier_Lounge2_Text_PyramidKingGoldMons::
	.string "Bạn đã đấu với PYRAMID KING khi ông ấy\n"
	.string "nghiêm túc chưa?\p"
	.string "Khi sức mạnh nóng bỏng dâng trào, nghe\n"
	.string "nói ông ấy dùng những POKéMON này:\p"
	.string "Một FREEZE POKéMON hệ ICE & FLYING,\n"
	.string "một ELECTRIC POKéMON hệ ELECTRIC &\l"
	.string "FLYING và một FLAME POKéMON hệ FIRE &\l"
	.string "FLYING.$"

BattleFrontier_Lounge2_Text_DoubleBattleAdvice1::
	.string "Đúng là có vài nơi bạn có thể tham gia\n"
	.string "DOUBLE BATTLES.\p"
	.string "Nhưng DOUBLE BATTLE ROOMS của BATTLE\n"
	.string "TOWER mới là nơi cơ bản nhất!\p"
	.string "Đó là nơi bạn nên học cách chơi DOUBLE\n"
	.string "BATTLES tại BATTLE FRONTIER.$"

BattleFrontier_Lounge2_Text_DoubleBattleAdvice2::
	.string "Hãy cẩn thận trong những trận đấu ở\n"
	.string "đây.\p"
	.string "Tôi nghe nói có những HLV đã phát\n"
	.string "triển chiến thuật dành riêng cho DOUBLE\l"
	.string "BATTLES.$"

BattleFrontier_Lounge2_Text_DoubleBattleAdvice3::
	.string "Khi đã tự tin và quen thuộc với DOUBLE\n"
	.string "BATTLES ở đây, bạn nên nghĩ đến việc\l"
	.string "thách đấu những nơi khác cũng tổ chức\l"
	.string "DOUBLE BATTLES.$"

BattleFrontier_Lounge2_Text_MultiBattleAdvice::
	.string "Đủ loại HLV tụ họp tại BATTLE\n"
	.string "SALON.\p"
	.string "Cứ nghĩ mà xem, bạn có thể gặp bạn bè\n"
	.string "hoặc những người hâm mộ mình! Hãy\l"
	.string "quan sát thật kỹ!$"

BattleFrontier_Lounge2_Text_LinkMultiBattleAdvice::
	.string "Nếu đi cùng một người bạn, hãy đến\n"
	.string "LINK MULTI BATTLE ROOM.\p"
	.string "Nếu chơi cùng một người bạn mạnh, bạn\n"
	.string "có thể sẽ gặp những đối thủ đáng gờm!$"

BattleFrontier_Lounge2_Text_NewsGatheringPower::
	.string "Khả năng thu thập tin tức thật đáng\n"
	.string "kinh ngạc! Sư phụ tôi đúng là độc nhất\l"
	.string "vô nhị!$"

BattleFrontier_Lounge2_Text_AmazingPowersOfObservation::
	.string "Khả năng quan sát thật đáng kinh ngạc!\n"
	.string "Sư phụ tôi đúng là độc nhất vô nhị!$"

BattleFrontier_Lounge2_Text_AmazingPowerOfPersuasion::
	.string "Khả năng thuyết phục thật đáng kinh\n"
	.string "ngạc! Sư phụ tôi đúng là độc nhất vô\l"
	.string "nhị!$"

BattleFrontier_Lounge2_Text_ThisPlaceIsScaringMe::
	.string "...Đây là nơi nào vậy? Nó làm mình sợ\n"
	.string "quá...$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global BattleFrontier_Lounge2_Text_FrontierManiacIntro
	.global BattleFrontier_Lounge2_Text_SwingByForTheLatestWord
	.global BattleFrontier_Lounge2_Text_MyInformationsBeenUsefulRight
	.global BattleFrontier_Lounge2_Text_FacilityIsHottest
	.global BattleFrontier_Lounge2_Text_BattleTowerIsHottest
	.global BattleFrontier_Lounge2_Text_SalonMaidenIsThere
	.global BattleFrontier_Lounge2_Text_SalonMaidenSilverMons
	.global BattleFrontier_Lounge2_Text_SalonMaidenGoldMons
	.global BattleFrontier_Lounge2_Text_DomeAceIsThere
	.global BattleFrontier_Lounge2_Text_DomeAceSilverMons
	.global BattleFrontier_Lounge2_Text_DomeAceGoldMons
	.global BattleFrontier_Lounge2_Text_FactoryHeadIsThere
	.global BattleFrontier_Lounge2_Text_FactoryHeadSilverMons
	.global BattleFrontier_Lounge2_Text_FactoryHeadGoldMons
	.global BattleFrontier_Lounge2_Text_PikeQueenIsThere
	.global BattleFrontier_Lounge2_Text_PikeQueenSilverMons
	.global BattleFrontier_Lounge2_Text_PikeQueenGoldMons
	.global BattleFrontier_Lounge2_Text_ArenaTycoonIsThere
	.global BattleFrontier_Lounge2_Text_ArenaTycoonSilverMons
	.global BattleFrontier_Lounge2_Text_ArenaTycoonGoldMons
	.global BattleFrontier_Lounge2_Text_PalaceMavenIsThere
	.global BattleFrontier_Lounge2_Text_PalaceMavenSilverMons
	.global BattleFrontier_Lounge2_Text_PalaceMavenGoldMons
	.global BattleFrontier_Lounge2_Text_PyramidKingIsThere
	.global BattleFrontier_Lounge2_Text_PyramidKingSilverMons
	.global BattleFrontier_Lounge2_Text_PyramidKingGoldMons
	.global BattleFrontier_Lounge2_Text_DoubleBattleAdvice1
	.global BattleFrontier_Lounge2_Text_DoubleBattleAdvice2
	.global BattleFrontier_Lounge2_Text_DoubleBattleAdvice3
	.global BattleFrontier_Lounge2_Text_MultiBattleAdvice
	.global BattleFrontier_Lounge2_Text_LinkMultiBattleAdvice
	.global BattleFrontier_Lounge2_Text_NewsGatheringPower
	.global BattleFrontier_Lounge2_Text_AmazingPowersOfObservation
	.global BattleFrontier_Lounge2_Text_AmazingPowerOfPersuasion
	.global BattleFrontier_Lounge2_Text_ThisPlaceIsScaringMe
@ END GENERATED LOCALIZATION EXPORTS
