SlateportCity_BattleTentCorridor_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SlateportCity_BattleTentCorridor_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, SlateportCity_BattleTentCorridor_OnWarp
	.byte 0

	@ This is Slateport Tent's version of the Battle Factory Pre-Battle Room

SlateportCity_BattleTentCorridor_OnWarp:
	map_script_2 VAR_TEMP_1, 0, SlateportCity_BattleTentCorridor_EventScript_SetUpObjects
	.2byte 0

SlateportCity_BattleTentCorridor_EventScript_SetUpObjects::
	setvar VAR_TEMP_1, 1
	goto_if_ne VAR_0x8006, 1, SlateportCity_BattleTentCorridor_EventScript_TurnPlayerNorth
	setobjectxy LOCALID_SLATEPORT_TENT_CORRIDOR_ATTENDANT, 2, 2
	turnobject LOCALID_SLATEPORT_TENT_CORRIDOR_ATTENDANT, DIR_SOUTH
SlateportCity_BattleTentCorridor_EventScript_TurnPlayerNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

SlateportCity_BattleTentCorridor_OnFrame:
	map_script_2 VAR_TEMP_0, 0, SlateportCity_BattleTentCorridor_EventScript_EnterCorridor
	.2byte 0

SlateportCity_BattleTentCorridor_EventScript_EnterCorridor::
	goto_if_eq VAR_0x8006, 1, SlateportCity_BattleTentCorridor_EventScript_ReturnToRoomFromBattle
	setvar VAR_TEMP_0, 1
	applymovement LOCALID_SLATEPORT_TENT_CORRIDOR_ATTENDANT, SlateportCity_BattleTentCorridor_Movement_AttendantEnter
	applymovement LOCALID_PLAYER, SlateportCity_BattleTentCorridor_Movement_PlayerEnter
	waitmovement 0
	goto_if_eq VAR_0x8006, 2, SlateportCity_BattleTentCorridor_EventScript_ResumeChallenge
	slateporttent_generaterentalmons
	slateporttent_generateopponentmons
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_HoldMonsChooseFromSelection, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	slateporttent_rentmons
	waitstate
SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_RightThisWay, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_TENT_CORRIDOR_ATTENDANT, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	opendoor 2, 1
	waitdooranim
	applymovement LOCALID_SLATEPORT_TENT_CORRIDOR_ATTENDANT, SlateportCity_BattleTentCorridor_Movement_AttendantExit
	applymovement LOCALID_PLAYER, SlateportCity_BattleTentCorridor_Movement_PlayerExit
	waitmovement 0
	closedoor 2, 1
	waitdooranim
	warp MAP_SLATEPORT_CITY_BATTLE_TENT_BATTLE_ROOM, 4, 4
	waitstate
	end

SlateportCity_BattleTentCorridor_EventScript_ReturnToRoomFromBattle::
	factory_setopponentmons
	factory_resethelditems
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_LetUsRestoreMons, MSGBOX_DEFAULT
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent::
	frontier_get FRONTIER_DATA_BATTLE_NUM
	call_if_eq VAR_RESULT, 1, SlateportCity_BattleTentCorridor_EventScript_ReadyFor2ndOpponent
	call_if_eq VAR_RESULT, 2, SlateportCity_BattleTentCorridor_EventScript_ReadyFor3rdOpponent
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, TRUE
	switch VAR_RESULT
	case 0, SlateportCity_BattleTentCorridor_EventScript_AskSwapMon
	case 1, SlateportCity_BattleTentCorridor_EventScript_AskPauseChallenge
	case 2, SlateportCity_BattleTentCorridor_EventScript_AskRetireChallenge

SlateportCity_BattleTentCorridor_EventScript_AskPauseChallenge::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_SaveAndQuitGame, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent
	case YES, SlateportCity_BattleTentCorridor_EventScript_PauseChallenge
	case MULTI_B_PRESSED, SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent

SlateportCity_BattleTentCorridor_EventScript_AskRetireChallenge::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_RetireFromChallenge
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent
	case 0, SlateportCity_BattleTent_EventScript_WarpToLobbyLost
	case MULTI_B_PRESSED, SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent

SlateportCity_BattleTentCorridor_EventScript_AskSwapMon::
	slateporttent_generateopponentmons
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_LikeToSwapMon, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom
	case YES, SlateportCity_BattleTentCorridor_EventScript_SwapMons
	case MULTI_B_PRESSED, SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom

SlateportCity_BattleTentCorridor_EventScript_SwapMons::
	fadescreen FADE_TO_BLACK
	slateporttent_swapmons
	waitstate
	goto_if_eq VAR_RESULT, 1, SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_YourSwapIsComplete, MSGBOX_DEFAULT
	goto SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom

