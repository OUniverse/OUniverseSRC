//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/Console/CnsOutputP.h"
#include "Protocol/Console/Ui/CnsOutputU.h"

#include "System/InputID.h"





CnsOutputP::CnsOutputP(int InID,CnsShelfP* InPro) : ProtocolC(InID,this)
{
	Pro_ = InPro;
}

void CnsOutputP::ConstructUi(UCnsOutput* InView)
{
	View_ = InView;
	View_->UiConstruct(this);
}

bool CnsOutputP::InputCommand(KeyS InKey)
{
	return FocalInputCommand(InKey);
}

void CnsOutputP::FluxOpen_Technical(FluxSwitchOpC* InOp)
{
	View_->Show();
}

void CnsOutputP::FluxClose_Technical(FluxSwitchOpC* InOp)
{
	View_->Hide();
}