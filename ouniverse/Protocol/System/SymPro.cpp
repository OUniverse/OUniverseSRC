//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/System/SymPro.h"
#include "Protocol/System/Ui/SymProU.h"
#include "System/Scope.h"
#include "Class/ClassProtocol.h"
#include "Protocol/FluxOp.h"

#include "System/Maestro.h"
#include "Ui/Ui.h"
#include "System/Major.h"

#include "Protocol/System/SymPreP.h"
#include "Protocol/System/SymTokensP.h"
#include "Protocol/System/SymMenuP.h"
#include "Protocol/System/SymUserMenuP.h"
#include "Protocol/System/SymLoadoutMenuP.h"


#include "Min/DebugM.h"

SystemPro* SystemPro::Create(int InID, UMajor* InMajor) 
{
	SystemPro* Neu = new SystemPro(InID, InMajor);
	return Neu;
}

SystemPro::SystemPro(int InID, UMajor* InMajor) : ProtocolC(InID,this)
{
	Major_ = InMajor;
	Maestro_ = Major_->Maestro();
	Ui_ = Major_->Ui();

	FluxDockC* Dock_ = AddFluxDock(Dock::DSym, this);
	
	SymPre_ = new SymPreP(Page::PPre,this);
	Dock_->AddFlux(SymPre_);
	SymMenu_ = new SymMenuP(Page::PMenu,this);
	Dock_->AddFlux(SymMenu_);
	SymUserMenu_ = new SymUserMenuP(Page::PUserMenu, this, Ui_, Major_->UserL());
	Dock_->AddFlux(SymUserMenu_);
	SymLoadoutMenu_ = new SymLoadoutMenuP(Page::PLoadoutMenu, this, Ui_, Major_->LoadoutL());
	Dock_->AddFlux(SymUserMenu_);

	//SymTokens_ = new SymTokensP(ProtocolREG::Flux::FSymTokens);
}


void SystemPro::FluxOpen_Technical(FluxSwitchOpC* InOp)
{
	View_ = CreateWidget<USymPro>(ScopeC::World(), UClassProtocol::Get()->SymProUI);
	Ui_->ToViewport(View_);
	SymUserMenu_->ConstructUi(View_->Page_UserMenu);
	SymLoadoutMenu_->ConstructUi(View_->Page_LoadoutMenu);
	SymPre_->ConstructUi(View_->Page_Pre);
	SymMenu_->ConstructUi(View_->Page_Menu);

	OpenMenu();
}

void SystemPro::FluxClose_Technical(FluxSwitchOpC* InOp)
{
	View_->RemoveFromParent();
	View_ = NULL;
}

void SystemPro::OpenMenu()
{
	FluxSwitchOpC* Op = FluxSwitchOpC::Create(this, Dock::DSym, Page::PMenu);
	Op->DirectInputStack(this);
	Op->Run();
}

void SystemPro::GoUser()
{
	FluxSwitchOpC* Op = FluxSwitchOpC::Create(this, Dock::DSym, Page::PUserMenu);
	Op->DirectInputStack(this);
	Op->Run();
}

void SystemPro::GoLoadout()
{
	FluxSwitchOpC* Op = FluxSwitchOpC::Create(this, Dock::DSym, Page::PLoadoutMenu);
	Op->DirectInputStack(this);
	Op->Run();
}

void SystemPro::GoWriter()
{
	Maestro_->ProWriter();
}