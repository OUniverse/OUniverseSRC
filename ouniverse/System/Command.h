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

#include "CoreMinimal.h"
#include "Delegates/IDelegateInstance.h"
#include "Interface/Event.h"


struct StrokeS
{
	bool KeyDown;

	StrokeS()
	{
		KeyDown = false;
	}
	
	StrokeS(bool InKeyDown)
	{
		KeyDown = InKeyDown;
	}
};

EVENT1(CommandE,CommandEL, void, StrokeS)

class OUNIVERSE_API CommandC
{

public:

	CommandC();

	int BoundKey();
	
	void SetBoundKey(int InBoundKey);
	
	void Trigger(StrokeS InStroke);
	
private:


	CommandE Event_;

	bool AllowDuringTypeMode_;
	
	int BoundKeyCode_;
};