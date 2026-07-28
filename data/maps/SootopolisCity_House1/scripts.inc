SootopolisCity_House1_MapScripts::
	.byte 0

SootopolisCity_House1_EventScript_BrickBreakBlackBelt::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_BRICK_BREAK, SootopolisCity_House1_EventScript_ReceivedBrickBreak
	msgbox SootopolisCity_House1_Text_DevelopedThisTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_BRICK_BREAK
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_BRICK_BREAK
	msgbox SootopolisCity_House1_Text_ExplainBrickBreak, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House1_EventScript_ReceivedBrickBreak::
	msgbox SootopolisCity_House1_Text_ExplainBrickBreak, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House1_EventScript_Kecleon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_KECLEON, CRY_MODE_NORMAL
	msgbox SootopolisCity_House1_Text_Kecleon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SootopolisCity_House1_Text_DevelopedThisTM:
	.string "Suốt ba mươi năm, ta ở lại SOOTOPOLIS\n"
	.string "để mài giũa kỹ năng.\p"
	.string "Ta đã tạo ra một TM có sức công phá\n"
	.string "kinh hoàng. Giờ ta truyền lại nó cho\l"
	.string "ngươi!$"

SootopolisCity_House1_Text_ExplainBrickBreak:
	.string "TM31 chứa BRICK BREAK! Đó là một chiêu\n"
	.string "khủng khiếp đến mức ta không thể diễn\l"
	.string "tả nổi.$"

SootopolisCity_House1_Text_Kecleon:
	.string "KECLEON: Puu puhyaah.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global SootopolisCity_House1_Text_DevelopedThisTM
	.global SootopolisCity_House1_Text_ExplainBrickBreak
@ END GENERATED LOCALIZATION EXPORTS
