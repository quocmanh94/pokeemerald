#include "global.h"
#include "data.h"
#include "event_scripts.h"
#include "follower_helper.h"
#include "constants/battle.h"
#include "constants/metatile_behaviors.h"
#include "constants/pokemon.h"
#include "constants/region_map_sections.h"
#include "constants/songs.h"
#include "constants/weather.h"

#define TYPE_NOT_TYPE1 NUMBER_OF_MON_TYPES

// difficult conditional messages follow
static const u8 sCondMsg00[] = _("{STR_VAR_1} vui vẻ nhảy múa.");
static const u8 sCondMsg01[] = _("{STR_VAR_1} nhảy múa thật đẹp.");
static const u8* const sCelebiTexts[] = {sCondMsg00, sCondMsg01, NULL};
static const u8 sCondMsg02[] = _("{STR_VAR_1} phun lửa và hét lên.");
static const u8 sCondMsg03[] = _("{STR_VAR_1} đang phun lửa dữ dội!");
static const u8 sCondMsg04[] = _("{STR_VAR_1} phun lửa!");
static const u8 sCondMsg05[] = _("{STR_VAR_1} đang thở lửa dữ dội!");
static const u8* const sFireTexts[] = {sCondMsg02, sCondMsg03, sCondMsg04, sCondMsg05, NULL};
static const u8 sCondMsg06[] = _("{STR_VAR_1} nhìn thẳng về phía\nPOKéMON LEAGUE.");
static const u8 sCondMsg07[] = _("POKéMON của bạn chăm chú nhìn\nđỉnh núi.");
static const u8 sCondMsg08[] = _("Khịt khịt, có gì đó thơm quá!");
static const u8 sCondMsg09[] = _("POKéMON của bạn bồn chồn\nquan sát các kệ hàng.");
static const u8 sCondMsg10[] = _("{STR_VAR_1} chăm chú nhìn\ncác kệ hàng.");
static const u8* const sShopTexts[] = {sCondMsg09, sCondMsg10, NULL};
static const u8 sCondMsg11[] = _("{STR_VAR_1} tập trung với\nánh mắt sắc bén!");
static const u8 sCondMsg12[] = _("{STR_VAR_1} có vẻ rất hứng thú\nvới những chiếc BIKE.");
static const u8 sCondMsg13[] = _("{STR_VAR_1} có vẻ muốn chạm\nvào các cỗ máy!");
static const u8 sCondMsg14[] = _("{STR_VAR_1} lắc lư theo con thuyền!");
static const u8 sCondMsg15[] = _("{STR_VAR_1} nhảy theo nhịp\nchòng chành của con tàu.");
static const u8 sCondMsg16[] = _("{STR_VAR_1} vẫn chưa muốn\nrời khỏi thuyền!");
static const u8* const sBoatTexts[] = {sCondMsg14, sCondMsg15, sCondMsg16, NULL};
static const u8 sCondMsg17[] = _("{STR_VAR_1} đang lắng nghe\ntiếng máy móc.");
static const u8* const sMachineTexts[] = {sCondMsg13, sCondMsg17, NULL};
static const u8 sCondMsg18[] = _("Á! POKéMON của bạn bỗng\nlàm nước bắn tung tóe!");
static const u8 sCondMsg19[] = _("POKéMON của bạn đang thổi\ncát bay lên không trung!");
static const u8 sCondMsg20[] = _("{STR_VAR_1} đang nghịch ngợm,\nbứt vài ngọn cỏ.");
static const u8 sCondMsg21[] = _("POKéMON của bạn vui vẻ nhìn\ndấu chân của bạn!");
static const u8 sCondMsg22[] = _("{STR_VAR_1} lo lắng và hơi\nsợ không gian kín.");
static const u8 sCondMsg23[] = _("{STR_VAR_1} dè chừng\nkhông gian chật hẹp!");
static const u8* const sElevatorTexts[] = {sCondMsg22, sCondMsg23, NULL};
static const u8 sCondMsg24[] = _("Một cơn gió lạnh bỗng thổi qua!");
static const u8 sCondMsg25[] = _("POKéMON của bạn trượt chân\nvà suýt ngã!");
static const u8 sCondMsg26[] = _("POKéMON của bạn ngạc nhiên\nkhi chạm vào băng.");
static const u8* const sColdTexts[] = {sCondMsg24, sCondMsg25, sCondMsg26, NULL};
static const u8 sCondMsg27[] = _("Có một cánh hoa trên mặt\nPOKéMON của bạn!");
static const u8 sCondMsg28[] = _("{STR_VAR_1} đang gầm gừ khe khẽ.");
static const u8 sCondMsg29[] = _("{STR_VAR_1} đang run lên vì sợ.");
static const u8 sCondMsg30[] = _("{STR_VAR_1} có vẻ buồn…");
static const u8* const sFearTexts[] = {sCondMsg29, sCondMsg30, NULL};
static const u8 sCondMsg31[] = _("{STR_VAR_1} đang trú mưa\ntrong bụi cỏ.");
static const u8 sCondMsg32[] = _("{STR_VAR_1} có vẻ rất lạnh.");
static const u8 sCondMsg33[] = _("{STR_VAR_1} đang nhìn ra biển.");
static const u8 sCondMsg34[] = _("POKéMON của bạn chăm chú\nnhìn ra biển!");
static const u8 sCondMsg35[] = _("{STR_VAR_1} đang nhìn biển cuộn sóng.");
static const u8* const sSeaTexts[] = {sCondMsg33, sCondMsg34, sCondMsg35, NULL};
static const u8 sCondMsg36[] = _("{STR_VAR_1} đang lắng nghe\ntiếng thác nước.");
static const u8 sCondMsg37[] = _("{STR_VAR_1} có vẻ vui vì trời mưa!");
static const u8 sCondMsg38[] = _("{STR_VAR_1} đang nhìn bóng mình\ntrên mặt nước.");
static const u8 sCondMsg39[] = _("{STR_VAR_1} có vẻ thư giãn khi nghe\ntiếng lá xào xạc…");
static const u8 sCondMsg40[] = _("{STR_VAR_1} đang gặm băng.");
static const u8 sCondMsg41[] = _("{STR_VAR_1} đang chạm vào băng.");
static const u8* const sIceTexts[] = {sCondMsg26, sCondMsg40, sCondMsg41, NULL};
static const u8 sCondMsg42[] = _("Vết bỏng của {STR_VAR_1} đau quá!");
static const u8 sCondMsg50[] = _("{STR_VAR_1} bất an vì\nthời tiết bất thường!");

