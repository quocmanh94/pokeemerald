MossdeepCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_OnTransition
	.byte 0

MossdeepCity_OnTransition:
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	end

MossdeepCity_EventScript_PokefanF::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_DIVE, MossdeepCity_EventScript_PokefanFMagmaGone
	msgbox MossdeepCity_Text_SpaceCenterReceivedLetter, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_PokefanFMagmaGone::
	msgbox MossdeepCity_Text_SpaceCenterLaunchingRockets, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_Sailor::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_DIVE, MossdeepCity_EventScript_SailorMagmaGone
	msgbox MossdeepCity_Text_MossdeepTargetedByMagma, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_SailorMagmaGone::
	msgbox MossdeepCity_Text_FeelReliefOnLand, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_NinjaBoy::
	msgbox MossdeepCity_Text_WailmerWatching, MSGBOX_NPC
	end

MossdeepCity_EventScript_ExpertM::
	msgbox MossdeepCity_Text_LifeNeedsSeaToLive, MSGBOX_NPC
	end

MossdeepCity_EventScript_Girl::
	msgbox MossdeepCity_Text_NiceIfWorldCoveredByFlowers, MSGBOX_NPC
	end

MossdeepCity_EventScript_Woman::
	msgbox MossdeepCity_Text_SpecialSpaceCenterRock, MSGBOX_NPC
	end

MossdeepCity_EventScript_WhiteRock::
	msgbox MossdeepCity_Text_ItsAWhiteRock, MSGBOX_SIGN
	end

MossdeepCity_EventScript_GymSign::
	msgbox MossdeepCity_Text_GymSign, MSGBOX_SIGN
	end

MossdeepCity_EventScript_CitySign::
	msgbox MossdeepCity_Text_CitySign, MSGBOX_SIGN
	end

MossdeepCity_EventScript_SpaceCenterSign::
	msgbox MossdeepCity_Text_SpaceCenterSign, MSGBOX_SIGN
	end

MossdeepCity_EventScript_VisitedMossdeep::
	setflag FLAG_VISITED_MOSSDEEP_CITY
	setvar VAR_TEMP_1, 1
	end

MossdeepCity_EventScript_TeamMagmaEnterSpaceCenter::
	lockall
	applymovement LOCALID_MOSSDEEP_MAXIE, MossdeepCity_Movement_MaxieGestureToSpaceCenter
	waitmovement 0
	applymovement LOCALID_MOSSDEEP_GRUNT_1, MossdeepCity_Movement_GruntFaceSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_2, MossdeepCity_Movement_GruntFaceSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_3, MossdeepCity_Movement_GruntFaceSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_4, MossdeepCity_Movement_GruntFaceSpaceCenter
	waitmovement 0
	applymovement LOCALID_MOSSDEEP_MAXIE, MossdeepCity_Movement_MaxieEnterSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_1, MossdeepCity_Movement_Grunt1EnterSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_2, MossdeepCity_Movement_Grunt2EnterSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_3, MossdeepCity_Movement_Grunt3EnterSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_4, MossdeepCity_Movement_Grunt4EnterSpaceCenter
	waitmovement 0
	removeobject LOCALID_MOSSDEEP_MAXIE
	removeobject LOCALID_MOSSDEEP_GRUNT_1
	removeobject LOCALID_MOSSDEEP_GRUNT_2
	removeobject LOCALID_MOSSDEEP_GRUNT_3
	removeobject LOCALID_MOSSDEEP_GRUNT_4
	delay 30
	setvar VAR_MOSSDEEP_CITY_STATE, 2
	setflag FLAG_HIDE_MOSSDEEP_CITY_TEAM_MAGMA
	releaseall
	end

MossdeepCity_Movement_MaxieGestureToSpaceCenter:
	delay_16
	face_right
	delay_16
	delay_16
	delay_16
	delay_16
	face_left
	delay_16
	delay_16
	step_end

MossdeepCity_Movement_GruntFaceSpaceCenter:
	face_right
	delay_16
	delay_16
	delay_16
	step_end

MossdeepCity_Movement_MaxieEnterSpaceCenter:
	walk_down
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt1EnterSpaceCenter:
	delay_16
	delay_8
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt2EnterSpaceCenter:
	delay_16
	delay_8
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt3EnterSpaceCenter:
	delay_16
	delay_8
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt4EnterSpaceCenter:
	delay_16
	delay_8
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_EventScript_Man::
	lock
	faceplayer
	msgbox MossdeepCity_Text_SurfExhilarating, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MossdeepCity_EventScript_KingsRockBoy::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_KINGS_ROCK, MossdeepCity_EventScript_ReceivedKingsRock
	msgbox MossdeepCity_Text_WantKingsRockStevenGaveMe, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MossdeepCity_EventScript_DeclineKingsRock
	msgbox MossdeepCity_Text_YouCanKeepIt, MSGBOX_DEFAULT
	giveitem ITEM_KINGS_ROCK
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_KINGS_ROCK
	release
	end

