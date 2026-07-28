MossdeepCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_Gym_OnTransition
	.byte 0

MossdeepCity_Gym_OnTransition:
	setflag FLAG_TEMP_HIDE_FOLLOWER @ Hide follower since it can collide with moving statues
	end

MossdeepCity_Gym_EventScript_TateAndLiza::
	trainerbattle_double TRAINER_TATE_AND_LIZA_1, MossdeepCity_Gym_Text_TateAndLizaIntro, MossdeepCity_Gym_Text_TateAndLizaDefeat, MossdeepCity_Gym_Text_TateAndLizaNeedTwoMons, MossdeepCity_Gym_EventScript_TateAndLizaDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MossdeepCity_Gym_EventScript_TateAndLizaRematch
	goto_if_unset FLAG_RECEIVED_TM_CALM_MIND, MossdeepCity_Gym_EventScript_GiveCalmMind2
	msgbox MossdeepCity_Gym_Text_TateAndLizaPostBattle, MSGBOX_DEFAULT
	release
	end

MossdeepCity_Gym_EventScript_TateAndLizaDefeated::
	message MossdeepCity_Gym_Text_ReceivedMindBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox MossdeepCity_Gym_Text_ExplainMindBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_MOSSDEEP_GYM
	setflag FLAG_BADGE07_GET
	setflag FLAG_HIDE_AQUA_HIDEOUT_GRUNTS
	clearflag FLAG_HIDE_SLATEPORT_CITY_STERNS_SHIPYARD_MR_BRINEY
	setvar VAR_0x8008, 7
	call Common_EventScript_SetGymTrainers
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_PATRONS
	clearflag FLAG_HIDE_MOSSDEEP_CITY_TEAM_MAGMA
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_TEAM_MAGMA
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_TEAM_MAGMA
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_STEVEN
	setvar VAR_MOSSDEEP_CITY_STATE, 1
	setflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_STEVEN
	setvar VAR_MOSSDEEP_SPACE_CENTER_STATE, 1
	call MossdeepCity_Gym_EventScript_GiveCalmMind
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MossdeepCity_Gym_Text_RegisteredTateAndLiza, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_TATE_AND_LIZA_MATCH_CALL
	release
	end

MossdeepCity_Gym_EventScript_GiveCalmMind2::
	giveitem ITEM_TM_CALM_MIND
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox MossdeepCity_Gym_Text_ExplainCalmMind, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_CALM_MIND
	release
	end

MossdeepCity_Gym_EventScript_GiveCalmMind::
	giveitem ITEM_TM_CALM_MIND
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox MossdeepCity_Gym_Text_ExplainCalmMind, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_CALM_MIND
	return

MossdeepCity_Gym_EventScript_TateAndLizaRematch::
	trainerbattle_rematch_double TRAINER_TATE_AND_LIZA_1, MossdeepCity_Gym_Text_TateAndLizaPreRematch, MossdeepCity_Gym_Text_TateAndLizaRematchDefeat, MossdeepCity_Gym_Text_TateAndLizaRematchNeedTwoMons
	msgbox MossdeepCity_Gym_Text_TateAndLizaPostRematch, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_WarpToEntrance::
	lockall
	warpmossdeepgym MAP_MOSSDEEP_CITY_GYM, 7, 30
	waitstate
	releaseall
	end

