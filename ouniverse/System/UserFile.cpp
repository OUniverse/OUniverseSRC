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


UserFileC::UserFileC(StringC InPath) 
{
	Valid_ = false;

	StringC FullPath = InPath / UserFileC::FILE_NAME;

	if (!FileC(FullPath).Exists())
	{
		LOG(BOOT, 0, 1, InPath + ": " + "Has no user file.");
		return;
	}

	SaveC::SaveC(FullPath);
	
	std::string Line;
	std::ifstream File;
	File.open(SavePath_.ToChar());

	std::getline(File, Line);
	U8 WriterVer = StringC(Line).ToU8ZeroFail();
	if (!WriterVer)
	{
		return;
	}

	std::getline(File, Line);
	JsonS J = JsonS(StringC(Line));
	Name_	= J.String(UserFileC::K_NAME);
	Glyph_	= J.String(UserFileC::K_GLYPH);

	Valid_ = true;

}

bool UserFileC::Valid()
{
	return Valid_;
}