//Copyright 2015-2019, All Rights Reserved.

#include "Ui/System/SYM_Home.h"
#include "System/Class.h"

#include "UI/System/SYM_Alpha.h"

void USYM_Home::NativeConstruct()
{
	Super::NativeConstruct();
}

USYM_Home* USYM_Home::Create(UUi_View* InParentView)
{
	USYM_Home* Neu = CreateWidget<USYM_Home>(InParentView->Scope(), ClassC::SYM_Home());
	Neu->Init(InParentView);
	return Neu;
}

void USYM_Home::Init(UUi_View* InParentView)
{
	StoreParentView(InParentView);

	CastedAlpha = Cast<USYM_Alpha>(Alpha());
}

void USYM_Home::CmdAdvance()
{

}