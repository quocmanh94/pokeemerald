#include "global.h"
#include "event_data.h"
#include "give_gift_ribbon_to_party.h"
#include "pokemon.h"

// Three of the unused ribbon bits remain available for gift ribbons.
#define UNUSED_GIFT_RIBBONS_COUNT 3

static const u8 sGiftRibbonsMonDataIds[GIFT_RIBBONS_COUNT - 4] =
{
    MON_DATA_MARINE_RIBBON, MON_DATA_LAND_RIBBON, MON_DATA_SKY_RIBBON,
    MON_DATA_COUNTRY_RIBBON, MON_DATA_NATIONAL_RIBBON, MON_DATA_EARTH_RIBBON,
    MON_DATA_WORLD_RIBBON
};

void GiveGiftRibbonToParty(u8 index, u8 ribbonId)
{
    s32 i;
    bool32 gotRibbon = FALSE;
    u8 data = 1;

    if (index < ARRAY_COUNT(sGiftRibbonsMonDataIds) + UNUSED_GIFT_RIBBONS_COUNT
        && ribbonId <= MAX_GIFT_RIBBON)
    {
        gSaveBlock1Ptr->giftRibbons[index] = ribbonId;
        for (i = 0; i < PARTY_SIZE; i++)
        {
            struct Pokemon *mon = &gPlayerParty[i];

            if (GetMonData(mon, MON_DATA_SPECIES) != 0 && GetMonData(mon, MON_DATA_SANITY_IS_EGG) == 0)
            {
                if (index < ARRAY_COUNT(sGiftRibbonsMonDataIds))
                {
                    SetMonData(mon, sGiftRibbonsMonDataIds[index], &data);
                }
                else
                {
                    u8 unusedRibbons = GetMonData(mon, MON_DATA_UNUSED_RIBBONS);
                    unusedRibbons |= 1 << (index - ARRAY_COUNT(sGiftRibbonsMonDataIds));
                    SetMonData(mon, MON_DATA_UNUSED_RIBBONS, &unusedRibbons);
                }
                gotRibbon = TRUE;
            }
        }
        if (gotRibbon)
            FlagSet(FLAG_SYS_RIBBON_GET);
    }
}
