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
#include "System/AtlasUID.h"

struct JsonS;

class OUNIVERSE_API LoadoutAtlasC
{

public:

	LoadoutAtlasC() {};
	LoadoutAtlasC(JsonS* InJ);
	LoadoutAtlasC(AtlasUID InUID, StringC InName);
	
	AtlasUID UID();

	StringC Name();

	bool Valid();

private:

	AtlasUID UID_;
	
	StringC Name_;

	bool Valid_;
};