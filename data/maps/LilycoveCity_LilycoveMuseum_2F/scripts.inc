LilycoveCity_LilycoveMuseum_2F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, LilycoveCity_LilycoveMuseum_2F_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LilycoveCity_LilycoveMuseum_2F_OnFrame
	.byte 0

LilycoveCity_LilycoveMuseum_2F_OnLoad:
	goto_if_set FLAG_COOL_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_SetCoolPainting
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_CheckBeautyPainting
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_CheckBeautyPainting::
	goto_if_set FLAG_BEAUTY_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_SetBeautyPainting
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_CheckCutePainting
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_CheckCutePainting::
	goto_if_set FLAG_CUTE_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_SetCutePainting
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_CheckSmartPainting
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_CheckSmartPainting::
	goto_if_set FLAG_SMART_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_SetSmartPainting
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_CheckToughPainting
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_CheckToughPainting::
	goto_if_set FLAG_TOUGH_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_SetToughPainting
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_SetCoolPainting::
	setmetatile 10, 6, METATILE_LilycoveMuseum_Painting2_Left, TRUE
	setmetatile 11, 6, METATILE_LilycoveMuseum_Painting2_Right, TRUE
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_CheckBeautyPainting
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_SetBeautyPainting::
	setmetatile 18, 6, METATILE_LilycoveMuseum_Painting1_Left, TRUE
	setmetatile 19, 6, METATILE_LilycoveMuseum_Painting1_Right, TRUE
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_CheckCutePainting
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_SetCutePainting::
	setmetatile 14, 10, METATILE_LilycoveMuseum_Painting3_Left, TRUE
	setmetatile 15, 10, METATILE_LilycoveMuseum_Painting3_Right, TRUE
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_CheckSmartPainting
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_SetSmartPainting::
	setmetatile 6, 10, METATILE_LilycoveMuseum_Painting0_Left, TRUE
	setmetatile 7, 10, METATILE_LilycoveMuseum_Painting0_Right, TRUE
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_CheckToughPainting
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_SetToughPainting::
	setmetatile 2, 6, METATILE_LilycoveMuseum_Painting4_Left, TRUE
	setmetatile 3, 6, METATILE_LilycoveMuseum_Painting4_Right, TRUE
	end

LilycoveCity_LilycoveMuseum_2F_OnFrame:
	map_script_2 VAR_LILYCOVE_MUSEUM_2F_STATE, 0, LilycoveCity_LilycoveMuseum_2F_EventScript_ShowExhibitHall
	.2byte 0

LilycoveCity_LilycoveMuseum_2F_EventScript_ShowExhibitHall::
	lockall
	applymovement LOCALID_MUSEUM_2F_CURATOR, Common_Movement_FacePlayer
	applymovement LOCALID_PLAYER, LilycoveCity_LilycoveMuseum_2F_Movement_PlayerWalkInPlaceLeft
	waitmovement 0
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ThisIsExhibitHall, MSGBOX_SIGN
	applymovement LOCALID_MUSEUM_2F_CURATOR, LilycoveCity_LilycoveMuseum_2F_Movement_FaceExhibitHall
	waitmovement 0
	applymovement LOCALID_PLAYER, LilycoveCity_LilycoveMuseum_2F_Movement_FaceExhibitHall
	waitmovement 0
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ExplainExhibitHall, MSGBOX_SIGN
	applymovement LOCALID_MUSEUM_2F_CURATOR, Common_Movement_FacePlayer
	waitmovement 0
	applymovement LOCALID_PLAYER, LilycoveCity_LilycoveMuseum_2F_Movement_PlayerWalkInPlaceLeft
	waitmovement 0
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_PleaseObtainPaintingsForExhibit, MSGBOX_SIGN
#ifdef UBFIX
	setvar VAR_LILYCOVE_MUSEUM_2F_STATE, 1
#else
	copyvar VAR_LILYCOVE_MUSEUM_2F_STATE, 1, warn=FALSE
#endif
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_Movement_PlayerWalkInPlaceLeft:
	walk_in_place_faster_left
	step_end

LilycoveCity_LilycoveMuseum_2F_Movement_FaceExhibitHall:
	face_up
	delay_16
	step_end

