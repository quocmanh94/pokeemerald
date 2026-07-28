LilycoveCity_LilycoveMuseum_1F_MapScripts::
	.byte 0

LilycoveCity_LilycoveMuseum_1F_EventScript_Greeter::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_WelcomeToLilycoveMuseum, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_Curator::
	lockall
	applymovement LOCALID_MUSEUM_1F_CURATOR, Common_Movement_FacePlayer
	message LilycoveCity_LilycoveMuseum_1F_Text_ImCuratorHaveYouViewedOurPaintings
	waitmessage
	multichoice 20, 8, MULTI_VIEWED_PAINTINGS, TRUE
	goto_if_eq VAR_RESULT, 0, LilycoveCity_LilycoveMuseum_1F_EventScript_SawPaintings
	goto_if_eq VAR_RESULT, 1, LilycoveCity_LilycoveMuseum_1F_EventScript_NotYet
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_NotYet::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_NotDisturbYouTakeYourTime, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_SawPaintings::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_HaveYouAnInterestInPaintings, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LilycoveCity_LilycoveMuseum_1F_EventScript_NotInterested
	goto_if_eq VAR_RESULT, YES, LilycoveCity_LilycoveMuseum_1F_EventScript_InterestedInPaintings
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_NotInterested::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_HonoredYoudVisitInSpiteOfThat, MSGBOX_SIGN
	releaseall
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_InterestedInPaintings::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_ExcellentCanYouComeWithMe, MSGBOX_SIGN
	applymovement LOCALID_MUSEUM_1F_CURATOR, LilycoveCity_LilycoveMuseum_1F_Movement_CuratorEnterStairs
	waitmovement 0
	removeobject LOCALID_MUSEUM_1F_CURATOR
	switch VAR_FACING
	case DIR_NORTH, LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorNorth
	case DIR_WEST, LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorWest
	case DIR_EAST, LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorEast
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorNorth::
	lockall
	applymovement LOCALID_PLAYER, LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorNorth
	waitmovement 0
	warp MAP_LILYCOVE_CITY_LILYCOVE_MUSEUM_2F, 11, 8
	waitstate
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorWest::
	lockall
	applymovement LOCALID_PLAYER, LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorWest
	waitmovement 0
	warp MAP_LILYCOVE_CITY_LILYCOVE_MUSEUM_2F, 11, 8
	waitstate
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorEast::
	lockall
	applymovement LOCALID_PLAYER, LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorEast
	waitmovement 0
	warp MAP_LILYCOVE_CITY_LILYCOVE_MUSEUM_2F, 11, 8
	waitstate
	end

LilycoveCity_LilycoveMuseum_1F_Movement_CuratorEnterStairs:
	walk_up
	step_end

LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorWest:
	walk_left
	walk_up
	step_end

LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorEast:
	walk_right
	walk_up
	step_end

LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorNorth:
	walk_up
	walk_up
	step_end

LilycoveCity_LilycoveMuseum_1F_EventScript_OldPainting::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_VeryOldPainting, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_FantasyPainting::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_OddLandscapeFantasticScenery, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_WomanPainting::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfBeautifulWoman, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_LegendaryPokemonPainting::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfLegendaryPokemon, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_GrassPokemonPainting::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfGrassPokemon, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_BerryPainting::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfBerries, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_EventScript_BirdSculpture::
	msgbox LilycoveCity_LilycoveMuseum_Text_BirdPokemonSculptureReplica, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_PokeBallSculpture::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_BigPokeBallCarvedFromStone, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_StoneTablet::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_StoneTabletWithAncientText, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_SchoolKidM::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_MustntForgetLoveForFineArts, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_Artist1::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_ThisMuseumIsInspiration, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_NinjaBoy::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_ThisLadyIsPretty, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_Woman1::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_ThisPokemonIsAdorable, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_Woman2::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_HeardMuseumGotNewPaintings, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_PsychicM::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_CuratorHasBeenCheerful, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_Artist2::
	lock
	faceplayer
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_AimToSeeGreatPaintings, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MUSEUM_1F_ARTIST_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_FatMan::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_MuseumTouristDestination, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_Text_WelcomeToLilycoveMuseum:
	.string "Chào mừng đến với LILYCOVE MUSEUM.\p"
	.string "Xin hãy thong thả thưởng lãm bộ sưu\n"
	.string "tập tác phẩm nghệ thuật tuyệt vời về\l"
	.string "POKéMON của chúng tôi.$"

