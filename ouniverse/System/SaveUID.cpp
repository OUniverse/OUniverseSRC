//Copyright 2015-2019, All Rights Reserved.

#include "System/SaveUID.h"

#include "Min/DebugM.h"
#include <string>

SaveUID::SaveUID()
{
	UID_ = 0;
}

SaveUID::SaveUID(int InInt)
{
	UID_ = InInt;
}

SaveUID::SaveUID(StringC InS)
{
	UID_ = 0;
	InS.BeInt(UID_);
}

int SaveUID::UID() const
{
	return UID_;
}


int SaveUID::UID()
{
	return UID_;
}

bool SaveUID::operator<(const SaveUID& l) const
{
	return UID_ < l.UID_;
}


bool SaveUID::operator==(SaveUID In)
{
	if (UID_ == In.UID_)
	{
		return true;
	}
	return false;
}


bool SaveUID::operator!=(SaveUID In)
{
	if (UID_ == In.UID_)
	{
		return false;
	}
	return true;
}

int SaveUID::ForJson()
{
	return UID_;
}

int SaveUID::ForUI()
{
	return UID_;
}

int SaveUID::ForLog()
{
	return UID_;
}

int SaveUID::ParseTitle(StringC InFileName)
{

	if (InFileName[0] != "S")
	{
		return 1;
	}

	if (!InFileName.SubString(1, -1).BeInt(UID_))
	{
		return 2;
	}

	if (UID_ > INT16_MAX)
	{
		return 3;
	}

	return 0;
}