MossdeepCity_EventScript_ReceivedKingsRock::
	msgbox MossdeepCity_Text_StevensHouseOverThere, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_DeclineKingsRock::
	msgbox MossdeepCity_Text_WhatToDoWithWeirdRock, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_BlackBelt::
	msgbox MossdeepCity_Text_SootopolisNewGymLeader, MSGBOX_NPC
	end

MossdeepCity_EventScript_Scott::
	lock
	faceplayer
	msgbox MossdeepCity_Text_ScottSomethingWrongWithTown, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, MossdeepCity_EventScript_ScottExitNorth
	call_if_eq VAR_FACING, DIR_EAST, MossdeepCity_EventScript_ScottExitEast
	addvar VAR_SCOTT_STATE, 1
	removeobject LOCALID_MOSSDEEP_SCOTT
	release
	end

MossdeepCity_EventScript_ScottExitNorth::
	applymovement LOCALID_PLAYER, MossdeepCity_Movement_PlayerWatchScottExit
	applymovement LOCALID_MOSSDEEP_SCOTT, MossdeepCity_Movement_ScottExitNorth
	waitmovement 0
	return

MossdeepCity_EventScript_ScottExitEast::
	applymovement LOCALID_PLAYER, MossdeepCity_Movement_PlayerWatchScottExit
	applymovement LOCALID_MOSSDEEP_SCOTT, MossdeepCity_Movement_ScottExitEast
	waitmovement 0
	return

MossdeepCity_Movement_PlayerWatchScottExit:
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

MossdeepCity_Movement_ScottExitNorth:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MossdeepCity_Movement_ScottExitEast:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MossdeepCity_Text_WantKingsRockStevenGaveMe:
	.string "Tôi nhận thứ này từ STEVEN, nhưng\n"
	.string "chẳng biết nó có tác dụng gì.\p"
	.string "Hình như nó được gọi là KING'S ROCK.\n"
	.string "Bạn có muốn lấy không?$"

MossdeepCity_Text_YouCanKeepIt:
	.string "Sao bạn lại muốn nó chứ? Bạn kỳ quặc\n"
	.string "thật.\p"
	.string "Cứ giữ lấy, nhưng phải giấu STEVEN đấy\n"
	.string "nhé.$"

MossdeepCity_Text_StevensHouseOverThere:
	.string "Nhà của STEVEN ở ngay đằng kia!$"

MossdeepCity_Text_WhatToDoWithWeirdRock:
	.string "Phải, bạn cũng nghĩ vậy đúng không! Một\n"
	.string "hòn đá kỳ quặc thì dùng để làm gì chứ?$"

MossdeepCity_Text_WailmerWatching:
	.string "Quanh MOSSDEEP, bạn có thể nhìn thấy\n"
	.string "WAILMER hoang dã.\p"
	.string "Hoạt động đó gọi là, ờ... Là gì nhỉ...\p"
	.string "WAI, WAI, WAI...\p"
	.string "Ngắm WAILMER!$"

MossdeepCity_Text_SpaceCenterReceivedLetter:
	.string "SPACE CENTER trên đảo vẫn đang phóng\n"
	.string "những tên lửa khổng lồ.\p"
	.string "Gần đây, một lá thư họ nhận được đã\n"
	.string "gây ra vụ náo động gì đó.$"

MossdeepCity_Text_SpaceCenterLaunchingRockets:
	.string "SPACE CENTER trên đảo vẫn đang phóng\n"
	.string "những tên lửa khổng lồ.$"

MossdeepCity_Text_MossdeepTargetedByMagma:
	.string "Tôi nghe một người bạn SAILOR kể rằng\n"
	.string "TEAM AQUA đã lập căn cứ tại LILYCOVE.\p"
	.string "Tôi còn nghe nói có người xuất hiện và\n"
	.string "đánh cho chúng tơi bời!\p"
	.string "Nhưng MOSSDEEP này lại trở thành mục\n"
	.string "tiêu của TEAM MAGMA.\p"
	.string "Nếu muốn biết chúng đang mưu tính gì,\n"
	.string "hãy đến SPACE CENTER.$"

MossdeepCity_Text_FeelReliefOnLand:
	.string "Tôi là SAILOR, nên biển cả hiển nhiên\n"
	.string "quan trọng với tôi hơn.\p"
	.string "Nhưng bạn biết không? Sau một chuyến\n"
	.string "hải trình dài, lúc trở lại đất liền tôi\l"
	.string "thật sự cảm thấy nhẹ nhõm!$"

