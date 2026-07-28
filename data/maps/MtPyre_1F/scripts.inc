MtPyre_1F_MapScripts::
	.byte 0

MtPyre_1F_EventScript_CleanseTagWoman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_CLEANSE_TAG, MtPyre_1F_EventScript_ReceivedCleanseTag
	msgbox MtPyre_1F_Text_TakeThisForYourOwnGood, MSGBOX_DEFAULT
	giveitem ITEM_CLEANSE_TAG
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_CLEANSE_TAG
	release
	end

MtPyre_1F_EventScript_ReceivedCleanseTag::
	msgbox MtPyre_1F_Text_ExplainCleanseTag, MSGBOX_DEFAULT
	release
	end

MtPyre_1F_EventScript_PokefanF::
	msgbox MtPyre_1F_Text_ComeToPayRespects, MSGBOX_NPC
	end

MtPyre_1F_EventScript_Man::
	msgbox MtPyre_1F_Text_RestingPlaceOfZigzagoon, MSGBOX_NPC
	end

MtPyre_1F_Text_TakeThisForYourOwnGood:
	.string "Đủ loại sinh vật lang thang trên sườn\n"
	.string "MT. PYRE...\p"
	.string "Không ai biết chuyện gì có thể xảy ra.\n"
	.string "Hãy cầm lấy. Vì sự an toàn của bạn.$"

MtPyre_1F_Text_ExplainCleanseTag:
	.string "Hãy để một POKéMON cầm CLEANSE TAG đó.\p"
	.string "Nó sẽ giúp xua đuổi POKéMON hoang dã.$"

MtPyre_1F_Text_ComeToPayRespects:
	.string "Bạn đến để viếng hương hồn những\n"
	.string "POKéMON đã khuất sao?\p"
	.string "Hẳn bạn rất yêu quý POKéMON của mình.$"

MtPyre_1F_Text_RestingPlaceOfZigzagoon:
	.string "Đây là nơi ZIGZAGOON của tôi an nghỉ.\n"
	.string "Tôi từng yêu quý nó biết bao...$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global MtPyre_1F_Text_TakeThisForYourOwnGood
	.global MtPyre_1F_Text_ExplainCleanseTag
	.global MtPyre_1F_Text_ComeToPayRespects
	.global MtPyre_1F_Text_RestingPlaceOfZigzagoon
@ END GENERATED LOCALIZATION EXPORTS
