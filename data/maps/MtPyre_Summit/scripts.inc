MtPyre_Summit_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtPyre_Summit_OnTransition
	.byte 0

MtPyre_Summit_OnTransition:
	call_if_eq VAR_MT_PYRE_STATE, 2, MtPyre_Summit_EventScript_SetArchieMaxiePositions
	end

MtPyre_Summit_EventScript_SetArchieMaxiePositions::
	setobjectxyperm LOCALID_MT_PYRE_SUMMIT_MAXIE, 23, 6
	setobjectxyperm LOCALID_MT_PYRE_SUMMIT_ARCHIE, 22, 6
	end

MtPyre_Summit_EventScript_TeamAquaTrigger0::
	lockall
	setvar VAR_0x8008, 0
	goto MtPyre_Summit_EventScript_TeamAquaExits
	end

MtPyre_Summit_EventScript_TeamAquaTrigger1::
	lockall
	setvar VAR_0x8008, 1
	goto MtPyre_Summit_EventScript_TeamAquaExits
	end

MtPyre_Summit_EventScript_TeamAquaTrigger2::
	lockall
	setvar VAR_0x8008, 2
	goto MtPyre_Summit_EventScript_TeamAquaExits
	end

MtPyre_Summit_EventScript_TeamAquaExits::
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 50
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_ArchieFacePlayer0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_ArchieFacePlayer1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_ArchieFacePlayer2
	msgbox MtPyre_Summit_Text_ArchieWeGotTheOrbLetsGo, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_MT_PYRE_SUMMIT_ARCHIE
	removeobject LOCALID_MT_PYRE_SUMMIT_GRUNT_1
	removeobject LOCALID_MT_PYRE_SUMMIT_GRUNT_2
	removeobject LOCALID_MT_PYRE_SUMMIT_GRUNT_3
	removeobject LOCALID_MT_PYRE_SUMMIT_GRUNT_4
	setflag FLAG_HIDE_MT_PYRE_SUMMIT_ARCHIE
	setflag FLAG_HIDE_MT_PYRE_SUMMIT_TEAM_AQUA
	fadedefaultbgm
	fadescreen FADE_FROM_BLACK
	delay 20
	setvar VAR_MT_PYRE_STATE, 1
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_OldLadyApproachPlayer0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_OldLadyApproachPlayer1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_OldLadyApproachPlayer2
	msgbox MtPyre_Summit_Text_BothOrbsTakenMagmaLeftThis, MSGBOX_DEFAULT
	giveitem ITEM_MAGMA_EMBLEM
	setflag FLAG_RECEIVED_RED_OR_BLUE_ORB
	setflag FLAG_HIDE_JAGGED_PASS_MAGMA_GUARD
	releaseall
	end

MtPyre_Summit_EventScript_ArchieFacePlayer0::
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieFacePlayer0
	waitmovement 0
	return

@ Archie is already facing player
MtPyre_Summit_EventScript_ArchieFacePlayer1::
	return

MtPyre_Summit_EventScript_ArchieFacePlayer2::
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieFacePlayer2
	waitmovement 0
	return

MtPyre_Summit_EventScript_OldLadyApproachPlayer0::
	applymovement LOCALID_MT_PYRE_SUMMIT_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer0
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

MtPyre_Summit_EventScript_OldLadyApproachPlayer1::
	applymovement LOCALID_MT_PYRE_SUMMIT_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer1
	waitmovement 0
	return

MtPyre_Summit_EventScript_OldLadyApproachPlayer2::
	applymovement LOCALID_MT_PYRE_SUMMIT_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer2
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

MtPyre_Summit_Movement_OldLadyApproachPlayer0:
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_OldLadyApproachPlayer1:
	walk_down
	step_end

MtPyre_Summit_Movement_OldLadyApproachPlayer2:
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_ArchieFacePlayer0:
	walk_left
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_ArchieFacePlayer2:
	walk_right
	walk_in_place_faster_down
	step_end

MtPyre_Summit_EventScript_OldMan::
	lock
	faceplayer
	goto_if_set FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE, MtPyre_Summit_EventScript_OldManAfterRayquaza
	msgbox MtPyre_Summit_Text_WillYouHearOutMyTale, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, MtPyre_Summit_EventScript_OldManTale
	call_if_eq VAR_RESULT, NO, MtPyre_Summit_EventScript_DeclineOldManTale
	release
	end

