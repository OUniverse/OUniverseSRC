//Copyright 2015-2019, All Rights Reserved.

#include "Ui/Writer/WRI_VFormEntry.h"
#include "Ui/Writer/WRI_VForm.h"

#include "Form/FormF.h"
#include "Ui/Ui_Catch.h"
#include "System/Class.h"

#include "Components/TextBlock.h"


void UWRI_VFormEntry::NativeConstruct()
{
	V_Catch->SetRelay(this);
	V_Text->SetText(FText::FromString(FormW_.Form()->ID().ToChar()));

	Super::NativeConstruct();
}

UWRI_VFormEntry* UWRI_VFormEntry::Create(UWorld* InScope, UWRI_VForm* InView, FormWrapS InFormW)
{
	UWRI_VFormEntry* Neu = CreateWidget<UWRI_VFormEntry>(InScope,ClassC::WRI_VFormEntry());
	Neu->Init(InView,InFormW);
	return Neu;
}

void UWRI_VFormEntry::Init(UWRI_VForm* InView, FormWrapS InFormW)
{
	View_ = InView;
	FormW_ = InFormW;
}

void UWRI_VFormEntry::Clicked()
{
	(Cast<UWRI_VForm>(View_))->FormSelected(FormW_);
}