MossdeepCity_Gym_EventScript_Preston::
	trainerbattle_single TRAINER_PRESTON, MossdeepCity_Gym_Text_PrestonIntro, MossdeepCity_Gym_Text_PrestonDefeat
	msgbox MossdeepCity_Gym_Text_PrestonPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Virgil::
	trainerbattle_single TRAINER_VIRGIL, MossdeepCity_Gym_Text_VirgilIntro, MossdeepCity_Gym_Text_VirgilDefeat
	msgbox MossdeepCity_Gym_Text_VirgilPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Blake::
	trainerbattle_single TRAINER_BLAKE, MossdeepCity_Gym_Text_BlakeIntro, MossdeepCity_Gym_Text_BlakeDefeat
	msgbox MossdeepCity_Gym_Text_BlakePostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Hannah::
	trainerbattle_single TRAINER_HANNAH, MossdeepCity_Gym_Text_HannahIntro, MossdeepCity_Gym_Text_HannahDefeat
	msgbox MossdeepCity_Gym_Text_HannahPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Samantha::
	trainerbattle_single TRAINER_SAMANTHA, MossdeepCity_Gym_Text_SamanthaIntro, MossdeepCity_Gym_Text_SamanthaDefeat
	msgbox MossdeepCity_Gym_Text_SamanthaPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Maura::
	trainerbattle_single TRAINER_MAURA, MossdeepCity_Gym_Text_MauraIntro, MossdeepCity_Gym_Text_MauraDefeat
	msgbox MossdeepCity_Gym_Text_MauraPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Sylvia::
	trainerbattle_single TRAINER_SYLVIA, MossdeepCity_Gym_Text_SylviaIntro, MossdeepCity_Gym_Text_SylviaDefeat
	msgbox MossdeepCity_Gym_Text_SylviaPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Nate::
	trainerbattle_single TRAINER_NATE, MossdeepCity_Gym_Text_NateIntro, MossdeepCity_Gym_Text_NateDefeat
	msgbox MossdeepCity_Gym_Text_NatePostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Macey::
	trainerbattle_single TRAINER_MACEY, MossdeepCity_Gym_Text_MaceyIntro, MossdeepCity_Gym_Text_MaceyDefeat
	msgbox MossdeepCity_Gym_Text_MaceyPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Clifford::
	trainerbattle_single TRAINER_CLIFFORD, MossdeepCity_Gym_Text_CliffordIntro, MossdeepCity_Gym_Text_CliffordDefeat
	msgbox MossdeepCity_Gym_Text_CliffordPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Nicholas::
	trainerbattle_single TRAINER_NICHOLAS, MossdeepCity_Gym_Text_NicholasIntro, MossdeepCity_Gym_Text_NicholasDefeat
	msgbox MossdeepCity_Gym_Text_NicholasPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Kathleen::
	trainerbattle_single TRAINER_KATHLEEN, MossdeepCity_Gym_Text_KathleenIntro, MossdeepCity_Gym_Text_KathleenDefeat
	msgbox MossdeepCity_Gym_Text_KathleenPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_MOSSDEEP_GYM, MossdeepCity_Gym_EventScript_GymGuidePostVictory
	msgbox MossdeepCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

MossdeepCity_Gym_EventScript_GymGuidePostVictory::
	msgbox MossdeepCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

@ Leftover from RS, functionally unused
MossdeepCity_Gym_Movement_WaitAfterSwitchUse:
	delay_16
	delay_16
	step_end

MossdeepCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE07_GET, MossdeepCity_Gym_EventScript_GymStatueCertified
	goto MossdeepCity_Gym_EventScript_GymStatue
	end

MossdeepCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE07_GET, MossdeepCity_Gym_EventScript_GymStatueCertified
	goto MossdeepCity_Gym_EventScript_GymStatue
	end

MossdeepCity_Gym_EventScript_GymStatueCertified::
	msgbox MossdeepCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_Gym_EventScript_GymStatue::
	msgbox MossdeepCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_Gym_EventScript_YellowFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 0
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_BlueFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 1
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_GreenFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 2
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_PurpleFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 3
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_RedFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 4
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_Text_GymGuideAdvice:
	.string "Này, ứng viên CHAMPION {PLAYER}, mọi\n"
	.string "chuyện thế nào?\p"
	.string "Các GYM LEADERS ở đây sử dụng POKéMON\n"
	.string "hệ PSYCHIC.\p"
	.string "Nếu dùng POKéMON hệ FIGHTING hoặc\n"
	.string "POISON đối đầu với họ, cậu sẽ phải chịu\l"
	.string "thiệt hại khủng khiếp!\p"
	.string "Họ còn tung ra những đòn phối hợp xuất\n"
	.string "sắc.\p"
	.string "Muốn thắng, cậu phải cho họ thấy mối\n"
	.string "gắn kết chặt chẽ giữa mình và POKéMON.\l"
	.string "Cố lên!$"

MossdeepCity_Gym_Text_GymGuidePostVictory:
	.string "Chà, cậu thật phi thường! Đúng là một\n"
	.string "HLV xuất sắc!$"

MossdeepCity_Gym_Text_PrestonIntro:
	.string "Thắng bại phụ thuộc vào sức mạnh tinh\n"
	.string "thần! Kẻ có ý chí yếu đuối sẽ không bao\l"
	.string "giờ thắng!$"

