//Copyright 2015-2019, All Rights Reserved.

#include "System/Atlas.h"
#include "System/Payload.h"

#include <fstream>
#include <string>

#include "System/AtlasLib.h"

#include "Interface/Int.h"
#include "Interface/Json.h"
#include "Interface/FileQuery.h"
#include "Interface/File.h"

#include "System/Log.h"

#include "Atlas/BoostD.h"

#include "System/FormLib.h"
#include "System/CreditLib.h"

#include "Interface/TitleParse.h"




const char* AtlasC::FILE_NAME = "_header.atlas";


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
	Path_ = InFullPath;

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

	
	StringC SearchPath = (InFullPath / AtlasC::FILE_NAME);

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
}

void AtlasC::Demote()
{
	Promoted_ = false;
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



bool AtlasC::CheckRequirements(AtlasLibC* InAtlasMap)
{
	if (!RequirementsChecked_)
	{
		bool IsAllowed = true;

		AtlasC* RequiredAtlas = NULL;

		int L = LinksHard.Len();
		for (int i = 0; i < L; i++)
		{
			if(InAtlasMap->Try(LinksHard[i].UID(), RequiredAtlas))
			{
				if(!RequiredAtlas->CheckRequirements(InAtlasMap))
				{
					IsAllowed = false;
				}
				else
				{
					LinksHard[i].Found();
				}
			}
			else
			{
				IsAllowed = false;
			}
		}

		RequirementsChecked_ = true;
		Requirements_ = IsAllowed;

		LOG(60875, Name_, "Checking requirements for: $V$")
		LOG(50166, IsAllowed, "Requirements result: $V$")
	}

	return Requirements_;
}




void AtlasC::Survey(AtlasLibC* InAtlasMap)
{

	AtlasC* LinkTarget = NULL;

	int L = LinksSoft.Len();
	for (int i = 0; i < L; i++)
	{
		if (InAtlasMap->Try(LinksSoft[i].UID(), LinkTarget))
		{
			if (LinkTarget->CheckRequirements(InAtlasMap))
			{
				LinksSoft[i].Found();
			}
		}
	}

	L = LinksPref.Len();
	for (int i = 0; i < L; i++)
	{
		if (InAtlasMap->Try(LinksPref[i].UID(), LinkTarget))
		{
			if (LinkTarget->CheckRequirements(InAtlasMap))
			{
				LinksPref[i].Found();
			}
		}
	}

}


void AtlasC::BoostMount()
{
		FormLib_ = new FormLibC();
		Boost_->Mount(FormLib_);
}

void AtlasC::BoostLink(PayloadC* InPayload)
{

	FormLib_->Link(InPayload);
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