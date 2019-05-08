//Copyright 2015-2019, All Rights Reserved.

#include "Actra.h"

// Sets default values
AActra::AActra()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void AActra::Bloom()
{

}

// Called when the game starts or when spawned
void AActra::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AActra::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AActra::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