LilycoveCity_LilycoveMuseum_1F_Text_ImCuratorHaveYouViewedOurPaintings:
	.string "Tôi là CURATOR của MUSEUM mỹ thuật này.\p"
	.string "Thật đáng mừng khi thấy một người trẻ\n"
	.string "như bạn đến MUSEUM của chúng tôi.\p"
	.string "Bạn đã xem bộ sưu tập tranh của chúng\n"
	.string "tôi chưa?$"

LilycoveCity_LilycoveMuseum_1F_Text_NotDisturbYouTakeYourTime:
	.string "À, vậy tôi xin không làm phiền. Xin cứ\n"
	.string "thong thả thưởng lãm.$"

LilycoveCity_LilycoveMuseum_1F_Text_HaveYouAnInterestInPaintings:
	.string "Ồ? Tôi tin rằng bạn là một POKéMON\n"
	.string "HLV.\p"
	.string "Bạn cũng hứng thú với hội họa sao?$"

LilycoveCity_LilycoveMuseum_1F_Text_HonoredYoudVisitInSpiteOfThat:
	.string "Tôi hiểu...\p"
	.string "Dù vậy, bạn vẫn ghé thăm chúng tôi, thật\n"
	.string "là một vinh hạnh.$"

LilycoveCity_LilycoveMuseum_1F_Text_ExcellentCanYouComeWithMe:
	.string "À, tuyệt vời! Bạn quả thật thích tranh!\p"
	.string "Vậy, tôi có thể mời bạn đi cùng tôi\n"
	.string "không?$"

LilycoveCity_LilycoveMuseum_1F_Text_VeryOldPainting:
	.string "Đây là một bức tranh rất cổ. Màu sơn\n"
	.string "bong tróc chỗ này chỗ kia.$"

LilycoveCity_LilycoveMuseum_1F_Text_OddLandscapeFantasticScenery:
	.string "Đây là một bức phong cảnh kỳ lạ với\n"
	.string "cảnh vật quái dị và huyền ảo.$"

LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfBeautifulWoman:
	.string "Đây là tranh một người phụ nữ xinh đẹp\n"
	.string "đang mỉm cười, với một POKéMON ngồi\l"
	.string "trên đùi.$"

LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfLegendaryPokemon:
	.string "Đây là tranh một POKéMON huyền thoại\n"
	.string "từ thời xa xưa.\p"
	.string "Họa sĩ đã vẽ nó từ trí tưởng tượng.$"

LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfGrassPokemon:
	.string "Đây là tranh những GRASS POKéMON đung\n"
	.string "đưa trong làn gió.\p"
	.string "Trông chúng như đang tận hưởng sự\n"
	.string "vuốt ve dịu dàng của gió.$"

LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfBerries:
	.string "Đây là một bức tranh BERRIES trông\n"
	.string "ngon tuyệt.\p"
	.string "Bức tranh này có thể khiến bạn thấy\n"
	.string "đói!$"

LilycoveCity_LilycoveMuseum_Text_BirdPokemonSculptureReplica:
	.string "Đây là bản sao của một tác phẩm điêu\n"
	.string "khắc nổi tiếng.\p"
	.string "Nó khắc họa một BIRD POKéMON cổ đại.$"

LilycoveCity_LilycoveMuseum_1F_Text_BigPokeBallCarvedFromStone:
	.string "Đây là một POKé BALL lớn được tạc từ\n"
	.string "đá đen.\p"
	.string "Có vẻ nó từng được dùng trong các lễ\n"
	.string "hội thời xưa.$"

LilycoveCity_LilycoveMuseum_1F_Text_StoneTabletWithAncientText:
	.string "Đây là một phiến đá khổng lồ, khắc hình\n"
	.string "POKéMON cùng những dòng chữ dày đặc\l"
	.string "bằng các ký tự nhỏ của một ngôn ngữ cổ\l"
	.string "không thể đọc được.$"

LilycoveCity_LilycoveMuseum_1F_Text_WorksOfMagnificence:
	.string "Hừm... Quả là những tác phẩm vô cùng\n"
	.string "tráng lệ...$"

LilycoveCity_LilycoveMuseum_1F_Text_MustntForgetLoveForFineArts:
	.string "Tôi công nhận chiến đấu cùng POKéMON\n"
	.string "rất vui.\p"
	.string "Nhưng ta không được quên tình yêu\n"
	.string "dành cho mỹ thuật.$"

