SlateportCity_PokemonFanClub_MapScripts::
	.byte 0

SlateportCity_PokemonFanClub_EventScript_Chairman::
	lock
	faceplayer
	goto_if_unset FLAG_ENTERED_CONTEST, SlateportCity_PokemonFanClub_EventScript_ChairmanNotEnteredContest
	call_if_unset FLAG_MET_SLATEPORT_FANCLUB_CHAIRMAN, SlateportCity_PokemonFanClub_EventScript_MeetChairman
	switch VAR_SLATEPORT_FAN_CLUB_STATE
	case 0, SlateportCity_PokemonFanClub_EventScript_ChairmanFirstAssessment
	case 1, SlateportCity_PokemonFanClub_EventScript_ChairmanTryAssessPokemon
	case 2, SlateportCity_PokemonFanClub_EventScript_NoMoreScarves
	release
	end

SlateportCity_PokemonFanClub_EventScript_ChairmanFirstAssessment::
	setvar VAR_SLATEPORT_FAN_CLUB_STATE, 1
	msgbox SlateportCity_PokemonFanClub_Text_AllowMeToExamineYourPokemon, MSGBOX_DEFAULT
	goto SlateportCity_PokemonFanClub_EventScript_ChairmanAssessLeadMon
	end

SlateportCity_PokemonFanClub_EventScript_ChairmanTryAssessPokemon::
	setvar VAR_TEMP_2, 0
	call_if_set FLAG_RECEIVED_YELLOW_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_set FLAG_RECEIVED_GREEN_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_set FLAG_RECEIVED_PINK_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_set FLAG_RECEIVED_BLUE_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_set FLAG_RECEIVED_RED_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_eq VAR_TEMP_2, CONTEST_CATEGORIES_COUNT, SlateportCity_PokemonFanClub_EventScript_ReceivedAllScarves
	goto_if_eq VAR_SLATEPORT_FAN_CLUB_STATE, 2, SlateportCity_PokemonFanClub_EventScript_NoMoreScarves
	msgbox SlateportCity_PokemonFanClub_Text_HowIsYourPokemonGrowing, MSGBOX_DEFAULT
	goto SlateportCity_PokemonFanClub_EventScript_ChairmanAssessLeadMon
	end

SlateportCity_PokemonFanClub_EventScript_NoMoreScarves::
	msgbox SlateportCity_PokemonFanClub_Text_NothingElseToGiveYou, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_ChairmanAssessLeadMon::
	msgbox SlateportCity_PokemonFanClub_Text_HmHmISee, MSGBOX_DEFAULT
	setvar VAR_TEMP_1, 0
	call_if_unset FLAG_RECEIVED_YELLOW_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonTough
	call_if_unset FLAG_RECEIVED_GREEN_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonSmart
	call_if_unset FLAG_RECEIVED_PINK_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonCute
	call_if_unset FLAG_RECEIVED_BLUE_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonBeauty
	call_if_unset FLAG_RECEIVED_RED_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonCool
	bufferleadmonspeciesname STR_VAR_1
	switch VAR_TEMP_1
	case 0, SlateportCity_PokemonFanClub_EventScript_NoHighConditions
	case 1, SlateportCity_PokemonFanClub_EventScript_GiveRedScarf
	case 2, SlateportCity_PokemonFanClub_EventScript_GiveBlueScarf
	case 3, SlateportCity_PokemonFanClub_EventScript_GivePinkScarf
	case 4, SlateportCity_PokemonFanClub_EventScript_GiveGreenScarf
	case 5, SlateportCity_PokemonFanClub_EventScript_GiveYellowScarf
	release
	end

SlateportCity_PokemonFanClub_EventScript_ReceivedAllScarves::
	setvar VAR_SLATEPORT_FAN_CLUB_STATE, 2
	return

SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf::
	addvar VAR_TEMP_2, 1
	return