SlateportCity_BattleTentCorridor_EventScript_ReadyFor2ndOpponent::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor2ndOpponent
	waitmessage
	return

SlateportCity_BattleTentCorridor_EventScript_ReadyFor3rdOpponent::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor3rdOpponent
	waitmessage
	return

SlateportCity_BattleTentCorridor_EventScript_PauseChallenge::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_SavingDataPleaseWait
	waitmessage
	slateporttent_save CHALLENGE_STATUS_PAUSED
	playse SE_SAVE
	waitse
	fadescreen FADE_TO_BLACK
	frontier_reset
	end

SlateportCity_BattleTentCorridor_EventScript_ResumeChallenge::
	special SavePlayerParty
	factory_setparties 0
	goto SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent

SlateportCity_BattleTentCorridor_Movement_PlayerEnter:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

SlateportCity_BattleTentCorridor_Movement_PlayerExit:
	walk_up
	walk_up
	set_invisible
	step_end

SlateportCity_BattleTentCorridor_Movement_AttendantEnter:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_down
	step_end

SlateportCity_BattleTentCorridor_Movement_AttendantExit:
	walk_up
	set_invisible
	step_end

@ Leftover text from when this was a Contest Hall in R/S
@ Unused
SlateportCity_ContestHall_Text_AdviceForContests:
	.string "Muốn nghe một lời khuyên hay ho về\n"
	.string "các cuộc thi không?\p"
	.string "Đôi khi, dùng một chiêu nhất định sau\n"
	.string "một loại chiêu nhất định khác sẽ giúp\l"
	.string "bạn thu hút thêm sự chú ý.\p"
	.string "Nếu biết mình đang làm gì, bạn có thể\n"
	.string "ghi rất nhiều điểm trình diễn.\p"
	.string "Tất nhiên, đối thủ cũng có thể tìm cách\n"
	.string "phá phần trình diễn của POKéMON bên\l"
	.string "bạn.$"

@ Unused
SlateportCity_ContestHall_Text_MyPapaIsContestJudge:
	.string "Ba cháu là GIÁM KHẢO CONTEST đấy.\p"
	.string "Không biết khi lớn lên cháu nên làm\n"
	.string "GIÁM KHẢO hay GYM LEADER nhỉ?$"

@ Unused
SlateportCity_ContestHall_Text_ImLikeMajorlyCheesed:
	.string "Này, ông bạn, tôi đang bực mình kinh\n"
	.string "khủng luôn ấy, biết không. Kiểu như, tôi\l"
	.string "chỉ muốn biết tại sao POKéMON của tôi\l"
	.string "chẳng bao giờ thắng thôi, hiểu không,\l"
	.string "kiểu, hả?\p"
	.string "Thế là tôi góp vài lời với GIÁM KHẢO,\n"
	.string "hoàn toàn miễn phí luôn.\p"
	.string "Vậy mà ông ta chẳng chịu nghe tôi nói,\n"
	.string "kiểu, này! Đúng là chán hết sức luôn,\l"
	.string "ông bạn!\p"
	.string "Này, cậu kia! Im đi, biết chưa? Cứ cầm\n"
	.string "lấy thứ này đi!$"

@ Unused
SlateportCity_ContestHall_Text_ExplainTorment:
	.string "Đó là TM41 đấy, biết không? Này, nó là\n"
	.string "TORMENT, nghe rõ chưa?\p"
	.string "Nó sẽ không cho đối phương dùng cùng\n"
	.string "một chiêu hai lần liên tiếp, hiểu chứ?\p"
	.string "Này, nghe cho rõ đây, tôi đâu có định\n"
	.string "hành hạ cậu!$"

@ Unused
SlateportCity_ContestHall_Text_MCStepUpTakePartInContest:
	.string "MC: Ôi chao! Quả là một POKéMON tuyệt\n"
	.string "vời!\p"
	.string "Xin mời! Hãy bước lên và tham gia những\n"
	.string "các cuộc thi tuyệt vời của chúng tôi!\p"
	.string "Bạn sẽ làm tốt thôi! Tôi chắc chắn đấy!\n"
	.string "Đôi mắt này chưa từng nhìn nhầm!$"

@ Unused
SlateportCity_ContestHall_Text_JudgeWouldntDoToMissContest:
	.string "GIÁM KHẢO: Chà, xin chào! Ta thấy\n"
	.string "cháu là một HLV!\p"
	.string "Vậy thì cháu tuyệt đối không nên bỏ lỡ\n"
	.string "POKéMON CONTEST!\p"
	.string "Hãy lấy CONTEST PASS ở VERDANTURF\n"
	.string "CITY rồi tham gia bất cứ lúc nào!$"

