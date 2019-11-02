//Copyright 2015-2019, All Rights Reserved.

#include "Ui/Writer_FormView.h"
#include "Ui/Ui_Master.h"
#include "System/Class.h"

UWriter_FormView* UWriter_FormView::Create(UUi_Master* InMaster)
{
	UWriter_FormView* Neu = CreateWidget<UWriter_FormView>(InMaster->Scope(), ClassC::Writer_FormView());
	Neu->Init(InMaster);
	return Neu;
}

void UWriter_FormView::Init(UUi_Master* InMaster)
{
	CreateViewer();
	SetMaster(InMaster);
}