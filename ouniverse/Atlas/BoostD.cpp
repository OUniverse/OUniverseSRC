//Copyright 2015-2019, All Rights Reserved.

#include "Atlas/BoostD.h"
#include <fstream>
#include <string>
#include "Interface/Int.h"
#include "Interface/TitleParse.h"
#include "Interface/Json.h"
#include "Interface/File.h"

#include "System/Log.h"

#include "Min/DebugM.h"

#include "System/FormLib.h"

const char* BoostD::FILE_NAME = "_.boost";

BoostD::BoostD(StringC InPath, StringC InLogID)
{
	LOG(35001, InLogID, "Loading Boost document: $V$")
	Valid_ = false;

	Path_ = (InPath / BoostD::FILE_NAME);

	LOG(105, Path_, "Path: $V$")

		
		if (!FileC(Path_).Exists())
		{
			LOG(404, Path_, "File missing")
				return;
		}

	std::string Line;
	std::ifstream File;
	File.open(Path_.ToChar());

	std::getline(File, Line);
	U8 WriterVer = StringC(Line).ToU8ZeroFail();
	if (!WriterVer)
	{
		LOG(505, Void(), "Error with Writer Version.");
		return;
	}

	std::getline(File, Line);

	LOG(600, Void(), "Doc is valid")
	Valid_ = true;

}
bool BoostD::Valid()
{
	return Valid_;
}

StringC BoostD::GetForms()
{
	
	std::string Line;
	std::ifstream File;
	File.open(Path_.ToChar());

	std::getline(File, Line);
	std::getline(File, Line);
	return StringC(Line);

}