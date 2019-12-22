//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/Writer/Ui/WriFormU_ScrollEntry.h"
#include "System/Scope.h"
#include "Class/ClassProtocol.h"
#include "Protocol/Writer/Ui/WriDataU.h"

#include "System/Atlas.h"
#include "Ui/UiMouseInput.h"

#include "Components/TextBlock.h"

#include "System/FormData.h"

void UWriForm_ScrollEntry::NativeConstruct()
{
	Super::NativeConstruct();
	vTitle->SetText(FText::FromString(FormData_->Form()->ID().ToChar()));

	vArea->Setup(REG::MiArea, this);
	vSelect->Setup(REG::MiSelect, this);
}

UWriForm_ScrollEntry* UWriForm_ScrollEntry::Create(UWriDataSearch* InView, FormDataC* InFormData)
{
	UWriForm_ScrollEntry* Neu = CreateWidget<UWriForm_ScrollEntry>(ScopeC::World(), UClassProtocol::Get()->WriForm_ScrollEntryUI);
	Neu->Init(InView, InFormData);
	return Neu;
}

void UWriForm_ScrollEntry::Init(UWriDataSearch* InView, FormDataC* InFormData)
{
	View_ = InView;
	FormData_ = InFormData;
}

void UWriForm_ScrollEntry::EventUi(int WidgetID, int InEventID, UUserWidget* InWidget)
{
	switch (WidgetID) {
	case REG::MiArea:
		//View_->OpenForm(FormData_);
		break;
	case REG::MiSelect:
		BoolSelectedToggle();
		break;
	}
}

void UWriForm_ScrollEntry::BoolSelectedToggle()
{
	if (bSelected_)
	{
		bSelected_ = false;
		BoolSelectedOff();
	}
	else
	{
		bSelected_ = true;
		BoolSelectedOn();
	}
}