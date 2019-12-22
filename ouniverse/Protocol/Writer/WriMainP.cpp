//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/Writer/WriMainP.h"
#include "Protocol/Writer/Ui/WriMainU.h"
#include "Protocol/Writer/WriPro.h"

#include "System/InputID.h"

#include "Ui/Ui.h"

#include "Ui/UiButton.h"
#include "Protocol/Focus.h"
#include "Protocol/FluxOp.h"

#include "Protocol/Writer/WriLoadoutP.h"
#include "Protocol/Writer/WriAtlasP.h"
#include "Protocol/Writer/WriDataP.h"

#include "Protocol/Writer/Ui/WriButtonOptU.h"

WriMenuP::WriMenuP(int InID, WriterPro* InPro, WriDataC* InWriData, AtlasLibC* InAtlasLib) : ProtocolC(InID,this)
{
	Pro_ = InPro;
	AtlasLib_ = InAtlasLib;
	WriData_ = InWriData;

	FluxDockC* Dock_ = AddFluxDock(Dock::DMain, this);

	WriLoadout_ = new WriLoadoutP(Pro::PLoadout,this,Pro_,WriData_,AtlasLib_);
	Dock_->AddFlux(WriLoadout_);
	WriAtlas_ = new WriAtlasP(Pro::PAtlas,this,WriData_);
	Dock_->AddFlux(WriAtlas_);
	WriForm_ = new WriDataP(Pro::PForm,this,AtlasLib_);
	Dock_->AddFlux(WriForm_);

	ODock_ = new FocusDockC(Focus::FDock, this);
	ODock_->SetPath(LeyS::Dir::Cancel, LeyS::Type::Move, Focus::FRack);

	RegisterFocus(ODock_);
	ODock_->Set(Dock_);

	ORack_ = new FocusUiRackC(Focus::FRack, this, true, false);
	RegisterFocus(ORack_);
}

void WriMenuP::ConstructUi(UWriMenu* InView)
{
	View_ = InView;
	View_->UiConstruct(this);
	WriLoadout_->ConstructUi(View_->View_Loadout);
	WriAtlas_->ConstructUi(View_->View_Atlas);
	WriForm_->ConstructUi(View_->View_Form);
}

bool WriMenuP::InputCommand(KeyS InKey)
{
	return FocalInputCommand(InKey);
}

void WriMenuP::FluxOpen_Technical(FluxSwitchOpC* InOp)
{
	View_->Show();

	ORack_->Reset();
	ORack_->Add(View_->vLoadout, Focus::FLoadout);
	ORack_->Add(View_->vAtlas, Focus::FAtlas);
	ORack_->Add(View_->vData, Focus::FData);
	ORack_->Add(View_->vWorld, Focus::FWorld);
	ORack_->Add(View_->vTools, Focus::FTools);
	ORack_->Add(View_->vExit, Focus::FExit);

	FocalActivate(Focus::FRack);
	AcceptLoadout();
}

void WriMenuP::FluxClose_Technical(FluxSwitchOpC* InOp)
{
	View_->Hide();
}

void WriMenuP::AcceptLoadout()
{
	FluxSwitchOpC* Op = FluxSwitchOpC::Create(this, Dock::DMain, Pro::PLoadout);
	//Op->FocalSwap(Focus::FDock);
	Op->Run();
}

void WriMenuP::AcceptAtlas()
{
	FluxSwitchOpC* Op = FluxSwitchOpC::Create(this, Dock::DMain, Pro::PAtlas);
	//Op->FocalSwap(Focus::FDock);
	Op->Run();
}

void WriMenuP::AcceptForm()
{
	FluxSwitchOpC* Op = FluxSwitchOpC::Create(this, Dock::DMain, Pro::PForm);
	//Op->FocalSwap(Focus::FDock);
	Op->Run();
}