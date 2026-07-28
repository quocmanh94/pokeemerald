FortreeCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_Gym_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, FortreeCity_Gym_OnWarp
	.byte 0

FortreeCity_Gym_OnTransition:
	special RotatingGate_InitPuzzle
	setflag FLAG_TEMP_HIDE_FOLLOWER @ Hide follower bc of rotating gates
	end

FortreeCity_Gym_OnWarp:
	map_script_2 VAR_TEMP_0, VAR_TEMP_0, FortreeCity_Gym_EventScript_InitRotatingGates
	.2byte 0

@ NOTE: This rotating gate puzzle makes use of VAR_TEMP_0 - VAR_TEMP_3
FortreeCity_Gym_EventScript_InitRotatingGates::
	special RotatingGate_InitPuzzleAndGraphics
	end

FortreeCity_Gym_EventScript_Winona::
	trainerbattle_single TRAINER_WINONA_1, FortreeCity_Gym_Text_WinonaIntro, FortreeCity_Gym_Text_WinonaDefeat, FortreeCity_Gym_EventScript_WinonaDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, FortreeCity_Gym_EventScript_WinonaRematch
	goto_if_unset FLAG_RECEIVED_TM_AERIAL_ACE, FortreeCity_Gym_EventScript_GiveAerialAce2
	msgbox FortreeCity_Gym_Text_WinonaPostBattle, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_WinonaDefeated::
	message FortreeCity_Gym_Text_ReceivedFeatherBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox FortreeCity_Gym_Text_ExplainFeatherBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_FORTREE_GYM
	setflag FLAG_BADGE06_GET
	setvar VAR_0x8008, 6
	call Common_EventScript_SetGymTrainers
	call FortreeCity_Gym_EventScript_GiveAerialAce
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox FortreeCity_Gym_Text_RegisteredWinona, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_WINONA_MATCH_CALL
	setvar VAR_SCOTT_FORTREE_CALL_STEP_COUNTER, 0
	setflag FLAG_SCOTT_CALL_FORTREE_GYM
	release
	end

FortreeCity_Gym_EventScript_GiveAerialAce2::
	giveitem ITEM_TM_AERIAL_ACE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox FortreeCity_Gym_Text_ExplainAerialAce, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_AERIAL_ACE
	release
	end

FortreeCity_Gym_EventScript_GiveAerialAce::
	giveitem ITEM_TM_AERIAL_ACE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox FortreeCity_Gym_Text_ExplainAerialAce, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_AERIAL_ACE
	return

FortreeCity_Gym_EventScript_WinonaRematch::
	trainerbattle_rematch_double TRAINER_WINONA_1, FortreeCity_Gym_Text_WinonaPreRematch, FortreeCity_Gym_Text_WinonaRematchDefeat, FortreeCity_Gym_Text_WinonaRematchNeedTwoMons
	msgbox FortreeCity_Gym_Text_WinonaPostRematch, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Jared::
	trainerbattle_single TRAINER_JARED, FortreeCity_Gym_Text_JaredIntro, FortreeCity_Gym_Text_JaredDefeat
	msgbox FortreeCity_Gym_Text_JaredPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Edwardo::
	trainerbattle_single TRAINER_EDWARDO, FortreeCity_Gym_Text_EdwardoIntro, FortreeCity_Gym_Text_EdwardoDefeat
	msgbox FortreeCity_Gym_Text_EdwardoPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Flint::
	trainerbattle_single TRAINER_FLINT, FortreeCity_Gym_Text_FlintIntro, FortreeCity_Gym_Text_FlintDefeat
	msgbox FortreeCity_Gym_Text_FlintPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Ashley::
	trainerbattle_single TRAINER_ASHLEY, FortreeCity_Gym_Text_AshleyIntro, FortreeCity_Gym_Text_AshleyDefeat
	msgbox FortreeCity_Gym_Text_AshleyPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Humberto::
	trainerbattle_single TRAINER_HUMBERTO, FortreeCity_Gym_Text_HumbertoIntro, FortreeCity_Gym_Text_HumbertoDefeat
	msgbox FortreeCity_Gym_Text_HumbertoPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Darius::
	trainerbattle_single TRAINER_DARIUS, FortreeCity_Gym_Text_DariusIntro, FortreeCity_Gym_Text_DariusDefeat
	msgbox FortreeCity_Gym_Text_DariusPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_FORTREE_GYM, FortreeCity_Gym_EventScript_GymGuidePostVictory
	msgbox FortreeCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_GymGuidePostVictory::
	msgbox FortreeCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE06_GET, FortreeCity_Gym_EventScript_GymStatueCertified
	goto FortreeCity_Gym_EventScript_GymStatue
	end

FortreeCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE06_GET, FortreeCity_Gym_EventScript_GymStatueCertified
	goto FortreeCity_Gym_EventScript_GymStatue
	end

FortreeCity_Gym_EventScript_GymStatueCertified::
	msgbox FortreeCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_Gym_EventScript_GymStatue::
	msgbox FortreeCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_Gym_Text_GymGuideAdvice:
	.string "Này, khỏe chứ, {PLAYER}, người đang\n"
	.string "hướng tới ngôi CHAMPION?\p"
	.string "FORTREE GYM LEADER WINONA là bậc thầy\n"
	.string "về POKéMON hệ FLYING.\p"
	.string "Cô ấy đang chờ ở cuối GYM này, phía sau\n"
	.string "những cánh cửa xoay.\p"
	.string "Cô ấy đang chờ những người thách đấu\n"
	.string "mới muốn tung cánh!\p"
	.string "Được rồi, tiến lên nào!$"

FortreeCity_Gym_Text_GymGuidePostVictory:
	.string "Bạn làm được rồi! Bạn đã cất cánh\n"
	.string "thành công!$"

FortreeCity_Gym_Text_JaredIntro:
	.string "Hãy chiêm ngưỡng phong cách chiến đấu\n"
	.string "thanh nhã của BIRD POKéMON!$"

FortreeCity_Gym_Text_JaredDefeat:
	.string "Bạn... Bạn mạnh thật...$"

FortreeCity_Gym_Text_JaredPostBattle:
	.string "Một HLV phải thật nhạy bén mới ứng\n"
	.string "phó được với những biến chuyển bất\l"
	.string "ngờ.\p"
	.string "Bạn có đủ thông minh để đến được chỗ\n"
	.string "LEADER của chúng tôi không?$"

FortreeCity_Gym_Text_EdwardoIntro:
	.string "Những người yêu BIRD POKéMON đều\n"
	.string "khao khát được gia nhập GYM này.\p"
	.string "Là một thành viên của FORTREE GYM, tôi\n"
	.string "không được phép thua!$"

FortreeCity_Gym_Text_EdwardoDefeat:
	.string "Gánh nặng này vượt quá sức tôi...$"

FortreeCity_Gym_Text_EdwardoPostBattle:
	.string "Thế giới rộng lớn, và có vô số HLV\n"
	.string "mạnh mẽ.\p"
	.string "Tôi sẽ tiếp tục rèn luyện để trở nên\n"
	.string "mạnh hơn nữa.$"

FortreeCity_Gym_Text_FlintIntro:
	.string "Không cần GYM LEADER WINONA của chúng\n"
	.string "tôi phải ra tay với bạn!\p"
	.string "Chỉ mình tôi là quá đủ rồi!$"

FortreeCity_Gym_Text_FlintDefeat:
	.string "WINONA, tôi... Tôi thua rồi!$"

FortreeCity_Gym_Text_FlintPostBattle:
	.string "WINONA vừa đáng yêu vừa mạnh mẽ. Cô ấy\n"
	.string "là LEADER tuyệt đỉnh!\p"
	.string "Ngượng quá...$"

FortreeCity_Gym_Text_AshleyIntro:
	.string "WINONA đã đích thân dạy tôi! Bạn không\n"
	.string "dễ thắng tôi đâu!$"

FortreeCity_Gym_Text_AshleyDefeat:
	.string "Tôi đã bị đánh bại...$"

FortreeCity_Gym_Text_AshleyPostBattle:
	.string "Nhờ có WINONA, người dân FORTREE có\n"
	.string "thể sống mà không phải sợ hãi.$"

