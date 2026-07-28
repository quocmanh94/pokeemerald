MauvilleCity_PokemonCenter_1F_EventScript_MauvilleOldMan::
	special Script_GetCurrentMauvilleMan
	switch VAR_RESULT
	case MAUVILLE_MAN_BARD, MauvilleCity_PokemonCenter_1F_EventScript_Bard
	case MAUVILLE_MAN_HIPSTER, MauvilleCity_PokemonCenter_1F_EventScript_Hipster
	case MAUVILLE_MAN_TRADER, MauvilleCity_PokemonCenter_1F_EventScript_Trader
	case MAUVILLE_MAN_STORYTELLER, MauvilleCity_PokemonCenter_1F_EventScript_Storyteller
	case MAUVILLE_MAN_GIDDY, MauvilleCity_PokemonCenter_1F_EventScript_Giddy
	end

@ Bard
MauvilleCity_PokemonCenter_1F_EventScript_Bard::
	lock
	faceplayer
	msgbox MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToHearMySong, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_PlaySong
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineSong
	end

MauvilleCity_PokemonCenter_1F_EventScript_PlaySong::
	setvar VAR_0x8004, FALSE  @ Play his current song
	special PlayBardSong
	delay 60
	special HasBardSongBeenChanged
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_AskToWriteLyrics
	msgbox MauvilleCity_PokemonCenter_1F_Text_WishICouldPlaySongForOthers, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineSong::
	msgbox MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues1, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_AskToWriteLyrics::
	msgbox MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToWriteSomeLyrics, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_WriteLyrics
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineWritingLyrics
	end

MauvilleCity_PokemonCenter_1F_EventScript_WriteLyrics::
	setvar VAR_0x8004, EASY_CHAT_TYPE_BARD_SONG
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto_if_eq VAR_RESULT, 0, MauvilleCity_PokemonCenter_1F_EventScript_DeclineWritingLyrics
	msgbox MauvilleCity_PokemonCenter_1F_Text_LetMeSingItForYou, MSGBOX_DEFAULT
	setvar VAR_0x8004, TRUE  @ Play the new song
	special PlayBardSong
	delay 60
	msgbox MauvilleCity_PokemonCenter_1F_Text_ThatHowYouWantedSongToGo, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_WriteLyrics
	special SaveBardSongLyrics
	msgbox MauvilleCity_PokemonCenter_1F_Text_IllSingThisSongForAWhile, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineWritingLyrics::
	msgbox MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues2, MSGBOX_DEFAULT
	release
	end

@ Hipster
MauvilleCity_PokemonCenter_1F_EventScript_Hipster::
	lock
	faceplayer
	setflag FLAG_UNLOCKED_TRENDY_SAYINGS
	msgbox MauvilleCity_PokemonCenter_1F_Text_TeachWhatsHipAndHappening, MSGBOX_DEFAULT
	special HasHipsterTaughtWord
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_TryTeachWord
	msgbox MauvilleCity_PokemonCenter_1F_Text_IAlreadyTaughtYou, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_TryTeachWord::
	special HipsterTryTeachWord
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_TeachWord
	msgbox MauvilleCity_PokemonCenter_1F_Text_IveGotNothingNewToTeach, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_TeachWord::
	msgbox MauvilleCity_PokemonCenter_1F_Text_HaveYouHeardOfWord, MSGBOX_DEFAULT
	special SetHipsterTaughtWord
	release
	end

@ Trader
MauvilleCity_PokemonCenter_1F_Text_WantToTradeDecor:
	.string "Chào, tôi là TRADER. Bạn muốn đổi đồ\n"
	.string "trang trí với tôi không?$"

MauvilleCity_PokemonCenter_1F_Text_TraderFeelingTheBlues:
	.string "Ôi... Bạn làm tôi buồn quá...$"

MauvilleCity_PokemonCenter_1F_Text_WeveAlreadyTraded:
	.string "Nhưng bạn và tôi đã đổi đồ trang trí\n"
	.string "rồi mà.$"

MauvilleCity_PokemonCenter_1F_Text_PickADecorItem:
	.string "Nếu thấy món đồ trang trí nào của tôi\n"
	.string "mà bạn muốn, cứ nói nhé.$"

MauvilleCity_PokemonCenter_1F_Text_YouDontWantAnything:
	.string "Bạn không muốn món nào sao? Tôi thấy\n"
	.string "mình bị hắt hủi quá...$"

MauvilleCity_PokemonCenter_1F_Text_OnceBelongedToPlayerDoYouWantIt:
	.string "Món đồ trang trí đó từng thuộc về\n"
	.string "{STR_VAR_1}.\p"
	.string "Bạn có muốn lấy nó không?$"

MauvilleCity_PokemonCenter_1F_Text_YouDontHaveAnyDecor:
	.string "Ơ... Khoan đã. Bạn không có lấy một món\n"
	.string "đồ trang trí nào!$"

MauvilleCity_PokemonCenter_1F_Text_PickTheDecorToTrade:
	.string "Được rồi, hãy chọn món đồ trang trí bạn\n"
	.string "sẽ đổi cho tôi.$"

MauvilleCity_PokemonCenter_1F_Text_YouDontWantToTrade:
	.string "Bạn không đổi với tôi sao? Tôi thấy\n"
	.string "mình bị hắt hủi quá...$"

MauvilleCity_PokemonCenter_1F_Text_YouveNoRoomForThis:
	.string "Bạn đã cất đủ số lượng\n"
	.string "{STR_VAR_2}S tối đa rồi. Không\l"
	.string "còn chỗ cho món này nữa.$"

MauvilleCity_PokemonCenter_1F_Text_SoWellTradeTheseDecor:
	.string "Được, vậy ta sẽ đổi {STR_VAR_3}\n"
	.string "của tôi lấy {STR_VAR_2} của bạn\l"
	.string "nhé?$"

MauvilleCity_PokemonCenter_1F_Text_ThatDecorIsInUse:
	.string "Món đồ trang trí đó đang được sử\n"
	.string "dụng. Bạn không thể đem đổi.$"

MauvilleCity_PokemonCenter_1F_Text_SendDecorToYourPC:
	.string "Vậy thì đổi nhé! Tôi sẽ gửi món đồ trang\n"
	.string "trí của mình vào PC của bạn.$"

MauvilleCity_PokemonCenter_1F_Text_CantTradeThatOne:
	.string "Ối! Xin lỗi nhé! Đó là một món đồ trang\n"
	.string "trí cực kỳ hiếm. Tôi không thể đem nó đi\l"
	.string "đổi được!\p"
	.string "Bạn có muốn chọn món khác không?$"

MauvilleCity_PokemonCenter_1F_EventScript_Trader::
	lock
	faceplayer
	msgbox MauvilleCity_PokemonCenter_1F_Text_WantToTradeDecor, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineTrade
	special GetTraderTradedFlag
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_AlreadyTraded
	message MauvilleCity_PokemonCenter_1F_Text_PickADecorItem
	waitmessage
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineTrade::
	msgbox MauvilleCity_PokemonCenter_1F_Text_TraderFeelingTheBlues, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_AlreadyTraded::
	msgbox MauvilleCity_PokemonCenter_1F_Text_WeveAlreadyTraded, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive::
	special TraderMenuGetDecoration
	goto_if_eq VAR_0x8004, 0, MauvilleCity_PokemonCenter_1F_EventScript_CancelPickDecor
	goto_if_eq VAR_0x8004, 0xFFFF, MauvilleCity_PokemonCenter_1F_EventScript_InvalidDecor
	msgbox MauvilleCity_PokemonCenter_1F_Text_OnceBelongedToPlayerDoYouWantIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_PickDifferentDecor
	special DoesPlayerHaveNoDecorations
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_DontHaveAnyDecor
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive
	end

