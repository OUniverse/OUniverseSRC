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
	U64 Atlas;
	U16 Doc;
	U32 Form;

	TwinS(U64 InAtlas, U16 InDoc, U32 InForm)
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
