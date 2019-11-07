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

#include "UObject/NoExportTypes.h"
#include "UI/Ui_View.h"
#include "Interface/Array.h"
#include "Ui_Viewer.generated.h"

class UUi_ViewPanel;
class UUi_View;
class UUi_Opt;

struct OUNIVERSE_API ViewTabS
{

public:


	ViewTabS(int InUID, UUi_Opt* InOpt, TSubclassOf<UUi_View> InViewClass, bool InPersists);

	int UID_;
	UUi_Opt* Opt_;
	TSubclassOf<UUi_View> ViewClass_;

	UUi_View* View_;
	bool Persists_;
};



UCLASS()
class OUNIVERSE_API UUi_Viewer : public UObject
{

	GENERATED_BODY()

public:

	static UUi_Viewer* Create(UUi_View* InView);

	void Init(UUi_View* InView);

	UUi_View* View_;

	UUi_ViewPanel* ViewPanel_;

	void SetViewPanel(UUi_ViewPanel* InViewSpace);

	ViewTabS* Active_;
	ViewTabS* Pending_;

	ArrayC<ViewTabS> Tabs_;

	void AddTab(int InUID, UUi_Opt* InOpt, TSubclassOf<UUi_View> InViewClass, bool InPersists);

	void SwitchView(int InUID, bool InOpenFirst);

	bool TryTabByID(int InUID, ViewTabS*& InTab);


	UFUNCTION(BlueprintCallable)
	void CloseComplete();

	UFUNCTION(BlueprintCallable)
	void OpenComplete();

};