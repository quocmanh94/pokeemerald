RustboroCity_Flat1_2F_MapScripts::
	.byte 0

RustboroCity_Flat1_2F_EventScript_WaldasDad::
	lock
	faceplayer
	specialvar VAR_RESULT, TryBufferWaldaPhrase
	goto_if_eq VAR_RESULT, FALSE, RustboroCity_Flat1_2F_EventScript_WaldasDadFirstPhrase
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Flat1_2F_EventScript_WaldasDadNewPhrase

RustboroCity_Flat1_2F_EventScript_GivePhrase::
	special DoWaldaNamingScreen
	goto_if_eq VAR_0x8004, 1, RustboroCity_Flat1_2F_EventScript_CancelGivePhrase
	goto_if_eq VAR_0x8004, 2, RustboroCity_Flat1_2F_EventScript_CancelGiveFirstPhrase
	specialvar VAR_RESULT, TryGetWallpaperWithWaldaPhrase
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Flat1_2F_EventScript_WaldaLikesPhrase
	goto_if_eq VAR_RESULT, FALSE, RustboroCity_Flat1_2F_EventScript_WaldaDoesntLikePhrase
	end

RustboroCity_Flat1_2F_EventScript_WaldasDadFirstPhrase::
	msgbox RustboroCity_Flat1_2F_Text_HelloDoYouKnowFunnyPhrase, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_Flat1_2F_EventScript_DeclineGivePhrase
	msgbox RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion, MSGBOX_DEFAULT
	goto RustboroCity_Flat1_2F_EventScript_GivePhrase

RustboroCity_Flat1_2F_EventScript_WaldasDadNewPhrase::
	msgbox RustboroCity_Flat1_2F_Text_BeenSayingXDoYouKnowBetterPhrase, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_Flat1_2F_EventScript_DeclineGivePhrase
	msgbox RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion, MSGBOX_DEFAULT
	goto RustboroCity_Flat1_2F_EventScript_GivePhrase

RustboroCity_Flat1_2F_EventScript_DeclineGivePhrase::
	msgbox RustboroCity_Flat1_2F_Text_OhIsThatRight, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_CancelGivePhrase::
	msgbox RustboroCity_Flat1_2F_Text_OhYouDontKnowAny, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_CancelGiveFirstPhrase::
	msgbox RustboroCity_Flat1_2F_Text_ThinkOfMyOwnPhrase, MSGBOX_DEFAULT
	call RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda
	msgbox RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll2, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_WaldaLikesPhrase::
	msgbox RustboroCity_Flat1_2F_Text_LetsGiveItATry2, MSGBOX_DEFAULT
	call RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda
	msgbox RustboroCity_Flat1_2F_Text_OhShesLaughing, MSGBOX_DEFAULT
	applymovement LOCALID_WALDAS_DAD, Common_Movement_FacePlayer
	waitmovement 0
	msgbox RustboroCity_Flat1_2F_Text_ThankYouIllGiveYouWallpaper, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_WaldaDoesntLikePhrase::
	msgbox RustboroCity_Flat1_2F_Text_LetsGiveItATry, MSGBOX_DEFAULT
	call RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda
	msgbox RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda::
	turnobject LOCALID_WALDAS_DAD, DIR_EAST
	return

RustboroCity_Flat1_2F_EventScript_WaldasMom::
	msgbox RustboroCity_Flat1_2F_Text_ComingUpWithMealsIsHard, MSGBOX_NPC
	end

RustboroCity_Flat1_2F_EventScript_PokeDoll::
	msgbox RustboroCity_Flat1_2F_Text_ItsAPokemonPlushDoll, MSGBOX_SIGN
	end

RustboroCity_Flat1_2F_Text_ComingUpWithMealsIsHard:
	.string "Ôi, ngày nào cũng khổ quá...\p"
	.string "Khổ chuyện gì à? Còn phải hỏi sao?\p"
	.string "Là nghĩ xem mỗi ngày nên nấu món gì\n"
	.string "đấy.\p"
	.string "Ngày nào cũng nghĩ thực đơn thật\n"
	.string "chẳng dễ chút nào.$"

RustboroCity_Flat1_2F_Text_HelloDoYouKnowFunnyPhrase:
	.string "Ồ, xin chào! Chào mừng đến với gia đình\n"
	.string "PEPPER.\p"
	.string "Tôi muốn hỏi bạn một chuyện. Bạn đã\n"
	.string "từng trông trẻ chưa?\p"
	.string "Tôi mới làm cha nên chuyện nuôi dạy con\n"
	.string "vẫn hoàn toàn mới mẻ.\p"
	.string "Mà tôi đang gặp một vấn đề. Con gái tôi,\n"
	.string "WALDA, chẳng mấy khi cười.\p"
	.string "Tôi nghĩ con bé sẽ cười nếu tôi nói điều\n"
	.string "gì đó vui vui.\p"
	.string "Bạn có biết từ hay câu nào hài hước để\n"
	.string "chỉ tôi không?$"

