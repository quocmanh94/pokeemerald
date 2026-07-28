SeafloorCavern_Room9_MapScripts::
	.byte 0

SeafloorCavern_Room9_EventScript_ArchieAwakenKyogre::
	lockall
	setvar VAR_0x8004, LOCALID_SEAFLOOR_CAVERN_ARCHIE
	setvar VAR_0x8005, LOCALID_SEAFLOOR_CAVERN_MAXIE
	setvar VAR_0x8006, LOCALID_SEAFLOOR_CAVERN_GRUNT_1
	setvar VAR_0x8007, LOCALID_SEAFLOOR_CAVERN_GRUNT_2
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	applymovement LOCALID_PLAYER, SeafloorCavern_Room9_Movement_Delay32
	waitmovement 0
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	msgbox SeafloorCavern_Room9_Text_ArchieHoldItRightThere, MSGBOX_DEFAULT
	closemessage
	addobject VAR_0x8004
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	applymovement VAR_0x8004, SeafloorCavern_Room9_Movement_ArchieApproachPlayer
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_ArchieSoItWasYou, MSGBOX_DEFAULT
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_ArchieBeholdKyogre, MSGBOX_DEFAULT
	applymovement VAR_0x8004, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_ArchieYouMustDisappear, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_ARCHIE, SeafloorCavern_Room9_Text_ArchieDefeat
	msgbox SeafloorCavern_Room9_Text_ArchieWithThisRedOrb, MSGBOX_DEFAULT
	setweather WEATHER_NONE
	doweather
	special Script_FadeOutMapMusic
	msgbox SeafloorCavern_Room9_Text_RedOrbShinesByItself, MSGBOX_DEFAULT
	special WaitWeather
	setvar VAR_RESULT, 1
	playse SE_M_DETECT
	dofieldeffectsparkle 16, 42, 0
	waitfieldeffect FLDEFF_SPARKLE
	closemessage
	setvar VAR_RESULT, 0
	playfanfare MUS_AWAKEN_LEGEND
	playse SE_ORB
	special DoOrbEffect
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 150
	removeobject LOCALID_SEAFLOOR_CAVERN_KYOGRE_SLEEPING
	addobject LOCALID_SEAFLOOR_CAVERN_KYOGRE
	waitstate
	delay 60
	applymovement LOCALID_SEAFLOOR_CAVERN_KYOGRE, SeafloorCavern_Room9_Movement_KyogreApproach
	waitmovement 0
	special FadeOutOrbEffect
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	applymovement LOCALID_SEAFLOOR_CAVERN_KYOGRE, SeafloorCavern_Room9_Movement_KyogreExit
	waitmovement 0
	removeobject LOCALID_SEAFLOOR_CAVERN_KYOGRE
	delay 4
	setvar VAR_0x8004, 2  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	delay 30
	setvar VAR_0x8004, LOCALID_SEAFLOOR_CAVERN_ARCHIE
	setvar VAR_0x8005, LOCALID_SEAFLOOR_CAVERN_MAXIE
	setvar VAR_0x8006, LOCALID_SEAFLOOR_CAVERN_GRUNT_1
	setvar VAR_0x8007, LOCALID_SEAFLOOR_CAVERN_GRUNT_2
	msgbox SeafloorCavern_Room9_Text_ArchieWhereDidKyogreGo, MSGBOX_DEFAULT
	playse SE_PC_LOGIN
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_ArchieAMessageFromOutside, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_0x8004, SeafloorCavern_Room9_Movement_ArchieListenMessage
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_ArchieWhatRainingTooHard, MSGBOX_DEFAULT
	closemessage
	playse SE_PC_OFF
	delay 20
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_ArchieWhyDidKyogreDisappear, MSGBOX_DEFAULT
	closemessage
	addobject VAR_0x8005
	addobject VAR_0x8006
	addobject VAR_0x8007
	applymovement VAR_0x8007, SeafloorCavern_Room9_Movement_MagmaGruntArrive
	applymovement VAR_0x8006, SeafloorCavern_Room9_Movement_MagmaGruntArrive
	applymovement VAR_0x8005, SeafloorCavern_Room9_Movement_MaxieArrive
	waitmovement 0
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_MaxieWhatHaveYouWrought, MSGBOX_DEFAULT
	playse SE_PIN
	applymovement VAR_0x8004, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_0x8004, Common_Movement_Delay48
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_ArchieDontGetAllHighAndMighty, MSGBOX_DEFAULT
	msgbox SeafloorCavern_Room9_Text_MaxieWeDontHaveTimeToArgue, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_0x8005, SeafloorCavern_Room9_Movement_MaxieExit
	applymovement VAR_0x8004, SeafloorCavern_Room9_Movement_ArchieExit
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_MaxieComeOnPlayer, MSGBOX_DEFAULT
	setvar VAR_ROUTE128_STATE, 1
	setvar VAR_SOOTOPOLIS_CITY_STATE, 1
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_STEVEN
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_ARCHIE
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_MAXIE
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_RESIDENTS
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_GROUDON
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_KYOGRE
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_MAN_1
	setflag FLAG_LEGENDARIES_IN_SOOTOPOLIS
	clearflag FLAG_HIDE_ROUTE_128_ARCHIE
	clearflag FLAG_HIDE_ROUTE_128_MAXIE
	setflag FLAG_SYS_WEATHER_CTRL
	setflag FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN
	setflag FLAG_HIDE_MOSSDEEP_CITY_STEVENS_HOUSE_STEVEN
	setvar VAR_STEVENS_HOUSE_STATE, 2
	setvar VAR_SEAFLOOR_CAVERN_STATE, 1
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_ARCHIE
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_MAXIE
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_MAGMA_GRUNTS
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_KYOGRE
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_AQUA_GRUNTS
	setflag FLAG_HIDE_MAP_NAME_POPUP
	warp MAP_ROUTE128, 38, 22
	waitstate
	releaseall
	end

