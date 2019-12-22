//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/Writer/WriPro.h"
#include "Protocol/Writer/Ui/WriProU.h"
#include "Protocol/Writer/Ex/WriData.h"
#include "System/Scope.h"
#include "Class/ClassProtocol.h"

#include "Protocol/Writer/WriMainP.h"
#include "Protocol/Writer/WriSplashP.h"
#include "Protocol/Writer/WriFooterP.h"
#include "Protocol/Writer/WriDataLoadP.h"

#include "System/Maestro.h"
#include "Ui/Ui.h"
#include "System/Major.h"

#include "Protocol/FluxOp.h"

#include "Interface/Dict.h"
#include "Interface/Url.h"

namespace WriterGlobal
{
	WriterPro* Pro;
}


WriterPro* WriterPro::Create(int InID, UMajor* InMajor) 
{
	WriterPro* Neu = new WriterPro(InID, InMajor);
	WriterGlobal::Pro = Neu;
	return Neu;
}

WriterPro::WriterPro(int InID, UMajor* InMajor) : ProtocolC(InID,this)
{
	Major_ = InMajor;
	Maestro_ = Major_->Maestro();
	Ui_ = Major_->Ui();

	WriterDict_ = new DictC();

	WriData_ = new WriDataC(Major_->Atlas());

	FluxDockC* Dock_ = AddFluxDock(Dock::DWri, this);

	WriMain_ = new WriMenuP(Pro::PMain,this,WriData_,Major_->Atlas());
	Dock_->AddFlux(WriMain_);

	WriDataLoad_ = new WriDataLoadP(Pro::PDataLoad, this,WriData_);
	Dock_->AddFlux(WriDataLoad_);

	WriSplash_ = new WriSplashP(Pro::PSplash, this);
	Dock_->AddFlux(WriSplash_);

	WriFooter_ = new WriFooterP(Pro::PFooter,this);

	//SymUserMenu_ = new SymUserMenuP(Page::PUserMenu, this, Ui_, Major_->UserL());
	//Dock_->AddFlux(SymUserMenu_, SymUserMenu_);
	
	//SymTokens_ = new SymTokensP(ProtocolREG::Flux::FSymTokens);
}

FText WriterPro::Dict(int InID)
{
	return WriterGlobal::Pro->WriterDict_->Get(InID).ToFText();
}

void WriterPro::FluxOpen_Technical(FluxSwitchOpC* InOp)
{
	
	WriterDict_->Load(PathC::FileDictWriter());

	View_ = CreateWidget<UWriPro>(ScopeC::World(), UClassProtocol::Get()->WriProUI);
	Ui_->ToViewport(View_);
	WriDataLoad_->ConstructUi(View_->View_DataLoad);
	WriMain_->ConstructUi(View_->View_Menu);
	WriSplash_->ConstructUi(View_->View_Splash);
	WriFooter_->ConstructUi(View_->View_Footer);

	OpenSplash();
}

void WriterPro::FluxClose_Technical(FluxSwitchOpC* InOp)
{
	WriterDict_->Clear();
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

void WriterPro::GoDataLoad()
{
	FluxSwitchOpC* Op = FluxSwitchOpC::Create(this, Dock::DWri, Pro::PDataLoad);
	Op->DirectInputStack(this);
	Op->Run();
}

void WriterPro::EscWriter()
{
	Maestro_->ProSystem();
}