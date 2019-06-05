//Copyright 2015-2019, All Rights Reserved.

#include "System/Session.h"

#include "Interface/Int.h"
#include "Interface/Json.h"
#include "Interface/WriterVer.h"

#include "Interface/TitleParse.h"

#include <fstream>
#include <string>

#include "Min/LogM.h"


const char* SessionC::P_SESSION = "S";


SessionC::SessionC(StringC InFileName, StringC InPath)
{
	Valid_ = false;
	Path_ = InPath;
	
	int ErrCode;
	ErrCode = TitleParseC::TryPrefixedUID(InFileName.TrimExtension(), SessionC::P_SESSION ,Int::MaxU16(),UID_);

	if (ErrCode)
	{
		LOG(BOOT, 0, 1, StringC("Error Code with file name: ")+StringC(ErrCode))
		return;
	}

	std::string Line;
	std::ifstream File;
	File.open(Path_.ToChar());

	std::getline(File, Line);
	
	UInt8 WriterVer = StringC(Line).ToU8ZeroFail();
	if(!WriterVer)
	{
		return;
	}

	Valid_ = true;
}

bool SessionC::IsValid() { return Valid_; };

SessionC::VersionS::VersionS(StringC InLine)
{
	JsonS J = JsonS(InLine.ToChar());
	Iteration = J.Int("i");
}

SessionC::DetailsS::DetailsS(StringC InLine)
{
	JsonS J = JsonS(InLine.ToChar());
	Area = J.String("area");
	Date = J.Int("date");
}

SessionC::PartyS::PartyS(StringC InLine)
{

}


int SessionC::GetUID()
{
	return UID_;
}

void SessionC::Promote()
{
	Full_ = new SessionFullC();
}

void SessionC::Demote()
{
	delete Full_;
}