LilycoveCity_LilycoveMuseum_1F_Text_ThisMuseumIsInspiration:
	.string "ART MUSEUM này... Ừm, ở đây có thể chiêm\n"
	.string "ngưỡng nhiều bức tranh tuyệt vời.\p"
	.string "Và CURATOR là một người tuyệt vời.\p"
	.string "Với những nghệ sĩ như tôi, MUSEUM này\n"
	.string "là nguồn cảm hứng.$"

LilycoveCity_LilycoveMuseum_1F_Text_ThisLadyIsPretty:
	.string "Cô này xinh quá! Giống mẹ mình vậy!$"

LilycoveCity_LilycoveMuseum_1F_Text_ThisPokemonIsAdorable:
	.string "POKéMON này đáng yêu quá! Giống hệt\n"
	.string "cậu con trai bé bỏng của chúng tôi!$"

LilycoveCity_LilycoveMuseum_1F_Text_HeardMuseumGotNewPaintings:
	.string "Tôi nghe nói ART MUSEUM này vừa có vài\n"
	.string "bức tranh mới.\p"
	.string "Thế là tôi vội tới ngay.\p"
	.string "Những bức tranh mới được trưng bày ở\n"
	.string "tầng hai phải không?$"

LilycoveCity_LilycoveMuseum_1F_Text_CuratorHasBeenCheerful:
	.string "Gần đây, CURATOR vui vẻ khác thường.\p"
	.string "Tôi cá là ông ấy gặp chuyện gì đó tốt\n"
	.string "lành. Chắc chắn luôn.$"

LilycoveCity_LilycoveMuseum_1F_Text_AimToSeeGreatPaintings:
	.string "Tôi muốn xem thật nhiều tranh tuyệt vời\n"
	.string "ở đây và học hỏi từ chúng.\p"
	.string "Tôi mơ một ngày nào đó tác phẩm của\n"
	.string "mình sẽ được trưng bày tại đây.$"

LilycoveCity_LilycoveMuseum_1F_Text_MuseumTouristDestination:
	.string "ART MUSEUM đã trở thành điểm đến yêu\n"
	.string "thích của du khách.\p"
	.string "Thật tuyệt cho LILYCOVE... Không, cho\n"
	.string "cả vùng HOENN!\p"
	.string "Tôi nghe nói toàn bộ tranh trên tầng\n"
	.string "đều do một HLV duy nhất sưu tầm\l"
	.string "được.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global LilycoveCity_LilycoveMuseum_1F_Text_WelcomeToLilycoveMuseum
	.global LilycoveCity_LilycoveMuseum_1F_Text_ImCuratorHaveYouViewedOurPaintings
	.global LilycoveCity_LilycoveMuseum_1F_Text_NotDisturbYouTakeYourTime
	.global LilycoveCity_LilycoveMuseum_1F_Text_HaveYouAnInterestInPaintings
	.global LilycoveCity_LilycoveMuseum_1F_Text_HonoredYoudVisitInSpiteOfThat
	.global LilycoveCity_LilycoveMuseum_1F_Text_ExcellentCanYouComeWithMe
	.global LilycoveCity_LilycoveMuseum_1F_Text_VeryOldPainting
	.global LilycoveCity_LilycoveMuseum_1F_Text_OddLandscapeFantasticScenery
	.global LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfBeautifulWoman
	.global LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfLegendaryPokemon
	.global LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfGrassPokemon
	.global LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfBerries
	.global LilycoveCity_LilycoveMuseum_Text_BirdPokemonSculptureReplica
	.global LilycoveCity_LilycoveMuseum_1F_Text_BigPokeBallCarvedFromStone
	.global LilycoveCity_LilycoveMuseum_1F_Text_StoneTabletWithAncientText
	.global LilycoveCity_LilycoveMuseum_1F_Text_WorksOfMagnificence
	.global LilycoveCity_LilycoveMuseum_1F_Text_MustntForgetLoveForFineArts
	.global LilycoveCity_LilycoveMuseum_1F_Text_ThisMuseumIsInspiration
	.global LilycoveCity_LilycoveMuseum_1F_Text_ThisLadyIsPretty
	.global LilycoveCity_LilycoveMuseum_1F_Text_ThisPokemonIsAdorable
	.global LilycoveCity_LilycoveMuseum_1F_Text_HeardMuseumGotNewPaintings
	.global LilycoveCity_LilycoveMuseum_1F_Text_CuratorHasBeenCheerful
	.global LilycoveCity_LilycoveMuseum_1F_Text_AimToSeeGreatPaintings
	.global LilycoveCity_LilycoveMuseum_1F_Text_MuseumTouristDestination
@ END GENERATED LOCALIZATION EXPORTS
