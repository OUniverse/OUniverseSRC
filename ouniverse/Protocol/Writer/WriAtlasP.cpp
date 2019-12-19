//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/Writer/WriAtlasP.h"
#include "Protocol/Writer/Ui/WriAtlasU.h"
#include "Protocol/Writer/WriPro.h"
#include "Protocol/Writer/Ex/WriData.h"

#include "System/InputID.h"

#include "Ui/Ui.h"

#include "Ui/UiButton.h"
#include "Protocol/Focus.h"



WriAtlasP::WriAtlasP(int InID, WriMenuP* InPro, WriDataC* InWriData) : ProtocolC(InID,this)
{
	Pro_ = InPro;
	WriData_ = InWriData;

	ORack_ = new FocusUiRackC(Focus::FRack, this, true, false);
	RegisterFocus(ORack_);

}

void WriAtlasP::ConstructUi(UWriAtlas* InView)
{
	View_ = InView;
	View_->UiConstruct(this);
	//View_->UiConstruct(this);
}

bool WriAtlasP::InputCommand(KeyS InKey)
{
	return FocalInputCommand(InKey);
}

void WriAtlasP::FluxOpen_Technical(FluxSwitchOpC* InOp)
{
	View_->OpenUI(WriData_->MasterAtlas_);
	View_->Show();		
}

void WriAtlasP::FluxClose_Technical(FluxSwitchOpC* InOp)
{
	View_->Hide();
}