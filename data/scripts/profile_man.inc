ProfileMan_EventScript_Man::
	lock
	faceplayer
	goto_if_set FLAG_SYS_CHAT_USED, ProfileMan_EventScript_GivenProfileBefore
	msgbox ProfileMan_Text_CollectTrainerProfiles, MSGBOX_DEFAULT
	goto ProfileMan_EventScript_AskToSeeProfile
	end

ProfileMan_EventScript_AskToSeeProfile::
	msgbox ProfileMan_Text_MayISeeYourProfile, MSGBOX_DEFAULT
	multichoice 17, 6, MULTI_YESNOINFO_2, FALSE
	switch VAR_RESULT
	case 0, ProfileMan_EventScript_CreateProfile
	case 1, ProfileMan_EventScript_DeclineShowProfile
	case 2, ProfileMan_EventScript_Info
	case MULTI_B_PRESSED, ProfileMan_EventScript_DeclineShowProfile
	end

ProfileMan_EventScript_Info::
	msgbox ProfileMan_Text_EasyChatExplanation, MSGBOX_DEFAULT
	goto ProfileMan_EventScript_AskToSeeProfile
	end

ProfileMan_EventScript_CreateProfile::
	msgbox ProfileMan_Text_LetsSeeItThen, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, EASY_CHAT_TYPE_PROFILE
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto_if_eq VAR_RESULT, 0, ProfileMan_EventScript_CancelShowProfile
	goto_if_eq VAR_RESULT, 1, ProfileMan_EventScript_ShowProfile
	end

ProfileMan_EventScript_CancelShowProfile::
	msgbox ProfileMan_Text_NotIntoItRightNow, MSGBOX_DEFAULT
	release
	end

ProfileMan_EventScript_ShowProfile::
	setvar VAR_0x8004, 0
	special ShowEasyChatProfile
	waitmessage
	delay 80
	msgbox ProfileMan_Text_FantasticProfile, MSGBOX_DEFAULT
	release
	end

ProfileMan_EventScript_DeclineShowProfile::
	msgbox ProfileMan_Text_ImagineYouWouldHaveWonderfulProfile, MSGBOX_DEFAULT
	release
	end

ProfileMan_EventScript_GivenProfileBefore::
	msgbox ProfileMan_Text_YouHaveWonderfulSmile, MSGBOX_DEFAULT
	goto ProfileMan_EventScript_AskToSeeNewProfile
	end

ProfileMan_EventScript_AskToSeeNewProfile::
	msgbox ProfileMan_Text_MayISeeYourNewProfile, MSGBOX_DEFAULT
	multichoice 17, 6, MULTI_YESNOINFO_2, FALSE
	switch VAR_RESULT
	case 0, ProfileMan_EventScript_CreateNewProfile
	case 1, ProfileMan_EventScript_DeclineNewProfile
	case 2, ProfileMan_EventScript_InfoNewProfile
	case MULTI_B_PRESSED, ProfileMan_EventScript_DeclineNewProfile
	end

ProfileMan_EventScript_InfoNewProfile::
	msgbox ProfileMan_Text_EasyChatExplanation, MSGBOX_DEFAULT
	goto ProfileMan_EventScript_AskToSeeNewProfile
	end

ProfileMan_EventScript_CreateNewProfile::
	msgbox ProfileMan_Text_EvenBetterThanLastProfile, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, EASY_CHAT_TYPE_PROFILE
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto_if_eq VAR_RESULT, 0, ProfileMan_EventScript_CancelShowProfile
	goto_if_eq VAR_RESULT, 1, ProfileMan_EventScript_ShowProfile
	end

ProfileMan_EventScript_DeclineNewProfile::
	msgbox ProfileMan_Text_LikeProfileWayItIs, MSGBOX_DEFAULT
	release
	end

@ Unused
ProfileMan_EventScript_Ret::
	return

ProfileMan_Text_CollectTrainerProfiles:
	.string "Chào HLV! Bạn có một nụ cười thật\n"
	.string "tuyệt.\p"
	.string "Tôi có một sở thích, đó là sưu tầm hồ\n"
	.string "sơ của các HLV POKéMON.$"

