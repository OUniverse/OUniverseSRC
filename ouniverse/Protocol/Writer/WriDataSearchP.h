//Copyright 2015-2019, All Rights Reserved.

/**
Protocol for handling the MainMenu.
 */

#pragma once

#include "Protocol/Protocol.h"
#include "System/Input.h"

class WriDataP;
class UWriDataSearch;
class FocusUiRackC;
class AtlasLibC;
class FocusUiC;
class FocusDockC;
class FocusRackC;

class OUNIVERSE_API WriDataSearchP : public ProtocolC, public InputC
{

public: 

	WriDataSearchP(int InID, WriDataP* InPro, AtlasLibC* InAtlasLi);

	UWriDataSearch* View_;

	WriDataP* Pro_;

	AtlasLibC* AtlasLib_;

	FocusUiC* FocusScroll_;
	FocusDockC* FocusDock_;
	FocusRackC* FocusRack_;

	void FluxOpen_Technical(FluxSwitchOpC* InOp) override;
	void FluxClose_Technical(FluxSwitchOpC* InOp) override;

	void ConstructUi(UWriDataSearch* InView);

	bool InputCommand(KeyS InKey) override;

	static enum Focus {
		FDock,
		FRack,
		FScroll,
		FOCUS_MAX,
	};

	FocusUiRackC* ORack_;

};