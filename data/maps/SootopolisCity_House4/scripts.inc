SootopolisCity_House4_MapScripts::
	.byte 0

SootopolisCity_House4_EventScript_Man::
	msgbox SootopolisCity_House4_Text_AncientTreasuresWaitingInSea, MSGBOX_NPC
	end

SootopolisCity_House4_EventScript_Woman::
	msgbox SootopolisCity_House4_Text_StrollUnderwaterWithPokemon, MSGBOX_NPC
	end

SootopolisCity_House4_EventScript_Azumarill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZUMARILL, CRY_MODE_NORMAL
	msgbox SootopolisCity_House4_Text_Azumarill, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SootopolisCity_House4_Text_AncientTreasuresWaitingInSea:
	.string "Nghe đây, tôi sẽ kể bạn một chuyện hay.\p"
	.string "Người ta nói dưới biển quanh đây có\n"
	.string "một di tích cổ.\p"
	.string "Có thể dưới đó đang có những kho báu\n"
	.string "chờ được khám phá.$"

SootopolisCity_House4_Text_StrollUnderwaterWithPokemon:
	.string "Kho báu cổ đại...\p"
	.string "Nếu chúng có thật thì tuyệt, nhưng kể\n"
	.string "cả không có, được dạo chơi dưới đáy\l"
	.string "biển cùng POKéMON của tôi cũng sẽ đẹp\l"
	.string "biết bao.$"

SootopolisCity_House4_Text_Azumarill:
	.string "AZUMARILL: Marurii.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global SootopolisCity_House4_Text_AncientTreasuresWaitingInSea
	.global SootopolisCity_House4_Text_StrollUnderwaterWithPokemon
@ END GENERATED LOCALIZATION EXPORTS
