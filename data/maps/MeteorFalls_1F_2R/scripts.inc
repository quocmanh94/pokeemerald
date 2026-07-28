MeteorFalls_1F_2R_MapScripts::
	.byte 0

MeteorFalls_1F_2R_EventScript_Nicolas::
	trainerbattle_single TRAINER_NICOLAS_1, MeteorFalls_1F_2R_Text_NicolasIntro, MeteorFalls_1F_2R_Text_NicolasDefeat, MeteorFalls_1F_2R_EventScript_RegisterNicolas
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MeteorFalls_1F_2R_EventScript_RematchNicolas
	msgbox MeteorFalls_1F_2R_Text_NicolasPostBattle, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_2R_EventScript_RegisterNicolas::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MeteorFalls_1F_2R_Text_NicolasRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_NICOLAS_1
	release
	end

MeteorFalls_1F_2R_EventScript_RematchNicolas::
	trainerbattle_rematch TRAINER_NICOLAS_1, MeteorFalls_1F_2R_Text_NicolasRematchIntro, MeteorFalls_1F_2R_Text_NicolasRematchDefeat
	msgbox MeteorFalls_1F_2R_Text_NicolasPostRematch, MSGBOX_AUTOCLOSE
	end

MeteorFalls_1F_2R_EventScript_John::
	trainerbattle_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JohnIntro, MeteorFalls_1F_2R_Text_JohnDefeat, MeteorFalls_1F_2R_Text_JohnNotEnoughMons, MeteorFalls_1F_2R_EventScript_RegisterJohn
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MeteorFalls_1F_2R_EventScript_RematchJohn
	msgbox MeteorFalls_1F_2R_Text_JohnPostBattle, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_2R_EventScript_RegisterJohn::
	msgbox MeteorFalls_1F_2R_Text_JohnRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_JOHN_AND_JAY_1
	release
	end

MeteorFalls_1F_2R_EventScript_RematchJohn::
	trainerbattle_rematch_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JohnRematchIntro, MeteorFalls_1F_2R_Text_JohnRematchDefeat, MeteorFalls_1F_2R_Text_JohnRematchNotEnoughMons
	msgbox MeteorFalls_1F_2R_Text_JohnPostRematch, MSGBOX_AUTOCLOSE
	end

MeteorFalls_1F_2R_EventScript_Jay::
	trainerbattle_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JayIntro, MeteorFalls_1F_2R_Text_JayDefeat, MeteorFalls_1F_2R_Text_JayNotEnoughMons, MeteorFalls_1F_2R_EventScript_RegisterJay
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MeteorFalls_1F_2R_EventScript_RematchJay
	msgbox MeteorFalls_1F_2R_Text_JayPostBattle, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_2R_EventScript_RegisterJay::
	msgbox MeteorFalls_1F_2R_Text_JohnRegister, MSGBOX_DEFAULT  @ John speaks for both during register
	register_matchcall TRAINER_JOHN_AND_JAY_1
	release
	end

MeteorFalls_1F_2R_EventScript_RematchJay::
	trainerbattle_rematch_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JayRematchIntro, MeteorFalls_1F_2R_Text_JayRematchDefeat, MeteorFalls_1F_2R_Text_JayRematchNotEnoughMons
	msgbox MeteorFalls_1F_2R_Text_JayPostRematch, MSGBOX_AUTOCLOSE
	end

MeteorFalls_1F_2R_Text_NicolasIntro:
	.string "Đây là nơi những người sử dụng DRAGON\n"
	.string "như chúng tôi rèn luyện.\p"
	.string "Ngay cả CHAMPION cũng ghé qua. Giờ bạn\n"
	.string "hiểu nơi này đặc biệt thế nào chưa?$"

MeteorFalls_1F_2R_Text_NicolasDefeat:
	.string "Ư! Tôi không ngờ bạn lại mạnh đến thế!$"

