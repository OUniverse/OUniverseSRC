//Copyright 2015-2019, All Rights Reserved.

#include "Ui/Sym_VUserEntry.h"
#include "Ui/Sym_VUser.h"
#include "Components/ScrollBox.h"
#include "System/Class.h"


USym_VUserEntry* USym_VUserEntry::Create(UWorld* InScope, USym_VUser* InView, UScrollBox* InBox)
{
	USym_VUserEntry* Neu = CreateWidget<USym_VUserEntry>(InScope,ClassC::Sym_VUserEntry());
	Neu->Init(InView,InBox);
	return Neu;
}

void USym_VUserEntry::Init(USym_VUser* InView, UScrollBox* InBox)
{
	View_ = InView;
	InBox->AddChild(this);
	Ready();
}

USym_VUser* USym_VUserEntry::View()
{
	return View_;
}