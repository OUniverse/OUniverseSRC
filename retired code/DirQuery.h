//Copyright 2015-2019, All Rights Reserved.

/**

## DirQuery

**Struct:** DirQueryS

Functionality for querying directories within a directory.

* Can return the name all folders within a directory.
* Can return the full path of all folders within a diretory.
* Can return the number of folders in a directory.

*/

#pragma once

#include "Interface/String.h"
#include "Interface/Array.h"



struct DirQueryS
{
	DirQueryS(StringC InPath);

	StringC Folder(int Index);
	StringC operator[](int Index);
	StringC Full(int Index);
	int Num();

private:

	int Num_;
	StringC Path_;
	ArrayC<StringC> Folders_;
};