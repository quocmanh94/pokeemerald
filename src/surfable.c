#include "global.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "field_effect.h"
#include "field_effect_helpers.h"
#include "field_player_avatar.h"
#include "field_weather.h"
#include "pokemon.h"
#include "sprite.h"
#include "surfable.h"
#include "constants/event_object_movement.h"
#include "constants/event_objects.h"
#include "constants/field_effects.h"
#include "constants/species.h"

extern const struct OamData gObjectEventBaseOam_64x64;

struct SurfablePokemon
{
    u16 species;
};

static void CreateSurfablePokemonOverlay(u16 surfMonIndex, bool8 isShiny);
static void UpdateSurfablePokemonOverlay(struct Sprite *sprite);

#include "data/object_events/surfable/surfable_pokemon.h"
#include "data/object_events/surfable/surfable_pokemon_graphics.h"
#include "data/object_events/surfable/surfable_pokemon_pic_tables.h"
#include "data/object_events/surfable/surfable_pokemon_templates.h"

STATIC_ASSERT(ARRAY_COUNT(sSurfablePokemon) == ARRAY_COUNT(gSurfablePokemonOverworldSprites), SurfablePokemonTemplateCountMismatch);
STATIC_ASSERT(ARRAY_COUNT(sSurfablePokemon) == ARRAY_COUNT(gSurfablePokemonOverworldShinySprites), SurfablePokemonShinyTemplateCountMismatch);
STATIC_ASSERT(ARRAY_COUNT(sSurfablePokemon) == ARRAY_COUNT(gSurfablePokemonOverlaySprites), SurfablePokemonOverlayCountMismatch);
STATIC_ASSERT(ARRAY_COUNT(sSurfablePokemon) == ARRAY_COUNT(gSurfablePokemonOverlayShinySprites), SurfablePokemonShinyOverlayCountMismatch);

static u16 GetSurfablePokemonIndex(void)
{
    u16 i;
    u16 partySlot = VarGet(VAR_SURF_MON_SLOT);
    u16 species;

    if (partySlot >= PARTY_SIZE)
        return ARRAY_COUNT(sSurfablePokemon);

    species = GetMonData(&gPlayerParty[partySlot], MON_DATA_SPECIES);
    for (i = 0; i < ARRAY_COUNT(sSurfablePokemon); i++)
    {
        if (species == sSurfablePokemon[i].species)
            return i;
    }

    return ARRAY_COUNT(sSurfablePokemon);
}

static void LoadSurfablePokemonPalette(u16 surfMonIndex, bool8 isShiny)
{
    u8 paletteNum;

    if (isShiny)
        paletteNum = LoadSpritePalette(&sSurfablePokemonShinyPalettes[surfMonIndex]);
    else
        paletteNum = LoadSpritePalette(&sSurfablePokemonPalettes[surfMonIndex]);

    if (paletteNum != 0xFF)
        UpdateSpritePaletteWithWeather(paletteNum, TRUE);
}

static u8 CreateVanillaSurfBlob(void)
{
    u8 paletteNum;
    u8 spriteId;
    u16 paletteTag;

    paletteTag = gSaveBlock2Ptr->playerGender == MALE
               ? FLDEFF_PAL_TAG_BRENDAN
               : FLDEFF_PAL_TAG_MAY;
    paletteNum = LoadObjectEventPalette(paletteTag);
    spriteId = CreateSpriteAtEnd(
        gFieldEffectObjectTemplatePointers[FLDEFFOBJ_SURF_BLOB],
        gFieldEffectArguments[0],
        gFieldEffectArguments[1],
        150);
    if (spriteId != MAX_SPRITES)
        gSprites[spriteId].oam.paletteNum = paletteNum;

    return spriteId;
}

