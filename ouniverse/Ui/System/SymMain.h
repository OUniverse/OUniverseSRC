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

#include "Ui/UiView.h"
#include "SymMain.generated.h"

class UserLibC;
class LoadoutLibC;

class UUiButton;

class USYM_Home;
class USYM_Settings;
class USYM_News;

UCLASS(Abstract,Blueprintable)
class OUNIVERSE_API USYM_Main : public UUiView
{

	GENERATED_BODY()


public:

	void Init(UUiView* InParentView, UserLibC* InUserLib, LoadoutLibC* InLoadoutLib);


	UserLibC* UserLib_;
	LoadoutLibC* LoadoutLib_;



	UPROPERTY(meta = (BindWidget))
	UUiButton* BT_Glory;
	UPROPERTY(meta = (BindWidget))
	UUiButton* BT_Settings;
	UPROPERTY(meta = (BindWidget))
	UUiButton* BT_News;
	UPROPERTY(meta = (BindWidget))
	UUiButton* BT_Journey;
	UPROPERTY(meta = (BindWidget))
	UUiButton* BT_Continue;
	UPROPERTY(meta = (BindWidget))
	UUiButton* BT_Scribe;


	UPROPERTY(meta = (BindWidget))
	USYM_Home* View_Home;
	UPROPERTY(meta = (BindWidget))
	USYM_Settings* View_Settings;
	UPROPERTY(meta = (BindWidget))
	USYM_News* View_News;

	static enum Interfaces {
		BTHome,
		BTGlory,
		BTSettings,
		BTNews,
		BTJourney,
		BTContinue,
		BTUpdate,
		BTUpdates,
		BTCredits,
		BTScribe,
	};

	static enum Views {
		Home,
		Settings,
		News,
	};

	void EventUi(int WidgetID, int InEventID, UUserWidget* InWidget) override;

};