MtPyre_Summit_EventScript_OldManAfterRayquaza::
	msgbox MtPyre_Summit_Text_HearTheNewLegendOfHoenn, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, MtPyre_Summit_EventScript_OldManNewTale
	call_if_eq VAR_RESULT, NO, MtPyre_Summit_EventScript_DeclineOldManTale
	release
	end

MtPyre_Summit_EventScript_OldManTale::
	msgbox MtPyre_Summit_Text_GroudonKyogreTale, MSGBOX_DEFAULT
	return

MtPyre_Summit_EventScript_DeclineOldManTale::
	msgbox MtPyre_Summit_Text_WellThatTooIsFine, MSGBOX_DEFAULT
	return

MtPyre_Summit_EventScript_OldManNewTale::
	msgbox MtPyre_Summit_Text_HoennTrioTale, MSGBOX_DEFAULT
	return

MtPyre_Summit_EventScript_OldLady::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_RED_OR_BLUE_ORB, MtPyre_Summit_EventScript_OldLadyAfterOrbsReturned
	call_if_ge VAR_MT_PYRE_STATE, 3, MtPyre_Summit_EventScript_OldLadyOrbsReturned
	goto_if_set FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, MtPyre_Summit_EventScript_OldLadyLegendariesAwake
	msgbox MtPyre_Summit_Text_OrbsHaveBeenTaken, MSGBOX_DEFAULT
	release
	end

MtPyre_Summit_EventScript_OldLadyOrbsReturned::
	msgbox MtPyre_Summit_Text_ThoseTwoMenReturnedOrbs, MSGBOX_DEFAULT
	setflag FLAG_RETURNED_RED_OR_BLUE_ORB
	release
	end

MtPyre_Summit_EventScript_OldLadyLegendariesAwake::
	msgbox MtPyre_Summit_Text_GroudonKyogreAwakened, MSGBOX_DEFAULT
	release
	end

MtPyre_Summit_EventScript_OldLadyAfterOrbsReturned::
	msgbox MtPyre_Summit_Text_SuperAncientPokemonTaughtUs, MSGBOX_DEFAULT
	release
	end

MtPyre_Summit_EventScript_ArchieMaxieTrigger0::
	lockall
	setvar VAR_0x8008, 0
	goto MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs
	end

MtPyre_Summit_EventScript_ArchieMaxieTrigger1::
	lockall
	setvar VAR_0x8008, 1
	goto MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs
	end

MtPyre_Summit_EventScript_ArchieMaxieTrigger2::
	lockall
	setvar VAR_0x8008, 2
	goto MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs
	end

MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 60
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_ArchieMaxieBeginExit0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_ArchieMaxieBeginExit1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_ArchieMaxieBeginExit2
	playse SE_PIN
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, Common_Movement_Delay48
	waitmovement 0
	delay 30
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_MaxieApproachPlayer0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_MaxieApproachPlayer1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_MaxieApproachPlayer2
	msgbox MtPyre_Summit_Text_MaxieSilence, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_MaxieApproachArchie0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_MaxieApproachArchie1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_MaxieApproachArchie2
	delay 30
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	removeobject LOCALID_MT_PYRE_SUMMIT_ARCHIE
	removeobject LOCALID_MT_PYRE_SUMMIT_MAXIE
	setvar VAR_MT_PYRE_STATE, 3
	releaseall
	end

MtPyre_Summit_EventScript_ArchieMaxieBeginExit0::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit0
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	return

MtPyre_Summit_EventScript_ArchieMaxieBeginExit1::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit1
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	return

MtPyre_Summit_EventScript_ArchieMaxieBeginExit2::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit2
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachPlayer0::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie0
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieWatchMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachPlayer0
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachPlayer1::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieWatchMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachPlayer1
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachPlayer2::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieWatchMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachPlayer2
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachArchie0::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachArchie0
	waitmovement 0
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachArchie1::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachArchie1
	waitmovement 0
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachArchie2::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachArchie2
	waitmovement 0
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

MtPyre_Summit_Movement_PlayerFaceMaxie0:
	delay_16
	delay_16
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_PlayerFaceMaxie:
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_ArchieExit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtPyre_Summit_Movement_MaxieExit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit0:
	delay_16
	delay_8
	walk_left
	walk_in_place_faster_right
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit1:
	delay_16
	delay_8
	walk_right
	walk_in_place_faster_left
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit2:
	delay_16
	delay_8
	walk_in_place_faster_left
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_MaxieApproachPlayer0:
	walk_up
	walk_up
	walk_up
	walk_left
	step_end

MtPyre_Summit_Movement_MaxieApproachPlayer1:
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_MaxieApproachPlayer2:
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_ArchieWatchMaxie:
	delay_16
	walk_in_place_faster_up
	step_end

