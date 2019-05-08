//Copyright 2015-2019, All Rights Reserved.

#include "Ui/I_Pulse.h"

#include "CohtmlHUD.h"
#include "cohtml/Binding/Binding.h"
#include "cohtml/Binding/EventHandler.h"
#include "CohtmlFStringBinder.h"

UI_Pulse::UI_Pulse()
{
	bPulsing = false;
	bPendingEnd = false;
}

void UI_Pulse::Activate()
{
	Ui->GetView()->BindCall("pulse_onEnd", cohtml::MakeHandler(this, &UI_Pulse::OnEnd));
}

UPulseHandler* UI_Pulse::AddPulse()
{
	UPulseHandler* NewPulse = NewObject<UPulseHandler>();
	Pulses.Add(NewPulse);
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

void UI_Pulse::EndPulse(UPulseHandler* Pulse)
{
	Pulses.Remove(Pulse);
	int count = Pulses.Num();
	if (count == 0)
	{
		Ui->GetView()->TriggerEvent("pulse_end");
		bPendingEnd = true;
	}
}
void UI_Pulse::OnEnd()
{
	bPendingEnd = false;
	bPulsing = false;
	int count = Pulses.Num();
	if (count > 0)
	{
		bPulsing = true;
		Ui->GetView()->TriggerEvent("pulse_start");
	}
}
