//Copyright 2015-2019, All Rights Reserved.

/**
IO (InterfaceObject)
Handles the cinematic text display announcing new area and regions the player has entered.
 */

#pragma once

#include "CoreMinimal.h"
#include "Ui/Io.h"


class OUNIVERSE_API AreaIO : public Io
{
	
	friend UiManager;

private:

	AreaIO(GlassC* InGlass);

	bool bInProgress;

	void Show(FString Type,FString Args);
};