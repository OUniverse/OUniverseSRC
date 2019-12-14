//Copyright 2015-2019, All Rights Reserved.

/**
Protocol for handling the MainMenu.
 */

#pragma once

#include "Protocol/Protocol.h"
#include "System/Input.h"

class USymUserCreate;

class OUNIVERSE_API SymUserCreateP : public ProtocolC, public InputC
{

public: 

	SymUserCreateP(int InID);

	void ConstructUi(USymUserCreate* InView);

	USymUserCreate* View_;

	void FluxOpen_Technical(FluxSwitchOpC* InOp) override;
	void FluxClose_Technical(FluxSwitchOpC* InOp) override;
};