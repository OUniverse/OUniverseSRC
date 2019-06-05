//Copyright 2015-2019, All Rights Reserved.

#include "Interface/TitleParse.h"


int TitleParseC::TryUID(StringC InFileName, int InMax, int& InUID)
{

	if (!InFileName.BeInt(InUID))
	{
		return 2;
	}

	if (InUID > InMax)
	{
		return 3;
	}

	return 0;
}

int TitleParseC::TryUID(StringC InFileName, UInt64 InMax, UInt64& InUID)
{

	if (!InFileName.BeInt(InUID))
	{
		return 2;
	}

	if (InUID > InMax)
	{
		return 3;
	}

	return 0;
}

int TitleParseC::TryPrefixedUID(StringC InFileName, const char* Prefix, int InMax, int& InUID)
{

	if (InFileName[0] != Prefix)
	{
		return 1;
	}

	if (!InFileName.SubString(1, 5).BeInt(InUID))
	{
		return 2;
	}

	if (InUID > InMax)
	{
		return 3;
	}

	return 0;
}

int TitleParseC::TryPrefixedUID(StringC InFileName, const char* Prefix, UInt64 InMax, UInt64& InUID)
{

	if (InFileName[0] != Prefix)
	{
		return 1;
	}

	if (!InFileName.SubString(1, 5).BeInt(InUID))
	{
		return 2;
	}

	if (InUID > InMax)
	{
		return 3;
	}

	return 0;
}