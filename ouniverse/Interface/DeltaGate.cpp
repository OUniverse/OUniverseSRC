//Copyright 2015-2019, All Rights Reserved.

#include "Interface/DeltaGate.h"

DeltaGateC::DeltaGateC()
{
	Limit_ = 0.0f;
	Current_ = 0.0f;
}

DeltaGateC::DeltaGateC(float InLimit)
{
	Limit_ = InLimit;
	Current_ = 0.0f;
}

bool DeltaGateC::Overflowed(float InDeltaTime)
{
	Current_ += InDeltaTime;

	if (Current_ > Limit_)
	{
		Current_ = 0.0f;
		return true;
	}

	return false;

}