// See the struct definition in follower_helper.h for more info
const struct FollowerMsgInfoExtended gFollowerConditionalMessages[COND_MSG_COUNT] = {
    [COND_MSG_CELEBI] =
    {
    .text = (u8*)sCelebiTexts,
    .textSpread = 1,
    .script = EventScript_FollowerDance,
    .emotion = FOLLOWER_EMOTION_NEUTRAL,
    .conditions = {MATCH_SPECIES(SPECIES_CELEBI)},
    },
    [COND_MSG_FIRE] =
    {
    .text = (u8*)sFireTexts,
    .textSpread = 1,
    .emotion = FOLLOWER_EMOTION_NEUTRAL,
    .conditions = {MATCH_TYPES(TYPE_FIRE, TYPE_FIRE)},
    },
    [COND_MSG_EVER_GRANDE] =
    {
    .text = sCondMsg06,
    .script = EventScript_FollowerFaceUp,
    .emotion = FOLLOWER_EMOTION_HAPPY,
    .conditions = {MATCH_MAP(EVER_GRANDE_CITY)},
    },
    [COND_MSG_ROUTE_112] =
    {
    .text = sCondMsg07,
    .emotion = FOLLOWER_EMOTION_HAPPY,
    .conditions = {MATCH_MAP(ROUTE112)},
    },
    [COND_MSG_DAY_CARE] =
    {
    .text = sCondMsg08,
    .script = EventScript_FollowerNostalgia,
    .emotion = FOLLOWER_EMOTION_NEUTRAL,
    .conditions = {MATCH_MAP(ROUTE117_POKEMON_DAY_CARE)},
    },
    [COND_MSG_MART] =
    {
    .text = (u8*)sShopTexts,
    .textSpread = 1,
    .script = EventScript_FollowerLookAround,
    .emotion = FOLLOWER_EMOTION_NEUTRAL,
    .conditions = {MATCH_MUSIC(MUS_POKE_MART)},
    },
    [COND_MSG_VICTORY_ROAD] =
    {
    .text = sCondMsg11,
    .emotion = FOLLOWER_EMOTION_PENSIVE,
    .conditions = {MATCH_MUSIC(MUS_VICTORY_ROAD)},
    },
    [COND_MSG_BIKE_SHOP] =
    {
    .text = sCondMsg12,
    .emotion = FOLLOWER_EMOTION_PENSIVE,
    .conditions = {MATCH_MAP(MAUVILLE_CITY_BIKE_SHOP)},
    },
    [COND_MSG_MACHINES] =
    {
    .text = (u8*)sMachineTexts,
    .textSpread = 1,
    .emotion = FOLLOWER_EMOTION_MUSIC,
    .orFlag = 1, // match any of these maps
    .conditions = {
        MATCH_MAP(NEW_MAUVILLE_INSIDE),
        MATCH_MAP(SLATEPORT_CITY_STERNS_SHIPYARD_1F),
        MATCH_MAP(SLATEPORT_CITY_STERNS_SHIPYARD_2F),
    }
    },
    [COND_MSG_SAILING] =
    {
    .text = (u8*)sBoatTexts,
    .textSpread = 1,
    .emotion = FOLLOWER_EMOTION_MUSIC,
    .script = EventScript_FollowerLookAround,
    .conditions = {MATCH_MUSIC(MUS_SAILING)},
    },
    [COND_MSG_PUDDLE] =
    {
    .text = sCondMsg18,
    .script = EventScript_FollowerHopping,
    .emotion = FOLLOWER_EMOTION_MUSIC,
    .conditions = {MATCH_ON_MB(MB_SHALLOW_WATER, MB_PUDDLE)},
    },
    [COND_MSG_SAND] =
    {
    .text = sCondMsg19,
    .emotion = FOLLOWER_EMOTION_MUSIC,
    .conditions = {MATCH_ON_MB(MB_SAND, MB_DEEP_SAND)},
    },
    [COND_MSG_GRASS] =
    {
    .text = sCondMsg20,
    .emotion = FOLLOWER_EMOTION_MUSIC,
    .conditions = {MATCH_ON_MB(MB_TALL_GRASS, MB_LONG_GRASS)},
    },
    [COND_MSG_FOOTPRINTS] =
    {
    .text = sCondMsg21,
    .emotion = FOLLOWER_EMOTION_MUSIC,
    .conditions = {MATCH_ON_MB(MB_SAND, MB_FOOTPRINTS)},
    },
    [COND_MSG_ELEVATOR] =
    {
    .text = (u8*)sElevatorTexts,
    .textSpread = 1,
    .emotion = FOLLOWER_EMOTION_SURPRISE,
    .conditions = {MATCH_MAP(LILYCOVE_CITY_DEPARTMENT_STORE_ELEVATOR)},
    },
    [COND_MSG_ICE_ROOM] =
    {
    .text = (u8*)sColdTexts,
    .textSpread = 1,
    .emotion = FOLLOWER_EMOTION_SURPRISE,
    .conditions = {MATCH_MAP(SHOAL_CAVE_LOW_TIDE_ICE_ROOM)},
    },
    [COND_MSG_ROUTE_117] =
    {
    .text = sCondMsg27,
    .emotion = FOLLOWER_EMOTION_SURPRISE,
    .conditions = {MATCH_MAP(ROUTE117)},
    },
    [COND_MSG_DRAGON_GROWL] =
    {
    .text = sCondMsg28,
    .emotion = FOLLOWER_EMOTION_UPSET,
    .conditions = {
        MATCH_TYPES(TYPE_DRAGON, TYPE_DRAGON),
        MATCH_MAPSEC(MAPSEC_SKY_PILLAR),
    }
    },
    [COND_MSG_FEAR] =
    {
    .text = (u8*)sFearTexts,
    .textSpread = 1,
    .emotion = FOLLOWER_EMOTION_UPSET,
    .conditions = {
        MATCH_NOT_TYPES(TYPE_GHOST, TYPE_GHOST),
        MATCH_MAPSEC(MAPSEC_MT_PYRE),
        MATCH_MUSIC(MUS_MT_PYRE),
    }
    },
    [COND_MSG_FIRE_RAIN] =
    {
    .text = sCondMsg31,
    .emotion = FOLLOWER_EMOTION_UPSET,
    .conditions = {
        MATCH_TYPES(TYPE_FIRE, TYPE_FIRE),
        MATCH_WEATHER(WEATHER_RAIN, WEATHER_RAIN_THUNDERSTORM),
    }
    },
    [COND_MSG_FROZEN] =
    {
    .text = sCondMsg32,
    .emotion = FOLLOWER_EMOTION_UPSET,
    .conditions = {
        MATCH_STATUS(STATUS1_FREEZE),
    }
    },
    [COND_MSG_SEASIDE] =
    {
    .text = (u8*)sSeaTexts,
    .textSpread = 1,
    .script = EventScript_FollowerFaceResult,
    .emotion = FOLLOWER_EMOTION_MUSIC,
    .conditions = {MATCH_NEAR_MB(MB_OCEAN_WATER, 5)},
    },
    [COND_MSG_WATERFALL] =
    {
    .text = sCondMsg36,
    .script = EventScript_FollowerFaceResult,
    .emotion = FOLLOWER_EMOTION_MUSIC,
    .conditions = {MATCH_NEAR_MB(MB_WATERFALL, 5)},
    },
    [COND_MSG_RAIN] =
    {
    .text = sCondMsg37,
    .emotion = FOLLOWER_EMOTION_MUSIC,
    .conditions = {
        MATCH_NOT_TYPES(TYPE_FIRE, TYPE_FIRE),
        MATCH_WEATHER(WEATHER_RAIN, WEATHER_RAIN_THUNDERSTORM)
    }
    },
    [COND_MSG_REFLECTION] =
    {
    .text = sCondMsg38,
    .script = EventScript_FollowerFaceResult,
    .emotion = FOLLOWER_EMOTION_PENSIVE,
    .conditions = {MATCH_NEAR_MB(MB_POND_WATER, 1)},
    },
    [COND_MSG_LEAVES] =
    {
    .text = sCondMsg39,
    .emotion = FOLLOWER_EMOTION_PENSIVE,
    .conditions = {MATCH_MAPSEC(MAPSEC_PETALBURG_WOODS)},
    },
    [COND_MSG_ICE] =
    {
    .text = (u8*)sIceTexts,
    .textSpread = 1,
    .script = EventScript_FollowerFaceResult,
    .emotion = FOLLOWER_EMOTION_PENSIVE,
    .conditions = {MATCH_NEAR_MB(MB_ICE, 1)},
    },
    [COND_MSG_BURN] =
    {
    .text = sCondMsg42,
    .emotion = FOLLOWER_EMOTION_SAD,
    .conditions = {MATCH_STATUS(STATUS1_BURN)},
    },
    [COND_MSG_ABNORMAL_WEATHER] =
    {
    .text = sCondMsg50,
    .emotion = FOLLOWER_EMOTION_SURPRISE,
    .conditions = {
        MATCH_MUSIC(MUS_ABNORMAL_WEATHER),
        MATCH_NOT_SPECIES(SPECIES_KYOGRE),
        MATCH_NOT_SPECIES(SPECIES_GROUDON),
        MATCH_NOT_SPECIES(SPECIES_RAYQUAZA),
    }
    },
};

