//Copyright 2015-2019, All Rights Reserved.

#include "System/LogManager.h"
#include "System/Log.h"
#include "System/LogMinimal.h"
#include "System/Major.h"
#include "System/PathManager.h"
#include "HAL/PlatformFilemanager.h"

void ULogManager::Init(UMajor* InMajor)
{
	Major = InMajor;
	FString UDU_GlobalLogsPath = Major->PathManager->GetPath(EPath::UDU_GlobalLogs);
	ULog* NewLog = AddLog(ELog::Primary, UDU_GlobalLogsPath + FString(LOG_NAME_PRIMARY));
}

ULog* ULogManager::AddLog(ELog LogType, FString Path)
{
	FPlatformFileManager::Get().GetPlatformFile().DeleteFile(*Path);
	ULog* NewLog = NewObject<ULog>();
	LogMap.Add(LogType, NewLog);
	NewLog->Path = Path;

	return NewLog;
}

void ULogManager::Write(ELE Log, uint8 Verb, FString Text)
{
	LogMap.FindRef(ELog::Primary)->Write(Log, Verb, Text);
}