//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/Writer/Ui/WriLoadoutU.h"
#include "Protocol/Writer/Ui/WriLoadoutU_ScrollEntry.h"
#include "Protocol/Writer/WriLoadoutP.h"
#include "Protocol/Writer/Ex/WriData.h"
#include "Interface/Array.h"

#include "System/AtlasLib.h"

#include "Ui/UiScroll.h"
#include "Protocol/Writer/Ui/WriButtonU.h"
#include "Ui/UiEventCodes.h"


void UWriLoadout::NativeConstruct()
{
	MasterEntry_ = NULL;
	Super::NativeConstruct();
	vLoad->SetupButton(REG::Load, this);	
	vUnlock->SetupButton(REG::Unlock, this);
	FirstDraw_ = false;
}

void UWriLoadout::UiConstruct(WriLoadoutP* InPro, AtlasLibC* InAtlasLib)
{
	Pro_ = InPro;
	AtlasLib_ = InAtlasLib;
}

void UWriLoadout::OpenUi()
{

	if (!FirstDraw_)
	{
		vScroll->ClearChildren();

		int L = AtlasLib_->GetAtlasPreMap()->Len();

		for (int i = 0; i < L; i++)
		{
			UWriLoadout_ScrollEntry* Entry = UWriLoadout_ScrollEntry::Create(this, AtlasLib_->GetAtlasPreMap()->At(i));
			vScroll->AddEntry(Entry);
		}

		FirstDraw_ = true;
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
	int L = vScroll->Entries_.Len();
	UWriLoadout_ScrollEntry* Cur;

	for (int i = 0; i < L; i++)
	{
		Cur = static_cast<UWriLoadout_ScrollEntry*>(vScroll->Entries_[i]);
		
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

	vLoad->SetVisibility(ESlateVisibility::Collapsed);
	vUnlock->SetVisibility(ESlateVisibility::HitTestInvisible);
}