//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Object.h"
#include "AtlasProfileLib.generated.h"

class UAtlasProfile;

UCLASS(BlueprintType)
class OUNIVERSE_API UAtlasProfileLib : public UObject
{
	GENERATED_BODY()

public:

	UPROPERTY()
	UAtlasProfile* SelectedProfile;

	UPROPERTY()
	TArray<UAtlasProfile*> ModManagerProfiles;
};