//Copyright 2015-2019, All Rights Reserved.

#include "Ui/System/SYM_Main.h"


USYM_Main* USYM_Main::Create(UUi_View* InParentView, UserLibC* InUserLib, LoadoutLibC* InLoadoutLib)
{
	USYM_Main* Neu = CreateWidget<USYM_Main>(InParentView->Scope());
	Neu->Init(InParentView, InUserLib, InLoadoutLib);
	return Neu;
}

void USYM_Main::Init(UUi_View* InParentView, UserLibC* InUserLib, LoadoutLibC* InLoadoutLib)
{
	StoreParentView(InParentView);
	UserLib_ = InUserLib;
	LoadoutLib_ = InLoadoutLib;
}