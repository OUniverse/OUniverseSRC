//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/Writer/WriDataP.h"
#include "Protocol/Writer/Ui/WriDataU.h"
#include "Protocol/Writer/WriPro.h"

#include "Protocol/Writer/WriFormEditP.h"
#include "Protocol/Writer/WriDataSearchP.h"

#include "System/InputID.h"
#include "Protocol/FluxOp.h"

#include "Ui/Ui.h"

#include "Ui/UiButton.h"
#include "Protocol/Focus.h"



WriDataP::WriDataP(int InID, WriMenuP* InPro, AtlasLibC* InAtlasLib) : ProtocolC(InID,this)
{
	Pro_ = InPro;
	AtlasLib_ = InAtlasLib;

	FluxDockC* SearchDock_ = AddFluxDock(Dock::DSearch, this);

	WriDataSearch0_ = new WriDataSearchP(Pro::PDataSearch0, this, AtlasLib_);
	SearchDock_->AddFlux(WriDataSearch0_);
	   
	WriDataSearch1_ = new WriDataSearchP(Pro::PDataSearch1, this, AtlasLib_);
	SearchDock_->AddFlux(WriDataSearch1_);

	WriDataSearch2_ = new WriDataSearchP(Pro::PDataSearch2, this, AtlasLib_);
	SearchDock_->AddFlux(WriDataSearch2_);

	FocusSearchDock_ = new FocusDockC(Focus::FSearch, this);
	FocusSearchDock_->SetPath(LeyS::Dir::Cancel, LeyS::Type::Move, Focus::FRack);

	FluxDockC* EditDock_ = AddFluxDock(Dock::DSearch, this);

	WriFormEdit_ = new WriFormEditP(Pro::PFormEdit, this);
	EditDock_->AddFlux(WriFormEdit_);

	FocusEditDock_ = new FocusDockC(Focus::FEdit, this);
	FocusEditDock_->SetPath(LeyS::Dir::Cancel, LeyS::Type::Move, Focus::FRack);

	RegisterFocus(FocusSearchDock_);
	FocusSearchDock_->Set(SearchDock_);

	RegisterFocus(FocusEditDock_);
	FocusEditDock_->Set(EditDock_);

	ORack_ = new FocusUiRackC(Focus::FRack, this, true, false);
	RegisterFocus(ORack_);
}

void WriDataP::ConstructUi(UWriData* InView)
{
	View_ = InView;
	View_->UiConstruct(this,AtlasLib_);

	WriDataSearch0_->ConstructUi(View_->vDataSearch0);
	WriDataSearch1_->ConstructUi(View_->vDataSearch1);
	WriDataSearch2_->ConstructUi(View_->vDataSearch2);
	WriFormEdit_->ConstructUi(View_->vDataEdit);

	//View_->UiConstruct(this);
}

bool WriDataP::InputCommand(KeyS InKey)
{
	return FocalInputCommand(InKey);
}

void WriDataP::FluxOpen_Technical(FluxSwitchOpC* InOp)
{
	View_->Show();
	FluxSwitchOpC* Op = FluxSwitchOpC::Create(this, Dock::DSearch, Pro::PDataSearch0);
	Op->Run();
}

void WriDataP::FluxClose_Technical(FluxSwitchOpC* InOp)
{
	View_->Hide();
}