#include "global.h"
#include "berry.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "event_scripts.h"
#include "field_control_avatar.h"
#include "fieldmap.h"
#include "item.h"
#include "item_menu.h"
#include "main.h"
#include "random.h"
#include "string_util.h"
#include "text.h"
#include "constants/event_object_movement.h"
#include "constants/items.h"

static u32 GetEnigmaBerryChecksum(struct EnigmaBerry *enigmaBerry);
static bool32 BerryTreeGrow(struct BerryTree *tree);
static u16 BerryTypeToItemId(u16 berry);
static u8 BerryTreeGetNumStagesWatered(struct BerryTree *tree);
static u8 GetNumStagesWateredByBerryTreeId(u8 id);
static u8 CalcBerryYieldInternal(u16 max, u16 min, u8 water);
static u8 CalcBerryYield(struct BerryTree *tree);
static u8 GetBerryCountByBerryTreeId(u8 id);
static u16 GetStageDurationByBerryType(u8);

//.rodata
static const u8 sBerryDescriptionPart1_Cheri[] = _("Nở những bông hoa nhỏ xinh.");
static const u8 sBerryDescriptionPart2_Cheri[] = _("BERRY đỏ tươi có vị rất cay.");
static const u8 sBerryDescriptionPart1_Chesto[] = _("Vỏ và thịt BERRY đều dày,");
static const u8 sBerryDescriptionPart2_Chesto[] = _("rất cứng và có vị khô.");
static const u8 sBerryDescriptionPart1_Pecha[] = _("Rất ngọt và thơm ngon.");
static const u8 sBerryDescriptionPart2_Pecha[] = _("Quả mềm nên phải cầm cẩn thận.");
static const u8 sBerryDescriptionPart1_Rawst[] = _("Khi lá mọc dài và xoăn,");
static const u8 sBerryDescriptionPart2_Rawst[] = _("BERRY dường như càng đắng.");
static const u8 sBerryDescriptionPart1_Aspear[] = _("BERRY cứng chứa nhiều nước ép");
static const u8 sBerryDescriptionPart2_Aspear[] = _("đậm đà và có vị khá chua.");
static const u8 sBerryDescriptionPart1_Leppa[] = _("Mọc chậm hơn CHERI và các loại khác.");
static const u8 sBerryDescriptionPart2_Leppa[] = _("BERRY càng nhỏ càng ngon.");
static const u8 sBerryDescriptionPart1_Oran[] = _("BERRY lạ có nhiều hương vị hòa trộn.");
static const u8 sBerryDescriptionPart2_Oran[] = _("BERRIES phát triển trong nửa ngày.");
static const u8 sBerryDescriptionPart1_Persim[] = _("Ưa ánh nắng. Màu của BERRY");
static const u8 sBerryDescriptionPart2_Persim[] = _("rực rỡ hơn khi được phơi nắng.");
static const u8 sBerryDescriptionPart1_Lum[] = _("Mọc chậm. Nếu được chăm sóc");
static const u8 sBerryDescriptionPart2_Lum[] = _("cẩn thận, cây có thể cho hai BERRIES.");
static const u8 sBerryDescriptionPart1_Sitrus[] = _("Có họ gần với ORAN. Quả lớn");
static const u8 sBerryDescriptionPart2_Sitrus[] = _("và mang hương vị cân bằng.");
static const u8 sBerryDescriptionPart1_Figy[] = _("BERRY trông như đã bị cắn,");
static const u8 sBerryDescriptionPart2_Figy[] = _("bên trong chứa đầy chất cay.");
static const u8 sBerryDescriptionPart1_Wiki[] = _("BERRY mọc nhiều chỗ lồi lõm");
static const u8 sBerryDescriptionPart2_Wiki[] = _("để POKéMON dễ cầm hơn.");
static const u8 sBerryDescriptionPart1_Mago[] = _("BERRY cong dần khi phát triển.");
static const u8 sBerryDescriptionPart2_Mago[] = _("Càng cong thì càng ngọt và ngon.");
static const u8 sBerryDescriptionPart1_Aguav[] = _("Hoa thanh mảnh. Loài cây hiếm");
static const u8 sBerryDescriptionPart2_Aguav[] = _("có thể phát triển thiếu ánh sáng.");
static const u8 sBerryDescriptionPart1_Iapapa[] = _("BERRY rất lớn và chua.");
static const u8 sBerryDescriptionPart2_Iapapa[] = _("Cần ít nhất một ngày để lớn.");
static const u8 sBerryDescriptionPart1_Razz[] = _("BERRY đỏ có vị hơi cay.");
static const u8 sBerryDescriptionPart2_Razz[] = _("Phát triển nhanh chỉ trong bốn giờ.");
static const u8 sBerryDescriptionPart1_Bluk[] = _("BERRY có vỏ ngoài màu xanh,");
static const u8 sBerryDescriptionPart2_Bluk[] = _("nhưng ăn vào sẽ làm đen miệng.");
static const u8 sBerryDescriptionPart1_Nanab[] = _("Đây là BERRY thứ bảy");
static const u8 sBerryDescriptionPart2_Nanab[] = _("được phát hiện. Nó có vị ngọt.");
static const u8 sBerryDescriptionPart1_Wepear[] = _("Hoa nhỏ màu trắng. Hương vị");
static const u8 sBerryDescriptionPart2_Wepear[] = _("cân bằng tinh tế giữa đắng và chua.");
static const u8 sBerryDescriptionPart1_Pinap[] = _("Yếu trước gió và thời tiết lạnh.");
static const u8 sBerryDescriptionPart2_Pinap[] = _("Thịt quả cay còn vỏ thì chua.");
static const u8 sBerryDescriptionPart1_Pomeg[] = _("Dù được tưới nhiều đến đâu,");
static const u8 sBerryDescriptionPart2_Pomeg[] = _("cây chỉ cho tối đa sáu BERRIES.");
static const u8 sBerryDescriptionPart1_Kelpsy[] = _("Giống hiếm có hình như rễ cây.");
static const u8 sBerryDescriptionPart2_Kelpsy[] = _("Cây nở một bông hoa rất lớn.");
static const u8 sBerryDescriptionPart1_Qualot[] = _("Ưa nước và vẫn phát triển tốt");
static const u8 sBerryDescriptionPart2_Qualot[] = _("ở nơi mưa liên tục.");
static const u8 sBerryDescriptionPart1_Hondew[] = _("BERRY rất quý giá và");
static const u8 sBerryDescriptionPart2_Hondew[] = _("hiếm gặp. Hương vị rất ngon.");
static const u8 sBerryDescriptionPart1_Grepa[] = _("Dù mềm và có hình tròn,");
static const u8 sBerryDescriptionPart2_Grepa[] = _("BERRY lại chua đến khó tin.");
static const u8 sBerryDescriptionPart1_Tamato[] = _("BERRY cay đến mức tê môi.");
static const u8 sBerryDescriptionPart2_Tamato[] = _("Cần nhiều thời gian để phát triển.");
static const u8 sBerryDescriptionPart1_Cornn[] = _("BERRY từ thời cổ đại, có thể");
static const u8 sBerryDescriptionPart2_Cornn[] = _("không mọc nếu trồng quá ít.");
static const u8 sBerryDescriptionPart1_Magost[] = _("BERRY nổi tiếng vì có");
static const u8 sBerryDescriptionPart2_Magost[] = _("hương vị cân bằng tinh tế.");
static const u8 sBerryDescriptionPart1_Rabuta[] = _("Giống hiếm mọc đầy lông.");
static const u8 sBerryDescriptionPart2_Rabuta[] = _("Nó có vị khá đắng.");
static const u8 sBerryDescriptionPart1_Nomel[] = _("Rất chua. Chỉ một miếng cũng khiến");
static const u8 sBerryDescriptionPart2_Nomel[] = _("mất vị giác suốt ba ngày.");
static const u8 sBerryDescriptionPart1_Spelon[] = _("BERRY đỏ rực có vị rất cay.");
static const u8 sBerryDescriptionPart2_Spelon[] = _("Các nốt sần tiết ra chất cay.");
static const u8 sBerryDescriptionPart1_Pamtre[] = _("Trôi dạt trên biển từ nơi nào đó.");
static const u8 sBerryDescriptionPart2_Pamtre[] = _("Được cho là mọc ở vùng đất khác.");
static const u8 sBerryDescriptionPart1_Watmel[] = _("BERRY khổng lồ, có quả dài hơn");
static const u8 sBerryDescriptionPart2_Watmel[] = _("20 inch. Hương vị cực kỳ ngọt.");
static const u8 sBerryDescriptionPart1_Durin[] = _("Nhìn thôi đã thấy đắng.");
static const u8 sBerryDescriptionPart2_Durin[] = _("Đắng đến mức chưa ai ăn nguyên quả.");
static const u8 sBerryDescriptionPart1_Belue[] = _("Bóng đẹp và trông ngon, nhưng");
static const u8 sBerryDescriptionPart2_Belue[] = _("rất chua và lâu phát triển.");
static const u8 sBerryDescriptionPart1_Liechi[] = _("BERRY bí ẩn được đồn rằng");
static const u8 sBerryDescriptionPart2_Liechi[] = _("chứa sức mạnh của biển cả.");
static const u8 sBerryDescriptionPart1_Ganlon[] = _("BERRY bí ẩn được đồn rằng");
static const u8 sBerryDescriptionPart2_Ganlon[] = _("chứa sức mạnh của đất liền.");
static const u8 sBerryDescriptionPart1_Salac[] = _("BERRY bí ẩn được đồn rằng");
static const u8 sBerryDescriptionPart2_Salac[] = _("chứa sức mạnh của bầu trời.");
static const u8 sBerryDescriptionPart1_Petaya[] = _("BERRY bí ẩn được đồn rằng");
static const u8 sBerryDescriptionPart2_Petaya[] = _("chứa sức mạnh của mọi sinh vật.");
static const u8 sBerryDescriptionPart1_Apicot[] = _("BERRY vô cùng bí ẩn. Không ai biết");
static const u8 sBerryDescriptionPart2_Apicot[] = _("chuyện gì xảy ra hay cách dùng nó.");
static const u8 sBerryDescriptionPart1_Lansat[] = _("Được cho là BERRY huyền thoại.");
static const u8 sBerryDescriptionPart2_Lansat[] = _("Mang theo nó được cho là đem niềm vui.");
static const u8 sBerryDescriptionPart1_Starf[] = _("Quá mạnh nên bị bỏ lại nơi");
static const u8 sBerryDescriptionPart2_Starf[] = _("tận cùng thế giới, như một ảo ảnh.");
static const u8 sBerryDescriptionPart1_Enigma[] = _("Một BERRY hoàn toàn bí ẩn.");
static const u8 sBerryDescriptionPart2_Enigma[] = _("Có vẻ chứa sức mạnh của các vì sao.");