// Pool of "unconditional" follower messages
const struct FollowerMessagePool gFollowerBasicMessages[FOLLOWER_EMOTION_LENGTH] = {
    [FOLLOWER_EMOTION_HAPPY] = {gFollowerHappyMessages, EventScript_FollowerGeneric, N_FOLLOWER_HAPPY_MESSAGES},
    [FOLLOWER_EMOTION_NEUTRAL] = {gFollowerNeutralMessages, EventScript_FollowerGeneric, N_FOLLOWER_NEUTRAL_MESSAGES},
    [FOLLOWER_EMOTION_SAD] = {gFollowerSadMessages, EventScript_FollowerGeneric, N_FOLLOWER_SAD_MESSAGES},
    [FOLLOWER_EMOTION_UPSET] = {gFollowerUpsetMessages, EventScript_FollowerGeneric, N_FOLLOWER_UPSET_MESSAGES},
    [FOLLOWER_EMOTION_ANGRY] = {gFollowerAngryMessages, EventScript_FollowerGeneric, N_FOLLOWER_ANGRY_MESSAGES},
    [FOLLOWER_EMOTION_PENSIVE] = {gFollowerPensiveMessages, EventScript_FollowerGeneric, N_FOLLOWER_PENSIVE_MESSAGES},
    [FOLLOWER_EMOTION_LOVE] = {gFollowerLoveMessages, EventScript_FollowerGeneric, N_FOLLOWER_LOVE_MESSAGES},
    [FOLLOWER_EMOTION_SURPRISE] = {gFollowerSurpriseMessages, EventScript_FollowerGeneric, N_FOLLOWER_SURPRISE_MESSAGES},
    [FOLLOWER_EMOTION_CURIOUS] = {gFollowerCuriousMessages, EventScript_FollowerGeneric, N_FOLLOWER_CURIOUS_MESSAGES},
    [FOLLOWER_EMOTION_MUSIC] = {gFollowerMusicMessages, EventScript_FollowerGeneric, N_FOLLOWER_MUSIC_MESSAGES},
    [FOLLOWER_EMOTION_POISONED] = {gFollowerPoisonedMessages, EventScript_FollowerGeneric, N_FOLLOWER_POISONED_MESSAGES},
};

