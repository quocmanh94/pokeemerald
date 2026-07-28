RustboroCity_Gym_MapScripts::
	.byte 0

RustboroCity_Gym_EventScript_Roxanne::
	trainerbattle_single TRAINER_ROXANNE_1, RustboroCity_Gym_Text_RoxanneIntro, RustboroCity_Gym_Text_RoxanneDefeat, RustboroCity_Gym_EventScript_RoxanneDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Gym_EventScript_RoxanneRematch
	goto_if_unset FLAG_RECEIVED_TM_ROCK_TOMB, RustboroCity_Gym_EventScript_GiveRockTomb
	msgbox RustboroCity_Gym_Text_RoxannePostBattle, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_RoxanneDefeated::
	message RustboroCity_Gym_Text_ReceivedStoneBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox RustboroCity_Gym_Text_StoneBadgeInfoTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_RUSTBORO_GYM
	setflag FLAG_BADGE01_GET
	setvar VAR_RUSTBORO_CITY_STATE, 1
	addvar VAR_PETALBURG_GYM_STATE, 1
	setvar VAR_0x8008, 1
	call Common_EventScript_SetGymTrainers
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	goto RustboroCity_Gym_EventScript_GiveRockTomb
	end

RustboroCity_Gym_EventScript_GiveRockTomb::
	giveitem ITEM_TM_ROCK_TOMB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_ROCK_TOMB
	msgbox RustboroCity_Gym_Text_ExplainRockTomb, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_RoxanneRematch::
	trainerbattle_rematch_double TRAINER_ROXANNE_1, RustboroCity_Gym_Text_RoxannePreRematch, RustboroCity_Gym_Text_RoxanneRematchDefeat, RustboroCity_Gym_Text_RoxanneRematchNeedTwoMons
	msgbox RustboroCity_Gym_Text_RoxannePostRematch, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Josh::
	trainerbattle_single TRAINER_JOSH, RustboroCity_Gym_Text_JoshIntro, RustboroCity_Gym_Text_JoshDefeat
	msgbox RustboroCity_Gym_Text_JoshPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Tommy::
	trainerbattle_single TRAINER_TOMMY, RustboroCity_Gym_Text_TommyIntro, RustboroCity_Gym_Text_TommyDefeat
	msgbox RustboroCity_Gym_Text_TommyPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Marc::
	trainerbattle_single TRAINER_MARC, RustboroCity_Gym_Text_MarcIntro, RustboroCity_Gym_Text_MarcDefeat
	msgbox RustboroCity_Gym_Text_MarcPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_RUSTBORO_GYM, RustboroCity_Gym_EventScript_GymGuidePostVictory
	msgbox RustboroCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_GymGuidePostVictory::
	msgbox RustboroCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_GymStatueCertified
	goto RustboroCity_Gym_EventScript_GymStatue
	end

RustboroCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_GymStatueCertified
	goto RustboroCity_Gym_EventScript_GymStatue
	end

RustboroCity_Gym_EventScript_GymStatueCertified::
	msgbox RustboroCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_Gym_EventScript_GymStatue::
	msgbox RustboroCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_Gym_EventScript_RegisterRoxanne::
	lockall
	pokenavcall RustboroCity_Gym_Text_RoxanneRegisterCall
	waitmessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox RustboroCity_Gym_Text_RegisteredRoxanne, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_ROXANNE_MATCH_CALL
	clearflag FLAG_ENABLE_ROXANNE_FIRST_CALL
	releaseall
	end

RustboroCity_Gym_Text_GymGuideAdvice:
	.string "Chào nhé, mọi chuyện ổn chứ?\p"
	.string "Nghe này, bạn tôi! Bạn có muốn trở\n"
	.string "thành CHAMPION không?\p"
	.string "Tôi không phải HLV, nhưng chắc\n"
	.string "chắn có thể cho bạn lời khuyên để chiến\l"
	.string "thắng.\p"
	.string "Quyết định vậy nhé! Chúng ta sẽ cùng\n"
	.string "hướng tới POKéMON CHAMPIONSHIP!\p"
	.string "Nhiệm vụ của một HLV là thu thập\n"
	.string "GYM BADGES, đúng chứ?\p"
	.string "Nhưng GYM LEADERS không phải đối thủ\n"
	.string "dễ chơi!\p"
	.string "Và đó là lúc tôi ra tay! Tôi ở đây để\n"
	.string "đưa ra lời khuyên chuyên môn!\p"
	.string "GYM LEADER ROXANNE sử dụng POKéMON hệ\n"
	.string "ROCK.\p"
	.string "Hệ ROCK rất bền bỉ, nhưng không chịu\n"
	.string "nổi các chiêu hệ WATER và GRASS.\p"
	.string "Nếu đánh bại GYM LEADER, hãy quay lại\n"
	.string "gặp tôi.\p"
	.string "Nào, cố lên!$"

