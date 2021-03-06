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

#include "CoreMinimal.h"
#include "Interface/Array.h"
#include "Interface/String.h"
#include "Interface/Url.h"

#include "Interface/Json.h"

class BootC;

class UserDaisC;
class UserC;
class OniManagerC;


class OUNIVERSE_API UserLibC
{

	friend BootC;

private:

	UserLibC(FolderC InFolder, UserDaisC* InUserD, OniManagerC* InOni);

	~UserLibC();

private:

	UserDaisC* UserDais_;
	OniManagerC* Oni_;

	FolderC Folder_;

	ArrayC<UserC*> Lib_;
	
	bool Loaded_;

	bool HasValidUser_;
	bool AutoLogin_;
	int LastUserUID_;

public:

	UserC* GetUser(int index);

	bool IsNameValid(StringC inName);

	int GetNewUID();

	bool AutoLogin();

	bool HasValidUser();

	bool Exists(int InUID);

	bool Try(int InUID, UserC*& InUser);
	
	void Set(UserC* InUser);

	UserC* CreateNewUser(StringC InID);

	void Add(UserC* NewUser);
	
	void Load();

	int GetSingleUID();

	int Num();

	ArrayC<UserC*>* Users();

};