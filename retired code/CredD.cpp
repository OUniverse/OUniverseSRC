//Copyright 2015-2019, All Rights Reserved.

#include "Atlas/CredD.h"
#include <fstream>
#include <string>
#include "Interface/Int.h"
#include "Interface/TitleParse.h"
#include "Interface/Json.h"
#include "Interface/File.h"

#include "System/Log.h"

#include "Min/DebugM.h"


const char* CredD::FILE_NAME = "_.cred";


CredD::CredD(StringC InPath, StringC InLogID)
{
	LOG(35003, InLogID, "Loading CRED document: $V$")
	Valid_ = false;


	StringC SearchPath = (InPath / CredD::FILE_NAME);
	LOG(105, InPath, "Path: $V$")

	

	if (!FileC(SearchPath).Exists())
	{
		LOG(404, SearchPath, "File missing")
		return;
	}

	std::string Line;
	std::ifstream File;
	File.open(SearchPath.ToChar());

	std::getline(File, Line);
	U8 WriterVer = StringC(Line).ToU8ZeroFail();
	if (!WriterVer)
	{
		LOG(505, Void(), "Error with Writer Version.");
		return;
	}

	std::getline(File, Line);
	//CredF NewCredForm = CredF(StringC(Line));
	//CredMap.Add(NewCredForm.UID(), NewCredForm);

	LOG(600, Void(), "Doc is valid")
	Valid_ = true;

}

bool CredD::Valid()
{
	return Valid_;
}