const struct Berry gBerries[] =
{
    [ITEM_CHERI_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("CHERI"),
        .firmness = BERRY_FIRMNESS_SOFT,
        .size = 20,
        .maxYield = 3,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Cheri,
        .description2 = sBerryDescriptionPart2_Cheri,
        .stageDuration = 3,
        .spicy = 10,
        .dry = 0,
        .sweet = 0,
        .bitter = 0,
        .sour = 0,
        .smoothness = 25,
    },

    [ITEM_CHESTO_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("CHESTO"),
        .firmness = BERRY_FIRMNESS_SUPER_HARD,
        .size = 80,
        .maxYield = 3,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Chesto,
        .description2 = sBerryDescriptionPart2_Chesto,
        .stageDuration = 3,
        .spicy = 0,
        .dry = 10,
        .sweet = 0,
        .bitter = 0,
        .sour = 0,
        .smoothness = 25,
    },

    [ITEM_PECHA_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("PECHA"),
        .firmness = BERRY_FIRMNESS_VERY_SOFT,
        .size = 40,
        .maxYield = 3,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Pecha,
        .description2 = sBerryDescriptionPart2_Pecha,
        .stageDuration = 3,
        .spicy = 0,
        .dry = 0,
        .sweet = 10,
        .bitter = 0,
        .sour = 0,
        .smoothness = 25,
    },

    [ITEM_RAWST_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("RAWST"),
        .firmness = BERRY_FIRMNESS_HARD,
        .size = 32,
        .maxYield = 3,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Rawst,
        .description2 = sBerryDescriptionPart2_Rawst,
        .stageDuration = 3,
        .spicy = 0,
        .dry = 0,
        .sweet = 0,
        .bitter = 10,
        .sour = 0,
        .smoothness = 25,
    },

    [ITEM_ASPEAR_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("ASPEAR"),
        .firmness = BERRY_FIRMNESS_SUPER_HARD,
        .size = 50,
        .maxYield = 3,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Aspear,
        .description2 = sBerryDescriptionPart2_Aspear,
        .stageDuration = 3,
        .spicy = 0,
        .dry = 0,
        .sweet = 0,
        .bitter = 0,
        .sour = 10,
        .smoothness = 25,
    },

    [ITEM_LEPPA_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("LEPPA"),
        .firmness = BERRY_FIRMNESS_VERY_HARD,
        .size = 28,
        .maxYield = 3,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Leppa,
        .description2 = sBerryDescriptionPart2_Leppa,
        .stageDuration = 4,
        .spicy = 10,
        .dry = 0,
        .sweet = 10,
        .bitter = 10,
        .sour = 10,
        .smoothness = 20,
    },

    [ITEM_ORAN_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("ORAN"),
        .firmness = BERRY_FIRMNESS_SUPER_HARD,
        .size = 35,
        .maxYield = 3,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Oran,
        .description2 = sBerryDescriptionPart2_Oran,
        .stageDuration = 3,
        .spicy = 10,
        .dry = 10,
        .sweet = 10,
        .bitter = 10,
        .sour = 10,
        .smoothness = 20,
    },

    [ITEM_PERSIM_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("PERSIM"),
        .firmness = BERRY_FIRMNESS_HARD,
        .size = 47,
        .maxYield = 3,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Persim,
        .description2 = sBerryDescriptionPart2_Persim,
        .stageDuration = 3,
        .spicy = 10,
        .dry = 10,
        .sweet = 10,
        .bitter = 10,
        .sour = 10,
        .smoothness = 20,
    },

    [ITEM_LUM_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("LUM"),
        .firmness = BERRY_FIRMNESS_SUPER_HARD,
        .size = 34,
        .maxYield = 2,
        .minYield = 1,
        .description1 = sBerryDescriptionPart1_Lum,
        .description2 = sBerryDescriptionPart2_Lum,
        .stageDuration = 12,
        .spicy = 10,
        .dry = 10,
        .sweet = 10,
        .bitter = 10,
        .sour = 10,
        .smoothness = 20,
    },

    [ITEM_SITRUS_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("SITRUS"),
        .firmness = BERRY_FIRMNESS_VERY_HARD,
        .size = 95,
        .maxYield = 3,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Sitrus,
        .description2 = sBerryDescriptionPart2_Sitrus,
        .stageDuration = 6,
        .spicy = 10,
        .dry = 10,
        .sweet = 10,
        .bitter = 10,
        .sour = 10,
        .smoothness = 20,
    },

    [ITEM_FIGY_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("FIGY"),
        .firmness = BERRY_FIRMNESS_SOFT,
        .size = 100,
        .maxYield = 3,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Figy,
        .description2 = sBerryDescriptionPart2_Figy,
        .stageDuration = 6,
        .spicy = 10,
        .dry = 0,
        .sweet = 0,
        .bitter = 0,
        .sour = 0,
        .smoothness = 25,
    },

    [ITEM_WIKI_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("WIKI"),
        .firmness = BERRY_FIRMNESS_HARD,
        .size = 115,
        .maxYield = 3,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Wiki,
        .description2 = sBerryDescriptionPart2_Wiki,
        .stageDuration = 6,
        .spicy = 0,
        .dry = 10,
        .sweet = 0,
        .bitter = 0,
        .sour = 0,
        .smoothness = 25,
    },

    [ITEM_MAGO_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("MAGO"),
        .firmness = BERRY_FIRMNESS_HARD,
        .size = 126,
        .maxYield = 3,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Mago,
        .description2 = sBerryDescriptionPart2_Mago,
        .stageDuration = 6,
        .spicy = 0,
        .dry = 0,
        .sweet = 10,
        .bitter = 0,
        .sour = 0,
        .smoothness = 25,
    },

    [ITEM_AGUAV_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("AGUAV"),
        .firmness = BERRY_FIRMNESS_SUPER_HARD,
        .size = 64,
        .maxYield = 3,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Aguav,
        .description2 = sBerryDescriptionPart2_Aguav,
        .stageDuration = 6,
        .spicy = 0,
        .dry = 0,
        .sweet = 0,
        .bitter = 10,
        .sour = 0,
        .smoothness = 25,
    },

    [ITEM_IAPAPA_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("IAPAPA"),
        .firmness = BERRY_FIRMNESS_SOFT,
        .size = 223,
        .maxYield = 3,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Iapapa,
        .description2 = sBerryDescriptionPart2_Iapapa,
        .stageDuration = 6,
        .spicy = 0,
        .dry = 0,
        .sweet = 0,
        .bitter = 0,
        .sour = 10,
        .smoothness = 25,
    },

    [ITEM_RAZZ_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("RAZZ"),
        .firmness = BERRY_FIRMNESS_VERY_HARD,
        .size = 120,
        .maxYield = 6,
        .minYield = 3,
        .description1 = sBerryDescriptionPart1_Razz,
        .description2 = sBerryDescriptionPart2_Razz,
        .stageDuration = 1,
        .spicy = 10,
        .dry = 10,
        .sweet = 0,
        .bitter = 0,
        .sour = 0,
        .smoothness = 20,
    },

    [ITEM_BLUK_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("BLUK"),
        .firmness = BERRY_FIRMNESS_SOFT,
        .size = 108,
        .maxYield = 6,
        .minYield = 3,
        .description1 = sBerryDescriptionPart1_Bluk,
        .description2 = sBerryDescriptionPart2_Bluk,
        .stageDuration = 1,
        .spicy = 0,
        .dry = 10,
        .sweet = 10,
        .bitter = 0,
        .sour = 0,
        .smoothness = 20,
    },

    [ITEM_NANAB_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("NANAB"),
        .firmness = BERRY_FIRMNESS_VERY_HARD,
        .size = 77,
        .maxYield = 6,
        .minYield = 3,
        .description1 = sBerryDescriptionPart1_Nanab,
        .description2 = sBerryDescriptionPart2_Nanab,
        .stageDuration = 1,
        .spicy = 0,
        .dry = 0,
        .sweet = 10,
        .bitter = 10,
        .sour = 0,
        .smoothness = 20,
    },

    [ITEM_WEPEAR_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("WEPEAR"),
        .firmness = BERRY_FIRMNESS_SUPER_HARD,
        .size = 74,
        .maxYield = 6,
        .minYield = 3,
        .description1 = sBerryDescriptionPart1_Wepear,
        .description2 = sBerryDescriptionPart2_Wepear,
        .stageDuration = 1,
        .spicy = 0,
        .dry = 0,
        .sweet = 0,
        .bitter = 10,
        .sour = 10,
        .smoothness = 20,
    },

    [ITEM_PINAP_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("PINAP"),
        .firmness = BERRY_FIRMNESS_HARD,
        .size = 80,
        .maxYield = 6,
        .minYield = 3,
        .description1 = sBerryDescriptionPart1_Pinap,
        .description2 = sBerryDescriptionPart2_Pinap,
        .stageDuration = 1,
        .spicy = 10,
        .dry = 0,
        .sweet = 0,
        .bitter = 0,
        .sour = 10,
        .smoothness = 20,
    },

    [ITEM_POMEG_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("POMEG"),
        .firmness = BERRY_FIRMNESS_VERY_HARD,
        .size = 135,
        .maxYield = 6,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Pomeg,
        .description2 = sBerryDescriptionPart2_Pomeg,
        .stageDuration = 3,
        .spicy = 10,
        .dry = 0,
        .sweet = 10,
        .bitter = 10,
        .sour = 0,
        .smoothness = 20,
    },

    [ITEM_KELPSY_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("KELPSY"),
        .firmness = BERRY_FIRMNESS_HARD,
        .size = 150,
        .maxYield = 6,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Kelpsy,
        .description2 = sBerryDescriptionPart2_Kelpsy,
        .stageDuration = 3,
        .spicy = 0,
        .dry = 10,
        .sweet = 0,
        .bitter = 10,
        .sour = 10,
        .smoothness = 20,
    },

    [ITEM_QUALOT_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("QUALOT"),
        .firmness = BERRY_FIRMNESS_HARD,
        .size = 110,
        .maxYield = 6,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Qualot,
        .description2 = sBerryDescriptionPart2_Qualot,
        .stageDuration = 3,
        .spicy = 10,
        .dry = 0,
        .sweet = 10,
        .bitter = 0,
        .sour = 10,
        .smoothness = 20,
    },

    [ITEM_HONDEW_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("HONDEW"),
        .firmness = BERRY_FIRMNESS_HARD,
        .size = 162,
        .maxYield = 6,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Hondew,
        .description2 = sBerryDescriptionPart2_Hondew,
        .stageDuration = 3,
        .spicy = 10,
        .dry = 10,
        .sweet = 0,
        .bitter = 10,
        .sour = 0,
        .smoothness = 20,
    },

    [ITEM_GREPA_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("GREPA"),
        .firmness = BERRY_FIRMNESS_SOFT,
        .size = 149,
        .maxYield = 6,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Grepa,
        .description2 = sBerryDescriptionPart2_Grepa,
        .stageDuration = 3,
        .spicy = 0,
        .dry = 10,
        .sweet = 10,
        .bitter = 0,
        .sour = 10,
        .smoothness = 20,
    },

    [ITEM_TAMATO_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("TAMATO"),
        .firmness = BERRY_FIRMNESS_SOFT,
        .size = 200,
        .maxYield = 4,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Tamato,
        .description2 = sBerryDescriptionPart2_Tamato,
        .stageDuration = 6,
        .spicy = 20,
        .dry = 10,
        .sweet = 0,
        .bitter = 0,
        .sour = 0,
        .smoothness = 30,
    },

    [ITEM_CORNN_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("CORNN"),
        .firmness = BERRY_FIRMNESS_HARD,
        .size = 75,
        .maxYield = 4,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Cornn,
        .description2 = sBerryDescriptionPart2_Cornn,
        .stageDuration = 6,
        .spicy = 0,
        .dry = 20,
        .sweet = 10,
        .bitter = 0,
        .sour = 0,
        .smoothness = 30,
    },

    [ITEM_MAGOST_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("MAGOST"),
        .firmness = BERRY_FIRMNESS_HARD,
        .size = 140,
        .maxYield = 4,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Magost,
        .description2 = sBerryDescriptionPart2_Magost,
        .stageDuration = 6,
        .spicy = 0,
        .dry = 0,
        .sweet = 20,
        .bitter = 10,
        .sour = 0,
        .smoothness = 30,
    },

    [ITEM_RABUTA_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("RABUTA"),
        .firmness = BERRY_FIRMNESS_SOFT,
        .size = 226,
        .maxYield = 4,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Rabuta,
        .description2 = sBerryDescriptionPart2_Rabuta,
        .stageDuration = 6,
        .spicy = 0,
        .dry = 0,
        .sweet = 0,
        .bitter = 20,
        .sour = 10,
        .smoothness = 30,
    },

    [ITEM_NOMEL_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("NOMEL"),
        .firmness = BERRY_FIRMNESS_SUPER_HARD,
        .size = 285,
        .maxYield = 4,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Nomel,
        .description2 = sBerryDescriptionPart2_Nomel,
        .stageDuration = 6,
        .spicy = 10,
        .dry = 0,
        .sweet = 0,
        .bitter = 0,
        .sour = 20,
        .smoothness = 30,
    },

    [ITEM_SPELON_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("SPELON"),
        .firmness = BERRY_FIRMNESS_SOFT,
        .size = 133,
        .maxYield = 2,
        .minYield = 1,
        .description1 = sBerryDescriptionPart1_Spelon,
        .description2 = sBerryDescriptionPart2_Spelon,
        .stageDuration = 18,
        .spicy = 40,
        .dry = 10,
        .sweet = 0,
        .bitter = 0,
        .sour = 0,
        .smoothness = 70,
    },

    [ITEM_PAMTRE_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("PAMTRE"),
        .firmness = BERRY_FIRMNESS_VERY_SOFT,
        .size = 244,
        .maxYield = 2,
        .minYield = 1,
        .description1 = sBerryDescriptionPart1_Pamtre,
        .description2 = sBerryDescriptionPart2_Pamtre,
        .stageDuration = 18,
        .spicy = 0,
        .dry = 40,
        .sweet = 10,
        .bitter = 0,
        .sour = 0,
        .smoothness = 70,
    },

    [ITEM_WATMEL_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("WATMEL"),
        .firmness = BERRY_FIRMNESS_SOFT,
        .size = 250,
        .maxYield = 2,
        .minYield = 1,
        .description1 = sBerryDescriptionPart1_Watmel,
        .description2 = sBerryDescriptionPart2_Watmel,
        .stageDuration = 18,
        .spicy = 0,
        .dry = 0,
        .sweet = 40,
        .bitter = 10,
        .sour = 0,
        .smoothness = 70,
    },

    [ITEM_DURIN_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("DURIN"),
        .firmness = BERRY_FIRMNESS_HARD,
        .size = 280,
        .maxYield = 2,
        .minYield = 1,
        .description1 = sBerryDescriptionPart1_Durin,
        .description2 = sBerryDescriptionPart2_Durin,
        .stageDuration = 18,
        .spicy = 0,
        .dry = 0,
        .sweet = 0,
        .bitter = 40,
        .sour = 10,
        .smoothness = 70,
    },

    [ITEM_BELUE_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("BELUE"),
        .firmness = BERRY_FIRMNESS_VERY_SOFT,
        .size = 300,
        .maxYield = 2,
        .minYield = 1,
        .description1 = sBerryDescriptionPart1_Belue,
        .description2 = sBerryDescriptionPart2_Belue,
        .stageDuration = 18,
        .spicy = 10,
        .dry = 0,
        .sweet = 0,
        .bitter = 0,
        .sour = 40,
        .smoothness = 70,
    },

    [ITEM_LIECHI_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("LIECHI"),
        .firmness = BERRY_FIRMNESS_VERY_HARD,
        .size = 111,
        .maxYield = 2,
        .minYield = 1,
        .description1 = sBerryDescriptionPart1_Liechi,
        .description2 = sBerryDescriptionPart2_Liechi,
        .stageDuration = 24,
        .spicy = 40,
        .dry = 0,
        .sweet = 40,
        .bitter = 0,
        .sour = 10,
        .smoothness = 80,
    },

    [ITEM_GANLON_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("GANLON"),
        .firmness = BERRY_FIRMNESS_VERY_HARD,
        .size = 33,
        .maxYield = 2,
        .minYield = 1,
        .description1 = sBerryDescriptionPart1_Ganlon,
        .description2 = sBerryDescriptionPart2_Ganlon,
        .stageDuration = 24,
        .spicy = 0,
        .dry = 40,
        .sweet = 0,
        .bitter = 40,
        .sour = 0,
        .smoothness = 80,
    },

    [ITEM_SALAC_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("SALAC"),
        .firmness = BERRY_FIRMNESS_VERY_HARD,
        .size = 95,
        .maxYield = 2,
        .minYield = 1,
        .description1 = sBerryDescriptionPart1_Salac,
        .description2 = sBerryDescriptionPart2_Salac,
        .stageDuration = 24,
        .spicy = 0,
        .dry = 0,
        .sweet = 40,
        .bitter = 0,
        .sour = 40,
        .smoothness = 80,
    },

    [ITEM_PETAYA_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("PETAYA"),
        .firmness = BERRY_FIRMNESS_VERY_HARD,
        .size = 237,
        .maxYield = 2,
        .minYield = 1,
        .description1 = sBerryDescriptionPart1_Petaya,
        .description2 = sBerryDescriptionPart2_Petaya,
        .stageDuration = 24,
        .spicy = 40,
        .dry = 0,
        .sweet = 0,
        .bitter = 40,
        .sour = 0,
        .smoothness = 80,
    },

    [ITEM_APICOT_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("APICOT"),
        .firmness = BERRY_FIRMNESS_HARD,
        .size = 75,
        .maxYield = 2,
        .minYield = 1,
        .description1 = sBerryDescriptionPart1_Apicot,
        .description2 = sBerryDescriptionPart2_Apicot,
        .stageDuration = 24,
        .spicy = 0,
        .dry = 40,
        .sweet = 0,
        .bitter = 0,
        .sour = 40,
        .smoothness = 80,
    },

    [ITEM_LANSAT_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("LANSAT"),
        .firmness = BERRY_FIRMNESS_SOFT,
        .size = 97,
        .maxYield = 2,
        .minYield = 1,
        .description1 = sBerryDescriptionPart1_Lansat,
        .description2 = sBerryDescriptionPart2_Lansat,
        .stageDuration = 24,
        .spicy = 10,
        .dry = 10,
        .sweet = 10,
        .bitter = 10,
        .sour = 10,
        .smoothness = 30,
    },

    [ITEM_STARF_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("STARF"),
        .firmness = BERRY_FIRMNESS_SUPER_HARD,
        .size = 153,
        .maxYield = 2,
        .minYield = 1,
        .description1 = sBerryDescriptionPart1_Starf,
        .description2 = sBerryDescriptionPart2_Starf,
        .stageDuration = 24,
        .spicy = 10,
        .dry = 10,
        .sweet = 10,
        .bitter = 10,
        .sour = 10,
        .smoothness = 30,
    },

    [ITEM_ENIGMA_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("ENIGMA"),
        .firmness = BERRY_FIRMNESS_UNKNOWN,
        .size = 0,
        .maxYield = 2,
        .minYield = 1,
        .description1 = sBerryDescriptionPart1_Enigma,
        .description2 = sBerryDescriptionPart2_Enigma,
        .stageDuration = 24,
        .spicy = 40,
        .dry = 40,
        .sweet = 40,
        .bitter = 40,
        .sour = 40,
        .smoothness = 40,
    },
};

