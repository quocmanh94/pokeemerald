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

static bool32 IsStringWithinGroup(const u8 *string, const u8 *first, const u8 *last)
{
    u32 address = (u32)string;
    u32 firstAddress = (u32)first;
    u32 lastAddress = (u32)last;

    if (firstAddress > lastAddress)
    {
        u32 temp = firstAddress;

        firstAddress = lastAddress;
        lastAddress = temp;
    }

    return address >= firstAddress && address <= lastAddress;
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
    u32 i;

    for (i = 0; i < gLocalizationPokedexCategoryCount; i++)
    {
        if (string == gPokedexEntries[i].categoryName)
            return gLocalizationPokedexCategoriesEnglish[i];
    }

    return NULL;
}

const u8 *GetLocalizedString(const u8 *string)
{
    const u8 *translation;

    if (gSaveBlock2Ptr == NULL || gSaveBlock2Ptr->optionsLanguage == OPTIONS_LANGUAGE_VIETNAMESE)
        return string;

    translation = FindDirectTranslation(string);
    if (translation == NULL)
        translation = FindIndirectTranslation(string);
    if (translation == NULL)
        translation = FindPokedexCategoryTranslation(string);

    return translation != NULL ? translation : string;
}
