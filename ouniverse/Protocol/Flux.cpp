//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/Flux.h"
#include "Protocol/FluxOp.h"
#include "Protocol/Protocol.h"
#include "System/Input.h"

#include "Min/DebugM.h"



FluxDockC::FluxDockC(int InID, ProtocolC* InOwner)
{
	ID_ = InID;
	Owner_ = InOwner;
	Op_ = NULL;


	Active_ = NULL;
}

void FluxDockC::AddFlux(ProtocolC* InProtocol)
{
	Fluxs_.Add(InProtocol->FluxID(), InProtocol);
}

ProtocolC* FluxDockC::GetProtocol(int InID)
{
	return Fluxs_.Find(InID);
}

int FluxDockC::FluxDockID()
{
	return ID_;
}

ProtocolC* FluxDockC::FluxGetActiveProtocol()
{
	return Active_;
}

bool FluxDockC::InputCommand(KeyS InKey)
{

	return Active_->Input_->InputCommand(InKey);

}










FluxC::FluxC(int InID)
{
	FluxID_ = InID;
}

FluxDockC* FluxC::AddFluxDock(int InDockID, ProtocolC* InOwner)
{
	FluxDockC* Neu = new FluxDockC(InDockID, InOwner);
	Docks_.Add(InDockID, Neu);
	return Neu;
}

FluxDockC* FluxC::GetFluxDock(int InDockID)
{
	return Docks_.Find(InDockID);
}

void FluxC::FluxSwitch_OpenVisual(FluxSwitchOpC* InOp)
{
	InOp->OpenComplete();
}

void FluxC::FluxSwitch_CloseVisual(FluxSwitchOpC* InOp)
{
	InOp->CloseComplete();
}

void FluxC::FluxSwitch_Transition(FluxSwitchOpC* InOp)
{
	InOp->TransitionComplete();
}

/**
void FluxC::FluxDockEnsure(int InDockID, int InID)
{
	FluxDockC* ThisDock = Docks_.Find(InDockID);
	FluxDataS* Next = &ThisDock->Fluxs_.Find(InID);

	if (ThisDock->Active_ != Next)
	{
		FluxSwitchOpC::Create(this, InDockID, InID)->Run();
	}

}
*/

int FluxC::FluxID()
{
	return FluxID_;
}