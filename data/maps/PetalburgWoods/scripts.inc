PetalburgWoods_MapScripts::
	.byte 0

PetalburgWoods_EventScript_DevonResearcherLeft::
	lockall
	call PetalburgWoods_EventScript_DevonResearcherIntro
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherApproachPlayerLeft
	waitmovement 0
	msgbox PetalburgWoods_Text_HaveYouSeenShroomish, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaEntrance
	waitmovement 0
	msgbox PetalburgWoods_Text_IWasGoingToAmbushYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaApproachResearcherLeft
	waitmovement 0
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox PetalburgWoods_Text_HandOverThosePapers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherFleeToPlayerLeft
	waitmovement 0
	msgbox PetalburgWoods_Text_YouHaveToHelpMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaApproachPlayer
	waitmovement 0
	msgbox PetalburgWoods_Text_NoOneCrossesTeamAqua, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_PETALBURG_WOODS, PetalburgWoods_Text_YoureKiddingMe
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaBackOff
	waitmovement 0
	call PetalburgWoods_EventScript_DevonResearcherPostBattle
	applymovement LOCALID_PLAYER, PetalburgWoods_Movement_WatchResearcherLeave
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherExitLeft
	waitmovement 0
	goto PetalburgWoods_EventScript_RemoveDevonResearcher
	end

PetalburgWoods_EventScript_DevonResearcherRight::
	lockall
	call PetalburgWoods_EventScript_DevonResearcherIntro
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherApproachPlayerRight
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox PetalburgWoods_Text_HaveYouSeenShroomish, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaEntrance
	waitmovement 0
	msgbox PetalburgWoods_Text_IWasGoingToAmbushYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaApproachResearcherRight
	waitmovement 0
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox PetalburgWoods_Text_HandOverThosePapers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherFleeToPlayerRight
	waitmovement 0
	msgbox PetalburgWoods_Text_YouHaveToHelpMe, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox PetalburgWoods_Text_NoOneCrossesTeamAqua, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_PETALBURG_WOODS, PetalburgWoods_Text_YoureKiddingMe
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaBackOff
	waitmovement 0
	call PetalburgWoods_EventScript_DevonResearcherPostBattle
	applymovement LOCALID_PLAYER, PetalburgWoods_Movement_WatchResearcherLeave
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherExitRight
	waitmovement 0
	goto PetalburgWoods_EventScript_RemoveDevonResearcher
	end

PetalburgWoods_EventScript_DevonResearcherIntro::
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherLookAround
	waitmovement 0
	msgbox PetalburgWoods_Text_NotAOneToBeFound, MSGBOX_DEFAULT
	closemessage
	return

PetalburgWoods_EventScript_DevonResearcherPostBattle::
	msgbox PetalburgWoods_Text_YouveGotSomeNerve, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaRunAway
	waitmovement 0
	removeobject LOCALID_PETALBURG_WOODS_GRUNT
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox PetalburgWoods_Text_ThatWasAwfullyClose, MSGBOX_DEFAULT
	giveitem ITEM_GREAT_BALL
	goto_if_eq VAR_RESULT, FALSE, PetalburgWoods_EventScript_BagFull
	goto PetalburgWoods_EventScript_DevonResearcherFinish
	end

PetalburgWoods_EventScript_BagFull::
	msgbox PetalburgWoods_Text_YoureLoadedWithItems, MSGBOX_DEFAULT
	goto PetalburgWoods_EventScript_DevonResearcherFinish
	end

PetalburgWoods_EventScript_DevonResearcherFinish::
	msgbox PetalburgWoods_Text_TeamAquaAfterSomethingInRustboro, MSGBOX_DEFAULT
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherStartExit
	waitmovement 0
	msgbox PetalburgWoods_Text_ICantBeWastingTime, MSGBOX_DEFAULT
	closemessage
	return

PetalburgWoods_EventScript_RemoveDevonResearcher::
	removeobject LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE
	setvar VAR_PETALBURG_WOODS_STATE, 1
	releaseall
	end

PetalburgWoods_Movement_DevonResearcherLookAround:
	face_up
	delay_16
	delay_4
	face_right
	delay_16
	delay_8
	face_left
	delay_16
	delay_8
	face_down
	delay_16
	face_right
	delay_16
	delay_8
	face_up
	delay_16
	step_end

PetalburgWoods_Movement_DevonResearcherExitLeft:
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

PetalburgWoods_Movement_DevonResearcherApproachPlayerLeft:
	delay_16
	face_player
	walk_down
	walk_down
	step_end

PetalburgWoods_Movement_DevonResearcherApproachPlayerRight:
	delay_16
	face_player
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

PetalburgWoods_Movement_DevonResearcherExitRight:
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

PetalburgWoods_Movement_WatchResearcherLeave:
	delay_16
	delay_16
	walk_in_place_faster_up
	step_end

