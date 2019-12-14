//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/System/SymPreP.h"
#include "Protocol/System/Ui/SymPreU.h"

SymPreP::SymPreP(int InID, SystemPro* InPro) : ProtocolC(InID,this)
{
	Pro_ = InPro;
}

void SymPreP::ConstructUi(USymPre* InView)
{
	View_ = InView;
}

void SymPreP::FluxOpen_Technical(FluxSwitchOpC* InOp)
{
	View_->Show();
}

void  SymPreP::FluxClose_Technical(FluxSwitchOpC* InOp)
{
	View_->Hide();
}