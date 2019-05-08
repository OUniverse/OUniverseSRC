//Copyright 2015-2019, All Rights Reserved.

/**
IO (InterfaceObject)
Handles the cinematic text display announcing new area and regions the player has entered.
 */

#pragma once

#include "CoreMinimal.h"
#include "Ui/Io.h"
#include "I_Area.generated.h"

UCLASS()
class OUNIVERSE_API UI_Area: public UIo
{
	GENERATED_BODY()

public:
	
	UI_Area();
	bool bInProgress;

	void Show(FString Type,FString Args);
};