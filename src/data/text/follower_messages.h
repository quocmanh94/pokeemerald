extern const u8 EventScript_FollowerIsShivering[];
extern const u8 EventScript_FollowerNostalgia[];
extern const u8 EventScript_FollowerHopping[];
extern const u8 EventScript_FollowerJumpOnPlayer[];
extern const u8 EventScript_FollowerCuddling[];
extern const u8 EventScript_FollowerShiverCuddling[];
extern const u8 EventScript_FollowerGetCloser[];
extern const u8 EventScript_FollowerPokingPlayer[];
extern const u8 EventScript_FollowerLookAround[];
extern const u8 EventScript_FollowerLookAway[];
extern const u8 EventScript_FollowerLookAwayBark[];
extern const u8 EventScript_FollowerLookAwayPoke[];
extern const u8 EventScript_FollowerPokeGround[];
extern const u8 EventScript_FollowerStartled[];
extern const u8 EventScript_FollowerFastHopping[];
extern const u8 EventScript_FollowerDizzy[];
extern const u8 EventScript_FollowerLookAroundScared[];
extern const u8 EventScript_FollowerDance[];
extern const u8 EventScript_FollowerLookUp[];

// 'Generic', unconditional happy messages
static const u8 sHappyMsg00[] = _("{STR_VAR_1} bắt đầu chọc vào bụng bạn.");
static const u8 sHappyMsg01[] = _("{STR_VAR_1} vui vẻ nhưng hơi ngượng.");
static const u8 sHappyMsg02[] = _("{STR_VAR_1} vui vẻ đi cùng bạn.");
static const u8 sHappyMsg03[] = _("{STR_VAR_1} rất điềm tĩnh.");
static const u8 sHappyMsg04[] = _("{STR_VAR_1} có vẻ rất vui\nkhi đi cùng bạn!");
static const u8 sHappyMsg05[] = _("{STR_VAR_1} tràn đầy sức sống.");
static const u8 sHappyMsg06[] = _("{STR_VAR_1} trông rất vui.");
static const u8 sHappyMsg07[] = _("{STR_VAR_1} đang cố gắng hơn nữa.");
static const u8 sHappyMsg08[] = _("{STR_VAR_1} đang ngửi hương thơm\ntrong không khí xung quanh.");
static const u8 sHappyMsg09[] = _("{STR_VAR_1} nhảy cẫng lên vì vui!");
static const u8 sHappyMsg10[] = _("{STR_VAR_1} vẫn đang rất phấn chấn!");
static const u8 sHappyMsg11[] = _("POKéMON của bạn ngửi thấy\nmùi khói.");
static const u8 sHappyMsg12[] = _("{STR_VAR_1} đang chọc vào bụng bạn.");
static const u8 sHappyMsg13[] = _("POKéMON của bạn duỗi người\nvà thư giãn.");
static const u8 sHappyMsg14[] = _("{STR_VAR_1} có vẻ muốn đi trước!");
static const u8 sHappyMsg15[] = _("{STR_VAR_1} đang cố hết sức\nđể theo kịp bạn.");
static const u8 sHappyMsg16[] = _("{STR_VAR_1} vui vẻ nép vào bạn!");
static const u8 sHappyMsg17[] = _("{STR_VAR_1} tràn đầy sinh lực!");
static const u8 sHappyMsg18[] = _("{STR_VAR_1} có vẻ rất vui!");
static const u8 sHappyMsg19[] = _("{STR_VAR_1} vui đến mức\nkhông thể đứng yên!");
static const u8 sHappyMsg20[] = _("{STR_VAR_1} chậm rãi gật đầu.");
static const u8 sHappyMsg21[] = _("{STR_VAR_1} rất háo hức!");
static const u8 sHappyMsg22[] = _("{STR_VAR_1} đi quanh và lắng nghe\nnhững âm thanh khác nhau.");
static const u8 sHappyMsg23[] = _("{STR_VAR_1} trông rất hứng thú.");
static const u8 sHappyMsg24[] = _("{STR_VAR_1} đang gắng gượng\nđể tiếp tục đi.");
static const u8 sHappyMsg25[] = _("{STR_VAR_1} nhìn bạn đầy rạng rỡ!");
static const u8 sHappyMsg26[] = _("{STR_VAR_1} vui vẻ nhìn bạn\nvà mỉm cười.");
static const u8 sHappyMsg27[] = _("POKéMON của bạn đang ngửi\nhương hoa.");
static const u8 sHappyMsg28[] = _("{STR_VAR_1} có vẻ rất vui khi gặp bạn!");
static const u8 sHappyMsg29[] = _("{STR_VAR_1} quay lại và nhe răng cười.");
static const u8 sHappyMsg30[] = _("{STR_VAR_1} vui vẻ nép vào bạn!");
// Conditional messages begin here, index 31
static const u8 sHappyMsg31[] = _("POKéMON của bạn có vẻ vui\nvì thời tiết đẹp.");
static const u8 sHappyMsg32[] = _("{STR_VAR_1} rất điềm tĩnh\nvà đầy tự tin!");