const struct BerryCrushBerryData gBerryCrush_BerryData[] = {
    [ITEM_CHERI_BERRY - FIRST_BERRY_INDEX]  = {.difficulty =  50, .powder =  20},
    [ITEM_CHESTO_BERRY - FIRST_BERRY_INDEX] = {.difficulty =  50, .powder =  20},
    [ITEM_PECHA_BERRY - FIRST_BERRY_INDEX]  = {.difficulty =  50, .powder =  20},
    [ITEM_RAWST_BERRY - FIRST_BERRY_INDEX]  = {.difficulty =  50, .powder =  20},
    [ITEM_ASPEAR_BERRY - FIRST_BERRY_INDEX] = {.difficulty =  50, .powder =  20},
    [ITEM_LEPPA_BERRY - FIRST_BERRY_INDEX]  = {.difficulty =  50, .powder =  30},
    [ITEM_ORAN_BERRY - FIRST_BERRY_INDEX]   = {.difficulty =  50, .powder =  30},
    [ITEM_PERSIM_BERRY - FIRST_BERRY_INDEX] = {.difficulty =  50, .powder =  30},
    [ITEM_LUM_BERRY - FIRST_BERRY_INDEX]    = {.difficulty =  50, .powder =  30},
    [ITEM_SITRUS_BERRY - FIRST_BERRY_INDEX] = {.difficulty =  50, .powder =  30},
    [ITEM_FIGY_BERRY - FIRST_BERRY_INDEX]   = {.difficulty =  60, .powder =  50},
    [ITEM_WIKI_BERRY - FIRST_BERRY_INDEX]   = {.difficulty =  60, .powder =  50},
    [ITEM_MAGO_BERRY - FIRST_BERRY_INDEX]   = {.difficulty =  60, .powder =  50},
    [ITEM_AGUAV_BERRY - FIRST_BERRY_INDEX]  = {.difficulty =  60, .powder =  50},
    [ITEM_IAPAPA_BERRY - FIRST_BERRY_INDEX] = {.difficulty =  60, .powder =  50},
    [ITEM_RAZZ_BERRY - FIRST_BERRY_INDEX]   = {.difficulty =  80, .powder =  70},
    [ITEM_BLUK_BERRY - FIRST_BERRY_INDEX]   = {.difficulty =  80, .powder =  70},
    [ITEM_NANAB_BERRY - FIRST_BERRY_INDEX]  = {.difficulty =  80, .powder =  70},
    [ITEM_WEPEAR_BERRY - FIRST_BERRY_INDEX] = {.difficulty =  80, .powder =  70},
    [ITEM_PINAP_BERRY - FIRST_BERRY_INDEX]  = {.difficulty =  80, .powder =  70},
    [ITEM_POMEG_BERRY - FIRST_BERRY_INDEX]  = {.difficulty = 100, .powder = 100},
    [ITEM_KELPSY_BERRY - FIRST_BERRY_INDEX] = {.difficulty = 100, .powder = 100},
    [ITEM_QUALOT_BERRY - FIRST_BERRY_INDEX] = {.difficulty = 100, .powder = 100},
    [ITEM_HONDEW_BERRY - FIRST_BERRY_INDEX] = {.difficulty = 100, .powder = 100},
    [ITEM_GREPA_BERRY - FIRST_BERRY_INDEX]  = {.difficulty = 100, .powder = 100},
    [ITEM_TAMATO_BERRY - FIRST_BERRY_INDEX] = {.difficulty = 130, .powder = 150},
    [ITEM_CORNN_BERRY - FIRST_BERRY_INDEX]  = {.difficulty = 130, .powder = 150},
    [ITEM_MAGOST_BERRY - FIRST_BERRY_INDEX] = {.difficulty = 130, .powder = 150},
    [ITEM_RABUTA_BERRY - FIRST_BERRY_INDEX] = {.difficulty = 130, .powder = 150},
    [ITEM_NOMEL_BERRY - FIRST_BERRY_INDEX]  = {.difficulty = 130, .powder = 150},
    [ITEM_SPELON_BERRY - FIRST_BERRY_INDEX] = {.difficulty = 160, .powder = 250},
    [ITEM_PAMTRE_BERRY - FIRST_BERRY_INDEX] = {.difficulty = 160, .powder = 250},
    [ITEM_WATMEL_BERRY - FIRST_BERRY_INDEX] = {.difficulty = 160, .powder = 250},
    [ITEM_DURIN_BERRY - FIRST_BERRY_INDEX]  = {.difficulty = 160, .powder = 250},
    [ITEM_BELUE_BERRY - FIRST_BERRY_INDEX]  = {.difficulty = 160, .powder = 250},
    [ITEM_LIECHI_BERRY - FIRST_BERRY_INDEX] = {.difficulty = 180, .powder = 500},
    [ITEM_GANLON_BERRY - FIRST_BERRY_INDEX] = {.difficulty = 180, .powder = 500},
    [ITEM_SALAC_BERRY - FIRST_BERRY_INDEX]  = {.difficulty = 180, .powder = 500},
    [ITEM_PETAYA_BERRY - FIRST_BERRY_INDEX] = {.difficulty = 180, .powder = 500},
    [ITEM_APICOT_BERRY - FIRST_BERRY_INDEX] = {.difficulty = 180, .powder = 500},
    [ITEM_LANSAT_BERRY - FIRST_BERRY_INDEX] = {.difficulty = 200, .powder = 750},
    [ITEM_STARF_BERRY - FIRST_BERRY_INDEX]  = {.difficulty = 200, .powder = 750},
    [ITEM_ENIGMA_BERRY - FIRST_BERRY_INDEX] = {.difficulty = 150, .powder = 200}
};

