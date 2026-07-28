BattleFrontier_BattlePikeRoomNormal_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattlePikeRoom_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattlePikeRoom_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePikeRoomNormal_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattlePikeRoom_OnWarp
	.byte 0

BattleFrontier_BattlePikeRoomNormal_OnFrame:
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattlePikeRoomNormal_EventScript_EnterRoom
	.2byte 0

BattleFrontier_BattlePikeRoomNormal_EventScript_EnterRoom::
	setvar VAR_TEMP_0, 1
	pike_getroomtype
	switch VAR_RESULT
	case PIKE_ROOM_SINGLE_BATTLE, BattleFrontier_BattlePikeRoomNormal_EventScript_EnterSingleBattleRoom
	case PIKE_ROOM_HEAL_FULL, BattleFrontier_BattlePikeRoomNormal_EventScript_EnterFullHealRoom
	case PIKE_ROOM_STATUS, BattleFrontier_BattlePikeRoomNormal_EventScript_EnterStatusRoom
	case PIKE_ROOM_HARD_BATTLE, BattleFrontier_BattlePikeRoomNormal_EventScript_EnterHardBattleRoom
	case PIKE_ROOM_DOUBLE_BATTLE, BattleFrontier_BattlePikeRoomNormal_EventScript_EnterDoubleBattleRoom
	case PIKE_ROOM_BRAIN, BattleFrontier_BattlePikeRoomNormal_EventScript_EnterBrainRoom
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_EnterSingleBattleRoom::
	lockall
	delay 16
	applymovement LOCALID_PIKE_ROOM_NPC_1, BattleFrontier_BattlePikeRoomNormal_Movement_ApproachPlayer
	waitmovement 0
	pike_gettrainerintro 0
	msgbox gStringVar4, MSGBOX_DEFAULT
	waitmessage
	closemessage
	releaseall
	setvar VAR_0x8004, SPECIAL_BATTLE_PIKE_SINGLE
	setvar VAR_0x8005, 0
	special DoSpecialTrainerBattle
	switch VAR_RESULT
	case 1, BattleFrontier_BattlePikeRoomNormal_EventScript_WonSingleBattle
BattleFrontier_BattlePikeRoomNormal_EventScript_WarpToLobbyLost::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST
	warp MAP_BATTLE_FRONTIER_BATTLE_PIKE_LOBBY, 5, 6
	waitstate
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_WonSingleBattle::
	applymovement LOCALID_PIKE_ROOM_NPC_1, BattleFrontier_BattlePikeRoomNormal_Movement_NPCExit
	waitmovement 0
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_EnterHardBattleRoom::
	lockall
	delay 16
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_BattleSomewhatToughTrainer, MSGBOX_DEFAULT
	waitmessage
	closemessage
	applymovement LOCALID_PIKE_ROOM_NPC_1, BattleFrontier_BattlePikeRoomNormal_Movement_ApproachPlayer
	waitmovement 0
	pike_gettrainerintro 0
	msgbox gStringVar4, MSGBOX_DEFAULT
	waitmessage
	closemessage
	releaseall
	setvar VAR_0x8004, SPECIAL_BATTLE_PIKE_SINGLE
	setvar VAR_0x8005, 0
	special DoSpecialTrainerBattle
	switch VAR_RESULT
	case 1, BattleFrontier_BattlePikeRoomNormal_EventScript_WonHardBattle
	goto BattleFrontier_BattlePikeRoomNormal_EventScript_WarpToLobbyLost
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_WonHardBattle::
	applymovement LOCALID_PIKE_ROOM_NPC_1, BattleFrontier_BattlePikeRoomNormal_Movement_NPCExit
	waitmovement 0
	applymovement LOCALID_PIKE_ROOM_NPC_2, BattleFrontier_BattlePikeRoomNormal_Movement_HealNPCApproachPlayer
	waitmovement 0
	lock
	faceplayer
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_RestoreToFullHealth, MSGBOX_DEFAULT
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_EnjoyRestOfChallenge2, MSGBOX_DEFAULT
	closemessage
	release
	applymovement LOCALID_PIKE_ROOM_NPC_2, BattleFrontier_BattlePikeRoomNormal_Movement_NPCExit
	waitmovement 0
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_EnterBrainRoom::
	delay 22
	lockall
	applymovement LOCALID_PIKE_ROOM_NPC_2, BattleFrontier_BattlePikeRoomNormal_Movement_PreQueenHealNPCApproachPlayer
	waitmovement 0
	pike_prequeenheal
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePikeRoomNormal_EventScript_PreQueenNoHeal
	case 1, BattleFrontier_BattlePikeRoomNormal_EventScript_PreQueenHealOneMon
	case 2, BattleFrontier_BattlePikeRoomNormal_EventScript_PreQueenHealTwoMons

