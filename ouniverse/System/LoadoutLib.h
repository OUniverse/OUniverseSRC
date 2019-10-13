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
#include "Interface/Url.h"

#include "System/LoadoutUID.h"

class LoadoutC;
class LoadoutW;

class OniManagerC;
struct JsonS;

class OUNIVERSE_API LoadoutLibC
{

private:

	static const int Provenance;

public:

	LoadoutLibC(LoadoutW* InLoadoutW, OniManagerC* InOni);

	void Load(FolderC InUserDir);

	void Unload();

	void Decide();

	bool Exists(int InUID);

	void Set(int InUID);

	bool Try(LoadoutUID InUID, LoadoutC*& OutLoadout);

	void Add(JsonS* InJ);

	LoadoutUID Last_;

	int Num();

	ArrayC<LoadoutC*> Loadouts();

private:

	OniManagerC* Oni_;
	ArrayC<LoadoutC*> Lib_;
	
	FileC File_;

	bool Valid_;

	LoadoutW* LoadoutW_;
	bool NoValids_;
	bool AutoLogin_;

	int GetSingleUID();
};