MauvilleCity_PokemonCenter_1F_EventScript_CancelPickDecor::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDontWantAnything, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_InvalidDecor::
	message MauvilleCity_PokemonCenter_1F_Text_CantTradeThatOne
	waitmessage
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive
	end

MauvilleCity_PokemonCenter_1F_EventScript_PickDifferentDecor::
	message MauvilleCity_PokemonCenter_1F_Text_PickADecorItem
	waitmessage
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive
	end

MauvilleCity_PokemonCenter_1F_EventScript_DontHaveAnyDecor::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDontHaveAnyDecor, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive::
	msgbox MauvilleCity_PokemonCenter_1F_Text_PickTheDecorToTrade, MSGBOX_DEFAULT
	special TraderShowDecorationMenu
	goto_if_eq VAR_0x8006, 0, MauvilleCity_PokemonCenter_1F_EventScript_CancelGiveDecor
	goto_if_eq VAR_0x8006, 0xFFFF, MauvilleCity_PokemonCenter_1F_EventScript_DecorInUse
	special IsDecorationCategoryFull
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_NoRoomForDecor
	msgbox MauvilleCity_PokemonCenter_1F_Text_SoWellTradeTheseDecor, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive
	special TraderDoDecorationTrade
	msgbox MauvilleCity_PokemonCenter_1F_Text_SendDecorToYourPC, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_CancelGiveDecor::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDontWantToTrade, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DecorInUse::
	msgbox MauvilleCity_PokemonCenter_1F_Text_ThatDecorIsInUse, MSGBOX_DEFAULT
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive
	end

MauvilleCity_PokemonCenter_1F_EventScript_NoRoomForDecor::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouveNoRoomForThis, MSGBOX_DEFAULT
	release
	end

@ Storyteller
MauvilleCity_PokemonCenter_1F_Text_WillYouHearMyTale:
	.string "Tôi là STORYTELLER. Tôi sẽ kể bạn nghe\n"
	.string "những câu chuyện về các HLV\l"
	.string "huyền thoại.\p"
	.string "Bạn có muốn nghe chuyện của tôi không?$"

MauvilleCity_PokemonCenter_1F_Text_StorytellerFeelingTheBlues:
	.string "Ôi... Bạn làm tôi buồn quá...$"

MauvilleCity_PokemonCenter_1F_Text_WhichTaleToTell:
	.string "Tôi biết những huyền thoại này. Bạn\n"
	.string "muốn tôi kể câu chuyện nào?$"

MauvilleCity_PokemonCenter_1F_Text_IKnowNoTales:
	.string "Nhưng tôi chẳng biết HLV huyền\n"
	.string "thoại nào cả. Vì vậy, tôi cũng chẳng có\l"
	.string "chuyện để kể.\p"
	.string "Biết tìm đâu ra một HLV xứng đáng\n"
	.string "được đưa vào huyền thoại đây?$"

MauvilleCity_PokemonCenter_1F_Text_YouDidStatXTimes:
	.string "Cái gì?! Bạn... Bạn đã...\p"
	.string "{STR_VAR_2} {STR_VAR_1}\n"
	.string "lần sao?!\p"
	.string "Quả thực quá phi thường! Một huyền\n"
	.string "thoại mới đã ra đời!$"

MauvilleCity_PokemonCenter_1F_Text_CouldThereBeOtherLegends:
	.string "Điều đó khiến tôi tự hỏi, liệu còn\n"
	.string "HLV nào có những kỳ tích ấn\l"
	.string "tượng hơn đang chờ được khám phá\l"
	.string "không?$"

MauvilleCity_PokemonCenter_1F_Text_HaveYouAnyLegendaryTales:
	.string "Bạn là một HLV sao?\p"
	.string "Vậy hãy nói tôi nghe, bạn có câu chuyện\n"
	.string "nào dù chỉ hơi xứng tầm huyền thoại\l"
	.string "không?$"

@ Unused
MauvilleCity_PokemonCenter_1F_Text_HearAnotherLegendaryTale:
	.string "Nhân tiện... Bạn có muốn nghe thêm một\n"
	.string "câu chuyện huyền thoại nữa không?$"

MauvilleCity_PokemonCenter_1F_Text_NotWorthyOfLegend:
	.string "Hừm... Tôi chưa hài lòng...\p"
	.string "Tôi mong bạn sẽ mang đến tin tức xứng\n"
	.string "đáng được gọi là huyền thoại.$"

MauvilleCity_PokemonCenter_1F_Text_IWishMorePeopleWereInterested:
	.string "Ước gì có thêm nhiều người muốn nghe\n"
	.string "những thiên sử thi của tôi về các\l"
	.string "HLV huyền thoại.$"

MauvilleCity_PokemonCenter_1F_Text_SavedGameTitle::
	.string "HLV mê lưu trò chơi$"

MauvilleCity_PokemonCenter_1F_Text_SavedGameAction::
	.string "Đã lưu trò chơi$"

MauvilleCity_PokemonCenter_1F_Text_SavedGameStory::
	.string "Đây là câu chuyện về một HLV tên là\n"
	.string "{STR_VAR_3}.\p"
	.string "HLV này đã lưu trò chơi\n"
	.string "{STR_VAR_1} lần!\p"
	.string "Không thể tìm đâu ra một HLV thận\n"
	.string "trọng hơn {STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_TrendsStartedTitle::
	.string "HLV dẫn đầu xu hướng$"

MauvilleCity_PokemonCenter_1F_Text_TrendsStartedAction::
	.string "Đã khởi xướng xu hướng$"

MauvilleCity_PokemonCenter_1F_Text_TrendsStartedStory::
	.string "Đây là câu chuyện về một HLV tên là\n"
	.string "{STR_VAR_3}.\p"
	.string "HLV này đã khởi xướng xu hướng\n"
	.string "mới {STR_VAR_1} lần!\p"
	.string "{STR_VAR_3} đang tạo nên xu\n"
	.string "hướng cho cả vùng HOENN!$"

MauvilleCity_PokemonCenter_1F_Text_BerriesPlantedTitle::
	.string "HLV trồng BERRY$"

MauvilleCity_PokemonCenter_1F_Text_BerriesPlantedAction::
	.string "Đã trồng BERRIES$"

MauvilleCity_PokemonCenter_1F_Text_BerriesPlantedStory::
	.string "Đây là câu chuyện về một HLV tên là\n"
	.string "{STR_VAR_3}.\p"
	.string "HLV này đã trồng BERRIES\n"
	.string "{STR_VAR_1} lần!\p"
	.string "{STR_VAR_3} là người yêu\n"
	.string "BERRIES đến mức trở thành huyền\l"
	.string "thoại!$"

MauvilleCity_PokemonCenter_1F_Text_BikeTradesTitle::
	.string "HLV mê BIKE$"

MauvilleCity_PokemonCenter_1F_Text_BikeTradesAction::
	.string "Đã đổi BIKES$"