SeafloorCavern_Room9_Movement_ArchieApproachPlayer:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SeafloorCavern_Room9_Movement_Unused1:
	walk_left
	walk_left
	step_end

SeafloorCavern_Room9_Movement_ArchieListenMessage:
	walk_left
	delay_16
	step_end

SeafloorCavern_Room9_Movement_Unused2:
	walk_right
	step_end

SeafloorCavern_Room9_Movement_ArchieExit:
	face_up
	lock_facing_direction
	walk_down
	unlock_facing_direction
	walk_in_place_faster_right
	step_end

SeafloorCavern_Room9_Movement_KyogreApproach:
	delay_16
	delay_16
	walk_slow_down
	delay_16
	delay_16
	delay_16
	walk_slow_down
	delay_16
	delay_16
	delay_16
	step_end

SeafloorCavern_Room9_Movement_KyogreExit:
	slide_up
	slide_up
	step_end

SeafloorCavern_Room9_Movement_MaxieArrive:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

SeafloorCavern_Room9_Movement_MaxieExit:
	walk_right
	walk_right
	step_end

SeafloorCavern_Room9_Movement_MagmaGruntArrive:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

SeafloorCavern_Room9_Movement_Delay32:
	delay_16
	delay_16
	step_end

SeafloorCavern_Room9_Text_ArchieHoldItRightThere:
	.string "ARCHIE: Đứng lại đó.$"

SeafloorCavern_Room9_Text_ArchieSoItWasYou:
	.string "ARCHIE: Fufufu... Quả nhiên lại là ngươi.$"

SeafloorCavern_Room9_Text_ArchieBeholdKyogre:
	.string "ARCHIE: Hãy chiêm ngưỡng!\p"
	.string "Hãy nhìn dáng vẻ say ngủ tuyệt đẹp của\n"
	.string "POKéMON cổ đại KYOGRE!\p"
	.string "Ta đã chờ ngày này quá lâu rồi...$"

SeafloorCavern_Room9_Text_ArchieYouMustDisappear:
	.string "ARCHIE: Ta rất ngạc nhiên khi ngươi có\n"
	.string "thể đuổi theo ta đến tận đây.\p"
	.string "Nhưng giờ mọi chuyện đã kết thúc.\p"
	.string "Để giấc mơ của ta trở thành hiện thực,\n"
	.string "ngươi phải biến mất!$"

SeafloorCavern_Room9_Text_ArchieDefeat:
	.string "Cái gì?! Ta lại thua một đứa trẻ như\n"
	.string "ngươi sao?!$"

SeafloorCavern_Room9_Text_ArchieWithThisRedOrb:
	.string "ARCHIE: Fufufu...\p"
	.string "Ta khen ngợi ngươi. Ta phải công nhận\n"
	.string "ngươi thật sự rất tài giỏi.\p"
	.string "Nhưng! Ta đang sở hữu thứ này!\p"
	.string "Với RED ORB, ta có thể khiến KYOGRE...$"

SeafloorCavern_Room9_Text_RedOrbShinesByItself:
	.string "RED ORB đột nhiên tự phát sáng!$"

SeafloorCavern_Room9_Text_ArchieWhereDidKyogreGo:
	.string "ARCHIE: Cái gì?!\p"
	.string "Ta có làm gì đâu. Tại sao RED ORB lại...\p"
	.string "KYOGRE đã đi đâu rồi?$"

