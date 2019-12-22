//Copyright 2015-2019, All Rights Reserved.

#include "System/Atlas.h"
#include "System/AtlasAccordLib.h"

#include "System/AtlasLib.h"
#include "System/RevisionLib.h"
#include "System/AmendmentLib.h"

#include "Interface/Int.h"
#include "Interface/Json.h"

#include "System/Log.h"

#include <fstream>
#include <string>

#include "System/FormLib.h"

#include "Key/GlobalK.h"

#include "ImageUtils.h"

#include "Min/DebugM.h"


const char* AtlasC::FILE_NAME = "_.atlas";
const char* AtlasC::FILE_NAME_DEV = "_.atlasdev";


const char* AtlasC::K_NAME			= "n";
const char* AtlasC::K_ICON			= "g";
const char* AtlasC::K_DESC			= "d";
const char* AtlasC::K_AUTHOR		= "a";
const char* AtlasC::K_WEBSITE		= "w";
const char* AtlasC::K_DATE			= "t";
const char* AtlasC::K_VER_VIS		= "vv";
const char* AtlasC::K_VER_INC		= "vi";
const char* AtlasC::K_VER_UPDATE	= "vu";
const char* AtlasC::K_WEB_SOCKET	= "so";

const char* AtlasC::K_LINKS			= "l";
const char* AtlasC::K_LINKS_HARD	= "h";
const char* AtlasC::K_LINKS_SOFT	= "s";
const char* AtlasC::K_LINKS_PREF	= "p";

const char* AtlasC::K_FLAGS			= "f";


AtlasC::AtlasC(StringC InFolderName, FolderC InFolder)
{

	FormLib_ = NULL;
	RevisionLib_ = NULL;
	AmendmentLib_ = NULL;
	GFXSmall_ = NULL;
	AccordsHard_ = new AtlasAccordLibC();
	AccordsSoft_ = new AtlasAccordLibC();
	AccordsPref_ = new AtlasAccordLibC();

	Folder_ = InFolder;
	AtlasFile_ = Folder_.ToFile("_", "atlas");

	Valid_ = false;
	Mounted_ = false;
	Requirements_ = false;
	RequirementsChecked_ = false;
	FoundLinksHard_ = false;
	FoundLinksSoft_ = false;
	FoundLinksPref_ = false;
	DevFile_ = false;

	

	LOG(29333, Folder_.ToString(), "Validating Atlas folder at path: $V$")

	int ErrCode = UID_.ParseTitle(InFolderName);

	if (ErrCode)
	{
		LOG(13451, ErrCode, "Name is incorrect. 1:Prefix Wrong, 2:Name can't become an Integer, 3:Integer of name is larger than max allowed size.  Error Code: $V$")
		return;
	}

	
	LOG(35000, UID_.ForLog(), "Loading ATLAS document: $V$")
	Valid_ = false;


	
	LOG(105, AtlasFile_.ToString(), "Path: $V$")


		if (!AtlasFile_.Exists())
		{
			LOG(404, AtlasFile_.ToString(), "File missing")
				return;
		}

	std::string LineSS;
	std::ifstream FileSS;

	FileSS.open(AtlasFile_.ToString().ToChar());

	std::getline(FileSS, LineSS);
	StringC WVer = StringC(LineSS);
	U16 WriterVer = WVer.ToU16ZeroFail();
	if (!WriterVer)
	{
		LOG(505, Void(), "Error with Writer Version.");
		return;
	}

	std::getline(FileSS, LineSS);
	JsonS J = JsonS(StringC(LineSS));


	if (!J.Has(GlobalK::ID))
	{
		LOG(300, GlobalK::ID, "Missing required Json Value: $V$")
		return;
	}

	if (!J.Has(AtlasC::K_NAME))
	{
		LOG(300, AtlasC::K_NAME, "Missing required Json Value: $V$")
		return;
	}

	if (!J.Has(AtlasC::K_ICON))
	{
		LOG(300, AtlasC::K_ICON, "Missing required Json Value: $V$")
			return;
	}

	if (!J.Has(AtlasC::K_DESC))
	{
		LOG(300, AtlasC::K_DESC, "Missing required Json Value: $V$")
			return;
	}

	if (!J.Has(AtlasC::K_AUTHOR))
	{
		LOG(300, AtlasC::K_AUTHOR, "Missing required Json Value: $V$")
			return;
	}

	if (!J.Has(AtlasC::K_WEBSITE))
	{
		LOG(300, AtlasC::K_WEBSITE, "Missing required Json Value: $V$")
			return;
	}

	if (!J.Has(AtlasC::K_DATE))
	{
		LOG(300, AtlasC::K_DATE, "Missing required Json Value: $V$")
			return;
	}

	if (!J.Has(AtlasC::K_VER_VIS))
	{
		LOG(300, AtlasC::K_VER_VIS, "Missing required Json Value: $V$")
			return;
	}

	if (!J.Has(AtlasC::K_VER_INC))
	{
		LOG(300, AtlasC::K_VER_INC, "Missing required Json Value: $V$")
			return;
	}

	if (!J.Has(AtlasC::K_VER_UPDATE))
	{
		LOG(300, AtlasC::K_VER_UPDATE, "Missing required Json Value: $V$")
			return;
	}

	if (!J.Has(AtlasC::K_WEB_SOCKET))
	{
		LOG(300, AtlasC::K_WEB_SOCKET, "Missing required Json Value: $V$")
			return;
	}

	if (!J.Has(AtlasC::K_LINKS))
	{
		LOG(300, AtlasC::K_LINKS, "Missing required Json Value: $V$")
			return;
	}

	ID_			= J.String(GlobalK::ID);
	Name_		= J.String(AtlasC::K_NAME);
	Icon_		= J.String(AtlasC::K_ICON);
	Desc_		= J.String(AtlasC::K_DESC);
	Author_		= J.String(AtlasC::K_AUTHOR);
	Website_	= J.String(AtlasC::K_WEBSITE);
	Date_		= J.String(AtlasC::K_DATE);
	VerVis_		= J.String(AtlasC::K_VER_VIS);
	VerInc_		= J.Int(AtlasC::K_VER_INC);
	VerUpdate_	= J.Int(AtlasC::K_VER_UPDATE);
	WebSocket_	= J.String(AtlasC::K_WEB_SOCKET);

	JsonS Links = J[AtlasC::K_LINKS];
	JsonS Cur;
	Cur = Links[AtlasC::K_LINKS_HARD];
	AccordsHard_->AddList(&Cur);
	Cur = Links[AtlasC::K_LINKS_SOFT];
	AccordsSoft_->AddList(&Cur);
	Cur = Links[AtlasC::K_LINKS_PREF];
	AccordsPref_->AddList(&Cur);

	FileC AtlasDevFi = Folder_.ToFile("_", "atlasdev");

	LOG(105, AtlasDevFi.ToString(), "Path: $V$")


		if (AtlasDevFi.Exists())
		{
				DevFile_ = true;
		}

	LOG(10293, Name_, "Is Valid: $V$")
	Valid_ = true;

	GFXSmall_ = GetGFX(AtlasC::GFXSize::Small);
}


