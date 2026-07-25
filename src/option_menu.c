#include "global.h"
#include "option_menu.h"
#include "bg.h"
#include "event_data.h"
#include "gpu_regs.h"
#include "international_string_util.h"
#include "list_menu.h"
#include "main.h"
#include "malloc.h"
#include "menu.h"
#include "palette.h"
#include "scanline_effect.h"
#include "sound.h"
#include "sprite.h"
#include "strings.h"
#include "task.h"
#include "text.h"
#include "text_window.h"
#include "window.h"
#include "gba/m4a_internal.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "constants/vars.h"

#define OPTIONS_ON_SCREEN 5
#define OPTION_ROW_HEIGHT 16
#define TAG_SCROLL_ARROW 110

enum
{
    PAGE_GENERAL,
    PAGE_BATTLE,
    PAGE_GAMEPLAY,
    PAGE_COUNT,
};

enum
{
    OPTION_TEXT_SPEED,
    OPTION_BATTLE_SCENE,
    OPTION_BATTLE_STYLE,
    OPTION_SOUND,
    OPTION_BUTTON_MODE,
    OPTION_FRAME_TYPE,
    OPTION_DIFFICULTY,
    OPTION_POKEMON_FOLLOWERS,
    OPTION_POKEDEX_THEME,
    OPTION_BATTLE_BAR_SPEED,
    OPTION_TYPE_EFFECTIVENESS,
    OPTION_CATCH_AND_SWAP,
    OPTION_ABILITY_POPUPS,
    OPTION_PUSH_B_TO_RUN,
    OPTION_MATCH_CALLS,
    OPTION_MODERN_SMALL_MECHANICS,
    OPTION_MID_BATTLE_EVOLUTION,
    OPTION_SAVE,
    OPTION_COUNT,
};

enum
{
    DIFFICULTY_SELECTION_EASY,
    DIFFICULTY_SELECTION_NORMAL,
    DIFFICULTY_SELECTION_HARD,
};

enum
{
    WIN_HEADER,
    WIN_OPTIONS,
    WIN_DESCRIPTION,
};

struct OptionMenuItem
{
    const u8 *name;
    u8 (*processInput)(u8 selection);
    void (*drawChoices)(u8 selection, u8 y);
    const u8 *const *descriptions;
    u8 descriptionCount;
};

struct OptionMenuPage
{
    const u8 *title;
    const u8 *previousTitle;
    const u8 *nextTitle;
    const u8 *items;
    u8 itemCount;
};

struct OptionMenu
{
    u8 page;
    u8 selections[OPTION_COUNT];
    u8 cursors[PAGE_COUNT];
    u16 scrollOffsets[PAGE_COUNT];
    u8 arrowTaskId;
};

static void Task_OptionMenuFadeIn(u8 taskId);
static void Task_OptionMenuProcessInput(u8 taskId);
static void Task_OptionMenuSave(u8 taskId);
static void Task_OptionMenuFadeOut(u8 taskId);
static void ChangePage(s8 direction);
static void MoveMenuCursor(s8 direction);
static void HighlightOptionMenuItem(void);
static void UpdateScrollArrows(void);
static u8 TextSpeed_ProcessInput(u8 selection);
static void TextSpeed_DrawChoices(u8 selection, u8 y);
static u8 BattleScene_ProcessInput(u8 selection);
static void BattleScene_DrawChoices(u8 selection, u8 y);
static u8 BattleStyle_ProcessInput(u8 selection);
static void BattleStyle_DrawChoices(u8 selection, u8 y);
static u8 Sound_ProcessInput(u8 selection);
static void Sound_DrawChoices(u8 selection, u8 y);
static u8 FrameType_ProcessInput(u8 selection);
static void FrameType_DrawChoices(u8 selection, u8 y);
static u8 ButtonMode_ProcessInput(u8 selection);
static void ButtonMode_DrawChoices(u8 selection, u8 y);
static u8 Toggle_ProcessInput(u8 selection);
static u8 Difficulty_ProcessInput(u8 selection);
static void DrawTwoChoices(const u8 *left, const u8 *right, u8 selection, u8 y);
static void OnOff_DrawChoices(u8 selection, u8 y);
static void Difficulty_DrawChoices(u8 selection, u8 y);
static void PokedexTheme_DrawChoices(u8 selection, u8 y);
static void BattleBarSpeed_DrawChoices(u8 selection, u8 y);
static void MatchCalls_DrawChoices(u8 selection, u8 y);
static void DrawHeaderText(void);
static void DrawVisibleOptions(void);
static void DrawDescriptionText(void);
static void DrawBgWindowFrames(void);

EWRAM_DATA static struct OptionMenu *sOptions = NULL;

static const u16 sOptionMenuText_Pal[] = INCGFX_U16("graphics/interface/option_menu_text.pal", ".gbapal");
// note: this is only used in the Japanese release
static const u8 sEqualSignGfx[] = INCGFX_U8("graphics/interface/option_menu_equals_sign.png", ".4bpp");

static const u8 sText_PageGeneral[] = _("GENERAL");
static const u8 sText_PageBattle[] = _("BATTLE");
static const u8 sText_PageGameplay[] = _("GAMEPLAY");
static const u8 sText_LButton[] = _("{L_BUTTON}");
static const u8 sText_RButton[] = _("{R_BUTTON}");

static const u8 sText_Difficulty[] = _("DIFFICULTY");
static const u8 sText_PokemonFollowers[] = _("FOLLOWERS");
static const u8 sText_PokedexTheme[] = _("POKEDEX THEME");
static const u8 sText_BattleBarSpeed[] = _("BATTLE BARS");
static const u8 sText_TypeEffectiveness[] = _("TYPE MATCHUPS");
static const u8 sText_CatchAndSwap[] = _("CATCH & SWAP");
static const u8 sText_AbilityPopups[] = _("ABILITY POPUPS");
static const u8 sText_PushBToRun[] = _("PUSH B TO RUN");
static const u8 sText_MatchCalls[] = _("MATCH CALLS");
static const u8 sText_ModernSmallMechanics[] = _("MODERN MECHANICS");
static const u8 sText_MidBattleEvolution[] = _("MID-BATTLE EVO");
static const u8 sText_On[] = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}ON");
static const u8 sText_Off[] = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}OFF");
static const u8 sText_Easy[] = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}EASY");
static const u8 sText_Normal[] = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}NORMAL");
static const u8 sText_Hard[] = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}HARD");
static const u8 sText_Light[] = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}LIGHT");
static const u8 sText_Dark[] = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}DARK");
static const u8 sText_Fast[] = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}FAST");
static const u8 sText_Rematch[] = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}REMATCH");
static const u8 sText_All[] = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}ALL");

