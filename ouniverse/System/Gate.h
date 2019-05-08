//Copyright 2015-2019, All Rights Reserved.

/**
The Gate Class serves to pause a thread until a bool condition is met.
- Initialized with a bool reference and a delegate.
- Checks per tick if the bool is true and when it is fires the delegate.
- Helpful with syncing the completion of multiple threads.

*** Currently not used by anything.
 */

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Containers/Ticker.h"
#include "System/Delegates.h"
#include "Gate.generated.h"

/**
 * 
 */
UCLASS()
class OUNIVERSE_API UGate : public UObject
{
	GENERATED_BODY()

public:

	float TickRate;
	float TickPlaceboDelay;
	FString ID;
	FDelegateHandle TickHandle;
	DelegateBool Condition;
	DelegateSimple CallBack;

	UGate();
	~UGate();
	UFUNCTION()
	virtual void Close();
	UFUNCTION()
	virtual bool Stall(float DeltaTime);

};