RustboroCity_Flat1_2F_Text_BeenSayingXDoYouKnowBetterPhrase:
	.string "Gần đây tôi vẫn nói\n"
	.string "“{STR_VAR_1}” để chọc con bé\l"
	.string "cười.\p"
	.string "Bạn có biết từ hay câu nào hay hơn và\n"
	.string "có thể hiệu nghiệm không?$"

RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion:
	.string "Ồ, tuyệt quá. Vậy hãy cho tôi nghe đề\n"
	.string "xuất của bạn nào.$"

RustboroCity_Flat1_2F_Text_OhIsThatRight:
	.string "Ồ, vậy sao?\p"
	.string "Nếu nghĩ ra đề xuất nào hay, tôi rất sẵn\n"
	.string "lòng lắng nghe.$"

RustboroCity_Flat1_2F_Text_LetsGiveItATry2:
	.string "À, tôi hiểu rồi. Vậy chúng ta thử xem\n"
	.string "nhé?$"

RustboroCity_Flat1_2F_Text_OhShesLaughing:
	.string "{STR_VAR_1}. {STR_VAR_1}.\p"
	.string "Ôi, đúng rồi! Con bé đang cười! Tôi cũng\n"
	.string "vui chẳng kém gì con bé!$"

RustboroCity_Flat1_2F_Text_LetsGiveItATry:
	.string "À, tôi hiểu rồi. Vậy chúng ta thử xem\n"
	.string "nhé?$"

RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll:
	.string "{STR_VAR_1}. {STR_VAR_1}.\p"
	.string "Hừm... Con bé chẳng cười chút nào. Có lẽ\n"
	.string "WALDA là một đứa trẻ rất nghiêm túc...$"

RustboroCity_Flat1_2F_Text_ThinkOfMyOwnPhrase:
	.string "Ồ, vậy là bạn không biết từ nào hay. Thế\n"
	.string "thì tôi đành tự nghĩ vậy.\p"
	.string "Hừm... “{STR_VAR_1}” thì sao\n"
	.string "nhỉ? Để xem có hiệu nghiệm không.$"

RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll2:
	.string "{STR_VAR_1}. {STR_VAR_1}.\p"
	.string "Hừm... Con bé chẳng cười chút nào. Có lẽ\n"
	.string "WALDA là một đứa trẻ rất nghiêm túc...$"

RustboroCity_Flat1_2F_Text_OhYouDontKnowAny:
	.string "Ồ, vậy là bạn không biết từ nào hay.\n"
	.string "Chắc tôi sẽ thử chọc con bé cười bằng\l"
	.string "câu trước đây vậy.\p"
	.string "Dù sao, nếu nghĩ ra đề xuất nào hay thì\n"
	.string "cứ nói với tôi nhé?$"

RustboroCity_Flat1_2F_Text_ThankYouIllGiveYouWallpaper:
	.string "Cảm ơn bạn!\p"
	.string "Nhờ bạn mà WALDA yêu quý của tôi đã\n"
	.string "cười rồi!\p"
	.string "Thật ra, trông tôi có vẻ chẳng đặc biệt\n"
	.string "gì, nhưng tôi là một trong những nhà\l"
	.string "nghiên cứu hàng đầu của DEVON\l"
	.string "CORPORATION.\p"
	.string "Vậy để tôi làm gì đó đáp lễ bạn nhé?\p"
	.string "Tôi biết rồi, tôi sẽ thêm vài mẫu hình\n"
	.string "nền mới cho các BOXES trong PC POKéMON\l"
	.string "Storage System.\p"
	.string "Trong trình đơn chọn mẫu hình nền, hãy\n"
	.string "chọn “FRIENDS.”\p"
	.string "Sau đó bạn sẽ sử dụng được các mẫu\n"
	.string "hình nền mới.$"

RustboroCity_Flat1_2F_Text_ItsAPokemonPlushDoll:
	.string "Đó là một con DOLL nhồi bông hình\n"
	.string "POKéMON!$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global RustboroCity_Flat1_2F_Text_ComingUpWithMealsIsHard
	.global RustboroCity_Flat1_2F_Text_HelloDoYouKnowFunnyPhrase
	.global RustboroCity_Flat1_2F_Text_BeenSayingXDoYouKnowBetterPhrase
	.global RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion
	.global RustboroCity_Flat1_2F_Text_OhIsThatRight
	.global RustboroCity_Flat1_2F_Text_LetsGiveItATry2
	.global RustboroCity_Flat1_2F_Text_OhShesLaughing
	.global RustboroCity_Flat1_2F_Text_LetsGiveItATry
	.global RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll
	.global RustboroCity_Flat1_2F_Text_ThinkOfMyOwnPhrase
	.global RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll2
	.global RustboroCity_Flat1_2F_Text_OhYouDontKnowAny
	.global RustboroCity_Flat1_2F_Text_ThankYouIllGiveYouWallpaper
	.global RustboroCity_Flat1_2F_Text_ItsAPokemonPlushDoll
@ END GENERATED LOCALIZATION EXPORTS
