RustboroCity_Flat2_3F_MapScripts::
	.byte 0

RustboroCity_Flat2_3F_EventScript_DevonEmployee::
	msgbox RustboroCity_Flat2_3F_Text_PresidentCollectsRareStones, MSGBOX_NPC
	end

RustboroCity_Flat2_3F_EventScript_Woman::
	msgbox RustboroCity_Flat2_3F_Text_PresidentsSonAlsoCollectsRareStones, MSGBOX_NPC
	end

RustboroCity_Flat2_3F_Text_PresidentCollectsRareStones:
	.string "PRESIDENT của DEVON thích sưu tầm đá\n"
	.string "quý hiếm.$"

RustboroCity_Flat2_3F_Text_PresidentsSonAlsoCollectsRareStones:
	.string "Tôi nghĩ con trai của PRESIDENT cũng\n"
	.string "sưu tầm đá quý hiếm.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global RustboroCity_Flat2_3F_Text_PresidentCollectsRareStones
	.global RustboroCity_Flat2_3F_Text_PresidentsSonAlsoCollectsRareStones
@ END GENERATED LOCALIZATION EXPORTS
