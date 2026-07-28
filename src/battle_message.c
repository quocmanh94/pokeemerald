#include "global.h"
#include "battle.h"
#include "battle_anim.h"
#include "battle_controllers.h"
#include "battle_message.h"
#include "battle_setup.h"
#include "battle_tower.h"
#include "data.h"
#include "event_data.h"
#include "frontier_util.h"
#include "graphics.h"
#include "international_string_util.h"
#include "item.h"
#include "link.h"
#include "localization.h"
#include "menu.h"
#include "palette.h"
#include "recorded_battle.h"
#include "string_util.h"
#include "strings.h"
#include "text.h"
#include "trainer_hill.h"
#include "window.h"
#include "constants/battle_dome.h"
#include "constants/battle_string_ids.h"
#include "constants/frontier_util.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/trainers.h"
#include "constants/trainer_hill.h"
#include "constants/weather.h"

struct BattleWindowText
{
    u8 fillValue;
    u8 fontId;
    u8 x;
    u8 y;
    u8 letterSpacing;
    u8 lineSpacing;
    u8 speed;
    u8 fgColor;
    u8 bgColor;
    u8 shadowColor;
};

static void ChooseMoveUsedParticle(u8 *textPtr);
static void ChooseTypeOfMoveUsedString(u8 *dst);
static void ExpandBattleTextBuffPlaceholders(const u8 *src, u8 *dst);

