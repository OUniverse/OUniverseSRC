//Copyright 2015-2019, All Rights Reserved.

#include "Interface/FileQuery.h"
#include "CoreMinimal.h"
#include "HAL/PlatformFilemanager.h"
#include "HAL/FileManager.h"


FileQueryS::FileQueryS(StringC InPath)
{
	Path_ = InPath;
	StringC Seek = Path_ + "*";
	TArray<FString> Files;
	IFileManager& FileManager = IFileManager::Get();
	FileManager.FindFiles(Files, *InPath.ToFString(), true, false);
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

StringC FileQueryS::Folder(int Index)
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