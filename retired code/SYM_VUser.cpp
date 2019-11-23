//Copyright 2015-2019, All Rights Reserved.

#include "Ui/System/SYM_VUser.h"
#include "Ui/System/SYM_Views.h"
#include "Ui/System/SYM_UserCreate.h"
#include "Ui/System/SYM_UserSelect.h"
#include "System/Class.h"

#include "Min/DebugM.h"

void  USYM_VUser::NativeConstruct()
{
	SetViewPanel(0, V_View);

	SwitchView(0, SYM_ViewsC::VUserVCreate);

	Super::NativeConstruct();
}

USYM_VUser* USYM_VUser::Create(UUi_View* InParentView, UserLibC* InUserLib)
{
	//USYM_VUser* Neu = CreateWidget<USYM_VUser>(InParentView->Scope(), ClassC::SYM_VUser());
	//Neu->Init(InParentView,InUserLib);
	return NULL;
}

void USYM_VUser::Init(UUi_View* InParentView, UserLibC* InUserLib)
{
	StoreParentView(InParentView);

	UserLib_ = InUserLib;

	AddViewPanel(0);
	View_Create = USYM_UserCreate::Create(this, InUserLib);
	AddView(0, SYM_ViewsC::VUserVCreate, View_Create);
	
	View_Select = USYM_UserSelect::Create(this, InUserLib);
	AddView(0, SYM_ViewsC::VUserVSelect, View_Select);
}