static const u8 sText_DescTextSpeedSlow[] = _("Display text at a relaxed speed.");
static const u8 sText_DescTextSpeedMid[] = _("Display text at the standard speed.");
static const u8 sText_DescTextSpeedFast[] = _("Display text as quickly as possible.");
static const u8 sText_DescBattleSceneOn[] = _("Show Pokemon battle animations.");
static const u8 sText_DescBattleSceneOff[] = _("Skip Pokemon battle animations.");
static const u8 sText_DescBattleStyleShift[] = _("Offer a switch after an opposing\nPokemon faints.");
static const u8 sText_DescBattleStyleSet[] = _("Do not offer a free switch after an\nopposing Pokemon faints.");
static const u8 sText_DescSoundMono[] = _("Play the same audio through both\nspeakers.");
static const u8 sText_DescSoundStereo[] = _("Use separate left and right audio\nchannels.");
static const u8 sText_DescButtonNormal[] = _("Use the standard button controls.");
static const u8 sText_DescButtonLR[] = _("Use L and R as left and right on\nsupported screens.");
static const u8 sText_DescButtonLEqualsA[] = _("Use the L Button as another A Button.");
static const u8 sText_DescFrameType[] = _("Choose the border used for text boxes.");
static const u8 sText_DescDifficultyEasy[] = _("Lower opposing Trainer Pokemon levels.");
static const u8 sText_DescDifficultyNormal[] = _("Use the standard Trainer Pokemon levels.");
static const u8 sText_DescDifficultyHard[] = _("Raise opposing Trainer Pokemon levels.");
static const u8 sText_DescFollowersOn[] = _("Show the first usable Pokemon behind\nthe player.");
static const u8 sText_DescFollowersOff[] = _("Keep the following Pokemon hidden.");
static const u8 sText_DescPokedexLight[] = _("Use the light HGSS Pokedex palette.");
static const u8 sText_DescPokedexDark[] = _("Use the dark HGSS Pokedex palette.");
static const u8 sText_DescBattleBarsFast[] = _("Use faster HP bar movement.");
static const u8 sText_DescBattleBarsNormal[] = _("Use the original HP bar movement.");
static const u8 sText_DescTypeEffectivenessOn[] = _("Show move effectiveness before\nselecting a target.");
static const u8 sText_DescTypeEffectivenessOff[] = _("Show only the selected move's type.");
static const u8 sText_DescCatchAndSwapOn[] = _("Offer to swap a newly caught Pokemon\ninto a full party.");
static const u8 sText_DescCatchAndSwapOff[] = _("Send newly caught Pokemon to the PC\nwhen the party is full.");
static const u8 sText_DescAbilityPopupsOn[] = _("Show ability banners during battle.");
static const u8 sText_DescAbilityPopupsOff[] = _("Hide ability banners during battle.");
static const u8 sText_DescPushBToRunOn[] = _("Let B move the battle cursor to RUN.");
static const u8 sText_DescPushBToRunOff[] = _("Keep the normal B Button behavior.");
static const u8 sText_DescMatchCallsRematch[] = _("Allow overworld Match Calls only for\nrematch requests.");
static const u8 sText_DescMatchCallsAll[] = _("Allow all normal overworld Match Calls.");
static const u8 sText_DescModernSmallMechanicsOn[] = _("Use modern poison, Berry, and\noverworld ability mechanics.");
static const u8 sText_DescModernSmallMechanicsOff[] = _("Use the original Emerald small\nmechanics.");
static const u8 sText_DescMidBattleEvolutionOn[] = _("Allow eligible Pokemon to evolve\nduring battle.");
static const u8 sText_DescMidBattleEvolutionOff[] = _("Only check evolution after battle.");
static const u8 sText_DescSave[] = _("Save these settings and return.");

static const u8 *const sTextSpeedDescriptions[] =
{
    sText_DescTextSpeedSlow,
    sText_DescTextSpeedMid,
    sText_DescTextSpeedFast,
};

static const u8 *const sBattleSceneDescriptions[] =
{
    sText_DescBattleSceneOn,
    sText_DescBattleSceneOff,
};

static const u8 *const sBattleStyleDescriptions[] =
{
    sText_DescBattleStyleShift,
    sText_DescBattleStyleSet,
};

static const u8 *const sSoundDescriptions[] =
{
    sText_DescSoundMono,
    sText_DescSoundStereo,
};

static const u8 *const sButtonModeDescriptions[] =
{
    sText_DescButtonNormal,
    sText_DescButtonLR,
    sText_DescButtonLEqualsA,
};

static const u8 *const sFrameTypeDescriptions[] =
{
    sText_DescFrameType,
};

static const u8 *const sDifficultyDescriptions[] =
{
    sText_DescDifficultyEasy,
    sText_DescDifficultyNormal,
    sText_DescDifficultyHard,
};

static const u8 *const sFollowerDescriptions[] =
{
    sText_DescFollowersOn,
    sText_DescFollowersOff,
};

static const u8 *const sPokedexThemeDescriptions[] =
{
    sText_DescPokedexLight,
    sText_DescPokedexDark,
};

static const u8 *const sBattleBarSpeedDescriptions[] =
{
    sText_DescBattleBarsFast,
    sText_DescBattleBarsNormal,
};

static const u8 *const sTypeEffectivenessDescriptions[] =
{
    sText_DescTypeEffectivenessOn,
    sText_DescTypeEffectivenessOff,
};

static const u8 *const sCatchAndSwapDescriptions[] =
{
    sText_DescCatchAndSwapOn,
    sText_DescCatchAndSwapOff,
};

static const u8 *const sAbilityPopupDescriptions[] =
{
    sText_DescAbilityPopupsOn,
    sText_DescAbilityPopupsOff,
};

static const u8 *const sPushBToRunDescriptions[] =
{
    sText_DescPushBToRunOn,
    sText_DescPushBToRunOff,
};

static const u8 *const sMatchCallDescriptions[] =
{
    sText_DescMatchCallsRematch,
    sText_DescMatchCallsAll,
};

static const u8 *const sModernSmallMechanicsDescriptions[] =
{
    sText_DescModernSmallMechanicsOn,
    sText_DescModernSmallMechanicsOff,
};

static const u8 *const sMidBattleEvolutionDescriptions[] =
{
    sText_DescMidBattleEvolutionOn,
    sText_DescMidBattleEvolutionOff,
};

