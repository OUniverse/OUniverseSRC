//Copyright 2015-2019, All Rights Reserved.

#include "System/LoadoutLib.h"

#include "System/Loadout.h"

#include "Interface/Int.h"
#include "Interface/WriterVer.h"

#include <fstream>
#include <string>

LoadoutLibC::LoadoutLibC(StringC InUserPath)
{
	Path_ = InUserPath;

	std::string Line;
	std::ifstream File;
	File.open(Path_.ToChar());

	std::getline(File, Line);

	UInt8 WriterVer = StringC(Line).ToU8ZeroFail();
	if (!WriterVer)
	{
		return;
	}

	UInt8 Count = StringC(Line).ToU8ZeroFail();
	if (!Count)
	{
		return;
	}

	for (int i = 0; i < Count.Ref(); i++)
	{
		std::getline(File, Line);
		LoadoutC* NewLoadout = new LoadoutC(StringC(Line));
	}

	UInt16 Entries = StringC(Line).ToU16ZeroFail();
	Num_ = Lib_.Len();

	Valid_ = true;
}


bool LoadoutLibC::Try(int InUID, LoadoutC*& OutLoadout)
{

	
	for (int i = 0; i < Num_; i++)
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