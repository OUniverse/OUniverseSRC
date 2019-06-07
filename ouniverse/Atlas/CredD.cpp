//Copyright 2015-2019, All Rights Reserved.

#include "Atlas/CredD.h"
#include <fstream>
#include <string>
#include "Interface/Int.h"
#include "Interface/TitleParse.h"
#include "Interface/Json.h"

#include "System/Log.h"

#include "Min/DebugM.h"


const char* CredD::EXT = "Cred";
const char* CredD::PFX = "G";

CredD::CredD(StringC InFile, StringC InPath)
{

	Valid_ = false;

	LOG(35187, InPath, "Validating Cred file at path: $V$")

		int ErrCode = TitleParseC::TryPrefixedUID(InFile.TrimExtension(), CredD::PFX, Int::MaxU8, UID_);

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
	//CredF NewCredForm = CredF(StringC(Line));
	//CredMap.Add(NewCredForm.UID(), NewCredForm);

	LOG(30398, int(UID_), "Cred is valid: $V$")
		Valid_ = true;

}

U8 CredD::UID()
{
	return UID_;
}

bool CredD::Valid()
{
	return Valid_;
}