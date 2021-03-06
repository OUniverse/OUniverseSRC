//Copyright 2015-2019, All Rights Reserved.

#include "Interface/FileQuery.h"
#include "CoreMinimal.h"
#include "HAL/PlatformFilemanager.h"
#include "HAL/FileManager.h"

#include "Min/DebugM.h"

FileQueryS::FileQueryS(StringC InPath)
{
	Path_ = InPath;
	StringC Seek = Path_/"";
	Seek+="*";
	TArray<FString> Files;
	IFileManager& FileManager = IFileManager::Get();
	FileManager.FindFiles(Files, *Seek.ToFString(), true, false);
	Num_ = Files.Num();

	for (int i = 0; i < Num_; i++)
	{
		Files_.Add(Files[i]);
	}
}

FileQueryS::FileQueryS(StringC InPath, StringC Extension)
{
	Path_ = InPath;
	TArray<FString> Files;
	IFileManager& FileManager = IFileManager::Get();
	FileManager.FindFiles(Files, *InPath.ToFString(), *Extension.ToFString());
	Num_ = Files.Num();

	for (int i = 0; i < Num_; i++)
	{
		Files_.Add(Files[i]);
	}
}

StringC FileQueryS::Full(int Index)
{
	return Path_ + Files_[Index];
}

StringC FileQueryS::File(int Index)
{
	return Files_[Index];
}

StringC FileQueryS::Extension(int Index)
{
	return FPaths::GetExtension(Files_[Index].ToChar(), false);
}

int FileQueryS::Num()
{
	return Num_;
}