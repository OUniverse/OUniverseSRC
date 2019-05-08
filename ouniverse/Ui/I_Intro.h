//Copyright 2015-2019, All Rights Reserved.

/**
IO (InterfaceObject)
Initial Trailers and movies.
 */

#pragma once

#include "CoreMinimal.h"
#include "Ui/Io.h"
#include "I_Intro.generated.h"

UCLASS()
class OUNIVERSE_API UI_Intro : public UIo
{
	GENERATED_BODY()

public:
	
	UI_Intro();
	bool bOpen;
};