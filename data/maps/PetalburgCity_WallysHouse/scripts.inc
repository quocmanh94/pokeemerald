PetalburgCity_WallysHouse_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PetalburgCity_WallysHouse_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PetalburgCity_WallysHouse_OnWarp
	.byte 0

PetalburgCity_WallysHouse_OnWarp:
	map_script_2 VAR_PETALBURG_CITY_STATE, 4, PetalburgCity_WallysHouse_EventScript_PlayerWallysDadFaceEachOther
	.2byte 0

PetalburgCity_WallysHouse_EventScript_PlayerWallysDadFaceEachOther::
	turnobject LOCALID_PLAYER, DIR_EAST
	turnobject LOCALID_WALLYS_HOUSE_WALLYS_DAD, DIR_WEST
	end

PetalburgCity_WallysHouse_OnFrame:
	map_script_2 VAR_PETALBURG_CITY_STATE, 4, PetalburgCity_WallysHouse_EventScript_GiveHMSurf
	.2byte 0

PetalburgCity_WallysHouse_EventScript_GiveHMSurf::
	lockall
	msgbox PetalburgCity_WallysHouse_Text_PleaseExcuseUs, MSGBOX_DEFAULT
	giveitem ITEM_HM_SURF
	setflag FLAG_RECEIVED_HM_SURF
	msgbox PetalburgCity_WallysHouse_Text_SurfGoAllSortsOfPlaces, MSGBOX_DEFAULT
	setvar VAR_PETALBURG_CITY_STATE, 5
	releaseall
	end

PetalburgCity_WallysHouse_EventScript_WallysDad::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, PetalburgCity_WallysHouse_EventScript_DefeatedWallyInVictoryRoad
	goto_if_set FLAG_RECEIVED_HM_SURF, PetalburgCity_WallysHouse_EventScript_ReceievedHMSurf
	goto_if_set FLAG_THANKED_FOR_PLAYING_WITH_WALLY, PetalburgCity_WallysHouse_EventScript_PlayedWithWally
	msgbox PetalburgCity_WallysHouse_Text_ThanksForPlayingWithWally, MSGBOX_DEFAULT
	setflag FLAG_THANKED_FOR_PLAYING_WITH_WALLY
	release
	end

PetalburgCity_WallysHouse_EventScript_ReceievedHMSurf::
	msgbox PetalburgCity_WallysHouse_Text_WallyIsComingHomeSoon, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_DefeatedWallyInVictoryRoad::
	msgbox PetalburgCity_WallysHouse_Text_YouMetWallyInEverGrandeCity, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_PlayedWithWally::
	msgbox PetalburgCity_WallysHouse_Text_WonderHowWallyIsDoing, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_WallysMom::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_SURF, PetalburgCity_WallysHouse_EventScript_ReceivedHMSurf
	msgbox PetalburgCity_WallysHouse_Text_WallyWasReallyHappy, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_ReceivedHMSurf::
	msgbox PetalburgCity_WallysHouse_Text_WallyLeftWithoutTelling, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_Text_ThanksForPlayingWithWally:
	.string "Cháu là... A, cháu hẳn là {PLAYER}{KUN},\n"
	.string "đúng không?\p"
	.string "Cảm ơn cháu đã chơi cùng WALLY lúc nãy.\p"
	.string "Thằng bé vốn yếu ớt và hay đau bệnh từ\n"
	.string "khi còn nhỏ.\p"
	.string "Chúng tôi đã gửi nó đến ở với họ hàng\n"
	.string "tại VERDANTURF TOWN một thời gian.\p"
	.string "Không khí ở đó trong lành hơn ở đây\n"
	.string "nhiều.\p"
	.string "Gì cơ? WALLY đâu à? WALLY nhà chú đã\n"
	.string "đi rồi.\p"
	.string "Không biết giờ nó đã tới đâu rồi?$"

PetalburgCity_WallysHouse_Text_WonderHowWallyIsDoing:
	.string "Không biết WALLY nhà mình dạo này thế\n"
	.string "nào?$"

PetalburgCity_WallysHouse_Text_PleaseExcuseUs:
	.string "{PLAYER}{KUN}! Xin lỗi vì đã kéo cháu\n"
	.string "tới đây như vậy.\p"
	.string "Nhưng WALLY nhà chú đã khỏe lên rất\n"
	.string "nhiều từ khi đến VERDANTURF TOWN.\p"
	.string "Tất cả là nhờ cháu!\p"
	.string "Khi WALLY rời thị trấn, cháu đã giúp nó\n"
	.string "bắt một POKéMON, đúng không?\p"
	.string "Chú nghĩ việc đó đã khiến WALLY rất vui.\p"
	.string "Thật ra không chỉ WALLY. Chú, ba của nó,\n"
	.string "cũng rất vui.\p"
	.string "Chú vui vì nó có được một người bạn\n"
	.string "tuyệt vời như cháu.\p"
	.string "Đây không phải hối lộ gì đâu, nhưng chú\n"
	.string "thật sự muốn cháu nhận thứ này.$"

PetalburgCity_WallysHouse_Text_SurfGoAllSortsOfPlaces:
	.string "Nếu POKéMON của bạn có thể dùng SURF,\n"
	.string "bạn sẽ đến được đủ mọi nơi.$"

PetalburgCity_WallysHouse_Text_WallyIsComingHomeSoon:
	.string "WALLY sắp về nhà rồi. Tôi mong đến ngày\n"
	.string "đó lắm.$"

PetalburgCity_WallysHouse_Text_YouMetWallyInEverGrandeCity:
	.string "Ồ? Cháu đã gặp WALLY ở EVER GRANDE\n"
	.string "CITY sao?\p"
	.string "Ôi, {PLAYER}{KUN}, đừng đùa chứ.\p"
	.string "Dù đã khỏe hơn, nó vẫn không thể một\n"
	.string "mình đi tới nơi xa như vậy.$"

PetalburgCity_WallysHouse_Text_WallyWasReallyHappy:
	.string "WALLY đã rất vui khi kể với chúng tôi\n"
	.string "rằng nó bắt được một POKéMON.\p"
	.string "Đã lâu lắm rồi tôi mới thấy nó cười như\n"
	.string "vậy.$"

PetalburgCity_WallysHouse_Text_WallyLeftWithoutTelling:
	.string "Cháu hãy giữ kín chuyện này với chồng\n"
	.string "cô...\p"
	.string "Nhưng WALLY nhà cô đã rời VERDANTURF\n"
	.string "TOWN mà không nói với ai.\p"
	.string "Cháu biết đấy, WALLY tuy yếu ớt nhưng\n"
	.string "lại có ý chí mạnh mẽ đáng ngạc nhiên.\p"
	.string "Cô tin một ngày nào đó nó sẽ bình an\n"
	.string "trở về!$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global PetalburgCity_WallysHouse_Text_ThanksForPlayingWithWally
	.global PetalburgCity_WallysHouse_Text_WonderHowWallyIsDoing
	.global PetalburgCity_WallysHouse_Text_PleaseExcuseUs
	.global PetalburgCity_WallysHouse_Text_SurfGoAllSortsOfPlaces
	.global PetalburgCity_WallysHouse_Text_WallyIsComingHomeSoon
	.global PetalburgCity_WallysHouse_Text_YouMetWallyInEverGrandeCity
	.global PetalburgCity_WallysHouse_Text_WallyWasReallyHappy
	.global PetalburgCity_WallysHouse_Text_WallyLeftWithoutTelling
@ END GENERATED LOCALIZATION EXPORTS
