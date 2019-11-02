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
#include "Ui/Ui_Opt.h"
#include "UObject/NoExportTypes.h"
#include "Interface/Array.h"
#include "Ui_View.generated.h"


class UUi_Viewer;
class UUi_Master;

UCLASS(Blueprintable, BlueprintType)
class OUNIVERSE_API UUi_View : public UUserWidget
{

	GENERATED_BODY()

private:



public:

	UPROPERTY()
	UUi_Viewer* Viewer_;

	UFUNCTION(BlueprintPure)
	UUi_Viewer* Viewer();

	UFUNCTION(BlueprintCallable)
	void ViewerBind(UUi_View* InView, UUi_Opt* InOpt);

	UFUNCTION(BlueprintCallable)
	void ViewerSwitch(int InUID);

	UFUNCTION(BlueprintCallable)
	void SetupForDefaultCanvas();

	UFUNCTION(BlueprintImplementableEvent)
	void Ready();

	void SetMaster(UUi_Master* InMaster);

	UFUNCTION(BlueprintPure)
	UUi_Master* Master();

	UUi_Master* Master_;

	void CreateViewer();

	bool OpenView_Internal();

	UFUNCTION(BlueprintNativeEvent)
	void OpenView();

	bool CloseView_Internal(UUi_Viewer* InViewer);

	UFUNCTION(BlueprintNativeEvent)
	void CloseView(UUi_Viewer* InViewer, bool& bCancel);

};


struct OUNIVERSE_API ViewTabS
{

public:


	ViewTabS(int InUID, UUi_Opt* InOpt, UUi_View* InView);

	int UID_;
	UUi_Opt* Opt_;
	UUi_View* View_;

};



UCLASS()
class OUNIVERSE_API UUi_Viewer : public UObject
{

	GENERATED_BODY()

public:

	static UUi_Viewer* Create(UUi_View* InView);

	ViewTabS* Active_;
	ViewTabS* Pending_;

	UPROPERTY()
	UUi_View* View_;

	ArrayC<ViewTabS> Tabs_;

	UFUNCTION(BlueprintCallable)
	void Bind(int InUID, UUi_View* InView, UUi_Opt* InOpt);

	bool TryTabByID(int InUID, ViewTabS*& InTab);

	UFUNCTION(BlueprintCallable)
	void SwitchView(int InUID);

	void CloseComplete();

};