static const u8 sGeneralPageItems[] =
{
    OPTION_TEXT_SPEED,
    OPTION_SOUND,
    OPTION_BUTTON_MODE,
    OPTION_FRAME_TYPE,
    OPTION_POKEDEX_THEME,
    OPTION_SAVE,
};

static const u8 sBattlePageItems[] =
{
    OPTION_BATTLE_SCENE,
    OPTION_BATTLE_STYLE,
    OPTION_DIFFICULTY,
    OPTION_BATTLE_BAR_SPEED,
    OPTION_TYPE_EFFECTIVENESS,
    OPTION_ABILITY_POPUPS,
    OPTION_SAVE,
};

static const u8 sGameplayPageItems[] =
{
    OPTION_POKEMON_FOLLOWERS,
    OPTION_CATCH_AND_SWAP,
    OPTION_PUSH_B_TO_RUN,
    OPTION_MATCH_CALLS,
    OPTION_MODERN_SMALL_MECHANICS,
    OPTION_MID_BATTLE_EVOLUTION,
    OPTION_SAVE,
};

static const struct OptionMenuItem sOptionMenuItems[OPTION_COUNT] =
{
    [OPTION_TEXT_SPEED] =
    {
        .name = gText_TextSpeed,
        .processInput = TextSpeed_ProcessInput,
        .drawChoices = TextSpeed_DrawChoices,
        .descriptions = sTextSpeedDescriptions,
        .descriptionCount = ARRAY_COUNT(sTextSpeedDescriptions),
    },
    [OPTION_BATTLE_SCENE] =
    {
        .name = gText_BattleScene,
        .processInput = BattleScene_ProcessInput,
        .drawChoices = BattleScene_DrawChoices,
        .descriptions = sBattleSceneDescriptions,
        .descriptionCount = ARRAY_COUNT(sBattleSceneDescriptions),
    },
    [OPTION_BATTLE_STYLE] =
    {
        .name = gText_BattleStyle,
        .processInput = BattleStyle_ProcessInput,
        .drawChoices = BattleStyle_DrawChoices,
        .descriptions = sBattleStyleDescriptions,
        .descriptionCount = ARRAY_COUNT(sBattleStyleDescriptions),
    },
    [OPTION_SOUND] =
    {
        .name = gText_Sound,
        .processInput = Sound_ProcessInput,
        .drawChoices = Sound_DrawChoices,
        .descriptions = sSoundDescriptions,
        .descriptionCount = ARRAY_COUNT(sSoundDescriptions),
    },
    [OPTION_BUTTON_MODE] =
    {
        .name = gText_ButtonMode,
        .processInput = ButtonMode_ProcessInput,
        .drawChoices = ButtonMode_DrawChoices,
        .descriptions = sButtonModeDescriptions,
        .descriptionCount = ARRAY_COUNT(sButtonModeDescriptions),
    },
    [OPTION_FRAME_TYPE] =
    {
        .name = gText_Frame,
        .processInput = FrameType_ProcessInput,
        .drawChoices = FrameType_DrawChoices,
        .descriptions = sFrameTypeDescriptions,
        .descriptionCount = ARRAY_COUNT(sFrameTypeDescriptions),
    },
    [OPTION_DIFFICULTY] =
    {
        .name = sText_Difficulty,
        .processInput = Difficulty_ProcessInput,
        .drawChoices = Difficulty_DrawChoices,
        .descriptions = sDifficultyDescriptions,
        .descriptionCount = ARRAY_COUNT(sDifficultyDescriptions),
    },
    [OPTION_POKEMON_FOLLOWERS] =
    {
        .name = sText_PokemonFollowers,
        .processInput = Toggle_ProcessInput,
        .drawChoices = OnOff_DrawChoices,
        .descriptions = sFollowerDescriptions,
        .descriptionCount = ARRAY_COUNT(sFollowerDescriptions),
    },
    [OPTION_POKEDEX_THEME] =
    {
        .name = sText_PokedexTheme,
        .processInput = Toggle_ProcessInput,
        .drawChoices = PokedexTheme_DrawChoices,
        .descriptions = sPokedexThemeDescriptions,
        .descriptionCount = ARRAY_COUNT(sPokedexThemeDescriptions),
    },
    [OPTION_BATTLE_BAR_SPEED] =
    {
        .name = sText_BattleBarSpeed,
        .processInput = Toggle_ProcessInput,
        .drawChoices = BattleBarSpeed_DrawChoices,
        .descriptions = sBattleBarSpeedDescriptions,
        .descriptionCount = ARRAY_COUNT(sBattleBarSpeedDescriptions),
    },
    [OPTION_TYPE_EFFECTIVENESS] =
    {
        .name = sText_TypeEffectiveness,
        .processInput = Toggle_ProcessInput,
        .drawChoices = OnOff_DrawChoices,
        .descriptions = sTypeEffectivenessDescriptions,
        .descriptionCount = ARRAY_COUNT(sTypeEffectivenessDescriptions),
    },
    [OPTION_CATCH_AND_SWAP] =
    {
        .name = sText_CatchAndSwap,
        .processInput = Toggle_ProcessInput,
        .drawChoices = OnOff_DrawChoices,
        .descriptions = sCatchAndSwapDescriptions,
        .descriptionCount = ARRAY_COUNT(sCatchAndSwapDescriptions),
    },
    [OPTION_ABILITY_POPUPS] =
    {
        .name = sText_AbilityPopups,
        .processInput = Toggle_ProcessInput,
        .drawChoices = OnOff_DrawChoices,
        .descriptions = sAbilityPopupDescriptions,
        .descriptionCount = ARRAY_COUNT(sAbilityPopupDescriptions),
    },
    [OPTION_PUSH_B_TO_RUN] =
    {
        .name = sText_PushBToRun,
        .processInput = Toggle_ProcessInput,
        .drawChoices = OnOff_DrawChoices,
        .descriptions = sPushBToRunDescriptions,
        .descriptionCount = ARRAY_COUNT(sPushBToRunDescriptions),
    },
    [OPTION_MATCH_CALLS] =
    {
        .name = sText_MatchCalls,
        .processInput = Toggle_ProcessInput,
        .drawChoices = MatchCalls_DrawChoices,
        .descriptions = sMatchCallDescriptions,
        .descriptionCount = ARRAY_COUNT(sMatchCallDescriptions),
    },
    [OPTION_MODERN_SMALL_MECHANICS] =
    {
        .name = sText_ModernSmallMechanics,
        .processInput = Toggle_ProcessInput,
        .drawChoices = OnOff_DrawChoices,
        .descriptions = sModernSmallMechanicsDescriptions,
        .descriptionCount = ARRAY_COUNT(sModernSmallMechanicsDescriptions),
    },
    [OPTION_MID_BATTLE_EVOLUTION] =
    {
        .name = sText_MidBattleEvolution,
        .processInput = Toggle_ProcessInput,
        .drawChoices = OnOff_DrawChoices,
        .descriptions = sMidBattleEvolutionDescriptions,
        .descriptionCount = ARRAY_COUNT(sMidBattleEvolutionDescriptions),
    },
    [OPTION_SAVE] =
    {
        .name = gText_OptionMenuCancel,
    },
};

