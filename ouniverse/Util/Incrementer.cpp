//Copyright 2015-2019, All Rights Reserved.

#include "Util/Incrementer.h"


Incrementer::Incrementer()
{
	Cursor = 0;
}

int Incrementer::Next() {
	Cursor += 1;
	return Cursor;
}