LilycoveCity_LilycoveMuseum_2F_EventScript_Curator::
	lockall
	goto_if_set FLAG_RECEIVED_GLASS_ORNAMENT, LilycoveCity_LilycoveMuseum_2F_EventScript_ReceivedGlassOrnament
	specialvar VAR_0x8004, CountPlayerMuseumPaintings
	switch VAR_0x8004
	case 1, LilycoveCity_LilycoveMuseum_2F_EventScript_AddedPainting
	case 2, LilycoveCity_LilycoveMuseum_2F_EventScript_AddedPainting
	case 3, LilycoveCity_LilycoveMuseum_2F_EventScript_AddedPainting
	case 4, LilycoveCity_LilycoveMuseum_2F_EventScript_AddedPainting
	case 5, LilycoveCity_LilycoveMuseum_2F_EventScript_ThankPlayer
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_WishToFillExhibit, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_AddedPainting::
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ThanksAddedNewPainting, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_ThankPlayer::
	applymovement LOCALID_MUSEUM_2F_CURATOR, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsYouPlayer, MSGBOX_DEFAULT
	applymovement LOCALID_MUSEUM_2F_CURATOR, LilycoveCity_LilycoveMuseum_2F_Movement_FaceExhibitHall
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_PaintingsAttractedMoreGuests, MSGBOX_DEFAULT
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_GiveGlassOrnament
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_GiveGlassOrnament::
	applymovement LOCALID_MUSEUM_2F_CURATOR, Common_Movement_FacePlayer
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_TokenOfGratitude, MSGBOX_DEFAULT
	givedecoration DECOR_GLASS_ORNAMENT
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_LilycoveMuseum_2F_EventScript_NoRoomForGlassOrnament
	setflag FLAG_RECEIVED_GLASS_ORNAMENT
	closemessage
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_NoRoomForGlassOrnament::
	call Common_EventScript_NoRoomForDecor
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_KeepThisForYou, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_ReceivedGlassOrnament::
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_HonorToHaveYouVisit, MSGBOX_NPC
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_CutePainting::
	lockall
	goto_if_set FLAG_CUTE_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_ShowCutePainting
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsPinkPictureFrame, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_ToughPainting::
	lockall
	goto_if_set FLAG_TOUGH_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_ShowToughPainting
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsYellowPictureFrame, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_CoolPainting::
	lockall
	goto_if_set FLAG_COOL_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_ShowCoolPainting
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsRedPictureFrame, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_BeautyPainting::
	lockall
	goto_if_set FLAG_BEAUTY_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_ShowBeautyPainting
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsBluePictureFrame, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_SmartPainting::
	lockall
	goto_if_set FLAG_SMART_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_ShowSmartPainting
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsGreenPictureFrame, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_Girl::
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_NewPaintingsSurprisedMe, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_ExpertM::
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_NewPaintingsRatherAmusing, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_RichBoy::
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ThesePaintingsOfYourPokemon, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_ShowCoolPainting::
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsPaintingOfPokemon, MSGBOX_SIGN
	fadescreen FADE_TO_BLACK
	showcontestpainting CONTEST_WINNER_MUSEUM_COOL
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_ShowBeautyPainting::
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsPaintingOfPokemon, MSGBOX_SIGN
	fadescreen FADE_TO_BLACK
	showcontestpainting CONTEST_WINNER_MUSEUM_BEAUTY
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_ShowCutePainting::
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsPaintingOfPokemon, MSGBOX_SIGN
	fadescreen FADE_TO_BLACK
	showcontestpainting CONTEST_WINNER_MUSEUM_CUTE
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_ShowSmartPainting::
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsPaintingOfPokemon, MSGBOX_SIGN
	fadescreen FADE_TO_BLACK
	showcontestpainting CONTEST_WINNER_MUSEUM_SMART
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_ShowToughPainting::
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsPaintingOfPokemon, MSGBOX_SIGN
	fadescreen FADE_TO_BLACK
	showcontestpainting CONTEST_WINNER_MUSEUM_TOUGH
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_Text_ThisIsExhibitHall:
	.string "Đây là phòng trưng bày đặc biệt của\n"
	.string "chúng tôi.$"

