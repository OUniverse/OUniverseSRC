//Copyright 2015-2019, All Rights Reserved.

#include "Ui/Writer_VSetup.h"
#include "Ui/Writer_Master.h"
#include "Ui/Writer_VSetupEntry.h"
#include "Ui/Ui_Bool.h"

#include "Components/CanvasPanel.h"
#include "Components/CanvasPanelSlot.h"
#include "System/Class.h"


UWriter_VSetup* UWriter_VSetup::Create(UUi_Master* InMaster, UCanvasPanel* InPanel)
{
	UWriter_VSetup* Neu = CreateWidget<UWriter_VSetup>(InMaster->Scope(),ClassC::Writer_VSetup());
	Neu->Init(InMaster,InPanel);
	return Neu;
}

void UWriter_VSetup::Init(UUi_Master* InMaster, UCanvasPanel* InPanel)
{
	ActiveEntry_ = NULL;
	CreateViewer();
	SetMaster(InMaster);
	CastedMaster_ = Cast<UWriter_Master>(Master_);
	InPanel->AddChild(this);
	SetupForDefaultCanvas();
	Ready();
}

void UWriter_VSetup::BuildEntryList(UScrollBox* InBox)
{
	int L = CastedMaster_->GetAtlasiPre().Num();

	for (int i = 0; i < L; i++)
	{
		UWriter_VSetupEntry* Entry = UWriter_VSetupEntry::Create(Master_->Scope(),this,CastedMaster_->GetAtlasiPre()[i],InBox);
		Entries_.Emplace(Entry);
	}
}

void UWriter_VSetup::OnEntryChanged(EWriter_VSetupEntryBoolType Type, UWriter_VSetupEntry* InEntry)
{
	if (Type == EWriter_VSetupEntryBoolType::Master)
	{
		if (InEntry->Master_->GetValue()==true)
		{
			if (ActiveEntry_ != NULL)
			{
				ActiveEntry_->Master_->SetNoChanged(false);
			}
			ActiveEntry_ = InEntry;
		}
		else
		{
			ActiveEntry_ = NULL;
		}
	}
}