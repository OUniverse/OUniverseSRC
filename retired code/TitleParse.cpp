//Copyright 2015-2019, All Rights Reserved.

#include "Interface/TitleParse.h"

#include "Min/DebugM.h"

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

int TitleParseC::TryUID(StringC InFileName, U64 InMax, U64& InUID)
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

	if (!InFileName.SubString(1,-1).BeInt(InUID))
	{
		return 2;
	}

	if (InUID > InMax)
	{
		return 3;
	}

	return 0;
}

int TitleParseC::TryPrefixedUID(StringC InFileName, const char* Prefix, U64 InMax, U64& InUID)
{

	if (InFileName[0] != Prefix)
	{
		return 1;
	}

	if (!InFileName.SubString(1,-1).BeInt(InUID))
	{
		return 2;
	}

	if (InUID > InMax)
	{
		return 3;
	}

	return 0;
}

int TitleParseC::TryPrefixedUID(StringC InFileName, const char* Prefix, int InMax, U8& InUID)
{


	if (InFileName[0] != Prefix)
	{
		return 1;
	}

	if (!InFileName.SubString(1,-1).BeInt(InUID))
	{
		return 2;
	}


	if (InUID.Ref() > InMax)
	{
		return 3;
	}

	return 0;
}