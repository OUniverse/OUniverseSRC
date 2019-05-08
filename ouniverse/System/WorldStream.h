//Copyright 2015-2019, All Rights Reserved.

/**
WorldManager manages the streaming in and out of areas based on the player's location using a grid.
 */

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "WorldStream.generated.h"


UCLASS()
class OUNIVERSE_API UWorldStream : public UObject
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UWorldStream();

	UPROPERTY()
	int x;
	UPROPERTY()
	int y;
	UPROPERTY()
	int GridSize;
	UPROPERTY()
	int SuperMap;
	UPROPERTY(BlueprintReadWrite)
	TArray<FString> LoadedGrids;

};
