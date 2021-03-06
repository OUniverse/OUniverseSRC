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


	LoadoutC* AutoLoadout = LoadoutC::Create();
	AutoLoadout->CreateMethod(1,"empty",GlyphC(0),true);
	Add(AutoLoadout);

	AutoLoadout = LoadoutC::Create();
	AutoLoadout->CreateMethod(2, "core", GlyphC(0), true);
	Add(AutoLoadout);

	AutoLoadout = LoadoutC::Create();
	AutoLoadout->CreateMethod(3, "all-official", GlyphC(0), true);
	AutoLoadout->AddAtlasLoadout(AtlasUID(1),"OUniverse");
	Add(AutoLoadout);


	if (File_.Exists())
	{
		std::string Line;
		std::ifstream File;
		File.open(File_.ToString().ToChar());

		std::getline(File, Line);

		ProvenanceC Prov = ProvenanceC(LoadoutLibC::Provenance, StringC(Line).ToIntZeroFail());

		if (!Prov.IsValid())
		{
			LOG(505, Void(), "Provenance is Invalid.");



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
				LoadoutC* NewLoadout = LoadoutC::Create();
				NewLoadout->JsonMethod(&CurJ);
				Add(NewLoadout);
			}

		}
	}

	Valid_ = true;

	

	bool FoundLoadout = false;
	bool LoginLast = Oni_->GetBool(OniTypeC::Type::User, OniUserC::LOADOUT_AUTOSELECT_LAST);

			if (LoginLast)
			{
				LOG(46288, Void(), "Attempting to select last used loadout due to config settings.");

				int LastUID = Oni_->GetInt(OniTypeC::Type::User, OniUserC::LOADOUT_LAST);

				bool LastExists = Exists(LastUID);

				LoadoutUID LastLoadoutUID = LoadoutUID(LastUID);
				LoadoutC* LastLoadout;

				if(Try(LastLoadoutUID, LastLoadout))
				{
					Set(LastLoadout);
					FoundLoadout = false;
				}
			}
	
			if (!FoundLoadout)
			{
				Set(AutoLoadout);
			}
}

void LoadoutLibC::Unload()
{
	Lib_.Cull();
}

LoadoutC* LoadoutLibC::GetLoadout(int index)
{
	return Lib_[index];
}

int LoadoutLibC::Num()
{
	return Lib_.Len();
}

void LoadoutLibC::Add(LoadoutC* InLoadout)
{
	Lib_.Add(InLoadout);
}

bool LoadoutLibC::Exists(int InUID)
{
	LoadoutC* ThrowAway;
	return Try(LoadoutUID(InUID),ThrowAway);
}

void LoadoutLibC::Set(LoadoutC* InLoadout)
{
	LOG(27668, InLoadout->Combo_UID_ID(), "New Loadout has been selected: $V$")
	LoadoutDais_->Set(InLoadout);
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