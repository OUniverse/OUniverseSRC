//Copyright 2015-2019, All Rights Reserved.

#include "System/Transient.h"
#include "Misc/FileHelper.h"

void UTransient::Log(FString NewEntry)
{
	FString path = FPaths::ProjectUserDir() + FString("Logs/log.txt");
	FString TheLog;
	FFileHelper::LoadFileToString(TheLog, *path);
	TheLog += NewEntry;
	TheLog += LINE_TERMINATOR;
	FFileHelper::SaveStringToFile(TheLog, *path);
}

void UTransient::Log(FString NewEntry,bool space)
{
	FString path = FPaths::ProjectUserDir() + FString("Logs/log.txt");
	FString TheLog;
	FFileHelper::LoadFileToString(TheLog, *path);

	TheLog += LINE_TERMINATOR;
	TheLog += NewEntry;
	TheLog += LINE_TERMINATOR;
	if (space)
	{
		TheLog += LINE_TERMINATOR;
	}
	FFileHelper::SaveStringToFile(TheLog, *path);
}

void UTransient::Log(FString LogName, FString NewEntry)
{
	FString path = FPaths::ProjectUserDir() + FString("Logs/") + LogName + FString(".txt");
	FString TheLog;
	FFileHelper::LoadFileToString(TheLog, *path);
	TheLog += NewEntry;
	TheLog += LINE_TERMINATOR;
	FFileHelper::SaveStringToFile(TheLog, *path);
}


