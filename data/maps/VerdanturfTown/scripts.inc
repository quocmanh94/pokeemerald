VerdanturfTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VerdanturfTown_OnTransition
	.byte 0

VerdanturfTown_OnTransition:
	setflag FLAG_VISITED_VERDANTURF_TOWN
	setvar VAR_CONTEST_HALL_STATE, 0
	end

VerdanturfTown_EventScript_Twin::
	lock
	faceplayer
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_EventScript_TwinTunnelOpen
	msgbox VerdanturfTown_Text_ManTryingToDigTunnel, MSGBOX_DEFAULT
	applymovement LOCALID_VERDANTURF_TWIN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

VerdanturfTown_EventScript_TwinTunnelOpen::
	msgbox VerdanturfTown_Text_ManDugTunnelForLove, MSGBOX_DEFAULT
	applymovement LOCALID_VERDANTURF_TWIN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

VerdanturfTown_EventScript_Man::
	msgbox VerdanturfTown_Text_AirCleanHere, MSGBOX_NPC
	end

VerdanturfTown_EventScript_Camper::
	msgbox VerdanturfTown_Text_MakeBattleTentDebut, MSGBOX_NPC
	end

VerdanturfTown_EventScript_Boy::
	lock
	faceplayer
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_EventScript_BoyTunnelOpen
	msgbox VerdanturfTown_Text_GuyTryingToBustThroughCave, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_EventScript_BoyTunnelOpen::
	msgbox VerdanturfTown_Text_EasyToGetToRustboroNow, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_EventScript_TownSign::
	msgbox VerdanturfTown_Text_TownSign, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_WandasHouseSign::
	msgbox VerdanturfTown_Text_WandasHouse, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_BattleTentSign::
	msgbox VerdanturfTown_Text_BattleTentSign, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_RusturfTunnelSign::
	msgbox VerdanturfTown_Text_RusturfTunnelSign, MSGBOX_SIGN
	end

VerdanturfTown_Text_ManTryingToDigTunnel:
	.string "Ba tôi kể đấy.\p"
	.string "Ba nói đường hầm này có rất nhiều\n"
	.string "POKéMON nhút nhát.\p"
	.string "Chúng hoảng sợ trước tiếng động lớn\n"
	.string "rồi làm náo loạn cả lên.\p"
	.string "Vì thế, dự án đường hầm lớn đã phải\n"
	.string "dừng lại.\p"
	.string "Nhưng có một người vẫn đang tự mình\n"
	.string "đào đường hầm!$"

VerdanturfTown_Text_ManDugTunnelForLove:
	.string "Có một người đã đào đường hầm vì\n"
	.string "người con gái mình yêu.\p"
	.string "Tôi cũng chẳng hiểu lắm, nhưng mà, ghê\n"
	.string "thật!$"

VerdanturfTown_Text_AirCleanHere:
	.string "Do hướng gió nên tro núi lửa không bao\n"
	.string "giờ bay đến đây.\p"
	.string "Không khí nơi này trong lành và dễ chịu.\n"
	.string "Sống ở đây hẳn sẽ rất tốt ngay cả với\l"
	.string "những người yếu ớt, hay đau ốm.$"

VerdanturfTown_Text_MakeBattleTentDebut:
	.string "Tôi và POKéMON của mình đang thắng như\n"
	.string "chẻ tre.\p"
	.string "Vì thế, tôi quyết định ra mắt tại BATTLE\n"
	.string "TENT ở thị trấn này.$"

VerdanturfTown_Text_GuyTryingToBustThroughCave:
	.string "Bạn thấy hang động cạnh POKéMON MART\n"
	.string "chưa?\p"
	.string "Trong đó có một người đang cố đập vỡ\n"
	.string "đá tảng để mở đường sang phía bên kia.\p"
	.string "Nếu có thể đi xuyên qua thì tuyệt quá...\n"
	.string "Đến RUSTBORO sẽ dễ dàng hơn nhiều.$"

VerdanturfTown_Text_EasyToGetToRustboroNow:
	.string "Hang động cạnh POKéMON MART giờ đã\n"
	.string "trở thành đường hầm thông sang phía\l"
	.string "bên kia.\p"
	.string "Tuyệt thật, giờ đến RUSTBORO mua sản\n"
	.string "phẩm DEVON mới dễ dàng hơn nhiều.$"

VerdanturfTown_Text_TownSign:
	.string "VERDANTURF TOWN\p"
	.string "Cao nguyên lộng gió, thoảng hương cỏ\n"
	.string "ngọt ngào.$"

VerdanturfTown_Text_WandasHouse:
	.string "WANDA'S HOUSE$"

VerdanturfTown_Text_BattleTentSign:
	.string "BATTLE TENT VERDANTURF SITE Hãy mãn\n"
	.string "nhãn với những trận đấu!$"

VerdanturfTown_Text_RusturfTunnelSign:
	.string "RUSTURF TUNNEL Nối liền RUSTBORO và\n"
	.string "VERDANTURF\p"
	.string "Dự án đường hầm đã bị hủy bỏ.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global VerdanturfTown_Text_ManTryingToDigTunnel
	.global VerdanturfTown_Text_ManDugTunnelForLove
	.global VerdanturfTown_Text_AirCleanHere
	.global VerdanturfTown_Text_MakeBattleTentDebut
	.global VerdanturfTown_Text_GuyTryingToBustThroughCave
	.global VerdanturfTown_Text_EasyToGetToRustboroNow
	.global VerdanturfTown_Text_TownSign
	.global VerdanturfTown_Text_BattleTentSign
	.global VerdanturfTown_Text_RusturfTunnelSign
@ END GENERATED LOCALIZATION EXPORTS
