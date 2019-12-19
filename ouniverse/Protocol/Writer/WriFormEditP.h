//Copyright 2015-2019, All Rights Reserved.

/**
Protocol for handling the MainMenu.
 */

#pragma once

#include "Protocol/Protocol.h"
#include "System/Input.h"


class WriMenuP;

class UWriForm;
class FocusUiRackC;

class AtlasLibC;

class OUNIVERSE_API WriFormEditP : public ProtocolC, public InputC
{

public: 

	WriFormEditP(int InID, WriFormP* InPro);

	UWriFormEdit* View_;

	WriFormP* Pro_;

	void FluxOpen_Technical(FluxSwitchOpC* InOp) override;
	void FluxClose_Technical(FluxSwitchOpC* InOp) override;

	void ConstructUi(UWriFormEdit* InView);

	bool InputCommand(KeyS InKey) override;

	static enum Focus {
		FRack,
		FStart,
		FBack,
		FOCUS_MAX,
	};

	FocusUiRackC* ORack_;


};