MossdeepCity_Gym_Text_PrestonDefeat:
	.string "Ta thua rồi! Ta phải rèn luyện tinh thần\n"
	.string "lại thôi!$"

MossdeepCity_Gym_Text_PrestonPostBattle:
	.string "Kẻ thiếu quyết đoán sẽ thua. Đó là lời\n"
	.string "cảnh báo của ta dành cho ngươi.$"

MossdeepCity_Gym_Text_VirgilIntro:
	.string "Hãy cho ta xem tài năng của ngươi!$"

MossdeepCity_Gym_Text_VirgilDefeat:
	.string "Ngươi sở hữu tài năng thật phi\n"
	.string "thường!$"

MossdeepCity_Gym_Text_VirgilPostBattle:
	.string "Nếu trên đời có những thiên tài, thì\n"
	.string "chính các GYM LEADERS của chúng ta là\l"
	.string "họ!\p"
	.string "Tuy nhiên, có lẽ ngươi còn tài năng hơn\n"
	.string "cả họ...$"

MossdeepCity_Gym_Text_BlakeIntro:
	.string "Fufufufu... Xem ta dùng tâm lực nâng\n"
	.string "POKé BALL bay lên đây!\p"
	.string "Gừừừừừừừừừ! ... ... ... ... ... ... ...\p"
	.string "Đôi khi tâm lực của ta mất nhịp...$"

MossdeepCity_Gym_Text_BlakeDefeat:
	.string "Kỹ năng chiến đấu POKéMON của ta cũng\n"
	.string "mất nhịp rồi!$"

MossdeepCity_Gym_Text_BlakePostBattle:
	.string "POKé BALL quá nặng để nâng bằng tâm\n"
	.string "lực. Nhưng cục bụi này thì...\p"
	.string "Phùùùùùùùùùùù! ... ... ... ... ... ...\p"
	.string "Không, ta không gian lận! Ta không hề\n"
	.string "thổi vào nó! Thật đấy!$"

MossdeepCity_Gym_Text_HannahIntro:
	.string "Khi thua tôi, đừng tự trách mình quá.\p"
	.string "Không phải bạn yếu, chỉ là tôi quá mạnh\n"
	.string "thôi!$"

MossdeepCity_Gym_Text_HannahDefeat:
	.string "Bạn mạnh quá đi mất!$"

MossdeepCity_Gym_Text_HannahPostBattle:
	.string "Tôi sẽ không buồn bã vì thất bại. Tôi\n"
	.string "chỉ cần luyện tập chăm chỉ hơn.\p"
	.string "Suy nghĩ tích cực chính là điểm mạnh\n"
	.string "của tôi!$"

MossdeepCity_Gym_Text_SamanthaIntro:
	.string "Ta thấy rồi... Ta nhìn thấy tương lai\n"
	.string "của ngươi...\p"
	.string "Nếu đánh bại được ta, ta sẽ tiết lộ\n"
	.string "tương lai ấy!$"

MossdeepCity_Gym_Text_SamanthaDefeat:
	.string "Ta đầu hàng!$"

MossdeepCity_Gym_Text_SamanthaPostBattle:
	.string "Ngươi sẽ có một trận đấu cực kỳ quyết\n"
	.string "liệt với các GYM LEADERS của chúng ta...\p"
	.string "Còn kết quả... Ta sẽ không nói đâu!$"

MossdeepCity_Gym_Text_MauraIntro:
	.string "Những con đường ngươi đã đi... Những\n"
	.string "điều ngươi đã trải qua...\p"
	.string "Hãy dùng tất cả những gì đã học được\n"
	.string "để đối đầu với ta!$"

MossdeepCity_Gym_Text_MauraDefeat:
	.string "Ngươi đã bước đi trên một con đường\n"
	.string "vĩ đại!$"

MossdeepCity_Gym_Text_MauraPostBattle:
	.string "Một tương lai tươi sáng đang chờ\n"
	.string "những người luôn nỗ lực hết mình.\p"
	.string "Còn kẻ chỉ biết lười biếng, cuối con\n"
	.string "đường chỉ có tuyệt vọng.\p"
	.string "Gieo nhân nào, gặt quả nấy...$"

MossdeepCity_Gym_Text_SylviaIntro:
	.string "Dù phải liều cả tính mạng, ta cũng sẽ\n"
	.string "thắng trận này!$"

MossdeepCity_Gym_Text_SylviaDefeat:
	.string "Những gì ngươi làm... khiến ta kinh\n"
	.string "hãi...$"

