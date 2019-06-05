//Copyright 2015-2019, All Rights Reserved.

#include "Data/World.h"
#include <fstream>
#include <string>
#include "Interface/Int.h"
#include "Interface/TitleParse.h"
#include "Interface/Json.h"

StringC WorldD::Extension()
{
	return "oworld";
}

WorldD::WorldD(AtlasC* InAtlas, StringC InFile)
{
	DocD::DocD(InAtlas);

	int Result = TitleParseC::TryUID(InFile, Int::MaxU16, UID_);

	if (!Result)
	{
		return;
	}

	std::string Line;
	std::ifstream File;
	File.open((InAtlas->Path() + InFile).ToChar());

	std::getline(File, Line);
	Scribe_ = ScribeS(Line);

	std::getline(File, Line);
	Header_ = HeaderS(Line);

	if (!Header_.Valid())
	{
		return;
	}

	Valid_ = true;

}

bool WorldD::Valid()
{
	return Valid_;
}

WorldD::HeaderS::HeaderS(StringC InLine)
{
	Valid_ = false;
	JsonS Json = JsonS(InLine.ToChar());
}

bool WorldD::HeaderS::Valid()
{
	
	return Valid_;
}


void WorldD::Promote()
{

}