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
#include "WRI_Alpha.generated.h"

class UHorizontalBox;
class UAtlas;
class AtlasLibC;
class UWRI_AlphaOpt;
class UUi_ViewPanel;

class UWRI_VSetup;
class UWRI_VForm;

UCLASS(Blueprintable)
class OUNIVERSE_API UWRI_Alpha : public UUi_Alpha
{

	GENERATED_BODY()

public:


	static UWRI_Alpha* Create(UWorld* InScope, AtlasLibC* InAtlasLib);
	void Init(AtlasLibC* InAtlasLib);

	UPROPERTY(meta = (BindWidget))
	UHorizontalBox* V_Opts;

	UPROPERTY(meta = (BindWidget))
	UUi_ViewPanel* V_ViewPanel;

	AtlasLibC* AtlasLib_;

	void ImbueVSetup(UWRI_VSetup* InVSetup);

	void ImbueVForm(UWRI_VForm* InVSetup);

	static enum Views {
		Setup,
		Atlas,
		Form,
		Views_MAX,
	};

};