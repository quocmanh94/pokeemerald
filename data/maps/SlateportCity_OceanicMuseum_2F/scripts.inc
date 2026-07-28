SlateportCity_OceanicMuseum_2F_MapScripts::
	.byte 0

SlateportCity_OceanicMuseum_2F_EventScript_CaptStern::
	lock
	faceplayer
	msgbox SlateportCity_OceanicMuseum_2F_Text_ThankYouForTheParts, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_AQUA, TRUE
	addobject LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_FirstGruntEnter
	waitmovement 0
	addobject LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_SecondGruntEnter
	waitmovement 0
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_FirstGruntApproach
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_SecondGruntApproach
	waitmovement 0
	call_if_eq VAR_FACING, DIR_SOUTH, SlateportCity_OceanicMuseum_2F_EventScript_PlayerFaceGrunts
	call_if_eq VAR_FACING, DIR_EAST, SlateportCity_OceanicMuseum_2F_EventScript_PlayerFaceGrunts
	msgbox SlateportCity_OceanicMuseum_2F_Text_WellTakeThoseParts, MSGBOX_DEFAULT
	call_if_ne VAR_FACING, DIR_EAST, SlateportCity_OceanicMuseum_2F_EventScript_SternFaceGrunts
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternWhoAreYou, MSGBOX_DEFAULT
	msgbox SlateportCity_OceanicMuseum_2F_Text_WereTeamAqua, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_GruntApproachToBattle
	waitmovement 0
	call_if_eq VAR_FACING, DIR_SOUTH, SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntSouth
	call_if_eq VAR_FACING, DIR_WEST, SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntWest
	trainerbattle_no_intro TRAINER_GRUNT_MUSEUM_1, SlateportCity_OceanicMuseum_2F_Text_Grunt1Defeat
	msgbox SlateportCity_OceanicMuseum_2F_Text_BossGoingToBeFurious, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_GruntDefeated
	waitmovement 0
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_GruntApproachToBattle
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_LetMeTakeCareOfThis, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_MUSEUM_2, SlateportCity_OceanicMuseum_2F_Text_Grunt2Defeat
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_GruntDefeated
	waitmovement 0
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_MeddlingKid, MSGBOX_DEFAULT
	closemessage
	delay 35
	addobject LOCALID_OCEANIC_MUSEUM_2F_ARCHIE
	applymovement LOCALID_OCEANIC_MUSEUM_2F_ARCHIE, SlateportCity_OceanicMuseum_2F_Movement_ArchieEnter
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_GruntMoveForArchie
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_CameToSeeWhatsTakingSoLong, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_OCEANIC_MUSEUM_2F_ARCHIE, SlateportCity_OceanicMuseum_2F_Movement_ArchieApproachPlayer
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_ArchieWarning, MSGBOX_DEFAULT
	closemessage
	savebgm MUS_DUMMY
	fadedefaultbgm
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_OCEANIC_MUSEUM_2F_ARCHIE
	removeobject LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1
	removeobject LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2
	fadescreen FADE_FROM_BLACK
	delay 30
	setflag FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_AQUA_GRUNTS
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternThankYouForSavingUs, MSGBOX_DEFAULT
	setvar VAR_0x8004, ITEM_DEVON_GOODS
	call Common_EventScript_PlayerHandedOverTheItem
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternIveGotToGo, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	removeobject LOCALID_OCEANIC_MUSEUM_2F_CAPT_STERN
	setflag FLAG_HIDE_ROUTE_110_TEAM_AQUA
	call_if_eq VAR_REGISTER_BIRCH_STATE, 0, SlateportCity_OceanicMuseum_2F_EventScript_ReadyRegisterBirch
	setflag FLAG_DELIVERED_DEVON_GOODS
	clearflag FLAG_HIDE_ROUTE_116_DEVON_EMPLOYEE
	setflag FLAG_HIDE_RUSTBORO_CITY_DEVON_CORP_3F_EMPLOYEE
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1
	fadescreen FADE_FROM_BLACK
	release
	end

SlateportCity_OceanicMuseum_2F_EventScript_ReadyRegisterBirch::
	setvar VAR_REGISTER_BIRCH_STATE, 1
	return

SlateportCity_OceanicMuseum_2F_EventScript_PlayerFaceGrunts::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

SlateportCity_OceanicMuseum_2F_EventScript_SternFaceGrunts::
	applymovement LOCALID_OCEANIC_MUSEUM_2F_CAPT_STERN, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntSouth::
	applymovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntSouth
	waitmovement 0
	return

SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntWest::
	applymovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntWest
	waitmovement 0
	return

SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntSouth:
	walk_left
	walk_down
	walk_in_place_faster_left
	step_end

SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntWest:
	walk_up
	walk_left
	walk_left
	walk_down
	walk_in_place_faster_left
	step_end

SlateportCity_OceanicMuseum_2F_Movement_Unused:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_left
	walk_left
	walk_up
	walk_up
	delay_8
	step_end

SlateportCity_OceanicMuseum_2F_Movement_ArchieApproachPlayer:
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_ArchieEnter:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_GruntApproachToBattle:
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_FirstGruntEnter:
	walk_down
	walk_right
	walk_in_place_faster_down
	step_end

SlateportCity_OceanicMuseum_2F_Movement_FirstGruntApproach:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_GruntDefeated:
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

SlateportCity_OceanicMuseum_2F_Movement_SecondGruntEnter:
	walk_down
	step_end

SlateportCity_OceanicMuseum_2F_Movement_SecondGruntApproach:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_GruntMoveForArchie:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_8
	walk_fast_down
	walk_in_place_faster_up
	step_end

SlateportCity_OceanicMuseum_2F_EventScript_WaterQualitySample1::
	msgbox SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample1, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_WaterQualitySample2::
	msgbox SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample2, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_PressureExperiment::
	msgbox SlateportCity_OceanicMuseum_2F_Text_PressureExperiment, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_HoennModel::
	msgbox SlateportCity_OceanicMuseum_2F_Text_HoennModel, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_DeepSeawaterDisplay::
	msgbox SlateportCity_OceanicMuseum_2F_Text_DeepSeawaterDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SurfaceSeawaterDisplay::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SurfaceSeawaterDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SSTidalReplica::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SSTidalReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SubmarineReplica::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SubmarineReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SubmersibleReplica::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SumbersibleReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SSAnneReplica::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SSAnneReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_MuseumPatron1::
	msgbox SlateportCity_OceanicMuseum_2F_Text_RemindsMeOfAbandonedShip, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_2F_EventScript_MuseumPatron2::
	msgbox SlateportCity_OceanicMuseum_2F_Text_DontRunInMuseum, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_2F_EventScript_MuseumPatron3::
	lock
	faceplayer
	msgbox SlateportCity_OceanicMuseum_2F_Text_WantToRideSubmarine, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_OceanicMuseum_2F_Text_ThankYouForTheParts:
	.string "Sao? Nếu cháu đang tìm STERN thì chính\n"
	.string "là tôi đây.\p"
	.string "A! Đây hẳn là số linh kiện tôi đã đặt từ\n"
	.string "MR. STONE của DEVON.\p"
	.string "Cảm ơn cháu! Tuyệt quá! Giờ chúng tôi\n"
	.string "có thể chuẩn bị cho chuyến thám hiểm\l"
	.string "rồi.$"

SlateportCity_OceanicMuseum_2F_Text_WellTakeThoseParts:
	.string "Hehehe, đứng lại! Bọn ta sẽ lấy số linh\n"
	.string "kiện đó!$"

SlateportCity_OceanicMuseum_2F_Text_SternWhoAreYou:
	.string "CAPT. STERN: C-cái gì? Các người là ai?$"

SlateportCity_OceanicMuseum_2F_Text_WereTeamAqua:
	.string "Bọn ta là TEAM AQUA!\p"
	.string "Thủ lĩnh bọn ta muốn số linh kiện đó! Im\n"
	.string "miệng và giao chúng ra đây!$"

SlateportCity_OceanicMuseum_2F_Text_Grunt1Defeat:
	.string "Aaaaa! Mình lại bị một đứa trẻ đánh bại!$"

SlateportCity_OceanicMuseum_2F_Text_BossGoingToBeFurious:
	.string "Ôi trời, nguy rồi... Thủ lĩnh sẽ nổi giận\n"
	.string "mất...$"

SlateportCity_OceanicMuseum_2F_Text_LetMeTakeCareOfThis:
	.string "Hừ, đồ mít ướt vô dụng! Để ta xử lý vụ\n"
	.string "này!$"

SlateportCity_OceanicMuseum_2F_Text_Grunt2Defeat:
	.string "Cái gì?! Cả ta cũng thua sao!$"

SlateportCity_OceanicMuseum_2F_Text_MeddlingKid:
	.string "Giờ phải làm sao? Không lấy được linh\n"
	.string "kiện thì bọn ta tiêu đời!\p"
	.string "Arrgh, ta không ngờ lại bị một đứa trẻ\n"
	.string "lắm chuyện phá đám!$"

