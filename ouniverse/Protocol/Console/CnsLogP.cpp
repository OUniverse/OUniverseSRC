//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/Console/CnsLogP.h"
#include "Protocol/Console/Ui/CnsLogU.h"

#include "System/InputID.h"

#include "Protocol/Focus.h"




CnsLogP::CnsLogP(int InID, CnsShelfP* InPro) : ProtocolC(InID,this)
{
	Pro_ = InPro;
}

void CnsLogP::ConstructUi(UCnsLog* InView)
{
	View_ = InView;
	View_->UiConstruct(this);
}

bool CnsLogP::InputCommand(KeyS InKey)
{
	return FocalInputCommand(InKey);
}

void CnsLogP::FluxOpen_Technical(FluxSwitchOpC* InOp)
{
	View_->Show();
}

void CnsLogP::FluxClose_Technical(FluxSwitchOpC* InOp)
{
	View_->Hide();
}