static EWRAM_DATA u8 sBattlerAbilities[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA struct BattleMsgData *gBattleMsgDataPtr = NULL;

// todo: make some of those names less vague: attacker/target vs pkmn, etc.

static const u8 sText_Trainer1LoseText[] = _("{B_TRAINER1_LOSE_TEXT}");
static const u8 sText_PkmnGainedEXP[] = _("{B_BUFF1} nhận được{B_BUFF2}\n{B_BUFF3} EXP. Points!\p");
static const u8 sText_EmptyString4[] = _("");
static const u8 sText_ABoosted[] = _(" thêm");
static const u8 sText_PkmnGrewToLv[] = _("{B_BUFF1} đã lên\nLV. {B_BUFF2}!{WAIT_SE}\p");
static const u8 sText_PkmnLearnedMove[] = _("{B_BUFF1} đã học\n{B_BUFF2}!{WAIT_SE}\p");
static const u8 sText_TryToLearnMove1[] = _("{B_BUFF1} muốn học\n{B_BUFF2}.\p");
static const u8 sText_TryToLearnMove2[] = _("Nhưng {B_BUFF1} đã biết\nbốn chiêu thức.\p");
static const u8 sText_TryToLearnMove3[] = _("Quên một chiêu để học\n{B_BUFF2}?");
static const u8 sText_PkmnForgotMove[] = _("{B_BUFF1} đã quên\n{B_BUFF2}.\p");
static const u8 sText_StopLearningMove[] = _("{PAUSE 32}Tiếp tục học\n{B_BUFF2}?");
static const u8 sText_DidNotLearnMove[] = _("{B_BUFF1} không học\n{B_BUFF2}.\p");
static const u8 sText_UseNextPkmn[] = _("Dùng POKéMON tiếp theo?");
static const u8 sText_AddCaughtMonToParty[] = _("Thêm {STR_VAR_1} vào đội?");
static const u8 sText_AttackMissed[] = _("Đòn tấn công của\n{B_ATK_NAME_WITH_PREFIX} đã trượt!");
static const u8 sText_PkmnProtectedItself[] = _("{B_DEF_NAME_WITH_PREFIX}\nđã tự bảo vệ!");
static const u8 sText_AvoidedDamage[] = _("{B_DEF_NAME_WITH_PREFIX} tránh sát thương\nnhờ {B_DEF_ABILITY}!");
static const u8 sText_PkmnMakesGroundMiss[] = _("{B_DEF_ABILITY} giúp {B_DEF_NAME_WITH_PREFIX}\nné các chiêu GROUND!");
static const u8 sText_PkmnAvoidedAttack[] = _("{B_DEF_NAME_WITH_PREFIX} đã né\nđòn tấn công!");
static const u8 sText_ItDoesntAffect[] = _("Không ảnh hưởng đến\n{B_DEF_NAME_WITH_PREFIX}…");
static const u8 sText_AttackerFainted[] = _("{B_ATK_NAME_WITH_PREFIX}\nđã ngất!\p");
static const u8 sText_TargetFainted[] = _("{B_DEF_NAME_WITH_PREFIX}\nđã ngất!\p");
static const u8 sText_PlayerGotMoney[] = _("{B_PLAYER_NAME} nhận ¥{B_BUFF1}\nnhờ chiến thắng!\p");
static const u8 sText_PlayerWhiteout[] = _("{B_PLAYER_NAME} không còn POKéMON\ncó thể chiến đấu!\p");
static const u8 sText_PlayerWhiteout2[] = _("{B_PLAYER_NAME} hoảng loạn và mất ¥{B_BUFF1}…\p… … … …\p{B_PLAYER_NAME} đã kiệt sức!{PAUSE_UNTIL_PRESS}");
static const u8 sText_PreventsEscape[] = _("{B_SCR_ACTIVE_ABILITY} của {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nngăn việc chạy thoát!\p");
static const u8 sText_CantEscape2[] = _("Không thể chạy thoát!\p");
static const u8 sText_AttackerCantEscape[] = _("{B_ATK_NAME_WITH_PREFIX} không thể chạy thoát!");
static const u8 sText_HitXTimes[] = _("Đánh trúng {B_BUFF1} lần!");
static const u8 sText_PkmnFellAsleep[] = _("{B_EFF_NAME_WITH_PREFIX}\nđã ngủ thiếp đi!");
static const u8 sText_PkmnMadeSleep[] = _("{B_SCR_ACTIVE_ABILITY} của {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nlàm {B_EFF_NAME_WITH_PREFIX} ngủ!");
static const u8 sText_PkmnAlreadyAsleep[] = _("{B_DEF_NAME_WITH_PREFIX}\nđã ngủ rồi!");
static const u8 sText_PkmnAlreadyAsleep2[] = _("{B_ATK_NAME_WITH_PREFIX}\nđã ngủ rồi!");
static const u8 sText_PkmnWasntAffected[] = _("{B_DEF_NAME_WITH_PREFIX}\nkhông bị ảnh hưởng!");
static const u8 sText_PkmnWasPoisoned[] = _("{B_EFF_NAME_WITH_PREFIX}\nđã trúng độc!");
static const u8 sText_PkmnPoisonedBy[] = _("{B_SCR_ACTIVE_ABILITY} của {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nđầu độc {B_EFF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnHurtByPoison[] = _("{B_ATK_NAME_WITH_PREFIX} chịu sát thương\ndo độc!");
static const u8 sText_PkmnAlreadyPoisoned[] = _("{B_DEF_NAME_WITH_PREFIX}\nđã trúng độc rồi.");
static const u8 sText_PkmnBadlyPoisoned[] = _("{B_EFF_NAME_WITH_PREFIX}\nđã trúng độc nặng!");
static const u8 sText_PkmnEnergyDrained[] = _("Năng lượng của {B_DEF_NAME_WITH_PREFIX}\nđã bị hút!");
static const u8 sText_PkmnWasBurned[] = _("{B_EFF_NAME_WITH_PREFIX} đã bị bỏng!");
static const u8 sText_PkmnBurnedBy[] = _("{B_SCR_ACTIVE_ABILITY} của {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nthiêu bỏng {B_EFF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnHurtByBurn[] = _("{B_ATK_NAME_WITH_PREFIX} chịu sát thương\ndo bỏng!");
static const u8 sText_PkmnAlreadyHasBurn[] = _("{B_DEF_NAME_WITH_PREFIX}\nđã bị bỏng rồi.");
static const u8 sText_PkmnWasFrozen[] = _("{B_EFF_NAME_WITH_PREFIX}\nđã bị đóng băng!");
static const u8 sText_PkmnFrozenBy[] = _("{B_SCR_ACTIVE_ABILITY} của {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nđóng băng {B_EFF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnIsFrozen[] = _("{B_ATK_NAME_WITH_PREFIX}\nđang bị đóng băng!");
static const u8 sText_PkmnWasDefrosted[] = _("{B_DEF_NAME_WITH_PREFIX}\nđã tan băng!");
static const u8 sText_PkmnWasDefrosted2[] = _("{B_ATK_NAME_WITH_PREFIX}\nđã tan băng!");
static const u8 sText_PkmnWasDefrostedBy[] = _("{B_CURRENT_MOVE} đã giúp\n{B_ATK_NAME_WITH_PREFIX} tan băng!");
static const u8 sText_PkmnWasParalyzed[] = _("{B_EFF_NAME_WITH_PREFIX} đã bị tê liệt!\nNó có thể không cử động được!");
static const u8 sText_PkmnWasParalyzedBy[] = _("{B_SCR_ACTIVE_ABILITY} của {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nlàm {B_EFF_NAME_WITH_PREFIX} tê liệt!\lNó có thể không cử động được!");
static const u8 sText_PkmnIsParalyzed[] = _("{B_ATK_NAME_WITH_PREFIX} bị tê liệt!\nNó không thể cử động!");
static const u8 sText_PkmnIsAlreadyParalyzed[] = _("{B_DEF_NAME_WITH_PREFIX}\nđã bị tê liệt rồi!");
static const u8 sText_PkmnHealedParalysis[] = _("{B_DEF_NAME_WITH_PREFIX}\nđã hết tê liệt!");
static const u8 sText_PkmnDreamEaten[] = _("Giấc mơ của {B_DEF_NAME_WITH_PREFIX}\nđã bị ăn mất!");
static const u8 sText_StatsWontIncrease[] = _("{B_BUFF1} của {B_ATK_NAME_WITH_PREFIX}\nkhông thể tăng thêm!");
static const u8 sText_StatsWontDecrease[] = _("{B_BUFF1} của {B_DEF_NAME_WITH_PREFIX}\nkhông thể giảm thêm!");
static const u8 sText_TeamStoppedWorking[] = _("{B_BUFF1} của đội bạn\nđã hết tác dụng!");
static const u8 sText_FoeStoppedWorking[] = _("{B_BUFF1} của đối thủ\nđã hết tác dụng!");
static const u8 sText_PkmnIsConfused[] = _("{B_ATK_NAME_WITH_PREFIX}\nđang bối rối!");
static const u8 sText_PkmnHealedConfusion[] = _("{B_ATK_NAME_WITH_PREFIX}\nđã hết bối rối!");
static const u8 sText_PkmnWasConfused[] = _("{B_EFF_NAME_WITH_PREFIX}\nđã trở nên bối rối!");
static const u8 sText_PkmnAlreadyConfused[] = _("{B_DEF_NAME_WITH_PREFIX}\nđã bối rối rồi!");
static const u8 sText_PkmnFellInLove[] = _("{B_DEF_NAME_WITH_PREFIX}\nđã phải lòng!");
static const u8 sText_PkmnInLove[] = _("{B_ATK_NAME_WITH_PREFIX} đang say mê\n{B_SCR_ACTIVE_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnImmobilizedByLove[] = _("{B_ATK_NAME_WITH_PREFIX}\nkhông thể cử động vì tình yêu!");
static const u8 sText_PkmnBlownAway[] = _("{B_DEF_NAME_WITH_PREFIX}\nđã bị thổi bay!");
static const u8 sText_PkmnChangedType[] = _("{B_ATK_NAME_WITH_PREFIX} đã biến thành\nhệ {B_BUFF1}!");
static const u8 sText_PkmnFlinched[] = _("{B_ATK_NAME_WITH_PREFIX} đã chùn bước!");
static const u8 sText_PkmnRegainedHealth[] = _("{B_DEF_NAME_WITH_PREFIX}\nđã hồi phục HP!");
static const u8 sText_PkmnHPFull[] = _("HP của {B_DEF_NAME_WITH_PREFIX}\nđã đầy!");
static const u8 sText_PkmnRaisedSpDef[] = _("{B_CURRENT_MOVE} của {B_ATK_PREFIX2}\nđã tăng SP. DEF!");
static const u8 sText_PkmnRaisedSpDefALittle[] = _("{B_CURRENT_MOVE} của {B_ATK_PREFIX2}\nđã tăng nhẹ SP. DEF!");
static const u8 sText_PkmnRaisedDef[] = _("{B_CURRENT_MOVE} của {B_ATK_PREFIX2}\nđã tăng DEFENSE!");
static const u8 sText_PkmnRaisedDefALittle[] = _("{B_CURRENT_MOVE} của {B_ATK_PREFIX2}\nđã tăng nhẹ DEFENSE!");
static const u8 sText_PkmnCoveredByVeil[] = _("Đội của {B_ATK_PREFIX2}\nđược bao phủ bởi một tấm màn!");
static const u8 sText_PkmnUsedSafeguard[] = _("Đội của {B_DEF_NAME_WITH_PREFIX}\nđược SAFEGUARD bảo vệ!");
static const u8 sText_PkmnSafeguardExpired[] = _("Đội của {B_ATK_PREFIX3}\nkhông còn được SAFEGUARD bảo vệ!");
static const u8 sText_PkmnWentToSleep[] = _("{B_ATK_NAME_WITH_PREFIX}\nđã chìm vào giấc ngủ!");
static const u8 sText_PkmnSleptHealthy[] = _("{B_ATK_NAME_WITH_PREFIX} ngủ một giấc\nvà hồi phục khỏe mạnh!");
static const u8 sText_PkmnWhippedWhirlwind[] = _("{B_ATK_NAME_WITH_PREFIX}\ntạo ra một cơn lốc!");
static const u8 sText_PkmnTookSunlight[] = _("{B_ATK_NAME_WITH_PREFIX}\nđã hấp thụ ánh nắng!");
static const u8 sText_PkmnLoweredHead[] = _("{B_ATK_NAME_WITH_PREFIX}\nđã cúi đầu!");
static const u8 sText_PkmnIsGlowing[] = _("{B_ATK_NAME_WITH_PREFIX} đang phát sáng!");
static const u8 sText_PkmnFlewHigh[] = _("{B_ATK_NAME_WITH_PREFIX}\nđã bay vút lên cao!");
static const u8 sText_PkmnDugHole[] = _("{B_ATK_NAME_WITH_PREFIX} đã đào một cái hố!");
static const u8 sText_PkmnHidUnderwater[] = _("{B_ATK_NAME_WITH_PREFIX}\nđã ẩn mình dưới nước!");
static const u8 sText_PkmnSprangUp[] = _("{B_ATK_NAME_WITH_PREFIX} đã bật lên cao!");
static const u8 sText_PkmnSqueezedByBind[] = _("{B_DEF_NAME_WITH_PREFIX} bị BIND của\n{B_ATK_NAME_WITH_PREFIX} siết chặt!");
static const u8 sText_PkmnTrappedInVortex[] = _("{B_DEF_NAME_WITH_PREFIX}\nđã mắc kẹt trong xoáy nước!");
static const u8 sText_PkmnTrappedBySandTomb[] = _("{B_DEF_NAME_WITH_PREFIX}\nđã mắc kẹt trong SAND TOMB!");
static const u8 sText_PkmnWrappedBy[] = _("{B_DEF_NAME_WITH_PREFIX} bị\n{B_ATK_NAME_WITH_PREFIX} WRAP!");
static const u8 sText_PkmnClamped[] = _("{B_ATK_NAME_WITH_PREFIX} đã CLAMP\n{B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnHurtBy[] = _("{B_ATK_NAME_WITH_PREFIX} chịu sát thương\ndo {B_BUFF1}!");
static const u8 sText_PkmnFreedFrom[] = _("{B_ATK_NAME_WITH_PREFIX}\nđã thoát khỏi {B_BUFF1}!");
static const u8 sText_PkmnCrashed[] = _("{B_ATK_NAME_WITH_PREFIX} lao quá đà\nvà đâm sầm vào!");
const u8 gText_PkmnShroudedInMist[] = _("{B_ATK_PREFIX2}\nđược bao phủ trong MIST!");
static const u8 sText_PkmnProtectedByMist[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}\nđược MIST bảo vệ!");
const u8 gText_PkmnGettingPumped[] = _("{B_ATK_NAME_WITH_PREFIX}\nđang hừng hực khí thế!");
static const u8 sText_PkmnHitWithRecoil[] = _("{B_ATK_NAME_WITH_PREFIX}\nchịu sát thương phản lực!");
static const u8 sText_PkmnProtectedItself2[] = _("{B_ATK_NAME_WITH_PREFIX}\nđã tự bảo vệ!");
static const u8 sText_PkmnBuffetedBySandstorm[] = _("{B_ATK_NAME_WITH_PREFIX} bị bão cát\nquật mạnh!");
static const u8 sText_PkmnPeltedByHail[] = _("{B_ATK_NAME_WITH_PREFIX}\nbị HAIL tấn công!");
static const u8 sText_PkmnsXWoreOff[] = _("{B_BUFF1} của {B_ATK_PREFIX1}\nđã hết tác dụng!");
static const u8 sText_PkmnSeeded[] = _("{B_DEF_NAME_WITH_PREFIX} đã bị gieo hạt!");
static const u8 sText_PkmnEvadedAttack[] = _("{B_DEF_NAME_WITH_PREFIX}\nđã né đòn tấn công!");
static const u8 sText_PkmnSappedByLeechSeed[] = _("HP của {B_ATK_NAME_WITH_PREFIX}\nbị LEECH SEED hút!");
static const u8 sText_PkmnFastAsleep[] = _("{B_ATK_NAME_WITH_PREFIX}\nđang ngủ say.");
static const u8 sText_PkmnWokeUp[] = _("{B_ATK_NAME_WITH_PREFIX} đã tỉnh giấc!");
static const u8 sText_PkmnUproarKeptAwake[] = _("UPROAR của {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nkhiến nó không thể ngủ!");
static const u8 sText_PkmnWokeUpInUproar[] = _("{B_ATK_NAME_WITH_PREFIX} tỉnh giấc\ngiữa UPROAR!");
static const u8 sText_PkmnCausedUproar[] = _("{B_ATK_NAME_WITH_PREFIX}\nđã gây ra UPROAR!");
static const u8 sText_PkmnMakingUproar[] = _("{B_ATK_NAME_WITH_PREFIX}\nđang gây UPROAR!");
static const u8 sText_PkmnCalmedDown[] = _("{B_ATK_NAME_WITH_PREFIX} đã bình tĩnh lại.");
static const u8 sText_PkmnCantSleepInUproar[] = _("Nhưng {B_DEF_NAME_WITH_PREFIX} không thể\nngủ giữa UPROAR!");
static const u8 sText_PkmnStockpiled[] = _("{B_ATK_NAME_WITH_PREFIX} đã STOCKPILE\n{B_BUFF1}!");
static const u8 sText_PkmnCantStockpile[] = _("{B_ATK_NAME_WITH_PREFIX} không thể\nSTOCKPILE thêm!");
static const u8 sText_PkmnCantSleepInUproar2[] = _("Nhưng {B_DEF_NAME_WITH_PREFIX} không thể\nngủ giữa UPROAR!");
static const u8 sText_UproarKeptPkmnAwake[] = _("UPROAR khiến\n{B_DEF_NAME_WITH_PREFIX} không thể ngủ!");
static const u8 sText_PkmnStayedAwakeUsing[] = _("{B_DEF_NAME_WITH_PREFIX} vẫn thức\nnhờ {B_DEF_ABILITY}!");
static const u8 sText_PkmnStoringEnergy[] = _("{B_ATK_NAME_WITH_PREFIX}\nđang tích trữ năng lượng!");
static const u8 sText_PkmnUnleashedEnergy[] = _("{B_ATK_NAME_WITH_PREFIX}\nđã giải phóng năng lượng!");
static const u8 sText_PkmnFatigueConfusion[] = _("{B_ATK_NAME_WITH_PREFIX}\nbối rối vì kiệt sức!");
static const u8 sText_PlayerPickedUpMoney[] = _("{B_PLAYER_NAME} nhặt được\n¥{B_BUFF1}!\p");
static const u8 sText_PkmnUnaffected[] = _("{B_DEF_NAME_WITH_PREFIX}\nkhông bị ảnh hưởng!");
static const u8 sText_PkmnTransformedInto[] = _("{B_ATK_NAME_WITH_PREFIX}\nđã biến thành {B_BUFF1}!");
static const u8 sText_PkmnMadeSubstitute[] = _("{B_ATK_NAME_WITH_PREFIX}\nđã tạo SUBSTITUTE!");
static const u8 sText_PkmnHasSubstitute[] = _("{B_ATK_NAME_WITH_PREFIX}\nđã có SUBSTITUTE rồi!");
static const u8 sText_SubstituteDamaged[] = _("SUBSTITUTE đã chịu sát thương\nthay {B_DEF_NAME_WITH_PREFIX}!\p");
static const u8 sText_PkmnSubstituteFaded[] = _("SUBSTITUTE của\n{B_DEF_NAME_WITH_PREFIX} đã biến mất!\p");
static const u8 sText_PkmnMustRecharge[] = _("{B_ATK_NAME_WITH_PREFIX}\nphải nạp lại năng lượng!");
static const u8 sText_PkmnRageBuilding[] = _("RAGE của {B_DEF_NAME_WITH_PREFIX}\nđang tăng lên!");
static const u8 sText_PkmnMoveWasDisabled[] = _("{B_BUFF1} của {B_DEF_NAME_WITH_PREFIX}\nđã bị vô hiệu hóa!");
static const u8 sText_PkmnMoveDisabledNoMore[] = _("Chiêu của {B_ATK_NAME_WITH_PREFIX}\nkhông còn bị vô hiệu hóa!");
static const u8 sText_PkmnGotEncore[] = _("{B_DEF_NAME_WITH_PREFIX}\nđã nhận ENCORE!");
static const u8 sText_PkmnEncoreEnded[] = _("ENCORE của {B_ATK_NAME_WITH_PREFIX}\nđã kết thúc!");
static const u8 sText_PkmnTookAim[] = _("{B_ATK_NAME_WITH_PREFIX} đã nhắm vào\n{B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnSketchedMove[] = _("{B_ATK_NAME_WITH_PREFIX} đã SKETCH\n{B_BUFF1}!");
static const u8 sText_PkmnTryingToTakeFoe[] = _("{B_ATK_NAME_WITH_PREFIX} đang cố\nkéo đối thủ đi cùng!");
static const u8 sText_PkmnTookFoe[] = _("{B_DEF_NAME_WITH_PREFIX} đã kéo\n{B_ATK_NAME_WITH_PREFIX} đi cùng!");
static const u8 sText_PkmnReducedPP[] = _("Giảm {B_BUFF1} của\n{B_DEF_NAME_WITH_PREFIX} đi {B_BUFF2}!");
static const u8 sText_PkmnStoleItem[] = _("{B_ATK_NAME_WITH_PREFIX} đã lấy trộm\n{B_LAST_ITEM} của {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_TargetCantEscapeNow[] = _("{B_DEF_NAME_WITH_PREFIX}\ngiờ không thể chạy thoát!");
static const u8 sText_PkmnFellIntoNightmare[] = _("{B_DEF_NAME_WITH_PREFIX}\nđã rơi vào NIGHTMARE!");
static const u8 sText_PkmnLockedInNightmare[] = _("{B_ATK_NAME_WITH_PREFIX}\nbị kẹt trong NIGHTMARE!");
static const u8 sText_PkmnLaidCurse[] = _("{B_ATK_NAME_WITH_PREFIX} giảm HP của mình và\nđặt CURSE lên {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnAfflictedByCurse[] = _("{B_ATK_NAME_WITH_PREFIX}\nđang chịu CURSE!");
static const u8 sText_SpikesScattered[] = _("SPIKES đã rải khắp\nphía sân đối thủ!");
static const u8 sText_PkmnHurtBySpikes[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}\nchịu sát thương từ SPIKES!");
static const u8 sText_PkmnIdentified[] = _("{B_ATK_NAME_WITH_PREFIX} đã nhận diện\n{B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnPerishCountFell[] = _("PERISH count của {B_ATK_NAME_WITH_PREFIX}\ngiảm còn {B_BUFF1}!");
static const u8 sText_PkmnBracedItself[] = _("{B_ATK_NAME_WITH_PREFIX}\nđã gồng mình!");
static const u8 sText_PkmnEnduredHit[] = _("{B_DEF_NAME_WITH_PREFIX} đã ENDURE\nđòn tấn công!");
static const u8 sText_MagnitudeStrength[] = _("MAGNITUDE {B_BUFF1}!");
static const u8 sText_PkmnCutHPMaxedAttack[] = _("{B_ATK_NAME_WITH_PREFIX} giảm HP của mình\nvà tăng tối đa ATTACK!");
static const u8 sText_PkmnCopiedStatChanges[] = _("{B_ATK_NAME_WITH_PREFIX} sao chép thay đổi\nchỉ số của {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnGotFree[] = _("{B_ATK_NAME_WITH_PREFIX} đã thoát khỏi\n{B_BUFF1} của {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnShedLeechSeed[] = _("{B_ATK_NAME_WITH_PREFIX}\nđã loại bỏ LEECH SEED!");
static const u8 sText_PkmnBlewAwaySpikes[] = _("{B_ATK_NAME_WITH_PREFIX}\nđã thổi bay SPIKES!");
static const u8 sText_PkmnFledFromBattle[] = _("{B_ATK_NAME_WITH_PREFIX}\nđã chạy khỏi trận đấu!");
static const u8 sText_PkmnForesawAttack[] = _("{B_ATK_NAME_WITH_PREFIX}\nđã thấy trước một đòn tấn công!");
static const u8 sText_PkmnTookAttack[] = _("{B_DEF_NAME_WITH_PREFIX} đã trúng\nđòn {B_BUFF1}!");
static const u8 sText_PkmnChoseXAsDestiny[] = _("{B_ATK_NAME_WITH_PREFIX} chọn\n{B_CURRENT_MOVE} làm định mệnh!");
static const u8 sText_PkmnAttack[] = _("Đòn tấn công của {B_BUFF1}!");
static const u8 sText_PkmnCenterAttention[] = _("{B_ATK_NAME_WITH_PREFIX}\nđã trở thành tâm điểm chú ý!");
static const u8 sText_PkmnChargingPower[] = _("{B_ATK_NAME_WITH_PREFIX}\nbắt đầu tích tụ sức mạnh!");
static const u8 sText_NaturePowerTurnedInto[] = _("NATURE POWER đã biến thành\n{B_CURRENT_MOVE}!");
static const u8 sText_PkmnStatusNormal[] = _("Trạng thái của {B_ATK_NAME_WITH_PREFIX}\nđã trở lại bình thường!");
static const u8 sText_PkmnSubjectedToTorment[] = _("{B_DEF_NAME_WITH_PREFIX}\nđã bị TORMENT!");
static const u8 sText_PkmnTighteningFocus[] = _("{B_ATK_NAME_WITH_PREFIX}\nđang tập trung cao độ!");
static const u8 sText_PkmnFellForTaunt[] = _("{B_DEF_NAME_WITH_PREFIX}\nđã mắc TAUNT!");
static const u8 sText_PkmnReadyToHelp[] = _("{B_ATK_NAME_WITH_PREFIX} sẵn sàng\ngiúp {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnSwitchedItems[] = _("{B_ATK_NAME_WITH_PREFIX} đã đổi vật phẩm\nvới đối thủ!");
static const u8 sText_PkmnObtainedX[] = _("{B_ATK_NAME_WITH_PREFIX} đã nhận\n{B_BUFF1}.");
static const u8 sText_PkmnObtainedX2[] = _("{B_DEF_NAME_WITH_PREFIX} đã nhận\n{B_BUFF2}.");
static const u8 sText_PkmnObtainedXYObtainedZ[] = _("{B_ATK_NAME_WITH_PREFIX} đã nhận\n{B_BUFF1}.\p{B_DEF_NAME_WITH_PREFIX} đã nhận\n{B_BUFF2}.");
static const u8 sText_PkmnCopiedFoe[] = _("{B_ATK_NAME_WITH_PREFIX} sao chép\n{B_DEF_ABILITY} của {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnMadeWish[] = _("{B_ATK_NAME_WITH_PREFIX} đã cầu WISH!");
static const u8 sText_PkmnWishCameTrue[] = _("WISH của {B_BUFF1}\nđã thành hiện thực!");
static const u8 sText_PkmnPlantedRoots[] = _("{B_ATK_NAME_WITH_PREFIX} đã cắm rễ!");
static const u8 sText_PkmnAbsorbedNutrients[] = _("{B_ATK_NAME_WITH_PREFIX} hấp thụ\ndinh dưỡng qua rễ!");
static const u8 sText_PkmnAnchoredItself[] = _("{B_DEF_NAME_WITH_PREFIX}\nđã bám chặt bằng rễ!");
static const u8 sText_PkmnWasMadeDrowsy[] = _("{B_ATK_NAME_WITH_PREFIX} làm\n{B_DEF_NAME_WITH_PREFIX} buồn ngủ!");
static const u8 sText_PkmnKnockedOff[] = _("{B_ATK_NAME_WITH_PREFIX} đánh rơi\n{B_LAST_ITEM} của {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnSwappedAbilities[] = _("{B_ATK_NAME_WITH_PREFIX} đã đổi Ability\nvới đối thủ!");
static const u8 sText_PkmnSealedOpponentMove[] = _("{B_ATK_NAME_WITH_PREFIX} đã phong ấn\nmove của đối thủ!");
static const u8 sText_PkmnWantsGrudge[] = _("{B_ATK_NAME_WITH_PREFIX} muốn đối thủ\nphải chịu GRUDGE!");
static const u8 sText_PkmnLostPPGrudge[] = _("{B_BUFF1} của {B_ATK_NAME_WITH_PREFIX} mất\ntoàn bộ PP vì GRUDGE!");
static const u8 sText_PkmnShroudedItself[] = _("{B_ATK_NAME_WITH_PREFIX} tự bao phủ\nbằng {B_CURRENT_MOVE}!");
static const u8 sText_PkmnMoveBounced[] = _("{B_CURRENT_MOVE} của {B_ATK_NAME_WITH_PREFIX}\nbị MAGIC COAT phản lại!");
static const u8 sText_PkmnWaitsForTarget[] = _("{B_ATK_NAME_WITH_PREFIX} chờ mục tiêu\nthực hiện chiêu!");
static const u8 sText_PkmnSnatchedMove[] = _("{B_DEF_NAME_WITH_PREFIX} đã SNATCH\nmove của {B_SCR_ACTIVE_NAME_WITH_PREFIX}!");
static const u8 sText_ElectricityWeakened[] = _("Sức mạnh điện\nđã suy yếu!");
static const u8 sText_FireWeakened[] = _("Sức mạnh lửa\nđã suy yếu!");
static const u8 sText_XFoundOneY[] = _("{B_ATK_NAME_WITH_PREFIX} tìm thấy\n{B_LAST_ITEM}!");
static const u8 sText_SoothingAroma[] = _("Một hương thơm dịu dàng\nlan khắp khu vực!");
static const u8 sText_ItemsCantBeUsedNow[] = _("Hiện không thể dùng vật phẩm.{PAUSE 64}");
static const u8 sText_ForXCommaYZ[] = _("Nhờ {B_LAST_ITEM},\n{B_SCR_ACTIVE_NAME_WITH_PREFIX} {B_BUFF1}");
static const u8 sText_PkmnUsedXToGetPumped[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX} dùng\n{B_LAST_ITEM} để tăng khí thế!");
static const u8 sText_PkmnLostFocus[] = _("{B_ATK_NAME_WITH_PREFIX} mất tập trung\nvà không thể cử động!");
static const u8 sText_PkmnWasDraggedOut[] = _("{B_DEF_NAME_WITH_PREFIX}\nđã bị kéo ra!\p");
static const u8 sText_TheWallShattered[] = _("Bức tường đã vỡ tan!");
static const u8 sText_ButNoEffect[] = _("Nhưng không có tác dụng!");
static const u8 sText_PkmnHasNoMovesLeft[] = _("{B_ACTIVE_NAME_WITH_PREFIX}\nkhông còn chiêu nào!\p");
static const u8 sText_PkmnMoveIsDisabled[] = _("{B_CURRENT_MOVE} của {B_ACTIVE_NAME_WITH_PREFIX}\nđã bị vô hiệu hóa!\p");
static const u8 sText_PkmnCantUseMoveTorment[] = _("{B_ACTIVE_NAME_WITH_PREFIX} không thể dùng cùng\nmove liên tiếp vì TORMENT!\p");
static const u8 sText_PkmnCantUseMoveTaunt[] = _("{B_ACTIVE_NAME_WITH_PREFIX} không thể dùng\n{B_CURRENT_MOVE} sau TAUNT!\p");
static const u8 sText_PkmnCantUseMoveSealed[] = _("{B_ACTIVE_NAME_WITH_PREFIX} không thể dùng\n{B_CURRENT_MOVE} đã bị phong ấn!\p");
static const u8 sText_PkmnMadeItRain[] = _("{B_SCR_ACTIVE_ABILITY} của {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nđã gọi mưa!");
static const u8 sText_PkmnRaisedSpeed[] = _("{B_SCR_ACTIVE_ABILITY} của {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nđã tăng SPEED!");
static const u8 sText_PkmnProtectedBy[] = _("{B_DEF_NAME_WITH_PREFIX}\nđược {B_DEF_ABILITY} bảo vệ!");
static const u8 sText_PkmnPreventsUsage[] = _("{B_DEF_ABILITY} của {B_DEF_NAME_WITH_PREFIX}\nngăn {B_ATK_NAME_WITH_PREFIX}\ldùng {B_CURRENT_MOVE}!");
static const u8 sText_PkmnRestoredHPUsing[] = _("{B_DEF_NAME_WITH_PREFIX} hồi HP\nnhờ {B_DEF_ABILITY}!");
static const u8 sText_PkmnsXMadeYUseless[] = _("{B_DEF_ABILITY} của {B_DEF_NAME_WITH_PREFIX}\nlàm {B_CURRENT_MOVE} vô dụng!");
static const u8 sText_PkmnChangedTypeWith[] = _("{B_DEF_ABILITY} của {B_DEF_NAME_WITH_PREFIX}\nbiến nó thành hệ {B_BUFF1}!");
static const u8 sText_PkmnPreventsParalysisWith[] = _("{B_DEF_ABILITY} của {B_EFF_NAME_WITH_PREFIX}\nngăn trạng thái tê liệt!");
static const u8 sText_PkmnPreventsRomanceWith[] = _("{B_DEF_ABILITY} của {B_DEF_NAME_WITH_PREFIX}\nngăn trạng thái say mê!");
static const u8 sText_PkmnPreventsPoisoningWith[] = _("{B_DEF_ABILITY} của {B_EFF_NAME_WITH_PREFIX}\nngăn trạng thái trúng độc!");
static const u8 sText_PkmnPreventsConfusionWith[] = _("{B_DEF_ABILITY} của {B_DEF_NAME_WITH_PREFIX}\nngăn trạng thái bối rối!");
static const u8 sText_PkmnRaisedFirePowerWith[] = _("{B_DEF_ABILITY} của {B_DEF_NAME_WITH_PREFIX}\nđã tăng sức mạnh FIRE!");
static const u8 sText_PkmnAnchorsItselfWith[] = _("{B_DEF_NAME_WITH_PREFIX} bám chặt\nnhờ {B_DEF_ABILITY}!");
static const u8 sText_PkmnCutsAttackWith[] = _("{B_SCR_ACTIVE_ABILITY} của {B_SCR_ACTIVE_NAME_WITH_PREFIX}\ngiảm ATTACK của {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnPreventsStatLossWith[] = _("{B_SCR_ACTIVE_ABILITY} của {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nngăn việc giảm chỉ số!");
static const u8 sText_PkmnHurtsWith[] = _("{B_DEF_ABILITY} của {B_DEF_NAME_WITH_PREFIX}\nlàm {B_ATK_NAME_WITH_PREFIX} bị thương!");
static const u8 sText_PkmnTraced[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX} đã TRACE\n{B_BUFF2} của {B_BUFF1}!");
static const u8 sText_PkmnsXPreventsBurns[] = _("{B_EFF_ABILITY} của {B_EFF_NAME_WITH_PREFIX}\nngăn trạng thái bỏng!");
static const u8 sText_PkmnsXBlocksY[] = _("{B_DEF_ABILITY} của {B_DEF_NAME_WITH_PREFIX}\nchặn {B_CURRENT_MOVE}!");
static const u8 sText_PkmnsXBlocksY2[] = _("{B_SCR_ACTIVE_ABILITY} của {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nchặn {B_CURRENT_MOVE}!");
static const u8 sText_PkmnsXRestoredHPALittle2[] = _("{B_ATK_ABILITY} của {B_ATK_NAME_WITH_PREFIX}\nhồi một ít HP!");
static const u8 sText_PkmnsXWhippedUpSandstorm[] = _("{B_SCR_ACTIVE_ABILITY} của {B_SCR_ACTIVE_NAME_WITH_PREFIX}\ntạo ra một cơn bão cát!");
static const u8 sText_PkmnsXIntensifiedSun[] = _("{B_SCR_ACTIVE_ABILITY} của {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nlàm ánh nắng gay gắt hơn!");
static const u8 sText_PkmnsXPreventsYLoss[] = _("{B_SCR_ACTIVE_ABILITY} của {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nngăn mất {B_BUFF1}!");
static const u8 sText_PkmnsXInfatuatedY[] = _("{B_DEF_ABILITY} của {B_DEF_NAME_WITH_PREFIX}\nlàm {B_ATK_NAME_WITH_PREFIX} say mê!");
static const u8 sText_PkmnsXMadeYIneffective[] = _("{B_DEF_ABILITY} của {B_DEF_NAME_WITH_PREFIX}\nlàm {B_CURRENT_MOVE} mất tác dụng!");
static const u8 sText_PkmnsXCuredYProblem[] = _("{B_SCR_ACTIVE_ABILITY} của {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nchữa trạng thái {B_BUFF1}!");
static const u8 sText_ItSuckedLiquidOoze[] = _("Nó đã hút phải\nLIQUID OOZE!");
static const u8 sText_PkmnTransformed[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX} đã biến hình!");
static const u8 sText_PkmnsXTookAttack[] = _("{B_DEF_ABILITY} của {B_DEF_NAME_WITH_PREFIX}\nđã đỡ đòn tấn công!");
const u8 gText_PkmnsXPreventsSwitching[] = _("{B_LAST_ABILITY} của {B_BUFF1}\nngăn việc đổi POKéMON!\p");
static const u8 sText_PreventedFromWorking[] = _("{B_DEF_ABILITY} của {B_DEF_NAME_WITH_PREFIX}\nngăn {B_BUFF1} của\l{B_SCR_ACTIVE_NAME_WITH_PREFIX} hoạt động!");
static const u8 sText_PkmnsXMadeItIneffective[] = _("{B_SCR_ACTIVE_ABILITY} của {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nlàm đòn đánh mất tác dụng!");
static const u8 sText_PkmnsXPreventsFlinching[] = _("{B_EFF_ABILITY} của {B_EFF_NAME_WITH_PREFIX}\nngăn trạng thái chùn bước!");
static const u8 sText_PkmnsXPreventsYsZ[] = _("{B_ATK_ABILITY} của {B_ATK_NAME_WITH_PREFIX}\nngăn {B_DEF_ABILITY} của\l{B_DEF_NAME_WITH_PREFIX} hoạt động!");
static const u8 sText_PkmnsXCuredItsYProblem[] = _("{B_SCR_ACTIVE_ABILITY} của {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nchữa trạng thái {B_BUFF1}!");
static const u8 sText_PkmnsXHadNoEffectOnY[] = _("{B_SCR_ACTIVE_ABILITY} của {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nkhông ảnh hưởng đến {B_EFF_NAME_WITH_PREFIX}!");
static const u8 sText_StatSharply[] = _("đã tăng mạnh!");
const u8 gText_StatRose[] = _("đã tăng!");
static const u8 sText_StatHarshly[] = _("đã giảm mạnh!");
static const u8 sText_StatFell[] = _("đã giảm!");
static const u8 sText_AttackersStatRose[] = _("{B_BUFF1}\ncủa {B_ATK_NAME_WITH_PREFIX} {B_BUFF2}");
const u8 gText_DefendersStatRose[] = _("{B_BUFF1}\ncủa {B_DEF_NAME_WITH_PREFIX} {B_BUFF2}");
static const u8 sText_UsingItemTheStatOfPkmnRose[] = _("Nhờ {B_LAST_ITEM},\n{B_BUFF1} của {B_SCR_ACTIVE_NAME_WITH_PREFIX} {B_BUFF2}");
static const u8 sText_AttackersStatFell[] = _("{B_BUFF1}\ncủa {B_ATK_NAME_WITH_PREFIX} {B_BUFF2}");
static const u8 sText_DefendersStatFell[] = _("{B_BUFF1}\ncủa {B_DEF_NAME_WITH_PREFIX} {B_BUFF2}");
static const u8 sText_StatsWontIncrease2[] = _("Chỉ số của {B_ATK_NAME_WITH_PREFIX}\nkhông thể tăng thêm!");
static const u8 sText_StatsWontDecrease2[] = _("Chỉ số của {B_DEF_NAME_WITH_PREFIX}\nkhông thể giảm thêm!");
static const u8 sText_CriticalHit[] = _("Một đòn chí mạng!");
static const u8 sText_OneHitKO[] = _("Hạ gục chỉ bằng một đòn!");
static const u8 sText_123Poof[] = _("{PAUSE 32}1, {PAUSE 15}2, và{PAUSE 15}… {PAUSE 15}… {PAUSE 15}… {PAUSE 15}{PLAY_SE SE_BALL_BOUNCE_1}Bụp!\p");
static const u8 sText_AndEllipsis[] = _("Và…\p");
static const u8 sText_HMMovesCantBeForgotten[] = _("Hiện không thể quên\nHM chiêu.\p");
static const u8 sText_NotVeryEffective[] = _("Không hiệu quả lắm…");
static const u8 sText_SuperEffective[] = _("Cực kỳ hiệu quả!");
static const u8 sText_GotAwaySafely[] = _("{PLAY_SE SE_FLEE}Đã chạy thoát an toàn!\p");
static const u8 sText_PkmnFledUsingIts[] = _("{PLAY_SE SE_FLEE}{B_ATK_NAME_WITH_PREFIX} chạy thoát\nnhờ {B_LAST_ITEM}!\p");
static const u8 sText_PkmnFledUsing[] = _("{PLAY_SE SE_FLEE}{B_ATK_NAME_WITH_PREFIX} chạy thoát\nnhờ {B_ATK_ABILITY}!\p");
static const u8 sText_WildPkmnFled[] = _("{PLAY_SE SE_FLEE}{B_BUFF1} hoang dã đã chạy mất!");
static const u8 sText_PlayerDefeatedLinkTrainer[] = _("Bạn đã đánh bại\n{B_LINK_OPPONENT1_NAME}!");
static const u8 sText_TwoLinkTrainersDefeated[] = _("Bạn đã đánh bại {B_LINK_OPPONENT1_NAME}\nvà {B_LINK_OPPONENT2_NAME}!");
static const u8 sText_PlayerLostAgainstLinkTrainer[] = _("Bạn đã thua\n{B_LINK_OPPONENT1_NAME}!");
static const u8 sText_PlayerLostToTwo[] = _("Bạn đã thua {B_LINK_OPPONENT1_NAME}\nvà {B_LINK_OPPONENT2_NAME}!");
static const u8 sText_PlayerBattledToDrawLinkTrainer[] = _("Bạn đã hòa với\n{B_LINK_OPPONENT1_NAME}!");
static const u8 sText_PlayerBattledToDrawVsTwo[] = _("Bạn đã hòa với {B_LINK_OPPONENT1_NAME}\nvà {B_LINK_OPPONENT2_NAME}!");
static const u8 sText_WildFled[] = _("{PLAY_SE SE_FLEE}{B_LINK_OPPONENT1_NAME} đã chạy mất!");
static const u8 sText_TwoWildFled[] = _("{PLAY_SE SE_FLEE}{B_LINK_OPPONENT1_NAME} và\n{B_LINK_OPPONENT2_NAME} đã chạy mất!");
static const u8 sText_NoRunningFromTrainers[] = _("Không! Không thể chạy khỏi\ntrận đấu với HLV!\p");
static const u8 sText_CantEscape[] = _("Không thể chạy thoát!\p");
static const u8 sText_DontLeaveBirch[] = _("PROF. BIRCH: Đừng bỏ ta lại thế này!\p");
static const u8 sText_ButNothingHappened[] = _("Nhưng không có gì xảy ra!");
static const u8 sText_ButItFailed[] = _("Nhưng đã thất bại!");
static const u8 sText_ItHurtConfusion[] = _("Nó tự làm mình bị thương\ntrong cơn bối rối!");
static const u8 sText_MirrorMoveFailed[] = _("MIRROR MOVE đã thất bại!");
static const u8 sText_StartedToRain[] = _("Trời bắt đầu mưa!");
static const u8 sText_DownpourStarted[] = _("Một trận mưa lớn bắt đầu!"); // corresponds to DownpourText in pokegold and pokecrystal and is used by Rain Dance in GSC
static const u8 sText_RainContinues[] = _("Mưa vẫn tiếp tục rơi.");
static const u8 sText_DownpourContinues[] = _("Mưa lớn vẫn tiếp diễn."); // unused
static const u8 sText_RainStopped[] = _("Mưa đã tạnh.");
static const u8 sText_SandstormBrewed[] = _("Một cơn bão cát nổi lên!");
static const u8 sText_SandstormRages[] = _("Bão cát đang hoành hành.");
static const u8 sText_SandstormSubsided[] = _("Bão cát đã lắng xuống.");
static const u8 sText_SunlightGotBright[] = _("Ánh nắng trở nên rực rỡ!");
static const u8 sText_SunlightStrong[] = _("Ánh nắng đang gay gắt.");
static const u8 sText_SunlightFaded[] = _("Ánh nắng đã dịu đi.");
static const u8 sText_StartedHail[] = _("HAIL bắt đầu rơi!");
static const u8 sText_HailContinues[] = _("HAIL vẫn tiếp tục rơi.");
static const u8 sText_HailStopped[] = _("HAIL đã ngừng.");
static const u8 sText_FailedToSpitUp[] = _("Nhưng không thể SPIT UP\nbất cứ thứ gì!");
static const u8 sText_FailedToSwallow[] = _("Nhưng không thể SWALLOW\nbất cứ thứ gì!");
static const u8 sText_WindBecameHeatWave[] = _("Gió đã biến thành\nHEAT WAVE!");
static const u8 sText_StatChangesGone[] = _("Mọi thay đổi chỉ số\nđã bị xóa bỏ!");
static const u8 sText_CoinsScattered[] = _("Tiền xu văng tung tóe khắp nơi!");
static const u8 sText_TooWeakForSubstitute[] = _("Nó quá yếu để tạo\nSUBSTITUTE!");
static const u8 sText_SharedPain[] = _("Hai bên đã chia sẻ\nnỗi đau!");
static const u8 sText_BellChimed[] = _("Một tiếng chuông vang lên!");
static const u8 sText_FaintInThree[] = _("Mọi POKéMON bị ảnh hưởng sẽ\nngất sau ba lượt!");
static const u8 sText_NoPPLeft[] = _("Chiêu này không còn PP!\p");
static const u8 sText_ButNoPPLeft[] = _("Nhưng chiêu không còn PP!");
static const u8 sText_PkmnIgnoresAsleep[] = _("{B_ATK_NAME_WITH_PREFIX} phớt lờ\nmệnh lệnh khi đang ngủ!");
static const u8 sText_PkmnIgnoredOrders[] = _("{B_ATK_NAME_WITH_PREFIX}\nđã phớt lờ mệnh lệnh!");
static const u8 sText_PkmnBeganToNap[] = _("{B_ATK_NAME_WITH_PREFIX} bắt đầu ngủ trưa!");
static const u8 sText_PkmnLoafing[] = _("{B_ATK_NAME_WITH_PREFIX}\nđang lười biếng!");
static const u8 sText_PkmnWontObey[] = _("{B_ATK_NAME_WITH_PREFIX}\nkhông chịu nghe lời!");
static const u8 sText_PkmnTurnedAway[] = _("{B_ATK_NAME_WITH_PREFIX} đã quay mặt đi!");
static const u8 sText_PkmnPretendNotNotice[] = _("{B_ATK_NAME_WITH_PREFIX} giả vờ\nkhông chú ý!");
static const u8 sText_EnemyAboutToSwitchPkmn[] = _("{B_TRAINER1_CLASS} {B_TRAINER1_NAME}\nsắp dùng {B_BUFF2}.\p{B_PLAYER_NAME} có đổi\nPOKéMON không?");
static const u8 sText_PkmnLearnedMove2[] = _("{B_ATK_NAME_WITH_PREFIX} đã học\n{B_BUFF1}!");
static const u8 sText_PlayerDefeatedLinkTrainerTrainer1[] = _("Bạn đã đánh bại\n{B_TRAINER1_CLASS} {B_TRAINER1_NAME}!\p");
static const u8 sText_CreptCloser[] = _("{B_PLAYER_NAME} đã tiến gần hơn đến\n{B_OPPONENT_MON1_NAME}!");
static const u8 sText_CantGetCloser[] = _("{B_PLAYER_NAME} không thể đến gần hơn!");
static const u8 sText_PkmnWatchingCarefully[] = _("{B_OPPONENT_MON1_NAME} đang\nquan sát cẩn thận!");
static const u8 sText_PkmnCuriousAboutX[] = _("{B_OPPONENT_MON1_NAME} tò mò về\n{B_BUFF1}!");
static const u8 sText_PkmnEnthralledByX[] = _("{B_OPPONENT_MON1_NAME} bị mê hoặc bởi\n{B_BUFF1}!");
static const u8 sText_PkmnIgnoredX[] = _("{B_OPPONENT_MON1_NAME} hoàn toàn phớt lờ\n{B_BUFF1}!");
static const u8 sText_ThrewPokeblockAtPkmn[] = _("{B_PLAYER_NAME} ném {POKEBLOCK}\ncho {B_OPPONENT_MON1_NAME}!");
static const u8 sText_OutOfSafariBalls[] = _("{PLAY_SE SE_DING_DONG}THÔNG BÁO: Bạn đã hết\nSAFARI BALLS! Trò chơi kết thúc!\p");
static const u8 sText_OpponentMon1Appeared[] = _("{B_OPPONENT_MON1_NAME} xuất hiện!\p");
static const u8 sText_WildPkmnAppeared[] = _("{B_OPPONENT_MON1_NAME} hoang dã xuất hiện!\p");
static const u8 sText_LegendaryPkmnAppeared[] = _("{B_OPPONENT_MON1_NAME} hoang dã xuất hiện!\p");
static const u8 sText_WildPkmnAppearedPause[] = _("{B_OPPONENT_MON1_NAME} hoang dã xuất hiện!{PAUSE 127}");
static const u8 sText_TwoWildPkmnAppeared[] = _("{B_OPPONENT_MON1_NAME} và {B_OPPONENT_MON2_NAME}\nhoang dã xuất hiện!\p");
static const u8 sText_Trainer1WantsToBattle[] = _("{B_TRAINER1_CLASS} {B_TRAINER1_NAME}\nmuốn chiến đấu!\p");
static const u8 sText_LinkTrainerWantsToBattle[] = _("{B_LINK_OPPONENT1_NAME}\nmuốn chiến đấu!");
static const u8 sText_TwoLinkTrainersWantToBattle[] = _("{B_LINK_OPPONENT1_NAME} và {B_LINK_OPPONENT2_NAME}\nmuốn chiến đấu!");
static const u8 sText_Trainer1SentOutPkmn[] = _("{B_TRAINER1_CLASS} {B_TRAINER1_NAME} đưa\n{B_OPPONENT_MON1_NAME} ra trận!");
static const u8 sText_Trainer1SentOutTwoPkmn[] = _("{B_TRAINER1_CLASS} {B_TRAINER1_NAME} đưa\n{B_OPPONENT_MON1_NAME} và {B_OPPONENT_MON2_NAME} ra trận!");
static const u8 sText_Trainer1SentOutPkmn2[] = _("{B_TRAINER1_CLASS} {B_TRAINER1_NAME} đưa\n{B_BUFF1} ra trận!");
static const u8 sText_LinkTrainerSentOutPkmn[] = _("{B_LINK_OPPONENT1_NAME} đưa\n{B_OPPONENT_MON1_NAME} ra trận!");
static const u8 sText_LinkTrainerSentOutTwoPkmn[] = _("{B_LINK_OPPONENT1_NAME} đưa\n{B_OPPONENT_MON1_NAME} và {B_OPPONENT_MON2_NAME} ra trận!");
static const u8 sText_TwoLinkTrainersSentOutPkmn[] = _("{B_LINK_OPPONENT1_NAME} đưa {B_LINK_OPPONENT_MON1_NAME} ra trận!\n{B_LINK_OPPONENT2_NAME} đưa {B_LINK_OPPONENT_MON2_NAME} ra trận!");
static const u8 sText_LinkTrainerSentOutPkmn2[] = _("{B_LINK_OPPONENT1_NAME} đưa\n{B_BUFF1} ra trận!");
static const u8 sText_LinkTrainerMultiSentOutPkmn[] = _("{B_LINK_SCR_TRAINER_NAME} đưa\n{B_BUFF1} ra trận!");
static const u8 sText_GoPkmn[] = _("Lên nào! {B_PLAYER_MON1_NAME}!");
static const u8 sText_GoTwoPkmn[] = _("Lên nào! {B_PLAYER_MON1_NAME} và\n{B_PLAYER_MON2_NAME}!");
static const u8 sText_GoPkmn2[] = _("Lên nào! {B_BUFF1}!");
static const u8 sText_DoItPkmn[] = _("Ra tay đi! {B_BUFF1}!");
static const u8 sText_GoForItPkmn[] = _("Cố lên, {B_BUFF1}!");
static const u8 sText_YourFoesWeakGetEmPkmn[] = _("Đối thủ đã yếu!\nHạ nó đi, {B_BUFF1}!");
static const u8 sText_LinkPartnerSentOutPkmnGoPkmn[] = _("{B_LINK_PARTNER_NAME} đưa {B_LINK_PLAYER_MON2_NAME} ra trận!\nLên nào! {B_LINK_PLAYER_MON1_NAME}!");
static const u8 sText_PkmnThatsEnough[] = _("{B_BUFF1}, đủ rồi!\nQuay lại đi!");
static const u8 sText_PkmnComeBack[] = _("{B_BUFF1}, quay lại!");
static const u8 sText_PkmnOkComeBack[] = _("{B_BUFF1}, được rồi!\nQuay lại đi!");
static const u8 sText_PkmnGoodComeBack[] = _("{B_BUFF1}, tốt lắm!\nQuay lại đi!");
static const u8 sText_Trainer1WithdrewPkmn[] = _("{B_TRAINER1_CLASS} {B_TRAINER1_NAME}\nthu {B_BUFF1} về!");
static const u8 sText_LinkTrainer1WithdrewPkmn[] = _("{B_LINK_OPPONENT1_NAME} thu\n{B_BUFF1} về!");
static const u8 sText_LinkTrainer2WithdrewPkmn[] = _("{B_LINK_SCR_TRAINER_NAME} thu\n{B_BUFF1} về!");
static const u8 sText_WildPkmnPrefix[] = _("Hoang dã ");
static const u8 sText_FoePkmnPrefix[] = _("Địch ");
static const u8 sText_EmptyString8[] = _("");
static const u8 sText_FoePkmnPrefix2[] = _("Địch");
static const u8 sText_AllyPkmnPrefix[] = _("Đồng minh");
static const u8 sText_FoePkmnPrefix3[] = _("Địch");
static const u8 sText_AllyPkmnPrefix2[] = _("Đồng minh");
static const u8 sText_FoePkmnPrefix4[] = _("Địch");
static const u8 sText_AllyPkmnPrefix3[] = _("Đồng minh");
static const u8 sText_AttackerUsedX[] = _("{B_ATK_NAME_WITH_PREFIX} đã dùng\n{B_BUFF2}");
static const u8 sText_ExclamationMark[] = _("!");
static const u8 sText_ExclamationMark2[] = _("!");
static const u8 sText_ExclamationMark3[] = _("!");
static const u8 sText_ExclamationMark4[] = _("!");
static const u8 sText_ExclamationMark5[] = _("!");
static const u8 sText_HP2[] = _("HP");
static const u8 sText_Attack2[] = _("ATTACK");
static const u8 sText_Defense2[] = _("DEFENSE");
static const u8 sText_Speed[] = _("SPEED");
static const u8 sText_SpAtk2[] = _("SP. ATK");
static const u8 sText_SpDef2[] = _("SP. DEF");
static const u8 sText_Accuracy[] = _("Độ chính xác");
static const u8 sText_Evasiveness[] = _("Độ né tránh");

const u8 *const gStatNamesTable[NUM_BATTLE_STATS] =
{
    [STAT_HP]      = sText_HP2,
    [STAT_ATK]     = sText_Attack2,
    [STAT_DEF]     = sText_Defense2,
    [STAT_SPEED]   = sText_Speed,
    [STAT_SPATK]   = sText_SpAtk2,
    [STAT_SPDEF]   = sText_SpDef2,
    [STAT_ACC]     = sText_Accuracy,
    [STAT_EVASION] = sText_Evasiveness,
};

static const u8 sText_PokeblockWasTooSpicy[] = _("quá cay!");
static const u8 sText_PokeblockWasTooDry[] = _("quá khô!");
static const u8 sText_PokeblockWasTooSweet[] = _("quá ngọt!");
static const u8 sText_PokeblockWasTooBitter[] = _("quá đắng!");
static const u8 sText_PokeblockWasTooSour[] = _("quá chua!");

const u8 *const gPokeblockWasTooXStringTable[FLAVOR_COUNT] =
{
    [FLAVOR_SPICY]  = sText_PokeblockWasTooSpicy,
    [FLAVOR_DRY]    = sText_PokeblockWasTooDry,
    [FLAVOR_SWEET]  = sText_PokeblockWasTooSweet,
    [FLAVOR_BITTER] = sText_PokeblockWasTooBitter,
    [FLAVOR_SOUR]   = sText_PokeblockWasTooSour
};

static const u8 sText_PlayerUsedItem[] = _("{B_PLAYER_NAME} đã dùng\n{B_LAST_ITEM}!");
static const u8 sText_WallyUsedItem[] = _("WALLY đã dùng\n{B_LAST_ITEM}!");
static const u8 sText_Trainer1UsedItem[] = _("{B_TRAINER1_CLASS} {B_TRAINER1_NAME}\nđã dùng {B_LAST_ITEM}!");
static const u8 sText_TrainerBlockedBall[] = _("HLV đã chặn BALL!");
static const u8 sText_DontBeAThief[] = _("Đừng làm kẻ trộm!");
static const u8 sText_ItDodgedBall[] = _("Nó đã né BALL được ném ra!\nKhông thể bắt POKéMON này!");
static const u8 sText_YouMissedPkmn[] = _("Bạn đã ném trượt POKéMON!");
static const u8 sText_PkmnBrokeFree[] = _("Ôi không!\nPOKéMON đã thoát ra!");
static const u8 sText_ItAppearedCaught[] = _("Tiếc quá!\nTưởng như đã bắt được rồi!");
static const u8 sText_AarghAlmostHadIt[] = _("Ôi!\nSuýt bắt được rồi!");
static const u8 sText_ShootSoClose[] = _("Tiếc thật!\nChỉ còn một chút nữa thôi!");
static const u8 sText_GotchaPkmnCaughtPlayer[] = _("Bắt được rồi!\nĐã bắt {B_OPPONENT_MON1_NAME}!{WAIT_SE}{PLAY_BGM MUS_CAUGHT}\p");
static const u8 sText_GotchaPkmnCaughtWally[] = _("Bắt được rồi!\nĐã bắt {B_OPPONENT_MON1_NAME}!{WAIT_SE}{PLAY_BGM MUS_CAUGHT}{PAUSE 127}");
static const u8 sText_GiveNicknameCaptured[] = _("Đặt tên cho {B_OPPONENT_MON1_NAME}\nvừa bắt không?");
static const u8 sText_PkmnSentToPC[] = _("{B_OPPONENT_MON1_NAME} được gửi đến\nPC của {B_PC_CREATOR_NAME}.");
static const u8 sText_Someones[] = _("ai đó");
static const u8 sText_Lanettes[] = _("LANETTE");
static const u8 sText_PkmnDataAddedToDex[] = _("Dữ liệu của {B_OPPONENT_MON1_NAME}\nđã được thêm vào POKéDEX.\p");
static const u8 sText_ItIsRaining[] = _("Trời đang mưa.");
static const u8 sText_SandstormIsRaging[] = _("Bão cát đang hoành hành.");
static const u8 sText_BoxIsFull[] = _("BOX đã đầy!\nBạn không thể bắt thêm!\p");
static const u8 sText_EnigmaBerry[] = _("ENIGMA BERRY");
static const u8 sText_BerrySuffix[] = _(" BERRY");
static const u8 sText_PkmnsItemCuredParalysis[] = _("{B_LAST_ITEM} của {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nđã chữa tê liệt!");
static const u8 sText_PkmnsItemCuredPoison[] = _("{B_LAST_ITEM} của {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nđã chữa trúng độc!");
static const u8 sText_PkmnsItemHealedBurn[] = _("{B_LAST_ITEM} của {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nđã chữa bỏng!");
static const u8 sText_PkmnsItemDefrostedIt[] = _("{B_LAST_ITEM} của {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nđã làm tan băng!");
static const u8 sText_PkmnsItemWokeIt[] = _("{B_LAST_ITEM} của {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nđã đánh thức nó!");
static const u8 sText_PkmnsItemSnappedOut[] = _("{B_LAST_ITEM} của {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nđã chữa bối rối!");
static const u8 sText_PkmnsItemCuredProblem[] = _("{B_LAST_ITEM} của {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nđã chữa trạng thái {B_BUFF1}!");
static const u8 sText_PkmnsItemNormalizedStatus[] = _("{B_LAST_ITEM} của {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nđã phục hồi trạng thái!");
static const u8 sText_PkmnsItemRestoredHealth[] = _("{B_LAST_ITEM} của {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nđã hồi phục HP!");
static const u8 sText_PkmnsItemRestoredPP[] = _("{B_LAST_ITEM} của {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nđã hồi PP cho {B_BUFF1}!");
static const u8 sText_PkmnsItemRestoredStatus[] = _("{B_LAST_ITEM} của {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nđã phục hồi trạng thái!");
static const u8 sText_PkmnsItemRestoredHPALittle[] = _("{B_LAST_ITEM} của {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nđã hồi một ít HP!");
static const u8 sText_ItemAllowsOnlyYMove[] = _("{B_LAST_ITEM} chỉ cho phép\ndùng {B_CURRENT_MOVE}!\p");
static const u8 sText_PkmnHungOnWithX[] = _("{B_DEF_NAME_WITH_PREFIX} trụ lại\nnhờ {B_LAST_ITEM}!");
const u8 gText_EmptyString3[] = _("");
static const u8 sText_YouThrowABallNowRight[] = _("Giờ cậu ném BALL, đúng không?\nTớ… Tớ sẽ cố hết sức!");
static const u8 sText_PlayerLostToEnemyTrainer[] = _("{B_PLAYER_NAME} không còn POKéMON\ncó thể chiến đấu!\pNgười chơi đã thua\n{B_TRAINER1_CLASS} {B_TRAINER1_NAME}!{PAUSE_UNTIL_PRESS}");
static const u8 sText_PlayerPaidPrizeMoney[] = _("{B_PLAYER_NAME} trả ¥{B_BUFF1} tiền thưởng…\p… … … …\p{B_PLAYER_NAME} đã kiệt sức!{PAUSE_UNTIL_PRESS}");
static const u8 sText_PlayerWhiteoutNoMoney[] = _("… … … …\p{B_PLAYER_NAME} đã kiệt sức!{PAUSE_UNTIL_PRESS}");
static const u8 sText_PkmnsAbilityActivated[] = _("{B_LAST_ABILITY} của\n{B_SCR_ACTIVE_NAME_WITH_PREFIX} đã kích hoạt!");
static const u8 sText_PkmnsAbilityRestoredHP[] = _("{B_LAST_ABILITY} của {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nđã hồi HP!");
static const u8 sText_PkmnHurtByAbility[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX} bị thương\ndo {B_LAST_ABILITY}!");
static const u8 sText_PkmnShuddered[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX} rùng mình!");
static const u8 sText_PkmnFriskedItem[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX} phát hiện\n{B_LAST_ITEM} của {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnFriskedTwoItems[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX} phát hiện\n{B_BUFF1} và {B_BUFF2} của đối thủ!");
static const u8 sText_PkmnRecoveredItem[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}\nđã lấy lại {B_LAST_ITEM}!");
static const u8 sText_PkmnMoveBouncedBack[] = _("{B_DEF_ABILITY} của {B_DEF_NAME_WITH_PREFIX}\nphản lại {B_CURRENT_MOVE}!");

// early declaration of strings
static const u8 sText_PkmnIncapableOfPower[];
static const u8 sText_GlintAppearsInEye[];
static const u8 sText_PkmnGettingIntoPosition[];
static const u8 sText_PkmnBeganGrowlingDeeply[];
static const u8 sText_PkmnEagerForMore[];
static const u8 sText_DefeatedOpponentByReferee[];
static const u8 sText_LostToOpponentByReferee[];
static const u8 sText_TiedOpponentByReferee[];
static const u8 sText_QuestionForfeitMatch[];
static const u8 sText_ForfeitedMatch[];
static const u8 sText_Trainer1WinText[];
static const u8 sText_Trainer2WinText[];
static const u8 sText_TwoInGameTrainersDefeated[];
static const u8 sText_Trainer2LoseText[];

const u8 *const gBattleStringsTable[BATTLESTRINGS_COUNT - BATTLESTRINGS_TABLE_START] =
{
    [STRINGID_TRAINER1LOSETEXT - BATTLESTRINGS_TABLE_START] = sText_Trainer1LoseText,
    [STRINGID_PKMNGAINEDEXP - BATTLESTRINGS_TABLE_START] = sText_PkmnGainedEXP,
    [STRINGID_PKMNGREWTOLV - BATTLESTRINGS_TABLE_START] = sText_PkmnGrewToLv,
    [STRINGID_PKMNLEARNEDMOVE - BATTLESTRINGS_TABLE_START] = sText_PkmnLearnedMove,
    [STRINGID_TRYTOLEARNMOVE1 - BATTLESTRINGS_TABLE_START] = sText_TryToLearnMove1,
    [STRINGID_TRYTOLEARNMOVE2 - BATTLESTRINGS_TABLE_START] = sText_TryToLearnMove2,
    [STRINGID_TRYTOLEARNMOVE3 - BATTLESTRINGS_TABLE_START] = sText_TryToLearnMove3,
    [STRINGID_PKMNFORGOTMOVE - BATTLESTRINGS_TABLE_START] = sText_PkmnForgotMove,
    [STRINGID_STOPLEARNINGMOVE - BATTLESTRINGS_TABLE_START] = sText_StopLearningMove,
    [STRINGID_DIDNOTLEARNMOVE - BATTLESTRINGS_TABLE_START] = sText_DidNotLearnMove,
    [STRINGID_PKMNLEARNEDMOVE2 - BATTLESTRINGS_TABLE_START] = sText_PkmnLearnedMove2,
    [STRINGID_ATTACKMISSED - BATTLESTRINGS_TABLE_START] = sText_AttackMissed,
    [STRINGID_PKMNPROTECTEDITSELF - BATTLESTRINGS_TABLE_START] = sText_PkmnProtectedItself,
    [STRINGID_STATSWONTINCREASE2 - BATTLESTRINGS_TABLE_START] = sText_StatsWontIncrease2,
    [STRINGID_AVOIDEDDAMAGE - BATTLESTRINGS_TABLE_START] = sText_AvoidedDamage,
    [STRINGID_ITDOESNTAFFECT - BATTLESTRINGS_TABLE_START] = sText_ItDoesntAffect,
    [STRINGID_ATTACKERFAINTED - BATTLESTRINGS_TABLE_START] = sText_AttackerFainted,
    [STRINGID_TARGETFAINTED - BATTLESTRINGS_TABLE_START] = sText_TargetFainted,
    [STRINGID_PLAYERGOTMONEY - BATTLESTRINGS_TABLE_START] = sText_PlayerGotMoney,
    [STRINGID_PLAYERWHITEOUT - BATTLESTRINGS_TABLE_START] = sText_PlayerWhiteout,
    [STRINGID_PLAYERWHITEOUT2 - BATTLESTRINGS_TABLE_START] = sText_PlayerWhiteout2,
    [STRINGID_PREVENTSESCAPE - BATTLESTRINGS_TABLE_START] = sText_PreventsEscape,
    [STRINGID_HITXTIMES - BATTLESTRINGS_TABLE_START] = sText_HitXTimes,
    [STRINGID_PKMNFELLASLEEP - BATTLESTRINGS_TABLE_START] = sText_PkmnFellAsleep,
    [STRINGID_PKMNMADESLEEP - BATTLESTRINGS_TABLE_START] = sText_PkmnMadeSleep,
    [STRINGID_PKMNALREADYASLEEP - BATTLESTRINGS_TABLE_START] = sText_PkmnAlreadyAsleep,
    [STRINGID_PKMNALREADYASLEEP2 - BATTLESTRINGS_TABLE_START] = sText_PkmnAlreadyAsleep2,
    [STRINGID_PKMNWASNTAFFECTED - BATTLESTRINGS_TABLE_START] = sText_PkmnWasntAffected,
    [STRINGID_PKMNWASPOISONED - BATTLESTRINGS_TABLE_START] = sText_PkmnWasPoisoned,
    [STRINGID_PKMNPOISONEDBY - BATTLESTRINGS_TABLE_START] = sText_PkmnPoisonedBy,
    [STRINGID_PKMNHURTBYPOISON - BATTLESTRINGS_TABLE_START] = sText_PkmnHurtByPoison,
    [STRINGID_PKMNALREADYPOISONED - BATTLESTRINGS_TABLE_START] = sText_PkmnAlreadyPoisoned,
    [STRINGID_PKMNBADLYPOISONED - BATTLESTRINGS_TABLE_START] = sText_PkmnBadlyPoisoned,
    [STRINGID_PKMNENERGYDRAINED - BATTLESTRINGS_TABLE_START] = sText_PkmnEnergyDrained,
    [STRINGID_PKMNWASBURNED - BATTLESTRINGS_TABLE_START] = sText_PkmnWasBurned,
    [STRINGID_PKMNBURNEDBY - BATTLESTRINGS_TABLE_START] = sText_PkmnBurnedBy,
    [STRINGID_PKMNHURTBYBURN - BATTLESTRINGS_TABLE_START] = sText_PkmnHurtByBurn,
    [STRINGID_PKMNWASFROZEN - BATTLESTRINGS_TABLE_START] = sText_PkmnWasFrozen,
    [STRINGID_PKMNFROZENBY - BATTLESTRINGS_TABLE_START] = sText_PkmnFrozenBy,
    [STRINGID_PKMNISFROZEN - BATTLESTRINGS_TABLE_START] = sText_PkmnIsFrozen,
    [STRINGID_PKMNWASDEFROSTED - BATTLESTRINGS_TABLE_START] = sText_PkmnWasDefrosted,
    [STRINGID_PKMNWASDEFROSTED2 - BATTLESTRINGS_TABLE_START] = sText_PkmnWasDefrosted2,
    [STRINGID_PKMNWASDEFROSTEDBY - BATTLESTRINGS_TABLE_START] = sText_PkmnWasDefrostedBy,
    [STRINGID_PKMNWASPARALYZED - BATTLESTRINGS_TABLE_START] = sText_PkmnWasParalyzed,
    [STRINGID_PKMNWASPARALYZEDBY - BATTLESTRINGS_TABLE_START] = sText_PkmnWasParalyzedBy,
    [STRINGID_PKMNISPARALYZED - BATTLESTRINGS_TABLE_START] = sText_PkmnIsParalyzed,
    [STRINGID_PKMNISALREADYPARALYZED - BATTLESTRINGS_TABLE_START] = sText_PkmnIsAlreadyParalyzed,
    [STRINGID_PKMNHEALEDPARALYSIS - BATTLESTRINGS_TABLE_START] = sText_PkmnHealedParalysis,
    [STRINGID_PKMNDREAMEATEN - BATTLESTRINGS_TABLE_START] = sText_PkmnDreamEaten,
    [STRINGID_STATSWONTINCREASE - BATTLESTRINGS_TABLE_START] = sText_StatsWontIncrease,
    [STRINGID_STATSWONTDECREASE - BATTLESTRINGS_TABLE_START] = sText_StatsWontDecrease,
    [STRINGID_TEAMSTOPPEDWORKING - BATTLESTRINGS_TABLE_START] = sText_TeamStoppedWorking,
    [STRINGID_FOESTOPPEDWORKING - BATTLESTRINGS_TABLE_START] = sText_FoeStoppedWorking,
    [STRINGID_PKMNISCONFUSED - BATTLESTRINGS_TABLE_START] = sText_PkmnIsConfused,
    [STRINGID_PKMNHEALEDCONFUSION - BATTLESTRINGS_TABLE_START] = sText_PkmnHealedConfusion,
    [STRINGID_PKMNWASCONFUSED - BATTLESTRINGS_TABLE_START] = sText_PkmnWasConfused,
    [STRINGID_PKMNALREADYCONFUSED - BATTLESTRINGS_TABLE_START] = sText_PkmnAlreadyConfused,
    [STRINGID_PKMNFELLINLOVE - BATTLESTRINGS_TABLE_START] = sText_PkmnFellInLove,
    [STRINGID_PKMNINLOVE - BATTLESTRINGS_TABLE_START] = sText_PkmnInLove,
    [STRINGID_PKMNIMMOBILIZEDBYLOVE - BATTLESTRINGS_TABLE_START] = sText_PkmnImmobilizedByLove,
    [STRINGID_PKMNBLOWNAWAY - BATTLESTRINGS_TABLE_START] = sText_PkmnBlownAway,
    [STRINGID_PKMNCHANGEDTYPE - BATTLESTRINGS_TABLE_START] = sText_PkmnChangedType,
    [STRINGID_PKMNFLINCHED - BATTLESTRINGS_TABLE_START] = sText_PkmnFlinched,
    [STRINGID_PKMNREGAINEDHEALTH - BATTLESTRINGS_TABLE_START] = sText_PkmnRegainedHealth,
    [STRINGID_PKMNHPFULL - BATTLESTRINGS_TABLE_START] = sText_PkmnHPFull,
    [STRINGID_PKMNRAISEDSPDEF - BATTLESTRINGS_TABLE_START] = sText_PkmnRaisedSpDef,
    [STRINGID_PKMNRAISEDDEF - BATTLESTRINGS_TABLE_START] = sText_PkmnRaisedDef,
    [STRINGID_PKMNCOVEREDBYVEIL - BATTLESTRINGS_TABLE_START] = sText_PkmnCoveredByVeil,
    [STRINGID_PKMNUSEDSAFEGUARD - BATTLESTRINGS_TABLE_START] = sText_PkmnUsedSafeguard,
    [STRINGID_PKMNSAFEGUARDEXPIRED - BATTLESTRINGS_TABLE_START] = sText_PkmnSafeguardExpired,
    [STRINGID_PKMNWENTTOSLEEP - BATTLESTRINGS_TABLE_START] = sText_PkmnWentToSleep,
    [STRINGID_PKMNSLEPTHEALTHY - BATTLESTRINGS_TABLE_START] = sText_PkmnSleptHealthy,
    [STRINGID_PKMNWHIPPEDWHIRLWIND - BATTLESTRINGS_TABLE_START] = sText_PkmnWhippedWhirlwind,
    [STRINGID_PKMNTOOKSUNLIGHT - BATTLESTRINGS_TABLE_START] = sText_PkmnTookSunlight,
    [STRINGID_PKMNLOWEREDHEAD - BATTLESTRINGS_TABLE_START] = sText_PkmnLoweredHead,
    [STRINGID_PKMNISGLOWING - BATTLESTRINGS_TABLE_START] = sText_PkmnIsGlowing,
    [STRINGID_PKMNFLEWHIGH - BATTLESTRINGS_TABLE_START] = sText_PkmnFlewHigh,
    [STRINGID_PKMNDUGHOLE - BATTLESTRINGS_TABLE_START] = sText_PkmnDugHole,
    [STRINGID_PKMNSQUEEZEDBYBIND - BATTLESTRINGS_TABLE_START] = sText_PkmnSqueezedByBind,
    [STRINGID_PKMNTRAPPEDINVORTEX - BATTLESTRINGS_TABLE_START] = sText_PkmnTrappedInVortex,
    [STRINGID_PKMNWRAPPEDBY - BATTLESTRINGS_TABLE_START] = sText_PkmnWrappedBy,
    [STRINGID_PKMNCLAMPED - BATTLESTRINGS_TABLE_START] = sText_PkmnClamped,
    [STRINGID_PKMNHURTBY - BATTLESTRINGS_TABLE_START] = sText_PkmnHurtBy,
    [STRINGID_PKMNFREEDFROM - BATTLESTRINGS_TABLE_START] = sText_PkmnFreedFrom,
    [STRINGID_PKMNCRASHED - BATTLESTRINGS_TABLE_START] = sText_PkmnCrashed,
    [STRINGID_PKMNSHROUDEDINMIST - BATTLESTRINGS_TABLE_START] = gText_PkmnShroudedInMist,
    [STRINGID_PKMNPROTECTEDBYMIST - BATTLESTRINGS_TABLE_START] = sText_PkmnProtectedByMist,
    [STRINGID_PKMNGETTINGPUMPED - BATTLESTRINGS_TABLE_START] = gText_PkmnGettingPumped,
    [STRINGID_PKMNHITWITHRECOIL - BATTLESTRINGS_TABLE_START] = sText_PkmnHitWithRecoil,
    [STRINGID_PKMNPROTECTEDITSELF2 - BATTLESTRINGS_TABLE_START] = sText_PkmnProtectedItself2,
    [STRINGID_PKMNBUFFETEDBYSANDSTORM - BATTLESTRINGS_TABLE_START] = sText_PkmnBuffetedBySandstorm,
    [STRINGID_PKMNPELTEDBYHAIL - BATTLESTRINGS_TABLE_START] = sText_PkmnPeltedByHail,
    [STRINGID_PKMNSEEDED - BATTLESTRINGS_TABLE_START] = sText_PkmnSeeded,
    [STRINGID_PKMNEVADEDATTACK - BATTLESTRINGS_TABLE_START] = sText_PkmnEvadedAttack,
    [STRINGID_PKMNSAPPEDBYLEECHSEED - BATTLESTRINGS_TABLE_START] = sText_PkmnSappedByLeechSeed,
    [STRINGID_PKMNFASTASLEEP - BATTLESTRINGS_TABLE_START] = sText_PkmnFastAsleep,
    [STRINGID_PKMNWOKEUP - BATTLESTRINGS_TABLE_START] = sText_PkmnWokeUp,
    [STRINGID_PKMNUPROARKEPTAWAKE - BATTLESTRINGS_TABLE_START] = sText_PkmnUproarKeptAwake,
    [STRINGID_PKMNWOKEUPINUPROAR - BATTLESTRINGS_TABLE_START] = sText_PkmnWokeUpInUproar,
    [STRINGID_PKMNCAUSEDUPROAR - BATTLESTRINGS_TABLE_START] = sText_PkmnCausedUproar,
    [STRINGID_PKMNMAKINGUPROAR - BATTLESTRINGS_TABLE_START] = sText_PkmnMakingUproar,
    [STRINGID_PKMNCALMEDDOWN - BATTLESTRINGS_TABLE_START] = sText_PkmnCalmedDown,
    [STRINGID_PKMNCANTSLEEPINUPROAR - BATTLESTRINGS_TABLE_START] = sText_PkmnCantSleepInUproar,
    [STRINGID_PKMNSTOCKPILED - BATTLESTRINGS_TABLE_START] = sText_PkmnStockpiled,
    [STRINGID_PKMNCANTSTOCKPILE - BATTLESTRINGS_TABLE_START] = sText_PkmnCantStockpile,
    [STRINGID_PKMNCANTSLEEPINUPROAR2 - BATTLESTRINGS_TABLE_START] = sText_PkmnCantSleepInUproar2,
    [STRINGID_UPROARKEPTPKMNAWAKE - BATTLESTRINGS_TABLE_START] = sText_UproarKeptPkmnAwake,
    [STRINGID_PKMNSTAYEDAWAKEUSING - BATTLESTRINGS_TABLE_START] = sText_PkmnStayedAwakeUsing,
    [STRINGID_PKMNSTORINGENERGY - BATTLESTRINGS_TABLE_START] = sText_PkmnStoringEnergy,
    [STRINGID_PKMNUNLEASHEDENERGY - BATTLESTRINGS_TABLE_START] = sText_PkmnUnleashedEnergy,
    [STRINGID_PKMNFATIGUECONFUSION - BATTLESTRINGS_TABLE_START] = sText_PkmnFatigueConfusion,
    [STRINGID_PLAYERPICKEDUPMONEY - BATTLESTRINGS_TABLE_START] = sText_PlayerPickedUpMoney,
    [STRINGID_PKMNUNAFFECTED - BATTLESTRINGS_TABLE_START] = sText_PkmnUnaffected,
    [STRINGID_PKMNTRANSFORMEDINTO - BATTLESTRINGS_TABLE_START] = sText_PkmnTransformedInto,
    [STRINGID_PKMNMADESUBSTITUTE - BATTLESTRINGS_TABLE_START] = sText_PkmnMadeSubstitute,
    [STRINGID_PKMNHASSUBSTITUTE - BATTLESTRINGS_TABLE_START] = sText_PkmnHasSubstitute,
    [STRINGID_SUBSTITUTEDAMAGED - BATTLESTRINGS_TABLE_START] = sText_SubstituteDamaged,
    [STRINGID_PKMNSUBSTITUTEFADED - BATTLESTRINGS_TABLE_START] = sText_PkmnSubstituteFaded,
    [STRINGID_PKMNMUSTRECHARGE - BATTLESTRINGS_TABLE_START] = sText_PkmnMustRecharge,
    [STRINGID_PKMNRAGEBUILDING - BATTLESTRINGS_TABLE_START] = sText_PkmnRageBuilding,
    [STRINGID_PKMNMOVEWASDISABLED - BATTLESTRINGS_TABLE_START] = sText_PkmnMoveWasDisabled,
    [STRINGID_PKMNMOVEISDISABLED - BATTLESTRINGS_TABLE_START] = sText_PkmnMoveIsDisabled,
    [STRINGID_PKMNMOVEDISABLEDNOMORE - BATTLESTRINGS_TABLE_START] = sText_PkmnMoveDisabledNoMore,
    [STRINGID_PKMNGOTENCORE - BATTLESTRINGS_TABLE_START] = sText_PkmnGotEncore,
    [STRINGID_PKMNENCOREENDED - BATTLESTRINGS_TABLE_START] = sText_PkmnEncoreEnded,
    [STRINGID_PKMNTOOKAIM - BATTLESTRINGS_TABLE_START] = sText_PkmnTookAim,
    [STRINGID_PKMNSKETCHEDMOVE - BATTLESTRINGS_TABLE_START] = sText_PkmnSketchedMove,
    [STRINGID_PKMNTRYINGTOTAKEFOE - BATTLESTRINGS_TABLE_START] = sText_PkmnTryingToTakeFoe,
    [STRINGID_PKMNTOOKFOE - BATTLESTRINGS_TABLE_START] = sText_PkmnTookFoe,
    [STRINGID_PKMNREDUCEDPP - BATTLESTRINGS_TABLE_START] = sText_PkmnReducedPP,
    [STRINGID_PKMNSTOLEITEM - BATTLESTRINGS_TABLE_START] = sText_PkmnStoleItem,
    [STRINGID_TARGETCANTESCAPENOW - BATTLESTRINGS_TABLE_START] = sText_TargetCantEscapeNow,
    [STRINGID_PKMNFELLINTONIGHTMARE - BATTLESTRINGS_TABLE_START] = sText_PkmnFellIntoNightmare,
    [STRINGID_PKMNLOCKEDINNIGHTMARE - BATTLESTRINGS_TABLE_START] = sText_PkmnLockedInNightmare,
    [STRINGID_PKMNLAIDCURSE - BATTLESTRINGS_TABLE_START] = sText_PkmnLaidCurse,
    [STRINGID_PKMNAFFLICTEDBYCURSE - BATTLESTRINGS_TABLE_START] = sText_PkmnAfflictedByCurse,
    [STRINGID_SPIKESSCATTERED - BATTLESTRINGS_TABLE_START] = sText_SpikesScattered,
    [STRINGID_PKMNHURTBYSPIKES - BATTLESTRINGS_TABLE_START] = sText_PkmnHurtBySpikes,
    [STRINGID_PKMNIDENTIFIED - BATTLESTRINGS_TABLE_START] = sText_PkmnIdentified,
    [STRINGID_PKMNPERISHCOUNTFELL - BATTLESTRINGS_TABLE_START] = sText_PkmnPerishCountFell,
    [STRINGID_PKMNBRACEDITSELF - BATTLESTRINGS_TABLE_START] = sText_PkmnBracedItself,
    [STRINGID_PKMNENDUREDHIT - BATTLESTRINGS_TABLE_START] = sText_PkmnEnduredHit,
    [STRINGID_MAGNITUDESTRENGTH - BATTLESTRINGS_TABLE_START] = sText_MagnitudeStrength,
    [STRINGID_PKMNCUTHPMAXEDATTACK - BATTLESTRINGS_TABLE_START] = sText_PkmnCutHPMaxedAttack,
    [STRINGID_PKMNCOPIEDSTATCHANGES - BATTLESTRINGS_TABLE_START] = sText_PkmnCopiedStatChanges,
    [STRINGID_PKMNGOTFREE - BATTLESTRINGS_TABLE_START] = sText_PkmnGotFree,
    [STRINGID_PKMNSHEDLEECHSEED - BATTLESTRINGS_TABLE_START] = sText_PkmnShedLeechSeed,
    [STRINGID_PKMNBLEWAWAYSPIKES - BATTLESTRINGS_TABLE_START] = sText_PkmnBlewAwaySpikes,
    [STRINGID_PKMNFLEDFROMBATTLE - BATTLESTRINGS_TABLE_START] = sText_PkmnFledFromBattle,
    [STRINGID_PKMNFORESAWATTACK - BATTLESTRINGS_TABLE_START] = sText_PkmnForesawAttack,
    [STRINGID_PKMNTOOKATTACK - BATTLESTRINGS_TABLE_START] = sText_PkmnTookAttack,
    [STRINGID_PKMNATTACK - BATTLESTRINGS_TABLE_START] = sText_PkmnAttack,
    [STRINGID_PKMNCENTERATTENTION - BATTLESTRINGS_TABLE_START] = sText_PkmnCenterAttention,
    [STRINGID_PKMNCHARGINGPOWER - BATTLESTRINGS_TABLE_START] = sText_PkmnChargingPower,
    [STRINGID_NATUREPOWERTURNEDINTO - BATTLESTRINGS_TABLE_START] = sText_NaturePowerTurnedInto,
    [STRINGID_PKMNSTATUSNORMAL - BATTLESTRINGS_TABLE_START] = sText_PkmnStatusNormal,
    [STRINGID_PKMNHASNOMOVESLEFT - BATTLESTRINGS_TABLE_START] = sText_PkmnHasNoMovesLeft,
    [STRINGID_PKMNSUBJECTEDTOTORMENT - BATTLESTRINGS_TABLE_START] = sText_PkmnSubjectedToTorment,
    [STRINGID_PKMNCANTUSEMOVETORMENT - BATTLESTRINGS_TABLE_START] = sText_PkmnCantUseMoveTorment,
    [STRINGID_PKMNTIGHTENINGFOCUS - BATTLESTRINGS_TABLE_START] = sText_PkmnTighteningFocus,
    [STRINGID_PKMNFELLFORTAUNT - BATTLESTRINGS_TABLE_START] = sText_PkmnFellForTaunt,
    [STRINGID_PKMNCANTUSEMOVETAUNT - BATTLESTRINGS_TABLE_START] = sText_PkmnCantUseMoveTaunt,
    [STRINGID_PKMNREADYTOHELP - BATTLESTRINGS_TABLE_START] = sText_PkmnReadyToHelp,
    [STRINGID_PKMNSWITCHEDITEMS - BATTLESTRINGS_TABLE_START] = sText_PkmnSwitchedItems,
    [STRINGID_PKMNCOPIEDFOE - BATTLESTRINGS_TABLE_START] = sText_PkmnCopiedFoe,
    [STRINGID_PKMNMADEWISH - BATTLESTRINGS_TABLE_START] = sText_PkmnMadeWish,
    [STRINGID_PKMNWISHCAMETRUE - BATTLESTRINGS_TABLE_START] = sText_PkmnWishCameTrue,
    [STRINGID_PKMNPLANTEDROOTS - BATTLESTRINGS_TABLE_START] = sText_PkmnPlantedRoots,
    [STRINGID_PKMNABSORBEDNUTRIENTS - BATTLESTRINGS_TABLE_START] = sText_PkmnAbsorbedNutrients,
    [STRINGID_PKMNANCHOREDITSELF - BATTLESTRINGS_TABLE_START] = sText_PkmnAnchoredItself,
    [STRINGID_PKMNWASMADEDROWSY - BATTLESTRINGS_TABLE_START] = sText_PkmnWasMadeDrowsy,
    [STRINGID_PKMNKNOCKEDOFF - BATTLESTRINGS_TABLE_START] = sText_PkmnKnockedOff,
    [STRINGID_PKMNSWAPPEDABILITIES - BATTLESTRINGS_TABLE_START] = sText_PkmnSwappedAbilities,
    [STRINGID_PKMNSEALEDOPPONENTMOVE - BATTLESTRINGS_TABLE_START] = sText_PkmnSealedOpponentMove,
    [STRINGID_PKMNCANTUSEMOVESEALED - BATTLESTRINGS_TABLE_START] = sText_PkmnCantUseMoveSealed,
    [STRINGID_PKMNWANTSGRUDGE - BATTLESTRINGS_TABLE_START] = sText_PkmnWantsGrudge,
    [STRINGID_PKMNLOSTPPGRUDGE - BATTLESTRINGS_TABLE_START] = sText_PkmnLostPPGrudge,
    [STRINGID_PKMNSHROUDEDITSELF - BATTLESTRINGS_TABLE_START] = sText_PkmnShroudedItself,
    [STRINGID_PKMNMOVEBOUNCED - BATTLESTRINGS_TABLE_START] = sText_PkmnMoveBounced,
    [STRINGID_PKMNWAITSFORTARGET - BATTLESTRINGS_TABLE_START] = sText_PkmnWaitsForTarget,
    [STRINGID_PKMNSNATCHEDMOVE - BATTLESTRINGS_TABLE_START] = sText_PkmnSnatchedMove,
    [STRINGID_PKMNMADEITRAIN - BATTLESTRINGS_TABLE_START] = sText_PkmnMadeItRain,
    [STRINGID_PKMNRAISEDSPEED - BATTLESTRINGS_TABLE_START] = sText_PkmnRaisedSpeed,
    [STRINGID_PKMNPROTECTEDBY - BATTLESTRINGS_TABLE_START] = sText_PkmnProtectedBy,
    [STRINGID_PKMNPREVENTSUSAGE - BATTLESTRINGS_TABLE_START] = sText_PkmnPreventsUsage,
    [STRINGID_PKMNRESTOREDHPUSING - BATTLESTRINGS_TABLE_START] = sText_PkmnRestoredHPUsing,
    [STRINGID_PKMNCHANGEDTYPEWITH - BATTLESTRINGS_TABLE_START] = sText_PkmnChangedTypeWith,
    [STRINGID_PKMNPREVENTSPARALYSISWITH - BATTLESTRINGS_TABLE_START] = sText_PkmnPreventsParalysisWith,
    [STRINGID_PKMNPREVENTSROMANCEWITH - BATTLESTRINGS_TABLE_START] = sText_PkmnPreventsRomanceWith,
    [STRINGID_PKMNPREVENTSPOISONINGWITH - BATTLESTRINGS_TABLE_START] = sText_PkmnPreventsPoisoningWith,
    [STRINGID_PKMNPREVENTSCONFUSIONWITH - BATTLESTRINGS_TABLE_START] = sText_PkmnPreventsConfusionWith,
    [STRINGID_PKMNRAISEDFIREPOWERWITH - BATTLESTRINGS_TABLE_START] = sText_PkmnRaisedFirePowerWith,
    [STRINGID_PKMNANCHORSITSELFWITH - BATTLESTRINGS_TABLE_START] = sText_PkmnAnchorsItselfWith,
    [STRINGID_PKMNCUTSATTACKWITH - BATTLESTRINGS_TABLE_START] = sText_PkmnCutsAttackWith,
    [STRINGID_PKMNPREVENTSSTATLOSSWITH - BATTLESTRINGS_TABLE_START] = sText_PkmnPreventsStatLossWith,
    [STRINGID_PKMNHURTSWITH - BATTLESTRINGS_TABLE_START] = sText_PkmnHurtsWith,
    [STRINGID_PKMNTRACED - BATTLESTRINGS_TABLE_START] = sText_PkmnTraced,
    [STRINGID_STATSHARPLY - BATTLESTRINGS_TABLE_START] = sText_StatSharply,
    [STRINGID_STATROSE - BATTLESTRINGS_TABLE_START] = gText_StatRose,
    [STRINGID_STATHARSHLY - BATTLESTRINGS_TABLE_START] = sText_StatHarshly,
    [STRINGID_STATFELL - BATTLESTRINGS_TABLE_START] = sText_StatFell,
    [STRINGID_ATTACKERSSTATROSE - BATTLESTRINGS_TABLE_START] = sText_AttackersStatRose,
    [STRINGID_DEFENDERSSTATROSE - BATTLESTRINGS_TABLE_START] = gText_DefendersStatRose,
    [STRINGID_ATTACKERSSTATFELL - BATTLESTRINGS_TABLE_START] = sText_AttackersStatFell,
    [STRINGID_DEFENDERSSTATFELL - BATTLESTRINGS_TABLE_START] = sText_DefendersStatFell,
    [STRINGID_CRITICALHIT - BATTLESTRINGS_TABLE_START] = sText_CriticalHit,
    [STRINGID_ONEHITKO - BATTLESTRINGS_TABLE_START] = sText_OneHitKO,
    [STRINGID_123POOF - BATTLESTRINGS_TABLE_START] = sText_123Poof,
    [STRINGID_ANDELLIPSIS - BATTLESTRINGS_TABLE_START] = sText_AndEllipsis,
    [STRINGID_NOTVERYEFFECTIVE - BATTLESTRINGS_TABLE_START] = sText_NotVeryEffective,
    [STRINGID_SUPEREFFECTIVE - BATTLESTRINGS_TABLE_START] = sText_SuperEffective,
    [STRINGID_GOTAWAYSAFELY - BATTLESTRINGS_TABLE_START] = sText_GotAwaySafely,
    [STRINGID_WILDPKMNFLED - BATTLESTRINGS_TABLE_START] = sText_WildPkmnFled,
    [STRINGID_NORUNNINGFROMTRAINERS - BATTLESTRINGS_TABLE_START] = sText_NoRunningFromTrainers,
    [STRINGID_CANTESCAPE - BATTLESTRINGS_TABLE_START] = sText_CantEscape,
    [STRINGID_DONTLEAVEBIRCH - BATTLESTRINGS_TABLE_START] = sText_DontLeaveBirch,
    [STRINGID_BUTNOTHINGHAPPENED - BATTLESTRINGS_TABLE_START] = sText_ButNothingHappened,
    [STRINGID_BUTITFAILED - BATTLESTRINGS_TABLE_START] = sText_ButItFailed,
    [STRINGID_ITHURTCONFUSION - BATTLESTRINGS_TABLE_START] = sText_ItHurtConfusion,
    [STRINGID_MIRRORMOVEFAILED - BATTLESTRINGS_TABLE_START] = sText_MirrorMoveFailed,
    [STRINGID_STARTEDTORAIN - BATTLESTRINGS_TABLE_START] = sText_StartedToRain,
    [STRINGID_DOWNPOURSTARTED - BATTLESTRINGS_TABLE_START] = sText_DownpourStarted,
    [STRINGID_RAINCONTINUES - BATTLESTRINGS_TABLE_START] = sText_RainContinues,
    [STRINGID_DOWNPOURCONTINUES - BATTLESTRINGS_TABLE_START] = sText_DownpourContinues,
    [STRINGID_RAINSTOPPED - BATTLESTRINGS_TABLE_START] = sText_RainStopped,
    [STRINGID_SANDSTORMBREWED - BATTLESTRINGS_TABLE_START] = sText_SandstormBrewed,
    [STRINGID_SANDSTORMRAGES - BATTLESTRINGS_TABLE_START] = sText_SandstormRages,
    [STRINGID_SANDSTORMSUBSIDED - BATTLESTRINGS_TABLE_START] = sText_SandstormSubsided,
    [STRINGID_SUNLIGHTGOTBRIGHT - BATTLESTRINGS_TABLE_START] = sText_SunlightGotBright,
    [STRINGID_SUNLIGHTSTRONG - BATTLESTRINGS_TABLE_START] = sText_SunlightStrong,
    [STRINGID_SUNLIGHTFADED - BATTLESTRINGS_TABLE_START] = sText_SunlightFaded,
    [STRINGID_STARTEDHAIL - BATTLESTRINGS_TABLE_START] = sText_StartedHail,
    [STRINGID_HAILCONTINUES - BATTLESTRINGS_TABLE_START] = sText_HailContinues,
    [STRINGID_HAILSTOPPED - BATTLESTRINGS_TABLE_START] = sText_HailStopped,
    [STRINGID_FAILEDTOSPITUP - BATTLESTRINGS_TABLE_START] = sText_FailedToSpitUp,
    [STRINGID_FAILEDTOSWALLOW - BATTLESTRINGS_TABLE_START] = sText_FailedToSwallow,
    [STRINGID_WINDBECAMEHEATWAVE - BATTLESTRINGS_TABLE_START] = sText_WindBecameHeatWave,
    [STRINGID_STATCHANGESGONE - BATTLESTRINGS_TABLE_START] = sText_StatChangesGone,
    [STRINGID_COINSSCATTERED - BATTLESTRINGS_TABLE_START] = sText_CoinsScattered,
    [STRINGID_TOOWEAKFORSUBSTITUTE - BATTLESTRINGS_TABLE_START] = sText_TooWeakForSubstitute,
    [STRINGID_SHAREDPAIN - BATTLESTRINGS_TABLE_START] = sText_SharedPain,
    [STRINGID_BELLCHIMED - BATTLESTRINGS_TABLE_START] = sText_BellChimed,
    [STRINGID_FAINTINTHREE - BATTLESTRINGS_TABLE_START] = sText_FaintInThree,
    [STRINGID_NOPPLEFT - BATTLESTRINGS_TABLE_START] = sText_NoPPLeft,
    [STRINGID_BUTNOPPLEFT - BATTLESTRINGS_TABLE_START] = sText_ButNoPPLeft,
    [STRINGID_PLAYERUSEDITEM - BATTLESTRINGS_TABLE_START] = sText_PlayerUsedItem,
    [STRINGID_WALLYUSEDITEM - BATTLESTRINGS_TABLE_START] = sText_WallyUsedItem,
    [STRINGID_TRAINERBLOCKEDBALL - BATTLESTRINGS_TABLE_START] = sText_TrainerBlockedBall,
    [STRINGID_DONTBEATHIEF - BATTLESTRINGS_TABLE_START] = sText_DontBeAThief,
    [STRINGID_ITDODGEDBALL - BATTLESTRINGS_TABLE_START] = sText_ItDodgedBall,
    [STRINGID_YOUMISSEDPKMN - BATTLESTRINGS_TABLE_START] = sText_YouMissedPkmn,
    [STRINGID_PKMNBROKEFREE - BATTLESTRINGS_TABLE_START] = sText_PkmnBrokeFree,
    [STRINGID_ITAPPEAREDCAUGHT - BATTLESTRINGS_TABLE_START] = sText_ItAppearedCaught,
    [STRINGID_AARGHALMOSTHADIT - BATTLESTRINGS_TABLE_START] = sText_AarghAlmostHadIt,
    [STRINGID_SHOOTSOCLOSE - BATTLESTRINGS_TABLE_START] = sText_ShootSoClose,
    [STRINGID_GOTCHAPKMNCAUGHTPLAYER - BATTLESTRINGS_TABLE_START] = sText_GotchaPkmnCaughtPlayer,
    [STRINGID_GOTCHAPKMNCAUGHTWALLY - BATTLESTRINGS_TABLE_START] = sText_GotchaPkmnCaughtWally,
    [STRINGID_GIVENICKNAMECAPTURED - BATTLESTRINGS_TABLE_START] = sText_GiveNicknameCaptured,
    [STRINGID_PKMNSENTTOPC - BATTLESTRINGS_TABLE_START] = sText_PkmnSentToPC,
    [STRINGID_PKMNDATAADDEDTODEX - BATTLESTRINGS_TABLE_START] = sText_PkmnDataAddedToDex,
    [STRINGID_ITISRAINING - BATTLESTRINGS_TABLE_START] = sText_ItIsRaining,
    [STRINGID_SANDSTORMISRAGING - BATTLESTRINGS_TABLE_START] = sText_SandstormIsRaging,
    [STRINGID_CANTESCAPE2 - BATTLESTRINGS_TABLE_START] = sText_CantEscape2,
    [STRINGID_PKMNIGNORESASLEEP - BATTLESTRINGS_TABLE_START] = sText_PkmnIgnoresAsleep,
    [STRINGID_PKMNIGNOREDORDERS - BATTLESTRINGS_TABLE_START] = sText_PkmnIgnoredOrders,
    [STRINGID_PKMNBEGANTONAP - BATTLESTRINGS_TABLE_START] = sText_PkmnBeganToNap,
    [STRINGID_PKMNLOAFING - BATTLESTRINGS_TABLE_START] = sText_PkmnLoafing,
    [STRINGID_PKMNWONTOBEY - BATTLESTRINGS_TABLE_START] = sText_PkmnWontObey,
    [STRINGID_PKMNTURNEDAWAY - BATTLESTRINGS_TABLE_START] = sText_PkmnTurnedAway,
    [STRINGID_PKMNPRETENDNOTNOTICE - BATTLESTRINGS_TABLE_START] = sText_PkmnPretendNotNotice,
    [STRINGID_ENEMYABOUTTOSWITCHPKMN - BATTLESTRINGS_TABLE_START] = sText_EnemyAboutToSwitchPkmn,
    [STRINGID_CREPTCLOSER - BATTLESTRINGS_TABLE_START] = sText_CreptCloser,
    [STRINGID_CANTGETCLOSER - BATTLESTRINGS_TABLE_START] = sText_CantGetCloser,
    [STRINGID_PKMNWATCHINGCAREFULLY - BATTLESTRINGS_TABLE_START] = sText_PkmnWatchingCarefully,
    [STRINGID_PKMNCURIOUSABOUTX - BATTLESTRINGS_TABLE_START] = sText_PkmnCuriousAboutX,
    [STRINGID_PKMNENTHRALLEDBYX - BATTLESTRINGS_TABLE_START] = sText_PkmnEnthralledByX,
    [STRINGID_PKMNIGNOREDX - BATTLESTRINGS_TABLE_START] = sText_PkmnIgnoredX,
    [STRINGID_THREWPOKEBLOCKATPKMN - BATTLESTRINGS_TABLE_START] = sText_ThrewPokeblockAtPkmn,
    [STRINGID_OUTOFSAFARIBALLS - BATTLESTRINGS_TABLE_START] = sText_OutOfSafariBalls,
    [STRINGID_PKMNSITEMCUREDPARALYSIS - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemCuredParalysis,
    [STRINGID_PKMNSITEMCUREDPOISON - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemCuredPoison,
    [STRINGID_PKMNSITEMHEALEDBURN - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemHealedBurn,
    [STRINGID_PKMNSITEMDEFROSTEDIT - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemDefrostedIt,
    [STRINGID_PKMNSITEMWOKEIT - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemWokeIt,
    [STRINGID_PKMNSITEMSNAPPEDOUT - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemSnappedOut,
    [STRINGID_PKMNSITEMCUREDPROBLEM - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemCuredProblem,
    [STRINGID_PKMNSITEMRESTOREDHEALTH - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemRestoredHealth,
    [STRINGID_PKMNSITEMRESTOREDPP - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemRestoredPP,
    [STRINGID_PKMNSITEMRESTOREDSTATUS - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemRestoredStatus,
    [STRINGID_PKMNSITEMRESTOREDHPALITTLE - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemRestoredHPALittle,
    [STRINGID_ITEMALLOWSONLYYMOVE - BATTLESTRINGS_TABLE_START] = sText_ItemAllowsOnlyYMove,
    [STRINGID_PKMNHUNGONWITHX - BATTLESTRINGS_TABLE_START] = sText_PkmnHungOnWithX,
    [STRINGID_EMPTYSTRING3 - BATTLESTRINGS_TABLE_START] = gText_EmptyString3,
    [STRINGID_PKMNSXPREVENTSBURNS - BATTLESTRINGS_TABLE_START] = sText_PkmnsXPreventsBurns,
    [STRINGID_PKMNSXBLOCKSY - BATTLESTRINGS_TABLE_START] = sText_PkmnsXBlocksY,
    [STRINGID_PKMNSXRESTOREDHPALITTLE2 - BATTLESTRINGS_TABLE_START] = sText_PkmnsXRestoredHPALittle2,
    [STRINGID_PKMNSXWHIPPEDUPSANDSTORM - BATTLESTRINGS_TABLE_START] = sText_PkmnsXWhippedUpSandstorm,
    [STRINGID_PKMNSXPREVENTSYLOSS - BATTLESTRINGS_TABLE_START] = sText_PkmnsXPreventsYLoss,
    [STRINGID_PKMNSXINFATUATEDY - BATTLESTRINGS_TABLE_START] = sText_PkmnsXInfatuatedY,
    [STRINGID_PKMNSXMADEYINEFFECTIVE - BATTLESTRINGS_TABLE_START] = sText_PkmnsXMadeYIneffective,
    [STRINGID_PKMNSXCUREDYPROBLEM - BATTLESTRINGS_TABLE_START] = sText_PkmnsXCuredYProblem,
    [STRINGID_ITSUCKEDLIQUIDOOZE - BATTLESTRINGS_TABLE_START] = sText_ItSuckedLiquidOoze,
    [STRINGID_PKMNTRANSFORMED - BATTLESTRINGS_TABLE_START] = sText_PkmnTransformed,
    [STRINGID_ELECTRICITYWEAKENED - BATTLESTRINGS_TABLE_START] = sText_ElectricityWeakened,
    [STRINGID_FIREWEAKENED - BATTLESTRINGS_TABLE_START] = sText_FireWeakened,
    [STRINGID_PKMNHIDUNDERWATER - BATTLESTRINGS_TABLE_START] = sText_PkmnHidUnderwater,
    [STRINGID_PKMNSPRANGUP - BATTLESTRINGS_TABLE_START] = sText_PkmnSprangUp,
    [STRINGID_HMMOVESCANTBEFORGOTTEN - BATTLESTRINGS_TABLE_START] = sText_HMMovesCantBeForgotten,
    [STRINGID_XFOUNDONEY - BATTLESTRINGS_TABLE_START] = sText_XFoundOneY,
    [STRINGID_PLAYERDEFEATEDTRAINER1 - BATTLESTRINGS_TABLE_START] = sText_PlayerDefeatedLinkTrainerTrainer1,
    [STRINGID_SOOTHINGAROMA - BATTLESTRINGS_TABLE_START] = sText_SoothingAroma,
    [STRINGID_ITEMSCANTBEUSEDNOW - BATTLESTRINGS_TABLE_START] = sText_ItemsCantBeUsedNow,
    [STRINGID_FORXCOMMAYZ - BATTLESTRINGS_TABLE_START] = sText_ForXCommaYZ,
    [STRINGID_USINGITEMSTATOFPKMNROSE - BATTLESTRINGS_TABLE_START] = sText_UsingItemTheStatOfPkmnRose,
    [STRINGID_PKMNUSEDXTOGETPUMPED - BATTLESTRINGS_TABLE_START] = sText_PkmnUsedXToGetPumped,
    [STRINGID_PKMNSXMADEYUSELESS - BATTLESTRINGS_TABLE_START] = sText_PkmnsXMadeYUseless,
    [STRINGID_PKMNTRAPPEDBYSANDTOMB - BATTLESTRINGS_TABLE_START] = sText_PkmnTrappedBySandTomb,
    [STRINGID_EMPTYSTRING4 - BATTLESTRINGS_TABLE_START] = sText_EmptyString4,
    [STRINGID_ABOOSTED - BATTLESTRINGS_TABLE_START] = sText_ABoosted,
    [STRINGID_PKMNSXINTENSIFIEDSUN - BATTLESTRINGS_TABLE_START] = sText_PkmnsXIntensifiedSun,
    [STRINGID_PKMNMAKESGROUNDMISS - BATTLESTRINGS_TABLE_START] = sText_PkmnMakesGroundMiss,
    [STRINGID_YOUTHROWABALLNOWRIGHT - BATTLESTRINGS_TABLE_START] = sText_YouThrowABallNowRight,
    [STRINGID_PLAYERLOSTTOENEMYTRAINER - BATTLESTRINGS_TABLE_START] = sText_PlayerLostToEnemyTrainer,
    [STRINGID_PLAYERPAIDPRIZEMONEY - BATTLESTRINGS_TABLE_START] = sText_PlayerPaidPrizeMoney,
    [STRINGID_PLAYERWHITEOUT_NOMONEY - BATTLESTRINGS_TABLE_START] = sText_PlayerWhiteoutNoMoney,
    [STRINGID_PKMNSXTOOKATTACK - BATTLESTRINGS_TABLE_START] = sText_PkmnsXTookAttack,
    [STRINGID_PKMNCHOSEXASDESTINY - BATTLESTRINGS_TABLE_START] = sText_PkmnChoseXAsDestiny,
    [STRINGID_PKMNLOSTFOCUS - BATTLESTRINGS_TABLE_START] = sText_PkmnLostFocus,
    [STRINGID_USENEXTPKMN - BATTLESTRINGS_TABLE_START] = sText_UseNextPkmn,
    [STRINGID_PKMNFLEDUSINGITS - BATTLESTRINGS_TABLE_START] = sText_PkmnFledUsingIts,
    [STRINGID_PKMNFLEDUSING - BATTLESTRINGS_TABLE_START] = sText_PkmnFledUsing,
    [STRINGID_PKMNWASDRAGGEDOUT - BATTLESTRINGS_TABLE_START] = sText_PkmnWasDraggedOut,
    [STRINGID_PREVENTEDFROMWORKING - BATTLESTRINGS_TABLE_START] = sText_PreventedFromWorking,
    [STRINGID_PKMNSITEMNORMALIZEDSTATUS - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemNormalizedStatus,
    [STRINGID_TRAINER1USEDITEM - BATTLESTRINGS_TABLE_START] = sText_Trainer1UsedItem,
    [STRINGID_BOXISFULL - BATTLESTRINGS_TABLE_START] = sText_BoxIsFull,
    [STRINGID_PKMNAVOIDEDATTACK - BATTLESTRINGS_TABLE_START] = sText_PkmnAvoidedAttack,
    [STRINGID_PKMNSXMADEITINEFFECTIVE - BATTLESTRINGS_TABLE_START] = sText_PkmnsXMadeItIneffective,
    [STRINGID_PKMNSXPREVENTSFLINCHING - BATTLESTRINGS_TABLE_START] = sText_PkmnsXPreventsFlinching,
    [STRINGID_PKMNALREADYHASBURN - BATTLESTRINGS_TABLE_START] = sText_PkmnAlreadyHasBurn,
    [STRINGID_STATSWONTDECREASE2 - BATTLESTRINGS_TABLE_START] = sText_StatsWontDecrease2,
    [STRINGID_PKMNSXBLOCKSY2 - BATTLESTRINGS_TABLE_START] = sText_PkmnsXBlocksY2,
    [STRINGID_PKMNSXWOREOFF - BATTLESTRINGS_TABLE_START] = sText_PkmnsXWoreOff,
    [STRINGID_PKMNRAISEDDEFALITTLE - BATTLESTRINGS_TABLE_START] = sText_PkmnRaisedDefALittle,
    [STRINGID_PKMNRAISEDSPDEFALITTLE - BATTLESTRINGS_TABLE_START] = sText_PkmnRaisedSpDefALittle,
    [STRINGID_THEWALLSHATTERED - BATTLESTRINGS_TABLE_START] = sText_TheWallShattered,
    [STRINGID_PKMNSXPREVENTSYSZ - BATTLESTRINGS_TABLE_START] = sText_PkmnsXPreventsYsZ,
    [STRINGID_PKMNSXCUREDITSYPROBLEM - BATTLESTRINGS_TABLE_START] = sText_PkmnsXCuredItsYProblem,
    [STRINGID_ATTACKERCANTESCAPE - BATTLESTRINGS_TABLE_START] = sText_AttackerCantEscape,
    [STRINGID_PKMNOBTAINEDX - BATTLESTRINGS_TABLE_START] = sText_PkmnObtainedX,
    [STRINGID_PKMNOBTAINEDX2 - BATTLESTRINGS_TABLE_START] = sText_PkmnObtainedX2,
    [STRINGID_PKMNOBTAINEDXYOBTAINEDZ - BATTLESTRINGS_TABLE_START] = sText_PkmnObtainedXYObtainedZ,
    [STRINGID_BUTNOEFFECT - BATTLESTRINGS_TABLE_START] = sText_ButNoEffect,
    [STRINGID_PKMNSXHADNOEFFECTONY - BATTLESTRINGS_TABLE_START] = sText_PkmnsXHadNoEffectOnY,
    [STRINGID_TWOENEMIESDEFEATED - BATTLESTRINGS_TABLE_START] = sText_TwoInGameTrainersDefeated,
    [STRINGID_TRAINER2LOSETEXT - BATTLESTRINGS_TABLE_START] = sText_Trainer2LoseText,
    [STRINGID_PKMNINCAPABLEOFPOWER - BATTLESTRINGS_TABLE_START] = sText_PkmnIncapableOfPower,
    [STRINGID_GLINTAPPEARSINEYE - BATTLESTRINGS_TABLE_START] = sText_GlintAppearsInEye,
    [STRINGID_PKMNGETTINGINTOPOSITION - BATTLESTRINGS_TABLE_START] = sText_PkmnGettingIntoPosition,
    [STRINGID_PKMNBEGANGROWLINGDEEPLY - BATTLESTRINGS_TABLE_START] = sText_PkmnBeganGrowlingDeeply,
    [STRINGID_PKMNEAGERFORMORE - BATTLESTRINGS_TABLE_START] = sText_PkmnEagerForMore,
    [STRINGID_DEFEATEDOPPONENTBYREFEREE - BATTLESTRINGS_TABLE_START] = sText_DefeatedOpponentByReferee,
    [STRINGID_LOSTTOOPPONENTBYREFEREE - BATTLESTRINGS_TABLE_START] = sText_LostToOpponentByReferee,
    [STRINGID_TIEDOPPONENTBYREFEREE - BATTLESTRINGS_TABLE_START] = sText_TiedOpponentByReferee,
    [STRINGID_QUESTIONFORFEITMATCH - BATTLESTRINGS_TABLE_START] = sText_QuestionForfeitMatch,
    [STRINGID_FORFEITEDMATCH - BATTLESTRINGS_TABLE_START] = sText_ForfeitedMatch,
    [STRINGID_PKMNTRANSFERREDSOMEONESPC - BATTLESTRINGS_TABLE_START] = gText_PkmnTransferredSomeonesPC,
    [STRINGID_PKMNTRANSFERREDLANETTESPC - BATTLESTRINGS_TABLE_START] = gText_PkmnTransferredLanettesPC,
    [STRINGID_PKMNBOXSOMEONESPCFULL - BATTLESTRINGS_TABLE_START] = gText_PkmnTransferredSomeonesPCBoxFull,
    [STRINGID_PKMNBOXLANETTESPCFULL - BATTLESTRINGS_TABLE_START] = gText_PkmnTransferredLanettesPCBoxFull,
    [STRINGID_TRAINER1WINTEXT - BATTLESTRINGS_TABLE_START] = sText_Trainer1WinText,
    [STRINGID_TRAINER2WINTEXT - BATTLESTRINGS_TABLE_START] = sText_Trainer2WinText,
    [STRINGID_PKMNSABILITYACTIVATED - BATTLESTRINGS_TABLE_START] = sText_PkmnsAbilityActivated,
    [STRINGID_PKMNSABILITYRESTOREDHP - BATTLESTRINGS_TABLE_START] = sText_PkmnsAbilityRestoredHP,
    [STRINGID_PKMNHURTBYABILITY - BATTLESTRINGS_TABLE_START] = sText_PkmnHurtByAbility,
    [STRINGID_PKMNSHUDDERED - BATTLESTRINGS_TABLE_START] = sText_PkmnShuddered,
    [STRINGID_PKMNFRISKEDITEM - BATTLESTRINGS_TABLE_START] = sText_PkmnFriskedItem,
    [STRINGID_PKMNRECOVEREDITEM - BATTLESTRINGS_TABLE_START] = sText_PkmnRecoveredItem,
    [STRINGID_PKMNMOVEBOUNCEDBACK - BATTLESTRINGS_TABLE_START] = sText_PkmnMoveBouncedBack,
    [STRINGID_PKMNFRISKEDTWOITEMS - BATTLESTRINGS_TABLE_START] = sText_PkmnFriskedTwoItems,
    [STRINGID_SENDCAUGHTMONPARTYORBOX - BATTLESTRINGS_TABLE_START] = sText_AddCaughtMonToParty,
    [STRINGID_PKMNSENTTOPCAFTERCATCH - BATTLESTRINGS_TABLE_START] = gText_PkmnSentToPCAfterCatch,
};

const u16 gMissStringIds[] =
{
    [B_MSG_MISSED]      = STRINGID_ATTACKMISSED,
    [B_MSG_PROTECTED]   = STRINGID_PKMNPROTECTEDITSELF,
    [B_MSG_AVOIDED_ATK] = STRINGID_PKMNAVOIDEDATTACK,
    [B_MSG_AVOIDED_DMG] = STRINGID_AVOIDEDDAMAGE,
    [B_MSG_GROUND_MISS] = STRINGID_PKMNMAKESGROUNDMISS
};

const u16 gNoEscapeStringIds[] =
{
    [B_MSG_CANT_ESCAPE]          = STRINGID_CANTESCAPE,
    [B_MSG_DONT_LEAVE_BIRCH]     = STRINGID_DONTLEAVEBIRCH,
    [B_MSG_PREVENTS_ESCAPE]      = STRINGID_PREVENTSESCAPE,
    [B_MSG_CANT_ESCAPE_2]        = STRINGID_CANTESCAPE2,
    [B_MSG_ATTACKER_CANT_ESCAPE] = STRINGID_ATTACKERCANTESCAPE
};

const u16 gMoveWeatherChangeStringIds[] =
{
    [B_MSG_STARTED_RAIN]      = STRINGID_STARTEDTORAIN,
    [B_MSG_STARTED_DOWNPOUR]  = STRINGID_DOWNPOURSTARTED, // Unused
    [B_MSG_WEATHER_FAILED]    = STRINGID_BUTITFAILED,
    [B_MSG_STARTED_SANDSTORM] = STRINGID_SANDSTORMBREWED,
    [B_MSG_STARTED_SUNLIGHT]  = STRINGID_SUNLIGHTGOTBRIGHT,
    [B_MSG_STARTED_HAIL]      = STRINGID_STARTEDHAIL,
};

const u16 gSandStormHailContinuesStringIds[] =
{
    [B_MSG_SANDSTORM] = STRINGID_SANDSTORMRAGES,
    [B_MSG_HAIL]      = STRINGID_HAILCONTINUES
};

const u16 gSandStormHailDmgStringIds[] =
{
    [B_MSG_SANDSTORM] = STRINGID_PKMNBUFFETEDBYSANDSTORM,
    [B_MSG_HAIL]      = STRINGID_PKMNPELTEDBYHAIL
};

const u16 gSandStormHailEndStringIds[] =
{
    [B_MSG_SANDSTORM] = STRINGID_SANDSTORMSUBSIDED,
    [B_MSG_HAIL]      = STRINGID_HAILSTOPPED
};

const u16 gRainContinuesStringIds[] =
{
    [B_MSG_RAIN_CONTINUES]     = STRINGID_RAINCONTINUES,
    [B_MSG_DOWNPOUR_CONTINUES] = STRINGID_DOWNPOURCONTINUES,
    [B_MSG_RAIN_STOPPED]       = STRINGID_RAINSTOPPED
};

const u16 gProtectLikeUsedStringIds[] =
{
    [B_MSG_PROTECTED_ITSELF] = STRINGID_PKMNPROTECTEDITSELF2,
    [B_MSG_BRACED_ITSELF]    = STRINGID_PKMNBRACEDITSELF,
    [B_MSG_PROTECT_FAILED]   = STRINGID_BUTITFAILED,
};

const u16 gReflectLightScreenSafeguardStringIds[] =
{
    [B_MSG_SIDE_STATUS_FAILED]     = STRINGID_BUTITFAILED,
    [B_MSG_SET_REFLECT_SINGLE]     = STRINGID_PKMNRAISEDDEF,
    [B_MSG_SET_REFLECT_DOUBLE]     = STRINGID_PKMNRAISEDDEFALITTLE,
    [B_MSG_SET_LIGHTSCREEN_SINGLE] = STRINGID_PKMNRAISEDSPDEF,
    [B_MSG_SET_LIGHTSCREEN_DOUBLE] = STRINGID_PKMNRAISEDSPDEFALITTLE,
    [B_MSG_SET_SAFEGUARD]          = STRINGID_PKMNCOVEREDBYVEIL,
};

const u16 gLeechSeedStringIds[] =
{
    [B_MSG_LEECH_SEED_SET]   = STRINGID_PKMNSEEDED,
    [B_MSG_LEECH_SEED_MISS]  = STRINGID_PKMNEVADEDATTACK,
    [B_MSG_LEECH_SEED_FAIL]  = STRINGID_ITDOESNTAFFECT,
    [B_MSG_LEECH_SEED_DRAIN] = STRINGID_PKMNSAPPEDBYLEECHSEED,
    [B_MSG_LEECH_SEED_OOZE]  = STRINGID_ITSUCKEDLIQUIDOOZE,
};

const u16 gRestUsedStringIds[] =
{
    [B_MSG_REST]          = STRINGID_PKMNWENTTOSLEEP,
    [B_MSG_REST_STATUSED] = STRINGID_PKMNSLEPTHEALTHY
};

const u16 gUproarOverTurnStringIds[] =
{
    [B_MSG_UPROAR_CONTINUES] = STRINGID_PKMNMAKINGUPROAR,
    [B_MSG_UPROAR_ENDS]      = STRINGID_PKMNCALMEDDOWN
};

const u16 gStockpileUsedStringIds[] =
{
    [B_MSG_STOCKPILED]     = STRINGID_PKMNSTOCKPILED,
    [B_MSG_CANT_STOCKPILE] = STRINGID_PKMNCANTSTOCKPILE,
};

const u16 gWokeUpStringIds[] =
{
    [B_MSG_WOKE_UP]        = STRINGID_PKMNWOKEUP,
    [B_MSG_WOKE_UP_UPROAR] = STRINGID_PKMNWOKEUPINUPROAR
};

const u16 gSwallowFailStringIds[] =
{
    [B_MSG_SWALLOW_FAILED]  = STRINGID_FAILEDTOSWALLOW,
    [B_MSG_SWALLOW_FULL_HP] = STRINGID_PKMNHPFULL
};

const u16 gUproarAwakeStringIds[] =
{
    [B_MSG_CANT_SLEEP_UPROAR]  = STRINGID_PKMNCANTSLEEPINUPROAR2,
    [B_MSG_UPROAR_KEPT_AWAKE]  = STRINGID_UPROARKEPTPKMNAWAKE,
    [B_MSG_STAYED_AWAKE_USING] = STRINGID_PKMNSTAYEDAWAKEUSING,
};

const u16 gStatUpStringIds[] =
{
    [B_MSG_ATTACKER_STAT_ROSE] = STRINGID_ATTACKERSSTATROSE,
    [B_MSG_DEFENDER_STAT_ROSE] = STRINGID_DEFENDERSSTATROSE,
    [B_MSG_STAT_WONT_INCREASE] = STRINGID_STATSWONTINCREASE,
    [B_MSG_STAT_ROSE_EMPTY]    = STRINGID_EMPTYSTRING3,
    [B_MSG_STAT_ROSE_ITEM]     = STRINGID_USINGITEMSTATOFPKMNROSE,
    [B_MSG_USED_DIRE_HIT]      = STRINGID_PKMNUSEDXTOGETPUMPED,
};

const u16 gStatDownStringIds[] =
{
    [B_MSG_ATTACKER_STAT_FELL] = STRINGID_ATTACKERSSTATFELL,
    [B_MSG_DEFENDER_STAT_FELL] = STRINGID_DEFENDERSSTATFELL,
    [B_MSG_STAT_WONT_DECREASE] = STRINGID_STATSWONTDECREASE,
    [B_MSG_STAT_FELL_EMPTY]    = STRINGID_EMPTYSTRING3,
};

// Index read from sTWOTURN_STRINGID
const u16 gFirstTurnOfTwoStringIds[] =
{
    [B_MSG_TURN1_RAZOR_WIND] = STRINGID_PKMNWHIPPEDWHIRLWIND,
    [B_MSG_TURN1_SOLAR_BEAM] = STRINGID_PKMNTOOKSUNLIGHT,
    [B_MSG_TURN1_SKULL_BASH] = STRINGID_PKMNLOWEREDHEAD,
    [B_MSG_TURN1_SKY_ATTACK] = STRINGID_PKMNISGLOWING,
    [B_MSG_TURN1_FLY]        = STRINGID_PKMNFLEWHIGH,
    [B_MSG_TURN1_DIG]        = STRINGID_PKMNDUGHOLE,
    [B_MSG_TURN1_DIVE]       = STRINGID_PKMNHIDUNDERWATER,
    [B_MSG_TURN1_BOUNCE]     = STRINGID_PKMNSPRANGUP,
};

// Index copied from move's index in gTrappingMoves
const u16 gWrappedStringIds[NUM_TRAPPING_MOVES] =
{
    STRINGID_PKMNSQUEEZEDBYBIND,   // MOVE_BIND
    STRINGID_PKMNWRAPPEDBY,        // MOVE_WRAP
    STRINGID_PKMNTRAPPEDINVORTEX,  // MOVE_FIRE_SPIN
    STRINGID_PKMNCLAMPED,          // MOVE_CLAMP
    STRINGID_PKMNTRAPPEDINVORTEX,  // MOVE_WHIRLPOOL
    STRINGID_PKMNTRAPPEDBYSANDTOMB // MOVE_SAND_TOMB
};

const u16 gMistUsedStringIds[] =
{
    [B_MSG_SET_MIST]    = STRINGID_PKMNSHROUDEDINMIST,
    [B_MSG_MIST_FAILED] = STRINGID_BUTITFAILED
};

const u16 gFocusEnergyUsedStringIds[] =
{
    [B_MSG_GETTING_PUMPED]      = STRINGID_PKMNGETTINGPUMPED,
    [B_MSG_FOCUS_ENERGY_FAILED] = STRINGID_BUTITFAILED
};

const u16 gTransformUsedStringIds[] =
{
    [B_MSG_TRANSFORMED]      = STRINGID_PKMNTRANSFORMEDINTO,
    [B_MSG_TRANSFORM_FAILED] = STRINGID_BUTITFAILED
};

const u16 gSubstituteUsedStringIds[] =
{
    [B_MSG_SET_SUBSTITUTE]    = STRINGID_PKMNMADESUBSTITUTE,
    [B_MSG_SUBSTITUTE_FAILED] = STRINGID_TOOWEAKFORSUBSTITUTE
};

const u16 gGotPoisonedStringIds[] =
{
    [B_MSG_STATUSED]            = STRINGID_PKMNWASPOISONED,
    [B_MSG_STATUSED_BY_ABILITY] = STRINGID_PKMNPOISONEDBY
};

const u16 gGotParalyzedStringIds[] =
{
    [B_MSG_STATUSED]            = STRINGID_PKMNWASPARALYZED,
    [B_MSG_STATUSED_BY_ABILITY] = STRINGID_PKMNWASPARALYZEDBY
};

const u16 gFellAsleepStringIds[] =
{
    [B_MSG_STATUSED]            = STRINGID_PKMNFELLASLEEP,
    [B_MSG_STATUSED_BY_ABILITY] = STRINGID_PKMNMADESLEEP,
};

const u16 gGotBurnedStringIds[] =
{
    [B_MSG_STATUSED]            = STRINGID_PKMNWASBURNED,
    [B_MSG_STATUSED_BY_ABILITY] = STRINGID_PKMNBURNEDBY
};

const u16 gGotFrozenStringIds[] =
{
    [B_MSG_STATUSED]            = STRINGID_PKMNWASFROZEN,
    [B_MSG_STATUSED_BY_ABILITY] = STRINGID_PKMNFROZENBY
};

const u16 gGotDefrostedStringIds[] =
{
    [B_MSG_DEFROSTED]         = STRINGID_PKMNWASDEFROSTED2,
    [B_MSG_DEFROSTED_BY_MOVE] = STRINGID_PKMNWASDEFROSTEDBY
};

const u16 gKOFailedStringIds[] =
{
    [B_MSG_KO_MISS]       = STRINGID_ATTACKMISSED,
    [B_MSG_KO_UNAFFECTED] = STRINGID_PKMNUNAFFECTED
};

const u16 gAttractUsedStringIds[] =
{
    [B_MSG_STATUSED]            = STRINGID_PKMNFELLINLOVE,
    [B_MSG_STATUSED_BY_ABILITY] = STRINGID_PKMNSXINFATUATEDY
};

const u16 gAbsorbDrainStringIds[] =
{
    [B_MSG_ABSORB]      = STRINGID_PKMNENERGYDRAINED,
    [B_MSG_ABSORB_OOZE] = STRINGID_ITSUCKEDLIQUIDOOZE
};

const u16 gSportsUsedStringIds[] =
{
    [B_MSG_WEAKEN_ELECTRIC] = STRINGID_ELECTRICITYWEAKENED,
    [B_MSG_WEAKEN_FIRE]     = STRINGID_FIREWEAKENED
};

const u16 gPartyStatusHealStringIds[] =
{
    [B_MSG_BELL]                     = STRINGID_BELLCHIMED,
    [B_MSG_BELL_SOUNDPROOF_ATTACKER] = STRINGID_BELLCHIMED,
    [B_MSG_BELL_SOUNDPROOF_PARTNER]  = STRINGID_BELLCHIMED,
    [B_MSG_BELL_BOTH_SOUNDPROOF]     = STRINGID_BELLCHIMED,
    [B_MSG_SOOTHING_AROMA]           = STRINGID_SOOTHINGAROMA
};

const u16 gFutureMoveUsedStringIds[] =
{
    [B_MSG_FUTURE_SIGHT] = STRINGID_PKMNFORESAWATTACK,
    [B_MSG_DOOM_DESIRE]  = STRINGID_PKMNCHOSEXASDESTINY
};

const u16 gBallEscapeStringIds[] =
{
    [BALL_NO_SHAKES]     = STRINGID_PKMNBROKEFREE,
    [BALL_1_SHAKE]       = STRINGID_ITAPPEAREDCAUGHT,
    [BALL_2_SHAKES]      = STRINGID_AARGHALMOSTHADIT,
    [BALL_3_SHAKES_FAIL] = STRINGID_SHOOTSOCLOSE
};

// Overworld weathers that don't have an associated battle weather default to "It is raining."
const u16 gWeatherStartsStringIds[] =
{
    [WEATHER_NONE]               = STRINGID_ITISRAINING,
    [WEATHER_SUNNY_CLOUDS]       = STRINGID_ITISRAINING,
    [WEATHER_SUNNY]              = STRINGID_ITISRAINING,
    [WEATHER_RAIN]               = STRINGID_ITISRAINING,
    [WEATHER_SNOW]               = STRINGID_STARTEDHAIL,
    [WEATHER_RAIN_THUNDERSTORM]  = STRINGID_ITISRAINING,
    [WEATHER_FOG_HORIZONTAL]     = STRINGID_ITISRAINING,
    [WEATHER_VOLCANIC_ASH]       = STRINGID_ITISRAINING,
    [WEATHER_SANDSTORM]          = STRINGID_SANDSTORMISRAGING,
    [WEATHER_FOG_DIAGONAL]       = STRINGID_ITISRAINING,
    [WEATHER_UNDERWATER]         = STRINGID_ITISRAINING,
    [WEATHER_SHADE]              = STRINGID_ITISRAINING,
    [WEATHER_DROUGHT]            = STRINGID_SUNLIGHTSTRONG,
    [WEATHER_DOWNPOUR]           = STRINGID_ITISRAINING,
    [WEATHER_UNDERWATER_BUBBLES] = STRINGID_ITISRAINING,
    [WEATHER_ABNORMAL]           = STRINGID_ITISRAINING
};

const u16 gInobedientStringIds[] =
{
    [B_MSG_LOAFING]            = STRINGID_PKMNLOAFING,
    [B_MSG_WONT_OBEY]          = STRINGID_PKMNWONTOBEY,
    [B_MSG_TURNED_AWAY]        = STRINGID_PKMNTURNEDAWAY,
    [B_MSG_PRETEND_NOT_NOTICE] = STRINGID_PKMNPRETENDNOTNOTICE,
    [B_MSG_INCAPABLE_OF_POWER] = STRINGID_PKMNINCAPABLEOFPOWER
};

const u16 gSafariGetNearStringIds[] =
{
    [B_MSG_CREPT_CLOSER]    = STRINGID_CREPTCLOSER,
    [B_MSG_CANT_GET_CLOSER] = STRINGID_CANTGETCLOSER
};

const u16 gSafariPokeblockResultStringIds[] =
{
    [B_MSG_MON_CURIOUS]    = STRINGID_PKMNCURIOUSABOUTX,
    [B_MSG_MON_ENTHRALLED] = STRINGID_PKMNENTHRALLEDBYX,
    [B_MSG_MON_IGNORED]    = STRINGID_PKMNIGNOREDX
};

const u16 gTrainerItemCuredStatusStringIds[] =
{
    [AI_HEAL_CONFUSION] = STRINGID_PKMNSITEMSNAPPEDOUT,
    [AI_HEAL_PARALYSIS] = STRINGID_PKMNSITEMCUREDPARALYSIS,
    [AI_HEAL_FREEZE]    = STRINGID_PKMNSITEMDEFROSTEDIT,
    [AI_HEAL_BURN]      = STRINGID_PKMNSITEMHEALEDBURN,
    [AI_HEAL_POISON]    = STRINGID_PKMNSITEMCUREDPOISON,
    [AI_HEAL_SLEEP]     = STRINGID_PKMNSITEMWOKEIT
};

const u16 gBerryEffectStringIds[] =
{
    [B_MSG_CURED_PROBLEM]     = STRINGID_PKMNSITEMCUREDPROBLEM,
    [B_MSG_NORMALIZED_STATUS] = STRINGID_PKMNSITEMNORMALIZEDSTATUS
};

const u16 gBRNPreventionStringIds[] =
{
    [B_MSG_ABILITY_PREVENTS_MOVE_STATUS]    = STRINGID_PKMNSXPREVENTSBURNS,
    [B_MSG_ABILITY_PREVENTS_ABILITY_STATUS] = STRINGID_PKMNSXPREVENTSYSZ,
    [B_MSG_STATUS_HAD_NO_EFFECT]            = STRINGID_PKMNSXHADNOEFFECTONY
};

const u16 gPRLZPreventionStringIds[] =
{
    [B_MSG_ABILITY_PREVENTS_MOVE_STATUS]    = STRINGID_PKMNPREVENTSPARALYSISWITH,
    [B_MSG_ABILITY_PREVENTS_ABILITY_STATUS] = STRINGID_PKMNSXPREVENTSYSZ,
    [B_MSG_STATUS_HAD_NO_EFFECT]            = STRINGID_PKMNSXHADNOEFFECTONY
};

const u16 gPSNPreventionStringIds[] =
{
    [B_MSG_ABILITY_PREVENTS_MOVE_STATUS]    = STRINGID_PKMNPREVENTSPOISONINGWITH,
    [B_MSG_ABILITY_PREVENTS_ABILITY_STATUS] = STRINGID_PKMNSXPREVENTSYSZ,
    [B_MSG_STATUS_HAD_NO_EFFECT]            = STRINGID_PKMNSXHADNOEFFECTONY
};

const u16 gItemSwapStringIds[] =
{
    [B_MSG_ITEM_SWAP_TAKEN] = STRINGID_PKMNOBTAINEDX,
    [B_MSG_ITEM_SWAP_GIVEN] = STRINGID_PKMNOBTAINEDX2,
    [B_MSG_ITEM_SWAP_BOTH]  = STRINGID_PKMNOBTAINEDXYOBTAINEDZ
};

const u16 gFlashFireStringIds[] =
{
    [B_MSG_FLASH_FIRE_BOOST]    = STRINGID_PKMNRAISEDFIREPOWERWITH,
    [B_MSG_FLASH_FIRE_NO_BOOST] = STRINGID_PKMNSXMADEYINEFFECTIVE
};

const u16 gCaughtMonStringIds[] =
{
    [B_MSG_SENT_SOMEONES_PC]   = STRINGID_PKMNTRANSFERREDSOMEONESPC,
    [B_MSG_SENT_LANETTES_PC]   = STRINGID_PKMNTRANSFERREDLANETTESPC,
    [B_MSG_SOMEONES_BOX_FULL]  = STRINGID_PKMNBOXSOMEONESPCFULL,
    [B_MSG_LANETTES_BOX_FULL]  = STRINGID_PKMNBOXLANETTESPCFULL,
    [B_MSG_SWAPPED_INTO_PARTY] = STRINGID_PKMNSENTTOPCAFTERCATCH,
};

const u16 gTrappingMoves[NUM_TRAPPING_MOVES + 1] =
{
    MOVE_BIND,
    MOVE_WRAP,
    MOVE_FIRE_SPIN,
    MOVE_CLAMP,
    MOVE_WHIRLPOOL,
    MOVE_SAND_TOMB,
    0xFFFF // Never read
};

const u8 gText_PkmnIsEvolving[] = _("Gì thế?\n{STR_VAR_1} đang tiến hóa!");
const u8 gText_CongratsPkmnEvolved[] = _("Xin chúc mừng! {STR_VAR_1} đã\ntiến hóa thành {STR_VAR_2}!{WAIT_SE}\p");
const u8 gText_PkmnStoppedEvolving[] = _("Hửm? {STR_VAR_1}\nđã ngừng tiến hóa!\p");
const u8 gText_EllipsisQuestionMark[] = _("……?\p");
const u8 gText_WhatWillPkmnDo[] = _("{B_ACTIVE_NAME_WITH_PREFIX}\nsẽ làm gì?");
const u8 gText_WhatWillPkmnDo2[] = _("{B_PLAYER_NAME}\nsẽ làm gì?");
const u8 gText_WhatWillWallyDo[] = _("WALLY\nsẽ làm gì?");
const u8 gText_LinkStandby[] = _("{PAUSE 16}Đang chờ kết nối…");
const u8 gText_BattleMenu[] = _("FIGHT{CLEAR_TO 56}BAG\nPOKéMON{CLEAR_TO 56}RUN");
const u8 gText_SafariZoneMenu[] = _("BALL{CLEAR_TO 56}{POKEBLOCK}\nGO NEAR{CLEAR_TO 56}RUN");
const u8 gText_MoveInterfacePP[] = _("PP ");
const u8 gText_MoveInterfaceType[] = _("TYPE/");
const u8 gText_MoveInterfacePPType[] = _("{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW DYNAMIC_COLOR4 DYNAMIC_COLOR5 DYNAMIC_COLOR6}PP\nTYPE/");
const u8 gText_MoveInterfaceDynamicColors[] = _("{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW DYNAMIC_COLOR4 DYNAMIC_COLOR5 DYNAMIC_COLOR6}");
const u8 gText_WhichMoveToForget4[] = _("{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW DYNAMIC_COLOR4 DYNAMIC_COLOR5 DYNAMIC_COLOR6}Muốn quên chiêu\nthức nào?");
const u8 gText_BattleYesNoChoice[] = _("{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW DYNAMIC_COLOR4 DYNAMIC_COLOR5 DYNAMIC_COLOR6}Yes\nNo");
const u8 gText_BattleSwitchWhich[] = _("{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW DYNAMIC_COLOR4 DYNAMIC_COLOR5 DYNAMIC_COLOR6}Đổi POKéMON\nnào?");
const u8 gText_BattleSwitchWhich2[] = _("{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW DYNAMIC_COLOR4 DYNAMIC_COLOR5 DYNAMIC_COLOR6}");
const u8 gText_BattleSwitchWhich3[] = _("{UP_ARROW}");
const u8 gText_BattleSwitchWhich4[] = _("{ESCAPE 4}");
const u8 gText_BattleSwitchWhich5[] = _("-");

static const u8 sText_HP[] = _("HP");
static const u8 sText_Attack[] = _("ATTACK");
static const u8 sText_Defense[] = _("DEFENSE");
static const u8 sText_SpAtk[] = _("SP. ATK");
static const u8 sText_SpDef[] = _("SP. DEF");

// Unused
static const u8 *const sStatNamesTable2[] =
{
    sText_HP, sText_SpAtk, sText_Attack,
    sText_SpDef, sText_Defense, sText_Speed
};

const u8 gText_SafariBalls[] = _("{HIGHLIGHT DARK_GRAY}SAFARI BALLS");
const u8 gText_SafariBallLeft[] = _("{HIGHLIGHT DARK_GRAY}Còn: $" "{HIGHLIGHT DARK_GRAY}");
const u8 gText_Sleep[] = _("ngủ");
const u8 gText_Poison[] = _("trúng độc");
const u8 gText_Burn[] = _("bỏng");
const u8 gText_Paralysis[] = _("tê liệt");
const u8 gText_Ice[] = _("đóng băng");
const u8 gText_Confusion[] = _("bối rối");
const u8 gText_Love[] = _("say mê");
const u8 gText_SpaceAndSpace[] = _(" và ");
const u8 gText_CommaSpace[] = _(", ");
const u8 gText_Space2[] = _(" ");
const u8 gText_LineBreak[] = _("\l");
const u8 gText_NewLine[] = _("\n");
const u8 gText_Are[] = _("đang");
const u8 gText_Are2[] = _("đang");
const u8 gText_BadEgg[] = _("Bad EGG");
const u8 gText_BattleWallyName[] = _("WALLY");
const u8 gText_Win[] = _("{HIGHLIGHT TRANSPARENT}Win");
const u8 gText_Loss[] = _("{HIGHLIGHT TRANSPARENT}Loss");
const u8 gText_Draw[] = _("{HIGHLIGHT TRANSPARENT}Draw");
static const u8 sText_SpaceIs[] = _(" là");
static const u8 sText_ApostropheS[] = _("'s");

// For displaying names of invalid moves.
// This is large enough that the text for TYPE_ELECTRIC will exceed TEXT_BUFF_ARRAY_COUNT.
static const u8 sATypeMove_Table[NUMBER_OF_MON_TYPES][17] =
{
    [TYPE_NORMAL]   = _("chiêu NORMAL"),
    [TYPE_FIGHTING] = _("chiêu FIGHTING"),
    [TYPE_FLYING]   = _("chiêu FLYING"),
    [TYPE_POISON]   = _("chiêu POISON"),
    [TYPE_GROUND]   = _("chiêu GROUND"),
    [TYPE_ROCK]     = _("chiêu ROCK"),
    [TYPE_BUG]      = _("chiêu BUG"),
    [TYPE_GHOST]    = _("chiêu GHOST"),
    [TYPE_STEEL]    = _("chiêu STEEL"),
    [TYPE_MYSTERY]  = _("chiêu ???"),
    [TYPE_FIRE]     = _("chiêu FIRE"),
    [TYPE_WATER]    = _("chiêu WATER"),
    [TYPE_GRASS]    = _("chiêu GRASS"),
    [TYPE_ELECTRIC] = _("chiêu ELECTRIC"),
    [TYPE_PSYCHIC]  = _("chiêu PSYCHIC"),
    [TYPE_ICE]      = _("chiêu ICE"),
    [TYPE_DRAGON]   = _("chiêu DRAGON"),
    [TYPE_DARK]     = _("chiêu DARK")
};

const u8 gText_BattleTourney[] = _("BATTLE TOURNEY");
static const u8 sText_Round1[] = _("Vòng 1");
static const u8 sText_Round2[] = _("Vòng 2");
static const u8 sText_Semifinal[] = _("Bán kết");
static const u8 sText_Final[] = _("Chung kết");

const u8 *const gRoundsStringTable[DOME_ROUNDS_COUNT] =
{
    [DOME_ROUND1]    = sText_Round1,
    [DOME_ROUND2]    = sText_Round2,
    [DOME_SEMIFINAL] = sText_Semifinal,
    [DOME_FINAL]     = sText_Final
};

const u8 gText_TheGreatNewHope[] = _("Niềm hy vọng mới đầy triển vọng!\p");
const u8 gText_WillChampionshipDreamComeTrue[] = _("Giấc mơ vô địch sẽ thành hiện thực?!\p");
const u8 gText_AFormerChampion[] = _("Một cựu CHAMPION!\p");
const u8 gText_ThePreviousChampion[] = _("CHAMPION của kỳ trước!\p");
const u8 gText_TheUnbeatenChampion[] = _("CHAMPION bất bại!\p");
const u8 gText_PlayerMon1Name[] = _("{B_PLAYER_MON1_NAME}");
const u8 gText_Vs[] = _("VS");
const u8 gText_OpponentMon1Name[] = _("{B_OPPONENT_MON1_NAME}");
const u8 gText_Mind[] = _("Mind");
const u8 gText_Skill[] = _("Skill");
const u8 gText_Body[] = _("Body");
const u8 gText_Judgment[] = _("{B_BUFF1}{CLEAR 13}Judgment{CLEAR 13}{B_BUFF2}");
static const u8 sText_TwoTrainersSentPkmn[] = _("{B_TRAINER1_CLASS} {B_TRAINER1_NAME} đưa\n{B_OPPONENT_MON1_NAME} ra trận!\p{B_TRAINER2_CLASS} {B_TRAINER2_NAME} đưa\n{B_OPPONENT_MON2_NAME} ra trận!");
static const u8 sText_Trainer2SentOutPkmn[] = _("{B_TRAINER2_CLASS} {B_TRAINER2_NAME} đưa\n{B_BUFF1} ra trận!");
static const u8 sText_TwoTrainersWantToBattle[] = _("{B_TRAINER1_CLASS} {B_TRAINER1_NAME} và\n{B_TRAINER2_CLASS} {B_TRAINER2_NAME}\lmuốn chiến đấu!\p");
static const u8 sText_InGamePartnerSentOutZGoN[] = _("{B_PARTNER_CLASS} {B_PARTNER_NAME} đưa\n{B_PLAYER_MON2_NAME} ra trận!\lLên nào, {B_PLAYER_MON1_NAME}!");
static const u8 sText_TwoInGameTrainersDefeated[] = _("{B_TRAINER1_CLASS} {B_TRAINER1_NAME} và\n{B_TRAINER2_CLASS} {B_TRAINER2_NAME}\lđã bị đánh bại!\p");
static const u8 sText_Trainer2LoseText[] = _("{B_TRAINER2_LOSE_TEXT}");
static const u8 sText_PkmnIncapableOfPower[] = _("{B_ATK_NAME_WITH_PREFIX} có vẻ không thể\nsử dụng sức mạnh của mình!");
static const u8 sText_GlintAppearsInEye[] = _("Ánh sáng lóe lên trong mắt\n{B_SCR_ACTIVE_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnGettingIntoPosition[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}\nđang vào vị trí!");
static const u8 sText_PkmnBeganGrowlingDeeply[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX} bắt đầu gầm gừ!");
static const u8 sText_PkmnEagerForMore[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX} vẫn muốn tiếp tục!");

const u16 gBattlePalaceFlavorTextTable[] =
{
    [B_MSG_GLINT_IN_EYE]   = STRINGID_GLINTAPPEARSINEYE,
    [B_MSG_GETTING_IN_POS] = STRINGID_PKMNGETTINGINTOPOSITION,
    [B_MSG_GROWL_DEEPLY]   = STRINGID_PKMNBEGANGROWLINGDEEPLY,
    [B_MSG_EAGER_FOR_MORE] = STRINGID_PKMNEAGERFORMORE,
};

static const u8 sText_RefIfNothingIsDecided[] = _("TRỌNG TÀI: Nếu chưa phân thắng bại sau\n3 lượt, chúng ta sẽ chấm điểm!");
static const u8 sText_RefThatsIt[] = _("TRỌNG TÀI: Hết giờ! Bây giờ sẽ\nchấm điểm để tìm người thắng!");
static const u8 sText_RefJudgeMind[] = _("TRỌNG TÀI: Hạng mục 1, Mind!\nPOKéMON thể hiện ý chí mạnh nhất!\p");
static const u8 sText_RefJudgeSkill[] = _("TRỌNG TÀI: Hạng mục 2, Skill!\nPOKéMON sử dụng chiêu tốt nhất!\p");
static const u8 sText_RefJudgeBody[] = _("TRỌNG TÀI: Hạng mục 3, Body!\nPOKéMON có sức sống mạnh nhất!\p");
static const u8 sText_RefPlayerWon[] = _("TRỌNG TÀI: Kết quả: {B_BUFF1} - {B_BUFF2}!\nNgười thắng là {B_PLAYER_MON1_NAME} của {B_PLAYER_NAME}!\p");
static const u8 sText_RefOpponentWon[] = _("TRỌNG TÀI: Kết quả: {B_BUFF1} - {B_BUFF2}!\nNgười thắng là {B_OPPONENT_MON1_NAME} của {B_TRAINER1_NAME}!\p");
static const u8 sText_RefDraw[] = _("TRỌNG TÀI: Kết quả: 3 - 3!\nTrận đấu hòa!\p");
static const u8 sText_DefeatedOpponentByReferee[] = _("{B_PLAYER_MON1_NAME} đã thắng đối thủ\n{B_OPPONENT_MON1_NAME} theo quyết định của trọng tài!");
static const u8 sText_LostToOpponentByReferee[] = _("{B_PLAYER_MON1_NAME} đã thua đối thủ\n{B_OPPONENT_MON1_NAME} theo quyết định của trọng tài!");
static const u8 sText_TiedOpponentByReferee[] = _("{B_PLAYER_MON1_NAME} đã hòa đối thủ\n{B_OPPONENT_MON1_NAME} theo quyết định của trọng tài!");
static const u8 sText_RefCommenceBattle[] = _("TRỌNG TÀI: {B_PLAYER_MON1_NAME} VS {B_OPPONENT_MON1_NAME}!\nBắt đầu trận đấu!");

const u8 *const gRefereeStringsTable[] =
{
    [B_MSG_REF_NOTHING_IS_DECIDED] = sText_RefIfNothingIsDecided,
    [B_MSG_REF_THATS_IT]           = sText_RefThatsIt,
    [B_MSG_REF_JUDGE_MIND]         = sText_RefJudgeMind,
    [B_MSG_REF_JUDGE_SKILL]        = sText_RefJudgeSkill,
    [B_MSG_REF_JUDGE_BODY]         = sText_RefJudgeBody,
    [B_MSG_REF_PLAYER_WON]         = sText_RefPlayerWon,
    [B_MSG_REF_OPPONENT_WON]       = sText_RefOpponentWon,
    [B_MSG_REF_DRAW]               = sText_RefDraw,
    [B_MSG_REF_COMMENCE_BATTLE]    = sText_RefCommenceBattle,
};

static const u8 sText_QuestionForfeitMatch[] = _("Bạn có muốn bỏ cuộc\nvà rời trận đấu không?");
static const u8 sText_ForfeitedMatch[] = _("{B_PLAYER_NAME} đã bỏ cuộc!");
static const u8 sText_Trainer1WinText[] = _("{B_TRAINER1_WIN_TEXT}");
static const u8 sText_Trainer2WinText[] = _("{B_TRAINER2_WIN_TEXT}");
static const u8 sText_Trainer1Fled[] = _( "{PLAY_SE SE_FLEE}{B_TRAINER1_CLASS} {B_TRAINER1_NAME} đã chạy mất!");
static const u8 sText_PlayerLostAgainstTrainer1[] = _("Bạn đã thua\n{B_TRAINER1_CLASS} {B_TRAINER1_NAME}!");
static const u8 sText_PlayerBattledToDrawTrainer1[] = _("Bạn đã hòa với\n{B_TRAINER1_CLASS} {B_TRAINER1_NAME}!");
const u8 gText_RecordBattleToPass[] = _("Bạn có muốn ghi lại trận đấu\nvào FRONTIER PASS không?");
const u8 gText_BattleRecordedOnPass[] = _("Kết quả trận đấu của {B_PLAYER_NAME}\nđã được ghi vào FRONTIER PASS.");
static const u8 sText_LinkTrainerWantsToBattlePause[] = _("{B_LINK_OPPONENT1_NAME}\nmuốn chiến đấu!{PAUSE 49}");
static const u8 sText_TwoLinkTrainersWantToBattlePause[] = _("{B_LINK_OPPONENT1_NAME} và {B_LINK_OPPONENT2_NAME}\nmuốn chiến đấu!{PAUSE 49}");

// This is four lists of moves which use a different attack string in Japanese
// to the default. See the documentation for ChooseTypeOfMoveUsedString for more detail.
static const u16 sGrammarMoveUsedTable[] =
{
    MOVE_SWORDS_DANCE, MOVE_STRENGTH, MOVE_GROWTH,
    MOVE_HARDEN, MOVE_MINIMIZE, MOVE_SMOKESCREEN,
    MOVE_WITHDRAW, MOVE_DEFENSE_CURL, MOVE_EGG_BOMB,
    MOVE_SMOG, MOVE_BONE_CLUB, MOVE_FLASH, MOVE_SPLASH,
    MOVE_ACID_ARMOR, MOVE_BONEMERANG, MOVE_REST, MOVE_SHARPEN,
    MOVE_SUBSTITUTE, MOVE_MIND_READER, MOVE_SNORE,
    MOVE_PROTECT, MOVE_SPIKES, MOVE_ENDURE, MOVE_ROLLOUT,
    MOVE_SWAGGER, MOVE_SLEEP_TALK, MOVE_HIDDEN_POWER,
    MOVE_PSYCH_UP, MOVE_EXTREME_SPEED, MOVE_FOLLOW_ME,
    MOVE_TRICK, MOVE_ASSIST, MOVE_INGRAIN, MOVE_KNOCK_OFF,
    MOVE_CAMOUFLAGE, MOVE_ASTONISH, MOVE_ODOR_SLEUTH,
    MOVE_GRASS_WHISTLE, MOVE_SHEER_COLD, MOVE_MUDDY_WATER,
    MOVE_IRON_DEFENSE, MOVE_BOUNCE, 0,

    MOVE_TELEPORT, MOVE_RECOVER, MOVE_BIDE, MOVE_AMNESIA,
    MOVE_FLAIL, MOVE_TAUNT, MOVE_BULK_UP, 0,

    MOVE_MEDITATE, MOVE_AGILITY, MOVE_MIMIC, MOVE_DOUBLE_TEAM,
    MOVE_BARRAGE, MOVE_TRANSFORM, MOVE_STRUGGLE, MOVE_SCARY_FACE,
    MOVE_CHARGE, MOVE_WISH, MOVE_BRICK_BREAK, MOVE_YAWN,
    MOVE_FEATHER_DANCE, MOVE_TEETER_DANCE, MOVE_MUD_SPORT,
    MOVE_FAKE_TEARS, MOVE_WATER_SPORT, MOVE_CALM_MIND, 0,

    MOVE_POUND, MOVE_SCRATCH, MOVE_VICE_GRIP,
    MOVE_WING_ATTACK, MOVE_FLY, MOVE_BIND, MOVE_SLAM,
    MOVE_HORN_ATTACK, MOVE_WRAP, MOVE_THRASH, MOVE_TAIL_WHIP,
    MOVE_LEER, MOVE_BITE, MOVE_GROWL, MOVE_ROAR,
    MOVE_SING, MOVE_PECK, MOVE_ABSORB, MOVE_STRING_SHOT,
    MOVE_EARTHQUAKE, MOVE_FISSURE, MOVE_DIG, MOVE_TOXIC,
    MOVE_SCREECH, MOVE_METRONOME, MOVE_LICK, MOVE_CLAMP,
    MOVE_CONSTRICT, MOVE_POISON_GAS, MOVE_BUBBLE,
    MOVE_SLASH, MOVE_SPIDER_WEB, MOVE_NIGHTMARE, MOVE_CURSE,
    MOVE_FORESIGHT, MOVE_CHARM, MOVE_ATTRACT, MOVE_ROCK_SMASH,
    MOVE_UPROAR, MOVE_SPIT_UP, MOVE_SWALLOW, MOVE_TORMENT,
    MOVE_FLATTER, MOVE_ROLE_PLAY, MOVE_ENDEAVOR, MOVE_TICKLE,
    MOVE_COVET, 0
};

static const u8 sText_EmptyStatus[] = _("$$$$$$$");

static const struct BattleWindowText sTextOnWindowsInfo_Normal[] =
{
    [B_WIN_MSG] = {
        .fillValue = PIXEL_FILL(0xF),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 1,
        .fgColor = 1,
        .bgColor = 15,
        .shadowColor = 6,
    },
    [B_WIN_ACTION_PROMPT] = {
        .fillValue = PIXEL_FILL(0xF),
        .fontId = FONT_NORMAL,
        .x = 1,
        .y = 1,
        .speed = 0,
        .fgColor = 1,
        .bgColor = 15,
        .shadowColor = 6,
    },
    [B_WIN_ACTION_MENU] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_MOVE_NAME_1] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_MOVE_NAME_2] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_MOVE_NAME_3] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_MOVE_NAME_4] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_PP] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 12,
        .bgColor = 14,
        .shadowColor = 11,
    },
    [B_WIN_PSS_ICON] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_PP_REMAINING] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 2,
        .y = 1,
        .speed = 0,
        .fgColor = 12,
        .bgColor = 14,
        .shadowColor = 11,
    },
    [B_WIN_MOVE_TYPE] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_SWITCH_PROMPT] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_YESNO] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_LEVEL_UP_BOX] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_LEVEL_UP_BANNER] = {
        .fillValue = PIXEL_FILL(0),
        .fontId = FONT_NORMAL,
        .x = 32,
        .y = 1,
        .speed = 0,
        .fgColor = 1,
        .shadowColor = 2,
    },
    [B_WIN_VS_PLAYER] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_VS_OPPONENT] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_VS_MULTI_PLAYER_1] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_VS_MULTI_PLAYER_2] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_VS_MULTI_PLAYER_3] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_VS_MULTI_PLAYER_4] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_VS_OUTCOME_DRAW] = {
        .fillValue = PIXEL_FILL(0),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 1,
        .shadowColor = 6,
    },
    [B_WIN_VS_OUTCOME_LEFT] = {
        .fillValue = PIXEL_FILL(0),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 1,
        .shadowColor = 6,
    },
    [B_WIN_VS_OUTCOME_RIGHT] = {
        .fillValue = PIXEL_FILL(0x0),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 1,
        .shadowColor = 6,
    },
    [B_WIN_TYPE_SUPER_EFF] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 6,
        .bgColor = 14,
        .shadowColor = 5,
    },
    [B_WIN_TYPE_NOT_VERY_EFF] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 1,
        .bgColor = 14,
        .shadowColor = 3,
    },
    [B_WIN_TYPE_NO_EFF] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 7,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_MOVE_DESCRIPTION] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = TEXT_DYNAMIC_COLOR_4,
        .bgColor = TEXT_DYNAMIC_COLOR_5,
        .shadowColor = TEXT_DYNAMIC_COLOR_6,
    },
};

static const struct BattleWindowText sTextOnWindowsInfo_Arena[] =
{
    [B_WIN_MSG] = {
        .fillValue = PIXEL_FILL(0xF),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 1,
        .fgColor = 1,
        .bgColor = 15,
        .shadowColor = 6,
    },
    [B_WIN_ACTION_PROMPT] = {
        .fillValue = PIXEL_FILL(0xF),
        .fontId = FONT_NORMAL,
        .x = 1,
        .y = 1,
        .speed = 0,
        .fgColor = 1,
        .bgColor = 15,
        .shadowColor = 6,
    },
    [B_WIN_ACTION_MENU] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_MOVE_NAME_1] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_MOVE_NAME_2] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_MOVE_NAME_3] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_MOVE_NAME_4] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_PP] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 12,
        .bgColor = 14,
        .shadowColor = 11,
    },
    [B_WIN_PSS_ICON] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_PP_REMAINING] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 2,
        .y = 1,
        .speed = 0,
        .fgColor = 12,
        .bgColor = 14,
        .shadowColor = 11,
    },
    [B_WIN_MOVE_TYPE] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_SWITCH_PROMPT] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_YESNO] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_LEVEL_UP_BOX] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_LEVEL_UP_BANNER] = {
        .fillValue = PIXEL_FILL(0),
        .fontId = FONT_NORMAL,
        .x = 32,
        .y = 1,
        .speed = 0,
        .fgColor = 1,
        .shadowColor = 2,
    },
    [ARENA_WIN_PLAYER_NAME] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 1,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [ARENA_WIN_VS] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [ARENA_WIN_OPPONENT_NAME] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [ARENA_WIN_MIND] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [ARENA_WIN_SKILL] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [ARENA_WIN_BODY] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [ARENA_WIN_JUDGMENT_TITLE] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [ARENA_WIN_JUDGMENT_TEXT] = {
        .fillValue = PIXEL_FILL(0x1),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 1,
        .fgColor = 2,
        .bgColor = 1,
        .shadowColor = 3,
    },
    [B_WIN_TYPE_SUPER_EFF] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 6,
        .bgColor = 14,
        .shadowColor = 5,
    },
    [B_WIN_TYPE_NOT_VERY_EFF] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 1,
        .bgColor = 14,
        .shadowColor = 3,
    },
    [B_WIN_TYPE_NO_EFF] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 7,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_MOVE_DESCRIPTION] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = TEXT_DYNAMIC_COLOR_4,
        .bgColor = TEXT_DYNAMIC_COLOR_5,
        .shadowColor = TEXT_DYNAMIC_COLOR_6,
    },
};

