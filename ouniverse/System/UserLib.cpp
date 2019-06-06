//Copyright 2015-2019, All Rights Reserved.

#include "System/UserLib.h"
#include "System/User.h"

#include "Interface/Dir.h"
#include "Interface/File.h"

#include "Interface/DirQuery.h"

#include "System/Log.h"

#include "Min/DebugM.h"

#include "System/Kernel.h"



#define EXT_USER ".ouser"
#define USER_STANDARD_FILEPREFIX "_"


UserLibC* UserLibC::Create(DirS* InDirUsers, KernelC* InKernel)
{
	return new UserLibC(InDirUsers, InKernel);
}

UserLibC::UserLibC(DirS* InDirUsers, KernelC* InKernel)
{
	UserSet_ = false;
	Session_ = InKernel;

	DirUsers = InDirUsers;
	Num_ = 0;
	DirLoaded_ = false;
}

void UserLibC::SetUser(int UID)
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


int UserLibC::Num()
{
	return Num_;
}
void UserLibC::LoadUsers()
{

	LOG(27073, DirUsers->Get(), "Loading all User data from folder: $V$")

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
		LOG(48414, Count, "Loading User data complete. Valid users found: $V$")
		return;
	}

	LOG(62059, Void(), "Loading User data skipped. The directory has already been scanned since the program opened.")
}

bool UserLibC::IsUserChosen()
{
	return false;
}

bool UserLibC::HasSoloUser()
{
	return false;
}

bool UserLibC::HasLastUser()
{
	return false;
}

UserC* UserLibC::GetUser()
{
	return User_;
}

void UserLibC::AddPreUser(UserC* NewUser)
{
	Num_++;
	UserArray.Add(NewUser);
}