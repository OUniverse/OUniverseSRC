//Copyright 2015-2019, All Rights Reserved.

/**
Conditions are predefined bool checks so that game data can include conditional switches.

Conditions are handled by a ConditionResolver and return true or false.
This is the abstract condition class that all conditions extend from.

*Going to investigate changing the condtion to an F or Struct kind of setup that can 
autoresolve itself without the need of a resolver. 
 */

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Condition.generated.h"


class UMajor;

UCLASS()
class OUNIVERSE_API UCondition : public UObject
{
	GENERATED_BODY()

public:
	UMajor* Major;
	FORCEINLINE void Init(UMajor* InMajor);
};
