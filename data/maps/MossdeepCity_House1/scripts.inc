MossdeepCity_House1_MapScripts::
	.byte 0

MossdeepCity_House1_EventScript_BlackBelt::
	lock
	faceplayer
	bufferleadmonspeciesname STR_VAR_1
	msgbox MossdeepCity_House1_Text_HmmYourPokemon, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetPokeblockNameByMonNature
	goto_if_eq VAR_RESULT, 0, MossdeepCity_House1_EventScript_NeutralNature
	msgbox MossdeepCity_House1_Text_ItLikesXPokeblocks, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House1_EventScript_NeutralNature::
	msgbox MossdeepCity_House1_Text_DoesntLikeOrDislikePokeblocks, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House1_EventScript_Woman::
	msgbox MossdeepCity_House1_Text_HusbandCanTellPokeblockMonLikes, MSGBOX_NPC
	end

MossdeepCity_House1_Text_HmmYourPokemon:
	.string "Hừm! {STR_VAR_1} của bạn...$"

MossdeepCity_House1_Text_ItLikesXPokeblocks:
	.string "Nó thích {STR_VAR_1}S, đúng\n"
	.string "không?\p"
	.string "Không, tôi chắc chắn đấy! Nó nhất định\n"
	.string "rất thích {STR_VAR_1}S!$"

MossdeepCity_House1_Text_DoesntLikeOrDislikePokeblocks:
	.string "Nó có vẻ chẳng thích cũng chẳng ghét\n"
	.string "loại {POKEBLOCK} nào.$"

MossdeepCity_House1_Text_HusbandCanTellPokeblockMonLikes:
	.string "Chồng tôi chỉ cần nhìn qua là biết một\n"
	.string "POKéMON thích loại {POKEBLOCK} nào.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global MossdeepCity_House1_Text_HmmYourPokemon
	.global MossdeepCity_House1_Text_ItLikesXPokeblocks
	.global MossdeepCity_House1_Text_DoesntLikeOrDislikePokeblocks
	.global MossdeepCity_House1_Text_HusbandCanTellPokeblockMonLikes
@ END GENERATED LOCALIZATION EXPORTS
