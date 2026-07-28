ALIGNED(4) static const u8 sText_EmptyString[] = _("");
ALIGNED(4) static const u8 sText_Colon[] = _(":");
ALIGNED(4) static const u8 sText_ID[] = _("{ID}");
ALIGNED(4) static const u8 sText_PleaseStartOver[] = _("Vui lòng bắt đầu lại từ đầu.");
ALIGNED(4) static const u8 sText_WirelessSearchCanceled[] = _("Đã hủy tìm kiếm bằng\nWIRELESS COMMUNICATION SYSTEM.");
ALIGNED(4) static const u8 sText_AwaitingCommunucation2[] = _("Đang chờ liên lạc\ntừ người chơi khác."); // Unused
ALIGNED(4) static const u8 sText_AwaitingCommunication[] = _("{STR_VAR_1}! Đang chờ liên lạc\ntừ người chơi khác.");
ALIGNED(4) static const u8 sText_AwaitingLinkPressStart[] = _("{STR_VAR_1}! Đang chờ kết nối!\nNhấn START khi mọi người sẵn sàng.");
ALIGNED(4) static const u8 sJPText_SingleBattle[] = _("シングルバトルを かいさいする");
ALIGNED(4) static const u8 sJPText_DoubleBattle[] = _("ダブルバトルを かいさいする");
ALIGNED(4) static const u8 sJPText_MultiBattle[] = _("マルチバトルを かいさいする");
ALIGNED(4) static const u8 sJPText_TradePokemon[] = _("ポケモンこうかんを かいさいする");
ALIGNED(4) static const u8 sJPText_Chat[] = _("チャットを かいさいする");
ALIGNED(4) static const u8 sJPText_DistWonderCard[] = _("ふしぎなカードをくばる");
ALIGNED(4) static const u8 sJPText_DistWonderNews[] = _("ふしぎなニュースをくばる");
ALIGNED(4) static const u8 sJPText_DistMysteryEvent[] = _("ふしぎなできごとを かいさいする"); // Unused
ALIGNED(4) static const u8 sJPText_HoldPokemonJump[] = _("なわとびを かいさいする");
ALIGNED(4) static const u8 sJPText_HoldBerryCrush[] = _("きのみマッシャーを かいさいする");
ALIGNED(4) static const u8 sJPText_HoldBerryPicking[] = _("きのみどりを かいさいする");
ALIGNED(4) static const u8 sJPText_HoldSpinTrade[] = _("ぐるぐるこうかんを かいさいする");
ALIGNED(4) static const u8 sJPText_HoldSpinShop[] = _("ぐるぐるショップを かいさいする");

// Unused
static const u8 *const sJPLinkGroupActionTexts[] = {
    sJPText_SingleBattle,
    sJPText_DoubleBattle,
    sJPText_MultiBattle,
    sJPText_TradePokemon,
    sJPText_Chat,
    sJPText_DistWonderCard,
    sJPText_DistWonderNews,
    sJPText_DistWonderCard,
    sJPText_HoldPokemonJump,
    sJPText_HoldBerryCrush,
    sJPText_HoldBerryPicking,
    sJPText_HoldBerryPicking,
    sJPText_HoldSpinTrade,
    sJPText_HoldSpinShop
};

static const u8 sText_1PlayerNeeded[] = _("Cần thêm\n1 người chơi.");
static const u8 sText_2PlayersNeeded[] = _("Cần thêm\n2 người chơi.");
static const u8 sText_3PlayersNeeded[] = _("Cần thêm\n3 người chơi.");
static const u8 sText_4PlayersNeeded[] = _("Cần thêm\n4 người chơi.");
static const u8 sText_2PlayerMode[] = _("2-PLAYER\nMODE");
static const u8 sText_3PlayerMode[] = _("3-PLAYER\nMODE");
static const u8 sText_4PlayerMode[] = _("4-PLAYER\nMODE");
static const u8 sText_5PlayerMode[] = _("5-PLAYER\nMODE");

static const u8 *const sPlayersNeededOrModeTexts[][5] = {
    // 2 players required
    {
        sText_1PlayerNeeded,
        sText_2PlayerMode
    },
    // 4 players required
    {
        sText_3PlayersNeeded,
        sText_2PlayersNeeded,
        sText_1PlayerNeeded,
        sText_4PlayerMode
    },
    // 2-5 players required
    {
        sText_1PlayerNeeded,
        sText_2PlayerMode,
        sText_3PlayerMode,
        sText_4PlayerMode,
        sText_5PlayerMode
    },
    // 3-5 players required
    {
        sText_2PlayersNeeded,
        sText_1PlayerNeeded,
        sText_3PlayerMode,
        sText_4PlayerMode,
        sText_5PlayerMode
    },
    // 2-4 players required
    {
        sText_1PlayerNeeded,
        sText_2PlayerMode,
        sText_3PlayerMode,
        sText_4PlayerMode
    }
};

ALIGNED(4) static const u8 sText_BButtonCancel[] = _("{B_BUTTON}CANCEL");
ALIGNED(4) static const u8 sJPText_SearchingForParticipants[] = _("ため\nさんかしゃ ぼしゅうちゅう です！"); // Unused, may have been cut off
ALIGNED(4) static const u8 sText_PlayerContactedYouForXAccept[] = _("{STR_VAR_2} liên lạc để tham gia\n{STR_VAR_1}. Chấp nhận?");
ALIGNED(4) static const u8 sText_PlayerContactedYouShareX[] = _("{STR_VAR_2} đã liên lạc.\nBạn muốn chia sẻ {STR_VAR_1}?");
ALIGNED(4) static const u8 sText_PlayerContactedYouAddToMembers[] = _("{STR_VAR_2} đã liên lạc.\nThêm vào nhóm?");
ALIGNED(4) static const u8 sText_AreTheseMembersOK[] = _("{STR_VAR_1}!\nNhóm này đã ổn chưa?");
ALIGNED(4) static const u8 sText_CancelModeWithTheseMembers[] = _("Hủy {STR_VAR_1} MODE\nvới nhóm này?");
ALIGNED(4) static const u8 sText_AnOKWasSentToPlayer[] = _("Đã gửi “OK”\ncho {STR_VAR_1}.");
ALIGNED(4) static const u8 sText_OtherTrainerUnavailableNow[] = _("HLV kia hiện không thể\nliên lạc…\p");
ALIGNED(4) static const u8 sText_CantTransmitTrainerTooFar[] = _("Không thể truyền với HLV\nở quá xa.\p");
ALIGNED(4) static const u8 sText_TrainersNotReadyYet[] = _("HLV kia chưa sẵn sàng.\p");

static const u8 *const sCantTransmitToTrainerTexts[] = {
    [UR_TRADE_PLAYER_NOT_READY - 1]  = sText_CantTransmitTrainerTooFar,
    [UR_TRADE_PARTNER_NOT_READY - 1] = sText_TrainersNotReadyYet
};

ALIGNED(4) static const u8 sText_ModeWithTheseMembersWillBeCanceled[] = _("{STR_VAR_1} MODE với nhóm này\nsẽ bị hủy.{PAUSE 60}");
ALIGNED(4) static const u8 sText_MemberNoLongerAvailable[] = _("Có thành viên không còn\nthể tiếp tục.\p");

static const u8 *const sPlayerUnavailableTexts[] = {
    sText_OtherTrainerUnavailableNow,
    sText_MemberNoLongerAvailable
};

ALIGNED(4) static const u8 sText_TrainerAppearsUnavailable[] = _("HLV kia có vẻ\nkhông thể liên lạc…\p");
ALIGNED(4) static const u8 sText_PlayerSentBackOK[] = _("{STR_VAR_1} đã trả lời “OK”!");
ALIGNED(4) static const u8 sText_PlayerOKdRegistration[] = _("{STR_VAR_1} đã đồng ý đăng ký bạn\nlàm thành viên.");
ALIGNED(4) static const u8 sText_PlayerRepliedNo[] = _("{STR_VAR_1} trả lời: “Không…”\p");
ALIGNED(4) static const u8 sText_AwaitingOtherMembers[] = _("{STR_VAR_1}!\nĐang chờ các thành viên khác!");
ALIGNED(4) static const u8 sText_QuitBeingMember[] = _("Rời khỏi nhóm?");
ALIGNED(4) static const u8 sText_StoppedBeingMember[] = _("Bạn đã rời khỏi nhóm.\p");

static const u8 *const sPlayerDisconnectedTexts[] = {
    [RFU_STATUS_OK]                  = NULL,
    [RFU_STATUS_FATAL_ERROR]         = sText_MemberNoLongerAvailable,
    [RFU_STATUS_CONNECTION_ERROR]    = sText_TrainerAppearsUnavailable,
    [RFU_STATUS_CHILD_SEND_COMPLETE] = NULL,
    [RFU_STATUS_NEW_CHILD_DETECTED]  = NULL,
    [RFU_STATUS_JOIN_GROUP_OK]       = NULL,
    [RFU_STATUS_JOIN_GROUP_NO]       = sText_PlayerRepliedNo,
    [RFU_STATUS_WAIT_ACK_JOIN_GROUP] = NULL,
    [RFU_STATUS_LEAVE_GROUP_NOTICE]  = NULL,
    [RFU_STATUS_LEAVE_GROUP]         = sText_StoppedBeingMember
};

ALIGNED(4) static const u8 sText_WirelessLinkEstablished[] = _("Đã thiết lập kết nối bằng\nWIRELESS COMMUNICATION SYSTEM.");
ALIGNED(4) static const u8 sText_WirelessLinkDropped[] = _("Kết nối bằng WIRELESS\nCOMMUNICATION SYSTEM đã mất…");
ALIGNED(4) static const u8 sText_LinkWithFriendDropped[] = _("Kết nối với bạn của bạn\nđã bị mất…");
ALIGNED(4) static const u8 sText_PlayerRepliedNo2[] = _("{STR_VAR_1} trả lời: “Không…”");

static const u8 *const sLinkDroppedTexts[] = {
    [RFU_STATUS_OK]                  = NULL,
    [RFU_STATUS_FATAL_ERROR]         = sText_LinkWithFriendDropped,
    [RFU_STATUS_CONNECTION_ERROR]    = sText_LinkWithFriendDropped,
    [RFU_STATUS_CHILD_SEND_COMPLETE] = NULL,
    [RFU_STATUS_NEW_CHILD_DETECTED]  = NULL,
    [RFU_STATUS_JOIN_GROUP_OK]       = NULL,
    [RFU_STATUS_JOIN_GROUP_NO]       = sText_PlayerRepliedNo2,
    [RFU_STATUS_WAIT_ACK_JOIN_GROUP] = NULL,
    [RFU_STATUS_LEAVE_GROUP_NOTICE]  = NULL,
    [RFU_STATUS_LEAVE_GROUP]         = NULL
};

