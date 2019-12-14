//Copyright 2015-2019, All Rights Reserved.

#include "Ui/Writer/WRI_Splash.h"
#include "System/Class.h"
#include "System/Scope.h"


UWRI_Splash* UWRI_Splash::Create(UUiView* InParentView)
{
	UWRI_Splash* Neu = CreateWidget<UWRI_Splash>(ScopeC::World(), ClassC::WRI_Splash());
	Neu->Init(InParentView);
	return Neu;
}

void UWRI_Splash::Init(UUiView* InParentView)
{
	ConstructView(InParentView);
}

void UWRI_Splash::CmdAdvance()
{
	//OwningView_->SwitchView(0, UWRI_Alpha::VMain);
}