//Copyright 2015-2019, All Rights Reserved.

#include "Ui/Ui_ViewPanel.h"
#include "Ui/Ui_View.h"
#include "Components/CanvasPanel.h"
#include "Components/CanvasPanelSlot.h"


void UUi_ViewPanel::Init()
{
	OpenView_ = NULL;
}

void UUi_ViewPanel::Add(UUi_View* InView)
{

	OpenView_ = InView;
	V_Canvas->AddChild(InView);

	UCanvasPanelSlot* CanvasSlot = Cast<UCanvasPanelSlot>(InView->Slot);
	CanvasSlot->SetAnchors(FAnchors(0.0f, 0.0f, 1.0f, 1.0f));

}