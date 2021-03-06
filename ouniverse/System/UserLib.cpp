//Copyright 2015-2019, All Rights Reserved.

#include "System/UserLib.h"
#include "System/UserDais.h"
#include "System/User.h"

#include "System/OniManager.h"
#include "System/OniType.h"
#include "System/OniKey.h"

#include "System/Log.h"

#include "Min/DebugM.h"




UserLibC::~UserLibC()
{
	for (int i = 0; i < Num(); i++)
	{
		delete Lib_[i];
	}
}

UserLibC::UserLibC(FolderC InFolder, UserDaisC* InUserD, OniManagerC* InOni)
{
	Folder_ = InFolder;
	UserDais_ = InUserD;
	Oni_ = InOni;

	Loaded_ = false;
	HasValidUser_ = false;
	AutoLogin_ = false;
}

void UserLibC::Load()
{
	if (Loaded_)
	{
		LOG(25797, Void(), "Loading User data skipped. The directory has already been scanned since the program opened.")
		return;
	}

	LOG(27073, Folder_.ToString(), "Loading all User data from folder: $V$")

		ArrayC<FolderC> Fo = Folder_.GetFolders();
		int l = Fo.Len();

		for (int i = 0; i < l; i++)
		{
			UserC* NewUser = UserC::Create(Fo[i]);
			NewUser->LoadMethod(Fo[i].GetFinalDir());
			if (NewUser->IsValid())
			{
				Add(NewUser);
			}
		}

		LOG(48414, Num(), "Loading User data complete. Valid users found: $V$")





		LastUserUID_ = -1;

		if (Num() == 0)
		{
			LOG(50838, Void(), "No valid users found.");
		}
		else
		{
			HasValidUser_ = true;

			if (Num() == 1 && Oni_->GetBool(OniTypeC::Type::Global, OniGlobalC::AUTOLOGIN_SINGLE_USER))
			{
				LOG(48382, Void(), "Logging in single user due to config settings and due to only 1 user being present.");

				AutoLogin_ = true;
				LastUserUID_ = GetSingleUID();
			}
			else
			{

				bool LoginLastUser = Oni_->GetBool(OniTypeC::Type::Global, OniGlobalC::AUTOLOGIN_LAST_USER);

				if (LoginLastUser)
				{
					LOG(43790, Void(), "Attempting to login in last user because of config settings...");

					int LastUserONI = Oni_->GetInt(OniTypeC::Type::Internal, OniInternalC::LAST_USER);

					bool LastUserExists = Exists(LastUserONI);

					if (LastUserExists)
					{
						LOG(36512, LastUserONI, "Last user found. UID: $V$");

						AutoLogin_ = true;
						LastUserUID_ = LastUserONI;
					}
					else
					{
						LOG(36513, LastUserONI, "Last user can no longer be found. UID: $V$");
					}
				}
			}

		}

		LOGP
		return;
}

 
bool UserLibC::AutoLogin()
{
	return AutoLogin_;
}

bool UserLibC::HasValidUser()
{
	return HasValidUser_;
}

bool UserLibC::IsNameValid(StringC inName)
{
	return true;
}

int UserLibC::GetNewUID()
{
	int NewUID = rand() % 22766 + 10000;
	return NewUID;
}

UserC* UserLibC::GetUser(int index)
{
	return Lib_[index];
}

UserC* UserLibC::CreateNewUser(StringC InName)
{
	int NewUID = GetNewUID();

	FolderC NewUserFolder = PathC::DirUsers().ToInsideFolder(StringC("U") + StringC(NewUID));
	NewUserFolder.Make();
	
	UserC* NewUser = UserC::Create(NewUserFolder);
	NewUser->CreateMethod(NewUID, InName);
	Add(NewUser);
	return NewUser;
}


bool UserLibC::Exists(int InUID)
{
	UserC* ThrowAwayUser;
	return Try(InUID, ThrowAwayUser);
}

void UserLibC::Set(UserC* InUser)
{

	LOG(18311, InUser->Combo_UID_ID(), "New USER has been selected: $V$")
	UserDais_->Set(InUser);

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
	return Lib_.Len();
}

void UserLibC::Add(UserC* NewUser)
{
	Lib_.Add(NewUser);
}

ArrayC<UserC*>* UserLibC::Users()
{
	return &Lib_;
}

int UserLibC::GetSingleUID()
{
	return Lib_[0]->UID().ToInt();
}