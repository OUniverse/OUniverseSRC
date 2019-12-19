//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/System/SymLoadoutMenuP.h"
#include "Protocol/FluxOp.h"
#include "System/InputID.h"

#include "Ui/Ui.h"

#include "Protocol/System/SymPro.h"
#include "Protocol/System/Ui/SymLoadoutMenuU.h"
#include "Ui/UiButton.h"
#include "Protocol/Focus.h"

#include "Protocol/System/SymLoadoutSelectP.h"


#include "Protocol/System/Ui/SymLoadoutSelectU.h"


SymLoadoutMenuP::SymLoadoutMenuP(int InID, SystemPro* InSym, UUi* InUI, LoadoutLibC* InLoadoutLib) : ProtocolC(InID,this)
{
	System_ = InSym;
	Ui_ = InUI;
	LoadoutLib_ = InLoadoutLib;

	FluxDockC* Dock_ = AddFluxDock(Dock::DLoadout, this);

	SymLoadoutSelect_ = new SymLoadoutSelectP(Flux::VSelect, this, LoadoutLib_);
	Dock_->AddFlux(SymLoadoutSelect_);

	ODock_ = new FocusDockC(Focus::FDock, this);
	ODock_->SetPath(LeyS::Dir::Cancel, LeyS::Type::Move, Focus::FRack);

	RegisterFocus(ODock_);
	ODock_->Set(Dock_);

	ORack_ = new FocusUiRackC(Focus::FRack, this, true, false);
	RegisterFocus(ORack_);

}


void SymLoadoutMenuP::ConstructUi(USymLoadoutMenu* InView)
{
	View_ = InView;
}

void SymLoadoutMenuP::FluxOpen_Technical(FluxSwitchOpC* InOp)
{
	View_->Show();
	//SymLoadoutMenuUI_ = CreateWidget<USymLoadoutMenu>(ScopeC::World(), UClassProtocol::Get()->SymLoadoutMenuUI);
	//Ui_->ToViewport(SymLoadoutMenuUI_);
	//SymLoadoutMenuUI_->UiConstruct(this);
	//SymLoadoutSelect_->ConstructUi(SymLoadoutMenuUI_->View_Select);

	//ORack_->Reset();
	//ORack_->Add(View_->V_Back, Focus::FRackBack);

	AcceptSelect();
}

void SymLoadoutMenuP::FluxClose_Technical(FluxSwitchOpC* InOp)
{
	View_->Hide();
}

bool SymLoadoutMenuP::InputCommand(KeyS InKey)
{
	return FocalInputCommand(InKey);
}

void SymLoadoutMenuP::FocusChanged(int InID)
{
	FluxSwitchOpC* Op;

	switch (InID) {
	case Focus::FRackNew:
		Op = FluxSwitchOpC::Create(this, Dock::DLoadout, Flux::VCreate);
		Op->Run();
		return;
	case Focus::FRackSelect:
		Op = FluxSwitchOpC::Create(this, Dock::DLoadout, Flux::VSelect);
		Op->Run();
		return;
	case Focus::FRackEdit:
		Op = FluxSwitchOpC::Create(this, Dock::DLoadout, Flux::VEdit);
		Op->Run();
		return;
	}
}

void SymLoadoutMenuP::AcceptCreate()
{

	FluxSwitchOpC* Op = FluxSwitchOpC::Create(this, Dock::DLoadout, Flux::VCreate);
	Op->Ensure();
	Op->FocalSwap(Focus::FDock);
	Op->Run();
	//FocalActivate(Focus::FDock);
}

void SymLoadoutMenuP::AcceptSelect()
{
	FluxSwitchOpC* Op = FluxSwitchOpC::Create(this, Dock::DLoadout, Flux::VSelect);
	Op->Ensure();
	Op->FocalSwap(Focus::FDock);
	Op->Run();
}

void SymLoadoutMenuP::AcceptEdit()
{
	FluxSwitchOpC* Op = FluxSwitchOpC::Create(this, Dock::DLoadout, Flux::VEdit);
	Op->Ensure();
	Op->FocalSwap(Focus::FDock);
	Op->Run();
}

void SymLoadoutMenuP::AcceptBack()
{

}

void SymLoadoutMenuP::DockEscape()
{
	FocalTrigger(SymLoadoutMenuP::Focus::FDock, LeyS::Dir::Cancel);
}