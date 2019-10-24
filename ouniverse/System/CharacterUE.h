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

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CharacterUE.generated.h"

class USkeletalMeshComponent;
class USpringArmComponent;
class UCameraComponent;
class UDollyControl;
class UDolly;

UCLASS()
class OUNIVERSE_API ACharacterUE : public ACharacter
{
	GENERATED_BODY()

public:
	ACharacterUE();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USkeletalMeshComponent* Skeleton_;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USpringArmComponent* OrbitBoom_;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UCameraComponent* OrbitCam_;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UDollyControl* DollyControl_;
	
	void ControlPossess();

	UCameraComponent* GetControlCam();
};