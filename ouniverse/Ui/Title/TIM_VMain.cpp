//Copyright 2015-2019, All Rights Reserved.

#include "Ui/Title/TIM_VMain.h"
#include "System/Class.h"

#include "System/UserDais.h"
#include "System/LoadoutDais.h"

#include "UI/Title/TIM_VMainTokenUser.h"
#include "UI/Title/TIM_VMainTokenLoadout.h"

#include "UI/Title/TIM_VMainVPre.h"
#include "UI/Title/TIM_VMainVLoad.h"
#include "UI/Title/TIM_VMainVHome.h"

void UTIM_VMain::NativeConstruct()
{
	SetViewPanel(0, V_View);

	SwitchView(0, UTIM_VMain::VPre);

	V_TokenUser->SetUser(UserDais_->Get());
	V_TokenLoadout->SetLoadout(LoadoutDais_->Get());

	Super::NativeConstruct();
}

UTIM_VMain* UTIM_VMain::Create(UUi_View* InParentView, UserDaisC* InUserDais, LoadoutDaisC* InLoadoutDais, AtlasLibC* InAtlasLib)
{
	UTIM_VMain* Neu = CreateWidget<UTIM_VMain>(InParentView->Scope(), ClassC::TIM_VMain());
	Neu->Init(InParentView, InUserDais, InLoadoutDais, InAtlasLib);
	return Neu;
}

void UTIM_VMain::Init(UUi_View* InParentView, UserDaisC* InUserDais, LoadoutDaisC* InLoadoutDais, AtlasLibC* InAtlasLib)
{
	StoreParentView(InParentView);

	UserDais_ = InUserDais;
	LoadoutDais_ = InLoadoutDais;
	AddViewPanel(0);

	View_Home = UTIM_VMainVHome::Create(this);
	AddView(0, UTIM_VMain::VHome, View_Home);
	
	View_Load = UTIM_VMainVLoad::Create(this, InAtlasLib);
	AddView(0, UTIM_VMain::VLoad, View_Load);

	View_Pre = UTIM_VMainVPre::Create(this);
	AddView(0, UTIM_VMain::VPre, View_Pre);



}