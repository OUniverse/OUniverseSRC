//Copyright 2015-2019, All Rights Reserved.

#include "Ui/System/Sym.h"
#include "Ui/System/SymReg.h"
#include "System/Scope.h"

#include "Ui/System/SymAtlasLoad.h"
#include "Ui/System/SymMain.h"
#include "Ui/System/SymPre.h"
#include "Ui/System/SymUser.h"
#include "Ui/Ui.h"
#include "System/Class.h"

#include "System/UserDais.h"
#include "System/LoadoutDais.h"

#include "Ui/System/SymToken_User.h"
#include "Ui/System/SymToken_Loadout.h"


namespace SYM_Mem
{
	bool FirstOpenComplete = false;
}



void USystemUi::NativeConstruct()
{
	Super::NativeConstruct();
		
	AddViewPanel(SYMREG::Docks::DAlpha);

	View_User->Init(this,UserLib_,UserDais_);
	AddView(SYMREG::Docks::DAlpha, SYMREG::Views::VUser,View_User);
	View_Pre->Init(this);
	AddView(SYMREG::Docks::DAlpha, SYMREG::Views::VPre, View_Pre);
	View_AtlasLoad->Init(this,AtlasLib_);
	AddView(SYMREG::Docks::DAlpha, SYMREG::Views::VAtlasLoad, View_AtlasLoad);
	View_Main->Init(this,UserLib_,LoadoutLib_);
	AddView(SYMREG::Docks::DAlpha, SYMREG::Views::VMain, View_Main);


	SwitchView(SYMREG::Docks::DAlpha, SYMREG::Views::VUser);

	SYM_Mem::FirstOpenComplete = true;
}


USystemUi* USystemUi::Create(SystemPro* InPro, AtlasLibC* InAtlasLib, UserLibC* InUserLib, UserDaisC* InUserDais, LoadoutLibC* InLoadoutLib, LoadoutDaisC* InLoadoutDais)
{
	USystemUi* Neu = CreateWidget<USystemUi>(ScopeC::World(), ClassC::SYM_Alpha());
	Neu->Init(InPro, InAtlasLib, InUserLib, InUserDais, InLoadoutLib, InLoadoutDais);

	return Neu;
}

void USystemUi::Init(SystemPro* InPro, AtlasLibC* InAtlasLib, UserLibC* InUserLib, UserDaisC* InUserDais, LoadoutLibC* InLoadoutLib, LoadoutDaisC* InLoadoutDais)
{
	ConstructAlpha();
	
	Profile_ = InPro;
	AtlasLib_ = InAtlasLib;
	UserLib_ = InUserLib;
	UserDais_ = InUserDais;
	LoadoutLib_ = InLoadoutLib;
	LoadoutDais_ = InLoadoutDais;
}

void USystemUi::UserSelected()
{
	ShowTokens();
	SwitchView(SYMREG::Docks::DAlpha, SYMREG::Views::VPre);
}

void USystemUi::ShowTokens()
{
	V_TokenUser->SetUser(UserDais_->Get());
	V_TokenLoadout->SetLoadout(LoadoutDais_->Get());
}