const struct BerryTree gBlankBerryTree = {};

// unused
void ClearEnigmaBerries(void)
{
    CpuFill16(0, &gSaveBlock1Ptr->enigmaBerry, sizeof(gSaveBlock1Ptr->enigmaBerry));
}

void SetEnigmaBerry(u8 *src)
{
    u32 i;
    u8 *dest = (u8 *)&gSaveBlock1Ptr->enigmaBerry;

    for (i = 0; i < sizeof(gSaveBlock1Ptr->enigmaBerry); i++)
        dest[i] = src[i];
}

static u32 GetEnigmaBerryChecksum(struct EnigmaBerry *enigmaBerry)
{
    u32 i;
    u32 checksum;
    u8 *dest;

    dest = (u8 *)enigmaBerry;
    checksum = 0;
    for (i = 0; i < sizeof(gSaveBlock1Ptr->enigmaBerry) - sizeof(gSaveBlock1Ptr->enigmaBerry.checksum); i++)
        checksum += dest[i];

    return checksum;
}

bool32 IsEnigmaBerryValid(void)
{
    if (!gSaveBlock1Ptr->enigmaBerry.berry.stageDuration)
        return FALSE;
    if (!gSaveBlock1Ptr->enigmaBerry.berry.maxYield)
        return FALSE;
    if (GetEnigmaBerryChecksum(&gSaveBlock1Ptr->enigmaBerry) != gSaveBlock1Ptr->enigmaBerry.checksum)
        return FALSE;
    return TRUE;
}