BattleFrontier_BattlePikeRoomNormal_EventScript_LucyEnter::
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_ShallFetchOurMaster, MSGBOX_DEFAULT
	closemessage
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, BattleFrontier_BattlePikeRoomNormal_Movement_CameraPanUp
	applymovement LOCALID_PIKE_ROOM_NPC_2, BattleFrontier_BattlePikeRoomNormal_Movement_HealNPCExitForLucy
	waitmovement 0
	playse SE_PIKE_CURTAIN_CLOSE
	call BattleFrontier_BattlePikeRoomNormal_EventScript_SetCurtainTilesLittleClosed
	delay 4
	call BattleFrontier_BattlePikeRoomNormal_EventScript_SetCurtainTilesMostlyClosed
	delay 4
	call BattleFrontier_BattlePikeRoomNormal_EventScript_SetCurtainTilesClosed
	delay 4
	waitse
	delay 60
	playse SE_PIKE_CURTAIN_OPEN
	delay 65
	call BattleFrontier_BattlePikeRoomNormal_EventScript_SetCurtainTilesMostlyClosed
	showobjectat LOCALID_PIKE_ROOM_NPC_1, MAP_BATTLE_FRONTIER_BATTLE_PIKE_ROOM_NORMAL
	delay 4
	call BattleFrontier_BattlePikeRoomNormal_EventScript_SetCurtainTilesLittleClosed
	delay 4
	call BattleFrontier_BattlePikeRoomNormal_EventScript_SetCurtainTilesOpen
	waitse
	applymovement LOCALID_PIKE_ROOM_NPC_1, BattleFrontier_BattlePikeRoomNormal_Movement_LucyEnter
	waitmovement 0
	pike_getbrainstatus
	switch VAR_RESULT
	case FRONTIER_BRAIN_GOLD, BattleFrontier_BattlePikeRoomNormal_EventScript_IntroLucyGold
	case FRONTIER_BRAIN_STREAK, BattleFrontier_BattlePikeRoomNormal_EventScript_BattleLucySilver
	case FRONTIER_BRAIN_STREAK_LONG, BattleFrontier_BattlePikeRoomNormal_EventScript_BattleLucyGold
	frontier_get FRONTIER_DATA_HEARD_BRAIN_SPEECH
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattlePikeRoomNormal_EventScript_BattleLucySilver
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_ImThePikeQueen, MSGBOX_DEFAULT
	frontier_set FRONTIER_DATA_HEARD_BRAIN_SPEECH
BattleFrontier_BattlePikeRoomNormal_EventScript_BattleLucySilver::
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_HopeYouDidntUseUpLuck, MSGBOX_DEFAULT
	call BattleFrontier_BattlePikeRoomNormal_EventScript_DoPikeQueenBattle
	goto_if_eq VAR_RESULT, 1, BattleFrontier_BattlePikeRoomNormal_EventScript_DefeatedLucySilver
	goto BattleFrontier_BattlePikeRoomNormal_EventScript_WarpToLobbyLost

BattleFrontier_BattlePikeRoomNormal_EventScript_DefeatedLucySilver::
	frontier_getsymbols
	goto_if_ne VAR_RESULT, 0, BattleFrontier_BattlePikeRoomNormal_EventScript_DefeatedLucy
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_LucyShowMeFrontierPass, MSGBOX_DEFAULT
	waitmessage
	playfanfare MUS_OBTAIN_SYMBOL
	message BattleFrontier_BattlePikeRoomNormal_Text_ReceivedLuckSymbol
	waitmessage
	waitfanfare
	frontier_givesymbol
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_AllThereIsDisappear, MSGBOX_DEFAULT
	closemessage
	goto BattleFrontier_BattlePikeRoomNormal_EventScript_DefeatedLucy

BattleFrontier_BattlePikeRoomNormal_EventScript_IntroLucyGold::
	frontier_get FRONTIER_DATA_HEARD_BRAIN_SPEECH
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattlePikeRoomNormal_EventScript_BattleLucyGold
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_LucyYouAgain, MSGBOX_DEFAULT
	frontier_set FRONTIER_DATA_HEARD_BRAIN_SPEECH
BattleFrontier_BattlePikeRoomNormal_EventScript_BattleLucyGold::
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_NowComeOn, MSGBOX_DEFAULT
	call BattleFrontier_BattlePikeRoomNormal_EventScript_DoPikeQueenBattle
	goto_if_eq VAR_RESULT, 1, BattleFrontier_BattlePikeRoomNormal_EventScript_DefeatedLucyGold
	goto BattleFrontier_BattlePikeRoomNormal_EventScript_WarpToLobbyLost

