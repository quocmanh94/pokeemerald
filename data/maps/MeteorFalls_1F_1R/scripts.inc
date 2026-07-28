MeteorFalls_1F_1R_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MeteorFalls_1F_1R_OnLoad
	.byte 0

MeteorFalls_1F_1R_OnLoad:
	call_if_set FLAG_SYS_GAME_CLEAR, MeteorFalls_1F_1R_EventScript_OpenStevensCave
	end

MeteorFalls_1F_1R_EventScript_OpenStevensCave::
	setmetatile 4, 1, METATILE_MeteorFalls_CaveEntrance_Top, TRUE
	setmetatile 3, 2, METATILE_MeteorFalls_CaveEntrance_Left, TRUE
	setmetatile 4, 2, METATILE_MeteorFalls_CaveEntrance_Bottom, FALSE
	setmetatile 5, 2, METATILE_MeteorFalls_CaveEntrance_Right, TRUE
	return

MeteorFalls_1F_1R_EventScript_MagmaStealsMeteoriteScene::
	lockall
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	delay 30
	applymovement LOCALID_METEOR_FALLS_MAGMA_GRUNT_1, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_WithThisMeteorite, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_METEOR_FALLS_MAGMA_GRUNT_1, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_METEOR_FALLS_MAGMA_GRUNT_2, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_METEOR_FALLS_MAGMA_GRUNT_1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_METEOR_FALLS_MAGMA_GRUNT_1, Common_Movement_Delay48
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_DontExpectMercyFromMagma, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_METEOR_FALLS_MAGMA_GRUNT_1, MeteorFalls_1F_1R_Movement_MagmaGruntApproachPlayer
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_HoldItRightThereMagma, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_METEOR_FALLS_MAGMA_GRUNT_1, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_METEOR_FALLS_MAGMA_GRUNT_2, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	addobject LOCALID_METEOR_FALLS_ARCHIE
	addobject LOCALID_METEOR_FALLS_AQUA_GRUNT_1
	addobject LOCALID_METEOR_FALLS_AQUA_GRUNT_2
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement LOCALID_METEOR_FALLS_ARCHIE, MeteorFalls_1F_1R_Movement_ArchieArrive
	applymovement LOCALID_METEOR_FALLS_AQUA_GRUNT_1, MeteorFalls_1F_1R_Movement_AquaGrunt1Arrive
	applymovement LOCALID_METEOR_FALLS_AQUA_GRUNT_2, MeteorFalls_1F_1R_Movement_AquaGrunt2Arrive
	waitmovement 0
	applymovement LOCALID_METEOR_FALLS_MAGMA_GRUNT_1, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_METEOR_FALLS_MAGMA_GRUNT_2, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_BeSeeingYouTeamAqua, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, MeteorFalls_1F_1R_Movement_PushPlayerOutOfWay
	applymovement LOCALID_METEOR_FALLS_MAGMA_GRUNT_1, MeteorFalls_1F_1R_Movement_MagmaGrunt1Exit
	applymovement LOCALID_METEOR_FALLS_MAGMA_GRUNT_2, MeteorFalls_1F_1R_Movement_MagmaGrunt2Exit
	waitmovement 0
	removeobject LOCALID_METEOR_FALLS_MAGMA_GRUNT_1
	removeobject LOCALID_METEOR_FALLS_MAGMA_GRUNT_2
	applymovement LOCALID_METEOR_FALLS_ARCHIE, MeteorFalls_1F_1R_Movement_ArchieApproachPlayer
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_ArchieSeenYouBefore, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_METEOR_FALLS_AQUA_GRUNT_1, MeteorFalls_1F_1R_Movement_AquaGrunt1ApproachArchie
	applymovement LOCALID_METEOR_FALLS_AQUA_GRUNT_2, MeteorFalls_1F_1R_Movement_AquaGrunt2ApproachArchie
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_BossWeShouldChaseMagma, MSGBOX_DEFAULT
	applymovement LOCALID_METEOR_FALLS_ARCHIE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_ArchieYesNoTellingWhatMagmaWillDo, MSGBOX_DEFAULT
	applymovement LOCALID_METEOR_FALLS_ARCHIE, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_ArchieFarewell, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_METEOR_FALLS_ARCHIE, MeteorFalls_1F_1R_Movement_ArchieExit
	applymovement LOCALID_METEOR_FALLS_AQUA_GRUNT_1, MeteorFalls_1F_1R_Movement_AquaGrunt1Exit
	applymovement LOCALID_METEOR_FALLS_AQUA_GRUNT_2, MeteorFalls_1F_1R_Movement_AquaGrunt2Exit
	waitmovement 0
	fadedefaultbgm
	removeobject LOCALID_METEOR_FALLS_ARCHIE
	removeobject LOCALID_METEOR_FALLS_AQUA_GRUNT_1
	removeobject LOCALID_METEOR_FALLS_AQUA_GRUNT_2
	setflag FLAG_HIDE_ROUTE_112_TEAM_MAGMA
	setflag FLAG_MET_ARCHIE_METEOR_FALLS
	setflag FLAG_HIDE_FALLARBOR_TOWN_BATTLE_TENT_SCOTT
	setvar VAR_METEOR_FALLS_STATE, 1
	releaseall
	end

