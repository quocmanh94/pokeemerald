SlateportCity_SternsShipyard_2F_MapScripts::
	.byte 0

SlateportCity_SternsShipyard_2F_EventScript_Scientist1::
	msgbox SlateportCity_SternsShipyard_2F_Text_ShipDesignMoreLikeBuilding, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_2F_EventScript_Scientist2::
	msgbox SlateportCity_SternsShipyard_2F_Text_FloatsBecauseBuoyancy, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_2F_Text_ShipDesignMoreLikeBuilding:
	.string "Thiết kế một con tàu lớn giống xây dựng\n"
	.string "một tòa nhà lớn hơn là lắp ráp một\l"
	.string "phương tiện giao thông.$"

SlateportCity_SternsShipyard_2F_Text_FloatsBecauseBuoyancy:
	.string "Bạn không thấy lạ khi một con tàu làm\n"
	.string "bằng sắt nặng nề lại có thể nổi sao?\p"
	.string "Nó nổi được là nhờ một nguyên lý gọi là\n"
	.string "lực nổi.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global SlateportCity_SternsShipyard_2F_Text_ShipDesignMoreLikeBuilding
	.global SlateportCity_SternsShipyard_2F_Text_FloatsBecauseBuoyancy
@ END GENERATED LOCALIZATION EXPORTS
