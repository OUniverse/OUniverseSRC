//Copyright 2015-2019, All Rights Reserved.

/**

## UiManager

> **Singleton Service: Created once only by the boot process.**

The UiManager is a service singleton which manages all user interface elements (UI).

#### IO
IO is used here as an abbreviation for Interface Object and is any menu component
* A menu IO can be made up of many smaller IOs.

#### Tasks:
* Coordinates all of the UI's IO elements.
* Allows the IO elements to register with other systems (For example the console registering for the console CommandC).
* Activates each IO so that they bind themselves to the actual UI.
* Provides functions for other parts of the program to trigger UI events like popup notifications or data ribbons.

**Creator:** UBoot
**Holder:** Major

 */

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Containers/Ticker.h"
#include "TickUE.generated.h"

class TimeC;

UCLASS()
class OUNIVERSE_API UTickUE : public UObject
{
	GENERATED_BODY()

public:

	FDelegateHandle Frame_H;
	FDelegateHandle Ms100_H;
	FDelegateHandle Ms1000_H;

	UFUNCTION()
	virtual bool OnFrame(float DeltaTime);

	UFUNCTION()
	virtual bool OnMs100(float DeltaTime);

	UFUNCTION()
	virtual bool OnMs1000(float DeltaTime);

	void BridgeAndBegin(TimeC* InTime);

	TimeC* Time_;
	UTickUE();
	~UTickUE();

};