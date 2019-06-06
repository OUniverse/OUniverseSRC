//Copyright 2015-2019, All Rights Reserved.

#include "Atlas/ActraD.h"
#include <fstream>
#include <string>
#include "Interface/Int.h"
#include "Interface/TitleParse.h"
#include "Interface/Json.h"

#include "System/Log.h"

#include "Min/DebugM.h"


const char* ActraD::EXT_Actra = "actra";
const char* ActraD::PFX = "A";

ActraD::ActraD(StringC InFile, StringC InPath)
{

	Valid_ = false;

	LOG(35187, InPath, "Validating Actra file at path: $V$")

		int ErrCode = TitleParseC::TryPrefixedUID(InFile.TrimExtension(), ActraD::PFX, Int::MaxU8, UID_);

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
	//ActraF NewActraForm = ActraF(StringC(Line));
	//ActraMap.Add(NewActraForm.UID(), NewActraForm);

	LOG(30398, int(UID_), "Actra is valid: $V$")
		Valid_ = true;

}

U8 ActraD::UID()
{
	return UID_;
}

bool ActraD::Valid()
{
	return Valid_;
}