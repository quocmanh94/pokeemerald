LavaridgeTown_House_MapScripts::
	.byte 0

LavaridgeTown_House_EventScript_OldMan::
	msgbox LavaridgeTown_House_Text_WifeWarmingEggInHotSprings, MSGBOX_NPC
	end

LavaridgeTown_House_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox LavaridgeTown_House_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

LavaridgeTown_House_Text_WifeWarmingEggInHotSprings:
	.string "Vợ tôi đang ủ ấm một EGG trong suối\n"
	.string "nước nóng. Cô ấy kể với tôi thế này.\p"
	.string "Cô ấy gửi hai POKéMON ở DAY CARE. Rồi\n"
	.string "người ta phát hiện ra EGG đó!$"

LavaridgeTown_House_Text_Zigzagoon:
	.string "ZIGZAGOON: Phù!$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global LavaridgeTown_House_Text_WifeWarmingEggInHotSprings
	.global LavaridgeTown_House_Text_Zigzagoon
@ END GENERATED LOCALIZATION EXPORTS
