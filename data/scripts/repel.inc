EventScript_RepelWoreOff::
	msgbox Text_RepelWoreOff, MSGBOX_SIGN
	call EventScript_SelectRepelToReuse
	goto_if_eq VAR_RESULT, FALSE, EventScript_RepelWoreOff_End
	bufferitemname STR_VAR_2, VAR_0x8004
	msgbox Text_UseAnotherRepel, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_RepelWoreOff_End

EventScript_UseAnotherRepel::
	removeitem VAR_0x8004, 1
	special GetItemHoldEffectParam_Script
	copyvar VAR_REPEL_LAST_USED, VAR_0x8004
	playse SE_REPEL
	msgbox gText_PlayerUsedVar2NoPause, MSGBOX_SIGN

EventScript_RepelWoreOff_End::
	closemessage
	end

Text_RepelWoreOff:
	.string "REPEL's effect wore off…$"

Text_UseAnotherRepel:
	.string "Would you like to use\n"
	.string "another {STR_VAR_2}?$"

EventScript_SelectRepelToReuse::
	copyvar VAR_0x8004, VAR_REPEL_LAST_USED
	checkitem VAR_0x8004, 1
	goto_if_eq VAR_RESULT, TRUE, EventScript_EndSelectRepelToReuse
	call EventScript_CycleThroughRepels

EventScript_EndSelectRepelToReuse::
	return

EventScript_CycleThroughRepels::
	setvar VAR_RESULT, TRUE

EventScript_TryUseRepel::
	setvar VAR_0x8004, ITEM_REPEL
	checkitem VAR_0x8004, 1
	goto_if_eq VAR_RESULT, TRUE, EventScript_EndCycleThroughRepels

EventScript_TryUseSuperRepel::
	setvar VAR_0x8004, ITEM_SUPER_REPEL
	checkitem VAR_0x8004, 1
	goto_if_eq VAR_RESULT, TRUE, EventScript_EndCycleThroughRepels

EventScript_TryUseMaxRepel::
	setvar VAR_0x8004, ITEM_MAX_REPEL
	checkitem VAR_0x8004, 1

EventScript_EndCycleThroughRepels::
	return
