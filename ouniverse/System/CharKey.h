//Copyright 2015-2019, All Rights Reserved.

/**
CharKey is a relay of a key press event to the UI so that certain commands can be reacted too in typing mode such as Backspace.
 */

#pragma once

#include "Interface/String.h"

class OUNIVERSE_API CharKey
{

public:

	CharKey(StringC InID);
	FString ID;
};