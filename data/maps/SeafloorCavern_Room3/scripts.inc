SeafloorCavern_Room3_MapScripts::
	.byte 0

SeafloorCavern_Room3_EventScript_Shelly::
	trainerbattle_single TRAINER_SHELLY_SEAFLOOR_CAVERN, SeafloorCavern_Room3_Text_ShellyIntro, SeafloorCavern_Room3_Text_ShellyDefeat
	msgbox SeafloorCavern_Room3_Text_ShellyPostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room3_EventScript_Grunt5::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_5, SeafloorCavern_Room3_Text_Grunt5Intro, SeafloorCavern_Room3_Text_Grunt5Defeat
	msgbox SeafloorCavern_Room3_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room3_Text_ShellyIntro:
	.string "Ahahahaha!\p"
	.string "Không có tàu ngầm mà ngươi vẫn đến\n"
	.string "được đây sao? Quả là một đứa trẻ đáng\l"
	.string "nể!\p"
	.string "Nhưng... Ta không thể để ngươi xen vào\n"
	.string "chuyện ở đây.\p"
	.string "Với lại, ta cũng muốn trả món nợ ở\n"
	.string "WEATHER INSTITUTE...\p"
	.string "Ta sẽ cho ngươi nếm chút đau đớn!\n"
	.string "Chuẩn bị chịu trận đi!$"

SeafloorCavern_Room3_Text_ShellyDefeat:
	.string "Ahahahaha!\p"
	.string "Đau quá!$"

SeafloorCavern_Room3_Text_ShellyPostBattle:
	.string "Ahahahaha! Ngươi mạnh kinh khủng.\p"
	.string "Thật đáng tiếc khi ngươi không phải\n"
	.string "thành viên của TEAM AQUA.\p"
	.string "Nếu gia nhập bọn ta, ngươi đã có thể\n"
	.string "tận hưởng thế giới mà thủ lĩnh hứa\l"
	.string "hẹn...$"

SeafloorCavern_Room3_Text_Grunt5Intro:
	.string "Để biến giấc mơ thành hiện thực, bọn ta\n"
	.string "cần sức mạnh của POKéMON.\p"
	.string "Vậy mà kẻ thích xen vào như ngươi lại\n"
	.string "dùng sức mạnh của POKéMON để phá bọn\l"
	.string "ta ngay cả ở nơi này!\p"
	.string "Cuộc đời chẳng bao giờ diễn ra theo ý\n"
	.string "mình!$"

SeafloorCavern_Room3_Text_Grunt5Defeat:
	.string "Gwah!$"

SeafloorCavern_Room3_Text_Grunt5PostBattle:
	.string "Bọn ta không dám chất vấn mục đích của\n"
	.string "thủ lĩnh.\p"
	.string "Thế mà một nhóc ranh như ngươi lại dám\n"
	.string "đối đầu với thủ lĩnh của bọn ta.\p"
	.string "Có lẽ... Ngươi không phải hạng tầm\n"
	.string "thường...$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global SeafloorCavern_Room3_Text_ShellyIntro
	.global SeafloorCavern_Room3_Text_ShellyDefeat
	.global SeafloorCavern_Room3_Text_ShellyPostBattle
	.global SeafloorCavern_Room3_Text_Grunt5Intro
	.global SeafloorCavern_Room3_Text_Grunt5PostBattle
@ END GENERATED LOCALIZATION EXPORTS
