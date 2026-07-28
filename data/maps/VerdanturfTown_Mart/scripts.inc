VerdanturfTown_Mart_MapScripts::
	.byte 0

VerdanturfTown_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart VerdanturfTown_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
VerdanturfTown_Mart_Pokemart:
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_NEST_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_REPEL
	.2byte ITEM_X_SPECIAL
	.2byte ITEM_FLUFFY_TAIL
	pokemartlistend

VerdanturfTown_Mart_EventScript_Boy::
	msgbox VerdanturfTown_Mart_Text_XSpecialIsCrucial, MSGBOX_NPC
	end

VerdanturfTown_Mart_EventScript_ExpertF::
	msgbox VerdanturfTown_Mart_Text_NoStrategyGuidesForBattleTent, MSGBOX_NPC
	end

VerdanturfTown_Mart_EventScript_Lass::
	msgbox VerdanturfTown_Mart_Text_NestBallOnWeakenedPokemon, MSGBOX_NPC
	end

VerdanturfTown_Mart_Text_XSpecialIsCrucial:
	.string "Trong bất kỳ trận đấu POKéMON nào, X\n"
	.string "SPECIAL cũng rất quan trọng.\p"
	.string "Nó tăng mạnh uy lực của một số chiêu, dù\n"
	.string "hiệu quả chỉ kéo dài trong một trận.$"

VerdanturfTown_Mart_Text_NoStrategyGuidesForBattleTent:
	.string "Có vẻ họ không bán cẩm nang chiến thuật\n"
	.string "giúp chiến thắng tại BATTLE TENT...\p"
	.string "Rốt cuộc, mỗi người vẫn phải dựa vào\n"
	.string "trí khôn của chính mình...$"

VerdanturfTown_Mart_Text_NestBallOnWeakenedPokemon:
	.string "NEST BALL hiệu quả hơn với POKéMON đã\n"
	.string "suy yếu.\p"
	.string "VERDANTURF là nơi duy nhất bạn có thể\n"
	.string "mua nó.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global VerdanturfTown_Mart_Text_XSpecialIsCrucial
	.global VerdanturfTown_Mart_Text_NoStrategyGuidesForBattleTent
	.global VerdanturfTown_Mart_Text_NestBallOnWeakenedPokemon
@ END GENERATED LOCALIZATION EXPORTS
