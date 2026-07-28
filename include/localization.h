#ifndef GUARD_LOCALIZATION_H
#define GUARD_LOCALIZATION_H

struct LocalizationDirectPair
{
    const u8 *vietnamese;
    const u8 *english;
};

struct LocalizationDirectGroup
{
    const struct LocalizationDirectPair *pairs;
    u16 count;
    u16 padding;
};

struct LocalizationIndirectPair
{
    const u8 *const *vietnamese;
    const u8 *english;
};

struct LocalizationIndirectGroup
{
    const struct LocalizationIndirectPair *pairs;
    u16 count;
    u16 padding;
};

const u8 *GetLocalizedString(const u8 *string);

#endif // GUARD_LOCALIZATION_H