MossdeepCity_Gym_Text_SylviaPostBattle:
	.string "Sao ngươi dám đánh bại ta...\p"
	.string "Nếu có chuyện kinh khủng xảy đến với\n"
	.string "ngươi, đó không phải lỗi của ta đâu...$"

MossdeepCity_Gym_Text_NateIntro:
	.string "Hohoho.\p"
	.string "Để ta cho ngươi thấy POKéMON hệ\n"
	.string "PSYCHIC có thể ngoan cường đến mức\l"
	.string "nào.$"

MossdeepCity_Gym_Text_NateDefeat:
	.string "Ồ! Chà chà! Phong cách chiến đấu của\n"
	.string "ngươi thật tuyệt vời!$"

MossdeepCity_Gym_Text_NatePostBattle:
	.string "T... Ta không để thất bại khiến m... mình\n"
	.string "nao núng, dù t... thua thảm đến đâu.$"

MossdeepCity_Gym_Text_KathleenIntro:
	.string "Để ta cho ngươi trải qua một khoảng\n"
	.string "thời gian kinh hoàng đến tột độ!$"

MossdeepCity_Gym_Text_KathleenDefeat:
	.string "Kh... khônggggg!$"

MossdeepCity_Gym_Text_KathleenPostBattle:
	.string "Sức sống của ngươi sẽ lây sang ta mất!\n"
	.string "Mau tránh xa ta ra!$"

MossdeepCity_Gym_Text_CliffordIntro:
	.string "Ta có thể đã qua thời đỉnh cao, nhưng\n"
	.string "đừng vì thế mà xem thường ta.$"

MossdeepCity_Gym_Text_CliffordDefeat:
	.string "A, sức mạnh tuổi trẻ đang tràn ngập\n"
	.string "trong ngươi!$"

MossdeepCity_Gym_Text_CliffordPostBattle:
	.string "Có vẻ ta không thể vượt qua nguồn năng\n"
	.string "lượng tuổi trẻ của ngươi.$"

MossdeepCity_Gym_Text_MaceyIntro:
	.string "Ngươi sẽ không đến được đích đâu! Ta\n"
	.string "nhất định sẽ ngăn ngươi lại!$"

MossdeepCity_Gym_Text_MaceyDefeat:
	.string "Sao ngươi có thể mạnh đến mức vô lý\n"
	.string "như vậy?$"

MossdeepCity_Gym_Text_MaceyPostBattle:
	.string "Hừ! Ngươi có thể mạnh, nhưng không phù\n"
	.string "hợp với hệ PSYCHIC!\p"
	.string "Cách chiến đấu của ngươi có gì đó thật\n"
	.string "tàn bạo!$"

MossdeepCity_Gym_Text_NicholasIntro:
	.string "Gừừừ! Hãy nếm thử sức mạnh chiến đấu\n"
	.string "POKéMON siêu hạng của ta!$"

MossdeepCity_Gym_Text_NicholasDefeat:
	.string "Ôi! Bị hạ rồi!$"

MossdeepCity_Gym_Text_NicholasPostBattle:
	.string "Được lắm! Tiếp theo, ta sẽ phát triển\n"
	.string "một sức mạnh POKéMON đặc biệt và bất\l"
	.string "khả chiến bại.$"

MossdeepCity_Gym_Text_TateAndLizaIntro:
	.string "TATE: Hehehe... Bạn ngạc nhiên chứ?\p"
	.string "LIZA: Fufufu... Bạn ngạc nhiên chứ?\p"
	.string "TATE: Vì có đến hai GYM LEADERS? LIZA:\n"
	.string "Vì có đến hai GYM LEADERS?\p"
	.string "TATE: Chúng tôi là sinh đôi! LIZA: Chúng\n"
	.string "tôi là sinh đôi!\p"
	.string "TATE: Chúng tôi không cần nói vì... LIZA:\n"
	.string "Mỗi người đều có thể biết...\p"
	.string "TATE: Người kia đang nghĩ gì... LIZA:\n"
	.string "Chỉ bằng tâm trí!\p"
	.string "TATE: Sự kết hợp của chúng tôi... LIZA:\n"
	.string "Bạn có thể đánh bại không?$"

