VictoryRoad_B1F_MapScripts::
	.byte 0

VictoryRoad_B1F_EventScript_Samuel::
	trainerbattle_single TRAINER_SAMUEL, VictoryRoad_B1F_Text_SamuelIntro, VictoryRoad_B1F_Text_SamuelDefeat
	msgbox VictoryRoad_B1F_Text_SamuelPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Shannon::
	trainerbattle_single TRAINER_SHANNON, VictoryRoad_B1F_Text_ShannonIntro, VictoryRoad_B1F_Text_ShannonDefeat
	msgbox VictoryRoad_B1F_Text_ShannonPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Michelle::
	trainerbattle_single TRAINER_MICHELLE, VictoryRoad_B1F_Text_MichelleIntro, VictoryRoad_B1F_Text_MichelleDefeat
	msgbox VictoryRoad_B1F_Text_MichellePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Mitchell::
	trainerbattle_single TRAINER_MITCHELL, VictoryRoad_B1F_Text_MitchellIntro, VictoryRoad_B1F_Text_MitchellDefeat
	msgbox VictoryRoad_B1F_Text_MitchellPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Halle::
	trainerbattle_single TRAINER_HALLE, VictoryRoad_B1F_Text_HalleIntro, VictoryRoad_B1F_Text_HalleDefeat
	msgbox VictoryRoad_B1F_Text_HallePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_Text_SamuelIntro:
	.string "Cứ nghĩ mình đang tiến gần hơn đến\n"
	.string "POKéMON LEAGUE...\p"
	.string "Tôi lại càng hồi hộp...$"

VictoryRoad_B1F_Text_SamuelDefeat:
	.string "Tôi chẳng làm được gì cả...$"

VictoryRoad_B1F_Text_SamuelPostBattle:
	.string "POKéMON LEAGUE lại trở nên xa vời...\n"
	.string "Thật thất vọng...$"

VictoryRoad_B1F_Text_ShannonIntro:
	.string "Để chiến thắng tại POKéMON LEAGUE, bạn\n"
	.string "cần có được lòng tin của POKéMON.$"

VictoryRoad_B1F_Text_ShannonDefeat:
	.string "Mối quan hệ giữa các bạn được xây\n"
	.string "dựng trên lòng tin vững chắc.$"

VictoryRoad_B1F_Text_ShannonPostBattle:
	.string "Khi luôn ở bên nhau, lòng tin giữa\n"
	.string "POKéMON và HLV sẽ ngày càng lớn.$"

VictoryRoad_B1F_Text_MichelleIntro:
	.string "Đây không phải đích đến. Nó chỉ là một\n"
	.string "nơi trên đường tới POKéMON LEAGUE.$"

VictoryRoad_B1F_Text_MichelleDefeat:
	.string "Đúng là phải như thế!$"

VictoryRoad_B1F_Text_MichellePostBattle:
	.string "Bạn chắc chắn sẽ làm tốt! Tất cả\n"
	.string "POKéMON của bạn đều đang háo hức tiến\l"
	.string "lên!$"

VictoryRoad_B1F_Text_MitchellIntro:
	.string "POKéMON của tôi kỳ vĩ đến tầm vũ trụ!$"

VictoryRoad_B1F_Text_MitchellDefeat:
	.string "Trước đây tôi chưa từng gặp ai như\n"
	.string "bạn.$"

VictoryRoad_B1F_Text_MitchellPostBattle:
	.string "Ngay cả ngoài trận đấu, tôi vẫn cảm\n"
	.string "nhận được nguồn sức mạnh phi thường\l"
	.string "tỏa ra từ bạn và POKéMON.$"

VictoryRoad_B1F_Text_HalleIntro:
	.string "Được rồi, đừng căng thẳng thế! Thư\n"
	.string "giãn đi, cứ thong thả thôi!$"

VictoryRoad_B1F_Text_HalleDefeat:
	.string "Chà! Tuyệt vời!$"

VictoryRoad_B1F_Text_HallePostBattle:
	.string "Đúng, đây là VICTORY ROAD.\p"
	.string "Nhưng nó cũng không khác mấy so với\n"
	.string "con đường bạn đã đi qua.\p"
	.string "Hãy cố tận hưởng nốt chặng đường còn\n"
	.string "lại!$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global VictoryRoad_B1F_Text_SamuelIntro
	.global VictoryRoad_B1F_Text_SamuelDefeat
	.global VictoryRoad_B1F_Text_SamuelPostBattle
	.global VictoryRoad_B1F_Text_ShannonIntro
	.global VictoryRoad_B1F_Text_ShannonDefeat
	.global VictoryRoad_B1F_Text_ShannonPostBattle
	.global VictoryRoad_B1F_Text_MichelleIntro
	.global VictoryRoad_B1F_Text_MichelleDefeat
	.global VictoryRoad_B1F_Text_MichellePostBattle
	.global VictoryRoad_B1F_Text_MitchellIntro
	.global VictoryRoad_B1F_Text_MitchellDefeat
	.global VictoryRoad_B1F_Text_MitchellPostBattle
	.global VictoryRoad_B1F_Text_HalleIntro
	.global VictoryRoad_B1F_Text_HalleDefeat
	.global VictoryRoad_B1F_Text_HallePostBattle
@ END GENERATED LOCALIZATION EXPORTS
