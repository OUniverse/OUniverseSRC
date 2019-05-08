//Copyright 2015-2019, All Rights Reserved.

#include "Ui/PulseI.h"
#include "CohtmlHUD.h"

#include "cohtml/Binding/Binding.h"
#include "cohtml/Binding/EventHandler.h"
#include "CohtmlFStringBinder.h"

PulseIO::PulseIO(UCohtmlHUD* InUi) : Io(InUi)
{
	bPulsing = false;
	bPendingEnd = false;
}

void PulseIO::Activate()
{
	Ui->GetView()->BindCall("pulse_onEnd", cohtml::MakeHandler(this, &PulseIO::OnEnd));
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
			Ui->GetView()->TriggerEvent("pulse_start");
		}
	}
	return NewPulse;
}

void PulseIO::EndPulse(PulseHandler* Pulse)
{
	Pulses.erase(Pulses.begin());

	if (Pulses.size() == 0)
	{
		Ui->GetView()->TriggerEvent("pulse_end");
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
		Ui->GetView()->TriggerEvent("pulse_start");
	}
}
