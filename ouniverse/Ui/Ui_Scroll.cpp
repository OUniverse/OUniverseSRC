//Copyright 2015-2019, All Rights Reserved.

#include "Ui/Ui_Scroll.h"
#include "Components/ScrollBox.h"
#include "Components/CanvasPanelSlot.h"


void UUi_Scroll::NativeConstruct()
{
	Slot_ = (Cast<UCanvasPanelSlot>(V_Scroll->Slot));
	Super::NativeConstruct();
}


void UUi_Scroll::Add(UUserWidget* InChild)
{
	V_Scroll->AddChild(InChild);

	int L = Entries_.Len();
	for (int i = 0; i < L; i++)
	{
		Slot_->SetAutoSize(true);
	}
}
void UUi_Scroll::ClearChildren()
{
	V_Scroll->ClearChildren();
}