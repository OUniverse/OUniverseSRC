//Copyright 2015-2019, All Rights Reserved.

#include "Ui/PulseI.h"
#include "System/Glass.h"

#include "cohtml/Binding/Binding.h"
#include "cohtml/Binding/EventHandler.h"
#include "CohtmlFStringBinder.h"

PulseIO::PulseIO(GlassC* InGlass) : Io(InGlass)
{
	bPulsing = false;
	bPendingEnd = false;
}

void PulseIO::Activate()
{
	GBIND("pulse_onEnd", this, &PulseIO::OnEnd);
}

PulseHandler* PulseIO::AddPulse()
{
	PulseHandler* NewPulse = new PulseHandler();
	Pulses.push_back(NewPulse);
	if (!bPulsing)
	{
		if (!bPendingEnd)
		{
			bPulsing = true;
			GSEND0("pulse_start");
		}
	}
	return NewPulse;
}

void PulseIO::EndPulse(PulseHandler* Pulse)
{
	Pulses.erase(Pulses.begin());

	if (Pulses.size() == 0)
	{
		GSEND0("pulse_end");
		bPendingEnd = true;
	}
}
void PulseIO::OnEnd()
{
	bPendingEnd = false;
	bPulsing = false;

	if (Pulses.size() > 0)
	{
		bPulsing = true;
		GSEND0("pulse_start");
	}
}
