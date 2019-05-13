//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Interface/String.h"
#include "Interface/Array.h"


struct DirS;

class FileC
{

public:

	FileC(DirS* InDirectory, StringC InFileName);
	
	DirS* Directory;
	
	StringC FileName;

	StringC Full();

	bool Append(StringC Text);

	bool Empty();

	bool Delete();
		

	static FString MakeDir(FString Path);
	
};

struct FileReadS
{
	bool bSuccess;

	FileReadS(const char* path);

	FileReadS(FString path);

	FString AsFString();

	const char* AsChar();

private:

	std::string String;

};