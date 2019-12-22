//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/Writer/WriFormEditP.h"
#include "Protocol/Writer/Ui/WriDataU.h"
#include "Protocol/Writer/WriPro.h"

#include "System/InputID.h"

#include "Ui/Ui.h"

#include "Ui/UiButton.h"
#include "Protocol/Focus.h"



WriFormEditP::WriFormEditP(int InID, WriDataP* InPro) : ProtocolC(InID,this)
{
	Pro_ = InPro;
}

void WriFormEditP::ConstructUi(UWriFormEdit* InView)
{
	View_ = InView;
	View_->UiConstruct(this);
}

bool WriFormEditP::InputCommand(KeyS InKey)
{
	return FocalInputCommand(InKey);
}

void WriFormEditP::FluxOpen_Technical(FluxSwitchOpC* InOp)
{
	View_->Show();

}

void WriFormEditP::FluxClose_Technical(FluxSwitchOpC* InOp)
{
	View_->Hide();
}