ALIGNED(4) static const u8 sText_DoYouWantXMode[] = _("Bạn muốn chọn\n{STR_VAR_2} MODE?");
ALIGNED(4) static const u8 sText_DoYouWantXMode2[] = _("Bạn muốn chọn\n{STR_VAR_2} MODE?");

// Unused
static const u8 *const sDoYouWantModeTexts[] = {
    sText_DoYouWantXMode,
    sText_DoYouWantXMode2
};

ALIGNED(4) static const u8 sText_CommunicatingPleaseWait[] = _("Đang liên lạc…\nVui lòng chờ."); // Unused
ALIGNED(4) static const u8 sText_AwaitingPlayersResponseAboutTrade[] = _("Đang chờ {STR_VAR_1} trả lời\nvề cuộc trao đổi…");
ALIGNED(4) static const u8 sText_Communicating[] = _("Đang liên lạc{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.\n{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.");
ALIGNED(4) static const u8 sText_CommunicatingWithPlayer[] = _("Đang liên lạc với {STR_VAR_1}{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.\n{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.");
ALIGNED(4) static const u8 sText_PleaseWaitAWhile[] = _("Vui lòng chờ một lát{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.\n{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.");

static const u8 *const sCommunicatingWaitTexts[] = {
    sText_Communicating,
    sText_CommunicatingWithPlayer,
    sText_PleaseWaitAWhile
};

ALIGNED(4) static const u8 sText_HiDoSomethingMale[] = _("Chào! Bạn muốn làm gì đó sao?");
ALIGNED(4) static const u8 sText_HiDoSomethingFemale[] = _("Xin chào!\nBạn muốn làm gì đó không?");
ALIGNED(4) static const u8 sText_HiDoSomethingAgainMale[] = _("{STR_VAR_1}: Chào, lại gặp nhau rồi!\nLần này bạn muốn làm gì?");
ALIGNED(4) static const u8 sText_HiDoSomethingAgainFemale[] = _("{STR_VAR_1}: Ô! Chào {PLAYER}!\nBạn muốn làm gì đó không?");

static const u8 *const sHiDoSomethingTexts[][GENDER_COUNT] = {
    {
        sText_HiDoSomethingMale,
        sText_HiDoSomethingFemale
    }, {
        sText_HiDoSomethingAgainMale,
        sText_HiDoSomethingAgainFemale
    }
};

ALIGNED(4) static const u8 sText_DoSomethingMale[] = _("Muốn làm gì đó không?");
ALIGNED(4) static const u8 sText_DoSomethingFemale[] = _("Bạn muốn làm gì đó không?");
ALIGNED(4) static const u8 sText_DoSomethingAgainMale[] = _("{STR_VAR_1}: Giờ bạn muốn\nlàm gì?");
ALIGNED(4) static const u8 sText_DoSomethingAgainFemale[] = _("{STR_VAR_1}: Còn muốn làm gì không?"); // Unused

// Unused
static const u8 *const sDoSomethingTexts[][GENDER_COUNT] = {
    {
        sText_DoSomethingMale,
        sText_DoSomethingFemale
    }, {
        sText_DoSomethingAgainMale,
        sText_DoSomethingAgainMale // was probably supposed to be sText_DoSomethingAgainFemale
    }
};

ALIGNED(4) static const u8 sText_SomebodyHasContactedYou[] = _("Có người vừa liên lạc với bạn.{PAUSE 60}");
ALIGNED(4) static const u8 sText_PlayerHasContactedYou[] = _("{STR_VAR_1} vừa liên lạc với bạn.{PAUSE 60}");

static const u8 *const sPlayerContactedYouTexts[] = {
    sText_SomebodyHasContactedYou,
    sText_PlayerHasContactedYou
};

ALIGNED(4) static const u8 sText_AwaitingResponseFromTrainer[] = _("Đang chờ phản hồi từ\nTRAINER kia…");
ALIGNED(4) static const u8 sText_AwaitingResponseFromPlayer[] = _("Đang chờ phản hồi từ\n{STR_VAR_1}…");

static const u8 *const sAwaitingResponseTexts[] = {
    sText_AwaitingResponseFromTrainer,
    sText_AwaitingResponseFromPlayer
};

ALIGNED(4) static const u8 sText_ShowTrainerCard[] = _("HLV kia đã cho bạn xem\nTRAINER CARD.\pBạn có muốn cho họ xem\nTRAINER CARD của mình?");
ALIGNED(4) static const u8 sText_BattleChallenge[] = _("HLV kia thách đấu bạn.\pBạn có chấp nhận\nlời thách đấu không?");
ALIGNED(4) static const u8 sText_ChatInvitation[] = _("HLV kia mời bạn trò chuyện.\pBạn có chấp nhận\nlời mời không?");
ALIGNED(4) static const u8 sText_OfferToTradeMon[] = _("Có đề nghị đổi POKéMON Lv. {DYNAMIC 2}\n{DYNAMIC 3} lấy POKéMON Lv. {DYNAMIC 0}\n{DYNAMIC 1} bạn đã đăng ký.\pBạn có chấp nhận không?");
ALIGNED(4) static const u8 sText_OfferToTradeEgg[] = _("Có đề nghị đổi lấy EGG\nbạn đã đăng ký.\lBạn có chấp nhận không?");
ALIGNED(4) static const u8 sText_ChatDropped[] = _("Cuộc trò chuyện đã bị ngắt.\p");
ALIGNED(4) static const u8 sText_OfferDeclined1[] = _("Bạn đã từ chối đề nghị.\p");
ALIGNED(4) static const u8 sText_OfferDeclined2[] = _("Bạn đã từ chối đề nghị.\p");
ALIGNED(4) static const u8 sText_ChatEnded[] = _("Cuộc trò chuyện đã kết thúc.\p");

// Unused
static const u8 *const sInvitationTexts[] = {
    sText_ShowTrainerCard,
    sText_BattleChallenge,
    sText_ChatInvitation,
    sText_OfferToTradeMon
};

ALIGNED(4) static const u8 sText_JoinChatMale[] = _("Ồ, chào! Chúng tôi đang trò chuyện.\nBạn muốn tham gia không?");
ALIGNED(4) static const u8 sText_PlayerJoinChatMale[] = _("{STR_VAR_1}: Chào, {PLAYER}!\nChúng tôi đang trò chuyện.\lBạn muốn tham gia không?");
ALIGNED(4) static const u8 sText_JoinChatFemale[] = _("Ồ, chào! Chúng tôi đang trò chuyện.\nBạn muốn tham gia không?");
ALIGNED(4) static const u8 sText_PlayerJoinChatFemale[] = _("{STR_VAR_1}: Ô, chào {PLAYER}!\nChúng tôi đang trò chuyện.\lBạn muốn tham gia không?");

static const u8 *const sJoinChatTexts[][GENDER_COUNT] = {
    {
        sText_JoinChatMale,
        sText_JoinChatFemale
    }, {
        sText_PlayerJoinChatMale,
        sText_PlayerJoinChatFemale
    }
};

ALIGNED(4) static const u8 sText_TrainerAppearsBusy[] = _("……\nTRAINER kia có vẻ đang bận…\p");
ALIGNED(4) static const u8 sText_WaitForBattleMale[] = _("Đấu à?\nĐược thôi, cho tôi ít thời gian.");
ALIGNED(4) static const u8 sText_WaitForChatMale[] = _("Muốn trò chuyện à?\nĐược, chờ tôi một chút.");
ALIGNED(4) static const u8 sText_ShowTrainerCardMale[] = _("Được thôi! Đây là TRAINER CARD,\ncoi như lời chào của tôi.");
ALIGNED(4) static const u8 sText_WaitForBattleFemale[] = _("Đấu sao? Tất nhiên, nhưng tôi cần\nthời gian chuẩn bị.");
ALIGNED(4) static const u8 sText_WaitForChatFemale[] = _("Bạn muốn trò chuyện sao?\nĐược, vui lòng chờ một chút.");
ALIGNED(4) static const u8 sText_ShowTrainerCardFemale[] = _("Để giới thiệu, tôi sẽ cho bạn xem\nTRAINER CARD của mình.");

static const u8 *const sText_WaitOrShowCardTexts[GENDER_COUNT][4] = {
    {
        sText_WaitForBattleMale,
        sText_WaitForChatMale,
        NULL,
        sText_ShowTrainerCardMale
    }, {
        sText_WaitForBattleFemale,
        sText_WaitForChatFemale,
        NULL,
        sText_ShowTrainerCardFemale
    }
};

ALIGNED(4) static const u8 sText_WaitForChatMale2[] = _("Muốn trò chuyện à?\nĐược, chờ tôi một chút."); // Unused
ALIGNED(4) static const u8 sText_DoneWaitingBattleMale[] = _("Cảm ơn đã chờ!\nBắt đầu trận đấu nào!{PAUSE 60}");
ALIGNED(4) static const u8 sText_DoneWaitingChatMale[] = _("Được rồi!\nCùng trò chuyện nào!{PAUSE 60}");
ALIGNED(4) static const u8 sText_DoneWaitingBattleFemale[] = _("Xin lỗi đã để bạn chờ!\nBắt đầu thôi!{PAUSE 60}");
ALIGNED(4) static const u8 sText_DoneWaitingChatFemale[] = _("Xin lỗi đã để bạn chờ!\nCùng trò chuyện nhé.{PAUSE 60}");
ALIGNED(4) static const u8 sText_TradeWillBeStarted[] = _("Cuộc trao đổi sẽ bắt đầu.{PAUSE 60}");
ALIGNED(4) static const u8 sText_BattleWillBeStarted[] = _("Trận đấu sẽ bắt đầu.{PAUSE 60}");
ALIGNED(4) static const u8 sText_EnteringChat[] = _("Đang vào phòng trò chuyện…{PAUSE 60}");

static const u8 *const sStartActivityTexts[][GENDER_COUNT][3] = {
    {
        {
            sText_BattleWillBeStarted,
            sText_EnteringChat,
            sText_TradeWillBeStarted
        }, {
            sText_BattleWillBeStarted,
            sText_EnteringChat,
            sText_TradeWillBeStarted
        }
    }, {
        {
            sText_DoneWaitingBattleMale,
            sText_DoneWaitingChatMale,
            sText_TradeWillBeStarted
        }, {
            sText_DoneWaitingBattleFemale,
            sText_DoneWaitingChatFemale,
            sText_TradeWillBeStarted
        }
    }
};

ALIGNED(4) static const u8 sText_BattleDeclinedMale[] = _("Xin lỗi! POKéMON của tôi có vẻ\nkhông được khỏe.\lĐể lần khác đấu nhé.\p");
ALIGNED(4) static const u8 sText_BattleDeclinedFemale[] = _("Tôi rất xin lỗi, POKéMON của tôi\nkhông được khỏe…\pĐể lần khác đấu nhé.\p");