PetalburgWoods_Movement_DevonResearcherFleeToPlayerLeft:
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_in_place_faster_up
	step_end

PetalburgWoods_Movement_DevonResearcherFleeToPlayerRight:
	walk_fast_down
	walk_fast_right
	walk_in_place_faster_up
	step_end

PetalburgWoods_Movement_DevonResearcherStartExit:
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	face_up
	step_end

PetalburgWoods_Movement_AquaApproachResearcherLeft:
	walk_fast_down
	walk_fast_down
	step_end

PetalburgWoods_Movement_AquaBackOff:
	lock_facing_direction
	walk_up
	unlock_facing_direction
	step_end

PetalburgWoods_Movement_AquaRunAway:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	delay_16
	delay_16
	step_end

PetalburgWoods_Movement_AquaApproachResearcherRight:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

PetalburgWoods_Movement_AquaEntrance:
	walk_down
	walk_down
	delay_16
	delay_16
	step_end

PetalburgWoods_Movement_AquaApproachPlayer:
	walk_down
	step_end

PetalburgWoods_EventScript_Boy1::
	msgbox PetalburgWoods_Text_StayOutOfTallGrass, MSGBOX_NPC
	end

PetalburgWoods_EventScript_Boy2::
	msgbox PetalburgWoods_Text_HiddenItemsExplanation, MSGBOX_NPC
	end

PetalburgWoods_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_MIRACLE_SEED, PetalburgWoods_EventScript_ExplainMiracleSeed
	msgbox PetalburgWoods_Text_TryUsingThisItem, MSGBOX_DEFAULT
	giveitem ITEM_MIRACLE_SEED
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_MIRACLE_SEED
	release
	end

PetalburgWoods_EventScript_ExplainMiracleSeed::
	msgbox PetalburgWoods_Text_MiracleSeedExplanation, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_Sign1::
	msgbox PetalburgWoods_Text_TrainerTipsExperience, MSGBOX_SIGN
	end

PetalburgWoods_EventScript_Sign2::
	msgbox PetalburgWoods_Text_TrainerTipsPP, MSGBOX_SIGN
	end

PetalburgWoods_EventScript_Lyle::
	trainerbattle_single TRAINER_LYLE, PetalburgWoods_Text_GoBugPokemonTeam, PetalburgWoods_Text_ICouldntWin
	msgbox PetalburgWoods_Text_ImOutOfPokeBalls, MSGBOX_AUTOCLOSE
	end

PetalburgWoods_EventScript_James::
	trainerbattle_single TRAINER_JAMES_1, PetalburgWoods_Text_InstantlyPopularWithBugPokemon, PetalburgWoods_Text_CantBePopularIfILose, PetalburgWoods_EventScript_TryRegisterJames
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, PetalburgWoods_EventScript_JamesRematch
	setvar VAR_0x8004, TRAINER_JAMES_1
	specialvar VAR_RESULT, IsTrainerRegistered
	goto_if_eq VAR_RESULT, FALSE, PetalburgWoods_EventScript_TryRegisterJames2
	msgbox PetalburgWoods_Text_PeopleRespectYou, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_TryRegisterJames::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	goto_if_set FLAG_HAS_MATCH_CALL, PetalburgWoods_EventScript_RegisterJames
	release
	end

PetalburgWoods_EventScript_RegisterJames::
	msgbox PetalburgWoods_Text_IWantRematch1, MSGBOX_DEFAULT
	register_matchcall TRAINER_JAMES_1
	release
	end

PetalburgWoods_EventScript_TryRegisterJames2::
	goto_if_set FLAG_HAS_MATCH_CALL, PetalburgWoods_EventScript_RegisterJames2
	msgbox PetalburgWoods_Text_PeopleRespectYou, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_RegisterJames2::
	msgbox PetalburgWoods_Text_IWantRematch2, MSGBOX_DEFAULT
	register_matchcall TRAINER_JAMES_1
	release
	end

PetalburgWoods_EventScript_JamesRematch::
	trainerbattle_rematch TRAINER_JAMES_1, PetalburgWoods_Text_MyPokemonHaveGrown, PetalburgWoods_Text_CantBePopularIfLose
	msgbox PetalburgWoods_Text_IveBeenTrainingHard, MSGBOX_AUTOCLOSE
	end

PetalburgWoods_Text_NotAOneToBeFound:
	.string "Hừm... Chẳng thấy con nào cả...$"

PetalburgWoods_Text_HaveYouSeenShroomish:
	.string "Xin chào, bạn có thấy POKéMON nào tên\n"
	.string "SHROOMISH quanh đây không?\p"
	.string "Tôi rất thích POKéMON đó.$"

