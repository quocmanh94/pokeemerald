LavaridgeTown_HerbShop_MapScripts::
	.byte 0

LavaridgeTown_HerbShop_EventScript_Clerk::
	lock
	faceplayer
	message LavaridgeTown_HerbShop_Text_WelcomeToHerbShop
	waitmessage
	pokemart LavaridgeTown_HerbShop_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LavaridgeTown_HerbShop_Pokemart:
	.2byte ITEM_ENERGY_POWDER
	.2byte ITEM_ENERGY_ROOT
	.2byte ITEM_HEAL_POWDER
	.2byte ITEM_REVIVAL_HERB
	pokemartlistend

LavaridgeTown_HerbShop_EventScript_ExpertM::
	msgbox LavaridgeTown_HerbShop_Text_HerbalMedicineWorksButMonWillDislike, MSGBOX_NPC
	end

LavaridgeTown_HerbShop_EventScript_OldMan::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_CHARCOAL, LavaridgeTown_HerbShop_EventScript_ExplainCharcoal
	msgbox LavaridgeTown_HerbShop_Text_YouveComeToLookAtHerbalMedicine, MSGBOX_DEFAULT
	giveitem ITEM_CHARCOAL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_CHARCOAL
	release
	end

LavaridgeTown_HerbShop_EventScript_ExplainCharcoal::
	msgbox LavaridgeTown_HerbShop_Text_ExplainCharcoal, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_HerbShop_Text_WelcomeToHerbShop:
	.string "Chào mừng đến với HERB SHOP, nơi bán\n"
	.string "thuốc hiệu quả với giá phải chăng!$"

LavaridgeTown_HerbShop_Text_YouveComeToLookAtHerbalMedicine:
	.string "Bạn đến LAVARIDGE để tìm hiểu thuốc\n"
	.string "thảo dược sao?\p"
	.string "Thật đáng khen.\p"
	.string "Tôi thích bạn đấy! Cầm lấy này!$"

LavaridgeTown_HerbShop_Text_ExplainCharcoal:
	.string "CHARCOAL tôi đưa bạn được dùng để chế\n"
	.string "thuốc thảo dược.\p"
	.string "Nó cũng phát huy tác dụng tuyệt vời khi\n"
	.string "được POKéMON mang theo.\p"
	.string "Nó làm tăng sức mạnh của các chiêu hệ\n"
	.string "FIRE.$"

LavaridgeTown_HerbShop_Text_HerbalMedicineWorksButMonWillDislike:
	.string "Thuốc thảo dược có hiệu quả đáng kinh\n"
	.string "ngạc. Nhưng POKéMON của bạn sẽ không\l"
	.string "thích bạn vì bị cho dùng chúng. Chắc\l"
	.string "chúng đắng khủng khiếp lắm!$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global LavaridgeTown_HerbShop_Text_WelcomeToHerbShop
	.global LavaridgeTown_HerbShop_Text_YouveComeToLookAtHerbalMedicine
	.global LavaridgeTown_HerbShop_Text_ExplainCharcoal
	.global LavaridgeTown_HerbShop_Text_HerbalMedicineWorksButMonWillDislike
@ END GENERATED LOCALIZATION EXPORTS
