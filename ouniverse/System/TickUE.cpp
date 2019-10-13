//Copyright 2015-2019, All Rights Reserved.

#include "System/TickUE.h"
#include "System/Time.h"

UTickUE::UTickUE()
{

}

void UTickUE::BridgeAndBegin(TimeC* InTime)
{
	Time_ = InTime;
	Frame_H = FTicker::GetCoreTicker().AddTicker(FTickerDelegate::CreateUObject(this, &UTickUE::OnFrame), 0.0f);
	Ms100_H = FTicker::GetCoreTicker().AddTicker(FTickerDelegate::CreateUObject(this, &UTickUE::OnMs100), 0.1f);
	Ms1000_H = FTicker::GetCoreTicker().AddTicker(FTickerDelegate::CreateUObject(this, &UTickUE::OnMs1000), 1.0f);
}

UTickUE::~UTickUE()
{
	FTicker::GetCoreTicker().RemoveTicker(Frame_H);
	FTicker::GetCoreTicker().RemoveTicker(Ms100_H);
	FTicker::GetCoreTicker().RemoveTicker(Ms1000_H);
}

bool UTickUE::OnFrame(float DeltaTime)
{
	Time_->OnFrame(DeltaTime);
	return true;
}

bool UTickUE::OnMs100(float DeltaTime)
{
	Time_->OnMs100(DeltaTime);
	return true;
}

bool UTickUE::OnMs1000(float DeltaTime)
{
	Time_->OnMs1000(DeltaTime);
	return true;
}