SlateportCity_PokemonFanClub_EventScript_NoHighConditions::
	msgbox SlateportCity_PokemonFanClub_Text_GiveMonMorePokeblocks, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveRedScarf::
	checkitemspace ITEM_RED_SCARF
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_RED_SCARF
	giveitem ITEM_RED_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainRedScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveBlueScarf::
	checkitemspace ITEM_BLUE_SCARF
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_BLUE_SCARF
	giveitem ITEM_BLUE_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainBlueScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GivePinkScarf::
	checkitemspace ITEM_PINK_SCARF
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_PINK_SCARF
	giveitem ITEM_PINK_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainPinkScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveGreenScarf::
	checkitemspace ITEM_GREEN_SCARF
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_GREEN_SCARF
	giveitem ITEM_GREEN_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainGreenScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveYellowScarf::
	checkitemspace ITEM_YELLOW_SCARF
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_YELLOW_SCARF
	giveitem ITEM_YELLOW_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainYellowScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf::
	msgbox SlateportCity_PokemonFanClub_Text_NoSpaceForReward, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_CheckMonCool::
	specialvar VAR_RESULT, CheckLeadMonCool
	call_if_eq VAR_RESULT, TRUE, SlateportCity_PokemonFanClub_EventScript_SetMonCool
	return

SlateportCity_PokemonFanClub_EventScript_SetMonCool::
	setvar VAR_TEMP_1, 1
	return

SlateportCity_PokemonFanClub_EventScript_CheckMonBeauty::
	specialvar VAR_RESULT, CheckLeadMonBeauty
	call_if_eq VAR_RESULT, TRUE, SlateportCity_PokemonFanClub_EventScript_SetMonBeauty
	return

SlateportCity_PokemonFanClub_EventScript_SetMonBeauty::
	setvar VAR_TEMP_1, 2
	return

SlateportCity_PokemonFanClub_EventScript_CheckMonCute::
	specialvar VAR_RESULT, CheckLeadMonCute
	call_if_eq VAR_RESULT, TRUE, SlateportCity_PokemonFanClub_EventScript_SetMonCute
	return

SlateportCity_PokemonFanClub_EventScript_SetMonCute::
	setvar VAR_TEMP_1, 3
	return

SlateportCity_PokemonFanClub_EventScript_CheckMonSmart::
	specialvar VAR_RESULT, CheckLeadMonSmart
	call_if_eq VAR_RESULT, TRUE, SlateportCity_PokemonFanClub_EventScript_SetMonSmart
	return

SlateportCity_PokemonFanClub_EventScript_SetMonSmart::
	setvar VAR_TEMP_1, 4
	return

SlateportCity_PokemonFanClub_EventScript_CheckMonTough::
	specialvar VAR_RESULT, CheckLeadMonTough
	call_if_eq VAR_RESULT, TRUE, SlateportCity_PokemonFanClub_EventScript_SetMonTough
	return

SlateportCity_PokemonFanClub_EventScript_SetMonTough::
	setvar VAR_TEMP_1, 5
	return

SlateportCity_PokemonFanClub_EventScript_ChairmanNotEnteredContest::
	goto_if_set FLAG_MET_SLATEPORT_FANCLUB_CHAIRMAN, SlateportCity_PokemonFanClub_EventScript_ChairmanEnterContest
	msgbox SlateportCity_PokemonFanClub_Text_MeetChairman, MSGBOX_DEFAULT
	setflag FLAG_MET_SLATEPORT_FANCLUB_CHAIRMAN
	release
	end

SlateportCity_PokemonFanClub_EventScript_ChairmanEnterContest::
	msgbox SlateportCity_PokemonFanClub_Text_LikeToSeeEnteredContestPokemon, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_MeetChairman::
	msgbox SlateportCity_PokemonFanClub_Text_MeetChairman, MSGBOX_DEFAULT
	setflag FLAG_MET_SLATEPORT_FANCLUB_CHAIRMAN
	return