MtPyre_Summit_Movement_PlayerWatchMaxie:
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_MaxieApproachArchie0:
	walk_down
	walk_right
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_MaxieApproachArchie1:
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_MaxieApproachArchie2:
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_1, MtPyre_Summit_Text_Grunt1Intro, MtPyre_Summit_Text_Grunt1Defeat
	msgbox MtPyre_Summit_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_2, MtPyre_Summit_Text_Grunt2Intro, MtPyre_Summit_Text_Grunt2Defeat
	msgbox MtPyre_Summit_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_3, MtPyre_Summit_Text_Grunt3Intro, MtPyre_Summit_Text_Grunt3Defeat
	msgbox MtPyre_Summit_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_4, MtPyre_Summit_Text_Grunt4Intro, MtPyre_Summit_Text_Grunt4Defeat
	msgbox MtPyre_Summit_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_Text_Grunt1Intro:
	.string "Không! Bọn tay sai TEAM MAGMA đã đến\n"
	.string "đây trước chúng ta!\p"
	.string "Không thể để bị tụt lại!$"

MtPyre_Summit_Text_Grunt1Defeat:
	.string "Ta cứ tưởng ngươi là một tên MAGMAS\n"
	.string "quay lại...$"

MtPyre_Summit_Text_Grunt1PostBattle:
	.string "Ừ, công nhận ngươi mạnh... Nhưng bọn ta\n"
	.string "đông lắm!$"

MtPyre_Summit_Text_Grunt2Intro:
	.string "Ha! Xui cho ngươi rồi!\p"
	.string "Nếu đến sớm hơn, ngươi chỉ phải đấu\n"
	.string "với lũ TEAM MAGMA yếu nhớt.\p"
	.string "Nhưng vì bây giờ mới tới, ngươi phải\n"
	.string "đối đầu với những kẻ mạnh như bọn ta!$"

MtPyre_Summit_Text_Grunt2Defeat:
	.string "Hự... Lẽ ra ta nên để ngươi đấu với\n"
	.string "TEAM MAGMA trước...$"

MtPyre_Summit_Text_Grunt2PostBattle:
	.string "Ngươi chẳng biết gì cả! Vậy tại sao còn\n"
	.string "xen vào chuyện của bọn ta?$"

MtPyre_Summit_Text_Grunt3Intro:
	.string "Ngươi... Bọn ta đã thấy ngươi ở MT.\n"
	.string "CHIMNEY.\p"
	.string "Ngươi không thuộc TEAM nào, vậy tới\n"
	.string "đây làm gì?$"

MtPyre_Summit_Text_Grunt3Defeat:
	.string "Nếu muốn gây chuyện với ai thì hãy nhắm\n"
	.string "vào TEAM MAGMA...$"

MtPyre_Summit_Text_Grunt3PostBattle:
	.string "Hừ, chẳng sao cả! Bọn ta đã câu được\n"
	.string "chút thời gian!\p"
	.string "Chắc thủ lĩnh đã lấy thứ mình muốn\n"
	.string "rồi!$"

MtPyre_Summit_Text_Grunt4Intro:
	.string "Ồ, ta biết rồi! Ngươi muốn gia nhập TEAM\n"
	.string "MAGMA nhưng chúng không chịu nhận!\p"
	.string "Đừng tưởng TEAM AQUA của bọn ta sẽ\n"
	.string "cho ngươi gia nhập!$"

MtPyre_Summit_Text_Grunt4Defeat:
	.string "Nếu ngươi muốn gia nhập TEAM AQUA đến\n"
	.string "thế, bọn ta có thể cân nhắc...$"

MtPyre_Summit_Text_Grunt4PostBattle:
	.string "Các thành viên bọn ta và thủ lĩnh phối\n"
	.string "hợp vô cùng ăn ý.$"

MtPyre_Summit_Text_ArchieWeGotTheOrbLetsGo:
	.string "ARCHIE: MAXIE của TEAM MAGMA đã đi\n"
	.string "trước chúng ta, nhưng ta cũng lấy\l"
	.string "được thứ mình muốn.\p"
	.string "RED ORB được gìn giữ tại MT. PYRE... Giờ\n"
	.string "nó đã thuộc về ta, ARCHIE!\p"
	.string "Hư hư hư... Giờ chúng ta có thể hoàn\n"
	.string "thành mục tiêu tối thượng!\p"
	.string "Được rồi, TEAM! Rút lui!$"

