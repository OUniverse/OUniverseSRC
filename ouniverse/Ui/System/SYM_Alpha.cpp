//Copyright 2015-2019, All Rights Reserved.

#include "Ui/System/SYM_Alpha.h"
#include "Ui/System/SYM_Main.h"
#include "Ui/System/SYM_UserCreate.h"
#include "Ui/System/SYM_UserSelect.h"
#include "Ui/Ui.h"

#include "System/Class.h"







namespace SYM_Mem
{
	bool FirstOpenComplete = false;
}



void USYM_Alpha::NativeConstruct()
{
	SetViewPanel(0, V_View);

	//SwitchView(0, USYM_Alpha::VUserCreate);
	SwitchView(0, USYM_Alpha::VUserSelect);

	SYM_Mem::FirstOpenComplete = true;

	Super::NativeConstruct();
}


USYM_Alpha* USYM_Alpha::Create(UWorld* InScope, UUi* InUi, UserLibC* InUserLib, UserDaisC* InUserDais, LoadoutLibC* InLoadoutLib, LoadoutDaisC* InLoadoutDais)
{
	USYM_Alpha* Neu = CreateWidget<USYM_Alpha>(InScope, ClassC::SYM_Alpha());
	Neu->Init(InScope, InUi, InUserLib, InUserDais, InLoadoutLib, InLoadoutDais);

	return Neu;
}

void USYM_Alpha::Init(UWorld* InScope, UUi* InUi, UserLibC* InUserLib, UserDaisC* InUserDais, LoadoutLibC* InLoadoutLib, LoadoutDaisC* InLoadoutDais)
{
	SetupAlpha(InScope, InUi);
	
	UserLib_ = InUserLib;
	UserDais_ = InUserDais;
	LoadoutLib_ = InLoadoutLib;
	LoadoutDais_ = InLoadoutDais;

	AddViewPanel(0);

	View_Main = USYM_Main::Create(this,InUserLib,InLoadoutLib);
	AddView(0, USYM_Alpha::VMain, View_Main);
	View_UserCreate = USYM_UserCreate::Create(this, InUserLib);
	AddView(0, USYM_Alpha::VUserCreate, View_UserCreate);
	View_UserSelect = USYM_UserSelect::Create(this, InUserLib);
	AddView(0, USYM_Alpha::VUserSelect, View_UserSelect);
	
}

void USYM_Alpha::ToTitleMenu()
{
	Ui_->OpenTitleMenu();
}