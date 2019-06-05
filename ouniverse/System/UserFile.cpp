//Copyright 2015-2019, All Rights Reserved.

#include "System/UserFile.h"

#include "Interface/Json.h"
#include "Interface/File.h"

#include <fstream>
#include <string>

#include "Min/LogM.h"

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
		LOG(BOOT, 0, 1, FullPath);
		LOG(BOOT, 0, 1, InPath + ": " + "Has no user file.");
		return;
	}
	
	std::string Line;
	std::ifstream File;
	File.open(SavePath_.ToChar());

	std::getline(File, Line);
	U8 WriterVer = StringC(Line).ToU8ZeroFail();
	if (!WriterVer)
	{
		LOG(BOOT, 0, 1, "Error with Writer Version.");
		LOG(BOOT, 0, 1, StringC(Line));
		LOG(BOOT, 0, 1, SavePath_.ToChar());
		LOG(BOOT, 0, 1, InPath);
		LOG(BOOT, 0, 1, FullPath);
		return;
	}

	std::getline(File, Line);
	JsonS J = JsonS(StringC(Line));
	Name_	= J.String(UserFileC::K_NAME);
	Glyph_	= J.String(UserFileC::K_GLYPH);

	LOG(BOOT, 0, 1, StringC("User Valid: ")+StringC(Name_));

	Valid_ = true;

}

bool UserFileC::Valid()
{
	return Valid_;
}