//Copyright 2015-2019, All Rights Reserved.

#include "Ui/Title/TIM_VMainVHome.h"
#include "System/Class.h"

#include "UI/Title/TIM_Alpha.h"

void UTIM_VMainVHome::NativeConstruct()
{
	Super::NativeConstruct();
}

UTIM_VMainVHome* UTIM_VMainVHome::Create(UUi_View* InParentView)
{
	UTIM_VMainVHome* Neu = CreateWidget<UTIM_VMainVHome>(InParentView->Scope(), ClassC::TIM_VMainVHome());
	Neu->Init(InParentView);
	return Neu;
}

void UTIM_VMainVHome::Init(UUi_View* InParentView)
{
	StoreParentView(InParentView);

	CastedAlpha = Cast<UTIM_Alpha>(Alpha());
}

void UTIM_VMainVHome::CmdAdvance()
{

}