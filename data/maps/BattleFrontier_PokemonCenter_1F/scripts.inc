BattleFrontier_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

BattleFrontier_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_BATTLE_FRONTIER_OUTSIDE_EAST
	end

BattleFrontier_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_FRONTIER_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_PokemonCenter_1F_EventScript_SchoolKid::
	msgbox BattleFrontier_PokemonCenter_1F_Text_NeverSeenPokemon, MSGBOX_NPC
	end

BattleFrontier_PokemonCenter_1F_EventScript_Man::
	msgbox BattleFrontier_PokemonCenter_1F_Text_NextStopBattleArena, MSGBOX_NPC
	end

BattleFrontier_PokemonCenter_1F_EventScript_Picnicker::
	msgbox BattleFrontier_PokemonCenter_1F_Text_GoingThroughEveryChallenge, MSGBOX_NPC
	end

BattleFrontier_PokemonCenter_1F_EventScript_Skitty::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SKITTY, CRY_MODE_NORMAL
	msgbox BattleFrontier_PokemonCenter_1F_Text_Skitty, MSGBOX_DEFAULT
	waitmoncry
	release
	end

BattleFrontier_PokemonCenter_1F_Text_NeverSeenPokemon:
	.string "Có người ở đây dùng một POKéMON mà tôi\n"
	.string "chưa từng thấy.\p"
	.string "Ít nhất thì tôi chưa hề học về nó ở\n"
	.string "TRAINER'S SCHOOL.\p"
	.string "Không biết có thể bắt POKéMON như thế\n"
	.string "ở đâu nhỉ.$"

BattleFrontier_PokemonCenter_1F_Text_NextStopBattleArena:
	.string "Được rồi! Điểm đến tiếp theo là BATTLE\n"
	.string "ARENA! Mình nên lấy đúng POKéMON từ PC\l"
	.string "Storage System.$"

BattleFrontier_PokemonCenter_1F_Text_GoingThroughEveryChallenge:
	.string "Hí hí... Tôi sẽ vượt qua mọi thử thách\n"
	.string "chỉ với bé cưng này!$"

BattleFrontier_PokemonCenter_1F_Text_Skitty:
	.string "SKITTY: Meo meooo!$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global BattleFrontier_PokemonCenter_1F_Text_NeverSeenPokemon
	.global BattleFrontier_PokemonCenter_1F_Text_NextStopBattleArena
	.global BattleFrontier_PokemonCenter_1F_Text_GoingThroughEveryChallenge
	.global BattleFrontier_PokemonCenter_1F_Text_Skitty
@ END GENERATED LOCALIZATION EXPORTS