FortreeCity_Gym_Text_HumbertoIntro:
	.string "Khi WINONA bước vào trận đấu, gương\n"
	.string "mặt cô ấy sáng lên với quyết tâm tuyệt\l"
	.string "đẹp...\p"
	.string "Tôi sẽ không để bạn được chứng kiến\n"
	.string "cảnh tượng đáng yêu ấy!$"

FortreeCity_Gym_Text_HumbertoDefeat:
	.string "Ư! Tôi không thể ngăn bạn lại.$"

FortreeCity_Gym_Text_HumbertoPostBattle:
	.string "Cẩn thận đấy! Đừng mải ngắm WINONA rồi\n"
	.string "phân tâm, nếu không bạn sẽ ngã nhào tan\l"
	.string "tác!$"

FortreeCity_Gym_Text_DariusIntro:
	.string "Bạn nên biết POKéMON hệ FLYING có đủ\n"
	.string "mọi loại.\p"
	.string "Bạn biết điều đó rồi, phải không?$"

FortreeCity_Gym_Text_DariusDefeat:
	.string "Có vẻ bạn rất am hiểu đấy!$"

FortreeCity_Gym_Text_DariusPostBattle:
	.string "Đúng là bạn đã thắng tôi. Nhưng hãy cẩn\n"
	.string "thận! POKéMON của LEADER WINONA không\l"
	.string "hề đùa đâu.$"

FortreeCity_Gym_Text_WinonaIntro:
	.string "Tôi là WINONA. Tôi là LEADER của FORTREE\n"
	.string "POKéMON GYM.\p"
	.string "Tôi đã hòa làm một với BIRD POKéMON và\n"
	.string "sải cánh trên bầu trời...\p"
	.string "Dù trận đấu có khắc nghiệt đến đâu,\n"
	.string "chúng tôi vẫn chiến thắng đầy thanh\l"
	.string "nhã...\p"
	.string "Hãy chiêm ngưỡng vũ điệu chiến đấu\n"
	.string "thanh nhã của tôi và BIRD POKéMON!$"

FortreeCity_Gym_Text_WinonaDefeat:
	.string "Trước nay, tôi chưa từng thấy một\n"
	.string "HLV nào điều khiển POKéMON thanh\l"
	.string "thoát đến mức vượt cả tôi...\p"
	.string "Để công nhận tài năng của bạn, tôi xin\n"
	.string "trao tặng GYM BADGE này.$"

FortreeCity_Gym_Text_ReceivedFeatherBadge:
	.string "{PLAYER} đã nhận FEATHER BADGE từ\n"
	.string "WINONA.$"

FortreeCity_Gym_Text_ExplainFeatherBadgeTakeThis:
	.string "Với FEATHER BADGE, mọi POKéMON đến LV\n"
	.string "70, kể cả những POKéMON nhận qua trao\l"
	.string "đổi, đều sẽ tuân theo mọi mệnh lệnh của\l"
	.string "bạn.\p"
	.string "Bạn cũng sẽ có thể dùng chiêu HM FLY\n"
	.string "ngoài trận đấu.\p"
	.string "Và đây... Đây là món quà của tôi.$"

FortreeCity_Gym_Text_ExplainAerialAce:
	.string "TM40 chứa AERIAL ACE.\p"
	.string "Tốc độ của nó... Không POKéMON nào có\n"
	.string "thể né tránh.\p"
	.string "... ... ... ... ... ...$"

FortreeCity_Gym_Text_RegisteredWinona:
	.string "Đã đăng ký GYM LEADER WINONA vào\n"
	.string "POKéNAV.$"

FortreeCity_Gym_Text_WinonaPostBattle:
	.string "Dù đã thua bạn, tôi vẫn sẽ luôn tận tâm\n"
	.string "với BIRD POKéMON.$"

FortreeCity_Gym_Text_GymStatue:
	.string "FORTREE CITY POKéMON GYM$"

FortreeCity_Gym_Text_GymStatueCertified:
	.string "FORTREE CITY POKéMON GYM\p"
	.string "WINONA'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"