static const struct BattleWindowText *const sBattleTextOnWindowsInfo[] =
{
    [B_WIN_TYPE_NORMAL] = sTextOnWindowsInfo_Normal,
    [B_WIN_TYPE_ARENA]  = sTextOnWindowsInfo_Arena
};

static const u8 sRecordedBattleTextSpeeds[] = {8, 4, 1, 0};

void BufferStringBattle(u16 stringID)
{
    s32 i;
    const u8 *stringPtr = NULL;

    gBattleMsgDataPtr = (struct BattleMsgData *)(&gBattleBufferA[gActiveBattler][4]);
    gLastUsedItem = gBattleMsgDataPtr->lastItem;
    gLastUsedAbility = gBattleMsgDataPtr->lastAbility;
    gBattleScripting.battler = gBattleMsgDataPtr->scrActive;
    *(&gBattleStruct->scriptPartyIdx) = gBattleMsgDataPtr->bakScriptPartyIdx;
    *(&gBattleStruct->hpScale) = gBattleMsgDataPtr->hpScale;
    gPotentialItemEffectBattler = gBattleMsgDataPtr->itemEffectBattler;
    *(&gBattleStruct->stringMoveType) = gBattleMsgDataPtr->moveType;

    for (i = 0; i < MAX_BATTLERS_COUNT; i++)
    {
        sBattlerAbilities[i] = gBattleMsgDataPtr->abilities[i];
    }
    for (i = 0; i < TEXT_BUFF_ARRAY_COUNT; i++)
    {
        gBattleTextBuff1[i] = gBattleMsgDataPtr->textBuffs[0][i];
        gBattleTextBuff2[i] = gBattleMsgDataPtr->textBuffs[1][i];
        gBattleTextBuff3[i] = gBattleMsgDataPtr->textBuffs[2][i];
    }

    switch (stringID)
    {
    case STRINGID_INTROMSG: // first battle msg
        if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
        {
            if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK))
            {
                if (gBattleTypeFlags & BATTLE_TYPE_TOWER_LINK_MULTI)
                {
                    stringPtr = sText_TwoTrainersWantToBattle;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
                {
                    if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
                        stringPtr = sText_TwoLinkTrainersWantToBattlePause;
                    else
                        stringPtr = sText_TwoLinkTrainersWantToBattle;
                }
                else
                {
                    if (gTrainerBattleOpponent_A == TRAINER_UNION_ROOM)
                        stringPtr = sText_Trainer1WantsToBattle;
                    else if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
                        stringPtr = sText_LinkTrainerWantsToBattlePause;
                    else
                        stringPtr = sText_LinkTrainerWantsToBattle;
                }
            }
            else
            {
                if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER)
                    stringPtr = sText_TwoTrainersWantToBattle;
                else if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
                    stringPtr = sText_TwoTrainersWantToBattle;
                else
                    stringPtr = sText_Trainer1WantsToBattle;
            }
        }
        else
        {
            if (gBattleTypeFlags & BATTLE_TYPE_LEGENDARY)
                stringPtr = sText_LegendaryPkmnAppeared;
            else if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE) // interesting, looks like they had something planned for wild double battles
                stringPtr = sText_TwoWildPkmnAppeared;
            else if (gBattleTypeFlags & BATTLE_TYPE_WALLY_TUTORIAL)
                stringPtr = sText_WildPkmnAppearedPause;
            else
                stringPtr = sText_WildPkmnAppeared;
        }
        break;
    case STRINGID_INTROSENDOUT: // poke first send-out
        if (GetBattlerSide(gActiveBattler) == B_SIDE_PLAYER)
        {
            if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
            {
                if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER)
                    stringPtr = sText_InGamePartnerSentOutZGoN;
                else if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
                    stringPtr = sText_GoTwoPkmn;
                else if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
                    stringPtr = sText_LinkPartnerSentOutPkmnGoPkmn;
                else
                    stringPtr = sText_GoTwoPkmn;
            }
            else
            {
                stringPtr = sText_GoPkmn;
            }
        }
        else
        {
            if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
            {
                if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
                    stringPtr = sText_TwoTrainersSentPkmn;
                else if (gBattleTypeFlags & BATTLE_TYPE_TOWER_LINK_MULTI)
                    stringPtr = sText_TwoTrainersSentPkmn;
                else if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
                    stringPtr = sText_TwoLinkTrainersSentOutPkmn;
                else if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK))
                    stringPtr = sText_LinkTrainerSentOutTwoPkmn;
                else
                    stringPtr = sText_Trainer1SentOutTwoPkmn;
            }
            else
            {
                if (!(gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK)))
                    stringPtr = sText_Trainer1SentOutPkmn;
                else if (gTrainerBattleOpponent_A == TRAINER_UNION_ROOM)
                    stringPtr = sText_Trainer1SentOutPkmn;
                else
                    stringPtr = sText_LinkTrainerSentOutPkmn;
            }
        }
        break;
    case STRINGID_RETURNMON: // sending poke to ball msg
        if (GetBattlerSide(gActiveBattler) == B_SIDE_PLAYER)
        {
            if (*(&gBattleStruct->hpScale) == 0)
                stringPtr = sText_PkmnThatsEnough;
            else if (*(&gBattleStruct->hpScale) == 1 || gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
                stringPtr = sText_PkmnComeBack;
            else if (*(&gBattleStruct->hpScale) == 2)
                stringPtr = sText_PkmnOkComeBack;
            else
                stringPtr = sText_PkmnGoodComeBack;
        }
        else
        {
            if (gTrainerBattleOpponent_A == TRAINER_LINK_OPPONENT || gBattleTypeFlags & BATTLE_TYPE_RECORDED_LINK)
            {
                if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
                    stringPtr = sText_LinkTrainer2WithdrewPkmn;
                else
                    stringPtr = sText_LinkTrainer1WithdrewPkmn;
            }
            else
            {
                stringPtr = sText_Trainer1WithdrewPkmn;
            }
        }
        break;
    case STRINGID_SWITCHINMON: // switch-in msg
        if (GetBattlerSide(gBattleScripting.battler) == B_SIDE_PLAYER)
        {
            if (*(&gBattleStruct->hpScale) == 0 || gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
                stringPtr = sText_GoPkmn2;
            else if (*(&gBattleStruct->hpScale) == 1)
                stringPtr = sText_DoItPkmn;
            else if (*(&gBattleStruct->hpScale) == 2)
                stringPtr = sText_GoForItPkmn;
            else
                stringPtr = sText_YourFoesWeakGetEmPkmn;
        }
        else
        {
            if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK))
            {
                if (gBattleTypeFlags & BATTLE_TYPE_TOWER_LINK_MULTI)
                {
                    if (gBattleScripting.battler == 1)
                        stringPtr = sText_Trainer1SentOutPkmn2;
                    else
                        stringPtr = sText_Trainer2SentOutPkmn;
                }
                else
                {
                    if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
                        stringPtr = sText_LinkTrainerMultiSentOutPkmn;
                    else if (gTrainerBattleOpponent_A == TRAINER_UNION_ROOM)
                        stringPtr = sText_Trainer1SentOutPkmn2;
                    else
                        stringPtr = sText_LinkTrainerSentOutPkmn2;
                }
            }
            else
            {
                if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
                {
                    if (gBattleScripting.battler == 1)
                        stringPtr = sText_Trainer1SentOutPkmn2;
                    else
                        stringPtr = sText_Trainer2SentOutPkmn;
                }
                else
                {
                    stringPtr = sText_Trainer1SentOutPkmn2;
                }
            }
        }
        break;
    case STRINGID_USEDMOVE: // Pokémon used a move msg
        ChooseMoveUsedParticle(gBattleTextBuff1); // buff1 doesn't appear in the string, leftover from japanese move names

        if (gBattleMsgDataPtr->currentMove >= MOVES_COUNT)
            StringCopy(gBattleTextBuff2, sATypeMove_Table[*(&gBattleStruct->stringMoveType)]);
        else
            StringCopy(gBattleTextBuff2, gMoveNames[gBattleMsgDataPtr->currentMove]);

        ChooseTypeOfMoveUsedString(gBattleTextBuff2);
        stringPtr = sText_AttackerUsedX;
        break;
    case STRINGID_BATTLEEND: // battle end
        if (gBattleTextBuff1[0] & B_OUTCOME_LINK_BATTLE_RAN)
        {
            gBattleTextBuff1[0] &= ~(B_OUTCOME_LINK_BATTLE_RAN);
            if (GetBattlerSide(gActiveBattler) == B_SIDE_OPPONENT && gBattleTextBuff1[0] != B_OUTCOME_DREW)
                gBattleTextBuff1[0] ^= (B_OUTCOME_LOST | B_OUTCOME_WON);

            if (gBattleTextBuff1[0] == B_OUTCOME_LOST || gBattleTextBuff1[0] == B_OUTCOME_DREW)
                stringPtr = sText_GotAwaySafely;
            else if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
                stringPtr = sText_TwoWildFled;
            else
                stringPtr = sText_WildFled;
        }
        else
        {
            if (GetBattlerSide(gActiveBattler) == B_SIDE_OPPONENT && gBattleTextBuff1[0] != B_OUTCOME_DREW)
                gBattleTextBuff1[0] ^= (B_OUTCOME_LOST | B_OUTCOME_WON);

            if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
            {
                switch (gBattleTextBuff1[0])
                {
                case B_OUTCOME_WON:
                    if (gBattleTypeFlags & BATTLE_TYPE_TOWER_LINK_MULTI)
                        stringPtr = sText_TwoInGameTrainersDefeated;
                    else
                        stringPtr = sText_TwoLinkTrainersDefeated;
                    break;
                case B_OUTCOME_LOST:
                    stringPtr = sText_PlayerLostToTwo;
                    break;
                case B_OUTCOME_DREW:
                    stringPtr = sText_PlayerBattledToDrawVsTwo;
                    break;
                }
            }
            else if (gTrainerBattleOpponent_A == TRAINER_UNION_ROOM)
            {
                switch (gBattleTextBuff1[0])
                {
                case B_OUTCOME_WON:
                    stringPtr = sText_PlayerDefeatedLinkTrainerTrainer1;
                    break;
                case B_OUTCOME_LOST:
                    stringPtr = sText_PlayerLostAgainstTrainer1;
                    break;
                case B_OUTCOME_DREW:
                    stringPtr = sText_PlayerBattledToDrawTrainer1;
                    break;
                }
            }
            else
            {
                switch (gBattleTextBuff1[0])
                {
                case B_OUTCOME_WON:
                    stringPtr = sText_PlayerDefeatedLinkTrainer;
                    break;
                case B_OUTCOME_LOST:
                    stringPtr = sText_PlayerLostAgainstLinkTrainer;
                    break;
                case B_OUTCOME_DREW:
                    stringPtr = sText_PlayerBattledToDrawLinkTrainer;
                    break;
                }
            }
        }
        break;
    default: // load a string from the table
        if (stringID >= BATTLESTRINGS_COUNT)
        {
            gDisplayedStringBattle[0] = EOS;
            return;
        }
        else
        {
            stringPtr = gBattleStringsTable[stringID - BATTLESTRINGS_TABLE_START];
        }
        break;
    }

    BattleStringExpandPlaceholdersToDisplayedString(stringPtr);
}

