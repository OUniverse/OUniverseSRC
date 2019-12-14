//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Interface/Map.h"
#include "System/InputData.h"

class FluxC;
class FluxOpC;

class FluxSwitchOpC;

class ProtocolC;
class InputC;


class OUNIVERSE_API FluxDockC
{

public:

	FluxDockC(int InID, ProtocolC* InOwner);


	FluxOpC* Op_;

	ProtocolC* Owner_;

	ProtocolC* Active_;
	   
	MapC<int, ProtocolC*> Fluxs_;

	void AddFlux(ProtocolC* InProtocol);

	ProtocolC* GetProtocol(int InID);

	ProtocolC* FluxGetActiveProtocol();

	int FluxDockID();
	int ID_;

	bool InputCommand(KeyS InKey);

};

class OUNIVERSE_API FluxC 
{

public:

	FluxC(int ID_);
	virtual ~FluxC() {};
	FluxDockC* AddFluxDock(int InDockID, ProtocolC* InOwner);

	FluxDockC* GetFluxDock(int InDockID);

	MapC<int,FluxDockC*> Docks_;

	virtual void FluxOpen_Technical(FluxSwitchOpC* InOp) {};
	virtual void FluxClose_Technical(FluxSwitchOpC* InOp) {};

	virtual void FluxSwitch_Transition(FluxSwitchOpC* InOp);
	virtual void FluxSwitch_OpenVisual(FluxSwitchOpC* InOp);
	virtual void FluxSwitch_CloseVisual(FluxSwitchOpC* InOp);


	int FluxID();
	int FluxID_;
};