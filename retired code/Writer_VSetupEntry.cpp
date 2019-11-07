//Copyright 2015-2019, All Rights Reserved.

#include "Ui/Writer_VSetupEntry.h"
#include "Ui/Writer_VSetup.h"

#include "Components/ScrollBox.h"
#include "System/Class.h"


UWriter_VSetupEntry* UWriter_VSetupEntry::Create(UWorld* InScope, UWriter_VSetup* InView, UAtlas* InAtlas, UScrollBox* InBox)
{
	UWriter_VSetupEntry* Neu = CreateWidget<UWriter_VSetupEntry>(InScope,ClassC::Writer_VSetupEntry());
	Neu->Init(InView,InAtlas,InBox);
	return Neu;
}

void UWriter_VSetupEntry::Init(UWriter_VSetup* InView, UAtlas* InAtlas, UScrollBox* InBox)
{
	RView_ = InView;
	Atlas_ = InAtlas;
	InBox->AddChild(this);
	Ready();
}

UAtlas* UWriter_VSetupEntry::Atlas()
{
	return Atlas_;
}

UWriter_VSetup* UWriter_VSetupEntry::RView()
{
	return RView_;
}

void UWriter_VSetupEntry::SetInterface(UUi_Bool* InMaster, UUi_Bool* InSupport)
{
	Master_ = InMaster;
	Support_ = InSupport;
}