MeteorFalls_1F_1R_Movement_MagmaGruntApproachPlayer:
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

MeteorFalls_1F_1R_Movement_MagmaGrunt1Exit:
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

MeteorFalls_1F_1R_Movement_MagmaGrunt2Exit:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

MeteorFalls_1F_1R_Movement_ArchieArrive:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_AquaGrunt1Arrive:
	delay_16
	delay_16
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_AquaGrunt2Arrive:
	delay_16
	delay_16
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_ArchieExit:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_ArchieApproachPlayer:
	walk_right
	walk_right
	walk_up
	walk_up
	walk_in_place_faster_left
	step_end

MeteorFalls_1F_1R_Movement_AquaGrunt1Exit:
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_AquaGrunt1ApproachArchie:
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

MeteorFalls_1F_1R_Movement_AquaGrunt2Exit:
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_AquaGrunt2ApproachArchie:
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

MeteorFalls_1F_1R_Movement_PushPlayerOutOfWay:
	walk_in_place_faster_down
	delay_4
	walk_in_place_faster_right
	lock_facing_direction
	walk_left
	unlock_facing_direction
	face_right
	step_end

MeteorFalls_1F_1R_EventScript_ProfCozmo::
	lock
	faceplayer
	goto_if_set FLAG_MET_PROF_COZMO, MeteorFalls_1F_1R_EventScript_MetCozmo
	setflag FLAG_MET_PROF_COZMO
	msgbox MeteorFalls_1F_1R_Text_MeetProfCozmo, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_1R_EventScript_MetCozmo::
	msgbox MeteorFalls_1F_1R_Text_WhatsTeamMagmaDoingAtMtChimney, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_1R_Text_WithThisMeteorite:
	.string "Hehehe!\p"
	.string "Có METEORITE này, thứ đó ở MT. CHIMNEY\n"
	.string "sẽ...$"

MeteorFalls_1F_1R_Text_DontExpectMercyFromMagma:
	.string "Hả?\p"
	.string "Ta không biết ngươi là ai, nhưng nếu\n"
	.string "cản đường TEAM MAGMA thì đừng mong\l"
	.string "được nương tay!$"

MeteorFalls_1F_1R_Text_HoldItRightThereMagma:
	.string "Đứng lại đó, TEAM MAGMA!\p"
	.string "Nếu nghĩ có thể muốn làm gì với thế\n"
	.string "giới cũng được thì các ngươi lầm to\l"
	.string "rồi!$"

MeteorFalls_1F_1R_Text_BeSeeingYouTeamAqua:
	.string "Hehehe! Cả TEAM AQUA cũng tới góp vui\n"
	.string "à!\p"
	.string "Nhưng đối phó với tất cả các ngươi thì\n"
	.string "phiền quá...\p"
	.string "Hừ, chẳng sao cả!\p"
	.string "Bọn ta đã có METEORITE, giờ lên đường\n"
	.string "đến MT. CHIMNEY!\p"
	.string "Hehehe! Hẹn gặp lại, lũ ngốc TEAM AQUA!$"

