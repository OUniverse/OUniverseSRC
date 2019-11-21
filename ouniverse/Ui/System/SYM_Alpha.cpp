//Copyright 2015-2019, All Rights Reserved.

#include "Ui/System/SYM_Alpha.h"
#include "Ui/System/SYM_VMain.h"
#include "Ui/System/SYM_VUser.h"
#include "Ui/Ui.h"

#include "System/Class.h"


#include "UI/System/SYM_Views.h"






namespace SYM_Mem
{
	bool FirstOpenComplete = false;
}



void USYM_Alpha::NativeConstruct()
{
	SetViewPanel(0, V_View);

	SwitchView(0, SYM_ViewsC::VUser);

	/**
	USYM_AlphaOpt* Opt = USYM_AlphaOpt::Create(Scope(), this, Views::User, 912569922);
	V_Viewer->AddTab(Views::User, Opt, *ClassC::SYM_VUser(), false);
	V_Scroll->Add(Opt);

	Opt = USYM_AlphaOpt::Create(Scope(), this, Views::Loadout, 756854254);
	V_Viewer->AddTab(Views::Loadout, Opt, *ClassC::SYM_VUser(), false);
	V_Scroll->Add(Opt);

	Opt = USYM_AlphaOpt::Create(Scope(), this, Views::User, 515093516);
	V_Viewer->AddTab(Views::User, Opt, *ClassC::SYM_VUser(), false);
	V_Scroll->Add(Opt);

	Opt = USYM_AlphaOpt::Create(Scope(), this, Views::User, 1077593158);
	V_Viewer->AddTab(Views::User, Opt, *ClassC::SYM_VUser(), false);
	V_Scroll->Add(Opt);

	Opt = USYM_AlphaOpt::Create(Scope(), this, Views::User, 634432051);
	V_Viewer->AddTab(Views::User, Opt, *ClassC::SYM_VUser(), false);
	V_Scroll->Add(Opt);

	Opt = USYM_AlphaOpt::Create(Scope(), this, Views::User, 760295618);
	V_Viewer->AddTab(Views::User, Opt, *ClassC::SYM_VUser(), false);
	V_Scroll->Add(Opt);

	Opt = USYM_AlphaOpt::Create(Scope(), this, Views::User, 1112825869);
	V_Viewer->AddTab(Views::User, Opt, *ClassC::SYM_VUser(), false);
	V_Scroll->Add(Opt);
	*/




	//V_Viewer->SwitchView(Views::User, false);

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

	//View_Menu = USYM_VMain::Create(this,InUserLib,InLoadoutLib);
	//AddView(0, SYM_ViewsC::Main, View_Menu);

	View_User = USYM_VUser::Create(this, InUserLib);
	AddView(0, SYM_ViewsC::VUser, View_User);
}

void USYM_Alpha::ToTitleMenu()
{
	Ui_->OpenTitleMenu();
}