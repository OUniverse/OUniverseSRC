//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "Interface/String.h"
#include "Interface/Array.h"


struct FileReadS
{

	FileReadS(StringC InPath);

	StringC& Out();

	bool Success();

private:

	bool Success_;

	StringC S;

};


class FileC
{

public:

	FileC(StringC InDirectory, StringC InFileName);
	
	StringC Directory;

	StringC FileName;

	StringC Full();

	bool Append(StringC Text);

	bool Empty();

	bool Delete();
	
	bool Exists();

	FileReadS Read();
};