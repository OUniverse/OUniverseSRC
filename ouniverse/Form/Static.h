//Copyright 2015-2019, All Rights Reserved.

/**
The base FORM for static 3D meshes.

Forms are objects meant to be combined with data to generate itself uniquely.
 */

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Static.generated.h"

class Data;
class D_Static;

UCLASS()
class OUNIVERSE_API AStatic : public AActor
{
	GENERATED_BODY()

public:

	D_Static* Gene;
	void Infuse(Data* InData);
};
