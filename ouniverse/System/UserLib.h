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

class UserDeleteC;
class UserC;
struct DirS;

class OUNIVERSE_API UserLib
{

private:

	UserLib(DirS* InDirUsers);

public:

	static UserLib* Create(DirS* InDirUsers);

	

private:

	DirS* DirUsers;

	int NumUsers;

	bool DirLoaded_;

	UserDeleteC* User_;

	UserC* UserLast;

	ArrayC<UserC*> UserArray;

public:

	UserDeleteC* GetUser();
	
	void SetUser(int UID);

	void AddPreUser(UserC* NewUser);

	bool IsUserChosen();

	bool HasLastUser();

	bool HasSoloUser();
	
	void LoadUsers();

	int Num();

private:

	bool UserSet_;
};