const struct FollowerMsgInfo gFollowerHappyMessages[] = {
    {sHappyMsg00, EventScript_FollowerPokingPlayer},
    {sHappyMsg01}, {sHappyMsg02}, {sHappyMsg03}, {sHappyMsg04}, {sHappyMsg05}, {sHappyMsg06}, {sHappyMsg07},
    {sHappyMsg08, EventScript_FollowerLookAround},
    {sHappyMsg09, EventScript_FollowerHopping},
    {sHappyMsg10}, {sHappyMsg11},
    {sHappyMsg12, EventScript_FollowerPokingPlayer},
    {sHappyMsg13, EventScript_FollowerLookAround},
    {sHappyMsg14}, {sHappyMsg15},
    {sHappyMsg16, EventScript_FollowerCuddling},
    {sHappyMsg17}, {sHappyMsg18},
    {sHappyMsg19, EventScript_FollowerFastHopping},
    {sHappyMsg20}, {sHappyMsg21}, {sHappyMsg22}, {sHappyMsg23}, {sHappyMsg24}, {sHappyMsg25}, {sHappyMsg26}, {sHappyMsg27}, {sHappyMsg28}, {sHappyMsg29},
    {sHappyMsg30, EventScript_FollowerCuddling},
    {sHappyMsg31}, {sHappyMsg32},
};

// Unconditional neutral messages
static const u8 sNeutralMsg00[] = _("{STR_VAR_1} đang đều đặn chọc đất.");
static const u8 sNeutralMsg01[] = _("{STR_VAR_1} đang đứng canh gác.");
static const u8 sNeutralMsg02[] = _("{STR_VAR_1} kiên nhẫn nhìn\nvào khoảng không.");
static const u8 sNeutralMsg03[] = _("{STR_VAR_1} đang đi quanh.");
static const u8 sNeutralMsg04[] = _("POKéMON của bạn ngáp thật to!");
static const u8 sNeutralMsg05[] = _("POKéMON của bạn bồn chồn\nnhìn quanh.");
static const u8 sNeutralMsg06[] = _("{STR_VAR_1} nhìn về phía này\nvà mỉm cười.");
static const u8 sNeutralMsg07[] = _("{STR_VAR_1} bồn chồn nhìn quanh.");
static const u8 sNeutralMsg08[] = _("{STR_VAR_1} cất tiếng thét xung trận.");
static const u8 sNeutralMsg09[] = _("{STR_VAR_1} biểu diễn một\nđiệu nhảy tuyệt đẹp!");
static const u8 sNeutralMsg10[] = _("{STR_VAR_1} rất háo hức.");
static const u8 sNeutralMsg11[] = _("{STR_VAR_1} chăm chú nhìn\nvề phía xa.");
static const u8 sNeutralMsg12[] = _("{STR_VAR_1} đang cảnh giác!");
static const u8 sNeutralMsg13[] = _("{STR_VAR_1} nhìn về phía xa\nrồi sủa lên!");

const struct FollowerMsgInfo gFollowerNeutralMessages[] = {
    {sNeutralMsg00, EventScript_FollowerPokeGround},
    {sNeutralMsg01},
    {sNeutralMsg02, EventScript_FollowerLookAway},
    {sNeutralMsg03, EventScript_FollowerLookAround},
    {sNeutralMsg04},
    {sNeutralMsg05, EventScript_FollowerLookAround},
    {sNeutralMsg06}, {sNeutralMsg07}, {sNeutralMsg08},
    {sNeutralMsg09, EventScript_FollowerDance},
    {sNeutralMsg10},
    {sNeutralMsg11, EventScript_FollowerLookAway},
    {sNeutralMsg12},
    {sNeutralMsg13, EventScript_FollowerLookAwayBark},
};