AtlasC::~AtlasC()
{
//DELETECHECK
	delete AccordsHard_;
	delete AccordsSoft_;
	delete AccordsPref_;

	delete GFXSmall_;

	delete FormLib_;
	delete RevisionLib_;
	delete AmendmentLib_;

	
}

bool AtlasC::Try(FormUID UID, DataD*& InForm)
{
	bool bFound = false;
	bFound = FormLib_->Try(UID, InForm);
	return bFound;
}

bool AtlasC::Mount(AtlasLibC* InAtlasLib, int InDataMode)
{
	FormLib_ = new FormLibC(this);
	RevisionLib_ = new RevisionLibC(this, InAtlasLib);
	AmendmentLib_ = new AmendmentLibC(this, InAtlasLib);

	std::string LineSS;
	std::ifstream FileSS;

	FileSS.open(AtlasFile_.ToString().ToChar());

	std::getline(FileSS, LineSS);//WriteVer
	std::getline(FileSS, LineSS);//AtlasPilot

	JsonS J;

	//Forms
	std::getline(FileSS, LineSS);
	J = JsonS(StringC(LineSS));
	FormLib_->AddList(&J, this, InDataMode);

	//Revisions
	std::getline(FileSS, LineSS);
	J = JsonS(StringC(LineSS));
	RevisionLib_->AddList(&J);

	
	//Amendments
	std::getline(FileSS, LineSS);
	J = JsonS(StringC(LineSS));
	AmendmentLib_->AddList(&J);
	
	Mounted_ = true;

	return Mounted_;
}

void AtlasC::Dismount()
{

	delete FormLib_;
	delete RevisionLib_;
	delete AmendmentLib_;
	FormLib_ = NULL;
	RevisionLib_ = NULL;
	AmendmentLib_ = NULL;

	Mounted_ = false;
}

bool AtlasC::Mounted()
{
	return Mounted_;
}

void AtlasC::Demarshal()
{
	FormLib_->Demarshal();
}

FolderC AtlasC::Folder()
{
	return Folder_;
}

bool AtlasC::Valid()
{
	return Valid_;
}

AtlasUID AtlasC::UID()
{
	return UID_;
}

StringC AtlasC::ID()
{
	return ID_;
}

StringC AtlasC::Name()
{
	return Name_;
}

StringC AtlasC::Desc()
{
	return Desc_;
}


StringC AtlasC::Author()
{
	return Author_;
}


StringC AtlasC::Website()
{
	return Website_;
}

StringC AtlasC::Date()
{
	return Date_;
}