static const struct OptionMenuPage sOptionMenuPages[PAGE_COUNT] =
{
    [PAGE_GENERAL] =
    {
        .title = sText_PageGeneral,
        .nextTitle = sText_PageBattle,
        .items = sGeneralPageItems,
        .itemCount = ARRAY_COUNT(sGeneralPageItems),
    },
    [PAGE_BATTLE] =
    {
        .title = sText_PageBattle,
        .previousTitle = sText_PageGeneral,
        .nextTitle = sText_PageGameplay,
        .items = sBattlePageItems,
        .itemCount = ARRAY_COUNT(sBattlePageItems),
    },
    [PAGE_GAMEPLAY] =
    {
        .title = sText_PageGameplay,
        .previousTitle = sText_PageBattle,
        .items = sGameplayPageItems,
        .itemCount = ARRAY_COUNT(sGameplayPageItems),
    },
};

static const struct WindowTemplate sOptionMenuWinTemplates[] =
{
    [WIN_HEADER] = {
        .bg = 1,
        .tilemapLeft = 2,
        .tilemapTop = 1,
        .width = 26,
        .height = 2,
        .paletteNum = 1,
        .baseBlock = 2
    },
    [WIN_OPTIONS] = {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 5,
        .width = 26,
        .height = 10,
        .paletteNum = 1,
        .baseBlock = 0x36
    },
    [WIN_DESCRIPTION] = {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 15,
        .width = 26,
        .height = 4,
        .paletteNum = 1,
        .baseBlock = 0x13A
    },
    DUMMY_WIN_TEMPLATE
};

static const struct BgTemplate sOptionMenuBgTemplates[] =
{
    {
        .bg = 1,
        .charBaseIndex = 1,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 0,
        .charBaseIndex = 1,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    }
};

static const u16 sOptionMenuBg_Pal[] = {RGB(17, 18, 31)};

static void MainCB2(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void VBlankCB(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static const struct OptionMenuPage *GetCurrentPage(void)
{
    return &sOptionMenuPages[sOptions->page];
}

static u8 GetCurrentItemId(void)
{
    const struct OptionMenuPage *page = GetCurrentPage();

    return page->items[sOptions->cursors[sOptions->page]];
}

void CB2_InitOptionMenu(void)
{
    switch (gMain.state)
    {
    default:
    case 0:
        SetVBlankCallback(NULL);
        gMain.state++;
        break;
    case 1:
        DmaClearLarge16(3, (void *)(VRAM), VRAM_SIZE, 0x1000);
        DmaClear32(3, OAM, OAM_SIZE);
        DmaClear16(3, PLTT, PLTT_SIZE);
        SetGpuReg(REG_OFFSET_DISPCNT, 0);
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(0, sOptionMenuBgTemplates, ARRAY_COUNT(sOptionMenuBgTemplates));
        ChangeBgX(0, 0, BG_COORD_SET);
        ChangeBgY(0, 0, BG_COORD_SET);
        ChangeBgX(1, 0, BG_COORD_SET);
        ChangeBgY(1, 0, BG_COORD_SET);
        ChangeBgX(2, 0, BG_COORD_SET);
        ChangeBgY(2, 0, BG_COORD_SET);
        ChangeBgX(3, 0, BG_COORD_SET);
        ChangeBgY(3, 0, BG_COORD_SET);
        InitWindows(sOptionMenuWinTemplates);
        DeactivateAllTextPrinters();
        SetGpuReg(REG_OFFSET_WIN0H, 0);
        SetGpuReg(REG_OFFSET_WIN0V, 0);
        SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG0);
        SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG0 | WINOUT_WIN01_BG1 | WINOUT_WIN01_CLR);
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG0 | BLDCNT_EFFECT_DARKEN);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetGpuReg(REG_OFFSET_BLDY, 4);
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON | DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
        ShowBg(0);
        ShowBg(1);
        gMain.state++;
        break;
    case 2:
        ResetPaletteFade();
        ScanlineEffect_Stop();
        ResetTasks();
        ResetSpriteData();
        sOptions = AllocZeroed(sizeof(*sOptions));
        sOptions->arrowTaskId = TASK_NONE;
        sOptions->selections[OPTION_TEXT_SPEED] = gSaveBlock2Ptr->optionsTextSpeed;
        sOptions->selections[OPTION_BATTLE_SCENE] = gSaveBlock2Ptr->optionsBattleSceneOff;
        sOptions->selections[OPTION_BATTLE_STYLE] = gSaveBlock2Ptr->optionsBattleStyle;
        sOptions->selections[OPTION_SOUND] = gSaveBlock2Ptr->optionsSound;
        sOptions->selections[OPTION_BUTTON_MODE] = gSaveBlock2Ptr->optionsButtonMode;
        sOptions->selections[OPTION_FRAME_TYPE] = gSaveBlock2Ptr->optionsWindowFrameType;
        switch (VarGet(VAR_DIFFICULTY))
        {
        case DIFFICULTY_EASY:
            sOptions->selections[OPTION_DIFFICULTY] = DIFFICULTY_SELECTION_EASY;
            break;
        case DIFFICULTY_HARD:
            sOptions->selections[OPTION_DIFFICULTY] = DIFFICULTY_SELECTION_HARD;
            break;
        default:
            sOptions->selections[OPTION_DIFFICULTY] = DIFFICULTY_SELECTION_NORMAL;
            break;
        }
        sOptions->selections[OPTION_POKEMON_FOLLOWERS] = gSaveBlock2Ptr->optionsPokemonFollowersOff;
        sOptions->selections[OPTION_POKEDEX_THEME] = gSaveBlock2Ptr->optionsPokedexTheme;
        sOptions->selections[OPTION_BATTLE_BAR_SPEED] = gSaveBlock2Ptr->optionsBattleBarSpeed;
        sOptions->selections[OPTION_TYPE_EFFECTIVENESS] = gSaveBlock2Ptr->optionsTypeEffectivenessOff;
        sOptions->selections[OPTION_CATCH_AND_SWAP] = gSaveBlock2Ptr->optionsCatchAndSwapOff;
        sOptions->selections[OPTION_ABILITY_POPUPS] = gSaveBlock2Ptr->optionsAbilityPopupsOff;
        sOptions->selections[OPTION_PUSH_B_TO_RUN] = gSaveBlock2Ptr->optionsPushBToRunOff;
        sOptions->selections[OPTION_MATCH_CALLS] = gSaveBlock2Ptr->optionsMatchCalls;
        sOptions->selections[OPTION_MODERN_SMALL_MECHANICS] = gSaveBlock2Ptr->optionsModernSmallMechanicsOff;
        sOptions->selections[OPTION_MID_BATTLE_EVOLUTION] = gSaveBlock2Ptr->optionsMidBattleEvolutionOff;
        gMain.state++;
        break;
    case 3:
        LoadBgTiles(1, GetWindowFrameTilesPal(gSaveBlock2Ptr->optionsWindowFrameType)->tiles, 0x120, 0x1A2);
        gMain.state++;
        break;
    case 4:
        LoadPalette(sOptionMenuBg_Pal, BG_PLTT_ID(0), sizeof(sOptionMenuBg_Pal));
        LoadPalette(GetWindowFrameTilesPal(gSaveBlock2Ptr->optionsWindowFrameType)->pal, BG_PLTT_ID(7), PLTT_SIZE_4BPP);
        gMain.state++;
        break;
    case 5:
        LoadPalette(sOptionMenuText_Pal, BG_PLTT_ID(1), sizeof(sOptionMenuText_Pal));
        gMain.state++;
        break;
    case 6:
        PutWindowTilemap(WIN_HEADER);
        PutWindowTilemap(WIN_OPTIONS);
        PutWindowTilemap(WIN_DESCRIPTION);
        DrawHeaderText();
        DrawVisibleOptions();
        DrawDescriptionText();
        DrawBgWindowFrames();
        HighlightOptionMenuItem();
        gMain.state++;
        break;
    case 7:
    {
        u8 taskId = CreateTask(Task_OptionMenuFadeIn, 0);

        UpdateScrollArrows();
        CopyWindowToVram(WIN_HEADER, COPYWIN_FULL);
        CopyWindowToVram(WIN_OPTIONS, COPYWIN_FULL);
        CopyWindowToVram(WIN_DESCRIPTION, COPYWIN_FULL);
        gMain.state++;
        break;
    }
    case 8:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        SetVBlankCallback(VBlankCB);
        SetMainCallback2(MainCB2);
        return;
    }
}

