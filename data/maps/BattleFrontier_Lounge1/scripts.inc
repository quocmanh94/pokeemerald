BattleFrontier_Lounge1_MapScripts::
	.byte 0

@ NPC that rates pokemon based on their IVs
BattleFrontier_Lounge1_EventScript_Breeder::
	lock
	faceplayer
	call_if_unset FLAG_MET_BATTLE_FRONTIER_BREEDER, BattleFrontier_Lounge1_EventScript_BreederIntro
	call_if_set FLAG_MET_BATTLE_FRONTIER_BREEDER, BattleFrontier_Lounge1_EventScript_AlreadyMetBreeder
	setflag FLAG_MET_BATTLE_FRONTIER_BREEDER
	goto BattleFrontier_Lounge1_EventScript_ChooseMonToShowBreeder
	end

BattleFrontier_Lounge1_EventScript_ChooseMonToShowBreeder::
	special ChoosePartyMon
	goto_if_ne VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_Lounge1_EventScript_ShowMonToBreeder
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_Lounge1_EventScript_CancelMonSelect
	end

BattleFrontier_Lounge1_EventScript_BreederIntro::
	msgbox BattleFrontier_Lounge1_Text_PokemonBreederIntro, MSGBOX_DEFAULT
	return

BattleFrontier_Lounge1_EventScript_AlreadyMetBreeder::
	msgbox BattleFrontier_Lounge1_Text_LetsLookAtYourPokemon, MSGBOX_DEFAULT
	return

@ BufferVarsForIVRater buffers the following values
@ VAR_0x8005: Sum of the mons IVs
@ VAR_0x8006: Stat id of highest IV stat
@ VAR_0x8007: IV of the highest IV stat
BattleFrontier_Lounge1_EventScript_ShowMonToBreeder::
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, BattleFrontier_Lounge1_EventScript_ShowEggToBreeder
	special BufferVarsForIVRater
	goto_if_le VAR_0x8005, 90, BattleFrontier_Lounge1_EventScript_AverageTotalIVs       @ Average of 15
	goto_if_le VAR_0x8005, 120, BattleFrontier_Lounge1_EventScript_AboveAverageTotalIVs @ Average of 20
	goto_if_le VAR_0x8005, 150, BattleFrontier_Lounge1_EventScript_HighTotalIVs         @ Average of 25
	goto_if_ge VAR_0x8005, 151, BattleFrontier_Lounge1_EventScript_VeryHighTotalIVs     @ Average of > 25
	end

BattleFrontier_Lounge1_EventScript_ShowEggToBreeder::
	msgbox BattleFrontier_Lounge1_Text_EvenICantTell, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_ChooseMonToShowBreeder
	end

@ Comment on the highest IV stat
BattleFrontier_Lounge1_EventScript_HighestIVStat::
	goto_if_eq VAR_0x8006, STAT_HP, BattleFrontier_Lounge1_EventScript_HighestIVHP
	goto_if_eq VAR_0x8006, STAT_ATK, BattleFrontier_Lounge1_EventScript_HighestIVAtk
	goto_if_eq VAR_0x8006, STAT_DEF, BattleFrontier_Lounge1_EventScript_HighestIVDef
	goto_if_eq VAR_0x8006, STAT_SPEED, BattleFrontier_Lounge1_EventScript_HighestIVSpeed
	goto_if_eq VAR_0x8006, STAT_SPATK, BattleFrontier_Lounge1_EventScript_HighestIVSpAtk
	goto_if_eq VAR_0x8006, STAT_SPDEF, BattleFrontier_Lounge1_EventScript_HighestIVSpDef
	end

@ Comment on the highest IV value
BattleFrontier_Lounge1_EventScript_HighestIVValue::
	goto_if_le VAR_0x8007, 15, BattleFrontier_Lounge1_EventScript_HighestIVLow
	goto_if_le VAR_0x8007, 25, BattleFrontier_Lounge1_EventScript_HighestIVMid
	goto_if_le VAR_0x8007, 30, BattleFrontier_Lounge1_EventScript_HighestIVHigh
	goto_if_ge VAR_0x8007, 31, BattleFrontier_Lounge1_EventScript_HighestIVMax
	end

BattleFrontier_Lounge1_EventScript_EndBreederComments::
	release
	end

BattleFrontier_Lounge1_EventScript_AverageTotalIVs::
	msgbox BattleFrontier_Lounge1_Text_AverageAbility, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat
	end

BattleFrontier_Lounge1_EventScript_AboveAverageTotalIVs::
	msgbox BattleFrontier_Lounge1_Text_BetterThanAverageAbility, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat
	end

