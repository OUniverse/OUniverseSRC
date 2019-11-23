//Copyright 2015-2019, All Rights Reserved.

#include "Ui/Title/TIM_Main.h"
#include "System/Class.h"

#include "System/UserDais.h"
#include "System/LoadoutDais.h"

#include "UI/Title/TIM_Main_TokenUser.h"
#include "UI/Title/TIM_Main_TokenLoadout.h"

#include "UI/Title/TIM_Alpha.h"
#include "UI/Title/TIM_Pre.h"
#include "UI/Title/TIM_AtlasMount.h"
#include "UI/Title/TIM_Home.h"

void UTIM_Main::NativeConstruct()
{
	SetViewPanel(0, V_View);

	SwitchView(0, UTIM_Main::VPre);

	V_TokenUser->SetUser(UserDais_->Get());
	V_TokenLoadout->SetLoadout(LoadoutDais_->Get());

	Super::NativeConstruct();
}

UTIM_Main* UTIM_Main::Create(UUi_View* InParentView, UserDaisC* InUserDais, LoadoutDaisC* InLoadoutDais, AtlasLibC* InAtlasLib)
{
	UTIM_Main* Neu = CreateWidget<UTIM_Main>(InParentView->Scope(), ClassC::TIM_Main());
	Neu->Init(InParentView, InUserDais, InLoadoutDais, InAtlasLib);
	return Neu;
}

void UTIM_Main::Init(UUi_View* InParentView, UserDaisC* InUserDais, LoadoutDaisC* InLoadoutDais, AtlasLibC* InAtlasLib)
{
	StoreParentView(InParentView);

	UserDais_ = InUserDais;
	LoadoutDais_ = InLoadoutDais;
	AddViewPanel(0);

	View_Home = UTIM_Home::Create(this);
	AddView(0, UTIM_Main::VHome, View_Home);
	
	View_Load = UTIM_AtlasMount::Create(this, InAtlasLib);
	AddView(0, UTIM_Main::VLoad, View_Load);

	View_Pre = UTIM_Pre::Create(this);
	AddView(0, UTIM_Main::VPre, View_Pre);

}


void UTIM_Main::CmdSettings()
{

}

void UTIM_Main::CmdSYM()
{

}

void UTIM_Main::CmdWRI()
{
	(Cast<UTIM_Alpha>(Alpha()))->ToWriterMenu();
}

void UTIM_Main::CmdUser()
{

}

void UTIM_Main::CmdLoadout()
{
	
}