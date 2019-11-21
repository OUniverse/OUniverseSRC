//Copyright 2015-2019, All Rights Reserved.

#include "Ui/System/SYM_VUserVSelect.h"
#include "System/Class.h"

void  USYM_VUserVSelect::NativeConstruct()
{
	Super::NativeConstruct();
}

USYM_VUserVSelect* USYM_VUserVSelect::Create(UUi_View* InParentView)
{
	USYM_VUserVSelect* Neu = CreateWidget<USYM_VUserVSelect>(InParentView->Scope(), ClassC::SYM_VUserVSelect());
	Neu->Init(InParentView);
	return Neu;
}

void USYM_VUserVSelect::Init(UUi_View* InParentView)
{
	StoreParentView(InParentView);
}