// Unconditional sad messages
static const u8 sSadMsg00[] = _("{STR_VAR_1} đang chóng mặt.");
static const u8 sSadMsg01[] = _("{STR_VAR_1} đang giẫm lên chân bạn!");
static const u8 sSadMsg02[] = _("{STR_VAR_1} có vẻ hơi mệt.");
// Conditional messages begin, index 3
static const u8 sSadMsg03[] = _("{STR_VAR_1} không vui.");
static const u8 sSadMsg04[] = _("{STR_VAR_1} sắp ngã!\n");
static const u8 sSadMsg05[] = _("{STR_VAR_1} có vẻ sắp ngã!");
static const u8 sSadMsg06[] = _("{STR_VAR_1} đang cố hết sức\nđể theo kịp bạn…");
static const u8 sSadMsg07[] = _("{STR_VAR_1} đang lo lắng.");

const struct FollowerMsgInfo gFollowerSadMessages[] = {
    {sSadMsg00, EventScript_FollowerDizzy},
    {sSadMsg01}, {sSadMsg02},
    {sSadMsg03}, {sSadMsg04}, {sSadMsg05}, {sSadMsg06}, {sSadMsg07},
};

// Unconditional upset messages
static const u8 sUpsetMsg00[] = _("{STR_VAR_1} có vẻ không vui…");
static const u8 sUpsetMsg01[] = _("{STR_VAR_1} đang tỏ vẻ buồn bực.");
static const u8 sUpsetMsg02[] = _("…POKéMON của bạn có vẻ\nhơi lạnh.");
// Conditional messages, index 3
static const u8 sUpsetMsg03[] = _("{STR_VAR_1} đang trú mưa\ntrong bụi cỏ.");

const struct FollowerMsgInfo gFollowerUpsetMessages[] = {
    {sUpsetMsg00}, {sUpsetMsg01},
    {sUpsetMsg02, EventScript_FollowerIsShivering},
    {sUpsetMsg03},
};

// Unconditional angry messages
static const u8 sAngryMsg00[] = _("{STR_VAR_1} gầm lên!");
static const u8 sAngryMsg01[] = _("{STR_VAR_1} đang tỏ vẻ giận dữ!");
static const u8 sAngryMsg02[] = _("{STR_VAR_1} có vẻ đang giận\nvì lý do nào đó.");
static const u8 sAngryMsg03[] = _("POKéMON của bạn quay mặt đi,\ntỏ vẻ chống đối.");
static const u8 sAngryMsg04[] = _("{STR_VAR_1} kêu lên.");

const struct FollowerMsgInfo gFollowerAngryMessages[] = {
    {sAngryMsg00}, {sAngryMsg01}, {sAngryMsg02},
    {sAngryMsg03, EventScript_FollowerLookAway},
    {sAngryMsg04},
};

// Unconditional pensive messages
static const u8 sPensiveMsg00[] = _("{STR_VAR_1} đang chăm chú nhìn xuống.");
static const u8 sPensiveMsg01[] = _("{STR_VAR_1} đang quan sát xung quanh.");
static const u8 sPensiveMsg02[] = _("{STR_VAR_1} đang cúi xuống nhìn.");
static const u8 sPensiveMsg03[] = _("{STR_VAR_1} đang cố chống lại\ncơn buồn ngủ…");
static const u8 sPensiveMsg04[] = _("{STR_VAR_1} có vẻ đang đi loanh quanh.");
static const u8 sPensiveMsg05[] = _("{STR_VAR_1} đang lơ đãng nhìn quanh.");
static const u8 sPensiveMsg06[] = _("{STR_VAR_1} ngáp thật to!");
static const u8 sPensiveMsg07[] = _("{STR_VAR_1} đang thư giãn thoải mái.");
static const u8 sPensiveMsg08[] = _("{STR_VAR_1} kiên định nhìn\nvào mặt bạn.");
static const u8 sPensiveMsg09[] = _("{STR_VAR_1} chăm chú nhìn\nvào mặt bạn.");
static const u8 sPensiveMsg10[] = _("{STR_VAR_1} đang tập trung\nchú ý vào bạn.");
static const u8 sPensiveMsg11[] = _("{STR_VAR_1} đang nhìn vào vực sâu.");
static const u8 sPensiveMsg12[] = _("{STR_VAR_1} đang ngửi mặt đất.");
static const u8 sPensiveMsg13[] = _("POKéMON của bạn chăm chú nhìn\nvào khoảng không.");
static const u8 sPensiveMsg14[] = _("{STR_VAR_1} tập trung với\nánh mắt sắc bén!");
static const u8 sPensiveMsg15[] = _("{STR_VAR_1} đang tập trung.");
static const u8 sPensiveMsg16[] = _("{STR_VAR_1} quay lại và gật đầu.");
static const u8 sPensiveMsg17[] = _("{STR_VAR_1} có vẻ hơi lo lắng…");
static const u8 sPensiveMsg18[] = _("{STR_VAR_1} đang nhìn dấu chân bạn.");
static const u8 sPensiveMsg19[] = _("{STR_VAR_1} nhìn thẳng vào mắt bạn.");

