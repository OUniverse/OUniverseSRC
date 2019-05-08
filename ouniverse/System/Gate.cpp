//Copyright 2015-2019, All Rights Reserved.

#include "Gate.h"


UGate::UGate()
{
	TickRate = 1.0f;
	TickPlaceboDelay = 0.0f;
	ID = "Unknown";
}

UGate::~UGate()
{
	FTicker::GetCoreTicker().RemoveTicker(TickHandle);
}

void UGate::Close()
{
	if (Condition.IsBound())
	{
		TickHandle = FTicker::GetCoreTicker().AddTicker(FTickerDelegate::CreateUObject(this, &UGate::Stall), TickRate);
	}
}

bool UGate::Stall(float DeltaTime)
{
 

	TickPlaceboDelay -= TickRate;

	if (Condition.Execute() && TickPlaceboDelay <= 0.0f)
	{
		FTicker::GetCoreTicker().RemoveTicker(TickHandle);
		CallBack.ExecuteIfBound();
		return false;
	}
	else
	{

	}
	return true;
}