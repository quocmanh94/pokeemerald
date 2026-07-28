FortreeCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, FortreeCity_OnResume
	.byte 0

FortreeCity_OnTransition:
	setflag FLAG_VISITED_FORTREE_CITY
	end

FortreeCity_OnResume:
	setstepcallback STEP_CB_FORTREE_BRIDGE
	end

FortreeCity_EventScript_Man::
	msgbox FortreeCity_Text_SawGiganticPokemonInSky, MSGBOX_NPC
	end

FortreeCity_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_KECLEON_FLED_FORTREE, FortreeCity_EventScript_WomanGymAccessible
	msgbox FortreeCity_Text_SomethingBlockingGym, MSGBOX_DEFAULT
	release
	end

FortreeCity_EventScript_WomanGymAccessible::
	msgbox FortreeCity_Text_ThisTimeIllBeatWinona, MSGBOX_DEFAULT
	release
	end

FortreeCity_EventScript_Girl::
	msgbox FortreeCity_Text_TreesGrowByDrinkingRainwater, MSGBOX_NPC
	end

FortreeCity_EventScript_OldMan::
	msgbox FortreeCity_Text_EveryoneHealthyAndLively, MSGBOX_NPC
	end

FortreeCity_EventScript_Boy::
	msgbox FortreeCity_Text_BugPokemonComeThroughWindow, MSGBOX_NPC
	end

FortreeCity_EventScript_GameboyKid::
	msgbox FortreeCity_Text_PokemonThatEvolveWhenTraded, MSGBOX_NPC
	end

FortreeCity_EventScript_CitySign::
	msgbox FortreeCity_Text_CitySign, MSGBOX_SIGN
	end

FortreeCity_EventScript_GymSign::
	msgbox FortreeCity_Text_GymSign, MSGBOX_SIGN
	end

FortreeCity_EventScript_Kecleon::
	lock
	faceplayer
	checkitem ITEM_DEVON_SCOPE
	goto_if_eq VAR_RESULT, TRUE, FortreeCity_EventScript_AskUseDevonScope
	msgbox FortreeCity_Text_SomethingUnseeable, MSGBOX_DEFAULT
	release
	end

FortreeCity_EventScript_AskUseDevonScope::
	msgbox FortreeCity_Text_UnseeableUseDevonScope, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FortreeCity_EventScript_UseDevonScope
	release
	end

FortreeCity_EventScript_UseDevonScope::
	msgbox FortreeCity_Text_UsedDevonScopePokemonFled, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Movement_KecleonAppears
	waitmovement 0
	waitse
	playmoncry SPECIES_KECLEON, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	applymovement VAR_LAST_TALKED, FortreeCity_Movement_KecleonFlee
	waitmovement 0
	removeobject VAR_LAST_TALKED
	setflag FLAG_KECLEON_FLED_FORTREE
	release
	end

FortreeCity_Movement_KecleonFlee:
	walk_right
	step_end

FortreeCity_Text_SawGiganticPokemonInSky:
	.string "Không ai tin tôi, nhưng tôi đã thấy một\n"
	.string "POKéMON khổng lồ trên bầu trời.\p"
	.string "Nó có vẻ uốn éo khi bay về phía ROUTE\n"
	.string "131.\p"
	.string "Mà này... Khịt... Ừm... Bạn, ờ... có mùi\n"
	.string "khét.\p"
	.string "Bạn vừa ở núi lửa hay đâu đó sao?$"

FortreeCity_Text_SomethingBlockingGym:
	.string "Tôi muốn đến POKéMON GYM, nhưng có thứ\n"
	.string "gì đó chặn đường.\p"
	.string "Bao công sức tôi luyện tập trên ROUTE\n"
	.string "120...$"

FortreeCity_Text_ThisTimeIllBeatWinona:
	.string "Tôi đã mang theo POKéMON niềm tự hào\n"
	.string "của mình. Lần này, tôi sẽ đánh bại\l"
	.string "WINONA.$"

FortreeCity_Text_TreesGrowByDrinkingRainwater:
	.string "Mặt đất hấp thụ nước mưa, rồi cây cối\n"
	.string "hút lấy nguồn nước ấy để lớn lên...\p"
	.string "FORTREE CITY của chúng tôi tồn tại nhờ\n"
	.string "có cả nước lẫn đất.$"

FortreeCity_Text_EveryoneHealthyAndLively:
	.string "CITY gồm những ngôi nhà được xây trên\n"
	.string "cây.\p"
	.string "Có lẽ nhờ lối sống đó mà ai cũng khỏe\n"
	.string "mạnh và tràn đầy sức sống.\p"
	.string "Ngay cả tôi cũng cảm thấy như mình trẻ\n"
	.string "lại ba mươi tuổi.$"

FortreeCity_Text_BugPokemonComeThroughWindow:
	.string "Sống trên ngọn cây cũng ổn.\p"
	.string "Nhưng đôi khi BUG POKéMON bay vào qua\n"
	.string "cửa sổ. Giật mình lắm đấy.$"

FortreeCity_Text_PokemonThatEvolveWhenTraded:
	.string "Nghe nói có những POKéMON sẽ tiến hóa\n"
	.string "khi được trao đổi!$"

FortreeCity_Text_SomethingUnseeable:
	.string "Có thứ gì đó không nhìn thấy đang chắn\n"
	.string "đường.$"

FortreeCity_Text_UnseeableUseDevonScope:
	.string "Có thứ gì đó không nhìn thấy đang chắn\n"
	.string "đường.\p"
	.string "Bạn có muốn dùng DEVON SCOPE không?$"

FortreeCity_Text_UsedDevonScopePokemonFled:
	.string "{PLAYER} đã dùng DEVON SCOPE.\p"
	.string "POKéMON vô hình đã hiện ra hoàn toàn!\p"
	.string "POKéMON giật mình rồi bỏ chạy!$"

FortreeCity_Text_CitySign:
	.string "FORTREE CITY: Thành phố trên ngọn cây\n"
	.string "vui đùa cùng thiên nhiên.$"

FortreeCity_Text_GymSign:
	.string "FORTREE CITY POKéMON GYM LEADER:\n"
	.string "WINONA\p"
	.string "Người điều khiển chim cất cánh bay ra\n"
	.string "thế giới.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global FortreeCity_Text_SawGiganticPokemonInSky
	.global FortreeCity_Text_SomethingBlockingGym
	.global FortreeCity_Text_ThisTimeIllBeatWinona
	.global FortreeCity_Text_TreesGrowByDrinkingRainwater
	.global FortreeCity_Text_EveryoneHealthyAndLively
	.global FortreeCity_Text_BugPokemonComeThroughWindow
	.global FortreeCity_Text_PokemonThatEvolveWhenTraded
	.global FortreeCity_Text_SomethingUnseeable
	.global FortreeCity_Text_UnseeableUseDevonScope
	.global FortreeCity_Text_UsedDevonScopePokemonFled
	.global FortreeCity_Text_CitySign
	.global FortreeCity_Text_GymSign
@ END GENERATED LOCALIZATION EXPORTS