const struct FollowerMsgInfo gFollowerPensiveMessages[] = {
    {sPensiveMsg00},
    {sPensiveMsg01, EventScript_FollowerLookAround},
    {sPensiveMsg02}, {sPensiveMsg03}, {sPensiveMsg04},
    {sPensiveMsg05, EventScript_FollowerLookAround},
    {sPensiveMsg06}, {sPensiveMsg07}, {sPensiveMsg08}, {sPensiveMsg09}, {sPensiveMsg10},
    {sPensiveMsg11, EventScript_FollowerLookAway},
    {sPensiveMsg12, EventScript_FollowerPokeGround},
    {sPensiveMsg13, EventScript_FollowerLookAway},
    {sPensiveMsg14}, {sPensiveMsg15}, {sPensiveMsg16}, {sPensiveMsg17}, {sPensiveMsg18}, {sPensiveMsg19},
};

// All 'love' messages are unconditional
static const u8 sLoveMsg00[] = _("{STR_VAR_1} bỗng bước lại gần bạn!");
static const u8 sLoveMsg01[] = _("Má {STR_VAR_1} đang ửng hồng!");
static const u8 sLoveMsg02[] = _("Ôi! {STR_VAR_1} bỗng ôm lấy bạn!");
static const u8 sLoveMsg03[] = _("Ôi! {STR_VAR_1} bỗng muốn đùa giỡn!");
static const u8 sLoveMsg04[] = _("{STR_VAR_1} đang cọ vào chân bạn!");
static const u8 sLoveMsg05[] = _("{STR_VAR_1} đỏ mặt.");
static const u8 sLoveMsg06[] = _("A! {STR_VAR_1} nép vào bạn!");
static const u8 sLoveMsg07[] = _("{STR_VAR_1} nhìn bạn đầy yêu mến!");
static const u8 sLoveMsg08[] = _("{STR_VAR_1} tiến lại gần bạn.");
static const u8 sLoveMsg09[] = _("{STR_VAR_1} bám sát bên chân bạn.");

const struct FollowerMsgInfo gFollowerLoveMessages[] = {
    {sLoveMsg00, EventScript_FollowerGetCloser},
    {sLoveMsg01},
    {sLoveMsg02, EventScript_FollowerCuddling},
    {sLoveMsg03},
    {sLoveMsg04, EventScript_FollowerCuddling},
    {sLoveMsg05},
    {sLoveMsg06, EventScript_FollowerCuddling},
    {sLoveMsg07},
    {sLoveMsg08, EventScript_FollowerGetCloser},
    {sLoveMsg09},
};

