//Copyright 2015-2019, All Rights Reserved.

/**
The base FORM for Actors/Characters.

Forms are objects meant to be combined with data to generate itself uniquely.
 */


#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Actra.generated.h"


UCLASS()
class OUNIVERSE_API AActra : public ACharacter
{
	GENERATED_BODY()


public:
	// Sets default values for this character's properties

	AActra();
	void Bloom();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
