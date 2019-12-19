//Copyright 2015-2019, All Rights Reserved.

/**

## UiManager

> **Singleton Service: Created once only by the boot process.**

The UiManager is a service singleton which manages all user interface Interfaces (UI).

#### IO
IO is used here as an abbreviation for Interface Object and is any menu component
* A menu IO can be made up of many smaller IOs.

#### Tasks:
* Coordinates all of the UI's IO Interfaces.
* Allows the IO Interfaces to register with other systems (For example the console registering for the console CommandC).
* Activates each IO so that they bind themselves to the actual UI.
* Provides functions for other parts of the program to trigger UI events like popup notifications or data ribbons.

**Creator:** UBoot
**Holder:** Major

 */

#pragma once

#include "Ui/UiEl.h"
#include "Interface/Map.h"
#include "Interface/Array.h"
#include "UiView.generated.h"

class UUiView;


class OUNIVERSE_API ViewPanelS
{

public:

	ViewPanelS() {};
	ViewPanelS(int InUID);

	int UID_;

	void Add(int InViewUID, UUiView* InView);

	UUiView* GetView(int InViewUID);

	MapC<int, UUiView*> Views_;


	int Active_;
	int Pending_;

	void SwitchView(int InViewID);


	UFUNCTION(BlueprintCallable)
	void ViewCloseComplete();

	UFUNCTION(BlueprintCallable)
	void ViewOpenComplete();

};







UCLASS(Abstract, Blueprintable, BlueprintType)
class OUNIVERSE_API UUiView : public UUiEl
{

	GENERATED_BODY()


public:

	void ConstructView(UUiView* InView);


	UUiView* OwningView_;	
	ViewPanelS* OwningViewPanel_;


	bool ViewOpen_Mechanism();

	UFUNCTION(BlueprintNativeEvent)
	void ViewOpen();

	void ViewClose_Mechanism();

	UFUNCTION(BlueprintNativeEvent)
	void ViewClose();



	virtual void ViewOpen_Technical() {};
	void ViewOpen_AutoTechnical() {};

	virtual void ViewClose_Technical() {};
	void ViewClose_AutoTechnical() {};


	void AddViewPanel(int InPanelUID);

	void AddView(int InPanelUID, int InViewUID, UUiView* InView);

	ViewPanelS* GetPanel(int InPanelUID);


	MapC<int, ViewPanelS> Panels_;

	void SwitchView(int InPanelID, int InViewID);

	
	

	void InterfacesInit(int InMax);
	void InterfacesAdd(int Index, UUiEl* InInterface);
	void InterfacesActivate(int Index);

	UUiEl* ActiveInterface_;
	ArrayC<UUiEl*> Interfaces_;
};