static const u8 *const sBattleDeclinedTexts[GENDER_COUNT] = {
    sText_BattleDeclinedMale,
    sText_BattleDeclinedFemale
};

ALIGNED(4) static const u8 sText_ShowTrainerCardDeclinedMale[] = _("Hả? TRAINER CARD của tôi…\nNó đâu rồi nhỉ?\lXin lỗi! Lần khác tôi sẽ cho xem!\p");
ALIGNED(4) static const u8 sText_ShowTrainerCardDeclinedFemale[] = _("Ô? Tôi để TRAINER CARD\nở đâu rồi nhỉ?…\lXin lỗi! Lần sau tôi sẽ cho xem!\p");

static const u8 *const sShowTrainerCardDeclinedTexts[GENDER_COUNT] = {
    sText_ShowTrainerCardDeclinedMale,
    sText_ShowTrainerCardDeclinedFemale
};

ALIGNED(4) static const u8 sText_IfYouWantToDoSomethingMale[] = _("Nếu muốn làm gì cùng tôi,\ncứ gọi nhé!\p");
ALIGNED(4) static const u8 sText_IfYouWantToDoSomethingFemale[] = _("Nếu muốn làm gì cùng tôi,\nđừng ngại nhé.\p");

static const u8 *const sIfYouWantToDoSomethingTexts[GENDER_COUNT] = {
    sText_IfYouWantToDoSomethingMale,
    sText_IfYouWantToDoSomethingFemale
};

ALIGNED(4) static const u8 sText_TrainerBattleBusy[] = _("Ôi! Xin lỗi, tôi phải làm\nviệc khác rồi.\lĐể lần khác nhé?\p");
ALIGNED(4) static const u8 sText_NeedTwoMonsOfLevel30OrLower1[] = _("Muốn đấu, bạn cần hai POKéMON\ndưới Lv. 30.\p");
ALIGNED(4) static const u8 sText_NeedTwoMonsOfLevel30OrLower2[] = _("Để đấu, bạn cần hai POKéMON\ndưới Lv. 30.\p");

ALIGNED(4) static const u8 sText_DeclineChatMale[] = _("Ồ, được thôi.\nLúc nào cũng có thể đến gặp tôi!\p");
ALIGNED(4) static const u8 stext_DeclineChatFemale[] = _("Ồ…\nLúc nào cũng có thể ghé nhé.\p");

// Response from partner when player declines chat
static const u8 *const sDeclineChatTexts[GENDER_COUNT] = {
    sText_DeclineChatMale,
    stext_DeclineChatFemale
};

ALIGNED(4) static const u8 sText_ChatDeclinedMale[] = _("Ồ, xin lỗi!\nGiờ tôi không thể.\lĐể lần khác trò chuyện nhé.\p");
ALIGNED(4) static const u8 sText_ChatDeclinedFemale[] = _("Ồ, xin lỗi.\nGiờ tôi có quá nhiều việc.\lĐể lần khác trò chuyện nhé.\p");

// Response from partner when they decline chat
static const u8 *const sChatDeclinedTexts[GENDER_COUNT] = {
    sText_ChatDeclinedMale,
    sText_ChatDeclinedFemale
};

ALIGNED(4) static const u8 sText_YoureToughMale[] = _("Ồ!\nTôi biết bạn rất mạnh!\p");
ALIGNED(4) static const u8 sText_UsedGoodMoveMale[] = _("Bạn dùng chiêu đó sao?\nChiến thuật hay đấy!\p");
ALIGNED(4) static const u8 sText_BattleSurpriseMale[] = _("Hay lắm!\nTrận đấu thật mở mang tầm mắt!\p");
ALIGNED(4) static const u8 sText_SwitchedMonsMale[] = _("Ồ! Sao bạn có thể dùng POKéMON đó\ntrong tình huống ấy nhỉ?\p");
ALIGNED(4) static const u8 sText_YoureToughFemale[] = _("POKéMON đó…\nĐược nuôi dạy rất tốt!\p");
ALIGNED(4) static const u8 sText_UsedGoodMoveFemale[] = _("Đúng rồi!\nGiờ dùng chiêu đó là hợp lý!\p");
ALIGNED(4) static const u8 sText_BattleSurpriseFemale[] = _("Tuyệt quá!\nBạn có thể đấu như vậy sao?\p");
ALIGNED(4) static const u8 sText_SwitchedMonsFemale[] = _("Bạn đổi POKéMON\nđúng lúc thật đấy!\p");

static const u8 *const sBattleReactionTexts[GENDER_COUNT][4] = {
    {
        sText_YoureToughMale,
        sText_UsedGoodMoveMale,
        sText_BattleSurpriseMale,
        sText_SwitchedMonsMale
    },
    {
        sText_YoureToughFemale,
        sText_UsedGoodMoveFemale,
        sText_BattleSurpriseFemale,
        sText_SwitchedMonsFemale
    }
};

ALIGNED(4) static const u8 sText_LearnedSomethingMale[] = _("Ồ, ra vậy!\nThật bổ ích!\p");
ALIGNED(4) static const u8 sText_ThatsFunnyMale[] = _("Đừng nói gì buồn cười nữa!\nTôi cười đau cả bụng rồi!\p");
ALIGNED(4) static const u8 sText_RandomChatMale1[] = _("Ồ?\nChuyện như thế đã xảy ra à.\p");
ALIGNED(4) static const u8 sText_RandomChatMale2[] = _("Ừm… Gì cơ?\nÝ bạn là vậy sao?\p");
ALIGNED(4) static const u8 sText_LearnedSomethingFemale[] = _("Thật sao?\nTôi không biết đấy.\p");
ALIGNED(4) static const u8 sText_ThatsFunnyFemale[] = _("Ha ha!\nChuyện gì vậy?\p");
ALIGNED(4) static const u8 sText_RandomChatFemale1[] = _("Đúng, chính xác!\nĐó là điều tôi muốn nói.\p");
ALIGNED(4) static const u8 sText_RandomChatFemale2[] = _("Nói cách khác…\nĐúng! Chính là vậy!\p");

static const u8 *const sChatReactionTexts[GENDER_COUNT][4] = {
    {
        sText_LearnedSomethingMale,
        sText_ThatsFunnyMale,
        sText_RandomChatMale1,
        sText_RandomChatMale2
    },
    {
        sText_LearnedSomethingFemale,
        sText_ThatsFunnyFemale,
        sText_RandomChatFemale1,
        sText_RandomChatFemale2
    }
};

ALIGNED(4) static const u8 sText_ShowedTrainerCardMale1[] = _("Tôi cho bạn xem TRAINER CARD\nnhư một lời chào.\p");
ALIGNED(4) static const u8 sText_ShowedTrainerCardMale2[] = _("Hy vọng chúng ta sẽ hiểu nhau hơn!\p");
ALIGNED(4) static const u8 sText_ShowedTrainerCardFemale1[] = _("Chúng tôi xem TRAINER CARD\ncủa nhau để làm quen.\p");
ALIGNED(4) static const u8 sText_ShowedTrainerCardFemale2[] = _("Rất vui được gặp bạn.\nĐừng ngại ghé lại nhé!\p");

static const u8 *const sTrainerCardReactionTexts[GENDER_COUNT][2] = {
    {
        sText_ShowedTrainerCardMale1,
        sText_ShowedTrainerCardMale2
    },
    {
        sText_ShowedTrainerCardFemale1,
        sText_ShowedTrainerCardFemale2
    }
};

ALIGNED(4) static const u8 sText_MaleTraded1[] = _("Hay quá!\nTôi rất muốn POKéMON này!\p");
ALIGNED(4) static const u8 sText_MaleTraded2[] = _("Cuối cùng tôi đã đổi được\nPOKéMON mình mong muốn bấy lâu.\p");
ALIGNED(4) static const u8 sText_FemaleTraded1[] = _("Tôi đang trao đổi POKéMON.\p");
ALIGNED(4) static const u8 sText_FemaleTraded2[] = _("Cuối cùng tôi đã đổi được\nPOKéMON mình muốn!\p");

static const u8 *const sTradeReactionTexts[GENDER_COUNT][4] = {
    {
        sText_MaleTraded1,
        sText_MaleTraded2
    },
    {
        sText_FemaleTraded1,
        sText_FemaleTraded2
    }
};

ALIGNED(4) static const u8 sText_XCheckedTradingBoard[] = _("{STR_VAR_1} đã xem\nTRADING BOARD.\p");
ALIGNED(4) static const u8 sText_RegisterMonAtTradingBoard[] = _("Chào mừng đến TRADING BOARD.\pBạn có thể đăng ký POKéMON\nđể đề nghị trao đổi.\pBạn muốn đăng ký một POKéMON?");
ALIGNED(4) static const u8 sText_TradingBoardInfo[] = _("TRADING BOARD dùng để đề nghị\ntrao đổi POKéMON.\pBạn chỉ cần đăng ký một POKéMON.\pTRAINER khác có thể đề nghị\nđổi một POKéMON trong đội.\pHãy đăng ký và trao đổi POKéMON\nvới thật nhiều HLV.\pBạn muốn đăng ký một POKéMON?");
ALIGNED(4) static const u8 sText_ThankYouForRegistering[] = _("Đã đăng ký POKéMON của bạn\nlên TRADING BOARD.\pCảm ơn bạn đã sử dụng dịch vụ!\p"); // unused
ALIGNED(4) static const u8 sText_NobodyHasRegistered[] = _("Chưa ai đăng ký POKéMON\ntrao đổi trên TRADING BOARD.\p\n"); // unused
ALIGNED(4) static const u8 sText_ChooseRequestedMonType[] = _("Hãy chọn type POKéMON\nbạn muốn nhận khi trao đổi.\n");
ALIGNED(4) static const u8 sText_WhichMonWillYouOffer[] = _("Bạn sẽ dùng POKéMON nào\ntrong đội để trao đổi?\p");
ALIGNED(4) static const u8 sText_RegistrationCanceled[] = _("Đã hủy đăng ký.\p");
ALIGNED(4) static const u8 sText_RegistrationCompleted[] = _("Đã hoàn tất đăng ký.\p");
ALIGNED(4) static const u8 sText_TradeCanceled[] = _("Đã hủy trao đổi.\p");
ALIGNED(4) static const u8 sText_CancelRegistrationOfMon[] = _("Hủy đăng ký POKéMON\nLv. {STR_VAR_2} {STR_VAR_1}?");
ALIGNED(4) static const u8 sText_CancelRegistrationOfEgg[] = _("Hủy đăng ký EGG?");
ALIGNED(4) static const u8 sText_RegistrationCanceled2[] = _("Đã hủy đăng ký.\p");
ALIGNED(4) static const u8 sText_TradeTrainersWillBeListed[] = _("Danh sách HLV muốn trao đổi\nsẽ được hiển thị."); // unused
ALIGNED(4) static const u8 sText_ChooseTrainerToTradeWith2[] = _("Hãy chọn HLV\nbạn muốn trao đổi POKéMON."); // unused
ALIGNED(4) static const u8 sText_AskTrainerToMakeTrade[] = _("Bạn muốn đề nghị {STR_VAR_1}\ntrao đổi không?");
ALIGNED(4) static const u8 sText_AwaitingResponseFromTrainer2[] = _("Đang chờ phản hồi từ\nTRAINER kia…"); // unused
ALIGNED(4) static const u8 sText_NotRegisteredAMonForTrade[] = _("Bạn chưa đăng ký POKéMON\nđể trao đổi.\p"); // unused
ALIGNED(4) static const u8 sText_DontHaveTypeTrainerWants[] = _("Bạn không có POKéMON type\n{STR_VAR_2} mà {STR_VAR_1} muốn.\p");
ALIGNED(4) static const u8 sText_DontHaveEggTrainerWants[] = _("Bạn không có EGG\nmà {STR_VAR_1} muốn.\p");
ALIGNED(4) static const u8 sText_PlayerCantTradeForYourMon[] = _("{STR_VAR_1} hiện không thể trao đổi\nPOKéMON của bạn.\p");
ALIGNED(4) static const u8 sText_CantTradeForPartnersMon[] = _("Hiện không thể trao đổi\nPOKéMON của {STR_VAR_1}.\p");

