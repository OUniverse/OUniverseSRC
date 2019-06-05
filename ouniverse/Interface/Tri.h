//Copyright 2015-2019, All Rights Reserved.

/**

## Tri

**Struct:** TriS

Holds the standard proprietary data address of a majority of OUniverse's data.
Atlas(uint64) + Doc(uint16) + Form(uint32)
*/



#pragma once

#include "Interface/String.h"
#include "Interface/Int.h"

struct TwinS
{
	UInt64 Atlas;
	UInt16 Doc;
	UInt32 Form;

	TwinS(UInt64 InAtlas, UInt16 InDoc, UInt32 InForm)
	{
		Atlas = InAtlas;
		Doc = InDoc;
		Form = InForm;
	}

	TwinS(StringC TwinString)
	{
		int Cur;
		TwinString.SubString(0,20).BeInt(Cur);
		Atlas = Cur;
		TwinString.SubString(20, 24).BeInt(Cur);
		Doc = Cur;
		TwinString.SubString(24, 30).BeInt(Cur);
		Cur = Cur;
	}

};
