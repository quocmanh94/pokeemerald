#include "global.h"
#include "localization.h"
#include "pokedex.h"

extern const struct LocalizationDirectGroup gLocalizationAsmGroups[];
extern const struct LocalizationDirectGroup gLocalizationAsmGroupsEnd[];
extern const struct LocalizationIndirectGroup gLocalizationCGroups[];
extern const u32 gLocalizationCGroupCount;
extern const u8 *const gLocalizationPokedexCategoriesEnglish[];
extern const u32 gLocalizationPokedexCategoryCount;
extern const struct PokedexEntry gPokedexEntries[];

// Each group lists strings in source order, which is also their address order in ROM.
static bool32 IsStringWithinGroup(const u8 *string, const u8 *first, const u8 *last)
{
    return string >= first && string <= last;
}

static const u8 *FindDirectTranslation(const u8 *string)
{
    const struct LocalizationDirectGroup *group;

    for (group = gLocalizationAsmGroups; group < gLocalizationAsmGroupsEnd; group++)
    {
        const struct LocalizationDirectPair *pairs = group->pairs;
        u32 i;

        if (group->count == 0
         || !IsStringWithinGroup(string, pairs[0].vietnamese, pairs[group->count - 1].vietnamese))
            continue;

        for (i = 0; i < group->count; i++)
        {
            if (string == pairs[i].vietnamese)
                return pairs[i].english;
        }
    }

    return NULL;
}

static const u8 *FindIndirectTranslation(const u8 *string)
{
    u32 groupIndex;

    for (groupIndex = 0; groupIndex < gLocalizationCGroupCount; groupIndex++)
    {
        const struct LocalizationIndirectGroup *group = &gLocalizationCGroups[groupIndex];
        const struct LocalizationIndirectPair *pairs = group->pairs;
        const u8 *first;
        const u8 *last;
        u32 i;

        if (group->count == 0)
            continue;

        first = *pairs[0].vietnamese;
        last = *pairs[group->count - 1].vietnamese;
        if (!IsStringWithinGroup(string, first, last))
            continue;

        for (i = 0; i < group->count; i++)
        {
            if (string == *pairs[i].vietnamese)
                return pairs[i].english;
        }
    }

    return NULL;
}

static const u8 *FindPokedexCategoryTranslation(const u8 *string)
{
    u32 offset = string - (const u8 *)gPokedexEntries;
    u32 i = offset / sizeof(struct PokedexEntry);

    if (string < (const u8 *)gPokedexEntries
     || i >= gLocalizationPokedexCategoryCount
     || string != gPokedexEntries[i].categoryName)
        return NULL;

    return gLocalizationPokedexCategoriesEnglish[i];
}

const u8 *GetLocalizedString(const u8 *string)
{
    const u8 *translation;

    // Strings built in RAM (gStringVar4 and friends) are never in the tables.
    if (gSaveBlock2Ptr == NULL || gSaveBlock2Ptr->optionsLanguage == OPTIONS_LANGUAGE_VIETNAMESE
     || (u32)string < ROM_START)
        return string;

    translation = FindDirectTranslation(string);
    if (translation == NULL)
        translation = FindIndirectTranslation(string);
    if (translation == NULL)
        translation = FindPokedexCategoryTranslation(string);

    return translation != NULL ? translation : string;
}