MtPyre_Summit_Text_BothOrbsTakenMagmaLeftThis:
	.string "Ôi, không... Chuyện này không thể xảy\n"
	.string "ra...\p"
	.string "Không chỉ BLUE ORB mà ngay cả RED ORB\n"
	.string "cũng đã bị lấy đi...\p"
	.string "BLUE ORB và RED ORB tuyệt đối không\n"
	.string "được tách rời. Chúng phải luôn ở bên\l"
	.string "nhau.\p"
	.string "Những kẻ đó định làm gì với hai ORBS?\p"
	.string ". . . . . . . . . . . .\p"
	.string "À, phải rồi. Có phải TEAM MAGMA đã đến\n"
	.string "lấy BLUE ORB trước không?\p"
	.string "Vì quá vội vàng, chúng đã bỏ lại thứ\n"
	.string "này.\p"
	.string "Ta không thể đoán được chính xác nó là\n"
	.string "gì.\p"
	.string "Ta muốn cháu giữ lấy. Có lẽ nó sẽ hữu\n"
	.string "ích theo cách nào đó.$"

MtPyre_Summit_Text_OrbsHaveBeenTaken:
	.string "BLUE ORB và RED ORB đã bị những kẻ hiểm\n"
	.string "độc đó lấy đi...\p"
	.string "Chúng tuyệt đối không được xa nhau...\n"
	.string "Ta e rằng một chuyện khủng khiếp sẽ xảy\l"
	.string "ra...$"

MtPyre_Summit_Text_GroudonKyogreAwakened:
	.string "Ôi trời...\p"
	.string "Cháu nói cả GROUDON lẫn KYOGRE đều đã\n"
	.string "thức tỉnh sao?\p"
	.string "Tương truyền BLUE ORB và RED ORB từng\n"
	.string "xoa dịu cơn thịnh nộ của hai POKéMON\l"
	.string "đó...\p"
	.string "Người ta cũng kể rằng chủ nhân thực\n"
	.string "sự của các ORBS vẫn còn tồn tại.\p"
	.string "Tuy nhiên, không ai biết chủ nhân ấy là\n"
	.string "ai, hay chính xác các ORBS thuộc về thứ\l"
	.string "gì.\p"
	.string "Có thể là một con người, hoặc một\n"
	.string "POKéMON, nhưng không ai biết cả.$"

MtPyre_Summit_Text_ThoseTwoMenReturnedOrbs:
	.string "Hai người đàn ông đã lấy các ORBS tự\n"
	.string "mình quay lại trả chúng.\p"
	.string "Hai người đó... Có lẽ họ cũng không hoàn\n"
	.string "toàn xấu xa...$"

MtPyre_Summit_Text_SuperAncientPokemonTaughtUs:
	.string "Hiện thân của đất liền, biển cả và bầu\n"
	.string "trời...\p"
	.string "Tương truyền đó chính là bản chất của\n"
	.string "những POKéMON siêu cổ đại...\p"
	.string "Cũng như con người và POKéMON có sinh\n"
	.string "mệnh, thế giới của chúng ta cũng đang\l"
	.string "sống...\p"
	.string "Những POKéMON siêu cổ đại đã dạy chúng\n"
	.string "ta điều đó...$"

MtPyre_Summit_Text_WillYouHearOutMyTale:
	.string "MT. PYRE là nơi chúng ta xoa dịu linh hồn\n"
	.string "của những POKéMON đã khuất...\p"
	.string "Từ nơi cao này có thể nhìn thấy toàn\n"
	.string "cõi HOENN...\p"
	.string "Những linh hồn POKéMON đã rời thân xác\n"
	.string "hẳn sẽ tìm được sự an nghỉ tại đây...\p"
	.string "Việc cháu có mặt nơi này liệu có phải\n"
	.string "tình cờ...\p"
	.string "Cháu có muốn nghe câu chuyện của ta\n"
	.string "không? Một câu chuyện được lưu truyền\l"
	.string "từ lâu tại vùng HOENN?$"