BattleFrontier_BattlePikeRoomNormal_EventScript_DefeatedLucyGold::
	frontier_getsymbols
	goto_if_eq VAR_RESULT, 2, BattleFrontier_BattlePikeRoomNormal_EventScript_DefeatedLucy
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_LucyFrontierPass, MSGBOX_DEFAULT
	waitmessage
	playfanfare MUS_OBTAIN_SYMBOL
	message BattleFrontier_BattlePikeRoomNormal_Text_LuckSymbolTookGoldenShine
	waitmessage
	waitfanfare
	frontier_givesymbol
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_IWontForget, MSGBOX_DEFAULT
	closemessage
	goto BattleFrontier_BattlePikeRoomNormal_EventScript_DefeatedLucy
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_DefeatedLucy::
	applymovement LOCALID_PIKE_ROOM_NPC_1, BattleFrontier_BattlePikeRoomNormal_Movement_LucyMoveAside
	waitmovement 0
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePikeRoomNormal_Movement_PlayerWalkUp2
	waitmovement 0
	pike_get PIKE_DATA_WIN_STREAK
	addvar VAR_RESULT, 1
	pike_set PIKE_DATA_WIN_STREAK, VAR_RESULT
	call BattleFrontier_BattlePikeRoom_EventScript_WarpToFinalRoom
	waitstate
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_PreQueenNoHeal::
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_ChoseRoomNoHeal, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeRoomNormal_EventScript_LucyEnter
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_PreQueenHealOneMon::
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_ChoseRoomHealOne, MSGBOX_DEFAULT
	playfanfare MUS_HEAL
	waitfanfare
	goto BattleFrontier_BattlePikeRoomNormal_EventScript_LucyEnter
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_PreQueenHealTwoMons::
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_ChoseRoomHealTwo, MSGBOX_DEFAULT
	playfanfare MUS_HEAL
	waitfanfare
	goto BattleFrontier_BattlePikeRoomNormal_EventScript_LucyEnter
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_EnterFullHealRoom::
	lockall
	delay 16
	applymovement LOCALID_PIKE_ROOM_NPC_1, BattleFrontier_BattlePikeRoomNormal_Movement_ApproachPlayer
	waitmovement 0
	message BattleFrontier_BattlePikeRoomNormal_Text_WillRestoreToFullHealth
	waitmessage
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_EnjoyRestOfChallenge, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PIKE_ROOM_NPC_1, BattleFrontier_BattlePikeRoomNormal_Movement_NPCExit
	waitmovement 0
	releaseall
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_EnterDoubleBattleRoom::
	lockall
	delay 16
	applymovement LOCALID_PIKE_ROOM_NPC_1, BattleFrontier_BattlePikeRoomNormal_Movement_Trainer1WalkRight
	applymovement LOCALID_PIKE_ROOM_NPC_2, BattleFrontier_BattlePikeRoomNormal_Movement_Trainer2WalkLeft
	waitmovement 0
	applymovement LOCALID_PIKE_ROOM_NPC_1, BattleFrontier_BattlePikeRoomNormal_Movement_DoubleTrainersWalkDown
	applymovement LOCALID_PIKE_ROOM_NPC_2, BattleFrontier_BattlePikeRoomNormal_Movement_DoubleTrainersWalkDown
	waitmovement 0
	applymovement LOCALID_PIKE_ROOM_NPC_1, BattleFrontier_BattlePikeRoomNormal_Movement_Trainer1FacePlayer
	applymovement LOCALID_PIKE_ROOM_NPC_2, BattleFrontier_BattlePikeRoomNormal_Movement_Trainer2FacePlayer
	waitmovement 0
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePikeRoomNormal_Movement_PlayerFaceTrainer1
	waitmovement 0
	pike_gettrainerintro 0
	msgbox gStringVar4, MSGBOX_DEFAULT
	closemessage
	delay 16
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePikeRoomNormal_Movement_PlayerFaceTrainer2
	waitmovement 0
	pike_gettrainerintro 1
	msgbox gStringVar4, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, SPECIAL_BATTLE_PIKE_DOUBLE
	setvar VAR_0x8005, 0
	special DoSpecialTrainerBattle
	switch VAR_RESULT
	case 1, BattleFrontier_BattlePikeRoomNormal_EventScript_WonDoubleBattle
	goto BattleFrontier_BattlePikeRoomNormal_EventScript_WarpToLobbyLost
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_WonDoubleBattle::
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePikeRoomNormal_Movement_PlayerFaceTrainer2
	waitmovement 0
	applymovement LOCALID_PIKE_ROOM_NPC_1, BattleFrontier_BattlePikeRoomNormal_Movement_Trainer1Exit
	waitmovement 0
	applymovement LOCALID_PIKE_ROOM_NPC_2, BattleFrontier_BattlePikeRoomNormal_Movement_Trainer2Exit
	waitmovement 0
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePikeRoomNormal_Movement_PlayerFaceUp
	waitmovement 0
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_EnterStatusRoom::
	lockall
	message BattleFrontier_BattlePikeRoomNormal_Text_WatchOut
	applymovement LOCALID_PIKE_ROOM_NPC_2, BattleFrontier_BattlePikeRoomNormal_Movement_MonApproachPlayer
	waitmovement 0
	pike_getstatusmon
	copyvar VAR_0x8004, VAR_RESULT
	call_if_eq VAR_0x8004, PIKE_STATUSMON_KIRLIA, BattleFrontier_BattlePikeRoomNormal_EventScript_KirliaAttack
	call_if_eq VAR_0x8004, PIKE_STATUSMON_DUSCLOPS, BattleFrontier_BattlePikeRoomNormal_EventScript_DusclopsAttack
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_AttacksWhenStartled, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_KirliaAttack::
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_KirliaStop, MSGBOX_DEFAULT
	closemessage
	waitse
	playmoncry SPECIES_KIRLIA, CRY_MODE_NORMAL
	waitmoncry
	pike_getstatus
	call_if_eq VAR_RESULT, PIKE_STATUS_TOXIC, BattleFrontier_BattlePikeRoomNormal_EventScript_KirliaUsedToxic
	call_if_eq VAR_RESULT, PIKE_STATUS_BURN, BattleFrontier_BattlePikeRoomNormal_EventScript_KirliaUsedWillOWisp
	call_if_eq VAR_RESULT, PIKE_STATUS_PARALYSIS, BattleFrontier_BattlePikeRoomNormal_EventScript_KirliaUsedThunderWave
	call_if_eq VAR_RESULT, PIKE_STATUS_SLEEP, BattleFrontier_BattlePikeRoomNormal_EventScript_KirliaUsedHypnosis
	pike_flashscreen
	waitstate
	applymovement LOCALID_PIKE_ROOM_NPC_1, BattleFrontier_BattlePikeRoomNormal_Movement_NPCApproachMon
	waitmovement 0
	applymovement LOCALID_PIKE_ROOM_NPC_2, BattleFrontier_BattlePikeRoomNormal_Movement_MonFaceNPC
	waitmovement 0
	waitse
	playmoncry SPECIES_KIRLIA, CRY_MODE_NORMAL
	waitmoncry
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_ThatsEnough, MSGBOX_DEFAULT
	waitse
	playmoncry SPECIES_KIRLIA, CRY_MODE_NORMAL
	waitmoncry
	closemessage
	applymovement LOCALID_PIKE_ROOM_NPC_2, BattleFrontier_BattlePikeRoomNormal_Movement_MonMoveAside
	applymovement LOCALID_PIKE_ROOM_NPC_1, BattleFrontier_BattlePikeRoomNormal_Movement_StatusNPCApproachPlayer
	waitmovement 0
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_ApologizeForKirlia, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePikeRoomNormal_EventScript_DusclopsAttack::
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_DusclopsStop, MSGBOX_DEFAULT
	closemessage
	waitse
	playmoncry SPECIES_DUSCLOPS, CRY_MODE_NORMAL
	waitmoncry
	pike_getstatus
	call_if_eq VAR_RESULT, PIKE_STATUS_FREEZE, BattleFrontier_BattlePikeRoomNormal_EventScript_DusclopsUsedIceBeam
	call_if_eq VAR_RESULT, PIKE_STATUS_BURN, BattleFrontier_BattlePikeRoomNormal_EventScript_DusclopsUsedWillOWisp
	pike_flashscreen
	waitstate
	applymovement LOCALID_PIKE_ROOM_NPC_1, BattleFrontier_BattlePikeRoomNormal_Movement_NPCApproachMon
	waitmovement 0
	applymovement LOCALID_PIKE_ROOM_NPC_2, BattleFrontier_BattlePikeRoomNormal_Movement_MonFaceNPC
	waitmovement 0
	waitse
	playmoncry SPECIES_DUSCLOPS, CRY_MODE_NORMAL
	waitmoncry
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_ThatsEnough, MSGBOX_DEFAULT
	waitse
	playmoncry SPECIES_DUSCLOPS, CRY_MODE_NORMAL
	waitmoncry
	closemessage
	applymovement LOCALID_PIKE_ROOM_NPC_2, BattleFrontier_BattlePikeRoomNormal_Movement_MonMoveAside
	applymovement LOCALID_PIKE_ROOM_NPC_1, BattleFrontier_BattlePikeRoomNormal_Movement_StatusNPCApproachPlayer
	waitmovement 0
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_ApologizeForDusclops, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePikeRoomNormal_EventScript_KirliaUsedToxic::
	message BattleFrontier_BattlePikeRoomNormal_Text_KirliaUsedToxic
	waitmessage
	return

