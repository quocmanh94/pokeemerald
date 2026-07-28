@ All the LOCALID constants used in this file are essentially redundant.
@ They're all used to have the NPC the player talked to turn back so they're facing
@ their original direction (because they're watching/participating in the contests).
@ They could all be substituted for VAR_LAST_TALKED.
LilycoveCity_ContestHall_MapScripts::
	.byte 0

LilycoveCity_ContestHall_EventScript_Boy1::
	msgbox LilycoveCity_ContestHall_Text_TodayWonSmartnessContest, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_Boy2::
	msgbox LilycoveCity_ContestHall_Text_EnteredBunchOfContests, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_Girl::
	msgbox LilycoveCity_ContestHall_Text_ManWhoWonEarlierHadPokeblocks, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_Sailor::
	msgbox LilycoveCity_ContestHall_Text_IsntThisPlaceHumongous, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_SmartContestMC::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_GiveItBestSmartAppeal, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_MC, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestJudge::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_AreYouEnjoyingThisContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_JUDGE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant1::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_EnteredWrongContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_RaisedMonToBeSmart, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_IfMonPullsSmartMoveNext, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant4::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_DontAppreciateCuteLeechLife, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience1::
	msgbox LilycoveCity_ContestHall_Text_YoureBeautifulGrandpa, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_AllSeemToUseDifferentMoves, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_AUDIENCE_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_PokemonSmarterThanTrainers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_AUDIENCE_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience4::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_StillLoveSmartnessContests, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_AUDIENCE_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestMC::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_AreYouEnteringBeautyContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_MC, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestJudge::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_EveryPokemonPristineBeauty, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_JUDGE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant1::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_EyesWillBeGluedToMyBeauty, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_OverdidGrooming, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_JudgeWontSeeAuroraBeam, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant4::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_PokemonLooksLikeYoungerMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestAudience1::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_WinBeautyContestMakesMeHappy, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_AUDIENCE_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestAudience2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_GanderAtAllThosePrettyPokemon, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_AUDIENCE_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestAudience3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_CantWinOnBeautyAlone, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_AUDIENCE_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestMC::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_InTheMiddleOfContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_MC, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestJudge::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_SuchCharmingCuteAppeals, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_JUDGE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant1::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_MyAzurillWasDistracted, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_NeverWonBattleButContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_PetalDanceIsMarvel, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant4::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_MyMonAppealSoMuchCuter, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestAudience1::
	lockall
	applymovement LOCALID_CUTE_AUDIENCE_1, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_ContestHall_Text_MyChildIsInContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_AUDIENCE_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	delay 25
	msgbox LilycoveCity_ContestHall_Text_ComeOnDear, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_ContestHall_EventScript_CuteContestAudience2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_WantCuteMonOfMyOwn, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_AUDIENCE_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestAudience3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_ThatGirlThereIsCutest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_AUDIENCE_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyStageSign::
	msgbox LilycoveCity_ContestHall_Text_BeautyContestStage, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_EventScript_CuteStageSign::
	msgbox LilycoveCity_ContestHall_Text_CuteContestStage, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_EventScript_SmartStageSign::
	msgbox LilycoveCity_ContestHall_Text_SmartContestStage, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_Text_TodayWonSmartnessContest:
	.string "POKéMON này từng thắng BEAUTY\n"
	.string "CONTEST ở đây.\p"
	.string "Và bạn đoán xem? Hôm nay, tôi còn giúp\n"
	.string "nó thắng cả SMARTNESS CONTEST!\p"
	.string "Đến tôi cũng phải sợ tài năng của chính\n"
	.string "mình...$"

LilycoveCity_ContestHall_Text_EnteredBunchOfContests:
	.string "Tôi đã tham gia nhiều cuộc thi nên\n"
	.string "cũng dần hiểu được cách thi đấu.\p"
	.string "Trong COOLNESS CONTEST, những chiêu\n"
	.string "thật ngầu sẽ gây ấn tượng khi biểu\l"
	.string "diễn.\p"
	.string "Nhưng chẳng hạn, những chiêu thông\n"
	.string "minh hay dễ thương lại không được\l"
	.string "đánh giá cao.$"

LilycoveCity_ContestHall_Text_ManWhoWonEarlierHadPokeblocks:
	.string "Chàng trai trẻ thắng lúc nãy có cả đống\n"
	.string "{POKEBLOCK}S đủ loại.\p"
	.string "Chỉ cần có nhiều đến thế là sẽ thắng\n"
	.string "sao?$"

LilycoveCity_ContestHall_Text_IsntThisPlaceHumongous:
	.string "Chà, nơi này rộng khủng khiếp!\p"
	.string "Bầu không khí căng thẳng này... Khác\n"
	.string "hẳn hội trường thi đấu ở vùng quê.$"

LilycoveCity_ContestHall_Text_GiveItBestSmartAppeal:
	.string "MC: Được rồi, các SMART POKéMON và\n"
	.string "HLV đã sẵn sàng chưa?!\p"
	.string "Hãy phô diễn hết khả năng! Cùng biểu\n"
	.string "diễn nào!$"

LilycoveCity_ContestHall_Text_AreYouEnjoyingThisContest:
	.string "GIÁM KHẢO: Bạn có thích cuộc thi này\n"
	.string "không?\p"
	.string "Hãy quay lại cùng ba người bạn, khi đó\n"
	.string "tất cả các bạn đều có thể tham gia một\l"
	.string "cuộc thi!$"

LilycoveCity_ContestHall_Text_EnteredWrongContest:
	.string "Ayayayay... Tôi vào nhầm cuộc thi mất\n"
	.string "rồi.\p"
	.string "Tôi lại đưa POKéMON mạnh mẽ này vào\n"
	.string "SMARTNESS CONTEST...\p"
	.string "Nào, hãy khiến họ trầm trồ bằng một\n"
	.string "ROCK SMASH trông thật thông minh đi.$"

LilycoveCity_ContestHall_Text_RaisedMonToBeSmart:
	.string "Tôi đã dành biết bao năm tháng cùng\n"
	.string "toàn bộ trí tuệ của mình để nuôi dạy\l"
	.string "POKéMON này trở nên thông minh.\p"
	.string "Nó sẽ không dễ dàng thua POKéMON của\n"
	.string "một đứa trẻ ranh đâu.\p"
	.string "Bà nhà thân yêu, bà có đang nhìn thấy\n"
	.string "không?$"

LilycoveCity_ContestHall_Text_IfMonPullsSmartMoveNext:
	.string "Đúng rồi!\p"
	.string "Nếu lượt tới POKéMON của tôi tung ra\n"
	.string "một chiêu thông minh, sự phấn khích của\l"
	.string "khán giả sẽ lên đến đỉnh điểm!$"

LilycoveCity_ContestHall_Text_DontAppreciateCuteLeechLife:
	.string "Ôi trời, không!\p"
	.string "LEECH LIFE của ZUBAT yêu quý dễ\n"
	.string "thương đến mức tôi cứ dùng hết lần\l"
	.string "này đến lần khác!\p"
	.string "Nhưng những người xấu tính này chẳng\n"
	.string "biết trân trọng chút nào!$"

LilycoveCity_ContestHall_Text_YoureBeautifulGrandpa:
	.string "Kyaaa! Ông ơi, ông đẹp quá!$"

LilycoveCity_ContestHall_Text_AllSeemToUseDifferentMoves:
	.string "Ngay cả khi các HLV đưa cùng một\n"
	.string "loài POKéMON đi thi, dường như mỗi\l"
	.string "người vẫn dùng những chiêu khác nhau\l"
	.string "để biểu diễn.\p"
	.string "Cũng giống như mỗi người có một phong\n"
	.string "cách chiến đấu riêng vậy.$"

LilycoveCity_ContestHall_Text_PokemonSmarterThanTrainers:
	.string "Tôi thấy các POKéMON trông thông minh\n"
	.string "hơn HLV của chúng. Thông minh\l"
	.string "hơn nhiều.$"

LilycoveCity_ContestHall_Text_StillLoveSmartnessContests:
	.string "Dù gì đi nữa, tôi vẫn yêu thích\n"
	.string "SMARTNESS CONTESTS.\p"
	.string "Màu xanh trí tuệ ấy... Thật là... thật là...\n"
	.string "ngầu.$"

LilycoveCity_ContestHall_Text_AreYouEnteringBeautyContest:
	.string "MC: Bạn cũng sẽ tham gia BEAUTY CONTEST\n"
	.string "à? Chúc may mắn!$"

LilycoveCity_ContestHall_Text_EveryPokemonPristineBeauty:
	.string "GIÁM KHẢO: Ôi, mọi POKéMON ở đây\n"
	.string "đều là hình mẫu của vẻ đẹp hoàn mỹ!\p"
	.string "Tôi suýt quên mất phải chấm điểm cho\n"
	.string "chúng!$"

LilycoveCity_ContestHall_Text_EyesWillBeGluedToMyBeauty:
	.string "Một POKéMON đẹp đến thế này... Không\n"
	.string "thể tìm đâu ra con thứ hai.\p"
	.string "Mọi ánh mắt sẽ dán chặt vào vẻ đẹp của\n"
	.string "tôi.$"

LilycoveCity_ContestHall_Text_OverdidGrooming:
	.string "Waaaah!\p"
	.string "Tôi đã chải chuốt POKéMON thật kỹ cho\n"
	.string "cuộc thi này...\p"
	.string "Nhưng tôi làm quá tay... Bộ lông của\n"
	.string "POKéMON trở nên xơ xác hết rồi...\p"
	.string "Tôi phải làm sao đây?$"

LilycoveCity_ContestHall_Text_JudgeWontSeeAuroraBeam:
	.string "AURORA BEAM này chói sáng đến mức\n"
	.string "GIÁM KHẢO sẽ chẳng nhìn thấy gì.\p"
	.string "Ơ, khoan đã... Vậy thì dùng nó cũng\n"
	.string "chẳng có ý nghĩa gì!$"

LilycoveCity_ContestHall_Text_PokemonLooksLikeYoungerMe:
	.string "POKéMON xinh đẹp này trông giống hệt\n"
	.string "tôi thời trẻ.\p"
	.string "Tôi vừa nói thế thì chồng tôi phun cả\n"
	.string "ngụm cà phê đang uống.\p"
	.string "Tôi đã nói gì buồn cười sao?$"

LilycoveCity_ContestHall_Text_WinBeautyContestMakesMeHappy:
	.string "Bạn biết không, thắng BEAUTY CONTEST\n"
	.string "đương nhiên khiến tôi vui. Ít nhất là\l"
	.string "vui hơn bình thường.$"

LilycoveCity_ContestHall_Text_GanderAtAllThosePrettyPokemon:
	.string "Wahahahah!\p"
	.string "Hãy nhìn tất cả những POKéMON xinh đẹp\n"
	.string "kia xem! Tôi mê sự lộng lẫy thế này lắm!$"

LilycoveCity_ContestHall_Text_CantWinOnBeautyAlone:
	.string "Không phải lúc nào chỉ có vẻ đẹp cũng\n"
	.string "đủ để chiến thắng.\p"
	.string "Bạn phải chăm chút POKéMON sao cho nó\n"
	.string "bóng mượt như POKéMON của tôi.$"

LilycoveCity_ContestHall_Text_InTheMiddleOfContest:
	.string "MC: Ối! Xin chào! Chúng tôi đang tổ chức\n"
	.string "cuộc thi!\p"
	.string "Xin hãy đăng ký tại quầy tiếp tân rồi đi\n"
	.string "vào từ lối dành cho thí sinh nhé?$"

LilycoveCity_ContestHall_Text_SuchCharmingCuteAppeals:
	.string "GIÁM KHẢO: Ôi, những màn biểu diễn thật\n"
	.string "duyên dáng và dễ thương!\p"
	.string "Trời ơi! Màn biểu diễn WATER SPORT đáng\n"
	.string "yêu hoàn hảo làm sao!$"

LilycoveCity_ContestHall_Text_MyAzurillWasDistracted:
	.string "Ôi không... AZURILL bé bỏng của tôi đã bị\n"
	.string "một POKéMON khác làm phân tâm.$"

LilycoveCity_ContestHall_Text_NeverWonBattleButContest:
	.string "POKéMON của tôi chưa từng thắng trận\n"
	.string "đấu nào, nhưng cứ đưa nó vào cuộc thi\l"
	.string "rồi xem!$"

LilycoveCity_ContestHall_Text_PetalDanceIsMarvel:
	.string "PETAL DANCE của POKéMON tôi là một\n"
	.string "tuyệt tác thanh nhã.\p"
	.string "Tôi sẽ không để bất kỳ ai quấy rầy màn\n"
	.string "biểu diễn của nó.$"

LilycoveCity_ContestHall_Text_MyMonAppealSoMuchCuter:
	.string "POKéMON của mọi người đều rất dễ\n"
	.string "thương.\p"
	.string "Tuy nhiên, nếu POKéMON của tôi biểu diễn\n"
	.string "vẻ dễ thương...\p"
	.string "Tôi chắc chắn nó sẽ đáng yêu hơn tất cả\n"
	.string "những POKéMON khác.$"

LilycoveCity_ContestHall_Text_MyChildIsInContest:
	.string "Con tôi đang tham gia cuộc thi này.$"

LilycoveCity_ContestHall_Text_ComeOnDear:
	.string "Cố lên, con yêu. Làm hết sức nhé!\n"
	.string "POKéMON của con là tuyệt nhất!$"

LilycoveCity_ContestHall_Text_ThatGirlThereIsCutest:
	.string "Tôi nghĩ cô gái đằng kia là người dễ\n"
	.string "thương nhất.\p"
	.string "Gì cơ? Họ đang chấm vẻ ngoài của\n"
	.string "POKéMON à?$"

LilycoveCity_ContestHall_Text_WantCuteMonOfMyOwn:
	.string "Ôi, nhìn bao nhiêu POKéMON dễ thương\n"
	.string "thế này làm tôi cũng muốn có một con!\p"
	.string "Tôi sẽ đi bắt vài con đây!$"

LilycoveCity_ContestHall_Text_BeautyContestStage:
	.string "BEAUTY CONTEST STAGE Hãy say mê trước\n"
	.string "những POKéMON xinh đẹp!$"

LilycoveCity_ContestHall_Text_CuteContestStage:
	.string "CUTENESS CONTEST STAGE Hãy đắm lòng\n"
	.string "trước những POKéMON dễ thương!$"

LilycoveCity_ContestHall_Text_SmartContestStage:
	.string "SMARTNESS CONTEST STAGE Hãy thán phục\n"
	.string "những POKéMON thông minh!$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global LilycoveCity_ContestHall_Text_TodayWonSmartnessContest
	.global LilycoveCity_ContestHall_Text_EnteredBunchOfContests
	.global LilycoveCity_ContestHall_Text_ManWhoWonEarlierHadPokeblocks
	.global LilycoveCity_ContestHall_Text_IsntThisPlaceHumongous
	.global LilycoveCity_ContestHall_Text_GiveItBestSmartAppeal
	.global LilycoveCity_ContestHall_Text_AreYouEnjoyingThisContest
	.global LilycoveCity_ContestHall_Text_EnteredWrongContest
	.global LilycoveCity_ContestHall_Text_RaisedMonToBeSmart
	.global LilycoveCity_ContestHall_Text_IfMonPullsSmartMoveNext
	.global LilycoveCity_ContestHall_Text_DontAppreciateCuteLeechLife
	.global LilycoveCity_ContestHall_Text_YoureBeautifulGrandpa
	.global LilycoveCity_ContestHall_Text_AllSeemToUseDifferentMoves
	.global LilycoveCity_ContestHall_Text_PokemonSmarterThanTrainers
	.global LilycoveCity_ContestHall_Text_StillLoveSmartnessContests
	.global LilycoveCity_ContestHall_Text_AreYouEnteringBeautyContest
	.global LilycoveCity_ContestHall_Text_EveryPokemonPristineBeauty
	.global LilycoveCity_ContestHall_Text_EyesWillBeGluedToMyBeauty
	.global LilycoveCity_ContestHall_Text_OverdidGrooming
	.global LilycoveCity_ContestHall_Text_JudgeWontSeeAuroraBeam
	.global LilycoveCity_ContestHall_Text_PokemonLooksLikeYoungerMe
	.global LilycoveCity_ContestHall_Text_WinBeautyContestMakesMeHappy
	.global LilycoveCity_ContestHall_Text_GanderAtAllThosePrettyPokemon
	.global LilycoveCity_ContestHall_Text_CantWinOnBeautyAlone
	.global LilycoveCity_ContestHall_Text_InTheMiddleOfContest
	.global LilycoveCity_ContestHall_Text_SuchCharmingCuteAppeals
	.global LilycoveCity_ContestHall_Text_MyAzurillWasDistracted
	.global LilycoveCity_ContestHall_Text_NeverWonBattleButContest
	.global LilycoveCity_ContestHall_Text_PetalDanceIsMarvel
	.global LilycoveCity_ContestHall_Text_MyMonAppealSoMuchCuter
	.global LilycoveCity_ContestHall_Text_MyChildIsInContest
	.global LilycoveCity_ContestHall_Text_ComeOnDear
	.global LilycoveCity_ContestHall_Text_ThatGirlThereIsCutest
	.global LilycoveCity_ContestHall_Text_WantCuteMonOfMyOwn
	.global LilycoveCity_ContestHall_Text_BeautyContestStage
	.global LilycoveCity_ContestHall_Text_CuteContestStage
	.global LilycoveCity_ContestHall_Text_SmartContestStage
@ END GENERATED LOCALIZATION EXPORTS
