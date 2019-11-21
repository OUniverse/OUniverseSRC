//Copyright 2015-2019, All Rights Reserved.

#include "Ui/System/SYM_VUserVCreate.h"
#include "System/Class.h"
#include "Components/EditableTextBox.h"
#include "Interface/String.h"
#include "System/UserLib.h"

#include "UI/System/SYM_Alpha.h"

void  USYM_VUserVCreate::NativeConstruct()
{
	Super::NativeConstruct();
}

USYM_VUserVCreate* USYM_VUserVCreate::Create(UUi_View* InParentView, UserLibC* InUserLib)
{
	USYM_VUserVCreate* Neu = CreateWidget<USYM_VUserVCreate>(InParentView->Scope(),ClassC::SYM_VUserVCreate());
	Neu->Init(InParentView, InUserLib);
	return Neu;
}

void USYM_VUserVCreate::Init(UUi_View* InParentView, UserLibC* InUserLib)
{
	StoreParentView(InParentView);
	UserLib_ = InUserLib;

	CastedAlpha = Cast<USYM_Alpha>(Alpha());
}

void USYM_VUserVCreate::CmdAccept()
{
	StringC UserInput = V_Input->Text.ToString();
	
	if(UserInput == "")
	{
		return;
	}

	UserC* NewUser = UserLib_->CreateNewUser(UserInput);
	UserLib_->Set(NewUser);

	CastedAlpha->ToTitleMenu();
}