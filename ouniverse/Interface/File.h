//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include <string>
#include <fstream>


class StringC;

class FileC
{

public:

	static bool Append(StringC Path, StringC Text);

	static bool Empty(StringC Path);

	static bool Delete(StringC Path);

	static FString MakeDir(FString Path);

	FORCEINLINE static std::string LineBreak() { return "\n"; };
	
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

struct DirFiles
{

	FString Path;
	TArray<FString> Files;

	DirFiles();
	DirFiles(FString Path);
	DirFiles(const char* Path);

	int Count;
	int Num();

	FString FullPath(int index);
	FString Extension(int index);

	FString operator[](int32 Index);

private:

	void Seek(FString InPath);

};
