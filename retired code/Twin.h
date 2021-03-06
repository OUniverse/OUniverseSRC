//Copyright 2015-2019, All Rights Reserved.

/**

## Twin

**Struct:** TwinS

Commonly used storage system by the Atlas/Form data system of OUniverse..
Holds a pair of int64s.

*/

#pragma once

#include "Interface/String.h"

struct TwinS
{
	int A;
	int B;

	TwinS(int InA, int InB)
	{
		A = InA;
		B = InB;
	}

	TwinS(StringC TwinString)
	{
		TwinString.SubString(0,20).BeInt(A);
		TwinString.SubString(20, 40).BeInt(B);
	}

};
