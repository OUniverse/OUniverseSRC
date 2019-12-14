//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/Writer/WriLoadoutP.h"
#include "Protocol/Writer/Ui/WriLoadoutU.h"
#include "Protocol/Writer/Ui/WriLoadoutU_Scroll.h"
#include "Protocol/Writer/Ui/WriLoadoutU_ScrollEntry.h"
#include "Protocol/Writer/WriPro.h"

#include "System/InputID.h"
#include "Ui/Ui.h"

#include "Ui/UiButtonNew.h"
#include "Protocol/Focus.h"



WriLoadoutP::WriLoadoutP(int InID, WriMenuP* InPro, AtlasLibC* InAtlasLib) : ProtocolC(InID,this)
{
	Pro_ = InPro;
	AtlasLib_ = InAtlasLib;

	FScroller_ = new FocusUiC(Focus::FRack, this);
	RegisterFocus(FScroller_);

	FRack_ = new FocusUiRackC(Focus::FRack, this, true, false);
	RegisterFocus(FRack_);
}

void WriLoadoutP::ConstructUi(UWriLoadout* InView)
{
	View_ = InView;
	View_->UiConstruct(this,AtlasLib_);
}

bool WriLoadoutP::InputCommand(KeyS InKey)
{
	return FocalInputCommand(InKey);
}

void WriLoadoutP::FluxOpen_Technical(FluxSwitchOpC* InOp)
{
	View_->Show();	
	View_->OpenUi();
}

void WriLoadoutP::FluxClose_Technical(FluxSwitchOpC* InOp)
{
	View_->Hide();
}