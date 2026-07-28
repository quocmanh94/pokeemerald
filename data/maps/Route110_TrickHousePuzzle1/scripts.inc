Route110_TrickHousePuzzle1_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Route110_TrickHousePuzzle1_OnLoad
	.byte 0

Route110_TrickHousePuzzle1_OnLoad:
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_1_STATE, 2, Route110_TrickHousePuzzle1_EventScript_OpenDoor
	end

Route110_TrickHousePuzzle1_EventScript_OpenDoor::
	setmetatile 13, 1, METATILE_TrickHousePuzzle_Stairs_Down, FALSE
	end

Route110_TrickHousePuzzle1_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_1_STATE, 0, Route110_TrickHousePuzzle1_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle1_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_1_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle1_EventScript_Sally::
	trainerbattle_single TRAINER_SALLY, Route110_TrickHousePuzzle1_Text_SallyIntro, Route110_TrickHousePuzzle1_Text_SallyDefeat
	msgbox Route110_TrickHousePuzzle1_Text_SallyPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle1_EventScript_Eddie::
	trainerbattle_single TRAINER_EDDIE, Route110_TrickHousePuzzle1_Text_EddieIntro, Route110_TrickHousePuzzle1_Text_EddieDefeat
	msgbox Route110_TrickHousePuzzle1_Text_EddiePostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle1_EventScript_Robin::
	trainerbattle_single TRAINER_ROBIN, Route110_TrickHousePuzzle1_Text_RobinIntro, Route110_TrickHousePuzzle1_Text_RobinDefeat
	msgbox Route110_TrickHousePuzzle1_Text_RobinPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle1_Text_WroteSecretCodeLockOpened::
	.string "{PLAYER} viết mật mã lên cửa.\p"
	.string "“TRICK MASTER thật tuyệt vời.” ... ... ...\n"
	.string "... ... ... ... ...\p"
	.string "Ổ khóa bật mở!$"

Route110_TrickHousePuzzle1_Text_SallyIntro:
	.string "Tôi sẽ dùng CUT vừa học, chặt phăng mọi\n"
	.string "thứ để mở đường đến chiến thắng!$"

Route110_TrickHousePuzzle1_Text_SallyDefeat:
	.string "Sao bạn nghiêm túc quá vậy?$"

Route110_TrickHousePuzzle1_Text_SallyPostBattle:
	.string "Tôi chặt chém mãi mà chẳng bao giờ\n"
	.string "chán!$"

Route110_TrickHousePuzzle1_Text_EddieIntro:
	.string "Tôi vô tình đi lạc vào ngôi nhà kỳ quặc\n"
	.string "này...$"

Route110_TrickHousePuzzle1_Text_EddieDefeat:
	.string "Giờ lại còn thua nữa...$"

Route110_TrickHousePuzzle1_Text_EddiePostBattle:
	.string "Tôi bị lạc đường, thua trận, giờ lại\n"
	.string "càng lạc hơn... Tôi không ra được...$"

Route110_TrickHousePuzzle1_Text_RobinIntro:
	.string "Rốt cuộc TRICK MASTER là ai?$"

Route110_TrickHousePuzzle1_Text_RobinDefeat:
	.string "Tôi mải suy nghĩ nên thua mất rồi!$"

Route110_TrickHousePuzzle1_Text_RobinPostBattle:
	.string "Bạn mạnh thật! Rốt cuộc bạn là ai?$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global Route110_TrickHousePuzzle1_Text_WroteSecretCodeLockOpened
	.global Route110_TrickHousePuzzle1_Text_SallyIntro
	.global Route110_TrickHousePuzzle1_Text_SallyDefeat
	.global Route110_TrickHousePuzzle1_Text_SallyPostBattle
	.global Route110_TrickHousePuzzle1_Text_EddieIntro
	.global Route110_TrickHousePuzzle1_Text_EddieDefeat
	.global Route110_TrickHousePuzzle1_Text_EddiePostBattle
	.global Route110_TrickHousePuzzle1_Text_RobinIntro
	.global Route110_TrickHousePuzzle1_Text_RobinDefeat
	.global Route110_TrickHousePuzzle1_Text_RobinPostBattle
@ END GENERATED LOCALIZATION EXPORTS
