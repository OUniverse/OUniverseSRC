//Copyright 2015-2019, All Rights Reserved.

#include "System/UserLib.h"
#include "System/UserFolder.h"
#include "User/User.h"

#include "Interface/Dir.h"
#include "Interface/File.h"

#include "Interface/DirQuery.h"
#include "Min/LogM.h"
#include "Min/DebugM.h"



#define EXT_USER ".ouser"
#define USER_STANDARD_FILEPREFIX "_"


UserLib* UserLib::Create(DirS* InDirUsers)
{
	return new UserLib(InDirUsers);
}

UserLib::UserLib(DirS* InDirUsers)
{
	DirUsers = InDirUsers;
	NumUsers = 0;
	DirLoaded_ = false;
}

void UserLib::SetUser(int UID)
{

	int L = UserArray.Len();
	for (int i = 0; i < L; i++)
	{
		if (UserArray[i]->GetUID() == UID)
		{
			DBUG("ACTIVE USER FOUND");
			i += 150;
		}
	}
}


int UserLib::Num()
{
	return NumUsers;
}
void UserLib::LoadUsers()
{

	LOG(BOOT, 0, 0, StringC("Loading users from folder: ")+DirUsers->Get().ToChar())
	if (DirLoaded_ == false)
	{

		
		DirQueryS Fo = DirQueryS(DirUsers->Get());
		int Count = Fo.Num();

		for (int i = 0; i < Count; i++)
		{

			UserFolderC* NewUser = UserFolderC::Create(DirUsers, Fo[i]);

			if(NewUser->IsValid())
			{
				AddPreUser(NewUser);
			}

		}



		DirLoaded_ = true;
		LOG(BOOT, 1, 1, "Loading Users Complete");
		return;
	}

	LOG(BOOT, 1, 0, "WARNING User directory already scanned.");
}

bool UserLib::IsUserChosen()
{
	return false;
}

bool UserLib::HasSoloUser()
{
	return false;
}

bool UserLib::HasLastUser()
{
	return false;
}

UserC* UserLib::GetUser()
{
	return User_;
}

void UserLib::AddPreUser(UserFolderC* NewUser)
{
	NumUsers++;
	UserArray.Add(NewUser);
}