static void Task_OptionMenuFadeIn(u8 taskId)
{
    if (!gPaletteFade.active)
        gTasks[taskId].func = Task_OptionMenuProcessInput;
}

static void Task_OptionMenuProcessInput(u8 taskId)
{
    u8 itemId = GetCurrentItemId();

    if (JOY_NEW(A_BUTTON))
    {
        if (itemId == OPTION_SAVE)
        {
            PlaySE(SE_SELECT);
            gTasks[taskId].func = Task_OptionMenuSave;
        }
    }
    else if (JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_SELECT);
        gTasks[taskId].func = Task_OptionMenuSave;
    }
    else if (JOY_NEW(L_BUTTON))
    {
        ChangePage(-1);
    }
    else if (JOY_NEW(R_BUTTON))
    {
        ChangePage(1);
    }
    else if (JOY_NEW(DPAD_UP))
    {
        MoveMenuCursor(-1);
    }
    else if (JOY_NEW(DPAD_DOWN))
    {
        MoveMenuCursor(1);
    }
    else if (itemId != OPTION_SAVE && sOptionMenuItems[itemId].processInput != NULL)
    {
        u8 previousOption = sOptions->selections[itemId];

        sOptions->selections[itemId] = sOptionMenuItems[itemId].processInput(previousOption);
        if (previousOption != sOptions->selections[itemId])
        {
            PlaySE(SE_SELECT);
            DrawVisibleOptions();
            DrawDescriptionText();
        }
    }
}

static void Task_OptionMenuSave(u8 taskId)
{
    gSaveBlock2Ptr->optionsTextSpeed = sOptions->selections[OPTION_TEXT_SPEED];
    gSaveBlock2Ptr->optionsBattleSceneOff = sOptions->selections[OPTION_BATTLE_SCENE];
    gSaveBlock2Ptr->optionsBattleStyle = sOptions->selections[OPTION_BATTLE_STYLE];
    gSaveBlock2Ptr->optionsSound = sOptions->selections[OPTION_SOUND];
    gSaveBlock2Ptr->optionsButtonMode = sOptions->selections[OPTION_BUTTON_MODE];
    gSaveBlock2Ptr->optionsWindowFrameType = sOptions->selections[OPTION_FRAME_TYPE];
    switch (sOptions->selections[OPTION_DIFFICULTY])
    {
    case DIFFICULTY_SELECTION_EASY:
        VarSet(VAR_DIFFICULTY, DIFFICULTY_EASY);
        break;
    case DIFFICULTY_SELECTION_HARD:
        VarSet(VAR_DIFFICULTY, DIFFICULTY_HARD);
        break;
    default:
        VarSet(VAR_DIFFICULTY, DIFFICULTY_NORMAL);
        break;
    }
    gSaveBlock2Ptr->optionsPokemonFollowersOff = sOptions->selections[OPTION_POKEMON_FOLLOWERS];
    gSaveBlock2Ptr->optionsPokedexTheme = sOptions->selections[OPTION_POKEDEX_THEME];
    gSaveBlock2Ptr->optionsBattleBarSpeed = sOptions->selections[OPTION_BATTLE_BAR_SPEED];
    gSaveBlock2Ptr->optionsTypeEffectivenessOff = sOptions->selections[OPTION_TYPE_EFFECTIVENESS];
    gSaveBlock2Ptr->optionsCatchAndSwapOff = sOptions->selections[OPTION_CATCH_AND_SWAP];
    gSaveBlock2Ptr->optionsAbilityPopupsOff = sOptions->selections[OPTION_ABILITY_POPUPS];
    gSaveBlock2Ptr->optionsPushBToRunOff = sOptions->selections[OPTION_PUSH_B_TO_RUN];
    gSaveBlock2Ptr->optionsMatchCalls = sOptions->selections[OPTION_MATCH_CALLS];
    gSaveBlock2Ptr->optionsModernSmallMechanicsOff = sOptions->selections[OPTION_MODERN_SMALL_MECHANICS];
    gSaveBlock2Ptr->optionsMidBattleEvolutionOff = sOptions->selections[OPTION_MID_BATTLE_EVOLUTION];

    if (sOptions->arrowTaskId != TASK_NONE)
    {
        RemoveScrollIndicatorArrowPair(sOptions->arrowTaskId);
        sOptions->arrowTaskId = TASK_NONE;
    }
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
    gTasks[taskId].func = Task_OptionMenuFadeOut;
}

