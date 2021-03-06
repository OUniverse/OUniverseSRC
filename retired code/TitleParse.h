//Copyright 2015-2019, All Rights Reserved.

/**

## FileQuery

**Struct:** FileQueryS

Functionality for querying files within a directory.

* Can return the name all files within a directory.
* Can return the full path of all files within a diretory.
* Can return the number of files in a directory.
* Can filter by extension.
* Check if file exists.

*/

#pragma once

#include "Interface/String.h"
#include "Interface/Int.h"

#include "System/AtlasUID.h"

class TitleParseC
{

public:

	static int TryUID(StringC InFileName, int InMax, int& InUID);

	static int TryUID(StringC InFileName, U64 InMax, U64& InUID);

	static int TryPrefixedUID(StringC InFileName, const char* Prefix, int InMax, int& InUID);
	static int TryPrefixedUID(StringC InFileName, const char* Prefix, U64 InMax, U64& InUID);
	static int TryPrefixedUID(StringC InFileName, const char* Prefix, int InMax, U8& InUID);
};