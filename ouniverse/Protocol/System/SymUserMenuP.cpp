//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/System/SymUserMenuP.h"
#include "Protocol/FluxOp.h"
#include "System/InputID.h"

#include "Ui/Ui.h"

#include "Protocol/System/SymPro.h"
#include "Protocol/System/Ui/SymUserMenuU.h"
#include "Ui/UiButton.h"
#include "Protocol/Focus.h"

#include "Protocol/System/SymUserSelectP.h"
#include "Protocol/System/SymUserCreateP.h"
#include "Protocol/System/SymUserEditP.h"

#include "Protocol/System/Ui/SymUserSelectU.h"


SymUserMenuP::SymUserMenuP(int InID, SystemPro* InSym, UUi* InUI, UserLibC* InUserLib) : ProtocolC(InID,this)
{
	System_ = InSym;
	Ui_ = InUI;
	UserLib_ = InUserLib;

	FluxDockC* Dock_ = AddFluxDock(Dock::DUser, this);

	SymUserSelect_ = new SymUserSelectP(Flux::VSelect, this, UserLib_);
	Dock_->AddFlux(SymUserSelect_);
	SymUserCreate_ = new SymUserCreateP(Flux::VCreate);
	Dock_->AddFlux(SymUserCreate_);
	SymUserEdit_ = new SymUserEditP(Flux::VEdit);
	Dock_->AddFlux(SymUserEdit_);

	ODock_ = new FocusDockC(Focus::FDock, this);
	ODock_->SetPath(LeyS::Dir::Cancel, LeyS::Type::Move, Focus::FRack);

	RegisterFocus(ODock_);
	ODock_->Set(Dock_);

	ORack_ = new FocusUiRackC(Focus::FRack, this, true, false);
	RegisterFocus(ORack_);

}

void SymUserMenuP::FluxOpen_Technical(FluxSwitchOpC* InOp)
{
	View_->Show();
	//AcceptSelect();
	FocalActivate(Focus::FRack);
}

void SymUserMenuP::FluxClose_Technical(FluxSwitchOpC* InOp)
{
	View_->Hide();
}

void SymUserMenuP::ConstructUi(USymUserMenu* InView)
{
	View_ = InView;
	View_->UiConstruct(this);
	SymUserSelect_->ConstructUi(View_->View_Select);
	SymUserCreate_->ConstructUi(View_->View_Create);
	SymUserEdit_->ConstructUi(View_->View_Edit);

	ORack_->Reset();
	ORack_->Add(View_->V_Create, Focus::FRackNew);
	ORack_->Add(View_->V_Select, Focus::FRackSelect);
	ORack_->Add(View_->V_Edit, Focus::FRackEdit);
	ORack_->Add(View_->V_Back, Focus::FRackBack);
}


bool SymUserMenuP::InputCommand(KeyS InKey)
{
	return FocalInputCommand(InKey);
}

void SymUserMenuP::FocusChanged(int InID)
{
	FluxSwitchOpC* Op;

	switch (InID) {
	case Focus::FRackNew:
		Op = FluxSwitchOpC::Create(this, Dock::DUser, Flux::VCreate);
		Op->Run();
		return;
	case Focus::FRackSelect:
		Op = FluxSwitchOpC::Create(this, Dock::DUser, Flux::VSelect);
		Op->Run();
		return;
	case Focus::FRackEdit:
		Op = FluxSwitchOpC::Create(this, Dock::DUser, Flux::VEdit);
		Op->Run();
		return;
	}
}

void SymUserMenuP::AcceptCreate()
{

	FluxSwitchOpC* Op = FluxSwitchOpC::Create(this, Dock::DUser, Flux::VCreate);
	Op->Ensure();
	Op->FocalSwap(Focus::FDock);
	Op->Run();
}

void SymUserMenuP::AcceptSelect()
{
	FluxSwitchOpC* Op = FluxSwitchOpC::Create(this, Dock::DUser, Flux::VSelect);
	Op->Ensure();
	Op->FocalSwap(Focus::FDock);
	Op->Run();
}

void SymUserMenuP::AcceptEdit()
{
	FluxSwitchOpC* Op = FluxSwitchOpC::Create(this, Dock::DUser, Flux::VEdit);
	Op->Ensure();
	Op->FocalSwap(Focus::FDock);
	Op->Run();
}

void SymUserMenuP::AcceptBack()
{
	System_->OpenMenu();
}

void SymUserMenuP::DockEscape()
{
	FocalTrigger(SymUserMenuP::Focus::FDock, LeyS::Dir::Cancel);
}