const struct Berry *GetBerryInfo(u8 berry)
{
    if (berry == ITEM_TO_BERRY(ITEM_ENIGMA_BERRY) && IsEnigmaBerryValid())
    {
        return (struct Berry *)(&gSaveBlock1Ptr->enigmaBerry.berry);
    }
    else
    {
        if (berry == BERRY_NONE || berry > ITEM_TO_BERRY(LAST_BERRY_INDEX))
            berry = ITEM_TO_BERRY(FIRST_BERRY_INDEX);
        return &gBerries[berry - 1];
    }
}

struct BerryTree *GetBerryTreeInfo(u8 id)
{
    return &gSaveBlock1Ptr->berryTrees[id];
}

bool32 ObjectEventInteractionWaterBerryTree(void)
{
    struct BerryTree *tree = GetBerryTreeInfo(GetObjectEventBerryTreeId(gSelectedObjectEvent));

    switch (tree->stage)
    {
    case BERRY_STAGE_PLANTED:
        tree->watered1 = TRUE;
        break;
    case BERRY_STAGE_SPROUTED:
        tree->watered2 = TRUE;
        break;
    case BERRY_STAGE_TALLER:
        tree->watered3 = TRUE;
        break;
    case BERRY_STAGE_FLOWERING:
        tree->watered4 = TRUE;
        break;
    default:
        return FALSE;
    }
    return TRUE;
}

