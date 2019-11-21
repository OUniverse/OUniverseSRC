//Copyright 2015-2019, All Rights Reserved.

#include "Ui/Title/TIM_VMainVPre.h"
#include "System/Class.h"

#include "UI/Title/TIM_Alpha.h"
#include "UI/Title/TIM_VMain.h"

void UTIM_VMainVPre::NativeConstruct()
{
	Super::NativeConstruct();
}

UTIM_VMainVPre* UTIM_VMainVPre::Create(UUi_View* InParentView)
{
	UTIM_VMainVPre* Neu = CreateWidget<UTIM_VMainVPre>(InParentView->Scope(), ClassC::TIM_VMainVPre());
	Neu->Init(InParentView);
	return Neu;
}

void UTIM_VMainVPre::Init(UUi_View* InParentView)
{
	StoreParentView(InParentView);

	CastedAlpha = Cast<UTIM_Alpha>(Alpha());
}

void UTIM_VMainVPre::CmdAdvance()
{
	OwningView_->SwitchView(0,UTIM_VMain::VLoad);
}