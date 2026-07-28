BattleFrontier_Lounge5_MapScripts::
	.byte 0

BattleFrontier_Lounge5_EventScript_NatureGirl::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge5_Text_NatureGirlGreeting, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge5_EventScript_NatureGirlNoneShown
	special ChoosePartyMon
	lock
	faceplayer
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_Lounge5_EventScript_NatureGirlNoneShown
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, BattleFrontier_Lounge5_EventScript_NatureGirlEgg
	special ShowNatureGirlMessage
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge5_EventScript_NatureGirlEgg::
	msgbox BattleFrontier_Lounge5_Text_NatureGirlEgg, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge5_EventScript_NatureGirlNoneShown::
	msgbox BattleFrontier_Lounge5_Text_NatureGirlNoneShown, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge5_EventScript_Gentleman::
	msgbox BattleFrontier_Lounge5_Text_LadyClaimsSheUnderstandsPokemon, MSGBOX_NPC
	end

BattleFrontier_Lounge5_EventScript_BlackBelt::
	msgbox BattleFrontier_Lounge5_Text_GirlSayingSomethingProfound, MSGBOX_NPC
	end

BattleFrontier_Lounge5_EventScript_LittleBoy::
	msgbox BattleFrontier_Lounge5_Text_GirlPlaysAtRedHouseALot, MSGBOX_NPC
	end

BattleFrontier_Lounge5_Text_NatureGirlGreeting::
	.string "Hê hê! Tớ biết POKéMON đang nghĩ gì\n"
	.string "đấy!\p"
	.string "Làm ơn! Cho tớ xem POKéMON của bạn\n"
	.string "nhé?$"

BattleFrontier_Lounge5_Text_NatureGirlNoneShown::
	.string "Xì! Keo kiệt!$"

BattleFrontier_Lounge5_Text_NatureGirlHardy::
	.string "Hừm hừm.\p"
	.string "Bé này nói rằng nó thích chiến đấu! Dù\n"
	.string "bị đau nhiều, nó vẫn sẽ tiếp tục chiến\l"
	.string "đấu!$"

BattleFrontier_Lounge5_Text_NatureGirlLonely::
	.string "Hừm hừm.\p"
	.string "Bé này nói rằng nó thích đánh lén!\n"
	.string "Nhưng nếu bị đau đủ nhiều, nó sẽ đánh\l"
	.string "trả!$"

BattleFrontier_Lounge5_Text_NatureGirlBrave::
	.string "Hừm hừm.\p"
	.string "Bé này nói rằng nó thích chiến đấu!\n"
	.string "Nhưng nếu bị đau đủ nhiều, nó sẽ bắt\l"
	.string "đầu lo cho bản thân!$"

BattleFrontier_Lounge5_Text_NatureGirlAdamant::
	.string "Hừm hừm.\p"
	.string "Bé này nói rằng nó thích chiến đấu! Dù\n"
	.string "bị đau nhiều, nó vẫn sẽ tiếp tục chiến\l"
	.string "đấu!$"

BattleFrontier_Lounge5_Text_NatureGirlNaughty::
	.string "Hừm hừm.\p"
	.string "Bé này nói rằng nó biết tự lo cho mình!\n"
	.string "Nhưng nếu bị đau đủ nhiều, nó sẽ đánh\l"
	.string "trả!$"

BattleFrontier_Lounge5_Text_NatureGirlBold::
	.string "Hừm hừm.\p"
	.string "Bé này nói rằng nó thích đánh lén!\n"
	.string "Nhưng nếu bị đau đủ nhiều, nó sẽ bắt\l"
	.string "đầu lo cho bản thân!$"

BattleFrontier_Lounge5_Text_NatureGirlDocileNaiveQuietQuirky::
	.string "Hừm hừm.\p"
	.string "Bé này nói rằng nó thích chiến đấu! Dù\n"
	.string "bị đau nhiều, nó vẫn sẽ tiếp tục chiến\l"
	.string "đấu!$"

