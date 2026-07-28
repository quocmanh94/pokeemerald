Route109_SeashoreHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route109_SeashoreHouse_OnTransition
	.byte 0

Route109_SeashoreHouse_OnTransition:
	setflag FLAG_LANDMARK_SEASHORE_HOUSE
	end

Route109_SeashoreHouse_EventScript_Owner::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_6_SODA_POP, Route109_SeashoreHouse_EventScript_AlreadyReceivedSodaPop
	goto_if_set FLAG_DEFEATED_SEASHORE_HOUSE, Route109_SeashoreHouse_EventScript_DefeatedTrainers
	goto_if_set FLAG_TEMP_2, Route109_SeashoreHouse_EventScript_AlreadyGaveIntroduction
	msgbox Route109_SeashoreHouse_Text_SeashoreHouseIntro, MSGBOX_DEFAULT
	setflag FLAG_TEMP_2
	release
	end

Route109_SeashoreHouse_EventScript_AlreadyGaveIntroduction::
	msgbox Route109_SeashoreHouse_Text_ShowMeSomeHotMatches, MSGBOX_DEFAULT
	release
	end

Route109_SeashoreHouse_EventScript_DefeatedTrainers::
	msgbox Route109_SeashoreHouse_Text_TakeTheseSodaPopBottles, MSGBOX_DEFAULT
	giveitem ITEM_SODA_POP, 6
	goto_if_eq VAR_RESULT, FALSE, Route109_SeashoreHouse_EventScript_BagFull
	setflag FLAG_RECEIVED_6_SODA_POP
	release
	end

Route109_SeashoreHouse_EventScript_BagFull::
	msgbox Route109_SeashoreHouse_Text_BagFull, MSGBOX_DEFAULT
	release
	end

Route109_SeashoreHouse_EventScript_AlreadyReceivedSodaPop::
	showmoneybox 0, 0
	msgbox Route109_SeashoreHouse_Text_WantToBuySodaPop, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route109_SeashoreHouse_EventScript_BuySodaPop
	msgbox Route109_SeashoreHouse_Text_ThatsTooBad, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

Route109_SeashoreHouse_EventScript_BuySodaPop::
	checkmoney 300
	goto_if_eq VAR_RESULT, FALSE, Route109_SeashoreHouse_EventScript_NotEnoughMoney
	checkitemspace ITEM_SODA_POP
	goto_if_eq VAR_RESULT, FALSE, Route109_SeashoreHouse_EventScript_NotEnoughSpace
	msgbox Route109_SeashoreHouse_Text_HereYouGo, MSGBOX_DEFAULT
	removemoney 300
	updatemoneybox
	giveitem ITEM_SODA_POP
	hidemoneybox
	release
	end

Route109_SeashoreHouse_EventScript_NotEnoughMoney::
	msgbox Route109_SeashoreHouse_Text_NotEnoughMoney, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

Route109_SeashoreHouse_EventScript_NotEnoughSpace::
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

Route109_SeashoreHouse_EventScript_Dwayne::
	trainerbattle_single TRAINER_DWAYNE, Route109_SeashoreHouse_Text_DwayneIntro, Route109_SeashoreHouse_Text_DwayneDefeated, Route109_SeashoreHouse_EventScript_CheckTrainersCompletion
	msgbox Route109_SeashoreHouse_Text_DwaynePostBattle, MSGBOX_AUTOCLOSE
	end

Route109_SeashoreHouse_EventScript_Johanna::
	trainerbattle_single TRAINER_JOHANNA, Route109_SeashoreHouse_Text_JohannaIntro, Route109_SeashoreHouse_Text_JohannaDefeated, Route109_SeashoreHouse_EventScript_CheckTrainersCompletion
	msgbox Route109_SeashoreHouse_Text_JohannaPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_SeashoreHouse_EventScript_Simon::
	trainerbattle_single TRAINER_SIMON, Route109_SeashoreHouse_Text_SimonIntro, Route109_SeashoreHouse_Text_SimonDefeated, Route109_SeashoreHouse_EventScript_CheckTrainersCompletion
	msgbox Route109_SeashoreHouse_Text_SimonPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_SeashoreHouse_EventScript_CheckTrainersCompletion::
	goto_if_not_defeated TRAINER_DWAYNE, Route109_SeashoreHouse_EventScript_TrainersNotCompleted
	goto_if_not_defeated TRAINER_JOHANNA, Route109_SeashoreHouse_EventScript_TrainersNotCompleted
	goto_if_not_defeated TRAINER_SIMON, Route109_SeashoreHouse_EventScript_TrainersNotCompleted
	setflag FLAG_DEFEATED_SEASHORE_HOUSE
	release
	end

Route109_SeashoreHouse_EventScript_TrainersNotCompleted::
	release
	end

Route109_SeashoreHouse_Text_SeashoreHouseIntro:
	.string "Tôi là chủ của SEASHORE HOUSE. Nhưng\n"
	.string "cậu có thể gọi tôi là MR. SEA!\p"
	.string "Điều tôi yêu thích hơn tất cả là được\n"
	.string "xem những trận POKéMON đầy máu lửa.\p"
	.string "Hãy cho tôi thấy trái tim cậu đang rực\n"
	.string "cháy!\p"
	.string "Nếu đánh bại được tất cả HLV ở\n"
	.string "đây, tôi sẽ thưởng cho nỗ lực của cậu.$"