static void Task_OptionMenuFadeOut(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        DestroyTask(taskId);
        FreeAllWindowBuffers();
        FREE_AND_SET_NULL(sOptions);
        SetMainCallback2(gMain.savedCallback);
    }
}

static void ChangePage(s8 direction)
{
    s8 page = sOptions->page + direction;

    if (page < 0 || page >= PAGE_COUNT)
        return;

    sOptions->page = page;
    PlaySE(SE_SELECT);
    DrawHeaderText();
    DrawVisibleOptions();
    DrawDescriptionText();
    HighlightOptionMenuItem();
    UpdateScrollArrows();
}

static void MoveMenuCursor(s8 direction)
{
    const struct OptionMenuPage *page = GetCurrentPage();
    u8 *cursor = &sOptions->cursors[sOptions->page];
    u16 *scrollOffset = &sOptions->scrollOffsets[sOptions->page];

    if (direction < 0)
    {
        if (*cursor == 0)
        {
            *cursor = page->itemCount - 1;
            *scrollOffset = page->itemCount > OPTIONS_ON_SCREEN ? page->itemCount - OPTIONS_ON_SCREEN : 0;
        }
        else
        {
            (*cursor)--;
            if (*cursor < *scrollOffset)
                *scrollOffset = *cursor;
        }
    }
    else
    {
        if (*cursor + 1 >= page->itemCount)
        {
            *cursor = 0;
            *scrollOffset = 0;
        }
        else
        {
            (*cursor)++;
            if (*cursor >= *scrollOffset + OPTIONS_ON_SCREEN)
                *scrollOffset = *cursor - OPTIONS_ON_SCREEN + 1;
        }
    }

    PlaySE(SE_SELECT);
    DrawVisibleOptions();
    DrawDescriptionText();
    HighlightOptionMenuItem();
}

static void HighlightOptionMenuItem(void)
{
    u8 visibleCursor = sOptions->cursors[sOptions->page] - sOptions->scrollOffsets[sOptions->page];

    SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(16, DISPLAY_WIDTH - 16));
    SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(visibleCursor * OPTION_ROW_HEIGHT + 40, visibleCursor * OPTION_ROW_HEIGHT + 56));
}

static void UpdateScrollArrows(void)
{
    const struct OptionMenuPage *page = GetCurrentPage();

    if (sOptions->arrowTaskId != TASK_NONE)
    {
        RemoveScrollIndicatorArrowPair(sOptions->arrowTaskId);
        sOptions->arrowTaskId = TASK_NONE;
    }

    if (page->itemCount > OPTIONS_ON_SCREEN)
    {
        sOptions->arrowTaskId = AddScrollIndicatorArrowPairParameterized(
            SCROLL_ARROW_UP,
            216,
            48,
            112,
            page->itemCount - OPTIONS_ON_SCREEN,
            TAG_SCROLL_ARROW,
            TAG_SCROLL_ARROW,
            &sOptions->scrollOffsets[sOptions->page]);
    }
}

static void DrawOptionMenuChoice(const u8 *text, u8 x, u8 y, u8 style)
{
    u8 dst[16];
    u16 i;

    for (i = 0; *text != EOS && i < ARRAY_COUNT(dst) - 1; i++)
        dst[i] = *(text++);

    if (style != 0)
    {
        dst[2] = TEXT_COLOR_RED;
        dst[5] = TEXT_COLOR_LIGHT_RED;
    }

    dst[i] = EOS;
    AddTextPrinterParameterized(WIN_OPTIONS, FONT_NORMAL, dst, x, y + 1, TEXT_SKIP_DRAW, NULL);
}

static u8 TextSpeed_ProcessInput(u8 selection)
{
    if (JOY_NEW(DPAD_RIGHT))
    {
        if (selection <= 1)
            selection++;
        else
            selection = 0;
    }
    if (JOY_NEW(DPAD_LEFT))
    {
        if (selection != 0)
            selection--;
        else
            selection = 2;
    }
    return selection;
}

static void TextSpeed_DrawChoices(u8 selection, u8 y)
{
    u8 styles[3] = {0};
    s32 widthSlow, widthMid, widthFast, xMid;

    styles[selection] = 1;
    DrawOptionMenuChoice(gText_TextSpeedSlow, 104, y, styles[0]);

    widthSlow = GetStringWidth(FONT_NORMAL, gText_TextSpeedSlow, 0);
    widthMid = GetStringWidth(FONT_NORMAL, gText_TextSpeedMid, 0);
    widthFast = GetStringWidth(FONT_NORMAL, gText_TextSpeedFast, 0);
    widthMid -= 94;
    xMid = (widthSlow - widthMid - widthFast) / 2 + 104;
    DrawOptionMenuChoice(gText_TextSpeedMid, xMid, y, styles[1]);
    DrawOptionMenuChoice(gText_TextSpeedFast, GetStringRightAlignXOffset(FONT_NORMAL, gText_TextSpeedFast, 198), y, styles[2]);
}

static u8 BattleScene_ProcessInput(u8 selection)
{
    if (JOY_NEW(DPAD_LEFT | DPAD_RIGHT))
        selection ^= 1;
    return selection;
}

static void BattleScene_DrawChoices(u8 selection, u8 y)
{
    u8 styles[2] = {0};

    styles[selection] = 1;
    DrawOptionMenuChoice(gText_BattleSceneOn, 104, y, styles[0]);
    DrawOptionMenuChoice(gText_BattleSceneOff, GetStringRightAlignXOffset(FONT_NORMAL, gText_BattleSceneOff, 198), y, styles[1]);
}

static u8 BattleStyle_ProcessInput(u8 selection)
{
    if (JOY_NEW(DPAD_LEFT | DPAD_RIGHT))
        selection ^= 1;
    return selection;
}