MauvilleCity_PokemonCenter_1F_Text_BikeTradesStory::
	.string "Đây là câu chuyện về một HLV tên là\n"
	.string "{STR_VAR_3}.\p"
	.string "HLV này đã đổi BIKES\n"
	.string "{STR_VAR_1} lần!\p"
	.string "Hẳn {STR_VAR_3} phải yêu BIKES\n"
	.string "vô cùng say đắm!$"

MauvilleCity_PokemonCenter_1F_Text_InterviewsTitle::
	.string "HLV được phỏng vấn$"

MauvilleCity_PokemonCenter_1F_Text_InterviewsAction::
	.string "Đã được phỏng vấn$"

MauvilleCity_PokemonCenter_1F_Text_InterviewsStory::
	.string "Đây là câu chuyện về một HLV tên là\n"
	.string "{STR_VAR_3}.\p"
	.string "HLV này đã được phỏng vấn\n"
	.string "{STR_VAR_1} lần!\p"
	.string "Hẳn {STR_VAR_3} là một HLV\n"
	.string "đang thu hút rất nhiều sự chú ý!$"

MauvilleCity_PokemonCenter_1F_Text_TrainerBattlesTitle::
	.string "HLV mê giao đấu$"

MauvilleCity_PokemonCenter_1F_Text_TrainerBattlesAction::
	.string "Đã giao đấu$"

MauvilleCity_PokemonCenter_1F_Text_TrainerBattlesStory::
	.string "Đây là câu chuyện về một HLV tên là\n"
	.string "{STR_VAR_3}.\p"
	.string "HLV này đã giao đấu\n"
	.string "{STR_VAR_1} lần!\p"
	.string "Hẳn {STR_VAR_3} là một HLV\n"
	.string "không bao giờ từ chối cơ hội giao đấu!$"

MauvilleCity_PokemonCenter_1F_Text_PokemonCaughtTitle::
	.string "HLV chuyên bắt POKéMON$"

MauvilleCity_PokemonCenter_1F_Text_PokemonCaughtAction::
	.string "Đã bắt POKéMON$"

MauvilleCity_PokemonCenter_1F_Text_PokemonCaughtStory::
	.string "Đây là câu chuyện về một HLV tên là\n"
	.string "{STR_VAR_3}.\p"
	.string "HLV này đã bắt {STR_VAR_1}\n"
	.string "POKéMON!\p"
	.string "{STR_VAR_3} là huyền thoại trong\n"
	.string "việc bắt POKéMON hoang dã!$"

MauvilleCity_PokemonCenter_1F_Text_FishingPokemonCaughtTitle::
	.string "HLV câu cá$"

MauvilleCity_PokemonCenter_1F_Text_FishingPokemonCaughtAction::
	.string "Đã bắt POKéMON bằng ROD$"

MauvilleCity_PokemonCenter_1F_Text_FishingPokemonCaughtStory::
	.string "Đây là câu chuyện về một HLV tên là\n"
	.string "{STR_VAR_3}.\p"
	.string "HLV này đã bắt {STR_VAR_1}\n"
	.string "POKéMON trong lúc câu cá!\p"
	.string "{STR_VAR_3} là một chuyên gia\n"
	.string "câu cá huyền thoại!$"

MauvilleCity_PokemonCenter_1F_Text_EggsHatchedTitle::
	.string "HLV ấp EGG$"

MauvilleCity_PokemonCenter_1F_Text_EggsHatchedAction::
	.string "Đã làm EGGS nở$"

MauvilleCity_PokemonCenter_1F_Text_EggsHatchedStory::
	.string "Đây là câu chuyện về một HLV tên là\n"
	.string "{STR_VAR_3}.\p"
	.string "HLV này đã làm nở\n"
	.string "{STR_VAR_1} POKéMON từ EGGS!\p"
	.string "{STR_VAR_3} là bậc thầy huyền\n"
	.string "thoại trong việc ấp EGGS!$"

MauvilleCity_PokemonCenter_1F_Text_PokemonEvolvedTitle::
	.string "HLV chuyên tiến hóa$"

MauvilleCity_PokemonCenter_1F_Text_PokemonEvolvedAction::
	.string "Đã tiến hóa POKéMON$"

MauvilleCity_PokemonCenter_1F_Text_PokemonEvolvedStory::
	.string "Đây là câu chuyện về một HLV tên là\n"
	.string "{STR_VAR_3}.\p"
	.string "HLV này đã giúp {STR_VAR_1}\n"
	.string "POKéMON tiến hóa!\p"
	.string "{STR_VAR_3} là bậc thầy tối\n"
	.string "thượng về tiến hóa POKéMON!$"

MauvilleCity_PokemonCenter_1F_Text_UsedPokemonCenterTitle::
	.string "HLV mê POKéMON CENTER$"

MauvilleCity_PokemonCenter_1F_Text_UsedPokemonCenterAction::
	.string "Đã dùng POKéMON CENTERS$"

MauvilleCity_PokemonCenter_1F_Text_UsedPokemonCenterStory::
	.string "Đây là câu chuyện về một HLV tên là\n"
	.string "{STR_VAR_3}.\p"
	.string "HLV này đã chữa trị cho POKéMON\n"
	.string "{STR_VAR_1} lần tại POKéMON\l"
	.string "CENTERS!\p"
	.string "Không ai có thể yêu POKéMON CENTERS\n"
	.string "hơn {STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_RestedAtHomeTitle::
	.string "HLV thích ở nhà$"

MauvilleCity_PokemonCenter_1F_Text_RestedAtHomeAction::
	.string "Đã cho POKéMON nghỉ ở nhà$"

MauvilleCity_PokemonCenter_1F_Text_RestedAtHomeStory::
	.string "Đây là câu chuyện về một HLV tên là\n"
	.string "{STR_VAR_3}.\p"
	.string "HLV này đã chữa trị cho POKéMON\n"
	.string "{STR_VAR_1} lần tại nhà!\p"
	.string "Không ai thích quanh quẩn ở nhà hơn\n"
	.string "{STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_SafariGamesTitle::
	.string "HLV mê SAFARI$"

MauvilleCity_PokemonCenter_1F_Text_SafariGamesAction::
	.string "Đã vào SAFARI ZONE$"

MauvilleCity_PokemonCenter_1F_Text_SafariGamesStory::
	.string "Đây là câu chuyện về một HLV tên là\n"
	.string "{STR_VAR_3}.\p"
	.string "HLV này đã vào SAFARI ZONE\n"
	.string "{STR_VAR_1} lần!\p"
	.string "Hẳn SAFARI ZONE là nơi bản năng hoang\n"
	.string "dã của HLV {STR_VAR_3} trỗi\l"
	.string "dậy!$"

MauvilleCity_PokemonCenter_1F_Text_UsedCutTitle::
	.string "HLV cuồng CUT$"

MauvilleCity_PokemonCenter_1F_Text_UsedCutAction::
	.string "Đã dùng CUT$"

MauvilleCity_PokemonCenter_1F_Text_UsedCutStory::
	.string "Đây là câu chuyện về một HLV tên là\n"
	.string "{STR_VAR_3}.\p"
	.string "HLV này đã dùng CUT\n"
	.string "{STR_VAR_1} lần!\p"
	.string "Hẳn HLV {STR_VAR_3} phải\n"
	.string "cực kỳ yêu thích CUT!$"

