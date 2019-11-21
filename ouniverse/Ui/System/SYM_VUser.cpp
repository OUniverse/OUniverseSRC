//Copyright 2015-2019, All Rights Reserved.

#include "Ui/System/SYM_VUser.h"
#include "Ui/System/SYM_Views.h"
#include "Ui/System/SYM_VUserVCreate.h"
#include "Ui/System/SYM_VUserVSelect.h"
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
	USYM_VUser* Neu = CreateWidget<USYM_VUser>(InParentView->Scope(), ClassC::SYM_VUser());
	Neu->Init(InParentView,InUserLib);
	return Neu;
}

void USYM_VUser::Init(UUi_View* InParentView, UserLibC* InUserLib)
{
	StoreParentView(InParentView);

	UserLib_ = InUserLib;

	AddViewPanel(0);
	View_Create = USYM_VUserVCreate::Create(this, InUserLib);
	AddView(0, SYM_ViewsC::VUserVCreate, View_Create);
	
	View_Select = USYM_VUserVSelect::Create(this);
	AddView(0, SYM_ViewsC::VUserVSelect, View_Select);
}