Route109_SeashoreHouse_Text_ShowMeSomeHotMatches:
	.string "Hãy cho tôi xem những trận đấu đầy máu\n"
	.string "lửa!\p"
	.string "Tôi điều hành SEASHORE HOUSE chỉ vì\n"
	.string "mục đích đó!$"

Route109_SeashoreHouse_Text_TakeTheseSodaPopBottles:
	.string "Cậu thật sự nóng bỏng! Những trận đấu\n"
	.string "ấy rực lửa vô cùng! Tôi hài lòng hơn cả\l"
	.string "mong đợi!\p"
	.string "Để cảm ơn vì màn thể hiện đầy máu lửa\n"
	.string "đó, tôi muốn cậu nhận những thứ này.\p"
	.string "Đó là nửa tá chai SODA POP!$"

Route109_SeashoreHouse_Text_BagFull:
	.string "Ôi, TÚI ĐỒ của cậu đã đầy. Tôi sẽ giữ\n"
	.string "những thứ này giúp cậu.$"

Route109_SeashoreHouse_Text_WantToBuySodaPop:
	.string "Muốn mua SODA POP không? POKéMON mê\n"
	.string "lắm đấy!\p"
	.string "Chỉ ¥300 một chai! Mua đi!$"

Route109_SeashoreHouse_Text_HereYouGo:
	.string "Của cậu đây!$"

Route109_SeashoreHouse_Text_NotEnoughMoney:
	.string "Cậu không đủ tiền.$"

Route109_SeashoreHouse_Text_ThatsTooBad:
	.string "Không à? Tiếc thật.$"

Route109_SeashoreHouse_Text_DwayneIntro:
	.string "Nếu muốn đấu ở SEASHORE HOUSE, cậu sẽ\n"
	.string "chẳng tìm được HLV nào máu lửa\l"
	.string "hơn tôi đâu, chiến hữu!$"

Route109_SeashoreHouse_Text_DwayneDefeated:
	.string "Quả là một trận đấu nảy lửa! Tôi tâm\n"
	.string "phục khẩu phục rồi, chiến hữu!$"

Route109_SeashoreHouse_Text_DwaynePostBattle:
	.string "Mỗi khi đến SLATEPORT, tôi đều thích\n"
	.string "những trận đấu nảy lửa và SODA POP\l"
	.string "lạnh buốt!$"

Route109_SeashoreHouse_Text_JohannaIntro:
	.string "Những trận đấu tẻ nhạt không đáng để\n"
	.string "bỏ công.\p"
	.string "Chính những trận đấu nảy lửa mới rèn\n"
	.string "giũa HLV và POKéMON!$"

Route109_SeashoreHouse_Text_JohannaDefeated:
	.string "Nóng bỏng thật!$"

Route109_SeashoreHouse_Text_JohannaPostBattle:
	.string "Phù, khát khô cả cổ rồi. Chắc mình uống\n"
	.string "SODA POP thôi.$"

Route109_SeashoreHouse_Text_SimonIntro:
	.string "Tớ sẽ cho cậu thấy POKéMON của tớ\n"
	.string "tuyệt thế nào, nhưng đừng khóc nhé!$"

Route109_SeashoreHouse_Text_SimonDefeated:
	.string "...Tớ thua rồi, nhưng tớ sẽ không khóc...$"

Route109_SeashoreHouse_Text_SimonPostBattle:
	.string "Nếu một POKéMON của tớ biết chiêu cõng\n"
	.string "tớ qua mặt nước, tớ có thể bỏ cái phao\l"
	.string "này rồi.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global Route109_SeashoreHouse_Text_SeashoreHouseIntro
	.global Route109_SeashoreHouse_Text_ShowMeSomeHotMatches
	.global Route109_SeashoreHouse_Text_TakeTheseSodaPopBottles
	.global Route109_SeashoreHouse_Text_BagFull
	.global Route109_SeashoreHouse_Text_WantToBuySodaPop
	.global Route109_SeashoreHouse_Text_HereYouGo
	.global Route109_SeashoreHouse_Text_NotEnoughMoney
	.global Route109_SeashoreHouse_Text_ThatsTooBad
	.global Route109_SeashoreHouse_Text_DwayneIntro
	.global Route109_SeashoreHouse_Text_DwayneDefeated
	.global Route109_SeashoreHouse_Text_DwaynePostBattle
	.global Route109_SeashoreHouse_Text_JohannaIntro
	.global Route109_SeashoreHouse_Text_JohannaDefeated
	.global Route109_SeashoreHouse_Text_JohannaPostBattle
	.global Route109_SeashoreHouse_Text_SimonIntro
	.global Route109_SeashoreHouse_Text_SimonDefeated
	.global Route109_SeashoreHouse_Text_SimonPostBattle
@ END GENERATED LOCALIZATION EXPORTS