MossdeepCity_Gym_Text_TateAndLizaDefeat:
	.string "TATE: Gì cơ?! Sự kết hợp của chúng\n"
	.string "tôi... LIZA: Đã bị phá vỡ!\p"
	.string "TATE: Đành chịu thôi. Bạn đã thắng...\n"
	.string "LIZA: Để công nhận chiến thắng, hãy\l"
	.string "nhận lấy thứ này.$"

MossdeepCity_Gym_Text_ReceivedMindBadge:
	.string "{PLAYER} nhận được MIND BADGE từ\n"
	.string "TATE và LIZA.$"

MossdeepCity_Gym_Text_ExplainMindBadgeTakeThis:
	.string "TATE: MIND BADGE tăng cường SP. ATK và\n"
	.string "SP. DEF của POKéMON.\p"
	.string "LIZA: Nó cũng cho phép bạn sử dụng\n"
	.string "chiêu HM DIVE bên ngoài trận đấu.\p"
	.string "TATE: Bạn cũng nên nhận lấy thứ này.$"

MossdeepCity_Gym_Text_ExplainCalmMind:
	.string "TATE: Bên trong TM04 là... LIZA: CALM\n"
	.string "MIND!\p"
	.string "TATE: Nó tăng SP. ATK và... LIZA: Nó tăng\n"
	.string "SP. DEF!\p"
	.string "TATE: Đây là chiêu hoàn hảo... LIZA: Dành\n"
	.string "cho POKéMON hệ PSYCHIC!\p"
	.string "... ... ... ... ... ...$"

MossdeepCity_Gym_Text_RegisteredTateAndLiza:
	.string "Đã đăng ký GYM LEADERS TATE & LIZA vào\n"
	.string "POKéNAV.$"

MossdeepCity_Gym_Text_TateAndLizaPostBattle:
	.string "TATE: Có vẻ mối gắn kết giữa bạn và\n"
	.string "POKéMON còn mạnh hơn cả mối gắn kết\l"
	.string "song sinh của chúng tôi.\p"
	.string "LIZA: Bạn sẽ còn trở nên mạnh hơn nữa!\n"
	.string "Chúng tôi đã đấu với bạn nên biết rõ\l"
	.string "điều đó.$"

MossdeepCity_Gym_Text_TateAndLizaNeedTwoMons:
	.string "TATE: Hehehe... Bạn ngạc nhiên chứ?\p"
	.string "LIZA: Vì có đến hai GYM LEADERS?\p"
	.string "TATE: Ôi, bạn chỉ có một... LIZA: POKéMON\n"
	.string "có thể chiến đấu.\p"
	.string "TATE: Như vậy chúng tôi không thể đấu\n"
	.string "được!\p"
	.string "LIZA: Nếu muốn thách đấu, hãy mang theo\n"
	.string "thêm POKéMON.$"

MossdeepCity_Gym_Text_GymStatue:
	.string "MOSSDEEP CITY POKéMON GYM$"

MossdeepCity_Gym_Text_GymStatueCertified:
	.string "MOSSDEEP CITY POKéMON GYM\p"
	.string "HLV ĐƯỢC LIZA VÀ TATE CÔNG NHẬN:\n"
	.string "{PLAYER}$"

MossdeepCity_Gym_Text_TateAndLizaPreRematch:
	.string "TATE: POKéMON... LIZA: POKéMON...\p"
	.string "TATE: Khi thay đổi đội hình... LIZA:\n"
	.string "Phong cách chiến đấu cũng thay đổi.\p"
	.string "TATE: Nhưng tôi... LIZA: Nhưng tôi...\p"
	.string "TATE: Sẽ luôn ở bên LIZA! LIZA: Sẽ luôn\n"
	.string "ở bên TATE!\p"
	.string "TATE: Sự kết hợp của chúng tôi... LIZA:\n"
	.string "Sẽ được thể hiện hết lần này đến lần\l"
	.string "khác!$"

MossdeepCity_Gym_Text_TateAndLizaRematchDefeat:
	.string "TATE: Bạn và POKéMON của mình... LIZA:\n"
	.string "Cứ như anh chị em ruột vậy!$"

MossdeepCity_Gym_Text_TateAndLizaPostRematch:
	.string "TATE: Bạn có thể đánh ngã chúng tôi,\n"
	.string "nhưng chúng tôi sẽ luôn đứng dậy!\p"
	.string "LIZA: Vì hai chúng tôi lúc nào cũng nâng\n"
	.string "đỡ lẫn nhau!$"