// BEGIN GENERATED LOCALIZATION EXPORTS
// These pointers expose file-local translated strings to the runtime resolver.
const u8 *const gLocalizationSource_C02580 = sCondMsg00;
const u8 *const gLocalizationSource_C02581 = sCondMsg01;
const u8 *const gLocalizationSource_C02582 = sCondMsg02;
const u8 *const gLocalizationSource_C02583 = sCondMsg03;
const u8 *const gLocalizationSource_C02584 = sCondMsg04;
const u8 *const gLocalizationSource_C02585 = sCondMsg05;
const u8 *const gLocalizationSource_C02586 = sCondMsg06;
const u8 *const gLocalizationSource_C02587 = sCondMsg07;
const u8 *const gLocalizationSource_C02588 = sCondMsg08;
const u8 *const gLocalizationSource_C02589 = sCondMsg09;
const u8 *const gLocalizationSource_C02590 = sCondMsg10;
const u8 *const gLocalizationSource_C02591 = sCondMsg11;
const u8 *const gLocalizationSource_C02592 = sCondMsg12;
const u8 *const gLocalizationSource_C02593 = sCondMsg13;
const u8 *const gLocalizationSource_C02594 = sCondMsg14;
const u8 *const gLocalizationSource_C02595 = sCondMsg15;
const u8 *const gLocalizationSource_C02596 = sCondMsg16;
const u8 *const gLocalizationSource_C02597 = sCondMsg17;
const u8 *const gLocalizationSource_C02598 = sCondMsg18;
const u8 *const gLocalizationSource_C02599 = sCondMsg19;
const u8 *const gLocalizationSource_C02600 = sCondMsg20;
const u8 *const gLocalizationSource_C02601 = sCondMsg21;
const u8 *const gLocalizationSource_C02602 = sCondMsg22;
const u8 *const gLocalizationSource_C02603 = sCondMsg23;
const u8 *const gLocalizationSource_C02604 = sCondMsg24;
const u8 *const gLocalizationSource_C02605 = sCondMsg25;
const u8 *const gLocalizationSource_C02606 = sCondMsg26;
const u8 *const gLocalizationSource_C02607 = sCondMsg27;
const u8 *const gLocalizationSource_C02608 = sCondMsg28;
const u8 *const gLocalizationSource_C02609 = sCondMsg29;
const u8 *const gLocalizationSource_C02610 = sCondMsg30;
const u8 *const gLocalizationSource_C02611 = sCondMsg31;
const u8 *const gLocalizationSource_C02612 = sCondMsg32;
const u8 *const gLocalizationSource_C02613 = sCondMsg33;
const u8 *const gLocalizationSource_C02614 = sCondMsg34;
const u8 *const gLocalizationSource_C02615 = sCondMsg35;
const u8 *const gLocalizationSource_C02616 = sCondMsg36;
const u8 *const gLocalizationSource_C02617 = sCondMsg37;
const u8 *const gLocalizationSource_C02618 = sCondMsg38;
const u8 *const gLocalizationSource_C02619 = sCondMsg39;
const u8 *const gLocalizationSource_C02620 = sCondMsg40;
const u8 *const gLocalizationSource_C02621 = sCondMsg41;
const u8 *const gLocalizationSource_C02622 = sCondMsg42;
const u8 *const gLocalizationSource_C02623 = sCondMsg50;
// END GENERATED LOCALIZATION EXPORTS
