//Copyright 2015-2019, All Rights Reserved.

/**
IO (InterfaceObject)
Throbber when waiting for a thread to finish running or content to finish loading.
 */

#include "CoreMinimal.h"
#include "Ui/Io.h"
#include <vector>

class UiManager;
class UCohtmlHUD;


class PulseHandler
{
	
};


class OUNIVERSE_API PulseIO : public Io
{

	friend UiManager;

private:

	PulseIO(UCohtmlHUD* InUi);

	bool bPulsing;
	bool bPendingEnd;
	std::vector <PulseHandler*> Pulses;

	PulseHandler* AddPulse();
	void EndPulse(PulseHandler* Pulse);
	void OnEnd();
	
	void Activate() override;
};