MeteorFalls_1F_1R_Text_ArchieSeenYouBefore:
	.string "ARCHIE: Chẳng phải ta đã gặp nhóc\n"
	.string "trước đây sao? Ở MUSEUM của\l"
	.string "SLATEPORT?\p"
	.string "À, vậy tên nhóc là {PLAYER}.\p"
	.string "Lúc đó, ta tưởng nhóc là một tên tay\n"
	.string "sai của TEAM MAGMA.\p"
	.string "Hừm... Nhóc đúng là một đứa kỳ lạ.\p"
	.string "TEAM MAGMA là một nhóm cuồng tín cực\n"
	.string "đoan và nguy hiểm.\p"
	.string "Chúng phá hoại khắp nơi, viện cớ để mở\n"
	.string "rộng đất liền.\p"
	.string "Chúng là đối thủ của TEAM AQUA chúng\n"
	.string "ta, những người yêu biển cả!$"

MeteorFalls_1F_1R_Text_BossWeShouldChaseMagma:
	.string "Thủ lĩnh, chúng ta nên đuổi theo TEAM\n"
	.string "MAGMA...$"

MeteorFalls_1F_1R_Text_ArchieYesNoTellingWhatMagmaWillDo:
	.string "ARCHIE: Phải, phải, nhất định rồi! Chúng\n"
	.string "ta phải nhanh lên.\p"
	.string "Không biết TEAM MAGMA sẽ làm gì ở MT.\n"
	.string "CHIMNEY đâu!$"

MeteorFalls_1F_1R_Text_ArchieFarewell:
	.string "ARCHIE: {PLAYER}, nhóc cũng nên đề\n"
	.string "phòng TEAM MAGMA.\p"
	.string "Tạm biệt!$"

MeteorFalls_1F_1R_Text_MeetProfCozmo:
	.string "Tôi... Tôi là COZMO... Tôi là một\n"
	.string "PROFESSOR...\p"
	.string "TEAM MAGMA nhờ tôi dẫn chúng đến\n"
	.string "METEOR FALLS...\p"
	.string "Nhưng chúng đã lừa tôi. Chúng còn lấy\n"
	.string "mất METEORITE của tôi...\p"
	.string "Rồi một nhóm tương tự khác là TEAM\n"
	.string "AQUA xuất hiện.\p"
	.string "Sau đó... Tôi chẳng hiểu gì nữa.\p"
	.string "Nhưng TEAM MAGMA đó...\p"
	.string "Chúng định làm gì với METEORITE ở MT.\n"
	.string "CHIMNEY?$"

MeteorFalls_1F_1R_Text_WhatsTeamMagmaDoingAtMtChimney:
	.string "PROF. COZMO: Nhưng TEAM MAGMA đó...\p"
	.string "Chúng định làm gì với METEORITE ở MT.\n"
	.string "CHIMNEY?$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global MeteorFalls_1F_1R_Text_WithThisMeteorite
	.global MeteorFalls_1F_1R_Text_DontExpectMercyFromMagma
	.global MeteorFalls_1F_1R_Text_HoldItRightThereMagma
	.global MeteorFalls_1F_1R_Text_BeSeeingYouTeamAqua
	.global MeteorFalls_1F_1R_Text_ArchieSeenYouBefore
	.global MeteorFalls_1F_1R_Text_BossWeShouldChaseMagma
	.global MeteorFalls_1F_1R_Text_ArchieYesNoTellingWhatMagmaWillDo
	.global MeteorFalls_1F_1R_Text_ArchieFarewell
	.global MeteorFalls_1F_1R_Text_MeetProfCozmo
	.global MeteorFalls_1F_1R_Text_WhatsTeamMagmaDoingAtMtChimney
@ END GENERATED LOCALIZATION EXPORTS