SlateportCity_OceanicMuseum_2F_Text_CameToSeeWhatsTakingSoLong:
	.string "Ta đến xem tại sao cướp vài linh kiện mà\n"
	.string "lâu thế, vậy mà lũ ngốc các ngươi lại bị\l"
	.string "một đứa trẻ cản đường sao?$"

SlateportCity_OceanicMuseum_2F_Text_ArchieWarning:
	.string "Bọn ta là TEAM AQUA, những người yêu\n"
	.string "biển cả!\p"
	.string "Còn ta là thủ lĩnh của TEAM AQUA,\n"
	.string "ARCHIE!\p"
	.string "Tại sao ngươi lại cản trở bọn ta?\p"
	.string "...Không! Không thể nào! Ngươi đâu phải\n"
	.string "người của TEAM MAGMA?\p"
	.string "Khoan, không đúng. Ngươi đâu có ăn mặc\n"
	.string "giống bọn chúng.\p"
	.string "... ... ... ... ... ... ... ... ... ... ... ...\p"
	.string "POKéMON, con người... Mọi sự sống đều\n"
	.string "phụ thuộc vào biển cả.\p"
	.string "Vì thế, TEAM AQUA quyết tâm mở rộng\n"
	.string "biển cả.\p"
	.string "Ngươi không đồng ý sao? Việc bọn ta\n"
	.string "đang làm là một sự nghiệp vô cùng vĩ\l"
	.string "đại.\p"
	.string "Hừ, thôi được... Ngươi vẫn còn quá trẻ\n"
	.string "để hiểu mục tiêu cao quý của bọn ta.\p"
	.string "Nhưng ta cảnh cáo ngươi, đừng bao giờ\n"
	.string "nghĩ đến chuyện cản trở kế hoạch của\l"
	.string "bọn ta lần nữa.\p"
	.string "Ngươi sẽ phải trả một cái giá rất đắt!\p"
	.string "Nhớ lấy điều đó!$"

SlateportCity_OceanicMuseum_2F_Text_SternThankYouForSavingUs:
	.string "CAPT. STERN: Cháu là... À, phải rồi, cháu\n"
	.string "là {PLAYER}{KUN}...\p"
	.string "Dù sao thì vừa rồi thật căng thẳng! Cảm\n"
	.string "ơn cháu đã cứu chúng tôi!\p"
	.string "Ô, phải rồi, tôi suýt quên rằng cháu còn\n"
	.string "mang linh kiện từ DEVON đến nữa!$"

SlateportCity_OceanicMuseum_2F_Text_SternIveGotToGo:
	.string "CAPT. STERN: Ôi! Không còn thời gian\n"
	.string "nữa!\p"
	.string "Chúng tôi sắp phải lên đường thám hiểm\n"
	.string "đáy đại dương.\p"
	.string "Cảm ơn cháu lần nữa, nhưng giờ tôi phải\n"
	.string "đi rồi!\p"
	.string "Tuy vậy, cháu cứ tự nhiên tham quan và\n"
	.string "xem các thiết bị ở đây nhé.$"

SlateportCity_OceanicMuseum_2F_Text_RemindsMeOfAbandonedShip:
	.string "Tôi đã thấy một mô hình con tàu ở đây.\p"
	.string "Nó khiến tôi nhớ đến ABANDONED SHIP\n"
	.string "gần DEWFORD TOWN...$"

SlateportCity_OceanicMuseum_2F_Text_DontRunInMuseum:
	.string "Cấm chạy lung tung bên trong MUSEUM!$"

SlateportCity_OceanicMuseum_2F_Text_WantToRideSubmarine:
	.string "Chà, tàu ngầm tuyệt thật! Tôi muốn\n"
	.string "được đi thử!$"

SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample1:
	.string "Trên nhãn ghi WATER QUALITY SAMPLE 1.\p"
	.string "Biển thông với nhau khắp nơi, nhưng\n"
	.string "nước biển dường như lại khác nhau tùy\l"
	.string "từng khu vực.$"

SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample2:
	.string "Trên nhãn ghi WATER QUALITY SAMPLE 2.\p"
	.string "Độ mặn của nước biển cũng khác nhau\n"
	.string "tùy từng khu vực sao?$"

SlateportCity_OceanicMuseum_2F_Text_PressureExperiment:
	.string "Một quả bóng cao su đang phồng lên rồi\n"
	.string "co lại.\p"
	.string "Trong biển, chính trọng lượng của\n"
	.string "nước tạo ra áp suất.\p"
	.string "Ở vùng nước nông, áp suất không quá\n"
	.string "lớn.\p"
	.string "Nhưng ở nơi cực kỳ sâu, áp lực trên\n"
	.string "một diện tích nhỏ có thể lên tới hàng\l"
	.string "chục nghìn tấn.$"

