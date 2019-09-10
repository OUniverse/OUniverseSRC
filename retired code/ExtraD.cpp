//Copyright 2015-2019, All Rights Reserved.

#include "Atlas/ExtraD.h"
#include <fstream>
#include <string>
#include "Interface/Int.h"
#include "Interface/TitleParse.h"
#include "Interface/Json.h"
#include "Interface/File.h"

#include "System/Log.h"

#include "Min/DebugM.h"


const char* ExtraD::FILE_NAME = "_.extra";


ExtraD::ExtraD(StringC InPath, StringC InLogID)
{

	LOG(35002, InLogID, "Loading EXTRA document: $V$")
	Valid_ = false;

	StringC SearchPath = (InPath / ExtraD::FILE_NAME);
	LOG(105, InPath, "Path: $V$")


	if (!FileC(SearchPath).Exists())
	{
		LOG(404, SearchPath, "File missing")
			return;
	}

	std::string Line;
	std::ifstream File;
	File.open(InPath.ToChar());

	std::getline(File, Line);
	U8 WriterVer = StringC(Line).ToU8ZeroFail();
	if (!WriterVer)
	{
		LOG(505, Void(), "Error with Writer Version.");
		return;
	}

	std::getline(File, Line);
	//ExtraF NewExtraForm = ExtraF(StringC(Line));
	//ExtraMap.Add(NewExtraForm.UID(), NewExtraForm);

	LOG(600, Void(), "Doc is valid")
	Valid_ = true;

}

void ExtraD::Mount(FormLibC* InFormLib)
{
	
}

bool ExtraD::Valid()
{
	return Valid_;
}