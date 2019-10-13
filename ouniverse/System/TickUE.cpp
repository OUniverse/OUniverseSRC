//Copyright 2015-2019, All Rights Reserved.

#include "System/TickUE.h"
#include "System/Time.h"

UTickUE::UTickUE()
{

}

void UTickUE::BridgeAndBegin(TimeC* InTime)
{
	Time_ = InTime;
	TickHandle = FTicker::GetCoreTicker().AddTicker(FTickerDelegate::CreateUObject(this, &UTickUE::OnTick), 0.0f);
}

UTickUE::~UTickUE()
{
	FTicker::GetCoreTicker().RemoveTicker(TickHandle);
}

bool UTickUE::OnTick(float DeltaTime)
{
	Time_->OnFrame(DeltaTime);
	return true;
}