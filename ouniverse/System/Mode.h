//Copyright 2015-2019, All Rights Reserved.

/**

## Mode

Extends UE4's AGameMode and holds default game mode assignments.

#### Current Swaps:
* APlayerController to AControLUE
* AHud to AHudUE

*/

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Mode.generated.h"


UCLASS()
class OUNIVERSE_API AMode : public AGameModeBase
{
	GENERATED_BODY()
	
	AMode();

};
