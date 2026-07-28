LilycoveCity_House3_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_House3_OnTransition
	.byte 0

LilycoveCity_House3_OnTransition:
	random 4
	copyvar VAR_TEMP_1, VAR_RESULT
	end

LilycoveCity_House3_EventScript_PokefanF::
	lock
	faceplayer
	msgbox LilycoveCity_House3_Text_LearnFromMasterOfPokeblocks, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LilycoveCity_House3_EventScript_DeclinePokeblockLearn
	msgbox LilycoveCity_House3_Text_ExplainPokeblocks, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_House3_EventScript_DeclinePokeblockLearn::
	msgbox LilycoveCity_House3_Text_OhAreYouSure, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_House3_EventScript_Man::
	lock
	faceplayer
	msgbox LilycoveCity_House3_Text_HappyToHaveQuadruplets, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_House3_EventScript_GameBoyKid1::
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_GameBoyKid2::
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_GameBoyKid3::
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_GameBoyKid4::
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_WereDoingMultiBattle::
	msgbox LilycoveCity_House3_Text_GoingToWinMultiBattles, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_EventScript_WereMixingRecords::
	msgbox LilycoveCity_House3_Text_LikeMixingAtRecordCorner, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_EventScript_WereBlendingBerries::
	msgbox LilycoveCity_House3_Text_MakePokeblocksWithBerryBlender, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_EventScript_WereDoingContest::
	msgbox LilycoveCity_House3_Text_GoingToEnterContest, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_Text_LearnFromMasterOfPokeblocks:
	.string "Ôi trời! Cháu đi du lịch một mình sao?\n"
	.string "Nhưng cháu còn nhỏ thế này! Giỏi lắm!\p"
	.string "Các con của bà chắc chắn có thể học\n"
	.string "được đôi điều từ cháu!\p"
	.string "Bà á? Bà là bậc thầy về {POKEBLOCK}S.\p"
	.string "Chỉ cần nghiêm túc một chút thôi, bà có\n"
	.string "thể pha chế ra những {POKEBLOCK}S\l"
	.string "tuyệt hảo.\p"
	.string "Cháu có muốn học từ bà, một bậc thầy về\n"
	.string "{POKEBLOCK}S không?$"

LilycoveCity_House3_Text_OhAreYouSure:
	.string "Ồ? Cháu chắc chứ?\p"
	.string "Đừng lúc nào cũng cố tự làm mọi thứ một\n"
	.string "mình, cháu nhé!$"

LilycoveCity_House3_Text_ExplainPokeblocks:
	.string "Ồ, tốt lắm! Cháu thông minh đấy! Phần\n"
	.string "này hơi dài nên hãy nghe kỹ nhé!\p"
	.string "Cháu sẵn sàng chưa?\p"
	.string "Khi xem {POKEBLOCK}S, cháu sẽ thấy\n"
	.string "chúng được đánh giá bằng chỉ số độ\l"
	.string "mịn.\p"
	.string "Chỉ số độ mịn càng thấp thì càng tốt.\n"
	.string "Đừng quên điều này!\p"
	.string "Một {POKEBLOCK} tốt có chỉ số độ mịn\n"
	.string "thấp và cấp độ cao.\p"
	.string "POKéMON cũng có thể ăn nhiều\n"
	.string "{POKEBLOCK}S tốt hơn so với loại bình\l"
	.string "thường.\p"
	.string "Và điều này rất quan trọng.\p"
	.string "Nếu muốn làm {POKEBLOCK}S mịn, hãy dùng\n"
	.string "nhiều loại BERRIES khác nhau.\p"
	.string "Đừng keo kiệt, loại BERRIES được dùng\n"
	.string "sẽ ảnh hưởng đến độ mịn của\l"
	.string "{POKEBLOCK}S.\p"
	.string "Còn một điều nữa.\p"
	.string "Càng có nhiều người trộn BERRIES thì\n"
	.string "{POKEBLOCK}S càng mịn.\p"
	.string "Vì vậy, cháu nên trò chuyện với người\n"
	.string "khác và cùng nhau làm {POKEBLOCK}S.\p"
	.string "Đó gần như là mọi điều cháu cần biết để\n"
	.string "làm ra {POKEBLOCK}S tốt.\p"
	.string "Nếu mọi người đều có POKéMON mình yêu\n"
	.string "quý, những {POKEBLOCK}S mịn và một gia\l"
	.string "đình yêu thương, thế giới sẽ hạnh phúc\l"
	.string "hơn.\p"
	.string "Đừng bỏ cuộc nhé, cháu!$"

LilycoveCity_House3_Text_HappyToHaveQuadruplets:
	.string "Khi vợ tôi sinh bốn, tôi thật sự rất sốc.\p"
	.string "Nhưng giờ đây, nhìn các con chơi cùng\n"
	.string "nhau khiến tôi cảm thấy hạnh phúc.$"

LilycoveCity_House3_Text_GoingToWinMultiBattles:
	.string "Bọn mình đang đấu MULTI BATTLES,\n"
	.string "nhưng mình biết chắc mình sẽ thắng.$"

LilycoveCity_House3_Text_LikeMixingAtRecordCorner:
	.string "Bọn mình thích trộn đủ thứ ở RECORD\n"
	.string "CORNER.\p"
	.string "Nhưng rốt cuộc thứ gì được trộn nhỉ?$"

LilycoveCity_House3_Text_MakePokeblocksWithBerryBlender:
	.string "Bọn mình sẽ dùng BERRY BLENDER để làm\n"
	.string "ra {POKEBLOCK}S siêu hạng!$"

LilycoveCity_House3_Text_GoingToEnterContest:
	.string "Tôi muốn khoe POKéMON của mình cứng\n"
	.string "cỏi đến mức nào, nên cả hai sẽ cùng\l"
	.string "tham gia một cuộc thi.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global LilycoveCity_House3_Text_LearnFromMasterOfPokeblocks
	.global LilycoveCity_House3_Text_OhAreYouSure
	.global LilycoveCity_House3_Text_ExplainPokeblocks
	.global LilycoveCity_House3_Text_HappyToHaveQuadruplets
	.global LilycoveCity_House3_Text_GoingToWinMultiBattles
	.global LilycoveCity_House3_Text_LikeMixingAtRecordCorner
	.global LilycoveCity_House3_Text_MakePokeblocksWithBerryBlender
	.global LilycoveCity_House3_Text_GoingToEnterContest
@ END GENERATED LOCALIZATION EXPORTS
