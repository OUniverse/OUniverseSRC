//Copyright 2015-2019, All Rights Reserved.

#include "Interface/Increment.h"


IncrementC::IncrementC()
{
	Cursor = 0;
}

int IncrementC::Next() {
	Cursor += 1;
	return Cursor;
}