bool8 IsPlayerFacingEmptyBerryTreePatch(void)
{
    if (GetObjectEventScriptPointerPlayerFacing() == BerryTreeScript
     && GetStageByBerryTreeId(GetObjectEventBerryTreeId(gSelectedObjectEvent)) == BERRY_STAGE_NO_BERRY)
        return TRUE;
    else
        return FALSE;
}

bool8 TryToWaterBerryTree(void)
{
    if (GetObjectEventScriptPointerPlayerFacing() != BerryTreeScript)
        return FALSE;
    else
        return ObjectEventInteractionWaterBerryTree();
}

void ClearBerryTrees(void)
{
    int i;

    for (i = 0; i < BERRY_TREES_COUNT; i++)
        gSaveBlock1Ptr->berryTrees[i] = gBlankBerryTree;
}

static bool32 BerryTreeGrow(struct BerryTree *tree)
{
    if (tree->stopGrowth)
        return FALSE;

    switch (tree->stage)
    {
    case BERRY_STAGE_NO_BERRY:
        return FALSE;
    case BERRY_STAGE_FLOWERING:
        tree->berryYield = CalcBerryYield(tree);
    case BERRY_STAGE_PLANTED:
    case BERRY_STAGE_SPROUTED:
    case BERRY_STAGE_TALLER:
        tree->stage++;
        break;
    case BERRY_STAGE_BERRIES:
        tree->watered1 = 0;
        tree->watered2 = 0;
        tree->watered3 = 0;
        tree->watered4 = 0;
        tree->berryYield = 0;
        tree->stage = BERRY_STAGE_SPROUTED;
        if (++tree->regrowthCount == 10)
            *tree = gBlankBerryTree;
        break;
    }
    return TRUE;
}

void BerryTreeTimeUpdate(s32 minutes)
{
    int i;
    struct BerryTree *tree;

    for (i = 0; i < BERRY_TREES_COUNT; i++)
    {
        tree = &gSaveBlock1Ptr->berryTrees[i];

        if (tree->berry && tree->stage && !tree->stopGrowth)
        {
            if (minutes >= GetStageDurationByBerryType(tree->berry) * 71)
            {
                *tree = gBlankBerryTree;
            }
            else
            {
                s32 time = minutes;

                while (time != 0)
                {
                    if (tree->minutesUntilNextStage > time)
                    {
                        tree->minutesUntilNextStage -= time;
                        break;
                    }
                    time -= tree->minutesUntilNextStage;
                    tree->minutesUntilNextStage = GetStageDurationByBerryType(tree->berry);
                    if (!BerryTreeGrow(tree))
                        break;
                    if (tree->stage == BERRY_STAGE_BERRIES)
                        tree->minutesUntilNextStage *= 4;
                }
            }
        }
    }
}

void PlantBerryTree(u8 id, u8 berry, u8 stage, bool8 allowGrowth)
{
    struct BerryTree *tree = GetBerryTreeInfo(id);

    *tree = gBlankBerryTree;
    tree->berry = berry;
    tree->minutesUntilNextStage = GetStageDurationByBerryType(berry);
    tree->stage = stage;
    if (stage == BERRY_STAGE_BERRIES)
    {
        tree->berryYield = CalcBerryYield(tree);
        tree->minutesUntilNextStage *= 4;
    }

    // Stop growth, to keep tree at this stage until the player has seen it
    // allowGrowth is always true for berry trees the player has planted
    if (!allowGrowth)
        tree->stopGrowth = TRUE;
}

void RemoveBerryTree(u8 id)
{
    gSaveBlock1Ptr->berryTrees[id] = gBlankBerryTree;
}

u8 GetBerryTypeByBerryTreeId(u8 id)
{
    return gSaveBlock1Ptr->berryTrees[id].berry;
}

u8 GetStageByBerryTreeId(u8 id)
{
    return gSaveBlock1Ptr->berryTrees[id].stage;
}

u8 ItemIdToBerryType(u16 item)
{
    u16 berry = item - FIRST_BERRY_INDEX;

    if (berry > LAST_BERRY_INDEX - FIRST_BERRY_INDEX)
        return ITEM_TO_BERRY(FIRST_BERRY_INDEX);
    else
        return ITEM_TO_BERRY(item);
}

static u16 BerryTypeToItemId(u16 berry)
{
    u16 item = berry - 1;

    if (item > LAST_BERRY_INDEX - FIRST_BERRY_INDEX)
        return FIRST_BERRY_INDEX;
    else
        return berry + FIRST_BERRY_INDEX - 1;
}

void GetBerryNameByBerryType(u8 berry, u8 *string)
{
    memcpy(string, GetBerryInfo(berry)->name, BERRY_NAME_LENGTH);
    string[BERRY_NAME_LENGTH] = EOS;
}

