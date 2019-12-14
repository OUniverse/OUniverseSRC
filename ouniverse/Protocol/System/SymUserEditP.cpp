//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/System/SymUserEditP.h"
#include "Protocol/System/Ui/SymUserEditU.h"

SymUserEditP::SymUserEditP(int InID) : ProtocolC(InID,this)
{

}

void SymUserEditP::ConstructUi(USymUserEdit* InView)
{
	View_ = InView;
}

void SymUserEditP::FluxOpen_Technical(FluxSwitchOpC* InOp)
{
	View_->Show();
	View_->UiConstruct(this);

	//FocalActivate(Foc::OSolodex);
}

void SymUserEditP::FluxClose_Technical(FluxSwitchOpC* InOp)
{
	View_->Hide();
}