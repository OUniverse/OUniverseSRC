//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/FluxOp.h"
#include "Protocol/Protocol.h"
#include "System/Input.h"


FluxOpC::FluxOpC(FluxOpC::Type InType)
{

}


FluxSwitchOpC* FluxSwitchOpC::Create(ProtocolC* InOwner, int DockID, int PendingID)
{
	FluxSwitchOpC* Neu = new FluxSwitchOpC(InOwner, DockID, PendingID);
	return Neu;
}

FluxSwitchOpC::FluxSwitchOpC(ProtocolC* InOwner, int DockID, int PendingFluxID) : FluxOpC(FluxOpC::Type::Switch)
{
	Dock_ = NULL;
	Pending_ = NULL;
	InputStack_ = NULL;
	FocalID_ = -1;

	Owner_ = InOwner;
	PendingID_ = PendingFluxID;
	DockID_ = DockID;
}



void FluxSwitchOpC::Run()
{
	Dock_ = Owner_->GetFluxDock(DockID_);
	Pending_ = Dock_->GetProtocol(PendingID_);

	if (Dock_->Active_ == NULL)
	{
		Dock_->Active_ = Pending_;
		Dock_->Active_->FluxOpen_Technical(this);
		Dock_->Active_->FluxSwitch_OpenVisual(this);
	}
	else
	{
		Dock_->Active_->FluxSwitch_CloseVisual(this);
	}
}

void FluxSwitchOpC::TransitionComplete()
{
	Dock_->Active_->FluxOpen_Technical(this);
	Dock_->Active_->FluxSwitch_OpenVisual(this);
}

void FluxSwitchOpC::OpenComplete()
{
	if (InputStack_ != NULL)
	{
		InputStack_->InputStackAdd(Dock_->Active_->Input_);
	}

	if (FocalID_ != -1)
	{
		Dock_->Active_->FocalActivate(FocalID_);

	}
	delete this;
}

void FluxSwitchOpC::CloseComplete()
{
	Dock_->Active_->FluxClose_Technical(this);

	if (InputStack_ != NULL)
	{
		InputStack_->InputStackRemove(Dock_->Active_->Input_);
	}

	Dock_->Active_ = Pending_;
	Dock_->Active_->FluxSwitch_Transition(this);
}

void FluxSwitchOpC::DirectInputStack(InputStackC* InStack)
{
	InputStack_ = InStack;
}

void FluxSwitchOpC::Ensure()
{
	Ensure_ = true;
}

void FluxSwitchOpC::FocalSwap(int FocalID)
{
	FocalID_ = FocalID;
}