//Copyright 2015-2019, All Rights Reserved.

/**
Protocol for handling the MainMenu.
 */

#pragma once

#include "Protocol/Protocol.h"
#include "System/Input.h"


class WriMenuP;
class WriDataC;

class UWriAtlas;
class FocusUiRackC;


class OUNIVERSE_API WriAtlasP : public ProtocolC, public InputC
{

public: 

	WriAtlasP(int InID, WriMenuP* InPro, WriDataC* InWriData);

	UWriAtlas* View_;
	WriDataC* WriData_;

	WriMenuP* Pro_;

	void FluxOpen_Technical(FluxSwitchOpC* InOp) override;
	void FluxClose_Technical(FluxSwitchOpC* InOp) override;

	void ConstructUi(UWriAtlas* InView);

	bool InputCommand(KeyS InKey) override;

	static enum Focus {
		FRack,
		FStart,
		FBack,
		FOCUS_MAX,
	};

	FocusUiRackC* ORack_;

};