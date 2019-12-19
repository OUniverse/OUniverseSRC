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

class WriFormEditP;

class FocusUiC;
class FocusDockC;
class FocusRackC;

class OUNIVERSE_API WriFormP : public ProtocolC, public InputC
{

public: 

	WriFormP(int InID, WriMenuP* InPro, AtlasLibC* InAtlasLi);

	UWriForm* View_;

	WriMenuP* Pro_;

	AtlasLibC* AtlasLib_;


	WriFormEditP* WriFormEdit_;

	FocusUiC* FocusScroll_;
	FocusDockC* FocusDock_;
	FocusRackC* FocusRack_;

	void FluxOpen_Technical(FluxSwitchOpC* InOp) override;
	void FluxClose_Technical(FluxSwitchOpC* InOp) override;

	void ConstructUi(UWriForm* InView);

	bool InputCommand(KeyS InKey) override;


	static enum Dock {
		DForm,
	};

	static enum Pro {
		PFormEdit,
	};

	static enum Focus {
		FDock,
		FRack,
		FScroll,
		FOCUS_MAX,
	};

	FocusUiRackC* ORack_;


};