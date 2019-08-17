//Copyright 2015-2019, All Rights Reserved.

/**

## CharKey
CharKey are command relays of certain presses while in typing mode using CHAR style input.
* Instead of sending the Char as a code it sends commands for special keys such as Backspace, Escape, Delete etc.

**Creator:** InputManager
**Holder:** InputManager
**Related:** CommandC

*/

#pragma once

#include "Interface/String.h"

class AControlUE;

class OUNIVERSE_API CharKey
{

public:

	enum Handler
	{
		Auto,
		Switch,
	};

	enum Modifier
	{
		None,
		CTR,
		ALT,
		CTRALT,
	};

	bool IsValid(bool InCtr, bool InAlt);

	CharKey(int InKeyCode, Handler InHandler, Modifier InModifier, StringC InID);
	int KeyCode_;
	StringC ID_;
	Modifier Modifier_;
	Handler Handler_;
};