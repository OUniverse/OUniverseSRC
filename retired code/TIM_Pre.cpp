//Copyright 2015-2019, All Rights Reserved.

#include "Ui/Title/TIM_Pre.h"
#include "System/Class.h"

#include "UI/Title/TIM_Alpha.h"
#include "UI/Title/TIM_Main.h"

void UTIM_Pre::NativeConstruct()
{
	Super::NativeConstruct();
}

UTIM_Pre* UTIM_Pre::Create(UUi_View* InParentView)
{
	UTIM_Pre* Neu = CreateWidget<UTIM_Pre>(InParentView->Scope(), ClassC::TIM_Pre());
	Neu->Init(InParentView);
	return Neu;
}

void UTIM_Pre::Init(UUi_View* InParentView)
{
	ConstructView(InParentView);

	CastedAlpha = Cast<UTIM_Alpha>(Alpha());
}

void UTIM_Pre::CmdAdvance()
{
	OwningView_->SwitchView(0,UTIM_Main::VLoad);
}