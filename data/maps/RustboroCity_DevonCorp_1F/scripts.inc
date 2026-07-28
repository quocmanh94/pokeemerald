RustboroCity_DevonCorp_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_DevonCorp_1F_OnTransition
	.byte 0

RustboroCity_DevonCorp_1F_OnTransition:
	call_if_unset FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_BlockStairs
	end

RustboroCity_DevonCorp_1F_EventScript_BlockStairs::
	setobjectxyperm LOCALID_DEVON_CORP_STAIR_GUARD, 14, 2
	setobjectmovementtype LOCALID_DEVON_CORP_STAIR_GUARD, MOVEMENT_TYPE_FACE_DOWN
	return

RustboroCity_DevonCorp_1F_EventScript_Employee::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_GoodsRecovered
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_RobberWasntBright
	msgbox RustboroCity_DevonCorp_1F_Text_ThoseShoesAreOurProduct, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_RobberWasntBright::
	msgbox RustboroCity_DevonCorp_1F_Text_RobberWasntVeryBright, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_GoodsRecovered::
	msgbox RustboroCity_DevonCorp_1F_Text_SoundsLikeStolenGoodsRecovered, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_StairGuard::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_AlwaysWelcome
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_GotRobbed
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_GotRobbed
	msgbox RustboroCity_DevonCorp_1F_Text_OnlyAuthorizedPeopleEnter, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_AlwaysWelcome::
	msgbox RustboroCity_DevonCorp_1F_Text_YoureAlwaysWelcomeHere, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_GotRobbed::
	msgbox RustboroCity_DevonCorp_1F_Text_HowCouldWeGetRobbed, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_Greeter::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_WelcomeToDevonCorp
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_StaffGotRobbed
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_StaffGotRobbed
	msgbox RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_WelcomeToDevonCorp::
	msgbox RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_StaffGotRobbed::
	msgbox RustboroCity_DevonCorp_1F_Text_StaffGotRobbed, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_RocksMetalDisplay::
	msgbox RustboroCity_DevonCorp_1F_Text_RocksMetalDisplay, MSGBOX_SIGN
	end

RustboroCity_DevonCorp_1F_EventScript_ProductsDisplay::
	msgbox RustboroCity_DevonCorp_1F_Text_ProductDisplay, MSGBOX_SIGN
	end

RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp:
	.string "Xin chào và chào mừng đến với DEVON\n"
	.string "CORPORATION.\p"
	.string "Chúng tôi tự hào sản xuất các vật phẩm\n"
	.string "và thuốc men giúp cuộc sống tốt đẹp\l"
	.string "hơn.$"

RustboroCity_DevonCorp_1F_Text_StaffGotRobbed:
	.string "Một nhân viên nghiên cứu của chúng tôi\n"
	.string "đã ngu ngốc để kẻ khác cướp mất một\l"
	.string "kiện hàng quan trọng.$"

RustboroCity_DevonCorp_1F_Text_ThoseShoesAreOurProduct:
	.string "Này, đôi RUNNING SHOES đó! Chúng là một\n"
	.string "trong các sản phẩm của chúng tôi!\p"
	.string "Tôi rất vui khi thấy có người sử dụng\n"
	.string "sản phẩm do chúng tôi làm ra.$"

RustboroCity_DevonCorp_1F_Text_RobberWasntVeryBright:
	.string "Kiện hàng bị đánh cắp đó...\p"
	.string "Đúng là nó quan trọng, nhưng không phải\n"
	.string "thứ mà ai cũng có thể sử dụng.\p"
	.string "Theo tôi thấy, tên trộm ấy chắc chẳng\n"
	.string "thông minh gì.$"

RustboroCity_DevonCorp_1F_Text_SoundsLikeStolenGoodsRecovered:
	.string "Có vẻ DEVON GOODS bị cướp đã được lấy\n"
	.string "lại rồi.$"

RustboroCity_DevonCorp_1F_Text_OnlyAuthorizedPeopleEnter:
	.string "Xin lỗi, chỉ người được ủy quyền mới\n"
	.string "được phép vào đây.$"

RustboroCity_DevonCorp_1F_Text_HowCouldWeGetRobbed:
	.string "Ngu ngốc hết chỗ nói. Sao chúng ta lại\n"
	.string "để bị cướp chứ?$"

RustboroCity_DevonCorp_1F_Text_YoureAlwaysWelcomeHere:
	.string "Xin chào! Bạn luôn được chào đón ở\n"
	.string "đây!$"

RustboroCity_DevonCorp_1F_Text_RocksMetalDisplay:
	.string "Các mẫu đá và kim loại được trưng bày\n"
	.string "trong tủ kính.\p"
	.string "Trên đó có một tấm bảng ghi...\p"
	.string "“DEVON CORPORATION khởi đầu bằng việc\n"
	.string "sản xuất đá lấy từ các mỏ.\p"
	.string "Công ty cũng sản xuất sắt từ mạt sắt\n"
	.string "trong cát.\p"
	.string "Từ khởi đầu khiêm tốn với vai trò nhà\n"
	.string "sản xuất nguyên liệu thô, DEVON đã phát\l"
	.string "triển.\p"
	.string "Giờ đây, DEVON là nhà sản xuất nhiều\n"
	.string "loại sản phẩm công nghiệp.“$"

RustboroCity_DevonCorp_1F_Text_ProductDisplay:
	.string "Các nguyên mẫu và sản phẩm thử nghiệm\n"
	.string "được trưng bày đầy trong tủ kính.\p"
	.string "Trên đó có một tấm bảng mô tả...\p"
	.string "“Ngoài sản phẩm công nghiệp, DEVON hiện\n"
	.string "còn kinh doanh hàng tiêu dùng và dược\l"
	.string "phẩm nhằm nâng cao chất lượng cuộc\l"
	.string "sống.\p"
	.string "Gần đây, DEVON đã bắt đầu kinh doanh\n"
	.string "công cụ dành cho HLV POKéMON, bao\l"
	.string "gồm POKé BALLS và hệ thống POKéNAV.“$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp
	.global RustboroCity_DevonCorp_1F_Text_StaffGotRobbed
	.global RustboroCity_DevonCorp_1F_Text_ThoseShoesAreOurProduct
	.global RustboroCity_DevonCorp_1F_Text_RobberWasntVeryBright
	.global RustboroCity_DevonCorp_1F_Text_SoundsLikeStolenGoodsRecovered
	.global RustboroCity_DevonCorp_1F_Text_OnlyAuthorizedPeopleEnter
	.global RustboroCity_DevonCorp_1F_Text_HowCouldWeGetRobbed
	.global RustboroCity_DevonCorp_1F_Text_YoureAlwaysWelcomeHere
	.global RustboroCity_DevonCorp_1F_Text_RocksMetalDisplay
	.global RustboroCity_DevonCorp_1F_Text_ProductDisplay
@ END GENERATED LOCALIZATION EXPORTS