// Unused
static const u8 *const sCantTradeMonTexts[] = {
    sText_PlayerCantTradeForYourMon,
    sText_CantTradeForPartnersMon
};

ALIGNED(4) static const u8 sText_TradeOfferRejected[] = _("Đề nghị trao đổi đã bị từ chối.\p");
ALIGNED(4) static const u8 sText_EggTrade[] = _("EGG TRADE");
ALIGNED(4) static const u8 sText_ChooseJoinCancel[] = _("{DPAD_UPDOWN}CHOOSE  {A_BUTTON}JOIN  {B_BUTTON}CANCEL");
ALIGNED(4) static const u8 sText_ChooseTrainer[] = _("Hãy chọn một HLV.");
ALIGNED(4) static const u8 sText_ChooseTrainerSingleBattle[] = _("Hãy chọn HLV cho\nSINGLE BATTLE.");
ALIGNED(4) static const u8 sText_ChooseTrainerDoubleBattle[] = _("Hãy chọn HLV cho\nDOUBLE BATTLE.");
ALIGNED(4) static const u8 sText_ChooseLeaderMultiBattle[] = _("Hãy chọn LEADER cho\nMULTI BATTLE.");
ALIGNED(4) static const u8 sText_ChooseTrainerToTradeWith[] = _("Hãy chọn HLV\nđể trao đổi.");
ALIGNED(4) static const u8 sText_ChooseTrainerToShareWonderCards[] = _("Hãy chọn HLV đang chia sẻ\nWONDER CARDS.");
ALIGNED(4) static const u8 sText_ChooseTrainerToShareWonderNews[] = _("Hãy chọn HLV đang chia sẻ\nWONDER NEWS.");
ALIGNED(4) static const u8 sText_ChooseLeaderPokemonJump[] = _("Nhảy cùng POKéMON nhỏ!\nHãy chọn LEADER.");
ALIGNED(4) static const u8 sText_ChooseLeaderBerryCrush[] = _("BERRY CRUSH!\nHãy chọn LEADER.");
ALIGNED(4) static const u8 sText_ChooseLeaderBerryPicking[] = _("DODRIO BERRY-PICKING!\nHãy chọn LEADER.");
ALIGNED(4) static const u8 sText_ChooseLeaderBerryBlender[] = _("BERRY BLENDER!\nHãy chọn LEADER.");
ALIGNED(4) static const u8 sText_ChooseLeaderRecordCorner[] = _("RECORD CORNER!\nHãy chọn LEADER.");
ALIGNED(4) static const u8 sText_ChooseLeaderCoolContest[] = _("COOLNESS CONTEST!\nHãy chọn LEADER.");
ALIGNED(4) static const u8 sText_ChooseLeaderBeautyContest[] = _("BEAUTY CONTEST!\nHãy chọn LEADER.");
ALIGNED(4) static const u8 sText_ChooseLeaderCuteContest[] = _("CUTENESS CONTEST!\nHãy chọn LEADER.");
ALIGNED(4) static const u8 sText_ChooseLeaderSmartContest[] = _("SMARTNESS CONTEST!\nHãy chọn LEADER.");
ALIGNED(4) static const u8 sText_ChooseLeaderToughContest[] = _("TOUGHNESS CONTEST!\nHãy chọn LEADER.");
ALIGNED(4) static const u8 sText_ChooseLeaderBattleTowerLv50[] = _("BATTLE TOWER LEVEL 50!\nHãy chọn LEADER.");
ALIGNED(4) static const u8 sText_ChooseLeaderBattleTowerOpenLv[] = _("BATTLE TOWER OPEN LEVEL!\nHãy chọn LEADER.");

static const u8 *const sChooseTrainerTexts[NUM_LINK_GROUP_TYPES] =
{
    [LINK_GROUP_SINGLE_BATTLE]     = sText_ChooseTrainerSingleBattle,
    [LINK_GROUP_DOUBLE_BATTLE]     = sText_ChooseTrainerDoubleBattle,
    [LINK_GROUP_MULTI_BATTLE]      = sText_ChooseLeaderMultiBattle,
    [LINK_GROUP_TRADE]             = sText_ChooseTrainerToTradeWith,
    [LINK_GROUP_POKEMON_JUMP]      = sText_ChooseLeaderPokemonJump,
    [LINK_GROUP_BERRY_CRUSH]       = sText_ChooseLeaderBerryCrush,
    [LINK_GROUP_BERRY_PICKING]     = sText_ChooseLeaderBerryPicking,
    [LINK_GROUP_WONDER_CARD]       = sText_ChooseTrainerToShareWonderCards,
    [LINK_GROUP_WONDER_NEWS]       = sText_ChooseTrainerToShareWonderNews,
    [LINK_GROUP_UNION_ROOM_RESUME] = NULL,
    [LINK_GROUP_UNION_ROOM_INIT]   = NULL,
    [LINK_GROUP_UNK_11]            = NULL,
    [LINK_GROUP_RECORD_CORNER]     = sText_ChooseLeaderRecordCorner,
    [LINK_GROUP_BERRY_BLENDER]     = sText_ChooseLeaderBerryBlender,
    [LINK_GROUP_UNK_14]            = NULL,
    [LINK_GROUP_COOL_CONTEST]      = sText_ChooseLeaderCoolContest,
    [LINK_GROUP_BEAUTY_CONTEST]    = sText_ChooseLeaderBeautyContest,
    [LINK_GROUP_CUTE_CONTEST]      = sText_ChooseLeaderCuteContest,
    [LINK_GROUP_SMART_CONTEST]     = sText_ChooseLeaderSmartContest,
    [LINK_GROUP_TOUGH_CONTEST]     = sText_ChooseLeaderToughContest,
    [LINK_GROUP_BATTLE_TOWER]      = sText_ChooseLeaderBattleTowerLv50,
    [LINK_GROUP_BATTLE_TOWER_OPEN] = sText_ChooseLeaderBattleTowerOpenLv
};

ALIGNED(4) static const u8 sText_SearchingForWirelessSystemWait[] = _("Đang tìm WIRELESS\nCOMMUNICATION SYSTEM. Xin chờ…");
ALIGNED(4) static const u8 sText_MustHaveTwoMonsForDoubleBattle[] = _("DOUBLE BATTLE cần ít nhất\nhai POKéMON.\p"); // Unused
ALIGNED(4) static const u8 sText_AwaitingPlayersResponse[] = _("Đang chờ {STR_VAR_1} phản hồi…");
ALIGNED(4) static const u8 sText_PlayerHasBeenAskedToRegisterYouPleaseWait[] = _("Đã yêu cầu {STR_VAR_1} đăng ký bạn\nlàm thành viên. Vui lòng chờ.");
ALIGNED(4) static const u8 sText_AwaitingResponseFromWirelessSystem[] = _("Đang chờ phản hồi từ\nWIRELESS COMMUNICATION SYSTEM.");
ALIGNED(4) static const u8 sText_PleaseWaitForOtherTrainersToGather[] = _("Vui lòng chờ các HLV khác\ntập hợp và chuẩn bị."); // Unused
ALIGNED(4) static const u8 sText_NoCardsSharedRightNow[] = _("Hiện không có CARD nào\nđược chia sẻ.");
ALIGNED(4) static const u8 sText_NoNewsSharedRightNow[] = _("Hiện không có NEWS nào\nđược chia sẻ.");

static const u8 *const sNoWonderSharedTexts[] = {
    sText_NoCardsSharedRightNow,
    sText_NoNewsSharedRightNow
};

ALIGNED(4) static const u8 sText_Battle[] = _("BATTLE");
ALIGNED(4) static const u8 sText_Chat2[] = _("CHAT");
ALIGNED(4) static const u8 sText_Greetings[] = _("GREETINGS");
ALIGNED(4) static const u8 sText_Exit[] = _("EXIT");
ALIGNED(4) static const u8 sText_Exit2[] = _("EXIT");
ALIGNED(4) static const u8 sText_Info[] = _("INFO");
ALIGNED(4) static const u8 sText_NameWantedOfferLv[] = _("NAME{CLEAR_TO 60}WANTED{CLEAR_TO 110}OFFER{CLEAR_TO 198}LV.");
ALIGNED(4) static const u8 sText_SingleBattle[] = _("SINGLE BATTLE");
ALIGNED(4) static const u8 sText_DoubleBattle[] = _("DOUBLE BATTLE");
ALIGNED(4) static const u8 sText_MultiBattle[] = _("MULTI BATTLE");
ALIGNED(4) static const u8 sText_PokemonTrades[] = _("POKéMON TRADES");
ALIGNED(4) static const u8 sText_Chat[] = _("CHAT");
ALIGNED(4) static const u8 sText_Cards[] = _("CARDS");
ALIGNED(4) static const u8 sText_WonderCards[] = _("WONDER CARDS");
ALIGNED(4) static const u8 sText_WonderNews[] = _("WONDER NEWS");
ALIGNED(4) static const u8 sText_PokemonJump[] = _("POKéMON JUMP");
ALIGNED(4) static const u8 sText_BerryCrush[] = _("BERRY CRUSH");
ALIGNED(4) static const u8 sText_BerryPicking[] = _("BERRY-PICKING");
ALIGNED(4) static const u8 sText_Search[] = _("SEARCH");
ALIGNED(4) static const u8 sText_BerryBlender[] = _("BERRY BLENDER");
ALIGNED(4) static const u8 sText_RecordCorner[] = _("RECORD CORNER");
ALIGNED(4) static const u8 sText_CoolContest[] = _("COOL CONTEST");
ALIGNED(4) static const u8 sText_BeautyContest[] = _("BEAUTY CONTEST");
ALIGNED(4) static const u8 sText_CuteContest[] = _("CUTE CONTEST");
ALIGNED(4) static const u8 sText_SmartContest[] = _("SMART CONTEST");
ALIGNED(4) static const u8 sText_ToughContest[] = _("TOUGH CONTEST");
ALIGNED(4) static const u8 sText_BattleTowerLv50[] = _("BATTLE TOWER LV. 50");
ALIGNED(4) static const u8 sText_BattleTowerOpenLv[] = _("BATTLE TOWER OPEN LEVEL");
ALIGNED(4) static const u8 sText_ItsNormalCard[] = _("Đây là NORMAL CARD.");
ALIGNED(4) static const u8 sText_ItsBronzeCard[] = _("Đây là BRONZE CARD!");
ALIGNED(4) static const u8 sText_ItsCopperCard[] = _("Đây là COPPER CARD!");
ALIGNED(4) static const u8 sText_ItsSilverCard[] = _("Đây là SILVER CARD!");
ALIGNED(4) static const u8 sText_ItsGoldCard[] = _("Đây là GOLD CARD!");

