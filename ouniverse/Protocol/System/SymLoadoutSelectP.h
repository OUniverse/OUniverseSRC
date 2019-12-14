//Copyright 2015-2019, All Rights Reserved.

/**
Protocol for handling the MainMenu.
 */

#pragma once

#include "Protocol/Protocol.h"
#include "System/Input.h"
#include "Enum/DirectionUE.h"

class USymLoadoutSelect;
class UUi;
class LoadoutLibC;
class SymLoadoutMenuP;

class FocusUiC;
class FocusUiRackC;

class OUNIVERSE_API SymLoadoutSelectP : public ProtocolC, public InputC
{

public: 

	SymLoadoutSelectP(int InID, SymLoadoutMenuP* InPro, LoadoutLibC* InLoadoutLib);
	
	void FluxOpen_Technical(FluxSwitchOpC* InOp) override;
	void FluxClose_Technical(FluxSwitchOpC* InOp) override;

	void ConstructUi(USymLoadoutSelect* InView);

	SymLoadoutMenuP* Pro_;
	LoadoutLibC* LoadoutLib_;

	USymLoadoutSelect* View_;

	bool InputCommand(KeyS InKey) override;

	static enum Foc {
		OSolodex,
		FOC_MAX,
	};

	static enum Events {
		EscapeSolodex,
		EVENTS_MAX,
	};

	void EventCode(int ID, int EventID, int Var) override;

	FocusUiC* OSolodex_;
	FocusUiRackC* ORack_;
};