//Copyright 2015-2019, All Rights Reserved.

#include "Ui/Writer_VFormEntry.h"
#include "Ui/Writer_VForm.h"

#include "Form/FormF.h"
#include "Components/ScrollBox.h"
#include "System/Class.h"



UWriter_VFormEntry* UWriter_VFormEntry::Create(UWorld* InScope, UWriter_VForm* InView, FormWrapS InFormW, UScrollBox* InBox)
{
	UWriter_VFormEntry* Neu = CreateWidget<UWriter_VFormEntry>(InScope,ClassC::Writer_VFormEntry());
	Neu->Init(InView,InFormW,InBox);
	return Neu;
}

void UWriter_VFormEntry::Init(UWriter_VForm* InView, FormWrapS InFormW, UScrollBox* InBox)
{
	RView_ = InView;
	FormW_ = InFormW;
	InBox->AddChild(this);
	Ready();
}

UWriter_VForm* UWriter_VFormEntry::RView()
{
	return RView_;
}

FString UWriter_VFormEntry::GetFormID()
{
	return FormW_.Form()->ID().ToFString();
}

int UWriter_VFormEntry::GetFormUID()
{
	return FormW_.Form()->UID().ForUI();
}