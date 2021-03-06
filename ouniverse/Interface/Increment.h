//Copyright 2015-2019, All Rights Reserved.

/**

## Increment

**Struct:**  IncrementS

Self contained incrementing INT with a cursor to the next available number for dealing unique ID values.

*/

#pragma once


struct IncrementC
{

public:

	IncrementC();

	int Next();

private:

	int Cursor;

};