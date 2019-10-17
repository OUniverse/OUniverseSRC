//Copyright 2015-2019, All Rights Reserved.

#include "System/LoadoutLib.h"

#include "System/Loadout.h"
#include "System/LoadoutDais.h"

#include "File/Loadout@.h"

#include "System/OniManager.h"
#include "System/OniKey.h"

#include "Interface/Int.h"
#include "Interface/Provenance.h"
#include "Interface/Json.h"

#include "Key/GlobalK.h"

#include <fstream>
#include <string>

#include "System/Log.h"

#include "Min/DebugM.h"

const int LoadoutLibC::Provenance = 1;


LoadoutLibC::LoadoutLibC(LoadoutDaisC* InLoadoutDais, OniManagerC* InOni)
{
	Valid_ = false;
	Oni_ = InOni;
	LoadoutDais_ = InLoadoutDais;
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

	Decide();
}

void LoadoutLibC::Unload()
{
	Lib_.Cull();
}



void LoadoutLibC::Decide()
{
	int AutoLoginUID = -1;

	if (Num() == 0)
	{
		LOG(7850, Void(), "No valid loadouts found.");
		NoValids_ = true;
	}
	else
	{
		if (Num() == 1 && Oni_->GetBool(OniTypeC::Type::User, OniUserC::LOADOUT_AUTOSELECT_SINGLE))
		{
			LOG(42667, Void(), "Selecting single loadout due to config settings and due to only 1 loadout being present.");

			AutoLogin_ = true;
			AutoLoginUID = GetSingleUID();
		}
		else
		{

			bool LoginLast = Oni_->GetBool(OniTypeC::Type::User, OniUserC::LOADOUT_AUTOSELECT_LAST);

			if (LoginLast)
			{
				LOG(46288, Void(), "Attempting to select last used loadout due to config settings.");

				int Last = Oni_->GetInt(OniTypeC::Type::User, OniUserC::LOADOUT_LAST);

				bool LastExists = Exists(Last);

				if (LastExists)
				{
					LOG(29522, Last, "Last loadout found. UID: $V$");

					AutoLogin_ = true;
					AutoLoginUID = Last;
				}
				else
				{
					LOG(28040, Last, "Last selected loadout can no longer be found. UID: $V$");
				}
			}
		}

	}


	if (AutoLoginUID != -1)
	{
		Set(AutoLoginUID);
	}
}

JsonS LoadoutLibC::UiStatus()
{

	JsonS J = JsonS();

	return J.Serialize();
}

int LoadoutLibC::Num()
{
	return Lib_.Len();
}

void LoadoutLibC::Add(JsonS* InJ)
{
	LoadoutC* New = new LoadoutC(InJ);
	Lib_.Add(New);
}

bool LoadoutLibC::Exists(int InUID)
{
	LoadoutC* ThrowAway;
	return Try(LoadoutUID(InUID),ThrowAway);
}

void LoadoutLibC::Set(int InUID)
{
	LoadoutC* Try_;
	if (Try(InUID, Try_))
	{
		LOG(27668, Try_->Combo_UID_ID(), "New Loadout has been selected: $V$")
		LoadoutDais_->Set(Try_);
	}
	else
	{
		DBUG("LOADOUT THAT SHOULD BE THERE WAS NOT")
		LOG(36307, InUID, "The selected Loadout file is somehow not there. This is a terminating error. UID: $V$")
	}
}

bool LoadoutLibC::Try(LoadoutUID InUID, LoadoutC*& OutLoadout)
{

	int l = Lib_.Len();

	for (int i = 0; i < l; i++)
	{
		if (Lib_[i]->UID() == InUID)
		{
			OutLoadout = Lib_[i];
			return true;
		}
	}
	return false;
}

int LoadoutLibC::GetSingleUID()
{
	return Lib_[0]->UID().ToInt();
}



ArrayC<LoadoutC*> LoadoutLibC::Loadouts()
{
	return Lib_;
}