//Copyright 2015-2019, All Rights Reserved.

#include "Ui/Title/TIM_Home.h"
#include "System/Class.h"

#include "UI/Title/TIM_Alpha.h"

void UTIM_Home::NativeConstruct()
{
	Super::NativeConstruct();
}

UTIM_Home* UTIM_Home::Create(UUi_View* InParentView)
{
	UTIM_Home* Neu = CreateWidget<UTIM_Home>(InParentView->Scope(), ClassC::TIM_Home());
	Neu->Init(InParentView);
	return Neu;
}

void UTIM_Home::Init(UUi_View* InParentView)
{
	ConstructView(InParentView);

	CastedAlpha = Cast<UTIM_Alpha>(Alpha());
}

void UTIM_Home::CmdAdvance()
{

}