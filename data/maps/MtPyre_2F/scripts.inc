MtPyre_2F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CaveHole_CheckFallDownHole
	map_script MAP_SCRIPT_ON_TRANSITION, CaveHole_FixCrackedGround
	map_script MAP_SCRIPT_ON_RESUME, MtPyre_2F_SetHoleWarp
	.byte 0

MtPyre_2F_SetHoleWarp:
	setstepcallback STEP_CB_CRACKED_FLOOR
	setholewarp MAP_MT_PYRE_1F
	end

MtPyre_2F_EventScript_Woman::
	msgbox MtPyre_2F_Text_MemoriesOfSkitty, MSGBOX_NPC
	end

MtPyre_2F_EventScript_PokefanM::
	msgbox MtPyre_2F_Text_TumbledFromFloorAbove, MSGBOX_NPC
	end

MtPyre_2F_EventScript_Mark::
	trainerbattle_single TRAINER_MARK, MtPyre_2F_Text_MarkIntro, MtPyre_2F_Text_MarkDefeat
	msgbox MtPyre_2F_Text_MarkPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_Luke::
	trainerbattle_double TRAINER_DEZ_AND_LUKE, MtPyre_2F_Text_LukeIntro, MtPyre_2F_Text_LukeDefeat, MtPyre_2F_Text_LukeNotEnoughMons
	msgbox MtPyre_2F_Text_LukePostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_Dez::
	trainerbattle_double TRAINER_DEZ_AND_LUKE, MtPyre_2F_Text_DezIntro, MtPyre_2F_Text_DezDefeat, MtPyre_2F_Text_DezNotEnoughMons
	msgbox MtPyre_2F_Text_DezPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_Leah::
	trainerbattle_single TRAINER_LEAH, MtPyre_2F_Text_LeahIntro, MtPyre_2F_Text_LeahDefeat
	msgbox MtPyre_2F_Text_LeahPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_Zander::
	trainerbattle_single TRAINER_ZANDER, MtPyre_2F_Text_ZanderIntro, MtPyre_2F_Text_ZanderDefeat
	msgbox MtPyre_2F_Text_ZanderPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_Text_MemoriesOfSkitty:
	.string "Những kỷ niệm về SKITTY yêu dấu của\n"
	.string "tôi... Nghĩ đến thôi là nước mắt lại trào\l"
	.string "ra.$"

MtPyre_2F_Text_TumbledFromFloorAbove:
	.string "Ui da, đau quá... Mặt đất ở đây chỗ nào\n"
	.string "cũng có lỗ.\p"
	.string "Tôi không để ý nên ngã từ tầng trên\n"
	.string "xuống.$"

MtPyre_2F_Text_MarkIntro:
	.string "Này! Bạn cũng đi tìm POKéMON à? Bạn đi\n"
	.string "theo sau tôi! Thật bất lịch sự!$"

MtPyre_2F_Text_MarkDefeat:
	.string "Ááá! Tôi xin lỗi, làm ơn tha cho tôi!$"

MtPyre_2F_Text_MarkPostBattle:
	.string "Ít người đến đây, nên tôi tưởng sẽ có\n"
	.string "POKéMON hiếm.$"

MtPyre_2F_Text_LukeIntro:
	.string "LUKE: Bọn tôi đến đây để thử gan.\p"
	.string "Hê hê, nếu cho cô ấy thấy mình ngầu thế\n"
	.string "nào, cô ấy sẽ mê tôi ngay. Chắc chắn!\p"
	.string "Biết rồi! Tôi sẽ hạ đẹp bạn và cho cô ấy\n"
	.string "thấy tôi ngầu cỡ nào!$"

MtPyre_2F_Text_LukeDefeat:
	.string "LUKE: Ôi chết!$"

MtPyre_2F_Text_LukePostBattle:
	.string "LUKE: Bọn tôi thua nhưng không sao! Anh\n"
	.string "vẫn ở ngay bên em. Chúng ta sẽ vượt\l"
	.string "qua màn thử gan này!$"

MtPyre_2F_Text_LukeNotEnoughMons:
	.string "LUKE: Muốn đấu với tôi thì hãy mang\n"
	.string "thêm POKéMON đến.\p"
	.string "Không thì tôi đâu thể cho bạn gái thấy\n"
	.string "tôi ngầu thế nào!$"

MtPyre_2F_Text_DezIntro:
	.string "DEZ: Tôi đến đây thử gan cùng bạn trai.\p"
	.string "Nơi này đáng sợ thật, nhưng có bạn\n"
	.string "trai bên cạnh nên tôi không sao.\p"
	.string "Biết rồi! Tôi sẽ giúp bạn trai mình trông\n"
	.string "thật ngầu bằng cách đánh bại bạn!$"

MtPyre_2F_Text_DezDefeat:
	.string "DEZ: Oaaa! Tôi sợ quá!$"

MtPyre_2F_Text_DezPostBattle:
	.string "DEZ: Bọn tôi yêu nhau say đắm, nên thua\n"
	.string "cũng chẳng sao!$"

MtPyre_2F_Text_DezNotEnoughMons:
	.string "DEZ: Muốn thách đấu bọn tôi thì bạn\n"
	.string "phải mang ít nhất hai POKéMON.\p"
	.string "Bạn trai tôi mạnh lắm. Chỉ một POKéMON\n"
	.string "thì hoàn toàn không đủ đâu.$"

MtPyre_2F_Text_LeahIntro:
	.string "Ngươi là kẻ lạ mặt... Hãy rời đi trước\n"
	.string "khi tai họa ập đến!$"

MtPyre_2F_Text_LeahDefeat:
	.string "Hừm... Ngươi cứng cỏi đấy.$"

MtPyre_2F_Text_LeahPostBattle:
	.string "Gia tộc ta đã làm HLV ở đây từ\n"
	.string "thời cụ cố...\p"
	.string "Bảo vệ ngọn núi này là bổn phận của ta...$"

MtPyre_2F_Text_ZanderIntro:
	.string "Kiaaaa! Tôi sợ chết khiếp!$"

MtPyre_2F_Text_ZanderDefeat:
	.string "Khôngggg! Tôi hoảng loạn mất rồi!$"

MtPyre_2F_Text_ZanderPostBattle:
	.string "Cứ thấy bất cứ thứ gì cử động là tôi\n"
	.string "lại hoảng hốt...\p"
	.string "Lẽ ra tôi không nên đến đây luyện tập...$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global MtPyre_2F_Text_MemoriesOfSkitty
	.global MtPyre_2F_Text_TumbledFromFloorAbove
	.global MtPyre_2F_Text_MarkIntro
	.global MtPyre_2F_Text_MarkDefeat
	.global MtPyre_2F_Text_MarkPostBattle
	.global MtPyre_2F_Text_LukeIntro
	.global MtPyre_2F_Text_LukeDefeat
	.global MtPyre_2F_Text_LukePostBattle
	.global MtPyre_2F_Text_LukeNotEnoughMons
	.global MtPyre_2F_Text_DezIntro
	.global MtPyre_2F_Text_DezDefeat
	.global MtPyre_2F_Text_DezPostBattle
	.global MtPyre_2F_Text_DezNotEnoughMons
	.global MtPyre_2F_Text_LeahIntro
	.global MtPyre_2F_Text_LeahDefeat
	.global MtPyre_2F_Text_LeahPostBattle
	.global MtPyre_2F_Text_ZanderIntro
	.global MtPyre_2F_Text_ZanderDefeat
	.global MtPyre_2F_Text_ZanderPostBattle
@ END GENERATED LOCALIZATION EXPORTS
