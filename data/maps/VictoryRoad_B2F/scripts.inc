VictoryRoad_B2F_MapScripts::
	.byte 0

VictoryRoad_B2F_EventScript_Vito::
	trainerbattle_single TRAINER_VITO, VictoryRoad_B2F_Text_VitoIntro, VictoryRoad_B2F_Text_VitoDefeat
	msgbox VictoryRoad_B2F_Text_VitoPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Owen::
	trainerbattle_single TRAINER_OWEN, VictoryRoad_B2F_Text_OwenIntro, VictoryRoad_B2F_Text_OwenDefeat
	msgbox VictoryRoad_B2F_Text_OwenPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Caroline::
	trainerbattle_single TRAINER_CAROLINE, VictoryRoad_B2F_Text_CarolineIntro, VictoryRoad_B2F_Text_CarolineDefeat
	msgbox VictoryRoad_B2F_Text_CarolinePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Julie::
	trainerbattle_single TRAINER_JULIE, VictoryRoad_B2F_Text_JulieIntro, VictoryRoad_B2F_Text_JulieDefeat
	msgbox VictoryRoad_B2F_Text_JuliePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Felix::
	trainerbattle_single TRAINER_FELIX, VictoryRoad_B2F_Text_FelixIntro, VictoryRoad_B2F_Text_FelixDefeat
	msgbox VictoryRoad_B2F_Text_FelixPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Dianne::
	trainerbattle_single TRAINER_DIANNE, VictoryRoad_B2F_Text_DianneIntro, VictoryRoad_B2F_Text_DianneDefeat
	msgbox VictoryRoad_B2F_Text_DiannePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_Text_VitoIntro:
	.string "Tôi đã luyện tập cùng toàn thể gia\n"
	.string "đình, không thiếu một ai! Tôi sẽ không\l"
	.string "thua bất kỳ người nào!$"

VictoryRoad_B2F_Text_VitoDefeat:
	.string "Giỏi hơn cả gia đình tôi sao?! Chuyện\n"
	.string "đó có thể ư?!$"

VictoryRoad_B2F_Text_VitoPostBattle:
	.string "Tôi giỏi hơn tất cả mọi người trong gia\n"
	.string "đình. Trước đây tôi chưa từng thua...\p"
	.string "Tôi mất hết tự tin rồi... Có lẽ tôi nên về\n"
	.string "nhà...$"

VictoryRoad_B2F_Text_OwenIntro:
	.string "Tôi nghe nói quanh đây có một nhóc con\n"
	.string "rất mạnh. Họ đang nói về bạn sao?$"

VictoryRoad_B2F_Text_OwenDefeat:
	.string "Nhóc con này mạnh thật!$"

VictoryRoad_B2F_Text_OwenPostBattle:
	.string "Theo lời đồn tôi nghe được, nhóc con\n"
	.string "rất mạnh đó đến từ PETALBURG CITY.$"

VictoryRoad_B2F_Text_CarolineIntro:
	.string "Chắc bạn đã bắt đầu thấy hơi mệt rồi.$"

VictoryRoad_B2F_Text_CarolineDefeat:
	.string "Chẳng có dấu hiệu mệt mỏi nào cả!$"

VictoryRoad_B2F_Text_CarolinePostBattle:
	.string "VICTORY ROAD và POKéMON LEAGUE là\n"
	.string "những thử thách dài và khắc nghiệt.\l"
	.string "Hãy đề phòng kiệt sức!$"

VictoryRoad_B2F_Text_JulieIntro:
	.string "Đừng tự mãn chỉ vì bạn có nhiều GYM\n"
	.string "BADGES.\p"
	.string "Sẽ luôn có người giỏi hơn bạn!$"

VictoryRoad_B2F_Text_JulieDefeat:
	.string "Bạn giỏi hơn tôi!$"

VictoryRoad_B2F_Text_JuliePostBattle:
	.string "Hãy ngắm những BADGES bạn đã thu thập\n"
	.string "và nhớ lại các HLV mình từng đối\l"
	.string "mặt.$"

VictoryRoad_B2F_Text_FelixIntro:
	.string "Tôi đã đi đến tận đây, nhưng căng\n"
	.string "thẳng khiến bụng tôi đau quặn...$"

VictoryRoad_B2F_Text_FelixDefeat:
	.string "Ôi... Đau quá...$"

VictoryRoad_B2F_Text_FelixPostBattle:
	.string "Biết mình đang đến gần POKéMON LEAGUE\n"
	.string "khiến tôi không sao hết căng thẳng\l"
	.string "được.\p"
	.string "Tôi chỉ còn biết giả vờ bình tĩnh.$"

VictoryRoad_B2F_Text_DianneIntro:
	.string "Những người tinh nhuệ bậc nhất tụ hội\n"
	.string "trong hang động này.\p"
	.string "Cậu thấy nơi này thế nào?$"

VictoryRoad_B2F_Text_DianneDefeat:
	.string "Chẳng nao núng một chút nào!$"

VictoryRoad_B2F_Text_DiannePostBattle:
	.string "Cậu đúng là gan dạ! Tôi thích thế! Cứ\n"
	.string "thế mà tiến lên nhé!$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global VictoryRoad_B2F_Text_VitoIntro
	.global VictoryRoad_B2F_Text_VitoDefeat
	.global VictoryRoad_B2F_Text_VitoPostBattle
	.global VictoryRoad_B2F_Text_OwenIntro
	.global VictoryRoad_B2F_Text_OwenDefeat
	.global VictoryRoad_B2F_Text_OwenPostBattle
	.global VictoryRoad_B2F_Text_CarolineIntro
	.global VictoryRoad_B2F_Text_CarolineDefeat
	.global VictoryRoad_B2F_Text_CarolinePostBattle
	.global VictoryRoad_B2F_Text_JulieIntro
	.global VictoryRoad_B2F_Text_JulieDefeat
	.global VictoryRoad_B2F_Text_JuliePostBattle
	.global VictoryRoad_B2F_Text_FelixIntro
	.global VictoryRoad_B2F_Text_FelixDefeat
	.global VictoryRoad_B2F_Text_FelixPostBattle
	.global VictoryRoad_B2F_Text_DianneIntro
	.global VictoryRoad_B2F_Text_DianneDefeat
	.global VictoryRoad_B2F_Text_DiannePostBattle
@ END GENERATED LOCALIZATION EXPORTS
