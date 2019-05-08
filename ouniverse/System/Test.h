//Copyright 2015-2019, All Rights Reserved.

/**
Not to be included in the final test is just an easy way to test some code quickly.
Primarily used for experiments with setting up complex string parsing to make sure the output is correct.
 */

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Test.generated.h"


UCLASS()
class OUNIVERSE_API UTest : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	static void Test();
};

