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

#include "Ui/Ubc.h"
#include "Ui/Ui_Opt.h"
#include "Ui_View.generated.h"

class UUi_Alpha;
class UUi_Viewer;

UCLASS(Blueprintable, BlueprintType)
class OUNIVERSE_API UUi_View : public UUbc
{

	GENERATED_BODY()


public:

	void CreateViewer();

	UUi_Viewer* Viewer_;

	void SwitchView(int InUID, bool InOpenFirst);

	void InitFromViewer_Internal(UUi_View* InOwningView);

	virtual void InitFromViewer();

	void SetView(UUi_View* InView);

	UWorld* Scope();

	UFUNCTION(BlueprintPure)
	UUi_Alpha* Alpha();

	UUi_Alpha* Alpha_;
	UUi_View* OwningView_;


	bool OpenView_Internal(UUi_Viewer* InViewer);

	UFUNCTION(BlueprintNativeEvent)
	void OpenView(UUi_Viewer* InViewer);

	void CloseView_Internal(UUi_Viewer* InViewer);

	UFUNCTION(BlueprintNativeEvent)
	void CloseView(UUi_Viewer* InViewer);

};