//Copyright 2015-2019, All Rights Reserved.

#include "System/AtlasUID.h"
#include "Interface/TitleParse.h"

#include "Min/DebugM.h"
#include <string>

AtlasUID::AtlasUID()
{
	UID_ = 0;
}

AtlasUID::AtlasUID(int InInt)
{
	UID_ = InInt;
}

AtlasUID::AtlasUID(StringC InS)
{
	UID_ = 0;
	InS.BeInt(UID_);
}

int AtlasUID::UID() const
{
	return UID_;
}


int AtlasUID::UID()
{
	return UID_;
}

bool AtlasUID::operator<(const AtlasUID& l) const
{
	return UID_ < l.UID_;
}


bool AtlasUID::operator==(AtlasUID In)
{
	if (UID_ == In.UID_)
	{
		return true;
	}
	return false;
}


bool AtlasUID::operator!=(AtlasUID In)
{
	if (UID_ == In.UID_)
	{
		return false;
	}
	return true;
}

int AtlasUID::ForJson()
{
	return UID_;
}

int AtlasUID::ForUI()
{
	return UID_;
}

int AtlasUID::ForLog()
{
	return UID_;
}

int AtlasUID::ParseTitle(StringC InFileName)
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