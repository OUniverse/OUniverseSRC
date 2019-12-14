//Copyright 2015-2019, All Rights Reserved.

/**
Protocol for handling the MainMenu.
 */

#pragma once

#include "Protocol/Protocol.h"
#include "Protocol/Flux.h"
#include "System/Input.h"


class WriMenuP;

class UWriForm;
class FocusUiRackC;


class OUNIVERSE_API WriFormP : public ProtocolC, public InputC
{

public: 

	WriFormP(int InID, WriMenuP* InPro);

	UWriForm* View_;

	WriMenuP* Pro_;

	void FluxOpen_Technical(FluxSwitchOpC* InOp) override;
	void FluxClose_Technical(FluxSwitchOpC* InOp) override;

	void ConstructUi(UWriForm* InView);

	bool InputCommand(KeyS InKey) override;

	static enum Focus {
		FRack,
		FStart,
		FBack,
		FOCUS_MAX,
	};

	FocusUiRackC* ORack_;

};