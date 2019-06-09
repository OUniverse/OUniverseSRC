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
#include "Interface/Map.h"


class LoadoutC;
struct JsonS;


class OUNIVERSE_API LoadoutLibC
{

public:

	static const char* FILE_NAME;

	LoadoutLibC(StringC InPath);

	static LoadoutLibC* Create(StringC InUserPath);

	bool Try(int InUID, LoadoutC*& OutLoadout);

	int Len();

	void Add(JsonS* InJ);

private:

	MapC<int,LoadoutC*> Lib_;
	
	StringC Path_;

	int Len_;

	int Inc_;

	bool Loaded;

	bool Valid_;
};