u32 CreateSurfablePokemonSprite(void)
{
    u8 spriteId;
    u16 surfMonIndex;
    u16 partySlot = VarGet(VAR_SURF_MON_SLOT);
    bool8 isShiny = FALSE;
    bool8 createOverlay = FALSE;

    SetSpritePosToOffsetMapCoords(
        (s16 *)&gFieldEffectArguments[0],
        (s16 *)&gFieldEffectArguments[1],
        8,
        8);

    FreeSpritePaletteByTag(PAL_TAG_SURFABLE_POKEMON);
    surfMonIndex = GetSurfablePokemonIndex();
    if (surfMonIndex < ARRAY_COUNT(sSurfablePokemon))
    {
        if (partySlot < PARTY_SIZE)
            isShiny = IsMonShiny(&gPlayerParty[partySlot]);

        LoadSurfablePokemonPalette(surfMonIndex, isShiny);
        if (isShiny)
        {
            spriteId = CreateSpriteAtEnd(
                &gSurfablePokemonOverworldShinySprites[surfMonIndex],
                gFieldEffectArguments[0],
                gFieldEffectArguments[1],
                150);
        }
        else
        {
            spriteId = CreateSpriteAtEnd(
                &gSurfablePokemonOverworldSprites[surfMonIndex],
                gFieldEffectArguments[0],
                gFieldEffectArguments[1],
                150);
        }

        createOverlay = gSurfablePokemonOverlaySprites[surfMonIndex].images != NULL;
    }
    else
    {
        spriteId = CreateVanillaSurfBlob();
    }

    if (spriteId != MAX_SPRITES)
    {
        struct Sprite *sprite = &gSprites[spriteId];

        sprite->coordOffsetEnabled = TRUE;
        sprite->data[2] = gFieldEffectArguments[2];
        sprite->data[3] = -1;
        sprite->data[6] = -1;
        sprite->data[7] = -1;

        if (createOverlay)
            CreateSurfablePokemonOverlay(surfMonIndex, isShiny);
    }

    FieldEffectActiveListRemove(FLDEFF_SURF_BLOB);
    return spriteId;
}

static void CreateSurfablePokemonOverlay(u16 surfMonIndex, bool8 isShiny)
{
    u8 spriteId;
    u8 subpriority = gSprites[gPlayerAvatar.spriteId].subpriority - 1;

    if (isShiny)
    {
        spriteId = CreateSpriteAtEnd(
            &gSurfablePokemonOverlayShinySprites[surfMonIndex],
            gFieldEffectArguments[0],
            gFieldEffectArguments[1],
            subpriority);
    }
    else
    {
        spriteId = CreateSpriteAtEnd(
            &gSurfablePokemonOverlaySprites[surfMonIndex],
            gFieldEffectArguments[0],
            gFieldEffectArguments[1],
            subpriority);
    }

    if (spriteId != MAX_SPRITES)
    {
        struct Sprite *sprite = &gSprites[spriteId];

        sprite->coordOffsetEnabled = TRUE;
        sprite->data[2] = gFieldEffectArguments[2];
        sprite->data[3] = -1;
        sprite->data[6] = -1;
        sprite->data[7] = -1;
        sprite->oam.priority = 2;
        SetSurfBlob_BobState(spriteId, BOB_PLAYER_AND_MON);
    }
}

static void UpdateSurfablePokemonOverlay(struct Sprite *sprite)
{
    struct ObjectEvent *playerObj = &gObjectEvents[gPlayerAvatar.objectEventId];
    struct Sprite *playerSprite = &gSprites[playerObj->spriteId];

    SynchronizeSurfAnim(playerObj, sprite);
    SynchronizeSurfPosition(playerObj, sprite);

    if (VarGet(VAR_FREEZE_SURF_BLOB) == 0)
        UpdateSurfBobbingEffect(playerObj, playerSprite, sprite);

    sprite->subpriority = playerSprite->subpriority - 1;
    sprite->invisible = playerSprite->invisible;

    if (playerSprite->animNum < MOVEMENT_ACTION_DELAY_16)
    {
        sprite->x = playerSprite->x;
        sprite->y = playerSprite->y + 8;
        sprite->y2 = playerSprite->y2;
    }

    if (!(gPlayerAvatar.flags & PLAYER_AVATAR_FLAG_SURFING))
        DestroySprite(sprite);
}
