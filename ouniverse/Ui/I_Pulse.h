//Copyright 2015-2019, All Rights Reserved.

/**
IO (InterfaceObject)
Throbber when waiting for a thread to finish running or content to finish loading.
 */
#pragma once

#include "CoreMinimal.h"
#include "Ui/Io.h"
#include "I_Pulse.generated.h"


UCLASS()
class UPulseHandler : public UObject
{
	GENERATED_BODY()
};

UCLASS()
class OUNIVERSE_API UI_Pulse : public UIo
{
	GENERATED_BODY()

public:
	
	UI_Pulse();
	bool bPulsing;
	bool bPendingEnd;
	TSet<UPulseHandler*> Pulses;

	UPulseHandler* AddPulse();
	void EndPulse(UPulseHandler* Pulse);
	void OnEnd();
	
	void Activate() override;
};