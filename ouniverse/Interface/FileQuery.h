//Copyright 2015-2019, All Rights Reserved.

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