SlateportCity_OceanicMuseum_2F_Text_HoennModel:
	.string "MODEL OF HOENN REGION\p"
	.string "Đây là một sa bàn thu nhỏ của vùng\n"
	.string "HOENN.\p"
	.string "LITTLEROOT TOWN nằm ở đâu trên đây\n"
	.string "nhỉ?$"

SlateportCity_OceanicMuseum_2F_Text_DeepSeawaterDisplay:
	.string "Đây là phần trưng bày về sự lưu chuyển\n"
	.string "của nước biển.\p"
	.string "Gần đáy biển, nước lưu chuyển do sự\n"
	.string "khác biệt về những yếu tố như nhiệt độ\l"
	.string "và độ mặn.$"

SlateportCity_OceanicMuseum_2F_Text_SurfaceSeawaterDisplay:
	.string "Đây là phần trưng bày về sự lưu chuyển\n"
	.string "của nước biển.\p"
	.string "Gần mặt biển, nước biển tạo thành\n"
	.string "những dòng hải lưu do gió thúc đẩy.$"

SlateportCity_OceanicMuseum_2F_Text_SSTidalReplica:
	.string "PHÀ S.S. TIDAL\p"
	.string "Mô hình thu nhỏ theo đúng tỷ lệ của con\n"
	.string "tàu đang được đóng tại STERN'S\l"
	.string "SHIPYARD.$"

SlateportCity_OceanicMuseum_2F_Text_SubmarineReplica:
	.string "SUBMARINE EXPLORER 1\p"
	.string "Mô hình của tàu ngầm thám hiểm đáy đại\n"
	.string "dương hiệu suất cao.$"

SlateportCity_OceanicMuseum_2F_Text_SumbersibleReplica:
	.string "SUBMERSIBLE POD\p"
	.string "Mô hình của một khoang thám hiểm đáy\n"
	.string "biển nhỏ gọn, không người lái.$"

SlateportCity_OceanicMuseum_2F_Text_SSAnneReplica:
	.string "S.S. ANNE\p"
	.string "Mô hình của chiếc tàu biển sang trọng\n"
	.string "đi vòng quanh thế giới.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global SlateportCity_OceanicMuseum_2F_Text_ThankYouForTheParts
	.global SlateportCity_OceanicMuseum_2F_Text_WellTakeThoseParts
	.global SlateportCity_OceanicMuseum_2F_Text_SternWhoAreYou
	.global SlateportCity_OceanicMuseum_2F_Text_WereTeamAqua
	.global SlateportCity_OceanicMuseum_2F_Text_Grunt1Defeat
	.global SlateportCity_OceanicMuseum_2F_Text_BossGoingToBeFurious
	.global SlateportCity_OceanicMuseum_2F_Text_LetMeTakeCareOfThis
	.global SlateportCity_OceanicMuseum_2F_Text_Grunt2Defeat
	.global SlateportCity_OceanicMuseum_2F_Text_MeddlingKid
	.global SlateportCity_OceanicMuseum_2F_Text_CameToSeeWhatsTakingSoLong
	.global SlateportCity_OceanicMuseum_2F_Text_ArchieWarning
	.global SlateportCity_OceanicMuseum_2F_Text_SternThankYouForSavingUs
	.global SlateportCity_OceanicMuseum_2F_Text_SternIveGotToGo
	.global SlateportCity_OceanicMuseum_2F_Text_RemindsMeOfAbandonedShip
	.global SlateportCity_OceanicMuseum_2F_Text_DontRunInMuseum
	.global SlateportCity_OceanicMuseum_2F_Text_WantToRideSubmarine
	.global SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample1
	.global SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample2
	.global SlateportCity_OceanicMuseum_2F_Text_PressureExperiment
	.global SlateportCity_OceanicMuseum_2F_Text_HoennModel
	.global SlateportCity_OceanicMuseum_2F_Text_DeepSeawaterDisplay
	.global SlateportCity_OceanicMuseum_2F_Text_SurfaceSeawaterDisplay
	.global SlateportCity_OceanicMuseum_2F_Text_SSTidalReplica
	.global SlateportCity_OceanicMuseum_2F_Text_SubmarineReplica
	.global SlateportCity_OceanicMuseum_2F_Text_SumbersibleReplica
	.global SlateportCity_OceanicMuseum_2F_Text_SSAnneReplica
@ END GENERATED LOCALIZATION EXPORTS