void GetBerryCountStringByBerryType(u8 berry, u8 *dest, u32 berryCount)
{
    GetBerryCountString(dest, GetBerryInfo(berry)->name, berryCount);
}

void AllowBerryTreeGrowth(u8 id)
{
    GetBerryTreeInfo(id)->stopGrowth = FALSE;
}

static u8 BerryTreeGetNumStagesWatered(struct BerryTree *tree)
{
    u8 count = 0;

    if (tree->watered1)
        count++;
    if (tree->watered2)
        count++;
    if (tree->watered3)
        count++;
    if (tree->watered4)
        count++;
    return count;
}

static u8 GetNumStagesWateredByBerryTreeId(u8 id)
{
    return BerryTreeGetNumStagesWatered(GetBerryTreeInfo(id));
}

// Berries can be watered at 4 stages of growth. The distribution is largely
// even but slightly prefers middle berry yields, since it uniformly draws from
// a subset of the total yield range.
static u8 CalcBerryYieldInternal(u16 max, u16 min, u8 water)
{
    u32 randMin;
    u32 randMax;
    u32 rand;
    u32 extraYield;

    if (water == 0)
    {
        return min;
    }
    else
    {
        randMin = (max - min) * (water - 1);
        randMax = (max - min) * (water);
        rand = randMin + Random() % (randMax - randMin + 1);

        // Round upwards
        if ((rand % NUM_WATER_STAGES) >= NUM_WATER_STAGES / 2)
            extraYield = rand / NUM_WATER_STAGES + 1;
        else
            extraYield = rand / NUM_WATER_STAGES;
        return extraYield + min;
    }
}

static u8 CalcBerryYield(struct BerryTree *tree)
{
    const struct Berry *berry = GetBerryInfo(tree->berry);
    u8 min = berry->minYield;
    u8 max = berry->maxYield;

    return CalcBerryYieldInternal(max, min, BerryTreeGetNumStagesWatered(tree));
}

static u8 GetBerryCountByBerryTreeId(u8 id)
{
    return gSaveBlock1Ptr->berryTrees[id].berryYield;
}

static u16 GetStageDurationByBerryType(u8 berry)
{
    return GetBerryInfo(berry)->stageDuration * 60;
}

void ObjectEventInteractionGetBerryTreeData(void)
{
    u8 id;
    u8 berry;
    u8 localId;
    u8 group;
    u8 num;

    id = GetObjectEventBerryTreeId(gSelectedObjectEvent);
    berry = GetBerryTypeByBerryTreeId(id);
    AllowBerryTreeGrowth(id);
    localId = gSpecialVar_LastTalked;
    num = gSaveBlock1Ptr->location.mapNum;
    group = gSaveBlock1Ptr->location.mapGroup;
    if (IsBerryTreeSparkling(localId, num, group))
        gSpecialVar_0x8004 = BERRY_STAGE_SPARKLING;
    else
        gSpecialVar_0x8004 = GetStageByBerryTreeId(id);
    gSpecialVar_0x8005 = GetNumStagesWateredByBerryTreeId(id);
    gSpecialVar_0x8006 = GetBerryCountByBerryTreeId(id);
    GetBerryCountStringByBerryType(berry, gStringVar1, gSpecialVar_0x8006);
}

void ObjectEventInteractionGetBerryName(void)
{
    u8 berryType = GetBerryTypeByBerryTreeId(GetObjectEventBerryTreeId(gSelectedObjectEvent));
    GetBerryNameByBerryType(berryType, gStringVar1);
}

void ObjectEventInteractionGetBerryCountString(void)
{
    u8 treeId = GetObjectEventBerryTreeId(gSelectedObjectEvent);
    u8 berry = GetBerryTypeByBerryTreeId(treeId);
    u8 count = GetBerryCountByBerryTreeId(treeId);
    GetBerryCountStringByBerryType(berry, gStringVar1, count);
}

void Bag_ChooseBerry(void)
{
    SetMainCallback2(CB2_ChooseBerry);
}

void ObjectEventInteractionPlantBerryTree(void)
{
    u8 berry = ItemIdToBerryType(gSpecialVar_ItemId);

    PlantBerryTree(GetObjectEventBerryTreeId(gSelectedObjectEvent), berry, BERRY_STAGE_PLANTED, TRUE);
    ObjectEventInteractionGetBerryTreeData();
}

void ObjectEventInteractionPickBerryTree(void)
{
    u8 id = GetObjectEventBerryTreeId(gSelectedObjectEvent);
    u8 berry = GetBerryTypeByBerryTreeId(id);

    gSpecialVar_0x8004 = AddBagItem(BerryTypeToItemId(berry), GetBerryCountByBerryTreeId(id));
}

void ObjectEventInteractionRemoveBerryTree(void)
{
    RemoveBerryTree(GetObjectEventBerryTreeId(gSelectedObjectEvent));
    SetBerryTreeJustPicked(gSpecialVar_LastTalked, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup);
}

bool8 PlayerHasBerries(void)
{
    return IsBagPocketNonEmpty(POCKET_BERRIES);
}

// Berry tree growth is frozen at their initial stage (usually, fully grown) until the player has seen the tree
// For all berry trees on screen, allow normal growth
void SetBerryTreesSeen(void)
{
    s16 cam_left;
    s16 cam_top;
    s16 left;
    s16 top;
    s16 right;
    s16 bottom;
    int i;

    GetCameraCoords(&cam_left, &cam_top);
    left = cam_left;
    top = cam_top + 3;
    right = cam_left + 14;
    bottom = top + 8;
    for (i = 0; i < OBJECT_EVENTS_COUNT; i++)
    {
        if (gObjectEvents[i].active && gObjectEvents[i].movementType == MOVEMENT_TYPE_BERRY_TREE_GROWTH)
        {
            cam_left = gObjectEvents[i].currentCoords.x;
            cam_top = gObjectEvents[i].currentCoords.y;
            if (left <= cam_left && cam_left <= right && top <= cam_top && cam_top <= bottom)
                AllowBerryTreeGrowth(gObjectEvents[i].trainerRange_berryTreeId);
        }
    }
}

