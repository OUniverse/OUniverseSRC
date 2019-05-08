//Copyright 2015-2019, All Rights Reserved.

#include "System/Listener.h"
#include "System/ListenerBeacon.h"

UListener::UListener()
{
	bConsume = false;
	bDeleteOnUse = false;
	bAsThread = false;
	Priority = -1;
}

void UListener::SetBeacon(UListenerBeacon* InBeacon)
{
	Beacon = InBeacon;
}

void UListener::Send()
{
		Destination.ExecuteIfBound();
}

void UListener::End()
{
	Beacon->RemoveListener(this);
}