RustboroCity_Gym_Text_GymGuidePostVictory:
	.string "Chà! Một chiến thắng thật ngoạn mục!\n"
	.string "Chắc lời cổ vũ của tôi đã có tác dụng!\p"
	.string "Tuyệt lắm! Hãy xem TRAINER CARD của\n"
	.string "bạn.\p"
	.string "STONE BADGE bạn vừa nhận chắc đã\n"
	.string "được ghi lại đàng hoàng trên đó.\p"
	.string "Nói cách khác...\p"
	.string "Bạn đã bước lên bậc đầu tiên của cầu\n"
	.string "thang dẫn tới CHAMPIONSHIP!\p"
	.string "Cảm giác hẳn tuyệt lắm!$"

RustboroCity_Gym_Text_JoshIntro:
	.string "Đừng xem thường HLV GYM bọn tôi!\n"
	.string "Tôi sẽ cho bạn thấy vì sao chúng tôi\l"
	.string "vượt trội!$"

RustboroCity_Gym_Text_JoshDefeat:
	.string "Bạn giỏi hơn tôi quá nhiều...$"

RustboroCity_Gym_Text_JoshPostBattle:
	.string "Bạn vẫn chưa thấy sức mạnh đáng sợ\n"
	.string "của hệ ROCK đâu!$"

RustboroCity_Gym_Text_TommyIntro:
	.string "Nếu không thắng nổi tôi, bạn chẳng có\n"
	.string "cơ hội nào trước ROXANNE đâu!$"

RustboroCity_Gym_Text_TommyDefeat:
	.string "Chà! Bạn có tiềm năng đấy!$"

RustboroCity_Gym_Text_TommyPostBattle:
	.string "ROXANNE mạnh hơn tôi gấp mấy lần.\p"
	.string "Tốt nhất bạn nên cảnh giác!$"

RustboroCity_Gym_Text_MarcIntro:
	.string "Đang ở giữa thành phố thì đã sao?\p"
	.string "POKéMON hệ ROCK của tôi cần chỗ để\n"
	.string "tung hoành!$"

RustboroCity_Gym_Text_MarcDefeat:
	.string "Trời ơi là trời! Người thách đấu của\n"
	.string "chúng ta gan lì thật đấy!$"

RustboroCity_Gym_Text_MarcPostBattle:
	.string "Tôi phải công nhận LEADER của chúng\n"
	.string "tôi.\p"
	.string "Còn trẻ như vậy mà chọn hệ ROCK thì\n"
	.string "phải rất thông minh và sáng suốt.$"

RustboroCity_Gym_Text_RoxanneIntro:
	.string "Xin chào, tôi là ROXANNE, GYM LEADER của\n"
	.string "RUSTBORO POKéMON GYM.\p"
	.string "Tôi trở thành GYM LEADER để vận dụng\n"
	.string "những gì đã học tại POKéMON TRAINER'S\l"
	.string "SCHOOL vào chiến đấu.\p"
	.string "Xin bạn hãy cho tôi xem cách bạn chiến\n"
	.string "đấu và những POKéMON bạn sử dụng.$"

RustboroCity_Gym_Text_RoxanneDefeat:
	.string "Vậy là... Tôi đã thua...\p"
	.string "Có vẻ tôi vẫn còn rất nhiều điều phải\n"
	.string "học...\p"
	.string "Tôi hiểu rồi.\p"
	.string "Theo quy định của POKéMON LEAGUE,\n"
	.string "HLV đánh bại một GYM LEADER sẽ\l"
	.string "được trao thứ này.\p"
	.string "Xin hãy nhận STONE BADGE chính thức\n"
	.string "của POKéMON LEAGUE.$"

RustboroCity_Gym_Text_ReceivedStoneBadge:
	.string "{PLAYER} đã nhận STONE BADGE từ\n"
	.string "ROXANNE.$"

RustboroCity_Gym_Text_StoneBadgeInfoTakeThis:
	.string "STONE BADGE tăng sức mạnh ATTACK của\n"
	.string "POKéMON.\p"
	.string "Nó cũng cho phép chúng sử dụng chiêu\n"
	.string "HM CUT ngoài trận đấu.\p"
	.string "Xin hãy nhận cả thứ này nữa.$"

RustboroCity_Gym_Text_ExplainRockTomb:
	.string "TECHNICAL MACHINE đó, TM39, chứa ROCK\n"
	.string "TOMB.\p"
	.string "Chiêu này không chỉ gây sát thương\n"
	.string "bằng cách thả đá xuống mà còn làm giảm\l"
	.string "SPEED.\p"
	.string "Khi sử dụng TM, bạn sẽ lập tức dạy chiêu\n"
	.string "đó cho một POKéMON.\p"
	.string "Hãy nhớ rằng mỗi TM chỉ dùng được một\n"
	.string "lần, nên hãy suy nghĩ trước khi sử\l"
	.string "dụng.$"

RustboroCity_Gym_Text_RoxannePostBattle:
	.string "Vì bạn rất mạnh, bạn nên thách đấu các\n"
	.string "GYM LEADERS khác.\p"
	.string "Qua việc chiến đấu với nhiều HLV,\n"
	.string "bạn sẽ học được rất nhiều điều.$"