u32 BattleStringExpandPlaceholdersToDisplayedString(const u8 *src)
{
    return BattleStringExpandPlaceholders(src, gDisplayedStringBattle);
}

static const u8 *TryGetStatusString(u8 *src)
{
    u32 i;
    u8 status[8];
    u32 chars1, chars2;
    u8 *statusPtr;

    memcpy(status, sText_EmptyStatus, min(ARRAY_COUNT(status), ARRAY_COUNT(sText_EmptyStatus)));

    statusPtr = status;
    for (i = 0; i < ARRAY_COUNT(status); i++)
    {
        if (*src == EOS) break; // one line required to match -g
        *statusPtr = *src;
        src++;
        statusPtr++;
    }

    chars1 = *(u32 *)(&status[0]);
    chars2 = *(u32 *)(&status[4]);

    for (i = 0; i < ARRAY_COUNT(gStatusConditionStringsTable); i++)
    {
        if (chars1 == *(u32 *)(&gStatusConditionStringsTable[i][0][0])
            && chars2 == *(u32 *)(&gStatusConditionStringsTable[i][0][4]))
            return gStatusConditionStringsTable[i][1];
    }
    return NULL;
}

#define HANDLE_NICKNAME_STRING_CASE(battler, monIndex)                \
    if (GetBattlerSide(battler) != B_SIDE_PLAYER)                     \
    {                                                                   \
        if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)                     \
            toCpy = sText_FoePkmnPrefix;                                \
        else                                                            \
            toCpy = sText_WildPkmnPrefix;                               \
        while (*toCpy != EOS)                                           \
        {                                                               \
            dst[dstID] = *toCpy;                                        \
            dstID++;                                                    \
            toCpy++;                                                    \
        }                                                               \
        GetMonData(&gEnemyParty[monIndex], MON_DATA_NICKNAME, text);    \
    }                                                                   \
    else                                                                \
    {                                                                   \
        GetMonData(&gPlayerParty[monIndex], MON_DATA_NICKNAME, text);   \
    }                                                                   \
    StringGet_Nickname(text);                                           \
    toCpy = text;

