//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/Writer/WriFormP.h"
#include "Protocol/Writer/Ui/WriFormU.h"
#include "Protocol/Writer/WriPro.h"

#include "System/InputID.h"

#include "Ui/Ui.h"

#include "Ui/UiButtonNew.h"
#include "Protocol/Focus.h"



WriFormP::WriFormP(int InID, WriMenuP* InPro) : ProtocolC(InID,this)
{
	Pro_ = InPro;

}

void WriFormP::ConstructUi(UWriForm* InView)
{
	View_ = InView;
	View_->UiConstruct(this);
	//View_->UiConstruct(this);
}

bool WriFormP::InputCommand(KeyS InKey)
{
	return FocalInputCommand(InKey);
}

void WriFormP::FluxOpen_Technical(FluxSwitchOpC* InOp)
{


}

void WriFormP::FluxClose_Technical(FluxSwitchOpC* InOp)
{
	View_->Hide();
}