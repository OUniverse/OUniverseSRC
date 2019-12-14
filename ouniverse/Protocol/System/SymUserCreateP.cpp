//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/System/SymUserCreateP.h"
#include "Protocol/System/Ui/SymUserCreateU.h"

SymUserCreateP::SymUserCreateP(int InID) : ProtocolC(InID,this)
{

}

void SymUserCreateP::ConstructUi(USymUserCreate* InView)
{
	View_ = InView;
}


void SymUserCreateP::FluxOpen_Technical(FluxSwitchOpC* InOp)
{
	View_->Show();
	View_->UiConstruct(this);

	//FocalActivate(Foc::OSolodex);
}

void SymUserCreateP::FluxClose_Technical(FluxSwitchOpC* InOp)
{

}