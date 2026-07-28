MeteorFalls_StevensCave_MapScripts::
	.byte 0

MeteorFalls_StevensCave_EventScript_Steven::
	lock
	goto_if_set FLAG_DEFEATED_METEOR_FALLS_STEVEN, MeteorFalls_StevensCave_EventScript_Defeated
	waitse
	playse SE_PIN
	applywaitmovement LOCALID_METEOR_FALLS_STEVEN, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_METEOR_FALLS_STEVEN, Common_Movement_Delay48
	applywaitmovement LOCALID_METEOR_FALLS_STEVEN, Common_Movement_FacePlayer
	msgbox MeteorFalls_StevensCave_Text_ShouldKnowHowGoodIAmExpectWorst, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_STEVEN, MeteorFalls_StevensCave_Text_StevenDefeat
	msgbox MeteorFalls_StevensCave_Text_MyPredictionCameTrue, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_METEOR_FALLS_STEVEN
	release
	end

MeteorFalls_StevensCave_EventScript_Defeated::
	applywaitmovement LOCALID_METEOR_FALLS_STEVEN, Common_Movement_FacePlayer
	msgbox MeteorFalls_StevensCave_Text_MyPredictionCameTrue, MSGBOX_DEFAULT
	release
	end

MeteorFalls_StevensCave_Text_ShouldKnowHowGoodIAmExpectWorst:
	.string "STEVEN: Ồ, tuyệt thật, {PLAYER}{KUN}.\n"
	.string "Anh rất ngạc nhiên khi em biết tìm anh\l"
	.string "ở đâu.\p"
	.string "Chẳng lẽ, ờ… em chỉ xem anh là một kẻ\n"
	.string "cuồng đá thôi sao?\p"
	.string "Không, chắc chắn không phải vậy.\p"
	.string "Chúng ta từng sát cánh chiến đấu tại\n"
	.string "SOOTOPOLIS SPACE CENTER.\p"
	.string "Hẳn em hiểu rất rõ thực lực của anh.\p"
	.string "Được rồi, {PLAYER}{KUN}, nếu định\n"
	.string "nghiêm túc thách đấu, hãy chuẩn bị cho\l"
	.string "tình huống tồi tệ nhất!$"

MeteorFalls_StevensCave_Text_StevenDefeat:
	.string "Em… Anh không ngờ em đã trở nên\n"
	.string "mạnh đến vậy…$"

MeteorFalls_StevensCave_Text_MyPredictionCameTrue:
	.string "STEVEN: Nghĩ lại thì ngay từ lần đầu\n"
	.string "chúng ta gặp nhau tại GRANITE CAVE ở\l"
	.string "DEWFORD, anh đã có linh cảm này.\p"
	.string "Anh nghĩ rồi sẽ có ngày em trở thành\n"
	.string "CHAMPION.\p"
	.string "Những dự đoán của anh thường thành\n"
	.string "sự thật.\p"
	.string "Từ đây, em sẽ đi về đâu?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Fufufu, ngay cả anh cũng không thể nói\n"
	.string "cho em biết.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global MeteorFalls_StevensCave_Text_ShouldKnowHowGoodIAmExpectWorst
	.global MeteorFalls_StevensCave_Text_StevenDefeat
	.global MeteorFalls_StevensCave_Text_MyPredictionCameTrue
@ END GENERATED LOCALIZATION EXPORTS
