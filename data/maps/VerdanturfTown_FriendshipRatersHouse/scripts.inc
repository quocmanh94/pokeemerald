VerdanturfTown_FriendshipRatersHouse_MapScripts::
	.byte 0

VerdanturfTown_FriendshipRatersHouse_EventScript_FriendshipRater::
	lock
	faceplayer
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_SeeHowMuchPokemonLikesYou, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	switch VAR_RESULT
	case FRIENDSHIP_NONE, VerdanturfTown_FriendshipRatersHouse_EventScript_DetestsYou
	case FRIENDSHIP_1_TO_49, VerdanturfTown_FriendshipRatersHouse_EventScript_VeryWary
	case FRIENDSHIP_50_TO_99, VerdanturfTown_FriendshipRatersHouse_EventScript_NotUsedToYou
	case FRIENDSHIP_100_TO_149, VerdanturfTown_FriendshipRatersHouse_EventScript_GettingUsedToYou
	case FRIENDSHIP_150_TO_199, VerdanturfTown_FriendshipRatersHouse_EventScript_LikesYouQuiteALot
	case FRIENDSHIP_200_TO_254, VerdanturfTown_FriendshipRatersHouse_EventScript_VeryHappy
	case FRIENDSHIP_MAX, VerdanturfTown_FriendshipRatersHouse_EventScript_AdoresYou
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_DetestsYou::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_DetestsYou, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_VeryWary::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_VeryWary, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_NotUsedToYou::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_NotUsedToYou, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_GettingUsedToYou::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_GettingUsedToYou, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_LikesYouQuiteALot::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_LikesYouQuiteALot, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_VeryHappy::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_VeryHappy, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_AdoresYou::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_AdoresYou, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_Pikachu::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIKACHU, CRY_MODE_NORMAL
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_Pikachu, MSGBOX_DEFAULT
	waitmoncry
	release
	end

VerdanturfTown_FriendshipRatersHouse_Text_SeeHowMuchPokemonLikesYou:
	.string "Để tôi xem POKéMON của bạn nào. Tôi sẽ\n"
	.string "xem nó quý bạn đến mức nào.\p"
	.string "Ồ. POKéMON của bạn...$"

VerdanturfTown_FriendshipRatersHouse_Text_AdoresYou:
	.string "Nó yêu quý bạn vô cùng. Không thể yêu\n"
	.string "quý bạn hơn được nữa. Nhìn nó, tôi\l"
	.string "cũng thấy vui lây.$"

VerdanturfTown_FriendshipRatersHouse_Text_VeryHappy:
	.string "Nó có vẻ rất hạnh phúc. Rõ ràng nó vô\n"
	.string "cùng quý bạn.$"

VerdanturfTown_FriendshipRatersHouse_Text_LikesYouQuiteALot:
	.string "Nó khá quý bạn. Có vẻ nó muốn được bạn\n"
	.string "cưng chiều thêm một chút.$"

VerdanturfTown_FriendshipRatersHouse_Text_GettingUsedToYou:
	.string "Nó đang dần quen với bạn. Có vẻ nó đã\n"
	.string "tin tưởng bạn.$"

VerdanturfTown_FriendshipRatersHouse_Text_NotUsedToYou:
	.string "Nó vẫn chưa quen với bạn lắm. Nó không\n"
	.string "yêu quý mà cũng chẳng ghét bạn.$"

VerdanturfTown_FriendshipRatersHouse_Text_VeryWary:
	.string "Nó rất cảnh giác. Ánh mắt nó đầy vẻ hung\n"
	.string "dữ đáng sợ. Nó chẳng quý bạn chút nào.$"

VerdanturfTown_FriendshipRatersHouse_Text_DetestsYou:
	.string "Tôi hơi khó nói điều này...\p"
	.string "POKéMON của bạn cực kỳ căm ghét bạn.\n"
	.string "Bạn không thấy bất an sao?$"

VerdanturfTown_FriendshipRatersHouse_Text_Pikachu:
	.string "PIKACHU: Pika pika!$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global VerdanturfTown_FriendshipRatersHouse_Text_SeeHowMuchPokemonLikesYou
	.global VerdanturfTown_FriendshipRatersHouse_Text_AdoresYou
	.global VerdanturfTown_FriendshipRatersHouse_Text_VeryHappy
	.global VerdanturfTown_FriendshipRatersHouse_Text_LikesYouQuiteALot
	.global VerdanturfTown_FriendshipRatersHouse_Text_GettingUsedToYou
	.global VerdanturfTown_FriendshipRatersHouse_Text_NotUsedToYou
	.global VerdanturfTown_FriendshipRatersHouse_Text_VeryWary
	.global VerdanturfTown_FriendshipRatersHouse_Text_DetestsYou
@ END GENERATED LOCALIZATION EXPORTS
