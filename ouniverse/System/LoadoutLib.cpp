//Copyright 2015-2019, All Rights Reserved.

#include "System/LoadoutLib.h"

#include "System/Loadout.h"

#include "File/Loadout@.h"

#include "Interface/Int.h"
#include "Interface/Provenance.h"
#include "Interface/Json.h"

#include "Key/GlobalK.h"

#include <fstream>
#include <string>

#include "System/Log.h"



const int LoadoutLibC::Provenance = 1;


LoadoutLibC::LoadoutLibC()
{
	Valid_ = false;
}


void LoadoutLibC::Load(FolderC InUserDir)
{
	Valid_ = false;
	File_ = InUserDir.ToFile(StringC(LoadoutFI::FileName), StringC(LoadoutFI::Extension));

	LOG(37930, File_.ToString().ToChar(), "Processing Loadout Data at path: $V$")

	Unload();	

	std::string Line;
	std::ifstream File;
	File.open(File_.ToString().ToChar());

	std::getline(File, Line);

	ProvenanceC Prov = ProvenanceC(LoadoutLibC::Provenance,StringC(Line).ToIntZeroFail());
	
	if (!Prov.IsValid())
	{
		LOG(505, Void(), "Provenance is Invalid.");
		return;
	}

	if (!Prov.IsCurrent())
	{
		return;
	}

	std::getline(File, Line);
	JsonS J = JsonS(StringC(Line));

	int L = J.Len();
	LOG(3004, L, "Loadouts: $V$")

		if (L == 0)
		{
			return;
		}

	for (int i = 0; i < L; i++)
	{
		JsonS CurJ = J[i];
		Add(&CurJ);
	}


	Valid_ = true;
}

void LoadoutLibC::Unload()
{
	Lib_.DeleteAndRemoveAll();
}



void LoadoutLibC::Decide()
{
	int AutoLoginUID = 0;

	if (Num() == 0)
	{
		LOG(50838, Void(), "System Menu has found no valid users.");
		NoValids_ = true;
	}
	else
	{
		if (Num() == 1 && Oni_->GetBool(OniTypeC::Type::Global, OniGlobalC::AUTOLOGIN_SINGLE_USER))
		{
			LOG(48382, Void(), "Logging in single user due to config settings and due to only 1 user being present.");

			AutoLogin_ = true;
			AutoLoginUID = GetSingleUserUID();
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


	Set(AutoLoginUID);
}

void LoadoutLibC::Add(JsonS* InJ)
{
	LoadoutC* New = new LoadoutC(InJ);
	Lib_.Add(LoadoutUID(New->UID()),New);
}

bool LoadoutLibC::Try(LoadoutUID InUID, LoadoutC*& OutLoadout)
{

	if (Lib_.Try(InUID,OutLoadout))
	{
			return true;
	}

	return false;
}


LoadoutLibC* LoadoutLibC::Create()
{
	return new LoadoutLibC();
}