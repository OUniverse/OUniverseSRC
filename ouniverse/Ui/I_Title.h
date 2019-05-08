//Copyright 2015-2019, All Rights Reserved.

/**
IO (InterfaceObject)
Main title screen.
 */

#pragma once

#include "CoreMinimal.h"
#include "Ui/Io.h"
#include "I_Title.generated.h"

UCLASS()
class OUNIVERSE_API UI_Title : public UIo
{
	GENERATED_BODY()

public:
	
	UI_Title();
	bool bOpen;
};