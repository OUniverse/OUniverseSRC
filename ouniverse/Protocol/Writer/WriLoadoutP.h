//Copyright 2015-2019, All Rights Reserved.

/**
Protocol for handling the MainMenu.
 */

#pragma once

#include "Protocol/Protocol.h"
#include "System/Input.h"

class AtlasLibC;
class AtlasC;
class WriDataC;

class WriMenuP;
class WriterPro;
class UWriLoadout;

class FocusUiC;
class FocusUiRackC;

class OUNIVERSE_API WriLoadoutP : public ProtocolC, public InputC
{

public: 

	WriLoadoutP(int InID, WriMenuP* InPro, WriterPro* InWriPro, WriDataC* InWriData, AtlasLibC* InAtlasLib);

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
	
	void AcceptLoad();
	void AcceptNew();

private:

	UWriLoadout* View_;
	WriMenuP* Pro_;
	WriterPro* WriPro_;

	AtlasLibC* AtlasLib_;
	WriDataC* WriData_;

	FocusUiRackC* FRack_;
	FocusUiC* FScroller_;
};