BattleFrontier_Lounge5_Text_NatureGirlRelaxed::
	.string "Hừm hừm.\p"
	.string "Bé này nói rằng nó thích đánh lén!\n"
	.string "Nhưng nếu bị đau đủ nhiều, nó sẽ đánh\l"
	.string "trả!$"

BattleFrontier_Lounge5_Text_NatureGirlImpish::
	.string "Hừm hừm.\p"
	.string "Bé này nói rằng nó thích chiến đấu!\n"
	.string "Nhưng nếu bị đau đủ nhiều, nó sẽ bắt\l"
	.string "đầu lo cho bản thân!$"

BattleFrontier_Lounge5_Text_NatureGirlLax::
	.string "Hừm hừm.\p"
	.string "Bé này nói rằng nó thích đánh lén! Nó\n"
	.string "bảo rằng dù bị đau nhiều, nó vẫn thích\l"
	.string "đánh lén!$"

BattleFrontier_Lounge5_Text_NatureGirlTimid::
	.string "Hừm hừm.\p"
	.string "Bé này nói rằng nó thích chiến đấu!\n"
	.string "Nhưng nếu bị đau đủ nhiều, nó sẽ chuyển\l"
	.string "sang đánh lén!$"

BattleFrontier_Lounge5_Text_NatureGirlHasty::
	.string "Hừm hừm.\p"
	.string "Bé này nói rằng nó thích chiến đấu! Dù\n"
	.string "bị đau nhiều, nó vẫn sẽ tiếp tục chiến\l"
	.string "đấu!$"

BattleFrontier_Lounge5_Text_NatureGirlSerious::
	.string "Hừm hừm.\p"
	.string "Bé này nói rằng nó thích đánh lén! Nó\n"
	.string "bảo rằng dù bị đau nhiều, nó vẫn thích\l"
	.string "đánh lén!$"

BattleFrontier_Lounge5_Text_NatureGirlJolly::
	.string "Hừm hừm.\p"
	.string "Bé này nói rằng nó thích đánh lén!\n"
	.string "Nhưng nếu bị đau đủ nhiều, nó sẽ bắt\l"
	.string "đầu lo cho bản thân!$"

BattleFrontier_Lounge5_Text_NatureGirlModest::
	.string "Hừm hừm.\p"
	.string "Bé này nói rằng nó biết tự lo cho mình!\n"
	.string "Nó bảo dù có bị đau nhiều hay không, nó\l"
	.string "vẫn luôn lo cho bản thân!$"

BattleFrontier_Lounge5_Text_NatureGirlMild::
	.string "Hừm hừm.\p"
	.string "Bé này nói rằng nó biết tự lo cho mình!\n"
	.string "Nhưng nếu bị đau đủ nhiều, nó sẽ chuyển\l"
	.string "sang đánh lén!$"

BattleFrontier_Lounge5_Text_NatureGirlBashful::
	.string "Hừm hừm.\p"
	.string "Bé này nói rằng nó biết tự lo cho mình!\n"
	.string "Nó bảo rằng ngay cả khi bị đau nhiều, nó\l"
	.string "vẫn sẽ lo cho bản thân!$"

BattleFrontier_Lounge5_Text_NatureGirlRash::
	.string "Hừm hừm.\p"
	.string "Bé này nói rằng nó thích đánh lén! Nó\n"
	.string "bảo rằng dù bị đau nhiều, nó vẫn thích\l"
	.string "đánh lén!$"

BattleFrontier_Lounge5_Text_NatureGirlCalm::
	.string "Hừm hừm.\p"
	.string "Bé này nói rằng nó biết tự lo cho mình!\n"
	.string "Nó bảo rằng ngay cả khi bị đau nhiều, nó\l"
	.string "vẫn sẽ lo cho bản thân!$"

