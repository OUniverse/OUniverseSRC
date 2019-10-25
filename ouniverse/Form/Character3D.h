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
#include "Character3D.generated.h"

class UInputSchemaStack;
class UInputCharacter;

class USkeletalMeshComponent;
class USpringArmComponent;
class UCameraComponent;
class UDollyControl;
class UDolly;

UCLASS(Blueprintable)
class OUNIVERSE_API ACharacter3D : public ACharacter
{
	GENERATED_BODY()

public:

	static const char* Class;

	ACharacter3D();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USkeletalMeshComponent* Skeleton_;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USpringArmComponent* OrbitBoom_;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UCameraComponent* OrbitCam_;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UDollyControl* DollyControl_;
	
	UInputSchemaStack* Possess();

	UCameraComponent* GetControlCam();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UInputSchemaStack* Input_;


};