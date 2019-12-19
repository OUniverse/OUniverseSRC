//Copyright 2015-2019, All Rights Reserved.

/**
Protocol for handling the MainMenu.
 */

#pragma once

#include "Protocol/Protocol.h"
#include "System/Input.h"


class UMajor;

class OUNIVERSE_API GlobalPro : public ProtocolC, public InputC
{


	friend MaestroC;

public:


private:

	static GlobalPro* Create(int InID, UMajor* InMajor);

	GlobalPro(int InID, UMajor* InMajor);

	bool InputCommand(KeyS InKey) override;

	UMajor* Major_;
};