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

class UCanvasPanel;
class UUi_View;

UCLASS()
class OUNIVERSE_API UUi_ViewElementData : public UObject
{
	GENERATED_BODY()

public:

	static UUi_ViewElementData* Create(int InUID, UUi_View* InView);

	int UID_;
	UUi_View* View_;
	UUbc* Opt_;
};




UCLASS()
class OUNIVERSE_API UViewPanelData : public UObject
{

	GENERATED_BODY()

public:

	static UViewPanelData* Create(int InUID);

	int UID_;

	void Add(int InViewUID, UUi_View* InView);

	UUi_ViewElementData* GetView(int InViewUID);

	void SetViewPanel(UCanvasPanel* InViewPanel);

	UCanvasPanel* Viewer_;

	UPROPERTY()
	TMap<int, UUi_ViewElementData*> Views_;


	UUi_ViewElementData* Active_;
	UUi_ViewElementData* Pending_;


	void SwitchView(int InViewID);



	UFUNCTION(BlueprintCallable)
		void CloseComplete();

	UFUNCTION(BlueprintCallable)
		void OpenComplete();

};







UCLASS(Blueprintable, BlueprintType)
class OUNIVERSE_API UUi_View : public UUbc
{

	GENERATED_BODY()


public:

	void StoreParentView(UUi_View* InView);

	UWorld* Scope();

	UFUNCTION(BlueprintPure)
	UUi_Alpha* Alpha();

	UUi_Alpha* Alpha_;
	UUi_View* OwningView_;


	bool OpenView_Internal(UViewPanelData* InViewer);

	UFUNCTION(BlueprintNativeEvent)
	void OpenView(UViewPanelData* InViewer);

	void CloseView_Internal(UViewPanelData* InViewer);

	UFUNCTION(BlueprintNativeEvent)
	void CloseView(UViewPanelData* InViewer);




	




	void AddViewPanel(int InPanelUID);

	void AddView(int InPanelUID, int InViewUID, UUi_View* InView);

	void SetViewPanel(int PanelUID, UCanvasPanel* InViewPanel);

	UViewPanelData* GetPanel(int InPanelUID);

	UPROPERTY()
	TMap<int, UViewPanelData*> Panels_;

	void SwitchView(int InPanelID, int InViewID);


};