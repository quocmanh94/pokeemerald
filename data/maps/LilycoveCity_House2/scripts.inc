LilycoveCity_House2_MapScripts::
	.byte 0

LilycoveCity_House2_EventScript_FatMan::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_REST, LilycoveCity_House2_EventScript_ReceivedRest
	msgbox LilycoveCity_House2_Text_NotAwakeYetHaveThis, MSGBOX_DEFAULT
	giveitem ITEM_TM_REST
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_REST
	msgbox LilycoveCity_House2_Text_SleepIsEssential, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House2_EventScript_ReceivedRest::
	msgbox LilycoveCity_House2_Text_SleepIsEssential, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House2_Text_NotAwakeYetHaveThis:
	.string "Hả? Gì cơ? Cái gì vậy?\p"
	.string "Tôi vẫn chưa tỉnh ngủ hẳn... Cái này cho\n"
	.string "bạn...$"

LilycoveCity_House2_Text_SleepIsEssential:
	.string "Ngáp...\p"
	.string "Ngủ rất cần thiết để có sức khỏe tốt...\n"
	.string "Hãy ngủ để hồi phục sức khỏe...$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global LilycoveCity_House2_Text_NotAwakeYetHaveThis
	.global LilycoveCity_House2_Text_SleepIsEssential
@ END GENERATED LOCALIZATION EXPORTS
