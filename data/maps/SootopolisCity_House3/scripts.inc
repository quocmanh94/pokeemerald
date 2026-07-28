SootopolisCity_House3_MapScripts::
	.byte 0

SootopolisCity_House3_EventScript_Woman::
	lock
	faceplayer
	msgbox SootopolisCity_House3_Text_JuanHasManyFansDoYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SootopolisCity_House3_EventScript_HaveFans
	msgbox SootopolisCity_House3_Text_LonesomeTryWorkingHarder, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House3_EventScript_HaveFans::
	msgbox SootopolisCity_House3_Text_YouMustBePrettyStrong, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House3_EventScript_Girl::
	msgbox SootopolisCity_House3_Text_TrainerFanClubWasWild, MSGBOX_NPC
	end

SootopolisCity_House3_Text_JuanHasManyFansDoYou:
	.string "Bạn là HLV POKéMON, đúng không?\p"
	.string "JUAN của SOOTOPOLIS có rất nhiều\n"
	.string "người hâm mộ. Thậm chí còn nhiều hơn\l"
	.string "học trò WALLACE của ông ấy!\p"
	.string "Bạn có người hâm mộ nào không?$"

SootopolisCity_House3_Text_YouMustBePrettyStrong:
	.string "Ồ, vậy thì hẳn bạn khá mạnh.$"

SootopolisCity_House3_Text_LonesomeTryWorkingHarder:
	.string "Ôi trời... Nghe hơi cô đơn nhỉ.\p"
	.string "Hãy cố gắng thêm một chút để có được\n"
	.string "những người hâm mộ nhé.$"

SootopolisCity_House3_Text_TrainerFanClubWasWild:
	.string "Những người hâm mộ cuồng nhiệt còn\n"
	.string "tìm đến từ bên ngoài HOENN.\p"
	.string "Lần tôi tới TRAINER FAN CLUB ở\n"
	.string "LILYCOVE, nơi đó náo nhiệt kinh khủng.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global SootopolisCity_House3_Text_JuanHasManyFansDoYou
	.global SootopolisCity_House3_Text_YouMustBePrettyStrong
	.global SootopolisCity_House3_Text_LonesomeTryWorkingHarder
	.global SootopolisCity_House3_Text_TrainerFanClubWasWild
@ END GENERATED LOCALIZATION EXPORTS
