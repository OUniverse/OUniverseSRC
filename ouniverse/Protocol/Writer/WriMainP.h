//Copyright 2015-2019, All Rights Reserved.

/**
Protocol for handling the MainMenu.
 */

#pragma once

#include "Protocol/Protocol.h"
#include "System/Input.h"


class WriterPro;

class UMajor;

class AtlasLibC;

class UWriMenu;
class FocusUiRackC;
class FocusDockC;

class WriDataC;

class WriLoadoutP;
class WriAtlasP;
class WriDataP;

class OUNIVERSE_API WriMenuP : public ProtocolC, public InputC
{

public: 

	WriMenuP(int InID, WriterPro* InPro, WriDataC* WriData_, AtlasLibC* InAtlasLib);

	UWriMenu* View_;

	WriterPro* Pro_;

	WriDataC* WriData_;

	WriLoadoutP* WriLoadout_;
	WriAtlasP* WriAtlas_;
	WriDataP* WriForm_;

	AtlasLibC* AtlasLib_;

	void FluxOpen_Technical(FluxSwitchOpC* InOp) override;
	void FluxClose_Technical(FluxSwitchOpC* InOp) override;

	void ConstructUi(UWriMenu* InView);

	bool InputCommand(KeyS InKey) override;

	static enum Focus {
		FRack,
		FDock,
		FLoadout,
		FAtlas,
		FData,
		FWorld,
		FTools,
		FExit,
		FOCUS_MAX,
	};

	static enum Dock {
		DMain,
	};

	static enum Pro {
		PLoadout,
		PAtlas,
		PForm,
	};

	FocusUiRackC* ORack_;
	FocusDockC* ODock_;

	void AcceptLoadout();
	void AcceptAtlas();
	void AcceptForm();
};