static void BattleStyle_DrawChoices(u8 selection, u8 y)
{
    u8 styles[2] = {0};

    styles[selection] = 1;
    DrawOptionMenuChoice(gText_BattleStyleShift, 104, y, styles[0]);
    DrawOptionMenuChoice(gText_BattleStyleSet, GetStringRightAlignXOffset(FONT_NORMAL, gText_BattleStyleSet, 198), y, styles[1]);
}

static u8 Sound_ProcessInput(u8 selection)
{
    if (JOY_NEW(DPAD_LEFT | DPAD_RIGHT))
    {
        selection ^= 1;
        SetPokemonCryStereo(selection);
    }
    return selection;
}

static void Sound_DrawChoices(u8 selection, u8 y)
{
    u8 styles[2] = {0};

    styles[selection] = 1;
    DrawOptionMenuChoice(gText_SoundMono, 104, y, styles[0]);
    DrawOptionMenuChoice(gText_SoundStereo, GetStringRightAlignXOffset(FONT_NORMAL, gText_SoundStereo, 198), y, styles[1]);
}

static u8 FrameType_ProcessInput(u8 selection)
{
    if (JOY_NEW(DPAD_RIGHT))
    {
        if (selection < WINDOW_FRAMES_COUNT - 1)
            selection++;
        else
            selection = 0;

        LoadBgTiles(1, GetWindowFrameTilesPal(selection)->tiles, 0x120, 0x1A2);
        LoadPalette(GetWindowFrameTilesPal(selection)->pal, BG_PLTT_ID(7), PLTT_SIZE_4BPP);
    }
    if (JOY_NEW(DPAD_LEFT))
    {
        if (selection != 0)
            selection--;
        else
            selection = WINDOW_FRAMES_COUNT - 1;

        LoadBgTiles(1, GetWindowFrameTilesPal(selection)->tiles, 0x120, 0x1A2);
        LoadPalette(GetWindowFrameTilesPal(selection)->pal, BG_PLTT_ID(7), PLTT_SIZE_4BPP);
    }
    return selection;
}

static void FrameType_DrawChoices(u8 selection, u8 y)
{
    u8 text[16];
    u8 n = selection + 1;
    u16 i;

    for (i = 0; gText_FrameTypeNumber[i] != EOS && i <= 5; i++)
        text[i] = gText_FrameTypeNumber[i];

    if (n / 10 != 0)
    {
        text[i++] = n / 10 + CHAR_0;
        text[i++] = n % 10 + CHAR_0;
    }
    else
    {
        text[i++] = n % 10 + CHAR_0;
        text[i++] = CHAR_SPACER;
    }
    text[i] = EOS;

    DrawOptionMenuChoice(gText_FrameType, 104, y, 0);
    DrawOptionMenuChoice(text, 128, y, 1);
}

static u8 ButtonMode_ProcessInput(u8 selection)
{
    if (JOY_NEW(DPAD_RIGHT))
    {
        if (selection <= 1)
            selection++;
        else
            selection = 0;
    }
    if (JOY_NEW(DPAD_LEFT))
    {
        if (selection != 0)
            selection--;
        else
            selection = 2;
    }
    return selection;
}

static void ButtonMode_DrawChoices(u8 selection, u8 y)
{
    s32 widthNormal, widthLR, widthLA, xLR;
    u8 styles[3] = {0};

    styles[selection] = 1;
    DrawOptionMenuChoice(gText_ButtonTypeNormal, 104, y, styles[0]);

    widthNormal = GetStringWidth(FONT_NORMAL, gText_ButtonTypeNormal, 0);
    widthLR = GetStringWidth(FONT_NORMAL, gText_ButtonTypeLR, 0);
    widthLA = GetStringWidth(FONT_NORMAL, gText_ButtonTypeLEqualsA, 0);
    widthLR -= 94;
    xLR = (widthNormal - widthLR - widthLA) / 2 + 104;
    DrawOptionMenuChoice(gText_ButtonTypeLR, xLR, y, styles[1]);
    DrawOptionMenuChoice(gText_ButtonTypeLEqualsA, GetStringRightAlignXOffset(FONT_NORMAL, gText_ButtonTypeLEqualsA, 198), y, styles[2]);
}

static u8 Toggle_ProcessInput(u8 selection)
{
    if (JOY_NEW(DPAD_LEFT | DPAD_RIGHT))
        selection ^= 1;
    return selection;
}

static u8 Difficulty_ProcessInput(u8 selection)
{
    if (JOY_NEW(DPAD_RIGHT))
    {
        if (selection < DIFFICULTY_SELECTION_HARD)
            selection++;
        else
            selection = DIFFICULTY_SELECTION_EASY;
    }
    if (JOY_NEW(DPAD_LEFT))
    {
        if (selection > DIFFICULTY_SELECTION_EASY)
            selection--;
        else
            selection = DIFFICULTY_SELECTION_HARD;
    }
    return selection;
}

static void DrawTwoChoices(const u8 *left, const u8 *right, u8 selection, u8 y)
{
    u8 styles[2] = {0};

    styles[selection] = 1;
    DrawOptionMenuChoice(left, 104, y, styles[0]);
    DrawOptionMenuChoice(right, GetStringRightAlignXOffset(FONT_NORMAL, right, 198), y, styles[1]);
}

static void OnOff_DrawChoices(u8 selection, u8 y)
{
    DrawTwoChoices(sText_On, sText_Off, selection, y);
}

static void Difficulty_DrawChoices(u8 selection, u8 y)
{
    u8 styles[3] = {0};
    s32 normalX = 151 - GetStringWidth(FONT_NORMAL, sText_Normal, 0) / 2;

    styles[selection] = 1;
    DrawOptionMenuChoice(sText_Easy, 104, y, styles[DIFFICULTY_SELECTION_EASY]);
    DrawOptionMenuChoice(sText_Normal, normalX, y, styles[DIFFICULTY_SELECTION_NORMAL]);
    DrawOptionMenuChoice(sText_Hard, GetStringRightAlignXOffset(FONT_NORMAL, sText_Hard, 198), y, styles[DIFFICULTY_SELECTION_HARD]);
}

static void PokedexTheme_DrawChoices(u8 selection, u8 y)
{
    DrawTwoChoices(sText_Light, sText_Dark, selection, y);
}

static void BattleBarSpeed_DrawChoices(u8 selection, u8 y)
{
    DrawTwoChoices(sText_Fast, sText_Normal, selection, y);
}

