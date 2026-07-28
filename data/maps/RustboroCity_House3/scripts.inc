RustboroCity_House3_MapScripts::
	.byte 0

RustboroCity_House3_EventScript_OldMan::
	msgbox RustboroCity_House3_Text_IGivePerfectlySuitedNicknames, MSGBOX_NPC
	end

RustboroCity_House3_EventScript_OldWoman::
	msgbox RustboroCity_House3_Text_NamingPikachuPekachu, MSGBOX_NPC
	end

@ Misspelling on purpose, see nickname
RustboroCity_House3_EventScript_Pekachu::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIKACHU, CRY_MODE_NORMAL
	msgbox RustboroCity_House3_Text_Pekachu, MSGBOX_DEFAULT
	waitmoncry
	release
	end

RustboroCity_House3_Text_IGivePerfectlySuitedNicknames:
	.string "Tôi luôn đặt cho POKéMON của mình\n"
	.string "những biệt danh hoàn toàn phù hợp!\p"
	.string "Đó là cách tôi thể hiện, ờ... sự độc đáo,\n"
	.string "đúng rồi, chính là thế!$"

RustboroCity_House3_Text_NamingPikachuPekachu:
	.string "Nhưng đặt tên PEKACHU cho một PIKACHU\n"
	.string "ư? Có vẻ chẳng để làm gì cả.\p"
	.string "Dùng một cái tên dễ hiểu cũng tốt,\n"
	.string "nhưng...$"

RustboroCity_House3_Text_Pekachu:
	.string "PEKACHU: Peka!$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global RustboroCity_House3_Text_IGivePerfectlySuitedNicknames
	.global RustboroCity_House3_Text_NamingPikachuPekachu
@ END GENERATED LOCALIZATION EXPORTS
