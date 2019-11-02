//Copyright 2015-2019, All Rights Reserved.

#include "Ui/Writer_SetupView.h"
#include "Ui/Ui_Master.h"
#include "Components/CanvasPanel.h"
#include "Components/CanvasPanelSlot.h"
#include "System/Class.h"


UWriter_SetupView* UWriter_SetupView::Create(UUi_Master* InMaster, UCanvasPanel* InPanel)
{
	UWriter_SetupView* Neu = NULL;
	return Neu;
}

void UWriter_SetupView::Init(UUi_Master* InMaster, UCanvasPanel* InPanel)
{
	CreateViewer();
	SetMaster(InMaster);
	InPanel->AddChild(this);
	SetupForDefaultCanvas();
	Ready();
}