BattleFrontier_Lounge5_Text_NatureGirlGentle::
	.string "Hừm hừm.\p"
	.string "Bé này nói rằng nó biết tự lo cho mình!\n"
	.string "Nhưng nếu bị đau đủ nhiều, nó sẽ đánh\l"
	.string "trả!$"

BattleFrontier_Lounge5_Text_NatureGirlSassy::
	.string "Hừm hừm.\p"
	.string "Bé này nói rằng nó thích chiến đấu!\n"
	.string "Nhưng nếu bị đau đủ nhiều, nó sẽ chuyển\l"
	.string "sang đánh lén!$"

BattleFrontier_Lounge5_Text_NatureGirlCareful::
	.string "Hừm hừm.\p"
	.string "Bé này nói rằng nó biết tự lo cho mình!\n"
	.string "Nhưng nếu bị đau đủ nhiều, nó sẽ chuyển\l"
	.string "sang đánh lén!$"

BattleFrontier_Lounge5_Text_NatureGirlEgg::
	.string "Ngốc quá! EGG đang ngủ mà! Tớ không nói\n"
	.string "chuyện với nó được!$"

BattleFrontier_Lounge5_Text_LadyClaimsSheUnderstandsPokemon::
	.string "Thật đáng yêu! Cô bé đó nói rằng mình\n"
	.string "hiểu được POKéMON!$"

BattleFrontier_Lounge5_Text_GirlSayingSomethingProfound::
	.string "Tôi có cảm giác cô bé ấy đang nói một\n"
	.string "điều rất sâu sắc.$"

BattleFrontier_Lounge5_Text_GirlPlaysAtRedHouseALot::
	.string "Tôi biết chuyện này!\p"
	.string "Cô bé đó thường xuyên chơi ở ngôi nhà\n"
	.string "màu đỏ!$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global BattleFrontier_Lounge5_Text_NatureGirlGreeting
	.global BattleFrontier_Lounge5_Text_NatureGirlNoneShown
	.global BattleFrontier_Lounge5_Text_NatureGirlHardy
	.global BattleFrontier_Lounge5_Text_NatureGirlLonely
	.global BattleFrontier_Lounge5_Text_NatureGirlBrave
	.global BattleFrontier_Lounge5_Text_NatureGirlAdamant
	.global BattleFrontier_Lounge5_Text_NatureGirlNaughty
	.global BattleFrontier_Lounge5_Text_NatureGirlBold
	.global BattleFrontier_Lounge5_Text_NatureGirlDocileNaiveQuietQuirky
	.global BattleFrontier_Lounge5_Text_NatureGirlRelaxed
	.global BattleFrontier_Lounge5_Text_NatureGirlImpish
	.global BattleFrontier_Lounge5_Text_NatureGirlLax
	.global BattleFrontier_Lounge5_Text_NatureGirlTimid
	.global BattleFrontier_Lounge5_Text_NatureGirlHasty
	.global BattleFrontier_Lounge5_Text_NatureGirlSerious
	.global BattleFrontier_Lounge5_Text_NatureGirlJolly
	.global BattleFrontier_Lounge5_Text_NatureGirlModest
	.global BattleFrontier_Lounge5_Text_NatureGirlMild
	.global BattleFrontier_Lounge5_Text_NatureGirlBashful
	.global BattleFrontier_Lounge5_Text_NatureGirlRash
	.global BattleFrontier_Lounge5_Text_NatureGirlCalm
	.global BattleFrontier_Lounge5_Text_NatureGirlGentle
	.global BattleFrontier_Lounge5_Text_NatureGirlSassy
	.global BattleFrontier_Lounge5_Text_NatureGirlCareful
	.global BattleFrontier_Lounge5_Text_NatureGirlEgg
	.global BattleFrontier_Lounge5_Text_LadyClaimsSheUnderstandsPokemon
	.global BattleFrontier_Lounge5_Text_GirlSayingSomethingProfound
	.global BattleFrontier_Lounge5_Text_GirlPlaysAtRedHouseALot
@ END GENERATED LOCALIZATION EXPORTS