MauvilleCity_PokemonCenter_1F_Text_UsedRockSmashTitle::
	.string "HLV chuyên đập đá$"

MauvilleCity_PokemonCenter_1F_Text_UsedRockSmashAction::
	.string "Đã đập đá$"

MauvilleCity_PokemonCenter_1F_Text_UsedRockSmashStory::
	.string "Đây là câu chuyện về một HLV tên là\n"
	.string "{STR_VAR_3}.\p"
	.string "HLV này đã dùng ROCK SMASH\n"
	.string "{STR_VAR_1} lần!\p"
	.string "Hẳn HLV {STR_VAR_3} không\n"
	.string "thể bỏ qua bất kỳ hòn đá nào mà chưa\l"
	.string "đập vỡ!$"

MauvilleCity_PokemonCenter_1F_Text_MovedBasesTitle::
	.string "HLV mê chuyển nhà$"

MauvilleCity_PokemonCenter_1F_Text_MovedBasesAction::
	.string "Đã chuyển SECRET BASE$"

MauvilleCity_PokemonCenter_1F_Text_MovedBasesStory::
	.string "Đây là câu chuyện về một HLV tên là\n"
	.string "{STR_VAR_3}.\p"
	.string "HLV này đã chuyển SECRET BASE\n"
	.string "{STR_VAR_1} lần!\p"
	.string "{STR_VAR_3} là một HLV rất\n"
	.string "thích chuyển nhà thường xuyên!$"

MauvilleCity_PokemonCenter_1F_Text_UsedSplashTitle::
	.string "HLV mê SPLASH$"

MauvilleCity_PokemonCenter_1F_Text_UsedSplashAction::
	.string "Đã dùng SPLASH$"

MauvilleCity_PokemonCenter_1F_Text_UsedSplashStory::
	.string "Đây là câu chuyện về một HLV tên là\n"
	.string "{STR_VAR_3}.\p"
	.string "HLV này đã dùng SPLASH\n"
	.string "{STR_VAR_1} lần!\p"
	.string "Hẳn HLV {STR_VAR_3} phải rất\n"
	.string "thích vùng vẫy với SPLASH!$"

MauvilleCity_PokemonCenter_1F_Text_UsedStruggleTitle::
	.string "HLV kiên cường$"

MauvilleCity_PokemonCenter_1F_Text_UsedStruggleAction::
	.string "Đã phải dùng STRUGGLE$"

MauvilleCity_PokemonCenter_1F_Text_UsedStruggleStory::
	.string "Đây là câu chuyện về một HLV tên là\n"
	.string "{STR_VAR_3}.\p"
	.string "HLV này đã phải dựa vào STRUGGLE\n"
	.string "{STR_VAR_1} lần!\p"
	.string "{STR_VAR_3} là một HLV kiên\n"
	.string "cường, không bao giờ khuất phục trước\l"
	.string "nghịch cảnh!$"

MauvilleCity_PokemonCenter_1F_Text_SlotJackpotsTitle::
	.string "Nhà vô địch SLOT$"

MauvilleCity_PokemonCenter_1F_Text_SlotJackpotsAction::
	.string "Đã trúng độc đắc trên SLOTS$"

MauvilleCity_PokemonCenter_1F_Text_SlotJackpotsStory::
	.string "Đây là câu chuyện về một HLV tên là\n"
	.string "{STR_VAR_3}.\p"
	.string "HLV này đã trúng độc đắc trên\n"
	.string "SLOTS {STR_VAR_1} lần.\p"
	.string "{STR_VAR_3} là một HLV gặp\n"
	.string "nhiều may mắn trên SLOTS!$"

MauvilleCity_PokemonCenter_1F_Text_RouletteWinsTitle::
	.string "Nhà vô địch ROULETTE$"

MauvilleCity_PokemonCenter_1F_Text_RouletteWinsAction::
	.string "Có chuỗi thắng ROULETTE liên tiếp là$"

MauvilleCity_PokemonCenter_1F_Text_RouletteWinsStory::
	.string "Đây là câu chuyện về một HLV tên là\n"
	.string "{STR_VAR_3}.\p"
	.string "HLV này đã thắng ROULETTE\n"
	.string "{STR_VAR_1} lần liên tiếp.\p"
	.string "{STR_VAR_3} thật may mắn với\n"
	.string "những cú nảy của quả bóng ROULETTE!$"

MauvilleCity_PokemonCenter_1F_Text_BattleTowerChallengesTitle::
	.string "Người thách đấu BATTLE TOWER$"

MauvilleCity_PokemonCenter_1F_Text_BattleTowerChallengesAction::
	.string "Đã thử thách BATTLE TOWER$"

MauvilleCity_PokemonCenter_1F_Text_BattleTowerChallengesStory::
	.string "Đây là câu chuyện về một HLV tên là\n"
	.string "{STR_VAR_3}.\p"
	.string "HLV này đã thử thách BATTLE TOWER\n"
	.string "{STR_VAR_1} lần!\p"
	.string "{STR_VAR_3} là một HLV luôn\n"
	.string "khao khát vươn tới đỉnh cao tại\l"
	.string "BATTLE TOWER!$"

MauvilleCity_PokemonCenter_1F_Text_MadePokeblocksTitle::
	.string "HLV mê pha chế$"

MauvilleCity_PokemonCenter_1F_Text_MadePokeblocksAction::
	.string "Đã làm {POKEBLOCK}S$"

MauvilleCity_PokemonCenter_1F_Text_MadePokeblocksStory::
	.string "Đây là câu chuyện về một HLV tên là\n"
	.string "{STR_VAR_3}.\p"
	.string "HLV này đã làm {POKEBLOCK}S\n"
	.string "{STR_VAR_1} lần!\p"
	.string "Không ai sử dụng BERRY BLENDER giỏi\n"
	.string "hơn {STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_EnteredContestsTitle::
	.string "HLV mê cuộc thi$"

MauvilleCity_PokemonCenter_1F_Text_EnteredContestsAction::
	.string "Đã tham gia các cuộc thi$"

MauvilleCity_PokemonCenter_1F_Text_EnteredContestsStory::
	.string "Đây là câu chuyện về một HLV tên là\n"
	.string "{STR_VAR_3}.\p"
	.string "HLV này đã tham gia các cuộc thi\n"
	.string "{STR_VAR_1} lần!\p"
	.string "Hẳn {STR_VAR_3} rất thích khoe\n"
	.string "POKéMON với mọi người!$"

MauvilleCity_PokemonCenter_1F_Text_WonContestsTitle::
	.string "Bậc thầy cuộc thi$"

MauvilleCity_PokemonCenter_1F_Text_WonContestsAction::
	.string "Đã thắng các cuộc thi$"

MauvilleCity_PokemonCenter_1F_Text_WonContestsStory::
	.string "Đây là câu chuyện về một HLV tên\n"
	.string "{STR_VAR_3}.\p"
	.string "HLV này đã chiến thắng các cuộc thi\n"
	.string "{STR_VAR_1} lần!\p"
	.string "{STR_VAR_3} hẳn là một bậc thầy\n"
	.string "cuộc thi đáng kinh ngạc!$"

MauvilleCity_PokemonCenter_1F_Text_TimesShoppedTitle::
	.string "Tín đồ mua sắm vui vẻ$"