PetalburgWoods_Text_IWasGoingToAmbushYou:
	.string "Ta định phục kích ngươi, thế mà ngươi\n"
	.string "cứ lần lữa mãi trong PETALBURG WOODS,\l"
	.string "phải không?\p"
	.string "Ta chờ phát ngán nên đành tự tới đây!$"

PetalburgWoods_Text_HandOverThosePapers:
	.string "Tên DEVON RESEARCHER kia!\p"
	.string "Giao đống giấy tờ đó ra!$"

PetalburgWoods_Text_YouHaveToHelpMe:
	.string "Ááá!\p"
	.string "Bạn là HLV POKéMON, phải không?\n"
	.string "Làm ơn cứu tôi với!$"

PetalburgWoods_Text_NoOneCrossesTeamAqua:
	.string "Hả? Ngươi định làm gì? Sao, ngươi muốn\n"
	.string "bảo vệ hắn à?\p"
	.string "Kẻ nào dám chống TEAM AQUA sẽ không\n"
	.string "được tha, kể cả trẻ con!\p"
	.string "Mau đấu với ta!$"

PetalburgWoods_Text_YoureKiddingMe:
	.string "Đùa ta sao! Ngươi mạnh thật!$"

PetalburgWoods_Text_YouveGotSomeNerve:
	.string "Gừừ... Ngươi gan lắm mới dám xen vào\n"
	.string "chuyện của TEAM AQUA! Đấu với ta lần\l"
	.string "nữa!\p"
	.string "Ta cũng muốn nói vậy lắm, nhưng đã hết\n"
	.string "POKéMON rồi...\p"
	.string "Này, bọn TEAM AQUA chúng ta cũng đang\n"
	.string "nhắm đến thứ gì đó ở RUSTBORO.\p"
	.string "Hôm nay ta tha cho ngươi đấy!$"

PetalburgWoods_Text_ThatWasAwfullyClose:
	.string "Phù... Suýt nữa thì nguy!\p"
	.string "Nhờ bạn mà hắn không cướp được những\n"
	.string "giấy tờ quan trọng này.\p"
	.string "Tôi biết rồi, để cảm ơn, tôi sẽ tặng bạn\n"
	.string "GREAT BALL!$"

PetalburgWoods_Text_TeamAquaAfterSomethingInRustboro:
	.string "Tên côn đồ TEAM AQUA đó chẳng phải đã\n"
	.string "nói bọn chúng cũng đang nhắm đến thứ\l"
	.string "gì đó ở RUSTBORO sao?$"

PetalburgWoods_Text_ICantBeWastingTime:
	.string "Ôi không! Có chuyện lớn rồi! Tôi không\n"
	.string "thể phí thời gian được!$"

PetalburgWoods_Text_YoureLoadedWithItems:
	.string "Túi đồ của cậu đầy rồi. Tớ không thể\n"
	.string "đưa GREAT BALL này cho cậu.$"

PetalburgWoods_Text_GoBugPokemonTeam:
	.string "Tớ đã bắt cả một đống POKéMON!\p"
	.string "Tiến lên, tiến lên, tiến lên! Đội BUG\n"
	.string "POKéMON của tớ!$"

PetalburgWoods_Text_ICouldntWin:
	.string "Có ngần ấy POKéMON mà tớ vẫn không\n"
	.string "thắng nổi...$"

PetalburgWoods_Text_ImOutOfPokeBalls:
	.string "Tớ đã bắt cả đống POKéMON. Giờ thì hết\n"
	.string "sạch POKé BALLS rồi.$"

PetalburgWoods_Text_InstantlyPopularWithBugPokemon:
	.string "Nếu mang BUG POKéMON đến trường, cậu\n"
	.string "sẽ nổi tiếng ngay lập tức!$"

PetalburgWoods_Text_CantBePopularIfILose:
	.string "Thua cuộc thì làm sao tớ nổi tiếng\n"
	.string "được.$"

PetalburgWoods_Text_PeopleRespectYou:
	.string "Nếu có một BUG POKéMON thật to, cậu sẽ\n"
	.string "được mọi người nể phục.$"

PetalburgWoods_Text_IWantRematch1:
	.string "Khi BUG POKéMON của tớ lớn lên, tớ muốn\n"
	.string "tái đấu!\p"
	.string "Tớ sẽ đăng ký cậu vào POKéNAV!$"

PetalburgWoods_Text_IWantRematch2:
	.string "Khi BUG POKéMON của tớ lớn lên, tớ muốn\n"
	.string "tái đấu!\p"
	.string "Tớ sẽ đăng ký cậu vào POKéNAV!$"

PetalburgWoods_Text_MyPokemonHaveGrown:
	.string "BUG POKéMON của tớ đã lớn rồi. Tớ sẽ lại\n"
	.string "nổi tiếng thôi.$"