BattleFrontier_BattlePikeRoomNormal_EventScript_KirliaUsedWillOWisp::
	message BattleFrontier_BattlePikeRoomNormal_Text_KirliaUsedWillOWisp
	waitmessage
	return

BattleFrontier_BattlePikeRoomNormal_EventScript_KirliaUsedThunderWave::
	message BattleFrontier_BattlePikeRoomNormal_Text_KirliaUsedThunderWave
	waitmessage
	return

BattleFrontier_BattlePikeRoomNormal_EventScript_KirliaUsedHypnosis::
	message BattleFrontier_BattlePikeRoomNormal_Text_KirliaUsedHypnosis
	waitmessage
	return

BattleFrontier_BattlePikeRoomNormal_EventScript_DusclopsUsedIceBeam::
	message BattleFrontier_BattlePikeRoomNormal_Text_DusclopsUsedIceBeam
	waitmessage
	return

BattleFrontier_BattlePikeRoomNormal_EventScript_DusclopsUsedWillOWisp::
	message BattleFrontier_BattlePikeRoomNormal_Text_DusclopsUsedWillOWisp
	waitmessage
	return

BattleFrontier_BattlePikeRoomNormal_EventScript_DoPikeQueenBattle::
	closemessage
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePikeRoomNormal_Movement_PlayerWalkUp2
	waitmovement 0
	setvar VAR_0x8004, SPECIAL_BATTLE_PIKE_SINGLE
	setvar VAR_0x8005, 0
	special DoSpecialTrainerBattle
	return

BattleFrontier_BattlePikeRoomNormal_Movement_ApproachPlayer:
	walk_down
	walk_down
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_NPCExit:
	walk_up
	walk_up
	walk_up
	set_invisible
	walk_up
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_HealNPCExit:
	walk_up
	set_invisible
	walk_up
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_NPCApproachMon:
	walk_down
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_StatusNPCApproachPlayer:
	walk_down
	face_left
	delay_16
	delay_16
	face_down
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_MonApproachPlayer:
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_left
	face_down
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_MonFaceNPC:
	face_up
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_MonMoveAside:
	walk_left