static void MatchCalls_DrawChoices(u8 selection, u8 y)
{
    DrawTwoChoices(sText_Rematch, sText_All, selection, y);
}

static void DrawHeaderText(void)
{
    const struct OptionMenuPage *page = GetCurrentPage();
    s32 x;
    s32 buttonWidth;
    s32 labelWidth;

    FillWindowPixelBuffer(WIN_HEADER, PIXEL_FILL(1));
    x = (208 - GetStringWidth(FONT_SMALL, page->title, 0)) / 2;
    AddTextPrinterParameterized(WIN_HEADER, FONT_SMALL, page->title, x, 1, TEXT_SKIP_DRAW, NULL);
    if (page->previousTitle != NULL)
    {
        buttonWidth = GetStringWidth(FONT_SMALL, sText_LButton, 0);
        AddTextPrinterParameterized(WIN_HEADER, FONT_SMALL, sText_LButton, 4, 1, TEXT_SKIP_DRAW, NULL);
        AddTextPrinterParameterized(WIN_HEADER, FONT_SMALL, page->previousTitle, 4 + buttonWidth + 1, 1, TEXT_SKIP_DRAW, NULL);
    }
    if (page->nextTitle != NULL)
    {
        buttonWidth = GetStringWidth(FONT_SMALL, sText_RButton, 0);
        labelWidth = GetStringWidth(FONT_SMALL, page->nextTitle, 0);
        x = 204 - buttonWidth - 1 - labelWidth;
        AddTextPrinterParameterized(WIN_HEADER, FONT_SMALL, sText_RButton, x, 1, TEXT_SKIP_DRAW, NULL);
        AddTextPrinterParameterized(WIN_HEADER, FONT_SMALL, page->nextTitle, x + buttonWidth + 1, 1, TEXT_SKIP_DRAW, NULL);
    }
    CopyWindowToVram(WIN_HEADER, COPYWIN_FULL);
}

static void DrawVisibleOptions(void)
{
    const struct OptionMenuPage *page = GetCurrentPage();
    u16 scrollOffset = sOptions->scrollOffsets[sOptions->page];
    u8 visibleCount = min(OPTIONS_ON_SCREEN, page->itemCount - scrollOffset);
    u8 i;

    FillWindowPixelBuffer(WIN_OPTIONS, PIXEL_FILL(1));
    for (i = 0; i < visibleCount; i++)
    {
        u8 itemId = page->items[scrollOffset + i];
        u8 y = i * OPTION_ROW_HEIGHT;

        AddTextPrinterParameterized(WIN_OPTIONS, FONT_NORMAL, sOptionMenuItems[itemId].name, 8, y + 1, TEXT_SKIP_DRAW, NULL);
        if (sOptionMenuItems[itemId].drawChoices != NULL)
            sOptionMenuItems[itemId].drawChoices(sOptions->selections[itemId], y);
    }
    CopyWindowToVram(WIN_OPTIONS, COPYWIN_FULL);
}

static void DrawDescriptionText(void)
{
    u8 itemId = GetCurrentItemId();
    const u8 *description;
    u16 i;
    u8 y = 10;

    if (itemId == OPTION_SAVE)
    {
        description = sText_DescSave;
    }
    else if (sOptionMenuItems[itemId].descriptionCount == 1)
    {
        description = sOptionMenuItems[itemId].descriptions[0];
    }
    else
    {
        description = sOptionMenuItems[itemId].descriptions[sOptions->selections[itemId]];
    }

    for (i = 0; description[i] != EOS; i++)
    {
        if (description[i] == CHAR_NEWLINE)
        {
            y = 4;
            break;
        }
    }

    FillWindowPixelBuffer(WIN_DESCRIPTION, PIXEL_FILL(1));
    FillWindowPixelRect(WIN_DESCRIPTION, PIXEL_FILL(6), 0, 0, 208, 1);
    AddTextPrinterParameterized(WIN_DESCRIPTION, FONT_SMALL, description, 4, y, TEXT_SKIP_DRAW, NULL);
    CopyWindowToVram(WIN_DESCRIPTION, COPYWIN_FULL);
}

#define TILE_TOP_CORNER_L 0x1A2
#define TILE_TOP_EDGE     0x1A3
#define TILE_TOP_CORNER_R 0x1A4
#define TILE_LEFT_EDGE    0x1A5
#define TILE_RIGHT_EDGE   0x1A7
#define TILE_BOT_CORNER_L 0x1A8
#define TILE_BOT_EDGE     0x1A9
#define TILE_BOT_CORNER_R 0x1AA

static void DrawBgWindowFrames(void)
{
    FillBgTilemapBufferRect(1, TILE_TOP_CORNER_L,  1,  0,  1,  1,  7);
    FillBgTilemapBufferRect(1, TILE_TOP_EDGE,      2,  0, 26,  1,  7);
    FillBgTilemapBufferRect(1, TILE_TOP_CORNER_R, 28,  0,  1,  1,  7);
    FillBgTilemapBufferRect(1, TILE_LEFT_EDGE,     1,  1,  1,  2,  7);
    FillBgTilemapBufferRect(1, TILE_RIGHT_EDGE,   28,  1,  1,  2,  7);
    FillBgTilemapBufferRect(1, TILE_BOT_CORNER_L,  1,  3,  1,  1,  7);
    FillBgTilemapBufferRect(1, TILE_BOT_EDGE,      2,  3, 26,  1,  7);
    FillBgTilemapBufferRect(1, TILE_BOT_CORNER_R, 28,  3,  1,  1,  7);

    FillBgTilemapBufferRect(1, TILE_TOP_CORNER_L,  1,  4,  1,  1,  7);
    FillBgTilemapBufferRect(1, TILE_TOP_EDGE,      2,  4, 26,  1,  7);
    FillBgTilemapBufferRect(1, TILE_TOP_CORNER_R, 28,  4,  1,  1,  7);
    FillBgTilemapBufferRect(1, TILE_LEFT_EDGE,     1,  5,  1, 14,  7);
    FillBgTilemapBufferRect(1, TILE_RIGHT_EDGE,   28,  5,  1, 14,  7);
    FillBgTilemapBufferRect(1, TILE_BOT_CORNER_L,  1, 19,  1,  1,  7);
    FillBgTilemapBufferRect(1, TILE_BOT_EDGE,      2, 19, 26,  1,  7);
    FillBgTilemapBufferRect(1, TILE_BOT_CORNER_R, 28, 19,  1,  1,  7);

    CopyBgTilemapBufferToVram(1);
}
