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

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

public:

	ACharacter3D();

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USkeletalMeshComponent* Skeleton_;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USpringArmComponent* OrbitBoom_;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UCameraComponent* OrbitCam_;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UDollyControl* DollyControl_;
	
	UCameraComponent* GetControlCam();

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseLookUpRate;
	

	float CamZoomGoal;

public:

	void MoveX(float Value);
	void MoveY(float Value);
	void TurnY(float Value);
	void LookX(float Value);
	void Zoom(float AxisValue);
};