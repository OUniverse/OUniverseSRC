//Copyright 2015-2019, All Rights Reserved.

#include "Ui/System/SYM_Pre.h"
#include "System/Class.h"

#include "UI/System/SYM_Alpha.h"
#include "UI/System/SYM_Main.h"

void USYM_Pre::NativeConstruct()
{
	Super::NativeConstruct();
}

USYM_Pre* USYM_Pre::Create(UUi_View* InParentView)
{
	USYM_Pre* Neu = CreateWidget<USYM_Pre>(InParentView->Scope(), ClassC::SYM_Pre());
	Neu->Init(InParentView);
	return Neu;
}

void USYM_Pre::Init(UUi_View* InParentView)
{
	StoreParentView(InParentView);

	CastedAlpha = Cast<USYM_Alpha>(Alpha());
}

void USYM_Pre::CmdAdvance()
{
	//OwningView_->SwitchView(0, USYM_Main::VLoad);
}