//Copyright 2015-2019, All Rights Reserved.

#include "CoreMinimal.h"
#include <string>
#include <fstream>


class FileC
{

public:

	static bool Append(const char* Path, FString Text);

	static bool Append(FString Path, FString Text);

	static bool Empty(const char* Path);

	static bool Empty(FString Path);

	static bool Delete(const char* Path);

	static bool Delete(FString Path);

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
