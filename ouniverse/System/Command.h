//Copyright 2015-2019, All Rights Reserved.

/**

## Commands
Every action triggered by input in OUniverse has a Command associated with. (For example "Jump" "Accept" "Interact" are all Commands.).
Commands forward receipt of the input action via Event Delegates which can be registered for.
These Event Delegates broadcast all clicks and presses to all registered methods.

#### Tasks
* Allows other areas of the program to easily register for Command Events.
* Commands are stored on a Map keyed by KeyScanCodes so they can be easily remapped.

**Creator:** InputManager
**Holder:** InputManager
**Related:** CharKeyC

 */

#pragma once

#include "Interface/Event.h"
#include "System/KeyCode.h"

struct StrokeS
{
	bool KeyDown_;

	StrokeS()
	{
		KeyDown_ = false;
	}
	
	StrokeS(bool InKeyDown)
	{
		KeyDown_ = InKeyDown;
	}

	bool KeyDown()
	{
		return KeyDown_;
	}
};

EVENT1(CommandE,CommandEL, void, StrokeS)

class OUNIVERSE_API CommandC
{

public:

	CommandC(KeyCodeC InKeyCode);

	KeyCodeC KeyCode();
	
	void SetKeyCode(KeyCodeC InKeyCode);
	
	void Trigger(StrokeS InStroke);

	CommandE Listen();

private:

	CommandE Event_;
	
	KeyCodeC KeyCode_;
};