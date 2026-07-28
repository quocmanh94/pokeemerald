RustboroCity_Flat2_2F_MapScripts::
	.byte 0

RustboroCity_Flat2_2F_EventScript_OldMan::
	msgbox RustboroCity_Flat2_2F_Text_DevonWasTinyInOldDays, MSGBOX_NPC
	end

RustboroCity_Flat2_2F_EventScript_NinjaBoy::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_PREMIER_BALL_RUSTBORO, RustboroCity_Flat2_2F_EventScript_GavePremierBall
	msgbox RustboroCity_Flat2_2F_Text_MyDaddyMadeThisYouCanHaveIt, MSGBOX_DEFAULT
	giveitem ITEM_PREMIER_BALL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_PREMIER_BALL_RUSTBORO
	release
	end

RustboroCity_Flat2_2F_EventScript_GavePremierBall::
	msgbox RustboroCity_Flat2_2F_Text_GoingToWorkAtDevonToo, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat2_2F_Text_DevonWasTinyInOldDays:
	.string "Ngày xửa ngày xưa, DEVON chỉ là một\n"
	.string "công ty bé tí tẹo.$"

RustboroCity_Flat2_2F_Text_MyDaddyMadeThisYouCanHaveIt:
	.string "Ba tớ làm việc ở CORPORATION.\p"
	.string "Cái này do ba tớ làm đấy! Nhưng tớ\n"
	.string "không dùng được nên cho cậu này.$"

RustboroCity_Flat2_2F_Text_GoingToWorkAtDevonToo:
	.string "Ba tớ làm việc ở CORPORATION.\p"
	.string "Khi lớn lên, tớ cũng sẽ làm việc cho\n"
	.string "DEVON.$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global RustboroCity_Flat2_2F_Text_DevonWasTinyInOldDays
	.global RustboroCity_Flat2_2F_Text_MyDaddyMadeThisYouCanHaveIt
	.global RustboroCity_Flat2_2F_Text_GoingToWorkAtDevonToo
@ END GENERATED LOCALIZATION EXPORTS