MauvilleCity_PokemonCenter_1F_Text_TimesShoppedAction::
	.string "Đã mua sắm$"

MauvilleCity_PokemonCenter_1F_Text_TimesShoppedStory::
	.string "Đây là câu chuyện về một HLV tên\n"
	.string "{STR_VAR_3}.\p"
	.string "HLV này đã mua hàng tại các cửa\n"
	.string "tiệm {STR_VAR_1} lần!\p"
	.string "{STR_VAR_3} hẳn là một trong\n"
	.string "những người sinh ra để mua sắm.$"

MauvilleCity_PokemonCenter_1F_Text_UsedItemFinderTitle::
	.string "HLV chuyên săn tìm vật phẩm$"

MauvilleCity_PokemonCenter_1F_Text_UsedItemFinderAction::
	.string "Đã dùng ITEMFINDER$"

MauvilleCity_PokemonCenter_1F_Text_UsedItemFinderStory::
	.string "Đây là câu chuyện về một HLV tên\n"
	.string "{STR_VAR_3}.\p"
	.string "HLV này đã dùng ITEMFINDER\n"
	.string "{STR_VAR_1} lần!\p"
	.string "{STR_VAR_3} hẳn rất thích lùng\n"
	.string "sục khắp mặt đất để tìm vật phẩm ẩn!$"

MauvilleCity_PokemonCenter_1F_Text_TimesRainedTitle::
	.string "HLV ướt sũng vì mưa$"

MauvilleCity_PokemonCenter_1F_Text_TimesRainedAction::
	.string "Đã bị mưa ướt$"

MauvilleCity_PokemonCenter_1F_Text_TimesRainedStory::
	.string "Đây là câu chuyện về một HLV tên\n"
	.string "{STR_VAR_3}.\p"
	.string "HLV này đã bị mưa làm ướt sũng\n"
	.string "{STR_VAR_1} lần!\p"
	.string "Sức hút của {STR_VAR_3} hẳn đến\n"
	.string "cả mưa cũng không cưỡng lại nổi!$"

MauvilleCity_PokemonCenter_1F_Text_CheckedPokedexTitle::
	.string "Người say mê đọc POKéDEX$"

MauvilleCity_PokemonCenter_1F_Text_CheckedPokedexAction::
	.string "Đã xem POKéDEX$"

MauvilleCity_PokemonCenter_1F_Text_CheckedPokedexStory::
	.string "Đây là câu chuyện về một HLV tên\n"
	.string "{STR_VAR_3}.\p"
	.string "HLV này đã xem POKéDEX\n"
	.string "{STR_VAR_1} lần!\p"
	.string "{STR_VAR_3} hẳn rất thích tra\n"
	.string "cứu POKéMON trong POKéDEX!$"

MauvilleCity_PokemonCenter_1F_Text_ReceivedRibbonsTitle::
	.string "Nhà sưu tập RIBBON$"

MauvilleCity_PokemonCenter_1F_Text_ReceivedRibbonsAction::
	.string "Đã nhận RIBBONS$"

MauvilleCity_PokemonCenter_1F_Text_ReceivedRibbonsStory::
	.string "Đây là câu chuyện về một HLV tên\n"
	.string "{STR_VAR_3}.\p"
	.string "HLV này đã nhận RIBBONS\n"
	.string "{STR_VAR_1} lần!\p"
	.string "{STR_VAR_3} hẳn là một HLV\n"
	.string "rất thích sưu tập RIBBONS!$"

MauvilleCity_PokemonCenter_1F_Text_LedgesJumpedTitle::
	.string "HLV mê nhảy xuống gờ$"

MauvilleCity_PokemonCenter_1F_Text_LedgesJumpedAction::
	.string "Đã nhảy xuống các gờ$"

MauvilleCity_PokemonCenter_1F_Text_LedgesJumpedStory::
	.string "Đây là câu chuyện về một HLV tên\n"
	.string "{STR_VAR_3}.\p"
	.string "HLV này đã nhảy xuống các gờ\n"
	.string "{STR_VAR_1} lần!\p"
	.string "Hễ thấy gờ nào có thể nhảy xuống là\n"
	.string "{STR_VAR_3} không thể bỏ qua!$"

MauvilleCity_PokemonCenter_1F_Text_TVWatchedTitle::
	.string "Huyền thoại xem TV$"

MauvilleCity_PokemonCenter_1F_Text_TVWatchedAction::
	.string "Đã xem TV$"

MauvilleCity_PokemonCenter_1F_Text_TVWatchedStory::
	.string "Đây là câu chuyện về một HLV tên\n"
	.string "{STR_VAR_3}.\p"
	.string "HLV này đã xem TV\n"
	.string "{STR_VAR_1} lần!\p"
	.string "{STR_VAR_3} hẳn rất thích xem\n"
	.string "TV!$"

MauvilleCity_PokemonCenter_1F_Text_CheckedClockTitle::
	.string "HLV luôn để ý thời gian$"

MauvilleCity_PokemonCenter_1F_Text_CheckedClockAction::
	.string "Đã xem giờ$"

MauvilleCity_PokemonCenter_1F_Text_CheckedClockStory::
	.string "Đây là câu chuyện về một HLV tên\n"
	.string "{STR_VAR_3}.\p"
	.string "HLV này đã xem giờ\n"
	.string "{STR_VAR_1} lần!\p"
	.string "{STR_VAR_3} hẳn là một HLV\n"
	.string "đúng giờ, luôn để ý thời gian.$"

MauvilleCity_PokemonCenter_1F_Text_WonLotteryTitle::
	.string "Phù thủy POKéMON LOTTERY$"

MauvilleCity_PokemonCenter_1F_Text_WonLotteryAction::
	.string "Đã trúng POKéMON LOTTERIES$"

MauvilleCity_PokemonCenter_1F_Text_WonLotteryStory::
	.string "Đây là câu chuyện về một HLV tên\n"
	.string "{STR_VAR_3}.\p"
	.string "HLV này đã trúng POKéMON\n"
	.string "LOTTERIES {STR_VAR_1} lần!\p"
	.string "{STR_VAR_3} hẳn có rất nhiều bạn\n"
	.string "để cùng trao đổi POKéMON!$"

MauvilleCity_PokemonCenter_1F_Text_UsedDaycareTitle::
	.string "HLV hay dùng DAY CARE$"

MauvilleCity_PokemonCenter_1F_Text_UsedDaycareAction::
	.string "Đã gửi POKéMON ở DAY CARE$"

MauvilleCity_PokemonCenter_1F_Text_UsedDaycareStory::
	.string "Đây là câu chuyện về một HLV tên\n"
	.string "{STR_VAR_3}.\p"
	.string "HLV này đã gửi POKéMON cho DAY\n"
	.string "CARE chăm sóc {STR_VAR_1} lần!\p"
	.string "{STR_VAR_3} hẳn là người đầy\n"
	.string "nhiệt huyết, luôn hăng hái huấn luyện\l"
	.string "POKéMON!$"

MauvilleCity_PokemonCenter_1F_Text_RodeCableCarTitle::
	.string "HLV mê CABLE CAR$"

MauvilleCity_PokemonCenter_1F_Text_RodeCableCarAction::
	.string "Đã đi CABLE CAR$"

