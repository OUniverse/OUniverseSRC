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

#include "Ui/Ui_View.h"
#include "TIM_VMain.generated.h"

class UTIM_VMainTokenUser;
class UTIM_VMainTokenLoadout;

class UserDaisC;
class LoadoutDaisC;
class AtlasLibC;

class UTIM_VMainVHome;
class UTIM_VMainVLoad;
class UTIM_VMainVPre;

UCLASS(Blueprintable)
class OUNIVERSE_API UTIM_VMain : public UUi_View
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

	static UTIM_VMain* Create(UUi_View* InParentView, UserDaisC* InUserDais, LoadoutDaisC* InLoadoutDais, AtlasLibC* InAtlasLib);

	void Init(UUi_View* InParentView, UserDaisC* InUserDais, LoadoutDaisC* InLoadoutDais, AtlasLibC* InAtlasLib);

	UserDaisC* UserDais_;
	LoadoutDaisC* LoadoutDais_;
	
	UPROPERTY(meta = (BindWidget))
	UCanvasPanel* V_View;

	UPROPERTY(meta = (BindWidget))
	UTIM_VMainTokenUser* V_TokenUser;

	UPROPERTY(meta = (BindWidget))
	UTIM_VMainTokenLoadout* V_TokenLoadout;

	UPROPERTY()
	UTIM_VMainVHome* View_Home;

	UPROPERTY()
	UTIM_VMainVLoad* View_Load;

	UPROPERTY()
	UTIM_VMainVPre* View_Pre;

	static constexpr int const& VHome	= 0;
	static constexpr int const& VLoad	= 1;
	static constexpr int const& VPre	= 2;

};