//Copyright 2015-2019, All Rights Reserved.

#include "Dais/PreDaisD.h"
#include "Interface/Int.h"
#include <fstream>
#include <string>

#include "Min/LogM.h"

DaisPreD::DaisPreD(StringC InFileName, StringC InPath)
{
	Valid_ = false;
	Path_ = InPath;
	//SaveFileK::SaveFileK(InPath);
	Crunch(InFileName);
}

void DaisPreD::Crunch(StringC InFileName)
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

	if (Int::Is32U(UID_))
	{
		LOG(BOOT, 0, 1, NameOnly + ": " + "UID is larger than a uint16 (" + UID_ + ")")
			return;
	}

	Preload();
}

void DaisPreD::Preload()
{
	std::string Line;
	std::ifstream File;
	File.open(Path_.ToChar());
	LOG(BOOT, 0, 0, Path_.ToChar())
	std::getline(File, Line);
	LOG(BOOT, 0, 0, Line.c_str())
}

int DaisPreD::GetUID()
{
	return UID_;
}