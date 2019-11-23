//Copyright 2015-2019, All Rights Reserved.

#include "Ui/Writer/WRI_Splash.h"
#include "System/Class.h"
#include "UI/Writer/WRI_Alpha.h"

void UWRI_Splash::NativeConstruct()
{
	Super::NativeConstruct();
}

UWRI_Splash* UWRI_Splash::Create(UUi_View* InParentView)
{
	UWRI_Splash* Neu = CreateWidget<UWRI_Splash>(InParentView->Scope(), ClassC::WRI_Splash());
	Neu->Init(InParentView);
	return Neu;
}

void UWRI_Splash::Init(UUi_View* InParentView)
{
	StoreParentView(InParentView);
}

void UWRI_Splash::CmdAdvance()
{
	OwningView_->SwitchView(0, UWRI_Alpha::VMain);
}