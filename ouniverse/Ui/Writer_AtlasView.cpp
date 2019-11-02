//Copyright 2015-2019, All Rights Reserved.

#include "Ui/Writer_AtlasView.h"
#include "Ui/Ui_Master.h"
#include "Components/CanvasPanel.h"
#include "Components/CanvasPanelSlot.h"
#include "System/Class.h"


UWriter_AtlasView* UWriter_AtlasView::Create(UUi_Master* InMax, UCanvasPanel* InPanel)
{
	UWriter_AtlasView* Neu = CreateWidget<UWriter_AtlasView>(InMax->Scope(),ClassC::Writer_AtlasView());
	Neu->Init(InMax,InPanel);
	return Neu;
}

void UWriter_AtlasView::Init(UUi_Master* InMax, UCanvasPanel* InPanel)
{
	CreateViewer();
	SetMaster(InMax);
	InPanel->AddChild(this);
	SetupForDefaultCanvas();
	Ready();
}