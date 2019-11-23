//Copyright 2015-2019, All Rights Reserved.

#include "Ui/Ui_Scroll.h"
#include "Components/ScrollBox.h"
#include "Components/CanvasPanelSlot.h"


void UUi_Scroll::NativeConstruct()
{
	Super::NativeConstruct();
}


void  UUi_Scroll::Require(UCanvasPanel* CanvasPanel, UScrollBox* ScrollBox)
{
	V_Canvas = CanvasPanel;
	V_Scroll = ScrollBox;

	//Slot_ = (Cast<UCanvasPanelSlot>(V_Scroll->Slot));


	//V_Size->SetHeightOverride(1000.0);
	
		/**
	int L = Entries_.Len();
	
	for (int i = 0; i < L; i++)
	{
	//	V_Scroll->AddChild(Entries_[i]);
	}

	if (V_Scroll->GetChildrenCount() > MaxDisplayed)
	{

	}
	else
	{

	}
	
	*/
}

void UUi_Scroll::Add(UUserWidget* InChild)
{
	V_Scroll->AddChild(InChild);
}
void UUi_Scroll::ClearChildren()
{
	V_Scroll->ClearChildren();
}