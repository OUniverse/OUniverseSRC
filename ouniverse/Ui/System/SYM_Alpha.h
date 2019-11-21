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

#include "Ui/Ui_Alpha.h"
#include "SYM_Alpha.generated.h"



class UCanvasPanel;

class USYM_VMain;
class USYM_VUser;

class UserLibC;
class UserDaisC;
class LoadoutLibC;
class LoadoutDaisC;

UCLASS(Blueprintable)
class OUNIVERSE_API USYM_Alpha : public UUi_Alpha
{

	GENERATED_BODY()

public:


	virtual void NativeConstruct() override;

	static USYM_Alpha* Create(UWorld* InScope, UUi* InUi, UserLibC* InUserLib, UserDaisC* InUserDais, LoadoutLibC* InLoadoutLib, LoadoutDaisC* InLoadoutDais);
	void Init(UWorld* InScope, UUi* InUi, UserLibC* InUserLib, UserDaisC* InUserDais, LoadoutLibC* InLoadoutLib, LoadoutDaisC* InLoadoutDais);

	UPROPERTY(meta = (BindWidget))
	UCanvasPanel* V_View;

	UserLibC* UserLib_;
	UserDaisC* UserDais_;
	LoadoutLibC* LoadoutLib_;
	LoadoutDaisC* LoadoutDais_;

	UPROPERTY()
	USYM_VMain* View_Menu;

	UPROPERTY()
	USYM_VUser* View_User;

	void ToTitleMenu();
};