@ Unused
SlateportCity_ContestHall_Text_ItsAppealTime:
	.string "Đến lúc trình diễn rồi! Mình nên mở màn\n"
	.string "bằng chiêu nào đây?$"

@ Unused
SlateportCity_ContestHall_Text_DidntPayAttentionToAppeal:
	.string "Họ chẳng mấy chú ý đến màn trình diễn\n"
	.string "của POKéMON bên mình...\p"
	.string "Hừ, GIÁM KHẢO đó chẳng biết nhìn\n"
	.string "ra cái hay.$"

@ Unused
SlateportCity_ContestHall_Text_RewardWithSageAdvice:
	.string "Ồ, chào bạn! Phải là một người hâm mộ\n"
	.string "cuồng nhiệt lắm bạn mới đến gần sân đấu\l"
	.string "thế này.\p"
	.string "Tôi sẽ đáp lại sự nhiệt tình ấy bằng một\n"
	.string "lời khuyên quý giá.\p"
	.string "Nếu một chiêu được đón nhận nồng\n"
	.string "nhiệt, khán giả sẽ trở nên phấn khích.\p"
	.string "POKéMON trình diễn đúng lúc mọi người\n"
	.string "đang phấn khích...\p"
	.string "Chà, chắc chắn sẽ có chuyện tốt xảy ra!$"

@ Unused
SlateportCity_ContestHall_Text_MoreFreakedOutThanMon:
	.string "Tôi không làm nổi đâu! Tôi còn hoảng\n"
	.string "hơn cả POKéMON của mình.\p"
	.string "Tôi đang run lẩy bẩy, tim thì đập thình\n"
	.string "thịch!$"

@ Unused
SlateportCity_ContestHall_Text_BattleAndContestAlike:
	.string "Trận đấu và cuộc thi không giống nhau,\n"
	.string "nhưng cũng có những điểm tương đồng.\p"
	.string "Bạn phải nỗ lực hết mình và tin tưởng\n"
	.string "vào POKéMON mình đã nuôi dưỡng.$"

@ Unused
SlateportCity_ContestHall_Text_MonLooksOnTopOfGame:
	.string "POKéMON đó trông đang có phong độ tốt\n"
	.string "nhất, phải không?\p"
	.string "Một POKéMON đạt kết quả tốt ở phần\n"
	.string "chấm điểm phụ dường như sẽ thoải mái\l"
	.string "hơn khi trình diễn.$"

@ Unused
SlateportCity_ContestHall_Text_MyMonBetterThanThatLot:
	.string "Nhìn cảnh tượng thảm hại đó kìa!\p"
	.string "Hừm, POKéMON của tôi chắc chắn giỏi hơn\n"
	.string "cả đám ấy!$"

@ Unused
SlateportCity_ContestHall_Text_GetUrgeToMoveWithMon:
	.string "Khi POKéMON trình diễn đầy năng lượng,\n"
	.string "bạn không thấy muốn nhún nhảy theo\l"
	.string "sao?$"

@ Unused
SlateportCity_ContestHall_Text_HyperRankStage:
	.string "POKéMON CONTESTS HYPER RANK STAGE!$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global SlateportCity_ContestHall_Text_AdviceForContests
	.global SlateportCity_ContestHall_Text_MyPapaIsContestJudge
	.global SlateportCity_ContestHall_Text_ImLikeMajorlyCheesed
	.global SlateportCity_ContestHall_Text_ExplainTorment
	.global SlateportCity_ContestHall_Text_MCStepUpTakePartInContest
	.global SlateportCity_ContestHall_Text_JudgeWouldntDoToMissContest
	.global SlateportCity_ContestHall_Text_ItsAppealTime
	.global SlateportCity_ContestHall_Text_DidntPayAttentionToAppeal
	.global SlateportCity_ContestHall_Text_RewardWithSageAdvice
	.global SlateportCity_ContestHall_Text_MoreFreakedOutThanMon
	.global SlateportCity_ContestHall_Text_BattleAndContestAlike
	.global SlateportCity_ContestHall_Text_MonLooksOnTopOfGame
	.global SlateportCity_ContestHall_Text_MyMonBetterThanThatLot
	.global SlateportCity_ContestHall_Text_GetUrgeToMoveWithMon
	.global SlateportCity_ContestHall_Text_HyperRankStage
@ END GENERATED LOCALIZATION EXPORTS
