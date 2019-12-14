//Copyright 2015-2019, All Rights Reserved.

/**
Protocol for handling the MainMenu.
 */

#pragma once

#include "Protocol/Protocol.h"
#include "System/Input.h"
#include "Enum/DirectionUE.h"

class USymUserSelect;
class UUi;
class UserLibC;
class SymUserMenuP;

class FocusUiC;
class FocusUiRackC;

class OUNIVERSE_API SymUserSelectP : public ProtocolC, public InputC
{

public: 

	SymUserSelectP(int InID, SymUserMenuP* InPro, UserLibC* InUserLib);
	
	void FluxOpen_Technical(FluxSwitchOpC* InOp) override;
	void FluxClose_Technical(FluxSwitchOpC* InOp) override;

	void ConstructUi(USymUserSelect* InView);

	SymUserMenuP* Pro_;
	UserLibC* UserLib_;

	USymUserSelect* View_;

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