SlateportCity_PokemonFanClub_EventScript_SootheBellWoman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SOOTHE_BELL, SlateportCity_PokemonFanClub_EventScript_ReceivedSootheBell
	msgbox SlateportCity_PokemonFanClub_Text_ShowMePokemonThatLoveYou, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_ge VAR_RESULT, FRIENDSHIP_150_TO_199, SlateportCity_PokemonFanClub_EventScript_GiveSootheBell
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveSootheBell::
	playse SE_PIN
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_LAST_TALKED, Common_Movement_Delay48
	waitmovement 0
	msgbox SlateportCity_PokemonFanClub_Text_PokemonAdoresYou, MSGBOX_DEFAULT
	giveitem ITEM_SOOTHE_BELL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_SOOTHE_BELL
	release
	end

SlateportCity_PokemonFanClub_EventScript_ReceivedSootheBell::
	msgbox SlateportCity_PokemonFanClub_Text_TreatPokemonWithLove, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_Man::
	msgbox SlateportCity_PokemonFanClub_Text_PokemonDontLikeFainting, MSGBOX_NPC
	end

SlateportCity_PokemonFanClub_EventScript_Twin::
	msgbox SlateportCity_PokemonFanClub_Text_MonEnjoyedProtein, MSGBOX_NPC
	end

SlateportCity_PokemonFanClub_EventScript_Skitty::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SKITTY, CRY_MODE_NORMAL
	msgbox SlateportCity_PokemonFanClub_Text_Skitty, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SlateportCity_PokemonFanClub_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox SlateportCity_PokemonFanClub_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SlateportCity_PokemonFanClub_EventScript_Azumarill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZUMARILL, CRY_MODE_NORMAL
	msgbox SlateportCity_PokemonFanClub_Text_Azumarill, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SlateportCity_PokemonFanClub_Text_MeetChairman:
	.string "Khụ khụ! Ta là CHỦ TỊCH của POKéMON\n"
	.string "FAN CLUB!\p"
	.string "Là CHỦ TỊCH, đương nhiên ta là người\n"
	.string "quan trọng nhất!\p"
	.string "Không ai có thể vượt qua ta trong việc\n"
	.string "nuôi dưỡng POKéMON. Không một ai!\p"
	.string "Để ta kể cho cậu nghe về POKéMON\n"
	.string "CONTESTS.\p"
	.string "Đó là những sự kiện cho phép mọi người\n"
	.string "khoe POKéMON của mình với cả thế giới!\p"
	.string "Tuy nhiên, chúng được tổ chức tại\n"
	.string "những thị trấn xa xôi nên ta không thể\l"
	.string "tham gia thường xuyên.\p"
	.string "Vì thế, chúng ta tụ họp ở đây để khoe\n"
	.string "POKéMON của mình và ngắm POKéMON của\l"
	.string "người khác.$"

SlateportCity_PokemonFanClub_Text_LikeToSeeEnteredContestPokemon:
	.string "POKéMON của một HLV từng tham gia\n"
	.string "POKéMON CONTEST... Ta rất muốn được\l"
	.string "tận mắt chứng kiến.$"

SlateportCity_PokemonFanClub_Text_AllowMeToExamineYourPokemon:
	.string "Khụ khụ! Ta thấy cậu đã tham gia\n"
	.string "POKéMON CONTEST!\p"
	.string "Xin hãy cho phép ta xem cậu đã nuôi\n"
	.string "dưỡng POKéMON của mình thế nào.\p"
	.string "Ta vui sướng vô cùng khi được ngắm\n"
	.string "những POKéMON do các HLV khác\l"
	.string "nuôi dưỡng.\p"
	.string "Vẻ mặt hạnh phúc của những POKéMON\n"
	.string "được chăm sóc chu đáo...\p"
	.string "Ánh mắt hiền hậu của HLV đã chăm\n"
	.string "chút và nuôi dưỡng POKéMON...\p"
	.string "Chỉ nghĩ đến thôi cũng khiến trái tim ta\n"
	.string "ngập tràn niềm vui.\p"
	.string "Ô! Ta thật thất lễ! Xin thứ lỗi vì ta đã\n"
	.string "thao thao bất tuyệt!\p"
	.string "Xin hãy cho phép ta xem POKéMON của cậu\n"
	.string "đã trưởng thành đến mức nào!$"