BattleFrontier_Lounge1_EventScript_HighTotalIVs::
	msgbox BattleFrontier_Lounge1_Text_ImpressiveAbility, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat
	end

BattleFrontier_Lounge1_EventScript_VeryHighTotalIVs::
	msgbox BattleFrontier_Lounge1_Text_OutstandingAbility, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat
	end

BattleFrontier_Lounge1_EventScript_HighestIVHP::
	msgbox BattleFrontier_Lounge1_Text_BestAspectHP, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVAtk::
	msgbox BattleFrontier_Lounge1_Text_BestAspectAtk, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVDef::
	msgbox BattleFrontier_Lounge1_Text_BestAspectDef, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVSpeed::
	msgbox BattleFrontier_Lounge1_Text_BestAspectSpeed, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVSpAtk::
	msgbox BattleFrontier_Lounge1_Text_BestAspectSpAtk, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVSpDef::
	msgbox BattleFrontier_Lounge1_Text_BestAspectSpDef, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVLow::
	msgbox BattleFrontier_Lounge1_Text_StatRelativelyGood, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_EndBreederComments
	end

BattleFrontier_Lounge1_EventScript_HighestIVMid::
	msgbox BattleFrontier_Lounge1_Text_StatImpressive, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_EndBreederComments
	end

BattleFrontier_Lounge1_EventScript_HighestIVHigh::
	msgbox BattleFrontier_Lounge1_Text_StatOutstanding, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_EndBreederComments
	end

BattleFrontier_Lounge1_EventScript_HighestIVMax::
	msgbox BattleFrontier_Lounge1_Text_StatFlawless, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_EndBreederComments
	end

BattleFrontier_Lounge1_EventScript_CancelMonSelect::
	msgbox BattleFrontier_Lounge1_Text_NoTimeForMyAdvice, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge1_EventScript_Boy1::
	msgbox BattleFrontier_Lounge1_Text_SaidMyMonIsOutstanding, MSGBOX_NPC
	end

BattleFrontier_Lounge1_EventScript_Boy2::
	msgbox BattleFrontier_Lounge1_Text_DidntDoAnythingSpecialRaisingIt, MSGBOX_NPC
	end

BattleFrontier_Lounge1_Text_PokemonBreederIntro:
	.string "Suốt 70 năm qua, ta đã nuôi dưỡng\n"
	.string "POKéMON! Ta chính là người được thiên\l"
	.string "hạ tôn kính như POKéMON BREEDER số\l"
	.string "một trong truyền thuyết!\p"
	.string "Khi dày dạn kinh nghiệm như ta, chỉ cần\n"
	.string "nhìn qua là cháu sẽ biết được năng lực\l"
	.string "của POKéMON.\p"
	.string "Cháu là một HLV. Cháu không muốn\n"
	.string "biết năng lực của POKéMON mình sao?\p"
	.string "Đây! Để ta xem POKéMON của cháu nào!$"

BattleFrontier_Lounge1_Text_AverageAbility:
	.string "...Hừm...\p"
	.string "Xét tổng thể, ta cho rằng năng lực của\n"
	.string "con này ở mức trung bình.$"

BattleFrontier_Lounge1_Text_BetterThanAverageAbility:
	.string "...Hừm...\p"
	.string "Xét tổng thể, ta cho rằng năng lực của\n"
	.string "con này trên mức trung bình.$"

BattleFrontier_Lounge1_Text_ImpressiveAbility:
	.string "...Hừm...\p"
	.string "Xét tổng thể, ta phải nói năng lực của\n"
	.string "con này khá ấn tượng!$"

BattleFrontier_Lounge1_Text_OutstandingAbility:
	.string "...Hừm...\p"
	.string "Xét tổng thể, ta phải nói năng lực của\n"
	.string "con này vô cùng xuất sắc!$"

BattleFrontier_Lounge1_Text_BestAspectHP:
	.string "Nhân tiện, điểm nổi trội nhất của nó,\n"
	.string "theo ta, là HP...$"

BattleFrontier_Lounge1_Text_BestAspectAtk:
	.string "Nhân tiện, điểm nổi trội nhất của nó,\n"
	.string "theo ta, là ATTACK...$"

BattleFrontier_Lounge1_Text_BestAspectDef:
	.string "Nhân tiện, điểm nổi trội nhất của nó,\n"
	.string "theo ta, là DEFENSE...$"

BattleFrontier_Lounge1_Text_BestAspectSpAtk:
	.string "Nhân tiện, điểm nổi trội nhất của nó,\n"
	.string "theo ta, là SPECIAL ATTACK...$"

