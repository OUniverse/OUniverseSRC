//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/Writer/WriMainP.h"
#include "Protocol/Writer/Ui/WriMainU.h"
#include "Protocol/Writer/WriPro.h"

#include "System/InputID.h"

#include "Ui/Ui.h"

#include "Ui/UiButtonNew.h"
#include "Protocol/Focus.h"
#include "Protocol/FluxOp.h"

#include "Protocol/Writer/WriLoadoutP.h"
#include "Protocol/Writer/WriAtlasP.h"
#include "Protocol/Writer/WriFormP.h"

WriMenuP::WriMenuP(int InID, WriterPro* InPro, AtlasLibC* InAtlasLib) : ProtocolC(InID,this)
{
	Pro_ = InPro;
	AtlasLib_ = InAtlasLib;

	FluxDockC* Dock_ = AddFluxDock(Dock::DMain, this);

	WriLoadout_ = new WriLoadoutP(Pro::PLoadout,this,AtlasLib_);
	Dock_->AddFlux(WriLoadout_);
	WriAtlas_ = new WriAtlasP(Pro::PAtlas,this);
	Dock_->AddFlux(WriAtlas_);
	WriForm_ = new WriFormP(Pro::PForm,this);
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
	ORack_->Add(View_->BT_Loadout, Focus::FLoadout);
	ORack_->Add(View_->BT_Atlas, Focus::FAtlas);
	ORack_->Add(View_->BT_Form, Focus::FForm);
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

}

void WriMenuP::AcceptForm()
{

}