MossdeepCity_Text_NiceIfWorldCoveredByFlowers:
	.string "Sẽ tuyệt lắm, phải không?\p"
	.string "Nếu cả thế giới đều được phủ đầy cây\n"
	.string "cỏ và hoa lá như hòn đảo này?$"

MossdeepCity_Text_LifeNeedsSeaToLive:
	.string "Mọi sinh vật đều cần biển để sống, dù\n"
	.string "chúng cư ngụ trên đất liền.\p"
	.string "Khi cuộc đời kết thúc, sinh vật trở\n"
	.string "thành đất và quay về với đất liền.\p"
	.string "Biển cũng luôn kết nối với đất liền.\p"
	.string "Phải, giống như chính bờ biển nơi đây.$"

MossdeepCity_Text_SurfExhilarating:
	.string "Du ngoạn bằng tàu cũng thú vị.\p"
	.string "Nhưng vượt biển cùng POKéMON bằng\n"
	.string "SURF...\p"
	.string "Đó mới là một chuyến đi đầy phấn khích!\n"
	.string "Cháu cũng thấy vậy chứ?$"

MossdeepCity_Text_SpecialSpaceCenterRock:
	.string "Tảng đá này mang ý nghĩa đặc biệt đối\n"
	.string "với những người tại SPACE CENTER.\p"
	.string "Họ đặt nó ở đây để cầu mong tên lửa\n"
	.string "luôn bay an toàn.\p"
	.string "Khi ước nguyện, bạn dùng thứ gì? Bạn\n"
	.string "có ước dưới một vì sao không?\p"
	.string "Tôi dùng thẻ ước để biến điều ước\n"
	.string "thành sự thật. Tôi luôn làm vậy.$"

MossdeepCity_Text_ItsAWhiteRock:
	.string "Đó là một tảng đá màu trắng.$"

MossdeepCity_Text_GymSign:
	.string "MOSSDEEP CITY POKéMON GYM LEADERS:\n"
	.string "LIZA & TATE\p"
	.string "Sự kết hợp huyền bí!$"

MossdeepCity_Text_CitySign:
	.string "MOSSDEEP CITY: Khẩu hiệu của chúng tôi\n"
	.string "là Hãy trân trọng POKéMON!$"

MossdeepCity_Text_SpaceCenterSign:
	.string "MOSSDEEP SPACE CENTER: Nơi gần không\n"
	.string "gian nhất.$"

MossdeepCity_Text_ScottSomethingWrongWithTown:
	.string "SCOTT: {PLAYER}{KUN}, khỏe chứ? Tôi\n"
	.string "thì tuyệt lắm!\p"
	.string "Tôi nghe nói GYM LEADER của MOSSDEEP\n"
	.string "khá mạnh, nên quyết định tự mình đến\l"
	.string "xem thử.\p"
	.string "Nhưng thị trấn này có gì đó không ổn.\p"
	.string "Mọi người cứ bàn tán về một lá thư\n"
	.string "cảnh cáo và SPACE CENTER...\p"
	.string "Dù vậy, tôi không nghĩ chuyện đó liên\n"
	.string "quan gì đến mình.$"

MossdeepCity_Text_SootopolisNewGymLeader:
	.string "A... Cảm giác sóng biển vỗ vào chân thật\n"
	.string "dễ chịu...\p"
	.string "Nhắc đến sóng biển, bạn biết thành phố\n"
	.string "đảo SOOTOPOLIS chứ?\p"
	.string "Hình như GYM ở đó vừa có một LEADER\n"
	.string "mới.\p"
	.string "Mọi người nói vị LEADER mới từng là\n"
	.string "thầy của WALLACE.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global MossdeepCity_Text_WantKingsRockStevenGaveMe
	.global MossdeepCity_Text_YouCanKeepIt
	.global MossdeepCity_Text_StevensHouseOverThere
	.global MossdeepCity_Text_WhatToDoWithWeirdRock
	.global MossdeepCity_Text_WailmerWatching
	.global MossdeepCity_Text_SpaceCenterReceivedLetter
	.global MossdeepCity_Text_SpaceCenterLaunchingRockets
	.global MossdeepCity_Text_MossdeepTargetedByMagma
	.global MossdeepCity_Text_FeelReliefOnLand
	.global MossdeepCity_Text_NiceIfWorldCoveredByFlowers
	.global MossdeepCity_Text_LifeNeedsSeaToLive
	.global MossdeepCity_Text_SurfExhilarating
	.global MossdeepCity_Text_SpecialSpaceCenterRock
	.global MossdeepCity_Text_ItsAWhiteRock
	.global MossdeepCity_Text_GymSign
	.global MossdeepCity_Text_CitySign
	.global MossdeepCity_Text_SpaceCenterSign
	.global MossdeepCity_Text_ScottSomethingWrongWithTown
	.global MossdeepCity_Text_SootopolisNewGymLeader
@ END GENERATED LOCALIZATION EXPORTS