MauvilleCity_PokemonCenter_1F_Text_RodeCableCarStory::
	.string "Đây là câu chuyện về một HLV tên\n"
	.string "{STR_VAR_3}.\p"
	.string "HLV này đã đi CABLE CAR\n"
	.string "{STR_VAR_1} lần!\p"
	.string "{STR_VAR_3} hẳn là một HLV\n"
	.string "bận rộn, cứ lên rồi lại xuống suốt ngày!$"

MauvilleCity_PokemonCenter_1F_Text_HotSpringsTitle::
	.string "HLV mê suối nước nóng$"

MauvilleCity_PokemonCenter_1F_Text_HotSpringsAction::
	.string "Đã tắm suối nước nóng$"

MauvilleCity_PokemonCenter_1F_Text_HotSpringsStory::
	.string "Đây là câu chuyện về một HLV tên\n"
	.string "{STR_VAR_3}.\p"
	.string "HLV này đã tắm suối nước nóng\n"
	.string "{STR_VAR_1} lần!\p"
	.string "{STR_VAR_3} hẳn là một HLV\n"
	.string "có làn da mềm mịn như em bé!$"


MauvilleCity_PokemonCenter_1F_EventScript_Storyteller::
	lock
	faceplayer
	setvar VAR_0x8008, 0
	setvar VAR_0x8009, 0
	setvar VAR_0x800A, 0
	setvar VAR_0x800B, 0
	msgbox MauvilleCity_PokemonCenter_1F_Text_WillYouHearMyTale, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller
	specialvar VAR_RESULT, StorytellerGetFreeStorySlot
	goto_if_eq VAR_RESULT, 0, MauvilleCity_PokemonCenter_1F_EventScript_KnowNoTales
	message MauvilleCity_PokemonCenter_1F_Text_WhichTaleToTell
	waitmessage
	special StorytellerStoryListMenu
	goto_if_eq VAR_RESULT, 0, MauvilleCity_PokemonCenter_1F_EventScript_CancelStorySelection
	setvar VAR_0x8008, 1
	special Script_StorytellerDisplayStory
	waitmessage
	waitbuttonpress
	specialvar VAR_RESULT, StorytellerUpdateStat
	goto_if_eq VAR_RESULT, 0, MauvilleCity_PokemonCenter_1F_EventScript_AreThereOtherTales
	goto MauvilleCity_PokemonCenter_1F_EventScript_TellPlayersTale

MauvilleCity_PokemonCenter_1F_EventScript_CancelStorySelection::
	goto MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller
	end

MauvilleCity_PokemonCenter_1F_EventScript_AreThereOtherTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_CouldThereBeOtherLegends, MSGBOX_DEFAULT
	specialvar VAR_RESULT, HasStorytellerAlreadyRecorded
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_StorytellerEnd
	goto MauvilleCity_PokemonCenter_1F_EventScript_DoYouHaveAnyTales

MauvilleCity_PokemonCenter_1F_EventScript_KnowNoTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_IKnowNoTales, MSGBOX_DEFAULT
MauvilleCity_PokemonCenter_1F_EventScript_DoYouHaveAnyTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_HaveYouAnyLegendaryTales, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller
	specialvar VAR_RESULT, Script_StorytellerInitializeRandomStat
	goto_if_eq VAR_RESULT, 1, MauvilleCity_PokemonCenter_1F_EventScript_TellPlayersTale
	msgbox MauvilleCity_PokemonCenter_1F_Text_NotWorthyOfLegend, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_TellPlayersTale::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDidStatXTimes, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller::
	msgbox MauvilleCity_PokemonCenter_1F_Text_StorytellerFeelingTheBlues, MSGBOX_DEFAULT
	release
	end

@ Unused
MauvilleCity_PokemonCenter_1F_EventScript_WaitingForRecordMix::
	msgbox MauvilleCity_PokemonCenter_1F_Text_IWishMorePeopleWereInterested, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_StorytellerEnd::
	release
	end

@ Giddy
MauvilleCity_PokemonCenter_1F_Text_HearMyStory:
	.string "Tôi là GIDDY! Tôi có một câu chuyện cực\n"
	.string "kỳ hấp dẫn dành cho bạn!\p"
	.string "Bạn có muốn nghe câu chuyện của tôi\n"
	.string "không?$"

MauvilleCity_PokemonCenter_1F_Text_GiddyFeelingTheBlues:
	.string "Ôi... Bạn làm tôi buồn quá...$"

MauvilleCity_PokemonCenter_1F_Text_AlsoIWasThinking:
	.string "Ngoài ra, tôi còn đang nghĩ...$"

MauvilleCity_PokemonCenter_1F_Text_WeShouldChatAgain:
	.string "Chắc chỉ có vậy thôi...\p"
	.string "Khi nào ta lại trò chuyện nhé! Tạm biệt!$"

MauvilleCity_PokemonCenter_1F_EventScript_Giddy::
	lock
	faceplayer
	msgbox MauvilleCity_PokemonCenter_1F_Text_HearMyStory, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_TryTellTale
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineGiddy
	end

MauvilleCity_PokemonCenter_1F_EventScript_TryTellTale::
	special GiddyShouldTellAnotherTale
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_GiddyTellTale
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_ToldEnoughTales
	end

MauvilleCity_PokemonCenter_1F_EventScript_TryTellNewTale::
	special GiddyShouldTellAnotherTale
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_GiddyStartNewTale
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_ToldEnoughTales
	end

MauvilleCity_PokemonCenter_1F_EventScript_GiddyStartNewTale::
	msgbox MauvilleCity_PokemonCenter_1F_Text_AlsoIWasThinking, MSGBOX_DEFAULT
	goto MauvilleCity_PokemonCenter_1F_EventScript_GiddyTellTale
	end

@ Giddy will continue to tell stories regardless of whether yes or no is selected below.
@ Each story there is a 10% chance it will be his last. Otherwise he will stop at 10 stories.
MauvilleCity_PokemonCenter_1F_EventScript_GiddyTellTale::
	special GenerateGiddyLine
	special ShowFieldMessageStringVar4
	waitmessage
	yesnobox 20, 8
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_TryTellNewTale
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_TryTellNewTale
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineGiddy::
	msgbox MauvilleCity_PokemonCenter_1F_Text_GiddyFeelingTheBlues, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_ToldEnoughTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_WeShouldChatAgain, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToHearMySong:
	.string "Chào bạn, tôi là BARD. Bạn có muốn nghe\n"
	.string "bài hát của tôi không?$"

MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues1:
	.string "Ôi... Bạn làm tôi buồn quá...$"

MauvilleCity_PokemonCenter_1F_Text_WishICouldPlaySongForOthers:
	.string "Ôi, một bài hát thật cảm động... Giá mà\n"
	.string "tôi có thể biểu diễn nó cho mọi người...$"

MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToWriteSomeLyrics:
	.string "Thế nào? Bạn thấy bài hát của tôi ra\n"
	.string "sao?\p"
	.string "Nhưng tôi vẫn chưa ưng phần lời lắm.\p"
	.string "Bạn có muốn viết lời mới giúp tôi không?$"

MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues2:
	.string "Ôi... Bạn làm tôi buồn quá...$"

MauvilleCity_PokemonCenter_1F_Text_LetMeSingItForYou:
	.string "Xin cảm ơn bạn! Để tôi hát cho bạn nghe.$"

