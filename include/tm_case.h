#ifndef GUARD_TM_CASE_H
#define GUARD_TM_CASE_H

enum TmCaseType
{
    TMCASE_FROMFIELD,
};

void InitTMCase(u8 a0, void (* a1)(void), u8 a2);
void CB2_ReturnToTMCaseFromPartyMenu(void);

#endif //GUARD_TM_CASE_H
