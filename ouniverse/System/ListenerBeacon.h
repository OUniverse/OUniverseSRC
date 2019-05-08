//Copyright 2015-2019, All Rights Reserved.

/**
ListenerBeacons fire off special delegates wrapped in an object and are for when many delegates's need to react to a single event.
They work in combination with a Listener Class which fills the Listeners array.

Listeners have some special logic beyond regular delegates such as the ability to consume the broadcast etc. 
This special logic is handled in the ListenerBeacon.
 */

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ListenerBeacon.generated.h"

class UListener;

UCLASS()
class OUNIVERSE_API UListenerBeacon : public UObject
{
	GENERATED_BODY()

public:

	UListenerBeacon();
	int Count;

	UPROPERTY()
	TArray<UListener*> Listeners;
	void AddListener(UListener* NewListener);
	void RemoveListener(UListener* EndListener);
	void Broadcast();
};