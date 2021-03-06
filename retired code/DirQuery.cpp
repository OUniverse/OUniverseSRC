//Copyright 2015-2019, All Rights Reserved.

#include "Interface/DirQuery.h"
#include "CoreMinimal.h"
#include "HAL/PlatformFilemanager.h"
#include "HAL/FileManager.h"


DirQueryS::DirQueryS(StringC InPath)
{
	Path_ = InPath;
	StringC Seek = Path_/"";
	Seek +="*";
	TArray<FString> Files;
	IFileManager& FileManager = IFileManager::Get();
	FileManager.FindFiles(Files, *Seek.ToFString(), false, true);
	Num_ = Files.Num();
	
	for (int i = 0; i < Num_; i++)
	{
		Folders_.Add(Files[i]);
	}
}

StringC DirQueryS::Full(int Index)
{
	return Path_/Folders_[Index];
}

StringC DirQueryS::operator[](int Index)
{
	return Folders_[Index];
}

StringC DirQueryS::Folder(int index)
{
	return Folders_[index];
}

int DirQueryS::Num()
{
	return Num_;
}