MauvilleCity_PokemonCenter_1F_Text_ThatHowYouWantedSongToGo:
	.string "Bài hát như vậy có đúng ý bạn không?$"

MauvilleCity_PokemonCenter_1F_Text_IllSingThisSongForAWhile:
	.string "Được! Vậy quyết định thế nhé. Tôi sẽ\n"
	.string "hát bài này một thời gian.$"

MauvilleCity_PokemonCenter_1F_Text_TeachWhatsHipAndHappening:
	.string "Này, yo! Mọi người gọi tôi là HIPSTER.\n"
	.string "Tôi sẽ chỉ cho bạn những gì đang thịnh\l"
	.string "hành.$"

MauvilleCity_PokemonCenter_1F_Text_IAlreadyTaughtYou:
	.string "Nhưng này, tôi đã chỉ cho bạn những gì\n"
	.string "đang thịnh hành rồi.\p"
	.string "Tôi muốn truyền bá những điều hay ho\n"
	.string "đó cho người khác nữa.$"

MauvilleCity_PokemonCenter_1F_Text_IveGotNothingNewToTeach:
	.string "Nhưng này, bạn đã biết rất nhiều về\n"
	.string "những gì đang thịnh hành rồi.\p"
	.string "Tôi chẳng còn gì mới để dạy bạn nữa!$"