StringC AtlasC::VerVis()
{
	return VerVis_;
}

int AtlasC::VerInc()
{
	return VerInc_;
}


int AtlasC::VerUpdate()
{
	return VerUpdate_;
}

StringC AtlasC::WebSocket()
{
	return WebSocket_;
}

UTexture2D* AtlasC::GFXSmall()
{
	return GFXSmall_;
}
UTexture2D* AtlasC::GFXLargeLoad()
{
	return GetGFX(AtlasC::GFXSize::Large);
}

UTexture2D* AtlasC::GetGFX(AtlasC::GFXSize Size)
{

	StringC Path;

	switch (Size) {
	case AtlasC::GFXSize::Large:
		Path = StringC("l");
		break;
	case AtlasC::GFXSize::Medium:
		Path = StringC("m");
		break;
	case AtlasC::GFXSize::Small:
		Path = StringC("S");
		break;
	}

	FileC ImgFile = PathC::DirAtlas().ToInsideFolder(UID_.ToString()).ToFile(Path, "png");
	return FImageUtils::ImportFileAsTexture2D(*ImgFile.ToString().ToFString());
}

bool AtlasC::CheckRequirements(AtlasLibC* InAtlasMap)
{
	if (!RequirementsChecked_)
	{
		bool IsAllowed = true;

		AtlasC* RequiredAtlas = NULL;

		int L = AccordsHard_->Len();
		for (int i = 0; i < L; i++)
		{
			if(InAtlasMap->Try(AccordsHard_->Get(i)->UID(), RequiredAtlas))
			{
				if(!RequiredAtlas->CheckRequirements(InAtlasMap))
				{
					IsAllowed = false;
				}
				else
				{
					AccordsHard_->Get(i)->Found();
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

	int L = AccordsSoft_->Len();
	for (int i = 0; i < L; i++)
	{
		if (InAtlasMap->Try(AccordsSoft_->Get(i)->UID(), LinkTarget))
		{
			if (LinkTarget->CheckRequirements(InAtlasMap))
			{
				AccordsSoft_->Get(i)->Found();
			}
		}
	}

	L = AccordsPref_->Len();
	for (int i = 0; i < L; i++)
	{
		if (InAtlasMap->Try(AccordsPref_->Get(i)->UID(), LinkTarget))
		{
			if (LinkTarget->CheckRequirements(InAtlasMap))
			{
				AccordsPref_->Get(i)->Found();
			}
		}
	}

}

void AtlasC::Query(FormQueryS* InQuery)
{
	FormLib_->Query(InQuery);
}

void AtlasC::QueryFormData(FormDataQueryC* InQuery)
{
	FormLib_->QueryFormData(InQuery);
}

FormWrapS AtlasC::GetFormWrap(FormUID InForm)
{
	return FormLib_->GetFormWrap(InForm);
}

void AtlasC::UpdateForm(FormUID InUID, JsonS& InJ)
{
	return FormLib_->Get(InUID)->Update(InJ);
}

void AtlasC::Update(JsonS InJ)
{
	
}

void AtlasC::SaveDoc()
{
	StringC Doc = StringC(1).NL();
	Doc+=  ToJson().Serialize().NL();
	Doc += FormLib_->Serialize().NL();
	Doc += RevisionLib_->Serialize().NL();
	Doc += AmendmentLib_->Serialize();

	DocC AtlasDo = AtlasFile_.Doc();
	AtlasDo.Write(Doc);
}


JsonS AtlasC::ToJson()
{
	JsonS S = JsonS();
	S.Add(GlobalK::ID, ID_);
	S.Add(AtlasC::K_NAME, Name_);
	S.Add(AtlasC::K_ICON, Icon_);
	S.Add(AtlasC::K_DESC, Desc_);
	S.Add(AtlasC::K_AUTHOR, Author_);
	S.Add(AtlasC::K_WEBSITE, Website_);
	
	U64 CurrentTime = FDateTime::Now().GetTicks();	
	S.Add(AtlasC::K_DATE, StringC(CurrentTime.ToStd()));
	S.Add(AtlasC::K_VER_VIS, VerVis_);
	S.Add(AtlasC::K_VER_INC, VerInc_);
	S.Add(AtlasC::K_VER_UPDATE, VerUpdate_);
	S.Add(AtlasC::K_WEB_SOCKET, WebSocket_);

	JsonS Links = JsonS();

	ArrayC<JsonS> JArr;
	JsonS TempLink = JsonS();
	
	Links.Add(AtlasC::K_LINKS_HARD, AccordsHard_->ToJson());
	Links.Add(AtlasC::K_LINKS_SOFT, AccordsSoft_->ToJson());
	Links.Add(AtlasC::K_LINKS_PREF, AccordsPref_->ToJson());
	
	S.Add(AtlasC::K_LINKS, Links);
	
	return S;
}