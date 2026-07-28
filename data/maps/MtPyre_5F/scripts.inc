MtPyre_5F_MapScripts::
	.byte 0

@ Seems like the scripts for the 4F and 5F were swapped

MtPyre_4F_EventScript_Tasha::
	trainerbattle_single TRAINER_TASHA, MtPyre_4F_Text_TashaIntro, MtPyre_4F_Text_TashaDefeat
	msgbox MtPyre_4F_Text_TashaPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_4F_Text_TashaIntro:
	.string "Tôi yêu mọi thứ kinh dị... Cứ như một căn\n"
	.string "bệnh...\p"
	.string "Khi ở đây... Tôi run lên vì sợ...$"

MtPyre_4F_Text_TashaDefeat:
	.string "Tôi ghét... thua cuộc...$"

MtPyre_4F_Text_TashaPostBattle:
	.string "Tôi muốn thấy những điều khủng khiếp...\n"
	.string "Tôi không thể rời đi...\p"
	.string "Ở lại đi... Bạn không ở lại với tôi sao?$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global MtPyre_4F_Text_TashaIntro
	.global MtPyre_4F_Text_TashaDefeat
	.global MtPyre_4F_Text_TashaPostBattle
@ END GENERATED LOCALIZATION EXPORTS