MauvilleCity_PokemonCenter_1F_Text_HaveYouHeardOfWord:
	.string "Này, bạn đã nghe nói đến\n"
	.string "{STR_VAR_1} chưa?\p"
	.string "Nó nghĩa là gì à? Ừm... Hỏi ba hoặc mẹ\n"
	.string "bạn nhé?$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global MauvilleCity_PokemonCenter_1F_Text_WantToTradeDecor
	.global MauvilleCity_PokemonCenter_1F_Text_TraderFeelingTheBlues
	.global MauvilleCity_PokemonCenter_1F_Text_WeveAlreadyTraded
	.global MauvilleCity_PokemonCenter_1F_Text_PickADecorItem
	.global MauvilleCity_PokemonCenter_1F_Text_YouDontWantAnything
	.global MauvilleCity_PokemonCenter_1F_Text_OnceBelongedToPlayerDoYouWantIt
	.global MauvilleCity_PokemonCenter_1F_Text_YouDontHaveAnyDecor
	.global MauvilleCity_PokemonCenter_1F_Text_PickTheDecorToTrade
	.global MauvilleCity_PokemonCenter_1F_Text_YouDontWantToTrade
	.global MauvilleCity_PokemonCenter_1F_Text_YouveNoRoomForThis
	.global MauvilleCity_PokemonCenter_1F_Text_SoWellTradeTheseDecor
	.global MauvilleCity_PokemonCenter_1F_Text_ThatDecorIsInUse
	.global MauvilleCity_PokemonCenter_1F_Text_SendDecorToYourPC
	.global MauvilleCity_PokemonCenter_1F_Text_CantTradeThatOne
	.global MauvilleCity_PokemonCenter_1F_Text_WillYouHearMyTale
	.global MauvilleCity_PokemonCenter_1F_Text_StorytellerFeelingTheBlues
	.global MauvilleCity_PokemonCenter_1F_Text_WhichTaleToTell
	.global MauvilleCity_PokemonCenter_1F_Text_IKnowNoTales
	.global MauvilleCity_PokemonCenter_1F_Text_YouDidStatXTimes
	.global MauvilleCity_PokemonCenter_1F_Text_CouldThereBeOtherLegends
	.global MauvilleCity_PokemonCenter_1F_Text_HaveYouAnyLegendaryTales
	.global MauvilleCity_PokemonCenter_1F_Text_HearAnotherLegendaryTale
	.global MauvilleCity_PokemonCenter_1F_Text_NotWorthyOfLegend
	.global MauvilleCity_PokemonCenter_1F_Text_IWishMorePeopleWereInterested
	.global MauvilleCity_PokemonCenter_1F_Text_SavedGameTitle
	.global MauvilleCity_PokemonCenter_1F_Text_SavedGameAction
	.global MauvilleCity_PokemonCenter_1F_Text_SavedGameStory
	.global MauvilleCity_PokemonCenter_1F_Text_TrendsStartedTitle
	.global MauvilleCity_PokemonCenter_1F_Text_TrendsStartedAction
	.global MauvilleCity_PokemonCenter_1F_Text_TrendsStartedStory
	.global MauvilleCity_PokemonCenter_1F_Text_BerriesPlantedTitle
	.global MauvilleCity_PokemonCenter_1F_Text_BerriesPlantedAction
	.global MauvilleCity_PokemonCenter_1F_Text_BerriesPlantedStory
	.global MauvilleCity_PokemonCenter_1F_Text_BikeTradesTitle
	.global MauvilleCity_PokemonCenter_1F_Text_BikeTradesAction
	.global MauvilleCity_PokemonCenter_1F_Text_BikeTradesStory
	.global MauvilleCity_PokemonCenter_1F_Text_InterviewsTitle
	.global MauvilleCity_PokemonCenter_1F_Text_InterviewsAction
	.global MauvilleCity_PokemonCenter_1F_Text_InterviewsStory
	.global MauvilleCity_PokemonCenter_1F_Text_TrainerBattlesTitle
	.global MauvilleCity_PokemonCenter_1F_Text_TrainerBattlesAction
	.global MauvilleCity_PokemonCenter_1F_Text_TrainerBattlesStory
	.global MauvilleCity_PokemonCenter_1F_Text_PokemonCaughtTitle
	.global MauvilleCity_PokemonCenter_1F_Text_PokemonCaughtAction
	.global MauvilleCity_PokemonCenter_1F_Text_PokemonCaughtStory
	.global MauvilleCity_PokemonCenter_1F_Text_FishingPokemonCaughtTitle
	.global MauvilleCity_PokemonCenter_1F_Text_FishingPokemonCaughtAction
	.global MauvilleCity_PokemonCenter_1F_Text_FishingPokemonCaughtStory
	.global MauvilleCity_PokemonCenter_1F_Text_EggsHatchedTitle
	.global MauvilleCity_PokemonCenter_1F_Text_EggsHatchedAction
	.global MauvilleCity_PokemonCenter_1F_Text_EggsHatchedStory
	.global MauvilleCity_PokemonCenter_1F_Text_PokemonEvolvedTitle
	.global MauvilleCity_PokemonCenter_1F_Text_PokemonEvolvedAction
	.global MauvilleCity_PokemonCenter_1F_Text_PokemonEvolvedStory
	.global MauvilleCity_PokemonCenter_1F_Text_UsedPokemonCenterTitle
	.global MauvilleCity_PokemonCenter_1F_Text_UsedPokemonCenterAction
	.global MauvilleCity_PokemonCenter_1F_Text_UsedPokemonCenterStory
	.global MauvilleCity_PokemonCenter_1F_Text_RestedAtHomeTitle
	.global MauvilleCity_PokemonCenter_1F_Text_RestedAtHomeAction
	.global MauvilleCity_PokemonCenter_1F_Text_RestedAtHomeStory
	.global MauvilleCity_PokemonCenter_1F_Text_SafariGamesTitle
	.global MauvilleCity_PokemonCenter_1F_Text_SafariGamesAction
	.global MauvilleCity_PokemonCenter_1F_Text_SafariGamesStory
	.global MauvilleCity_PokemonCenter_1F_Text_UsedCutTitle
	.global MauvilleCity_PokemonCenter_1F_Text_UsedCutAction
	.global MauvilleCity_PokemonCenter_1F_Text_UsedCutStory
	.global MauvilleCity_PokemonCenter_1F_Text_UsedRockSmashTitle
	.global MauvilleCity_PokemonCenter_1F_Text_UsedRockSmashAction
	.global MauvilleCity_PokemonCenter_1F_Text_UsedRockSmashStory
	.global MauvilleCity_PokemonCenter_1F_Text_MovedBasesTitle
	.global MauvilleCity_PokemonCenter_1F_Text_MovedBasesAction
	.global MauvilleCity_PokemonCenter_1F_Text_MovedBasesStory
	.global MauvilleCity_PokemonCenter_1F_Text_UsedSplashTitle
	.global MauvilleCity_PokemonCenter_1F_Text_UsedSplashAction
	.global MauvilleCity_PokemonCenter_1F_Text_UsedSplashStory
	.global MauvilleCity_PokemonCenter_1F_Text_UsedStruggleTitle
	.global MauvilleCity_PokemonCenter_1F_Text_UsedStruggleAction
	.global MauvilleCity_PokemonCenter_1F_Text_UsedStruggleStory
	.global MauvilleCity_PokemonCenter_1F_Text_SlotJackpotsTitle
	.global MauvilleCity_PokemonCenter_1F_Text_SlotJackpotsAction
	.global MauvilleCity_PokemonCenter_1F_Text_SlotJackpotsStory
	.global MauvilleCity_PokemonCenter_1F_Text_RouletteWinsTitle
	.global MauvilleCity_PokemonCenter_1F_Text_RouletteWinsAction
	.global MauvilleCity_PokemonCenter_1F_Text_RouletteWinsStory
	.global MauvilleCity_PokemonCenter_1F_Text_BattleTowerChallengesTitle
	.global MauvilleCity_PokemonCenter_1F_Text_BattleTowerChallengesAction
	.global MauvilleCity_PokemonCenter_1F_Text_BattleTowerChallengesStory
	.global MauvilleCity_PokemonCenter_1F_Text_MadePokeblocksTitle
	.global MauvilleCity_PokemonCenter_1F_Text_MadePokeblocksAction
	.global MauvilleCity_PokemonCenter_1F_Text_MadePokeblocksStory
	.global MauvilleCity_PokemonCenter_1F_Text_EnteredContestsTitle
	.global MauvilleCity_PokemonCenter_1F_Text_EnteredContestsAction
	.global MauvilleCity_PokemonCenter_1F_Text_EnteredContestsStory
	.global MauvilleCity_PokemonCenter_1F_Text_WonContestsTitle
	.global MauvilleCity_PokemonCenter_1F_Text_WonContestsAction
	.global MauvilleCity_PokemonCenter_1F_Text_WonContestsStory
	.global MauvilleCity_PokemonCenter_1F_Text_TimesShoppedTitle
	.global MauvilleCity_PokemonCenter_1F_Text_TimesShoppedAction
	.global MauvilleCity_PokemonCenter_1F_Text_TimesShoppedStory
	.global MauvilleCity_PokemonCenter_1F_Text_UsedItemFinderTitle
	.global MauvilleCity_PokemonCenter_1F_Text_UsedItemFinderAction
	.global MauvilleCity_PokemonCenter_1F_Text_UsedItemFinderStory
	.global MauvilleCity_PokemonCenter_1F_Text_TimesRainedTitle
	.global MauvilleCity_PokemonCenter_1F_Text_TimesRainedAction
	.global MauvilleCity_PokemonCenter_1F_Text_TimesRainedStory
	.global MauvilleCity_PokemonCenter_1F_Text_CheckedPokedexTitle
	.global MauvilleCity_PokemonCenter_1F_Text_CheckedPokedexAction
	.global MauvilleCity_PokemonCenter_1F_Text_CheckedPokedexStory
	.global MauvilleCity_PokemonCenter_1F_Text_ReceivedRibbonsTitle
	.global MauvilleCity_PokemonCenter_1F_Text_ReceivedRibbonsAction
	.global MauvilleCity_PokemonCenter_1F_Text_ReceivedRibbonsStory
	.global MauvilleCity_PokemonCenter_1F_Text_LedgesJumpedTitle
	.global MauvilleCity_PokemonCenter_1F_Text_LedgesJumpedAction
	.global MauvilleCity_PokemonCenter_1F_Text_LedgesJumpedStory
	.global MauvilleCity_PokemonCenter_1F_Text_TVWatchedTitle
	.global MauvilleCity_PokemonCenter_1F_Text_TVWatchedAction
	.global MauvilleCity_PokemonCenter_1F_Text_TVWatchedStory
	.global MauvilleCity_PokemonCenter_1F_Text_CheckedClockTitle
	.global MauvilleCity_PokemonCenter_1F_Text_CheckedClockAction
	.global MauvilleCity_PokemonCenter_1F_Text_CheckedClockStory
	.global MauvilleCity_PokemonCenter_1F_Text_WonLotteryTitle
	.global MauvilleCity_PokemonCenter_1F_Text_WonLotteryAction
	.global MauvilleCity_PokemonCenter_1F_Text_WonLotteryStory
	.global MauvilleCity_PokemonCenter_1F_Text_UsedDaycareTitle
	.global MauvilleCity_PokemonCenter_1F_Text_UsedDaycareAction
	.global MauvilleCity_PokemonCenter_1F_Text_UsedDaycareStory
	.global MauvilleCity_PokemonCenter_1F_Text_RodeCableCarTitle
	.global MauvilleCity_PokemonCenter_1F_Text_RodeCableCarAction
	.global MauvilleCity_PokemonCenter_1F_Text_RodeCableCarStory
	.global MauvilleCity_PokemonCenter_1F_Text_HotSpringsTitle
	.global MauvilleCity_PokemonCenter_1F_Text_HotSpringsAction
	.global MauvilleCity_PokemonCenter_1F_Text_HotSpringsStory
	.global MauvilleCity_PokemonCenter_1F_Text_HearMyStory
	.global MauvilleCity_PokemonCenter_1F_Text_GiddyFeelingTheBlues
	.global MauvilleCity_PokemonCenter_1F_Text_AlsoIWasThinking
	.global MauvilleCity_PokemonCenter_1F_Text_WeShouldChatAgain
	.global MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToHearMySong
	.global MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues1
	.global MauvilleCity_PokemonCenter_1F_Text_WishICouldPlaySongForOthers
	.global MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToWriteSomeLyrics
	.global MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues2
	.global MauvilleCity_PokemonCenter_1F_Text_LetMeSingItForYou
	.global MauvilleCity_PokemonCenter_1F_Text_ThatHowYouWantedSongToGo
	.global MauvilleCity_PokemonCenter_1F_Text_IllSingThisSongForAWhile
	.global MauvilleCity_PokemonCenter_1F_Text_TeachWhatsHipAndHappening
	.global MauvilleCity_PokemonCenter_1F_Text_IAlreadyTaughtYou
	.global MauvilleCity_PokemonCenter_1F_Text_IveGotNothingNewToTeach
	.global MauvilleCity_PokemonCenter_1F_Text_HaveYouHeardOfWord
@ END GENERATED LOCALIZATION EXPORTS
