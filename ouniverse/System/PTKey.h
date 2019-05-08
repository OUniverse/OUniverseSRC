//Copyright 2015-2019, All Rights Reserved.

/**
Commands represent functions that can be bound to a keypress.
For example "Jump" "Accept" "Interact" could all be commands.

A Command has an ID and a delegate which can broadcast.
If something wants to register for a keypress they add their trigger function to the delegate.
 */

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "System/Delegates.h"
#include "PTKey.generated.h"


USTRUCT(Blueprintable)
struct FPTStroke
{
	GENERATED_BODY()

	UPROPERTY()
	
	bool KeyDown;

	FPTStroke()
	{
		KeyDown = false;
	}
	
	FPTStroke(bool InKeyDown)
	{
		KeyDown = InKeyDown;
	}
};

UCLASS()
class OUNIVERSE_API UPTKey : public UObject
{

	GENERATED_BODY()

public:

	UPTKey();
	FString ID;
};