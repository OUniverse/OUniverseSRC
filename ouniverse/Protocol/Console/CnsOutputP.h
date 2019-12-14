//Copyright 2015-2019, All Rights Reserved.

/**
Protocol for handling the MainMenu.
 */

#pragma once

#include "Protocol/Protocol.h"
#include "System/Input.h"


class CnsShelfP;

class UCnsOutput;
class FocusUiRackC;


class OUNIVERSE_API CnsOutputP : public ProtocolC, public InputC
{

public:

	CnsOutputP(int InID, CnsShelfP* InPro);

	UCnsOutput* View_;

	CnsShelfP* Pro_;

	void FluxOpen_Technical(FluxSwitchOpC* InOp) override;
	void FluxClose_Technical(FluxSwitchOpC* InOp) override;

	void ConstructUi(UCnsOutput* InView);

	bool InputCommand(KeyS InKey) override;

};