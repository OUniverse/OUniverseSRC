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

struct JsonS;

class OUNIVERSE_API LoadoutC
{

public:

	static const char* K_UID;
	static const char* K_NAME;
	static const char* K_ATLAS;

private:

	U8 UID_;
	int Glyph;


	struct ComboS
	{
		StringC Name_;
		U64 UID_;

		ComboS() {};
		ComboS(JsonS* InJ);

		bool Valid_;
	};


public:
	

	U8 GetUID();

	ArrayC<ComboS> Atlases_;

	LoadoutC(int InUID, JsonS* InJ);
};