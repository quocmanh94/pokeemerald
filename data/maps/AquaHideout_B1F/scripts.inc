AquaHideout_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, AquaHideout_B1F_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, AquaHideout_B1F_OnTransition
	.byte 0

AquaHideout_B1F_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, AquaHideout_B1F_EventScript_TryRemoveElectrode
	end

AquaHideout_B1F_EventScript_TryRemoveElectrode::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

AquaHideout_B1F_OnTransition:
	call_if_unset FLAG_DEFEATED_ELECTRODE_1_AQUA_HIDEOUT, AquaHideout_B1F_EventScript_ShowElectrode1
	call_if_unset FLAG_DEFEATED_ELECTRODE_2_AQUA_HIDEOUT, AquaHideout_B1F_EventScript_ShowElectrode2
	end

AquaHideout_B1F_EventScript_ShowElectrode1::
	clearflag FLAG_HIDE_AQUA_HIDEOUT_B1F_ELECTRODE_1
	return

AquaHideout_B1F_EventScript_ShowElectrode2::
	clearflag FLAG_HIDE_AQUA_HIDEOUT_B1F_ELECTRODE_2
	return

AquaHideout_B1F_EventScript_Electrode1::
	lock
	faceplayer
	setwildbattle SPECIES_ELECTRODE, 30
	waitse
	playmoncry SPECIES_ELECTRODE, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, AquaHideout_B1F_EventScript_DefeatedElectrode1
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, AquaHideout_B1F_EventScript_DefeatedElectrode1
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, AquaHideout_B1F_EventScript_DefeatedElectrode1
	setflag FLAG_DEFEATED_ELECTRODE_1_AQUA_HIDEOUT
	release
	end

AquaHideout_B1F_EventScript_DefeatedElectrode1::
	setflag FLAG_DEFEATED_ELECTRODE_1_AQUA_HIDEOUT
	goto Common_EventScript_RemoveStaticPokemon
	end

AquaHideout_B1F_EventScript_Electrode2::
	lock
	faceplayer
	setwildbattle SPECIES_ELECTRODE, 30
	waitse
	playmoncry SPECIES_ELECTRODE, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, AquaHideout_B1F_EventScript_DefeatedElectrode2
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, AquaHideout_B1F_EventScript_DefeatedElectrode2
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, AquaHideout_B1F_EventScript_DefeatedElectrode2
	setflag FLAG_DEFEATED_ELECTRODE_2_AQUA_HIDEOUT
	release
	end

AquaHideout_B1F_EventScript_DefeatedElectrode2::
	setflag FLAG_DEFEATED_ELECTRODE_2_AQUA_HIDEOUT
	goto Common_EventScript_RemoveStaticPokemon
	end

AquaHideout_B1F_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_2, AquaHideout_B1F_Text_Grunt2Intro, AquaHideout_B1F_Text_Grunt2Defeat, AquaHideout_B1F_EventScript_Grunt2Defeated
	msgbox AquaHideout_B1F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B1F_EventScript_Grunt2Defeated::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox AquaHideout_B1F_Text_Grunt2PostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_B1F_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_3, AquaHideout_B1F_Text_Grunt3Intro, AquaHideout_B1F_Text_Grunt3Defeat, AquaHideout_B1F_EventScript_Grunt3Defeated
	msgbox AquaHideout_B1F_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B1F_EventScript_Grunt3Defeated::
	msgbox AquaHideout_B1F_Text_Grunt3PostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_B1F_EventScript_Grunt5::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_5, AquaHideout_B1F_Text_Grunt5Intro, AquaHideout_B1F_Text_Grunt5Defeat
	msgbox AquaHideout_B1F_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B1F_EventScript_Grunt7::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_7, AquaHideout_B1F_Text_Grunt7Intro, AquaHideout_B1F_Text_Grunt7Defeat
	msgbox AquaHideout_B1F_Text_Grunt7PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B1F_Text_Grunt2Intro:
	.string "Nếu muốn biết bí mật về HIDEOUT của\n"
	.string "chúng tôi, trước hết bạn phải đánh bại\l"
	.string "tôi!$"

AquaHideout_B1F_Text_Grunt2Defeat:
	.string "Tôi hoàn toàn không thắng nổi...$"

AquaHideout_B1F_Text_Grunt2PostBattle:
	.string "Bí mật của HIDEOUT ư?\p"
	.string "Chà, chỉ có thể nói là... Ở tận cùng có\n"
	.string "một chiếc tàu ngầm!\p"
	.string "Nhưng đến lúc này thì... Kekekeke...$"

AquaHideout_B1F_Text_Grunt3Intro:
	.string "Nhiên liệu đã nạp A-OK! Đồ ăn vặt cho\n"
	.string "chuyến đi đã nạp A-OK!\p"
	.string "Giờ chỉ còn KO kẻ phá đám phiền phức\n"
	.string "này thôi!$"

AquaHideout_B1F_Text_Grunt3Defeat:
	.string "Tôi bị đánh cho một trận ra trò!$"

AquaHideout_B1F_Text_Grunt3PostBattle:
	.string "Hừ! Mọi chuyện đúng như dự tính!\p"
	.string "Nhiệm vụ của tôi chỉ là cầm chân bạn\n"
	.string "thôi!$"

AquaHideout_B1F_Text_Grunt5Intro:
	.string "Ngáp... Canh gác HIDEOUT chán quá. Tôi\n"
	.string "đấu với bạn vậy.$"

AquaHideout_B1F_Text_Grunt5Defeat:
	.string "Ngáp... Ồ, tôi thua rồi...$"

AquaHideout_B1F_Text_Grunt5PostBattle:
	.string "Nếu cứ chạy nháo nhào như thế, bạn có\n"
	.string "thể bị các thành viên TEAM AQUA khác\l"
	.string "tóm đấy.$"

AquaHideout_B1F_Text_Grunt7Intro:
	.string "Này! Bạn kia!\p"
	.string "Bạn thấy bộ đồng phục nào ngầu hơn?\n"
	.string "Của TEAM AQUA hay TEAM MAGMA?$"

AquaHideout_B1F_Text_Grunt7Defeat:
	.string "Tôi đã thua một cách thật ngầu...$"

AquaHideout_B1F_Text_Grunt7PostBattle:
	.string "Có bộ đồng phục ngầu thì dù thua trông\n"
	.string "vẫn oách, bạn thấy đúng không?$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global AquaHideout_B1F_Text_Grunt2Intro
	.global AquaHideout_B1F_Text_Grunt2Defeat
	.global AquaHideout_B1F_Text_Grunt2PostBattle
	.global AquaHideout_B1F_Text_Grunt3Intro
	.global AquaHideout_B1F_Text_Grunt3Defeat
	.global AquaHideout_B1F_Text_Grunt3PostBattle
	.global AquaHideout_B1F_Text_Grunt5Intro
	.global AquaHideout_B1F_Text_Grunt5Defeat
	.global AquaHideout_B1F_Text_Grunt5PostBattle
	.global AquaHideout_B1F_Text_Grunt7Intro
	.global AquaHideout_B1F_Text_Grunt7Defeat
	.global AquaHideout_B1F_Text_Grunt7PostBattle
@ END GENERATED LOCALIZATION EXPORTS
