//Copyright 2015-2019, All Rights Reserved.

#include "System/AtlasUID.h"
#include "Interface/TitleParse.h"

int AtlasUID::Max = 4294967295;

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
	return UID() < l.UID();
}


bool AtlasUID::operator==(AtlasUID In)
{
	if (UID() == In.UID())
	{
		return true;
	}
	return false;
}


bool AtlasUID::operator!=(AtlasUID In)
{
	if (UID() == In.UID())
	{
		return false;
	}
	return true;
}

int AtlasUID::ToInt()
{
	return UID_;
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
	return TitleParseC::TryUID(InFileName, Max, UID_);
}