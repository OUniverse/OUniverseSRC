//Copyright 2015-2019, All Rights Reserved.

#include "Ui/Writer/WRI_Loadout.h"
#include "Ui/Writer/Wri.h"
#include "Ui/Writer/WRI_Main.h"
#include "Ui/Writer/WRI_Loadout_Le.h"
#include "Ui/Ui_Bool.h"
#include "Ui/Ui_ScrollBox.h"

#include "System/AtlasLib.h"
#include "System/Class.h"

class AtlasLibC;

void UWRI_Loadout::Init(UUiView* InParentView, AtlasLibC* InAtlasLib)
{
	ConstructView(InParentView);
	//CastedAlpha = Cast<UWRI>(Alpha());
	AtlasLib_ = InAtlasLib;

	ActiveEntry_ = NULL;
	V_Scroll->ClearChildren();
	Entries_.Empty();

	int L = AtlasLib_->GetAtlasPreMap()->Len();

	//V_Accept->SetupInterface(this, Interactives::Accept);

	for (int i = 0; i < L; i++)
	{
		UWRI_Loadout_Le* Entry = UWRI_Loadout_Le::Create(this, AtlasLib_->GetAtlasPreMap()->At(i));
		V_Scroll->Add(Entry);
		Entries_.Emplace(Entry);
	}


}

void UWRI_Loadout::BoolChanged(int Type, UWRI_Loadout_Le* InEntry)
{
	if (Type == UWRI_Loadout_Le::Interfaces::Master)
	{
		if (InEntry->V_BoolMaster->GetValue()==true)
		{
			if (ActiveEntry_ != NULL)
			{
				ActiveEntry_->V_BoolMaster->Set(false,true);
			}
			ActiveEntry_ = InEntry;
		}
		else
		{
			ActiveEntry_ = NULL;
		}
	}
}

/**
void UWRI_Loadout::Click(UUi_Interactive* Interactive)
{

	if (Interactive->InterfaceUID() == Interactives::Accept)
	{
		CastedAlpha->Loadout_.Clear();

		CastedAlpha->MasterAtlas_ = ActiveEntry_->Atlas_;
		int L = Entries_.Num();

		for (int i = 0; i < L; i++)
		{
			if (Entries_[i]->AtlasActivated()&&Entries_[i]!=ActiveEntry_)
			{
				CastedAlpha->Loadout_.Add(Entries_[i]->Atlas_);
			}
		}

		CastedAlpha->Loadout_.Add(ActiveEntry_->Atlas_);
		//OwningView_->SwitchView(0, UWRI_Main::VAtlasMount);
	}
}
*/