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

class BootC;


class ConsoleU;
class HudU;
class ComU;

class OUNIVERSE_API UiC
{
	friend BootC;

private:

	static UiC* Create();

	ConsoleU*	Console_;
	HudU*		Hud_;
	ComU*		Com_;

public:

	static UiC* Get();
	UiC();

};