BattleFrontier_BattlePikeRoomNormal_Movement_MonFaceRight:
	face_right
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_HealNPCApproachPlayer:
	walk_down
	walk_down
	walk_right
	face_down
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_PlayerFaceTrainer1:
	face_left
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_PlayerFaceTrainer2:
	face_right
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_PlayerFaceUp:
	face_up
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_Trainer1WalkRight:
	walk_right
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_Trainer2WalkLeft:
	walk_left
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_DoubleTrainersWalkDown:
	walk_down
	walk_down
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_Trainer1FacePlayer:
	face_right
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_Trainer2FacePlayer:
	face_left
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_Trainer1Exit:
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	set_invisible
	walk_up
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_Trainer2Exit:
	walk_up
	walk_up
	walk_up
	walk_left
	walk_up
	set_invisible
	walk_up
	step_end

@ For approaching Lucy and exiting room after defeating Lucy
BattleFrontier_BattlePikeRoomNormal_Movement_PlayerWalkUp2:
	walk_up
	walk_up
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_PreQueenHealNPCApproachPlayer:
	walk_down
	walk_down
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_HealNPCExitForLucy:
	walk_up
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_LucyEnter:
	set_visible
	walk_down
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_LucyMoveAside:
	walk_left
	face_right
	step_end

BattleFrontier_BattlePikeRoomNormal_EventScript_NPC::
	pike_getroomtype
	switch VAR_RESULT
	case PIKE_ROOM_NPC, BattleFrontier_BattlePikeRoomNormal_EventScript_NormalNPC
	case PIKE_ROOM_STATUS, BattleFrontier_BattlePikeRoomNormal_EventScript_StatusNPC
	case PIKE_ROOM_HEAL_PART, BattleFrontier_BattlePikeRoomNormal_EventScript_HealNPC
BattleFrontier_BattlePikeRoomNormal_EventScript_NormalNPC::
	lock
	faceplayer
	pike_getnpcmsg
	msgbox gStringVar4, MSGBOX_DEFAULT
	waitmessage
	closemessage
	release
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_StatusNPC::
	lock
	faceplayer
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_ApologizeHopeMonsAreFine, MSGBOX_DEFAULT
	closemessage
	release
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_HealNPC::
	pike_healonetwomons
	call_if_eq VAR_RESULT, 2, BattleFrontier_BattlePikeRoomNormal_EventScript_WillRestoreTwoMons
	call_if_eq VAR_RESULT, 1, BattleFrontier_BattlePikeRoomNormal_EventScript_WillRestoreOneMon
	playfanfare MUS_HEAL
	waitfanfare
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_BestOfLuckFarewell, MSGBOX_DEFAULT
	closemessage
	release
	applymovement LOCALID_PIKE_ROOM_NPC_1, BattleFrontier_BattlePikeRoomNormal_Movement_HealNPCExit
	waitmovement 0
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_WillRestoreOneMon::
	lock
	faceplayer
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_WillRestoreOneMon, MSGBOX_DEFAULT
	closemessage
	return

BattleFrontier_BattlePikeRoomNormal_EventScript_WillRestoreTwoMons::
	lock
	faceplayer
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_WillRestoreTwoMons, MSGBOX_DEFAULT
	closemessage
	return

@ Dusclops or Kirlia
BattleFrontier_BattlePikeRoomNormal_EventScript_StatusMon::
	lock
	faceplayer
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_Silence, MSGBOX_DEFAULT
	closemessage
	release
	applymovement LOCALID_PIKE_ROOM_NPC_2, BattleFrontier_BattlePikeRoomNormal_Movement_MonFaceRight
	waitmovement 0
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_SetCurtainTilesMostlyClosed::
	setmetatile 4, 1, METATILE_BattlePike_Curtain_Stage1_Tile0, TRUE
	setmetatile 3, 2, METATILE_BattlePike_Curtain_Stage1_Tile1, TRUE
	setmetatile 4, 2, METATILE_BattlePike_Curtain_Stage1_Tile2, TRUE
	setmetatile 5, 2, METATILE_BattlePike_Curtain_Stage1_Tile3, TRUE
	setmetatile 3, 3, METATILE_BattlePike_Curtain_Stage1_Tile4, TRUE
	setmetatile 4, 3, METATILE_BattlePike_Curtain_Stage1_Tile5, FALSE
	setmetatile 5, 3, METATILE_BattlePike_Curtain_Stage1_Tile6, TRUE
	special DrawWholeMapView
	return

BattleFrontier_BattlePikeRoomNormal_EventScript_SetCurtainTilesLittleClosed::
	setmetatile 4, 1, METATILE_BattlePike_Curtain_Stage2_Tile0, TRUE
	setmetatile 3, 2, METATILE_BattlePike_Curtain_Stage2_Tile1, TRUE
	setmetatile 4, 2, METATILE_BattlePike_Curtain_Stage2_Tile2, TRUE
	setmetatile 5, 2, METATILE_BattlePike_Curtain_Stage2_Tile3, TRUE
	setmetatile 3, 3, METATILE_BattlePike_Curtain_Stage2_Tile4, TRUE
	setmetatile 4, 3, METATILE_BattlePike_Curtain_Stage2_Tile5, FALSE
	setmetatile 5, 3, METATILE_BattlePike_Curtain_Stage2_Tile6, TRUE
	special DrawWholeMapView
	return

