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

#include "CoreMinimal.h"
#include "Interface/String.h"
#include "Interface/Array.h"


struct FileQueryS
{
public:

	FileQueryS(StringC InPath);
	FileQueryS(StringC InPath, StringC Extension);

	StringC File(int Index);
	StringC Full(int Index);
	StringC Extension(int Index);
	int Num();

private:

	int Num_;
	StringC Path_;
	ArrayC<StringC> Files_;
};