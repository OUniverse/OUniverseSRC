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


UserLibC* UserLibC::Create(NewFolderC InFolder, KernelC* InKernel)
{
	return new UserLibC(InFolder, InKernel);
}

UserLibC::~UserLibC()
{
	for (int i = 0; i < Num(); i++)
	{
		delete Lib_[i];
	}
}

UserLibC::UserLibC(NewFolderC InFolder, KernelC* InKernel)
{
	UserSet_ = false;
	Session_ = InKernel;

	Folder_ = InFolder;
	Num_ = 0;
	DirLoaded_ = false;
}

void UserLibC::LoadUsers()
{

	LOG(27073, Folder_.ToString(), "Loading all User data from folder: $V$")
	DBUG("GOT HERE")

		if (DirLoaded_ == false)
		{

			ArrayC<NewFolderC> Fo = Folder_.GetFolders();
			int l = Fo.Len();

			for (int i = 0; i < l; i++)
			{

				UserC* NewUser = UserC::Create(Fo[i], Fo[i].GetFinalDir());

				if (NewUser->IsValid())
				{
					AddUser(NewUser);
				}

			}

			DirLoaded_ = true;
			DBUG("GOT HERE22222222222")
			LOG(48414, Num(), "Loading User data complete. Valid users found: $V$")
			LOGP
			return;
		}

	LOG(62059, Void(), "Loading User data skipped. The directory has already been scanned since the program opened.")
}

void UserLibC::SetUser(int UID)
{
	int L = Lib_.Len();
	for (int i = 0; i < L; i++)
	{
		if (Lib_[i]->UID() == UID)
		{
			DBUG("ACTIVE USER FOUND");

			if (UserSet_)
			{
				User_->Demount();
			}
			UserSet_ = true;
			User_ = Lib_[i];
			
			Session_->SetUser(Lib_[i]);
			break;
		}
	}
}

UserC* UserLibC::User(int Index)
{
	return Lib_[Index];
}

int UserLibC::Num()
{
	return Num_;
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

void UserLibC::AddUser(UserC* NewUser)
{
	Num_++;
	Lib_.Add(NewUser);
}

ArrayC<UserC*> UserLibC::Users()
{
	return Lib_;
}