BattleFrontier_BattlePikeRoomNormal_EventScript_SetCurtainTilesOpen::
	setmetatile 4, 1, METATILE_BattlePike_Curtain_Stage3_Tile0, TRUE
	setmetatile 3, 2, METATILE_BattlePike_Curtain_Stage3_Tile1, TRUE
	setmetatile 4, 2, METATILE_BattlePike_Curtain_Stage3_Tile2, TRUE
	setmetatile 5, 2, METATILE_BattlePike_Curtain_Stage3_Tile3, TRUE
	setmetatile 3, 3, METATILE_BattlePike_Curtain_Stage3_Tile4, TRUE
	setmetatile 4, 3, METATILE_BattlePike_Curtain_Stage3_Tile5, FALSE
	setmetatile 5, 3, METATILE_BattlePike_Curtain_Stage3_Tile6, TRUE
	special DrawWholeMapView
	return

BattleFrontier_BattlePikeRoomNormal_EventScript_SetCurtainTilesClosed::
	setmetatile 4, 1, METATILE_BattlePike_Curtain_Stage0_Tile0, TRUE
	setmetatile 3, 2, METATILE_BattlePike_Curtain_Stage0_Tile1, TRUE
	setmetatile 4, 2, METATILE_BattlePike_Curtain_Stage0_Tile2, TRUE
	setmetatile 5, 2, METATILE_BattlePike_Curtain_Stage0_Tile3, TRUE
	setmetatile 3, 3, METATILE_BattlePike_Curtain_Stage0_Tile4, TRUE
	setmetatile 4, 3, METATILE_BattlePike_Curtain_Stage0_Tile5, FALSE
	setmetatile 5, 3, METATILE_BattlePike_Curtain_Stage0_Tile6, TRUE
	special DrawWholeMapView
	return

BattleFrontier_BattlePikeRoomNormal_Movement_CameraPanUp:
	walk_up
	walk_up
	step_end

@ Unused
BattleFrontier_BattlePikeRoomNormal_Movement_CameraPanDown:
	walk_down
	walk_down
	step_end

BattleFrontier_BattlePikeRoomNormal_Text_WillRestoreToFullHealth:
	.string "Chào mừng... Vận may của bạn thật đáng\n"
	.string "khen...\p"
	.string "POKéMON của bạn sẽ được hồi phục hoàn\n"
	.string "toàn...$"

BattleFrontier_BattlePikeRoomNormal_Text_EnjoyRestOfChallenge:
	.string "Chúc bạn tận hưởng phần còn lại của\n"
	.string "thử thách Battle Choice...$"

BattleFrontier_BattlePikeRoomNormal_Text_WillRestoreOneMon:
	.string "Ồ, bạn thật may mắn. Tâm trạng tôi lúc\n"
	.string "này cũng khá tốt.\p"
	.string "Tôi sẽ hồi phục hoàn toàn cho một\n"
	.string "POKéMON của bạn.$"

BattleFrontier_BattlePikeRoomNormal_Text_BestOfLuckFarewell:
	.string "Chúc bạn gặp nhiều may mắn. Tạm biệt.$"

@ Seems there was a planned room type where the player could choose to battle and would be healed if they won
@ Possibly replaced/superseded by the hard battle room, which is the same but the battle isnt optional
@ Unused
BattleFrontier_BattlePikeRoomNormal_Text_CareForBattleWillRestoreMons:
	.string "Xin thứ lỗi...\p"
	.string "Bạn có muốn đấu một trận không? Nếu\n"
	.string "bạn thắng, tôi sẽ hồi phục POKéMON của\l"
	.string "bạn.$"

@ Unused
BattleFrontier_BattlePikeRoomNormal_Text_NowShallWe:
	.string "Tốt thôi... Bây giờ, bắt đầu nhé?$"

@ Unused
BattleFrontier_BattlePikeRoomNormal_Text_HowUnsportingOfYou:
	.string "Ra vậy... Bạn thật thiếu tinh thần\n"
	.string "thượng võ...$"

@ Unused
BattleFrontier_BattlePikeRoomNormal_Text_WillRestoreMonsAsPromised:
	.string "Tuyệt vời...\p"
	.string "Như đã hứa, tôi sẽ hồi phục hoàn toàn\n"
	.string "cho POKéMON của bạn.$"

@ Unused
BattleFrontier_BattlePikeRoomNormal_Text_BestOfLuckFarewell2:
	.string "Chúc bạn gặp nhiều may mắn. Tạm biệt.$"

BattleFrontier_BattlePikeRoomNormal_Text_WatchOut:
	.string "Ôi trời!\p"
	.string "Cẩn thận!$"

BattleFrontier_BattlePikeRoomNormal_Text_KirliaStop:
	.string "Nào, nào! KIRLIA, dừng lại!$"

BattleFrontier_BattlePikeRoomNormal_Text_DusclopsStop:
	.string "Nào, nào! DUSCLOPS, dừng lại!$"

BattleFrontier_BattlePikeRoomNormal_Text_KirliaUsedToxic:
	.string "KIRLIA đã dùng TOXIC!$"

BattleFrontier_BattlePikeRoomNormal_Text_KirliaUsedHypnosis:
	.string "KIRLIA đã dùng HYPNOSIS!$"

BattleFrontier_BattlePikeRoomNormal_Text_KirliaUsedThunderWave:
	.string "KIRLIA đã dùng THUNDER WAVE!$"

BattleFrontier_BattlePikeRoomNormal_Text_KirliaUsedWillOWisp:
	.string "KIRLIA đã dùng WILL-O-WISP!$"

BattleFrontier_BattlePikeRoomNormal_Text_DusclopsUsedWillOWisp:
	.string "DUSCLOPS đã dùng WILL-O-WISP!$"

