//Copyright 2015-2019, All Rights Reserved.

#include "Ui/System/SYM_UserSelect.h"
#include "Ui/System/SYM_UserSelect_Le.h"

#include "Ui/Ui_Scroll.h"

#include "System/Class.h"

#include "System/UserLib.h"

void  USYM_UserSelect::NativeConstruct()
{
	int L = UserLib_->Num();

	for (int i = 0; i < L;i++)
	{
		USYM_UserSelect_Le* Entry = USYM_UserSelect_Le::Create(this, UserLib_->GetUser(i));
		V_Scroll->AddEntry(Entry);
	}


	V_Scroll->Build();

	Super::NativeConstruct();
}

USYM_UserSelect* USYM_UserSelect::Create(UUi_View* InParentView, UserLibC* InUserLib)
{
	USYM_UserSelect* Neu = CreateWidget<USYM_UserSelect>(InParentView->Scope(), ClassC::SYM_UserSelect());
	Neu->Init(InParentView, InUserLib);
	return Neu;
}

void USYM_UserSelect::Init(UUi_View* InParentView, UserLibC* InUserLib)
{
	StoreParentView(InParentView);

	UserLib_ = InUserLib;
}