// Ensure the defined length for an item name can contain the full defined length of a berry name.
// This ensures that custom Enigma Berry names will fit in the text buffer at the top of BattleStringExpandPlaceholders.
STATIC_ASSERT(BERRY_NAME_LENGTH + ARRAY_COUNT(sText_BerrySuffix) <= ITEM_NAME_LENGTH, BerryNameTooLong);

u32 BattleStringExpandPlaceholders(const u8 *src, u8 *dst)
{
    u32 dstID = 0; // if they used dstID, why not use srcID as well?
    const u8 *toCpy = NULL;
    // This buffer may hold either the name of a trainer, Pokémon, or item.
    u8 text[max(max(max(32, TRAINER_NAME_LENGTH + 1), POKEMON_NAME_LENGTH + 1), ITEM_NAME_LENGTH)];
    u8 multiplayerId;
    s32 i;

    src = GetLocalizedString(src);

    if (gBattleTypeFlags & BATTLE_TYPE_RECORDED_LINK)
        multiplayerId = gRecordedBattleMultiplayerId;
    else
        multiplayerId = GetMultiplayerId();

    while (*src != EOS)
    {
        if (*src == PLACEHOLDER_BEGIN)
        {
            src++;
            switch (*src)
            {
            case B_TXT_BUFF1:
                if (gBattleTextBuff1[0] == B_BUFF_PLACEHOLDER_BEGIN)
                {
                    ExpandBattleTextBuffPlaceholders(gBattleTextBuff1, gStringVar1);
                    toCpy = gStringVar1;
                }
                else
                {
                    toCpy = TryGetStatusString(gBattleTextBuff1);
                    if (toCpy == NULL)
                        toCpy = gBattleTextBuff1;
                }
                break;
            case B_TXT_BUFF2:
                if (gBattleTextBuff2[0] == B_BUFF_PLACEHOLDER_BEGIN)
                {
                    ExpandBattleTextBuffPlaceholders(gBattleTextBuff2, gStringVar2);
                    toCpy = gStringVar2;
                }
                else
                {
                    toCpy = gBattleTextBuff2;
                }
                break;
            case B_TXT_BUFF3:
                if (gBattleTextBuff3[0] == B_BUFF_PLACEHOLDER_BEGIN)
                {
                    ExpandBattleTextBuffPlaceholders(gBattleTextBuff3, gStringVar3);
                    toCpy = gStringVar3;
                }
                else
                {
                    toCpy = gBattleTextBuff3;
                }
                break;
            case B_TXT_COPY_VAR_1:
                toCpy = gStringVar1;
                break;
            case B_TXT_COPY_VAR_2:
                toCpy = gStringVar2;
                break;
            case B_TXT_COPY_VAR_3:
                toCpy = gStringVar3;
                break;
            case B_TXT_PLAYER_MON1_NAME: // first player poke name
                GetMonData(&gPlayerParty[gBattlerPartyIndexes[GetBattlerAtPosition(B_POSITION_PLAYER_LEFT)]],
                           MON_DATA_NICKNAME, text);
                StringGet_Nickname(text);
                toCpy = text;
                break;
            case B_TXT_OPPONENT_MON1_NAME: // first enemy poke name
                GetMonData(&gEnemyParty[gBattlerPartyIndexes[GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT)]],
                           MON_DATA_NICKNAME, text);
                StringGet_Nickname(text);
                toCpy = text;
                break;
            case B_TXT_PLAYER_MON2_NAME: // second player poke name
                GetMonData(&gPlayerParty[gBattlerPartyIndexes[GetBattlerAtPosition(B_POSITION_PLAYER_RIGHT)]],
                           MON_DATA_NICKNAME, text);
                StringGet_Nickname(text);
                toCpy = text;
                break;
            case B_TXT_OPPONENT_MON2_NAME: // second enemy poke name
                GetMonData(&gEnemyParty[gBattlerPartyIndexes[GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT)]],
                           MON_DATA_NICKNAME, text);
                StringGet_Nickname(text);
                toCpy = text;
                break;
            case B_TXT_LINK_PLAYER_MON1_NAME: // link first player poke name
                GetMonData(&gPlayerParty[gBattlerPartyIndexes[gLinkPlayers[multiplayerId].id]],
                           MON_DATA_NICKNAME, text);
                StringGet_Nickname(text);
                toCpy = text;
                break;
            case B_TXT_LINK_OPPONENT_MON1_NAME: // link first opponent poke name
                GetMonData(&gEnemyParty[gBattlerPartyIndexes[gLinkPlayers[multiplayerId].id ^ 1]],
                           MON_DATA_NICKNAME, text);
                StringGet_Nickname(text);
                toCpy = text;
                break;
            case B_TXT_LINK_PLAYER_MON2_NAME: // link second player poke name
                GetMonData(&gPlayerParty[gBattlerPartyIndexes[gLinkPlayers[multiplayerId].id ^ 2]],
                           MON_DATA_NICKNAME, text);
                StringGet_Nickname(text);
                toCpy = text;
                break;
            case B_TXT_LINK_OPPONENT_MON2_NAME: // link second opponent poke name
                GetMonData(&gEnemyParty[gBattlerPartyIndexes[gLinkPlayers[multiplayerId].id ^ 3]],
                           MON_DATA_NICKNAME, text);
                StringGet_Nickname(text);
                toCpy = text;
                break;
            case B_TXT_ATK_NAME_WITH_PREFIX_MON1: // attacker name with prefix, only battler 0/1
                HANDLE_NICKNAME_STRING_CASE(gBattlerAttacker,
                                            gBattlerPartyIndexes[GetBattlerAtPosition(GET_BATTLER_SIDE(gBattlerAttacker))])
                break;
            case B_TXT_ATK_PARTNER_NAME: // attacker partner name
                if (GetBattlerSide(gBattlerAttacker) == B_SIDE_PLAYER)
                    GetMonData(&gPlayerParty[gBattlerPartyIndexes[GetBattlerAtPosition(GET_BATTLER_SIDE(gBattlerAttacker)) + 2]], MON_DATA_NICKNAME, text);
                else
                    GetMonData(&gEnemyParty[gBattlerPartyIndexes[GetBattlerAtPosition(GET_BATTLER_SIDE(gBattlerAttacker)) + 2]], MON_DATA_NICKNAME, text);

                StringGet_Nickname(text);
                toCpy = text;
                break;
            case B_TXT_ATK_NAME_WITH_PREFIX: // attacker name with prefix
                HANDLE_NICKNAME_STRING_CASE(gBattlerAttacker, gBattlerPartyIndexes[gBattlerAttacker])
                break;
            case B_TXT_DEF_NAME_WITH_PREFIX: // target name with prefix
                HANDLE_NICKNAME_STRING_CASE(gBattlerTarget, gBattlerPartyIndexes[gBattlerTarget])
                break;
            case B_TXT_EFF_NAME_WITH_PREFIX: // effect battler name with prefix
                HANDLE_NICKNAME_STRING_CASE(gEffectBattler, gBattlerPartyIndexes[gEffectBattler])
                break;
            case B_TXT_ACTIVE_NAME_WITH_PREFIX: // active battler name with prefix
                HANDLE_NICKNAME_STRING_CASE(gActiveBattler, gBattlerPartyIndexes[gActiveBattler])
                break;
            case B_TXT_SCR_ACTIVE_NAME_WITH_PREFIX: // scripting active battler name with prefix
                HANDLE_NICKNAME_STRING_CASE(gBattleScripting.battler, gBattlerPartyIndexes[gBattleScripting.battler])
                break;
            case B_TXT_CURRENT_MOVE: // current move name
                if (gBattleMsgDataPtr->currentMove >= MOVES_COUNT)
                    toCpy = sATypeMove_Table[gBattleStruct->stringMoveType];
                else
                    toCpy = gMoveNames[gBattleMsgDataPtr->currentMove];
                break;
            case B_TXT_LAST_MOVE: // originally used move name
                if (gBattleMsgDataPtr->originallyUsedMove >= MOVES_COUNT)
                    toCpy = sATypeMove_Table[gBattleStruct->stringMoveType];
                else
                    toCpy = gMoveNames[gBattleMsgDataPtr->originallyUsedMove];
                break;
            case B_TXT_LAST_ITEM: // last used item
                if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK))
                {
                    if (gLastUsedItem == ITEM_ENIGMA_BERRY)
                    {
                        if (!(gBattleTypeFlags & BATTLE_TYPE_MULTI))
                        {
                            if ((gBattleScripting.multiplayerId != 0 && (gPotentialItemEffectBattler & BIT_SIDE))
                                || (gBattleScripting.multiplayerId == 0 && !(gPotentialItemEffectBattler & BIT_SIDE)))
                            {
                                StringCopy(text, gEnigmaBerries[gPotentialItemEffectBattler].name);
                                StringAppend(text, sText_BerrySuffix);
                                toCpy = text;
                            }
                            else
                            {
                                toCpy = sText_EnigmaBerry;
                            }
                        }
                        else
                        {
                            if (gLinkPlayers[gBattleScripting.multiplayerId].id == gPotentialItemEffectBattler)
                            {
                                StringCopy(text, gEnigmaBerries[gPotentialItemEffectBattler].name);
                                StringAppend(text, sText_BerrySuffix);
                                toCpy = text;
                            }
                            else
                            {
                                toCpy = sText_EnigmaBerry;
                            }
                        }
                    }
                    else
                    {
                        CopyItemName(gLastUsedItem, text);
                        toCpy = text;
                    }
                }
                else
                {
                    CopyItemName(gLastUsedItem, text);
                    toCpy = text;
                }
                break;
            case B_TXT_LAST_ABILITY: // last used ability
                toCpy = gAbilityNames[gLastUsedAbility];
                break;
            case B_TXT_ATK_ABILITY: // attacker ability
                toCpy = gAbilityNames[sBattlerAbilities[gBattlerAttacker]];
                break;
            case B_TXT_DEF_ABILITY: // target ability
                toCpy = gAbilityNames[sBattlerAbilities[gBattlerTarget]];
                break;
            case B_TXT_SCR_ACTIVE_ABILITY: // scripting active ability
                toCpy = gAbilityNames[sBattlerAbilities[gBattleScripting.battler]];
                break;
            case B_TXT_EFF_ABILITY: // effect battler ability
                toCpy = gAbilityNames[sBattlerAbilities[gEffectBattler]];
                break;
            case B_TXT_TRAINER1_CLASS: // trainer class name
                if (gBattleTypeFlags & BATTLE_TYPE_SECRET_BASE)
                    toCpy = gTrainerClassNames[GetSecretBaseTrainerClass()];
                else if (gTrainerBattleOpponent_A == TRAINER_UNION_ROOM)
                    toCpy = gTrainerClassNames[GetUnionRoomTrainerClass()];
                else if (gTrainerBattleOpponent_A == TRAINER_FRONTIER_BRAIN)
                    toCpy = gTrainerClassNames[GetFrontierBrainTrainerClass()];
                else if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
                    toCpy = gTrainerClassNames[GetFrontierOpponentClass(gTrainerBattleOpponent_A)];
                else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
                    toCpy = gTrainerClassNames[GetTrainerHillOpponentClass(gTrainerBattleOpponent_A)];
                else if (gBattleTypeFlags & BATTLE_TYPE_EREADER_TRAINER)
                    toCpy = gTrainerClassNames[GetEreaderTrainerClassId()];
                else
                    toCpy = gTrainerClassNames[gTrainers[gTrainerBattleOpponent_A].trainerClass];
                break;
            case B_TXT_TRAINER1_NAME: // trainer1 name
                if (gBattleTypeFlags & BATTLE_TYPE_SECRET_BASE)
                {
                    for (i = 0; i < (s32) ARRAY_COUNT(gBattleResources->secretBase->trainerName); i++)
                        text[i] = gBattleResources->secretBase->trainerName[i];
                    text[i] = EOS;
                    ConvertInternationalString(text, gBattleResources->secretBase->language);
                    toCpy = text;
                }
                else if (gTrainerBattleOpponent_A == TRAINER_UNION_ROOM)
                {
                    toCpy = gLinkPlayers[multiplayerId ^ BIT_SIDE].name;
                }
                else if (gTrainerBattleOpponent_A == TRAINER_FRONTIER_BRAIN)
                {
                    CopyFrontierBrainTrainerName(text);
                    toCpy = text;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
                {
                    GetFrontierTrainerName(text, gTrainerBattleOpponent_A);
                    toCpy = text;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
                {
                    GetTrainerHillTrainerName(text, gTrainerBattleOpponent_A);
                    toCpy = text;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_EREADER_TRAINER)
                {
                    GetEreaderTrainerName(text);
                    toCpy = text;
                }
                else
                {
                    toCpy = gTrainers[gTrainerBattleOpponent_A].trainerName;
                }
                break;
            case B_TXT_LINK_PLAYER_NAME: // link player name
                toCpy = gLinkPlayers[multiplayerId].name;
                break;
            case B_TXT_LINK_PARTNER_NAME: // link partner name
                toCpy = gLinkPlayers[GetBattlerMultiplayerId(BATTLE_PARTNER(gLinkPlayers[multiplayerId].id))].name;
                break;
            case B_TXT_LINK_OPPONENT1_NAME: // link opponent 1 name
                toCpy = gLinkPlayers[GetBattlerMultiplayerId(BATTLE_OPPOSITE(gLinkPlayers[multiplayerId].id))].name;
                break;
            case B_TXT_LINK_OPPONENT2_NAME: // link opponent 2 name
                toCpy = gLinkPlayers[GetBattlerMultiplayerId(BATTLE_PARTNER(BATTLE_OPPOSITE(gLinkPlayers[multiplayerId].id)))].name;
                break;
            case B_TXT_LINK_SCR_TRAINER_NAME: // link scripting active name
                toCpy = gLinkPlayers[GetBattlerMultiplayerId(gBattleScripting.battler)].name;
                break;
            case B_TXT_PLAYER_NAME: // player name
                if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
                    toCpy = gLinkPlayers[0].name;
                else
                    toCpy = gSaveBlock2Ptr->playerName;
                break;
            case B_TXT_TRAINER1_LOSE_TEXT: // trainerA lose text
                if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
                {
                    CopyFrontierTrainerText(FRONTIER_PLAYER_WON_TEXT, gTrainerBattleOpponent_A);
                    toCpy = gStringVar4;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
                {
                    CopyTrainerHillTrainerText(TRAINER_HILL_TEXT_PLAYER_WON, gTrainerBattleOpponent_A);
                    toCpy = gStringVar4;
                }
                else
                {
                    toCpy = GetTrainerALoseText();
                }
                break;
            case B_TXT_TRAINER1_WIN_TEXT: // trainerA win text
                if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
                {
                    CopyFrontierTrainerText(FRONTIER_PLAYER_LOST_TEXT, gTrainerBattleOpponent_A);
                    toCpy = gStringVar4;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
                {
                    CopyTrainerHillTrainerText(TRAINER_HILL_TEXT_PLAYER_LOST, gTrainerBattleOpponent_A);
                    toCpy = gStringVar4;
                }
                break;
            case B_TXT_26: // ?
                HANDLE_NICKNAME_STRING_CASE(gBattleScripting.battler, *(&gBattleStruct->scriptPartyIdx))
                break;
            case B_TXT_PC_CREATOR_NAME: // lanette pc
                if (FlagGet(FLAG_SYS_PC_LANETTE))
                    toCpy = sText_Lanettes;
                else
                    toCpy = sText_Someones;
                break;
            case B_TXT_ATK_PREFIX2:
                if (GetBattlerSide(gBattlerAttacker) == B_SIDE_PLAYER)
                    toCpy = sText_AllyPkmnPrefix2;
                else
                    toCpy = sText_FoePkmnPrefix3;
                break;
            case B_TXT_DEF_PREFIX2:
                if (GetBattlerSide(gBattlerTarget) == B_SIDE_PLAYER)
                    toCpy = sText_AllyPkmnPrefix2;
                else
                    toCpy = sText_FoePkmnPrefix3;
                break;
            case B_TXT_ATK_PREFIX1:
                if (GetBattlerSide(gBattlerAttacker) == B_SIDE_PLAYER)
                    toCpy = sText_AllyPkmnPrefix;
                else
                    toCpy = sText_FoePkmnPrefix2;
                break;
            case B_TXT_DEF_PREFIX1:
                if (GetBattlerSide(gBattlerTarget) == B_SIDE_PLAYER)
                    toCpy = sText_AllyPkmnPrefix;
                else
                    toCpy = sText_FoePkmnPrefix2;
                break;
            case B_TXT_ATK_PREFIX3:
                if (GetBattlerSide(gBattlerAttacker) == B_SIDE_PLAYER)
                    toCpy = sText_AllyPkmnPrefix3;
                else
                    toCpy = sText_FoePkmnPrefix4;
                break;
            case B_TXT_DEF_PREFIX3:
                if (GetBattlerSide(gBattlerTarget) == B_SIDE_PLAYER)
                    toCpy = sText_AllyPkmnPrefix3;
                else
                    toCpy = sText_FoePkmnPrefix4;
                break;
            case B_TXT_TRAINER2_CLASS:
                if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
                    toCpy = gTrainerClassNames[GetFrontierOpponentClass(gTrainerBattleOpponent_B)];
                else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
                    toCpy = gTrainerClassNames[GetTrainerHillOpponentClass(gTrainerBattleOpponent_B)];
                else
                    toCpy = gTrainerClassNames[gTrainers[gTrainerBattleOpponent_B].trainerClass];
                break;
            case B_TXT_TRAINER2_NAME:
                if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
                {
                    GetFrontierTrainerName(text, gTrainerBattleOpponent_B);
                    toCpy = text;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
                {
                    GetTrainerHillTrainerName(text, gTrainerBattleOpponent_B);
                    toCpy = text;
                }
                else
                {
                    toCpy = gTrainers[gTrainerBattleOpponent_B].trainerName;
                }
                break;
            case B_TXT_TRAINER2_LOSE_TEXT:
                if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
                {
                    CopyFrontierTrainerText(FRONTIER_PLAYER_WON_TEXT, gTrainerBattleOpponent_B);
                    toCpy = gStringVar4;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
                {
                    CopyTrainerHillTrainerText(TRAINER_HILL_TEXT_PLAYER_WON, gTrainerBattleOpponent_B);
                    toCpy = gStringVar4;
                }
                else
                {
                    toCpy = GetTrainerBLoseText();
                }
                break;
            case B_TXT_TRAINER2_WIN_TEXT:
                if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
                {
                    CopyFrontierTrainerText(FRONTIER_PLAYER_LOST_TEXT, gTrainerBattleOpponent_B);
                    toCpy = gStringVar4;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
                {
                    CopyTrainerHillTrainerText(TRAINER_HILL_TEXT_PLAYER_LOST, gTrainerBattleOpponent_B);
                    toCpy = gStringVar4;
                }
                break;
            case B_TXT_PARTNER_CLASS:
                toCpy = gTrainerClassNames[GetFrontierOpponentClass(gPartnerTrainerId)];
                break;
            case B_TXT_PARTNER_NAME:
                GetFrontierTrainerName(text, gPartnerTrainerId);
                toCpy = text;
                break;
            }

            // missing if (toCpy != NULL) check
            while (*toCpy != EOS)
            {
                dst[dstID] = *toCpy;
                dstID++;
                toCpy++;
            }
            if (*src == B_TXT_TRAINER1_LOSE_TEXT || *src == B_TXT_TRAINER2_LOSE_TEXT
                || *src == B_TXT_TRAINER1_WIN_TEXT || *src == B_TXT_TRAINER2_WIN_TEXT)
            {
                dst[dstID] = EXT_CTRL_CODE_BEGIN;
                dstID++;
                dst[dstID] = EXT_CTRL_CODE_PAUSE_UNTIL_PRESS;
                dstID++;
            }
        }
        else
        {
            dst[dstID] = *src;
            dstID++;
        }
        src++;
    }

    dst[dstID] = *src;
    dstID++;

    return dstID;
}

static void ExpandBattleTextBuffPlaceholders(const u8 *src, u8 *dst)
{
    u32 srcID = 1;
    u32 value = 0;
    u8 nickname[POKEMON_NAME_LENGTH + 1];
    u16 hword;

    *dst = EOS;
    while (src[srcID] != B_BUFF_EOS)
    {
        switch (src[srcID])
        {
        case B_BUFF_STRING: // battle string
            hword = T1_READ_16(&src[srcID + 1]);
            StringAppend(dst, gBattleStringsTable[hword - BATTLESTRINGS_TABLE_START]);
            srcID += 3;
            break;
        case B_BUFF_NUMBER: // int to string
            switch (src[srcID + 1])
            {
            case 1:
                value = src[srcID + 3];
                break;
            case 2:
                value = T1_READ_16(&src[srcID + 3]);
                break;
            case 4:
                value = T1_READ_32(&src[srcID + 3]);
                break;
            }
            ConvertIntToDecimalStringN(dst, value, STR_CONV_MODE_LEFT_ALIGN, src[srcID + 2]);
            srcID += src[srcID + 1] + 3;
            break;
        case B_BUFF_MOVE: // move name
            StringAppend(dst, gMoveNames[T1_READ_16(&src[srcID + 1])]);
            srcID += 3;
            break;
        case B_BUFF_TYPE: // type name
            StringAppend(dst, gTypeNames[src[srcID + 1]]);
            srcID += 2;
            break;
        case B_BUFF_MON_NICK_WITH_PREFIX: // poke nick with prefix
            if (GetBattlerSide(src[srcID + 1]) == B_SIDE_PLAYER)
            {
                GetMonData(&gPlayerParty[src[srcID + 2]], MON_DATA_NICKNAME, nickname);
            }
            else
            {
                if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
                    StringAppend(dst, sText_FoePkmnPrefix);
                else
                    StringAppend(dst, sText_WildPkmnPrefix);

                GetMonData(&gEnemyParty[src[srcID + 2]], MON_DATA_NICKNAME, nickname);
            }
            StringGet_Nickname(nickname);
            StringAppend(dst, nickname);
            srcID += 3;
            break;
        case B_BUFF_STAT: // stats
            StringAppend(dst, gStatNamesTable[src[srcID + 1]]);
            srcID += 2;
            break;
        case B_BUFF_SPECIES: // species name
            GetSpeciesName(dst, T1_READ_16(&src[srcID + 1]));
            srcID += 3;
            break;
        case B_BUFF_MON_NICK: // poke nick without prefix
            if (GetBattlerSide(src[srcID + 1]) == B_SIDE_PLAYER)
                GetMonData(&gPlayerParty[src[srcID + 2]], MON_DATA_NICKNAME, dst);
            else
                GetMonData(&gEnemyParty[src[srcID + 2]], MON_DATA_NICKNAME, dst);
            StringGet_Nickname(dst);
            srcID += 3;
            break;
        case B_BUFF_NEGATIVE_FLAVOR: // flavor table
            StringAppend(dst, gPokeblockWasTooXStringTable[src[srcID + 1]]);
            srcID += 2;
            break;
        case B_BUFF_ABILITY: // ability names
            StringAppend(dst, gAbilityNames[src[srcID + 1]]);
            srcID += 2;
            break;
        case B_BUFF_ITEM: // item name
            hword = T1_READ_16(&src[srcID + 1]);
            if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK))
            {
                if (hword == ITEM_ENIGMA_BERRY)
                {
                    if (gLinkPlayers[gBattleScripting.multiplayerId].id == gPotentialItemEffectBattler)
                    {
                        StringCopy(dst, gEnigmaBerries[gPotentialItemEffectBattler].name);
                        StringAppend(dst, sText_BerrySuffix);
                    }
                    else
                    {
                        StringAppend(dst, sText_EnigmaBerry);
                    }
                }
                else
                {
                    CopyItemName(hword, dst);
                }
            }
            else
            {
                CopyItemName(hword, dst);
            }
            srcID += 3;
            break;
        }
    }
}

// Loads one of two text strings into the provided buffer. This is functionally
// unused, since the value loaded into the buffer is not read; it loaded one of
// two particles (either "は" or "の") which works in tandem with ChooseTypeOfMoveUsedString
// below to effect changes in the meaning of the line.
static void ChooseMoveUsedParticle(u8 *textBuff)
{
    s32 counter = 0;
    u32 i = 0;

    while (counter != MAX_MON_MOVES)
    {
        if (sGrammarMoveUsedTable[i] == 0)
            counter++;
        if (sGrammarMoveUsedTable[i++] == gBattleMsgDataPtr->currentMove)
            break;
    }

    if (counter >= 0)
    {
        if (counter <= 2)
            StringCopy(textBuff, sText_SpaceIs); // is
        else if (counter <= MAX_MON_MOVES)
            StringCopy(textBuff, sText_ApostropheS); // 's
    }
}

// Appends "!" to the text buffer `dst`. In the original Japanese this looked
// into the table of moves at sGrammarMoveUsedTable and varied the line accordingly.
//
// sText_ExclamationMark was a plain "!", used for any attack not on the list.
// It resulted in the translation "<NAME>'s <ATTACK>!".
//
// sText_ExclamationMark2 was "を つかった！". This resulted in the translation
// "<NAME> used <ATTACK>!", which was used for all attacks in English.
//
// sText_ExclamationMark3 was "した！". This was used for those moves whose
// names were verbs, such as Recover, and resulted in translations like "<NAME>
// recovered itself!".
//
// sText_ExclamationMark4 was "を した！" This resulted in a translation of
// "<NAME> did an <ATTACK>!".
//
// sText_ExclamationMark5 was " こうげき！" This resulted in a translation of
// "<NAME>'s <ATTACK> attack!".
static void ChooseTypeOfMoveUsedString(u8 *dst)
{
    s32 counter = 0;
    s32 i = 0;

    while (*dst != EOS)
        dst++;

    while (counter != MAX_MON_MOVES)
    {
        if (sGrammarMoveUsedTable[i] == MOVE_NONE)
            counter++;
        if (sGrammarMoveUsedTable[i++] == gBattleMsgDataPtr->currentMove)
            break;
    }

    switch (counter)
    {
    case 0:
        StringCopy(dst, sText_ExclamationMark);
        break;
    case 1:
        StringCopy(dst, sText_ExclamationMark2);
        break;
    case 2:
        StringCopy(dst, sText_ExclamationMark3);
        break;
    case 3:
        StringCopy(dst, sText_ExclamationMark4);
        break;
    case 4:
        StringCopy(dst, sText_ExclamationMark5);
        break;
    }
}

void BattlePutTextOnWindow(const u8 *text, u8 windowId)
{
    const struct BattleWindowText *textInfo = sBattleTextOnWindowsInfo[gBattleScripting.windowsType];
    bool32 copyToVram;
    struct TextPrinterTemplate printerTemplate;
    u8 speed;

    if (windowId & B_WIN_COPYTOVRAM)
    {
        windowId &= ~B_WIN_COPYTOVRAM;
        copyToVram = FALSE;
    }
    else
    {
        FillWindowPixelBuffer(windowId, textInfo[windowId].fillValue);
        copyToVram = TRUE;
    }

    printerTemplate.currentChar = text;
    printerTemplate.windowId = windowId;
    printerTemplate.fontId = textInfo[windowId].fontId;
    printerTemplate.x = textInfo[windowId].x;
    printerTemplate.y = textInfo[windowId].y;
    printerTemplate.currentX = printerTemplate.x;
    printerTemplate.currentY = printerTemplate.y;
    printerTemplate.letterSpacing = textInfo[windowId].letterSpacing;
    printerTemplate.lineSpacing = textInfo[windowId].lineSpacing;
    printerTemplate.unk = 0;
    printerTemplate.fgColor = textInfo[windowId].fgColor;
    printerTemplate.bgColor = textInfo[windowId].bgColor;
    printerTemplate.shadowColor = textInfo[windowId].shadowColor;

    if (printerTemplate.x == 0xFF)
    {
        u32 width = GetBattleWindowTemplatePixelWidth(gBattleScripting.windowsType, windowId);
        s32 alignX = GetStringCenterAlignXOffsetWithLetterSpacing(printerTemplate.fontId, printerTemplate.currentChar, width, printerTemplate.letterSpacing);
        printerTemplate.x = printerTemplate.currentX = alignX;
    }

    if (windowId == ARENA_WIN_JUDGMENT_TEXT)
        gTextFlags.useAlternateDownArrow = FALSE;
    else
        gTextFlags.useAlternateDownArrow = TRUE;

    if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED))
        gTextFlags.autoScroll = TRUE;
    else
        gTextFlags.autoScroll = FALSE;

    if (windowId == B_WIN_MSG || windowId == ARENA_WIN_JUDGMENT_TEXT)
    {
        if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK))
            speed = 1;
        else if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
            speed = sRecordedBattleTextSpeeds[GetTextSpeedInRecordedBattle()];
        else
            speed = GetPlayerTextSpeedDelay();

        gTextFlags.canABSpeedUpPrint = 1;
    }
    else
    {
        speed = textInfo[windowId].speed;
        gTextFlags.canABSpeedUpPrint = 0;
    }

    AddTextPrinter(&printerTemplate, speed, NULL);

    if (copyToVram)
    {
        PutWindowTilemap(windowId);
        CopyWindowToVram(windowId, COPYWIN_FULL);
    }
}

