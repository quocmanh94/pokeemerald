AquaHideout_1F_MapScripts::
	.byte 0

@ The below two entrance guards give hints about what to do to progress the story
AquaHideout_1F_EventScript_HideoutEntranceGrunt1::
	lock
	faceplayer
	goto_if_set FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT, AquaHideout_1F_EventScript_SlateportHint1
	goto_if_set FLAG_RECEIVED_RED_OR_BLUE_ORB, AquaHideout_1F_EventScript_MagmaHideoutHint1
	msgbox AquaHideout_1F_Text_OurBossIsSnatchingSomething, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_MagmaHideoutHint1::
	msgbox AquaHideout_1F_Text_WhereMightMagmaHideoutBe, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_SlateportHint1::
	msgbox AquaHideout_1F_Text_BossWentToJackASubmarine, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_HideoutEntranceGrunt2::
	lock
	faceplayer
	goto_if_set FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT, AquaHideout_1F_EventScript_SlateportHint2
	goto_if_set FLAG_RECEIVED_RED_OR_BLUE_ORB, AquaHideout_1F_EventScript_MagmaHideoutHint2
	msgbox AquaHideout_1F_Text_BossIsOnRoute122, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_MagmaHideoutHint2::
	msgbox AquaHideout_1F_Text_TeamMagmaAtMtChimney, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_SlateportHint2::
	msgbox AquaHideout_1F_Text_BossIsInSlateportCity, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_1, AquaHideout_1F_Text_Grunt1Intro, AquaHideout_1F_Text_Grunt1Defeat, AquaHideout_1F_EventScript_Grunt1Defeated
	msgbox AquaHideout_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_1F_EventScript_Grunt1Defeated::
	msgbox AquaHideout_1F_Text_Grunt1PostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_Text_OurBossIsSnatchingSomething:
	.string "Gì? Gì? Bạn muốn gì ở TEAM AQUA?\p"
	.string "Thủ lĩnh chúng tôi vắng mặt! Ông ấy\n"
	.string "đi cướp một thứ quan trọng rồi!\p"
	.string "... ... Ông ấy đi đâu ư?\p"
	.string "Wahaha! Bạn thật sự nghĩ tôi sẽ nói cho\n"
	.string "bạn chuyện quan trọng đến thế sao?$"

AquaHideout_1F_Text_WhereMightMagmaHideoutBe:
	.string "Gì? Gì? Bạn là lính quèn của TEAM MAGMA\n"
	.string "à?\p"
	.string "Tôi nghe nói TEAM MAGMA đang định đánh\n"
	.string "thức một POKéMON hùng mạnh tại\l"
	.string "HIDEOUT của chúng.\p"
	.string "Nhưng HIDEOUT đó có thể ở đâu nhỉ?$"

AquaHideout_1F_Text_BossWentToJackASubmarine:
	.string "Gì? Gì? Bạn muốn gì ở TEAM AQUA?\p"
	.string "Thủ lĩnh chúng tôi vắng mặt! Ông ấy\n"
	.string "đi cướp một chiếc tàu ngầm rồi!\p"
	.string "... ... Ông ấy đi đâu ư?\p"
	.string "Wahaha! Bạn thật sự nghĩ tôi sẽ nói cho\n"
	.string "bạn chuyện quan trọng đến thế sao?$"

AquaHideout_1F_Text_BossIsOnRoute122:
	.string "Gì? Gì? Bạn muốn gì ở TEAM AQUA?\p"
	.string "Thủ lĩnh chúng tôi vắng mặt! Ông ấy\n"
	.string "đang trên đường đến MT. PYRE ở ROUTE\l"
	.string "122!\p"
	.string "... ... Tại sao ông ấy đến đó ư?\p"
	.string "Wahaha! Bạn thật sự nghĩ tôi sẽ nói cho\n"
	.string "bạn chuyện quan trọng đến thế sao?$"

AquaHideout_1F_Text_TeamMagmaAtMtChimney:
	.string "Gì? Gì? Bạn là lính quèn của TEAM MAGMA\n"
	.string "à?\p"
	.string "Tôi nghe nói TEAM MAGMA đang nhắm tới\n"
	.string "một POKéMON hùng mạnh ở MT. CHIMNEY.\p"
	.string "Nhưng POKéMON đó trông như thế nào\n"
	.string "nhỉ?$"

AquaHideout_1F_Text_BossIsInSlateportCity:
	.string "Gì? Gì? Bạn muốn gì ở TEAM AQUA?\p"
	.string "Thủ lĩnh chúng tôi vắng mặt! Ông ấy\n"
	.string "đang trên đường đến SLATEPORT CITY!\p"
	.string "... ... Tại sao ông ấy đến đó ư?\p"
	.string "Wahaha! Bạn thật sự nghĩ tôi sẽ nói cho\n"
	.string "bạn chuyện quan trọng đến thế sao?$"

AquaHideout_1F_Text_Grunt1Intro:
	.string "Ái chà chà! Phát hiện nhân vật khả nghi!$"

AquaHideout_1F_Text_Grunt1Defeat:
	.string "Grrrrr... Tôi thua mất rồi!$"

AquaHideout_1F_Text_Grunt1PostBattle:
	.string "Tôi đã chịu thua vì TEAM, nhưng cũng\n"
	.string "hoàn thành nhiệm vụ...$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global AquaHideout_1F_Text_OurBossIsSnatchingSomething
	.global AquaHideout_1F_Text_WhereMightMagmaHideoutBe
	.global AquaHideout_1F_Text_BossWentToJackASubmarine
	.global AquaHideout_1F_Text_BossIsOnRoute122
	.global AquaHideout_1F_Text_TeamMagmaAtMtChimney
	.global AquaHideout_1F_Text_BossIsInSlateportCity
	.global AquaHideout_1F_Text_Grunt1Intro
	.global AquaHideout_1F_Text_Grunt1Defeat
	.global AquaHideout_1F_Text_Grunt1PostBattle
@ END GENERATED LOCALIZATION EXPORTS
