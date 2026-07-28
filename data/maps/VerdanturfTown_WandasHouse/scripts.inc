VerdanturfTown_WandasHouse_MapScripts::
	.byte 0

VerdanturfTown_WandasHouse_EventScript_Wally::
	lock
	faceplayer
	goto_if_set FLAG_WALLY_SPEECH, VerdanturfTown_WandasHouse_EventScript_WallyShortSpeech
	msgbox VerdanturfTown_WandasHouse_Text_StrongerSpeech, MSGBOX_DEFAULT
	setflag FLAG_WALLY_SPEECH
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallyShortSpeech::
	msgbox VerdanturfTown_WandasHouse_Text_StrongerSpeechShort, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysUncle::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, VerdanturfTown_WandasHouse_EventScript_WallysUncleEverGrande
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, VerdanturfTown_WandasHouse_EventScript_WallysUncleSlippedOff
	msgbox VerdanturfTown_WandasHouse_Text_WallysNextDoor, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysUncleSlippedOff::
	msgbox VerdanturfTown_WandasHouse_Text_WallySlippedOff, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysUncleEverGrande::
	msgbox VerdanturfTown_WandasHouse_Text_WallyGoneThatFar, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WandasBoyfriend::
	msgbox VerdanturfTown_WandasHouse_Text_CanSeeGirlfriendEveryDay, MSGBOX_NPC
	end

VerdanturfTown_WandasHouse_EventScript_Wanda::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, VerdanturfTown_WandasHouse_EventScript_WandaDontWorry
	goto_if_set FLAG_DEFEATED_WALLY_MAUVILLE, VerdanturfTown_WandasHouse_EventScript_MeetWanda
	msgbox VerdanturfTown_WandasHouse_Text_DontWorryAboutWally, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_MeetWanda::
	msgbox VerdanturfTown_WandasHouse_Text_MeetWanda, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WandaDontWorry::
	msgbox VerdanturfTown_WandasHouse_Text_DontWorryAboutWally, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAunt::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, VerdanturfTown_WandasHouse_EventScript_WallysAuntEverGrande
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, VerdanturfTown_WandasHouse_EventScript_WallysAuntAnythingHappened
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_WandasHouse_EventScript_WallysAuntTunnelOpen
	msgbox VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendDriven, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAuntTunnelOpen::
	msgbox VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendWasDigging, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAuntAnythingHappened::
	msgbox VerdanturfTown_WandasHouse_Text_IfAnythingHappenedToWally, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAuntEverGrande::
	msgbox VerdanturfTown_WandasHouse_Text_WallyWasInEverGrande, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_Text_StrongerSpeech:
	.string "WALLY: Tớ đã thua cậu, {PLAYER},\n"
	.string "nhưng giờ tớ không còn buồn nữa.\p"
	.string "Vì tớ đã có một mục tiêu mới trong đời.\n"
	.string "Cùng với RALTS, tớ sẽ thách đấu các\l"
	.string "POKéMON GYM và trở thành một HLV\l"
	.string "xuất sắc.\p"
	.string "Hãy dõi theo tớ nhé, {PLAYER}. Tớ sẽ\n"
	.string "trở nên mạnh hơn cậu.\p"
	.string "Khi đó, tớ sẽ lại thách đấu với cậu.$"

VerdanturfTown_WandasHouse_Text_StrongerSpeechShort:
	.string "WALLY: Hãy dõi theo tớ nhé, {PLAYER}.\n"
	.string "Tớ sẽ trở nên mạnh hơn cậu.\p"
	.string "Khi đó, tớ sẽ lại thách đấu với cậu.$"

VerdanturfTown_WandasHouse_Text_WallysNextDoor:
	.string "CHÚ: Ồ! {PLAYER}{KUN}! WALLY đang ở\n"
	.string "nhà bên cạnh.\p"
	.string "Nhưng này cháu, chú có chuyện phải nói\n"
	.string "với cháu.\p"
	.string "Môi trường tự nhiên nơi đây rất tốt\n"
	.string "cho sức khỏe của WALLY.\p"
	.string "Có lẽ không chỉ nhờ môi trường. Biết\n"
	.string "đâu chính POKéMON đã mang lại hy vọng\l"
	.string "cho thằng bé.$"