BattleFrontier_Lounge1_Text_BestAspectSpDef:
	.string "Nhân tiện, điểm nổi trội nhất của nó,\n"
	.string "theo ta, là SPECIAL DEFENSE...$"

BattleFrontier_Lounge1_Text_BestAspectSpeed:
	.string "Nhân tiện, điểm nổi trội nhất của nó,\n"
	.string "theo ta, là SPEED...$"

BattleFrontier_Lounge1_Text_StatRelativelyGood:
	.string "Chỉ số đó khá tốt. ...Hừm... Ta đánh giá\n"
	.string "như vậy.$"

BattleFrontier_Lounge1_Text_StatImpressive:
	.string "Chỉ số đó rất ấn tượng. ...Hừm... Ta đánh\n"
	.string "giá như vậy.$"

BattleFrontier_Lounge1_Text_StatOutstanding:
	.string "Chỉ số đó thật xuất sắc! ...Hừm... Ta\n"
	.string "đánh giá như vậy.$"

BattleFrontier_Lounge1_Text_StatFlawless:
	.string "Hoàn hảo! Một tuyệt phẩm không tì vết!\n"
	.string "...Hừm... Ta đánh giá như vậy.$"

BattleFrontier_Lounge1_Text_NoTimeForMyAdvice:
	.string "Sao? Cháu không có thời gian nghe lời\n"
	.string "khuyên của ta à?\p"
	.string "Phải luôn ham học hỏi từ kinh nghiệm của\n"
	.string "người lớn tuổi chứ!$"

@ Unused
BattleFrontier_Lounge1_Text_HaveBusinessNeedsTending:
	.string "Ừ, giờ lại có chuyện gì?\p"
	.string "Ta còn việc cần lo! Để lần sau đi!$"

BattleFrontier_Lounge1_Text_LetsLookAtYourPokemon:
	.string "À, người trẻ tuổi! Cháu tò mò về năng\n"
	.string "lực của POKéMON mình sao?\p"
	.string "Lại đây! Để ta xem POKéMON của cháu\n"
	.string "nào!$"

BattleFrontier_Lounge1_Text_EvenICantTell:
	.string "Ta là chuyên gia, nhưng đến ta cũng\n"
	.string "chẳng thể biết gì về một POKéMON chưa\l"
	.string "nở!\p"
	.string "Cho ta xem một POKéMON! Ta cần nhìn\n"
	.string "thấy một POKéMON cơ!$"

BattleFrontier_Lounge1_Text_SaidMyMonIsOutstanding:
	.string "Ông ấy nói POKéMON của tôi rất xuất\n"
	.string "sắc! Thật mừng vì tôi đã chăm sóc nó\l"
	.string "cẩn thận!$"

BattleFrontier_Lounge1_Text_DidntDoAnythingSpecialRaisingIt:
	.string "Ông ấy nói POKéMON của tôi rất xuất\n"
	.string "sắc! Nhưng tôi đâu làm gì đặc biệt khi\l"
	.string "nuôi nó...$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global BattleFrontier_Lounge1_Text_PokemonBreederIntro
	.global BattleFrontier_Lounge1_Text_AverageAbility
	.global BattleFrontier_Lounge1_Text_BetterThanAverageAbility
	.global BattleFrontier_Lounge1_Text_ImpressiveAbility
	.global BattleFrontier_Lounge1_Text_OutstandingAbility
	.global BattleFrontier_Lounge1_Text_BestAspectHP
	.global BattleFrontier_Lounge1_Text_BestAspectAtk
	.global BattleFrontier_Lounge1_Text_BestAspectDef
	.global BattleFrontier_Lounge1_Text_BestAspectSpAtk
	.global BattleFrontier_Lounge1_Text_BestAspectSpDef
	.global BattleFrontier_Lounge1_Text_BestAspectSpeed
	.global BattleFrontier_Lounge1_Text_StatRelativelyGood
	.global BattleFrontier_Lounge1_Text_StatImpressive
	.global BattleFrontier_Lounge1_Text_StatOutstanding
	.global BattleFrontier_Lounge1_Text_StatFlawless
	.global BattleFrontier_Lounge1_Text_NoTimeForMyAdvice
	.global BattleFrontier_Lounge1_Text_HaveBusinessNeedsTending
	.global BattleFrontier_Lounge1_Text_LetsLookAtYourPokemon
	.global BattleFrontier_Lounge1_Text_EvenICantTell
	.global BattleFrontier_Lounge1_Text_SaidMyMonIsOutstanding
	.global BattleFrontier_Lounge1_Text_DidntDoAnythingSpecialRaisingIt
@ END GENERATED LOCALIZATION EXPORTS
