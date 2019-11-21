//Copyright 2015-2019, All Rights Reserved.

#include "Ui/Writer/WRI_VSetup.h"
#include "Ui/Writer/WRI_Alpha.h"
#include "Ui/Writer/WRI_VSetupEntry.h"
#include "Ui/Ui_Bool.h"
#include "Ui/Ui_ScrollBox.h"

#include "System/AtlasLib.h"

#include "Components/CanvasPanel.h"
#include "Components/CanvasPanelSlot.h"
#include "System/Class.h"


/**
void UWRI_VSetup::InitFromViewer()
{
	ActiveEntry_ = NULL;
	CastedView_ = Cast<UWRI_Alpha>(OwningView_);
	CastedView_->ImbueVSetup(this);
}

void UWRI_VSetup::Imbue(AtlasLibC* InAtlasLib)
{
	int L = InAtlasLib->GetAtlasPreMap()->Len();

	for (int i = 0; i < L; i++)
	{
		UWRI_VSetupEntry* Entry = UWRI_VSetupEntry::Create(OwningView_->Scope(), this, InAtlasLib->GetAtlasPreMap()->At(i));
		V_Scroll->Add(Entry);
		Entries_.Emplace(Entry);
	}
}
*/

void UWRI_VSetup::BoolChanged(EWRI_VSetupEntryBoolType Type, UWRI_VSetupEntry* InEntry)
{
	if (Type == EWRI_VSetupEntryBoolType::Master)
	{
		if (InEntry->V_BoolMaster->GetValue()==true)
		{
			if (ActiveEntry_ != NULL)
			{
				ActiveEntry_->V_BoolMaster->SetNoChanged(false);
			}
			ActiveEntry_ = InEntry;
		}
		else
		{
			ActiveEntry_ = NULL;
		}
	}
}