SeafloorCavern_Room9_Text_ArchieAMessageFromOutside:
	.string "ARCHIE: Hửm? Có tin nhắn từ các thành\n"
	.string "viên bên ngoài...$"

SeafloorCavern_Room9_Text_ArchieWhatRainingTooHard:
	.string "ARCHIE: Ừ, có chuyện gì?\p"
	.string "Hửm... Trời đang mưa lớn sao?\p"
	.string "Tốt... Đúng là phải như vậy. Đó chính là\n"
	.string "lý do bọn ta đánh thức KYOGRE, để thực\l"
	.string "hiện lý tưởng mở rộng biển cả của TEAM\l"
	.string "AQUA.\p"
	.string "Cái gì?!\p"
	.string "Mưa lớn hơn dự tính rất nhiều sao? Các\n"
	.string "ngươi đang gặp nguy hiểm?\p"
	.string "Không thể nào... Chuyện đó không thể\n"
	.string "xảy ra...\p"
	.string "Giữ nguyên vị trí và tiếp tục theo dõi\n"
	.string "tình hình!$"

SeafloorCavern_Room9_Text_ArchieWhyDidKyogreDisappear:
	.string "ARCHIE: Có gì đó không ổn...\p"
	.string "RED ORB đáng lẽ phải đánh thức và điều\n"
	.string "khiển KYOGRE...\p"
	.string "Nhưng... Tại sao? Tại sao KYOGRE lại biến\n"
	.string "mất?\p"
	.string "Tại sao?!$"

SeafloorCavern_Room9_Text_MaxieWhatHaveYouWrought:
	.string "MAXIE: Ngươi đã gây ra chuyện gì thế?\p"
	.string "ARCHIE... Cuối cùng ngươi cũng đánh\n"
	.string "thức KYOGRE rồi, phải không?\p"
	.string "Thế giới sẽ ra sao nếu trận mưa này kéo\n"
	.string "dài vĩnh viễn?\p"
	.string "Toàn bộ đất liền sẽ chìm trong biển\n"
	.string "nước ngày càng dâng cao...$"

SeafloorCavern_Room9_Text_ArchieDontGetAllHighAndMighty:
	.string "ARCHIE: C-cái gì?! Đừng có lên mặt với\n"
	.string "ta!\p"
	.string "Chẳng phải chính TEAM MAGMA các ngươi\n"
	.string "đã chọc giận GROUDON sao?\p"
	.string "Chỉ cần có RED ORB, ta phải điều khiển\n"
	.string "được KYOGRE...\p"
	.string "Ta phải điều khiển được nó...$"

SeafloorCavern_Room9_Text_MaxieWeDontHaveTimeToArgue:
	.string "MAXIE: Chúng ta không có thời gian\n"
	.string "tranh cãi ở đây!\p"
	.string "Ra ngoài và tự mình nhìn đi!\p"
	.string "Hãy xem thế giới do ngươi gây nên có\n"
	.string "phải là thế giới chúng ta mong muốn\l"
	.string "không!$"

SeafloorCavern_Room9_Text_MaxieComeOnPlayer:
	.string "MAXIE: {PLAYER}, mau lên, ngươi cũng\n"
	.string "phải rời khỏi đây!$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global SeafloorCavern_Room9_Text_ArchieHoldItRightThere
	.global SeafloorCavern_Room9_Text_ArchieSoItWasYou
	.global SeafloorCavern_Room9_Text_ArchieBeholdKyogre
	.global SeafloorCavern_Room9_Text_ArchieYouMustDisappear
	.global SeafloorCavern_Room9_Text_ArchieDefeat
	.global SeafloorCavern_Room9_Text_ArchieWithThisRedOrb
	.global SeafloorCavern_Room9_Text_RedOrbShinesByItself
	.global SeafloorCavern_Room9_Text_ArchieWhereDidKyogreGo
	.global SeafloorCavern_Room9_Text_ArchieAMessageFromOutside
	.global SeafloorCavern_Room9_Text_ArchieWhatRainingTooHard
	.global SeafloorCavern_Room9_Text_ArchieWhyDidKyogreDisappear
	.global SeafloorCavern_Room9_Text_MaxieWhatHaveYouWrought
	.global SeafloorCavern_Room9_Text_ArchieDontGetAllHighAndMighty
	.global SeafloorCavern_Room9_Text_MaxieWeDontHaveTimeToArgue
	.global SeafloorCavern_Room9_Text_MaxieComeOnPlayer
@ END GENERATED LOCALIZATION EXPORTS
