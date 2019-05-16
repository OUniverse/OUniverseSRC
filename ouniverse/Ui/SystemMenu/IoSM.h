//Copyright 2015-2019, All Rights Reserved.

/**
Sub type of Io used by all of the SystemMenu's submenus.
 */

#pragma once

#include "Ui/Io.h"

class SystemMenuIO;


class OUNIVERSE_API IoSM : public Io
{

	friend SystemMenuIO;

protected:
	
	IoSM(GlassC* InGlass, SystemMenuIO* InSyMenu);

	SystemMenuIO* SystemMenuP;

	virtual void King() {};

};