LilycoveCity_LilycoveMuseum_2F_Text_ExplainExhibitHall:
	.string "Như bạn thấy đấy, ở đây chưa trưng\n"
	.string "bày một bức tranh nào.\p"
	.string "Tôi không muốn trưng bày những tác\n"
	.string "phẩm được gọi là nghệ thuật cổ điển tại\l"
	.string "đây.\p"
	.string "Bạn có thể xem những tác phẩm cổ điển\n"
	.string "ấy ở tầng trệt.\p"
	.string "Tôi muốn trưng bày những tác phẩm hoàn\n"
	.string "toàn khác với trường phái cổ điển.\p"
	.string "Suy cho cùng, nghệ thuật đâu chỉ giới\n"
	.string "hạn trong những tác phẩm lâu đời, nổi\l"
	.string "tiếng!\p"
	.string "Tôi muốn lấp đầy phòng trưng bày này\n"
	.string "bằng...\p"
	.string "Những tác phẩm hiện đại, sống động về\n"
	.string "POKéMON, như thể chúng sắp tung mình\l"
	.string "bước ra và bừng lên sức sống rực rỡ!$"

LilycoveCity_LilycoveMuseum_2F_Text_PleaseObtainPaintingsForExhibit:
	.string "Xin thứ lỗi. Tôi không định độc chiếm\n"
	.string "cuộc trò chuyện đâu.\p"
	.string "Bạn còn trẻ, nhưng rõ ràng đã đi đây đi\n"
	.string "đó rất nhiều...\p"
	.string "Hẳn bạn sẽ gặp những POKéMON tràn đầy\n"
	.string "sức sống và các tác phẩm khắc họa\l"
	.string "chúng.\p"
	.string "Nếu bắt gặp một bức tranh như vậy, bạn\n"
	.string "có thể xin phép họa sĩ cho chúng tôi\l"
	.string "trưng bày nó tại đây được không?$"

LilycoveCity_LilycoveMuseum_2F_Text_WishToFillExhibit:
	.string "Tôi muốn lấp đầy phòng trưng bày này\n"
	.string "bằng những bức tranh hiện đại, sống\l"
	.string "động về POKéMON.$"

LilycoveCity_LilycoveMuseum_2F_Text_ThanksAddedNewPainting:
	.string "Nhờ có bạn, bộ sưu tập của chúng tôi đã\n"
	.string "có thêm một bức tranh mới!\p"
	.string "Tôi nghe nói bức tranh khắc họa\n"
	.string "POKéMON của bạn. Thật sự tuyệt mỹ!\p"
	.string "Cảm ơn bạn vô cùng, vô cùng nhiều!$"

LilycoveCity_LilycoveMuseum_2F_Text_ItsYouPlayer:
	.string "A! Là bạn! {PLAYER}!$"

LilycoveCity_LilycoveMuseum_2F_Text_PaintingsAttractedMoreGuests:
	.string "Tuyệt vời quá phải không? Bộ sưu tập\n"
	.string "tranh này ấy!\p"
	.string "Bức nào cũng hoàn mỹ! Không bức nào\n"
	.string "hơn bức nào!\p"
	.string "Những bức tranh này đã thu hút thêm\n"
	.string "nhiều khách đến ART MUSEUM.\p"
	.string "Tôi chân thành cảm ơn bạn, {PLAYER}.\n"
	.string "Giấc mơ của tôi đã thành hiện thực!$"

LilycoveCity_LilycoveMuseum_2F_Text_TokenOfGratitude:
	.string "Đây chỉ là chút quà để bày tỏ lòng biết\n"
	.string "ơn của tôi.$"

LilycoveCity_LilycoveMuseum_2F_Text_KeepThisForYou:
	.string "Tôi sẽ giữ món này cho bạn đến khi\n"
	.string "chúng ta gặp lại.$"

LilycoveCity_LilycoveMuseum_2F_Text_HonorToHaveYouVisit:
	.string "A, thật vui khi được gặp lại bạn,\n"
	.string "{PLAYER}!\p"
	.string "Thật vinh dự khi bạn ghé thăm chúng tôi\n"
	.string "giữa những chuyến hành trình bận rộn.\p"
	.string "Xin cứ thư giãn và tận hưởng thời gian\n"
	.string "ở đây.$"