MeteorFalls_1F_2R_Text_NicolasPostBattle:
	.string "Con đường phía trước vẫn còn dài và\n"
	.string "khắc nghiệt.\p"
	.string "Bao giờ tôi và POKéMON của mình mới\n"
	.string "trở thành số một đây?$"

MeteorFalls_1F_2R_Text_NicolasRegister:
	.string "Tôi muốn biết thêm về sức mạnh của bạn.\n"
	.string "Hãy để tôi đăng ký bạn vào POKéNAV.$"

MeteorFalls_1F_2R_Text_NicolasRematchIntro:
	.string "Từ ngày gặp bạn, chúng tôi đã chăm chỉ\n"
	.string "rèn luyện với mục tiêu trở thành số\l"
	.string "một.\p"
	.string "Hãy giúp chúng tôi xem mình đã mạnh lên\n"
	.string "bao nhiêu!$"

MeteorFalls_1F_2R_Text_NicolasRematchDefeat:
	.string "Ư! Tôi không ngờ bạn lại mạnh đến thế!$"

MeteorFalls_1F_2R_Text_NicolasPostRematch:
	.string "Rõ ràng bạn vẫn luôn chăm chỉ rèn luyện\n"
	.string "POKéMON.\p"
	.string "Chỉ cần bạn còn mạnh mẽ, tôi cũng có thể\n"
	.string "trở nên mạnh hơn!$"

MeteorFalls_1F_2R_Text_JohnIntro:
	.string "JOHN: Hai vợ chồng chúng tôi luôn cùng\n"
	.string "nhau chiến đấu với POKéMON. Chúng tôi\l"
	.string "rất tự tin vào bản thân.$"

MeteorFalls_1F_2R_Text_JohnDefeat:
	.string "JOHN: Ôi chao. Chúng ta thua rồi, bà nhà\n"
	.string "ơi.$"

MeteorFalls_1F_2R_Text_JohnPostBattle:
	.string "JOHN: Chúng tôi đã kết hôn được năm\n"
	.string "mươi năm.\p"
	.string "Nghĩ lại thì tôi vẫn chưa từng thắng bà\n"
	.string "nhà trong một trận đấu.$"

MeteorFalls_1F_2R_Text_JohnNotEnoughMons:
	.string "JOHN: Chà chà, một HLV trẻ tuổi!\p"
	.string "Bạn có muốn đấu với chúng tôi không?\n"
	.string "Nếu muốn, hãy quay lại khi có nhiều\l"
	.string "POKéMON hơn.$"

MeteorFalls_1F_2R_Text_JohnRegister:
	.string "JOHN: HLV trẻ tuổi, nếu có dịp, bạn\n"
	.string "sẽ lại đấu với chúng tôi chứ?$"

MeteorFalls_1F_2R_Text_JayIntro:
	.string "JAY: Chúng tôi đã kết hôn được năm\n"
	.string "mươi năm.\p"
	.string "Mối gắn kết vợ chồng giữa chúng tôi\n"
	.string "không gì có thể phá vỡ.$"

MeteorFalls_1F_2R_Text_JayDefeat:
	.string "JAY: Ôi trời. Chúng ta thua rồi, ông nhà\n"
	.string "ơi.$"

MeteorFalls_1F_2R_Text_JayPostBattle:
	.string "JAY: Năm mươi năm chung sống...\p"
	.string "Mỗi khi bất hòa, vợ chồng tôi luôn giải\n"
	.string "quyết bằng một trận đấu POKéMON...$"

MeteorFalls_1F_2R_Text_JayNotEnoughMons:
	.string "JAY: Chà chà, một HLV trẻ tuổi đây\n"
	.string "mà!\p"
	.string "Nếu muốn đấu với vợ chồng tôi, cháu\n"
	.string "phải quay lại cùng nhiều POKéMON hơn.$"

MeteorFalls_1F_2R_Text_JohnRematchIntro:
	.string "JOHN: Vợ chồng tôi luôn sát cánh cùng\n"
	.string "nhau trong các trận đấu POKéMON. Chúng\l"
	.string "tôi rất tự tin vào bản thân.$"

