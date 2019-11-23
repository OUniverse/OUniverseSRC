//Copyright 2015-2019, All Rights Reserved.

#include "Ui/Ui_Viewer.h"
#include "Components/CanvasPanel.h"
#include "Components/CanvasPanelSlot.h"



void UUi_Viewer::Add(UUi_View* InView)
{
	V_Canvas->AddChildToCanvas(InView);
}

void UUi_Viewer::ClearChildren()
{
	V_Canvas->ClearChildren();
}