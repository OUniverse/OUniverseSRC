//Copyright 2015-2019, All Rights Reserved.

#include "System/Atlas.h"
#include "System/Payload.h"

#include <fstream>
#include <string>

#include "Interface/Int.h"
#include "Interface/Json.h"
#include "Interface/FileQuery.h"

#include "System/Log.h"

#include "Data/World.h"

#include "Interface/TitleParse.h"

const char* AtlasC::EXT = "atlas";


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


	FileQueryS Fi = FileQueryS(Path_, AtlasC::EXT);

	LOG(29333, InPath + "/", "Scanning Atlas Folder at path: $V$")


	if (Fi.Num() != 1)
	{
		LOG(23985, Void(), "Multiple or no Atlas files found inside.")
		return;
	}

	int  ErrCode = TitleParseC::TryUID(Fi.File(1), Int::MaxU64, UID_);

	if (ErrCode)
	{
		LOG(13451, ErrCode, "Name is incorrect. 1:Prefix Wrong, 2:Name can't become an Integer, 3:Integer of name is larger then max allowed size.  Error Code: $V$")
			return;
	}

	if (!Header())
	{
		LOG(16946, Void(), "The file's header information is not valid.")
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