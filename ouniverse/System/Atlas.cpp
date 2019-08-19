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
#include "Atlas/ExtraD.h"

#include "System/FormLib.h"
#include "System/CreditLib.h"
#include "System/Cosmos.h"

#include "Interface/TitleParse.h"




const char* AtlasC::FILE_NAME = "_.atlas";
const char* AtlasC::FILE_NAME_DEV = "_.atlasdev";

const char* AtlasC::K_ID			= "i";
const char* AtlasC::K_NAME			= "n";
const char* AtlasC::K_ICON			= "g";
const char* AtlasC::K_DESC			= "d";
const char* AtlasC::K_AUTHOR		= "a";
const char* AtlasC::K_WEBSITE		= "w";
const char* AtlasC::K_DATE			= "t";
const char* AtlasC::K_VER_VIS		= "vv";
const char* AtlasC::K_VER_ITT		= "vi";
const char* AtlasC::K_VER_UPD		= "vu";
const char* AtlasC::K_WEB_SOCKET	= "so";

const char* AtlasC::K_LINKS			= "l";
const char* AtlasC::K_LINKS_HARD	= "h";
const char* AtlasC::K_LINKS_SOFT	= "s";
const char* AtlasC::K_LINKS_PREF	= "p";

const char* AtlasC::K_FLAGS			= "f";

AtlasC::AtlasC(StringC InFolderName,StringC InPath)
{
	Path_ = InPath;

	Valid_ = false;
	Mounted_ = false;
	Requirements_ = false;
	RequirementsChecked_ = false;
	FoundLinksHard_ = false;
	FoundLinksSoft_ = false;
	FoundLinksPref_ = false;
	DevFile_ = false;

	LOG(29333, InPath, "Validating Atlas folder at path: $V$")

	int ErrCode = TitleParseC::TryUID(InFolderName, Int::MaxU64, UID_);

	if (ErrCode)
	{
		LOG(13451, ErrCode, "Name is incorrect. 1:Prefix Wrong, 2:Name can't become an Integer, 3:Integer of name is larger than max allowed size.  Error Code: $V$")
		return;
	}

	
	LOG(35000, UID_, "Loading ATLAS document: $V$")
	Valid_ = false;


	StringC SearchPath = (InPath / AtlasC::FILE_NAME);
	LOG(105, InPath, "Path: $V$")


		if (!FileC(SearchPath).Exists())
		{
			LOG(404, SearchPath, "File missing")
				return;
		}

	std::string Line;
	std::ifstream File;
	File.open(SearchPath.ToChar());

	std::getline(File, Line);
	U8 WriterVer = StringC(Line).ToU8ZeroFail();
	if (!WriterVer)
	{
		LOG(505, Void(), "Error with Writer Version.");
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
	VerVis_		= J.String(AtlasC::K_VER_VIS);
	Inc_		= J.Int(AtlasC::K_VER_ITT);

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


	SearchPath = (InPath / AtlasC::FILE_NAME_DEV);
	LOG(105, InPath, "Path: $V$")


		if (FileC(SearchPath).Exists())
		{
				DevFile_ = true;
		}

	LOG(10293, Name_, "Is Valid: $V$")
	Valid_ = true;

}

bool AtlasC::Mount()
{
	FormLib_ = new FormLibC();

	std::string Line;
	std::ifstream File;

	StringC SearchPath = (Path_ / AtlasC::FILE_NAME);
	File.open(SearchPath.ToChar());
	std::getline(File, Line);//WriteVer
	std::getline(File, Line);//AtlasPilot

	JsonS J;

	std::getline(File, Line);//Forms
	J = JsonS(StringC(Line));
	FormLib_->AddList(&J);

	//BoostD BoostDoc = BoostD(Path_, Name_);
	//JsonS Forms = JsonS(BoostDoc.GetForms());
	//FormLib_->AddList(&Forms);
	Mounted_ = true;

	return Mounted_;
}

void AtlasC::Dismount()
{
	Mounted_ = false;
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


void AtlasC::LinkBoost(AtlasLibC* InAtlasLib)
{
	FormLib_->LinkBoost(InAtlasLib);
}

void AtlasC::LinkExtra(AtlasLibC* InAtlasLib)
{
	FormLib_->LinkExtra(InAtlasLib);
}


AtlasC::Link::Link()
{
	long long zero = 0;
	UID_ = zero;
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


ArrayC<FormPilotS> AtlasC::GetFormPilots()
{
	return FormLib_->GetFormPilots();
}

FormQueryS AtlasC::Query(FormQueryS InQuery)
{
	return FormLib_->Query(InQuery);
}