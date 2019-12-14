//Copyright 2015-2019, All Rights Reserved.

/**
Protocol for handling the MainMenu.
 */

#pragma once

#include "Protocol/Protocol.h"
#include "System/Input.h"


class USymUserEdit;

class OUNIVERSE_API SymUserEditP : public ProtocolC, public InputC
{

public: 


	SymUserEditP(int InID);

	void ConstructUi(USymUserEdit* InView);

	USymUserEdit* View_;

	void FluxOpen_Technical(FluxSwitchOpC* InOp) override;
	void FluxClose_Technical(FluxSwitchOpC* InOp) override;

};