PetalburgWoods_Text_CantBePopularIfLose:
	.string "Thua cuộc thì làm sao tớ nổi tiếng\n"
	.string "được.$"

PetalburgWoods_Text_IveBeenTrainingHard:
	.string "Có POKéMON mạnh thì sẽ nổi tiếng, đúng\n"
	.string "không? Vì vậy tớ đã chăm chỉ luyện tập.$"

PetalburgWoods_Text_StayOutOfTallGrass:
	.string "Này, chào cậu! POKéMON của cậu vẫn ổn\n"
	.string "chứ?\p"
	.string "Nếu POKéMON đang yếu và cậu muốn tránh\n"
	.string "giao chiến, hãy tránh xa cỏ cao.$"

PetalburgWoods_Text_HiddenItemsExplanation:
	.string "Đôi khi trên mặt đất có đồ vật mà mắt\n"
	.string "thường không nhìn thấy.\p"
	.string "Vì vậy tôi luôn kiểm tra kỹ nơi mình đặt\n"
	.string "chân.$"

PetalburgWoods_Text_TryUsingThisItem:
	.string "Ồ, tuyệt thật! Đó là BADGE của RUSTBORO\n"
	.string "GYM!\p"
	.string "Bạn hẳn là một HLV. Hãy thử dùng\n"
	.string "vật phẩm này nhé.$"

PetalburgWoods_Text_MiracleSeedExplanation:
	.string "Đó là MIRACLE SEED. Khi POKéMON cầm\n"
	.string "vật phẩm này, chiêu hệ GRASS sẽ mạnh\l"
	.string "hơn.\p"
	.string "Ngoài MIRACLE SEED, còn nhiều vật phẩm\n"
	.string "hữu ích khác để POKéMON cầm.$"

PetalburgWoods_Text_TrainerTipsExperience:
	.string "TRAINER TIPS\p"
	.string "Bất kỳ POKéMON nào xuất hiện dù chỉ một\n"
	.string "lần trong trận đấu cũng sẽ nhận được\l"
	.string "EXP Points.\p"
	.string "Muốn rèn luyện một POKéMON yếu, hãy đặt\n"
	.string "nó ở bên trái danh sách đội.\p"
	.string "Ngay khi trận đấu bắt đầu, hãy đổi nó\n"
	.string "ra. Nó vẫn nhận được EXP Points mà\l"
	.string "không phải chịu bất kỳ tổn hại nào.$"

PetalburgWoods_Text_TrainerTipsPP:
	.string "TRAINER TIPS\p"
	.string "Ngoài Hit Points (HP), POKéMON còn có\n"
	.string "Power Points (PP), được tiêu hao khi sử\l"
	.string "dụng chiêu thức trong trận đấu.\p"
	.string "Nếu một POKéMON cạn PP, hãy đưa nó đến\n"
	.string "POKéMON CENTER.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global PetalburgWoods_Text_NotAOneToBeFound
	.global PetalburgWoods_Text_HaveYouSeenShroomish
	.global PetalburgWoods_Text_IWasGoingToAmbushYou
	.global PetalburgWoods_Text_HandOverThosePapers
	.global PetalburgWoods_Text_YouHaveToHelpMe
	.global PetalburgWoods_Text_NoOneCrossesTeamAqua
	.global PetalburgWoods_Text_YoureKiddingMe
	.global PetalburgWoods_Text_YouveGotSomeNerve
	.global PetalburgWoods_Text_ThatWasAwfullyClose
	.global PetalburgWoods_Text_TeamAquaAfterSomethingInRustboro
	.global PetalburgWoods_Text_ICantBeWastingTime
	.global PetalburgWoods_Text_YoureLoadedWithItems
	.global PetalburgWoods_Text_GoBugPokemonTeam
	.global PetalburgWoods_Text_ICouldntWin
	.global PetalburgWoods_Text_ImOutOfPokeBalls
	.global PetalburgWoods_Text_InstantlyPopularWithBugPokemon
	.global PetalburgWoods_Text_CantBePopularIfILose
	.global PetalburgWoods_Text_PeopleRespectYou
	.global PetalburgWoods_Text_IWantRematch1
	.global PetalburgWoods_Text_IWantRematch2
	.global PetalburgWoods_Text_MyPokemonHaveGrown
	.global PetalburgWoods_Text_CantBePopularIfLose
	.global PetalburgWoods_Text_IveBeenTrainingHard
	.global PetalburgWoods_Text_StayOutOfTallGrass
	.global PetalburgWoods_Text_HiddenItemsExplanation
	.global PetalburgWoods_Text_TryUsingThisItem
	.global PetalburgWoods_Text_MiracleSeedExplanation
	.global PetalburgWoods_Text_TrainerTipsExperience
	.global PetalburgWoods_Text_TrainerTipsPP
@ END GENERATED LOCALIZATION EXPORTS