RustboroCity_Gym_Text_GymStatue:
	.string "RUSTBORO CITY POKéMON GYM$"

RustboroCity_Gym_Text_GymStatueCertified:
	.string "RUSTBORO CITY POKéMON GYM\p"
	.string "HLV được ROXANNE công nhận:\n"
	.string "{PLAYER}$"

RustboroCity_Gym_Text_RoxanneRegisterCall:
	.string "... ... ... ... ... ... ... ... ... ... ... Bíp!\p"
	.string "ROXANNE: A lô, {PLAYER} phải không?\n"
	.string "Tôi là ROXANNE ở RUSTBORO CITY.\p"
	.string "Tôi nghe BRAWLY nói rằng bạn đang\n"
	.string "thăng tiến trong hàng ngũ HLV với\l"
	.string "tốc độ đáng kinh ngạc.\p"
	.string "Tôi không muốn nghĩ rằng mình không\n"
	.string "thể đánh bại bạn.\p"
	.string "Tôi hứa sẽ rèn luyện GYM của mình để\n"
	.string "bạn có thể quay lại thách đấu chúng tôi.\p"
	.string "Mong rằng bạn cũng háo hức chờ ngày đó\n"
	.string "như tôi!\p"
	.string "... ... ... ... ... ... ... ... ... ... ... Cạch!$"

RustboroCity_Gym_Text_RegisteredRoxanne:
	.string "Đã đăng ký GYM LEADER ROXANNE vào\n"
	.string "POKéNAV.$"

RustboroCity_Gym_Text_RoxannePreRematch:
	.string "ROXANNE: Tôi rất vui được gặp lại bạn.\n"
	.string "Tôi là ROXANNE, GYM LEADER ở đây.\p"
	.string "Tôi chắc rằng cả hai chúng ta đều đã\n"
	.string "trải qua nhiều trận chiến kể từ lần gặp\l"
	.string "trước.\p"
	.string "Tôi muốn xem chúng ta đã tiến bộ đến\n"
	.string "đâu. Hãy chiến đấu nào!$"

RustboroCity_Gym_Text_RoxanneRematchDefeat:
	.string "Gừ... Tôi lại thua rồi...$"

RustboroCity_Gym_Text_RoxannePostRematch:
	.string "ROXANNE: Tôi vẫn còn rất nhiều điều phải\n"
	.string "học về chiến đấu POKéMON.\p"
	.string "Càng nhận thức rõ điều đó, tôi lại càng\n"
	.string "yêu thích chiến đấu hơn!$"

RustboroCity_Gym_Text_RoxanneRematchNeedTwoMons:
	.string "ROXANNE: Tôi rất vui được gặp lại bạn.\n"
	.string "Tôi là ROXANNE, GYM LEADER ở đây.\p"
	.string "Tôi chắc rằng cả hai chúng ta đều đã\n"
	.string "trải qua nhiều trận chiến kể từ lần gặp\l"
	.string "trước.\p"
	.string "Tôi muốn xem chúng ta đã tiến bộ đến\n"
	.string "đâu...\p"
	.string "Ôi, không... Bạn chỉ mang theo một\n"
	.string "POKéMON thôi sao?\p"
	.string "Xin hãy quay lại khi có thêm ít nhất một\n"
	.string "POKéMON nữa.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global RustboroCity_Gym_Text_GymGuideAdvice
	.global RustboroCity_Gym_Text_GymGuidePostVictory
	.global RustboroCity_Gym_Text_JoshIntro
	.global RustboroCity_Gym_Text_JoshDefeat
	.global RustboroCity_Gym_Text_JoshPostBattle
	.global RustboroCity_Gym_Text_TommyIntro
	.global RustboroCity_Gym_Text_TommyDefeat
	.global RustboroCity_Gym_Text_TommyPostBattle
	.global RustboroCity_Gym_Text_MarcIntro
	.global RustboroCity_Gym_Text_MarcDefeat
	.global RustboroCity_Gym_Text_MarcPostBattle
	.global RustboroCity_Gym_Text_RoxanneIntro
	.global RustboroCity_Gym_Text_RoxanneDefeat
	.global RustboroCity_Gym_Text_ReceivedStoneBadge
	.global RustboroCity_Gym_Text_StoneBadgeInfoTakeThis
	.global RustboroCity_Gym_Text_ExplainRockTomb
	.global RustboroCity_Gym_Text_RoxannePostBattle
	.global RustboroCity_Gym_Text_GymStatueCertified
	.global RustboroCity_Gym_Text_RoxanneRegisterCall
	.global RustboroCity_Gym_Text_RegisteredRoxanne
	.global RustboroCity_Gym_Text_RoxannePreRematch
	.global RustboroCity_Gym_Text_RoxanneRematchDefeat
	.global RustboroCity_Gym_Text_RoxannePostRematch
	.global RustboroCity_Gym_Text_RoxanneRematchNeedTwoMons
@ END GENERATED LOCALIZATION EXPORTS
