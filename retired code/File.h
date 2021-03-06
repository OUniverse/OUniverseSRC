//Copyright 2015-2019, All Rights Reserved.

/**

## File

**Class:**  FileC
Custom OOP File class with some helper functionality.

*/ 

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

	FileC();

	FileC(StringC InPath);
	
	StringC Path_;

	bool Append(StringC Text);

	bool Write(StringC Text);

	bool Empty();

	bool Delete();
	
	bool Exists();

	FileReadS Read();
};