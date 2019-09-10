//Copyright 2015-2019, All Rights Reserved.

/**
IO (InterfaceObject)
Toaster notification, meant to convey game context related messages.
 */

#pragma once

#include "Interface/Event.h"

class OUNIVERSE_API Ui
{

public:

	Ui();

	void Activate();

	const char* Path();

	EventLife ViewReady();
};