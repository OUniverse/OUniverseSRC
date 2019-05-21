//Copyright 2015-2019, All Rights Reserved.

#include "System/UserLib.h"
#include "System/User.h"

#include "Interface/Dir.h"
#include "Interface/File.h"

#include "Interface/DirQuery.h"

#include "Min/LogM.h"

#include "Min/DebugM.h"

#include "System/Kernel.h"



#define EXT_USER ".ouser"
#define USER_STANDARD_FILEPREFIX "_"


UserLib* UserLib::Create(DirS* InDirUsers, KernelC* InSession)
{
	return new UserLib(InDirUsers, InSession);
}

UserLib::UserLib(DirS* InDirUsers, KernelC* InSession)
{
	UserSet_ = false;
	Session_ = InSession;

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

			if (UserSet_)
			{
				User_->Demote();
			}
			UserSet_ = true;
			User_ = UserArray[i];
			
			Session_->SetUser(UserArray[i]);
			break;
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

			UserC* NewUser = UserC::Create(DirUsers, Fo[i]);

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

void UserLib::AddPreUser(UserC* NewUser)
{
	NumUsers++;
	UserArray.Add(NewUser);
}