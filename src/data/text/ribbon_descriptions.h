const u8 gRibbonDescriptionPart1_Champion[] = _("Hạ CHAMPION, vào HALL");
const u8 gRibbonDescriptionPart2_Champion[] = _("OF FAME, nhận RIBBON");
const u8 gRibbonDescriptionPart1_CoolContest[] = _("COOL CONTEST");
const u8 gRibbonDescriptionPart1_BeautyContest[] = _("BEAUTY CONTEST");
const u8 gRibbonDescriptionPart1_CuteContest[] = _("CUTE CONTEST");
const u8 gRibbonDescriptionPart1_SmartContest[] = _("SMART CONTEST");
const u8 gRibbonDescriptionPart1_ToughContest[] = _("TOUGH CONTEST");
const u8 gRibbonDescriptionPart2_NormalRank[] = _("Quán quân Normal Rank!");
const u8 gRibbonDescriptionPart2_SuperRank[] = _("Quán quân Super Rank!");
const u8 gRibbonDescriptionPart2_HyperRank[] = _("Quán quân Hyper Rank!");
const u8 gRibbonDescriptionPart2_MasterRank[] = _("Quán quân Master Rank!");
const u8 gRibbonDescriptionPart1_Winning[] = _("Vì đã vượt qua LV50");
const u8 gRibbonDescriptionPart2_Winning[] = _("tại BATTLE TOWER.");
const u8 gRibbonDescriptionPart1_Victory[] = _("Vượt Open Level");
const u8 gRibbonDescriptionPart2_Victory[] = _("tại BATTLE TOWER.");
const u8 gRibbonDescriptionPart1_Artist[] = _("RIBBON vì được chọn");
const u8 gRibbonDescriptionPart2_Artist[] = _("làm mẫu ký họa siêu hạng.");
const u8 gRibbonDescriptionPart1_Effort[] = _("RIBBON được trao vì");
const u8 gRibbonDescriptionPart2_Effort[] = _("đã luôn nỗ lực hết mình.");

const u8 *const gRibbonDescriptionPointers[][2] =
{
    [CHAMPION_RIBBON]      = {gRibbonDescriptionPart1_Champion,      gRibbonDescriptionPart2_Champion},
    [COOL_RIBBON_NORMAL]   = {gRibbonDescriptionPart1_CoolContest,   gRibbonDescriptionPart2_NormalRank},
    [COOL_RIBBON_SUPER]    = {gRibbonDescriptionPart1_CoolContest,   gRibbonDescriptionPart2_SuperRank},
    [COOL_RIBBON_HYPER]    = {gRibbonDescriptionPart1_CoolContest,   gRibbonDescriptionPart2_HyperRank},
    [COOL_RIBBON_MASTER]   = {gRibbonDescriptionPart1_CoolContest,   gRibbonDescriptionPart2_MasterRank},
    [BEAUTY_RIBBON_NORMAL] = {gRibbonDescriptionPart1_BeautyContest, gRibbonDescriptionPart2_NormalRank},
    [BEAUTY_RIBBON_SUPER]  = {gRibbonDescriptionPart1_BeautyContest, gRibbonDescriptionPart2_SuperRank},
    [BEAUTY_RIBBON_HYPER]  = {gRibbonDescriptionPart1_BeautyContest, gRibbonDescriptionPart2_HyperRank},
    [BEAUTY_RIBBON_MASTER] = {gRibbonDescriptionPart1_BeautyContest, gRibbonDescriptionPart2_MasterRank},
    [CUTE_RIBBON_NORMAL]   = {gRibbonDescriptionPart1_CuteContest,   gRibbonDescriptionPart2_NormalRank},
    [CUTE_RIBBON_SUPER]    = {gRibbonDescriptionPart1_CuteContest,   gRibbonDescriptionPart2_SuperRank},
    [CUTE_RIBBON_HYPER]    = {gRibbonDescriptionPart1_CuteContest,   gRibbonDescriptionPart2_HyperRank},
    [CUTE_RIBBON_MASTER]   = {gRibbonDescriptionPart1_CuteContest,   gRibbonDescriptionPart2_MasterRank},
    [SMART_RIBBON_NORMAL]  = {gRibbonDescriptionPart1_SmartContest,  gRibbonDescriptionPart2_NormalRank},
    [SMART_RIBBON_SUPER]   = {gRibbonDescriptionPart1_SmartContest,  gRibbonDescriptionPart2_SuperRank},
    [SMART_RIBBON_HYPER]   = {gRibbonDescriptionPart1_SmartContest,  gRibbonDescriptionPart2_HyperRank},
    [SMART_RIBBON_MASTER]  = {gRibbonDescriptionPart1_SmartContest,  gRibbonDescriptionPart2_MasterRank},
    [TOUGH_RIBBON_NORMAL]  = {gRibbonDescriptionPart1_ToughContest,  gRibbonDescriptionPart2_NormalRank},
    [TOUGH_RIBBON_SUPER]   = {gRibbonDescriptionPart1_ToughContest,  gRibbonDescriptionPart2_SuperRank},
    [TOUGH_RIBBON_HYPER]   = {gRibbonDescriptionPart1_ToughContest,  gRibbonDescriptionPart2_HyperRank},
    [TOUGH_RIBBON_MASTER]  = {gRibbonDescriptionPart1_ToughContest,  gRibbonDescriptionPart2_MasterRank},
    [WINNING_RIBBON]       = {gRibbonDescriptionPart1_Winning,       gRibbonDescriptionPart2_Winning},
    [VICTORY_RIBBON]       = {gRibbonDescriptionPart1_Victory,       gRibbonDescriptionPart2_Victory},
    [ARTIST_RIBBON]        = {gRibbonDescriptionPart1_Artist,        gRibbonDescriptionPart2_Artist},
    [EFFORT_RIBBON]        = {gRibbonDescriptionPart1_Effort,        gRibbonDescriptionPart2_Effort},
};

// BEGIN GENERATED LOCALIZATION EXPORTS
// These pointers expose file-local translated strings to the runtime resolver.
const u8 *const gLocalizationSource_C02384 = gRibbonDescriptionPart1_Champion;
const u8 *const gLocalizationSource_C02385 = gRibbonDescriptionPart2_Champion;
const u8 *const gLocalizationSource_C02386 = gRibbonDescriptionPart2_NormalRank;
const u8 *const gLocalizationSource_C02387 = gRibbonDescriptionPart2_SuperRank;
const u8 *const gLocalizationSource_C02388 = gRibbonDescriptionPart2_HyperRank;
const u8 *const gLocalizationSource_C02389 = gRibbonDescriptionPart2_MasterRank;
const u8 *const gLocalizationSource_C02390 = gRibbonDescriptionPart1_Winning;
const u8 *const gLocalizationSource_C02391 = gRibbonDescriptionPart2_Winning;
const u8 *const gLocalizationSource_C02392 = gRibbonDescriptionPart1_Victory;
const u8 *const gLocalizationSource_C02393 = gRibbonDescriptionPart2_Victory;
const u8 *const gLocalizationSource_C02394 = gRibbonDescriptionPart1_Artist;
const u8 *const gLocalizationSource_C02395 = gRibbonDescriptionPart2_Artist;
const u8 *const gLocalizationSource_C02396 = gRibbonDescriptionPart1_Effort;
const u8 *const gLocalizationSource_C02397 = gRibbonDescriptionPart2_Effort;
// END GENERATED LOCALIZATION EXPORTS
