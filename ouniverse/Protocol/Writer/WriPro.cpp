//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/Writer/WriPro.h"
#include "Protocol/Writer/Ui/WriProU.h"
#include "System/Scope.h"
#include "Class/ClassProtocol.h"

#include "Protocol/Writer/WriMainP.h"
#include "Protocol/Writer/WriSplashP.h"

#include "System/Maestro.h"
#include "Ui/Ui.h"
#include "System/Major.h"

#include "Protocol/FluxOp.h"

#include "Min/DebugM.h"

WriterPro* WriterPro::Create(int InID, UMajor* InMajor) 
{
	WriterPro* Neu = new WriterPro(InID, InMajor);
	return Neu;
}

WriterPro::WriterPro(int InID, UMajor* InMajor) : ProtocolC(InID,this)
{
	Major_ = InMajor;
	Maestro_ = Major_->Maestro();
	Ui_ = Major_->Ui();

	FluxDockC* Dock_ = AddFluxDock(Dock::DWri, this);

	WriMain_ = new WriMenuP(Pro::PMain,this,Major_->Atlas());
	Dock_->AddFlux(WriMain_);

	WriSplash_ = new WriSplashP(Pro::PSplash, this);
	Dock_->AddFlux(WriSplash_);

	//SymUserMenu_ = new SymUserMenuP(Page::PUserMenu, this, Ui_, Major_->UserL());
	//Dock_->AddFlux(SymUserMenu_, SymUserMenu_);
	
	//SymTokens_ = new SymTokensP(ProtocolREG::Flux::FSymTokens);
}


void WriterPro::FluxOpen_Technical(FluxSwitchOpC* InOp)
{
	View_ = CreateWidget<UWriPro>(ScopeC::World(), UClassProtocol::Get()->WriProUI);
	Ui_->ToViewport(View_);
	WriMain_->ConstructUi(View_->View_Menu);
	WriSplash_->ConstructUi(View_->View_Splash);

	OpenSplash();
}

void WriterPro::FluxClose_Technical(FluxSwitchOpC* InOp)
{
	View_->RemoveFromParent();
	View_ = NULL;
}

void WriterPro::OpenSplash()
{
	FluxSwitchOpC* Op = FluxSwitchOpC::Create(this, Dock::DWri, Pro::PSplash);
	Op->DirectInputStack(this);
	Op->Run();
}

void WriterPro::GoMain()
{
	FluxSwitchOpC* Op = FluxSwitchOpC::Create(this, Dock::DWri, Pro::PMain);
	Op->DirectInputStack(this);
	Op->Run();
}

void WriterPro::EscWriter()
{
	Maestro_->ProSystem();
}