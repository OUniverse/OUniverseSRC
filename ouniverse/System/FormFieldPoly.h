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
#include "CoreMinimal.h"
#include "Interface/Array.h"
#include "Interface/String.h"

class UTexture2D;
class UFFbc;

struct OUNIVERSE_API FormFieldPolyS
{

public:

	
	UTexture2D* PolyGFX_;
	FText PolyName_;
	ArrayC<UFFbc*> Fields_;

	void AddInt(int FFID, int* P);
	void AddString(int FFID, StringC* P);
};