LilycoveCity_LilycoveMuseum_2F_Text_ItsPinkPictureFrame:
	.string "Đây là một khung tranh được trang trí\n"
	.string "bằng những họa tiết màu hồng.$"

LilycoveCity_LilycoveMuseum_2F_Text_ItsYellowPictureFrame:
	.string "Đây là một khung tranh được trang trí\n"
	.string "bằng những họa tiết màu vàng.$"

LilycoveCity_LilycoveMuseum_2F_Text_ItsBluePictureFrame:
	.string "Đây là một khung tranh được trang trí\n"
	.string "bằng những họa tiết màu xanh lam.$"

LilycoveCity_LilycoveMuseum_2F_Text_ItsRedPictureFrame:
	.string "Đây là một khung tranh được trang trí\n"
	.string "bằng những họa tiết màu đỏ.$"

LilycoveCity_LilycoveMuseum_2F_Text_ItsGreenPictureFrame:
	.string "Đây là một khung tranh được trang trí\n"
	.string "bằng những họa tiết màu xanh lục.$"

LilycoveCity_LilycoveMuseum_2F_Text_ItsPaintingOfPokemon:
	.string "Đây là một bức tranh về POKéMON.$"

LilycoveCity_LilycoveMuseum_2F_Text_NewPaintingsSurprisedMe:
	.string "Tôi đã vắng mặt một thời gian, nên\n"
	.string "những bức tranh mới trên này làm tôi\l"
	.string "bất ngờ.\p"
	.string "Ước gì có người vẽ POKéMON của tôi\n"
	.string "đẹp đến thế này.$"

LilycoveCity_LilycoveMuseum_2F_Text_NewPaintingsRatherAmusing:
	.string "Chà... Vậy đây là nơi họ trưng bày\n"
	.string "những bức tranh POKéMON mang hơi thở\l"
	.string "thời đại.\p"
	.string "Hiểu rồi, những bức tranh mới này quả\n"
	.string "thật khá thú vị.$"

LilycoveCity_LilycoveMuseum_2F_Text_ThesePaintingsOfYourPokemon:
	.string "Chà, thật vậy sao? Những bức tranh này\n"
	.string "vẽ POKéMON của bạn à.\p"
	.string "Với một HLV, còn niềm vui nào lớn\n"
	.string "hơn thế nữa?$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global LilycoveCity_LilycoveMuseum_2F_Text_ThisIsExhibitHall
	.global LilycoveCity_LilycoveMuseum_2F_Text_ExplainExhibitHall
	.global LilycoveCity_LilycoveMuseum_2F_Text_PleaseObtainPaintingsForExhibit
	.global LilycoveCity_LilycoveMuseum_2F_Text_WishToFillExhibit
	.global LilycoveCity_LilycoveMuseum_2F_Text_ThanksAddedNewPainting
	.global LilycoveCity_LilycoveMuseum_2F_Text_ItsYouPlayer
	.global LilycoveCity_LilycoveMuseum_2F_Text_PaintingsAttractedMoreGuests
	.global LilycoveCity_LilycoveMuseum_2F_Text_TokenOfGratitude
	.global LilycoveCity_LilycoveMuseum_2F_Text_KeepThisForYou
	.global LilycoveCity_LilycoveMuseum_2F_Text_HonorToHaveYouVisit
	.global LilycoveCity_LilycoveMuseum_2F_Text_ItsPinkPictureFrame
	.global LilycoveCity_LilycoveMuseum_2F_Text_ItsYellowPictureFrame
	.global LilycoveCity_LilycoveMuseum_2F_Text_ItsBluePictureFrame
	.global LilycoveCity_LilycoveMuseum_2F_Text_ItsRedPictureFrame
	.global LilycoveCity_LilycoveMuseum_2F_Text_ItsGreenPictureFrame
	.global LilycoveCity_LilycoveMuseum_2F_Text_ItsPaintingOfPokemon
	.global LilycoveCity_LilycoveMuseum_2F_Text_NewPaintingsSurprisedMe
	.global LilycoveCity_LilycoveMuseum_2F_Text_NewPaintingsRatherAmusing
	.global LilycoveCity_LilycoveMuseum_2F_Text_ThesePaintingsOfYourPokemon
@ END GENERATED LOCALIZATION EXPORTS
