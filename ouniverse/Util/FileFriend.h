//Copyright 2015-2019, All Rights Reserved.

/**
Returns an incrimenting number that it tracks so that the number is always unique.
Useful for giving a constant reference lookup to something that could be renamed making a text based id/name search not valid.
 */

#pragma once

#include "CoreMinimal.h"
#include "json.h"
#include "FileFriend.generated.h"


USTRUCT()
struct FFolderCollector
{
	GENERATED_BODY()

	FString Path;
	TArray<FString> Folders;

	FFolderCollector();
	FFolderCollector(FString Path);

	int Count;
	int Num();
	FString Folder(int index);
	FString FolderPath(int index);	
};


USTRUCT()
struct FFileWriter
{
	GENERATED_BODY()

	FString Path;
	FString Text;

	FFileWriter();
	FFileWriter(FString InText, FString InPath);
	void Encrypt();
	void Write();
};

USTRUCT()
struct FFileReader
{
	GENERATED_BODY()

	FString AsString;
	TSharedPtr<FJsonObject> AsJson;

	bool bFileSuccess;
	bool bJsonSuccess;
	
	FFileReader();
	FFileReader(FString Path);

	void Decrypt();
	void ToJson();
	FString String();
	TSharedPtr<FJsonObject> Json();
	
};