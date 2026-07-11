.set ITEMID, VAR_0x8000
.set AMOUNT, VAR_0x8001
.set ITEM_STORAGE_NONE, 0
.set ITEM_STORAGE_BAG, 1
.set ITEM_STORAGE_PC, 2

Std_ObtainItem::
	copyvar VAR_0x8004, ITEMID
	copyvar VAR_0x8005, AMOUNT
	additem ITEMID, AMOUNT
	copyvar VAR_0x8007, VAR_RESULT
	call_if_eq VAR_0x8007, ITEM_STORAGE_NONE, EventScript_TryAddItemToPC
	call EventScript_ObtainItemMessage
	return

EventScript_TryAddItemToPC::
	checkitemtype VAR_0x8004
	goto_if_eq VAR_RESULT, POCKET_KEY_ITEMS, EventScript_TryAddItemToPCEnd
	copyvar VAR_0x8008, VAR_0x8004
	pyramid_getlocation
	copyvar VAR_0x8004, VAR_0x8008
	goto_if_ne VAR_RESULT, PYRAMID_LOCATION_NONE, EventScript_TryAddItemToPCEnd
	addpcitem VAR_0x8004, VAR_0x8005
	goto_if_eq VAR_RESULT, FALSE, EventScript_TryAddItemToPCEnd
	setvar VAR_0x8007, ITEM_STORAGE_PC
EventScript_TryAddItemToPCEnd::
	return

EventScript_ObtainItemMessage::
	bufferitemnameplural STR_VAR_2, ITEMID, AMOUNT
	checkitemtype ITEMID
	call EventScript_BufferPocketNameAndTryFanfare
	call_if_ne VAR_0x8007, ITEM_STORAGE_NONE, EventScript_ObtainedItem
	call_if_eq VAR_0x8007, ITEM_STORAGE_NONE, EventScript_NoRoomForItem
	return

EventScript_BufferPocketNameAndTryFanfare::
	switch VAR_RESULT
	case POCKET_ITEMS,      EventScript_BufferItemsPocket
	case POCKET_KEY_ITEMS,  EventScript_BufferKeyItemsPocket
	case POCKET_POKE_BALLS, EventScript_BufferPokeballsPocket
	case POCKET_TM_HM,      EventScript_BufferTMHMsPocket
	case POCKET_BERRIES,    EventScript_BufferBerriesPocket
	end

EventScript_BufferItemsPocket::
	bufferstdstring STR_VAR_3, STDSTRING_ITEMS
	call_if_ne VAR_0x8007, ITEM_STORAGE_NONE, EventScript_PlayFanfareObtainedItem
	return

EventScript_BufferKeyItemsPocket::
	bufferstdstring STR_VAR_3, STDSTRING_KEYITEMS
	call_if_ne VAR_0x8007, ITEM_STORAGE_NONE, EventScript_PlayFanfareObtainedItem
	return

EventScript_BufferPokeballsPocket::
	bufferstdstring STR_VAR_3, STDSTRING_POKEBALLS
	call_if_ne VAR_0x8007, ITEM_STORAGE_NONE, EventScript_PlayFanfareObtainedItem
	return

EventScript_BufferTMHMsPocket::
	bufferstdstring STR_VAR_3, STDSTRING_TMHMS
	call_if_ne VAR_0x8007, ITEM_STORAGE_NONE, EventScript_PlayFanfareObtainedTMHM
	return

EventScript_BufferBerriesPocket::
	bufferstdstring STR_VAR_3, STDSTRING_BERRIES
	call_if_ne VAR_0x8007, ITEM_STORAGE_NONE, EventScript_PlayFanfareObtainedItem
	return

EventScript_ObtainedItem::
	message gText_ObtainedTheItem
	waitfanfare
	call EventScript_PutItemMessage
	setvar VAR_RESULT, TRUE
	return

EventScript_NoRoomForItem::
	setvar VAR_RESULT, FALSE
	return

EventScript_PlayFanfareObtainedItem::
	playfanfare MUS_OBTAIN_ITEM
	return

EventScript_PlayFanfareObtainedTMHM::
	playfanfare MUS_OBTAIN_TMHM
	return

Std_ObtainDecoration::
	adddecoration ITEMID
	copyvar VAR_0x8007, VAR_RESULT
	call EventScript_ObtainDecorationMessage
	return

EventScript_ObtainDecorationMessage::
	bufferdecorationname STR_VAR_2, ITEMID
	call_if_eq VAR_0x8007, TRUE, EventScript_ObtainedDecor
	call_if_eq VAR_0x8007, FALSE, EventScript_NoRoomForDecor
	return

EventScript_ObtainedDecor::
	playfanfare MUS_OBTAIN_ITEM
	message gText_ObtainedTheDecor
	waitfanfare
	msgbox gText_TheDecorWasTransferredToThePC, MSGBOX_DEFAULT
	setvar VAR_RESULT, TRUE
	return

EventScript_NoRoomForDecor::
	setvar VAR_RESULT, FALSE
	return

