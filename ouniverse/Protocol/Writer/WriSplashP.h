//Copyright 2015-2019, All Rights Reserved.

/**
Protocol for handling the MainMenu.
 */

#pragma once

#include "Protocol/Protocol.h"
#include "Protocol/Flux.h"
#include "System/Input.h"


class WriterPro;

class UWriSplash;
class FocusUiRackC;


class OUNIVERSE_API WriSplashP : public ProtocolC, public InputC
{

public: 

	WriSplashP(int InID, WriterPro* InPro);

	UWriSplash* View_;

	WriterPro* Pro_;

	void FluxOpen_Technical(FluxSwitchOpC* InOp) override;
	void FluxClose_Technical(FluxSwitchOpC* InOp) override;

	void ConstructUi(UWriSplash* InView);

	bool InputCommand(KeyS InKey) override;

	void AcceptStart();
	void AcceptBack();


	static enum Focus {
		FRack,
		FStart,
		FBack,
		FOCUS_MAX,
	};

	FocusUiRackC* ORack_;

};