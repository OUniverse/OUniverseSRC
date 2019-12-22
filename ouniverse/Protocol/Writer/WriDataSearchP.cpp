//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/Writer/WriDataSearchP.h"
#include "Protocol/Writer/Ui/WriDataSearchU.h"
#include "Protocol/Writer/WriPro.h"

#include "Protocol/Writer/WriDataSearchP.h"

#include "System/InputID.h"

#include "Ui/Ui.h"

#include "Ui/UiButton.h"
#include "Protocol/Focus.h"



WriDataSearchP::WriDataSearchP(int InID, WriDataP* InPro, AtlasLibC* InAtlasLib) : ProtocolC(InID,this)
{
	Pro_ = InPro;
	AtlasLib_ = InAtlasLib;

	FocusScroll_ = new FocusUiC(Focus::FScroll, this);
	RegisterFocus(FocusScroll_);

	ORack_ = new FocusUiRackC(Focus::FRack, this, true, false);
	RegisterFocus(ORack_);
}

void WriDataSearchP::ConstructUi(UWriDataSearch* InView)
{
	View_ = InView;
	View_->UiConstruct(this,AtlasLib_);
}

bool WriDataSearchP::InputCommand(KeyS InKey)
{
	return FocalInputCommand(InKey);
}

void WriDataSearchP::FluxOpen_Technical(FluxSwitchOpC* InOp)
{
	View_->Show();

}

void WriDataSearchP::FluxClose_Technical(FluxSwitchOpC* InOp)
{
	View_->Hide();
}