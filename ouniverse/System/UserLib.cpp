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
	NoValids_ = false;
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
			UserC* NewUser = UserC::Create(Fo[i], Fo[i].GetFinalDir());

			if (NewUser->IsValid())
			{
				Add(NewUser);
			}
		}

		LOG(48414, Num(), "Loading User data complete. Valid users found: $V$")
		LOGP
		return;
}

void UserLibC::Decide()
{
	int AutoLoginUID = -1;

	if (Num() == 0)
	{
		LOG(50838, Void(), "No valid users found.");
		NoValids_ = true;
	}
	else
	{
		if (Num() == 1 && Oni_->GetBool(OniTypeC::Type::Global, OniGlobalC::AUTOLOGIN_SINGLE_USER))
		{
			LOG(48382, Void(), "Logging in single user due to config settings and due to only 1 user being present.");

			AutoLogin_ = true;
			AutoLoginUID = GetSingleUID();
		}
		else
		{

			bool LoginLastUser = Oni_->GetBool(OniTypeC::Type::Global, OniGlobalC::AUTOLOGIN_LAST_USER);

			if (LoginLastUser)
			{
				LOG(43790, Void(), "Attempting to login in last user because of config settings...");

				int LastUser = Oni_->GetInt(OniTypeC::Type::Internal, OniInternalC::LAST_USER);

				bool LastUserExists = Exists(LastUser);

				if (LastUserExists)
				{
					LOG(36512, LastUser, "Last user found. UID: $V$");

					AutoLogin_ = true;
					AutoLoginUID = LastUser;
				}
				else
				{
					LOG(36513, LastUser, "Last user can no longer be found. UID: $V$");
				}
			}
		}

	}

	if (AutoLoginUID != -1)
	{
		Set(AutoLoginUID);
	}
}

JsonS UserLibC::UiStatus()
{

	JsonS J = JsonS();

	J.Add("autolog", AutoLogin_);
	J.Add("novalids", NoValids_);

	return J.Serialize();
}

bool UserLibC::Exists(int InUID)
{
	UserC* ThrowAwayUser;
	return Try(InUID, ThrowAwayUser);
}

void UserLibC::Set(int InUID)
{
	UserC* TryUser;
	if (Try(InUID,TryUser))
	{
		LOG(18311, TryUser->Combo_UID_ID(), "New USER has been selected: $V$")
		UserDais_->Set(TryUser);
	}
	else
	{
		DBUG("USER THAT SHOULD BE THERE WAS NOT")
		LOG(43669, InUID, "The selected User Folder is somehow not there. This is a terminating error. UID: $V$")
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
	return Lib_.Len();
}

void UserLibC::Add(UserC* NewUser)
{
	Lib_.Add(NewUser);
}

ArrayC<UserC*> UserLibC::Users()
{
	return Lib_;
}

int UserLibC::GetSingleUID()
{
	return Lib_[0]->UID().ToInt();
}