static const u8 *const sCardColorTexts[] = {
    sText_ItsNormalCard,
    sText_ItsBronzeCard,
    sText_ItsCopperCard,
    sText_ItsSilverCard,
    sText_ItsGoldCard
};

ALIGNED(4) static const u8 sText_TrainerCardInfoPage1[] = _("Đây là TRAINER CARD của\n{DYNAMIC 0} {DYNAMIC 1}…\l{DYNAMIC 2}\pPOKéDEX: {DYNAMIC 3}\nTIME:    {DYNAMIC 4}:{DYNAMIC 5}\p");
ALIGNED(4) static const u8 sText_TrainerCardInfoPage2[] = _("BATTLES: WINS: {DYNAMIC 0}  LOSSES: {DYNAMIC 2}\nTRADES: {DYNAMIC 3}\p“{DYNAMIC 4} {DYNAMIC 5}\n{DYNAMIC 6} {DYNAMIC 7}”\p");
ALIGNED(4) static const u8 sText_GladToMeetYouMale[] = _("{DYNAMIC 1}: Rất vui vì đã gặp bạn!{PAUSE 60}");
ALIGNED(4) static const u8 sText_GladToMeetYouFemale[] = _("{DYNAMIC 1}: Rất vui được gặp bạn!{PAUSE 60}");

static const u8 *const sGladToMeetYouTexts[GENDER_COUNT] = {
    sText_GladToMeetYouMale,
    sText_GladToMeetYouFemale
};

ALIGNED(4) static const u8 sText_FinishedCheckingPlayersTrainerCard[] = _("Đã xem xong TRAINER CARD\ncủa {DYNAMIC 1}.{PAUSE 60}");

static const u8 *const sLinkGroupActivityNameTexts[] = {
    [ACTIVITY_NONE]              = sText_EmptyString,
    [ACTIVITY_BATTLE_SINGLE]     = sText_SingleBattle,
    [ACTIVITY_BATTLE_DOUBLE]     = sText_DoubleBattle,
    [ACTIVITY_BATTLE_MULTI]      = sText_MultiBattle,
    [ACTIVITY_TRADE]             = sText_PokemonTrades,
    [ACTIVITY_CHAT]              = sText_Chat,
    [ACTIVITY_WONDER_CARD_DUP]   = sText_WonderCards,
    [ACTIVITY_WONDER_NEWS_DUP]   = sText_WonderNews,
    [ACTIVITY_CARD]              = sText_Cards,
    [ACTIVITY_POKEMON_JUMP]      = sText_PokemonJump,
    [ACTIVITY_BERRY_CRUSH]       = sText_BerryCrush,
    [ACTIVITY_BERRY_PICK]        = sText_BerryPicking,
    [ACTIVITY_SEARCH]            = sText_Search,
    [ACTIVITY_SPIN_TRADE]        = sText_EmptyString,
    [ACTIVITY_BATTLE_TOWER_OPEN] = sText_BattleTowerOpenLv,
    [ACTIVITY_RECORD_CORNER]     = sText_RecordCorner,
    [ACTIVITY_BERRY_BLENDER]     = sText_BerryBlender,
    [ACTIVITY_ACCEPT]            = sText_EmptyString,
    [ACTIVITY_DECLINE]           = sText_EmptyString,
    [ACTIVITY_NPCTALK]           = sText_EmptyString,
    [ACTIVITY_PLYRTALK]          = sText_EmptyString,
    [ACTIVITY_WONDER_CARD]       = sText_WonderCards,
    [ACTIVITY_WONDER_NEWS]       = sText_WonderNews,
    [ACTIVITY_CONTEST_COOL]      = sText_CoolContest,
    [ACTIVITY_CONTEST_BEAUTY]    = sText_BeautyContest,
    [ACTIVITY_CONTEST_CUTE]      = sText_CuteContest,
    [ACTIVITY_CONTEST_SMART]     = sText_SmartContest,
    [ACTIVITY_CONTEST_TOUGH]     = sText_ToughContest,
    [ACTIVITY_BATTLE_TOWER]      = sText_BattleTowerLv50
};

static const struct WindowTemplate sWindowTemplate_BButtonCancel = {
    .bg = 0,
    .tilemapLeft = 0,
    .tilemapTop = 0,
    .width = 30,
    .height = 2,
    .paletteNum = 15,
    .baseBlock = 0x0008
};

// Minimum and maximum number of players for a link group
// A minimum of 0 means the min and max are equal
#define LINK_GROUP_CAPACITY(min, max) (((min) << 12) | ((max) << 8))
#define GROUP_MAX(capacity) (capacity & 0x0F)
#define GROUP_MIN(capacity) (capacity >> 4)
#define GROUP_MIN2(capacity) (capacity & 0xF0) // Unnecessary to have both, but needed to match

static const u32 sLinkGroupToActivityAndCapacity[NUM_LINK_GROUP_TYPES] = {
    [LINK_GROUP_SINGLE_BATTLE]     = ACTIVITY_BATTLE_SINGLE     | LINK_GROUP_CAPACITY(0, 2),
    [LINK_GROUP_DOUBLE_BATTLE]     = ACTIVITY_BATTLE_DOUBLE     | LINK_GROUP_CAPACITY(0, 2),
    [LINK_GROUP_MULTI_BATTLE]      = ACTIVITY_BATTLE_MULTI      | LINK_GROUP_CAPACITY(0, 4),
    [LINK_GROUP_TRADE]             = ACTIVITY_TRADE             | LINK_GROUP_CAPACITY(0, 2),
    [LINK_GROUP_POKEMON_JUMP]      = ACTIVITY_POKEMON_JUMP      | LINK_GROUP_CAPACITY(2, 5),
    [LINK_GROUP_BERRY_CRUSH]       = ACTIVITY_BERRY_CRUSH       | LINK_GROUP_CAPACITY(2, 5),
    [LINK_GROUP_BERRY_PICKING]     = ACTIVITY_BERRY_PICK        | LINK_GROUP_CAPACITY(3, 5),
    [LINK_GROUP_WONDER_CARD]       = ACTIVITY_NONE              | LINK_GROUP_CAPACITY(0, 0),
    [LINK_GROUP_WONDER_NEWS]       = ACTIVITY_NONE              | LINK_GROUP_CAPACITY(0, 0),
    [LINK_GROUP_UNION_ROOM_RESUME] = ACTIVITY_NONE              | LINK_GROUP_CAPACITY(0, 0),
    [LINK_GROUP_UNION_ROOM_INIT]   = ACTIVITY_NONE              | LINK_GROUP_CAPACITY(0, 0),
    [LINK_GROUP_UNK_11]            = ACTIVITY_NONE              | LINK_GROUP_CAPACITY(0, 0),
    [LINK_GROUP_RECORD_CORNER]     = ACTIVITY_RECORD_CORNER     | LINK_GROUP_CAPACITY(2, 4),
    [LINK_GROUP_BERRY_BLENDER]     = ACTIVITY_BERRY_BLENDER     | LINK_GROUP_CAPACITY(2, 4),
    [LINK_GROUP_UNK_14]            = ACTIVITY_NONE              | LINK_GROUP_CAPACITY(0, 0),
    [LINK_GROUP_COOL_CONTEST]      = ACTIVITY_CONTEST_COOL      | LINK_GROUP_CAPACITY(2, 4),
    [LINK_GROUP_BEAUTY_CONTEST]    = ACTIVITY_CONTEST_BEAUTY    | LINK_GROUP_CAPACITY(2, 4),
    [LINK_GROUP_CUTE_CONTEST]      = ACTIVITY_CONTEST_CUTE      | LINK_GROUP_CAPACITY(2, 4),
    [LINK_GROUP_SMART_CONTEST]     = ACTIVITY_CONTEST_SMART     | LINK_GROUP_CAPACITY(2, 4),
    [LINK_GROUP_TOUGH_CONTEST]     = ACTIVITY_CONTEST_TOUGH     | LINK_GROUP_CAPACITY(2, 4),
    [LINK_GROUP_BATTLE_TOWER]      = ACTIVITY_BATTLE_TOWER      | LINK_GROUP_CAPACITY(0, 2),
    [LINK_GROUP_BATTLE_TOWER_OPEN] = ACTIVITY_BATTLE_TOWER_OPEN | LINK_GROUP_CAPACITY(0, 2)
};

static const struct WindowTemplate sWindowTemplate_PlayerList = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 3,
    .width = 13,
    .height = 8,
    .paletteNum = 15,
    .baseBlock = 0x0044
};

static const struct WindowTemplate sWindowTemplate_5PlayerList = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 3,
    .width = 13,
    .height = 10,
    .paletteNum = 15,
    .baseBlock = 0x0044
};

static const struct WindowTemplate sWindowTemplate_NumPlayerMode = {
    .bg = 0,
    .tilemapLeft = 16,
    .tilemapTop = 3,
    .width = 7,
    .height = 4,
    .paletteNum = 15,
    .baseBlock = 0x00c6
};

static const struct ListMenuItem sPossibleGroupMembersListMenuItems[] = {
    { sText_EmptyString, 0 },
    { sText_EmptyString, 1 },
    { sText_EmptyString, 2 },
    { sText_EmptyString, 3 },
    { sText_EmptyString, 4 }
};

static const struct ListMenuTemplate sListMenuTemplate_PossibleGroupMembers = {
    .items = sPossibleGroupMembersListMenuItems,
    .moveCursorFunc = NULL,
    .itemPrintFunc = ItemPrintFunc_PossibleGroupMembers,
    .totalItems = ARRAY_COUNT(sPossibleGroupMembersListMenuItems),
    .maxShowed = 5,
    .windowId = 0,
    .header_X = 0,
    .item_X = 0,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_NO_MULTIPLE_SCROLL,
    .fontId = FONT_NORMAL,
    .cursorKind = CURSOR_INVISIBLE
};