BattleFrontier_BattlePikeRoomNormal_Text_DusclopsUsedIceBeam:
	.string "DUSCLOPS đã dùng ICE BEAM!$"

BattleFrontier_BattlePikeRoomNormal_Text_ThatsEnough:
	.string "Này! Thế là quá đủ rồi!$"

BattleFrontier_BattlePikeRoomNormal_Text_ApologizeForKirlia:
	.string "Tôi phải xin lỗi bạn...\p"
	.string "KIRLIA của tôi có tính cách TIMID...$"

BattleFrontier_BattlePikeRoomNormal_Text_ApologizeForDusclops:
	.string "Tôi phải xin lỗi bạn...\p"
	.string "DUSCLOPS của tôi có tính cách TIMID...$"

BattleFrontier_BattlePikeRoomNormal_Text_AttacksWhenStartled:
	.string "Nó sẽ bất ngờ tấn công nếu có người\n"
	.string "khiến nó giật mình...\p"
	.string "Bạn và POKéMON của bạn đều ổn chứ?$"

BattleFrontier_BattlePikeRoomNormal_Text_ApologizeHopeMonsAreFine:
	.string "Tôi thành thật xin lỗi về chuyện vừa\n"
	.string "xảy ra... Mong rằng POKéMON của bạn vẫn\l"
	.string "ổn.$"

BattleFrontier_BattlePikeRoomNormal_Text_Silence:
	.string ". . . . . . . . . . . .$"

BattleFrontier_BattlePikeRoomNormal_Text_BattleSomewhatToughTrainer:
	.string "Chào mừng...\p"
	.string "Tại đây, bạn sẽ phải đấu với một\n"
	.string "HLV khá mạnh...$"

BattleFrontier_BattlePikeRoomNormal_Text_RestoreToFullHealth:
	.string "Thật tuyệt vời...\p"
	.string "Để tôn vinh chiến thắng của bạn,\n"
	.string "POKéMON của bạn sẽ được hồi phục hoàn\l"
	.string "toàn...$"

BattleFrontier_BattlePikeRoomNormal_Text_EnjoyRestOfChallenge2:
	.string "Chúc bạn tận hưởng phần còn lại của\n"
	.string "thử thách Battle Choice...$"

BattleFrontier_BattlePikeRoomNormal_Text_ImThePikeQueen:
	.string "Ta là LUCY... Ta chính là luật lệ ở đây...\n"
	.string "Bởi ta là PIKE QUEEN...\p"
	.string "Ngươi đã biết rồi, nhưng muốn đi tiếp\n"
	.string "thì phải đánh bại ta...\p"
	.string "...Ta không thích chuyện trò vô bổ.\n"
	.string "Nhanh lên. Tới đây...$"

BattleFrontier_BattlePikeRoomNormal_Text_HopeYouDidntUseUpLuck:
	.string "Vận may của ngươi... Ta hy vọng ngươi\n"
	.string "chưa dùng hết ở đây...$"

BattleFrontier_BattlePikeRoomNormal_Text_LucyShowMeFrontierPass:
	.string "LUCY: . . . . . . Đưa FRONTIER PASS của\n"
	.string "ngươi đây...$"

BattleFrontier_BattlePikeRoomNormal_Text_ReceivedLuckSymbol:
	.string "Luck Symbol đã được dập nổi lên\n"
	.string "FRONTIER PASS!$"

BattleFrontier_BattlePikeRoomNormal_Text_AllThereIsDisappear:
	.string "...Chỉ có vậy thôi... Biến đi...$"

BattleFrontier_BattlePikeRoomNormal_Text_LucyYouAgain:
	.string "LUCY: ...Lại là ngươi...\p"
	.string ". . . . . .\p"
	.string "...Ta đã giẫm nát hoa và vượt qua giông\n"
	.string "bão để có được vị trí hôm nay...\p"
	.string "Ta chẳng có lý do gì phải tiếp tục thua\n"
	.string "cùng một đối thủ...\p"
	.string ". . . . . . Được thôi... Ta sẽ đấu...$"

BattleFrontier_BattlePikeRoomNormal_Text_NowComeOn:
	.string "Nào! Tới đây!$"

BattleFrontier_BattlePikeRoomNormal_Text_LucyFrontierPass:
	.string "LUCY: . . . . . .\p"
	.string "...FRONTIER PASS...$"

BattleFrontier_BattlePikeRoomNormal_Text_LuckSymbolTookGoldenShine:
	.string "Luck Symbol đã ánh lên sắc vàng!$"

BattleFrontier_BattlePikeRoomNormal_Text_IWontForget:
	.string "...Ngươi, ta sẽ không quên... ...Không bao\n"
	.string "giờ...$"

BattleFrontier_BattlePikeRoomNormal_Text_ChoseRoomNoHeal:
	.string "Chào mừng...\p"
	.string "Hí hí... Có vẻ vận may của bạn đã cạn...\p"
	.string "Giá mà bạn không chọn căn phòng này thì\n"
	.string "POKéMON của bạn đã có thể được chữa\l"
	.string "trị...$"

BattleFrontier_BattlePikeRoomNormal_Text_ChoseRoomHealOne:
	.string "Chào mừng...\p"
	.string "Vì bạn đã chọn căn phòng này, tôi sẽ hồi\n"
	.string "phục hoàn toàn cho một POKéMON...$"

