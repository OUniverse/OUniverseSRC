//Copyright 2015-2019, All Rights Reserved.

#include "System/Atlas.h"
#include "System/Payload.h"

#include <fstream>
#include <string>

#include "Interface/Int.h"
#include "Interface/Json.h"
#include "Interface/FileQuery.h"
#include "Interface/File.h"

#include "System/Log.h"

#include "Data/World.h"

#include "Interface/TitleParse.h"

const char* AtlasC::FILE_NAME = "header.atlas";

const char* AtlasC::K_ID			= "i";
const char* AtlasC::K_NAME			= "n";
const char* AtlasC::K_ICON			= "g";
const char* AtlasC::K_DESC			= "d";
const char* AtlasC::K_AUTHOR		= "a";
const char* AtlasC::K_WEBSITE		= "w";
const char* AtlasC::K_DATE			= "t";
const char* AtlasC::K_VER			= "vv";
const char* AtlasC::K_IVER			= "iv";

const char* AtlasC::K_LINKS			= "l";
const char* AtlasC::K_LINKS_HARD	= "h";
const char* AtlasC::K_LINKS_SOFT	= "s";
const char* AtlasC::K_LINKS_PREF	= "p";

const char* AtlasC::K_FLAGS			= "f";

AtlasC::AtlasC(StringC InFolderName,StringC InFullPath)
{
	Valid_ = false;
	Promoted_ = false;
	Requirements_ = false;
	RequirementsChecked_ = false;
	FoundLinksHard_ = false;
	FoundLinksSoft_ = false;
	FoundLinksPref_ = false;
	
	LOG(29333, InFullPath, "Validating Atlas folder at path: $V$")

	int ErrCode = TitleParseC::TryUID(InFolderName, Int::MaxU64, UID_);

	if (ErrCode)
	{
		LOG(13451, ErrCode, "Name is incorrect. 1:Prefix Wrong, 2:Name can't become an Integer, 3:Integer of name is larger than max allowed size.  Error Code: $V$")
		return;
	}

	
	StringC SearchPath = InFullPath/AtlasC::FILE_NAME;

	if (!FileC(SearchPath).Exists())
	{
		LOG(13789, SearchPath, "File missing: $V$")
		return;
	}

	std::string Line;
	std::ifstream File;
	File.open(SearchPath.ToChar());

	std::getline(File, Line);
	U8 WriterVer = StringC(Line).ToU8ZeroFail();
	if (!WriterVer)
	{
		LOG(51687, Void(), "Error with Writer Version.");
		return;
	}

	std::getline(File, Line);
	JsonS J = JsonS(StringC(Line));
	ID_			= J.String(AtlasC::K_ID);
	Name_		= J.String(AtlasC::K_NAME);
	Icon_		= J.String(AtlasC::K_ICON);
	Desc_		= J.String(AtlasC::K_DESC);
	Author_		= J.String(AtlasC::K_AUTHOR);
	Website_	= J.String(AtlasC::K_WEBSITE);
	Date_		= J.String(AtlasC::K_DATE);
	Ver_		= J.String(AtlasC::K_VER);
	Inc_		= J.Int(AtlasC::K_IVER);

	JsonS Links = J[AtlasC::K_LINKS];

	JsonS CurLinks = Links[AtlasC::K_LINKS_HARD];
	int L = CurLinks.Len();
	for (int i = 0; i < L; i++)
	{
		LinksHard.Add(Link(CurLinks[i].UInt64()));
	}

	CurLinks = Links[AtlasC::K_LINKS_SOFT];
	L = CurLinks.Len();
	for (int i = 0; i < L; i++)
	{
		LinksSoft.Add(Link(CurLinks[i].UInt64()));
	}

	CurLinks = Links[AtlasC::K_LINKS_PREF];
	L = CurLinks.Len();
	for (int i = 0; i < L; i++)
	{
		LinksPref.Add(Link(CurLinks[i].UInt64()));
	}

	LOG(5587, UID_, "Atlas approved: $V$")

	LOG(10293, Name_, "Is Valid: $V$")

	Valid_ = true;

}

void AtlasC::Promote()
{
	Promoted_ = true;
	Full_ = new AtlasFullC(this);
}

void AtlasC::Demote()
{
	Promoted_ = false;
	delete Full_;
}


bool AtlasC::Promoted()
{
	return Promoted_;
}

StringC AtlasC::Path()
{
	return Path_;
}

bool AtlasC::Valid()
{
	return Valid_;
}

U64 AtlasC::UID()
{
	return UID_;
}



bool AtlasC::CheckRequirements(MapC<U64, AtlasC*>* InAtlasMap)
{
	if (!RequirementsChecked_)
	{
		bool OK = true;

		AtlasC* LinkTarget;

		int L = LinksHard.Len();
		for (int i = 0; i < L; i++)
		{
			if(InAtlasMap->Try(LinksHard[i].UID(), LinkTarget))
			{
				if(!LinkTarget->CheckRequirements(InAtlasMap))
				{
					OK = false;
				}
				else
				{
					LinksHard[i].Found();
				}
			}
			else
			{
				OK = false;
			}
		}

		RequirementsChecked_ = true;
		Requirements_ = OK;

		LOG(60875, Name_, "Checking requirements for: $V$")
		LOG(50166, OK, "Requirements result: $V$")
	}

	return Requirements_;
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







AtlasC::Link::Link()
{
	UID_ = 0;
	Exists_ = false;
}

AtlasC::Link::Link(U64 InUID)
{
	UID_ = InUID;
}

void AtlasC::Link::Found()
{
	Exists_ = true;
}

bool AtlasC::Link::Exists()
{
	return Exists_;
}

U64 AtlasC::Link::UID()
{
	return UID_;
}