SlateportCity_PokemonFanClub_Text_HowIsYourPokemonGrowing:
	.string "POKéMON của cậu trưởng thành thế nào\n"
	.string "rồi? Hãy để ta xem thử.$"

SlateportCity_PokemonFanClub_Text_HmHmISee:
	.string "Hừm, hừm... Ta hiểu rồi...$"

SlateportCity_PokemonFanClub_Text_GiveMonMorePokeblocks:
	.string "Hừm... Không tệ, nhưng cũng chưa tốt...\p"
	.string "Cậu, với tư cách HLV, phải cố gắng\n"
	.string "hơn nữa để nuôi dưỡng POKéMON này!\p"
	.string "Chẳng hạn, ta đề nghị cậu cho nó dùng\n"
	.string "thêm {POKEBLOCK}S nhé?$"

SlateportCity_PokemonFanClub_Text_NoSpaceForReward:
	.string "Ôi chao...\p"
	.string "POKéMON của cậu đang trưởng thành rất\n"
	.string "tốt, nên cậu xứng đáng nhận phần\l"
	.string "thưởng.\p"
	.string "Tiếc là TÚI ĐỒ của cậu không còn chỗ\n"
	.string "chứa vật này.$"

SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis:
	.string "{STR_VAR_1} của cậu đang trưởng\n"
	.string "thành cực kỳ ấn tượng! Quả là một cá\l"
	.string "thể xuất sắc!\p"
	.string "Nhưng! Nếu cậu cho nó dùng thứ này, nó\n"
	.string "sẽ còn trưởng thành tốt hơn nữa! Đúng\l"
	.string "vậy!$"

SlateportCity_PokemonFanClub_Text_ExplainRedScarf:
	.string "Hãy để một POKéMON giữ RED SCARF.\p"
	.string "Mọi người sẽ nhận ra vẻ phong độ của\n"
	.string "POKéMON đó!$"

SlateportCity_PokemonFanClub_Text_ExplainBlueScarf:
	.string "Hãy để một POKéMON giữ BLUE SCARF.\p"
	.string "Vẻ đẹp của nó sẽ nổi bật hơn bây giờ\n"
	.string "rất nhiều!$"

SlateportCity_PokemonFanClub_Text_ExplainPinkScarf:
	.string "Hãy để một POKéMON giữ PINK SCARF.\p"
	.string "Vẻ đáng yêu của POKéMON đó sẽ được\n"
	.string "thể hiện rõ hơn!$"

SlateportCity_PokemonFanClub_Text_ExplainGreenScarf:
	.string "Hãy để một POKéMON giữ GREEN SCARF.\p"
	.string "Nó sẽ làm tăng vẻ thông minh của\n"
	.string "POKéMON!$"

SlateportCity_PokemonFanClub_Text_ExplainYellowScarf:
	.string "Hãy để một POKéMON giữ YELLOW SCARF.\p"
	.string "Nó sẽ làm tăng đáng kể vẻ cứng cỏi của\n"
	.string "POKéMON!$"

SlateportCity_PokemonFanClub_Text_NothingElseToGiveYou:
	.string "Ta xin lỗi, nhưng chẳng còn gì khác để\n"
	.string "tặng cậu nữa! Hoàn toàn không còn!\p"
	.string "Dù sao, cậu cũng có tài nuôi dưỡng\n"
	.string "POKéMON mà chẳng cần nhờ đến bất kỳ\l"
	.string "vật phẩm nào!$"

SlateportCity_PokemonFanClub_Text_ShowMePokemonThatLoveYou:
	.string "Tôi rất thích ngắm những POKéMON yêu\n"
	.string "quý HLV của mình.\p"
	.string "POKéMON rất nhạy cảm với tình cảm của\n"
	.string "HLV.\p"
	.string "Nếu bạn đối xử với POKéMON bằng tình\n"
	.string "yêu và sự quan tâm, chúng cũng sẽ yêu\l"
	.string "quý bạn.\p"
	.string "Khi POKéMON đã thật sự yêu quý bạn, hãy\n"
	.string "đến cho tôi xem nhé.$"

