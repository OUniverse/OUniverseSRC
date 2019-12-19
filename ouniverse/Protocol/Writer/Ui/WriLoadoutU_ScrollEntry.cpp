//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/Writer/Ui/WriLoadoutU_ScrollEntry.h"
#include "System/Scope.h"
#include "Class/ClassProtocol.h"
#include "Protocol/Writer/Ui/WriLoadoutU.h"

#include "System/Atlas.h"
#include "Ui/UiMouseInput.h"

#include "Components/TextBlock.h"

void UWriLoadout_ScrollEntry::NativeConstruct()
{
	Super::NativeConstruct();
	V_Text->SetText(FText::FromString(Atlas_->ID().ToChar()));

	V_BoolMaster->Setup(REG::BoolMaster, this);
	V_BoolActive->Setup(REG::BoolActive, this);
}

UWriLoadout_ScrollEntry* UWriLoadout_ScrollEntry::Create(UWriLoadout* InView, AtlasC* InAtlas)
{
	UWriLoadout_ScrollEntry* Neu = CreateWidget<UWriLoadout_ScrollEntry>(ScopeC::World(), UClassProtocol::Get()->WriLoadout_ScrollEntryUI);
	Neu->Init(InView, InAtlas);
	return Neu;
}

void UWriLoadout_ScrollEntry::Init(UWriLoadout* InView, AtlasC* InAtlas)
{
	Atlas_ = InAtlas;
	View_ = InView;
}

void UWriLoadout_ScrollEntry::EventUi(int WidgetID, int InEventID, UUserWidget* InWidget)
{
	switch (WidgetID) {
	case REG::BoolMaster:
		BoolMasterToggle(false);
		break;
	case REG::BoolActive:
		BoolActiveToggle();
		break;
	}
}

void UWriLoadout_ScrollEntry::BoolMasterToggle(bool FromView)
{
	if (AtlasMaster_)
	{
		AtlasMaster_ = false;
		BoolMasterOff();
		if (!FromView)
		{
			View_->MasterCleared();
		}
	}
	else
	{
		AtlasMaster_ = true;
		BoolMasterOn();
		if (!FromView)
		{
			View_->MasterSet(this);
		}
	}
}

void UWriLoadout_ScrollEntry::BoolActiveToggle()
{
	if (AtlasActive_)
	{
		AtlasActive_ = false;
		BoolActiveOff();
	}
	else
	{
		AtlasActive_ = true;
		BoolActiveOn();
	}
}