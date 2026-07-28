SootopolisCity_House6_MapScripts::
	.byte 0

SootopolisCity_House6_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_WAILMER_DOLL, SootopolisCity_House6_EventScript_ReceivedWailmerDoll
	msgbox SootopolisCity_House6_Text_FirstGuestInWhileTakeDoll, MSGBOX_YESNO
	call_if_eq VAR_RESULT, NO, SootopolisCity_House6_EventScript_DeclineWailmerDoll
	msgbox SootopolisCity_House6_Text_TakeGoodCareOfIt, MSGBOX_DEFAULT
	givedecoration DECOR_WAILMER_DOLL
	goto_if_eq VAR_RESULT, FALSE, SootopolisCity_House6_EventScript_NoRoomForWailmerDoll
	setflag FLAG_RECEIVED_WAILMER_DOLL
	release
	end

SootopolisCity_House6_EventScript_DeclineWailmerDoll::
	msgbox SootopolisCity_House6_Text_DontWantThisDoll, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House6_EventScript_ReceivedWailmerDoll::
	msgbox SootopolisCity_House6_Text_LovePlushDolls, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House6_EventScript_NoRoomForWailmerDoll::
	bufferdecorationname STR_VAR_2, DECOR_WAILMER_DOLL
	msgbox gText_NoRoomLeftForAnother, MSGBOX_DEFAULT
	msgbox SootopolisCity_House6_Text_IllHoldItForYou, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House6_Text_FirstGuestInWhileTakeDoll:
	.string "Xin chào! Bạn là vị khách đầu tiên của\n"
	.string "chúng tôi sau một thời gian dài.\p"
	.string "Bạn đã khiến ngày hôm nay của tôi vui\n"
	.string "hẳn lên, nên tôi sẽ tặng bạn một\l"
	.string "WAILMER DOLL lớn.$"

SootopolisCity_House6_Text_TakeGoodCareOfIt:
	.string "Hãy chăm sóc nó thật tốt nhé!$"

SootopolisCity_House6_Text_IllHoldItForYou:
	.string "Ồ, bạn muốn nó nhưng chưa lấy ngay bây\n"
	.string "giờ sao? Được rồi, vậy tôi sẽ giữ nó\l"
	.string "giúp bạn.$"

SootopolisCity_House6_Text_DontWantThisDoll:
	.string "Bạn chắc chứ? Bạn không muốn DOLL này\n"
	.string "sao?$"

SootopolisCity_House6_Text_LovePlushDolls:
	.string "Tôi rất thích DOLLS bằng bông!$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global SootopolisCity_House6_Text_FirstGuestInWhileTakeDoll
	.global SootopolisCity_House6_Text_TakeGoodCareOfIt
	.global SootopolisCity_House6_Text_IllHoldItForYou
	.global SootopolisCity_House6_Text_DontWantThisDoll
	.global SootopolisCity_House6_Text_LovePlushDolls
@ END GENERATED LOCALIZATION EXPORTS