SlateportCity_PokemonFanClub_Text_PokemonAdoresYou:
	.string "POKéMON của bạn thật sự rất yêu quý\n"
	.string "bạn.\p"
	.string "Đây là món quà từ FAN CLUB dành cho một\n"
	.string "HLV giàu lòng yêu thương như bạn!$"

SlateportCity_PokemonFanClub_Text_TreatPokemonWithLove:
	.string "POKéMON rất nhạy cảm với tình cảm của\n"
	.string "HLV.\p"
	.string "Nếu bạn đối xử với POKéMON bằng tình\n"
	.string "yêu và sự quan tâm, chúng cũng sẽ yêu\l"
	.string "quý bạn.$"

SlateportCity_PokemonFanClub_Text_PokemonDontLikeFainting:
	.string "Nếu bạn cứ để một POKéMON gục ngã\n"
	.string "trong trận đấu, nó sẽ dần oán ghét điều\l"
	.string "đó.\p"
	.string "Chẳng bao lâu, nó sẽ không còn tin\n"
	.string "tưởng HLV của mình như trước.\p"
	.string "Nói cách khác, nó chắc chắn sẽ không\n"
	.string "yêu quý bạn cho lắm.$"

SlateportCity_PokemonFanClub_Text_MonEnjoyedProtein:
	.string "POKéMON có thích được dùng vật phẩm\n"
	.string "lên mình không nhỉ?\p"
	.string "POKéMON của tôi tỏ ra rất vui khi tôi\n"
	.string "cho nó dùng PROTEIN.$"

SlateportCity_PokemonFanClub_Text_Skitty:
	.string "SKITTY: Fffnyaaaah...$"

SlateportCity_PokemonFanClub_Text_Zigzagoon:
	.string "ZIGZAGOON: Kyuuu...$"

SlateportCity_PokemonFanClub_Text_Azumarill:
	.string "AZUMARILL: Marimari?$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global SlateportCity_PokemonFanClub_Text_MeetChairman
	.global SlateportCity_PokemonFanClub_Text_LikeToSeeEnteredContestPokemon
	.global SlateportCity_PokemonFanClub_Text_AllowMeToExamineYourPokemon
	.global SlateportCity_PokemonFanClub_Text_HowIsYourPokemonGrowing
	.global SlateportCity_PokemonFanClub_Text_HmHmISee
	.global SlateportCity_PokemonFanClub_Text_GiveMonMorePokeblocks
	.global SlateportCity_PokemonFanClub_Text_NoSpaceForReward
	.global SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis
	.global SlateportCity_PokemonFanClub_Text_ExplainRedScarf
	.global SlateportCity_PokemonFanClub_Text_ExplainBlueScarf
	.global SlateportCity_PokemonFanClub_Text_ExplainPinkScarf
	.global SlateportCity_PokemonFanClub_Text_ExplainGreenScarf
	.global SlateportCity_PokemonFanClub_Text_ExplainYellowScarf
	.global SlateportCity_PokemonFanClub_Text_NothingElseToGiveYou
	.global SlateportCity_PokemonFanClub_Text_ShowMePokemonThatLoveYou
	.global SlateportCity_PokemonFanClub_Text_PokemonAdoresYou
	.global SlateportCity_PokemonFanClub_Text_TreatPokemonWithLove
	.global SlateportCity_PokemonFanClub_Text_PokemonDontLikeFainting
	.global SlateportCity_PokemonFanClub_Text_MonEnjoyedProtein
	.global SlateportCity_PokemonFanClub_Text_Skitty
	.global SlateportCity_PokemonFanClub_Text_Zigzagoon
@ END GENERATED LOCALIZATION EXPORTS