BattleFrontier_BattlePikeRoomNormal_Text_ChoseRoomHealTwo:
	.string "Chào mừng...\p"
	.string "Vì bạn đã chọn căn phòng này, tôi sẽ hồi\n"
	.string "phục hoàn toàn cho hai POKéMON...$"

@ Unused
BattleFrontier_BattlePikeRoomNormal_Text_WillRestoreAllMons:
	.string "Chào mừng bạn...\p"
	.string "Khúc khích... Bạn nên cảm tạ vận may của\n"
	.string "mình...\p"
	.string "Vì đã chọn căn phòng này, toàn bộ\n"
	.string "POKéMON của bạn sẽ được hồi phục...$"

BattleFrontier_BattlePikeRoomNormal_Text_ShallFetchOurMaster:
	.string "Tôi sẽ đi mời chủ nhân của chúng tôi...$"

BattleFrontier_BattlePikeRoomNormal_Text_WillRestoreTwoMons:
	.string "Ồ, bạn may mắn thật đấy! Giờ tâm trạng\n"
	.string "tôi đang rất tốt.\p"
	.string "Tôi sẽ hồi phục hoàn toàn cho hai\n"
	.string "POKéMON của bạn!$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global BattleFrontier_BattlePikeRoomNormal_Text_WillRestoreToFullHealth
	.global BattleFrontier_BattlePikeRoomNormal_Text_EnjoyRestOfChallenge
	.global BattleFrontier_BattlePikeRoomNormal_Text_WillRestoreOneMon
	.global BattleFrontier_BattlePikeRoomNormal_Text_BestOfLuckFarewell
	.global BattleFrontier_BattlePikeRoomNormal_Text_CareForBattleWillRestoreMons
	.global BattleFrontier_BattlePikeRoomNormal_Text_NowShallWe
	.global BattleFrontier_BattlePikeRoomNormal_Text_HowUnsportingOfYou
	.global BattleFrontier_BattlePikeRoomNormal_Text_WillRestoreMonsAsPromised
	.global BattleFrontier_BattlePikeRoomNormal_Text_BestOfLuckFarewell2
	.global BattleFrontier_BattlePikeRoomNormal_Text_WatchOut
	.global BattleFrontier_BattlePikeRoomNormal_Text_KirliaStop
	.global BattleFrontier_BattlePikeRoomNormal_Text_DusclopsStop
	.global BattleFrontier_BattlePikeRoomNormal_Text_KirliaUsedToxic
	.global BattleFrontier_BattlePikeRoomNormal_Text_KirliaUsedHypnosis
	.global BattleFrontier_BattlePikeRoomNormal_Text_KirliaUsedThunderWave
	.global BattleFrontier_BattlePikeRoomNormal_Text_KirliaUsedWillOWisp
	.global BattleFrontier_BattlePikeRoomNormal_Text_DusclopsUsedWillOWisp
	.global BattleFrontier_BattlePikeRoomNormal_Text_DusclopsUsedIceBeam
	.global BattleFrontier_BattlePikeRoomNormal_Text_ThatsEnough
	.global BattleFrontier_BattlePikeRoomNormal_Text_ApologizeForKirlia
	.global BattleFrontier_BattlePikeRoomNormal_Text_ApologizeForDusclops
	.global BattleFrontier_BattlePikeRoomNormal_Text_AttacksWhenStartled
	.global BattleFrontier_BattlePikeRoomNormal_Text_ApologizeHopeMonsAreFine
	.global BattleFrontier_BattlePikeRoomNormal_Text_Silence
	.global BattleFrontier_BattlePikeRoomNormal_Text_BattleSomewhatToughTrainer
	.global BattleFrontier_BattlePikeRoomNormal_Text_RestoreToFullHealth
	.global BattleFrontier_BattlePikeRoomNormal_Text_EnjoyRestOfChallenge2
	.global BattleFrontier_BattlePikeRoomNormal_Text_ImThePikeQueen
	.global BattleFrontier_BattlePikeRoomNormal_Text_HopeYouDidntUseUpLuck
	.global BattleFrontier_BattlePikeRoomNormal_Text_LucyShowMeFrontierPass
	.global BattleFrontier_BattlePikeRoomNormal_Text_ReceivedLuckSymbol
	.global BattleFrontier_BattlePikeRoomNormal_Text_AllThereIsDisappear
	.global BattleFrontier_BattlePikeRoomNormal_Text_LucyYouAgain
	.global BattleFrontier_BattlePikeRoomNormal_Text_NowComeOn
	.global BattleFrontier_BattlePikeRoomNormal_Text_LucyFrontierPass
	.global BattleFrontier_BattlePikeRoomNormal_Text_LuckSymbolTookGoldenShine
	.global BattleFrontier_BattlePikeRoomNormal_Text_IWontForget
	.global BattleFrontier_BattlePikeRoomNormal_Text_ChoseRoomNoHeal
	.global BattleFrontier_BattlePikeRoomNormal_Text_ChoseRoomHealOne
	.global BattleFrontier_BattlePikeRoomNormal_Text_ChoseRoomHealTwo
	.global BattleFrontier_BattlePikeRoomNormal_Text_WillRestoreAllMons
	.global BattleFrontier_BattlePikeRoomNormal_Text_ShallFetchOurMaster
	.global BattleFrontier_BattlePikeRoomNormal_Text_WillRestoreTwoMons
@ END GENERATED LOCALIZATION EXPORTS
