//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "Interface/String.h"
#include "Interface/Array.h"



struct DirQueryS
{
	DirQueryS(StringC InPath);

	StringC Folder(int Index);
	StringC Full(int Index);
	int Num();

private:

	int Num_;
	StringC Path_;
	ArrayC<StringC> Folders_;
};