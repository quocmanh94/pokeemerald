Route111_Text_MakingRoomUseTMToMakeYourOwn:
	.string "Sao cơ? Tôi đang làm gì à?\p"
	.string "Tôi đang nghĩ đến việc dùng một chiêu\n"
	.string "thức của POKéMON để tạo căn phòng\l"
	.string "riêng ở đây.\p"
	.string "Biết rồi! Tôi sẽ tặng bạn TM này. Bạn có\n"
	.string "muốn dùng nó để tạo căn phòng riêng\l"
	.string "không?$"

Route111_Text_ExplainSecretPower:
	.string "Hãy tìm một cây lớn trông như có thể\n"
	.string "thả dây leo xuống.\p"
	.string "Dùng SECRET POWER trước cái cây. Một\n"
	.string "số dây leo sẽ bung ra và thả xuống để\l"
	.string "bạn có thể trèo lên cây.\p"
	.string "Bên trong sẽ có rất nhiều chỗ để đặt\n"
	.string "những món đồ bạn yêu thích.\p"
	.string "Đó sẽ là căn phòng bí mật của riêng\n"
	.string "bạn... Một SECRET BASE!\p"
	.string "Bạn cũng nên tạo một nơi như thế.\p"
	.string "Còn nữa, bạn không nhất thiết phải tạo\n"
	.string "SECRET BASE trên cây.\p"
	.string "Hãy thử dùng SECRET POWER lên những\n"
	.string "vách đá có chỗ lõm nhỏ.\p"
	.string "Tôi cũng sẽ đi tìm những nơi khác.\n"
	.string "Được rồi, tạm biệt!$"

Route111_Text_DontWantThis:
	.string "Ồ, bạn không muốn món này sao? Nếu đổi\n"
	.string "ý thì hãy nói với tôi nhé?$"

Route111_Text_DontHaveAnyRoom:
	.string "Ồ, bạn không còn chỗ để nhận món này.\p"
	.string "Tôi sẽ giữ nó, nên lần khác quay lại lấy\n"
	.string "nhé?$"

Route111_EventScript_SecretPowerMan::
	lock
	faceplayer
	msgbox Route111_Text_MakingRoomUseTMToMakeYourOwn, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route111_EventScript_GiveSecretPower
	msgbox Route111_Text_DontWantThis, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_GiveSecretPower::
	giveitem ITEM_TM_SECRET_POWER
	goto_if_eq VAR_RESULT, FALSE, Route111_EventScript_NoRoomForSecretPower
	msgbox Route111_Text_ExplainSecretPower, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_RECEIVED_SECRET_POWER
	clearflag FLAG_HIDE_SLATEPORT_CITY_TM_SALESMAN
	call_if_eq VAR_FACING, DIR_WEST, Route111_EventScript_SecretPowerManExit
	call_if_eq VAR_FACING, DIR_EAST, Route111_EventScript_SecretPowerManExit
	call_if_eq VAR_FACING, DIR_NORTH, Route111_EventScript_SecretPowerManExitNorth
	removeobject VAR_LAST_TALKED
	release
	end

Route111_EventScript_SecretPowerManExit::
	applymovement VAR_LAST_TALKED, Route111_Movement_SecretPowerManExit
	waitmovement 0
	return

Route111_EventScript_SecretPowerManExitNorth::
	applymovement VAR_LAST_TALKED, Route111_Movement_SecretPowerManExitNorth
	waitmovement 0
	return

Route111_EventScript_NoRoomForSecretPower::
	msgbox Route111_Text_DontHaveAnyRoom, MSGBOX_DEFAULT
	release
	end

Route111_Movement_SecretPowerManExit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

Route111_Movement_SecretPowerManExitNorth:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global Route111_Text_MakingRoomUseTMToMakeYourOwn
	.global Route111_Text_ExplainSecretPower
	.global Route111_Text_DontWantThis
	.global Route111_Text_DontHaveAnyRoom
@ END GENERATED LOCALIZATION EXPORTS
