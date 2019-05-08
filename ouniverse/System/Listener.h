//Copyright 2015-2019, All Rights Reserved.

/**
Listeners are delegate wrappers for when many delegates's need to react to a single event.
They work in combination with a ListenerBeacon which holds the array and fires off the stack.
Listener's store a reference to their beacon so they can be easily unregistered.

Contains additional logic to do some special tasks:
- bDeleteOnUse: Gets broadcasted once then deletes itself from the ListenerBeacon (Not Implemented Yet.)
- bConsume: Does not allow the listener to broadcast to the remaining array of Listeners. (Not Implemented Yet.)
- bAsThread: Calls the listener in a new thread. (Not Implemented Yet.)
- Priority: Reorders the order they are broadcasted based on this value. (Not Implemented Yet.) 
 */


#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "System/Delegates.h"
#include "Listener.generated.h"


class UListenerBeacon;

UCLASS()
class OUNIVERSE_API UListener : public UObject
{
	GENERATED_BODY()

public:
	UListener();

	bool bConsume;
	bool bDeleteOnUse;
	bool bAsThread;
	int Priority;

	DelegateBool ConsumeCondition;
	DelegateSimple Destination;
	UListenerBeacon* Beacon;
	void SetBeacon(UListenerBeacon* InBeacon);
	virtual void Send();
	virtual void End();

};