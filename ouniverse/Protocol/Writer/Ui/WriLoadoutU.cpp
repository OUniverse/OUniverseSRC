//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/Writer/Ui/WriLoadoutU.h"
#include "Protocol/Writer/Ui/WriLoadoutU_ScrollEntry.h"
#include "Protocol/Writer/WriLoadoutP.h"
#include "Protocol/Writer/Ex/WriData.h"
#include "Interface/Array.h"

#include "System/AtlasLib.h"

#include "Ui/UiScroll.h"
#include "Ui/UiButton.h"
#include "Ui/UiEventCodes.h"


void UWriLoadout::NativeConstruct()
{
	MasterEntry_ = NULL;
	Super::NativeConstruct();
	BT_Load->SetupButton(REG::Load, this);	
}

void UWriLoadout::UiConstruct(WriLoadoutP* InPro, AtlasLibC* InAtlasLib)
{
	Pro_ = InPro;
	AtlasLib_ = InAtlasLib;
}

void UWriLoadout::OpenUi()
{
	//V_Scroll->ClearChildren();
	//Entries_.Empty();

	int L = AtlasLib_->GetAtlasPreMap()->Len();

	for (int i = 0; i < L; i++)
	{
		UWriLoadout_ScrollEntry* Entry = UWriLoadout_ScrollEntry::Create(this, AtlasLib_->GetAtlasPreMap()->At(i));
		V_Scroll->AddEntry(Entry);
		//Entries_.Emplace(Entry);
	}
}

void UWriLoadout::MasterSet(UWriLoadout_ScrollEntry* InMaster)
{
	if (MasterEntry_ != NULL)
	{
		MasterEntry_->BoolMasterToggle(true);
	}

	MasterEntry_ = InMaster;
}

void UWriLoadout::MasterCleared()
{
	MasterEntry_ = NULL;
}

void UWriLoadout::EventUi(int WidgetID, int InEventID, UUserWidget* InWidget)
{
	if (InEventID == UiEventsC::ButtonAccept || InEventID == UiEventsC::MouseLeftClick)
	{
		switch (WidgetID) {
		case REG::Load:
			Pro_->AcceptLoad();
			break;
		case REG::New:
			Pro_->AcceptNew();
			break;
		}
	}
}

void UWriLoadout::SetData(WriDataC* InData)
{
	int L = V_Scroll->Entries_.Len();
	UWriLoadout_ScrollEntry* Cur;

	for (int i = 0; i < L; i++)
	{
		Cur = static_cast<UWriLoadout_ScrollEntry*>(V_Scroll->Entries_[i]);
		
		if (Cur->AtlasMaster_)
		{
			InData->Loadout_.Add(Cur->Atlas_);
			InData->SetMaster(Cur->Atlas_);
		}
		else if (Cur->AtlasActive_)
		{
			InData->Loadout_.Add(Cur->Atlas_);
		}
	}
}