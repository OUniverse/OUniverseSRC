//Copyright 2015-2019, All Rights Reserved.

#include "Ui/Ui_ViewCanvas.h"
#include "Components/CanvasPanelSlot.h"



void UUi_ViewCanvas::Add(UUi_View* InView)
{
	AddChildToCanvas(InView);
	UCanvasPanelSlot* CanvasSlot = Cast<UCanvasPanelSlot>(InView->Slot);
	CanvasSlot->SetAnchors(FAnchors(0.0f, 0.0f, 1.0f, 1.0f));
}

void UUi_ViewCanvas::ClearChildren()
{
	ClearChildren();
}