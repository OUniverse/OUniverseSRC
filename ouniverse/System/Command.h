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
#include "Command.generated.h"


USTRUCT(Blueprintable)
struct FStroke
{
	GENERATED_BODY()

	UPROPERTY()
	
	bool KeyDown;

	FStroke()
	{
		KeyDown = false;
	}
	
	FStroke(bool InKeyDown)
	{
		KeyDown = InKeyDown;
	}
};

DECLARE_DELEGATE_OneParam(DelegateCommand, FStroke);

UCLASS()
class OUNIVERSE_API UCommand : public UObject
{

	GENERATED_BODY()

public:

	UCommand();
	DelegateCommand Call;
	FName ID;
	int32 BoundKeyCode;
	bool bAllowDuringTypeMode;
	void Send(FStroke Stroke);
	//Beacon
};