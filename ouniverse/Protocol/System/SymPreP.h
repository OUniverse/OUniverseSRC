//Copyright 2015-2019, All Rights Reserved.

/**
Protocol for handling the MainMenu.
 */

#pragma once

#include "Protocol/Protocol.h"
#include "System/Input.h"

class USymPre;
class SystemPro;

class OUNIVERSE_API SymPreP : public ProtocolC, public InputC
{

public:

	SymPreP(int InID, SystemPro* InPro);

	USymPre* View_;
	SystemPro* Pro_;

	void FluxOpen_Technical(FluxSwitchOpC* InOp) override;
	void FluxClose_Technical(FluxSwitchOpC* InOp) override;

	void ConstructUi(USymPre* InView);

};