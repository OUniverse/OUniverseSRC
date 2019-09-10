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
#include "Interface/Url.h"

#include "System/LoadoutUID.h"
#include "System/UserUID.h"

class LoadoutC;
struct JsonS;


class OUNIVERSE_API LoadoutLibC
{

private:

	static const int Provenance;

public:

	LoadoutLibC();

	static LoadoutLibC* Create();

	void Load(FolderC InUserDir);

	void Unload();

	bool Try(LoadoutUID InUID, LoadoutC*& OutLoadout);

	void Add(JsonS* InJ);

private:

	MapC<LoadoutUID,LoadoutC*> Lib_;
	
	FileC File_;

	bool Valid_;
};