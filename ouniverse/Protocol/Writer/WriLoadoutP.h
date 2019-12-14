//Copyright 2015-2019, All Rights Reserved.

/**
Protocol for handling the MainMenu.
 */

#pragma once

#include "Protocol/Protocol.h"
#include "Protocol/Flux.h"
#include "System/Input.h"

class AtlasLibC;

class WriMenuP;
class UWriLoadout;

class FocusUiC;
class FocusUiRackC;

class OUNIVERSE_API WriLoadoutP : public ProtocolC, public InputC
{

public: 

	WriLoadoutP(int InID, WriMenuP* InPro, AtlasLibC* InAtlasLib);

	UWriLoadout* View_;

	WriMenuP* Pro_;

	AtlasLibC* AtlasLib_;

	void FluxOpen_Technical(FluxSwitchOpC* InOp) override;
	void FluxClose_Technical(FluxSwitchOpC* InOp) override;

	void ConstructUi(UWriLoadout* InView);

	bool InputCommand(KeyS InKey) override;
	

	static enum Focus {
		FRack,
		FScroller,
		FLoad,
		FOCUS_MAX,
	};

	FocusUiRackC* FRack_;
	FocusUiC* FScroller_;
};