void SetPPNumbersPaletteInMoveSelection(void)
{
    struct ChooseMoveStruct *chooseMoveStruct = (struct ChooseMoveStruct *)(&gBattleBufferA[gActiveBattler][4]);
    const u16 *palPtr = gPPTextPalette;
    u8 var = GetCurrentPPToMaxPPState(chooseMoveStruct->currentPP[gMoveSelectionCursor[gActiveBattler]],
                         chooseMoveStruct->maxPP[gMoveSelectionCursor[gActiveBattler]]);

    gPlttBufferUnfaded[BG_PLTT_ID(5) + 12] = palPtr[(var * 2) + 0];
    gPlttBufferUnfaded[BG_PLTT_ID(5) + 11] = palPtr[(var * 2) + 1];

    CpuCopy16(&gPlttBufferUnfaded[BG_PLTT_ID(5) + 12], &gPlttBufferFaded[BG_PLTT_ID(5) + 12], PLTT_SIZEOF(1));
    CpuCopy16(&gPlttBufferUnfaded[BG_PLTT_ID(5) + 11], &gPlttBufferFaded[BG_PLTT_ID(5) + 11], PLTT_SIZEOF(1));
}

u8 GetCurrentPPToMaxPPState(u8 currentPP, u8 maxPP)
{
    if (maxPP == currentPP)
    {
        return 3;
    }
    else if (maxPP <= 2)
    {
        if (currentPP > 1)
            return 3;
        else
            return 2 - currentPP;
    }
    else if (maxPP <= 7)
    {
        if (currentPP > 2)
            return 3;
        else
            return 2 - currentPP;
    }
    else
    {
        if (currentPP == 0)
            return 2;
        if (currentPP <= maxPP / 4)
            return 1;
        if (currentPP > maxPP / 2)
            return 3;
    }

    return 0;
}

