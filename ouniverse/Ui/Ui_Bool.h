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

#include "Ui/UiEl.h"
#include "Ui_Bool.generated.h"


UCLASS(Blueprintable)
class OUNIVERSE_API UUi_Bool : public UUiEl
{

	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool Value;

	UFUNCTION(BlueprintCallable)
	bool GetValue();

	UFUNCTION(BlueprintCallable)
	void Toggle();

	UFUNCTION(BlueprintCallable)
	void Set(bool SetTo, bool bInternalOnly);

	UFUNCTION(BlueprintImplementableEvent)
	void Update();

	UFUNCTION(BlueprintImplementableEvent)
	void Changed();
};