Std_FindItem::
	lock
	faceplayer
	waitse
	copyvar VAR_0x8004, ITEMID
	copyvar VAR_0x8005, AMOUNT
	checkitemspace ITEMID, AMOUNT
	copyvar VAR_0x8007, VAR_RESULT
	call_if_eq VAR_0x8007, ITEM_STORAGE_NONE, EventScript_TryAddItemToPC
	bufferitemnameplural STR_VAR_2, ITEMID, AMOUNT
	checkitemtype ITEMID
	call EventScript_BufferPocketNameAndTryFanfare
	call_if_ne VAR_0x8007, ITEM_STORAGE_NONE, EventScript_PickUpItem
	call_if_eq VAR_0x8007, ITEM_STORAGE_NONE, EventScript_NoRoomToPickUpItem
	release
	return

EventScript_PickUpItem::
	removeobject VAR_LAST_TALKED
	goto_if_eq VAR_0x8007, ITEM_STORAGE_PC, EventScript_PickUpItemAdded
	additem VAR_0x8004, VAR_0x8005
EventScript_PickUpItemAdded::
	specialvar VAR_RESULT, BufferTMHMMoveName
	copyvar VAR_0x8008, VAR_RESULT
	call_if_eq VAR_0x8008, TRUE, EventScript_FoundTMHM
	call_if_eq VAR_0x8008, FALSE, EventScript_FoundItem
	waitfanfare
	waitmessage
	bufferitemnameplural STR_VAR_2, VAR_0x8004, VAR_0x8005
	pyramid_getlocation
	goto_if_eq VAR_RESULT, PYRAMID_LOCATION_FLOOR, EventScript_PutBattlePyramidItemInBag
	call EventScript_PutItemMessage
	return

EventScript_PutBattlePyramidItemInBag::
	msgbox gText_PlayerPutItemInBag, MSGBOX_DEFAULT
	return

EventScript_FoundTMHM::
	bufferitemnameplural STR_VAR_1, VAR_0x8004, VAR_0x8005
	message gText_PlayerFoundOneTMHM
	return

EventScript_FoundItem::
	message gText_PlayerFoundOneItem
	return

EventScript_NoRoomToPickUpItem::
	msgbox gText_ObtainedTheItem, MSGBOX_DEFAULT
	call EventScript_ShowNoRoomForItem
	setvar VAR_RESULT, FALSE
	return

EventScript_HiddenItemScript::
	lockall
	waitse
	copyvar VAR_0x8009, VAR_0x8004
	additem VAR_0x8005
	copyvar VAR_0x8007, VAR_RESULT
	copyvar VAR_0x8004, VAR_0x8005
	setvar VAR_0x8005, 1
	call_if_eq VAR_0x8007, ITEM_STORAGE_NONE, EventScript_TryAddItemToPC
	bufferitemnameplural STR_VAR_2, VAR_0x8004, VAR_0x8005
	checkitemtype VAR_0x8004
	call EventScript_BufferPocketNameAndTryFanfare
	goto_if_ne VAR_0x8007, ITEM_STORAGE_NONE, EventScript_PickUpHiddenItem
	goto_if_eq VAR_0x8007, ITEM_STORAGE_NONE, EventScript_NoRoomForHiddenItem
	end

EventScript_PickUpHiddenItem::
	specialvar VAR_RESULT, BufferTMHMMoveName
	goto_if_eq VAR_RESULT, TRUE, EventScript_FoundHiddenTMHM
	goto_if_eq VAR_RESULT, FALSE, EventScript_FoundHiddenItem
	end

EventScript_FoundHiddenTMHM::
	bufferitemnameplural STR_VAR_1, VAR_0x8004, 1
	message gText_PlayerFoundOneTMHM
	goto EventScript_PutHiddenItemInPocket
	end

EventScript_FoundHiddenItem::
	message gText_PlayerFoundOneItem
	goto EventScript_PutHiddenItemInPocket
	end

EventScript_PutHiddenItemInPocket::
	waitmessage
	waitfanfare
	bufferitemnameplural STR_VAR_2, VAR_0x8004, VAR_0x8005
	copyvar VAR_0x8005, VAR_0x8004
	copyvar VAR_0x8004, VAR_0x8009
	call EventScript_PutItemMessage
	special TryPutTreasureInvestigatorsOnAir
	special SetHiddenItemFlag
	releaseall
	end

EventScript_NoRoomForHiddenItem::
	msgbox gText_PlayerFoundOneItem, MSGBOX_DEFAULT
	call EventScript_ShowNoRoomForItem
	setvar VAR_RESULT, 0
	releaseall
	end

EventScript_PutItemMessage::
	goto_if_eq VAR_0x8007, ITEM_STORAGE_PC, EventScript_PutItemInPCMessage
	msgbox gText_PutItemInPocket, MSGBOX_DEFAULT
	return

EventScript_PutItemInPCMessage::
	msgbox gText_PutItemInPC, MSGBOX_DEFAULT
	return

EventScript_ShowNoRoomForItem::
	checkitemtype VAR_0x8004
	goto_if_eq VAR_RESULT, POCKET_KEY_ITEMS, EventScript_ShowBagIsFull
	copyvar VAR_0x8008, VAR_0x8004
	pyramid_getlocation
	copyvar VAR_0x8004, VAR_0x8008
	goto_if_ne VAR_RESULT, PYRAMID_LOCATION_NONE, EventScript_ShowBagIsFull
	msgbox gText_TooBadBagAndPCAreFull, MSGBOX_DEFAULT
	return

EventScript_ShowBagIsFull::
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	return
