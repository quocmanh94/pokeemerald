SootopolisCity_House2_MapScripts::
	.byte 0

SootopolisCity_House2_EventScript_ExpertF::
	lock
	faceplayer
	msgbox SootopolisCity_House2_Text_DidYouKnowAboutMtPyreOrbs, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, SootopolisCity_House2_EventScript_KnowAboutOrbs
	call_if_eq VAR_RESULT, NO, SootopolisCity_House2_EventScript_DontKnowAboutOrbs
	release
	end

SootopolisCity_House2_EventScript_KnowAboutOrbs::
	msgbox SootopolisCity_House2_Text_YesTwoOrbsSideBySide, MSGBOX_DEFAULT
	return

SootopolisCity_House2_EventScript_DontKnowAboutOrbs::
	msgbox SootopolisCity_House2_Text_OughtToVisitAndSee, MSGBOX_DEFAULT
	return

SootopolisCity_House2_Text_DidYouKnowAboutMtPyreOrbs:
	.string "MT. PYRE...\p"
	.string "Trên đỉnh núi có hai quả cầu được đặt\n"
	.string "cạnh nhau. Bạn có biết không?$"

SootopolisCity_House2_Text_YesTwoOrbsSideBySide:
	.string "Đúng vậy, hai quả cầu nằm cạnh nhau...\p"
	.string "Cảnh chúng ở bên nhau... Không hiểu sao\n"
	.string "lại khiến lòng người thanh thản...$"

SootopolisCity_House2_Text_OughtToVisitAndSee:
	.string "Vậy sao? Có lẽ bạn nên tới đó tận mắt\n"
	.string "xem thử...$"

@ BEGIN GENERATED LOCALIZATION EXPORTS
	.global SootopolisCity_House2_Text_DidYouKnowAboutMtPyreOrbs
	.global SootopolisCity_House2_Text_YesTwoOrbsSideBySide
	.global SootopolisCity_House2_Text_OughtToVisitAndSee
@ END GENERATED LOCALIZATION EXPORTS
