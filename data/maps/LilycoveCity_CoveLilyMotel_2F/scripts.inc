LilycoveCity_CoveLilyMotel_2F_MapScripts::
	.byte 0

LilycoveCity_CoveLilyMotel_2F_EventScript_GameDesigner::
	lock
	faceplayer
	call_if_unset FLAG_TEMP_2, LilycoveCity_CoveLilyMotel_2F_EventScript_ShowMeCompletedDex
	call_if_set FLAG_TEMP_2, LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma
	specialvar VAR_RESULT, HasAllHoennMons
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_CoveLilyMotel_2F_EventScript_AllHoennMonsFanfare
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_ShowMeCompletedDex::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ShowMeCompletedDex, MSGBOX_DEFAULT
	return

LilycoveCity_CoveLilyMotel_2F_EventScript_AllHoennMonsFanfare::
	setflag FLAG_TEMP_2
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma::
	message LilycoveCity_CoveLilyMotel_2F_Text_FilledPokedexGiveYouThis
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	special Special_ShowDiploma
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_Programmer::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ImTheProgrammer, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_GraphicArtist::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ImTheGraphicArtist, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_FatMan::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_GirlsAreCute, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_Woman::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_SeaBreezeTicklesHeart, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_GameBoyKid::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_NeverLeaveWithoutGameBoy, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_Scott::
	lock
	faceplayer
	goto_if_set FLAG_MET_SCOTT_IN_LILYCOVE, LilycoveCity_CoveLilyMotel_2F_EventScript_MetScott
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_SnoozingPreferBattles, MSGBOX_DEFAULT
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_IN_LILYCOVE
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_MetScott::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ContestsDoTakeStrategy, MSGBOX_DEFAULT
	release
	end

LilycoveCity_CoveLilyMotel_2F_Text_ShowMeCompletedDex:
	.string "Tôi là GAME DESIGNER.\p"
	.string "Ồ, vậy sao? Bạn đang hoàn thành một\n"
	.string "POKéDEX à?\p"
	.string "Hoàn thành nó khó lắm, nhưng đừng bỏ\n"
	.string "cuộc.\p"
	.string "Nếu hoàn thành được, hãy đến cho tôi\n"
	.string "xem nhé.$"

LilycoveCity_CoveLilyMotel_2F_Text_FilledPokedexGiveYouThis:
	.string "Chà! Tuyệt vời quá! Đúng vậy, thật sự\n"
	.string "tuyệt vời!\p"
	.string "POKéDEX này đã được hoàn thành toàn\n"
	.string "bộ! Bạn hẳn phải yêu POKéMON lắm!\p"
	.string "Tôi thực sự rất ấn tượng!\p"
	.string "Hãy để tôi tặng bạn thứ này để ghi nhận\n"
	.string "thành tích đó!$"

LilycoveCity_CoveLilyMotel_2F_Text_ImTheProgrammer:
	.string "Tôi á? Bạn đang nói với tôi sao? Tôi là\n"
	.string "PROGRAMMER.\p"
	.string "Không biết SLOTS ở đây thế nào nhỉ.$"

LilycoveCity_CoveLilyMotel_2F_Text_ImTheGraphicArtist:
	.string "Tôi là GRAPHIC ARTIST! POKéMON ở HOENN\n"
	.string "thú vị lắm phải không?$"

LilycoveCity_CoveLilyMotel_2F_Text_GirlsAreCute:
	.string "Mấy bé gái TUBERS dễ thương quá nhỉ?\n"
	.string "Được đấu với một TUBER dễ thương...\p"
	.string "Úi chao, tuyệt vời quá!\p"
	.string "Còn TWINS nữa! Chẳng phải họ rất dễ\n"
	.string "thương sao? Một trận đấu 2 đấu 2 với\l"
	.string "TWINS...\p"
	.string "Úi chao, vui không chịu nổi!$"

LilycoveCity_CoveLilyMotel_2F_Text_SeaBreezeTicklesHeart:
	.string "Làn gió biển khẽ mơn man trái tim tôi. Ở\n"
	.string "đây thật tuyệt vời!$"

LilycoveCity_CoveLilyMotel_2F_Text_NeverLeaveWithoutGameBoy:
	.string "Bạn chẳng bao giờ biết người ta sẽ\n"
	.string "thách đấu mình lúc nào và ở đâu.\p"
	.string "Vì vậy, tôi không bao giờ ra khỏi nhà mà\n"
	.string "thiếu GAME BOY ADVANCE.$"

LilycoveCity_CoveLilyMotel_2F_Text_SnoozingPreferBattles:
	.string "SCOTT: ... ... ... ... ... ... ... ... ... ... Khò...\p"
	.string "... ... ... ... ... Hả?! Ôi, xin lỗi, xin lỗi! Tôi\n"
	.string "ngủ gật mất!\p"
	.string "Tôi đến xem thử cái gọi là POKéMON\n"
	.string "CONTEST này.\p"
	.string "Phải công nhận trông nó khá thú vị,\n"
	.string "nhưng...\p"
	.string "Cứ coi tôi là người theo trường phái\n"
	.string "thuần túy, tôi thích chiến đấu và\l"
	.string "những HLV mạnh mẽ hơn.\p"
	.string "Nhưng đó chỉ là sở thích của riêng tôi.\p"
	.string "{PLAYER}{KUN}, tôi mong bạn sẽ tận\n"
	.string "hưởng mọi thứ, từ GYMS, các cuộc thi,\l"
	.string "BATTLE TENT cho đến tất tần tật những\l"
	.string "điều khác!$"

LilycoveCity_CoveLilyMotel_2F_Text_ContestsDoTakeStrategy:
	.string "SCOTT: Tôi nghĩ muốn thắng một cuộc thi\n"
	.string "thì đúng là cần chiến thuật.\p"
	.string "Theo tôi, xây dựng chiến thuật cho\n"
	.string "cuộc thi cũng là một cách để trở thành\l"
	.string "HLV giỏi hơn.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global LilycoveCity_CoveLilyMotel_2F_Text_ShowMeCompletedDex
	.global LilycoveCity_CoveLilyMotel_2F_Text_FilledPokedexGiveYouThis
	.global LilycoveCity_CoveLilyMotel_2F_Text_ImTheProgrammer
	.global LilycoveCity_CoveLilyMotel_2F_Text_ImTheGraphicArtist
	.global LilycoveCity_CoveLilyMotel_2F_Text_GirlsAreCute
	.global LilycoveCity_CoveLilyMotel_2F_Text_SeaBreezeTicklesHeart
	.global LilycoveCity_CoveLilyMotel_2F_Text_NeverLeaveWithoutGameBoy
	.global LilycoveCity_CoveLilyMotel_2F_Text_SnoozingPreferBattles
	.global LilycoveCity_CoveLilyMotel_2F_Text_ContestsDoTakeStrategy
@ END GENERATED LOCALIZATION EXPORTS
