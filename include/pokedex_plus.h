#ifndef GUARD_POKEDEX_PLUS_H
#define GUARD_POKEDEX_PLUS_H

extern u8 gUnusedPokedexU8;
extern void (*gPokedexVBlankCB)(void);

void CB2_OpenPokedexPlus(void);
void Task_DisplayCaughtMonDexPagePlus(u8);

#endif // GUARD_POKEDEX_PLUS_H
