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

#include "Ui/Ui_Master.h"
#include "Writer_Master.generated.h"

class UAtlas;
class AtlasLibC;

UCLASS(Blueprintable)
class OUNIVERSE_API UWriter_Master : public UUi_Master
{

	GENERATED_BODY()

public:

	static UWriter_Master* Create(UWorld* InScope, AtlasLibC* InAtlasLib);
	void Init(AtlasLibC* InAtlasLib);

	UFUNCTION(BlueprintPure, meta=(DisplayName="GetAtlasiPre"))
	TArray<UAtlas*>	GetAtlasiPre();

	UPROPERTY()
	TArray<UAtlas*>	PreAtlasi_;

	AtlasLibC* AtlasLib_;
};