// BEGIN GENERATED LOCALIZATION EXPORTS
// These pointers expose file-local translated strings to the runtime resolver.
const u8 *const gLocalizationSource_C00493 = sBerryDescriptionPart1_Cheri;
const u8 *const gLocalizationSource_C00494 = sBerryDescriptionPart2_Cheri;
const u8 *const gLocalizationSource_C00495 = sBerryDescriptionPart1_Chesto;
const u8 *const gLocalizationSource_C00496 = sBerryDescriptionPart2_Chesto;
const u8 *const gLocalizationSource_C00497 = sBerryDescriptionPart1_Pecha;
const u8 *const gLocalizationSource_C00498 = sBerryDescriptionPart2_Pecha;
const u8 *const gLocalizationSource_C00499 = sBerryDescriptionPart1_Rawst;
const u8 *const gLocalizationSource_C00500 = sBerryDescriptionPart2_Rawst;
const u8 *const gLocalizationSource_C00501 = sBerryDescriptionPart1_Aspear;
const u8 *const gLocalizationSource_C00502 = sBerryDescriptionPart2_Aspear;
const u8 *const gLocalizationSource_C00503 = sBerryDescriptionPart1_Leppa;
const u8 *const gLocalizationSource_C00504 = sBerryDescriptionPart2_Leppa;
const u8 *const gLocalizationSource_C00505 = sBerryDescriptionPart1_Oran;
const u8 *const gLocalizationSource_C00506 = sBerryDescriptionPart2_Oran;
const u8 *const gLocalizationSource_C00507 = sBerryDescriptionPart1_Persim;
const u8 *const gLocalizationSource_C00508 = sBerryDescriptionPart2_Persim;
const u8 *const gLocalizationSource_C00509 = sBerryDescriptionPart1_Lum;
const u8 *const gLocalizationSource_C00510 = sBerryDescriptionPart2_Lum;
const u8 *const gLocalizationSource_C00511 = sBerryDescriptionPart1_Sitrus;
const u8 *const gLocalizationSource_C00512 = sBerryDescriptionPart2_Sitrus;
const u8 *const gLocalizationSource_C00513 = sBerryDescriptionPart1_Figy;
const u8 *const gLocalizationSource_C00514 = sBerryDescriptionPart2_Figy;
const u8 *const gLocalizationSource_C00515 = sBerryDescriptionPart1_Wiki;
const u8 *const gLocalizationSource_C00516 = sBerryDescriptionPart2_Wiki;
const u8 *const gLocalizationSource_C00517 = sBerryDescriptionPart1_Mago;
const u8 *const gLocalizationSource_C00518 = sBerryDescriptionPart2_Mago;
const u8 *const gLocalizationSource_C00519 = sBerryDescriptionPart1_Aguav;
const u8 *const gLocalizationSource_C00520 = sBerryDescriptionPart2_Aguav;
const u8 *const gLocalizationSource_C00521 = sBerryDescriptionPart1_Iapapa;
const u8 *const gLocalizationSource_C00522 = sBerryDescriptionPart2_Iapapa;
const u8 *const gLocalizationSource_C00523 = sBerryDescriptionPart1_Razz;
const u8 *const gLocalizationSource_C00524 = sBerryDescriptionPart2_Razz;
const u8 *const gLocalizationSource_C00525 = sBerryDescriptionPart1_Bluk;
const u8 *const gLocalizationSource_C00526 = sBerryDescriptionPart2_Bluk;
const u8 *const gLocalizationSource_C00527 = sBerryDescriptionPart1_Nanab;
const u8 *const gLocalizationSource_C00528 = sBerryDescriptionPart2_Nanab;
const u8 *const gLocalizationSource_C00529 = sBerryDescriptionPart1_Wepear;
const u8 *const gLocalizationSource_C00530 = sBerryDescriptionPart2_Wepear;
const u8 *const gLocalizationSource_C00531 = sBerryDescriptionPart1_Pinap;
const u8 *const gLocalizationSource_C00532 = sBerryDescriptionPart2_Pinap;
const u8 *const gLocalizationSource_C00533 = sBerryDescriptionPart1_Pomeg;
const u8 *const gLocalizationSource_C00534 = sBerryDescriptionPart2_Pomeg;
const u8 *const gLocalizationSource_C00535 = sBerryDescriptionPart1_Kelpsy;
const u8 *const gLocalizationSource_C00536 = sBerryDescriptionPart2_Kelpsy;
const u8 *const gLocalizationSource_C00537 = sBerryDescriptionPart1_Qualot;
const u8 *const gLocalizationSource_C00538 = sBerryDescriptionPart2_Qualot;
const u8 *const gLocalizationSource_C00539 = sBerryDescriptionPart1_Hondew;
const u8 *const gLocalizationSource_C00540 = sBerryDescriptionPart2_Hondew;
const u8 *const gLocalizationSource_C00541 = sBerryDescriptionPart1_Grepa;
const u8 *const gLocalizationSource_C00542 = sBerryDescriptionPart2_Grepa;
const u8 *const gLocalizationSource_C00543 = sBerryDescriptionPart1_Tamato;
const u8 *const gLocalizationSource_C00544 = sBerryDescriptionPart2_Tamato;
const u8 *const gLocalizationSource_C00545 = sBerryDescriptionPart1_Cornn;
const u8 *const gLocalizationSource_C00546 = sBerryDescriptionPart2_Cornn;
const u8 *const gLocalizationSource_C00547 = sBerryDescriptionPart1_Magost;
const u8 *const gLocalizationSource_C00548 = sBerryDescriptionPart2_Magost;
const u8 *const gLocalizationSource_C00549 = sBerryDescriptionPart1_Rabuta;
const u8 *const gLocalizationSource_C00550 = sBerryDescriptionPart2_Rabuta;
const u8 *const gLocalizationSource_C00551 = sBerryDescriptionPart1_Nomel;
const u8 *const gLocalizationSource_C00552 = sBerryDescriptionPart2_Nomel;
const u8 *const gLocalizationSource_C00553 = sBerryDescriptionPart1_Spelon;
const u8 *const gLocalizationSource_C00554 = sBerryDescriptionPart2_Spelon;
const u8 *const gLocalizationSource_C00555 = sBerryDescriptionPart1_Pamtre;
const u8 *const gLocalizationSource_C00556 = sBerryDescriptionPart2_Pamtre;
const u8 *const gLocalizationSource_C00557 = sBerryDescriptionPart1_Watmel;
const u8 *const gLocalizationSource_C00558 = sBerryDescriptionPart2_Watmel;
const u8 *const gLocalizationSource_C00559 = sBerryDescriptionPart1_Durin;
const u8 *const gLocalizationSource_C00560 = sBerryDescriptionPart2_Durin;
const u8 *const gLocalizationSource_C00561 = sBerryDescriptionPart1_Belue;
const u8 *const gLocalizationSource_C00562 = sBerryDescriptionPart2_Belue;
const u8 *const gLocalizationSource_C00563 = sBerryDescriptionPart1_Liechi;
const u8 *const gLocalizationSource_C00564 = sBerryDescriptionPart2_Liechi;
const u8 *const gLocalizationSource_C00565 = sBerryDescriptionPart1_Ganlon;
const u8 *const gLocalizationSource_C00566 = sBerryDescriptionPart2_Ganlon;
const u8 *const gLocalizationSource_C00567 = sBerryDescriptionPart1_Salac;
const u8 *const gLocalizationSource_C00568 = sBerryDescriptionPart2_Salac;
const u8 *const gLocalizationSource_C00569 = sBerryDescriptionPart1_Petaya;
const u8 *const gLocalizationSource_C00570 = sBerryDescriptionPart2_Petaya;
const u8 *const gLocalizationSource_C00571 = sBerryDescriptionPart1_Apicot;
const u8 *const gLocalizationSource_C00572 = sBerryDescriptionPart2_Apicot;
const u8 *const gLocalizationSource_C00573 = sBerryDescriptionPart1_Lansat;
const u8 *const gLocalizationSource_C00574 = sBerryDescriptionPart2_Lansat;
const u8 *const gLocalizationSource_C00575 = sBerryDescriptionPart1_Starf;
const u8 *const gLocalizationSource_C00576 = sBerryDescriptionPart2_Starf;
const u8 *const gLocalizationSource_C00577 = sBerryDescriptionPart1_Enigma;
const u8 *const gLocalizationSource_C00578 = sBerryDescriptionPart2_Enigma;
// END GENERATED LOCALIZATION EXPORTS
