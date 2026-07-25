#ifndef GUARD_WILD_ENCOUNTER_H
#define GUARD_WILD_ENCOUNTER_H

#include "constants/wild_encounter.h"

struct WildPokemon
{
    u8 minLevel;
    u8 maxLevel;
    u16 species;
};

struct WildPokemonInfo
{
    u8 encounterRate;
    const struct WildPokemon *wildPokemon;
};

enum WildEncounterArea
{
    WILD_AREA_LAND,
    WILD_AREA_WATER,
    WILD_AREA_ROCKS,
    WILD_AREA_FISHING,
};

enum WildEncounterTime
{
    WILD_TIME_MORNING,
    WILD_TIME_DAY,
    WILD_TIME_EVENING,
    WILD_TIME_NIGHT,
    WILD_TIME_COUNT,
};

struct WildPokemonHeader
{
    u8 mapGroup;
    u8 mapNum;
    const struct WildPokemonInfo *landMonsInfo;
    const struct WildPokemonInfo *waterMonsInfo;
    const struct WildPokemonInfo *rockSmashMonsInfo;
    const struct WildPokemonInfo *fishingMonsInfo;
};

struct TimeBasedWildPokemonHeader
{
    u8 mapGroup;
    u8 mapNum;
    u8 time;
    u8 area;
    const struct WildPokemonInfo *monsInfo;
};

extern const struct WildPokemonHeader gWildMonHeaders[];
extern const struct TimeBasedWildPokemonHeader gTimeBasedWildMonHeaders[];
extern bool8 gIsFishingEncounter;

void DisableWildEncounters(bool8 disabled);
bool8 StandardWildEncounter(u16 curMetatileBehavior, u16 prevMetatileBehavior);
bool8 SweetScentWildEncounter(void);
bool8 DoesCurrentMapHaveFishingMons(void);
void FishingWildEncounter(u8 rod);
u16 GetLocalWildMon(bool8 *isWaterMon);
u16 GetLocalWaterMon(void);
bool8 UpdateRepelCounter(void);
u8 GetWildEncounterTime(void);
const struct WildPokemonInfo *GetWildPokemonInfoForTime(const struct WildPokemonHeader *header, u8 area, u8 time);

#endif // GUARD_WILD_ENCOUNTER_H
