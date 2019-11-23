//Copyright 2015-2019, All Rights Reserved.

#include "Ui/System/SYM_UserCreate.h"
#include "System/Class.h"
#include "Ui/Ui_TextEdit.h"
#include "Interface/String.h"
#include "System/UserLib.h"

#include "UI/System/SYM_Alpha.h"


void  USYM_UserCreate::NativeConstruct()
{
	V_TextInput->SetupInterface(0, 0);
	Super::NativeConstruct();
}

USYM_UserCreate* USYM_UserCreate::Create(UUi_View* InParentView, UserLibC* InUserLib)
{
	USYM_UserCreate* Neu = CreateWidget<USYM_UserCreate>(InParentView->Scope(),ClassC::SYM_UserCreate());
	Neu->Init(InParentView, InUserLib);
	return Neu;
}

void USYM_UserCreate::Init(UUi_View* InParentView, UserLibC* InUserLib)
{
	StoreParentView(InParentView);
	UserLib_ = InUserLib;

	CastedAlpha = Cast<USYM_Alpha>(Alpha());
}

void USYM_UserCreate::CmdAccept()
{
	StringC UserInput = V_TextInput->GetText();

	if(UserInput == "")
	{
		return;
	}

	UserC* NewUser = UserLib_->CreateNewUser(UserInput);
	UserLib_->Set(NewUser);

	CastedAlpha->ToTitleMenu();
}