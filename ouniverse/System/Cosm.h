//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Engine/LevelStreamingDynamic.h"
#include "Cosm.generated.h"

class Data;
class D_Area;

UCLASS()
class OUNIVERSE_API ACosm : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ACosm();

	D_Area* Gene;

	ULevelStreamingDynamic* LevelStreamed;

	void Infuse(Data* InData);

	void NewLevel();

	UFUNCTION()
	void MapLoaded();

};
