//Copyright 2015-2019, All Rights Reserved.

/**
Protocol for handling the MainMenu.
 */

#pragma once

#include "Protocol/Protocol.h"
#include "GlobalPro.generated.h"

UCLASS()
class OUNIVERSE_API UGlobalPro : public UProtocol
{
	GENERATED_BODY()

	friend UMaestro;

public:

	static UGlobalPro* Create();


private:

	UGlobalPro();

	virtual bool Up(bool Down);
};