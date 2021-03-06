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
#include "Interface/Json.h"
#include "Interface/Url.h"

#include "System/LoadoutUID.h"

class LoadoutC;
class LoadoutDaisC;

class OniManagerC;
struct JsonS;

class OUNIVERSE_API LoadoutLibC
{

private:

	static const int Provenance;

public:


	LoadoutLibC(LoadoutDaisC* InLoadoutDais, OniManagerC* InOni);

	void Load(FolderC InUserDir);

	void Unload();

	LoadoutC* GetLoadout(int index);

	bool Exists(int InUID);

	void Set(LoadoutC* InLoadout);

	bool Try(LoadoutUID InUID, LoadoutC*& OutLoadout);

	void Add(LoadoutC* InLoadout);

	LoadoutUID Last_;

	int Num();

	ArrayC<LoadoutC*> Loadouts();

private:

	ArrayC<LoadoutC*> Lib_;
	
	FileC File_;

	bool Valid_;

	OniManagerC* Oni_;

	LoadoutDaisC* LoadoutDais_;
	
	bool NoValids_;
	bool AutoLogin_;

	int GetSingleUID();
};