//Copyright 2015-2019, All Rights Reserved.

/**

## UserLib

> **Singleton Service: Created once only by the boot process.**
>
A service singleton which manages all User data. (A User represents the person that is playing.)

#### Tasks:
* Can return user from an ID or a serial number (In case ID is changed)
* Manages the shifting of Users or assigning a new User.
* Scans the user directory and creates a UserFolder class object for each valid user found.

**Creator:** UBoot
**Holder:** Major

 */

#pragma once

#include "Interface/String.h"
#include "Interface/Array.h"


class OUNIVERSE_API LoadoutC
{

private:

	UInt8 UID_;
	int Glyph;


struct ComboS
{
	StringC Name_;
	int UID_;

	ComboS()
	{
		Name_ = "";
		UID_ = 0;
	}
};

	ArrayC<ComboS> Enabled_;

public:
	
	UInt8 GetUID();

	LoadoutC(StringC InStr);
};