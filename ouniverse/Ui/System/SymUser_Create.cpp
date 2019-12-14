//Copyright 2015-2019, All Rights Reserved.

#include "Ui/System/SymUser_Create.h"
#include "Ui/System/Sym.h"
#include "Interface/String.h"
#include "System/UserLib.h"
#include "Components/EditableText.h"

#include "Min/DebugM.h"

void USYM_UserCreate::Init(UUiView* InParentView, UserLibC* InUserLib)
{
	ConstructView(InParentView);
	UserLib_ = InUserLib;
	V_TextInput->OnTextChanged.AddDynamic(this, &USYM_UserCreate::TextChanged);
	V_TextInput->OnTextCommitted.AddDynamic(this, &USYM_UserCreate::OnTextCommitted);
}

void USYM_UserCreate::NativeDestruct()
{
	V_TextInput->OnTextChanged.RemoveDynamic(this, &USYM_UserCreate::TextChanged);
	V_TextInput->OnTextCommitted.RemoveDynamic(this, &USYM_UserCreate::OnTextCommitted);
	DBUG("DECONSTRUCTION TESTER, DESCONSTRUCTION TESTER LETS GO GOGOGOGOGOGO")
	Super::NativeDestruct();
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

	//Cast<USYM>(Alpha())->ToTitleMenu();
}


void USYM_UserCreate::TextChanged(const FText& Text) 
{

};


void USYM_UserCreate::OnTextCommitted(const FText& Text, ETextCommit::Type CommitMethod)
{

}
