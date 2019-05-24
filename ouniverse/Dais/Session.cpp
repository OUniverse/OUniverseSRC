//Copyright 2015-2019, All Rights Reserved.

#include "Dais/Session.h"

#include "Interface/Int.h"
#include "Interface/Json.h"

#include <fstream>
#include <string>

#include "Min/LogM.h"

SessionC::SessionC(StringC InFileName, StringC InPath)
{
	Valid_ = false;
	Path_ = InPath;
	//SaveFileK::SaveFileK(InPath);
	Crunch(InFileName);
}

bool SessionC::IsValid() { return Valid_; };

void SessionC::Crunch(StringC InFileName)
{

	StringC NameOnly = InFileName.TrimExtension();

	if (NameOnly.Len() != 6)
	{
		LOG(BOOT, 0, 1, NameOnly + ": " + "Folder Name is too long.")
		return;
	}

	if (NameOnly[0] != 'S')
	{
		LOG(BOOT, 0, 1, NameOnly + ": " + "Prefix is not U.")
		return;
	}

	StringC StrUID = NameOnly.SubString(1, 5);

	if (!StrUID.BeInt(UID_))
	{
		LOG(BOOT, 0, 1, NameOnly + ": " + "Prefix is not a number (" + StrUID + ")")
			return;
	}

	if (!Int::Is32U(UID_))
	{
		LOG(BOOT, 0, 1, NameOnly + ": " + "UID is larger than a uint16 (" + UID_ + ")")
			return;
	}

	Preload();
}

void SessionC::Preload()
{
	std::string Line;
	std::ifstream File;
	File.open(Path_.ToChar());

	std::getline(File, Line);
	Minister_ = MinisterS(Line);

	std::getline(File, Line);
	Version_ = VersionS(Line);

	std::getline(File, Line);
	Details_ = DetailsS(Line);

	std::getline(File, Line);
	Party_ = PartyS(Line);

	Valid_ = true;
}


SessionC::MinisterS::MinisterS(StringC InLine)
{
	
	if (InLine.BeInt(Ver))
	{
		return;
	}

	LOG(BOOT, 0, 1, StringC("Minister Error: ") + InLine + StringC(" was not able to be converted to a Version number."))
}

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