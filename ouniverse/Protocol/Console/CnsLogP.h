//Copyright 2015-2019, All Rights Reserved.

/**
Protocol for handling the MainMenu.
 */

#pragma once

#include "Protocol/Protocol.h"
#include "System/Input.h"


class CnsShelfP;

class UCnsLog;
class FocusUiRackC;


class OUNIVERSE_API CnsLogP : public ProtocolC, public InputC
{

public:

	CnsLogP(int InID, CnsShelfP* InPro);

	UCnsLog* View_;

	CnsShelfP* Pro_;

	void FluxOpen_Technical(FluxSwitchOpC* InOp) override;
	void FluxClose_Technical(FluxSwitchOpC* InOp) override;

	void ConstructUi(UCnsLog* InView);

	bool InputCommand(KeyS InKey) override;

};