MossdeepCity_Gym_Text_TateAndLizaRematchNeedTwoMons:
	.string "TATE: Bạn lại quay lại... LIZA: Bạn lại\n"
	.string "quay lại...\p"
	.string "TATE: Để tái đấu với chúng tôi. LIZA: Để\n"
	.string "tái đấu với chúng tôi.\p"
	.string "TATE: Nhưng... LIZA: Trong trận đấu\n"
	.string "này...\p"
	.string "TATE: Bạn chỉ mang theo một POKéMON!\n"
	.string "LIZA: Bạn chỉ mang theo một POKéMON!\p"
	.string "TATE: Khi quay lại, bạn cần mang theo ít\n"
	.string "nhất... LIZA: Hai POKéMON.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global MossdeepCity_Gym_Text_GymGuideAdvice
	.global MossdeepCity_Gym_Text_GymGuidePostVictory
	.global MossdeepCity_Gym_Text_PrestonIntro
	.global MossdeepCity_Gym_Text_PrestonDefeat
	.global MossdeepCity_Gym_Text_PrestonPostBattle
	.global MossdeepCity_Gym_Text_VirgilIntro
	.global MossdeepCity_Gym_Text_VirgilDefeat
	.global MossdeepCity_Gym_Text_VirgilPostBattle
	.global MossdeepCity_Gym_Text_BlakeIntro
	.global MossdeepCity_Gym_Text_BlakeDefeat
	.global MossdeepCity_Gym_Text_BlakePostBattle
	.global MossdeepCity_Gym_Text_HannahIntro
	.global MossdeepCity_Gym_Text_HannahDefeat
	.global MossdeepCity_Gym_Text_HannahPostBattle
	.global MossdeepCity_Gym_Text_SamanthaIntro
	.global MossdeepCity_Gym_Text_SamanthaDefeat
	.global MossdeepCity_Gym_Text_SamanthaPostBattle
	.global MossdeepCity_Gym_Text_MauraIntro
	.global MossdeepCity_Gym_Text_MauraDefeat
	.global MossdeepCity_Gym_Text_MauraPostBattle
	.global MossdeepCity_Gym_Text_SylviaIntro
	.global MossdeepCity_Gym_Text_SylviaDefeat
	.global MossdeepCity_Gym_Text_SylviaPostBattle
	.global MossdeepCity_Gym_Text_NateIntro
	.global MossdeepCity_Gym_Text_NateDefeat
	.global MossdeepCity_Gym_Text_NatePostBattle
	.global MossdeepCity_Gym_Text_KathleenIntro
	.global MossdeepCity_Gym_Text_KathleenDefeat
	.global MossdeepCity_Gym_Text_KathleenPostBattle
	.global MossdeepCity_Gym_Text_CliffordIntro
	.global MossdeepCity_Gym_Text_CliffordDefeat
	.global MossdeepCity_Gym_Text_CliffordPostBattle
	.global MossdeepCity_Gym_Text_MaceyIntro
	.global MossdeepCity_Gym_Text_MaceyDefeat
	.global MossdeepCity_Gym_Text_MaceyPostBattle
	.global MossdeepCity_Gym_Text_NicholasIntro
	.global MossdeepCity_Gym_Text_NicholasDefeat
	.global MossdeepCity_Gym_Text_NicholasPostBattle
	.global MossdeepCity_Gym_Text_TateAndLizaIntro
	.global MossdeepCity_Gym_Text_TateAndLizaDefeat
	.global MossdeepCity_Gym_Text_ReceivedMindBadge
	.global MossdeepCity_Gym_Text_ExplainMindBadgeTakeThis
	.global MossdeepCity_Gym_Text_ExplainCalmMind
	.global MossdeepCity_Gym_Text_RegisteredTateAndLiza
	.global MossdeepCity_Gym_Text_TateAndLizaPostBattle
	.global MossdeepCity_Gym_Text_TateAndLizaNeedTwoMons
	.global MossdeepCity_Gym_Text_GymStatueCertified
	.global MossdeepCity_Gym_Text_TateAndLizaPreRematch
	.global MossdeepCity_Gym_Text_TateAndLizaRematchDefeat
	.global MossdeepCity_Gym_Text_TateAndLizaPostRematch
	.global MossdeepCity_Gym_Text_TateAndLizaRematchNeedTwoMons
@ END GENERATED LOCALIZATION EXPORTS