static const struct WindowTemplate sWindowTemplate_GroupList = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 3,
    .width = 17,
    .height = 10,
    .paletteNum = 15,
    .baseBlock = 0x0044
};

static const struct WindowTemplate sWindowTemplate_PlayerNameAndId = {
    .bg = 0,
    .tilemapLeft = 20,
    .tilemapTop = 3,
    .width = 7,
    .height = 4,
    .paletteNum = 15,
    .baseBlock = 0x00ee
};

static const struct ListMenuItem sUnionRoomGroupsMenuItems[] = {
    { sText_EmptyString,  0 },
    { sText_EmptyString,  1 },
    { sText_EmptyString,  2 },
    { sText_EmptyString,  3 },
    { sText_EmptyString,  4 },
    { sText_EmptyString,  5 },
    { sText_EmptyString,  6 },
    { sText_EmptyString,  7 },
    { sText_EmptyString,  8 },
    { sText_EmptyString,  9 },
    { sText_EmptyString, 10 },
    { sText_EmptyString, 11 },
    { sText_EmptyString, 12 },
    { sText_EmptyString, 13 },
    { sText_EmptyString, 14 },
    { sText_EmptyString, 15 }
};

static const struct ListMenuTemplate sListMenuTemplate_UnionRoomGroups = {
    .items = sUnionRoomGroupsMenuItems,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = ListMenuItemPrintFunc_UnionRoomGroups,
    .totalItems = ARRAY_COUNT(sUnionRoomGroupsMenuItems),
    .maxShowed = 5,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_MULTIPLE_SCROLL_DPAD,
    .fontId = FONT_NORMAL,
    .cursorKind = CURSOR_BLACK_ARROW
};

static const struct WindowTemplate sWindowTemplate_InviteToActivity = {
    .bg = 0,
    .tilemapLeft = 20,
    .tilemapTop = 5,
    .width = 16,
    .height = 8,
    .paletteNum = 15,
    .baseBlock = 0x0001
};

static const struct ListMenuItem sInviteToActivityMenuItems[] = {
    { sText_Greetings, ACTIVITY_CARD | LINK_GROUP_CAPACITY(0, 2)},
    { sText_Battle,    ACTIVITY_BATTLE_SINGLE | IN_UNION_ROOM | LINK_GROUP_CAPACITY(0, 2)},
    { sText_Chat2,     ACTIVITY_CHAT | IN_UNION_ROOM | LINK_GROUP_CAPACITY(0, 2)},
    { sText_Exit,      ACTIVITY_NONE | IN_UNION_ROOM }
};

static const struct ListMenuTemplate sListMenuTemplate_InviteToActivity = {
    .items = sInviteToActivityMenuItems,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = NULL,
    .totalItems = ARRAY_COUNT(sInviteToActivityMenuItems),
    .maxShowed = 4,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_NO_MULTIPLE_SCROLL,
    .fontId = FONT_NORMAL,
    .cursorKind = CURSOR_BLACK_ARROW
};

static const struct WindowTemplate sWindowTemplate_RegisterForTrade = {
    .bg = 0,
    .tilemapLeft = 18,
    .tilemapTop = 7,
    .width = 16,
    .height = 6,
    .paletteNum = 15,
    .baseBlock = 0x0001
};

static const struct ListMenuItem sRegisterForTradeListMenuItems[] = {
    { gText_Register, 1 },
    { sText_Info, 2 },
    { sText_Exit, 3 }
};

static const struct ListMenuTemplate sListMenuTemplate_RegisterForTrade = {
    .items = sRegisterForTradeListMenuItems,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = NULL,
    .totalItems = ARRAY_COUNT(sRegisterForTradeListMenuItems),
    .maxShowed = 3,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_NO_MULTIPLE_SCROLL,
    .fontId = FONT_NORMAL,
    .cursorKind = CURSOR_BLACK_ARROW
};

static const struct WindowTemplate sWindowTemplate_TradingBoardRequestType = {
    .bg = 0,
    .tilemapLeft = 20,
    .tilemapTop = 1,
    .width = 16,
    .height = 12,
    .paletteNum = 15,
    .baseBlock = 0x0001
};

static const struct ListMenuItem sTradingBoardTypes[NUMBER_OF_MON_TYPES] = {
    { gTypeNames[TYPE_NORMAL],   TYPE_NORMAL         },
    { gTypeNames[TYPE_FIRE],     TYPE_FIRE           },
    { gTypeNames[TYPE_WATER],    TYPE_WATER          },
    { gTypeNames[TYPE_ELECTRIC], TYPE_ELECTRIC       },
    { gTypeNames[TYPE_GRASS],    TYPE_GRASS          },
    { gTypeNames[TYPE_ICE],      TYPE_ICE            },
    { gTypeNames[TYPE_GROUND],   TYPE_GROUND         },
    { gTypeNames[TYPE_ROCK],     TYPE_ROCK           },
    { gTypeNames[TYPE_FLYING],   TYPE_FLYING         },
    { gTypeNames[TYPE_PSYCHIC],  TYPE_PSYCHIC        },
    { gTypeNames[TYPE_FIGHTING], TYPE_FIGHTING       },
    { gTypeNames[TYPE_POISON],   TYPE_POISON         },
    { gTypeNames[TYPE_BUG],      TYPE_BUG            },
    { gTypeNames[TYPE_GHOST],    TYPE_GHOST          },
    { gTypeNames[TYPE_DRAGON],   TYPE_DRAGON         },
    { gTypeNames[TYPE_STEEL],    TYPE_STEEL          },
    { gTypeNames[TYPE_DARK],     TYPE_DARK           },
    { sText_Exit,                NUMBER_OF_MON_TYPES }
};

static const struct ListMenuTemplate sMenuTemplate_TradingBoardRequestType = {
    .items = sTradingBoardTypes,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = NULL,
    .totalItems = ARRAY_COUNT(sTradingBoardTypes),
    .maxShowed = 6,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_NO_MULTIPLE_SCROLL,
    .fontId = FONT_NORMAL,
    .cursorKind = CURSOR_BLACK_ARROW
};

static const struct WindowTemplate sWindowTemplate_TradingBoardHeader = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 1,
    .width = 28,
    .height = 2,
    .paletteNum = 13,
    .baseBlock = 0x0001
};

static const struct WindowTemplate sWindowTemplate_TradingBoardMain = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 5,
    .width = 28,
    .height = 12,
    .paletteNum = 13,
    .baseBlock = 0x0039
};

static const struct ListMenuItem sTradeBoardListMenuItems[] = {
    { sText_EmptyString, LIST_HEADER },
    { sText_EmptyString,  0 },
    { sText_EmptyString,  1 },
    { sText_EmptyString,  2 },
    { sText_EmptyString,  3 },
    { sText_EmptyString,  4 },
    { sText_EmptyString,  5 },
    { sText_EmptyString,  6 },
    { sText_EmptyString,  7 },
    { sText_Exit2,  8 }
};

static const struct ListMenuTemplate sTradeBoardListMenuTemplate = {
    .items = sTradeBoardListMenuItems,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = TradeBoardListMenuItemPrintFunc,
    .totalItems = ARRAY_COUNT(sTradeBoardListMenuItems),
    .maxShowed = 6,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 14,
    .fillValue = 15,
    .cursorShadowPal = 13,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_NO_MULTIPLE_SCROLL,
    .fontId = FONT_NORMAL,
    .cursorKind = CURSOR_BLACK_ARROW
};

// Unused
static const struct WindowTemplate sWindowTemplate_Unused = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 5,
    .width = 28,
    .height = 12,
    .paletteNum = 13,
    .baseBlock = 0x0039
};

static const struct ListMenuItem sEmptyListMenuItems[] = {
    { sText_EmptyString,  0 },
    { sText_EmptyString,  1 },
    { sText_EmptyString,  2 },
    { sText_EmptyString,  3 },
    { sText_EmptyString,  4 },
    { sText_EmptyString,  5 },
    { sText_EmptyString,  6 },
    { sText_EmptyString,  7 },
    { sText_EmptyString,  8 },
    { sText_EmptyString,  9 },
    { sText_EmptyString, 10 },
    { sText_EmptyString, 11 },
    { sText_EmptyString, 12 },
    { sText_EmptyString, 13 },
    { sText_EmptyString, 14 },
    { sText_EmptyString, 15 }
};

// Unused
static const struct ListMenuTemplate sEmptyListMenuTemplate = {
    .items = sEmptyListMenuItems,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = ItemPrintFunc_EmptyList,
    .totalItems = ARRAY_COUNT(sEmptyListMenuItems),
    .maxShowed = 4,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_MULTIPLE_SCROLL_DPAD,
    .fontId = FONT_NORMAL,
    .cursorKind = CURSOR_BLACK_ARROW
};

static const struct RfuPlayerData sUnionRoomPlayer_DummyRfu = {0};