MeteorFalls_1F_2R_Text_JohnRematchDefeat:
	.string "JOHN: Ôi chao. Chúng ta thua rồi, bà nó ạ.$"

MeteorFalls_1F_2R_Text_JohnPostRematch:
	.string "JOHN: Năm mươi năm vợ chồng...\p"
	.string "Nghĩ lại thì bà nó và tôi đã đấu với\n"
	.string "nhau hết ngày này qua ngày khác...$"

MeteorFalls_1F_2R_Text_JohnRematchNotEnoughMons:
	.string "JOHN: Chà chà, một HLV trẻ tuổi làm\n"
	.string "sao!\p"
	.string "Cháu muốn đấu với vợ chồng tôi chứ?\n"
	.string "Nếu vậy, hãy quay lại cùng nhiều\l"
	.string "POKéMON hơn.$"

MeteorFalls_1F_2R_Text_JayRematchIntro:
	.string "JAY: Vợ chồng tôi đã chung sống được\n"
	.string "năm mươi năm.\p"
	.string "Suốt thời gian ấy, chúng tôi luôn nâng\n"
	.string "đỡ nhau và cùng trở nên mạnh mẽ.$"

MeteorFalls_1F_2R_Text_JayRematchDefeat:
	.string "JAY: Ôi chao. Chúng ta thua rồi, ông nó ạ.$"

MeteorFalls_1F_2R_Text_JayPostRematch:
	.string "JAY: Năm mươi năm chung sống... Biết bao\n"
	.string "chuyện đã xảy ra.\p"
	.string "Tôi mong vợ chồng mình sẽ tiếp tục cùng\n"
	.string "nhau tạo nên những kỷ niệm vui vẻ.$"

MeteorFalls_1F_2R_Text_JayRematchNotEnoughMons:
	.string "JAY: Chà chà, một HLV trẻ tuổi đây\n"
	.string "mà!\p"
	.string "Nếu muốn đấu với vợ chồng tôi, cháu\n"
	.string "phải quay lại cùng nhiều POKéMON hơn.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global MeteorFalls_1F_2R_Text_NicolasIntro
	.global MeteorFalls_1F_2R_Text_NicolasDefeat
	.global MeteorFalls_1F_2R_Text_NicolasPostBattle
	.global MeteorFalls_1F_2R_Text_NicolasRegister
	.global MeteorFalls_1F_2R_Text_NicolasRematchIntro
	.global MeteorFalls_1F_2R_Text_NicolasRematchDefeat
	.global MeteorFalls_1F_2R_Text_NicolasPostRematch
	.global MeteorFalls_1F_2R_Text_JohnIntro
	.global MeteorFalls_1F_2R_Text_JohnDefeat
	.global MeteorFalls_1F_2R_Text_JohnPostBattle
	.global MeteorFalls_1F_2R_Text_JohnNotEnoughMons
	.global MeteorFalls_1F_2R_Text_JohnRegister
	.global MeteorFalls_1F_2R_Text_JayIntro
	.global MeteorFalls_1F_2R_Text_JayDefeat
	.global MeteorFalls_1F_2R_Text_JayPostBattle
	.global MeteorFalls_1F_2R_Text_JayNotEnoughMons
	.global MeteorFalls_1F_2R_Text_JohnRematchIntro
	.global MeteorFalls_1F_2R_Text_JohnRematchDefeat
	.global MeteorFalls_1F_2R_Text_JohnPostRematch
	.global MeteorFalls_1F_2R_Text_JohnRematchNotEnoughMons
	.global MeteorFalls_1F_2R_Text_JayRematchIntro
	.global MeteorFalls_1F_2R_Text_JayRematchDefeat
	.global MeteorFalls_1F_2R_Text_JayPostRematch
	.global MeteorFalls_1F_2R_Text_JayRematchNotEnoughMons
@ END GENERATED LOCALIZATION EXPORTS