// BEGIN GENERATED LOCALIZATION EXPORTS
// These pointers expose file-local translated strings to the runtime resolver.
const u8 *const gLocalizationSource_C00000 = sText_PkmnGainedEXP;
const u8 *const gLocalizationSource_C00001 = sText_ABoosted;
const u8 *const gLocalizationSource_C00002 = sText_PkmnGrewToLv;
const u8 *const gLocalizationSource_C00003 = sText_PkmnLearnedMove;
const u8 *const gLocalizationSource_C00004 = sText_TryToLearnMove1;
const u8 *const gLocalizationSource_C00005 = sText_TryToLearnMove2;
const u8 *const gLocalizationSource_C00006 = sText_TryToLearnMove3;
const u8 *const gLocalizationSource_C00007 = sText_PkmnForgotMove;
const u8 *const gLocalizationSource_C00008 = sText_StopLearningMove;
const u8 *const gLocalizationSource_C00009 = sText_DidNotLearnMove;
const u8 *const gLocalizationSource_C00010 = sText_UseNextPkmn;
const u8 *const gLocalizationSource_C00011 = sText_AddCaughtMonToParty;
const u8 *const gLocalizationSource_C00012 = sText_AttackMissed;
const u8 *const gLocalizationSource_C00013 = sText_PkmnProtectedItself;
const u8 *const gLocalizationSource_C00014 = sText_AvoidedDamage;
const u8 *const gLocalizationSource_C00015 = sText_PkmnMakesGroundMiss;
const u8 *const gLocalizationSource_C00016 = sText_PkmnAvoidedAttack;
const u8 *const gLocalizationSource_C00017 = sText_ItDoesntAffect;
const u8 *const gLocalizationSource_C00018 = sText_AttackerFainted;
const u8 *const gLocalizationSource_C00019 = sText_TargetFainted;
const u8 *const gLocalizationSource_C00020 = sText_PlayerGotMoney;
const u8 *const gLocalizationSource_C00021 = sText_PlayerWhiteout;
const u8 *const gLocalizationSource_C00022 = sText_PlayerWhiteout2;
const u8 *const gLocalizationSource_C00023 = sText_PreventsEscape;
const u8 *const gLocalizationSource_C00024 = sText_CantEscape2;
const u8 *const gLocalizationSource_C00025 = sText_AttackerCantEscape;
const u8 *const gLocalizationSource_C00026 = sText_HitXTimes;
const u8 *const gLocalizationSource_C00027 = sText_PkmnFellAsleep;
const u8 *const gLocalizationSource_C00028 = sText_PkmnMadeSleep;
const u8 *const gLocalizationSource_C00029 = sText_PkmnAlreadyAsleep;
const u8 *const gLocalizationSource_C00030 = sText_PkmnAlreadyAsleep2;
const u8 *const gLocalizationSource_C00031 = sText_PkmnWasntAffected;
const u8 *const gLocalizationSource_C00032 = sText_PkmnWasPoisoned;
const u8 *const gLocalizationSource_C00033 = sText_PkmnPoisonedBy;
const u8 *const gLocalizationSource_C00034 = sText_PkmnHurtByPoison;
const u8 *const gLocalizationSource_C00035 = sText_PkmnAlreadyPoisoned;
const u8 *const gLocalizationSource_C00036 = sText_PkmnBadlyPoisoned;
const u8 *const gLocalizationSource_C00037 = sText_PkmnEnergyDrained;
const u8 *const gLocalizationSource_C00038 = sText_PkmnWasBurned;
const u8 *const gLocalizationSource_C00039 = sText_PkmnBurnedBy;
const u8 *const gLocalizationSource_C00040 = sText_PkmnHurtByBurn;
const u8 *const gLocalizationSource_C00041 = sText_PkmnAlreadyHasBurn;
const u8 *const gLocalizationSource_C00042 = sText_PkmnWasFrozen;
const u8 *const gLocalizationSource_C00043 = sText_PkmnFrozenBy;
const u8 *const gLocalizationSource_C00044 = sText_PkmnIsFrozen;
const u8 *const gLocalizationSource_C00045 = sText_PkmnWasDefrosted;
const u8 *const gLocalizationSource_C00046 = sText_PkmnWasDefrosted2;
const u8 *const gLocalizationSource_C00047 = sText_PkmnWasDefrostedBy;
const u8 *const gLocalizationSource_C00048 = sText_PkmnWasParalyzed;
const u8 *const gLocalizationSource_C00049 = sText_PkmnWasParalyzedBy;
const u8 *const gLocalizationSource_C00050 = sText_PkmnIsParalyzed;
const u8 *const gLocalizationSource_C00051 = sText_PkmnIsAlreadyParalyzed;
const u8 *const gLocalizationSource_C00052 = sText_PkmnHealedParalysis;
const u8 *const gLocalizationSource_C00053 = sText_PkmnDreamEaten;
const u8 *const gLocalizationSource_C00054 = sText_StatsWontIncrease;
const u8 *const gLocalizationSource_C00055 = sText_StatsWontDecrease;
const u8 *const gLocalizationSource_C00056 = sText_TeamStoppedWorking;
const u8 *const gLocalizationSource_C00057 = sText_FoeStoppedWorking;
const u8 *const gLocalizationSource_C00058 = sText_PkmnIsConfused;
const u8 *const gLocalizationSource_C00059 = sText_PkmnHealedConfusion;
const u8 *const gLocalizationSource_C00060 = sText_PkmnWasConfused;
const u8 *const gLocalizationSource_C00061 = sText_PkmnAlreadyConfused;
const u8 *const gLocalizationSource_C00062 = sText_PkmnFellInLove;
const u8 *const gLocalizationSource_C00063 = sText_PkmnInLove;
const u8 *const gLocalizationSource_C00064 = sText_PkmnImmobilizedByLove;
const u8 *const gLocalizationSource_C00065 = sText_PkmnBlownAway;
const u8 *const gLocalizationSource_C00066 = sText_PkmnChangedType;
const u8 *const gLocalizationSource_C00067 = sText_PkmnFlinched;
const u8 *const gLocalizationSource_C00068 = sText_PkmnRegainedHealth;
const u8 *const gLocalizationSource_C00069 = sText_PkmnHPFull;
const u8 *const gLocalizationSource_C00070 = sText_PkmnRaisedSpDef;
const u8 *const gLocalizationSource_C00071 = sText_PkmnRaisedSpDefALittle;
const u8 *const gLocalizationSource_C00072 = sText_PkmnRaisedDef;
const u8 *const gLocalizationSource_C00073 = sText_PkmnRaisedDefALittle;
const u8 *const gLocalizationSource_C00074 = sText_PkmnCoveredByVeil;
const u8 *const gLocalizationSource_C00075 = sText_PkmnUsedSafeguard;
const u8 *const gLocalizationSource_C00076 = sText_PkmnSafeguardExpired;
const u8 *const gLocalizationSource_C00077 = sText_PkmnWentToSleep;
const u8 *const gLocalizationSource_C00078 = sText_PkmnSleptHealthy;
const u8 *const gLocalizationSource_C00079 = sText_PkmnWhippedWhirlwind;
const u8 *const gLocalizationSource_C00080 = sText_PkmnTookSunlight;
const u8 *const gLocalizationSource_C00081 = sText_PkmnLoweredHead;
const u8 *const gLocalizationSource_C00082 = sText_PkmnIsGlowing;
const u8 *const gLocalizationSource_C00083 = sText_PkmnFlewHigh;
const u8 *const gLocalizationSource_C00084 = sText_PkmnDugHole;
const u8 *const gLocalizationSource_C00085 = sText_PkmnHidUnderwater;
const u8 *const gLocalizationSource_C00086 = sText_PkmnSprangUp;
const u8 *const gLocalizationSource_C00087 = sText_PkmnSqueezedByBind;
const u8 *const gLocalizationSource_C00088 = sText_PkmnTrappedInVortex;
const u8 *const gLocalizationSource_C00089 = sText_PkmnTrappedBySandTomb;
const u8 *const gLocalizationSource_C00090 = sText_PkmnWrappedBy;
const u8 *const gLocalizationSource_C00091 = sText_PkmnClamped;
const u8 *const gLocalizationSource_C00092 = sText_PkmnHurtBy;
const u8 *const gLocalizationSource_C00093 = sText_PkmnFreedFrom;
const u8 *const gLocalizationSource_C00094 = sText_PkmnCrashed;
const u8 *const gLocalizationSource_C00095 = gText_PkmnShroudedInMist;
const u8 *const gLocalizationSource_C00096 = sText_PkmnProtectedByMist;
const u8 *const gLocalizationSource_C00097 = gText_PkmnGettingPumped;
const u8 *const gLocalizationSource_C00098 = sText_PkmnHitWithRecoil;
const u8 *const gLocalizationSource_C00099 = sText_PkmnProtectedItself2;
const u8 *const gLocalizationSource_C00100 = sText_PkmnBuffetedBySandstorm;
const u8 *const gLocalizationSource_C00101 = sText_PkmnPeltedByHail;
const u8 *const gLocalizationSource_C00102 = sText_PkmnsXWoreOff;
const u8 *const gLocalizationSource_C00103 = sText_PkmnSeeded;
const u8 *const gLocalizationSource_C00104 = sText_PkmnEvadedAttack;
const u8 *const gLocalizationSource_C00105 = sText_PkmnSappedByLeechSeed;
const u8 *const gLocalizationSource_C00106 = sText_PkmnFastAsleep;
const u8 *const gLocalizationSource_C00107 = sText_PkmnWokeUp;
const u8 *const gLocalizationSource_C00108 = sText_PkmnUproarKeptAwake;
const u8 *const gLocalizationSource_C00109 = sText_PkmnWokeUpInUproar;
const u8 *const gLocalizationSource_C00110 = sText_PkmnCausedUproar;
const u8 *const gLocalizationSource_C00111 = sText_PkmnMakingUproar;
const u8 *const gLocalizationSource_C00112 = sText_PkmnCalmedDown;
const u8 *const gLocalizationSource_C00113 = sText_PkmnCantSleepInUproar;
const u8 *const gLocalizationSource_C00114 = sText_PkmnStockpiled;
const u8 *const gLocalizationSource_C00115 = sText_PkmnCantStockpile;
const u8 *const gLocalizationSource_C00116 = sText_PkmnCantSleepInUproar2;
const u8 *const gLocalizationSource_C00117 = sText_UproarKeptPkmnAwake;
const u8 *const gLocalizationSource_C00118 = sText_PkmnStayedAwakeUsing;
const u8 *const gLocalizationSource_C00119 = sText_PkmnStoringEnergy;
const u8 *const gLocalizationSource_C00120 = sText_PkmnUnleashedEnergy;
const u8 *const gLocalizationSource_C00121 = sText_PkmnFatigueConfusion;
const u8 *const gLocalizationSource_C00122 = sText_PlayerPickedUpMoney;
const u8 *const gLocalizationSource_C00123 = sText_PkmnUnaffected;
const u8 *const gLocalizationSource_C00124 = sText_PkmnTransformedInto;
const u8 *const gLocalizationSource_C00125 = sText_PkmnMadeSubstitute;
const u8 *const gLocalizationSource_C00126 = sText_PkmnHasSubstitute;
const u8 *const gLocalizationSource_C00127 = sText_SubstituteDamaged;
const u8 *const gLocalizationSource_C00128 = sText_PkmnSubstituteFaded;
const u8 *const gLocalizationSource_C00129 = sText_PkmnMustRecharge;
const u8 *const gLocalizationSource_C00130 = sText_PkmnRageBuilding;
const u8 *const gLocalizationSource_C00131 = sText_PkmnMoveWasDisabled;
const u8 *const gLocalizationSource_C00132 = sText_PkmnMoveDisabledNoMore;
const u8 *const gLocalizationSource_C00133 = sText_PkmnGotEncore;
const u8 *const gLocalizationSource_C00134 = sText_PkmnEncoreEnded;
const u8 *const gLocalizationSource_C00135 = sText_PkmnTookAim;
const u8 *const gLocalizationSource_C00136 = sText_PkmnSketchedMove;
const u8 *const gLocalizationSource_C00137 = sText_PkmnTryingToTakeFoe;
const u8 *const gLocalizationSource_C00138 = sText_PkmnTookFoe;
const u8 *const gLocalizationSource_C00139 = sText_PkmnReducedPP;
const u8 *const gLocalizationSource_C00140 = sText_PkmnStoleItem;
const u8 *const gLocalizationSource_C00141 = sText_TargetCantEscapeNow;
const u8 *const gLocalizationSource_C00142 = sText_PkmnFellIntoNightmare;
const u8 *const gLocalizationSource_C00143 = sText_PkmnLockedInNightmare;
const u8 *const gLocalizationSource_C00144 = sText_PkmnLaidCurse;
const u8 *const gLocalizationSource_C00145 = sText_PkmnAfflictedByCurse;
const u8 *const gLocalizationSource_C00146 = sText_SpikesScattered;
const u8 *const gLocalizationSource_C00147 = sText_PkmnHurtBySpikes;
const u8 *const gLocalizationSource_C00148 = sText_PkmnIdentified;
const u8 *const gLocalizationSource_C00149 = sText_PkmnPerishCountFell;
const u8 *const gLocalizationSource_C00150 = sText_PkmnBracedItself;
const u8 *const gLocalizationSource_C00151 = sText_PkmnEnduredHit;
const u8 *const gLocalizationSource_C00152 = sText_PkmnCutHPMaxedAttack;
const u8 *const gLocalizationSource_C00153 = sText_PkmnCopiedStatChanges;
const u8 *const gLocalizationSource_C00154 = sText_PkmnGotFree;
const u8 *const gLocalizationSource_C00155 = sText_PkmnShedLeechSeed;
const u8 *const gLocalizationSource_C00156 = sText_PkmnBlewAwaySpikes;
const u8 *const gLocalizationSource_C00157 = sText_PkmnFledFromBattle;
const u8 *const gLocalizationSource_C00158 = sText_PkmnForesawAttack;
const u8 *const gLocalizationSource_C00159 = sText_PkmnTookAttack;
const u8 *const gLocalizationSource_C00160 = sText_PkmnChoseXAsDestiny;
const u8 *const gLocalizationSource_C00161 = sText_PkmnAttack;
const u8 *const gLocalizationSource_C00162 = sText_PkmnCenterAttention;
const u8 *const gLocalizationSource_C00163 = sText_PkmnChargingPower;
const u8 *const gLocalizationSource_C00164 = sText_NaturePowerTurnedInto;
const u8 *const gLocalizationSource_C00165 = sText_PkmnStatusNormal;
const u8 *const gLocalizationSource_C00166 = sText_PkmnSubjectedToTorment;
const u8 *const gLocalizationSource_C00167 = sText_PkmnTighteningFocus;
const u8 *const gLocalizationSource_C00168 = sText_PkmnFellForTaunt;
const u8 *const gLocalizationSource_C00169 = sText_PkmnReadyToHelp;
const u8 *const gLocalizationSource_C00170 = sText_PkmnSwitchedItems;
const u8 *const gLocalizationSource_C00171 = sText_PkmnObtainedX;
const u8 *const gLocalizationSource_C00172 = sText_PkmnObtainedX2;
const u8 *const gLocalizationSource_C00173 = sText_PkmnObtainedXYObtainedZ;
const u8 *const gLocalizationSource_C00174 = sText_PkmnCopiedFoe;
const u8 *const gLocalizationSource_C00175 = sText_PkmnMadeWish;
const u8 *const gLocalizationSource_C00176 = sText_PkmnWishCameTrue;
const u8 *const gLocalizationSource_C00177 = sText_PkmnPlantedRoots;
const u8 *const gLocalizationSource_C00178 = sText_PkmnAbsorbedNutrients;
const u8 *const gLocalizationSource_C00179 = sText_PkmnAnchoredItself;
const u8 *const gLocalizationSource_C00180 = sText_PkmnWasMadeDrowsy;
const u8 *const gLocalizationSource_C00181 = sText_PkmnKnockedOff;
const u8 *const gLocalizationSource_C00182 = sText_PkmnSwappedAbilities;
const u8 *const gLocalizationSource_C00183 = sText_PkmnSealedOpponentMove;
const u8 *const gLocalizationSource_C00184 = sText_PkmnWantsGrudge;
const u8 *const gLocalizationSource_C00185 = sText_PkmnLostPPGrudge;
const u8 *const gLocalizationSource_C00186 = sText_PkmnShroudedItself;
const u8 *const gLocalizationSource_C00187 = sText_PkmnMoveBounced;
const u8 *const gLocalizationSource_C00188 = sText_PkmnWaitsForTarget;
const u8 *const gLocalizationSource_C00189 = sText_PkmnSnatchedMove;
const u8 *const gLocalizationSource_C00190 = sText_ElectricityWeakened;
const u8 *const gLocalizationSource_C00191 = sText_FireWeakened;
const u8 *const gLocalizationSource_C00192 = sText_XFoundOneY;
const u8 *const gLocalizationSource_C00193 = sText_SoothingAroma;
const u8 *const gLocalizationSource_C00194 = sText_ItemsCantBeUsedNow;
const u8 *const gLocalizationSource_C00195 = sText_ForXCommaYZ;
const u8 *const gLocalizationSource_C00196 = sText_PkmnUsedXToGetPumped;
const u8 *const gLocalizationSource_C00197 = sText_PkmnLostFocus;
const u8 *const gLocalizationSource_C00198 = sText_PkmnWasDraggedOut;
const u8 *const gLocalizationSource_C00199 = sText_TheWallShattered;
const u8 *const gLocalizationSource_C00200 = sText_ButNoEffect;
const u8 *const gLocalizationSource_C00201 = sText_PkmnHasNoMovesLeft;
const u8 *const gLocalizationSource_C00202 = sText_PkmnMoveIsDisabled;
const u8 *const gLocalizationSource_C00203 = sText_PkmnCantUseMoveTorment;
const u8 *const gLocalizationSource_C00204 = sText_PkmnCantUseMoveTaunt;
const u8 *const gLocalizationSource_C00205 = sText_PkmnCantUseMoveSealed;
const u8 *const gLocalizationSource_C00206 = sText_PkmnMadeItRain;
const u8 *const gLocalizationSource_C00207 = sText_PkmnRaisedSpeed;
const u8 *const gLocalizationSource_C00208 = sText_PkmnProtectedBy;
const u8 *const gLocalizationSource_C00209 = sText_PkmnPreventsUsage;
const u8 *const gLocalizationSource_C00210 = sText_PkmnRestoredHPUsing;
const u8 *const gLocalizationSource_C00211 = sText_PkmnsXMadeYUseless;
const u8 *const gLocalizationSource_C00212 = sText_PkmnChangedTypeWith;
const u8 *const gLocalizationSource_C00213 = sText_PkmnPreventsParalysisWith;
const u8 *const gLocalizationSource_C00214 = sText_PkmnPreventsRomanceWith;
const u8 *const gLocalizationSource_C00215 = sText_PkmnPreventsPoisoningWith;
const u8 *const gLocalizationSource_C00216 = sText_PkmnPreventsConfusionWith;
const u8 *const gLocalizationSource_C00217 = sText_PkmnRaisedFirePowerWith;
const u8 *const gLocalizationSource_C00218 = sText_PkmnAnchorsItselfWith;
const u8 *const gLocalizationSource_C00219 = sText_PkmnCutsAttackWith;
const u8 *const gLocalizationSource_C00220 = sText_PkmnPreventsStatLossWith;
const u8 *const gLocalizationSource_C00221 = sText_PkmnHurtsWith;
const u8 *const gLocalizationSource_C00222 = sText_PkmnTraced;
const u8 *const gLocalizationSource_C00223 = sText_PkmnsXPreventsBurns;
const u8 *const gLocalizationSource_C00224 = sText_PkmnsXBlocksY;
const u8 *const gLocalizationSource_C00225 = sText_PkmnsXBlocksY2;
const u8 *const gLocalizationSource_C00226 = sText_PkmnsXRestoredHPALittle2;
const u8 *const gLocalizationSource_C00227 = sText_PkmnsXWhippedUpSandstorm;
const u8 *const gLocalizationSource_C00228 = sText_PkmnsXIntensifiedSun;
const u8 *const gLocalizationSource_C00229 = sText_PkmnsXPreventsYLoss;
const u8 *const gLocalizationSource_C00230 = sText_PkmnsXInfatuatedY;
const u8 *const gLocalizationSource_C00231 = sText_PkmnsXMadeYIneffective;
const u8 *const gLocalizationSource_C00232 = sText_PkmnsXCuredYProblem;
const u8 *const gLocalizationSource_C00233 = sText_ItSuckedLiquidOoze;
const u8 *const gLocalizationSource_C00234 = sText_PkmnTransformed;
const u8 *const gLocalizationSource_C00235 = sText_PkmnsXTookAttack;
const u8 *const gLocalizationSource_C00236 = gText_PkmnsXPreventsSwitching;
const u8 *const gLocalizationSource_C00237 = sText_PreventedFromWorking;
const u8 *const gLocalizationSource_C00238 = sText_PkmnsXMadeItIneffective;
const u8 *const gLocalizationSource_C00239 = sText_PkmnsXPreventsFlinching;
const u8 *const gLocalizationSource_C00240 = sText_PkmnsXPreventsYsZ;
const u8 *const gLocalizationSource_C00241 = sText_PkmnsXCuredItsYProblem;
const u8 *const gLocalizationSource_C00242 = sText_PkmnsXHadNoEffectOnY;
const u8 *const gLocalizationSource_C00243 = sText_StatSharply;
const u8 *const gLocalizationSource_C00244 = gText_StatRose;
const u8 *const gLocalizationSource_C00245 = sText_StatHarshly;
const u8 *const gLocalizationSource_C00246 = sText_StatFell;
const u8 *const gLocalizationSource_C00247 = sText_AttackersStatRose;
const u8 *const gLocalizationSource_C00248 = gText_DefendersStatRose;
const u8 *const gLocalizationSource_C00249 = sText_UsingItemTheStatOfPkmnRose;
const u8 *const gLocalizationSource_C00250 = sText_AttackersStatFell;
const u8 *const gLocalizationSource_C00251 = sText_DefendersStatFell;
const u8 *const gLocalizationSource_C00252 = sText_StatsWontIncrease2;
const u8 *const gLocalizationSource_C00253 = sText_StatsWontDecrease2;
const u8 *const gLocalizationSource_C00254 = sText_CriticalHit;
const u8 *const gLocalizationSource_C00255 = sText_OneHitKO;
const u8 *const gLocalizationSource_C00256 = sText_123Poof;
const u8 *const gLocalizationSource_C00257 = sText_AndEllipsis;
const u8 *const gLocalizationSource_C00258 = sText_HMMovesCantBeForgotten;
const u8 *const gLocalizationSource_C00259 = sText_NotVeryEffective;
const u8 *const gLocalizationSource_C00260 = sText_SuperEffective;
const u8 *const gLocalizationSource_C00261 = sText_GotAwaySafely;
const u8 *const gLocalizationSource_C00262 = sText_PkmnFledUsingIts;
const u8 *const gLocalizationSource_C00263 = sText_PkmnFledUsing;
const u8 *const gLocalizationSource_C00264 = sText_WildPkmnFled;
const u8 *const gLocalizationSource_C00265 = sText_PlayerDefeatedLinkTrainer;
const u8 *const gLocalizationSource_C00266 = sText_TwoLinkTrainersDefeated;
const u8 *const gLocalizationSource_C00267 = sText_PlayerLostAgainstLinkTrainer;
const u8 *const gLocalizationSource_C00268 = sText_PlayerLostToTwo;
const u8 *const gLocalizationSource_C00269 = sText_PlayerBattledToDrawLinkTrainer;
const u8 *const gLocalizationSource_C00270 = sText_PlayerBattledToDrawVsTwo;
const u8 *const gLocalizationSource_C00271 = sText_WildFled;
const u8 *const gLocalizationSource_C00272 = sText_TwoWildFled;
const u8 *const gLocalizationSource_C00273 = sText_NoRunningFromTrainers;
const u8 *const gLocalizationSource_C00274 = sText_CantEscape;
const u8 *const gLocalizationSource_C00275 = sText_DontLeaveBirch;
const u8 *const gLocalizationSource_C00276 = sText_ButNothingHappened;
const u8 *const gLocalizationSource_C00277 = sText_ButItFailed;
const u8 *const gLocalizationSource_C00278 = sText_ItHurtConfusion;
const u8 *const gLocalizationSource_C00279 = sText_MirrorMoveFailed;
const u8 *const gLocalizationSource_C00280 = sText_StartedToRain;
const u8 *const gLocalizationSource_C00281 = sText_DownpourStarted;
const u8 *const gLocalizationSource_C00282 = sText_RainContinues;
const u8 *const gLocalizationSource_C00283 = sText_DownpourContinues;
const u8 *const gLocalizationSource_C00284 = sText_RainStopped;
const u8 *const gLocalizationSource_C00285 = sText_SandstormBrewed;
const u8 *const gLocalizationSource_C00286 = sText_SandstormRages;
const u8 *const gLocalizationSource_C00287 = sText_SandstormSubsided;
const u8 *const gLocalizationSource_C00288 = sText_SunlightGotBright;
const u8 *const gLocalizationSource_C00289 = sText_SunlightStrong;
const u8 *const gLocalizationSource_C00290 = sText_SunlightFaded;
const u8 *const gLocalizationSource_C00291 = sText_StartedHail;
const u8 *const gLocalizationSource_C00292 = sText_HailContinues;
const u8 *const gLocalizationSource_C00293 = sText_HailStopped;
const u8 *const gLocalizationSource_C00294 = sText_FailedToSpitUp;
const u8 *const gLocalizationSource_C00295 = sText_FailedToSwallow;
const u8 *const gLocalizationSource_C00296 = sText_WindBecameHeatWave;
const u8 *const gLocalizationSource_C00297 = sText_StatChangesGone;
const u8 *const gLocalizationSource_C00298 = sText_CoinsScattered;
const u8 *const gLocalizationSource_C00299 = sText_TooWeakForSubstitute;
const u8 *const gLocalizationSource_C00300 = sText_SharedPain;
const u8 *const gLocalizationSource_C00301 = sText_BellChimed;
const u8 *const gLocalizationSource_C00302 = sText_FaintInThree;
const u8 *const gLocalizationSource_C00303 = sText_NoPPLeft;
const u8 *const gLocalizationSource_C00304 = sText_ButNoPPLeft;
const u8 *const gLocalizationSource_C00305 = sText_PkmnIgnoresAsleep;
const u8 *const gLocalizationSource_C00306 = sText_PkmnIgnoredOrders;
const u8 *const gLocalizationSource_C00307 = sText_PkmnBeganToNap;
const u8 *const gLocalizationSource_C00308 = sText_PkmnLoafing;
const u8 *const gLocalizationSource_C00309 = sText_PkmnWontObey;
const u8 *const gLocalizationSource_C00310 = sText_PkmnTurnedAway;
const u8 *const gLocalizationSource_C00311 = sText_PkmnPretendNotNotice;
const u8 *const gLocalizationSource_C00312 = sText_EnemyAboutToSwitchPkmn;
const u8 *const gLocalizationSource_C00313 = sText_PkmnLearnedMove2;
const u8 *const gLocalizationSource_C00314 = sText_PlayerDefeatedLinkTrainerTrainer1;
const u8 *const gLocalizationSource_C00315 = sText_CreptCloser;
const u8 *const gLocalizationSource_C00316 = sText_CantGetCloser;
const u8 *const gLocalizationSource_C00317 = sText_PkmnWatchingCarefully;
const u8 *const gLocalizationSource_C00318 = sText_PkmnCuriousAboutX;
const u8 *const gLocalizationSource_C00319 = sText_PkmnEnthralledByX;
const u8 *const gLocalizationSource_C00320 = sText_PkmnIgnoredX;
const u8 *const gLocalizationSource_C00321 = sText_ThrewPokeblockAtPkmn;
const u8 *const gLocalizationSource_C00322 = sText_OutOfSafariBalls;
const u8 *const gLocalizationSource_C00323 = sText_OpponentMon1Appeared;
const u8 *const gLocalizationSource_C00324 = sText_WildPkmnAppeared;
const u8 *const gLocalizationSource_C00325 = sText_LegendaryPkmnAppeared;
const u8 *const gLocalizationSource_C00326 = sText_WildPkmnAppearedPause;
const u8 *const gLocalizationSource_C00327 = sText_TwoWildPkmnAppeared;
const u8 *const gLocalizationSource_C00328 = sText_Trainer1WantsToBattle;
const u8 *const gLocalizationSource_C00329 = sText_LinkTrainerWantsToBattle;
const u8 *const gLocalizationSource_C00330 = sText_TwoLinkTrainersWantToBattle;
const u8 *const gLocalizationSource_C00331 = sText_Trainer1SentOutPkmn;
const u8 *const gLocalizationSource_C00332 = sText_Trainer1SentOutTwoPkmn;
const u8 *const gLocalizationSource_C00333 = sText_Trainer1SentOutPkmn2;
const u8 *const gLocalizationSource_C00334 = sText_LinkTrainerSentOutPkmn;
const u8 *const gLocalizationSource_C00335 = sText_LinkTrainerSentOutTwoPkmn;
const u8 *const gLocalizationSource_C00336 = sText_TwoLinkTrainersSentOutPkmn;
const u8 *const gLocalizationSource_C00337 = sText_LinkTrainerSentOutPkmn2;
const u8 *const gLocalizationSource_C00338 = sText_LinkTrainerMultiSentOutPkmn;
const u8 *const gLocalizationSource_C00339 = sText_GoPkmn;
const u8 *const gLocalizationSource_C00340 = sText_GoTwoPkmn;
const u8 *const gLocalizationSource_C00341 = sText_GoPkmn2;
const u8 *const gLocalizationSource_C00342 = sText_DoItPkmn;
const u8 *const gLocalizationSource_C00343 = sText_GoForItPkmn;
const u8 *const gLocalizationSource_C00344 = sText_YourFoesWeakGetEmPkmn;
const u8 *const gLocalizationSource_C00345 = sText_LinkPartnerSentOutPkmnGoPkmn;
const u8 *const gLocalizationSource_C00346 = sText_PkmnThatsEnough;
const u8 *const gLocalizationSource_C00347 = sText_PkmnComeBack;
const u8 *const gLocalizationSource_C00348 = sText_PkmnOkComeBack;
const u8 *const gLocalizationSource_C00349 = sText_PkmnGoodComeBack;
const u8 *const gLocalizationSource_C00350 = sText_Trainer1WithdrewPkmn;
const u8 *const gLocalizationSource_C00351 = sText_LinkTrainer1WithdrewPkmn;
const u8 *const gLocalizationSource_C00352 = sText_LinkTrainer2WithdrewPkmn;
const u8 *const gLocalizationSource_C00353 = sText_WildPkmnPrefix;
const u8 *const gLocalizationSource_C00354 = sText_FoePkmnPrefix;
const u8 *const gLocalizationSource_C00355 = sText_FoePkmnPrefix2;
const u8 *const gLocalizationSource_C00356 = sText_AllyPkmnPrefix;
const u8 *const gLocalizationSource_C00357 = sText_FoePkmnPrefix3;
const u8 *const gLocalizationSource_C00358 = sText_AllyPkmnPrefix2;
const u8 *const gLocalizationSource_C00359 = sText_FoePkmnPrefix4;
const u8 *const gLocalizationSource_C00360 = sText_AllyPkmnPrefix3;
const u8 *const gLocalizationSource_C00361 = sText_AttackerUsedX;
const u8 *const gLocalizationSource_C00362 = sText_PokeblockWasTooSpicy;
const u8 *const gLocalizationSource_C00363 = sText_PokeblockWasTooDry;
const u8 *const gLocalizationSource_C00364 = sText_PokeblockWasTooSweet;
const u8 *const gLocalizationSource_C00365 = sText_PokeblockWasTooBitter;
const u8 *const gLocalizationSource_C00366 = sText_PokeblockWasTooSour;
const u8 *const gLocalizationSource_C00367 = sText_PlayerUsedItem;
const u8 *const gLocalizationSource_C00368 = sText_WallyUsedItem;
const u8 *const gLocalizationSource_C00369 = sText_Trainer1UsedItem;
const u8 *const gLocalizationSource_C00370 = sText_TrainerBlockedBall;
const u8 *const gLocalizationSource_C00371 = sText_DontBeAThief;
const u8 *const gLocalizationSource_C00372 = sText_ItDodgedBall;
const u8 *const gLocalizationSource_C00373 = sText_YouMissedPkmn;
const u8 *const gLocalizationSource_C00374 = sText_PkmnBrokeFree;
const u8 *const gLocalizationSource_C00375 = sText_ItAppearedCaught;
const u8 *const gLocalizationSource_C00376 = sText_AarghAlmostHadIt;
const u8 *const gLocalizationSource_C00377 = sText_ShootSoClose;
const u8 *const gLocalizationSource_C00378 = sText_GotchaPkmnCaughtPlayer;
const u8 *const gLocalizationSource_C00379 = sText_GotchaPkmnCaughtWally;
const u8 *const gLocalizationSource_C00380 = sText_GiveNicknameCaptured;
const u8 *const gLocalizationSource_C00381 = sText_PkmnSentToPC;
const u8 *const gLocalizationSource_C00382 = sText_Someones;
const u8 *const gLocalizationSource_C00383 = sText_Lanettes;
const u8 *const gLocalizationSource_C00384 = sText_PkmnDataAddedToDex;
const u8 *const gLocalizationSource_C00385 = sText_ItIsRaining;
const u8 *const gLocalizationSource_C00386 = sText_SandstormIsRaging;
const u8 *const gLocalizationSource_C00387 = sText_BoxIsFull;
const u8 *const gLocalizationSource_C00388 = sText_PkmnsItemCuredParalysis;
const u8 *const gLocalizationSource_C00389 = sText_PkmnsItemCuredPoison;
const u8 *const gLocalizationSource_C00390 = sText_PkmnsItemHealedBurn;
const u8 *const gLocalizationSource_C00391 = sText_PkmnsItemDefrostedIt;
const u8 *const gLocalizationSource_C00392 = sText_PkmnsItemWokeIt;
const u8 *const gLocalizationSource_C00393 = sText_PkmnsItemSnappedOut;
const u8 *const gLocalizationSource_C00394 = sText_PkmnsItemCuredProblem;
const u8 *const gLocalizationSource_C00395 = sText_PkmnsItemNormalizedStatus;
const u8 *const gLocalizationSource_C00396 = sText_PkmnsItemRestoredHealth;
const u8 *const gLocalizationSource_C00397 = sText_PkmnsItemRestoredPP;
const u8 *const gLocalizationSource_C00398 = sText_PkmnsItemRestoredStatus;
const u8 *const gLocalizationSource_C00399 = sText_PkmnsItemRestoredHPALittle;
const u8 *const gLocalizationSource_C00400 = sText_ItemAllowsOnlyYMove;
const u8 *const gLocalizationSource_C00401 = sText_PkmnHungOnWithX;
const u8 *const gLocalizationSource_C00402 = sText_YouThrowABallNowRight;
const u8 *const gLocalizationSource_C00403 = sText_PlayerLostToEnemyTrainer;
const u8 *const gLocalizationSource_C00404 = sText_PlayerPaidPrizeMoney;
const u8 *const gLocalizationSource_C00405 = sText_PlayerWhiteoutNoMoney;
const u8 *const gLocalizationSource_C00406 = sText_PkmnsAbilityActivated;
const u8 *const gLocalizationSource_C00407 = sText_PkmnsAbilityRestoredHP;
const u8 *const gLocalizationSource_C00408 = sText_PkmnHurtByAbility;
const u8 *const gLocalizationSource_C00409 = sText_PkmnShuddered;
const u8 *const gLocalizationSource_C00410 = sText_PkmnFriskedItem;
const u8 *const gLocalizationSource_C00411 = sText_PkmnFriskedTwoItems;
const u8 *const gLocalizationSource_C00412 = sText_PkmnRecoveredItem;
const u8 *const gLocalizationSource_C00413 = sText_PkmnMoveBouncedBack;
const u8 *const gLocalizationSource_C00414 = gText_PkmnIsEvolving;
const u8 *const gLocalizationSource_C00415 = gText_CongratsPkmnEvolved;
const u8 *const gLocalizationSource_C00416 = gText_PkmnStoppedEvolving;
const u8 *const gLocalizationSource_C00417 = gText_WhatWillPkmnDo;
const u8 *const gLocalizationSource_C00418 = gText_WhatWillPkmnDo2;
const u8 *const gLocalizationSource_C00419 = gText_WhatWillWallyDo;
const u8 *const gLocalizationSource_C00420 = gText_LinkStandby;
const u8 *const gLocalizationSource_C00421 = gText_WhichMoveToForget4;
const u8 *const gLocalizationSource_C00422 = gText_BattleSwitchWhich;
const u8 *const gLocalizationSource_C00423 = gText_SafariBallLeft;
const u8 *const gLocalizationSource_C00424 = gText_Sleep;
const u8 *const gLocalizationSource_C00425 = gText_Poison;
const u8 *const gLocalizationSource_C00426 = gText_Burn;
const u8 *const gLocalizationSource_C00427 = gText_Paralysis;
const u8 *const gLocalizationSource_C00428 = gText_Ice;
const u8 *const gLocalizationSource_C00429 = gText_Confusion;
const u8 *const gLocalizationSource_C00430 = gText_Love;
const u8 *const gLocalizationSource_C00431 = gText_SpaceAndSpace;
const u8 *const gLocalizationSource_C00432 = gText_Are;
const u8 *const gLocalizationSource_C00433 = gText_Are2;
const u8 *const gLocalizationSource_C00434 = sText_SpaceIs;
const u8 *const gLocalizationSource_C00435 = sATypeMove_Table[TYPE_NORMAL];
const u8 *const gLocalizationSource_C00436 = sATypeMove_Table[TYPE_FIGHTING];
const u8 *const gLocalizationSource_C00437 = sATypeMove_Table[TYPE_FLYING];
const u8 *const gLocalizationSource_C00438 = sATypeMove_Table[TYPE_POISON];
const u8 *const gLocalizationSource_C00439 = sATypeMove_Table[TYPE_GROUND];
const u8 *const gLocalizationSource_C00440 = sATypeMove_Table[TYPE_ROCK];
const u8 *const gLocalizationSource_C00441 = sATypeMove_Table[TYPE_BUG];
const u8 *const gLocalizationSource_C00442 = sATypeMove_Table[TYPE_GHOST];
const u8 *const gLocalizationSource_C00443 = sATypeMove_Table[TYPE_STEEL];
const u8 *const gLocalizationSource_C00444 = sATypeMove_Table[TYPE_MYSTERY];
const u8 *const gLocalizationSource_C00445 = sATypeMove_Table[TYPE_FIRE];
const u8 *const gLocalizationSource_C00446 = sATypeMove_Table[TYPE_WATER];
const u8 *const gLocalizationSource_C00447 = sATypeMove_Table[TYPE_GRASS];
const u8 *const gLocalizationSource_C00448 = sATypeMove_Table[TYPE_ELECTRIC];
const u8 *const gLocalizationSource_C00449 = sATypeMove_Table[TYPE_PSYCHIC];
const u8 *const gLocalizationSource_C00450 = sATypeMove_Table[TYPE_ICE];
const u8 *const gLocalizationSource_C00451 = sATypeMove_Table[TYPE_DRAGON];
const u8 *const gLocalizationSource_C00452 = sATypeMove_Table[TYPE_DARK];
const u8 *const gLocalizationSource_C00453 = sText_Round1;
const u8 *const gLocalizationSource_C00454 = sText_Round2;
const u8 *const gLocalizationSource_C00455 = sText_Semifinal;
const u8 *const gLocalizationSource_C00456 = sText_Final;
const u8 *const gLocalizationSource_C00457 = gText_TheGreatNewHope;
const u8 *const gLocalizationSource_C00458 = gText_WillChampionshipDreamComeTrue;
const u8 *const gLocalizationSource_C00459 = gText_AFormerChampion;
const u8 *const gLocalizationSource_C00460 = gText_ThePreviousChampion;
const u8 *const gLocalizationSource_C00461 = gText_TheUnbeatenChampion;
const u8 *const gLocalizationSource_C00462 = sText_TwoTrainersSentPkmn;
const u8 *const gLocalizationSource_C00463 = sText_Trainer2SentOutPkmn;
const u8 *const gLocalizationSource_C00464 = sText_TwoTrainersWantToBattle;
const u8 *const gLocalizationSource_C00465 = sText_InGamePartnerSentOutZGoN;
const u8 *const gLocalizationSource_C00466 = sText_TwoInGameTrainersDefeated;
const u8 *const gLocalizationSource_C00467 = sText_PkmnIncapableOfPower;
const u8 *const gLocalizationSource_C00468 = sText_GlintAppearsInEye;
const u8 *const gLocalizationSource_C00469 = sText_PkmnGettingIntoPosition;
const u8 *const gLocalizationSource_C00470 = sText_PkmnBeganGrowlingDeeply;
const u8 *const gLocalizationSource_C00471 = sText_PkmnEagerForMore;
const u8 *const gLocalizationSource_C00472 = sText_RefIfNothingIsDecided;
const u8 *const gLocalizationSource_C00473 = sText_RefThatsIt;
const u8 *const gLocalizationSource_C00474 = sText_RefJudgeMind;
const u8 *const gLocalizationSource_C00475 = sText_RefJudgeSkill;
const u8 *const gLocalizationSource_C00476 = sText_RefJudgeBody;
const u8 *const gLocalizationSource_C00477 = sText_RefPlayerWon;
const u8 *const gLocalizationSource_C00478 = sText_RefOpponentWon;
const u8 *const gLocalizationSource_C00479 = sText_RefDraw;
const u8 *const gLocalizationSource_C00480 = sText_DefeatedOpponentByReferee;
const u8 *const gLocalizationSource_C00481 = sText_LostToOpponentByReferee;
const u8 *const gLocalizationSource_C00482 = sText_TiedOpponentByReferee;
const u8 *const gLocalizationSource_C00483 = sText_RefCommenceBattle;
const u8 *const gLocalizationSource_C00484 = sText_QuestionForfeitMatch;
const u8 *const gLocalizationSource_C00485 = sText_ForfeitedMatch;
const u8 *const gLocalizationSource_C00486 = sText_Trainer1Fled;
const u8 *const gLocalizationSource_C00487 = sText_PlayerLostAgainstTrainer1;
const u8 *const gLocalizationSource_C00488 = sText_PlayerBattledToDrawTrainer1;
const u8 *const gLocalizationSource_C00489 = gText_RecordBattleToPass;
const u8 *const gLocalizationSource_C00490 = gText_BattleRecordedOnPass;
const u8 *const gLocalizationSource_C00491 = sText_LinkTrainerWantsToBattlePause;
const u8 *const gLocalizationSource_C00492 = sText_TwoLinkTrainersWantToBattlePause;
// END GENERATED LOCALIZATION EXPORTS
