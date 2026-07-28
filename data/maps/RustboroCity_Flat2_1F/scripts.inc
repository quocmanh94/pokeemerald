RustboroCity_Flat2_1F_MapScripts::
	.byte 0

RustboroCity_Flat2_1F_EventScript_OldWoman::
	msgbox RustboroCity_Flat2_1F_Text_DevonWorkersLiveHere, MSGBOX_NPC
	end

RustboroCity_Flat2_1F_EventScript_Skitty::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SKITTY, CRY_MODE_NORMAL
	msgbox RustboroCity_Flat2_1F_Text_Skitty, MSGBOX_DEFAULT
	waitmoncry
	release
	end

RustboroCity_Flat2_1F_Text_DevonWorkersLiveHere:
	.string "Các nhân viên của DEVON CORPORATION\n"
	.string "sống trong tòa nhà này.$"

RustboroCity_Flat2_1F_Text_Skitty:
	.string "SKITTY: Gyaaaah!$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global RustboroCity_Flat2_1F_Text_DevonWorkersLiveHere
@ END GENERATED LOCALIZATION EXPORTS
