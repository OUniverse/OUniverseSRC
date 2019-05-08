//Copyright 2015-2019, All Rights Reserved.

/**
IO (InterfaceObject)
Banner effect with text that gives player notifications.
Meant to show messages outside the lore of the game.
Ex: Battery power in a controller is low etc.
 */

#pragma once

#include "CoreMinimal.h"
#include "Ui/Io.h"
#include "I_Notice.generated.h"

UCLASS()
class OUNIVERSE_API UI_Notice : public UIo
{
	GENERATED_BODY()

public:
	
	UI_Notice();
};