MtPyre_Summit_Text_GroudonKyogreTale:
	.string "Chuyện xảy ra từ rất, rất lâu về\n"
	.string "trước...\p"
	.string "Thế giới bị tàn phá bởi cuộc đụng độ dữ\n"
	.string "dội giữa POKéMON của đất liền và\l"
	.string "POKéMON của biển cả...\p"
	.string "POKéMON của đất liền nâng núi cao và\n"
	.string "tạo nên các lục địa...\p"
	.string "POKéMON của biển cả dâng những con\n"
	.string "sóng khổng lồ và tạo nên đại dương...\p"
	.string "Trận quyết đấu khốc liệt của chúng kéo\n"
	.string "dài không dứt.\p"
	.string "Thế giới chìm trong biển lửa khổng lồ\n"
	.string "và những cơn bão hung tàn.\p"
	.string "BLUE ORB và RED ORB đã chấm dứt tai\n"
	.string "họa.\p"
	.string "Ánh sáng tuôn ra từ hai ORBS và xoa dịu\n"
	.string "những đối thủ đang nổi giận.\p"
	.string "Khi đã trở nên hiền hòa, cả hai lặn sâu\n"
	.string "xuống biển rồi cuối cùng biến mất...$"

MtPyre_Summit_Text_WellThatTooIsFine:
	.string "Ta hiểu rồi... Như vậy cũng không sao...$"

MtPyre_Summit_Text_MaxieSilence:
	.string "MAXIE: {PLAYER}...\p"
	.string ". . . . . . . . . . . .$"

MtPyre_Summit_Text_HearTheNewLegendOfHoenn:
	.string "Vai trò của ta là truyền lại những huyền\n"
	.string "thoại của HOENN cho các thế hệ mai sau.\p"
	.string "Và cuộc khủng hoảng vừa kết thúc tại\n"
	.string "SOOTOPOLIS đã viết lại một huyền\l"
	.string "thoại...\p"
	.string "Cháu có thời gian nghe huyền thoại mới\n"
	.string "của HOENN không?$"

MtPyre_Summit_Text_HoennTrioTale:
	.string "Chuyện xảy ra từ rất, rất lâu về\n"
	.string "trước...\p"
	.string "Thế giới bị tàn phá bởi cuộc đụng độ dữ\n"
	.string "dội giữa POKéMON của đất liền và\l"
	.string "POKéMON của biển cả...\p"
	.string "POKéMON của đất liền nâng núi cao và\n"
	.string "tạo nên các lục địa...\p"
	.string "POKéMON của biển cả dâng những con\n"
	.string "sóng khổng lồ và tạo nên đại dương...\p"
	.string "Trận quyết đấu khốc liệt của chúng kéo\n"
	.string "dài không dứt.\p"
	.string "Thế giới chìm trong biển lửa khổng lồ\n"
	.string "và những cơn bão hung tàn.\p"
	.string "Chính lúc ấy, POKéMON của bầu trời từ\n"
	.string "trong cơn bão hạ xuống.\p"
	.string "POKéMON tỏa ánh sáng xanh rực rỡ ấy đã\n"
	.string "xoa dịu hai POKéMON đang nổi giận.\p"
	.string "Sau khi hoàn thành sứ mệnh, POKéMON\n"
	.string "màu xanh bay vào khoảng trời xanh\l"
	.string "thẳm...$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global MtPyre_Summit_Text_Grunt1Intro
	.global MtPyre_Summit_Text_Grunt1Defeat
	.global MtPyre_Summit_Text_Grunt1PostBattle
	.global MtPyre_Summit_Text_Grunt2Intro
	.global MtPyre_Summit_Text_Grunt2Defeat
	.global MtPyre_Summit_Text_Grunt2PostBattle
	.global MtPyre_Summit_Text_Grunt3Intro
	.global MtPyre_Summit_Text_Grunt3Defeat
	.global MtPyre_Summit_Text_Grunt3PostBattle
	.global MtPyre_Summit_Text_Grunt4Intro
	.global MtPyre_Summit_Text_Grunt4Defeat
	.global MtPyre_Summit_Text_Grunt4PostBattle
	.global MtPyre_Summit_Text_ArchieWeGotTheOrbLetsGo
	.global MtPyre_Summit_Text_BothOrbsTakenMagmaLeftThis
	.global MtPyre_Summit_Text_OrbsHaveBeenTaken
	.global MtPyre_Summit_Text_GroudonKyogreAwakened
	.global MtPyre_Summit_Text_ThoseTwoMenReturnedOrbs
	.global MtPyre_Summit_Text_SuperAncientPokemonTaughtUs
	.global MtPyre_Summit_Text_WillYouHearOutMyTale
	.global MtPyre_Summit_Text_GroudonKyogreTale
	.global MtPyre_Summit_Text_WellThatTooIsFine
	.global MtPyre_Summit_Text_MaxieSilence
	.global MtPyre_Summit_Text_HearTheNewLegendOfHoenn
	.global MtPyre_Summit_Text_HoennTrioTale
@ END GENERATED LOCALIZATION EXPORTS