ProfileMan_Text_MayISeeYourProfile:
	.string "Vậy bạn thấy sao? Cho tôi xem hồ sơ của\n"
	.string "bạn được không?$"

ProfileMan_Text_EasyChatExplanation:
	.string "Bạn tạo hồ sơ của riêng mình bằng cách\n"
	.string "ghép bốn từ hoặc cụm từ.\p"
	.string "Đây, tôi sẽ cho bạn xem một hồ sơ mẫu\n"
	.string "được tạo từ bốn phần văn bản.\p"
	.string "Bạn có thể tùy ý thay bốn phần đó bằng\n"
	.string "những phần khác để tạo hồ sơ riêng.\p"
	.string "Có rất nhiều phần văn bản để bạn sử\n"
	.string "dụng.\p"
	.string "Chúng được xếp thành các nhóm như\n"
	.string "POKéMON, lối sống và sở thích để dễ tìm\l"
	.string "hơn.\p"
	.string "Trước tiên, hãy chọn một nhóm để hiển\n"
	.string "thị danh sách các lựa chọn.\p"
	.string "Sau đó, chọn nội dung bạn muốn.\p"
	.string "Lặp lại với những phần còn lại, thế là\n"
	.string "bạn sẽ có hồ sơ của riêng mình.$"

ProfileMan_Text_LetsSeeItThen:
	.string "Tuyệt! Cảm ơn bạn! Vậy cho tôi xem nhé.$"

ProfileMan_Text_ImagineYouWouldHaveWonderfulProfile:
	.string "Ôi, thật sao?\p"
	.string "Tôi cứ nghĩ người như bạn sẽ có một hồ\n"
	.string "sơ tuyệt vời...$"

ProfileMan_Text_NotIntoItRightNow:
	.string "Ồ? Bây giờ bạn chưa có hứng à?\p"
	.string "Với tôi thì lúc nào cũng được!$"

ProfileMan_Text_YouHaveWonderfulSmile:
	.string "Chào HLV! Bạn có một nụ cười thật\n"
	.string "tuyệt.$"

ProfileMan_Text_MayISeeYourNewProfile:
	.string "Cho tôi xem hồ sơ mới của bạn được\n"
	.string "không?$"

ProfileMan_Text_EvenBetterThanLastProfile:
	.string "Tuyệt! Cảm ơn bạn!\p"
	.string "Tôi hy vọng nó còn hay hơn hồ sơ bạn đã\n"
	.string "cho tôi xem lần trước.$"

ProfileMan_Text_LikeProfileWayItIs:
	.string "Ồ, bạn thích giữ nguyên hồ sơ hiện tại.\p"
	.string "Tôi hiểu mà, vì hồ sơ hiện giờ của bạn\n"
	.string "đã rất tuyệt rồi.$"

ProfileMan_Text_FantasticProfile:
	.string "T-tuyệt vời!\p"
	.string "Hồ sơ của bạn thật xuất sắc! Nó thể\n"
	.string "hiện đúng con người bạn.\p"
	.string "Bất cứ ai nghe hồ sơ này cũng sẽ bị bạn\n"
	.string "cuốn hút!\p"
	.string "Cảm ơn bạn!$"

@ Unused
ProfileMan_Text_YouKnowSecretSaying:
	.string "Ồ? Bạn biết câu nói bí mật!\p"
	.string "Vậy là giờ bạn cũng là thành viên của\n"
	.string "MYSTERY EVENT CLUB!$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global ProfileMan_Text_CollectTrainerProfiles
	.global ProfileMan_Text_MayISeeYourProfile
	.global ProfileMan_Text_EasyChatExplanation
	.global ProfileMan_Text_LetsSeeItThen
	.global ProfileMan_Text_ImagineYouWouldHaveWonderfulProfile
	.global ProfileMan_Text_NotIntoItRightNow
	.global ProfileMan_Text_YouHaveWonderfulSmile
	.global ProfileMan_Text_MayISeeYourNewProfile
	.global ProfileMan_Text_EvenBetterThanLastProfile
	.global ProfileMan_Text_LikeProfileWayItIs
	.global ProfileMan_Text_FantasticProfile
	.global ProfileMan_Text_YouKnowSecretSaying
@ END GENERATED LOCALIZATION EXPORTS
