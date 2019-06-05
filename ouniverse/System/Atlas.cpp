//Copyright 2015-2019, All Rights Reserved.

#include "System/Atlas.h"
#include "System/Payload.h"

#include <fstream>
#include <string>

#include "Interface/Int.h"
#include "Interface/Json.h"
#include "Interface/FileQuery.h"

#include "Min/LogM.h"

#include "Data/World.h"

#include "Interface/TitleParse.h"

bool AtlasC::HasExtension(StringC InExtension)
{
	if (InExtension == StringC(Extension()))
	{
		return true;
	}
	return false;
}

StringC AtlasC::Extension()
{
	return "atlas";
}


AtlasC::DetailsS::DetailsS(const char*  JSerialized)
{
	JsonS J = JsonS(JSerialized);

	ID			= J.Int("id");
	Name		= J.String("name");
	Icon		= J.String("icon");
	Description	= J.String("desc");
	Author		= J.String("author");
	Website		= J.String("web");
	Date		= J.String("date");

}

AtlasC::AtlasC(StringC InPath)
{
	Path_ = InPath;
	Valid_ = false;


	FileQueryS Fi = FileQueryS(Path_,Extension());

	LOG(BOOT, 0, 0, StringC("Scanning Atlas Folder: ") + InPath + "/")


	if (Fi.Num() != 1)
	{
		LOG(BOOT, 0, 0, StringC("ERROR: Multiple or no atlas files found in folder."))
		return;
	}

	int Result = TitleParseC::TryUID(Fi.File(1), Int::MaxU64, UID_);

	if (!Result)
	{
		LOG(BOOT, 0, 0, StringC("Atlas file name is incorrect. Code: ")+StringC(Result))
		return;
	}

	if(!Header())
	{
		return;
	}

	Valid_ = true;

}

bool AtlasC::Header()
{
	std::string Line;
	std::ifstream File;
	File.open(Path_.ToChar());

	std::getline(File, Line);
	Scribe_ = ScribeS(Line);

	Details_ = DetailsS(Line.c_str());

	return true;
}

void AtlasC::Promote()
{
	
	Full_ = new AtlasFullC(this);
}

StringC AtlasC::Path()
{
	return Path_;
}

bool AtlasC::Valid()
{
	return Valid_;
}

int AtlasC::UID()
{
	return UID_;
}







AtlasFullC::AtlasFullC(AtlasC* InAtlas)
{

	Atlas_ = InAtlas;
	FileQueryS Fi = FileQueryS(Atlas_->Path());

	int Count = Fi.Num();
	for (int i = 0; i < Count; i++)
	{
		if (Fi.Extension(i) == WorldD::Extension())
		{
			WorldD* NewWorld = new WorldD(Atlas_,Fi.File(i));

		}
	}
}