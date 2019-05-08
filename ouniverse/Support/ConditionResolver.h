//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ConditionResolver.generated.h"

class UMajor;

UCLASS()
class OUNIVERSE_API UConditionResolver : public UObject
{
	GENERATED_BODY()

public:
	UMajor* Major;
	FORCEINLINE void Init(UMajor* InMajor);
};