// Unconditional surprised messages
static const u8 sSurpriseMsg00[] = _("{STR_VAR_1} sắp ngã!");
static const u8 sSurpriseMsg01[] = _("{STR_VAR_1} va vào bạn!");
static const u8 sSurpriseMsg02[] = _("{STR_VAR_1} có vẻ chưa quen\nvới tên của mình.");
static const u8 sSurpriseMsg03[] = _("{STR_VAR_1} đang cúi xuống nhìn.");
static const u8 sSurpriseMsg04[] = _("POKéMON của bạn loạng choạng\nvà suýt ngã!");
static const u8 sSurpriseMsg05[] = _("{STR_VAR_1} cảm thấy gì đó\nvà tru lên!");
static const u8 sSurpriseMsg06[] = _("{STR_VAR_1} có vẻ tỉnh táo hơn!");
static const u8 sSurpriseMsg07[] = _("{STR_VAR_1} bỗng quay lại\nvà sủa lên!");
static const u8 sSurpriseMsg08[] = _("{STR_VAR_1} bỗng quay lại!");
static const u8 sSurpriseMsg09[] = _("POKéMON của bạn giật mình\nkhi bạn bất ngờ lên tiếng!");
static const u8 sSurpriseMsg10[] = _("Khịt khịt, có gì đó thơm quá!");
static const u8 sSurpriseMsg11[] = _("{STR_VAR_1} cảm thấy khoan khoái.");
static const u8 sSurpriseMsg12[] = _("{STR_VAR_1} đang loạng choạng\nvà có vẻ sắp ngã.");
static const u8 sSurpriseMsg13[] = _("{STR_VAR_1} có nguy cơ bị ngã.");
static const u8 sSurpriseMsg14[] = _("{STR_VAR_1} đang thận trọng bước đi.");
static const u8 sSurpriseMsg15[] = _("{STR_VAR_1} căng thẳng vì lo lắng.");
static const u8 sSurpriseMsg16[] = _("{STR_VAR_1} cảm nhận điều lạ\nvà giật mình!");
static const u8 sSurpriseMsg17[] = _("{STR_VAR_1} sợ hãi nép vào bạn!");
static const u8 sSurpriseMsg18[] = _("{STR_VAR_1} cảm nhận một\nsự hiện diện khác thường…");
static const u8 sSurpriseMsg19[] = _("{STR_VAR_1} căng thẳng vì lo lắng.");
// Conditional messages, index 20
static const u8 sSurpriseMsg20[] = _("{STR_VAR_1} có vẻ rất ngạc nhiên\nvì trời đang mưa!");

const struct FollowerMsgInfo gFollowerSurpriseMessages[] = {
    {sSurpriseMsg00},
    {sSurpriseMsg01, EventScript_FollowerPokingPlayer},
    {sSurpriseMsg02}, {sSurpriseMsg03}, {sSurpriseMsg04}, {sSurpriseMsg05}, {sSurpriseMsg06},
    {sSurpriseMsg07, EventScript_FollowerLookAwayBark},
    {sSurpriseMsg08, EventScript_FollowerLookAway},
    {sSurpriseMsg09},
    {sSurpriseMsg10, EventScript_FollowerLookAround},
    {sSurpriseMsg11}, {sSurpriseMsg12}, {sSurpriseMsg13}, {sSurpriseMsg14}, {sSurpriseMsg15}, {sSurpriseMsg16},
    {sSurpriseMsg17, EventScript_FollowerCuddling},
    {sSurpriseMsg18},
    {sSurpriseMsg19, EventScript_FollowerLookAround},
    {sSurpriseMsg20},
};

// Unconditional curious messages
static const u8 sCuriousMsg00[] = _("POKéMON của bạn bồn chồn\ntìm kiếm thứ gì đó.");
static const u8 sCuriousMsg01[] = _("POKéMON của bạn không để ý\nvà đâm vào bạn!");
static const u8 sCuriousMsg02[] = _("Khịt, khịt! Có gì gần đây sao?");
static const u8 sCuriousMsg03[] = _("{STR_VAR_1} tinh nghịch lăn\nmột viên sỏi.");
static const u8 sCuriousMsg04[] = _("{STR_VAR_1} đi quanh\nvà tìm kiếm thứ gì đó.");
static const u8 sCuriousMsg05[] = _("{STR_VAR_1} đang ngửi bạn.");
static const u8 sCuriousMsg06[] = _("{STR_VAR_1} có vẻ hơi do dự…");

const struct FollowerMsgInfo gFollowerCuriousMessages[] = {
    {sCuriousMsg00, EventScript_FollowerLookAround},
    {sCuriousMsg01, EventScript_FollowerPokingPlayer},
    {sCuriousMsg02}, {sCuriousMsg03},
    {sCuriousMsg04, EventScript_FollowerLookAround},
    {sCuriousMsg05}, {sCuriousMsg06},
};

