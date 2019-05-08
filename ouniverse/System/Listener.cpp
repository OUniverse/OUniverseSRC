//Copyright 2015-2019, All Rights Reserved.

#include "System/Listener.h"


ListenerC::ListenerC()
{
	bConsume = false;
	bDeleteOnUse = false;
	bAsThread = false;
	Priority = -1;
}

void ListenerC::SetBeacon(ListenerBeacon* InBeacon)
{
	Beacon = InBeacon;
}

void ListenerC::Send()
{
		Destination.ExecuteIfBound();
}

void ListenerC::End()
{
	Beacon->RemoveListener(this);
}





ListenerBeacon::ListenerBeacon()
{
	Count = 0;
}

void ListenerBeacon::AddListener(ListenerC* NewListener)
{
	Listeners.push_back(NewListener);
	NewListener->SetBeacon(this);
	Count = Listeners.size();
}

void ListenerBeacon::RemoveListener(ListenerC* EndListener)
{

	std::vector<ListenerC*>::iterator ToErase;

	ToErase = std::find(Listeners.begin(), Listeners.end(), EndListener);

	if (ToErase != Listeners.end())
	{
		delete* ToErase;
		Listeners.erase(ToErase);
	}

	Count = Listeners.size();
}

void ListenerBeacon::Broadcast()
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