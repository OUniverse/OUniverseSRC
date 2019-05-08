//Copyright 2015-2019, All Rights Reserved.

#include "System/ListenerBeacon.h"
#include "System/Listener.h"


UListenerBeacon::UListenerBeacon()
{
	Count = 0;
}

void UListenerBeacon::AddListener(UListener* NewListener)
{
	Listeners.Add(NewListener);
	NewListener->SetBeacon(this);
	Count = Listeners.Num();
}

void UListenerBeacon::RemoveListener(UListener* EndListener)
{
	Listeners.Remove(EndListener);
	Count = Listeners.Num();
}

void UListenerBeacon::Broadcast()
{
	for (int i = 0; i < Count; i++)
	{
		Listeners[i]->Send();
		if (Listeners[i]->ConsumeCondition.IsBound())
		{
			if (Listeners[i]->ConsumeCondition.Execute())
			{
				return;
			}
		}
		
	}
}