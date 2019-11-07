//Copyright 2015-2019, All Rights Reserved.

#include "Ui/Writer/WRI_VFormEntry.h"
#include "Ui/Writer/WRI_VForm.h"

#include "Form/FormF.h"
#include "Components/ScrollBox.h"
#include "System/Class.h"



void UWRI_VFormEntry::NativeConstruct()
{

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

UWRI_VForm* UWRI_VFormEntry::View()
{
	return View_;
}

FString UWRI_VFormEntry::GetFormID()
{
	return FormW_.Form()->ID().ToFString();
}

int UWRI_VFormEntry::GetFormUID()
{
	return FormW_.Form()->UID().ForUI();
}