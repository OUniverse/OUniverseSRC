//Copyright 2015-2019, All Rights Reserved.

#include "System/UserUID.h"
#include <string> 

#include "Min/DebugM.h"

UserUID::UserUID()
{
	UID_ = 0;
}

UserUID::UserUID(int InInt)
{
	UID_ = InInt;
}

UserUID::UserUID(StringC InS)
{
	UID_ = 0;
	InS.BeInt(UID_);
}

int UserUID::UID() const
{
	return UID_;
}


int UserUID::UID()
{
	return UID_;
}

bool UserUID::operator<(const UserUID& l) const
{
	return UID_ < l.UID_;
}


bool UserUID::operator==(UserUID In)
{
	if (UID_ == In.UID_)
	{
		return true;
	}
	return false;
}


bool UserUID::operator!=(UserUID In)
{
	if (UID_ == In.UID_)
	{
		return false;
	}
	return true;
}

int UserUID::ForJson()
{
	return UID_;
}

int UserUID::ForUI()
{
	return UID_;
}

int UserUID::ForLog()
{
	return UID_;
}

StringC UserUID::ToString()
{
	return StringC(std::to_string(UID_));
}

int UserUID::ParseTitle(StringC InFileName)
{

	if (InFileName[0] != "U")
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