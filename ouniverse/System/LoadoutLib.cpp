//Copyright 2015-2019, All Rights Reserved.

#include "System/LoadoutLib.h"

#include "System/Loadout.h"

#include "Interface/Int.h"
#include "Interface/WriterVer.h"
#include "Interface/Json.h"

#include <fstream>
#include <string>

#include "System/Log.h"



const char* LoadoutLibC::FILE_NAME = "_loadout.olo";


LoadoutLibC::LoadoutLibC(StringC InUserPath)
{
	LOG(30000, "LoadoutLib:", "Initializing $V$.")

	Inc_ = 1;
	Len_ = 0;

	Path_ = InUserPath;

	std::string Line;
	std::ifstream File;
	File.open((Path_/LoadoutLibC::FILE_NAME).ToChar());

	std::getline(File, Line);

	U8 WriterVer = StringC(Line).ToU8ZeroFail();
	if (!WriterVer)
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


void LoadoutLibC::Add(JsonS* InJ)
{
	LoadoutC* NewLoadout = new LoadoutC(Inc_, InJ);
	Lib_.Add(Inc_,NewLoadout);
	Len_++;
	Inc_++;
}

bool LoadoutLibC::Try(int InUID, LoadoutC*& OutLoadout)
{

		if (Lib_.Try(InUID,OutLoadout))
		{
			return true;
		}

	return false;
}


LoadoutLibC* LoadoutLibC::Create(StringC InUserPath)
{
	return new LoadoutLibC(InUserPath);
}


int LoadoutLibC::Len()
{
	return Len_;
}