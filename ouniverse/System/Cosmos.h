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
#include "Cosmos.generated.h"


class AControlUE;
class ACameraUE;
class ACharacterUE;
class ActorA;

UCLASS()
class OUNIVERSE_API UCosmos : public UObject
{

	GENERATED_BODY()

public:

	void Init(AControlUE* InControl, UObject* InWorldContext, UWorld* InScope);

	void LoadLevel(StringC LevelName);

	void Mount();
	void Dismount();

	void SpawnParty(ArrayC<ActorA*> InPartyActors);

	ACharacterUE* SpawnCharacter(ActorA* InActor);
	ACameraUE* SpawnCamera();

	UFUNCTION()
	void OnLevelStreamed();

private:

	AControlUE* Control_;
	UObject* WorldContext_;
	UWorld* Scope_;
	ULevelStreamingDynamic* StreamedLevel_;
};