//Copyright 2015-2019, All Rights Reserved.

#include "Ui/Writer/WRI_FormEdit_Le.h"
#include "Ui/Writer/WRI_FormEdit.h"

#include "Form/FormF.h"
#include "System/Class.h"

#include "Components/TextBlock.h"


void UWRI_FormEdit_Le::NativeConstruct()
{
	V_Text->SetText(FText::FromString(FormW_.Form()->ID().ToChar()));

	Super::NativeConstruct();
}

UWRI_FormEdit_Le* UWRI_FormEdit_Le::Create(UWorld* InScope, UWRI_FormEdit* InView, FormWrapS InFormW)
{
	UWRI_FormEdit_Le* Neu = CreateWidget<UWRI_FormEdit_Le>(InScope,ClassC::WRI_FormEdit_Le());
	Neu->Init(InView,InFormW);
	return Neu;
}

void UWRI_FormEdit_Le::Init(UWRI_FormEdit* InView, FormWrapS InFormW)
{
	View_ = InView;
	FormW_ = InFormW;
}

void UWRI_FormEdit_Le::OnClick()
{
	(Cast<UWRI_FormEdit>(View_))->FormSelected(FormW_);
}