// Unconditional music messages
static const u8 sMusicMsg00[] = _("{STR_VAR_1} đang khoe sự nhanh nhẹn!");
static const u8 sMusicMsg01[] = _("{STR_VAR_1} vui vẻ chạy quanh!");
static const u8 sMusicMsg02[] = _("Ôi! {STR_VAR_1} bỗng vui vẻ\nnhảy múa!");
static const u8 sMusicMsg03[] = _("{STR_VAR_1} đang đều bước theo bạn!");
static const u8 sMusicMsg04[] = _("{STR_VAR_1} có vẻ muốn chơi với bạn.");
static const u8 sMusicMsg05[] = _("{STR_VAR_1} vui vẻ nhảy chân sáo.");
static const u8 sMusicMsg06[] = _("{STR_VAR_1} vừa hát vừa ngân nga.");
static const u8 sMusicMsg07[] = _("{STR_VAR_1} đang cắn nhẹ chân bạn!");
static const u8 sMusicMsg08[] = _("{STR_VAR_1} quay lại nhìn bạn.");
static const u8 sMusicMsg09[] = _("{STR_VAR_1} đang cố khoe\nsức mạnh phi thường!");
static const u8 sMusicMsg10[] = _("Ôi! {STR_VAR_1} bỗng vui vẻ\nnhảy múa!");
static const u8 sMusicMsg11[] = _("{STR_VAR_1} rất vui vẻ!");
static const u8 sMusicMsg12[] = _("{STR_VAR_1} vô tư nhảy nhót!");
static const u8 sMusicMsg13[] = _("POKéMON của bạn ngửi thấy\nmùi hương thân thuộc xa xưa…");
// Conditional music messages, index 14
static const u8 sMusicMsg14[] = _("{STR_VAR_1} rất vui vì trời mưa.");

const struct FollowerMsgInfo gFollowerMusicMessages[] = {
    {sMusicMsg00, EventScript_FollowerLookAround},
    {sMusicMsg01},
    {sMusicMsg02, EventScript_FollowerDance},
    {sMusicMsg03},
    {sMusicMsg04, EventScript_FollowerHopping},
    {sMusicMsg05, EventScript_FollowerHopping},
    {sMusicMsg06}, {sMusicMsg07}, {sMusicMsg08}, {sMusicMsg09},
    {sMusicMsg10, EventScript_FollowerDance},
    {sMusicMsg11},
    {sMusicMsg12, EventScript_FollowerHopping},
    {sMusicMsg13, EventScript_FollowerNostalgia},
    {sMusicMsg14}
};


static const u8 sPoisonedMsg00[] = _("{STR_VAR_1} đang run rẩy\nvì bị trúng độc.");

const struct FollowerMsgInfo gFollowerPoisonedMessages[] = {
    {sPoisonedMsg00, EventScript_FollowerIsShivering},
};

