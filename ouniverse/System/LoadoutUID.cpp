//Copyright 2015-2019, All Rights Reserved.

#include "System/LoadoutUID.h"

#include "Min/DebugM.h"
#include <string>

LoadoutUID::LoadoutUID()
{
	UID_ = 0;
}

LoadoutUID::LoadoutUID(int InInt)
{
	UID_ = InInt;
}

LoadoutUID::LoadoutUID(StringC InS)
{
	UID_ = 0;
	InS.BeInt(UID_);
}

int LoadoutUID::UID() const
{
	return UID_;
}


int LoadoutUID::UID()
{
	return UID_;
}

bool LoadoutUID::operator<(const LoadoutUID& l) const
{
	return UID_ < l.UID_;
}


bool LoadoutUID::operator==(LoadoutUID In)
{
	if (UID_ == In.UID_)
	{
		return true;
	}
	return false;
}


bool LoadoutUID::operator!=(LoadoutUID In)
{
	if (UID_ == In.UID_)
	{
		return false;
	}
	return true;
}

int LoadoutUID::ForJson()
{
	return UID_;
}

int LoadoutUID::ForUI()
{
	return UID_;
}

int LoadoutUID::ForLog()
{
	return UID_;
}

StringC LoadoutUID::ToString()
{
	return StringC(std::to_string(UID_));
}

int LoadoutUID::ParseTitle(StringC InFileName)
{
	if (!InFileName.BeInt(UID_))
	{
		return 2;
	}

	if (UID_ > INT32_MAX)
	{
		return 3;
	}

	return 0;
}