FortreeCity_Gym_Text_WinonaPreRematch:
	.string "WINONA: Con người chúng ta không bao\n"
	.string "giờ thoát khỏi sức hút của trọng lực\l"
	.string "nơi mặt đất.\p"
	.string "Nhưng bằng cách không ngừng vươn tới\n"
	.string "sự hoàn hảo, chúng ta có sức mạnh để\l"
	.string "bay cao!\p"
	.string "Bạn đã vươn tới đỉnh cao với tư cách\n"
	.string "CHAMPION đương nhiệm.\p"
	.string "Xin hãy cho tôi được chứng kiến sức\n"
	.string "mạnh của bạn khi tung cánh hết mình!$"

FortreeCity_Gym_Text_WinonaRematchDefeat:
	.string "Một lần nữa, tôi vẫn không thể vươn\n"
	.string "tới tầm cao của bạn...$"

FortreeCity_Gym_Text_WinonaPostRematch:
	.string "WINONA: Dù đã thua, đôi cánh trong tim\n"
	.string "tôi vẫn không gãy.\p"
	.string "Tôi có thể đứng dậy và lại bay cao, hết\n"
	.string "lần này đến lần khác.\p"
	.string "Tôi tin chắc như vậy!$"

FortreeCity_Gym_Text_WinonaRematchNeedTwoMons:
	.string "WINONA: Con người chúng ta không bao\n"
	.string "giờ thoát khỏi sức hút của trọng lực\l"
	.string "nơi mặt đất.\p"
	.string "Nhưng bằng cách không ngừng vươn tới\n"
	.string "sự hoàn hảo, chúng ta có sức mạnh để\l"
	.string "bay cao!\p"
	.string "Bạn đã vươn tới đỉnh cao với tư cách\n"
	.string "CHAMPION đương nhiệm.\p"
	.string "Xin hãy cho tôi được chứng kiến sức\n"
	.string "mạnh của bạn khi tung cánh hết mình!\p"
	.string "Ồ, không... Bạn chỉ mang theo một\n"
	.string "POKéMON thôi sao?\p"
	.string "Xin hãy quay lại với ít nhất hai\n"
	.string "POKéMON.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global FortreeCity_Gym_Text_GymGuideAdvice
	.global FortreeCity_Gym_Text_GymGuidePostVictory
	.global FortreeCity_Gym_Text_JaredIntro
	.global FortreeCity_Gym_Text_JaredDefeat
	.global FortreeCity_Gym_Text_JaredPostBattle
	.global FortreeCity_Gym_Text_EdwardoIntro
	.global FortreeCity_Gym_Text_EdwardoDefeat
	.global FortreeCity_Gym_Text_EdwardoPostBattle
	.global FortreeCity_Gym_Text_FlintIntro
	.global FortreeCity_Gym_Text_FlintDefeat
	.global FortreeCity_Gym_Text_FlintPostBattle
	.global FortreeCity_Gym_Text_AshleyIntro
	.global FortreeCity_Gym_Text_AshleyDefeat
	.global FortreeCity_Gym_Text_AshleyPostBattle
	.global FortreeCity_Gym_Text_HumbertoIntro
	.global FortreeCity_Gym_Text_HumbertoDefeat
	.global FortreeCity_Gym_Text_HumbertoPostBattle
	.global FortreeCity_Gym_Text_DariusIntro
	.global FortreeCity_Gym_Text_DariusDefeat
	.global FortreeCity_Gym_Text_DariusPostBattle
	.global FortreeCity_Gym_Text_WinonaIntro
	.global FortreeCity_Gym_Text_WinonaDefeat
	.global FortreeCity_Gym_Text_ReceivedFeatherBadge
	.global FortreeCity_Gym_Text_ExplainFeatherBadgeTakeThis
	.global FortreeCity_Gym_Text_ExplainAerialAce
	.global FortreeCity_Gym_Text_RegisteredWinona
	.global FortreeCity_Gym_Text_WinonaPostBattle
	.global FortreeCity_Gym_Text_WinonaPreRematch
	.global FortreeCity_Gym_Text_WinonaRematchDefeat
	.global FortreeCity_Gym_Text_WinonaPostRematch
	.global FortreeCity_Gym_Text_WinonaRematchNeedTwoMons
@ END GENERATED LOCALIZATION EXPORTS
