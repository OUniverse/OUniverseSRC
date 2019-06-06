//Copyright 2015-2019, All Rights Reserved.

#include "Atlas/BoostD.h"
#include <fstream>
#include <string>
#include "Interface/Int.h"
#include "Interface/TitleParse.h"
#include "Interface/Json.h"

#include "System/Log.h"

#include "Min/DebugM.h"


const char* BoostD::EXT_Boost = "boost";
const char* BoostD::PFX = "B";

BoostD::BoostD(StringC InFile, StringC InPath)
{

	Valid_ = false;

	LOG(35187, InPath, "Validating Boost file at path: $V$")

		int ErrCode = TitleParseC::TryPrefixedUID(InFile.TrimExtension(), BoostD::PFX, Int::MaxU8, UID_);

	if (ErrCode)
	{
		LOG(13451, ErrCode, "Name is incorrect. 1:Prefix Wrong, 2:Name can't become an Integer, 3:Integer of name is larger than max allowed size.  Error Code: $V$")
			return;
	}

	std::string Line;
	std::ifstream File;
	File.open(InPath.ToChar());

	std::getline(File, Line);
	U8 WriterVer = StringC(Line).ToU8ZeroFail();
	if (!WriterVer)
	{
		LOG(51687, Void(), "Error with Writer Version.");
		return;
	}

	std::getline(File, Line);
	//BoostF NewBoostForm = BoostF(StringC(Line));
	//BoostMap.Add(NewBoostForm.UID(), NewBoostForm);

	LOG(30398, int(UID_), "Boost is valid: $V$")
		Valid_ = true;

}

U8 BoostD::UID()
{
	return UID_;
}

bool BoostD::Valid()
{
	return Valid_;
}