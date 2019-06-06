//Copyright 2015-2019, All Rights Reserved.

#include "System/LoadoutLib.h"

#include "System/Loadout.h"

#include "Interface/Int.h"
#include "Interface/WriterVer.h"

#include <fstream>
#include <string>

#include "System/Log.h"



const char* LoadoutLibC::FILE_NAME = "_loadout.olo";



LoadoutLibC::LoadoutLibC(StringC InUserPath)
{
	LOG(30000, "LoadoutLib:", "Initializing $V$.")

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
	int Count = StringC(Line).ToIntZeroFail();

	LOG(51222, Count, "Entries: $V$")
	
	if (Count == 0)
	{
		return;
	}	

	for (int i = 0; i < Count; i++)
	{
		std::getline(File, Line);		
		LoadoutC* NewLoadout = new LoadoutC(i,StringC(Line));
		Lib_.Add(NewLoadout);
	}

	U16 Entries = StringC(Line).ToU16ZeroFail();
	Num_ = Lib_.Len();

	Valid_ = true;
}


bool LoadoutLibC::Try(int InUID, LoadoutC*& OutLoadout)
{

	int L = Lib_.Len();
	for (int i = 0; i < L; i++)
	{
		if (Lib_[i]->GetUID().Ref() == InUID)
		{
			OutLoadout = Lib_[i];
			return true;
		}
	}

	return false;
}


LoadoutLibC* LoadoutLibC::Create(StringC InUserPath)
{
	return new LoadoutLibC(InUserPath);
}


int LoadoutLibC::Num()
{
	return Num_;
}