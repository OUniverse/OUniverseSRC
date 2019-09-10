//Copyright 2015-2019, All Rights Reserved.

#include "System/LoadoutLib.h"

#include "System/Loadout.h"

#include "File/Loadout@.h"

#include "Interface/Int.h"
#include "Interface/Provenance.h"
#include "Interface/Json.h"

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
	Unload();
	Valid_ = false;

	File_ = InUserDir.ToFile(LoadoutFI::FileName, LoadoutFI::Extension);

	std::string Line;
	std::ifstream File;
	File.open(File_.ToString().ToChar());

	std::getline(File, Line);

	ProvenanceC Prov = ProvenanceC(LoadoutLibC::Provenance,StringC(Line).ToIntZeroFail());
	
	if (!Prov.IsValid())
	{
		return;
	}

	if (!Prov.IsCurrent())
	{
		return;
	}

	std::getline(File, Line);
	JsonS J = JsonS(StringC(Line));

	int L = J.Len();
	LOG(51222, L, "Entries: $V$")

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