ALIGNED(4) static const u8 sAcceptedActivityIds_SingleBattle[]    = {ACTIVITY_BATTLE_SINGLE, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_DoubleBattle[]    = {ACTIVITY_BATTLE_DOUBLE, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_MultiBattle[]     = {ACTIVITY_BATTLE_MULTI, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_Trade[]           = {ACTIVITY_TRADE, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_PokemonJump[]     = {ACTIVITY_POKEMON_JUMP, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_BerryCrush[]      = {ACTIVITY_BERRY_CRUSH, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_BerryPicking[]    = {ACTIVITY_BERRY_PICK, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_WonderCard[]      = {ACTIVITY_WONDER_CARD, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_WonderNews[]      = {ACTIVITY_WONDER_NEWS, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_Resume[]          = {
    IN_UNION_ROOM | ACTIVITY_NONE,
    IN_UNION_ROOM | ACTIVITY_BATTLE_SINGLE,
    IN_UNION_ROOM | ACTIVITY_TRADE,
    IN_UNION_ROOM | ACTIVITY_CHAT,
    IN_UNION_ROOM | ACTIVITY_CARD,
    IN_UNION_ROOM | ACTIVITY_ACCEPT,
    IN_UNION_ROOM | ACTIVITY_DECLINE,
    IN_UNION_ROOM | ACTIVITY_NPCTALK,
    IN_UNION_ROOM | ACTIVITY_PLYRTALK,
    0xff
};
ALIGNED(4) static const u8 sAcceptedActivityIds_Init[]            = {ACTIVITY_SEARCH, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_Unk11[]           = {
    ACTIVITY_BATTLE_SINGLE,
    ACTIVITY_BATTLE_DOUBLE,
    ACTIVITY_BATTLE_MULTI,
    ACTIVITY_TRADE,
    ACTIVITY_POKEMON_JUMP,
    ACTIVITY_BERRY_CRUSH,
    ACTIVITY_BERRY_PICK,
    ACTIVITY_WONDER_CARD,
    ACTIVITY_WONDER_NEWS,
    ACTIVITY_SPIN_TRADE,
    0xff
};
ALIGNED(4) static const u8 sAcceptedActivityIds_RecordCorner[]    = {ACTIVITY_RECORD_CORNER, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_BerryBlender[]    = {ACTIVITY_BERRY_BLENDER, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_CoolContest[]     = {ACTIVITY_CONTEST_COOL, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_BeautyContest[]   = {ACTIVITY_CONTEST_BEAUTY, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_CuteContest[]     = {ACTIVITY_CONTEST_CUTE, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_SmartContest[]    = {ACTIVITY_CONTEST_SMART, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_ToughContest[]    = {ACTIVITY_CONTEST_TOUGH, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_BattleTower[]     = {ACTIVITY_BATTLE_TOWER, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_BattleTowerOpen[] = {ACTIVITY_BATTLE_TOWER_OPEN, 0xff};

static const u8 *const sAcceptedActivityIds[NUM_LINK_GROUP_TYPES] = {
    [LINK_GROUP_SINGLE_BATTLE]     = sAcceptedActivityIds_SingleBattle,
    [LINK_GROUP_DOUBLE_BATTLE]     = sAcceptedActivityIds_DoubleBattle,
    [LINK_GROUP_MULTI_BATTLE]      = sAcceptedActivityIds_MultiBattle,
    [LINK_GROUP_TRADE]             = sAcceptedActivityIds_Trade,
    [LINK_GROUP_POKEMON_JUMP]      = sAcceptedActivityIds_PokemonJump,
    [LINK_GROUP_BERRY_CRUSH]       = sAcceptedActivityIds_BerryCrush,
    [LINK_GROUP_BERRY_PICKING]     = sAcceptedActivityIds_BerryPicking,
    [LINK_GROUP_WONDER_CARD]       = sAcceptedActivityIds_WonderCard,
    [LINK_GROUP_WONDER_NEWS]       = sAcceptedActivityIds_WonderNews,
    [LINK_GROUP_UNION_ROOM_RESUME] = sAcceptedActivityIds_Resume,
    [LINK_GROUP_UNION_ROOM_INIT]   = sAcceptedActivityIds_Init,
    [LINK_GROUP_UNK_11]            = sAcceptedActivityIds_Unk11,
    [LINK_GROUP_RECORD_CORNER]     = sAcceptedActivityIds_RecordCorner,
    [LINK_GROUP_BERRY_BLENDER]     = sAcceptedActivityIds_BerryBlender,
    [LINK_GROUP_UNK_14]            = NULL,
    [LINK_GROUP_COOL_CONTEST]      = sAcceptedActivityIds_CoolContest,
    [LINK_GROUP_BEAUTY_CONTEST]    = sAcceptedActivityIds_BeautyContest,
    [LINK_GROUP_CUTE_CONTEST]      = sAcceptedActivityIds_CuteContest,
    [LINK_GROUP_SMART_CONTEST]     = sAcceptedActivityIds_SmartContest,
    [LINK_GROUP_TOUGH_CONTEST]     = sAcceptedActivityIds_ToughContest,
    [LINK_GROUP_BATTLE_TOWER]      = sAcceptedActivityIds_BattleTower,
    [LINK_GROUP_BATTLE_TOWER_OPEN] = sAcceptedActivityIds_BattleTowerOpen
};

static const u8 sLinkGroupToURoomActivity[NUM_LINK_GROUP_TYPES + 2] =
{
    [LINK_GROUP_SINGLE_BATTLE]     = ACTIVITY_BATTLE_SINGLE,
    [LINK_GROUP_DOUBLE_BATTLE]     = ACTIVITY_BATTLE_DOUBLE,
    [LINK_GROUP_MULTI_BATTLE]      = ACTIVITY_BATTLE_MULTI,
    [LINK_GROUP_TRADE]             = ACTIVITY_TRADE,
    [LINK_GROUP_POKEMON_JUMP]      = ACTIVITY_POKEMON_JUMP,
    [LINK_GROUP_BERRY_CRUSH]       = ACTIVITY_BERRY_CRUSH,
    [LINK_GROUP_BERRY_PICKING]     = ACTIVITY_BERRY_PICK,
    [LINK_GROUP_WONDER_CARD]       = ACTIVITY_WONDER_CARD,
    [LINK_GROUP_WONDER_NEWS]       = ACTIVITY_WONDER_NEWS,
    [LINK_GROUP_UNION_ROOM_RESUME] = ACTIVITY_NONE,
    [LINK_GROUP_UNION_ROOM_INIT]   = ACTIVITY_NONE,
    [LINK_GROUP_UNK_11]            = ACTIVITY_NONE,
    [LINK_GROUP_RECORD_CORNER]     = ACTIVITY_RECORD_CORNER,
    [LINK_GROUP_BERRY_BLENDER]     = ACTIVITY_BERRY_BLENDER,
    [LINK_GROUP_UNK_14]            = ACTIVITY_NONE,
    [LINK_GROUP_COOL_CONTEST]      = ACTIVITY_CONTEST_COOL,
    [LINK_GROUP_BEAUTY_CONTEST]    = ACTIVITY_CONTEST_BEAUTY,
    [LINK_GROUP_CUTE_CONTEST]      = ACTIVITY_CONTEST_CUTE,
    [LINK_GROUP_SMART_CONTEST]     = ACTIVITY_CONTEST_SMART,
    [LINK_GROUP_TOUGH_CONTEST]     = ACTIVITY_CONTEST_TOUGH,
    [LINK_GROUP_BATTLE_TOWER]      = ACTIVITY_BATTLE_TOWER,
    [LINK_GROUP_BATTLE_TOWER_OPEN] = ACTIVITY_BATTLE_TOWER_OPEN
};

// BEGIN GENERATED LOCALIZATION EXPORTS
// These pointers expose file-local translated strings to the runtime resolver.
const u8 *const gLocalizationSource_C02406 = sText_PleaseStartOver;
const u8 *const gLocalizationSource_C02407 = sText_WirelessSearchCanceled;
const u8 *const gLocalizationSource_C02408 = sText_AwaitingCommunucation2;
const u8 *const gLocalizationSource_C02409 = sText_AwaitingCommunication;
const u8 *const gLocalizationSource_C02410 = sText_AwaitingLinkPressStart;
const u8 *const gLocalizationSource_C02411 = sText_1PlayerNeeded;
const u8 *const gLocalizationSource_C02412 = sText_2PlayersNeeded;
const u8 *const gLocalizationSource_C02413 = sText_3PlayersNeeded;
const u8 *const gLocalizationSource_C02414 = sText_4PlayersNeeded;
const u8 *const gLocalizationSource_C02415 = sText_PlayerContactedYouForXAccept;
const u8 *const gLocalizationSource_C02416 = sText_PlayerContactedYouShareX;
const u8 *const gLocalizationSource_C02417 = sText_PlayerContactedYouAddToMembers;
const u8 *const gLocalizationSource_C02418 = sText_AreTheseMembersOK;
const u8 *const gLocalizationSource_C02419 = sText_CancelModeWithTheseMembers;
const u8 *const gLocalizationSource_C02420 = sText_AnOKWasSentToPlayer;
const u8 *const gLocalizationSource_C02421 = sText_OtherTrainerUnavailableNow;
const u8 *const gLocalizationSource_C02422 = sText_CantTransmitTrainerTooFar;
const u8 *const gLocalizationSource_C02423 = sText_TrainersNotReadyYet;
const u8 *const gLocalizationSource_C02424 = sText_ModeWithTheseMembersWillBeCanceled;
const u8 *const gLocalizationSource_C02425 = sText_MemberNoLongerAvailable;
const u8 *const gLocalizationSource_C02426 = sText_TrainerAppearsUnavailable;
const u8 *const gLocalizationSource_C02427 = sText_PlayerSentBackOK;
const u8 *const gLocalizationSource_C02428 = sText_PlayerOKdRegistration;
const u8 *const gLocalizationSource_C02429 = sText_PlayerRepliedNo;
const u8 *const gLocalizationSource_C02430 = sText_AwaitingOtherMembers;
const u8 *const gLocalizationSource_C02431 = sText_QuitBeingMember;
const u8 *const gLocalizationSource_C02432 = sText_StoppedBeingMember;
const u8 *const gLocalizationSource_C02433 = sText_WirelessLinkEstablished;
const u8 *const gLocalizationSource_C02434 = sText_WirelessLinkDropped;
const u8 *const gLocalizationSource_C02435 = sText_LinkWithFriendDropped;
const u8 *const gLocalizationSource_C02436 = sText_PlayerRepliedNo2;
const u8 *const gLocalizationSource_C02437 = sText_DoYouWantXMode;
const u8 *const gLocalizationSource_C02438 = sText_DoYouWantXMode2;
const u8 *const gLocalizationSource_C02439 = sText_CommunicatingPleaseWait;
const u8 *const gLocalizationSource_C02440 = sText_AwaitingPlayersResponseAboutTrade;
const u8 *const gLocalizationSource_C02441 = sText_Communicating;
const u8 *const gLocalizationSource_C02442 = sText_CommunicatingWithPlayer;
const u8 *const gLocalizationSource_C02443 = sText_PleaseWaitAWhile;
const u8 *const gLocalizationSource_C02444 = sText_HiDoSomethingMale;
const u8 *const gLocalizationSource_C02445 = sText_HiDoSomethingFemale;
const u8 *const gLocalizationSource_C02446 = sText_HiDoSomethingAgainMale;
const u8 *const gLocalizationSource_C02447 = sText_HiDoSomethingAgainFemale;
const u8 *const gLocalizationSource_C02448 = sText_DoSomethingMale;
const u8 *const gLocalizationSource_C02449 = sText_DoSomethingFemale;
const u8 *const gLocalizationSource_C02450 = sText_DoSomethingAgainMale;
const u8 *const gLocalizationSource_C02451 = sText_DoSomethingAgainFemale;
const u8 *const gLocalizationSource_C02452 = sText_SomebodyHasContactedYou;
const u8 *const gLocalizationSource_C02453 = sText_PlayerHasContactedYou;
const u8 *const gLocalizationSource_C02454 = sText_AwaitingResponseFromTrainer;
const u8 *const gLocalizationSource_C02455 = sText_AwaitingResponseFromPlayer;
const u8 *const gLocalizationSource_C02456 = sText_ShowTrainerCard;
const u8 *const gLocalizationSource_C02457 = sText_BattleChallenge;
const u8 *const gLocalizationSource_C02458 = sText_ChatInvitation;
const u8 *const gLocalizationSource_C02459 = sText_OfferToTradeMon;
const u8 *const gLocalizationSource_C02460 = sText_OfferToTradeEgg;
const u8 *const gLocalizationSource_C02461 = sText_ChatDropped;
const u8 *const gLocalizationSource_C02462 = sText_OfferDeclined1;
const u8 *const gLocalizationSource_C02463 = sText_OfferDeclined2;
const u8 *const gLocalizationSource_C02464 = sText_ChatEnded;
const u8 *const gLocalizationSource_C02465 = sText_JoinChatMale;
const u8 *const gLocalizationSource_C02466 = sText_PlayerJoinChatMale;
const u8 *const gLocalizationSource_C02467 = sText_JoinChatFemale;
const u8 *const gLocalizationSource_C02468 = sText_PlayerJoinChatFemale;
const u8 *const gLocalizationSource_C02469 = sText_TrainerAppearsBusy;
const u8 *const gLocalizationSource_C02470 = sText_WaitForBattleMale;
const u8 *const gLocalizationSource_C02471 = sText_WaitForChatMale;
const u8 *const gLocalizationSource_C02472 = sText_ShowTrainerCardMale;
const u8 *const gLocalizationSource_C02473 = sText_WaitForBattleFemale;
const u8 *const gLocalizationSource_C02474 = sText_WaitForChatFemale;
const u8 *const gLocalizationSource_C02475 = sText_ShowTrainerCardFemale;
const u8 *const gLocalizationSource_C02476 = sText_WaitForChatMale2;
const u8 *const gLocalizationSource_C02477 = sText_DoneWaitingBattleMale;
const u8 *const gLocalizationSource_C02478 = sText_DoneWaitingChatMale;
const u8 *const gLocalizationSource_C02479 = sText_DoneWaitingBattleFemale;
const u8 *const gLocalizationSource_C02480 = sText_DoneWaitingChatFemale;
const u8 *const gLocalizationSource_C02481 = sText_TradeWillBeStarted;
const u8 *const gLocalizationSource_C02482 = sText_BattleWillBeStarted;
const u8 *const gLocalizationSource_C02483 = sText_EnteringChat;
const u8 *const gLocalizationSource_C02484 = sText_BattleDeclinedMale;
const u8 *const gLocalizationSource_C02485 = sText_BattleDeclinedFemale;
const u8 *const gLocalizationSource_C02486 = sText_ShowTrainerCardDeclinedMale;
const u8 *const gLocalizationSource_C02487 = sText_ShowTrainerCardDeclinedFemale;
const u8 *const gLocalizationSource_C02488 = sText_IfYouWantToDoSomethingMale;
const u8 *const gLocalizationSource_C02489 = sText_IfYouWantToDoSomethingFemale;
const u8 *const gLocalizationSource_C02490 = sText_TrainerBattleBusy;
const u8 *const gLocalizationSource_C02491 = sText_NeedTwoMonsOfLevel30OrLower1;
const u8 *const gLocalizationSource_C02492 = sText_NeedTwoMonsOfLevel30OrLower2;
const u8 *const gLocalizationSource_C02493 = sText_DeclineChatMale;
const u8 *const gLocalizationSource_C02494 = stext_DeclineChatFemale;
const u8 *const gLocalizationSource_C02495 = sText_ChatDeclinedMale;
const u8 *const gLocalizationSource_C02496 = sText_ChatDeclinedFemale;
const u8 *const gLocalizationSource_C02497 = sText_YoureToughMale;
const u8 *const gLocalizationSource_C02498 = sText_UsedGoodMoveMale;
const u8 *const gLocalizationSource_C02499 = sText_BattleSurpriseMale;
const u8 *const gLocalizationSource_C02500 = sText_SwitchedMonsMale;
const u8 *const gLocalizationSource_C02501 = sText_YoureToughFemale;
const u8 *const gLocalizationSource_C02502 = sText_UsedGoodMoveFemale;
const u8 *const gLocalizationSource_C02503 = sText_BattleSurpriseFemale;
const u8 *const gLocalizationSource_C02504 = sText_SwitchedMonsFemale;
const u8 *const gLocalizationSource_C02505 = sText_LearnedSomethingMale;
const u8 *const gLocalizationSource_C02506 = sText_ThatsFunnyMale;
const u8 *const gLocalizationSource_C02507 = sText_RandomChatMale1;
const u8 *const gLocalizationSource_C02508 = sText_RandomChatMale2;
const u8 *const gLocalizationSource_C02509 = sText_LearnedSomethingFemale;
const u8 *const gLocalizationSource_C02510 = sText_ThatsFunnyFemale;
const u8 *const gLocalizationSource_C02511 = sText_RandomChatFemale1;
const u8 *const gLocalizationSource_C02512 = sText_RandomChatFemale2;
const u8 *const gLocalizationSource_C02513 = sText_ShowedTrainerCardMale1;
const u8 *const gLocalizationSource_C02514 = sText_ShowedTrainerCardMale2;
const u8 *const gLocalizationSource_C02515 = sText_ShowedTrainerCardFemale1;
const u8 *const gLocalizationSource_C02516 = sText_ShowedTrainerCardFemale2;
const u8 *const gLocalizationSource_C02517 = sText_MaleTraded1;
const u8 *const gLocalizationSource_C02518 = sText_MaleTraded2;
const u8 *const gLocalizationSource_C02519 = sText_FemaleTraded1;
const u8 *const gLocalizationSource_C02520 = sText_FemaleTraded2;
const u8 *const gLocalizationSource_C02521 = sText_XCheckedTradingBoard;
const u8 *const gLocalizationSource_C02522 = sText_RegisterMonAtTradingBoard;
const u8 *const gLocalizationSource_C02523 = sText_TradingBoardInfo;
const u8 *const gLocalizationSource_C02524 = sText_ThankYouForRegistering;
const u8 *const gLocalizationSource_C02525 = sText_NobodyHasRegistered;
const u8 *const gLocalizationSource_C02526 = sText_ChooseRequestedMonType;
const u8 *const gLocalizationSource_C02527 = sText_WhichMonWillYouOffer;
const u8 *const gLocalizationSource_C02528 = sText_RegistrationCanceled;
const u8 *const gLocalizationSource_C02529 = sText_RegistrationCompleted;
const u8 *const gLocalizationSource_C02530 = sText_TradeCanceled;
const u8 *const gLocalizationSource_C02531 = sText_CancelRegistrationOfMon;
const u8 *const gLocalizationSource_C02532 = sText_CancelRegistrationOfEgg;
const u8 *const gLocalizationSource_C02533 = sText_RegistrationCanceled2;
const u8 *const gLocalizationSource_C02534 = sText_TradeTrainersWillBeListed;
const u8 *const gLocalizationSource_C02535 = sText_ChooseTrainerToTradeWith2;
const u8 *const gLocalizationSource_C02536 = sText_AskTrainerToMakeTrade;
const u8 *const gLocalizationSource_C02537 = sText_AwaitingResponseFromTrainer2;
const u8 *const gLocalizationSource_C02538 = sText_NotRegisteredAMonForTrade;
const u8 *const gLocalizationSource_C02539 = sText_DontHaveTypeTrainerWants;
const u8 *const gLocalizationSource_C02540 = sText_DontHaveEggTrainerWants;
const u8 *const gLocalizationSource_C02541 = sText_PlayerCantTradeForYourMon;
const u8 *const gLocalizationSource_C02542 = sText_CantTradeForPartnersMon;
const u8 *const gLocalizationSource_C02543 = sText_TradeOfferRejected;
const u8 *const gLocalizationSource_C02544 = sText_ChooseTrainer;
const u8 *const gLocalizationSource_C02545 = sText_ChooseTrainerSingleBattle;
const u8 *const gLocalizationSource_C02546 = sText_ChooseTrainerDoubleBattle;
const u8 *const gLocalizationSource_C02547 = sText_ChooseLeaderMultiBattle;
const u8 *const gLocalizationSource_C02548 = sText_ChooseTrainerToTradeWith;
const u8 *const gLocalizationSource_C02549 = sText_ChooseTrainerToShareWonderCards;
const u8 *const gLocalizationSource_C02550 = sText_ChooseTrainerToShareWonderNews;
const u8 *const gLocalizationSource_C02551 = sText_ChooseLeaderPokemonJump;
const u8 *const gLocalizationSource_C02552 = sText_ChooseLeaderBerryCrush;
const u8 *const gLocalizationSource_C02553 = sText_ChooseLeaderBerryPicking;
const u8 *const gLocalizationSource_C02554 = sText_ChooseLeaderBerryBlender;
const u8 *const gLocalizationSource_C02555 = sText_ChooseLeaderRecordCorner;
const u8 *const gLocalizationSource_C02556 = sText_ChooseLeaderCoolContest;
const u8 *const gLocalizationSource_C02557 = sText_ChooseLeaderBeautyContest;
const u8 *const gLocalizationSource_C02558 = sText_ChooseLeaderCuteContest;
const u8 *const gLocalizationSource_C02559 = sText_ChooseLeaderSmartContest;
const u8 *const gLocalizationSource_C02560 = sText_ChooseLeaderToughContest;
const u8 *const gLocalizationSource_C02561 = sText_ChooseLeaderBattleTowerLv50;
const u8 *const gLocalizationSource_C02562 = sText_ChooseLeaderBattleTowerOpenLv;
const u8 *const gLocalizationSource_C02563 = sText_SearchingForWirelessSystemWait;
const u8 *const gLocalizationSource_C02564 = sText_MustHaveTwoMonsForDoubleBattle;
const u8 *const gLocalizationSource_C02565 = sText_AwaitingPlayersResponse;
const u8 *const gLocalizationSource_C02566 = sText_PlayerHasBeenAskedToRegisterYouPleaseWait;
const u8 *const gLocalizationSource_C02567 = sText_AwaitingResponseFromWirelessSystem;
const u8 *const gLocalizationSource_C02568 = sText_PleaseWaitForOtherTrainersToGather;
const u8 *const gLocalizationSource_C02569 = sText_NoCardsSharedRightNow;
const u8 *const gLocalizationSource_C02570 = sText_NoNewsSharedRightNow;
const u8 *const gLocalizationSource_C02571 = sText_ItsNormalCard;
const u8 *const gLocalizationSource_C02572 = sText_ItsBronzeCard;
const u8 *const gLocalizationSource_C02573 = sText_ItsCopperCard;
const u8 *const gLocalizationSource_C02574 = sText_ItsSilverCard;
const u8 *const gLocalizationSource_C02575 = sText_ItsGoldCard;
const u8 *const gLocalizationSource_C02576 = sText_TrainerCardInfoPage1;
const u8 *const gLocalizationSource_C02577 = sText_GladToMeetYouMale;
const u8 *const gLocalizationSource_C02578 = sText_GladToMeetYouFemale;
const u8 *const gLocalizationSource_C02579 = sText_FinishedCheckingPlayersTrainerCard;
// END GENERATED LOCALIZATION EXPORTS
