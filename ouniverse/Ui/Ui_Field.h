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

#include "Blueprint/UserWidget.h"
#include "Ui_Field.generated.h"

class UUi_Basic;

UCLASS(Blueprintable)
class OUNIVERSE_API UUi_Field : public UUserWidget
{

	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	int BID_;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int FID_;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int HelpUID_;

	UFUNCTION(BlueprintPure, Category = "Ui")
	int GetFieldBID();

	UFUNCTION(BlueprintPure, Category = "Ui")
	int GetFieldFID();

	UFUNCTION(BlueprintPure, Category = "Ui")
	int GetFieldHelpUID();

	UFUNCTION(BlueprintCallable)
	virtual void Ready();

	UFUNCTION(BlueprintImplementableEvent)
	void OnReady();

};