VerdanturfTown_WandasHouse_Text_WallySlippedOff:
	.string "WALLY đi mất rồi... Thằng bé đã lặng lẽ đi\n"
	.string "một mình...$"

VerdanturfTown_WandasHouse_Text_WallyGoneThatFar:
	.string "CHÚ: Vậy sao? WALLY đã tự mình đi xa\n"
	.string "đến thế...\p"
	.string "Dù sao cũng phải công nhận thằng bé\n"
	.string "giỏi. Đúng là con trai của em chú.$"

VerdanturfTown_WandasHouse_Text_MeetWanda:
	.string "WANDA: Cậu là...? À, phải rồi, tớ hiểu rồi!\p"
	.string "Cậu chính là {PLAYER} mà WALLY đã kể\n"
	.string "với tớ.\p"
	.string "Tớ là chị họ của WALLY. Rất vui được\n"
	.string "gặp cậu!\p"
	.string "Tớ thấy WALLY đã khỏe mạnh và hoạt bát\n"
	.string "hơn nhiều kể từ khi đến đây.$"

VerdanturfTown_WandasHouse_Text_DontWorryAboutWally:
	.string "WANDA: Đừng lo cho WALLY. Em ấy sẽ ổn\n"
	.string "thôi.\p"
	.string "Tớ hiểu em họ mình, hơn nữa em ấy còn\n"
	.string "có POKéMON bên cạnh.$"

VerdanturfTown_WandasHouse_Text_CanSeeGirlfriendEveryDay:
	.string "Nhờ có bạn, ngày nào tôi cũng có thể\n"
	.string "gặp bạn gái. Có vui không ư? Dĩ nhiên là\l"
	.string "có rồi!$"

VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendDriven:
	.string "Bạn trai của con gái tôi là một chàng\n"
	.string "trai vô cùng quyết tâm và nhiệt huyết.\p"
	.string "Cậu ấy đào đường hầm không ngừng\n"
	.string "nghỉ chỉ để có thể gặp con gái tôi.\p"
	.string "Con gái tôi hơi lo cho cậu ấy nên\n"
	.string "thường xuyên ra đường hầm.$"

VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendWasDigging:
	.string "Thật đáng kinh ngạc. Bạn trai của con\n"
	.string "gái tôi đã đào đường hầm bằng tay\l"
	.string "không!\p"
	.string "Quả là phi thường!$"

VerdanturfTown_WandasHouse_Text_IfAnythingHappenedToWally:
	.string "Nếu WALLY xảy ra chuyện gì, tôi sẽ\n"
	.string "không bao giờ còn mặt mũi nhìn ba mẹ\l"
	.string "thằng bé ở PETALBURG...$"

VerdanturfTown_WandasHouse_Text_WallyWasInEverGrande:
	.string "WALLY đã đến EVER GRANDE sao?\p"
	.string "Ba mẹ thằng bé ở PETALBURG mà nghe tin\n"
	.string "này chắc sẽ kinh ngạc lắm!$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global VerdanturfTown_WandasHouse_Text_StrongerSpeech
	.global VerdanturfTown_WandasHouse_Text_StrongerSpeechShort
	.global VerdanturfTown_WandasHouse_Text_WallysNextDoor
	.global VerdanturfTown_WandasHouse_Text_WallySlippedOff
	.global VerdanturfTown_WandasHouse_Text_WallyGoneThatFar
	.global VerdanturfTown_WandasHouse_Text_MeetWanda
	.global VerdanturfTown_WandasHouse_Text_DontWorryAboutWally
	.global VerdanturfTown_WandasHouse_Text_CanSeeGirlfriendEveryDay
	.global VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendDriven
	.global VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendWasDigging
	.global VerdanturfTown_WandasHouse_Text_IfAnythingHappenedToWally
	.global VerdanturfTown_WandasHouse_Text_WallyWasInEverGrande
@ END GENERATED LOCALIZATION EXPORTS
