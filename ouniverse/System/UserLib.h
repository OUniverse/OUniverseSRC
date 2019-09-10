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

class BootC;

class UserW;
class UserC;
struct DirS;
class KernelC;

class OUNIVERSE_API UserLibC
{

	friend BootC;

private:

	UserLibC(FolderC InFolder, UserW* UserW_);

	~UserLibC();

private:

	UserW* UserW_;

	FolderC Folder_;

	int Num_;

	bool DirLoaded_;

	UserC* UserLast_;

	ArrayC<UserC*> Lib_;
	
public:


	bool Try(int UID, UserC*& InUser);
	
	void SetUser(int UID);

	void AddUser(UserC* NewUser);

	bool IsUserChosen();

	bool HasLastUser();

	bool HasSoloUser();
	
	void LoadUsers();

	int Num();

	ArrayC<UserC*> Users();

};