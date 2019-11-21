//Copyright 2015-2019, All Rights Reserved.

#include "Ui/System/SYM_VMain.h"


USYM_VMain* USYM_VMain::Create(UUi_View* InParentView, UserLibC* InUserLib, LoadoutLibC* InLoadoutLib)
{
	USYM_VMain* Neu = CreateWidget<USYM_VMain>(InParentView->Scope());
	Neu->Init(InParentView, InUserLib, InLoadoutLib);
	return Neu;
}

void USYM_VMain::Init(UUi_View* InParentView, UserLibC* InUserLib, LoadoutLibC* InLoadoutLib)
{
	StoreParentView(InParentView);
	UserLib_ = InUserLib;
	LoadoutLib_ = InLoadoutLib;
}