// BEGIN GENERATED LOCALIZATION EXPORTS
// These pointers expose file-local translated strings to the runtime resolver.
const u8 *const gLocalizationSource_C01245 = sHappyMsg00;
const u8 *const gLocalizationSource_C01246 = sHappyMsg01;
const u8 *const gLocalizationSource_C01247 = sHappyMsg02;
const u8 *const gLocalizationSource_C01248 = sHappyMsg03;
const u8 *const gLocalizationSource_C01249 = sHappyMsg04;
const u8 *const gLocalizationSource_C01250 = sHappyMsg05;
const u8 *const gLocalizationSource_C01251 = sHappyMsg06;
const u8 *const gLocalizationSource_C01252 = sHappyMsg07;
const u8 *const gLocalizationSource_C01253 = sHappyMsg08;
const u8 *const gLocalizationSource_C01254 = sHappyMsg09;
const u8 *const gLocalizationSource_C01255 = sHappyMsg10;
const u8 *const gLocalizationSource_C01256 = sHappyMsg11;
const u8 *const gLocalizationSource_C01257 = sHappyMsg12;
const u8 *const gLocalizationSource_C01258 = sHappyMsg13;
const u8 *const gLocalizationSource_C01259 = sHappyMsg14;
const u8 *const gLocalizationSource_C01260 = sHappyMsg15;
const u8 *const gLocalizationSource_C01261 = sHappyMsg16;
const u8 *const gLocalizationSource_C01262 = sHappyMsg17;
const u8 *const gLocalizationSource_C01263 = sHappyMsg18;
const u8 *const gLocalizationSource_C01264 = sHappyMsg19;
const u8 *const gLocalizationSource_C01265 = sHappyMsg20;
const u8 *const gLocalizationSource_C01266 = sHappyMsg21;
const u8 *const gLocalizationSource_C01267 = sHappyMsg22;
const u8 *const gLocalizationSource_C01268 = sHappyMsg23;
const u8 *const gLocalizationSource_C01269 = sHappyMsg24;
const u8 *const gLocalizationSource_C01270 = sHappyMsg25;
const u8 *const gLocalizationSource_C01271 = sHappyMsg26;
const u8 *const gLocalizationSource_C01272 = sHappyMsg27;
const u8 *const gLocalizationSource_C01273 = sHappyMsg28;
const u8 *const gLocalizationSource_C01274 = sHappyMsg29;
const u8 *const gLocalizationSource_C01275 = sHappyMsg30;
const u8 *const gLocalizationSource_C01276 = sHappyMsg31;
const u8 *const gLocalizationSource_C01277 = sHappyMsg32;
const u8 *const gLocalizationSource_C01278 = sNeutralMsg00;
const u8 *const gLocalizationSource_C01279 = sNeutralMsg01;
const u8 *const gLocalizationSource_C01280 = sNeutralMsg02;
const u8 *const gLocalizationSource_C01281 = sNeutralMsg03;
const u8 *const gLocalizationSource_C01282 = sNeutralMsg04;
const u8 *const gLocalizationSource_C01283 = sNeutralMsg05;
const u8 *const gLocalizationSource_C01284 = sNeutralMsg06;
const u8 *const gLocalizationSource_C01285 = sNeutralMsg07;
const u8 *const gLocalizationSource_C01286 = sNeutralMsg08;
const u8 *const gLocalizationSource_C01287 = sNeutralMsg09;
const u8 *const gLocalizationSource_C01288 = sNeutralMsg10;
const u8 *const gLocalizationSource_C01289 = sNeutralMsg11;
const u8 *const gLocalizationSource_C01290 = sNeutralMsg12;
const u8 *const gLocalizationSource_C01291 = sNeutralMsg13;
const u8 *const gLocalizationSource_C01292 = sSadMsg00;
const u8 *const gLocalizationSource_C01293 = sSadMsg01;
const u8 *const gLocalizationSource_C01294 = sSadMsg02;
const u8 *const gLocalizationSource_C01295 = sSadMsg03;
const u8 *const gLocalizationSource_C01296 = sSadMsg04;
const u8 *const gLocalizationSource_C01297 = sSadMsg05;
const u8 *const gLocalizationSource_C01298 = sSadMsg06;
const u8 *const gLocalizationSource_C01299 = sSadMsg07;
const u8 *const gLocalizationSource_C01300 = sUpsetMsg00;
const u8 *const gLocalizationSource_C01301 = sUpsetMsg01;
const u8 *const gLocalizationSource_C01302 = sUpsetMsg02;
const u8 *const gLocalizationSource_C01303 = sUpsetMsg03;
const u8 *const gLocalizationSource_C01304 = sAngryMsg00;
const u8 *const gLocalizationSource_C01305 = sAngryMsg01;
const u8 *const gLocalizationSource_C01306 = sAngryMsg02;
const u8 *const gLocalizationSource_C01307 = sAngryMsg03;
const u8 *const gLocalizationSource_C01308 = sAngryMsg04;
const u8 *const gLocalizationSource_C01309 = sPensiveMsg00;
const u8 *const gLocalizationSource_C01310 = sPensiveMsg01;
const u8 *const gLocalizationSource_C01311 = sPensiveMsg02;
const u8 *const gLocalizationSource_C01312 = sPensiveMsg03;
const u8 *const gLocalizationSource_C01313 = sPensiveMsg04;
const u8 *const gLocalizationSource_C01314 = sPensiveMsg05;
const u8 *const gLocalizationSource_C01315 = sPensiveMsg06;
const u8 *const gLocalizationSource_C01316 = sPensiveMsg07;
const u8 *const gLocalizationSource_C01317 = sPensiveMsg08;
const u8 *const gLocalizationSource_C01318 = sPensiveMsg09;
const u8 *const gLocalizationSource_C01319 = sPensiveMsg10;
const u8 *const gLocalizationSource_C01320 = sPensiveMsg11;
const u8 *const gLocalizationSource_C01321 = sPensiveMsg12;
const u8 *const gLocalizationSource_C01322 = sPensiveMsg13;
const u8 *const gLocalizationSource_C01323 = sPensiveMsg14;
const u8 *const gLocalizationSource_C01324 = sPensiveMsg15;
const u8 *const gLocalizationSource_C01325 = sPensiveMsg16;
const u8 *const gLocalizationSource_C01326 = sPensiveMsg17;
const u8 *const gLocalizationSource_C01327 = sPensiveMsg18;
const u8 *const gLocalizationSource_C01328 = sPensiveMsg19;
const u8 *const gLocalizationSource_C01329 = sLoveMsg00;
const u8 *const gLocalizationSource_C01330 = sLoveMsg01;
const u8 *const gLocalizationSource_C01331 = sLoveMsg02;
const u8 *const gLocalizationSource_C01332 = sLoveMsg03;
const u8 *const gLocalizationSource_C01333 = sLoveMsg04;
const u8 *const gLocalizationSource_C01334 = sLoveMsg05;
const u8 *const gLocalizationSource_C01335 = sLoveMsg06;
const u8 *const gLocalizationSource_C01336 = sLoveMsg07;
const u8 *const gLocalizationSource_C01337 = sLoveMsg08;
const u8 *const gLocalizationSource_C01338 = sLoveMsg09;
const u8 *const gLocalizationSource_C01339 = sSurpriseMsg00;
const u8 *const gLocalizationSource_C01340 = sSurpriseMsg01;
const u8 *const gLocalizationSource_C01341 = sSurpriseMsg02;
const u8 *const gLocalizationSource_C01342 = sSurpriseMsg03;
const u8 *const gLocalizationSource_C01343 = sSurpriseMsg04;
const u8 *const gLocalizationSource_C01344 = sSurpriseMsg05;
const u8 *const gLocalizationSource_C01345 = sSurpriseMsg06;
const u8 *const gLocalizationSource_C01346 = sSurpriseMsg07;
const u8 *const gLocalizationSource_C01347 = sSurpriseMsg08;
const u8 *const gLocalizationSource_C01348 = sSurpriseMsg09;
const u8 *const gLocalizationSource_C01349 = sSurpriseMsg10;
const u8 *const gLocalizationSource_C01350 = sSurpriseMsg11;
const u8 *const gLocalizationSource_C01351 = sSurpriseMsg12;
const u8 *const gLocalizationSource_C01352 = sSurpriseMsg13;
const u8 *const gLocalizationSource_C01353 = sSurpriseMsg14;
const u8 *const gLocalizationSource_C01354 = sSurpriseMsg15;
const u8 *const gLocalizationSource_C01355 = sSurpriseMsg16;
const u8 *const gLocalizationSource_C01356 = sSurpriseMsg17;
const u8 *const gLocalizationSource_C01357 = sSurpriseMsg18;
const u8 *const gLocalizationSource_C01358 = sSurpriseMsg19;
const u8 *const gLocalizationSource_C01359 = sSurpriseMsg20;
const u8 *const gLocalizationSource_C01360 = sCuriousMsg00;
const u8 *const gLocalizationSource_C01361 = sCuriousMsg01;
const u8 *const gLocalizationSource_C01362 = sCuriousMsg02;
const u8 *const gLocalizationSource_C01363 = sCuriousMsg03;
const u8 *const gLocalizationSource_C01364 = sCuriousMsg04;
const u8 *const gLocalizationSource_C01365 = sCuriousMsg05;
const u8 *const gLocalizationSource_C01366 = sCuriousMsg06;
const u8 *const gLocalizationSource_C01367 = sMusicMsg00;
const u8 *const gLocalizationSource_C01368 = sMusicMsg01;
const u8 *const gLocalizationSource_C01369 = sMusicMsg02;
const u8 *const gLocalizationSource_C01370 = sMusicMsg03;
const u8 *const gLocalizationSource_C01371 = sMusicMsg04;
const u8 *const gLocalizationSource_C01372 = sMusicMsg05;
const u8 *const gLocalizationSource_C01373 = sMusicMsg06;
const u8 *const gLocalizationSource_C01374 = sMusicMsg07;
const u8 *const gLocalizationSource_C01375 = sMusicMsg08;
const u8 *const gLocalizationSource_C01376 = sMusicMsg09;
const u8 *const gLocalizationSource_C01377 = sMusicMsg10;
const u8 *const gLocalizationSource_C01378 = sMusicMsg11;
const u8 *const gLocalizationSource_C01379 = sMusicMsg12;
const u8 *const gLocalizationSource_C01380 = sMusicMsg13;
const u8 *const gLocalizationSource_C01381 = sMusicMsg14;
const u8 *const gLocalizationSource_C01382 = sPoisonedMsg00;
// END GENERATED LOCALIZATION EXPORTS
