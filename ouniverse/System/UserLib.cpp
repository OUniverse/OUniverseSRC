//Copyright 2015-2019, All Rights Reserved.

#include "System/UserLib.h"
#include "System/User.h"

#include "Interface/Dir.h"
#include "Interface/File.h"

#include "Interface/DirQuery.h"

#include "System/Log.h"

#include "Min/DebugM.h"

#include "System/Kernel.h"




UserLibC::~UserLibC()
{
	for (int i = 0; i < Num(); i++)
	{
		delete Lib_[i];
	}
}

UserLibC::UserLibC(NewFolderC InFolder, UserW* UserW_)
{
	Folder_ = InFolder;
	Num_ = 0;
	DirLoaded_ = false;
}

void UserLibC::LoadUsers()
{

	LOG(27073, Folder_.ToString(), "Loading all User data from folder: $V$")

		if (DirLoaded_ == false)
		{

			ArrayC<NewFolderC> Fo = Folder_.GetFolders();
			int l = Fo.Len();

			for (int i = 0; i < l; i++)
			{
				DBUG(Fo[i].ToString().ToChar())
				UserC* NewUser = UserC::Create(Fo[i], Fo[i].GetFinalDir());

				if (NewUser->IsValid())
				{
					AddUser(NewUser);
				}

			}

			DirLoaded_ = true;
			LOG(48414, Num(), "Loading User data complete. Valid users found: $V$")
			LOGP
			return;
		}

	LOG(62059, Void(), "Loading User data skipped. The directory has already been scanned since the program opened.")
}

void UserLibC::SetUser(int UID)
{
	UserC* TryUser;
	if (Try(UID,TryUser))
	{
		UserW_->Set(TryUser);
	}
	else
	{
		DBUG("USER THAT SHOULD BE THERE WAS NOT")
	}
}

bool UserLibC::Try(int UID, UserC*& InUser)
{
	int L = Lib_.Len();
	for (int i = 0; i < L; i++)
	{
		if (Lib_[i]->UID() == UID)
		{
			InUser = Lib_[i];
			return true;
		}
	}

	return false;
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

void UserLibC::AddUser(UserC* NewUser)
{
	Num_++;
	Lib_.Add(NewUser);
}

ArrayC<UserC*> UserLibC::Users()
{
	return Lib_;
}