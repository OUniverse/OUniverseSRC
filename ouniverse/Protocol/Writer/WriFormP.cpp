//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/Writer/WriFormP.h"
#include "Protocol/Writer/Ui/WriFormU.h"
#include "Protocol/Writer/WriPro.h"

#include "Protocol/Writer/WriFormEditP.h"

#include "System/InputID.h"

#include "Ui/Ui.h"

#include "Ui/UiButton.h"
#include "Protocol/Focus.h"



WriFormP::WriFormP(int InID, WriMenuP* InPro, AtlasLibC* InAtlasLib) : ProtocolC(InID,this)
{
	Pro_ = InPro;
	AtlasLib_ = InAtlasLib;

	FluxDockC* NewDock_ = AddFluxDock(Dock::DForm, this);

	WriFormEdit_ = new WriFormEditP(Pro::PFormEdit, this);
	NewDock_->AddFlux(WriFormEdit_);

	FocusScroll_ = new FocusUiC(Focus::FScroll, this);
	RegisterFocus(FocusScroll_);

	FocusDock_ = new FocusDockC(Focus::FDock, this);
	FocusDock_->SetPath(LeyS::Dir::Cancel, LeyS::Type::Move, Focus::FRack);

	RegisterFocus(FocusDock_);
	FocusDock_->Set(NewDock_);

	ORack_ = new FocusUiRackC(Focus::FRack, this, true, false);
	RegisterFocus(ORack_);
}

void WriFormP::ConstructUi(UWriForm* InView)
{
	View_ = InView;
	View_->UiConstruct(this,AtlasLib_);

	WriFormEdit_->ConstructUi(View_->vFormEdit);

	//View_->UiConstruct(this);
}

bool WriFormP::InputCommand(KeyS InKey)
{
	return FocalInputCommand(InKey);
}

void WriFormP::FluxOpen_Technical(FluxSwitchOpC* InOp)
{
	View_->Show();

}

void WriFormP::FluxClose_Technical(FluxSwitchOpC* InOp)
{
	View_->Hide();
}