//Copyright 2015-2019, All Rights Reserved.

/**
UserManager is a Singleton extension to MAJOR (GameInstance) and manages all User data.
A User represents the person that is playing.

The UserManager class has the following abilities:
-Can return user from an ID or a serial number (In case ID is changed)
-Manages the shifting of Users or assigning a new User.
-Scans the user directory and creats a User class object for each valid user found.
 */

#pragma once

#include "CoreMinimal.h"
#include "Interface/Array.h"
#include "Interface/String.h"

class UserC;
class UserFolderC;
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

	UserC* User_;

	UserFolderC* UserLast;

	ArrayC<UserFolderC*> UserArray;

public:

	UserC* GetUser();
	
	void SetUser(int UID);

	void AddPreUser(UserFolderC* NewUser);

	bool IsUserChosen();

	bool HasLastUser();

	bool HasSoloUser();
	
	void LoadUsers();

	int Num();

private:


};