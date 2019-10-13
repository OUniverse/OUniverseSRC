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

#include "Interface/Event.h"

EVENT1(FrameGlobalE, FrameGlobalL, EventLife, float)
EVENT1(FramePausableE, FramePausableL, EventLife, float)

EVENT1(Ms100_GlobalE, Ms100_GlobalL, EventLife, float)
EVENT1(Ms100_PausableE, Ms100_PausableL, EventLife, float)

EVENT1(Ms1000_GlobalE, Ms1000_GlobalL, EventLife, float)
EVENT1(Ms1000_PausableE, Ms1000_PausableL, EventLife, float)

class BootC;

class OUNIVERSE_API TimeC
{
	friend BootC;

private:

	static TimeC* Create();

	bool Pause_;

public:

	static TimeC* Get();
	TimeC();

	void OnFrame(float DeltaTime);
	void OnMs100(float DeltaTime);
	void OnMs1000(float DeltaTime);

	void Pause(bool DoPause);
	
	FrameGlobalE Frame_Global_;
	FrameGlobalE Frame_Global();

	FramePausableE Frame_Pausable_;	
	FramePausableE Frame_Pausable();

	Ms100_GlobalE Ms100_Global_;
	Ms100_GlobalE Ms100_Global();

	Ms100_PausableE Ms100_Pausable_;
	Ms100_PausableE Ms100_Pausable();

	Ms1000_GlobalE Ms1000_Global_;
	Ms1000_GlobalE Ms1000_Global();

	Ms1000_PausableE Ms1000_Pausable_;
	Ms1000_PausableE Ms1000_Pausable();
};