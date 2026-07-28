RustboroCity_CuttersHouse_MapScripts::
	.byte 0

RustboroCity_CuttersHouse_EventScript_Cutter::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_CUT, RustboroCity_CuttersHouse_EventScript_ExplainCut
	msgbox RustboroCity_CuttersHouse_Text_YouCanPutThisHMToGoodUse, MSGBOX_DEFAULT
	giveitem ITEM_HM_CUT
	setflag FLAG_RECEIVED_HM_CUT
	msgbox RustboroCity_CuttersHouse_Text_ExplainCut, MSGBOX_DEFAULT
	release
	end

RustboroCity_CuttersHouse_EventScript_ExplainCut::
	msgbox RustboroCity_CuttersHouse_Text_ExplainCut, MSGBOX_DEFAULT
	release
	end

RustboroCity_CuttersHouse_EventScript_Lass::
	msgbox RustboroCity_CuttersHouse_Text_DadHelpedClearLandOfTrees, MSGBOX_NPC
	end

RustboroCity_CuttersHouse_Text_YouCanPutThisHMToGoodUse:
	.string "Ánh mắt đầy quyết tâm... Cách di chuyển\n"
	.string "linh hoạt... Và những POKéMON được rèn\l"
	.string "luyện kỹ lưỡng...\p"
	.string "Rõ ràng bạn là một HLV tài giỏi!\p"
	.string "Không, khoan, đừng nói gì cả. Chỉ nhìn\n"
	.string "bạn là tôi biết rồi.\p"
	.string "Tôi tin bạn có thể tận dụng tốt HIDDEN\n"
	.string "MACHINE này.\p"
	.string "Không cần khiêm tốn hay ngại ngùng.\n"
	.string "Nào, hãy nhận lấy!$"

RustboroCity_CuttersHouse_Text_ExplainCut:
	.string "HIDDEN MACHINE đó, gọi tắt là HM, chính\n"
	.string "là CUT.\p"
	.string "Chiêu HM là chiêu POKéMON có thể sử\n"
	.string "dụng bên ngoài trận đấu.\p"
	.string "Bất kỳ POKéMON nào đã học CUT đều có\n"
	.string "thể chặt cây nhỏ nếu HLV đã giành\l"
	.string "được STONE BADGE.\p"
	.string "Và khác với TM, HM có thể được sử dụng\n"
	.string "nhiều lần.$"

RustboroCity_CuttersHouse_Text_DadHelpedClearLandOfTrees:
	.string "Khi thành phố RUSTBORO được mở rộng,\n"
	.string "ba tôi đã góp sức.\p"
	.string "Ông cho POKéMON dùng CUT để dọn cây\n"
	.string "trên khu đất.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global RustboroCity_CuttersHouse_Text_YouCanPutThisHMToGoodUse
	.global RustboroCity_CuttersHouse_Text_ExplainCut
	.global RustboroCity_CuttersHouse_Text_DadHelpedClearLandOfTrees
@ END GENERATED LOCALIZATION EXPORTS
