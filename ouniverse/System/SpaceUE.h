//Copyright 2015-2019, All Rights Reserved.

/**

## Cosmos
> **Singleton Service: Created once only by the boot process.**

Cosmos is a singleton service that acts like a 3D space bucket. All 3D space objects are loaded into and by the Cosmos.

#### Tasks
* Handles loading and unloading levels smoothly.
* Loads world style levels
* Loads effect style levels such as 3D effects used by menus.

**Creator:** UBoot
**Holder:** Major

 */

#pragma once

#include "UObject/NoExportTypes.h"
#include "Interface/String.h"
#include "Engine/LevelStreamingDynamic.h"
#include "SpaceUE.generated.h"

class EtherC;

class ACharacterUE;

UCLASS()
class OUNIVERSE_API USpaceUE : public UObject
{
	GENERATED_BODY()

public:

	USpaceUE();

	
	void Init(EtherC* InEther, UObject* InWorldContext, UWorld* InScope);
	void StreamLevel(StringC InLevelID);
	
	UFUNCTION()
	void OnLevelStreamed();


	ACharacterUE* Spawn();

private:

	UObject* WorldContext_;
	EtherC* Ether_;
	UWorld* Scope_;
	ULevelStreamingDynamic* StreamedLevel_;
};