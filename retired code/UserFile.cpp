//Copyright 2015-2019, All Rights Reserved.

#include "System/UserFile.h"

#include "Interface/Json.h"
#include "Interface/File.h"

#include <fstream>
#include <string>

#include "System/Log.h"

const char* UserFileC::K_NAME		= "n";
const char* UserFileC::K_GLYPH		= "g";
const char* UserFileC::K_AWARDS		= "a";
const char* UserFileC::FILE_NAME	= "_user.ousr";


UserFileC::UserFileC(StringC InPath) : SaveC(InPath / UserFileC::FILE_NAME)
{
	Valid_ = false;

	StringC FullPath = InPath / UserFileC::FILE_NAME;

	if (!FileC(FullPath).Exists())
	{
		LOG(13789, UserFileC::FILE_NAME, "File missing: $V$")
		return;
	}
	
	std::string Line;
	std::ifstream File;
	File.open(SavePath_.ToChar());

	std::getline(File, Line);
	U8 WriterVer = StringC(Line).ToU8ZeroFail();
	if (!WriterVer)
	{
		LOG(505, Void(), "Error with Writer Version.");
		return;
	}

	std::getline(File, Line);
	JsonS J = JsonS(StringC(Line));
	Name_	= J.String(UserFileC::K_NAME);
	Glyph_	= J.String(UserFileC::K_GLYPH);

	LOG(10293, Name_, "Is Valid: $V$")

	Valid_ = true;

}

bool UserFileC::Valid()
{
	return Valid_;
}